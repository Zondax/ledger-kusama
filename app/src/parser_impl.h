/*******************************************************************************
*  (c) 2019 Zondax GmbH
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
********************************************************************************/
#pragma once

#include "parser_common.h"
#include <zxmacros.h>

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include "zxtypes.h"
#include "parser_txdef.h"

parser_error_t parser_init(parser_context_t *ctx,
                           const uint8_t *buffer,
                           uint16_t bufferSize);

#define GEN_DEC_READFIX_UNSIGNED(BITS) parser_error_t _readUInt ## BITS(parser_context_t *ctx, uint ## BITS ##_t *value)
#define GEN_DEF_READFIX_UNSIGNED(BITS) parser_error_t _readUInt ## BITS(parser_context_t *ctx, uint ## BITS ##_t *value) \
{                                                                                           \
    if (value == NULL)  return parser_no_data;                                              \
    *value = 0u;                                                                            \
    for(uint8_t i=0u; i < (BITS##u>>3u); i++, ctx->offset++) {                              \
        if (ctx->offset >= ctx->bufferLen) return parser_unexpected_buffer_end;             \
        *value += *(ctx->buffer + ctx->offset) << (8u*i);                                   \
    }                                                                                       \
    return parser_ok;                                                                       \
}

GEN_DEC_READFIX_UNSIGNED(8);
GEN_DEC_READFIX_UNSIGNED(16);
GEN_DEC_READFIX_UNSIGNED(32);
GEN_DEC_READFIX_UNSIGNED(64);

// Checks that there are at least SIZE bytes available in the buffer
#define CTX_CHECK_AVAIL(CTX, SIZE) \
    if ( (CTX) == NULL || ((CTX)->offset + SIZE) > (CTX)->bufferLen) { return parser_unexpected_buffer_end; }

#define CTX_CHECK_AND_ADVANCE(CTX, SIZE) \
    CTX_CHECK_AVAIL((CTX), (SIZE))   \
    (CTX)->offset += (SIZE);

// Checks function input is valid
#define CHECK_INPUT() \
    if (v == NULL) { return parser_no_data; } \
    CTX_CHECK_AVAIL(c, 1) // Checks that there is something available in the buffer

#define CLEAN_AND_CHECK() MEMZERO(outValue, outValueLen);  \
    if (v == NULL) { *pageCount = 0; return parser_no_data; }

#define GEN_DEF_READARRAY(SIZE) \
    v->_ptr = c->buffer + c->offset; \
    CTX_CHECK_AND_ADVANCE(c, SIZE) \
    return parser_ok;

#define GEN_DEF_TOSTRING_ARRAY(SIZE) \
    CLEAN_AND_CHECK();\
    if (v->_ptr == NULL) return parser_unexpected_buffer_end; \
    const uint16_t outLenNormalized = ((outValueLen - 1u) >> 1u);\
    const uint16_t pageOffset = pageIdx * outLenNormalized;\
    *pageCount = SIZE / outLenNormalized;    \
    if (SIZE % outLenNormalized != 0)    \
    (*pageCount)++; \
    uint16_t loopmax = outLenNormalized;    \
    if (loopmax > SIZE - pageOffset) { \
        loopmax = SIZE - pageOffset; \
    };\
    for (uint16_t i = 0; i < loopmax; i++) {\
        const uint16_t offset = i << 1u;\
        snprintf(outValue + offset,\
        outValueLen - offset,\
        "%02x", *(v->_ptr + pageOffset + i));\
    }\
    return parser_ok;

#define GEN_DEF_READVECTOR(TYPE) \
    pd_##TYPE##_t dummy;                                            \
    compactInt_t clen;                                              \
    CHECK_ERROR(_readCompactInt(c, &clen));                         \
    CHECK_ERROR(_getValue(&clen, &v->_len));                        \
    v->_ptr = c->buffer + c->offset;                                \
    v->_lenBuffer = c->offset;                                      \
    for (uint64_t i = 0; i < v->_len; i++ ) CHECK_ERROR(_read##TYPE(c, &dummy));  \
    v->_lenBuffer = c->offset - v->_lenBuffer;                      \
    return parser_ok;

#define GEN_DEF_TOSTRING_VECTOR(TYPE) \
    CLEAN_AND_CHECK()      \
    /* count number of pages, then output specific */       \
    *pageCount = 0;                                         \
    pd_##TYPE##_t tmp;                                      \
    parser_context_t ctx;                                   \
    uint8_t chunkPageCount;                                 \
    uint16_t currentPage, currentTotalPage = 0;             \
    /* We need to do it twice because there is no memory to keep intermediate results*/ \
    /* First count*/ \
    parser_init(&ctx, v->_ptr, v->_lenBuffer);\
    for (uint16_t i = 0; i < v->_len; i++) {\
        CHECK_ERROR(_read##TYPE(&ctx, &tmp));\
        CHECK_ERROR(_toString##TYPE(&tmp, outValue, outValueLen, 0, &chunkPageCount));\
        (*pageCount)+=chunkPageCount;\
    }\
    /* Then iterate until we can print the corresponding chunk*/ \
    parser_init(&ctx, v->_ptr, v->_lenBuffer);\
    for (uint16_t i = 0; i < v->_len; i++) {\
        CHECK_ERROR(_read##TYPE(&ctx, &tmp));\
        chunkPageCount = 1;\
        currentPage = 0;\
        while (currentPage < chunkPageCount) {\
            CHECK_ERROR(_toString##TYPE(&tmp, outValue, outValueLen, currentPage, &chunkPageCount));\
            if (currentTotalPage == pageIdx) { return parser_ok; } \
            currentPage++;\
            currentTotalPage++;\
        }\
    };\
    return parser_print_not_supported;

parser_error_t _readBool(parser_context_t *c, pd_bool_t *value);

parser_error_t _readCompactInt(parser_context_t *c, compactInt_t *v);

parser_error_t _getValue(const compactInt_t *c, uint64_t *v);

parser_error_t _readCallIndex(parser_context_t *c, pd_CallIndex_t *v);

parser_error_t _readEra(parser_context_t *c, pd_ExtrinsicEra_t *v);

parser_error_t _readTx(parser_context_t *c, parser_tx_t *v);

uint8_t _getAddressType();

parser_error_t _toStringCompactInt(const compactInt_t *c,
                                   uint8_t decimalPlaces,
                                   char *outValue, uint16_t outValueLen,
                                   uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringCompactIndex(const pd_CompactIndex_t *v,
                                     char *outValue, uint16_t outValueLen,
                                     uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringPubkeyAsAddress(const uint8_t *pubkey,
                                        char *outValue, uint16_t outValueLen,
                                        uint8_t pageIdx, uint8_t *pageCount);

#ifdef __cplusplus
}
#endif
