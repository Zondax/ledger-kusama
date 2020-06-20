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

#include <zxmacros.h>
#include "parser_impl.h"
#include "parser_txdef.h"
#include "coin.h"
#include "substrate_dispatch.h"
#include "crypto.h"
#include "bignum.h"

char bufferUI[300];

parser_tx_t parser_tx_obj;

parser_error_t parser_init_context(parser_context_t *ctx,
                                   const uint8_t *buffer,
                                   uint16_t bufferSize) {
    ctx->offset = 0;
    ctx->buffer = NULL;
    ctx->bufferLen = 0;

    if (bufferSize == 0 || buffer == NULL) {
        // Not available, use defaults
        return parser_init_context_empty;
    }

    ctx->buffer = buffer;
    ctx->bufferLen = bufferSize;
    return parser_ok;
}

parser_error_t parser_init(parser_context_t *ctx, const uint8_t *buffer, uint16_t bufferSize) {
    CHECK_PARSER_ERR(parser_init_context(ctx, buffer, bufferSize))
    return parser_ok;
}

const char *parser_getErrorDescription(parser_error_t err) {
    switch (err) {
        case parser_ok:
            return "No error";
        case parser_no_data:
            return "No more data";
        case parser_init_context_empty:
            return "Initialized empty context";
        case parser_display_idx_out_of_range:
            return "display_idx_out_of_range";
        case parser_display_page_out_of_range:
            return "display_page_out_of_range";

            // Coin specific
        case parser_spec_not_supported:
            return "Spec version not supported";
        case parser_not_supported:
            return "Not supported";
        case parser_unexpected_buffer_end:
            return "Unexpected buffer end";
        case parser_unexpected_value:
            return "Unexpected value";
        case parser_value_out_of_range:
            return "Value out of range";
        case parser_value_too_many_bytes:
            return "Value too many bytes";
        case parser_unexpected_module:
            return "Unexpected module";
        case parser_unexpected_callIndex:
            return "Unexpected call index";
        case parser_unexpected_unparsed_bytes:
            return "Unexpected unparsed bytes";
        case parser_print_not_supported:
            return "Value cannot be printed";
        default:
            return "Unrecognized error code";
    }
}

GEN_DEF_READFIX_UNSIGNED(8)

GEN_DEF_READFIX_UNSIGNED(16)

GEN_DEF_READFIX_UNSIGNED(32)

GEN_DEF_READFIX_UNSIGNED(64)

parser_error_t _readBool(parser_context_t *c, pd_bool_t *v) {
    CHECK_INPUT();

    const uint8_t p = *(c->buffer + c->offset);
    CTX_CHECK_AND_ADVANCE(c, 1)

    switch (p) {
        case 0x00:
            *v = bool_false;
            break;
        case 0x01:
            *v = bool_true;
            break;
        default:
            return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readCompactInt(parser_context_t *c, compactInt_t *v) {
    CHECK_INPUT();

    v->ptr = c->buffer + c->offset;
    const uint8_t mode = *v->ptr & 0x03u;      // get mode from two least significant bits

    uint64_t tmp;
    switch (mode) {
        case 0:         // single byte
            v->len = 1;
            CTX_CHECK_AND_ADVANCE(c, v->len)
            break;
        case 1:         // 2-byte
            v->len = 2;
            CTX_CHECK_AND_ADVANCE(c, v->len)
            _getValue(v, &tmp);
            break;
        case 2:         // 4-byte
            v->len = 4;
            CTX_CHECK_AND_ADVANCE(c, v->len)
            _getValue(v, &tmp);
            break;
        case 3:         // bitint
            v->len = (*v->ptr >> 2u) + 4 + 1;
            CTX_CHECK_AND_ADVANCE(c, v->len)
            break;
        default:
            // this is actually impossible
            return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _getValue(const compactInt_t *c, uint64_t *v) {
    *v = 0;

    switch (c->len) {
        case 1:
            *v = (*c->ptr) >> 2u;
            break;
        case 2:
            *v = (*c->ptr) >> 2u;
            *v += *(c->ptr + 1) << 6u;
            if (*v < 64) {
                return parser_value_out_of_range;
            }
            break;
        case 4:
            *v = (*c->ptr) >> 2u;
            *v += *(c->ptr + 1) << 6u;
            *v += *(c->ptr + 2) << (8u + 6u);
            *v += *(c->ptr + 3) << (16u + 6u);
            if (*v < 16383) {
                return parser_value_out_of_range;
            }
            break;
        default:
            return parser_value_out_of_range;
    }

    return parser_ok;
}

parser_error_t _toStringCompactInt(const compactInt_t *c,
                                   uint8_t decimalPlaces,
                                   char *outValue, uint16_t outValueLen,
                                   uint8_t pageIdx, uint8_t *pageCount) {
    MEMZERO(outValue, outValueLen);
    MEMZERO(bufferUI, sizeof(bufferUI));
    *pageCount = 1;

    if (c->len <= 4) {
        uint64_t v;
        _getValue(c, &v);

        if (decimalPlaces == 0) {
            uint64_to_str(bufferUI, sizeof(bufferUI), v);
        } else {
            fpuint64_to_str(bufferUI, sizeof(bufferUI), v, decimalPlaces);
        }

        pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    } else {
        uint8_t bcdOut[100];
        const uint16_t bcdOutLen = sizeof(bcdOut);

        bignumLittleEndian_to_bcd(bcdOut, bcdOutLen, c->ptr + 1, c->len - 1);
        if (!bignumLittleEndian_bcdprint(bufferUI, sizeof(bufferUI), bcdOut, bcdOutLen))
            return parser_unexpected_buffer_end;

        if (decimalPlaces > 0) {
            uint16_t numChars = strlen(bufferUI);

//        0123456789012     <-decimal places
//        abcd              < numChars = 4
//                 abcd     < shift
//        000000000abcd     < fill
//        0.00000000abcd    < add decimal point

            if (numChars < decimalPlaces) {
                for (uint16_t j = 0; j < numChars; j++) {
                    bufferUI[decimalPlaces + 1 - j] = bufferUI[numChars - 1 - j];
                }
                MEMSET(bufferUI, '0', decimalPlaces - numChars + 1);
                numChars = strlen(bufferUI);
            }

            // add decimal point
            for (uint16_t j = 0; j < decimalPlaces + 1; j++) {
                bufferUI[numChars + 1 - j] = bufferUI[numChars - j];
            }
            bufferUI[numChars - decimalPlaces] = '.';
        }

        pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    }

    return parser_ok;
}

//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////

parser_error_t _readCallIndex(parser_context_t *c, pd_CallIndex_t *v) {
    CHECK_INPUT();

    CHECK_ERROR(_readUInt8(c, &v->moduleIdx));
    CHECK_ERROR(_readUInt8(c, &v->idx));
    return parser_ok;
}

parser_error_t _readEra(parser_context_t *c, pd_ExtrinsicEra_t *v) {
    CHECK_INPUT();
    //  https://github.com/paritytech/substrate/blob/fc3adc87dc806237eb7371c1d21055eea1702be0/core/sr-primitives/src/generic/era.rs#L117

    v->type = eEraImmortal;

    uint8_t first;
    CHECK_ERROR(_readUInt8(c, &first));
    if (first == 0) { return parser_ok; }

    v->type = eEraMortal;
    uint64_t encoded = first;
    CHECK_ERROR(_readUInt8(c, &first));
    encoded += (uint64_t) first << 8u;

    v->period = 2U << (encoded % (1u << 4u));
    uint64_t quantize_factor = (v->period >> 12u);
    quantize_factor = (quantize_factor == 0 ? 1 : quantize_factor);

    v->phase = (encoded >> 4u) * quantize_factor;

    if (v->period >= 4 && v->phase < v->period) {
        return parser_ok;
    }

    return parser_unexpected_value;
}

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

parser_error_t _readCompactIndex(parser_context_t *c, pd_CompactIndex_t *v) {
    CHECK_INPUT();
    CHECK_ERROR(_readCompactInt(c, &v->index));
    return parser_ok;
}

parser_error_t _readCompactBalance(parser_context_t *c, pd_CompactBalance_t *v) {
    CHECK_INPUT();
    CHECK_ERROR(_readCompactInt(c, &v->value));
    return parser_ok;
}

parser_error_t _toStringCompactIndex(const pd_CompactIndex_t *v,
                                     char *outValue, uint16_t outValueLen,
                                     uint8_t pageIdx, uint8_t *pageCount) {
    return _toStringCompactInt(&v->index, 0, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactBalance(const pd_CompactBalance_t *v,
                                       char *outValue, uint16_t outValueLen,
                                       uint8_t pageIdx, uint8_t *pageCount) {
    return _toStringCompactInt(&v->value, COIN_AMOUNT_DECIMAL_PLACES, outValue, outValueLen, pageIdx, pageCount);
}

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

parser_error_t _checkVersions(parser_context_t *c) {
    // Methods are not length delimited so in order to retrieve the specVersion
    // it is necessary to parse from the back.
    // The transaction is expect to end in
    // [4 bytes] specVersion
    // [4 bytes] transactionVersion
    // [32 bytes] genesisHash
    // [32 bytes] blockHash
    const uint16_t specOffsetFromBack = 4 + 4 + 32 + 32;
    if (c->bufferLen < specOffsetFromBack) {
        return parser_unexpected_buffer_end;
    }

    uint8_t *p = (uint8_t *) (c->buffer + c->bufferLen - specOffsetFromBack);
    uint32_t specVersion = 0;
    specVersion += p[0] << 0u;
    specVersion += p[1] << 8u;
    specVersion += p[2] << 16u;
    specVersion += p[3] << 24u;

    p += 4;
    uint32_t transactionVersion = 0;
    transactionVersion += p[0] << 0u;
    transactionVersion += p[1] << 8u;
    transactionVersion += p[2] << 16u;
    transactionVersion += p[3] << 24u;

    if (specVersion < SUPPORTED_MINIMUM_SPEC_VERSION) {
        return parser_spec_not_supported;
    }

    if (transactionVersion != (SUPPORTED_TX_VERSION)) {
        return parser_spec_not_supported;
    }

    return parser_ok;
}

parser_error_t _readTx(parser_context_t *c, parser_tx_t *v) {
    CHECK_INPUT();

    // Reverse parse to retrieve spec before forward parsing
    CHECK_ERROR(_checkVersions(c));

    // Now forward parse
    CHECK_ERROR(_readCallIndex(c, &v->callIndex));
    CHECK_ERROR(_readMethod(c, v->callIndex.moduleIdx, v->callIndex.idx, &v->method));
    CHECK_ERROR(_readEra(c, &v->era));
    CHECK_ERROR(_readCompactIndex(c, &v->nonce));
    CHECK_ERROR(_readCompactBalance(c, &v->tip));
    CHECK_ERROR(_readUInt32(c, &v->specVersion));
    CHECK_ERROR(_readUInt32(c, &v->transactionVersion));
    CHECK_ERROR(_readHash(c, &v->genesisHash));
    CHECK_ERROR(_readHash(c, &v->blockHash));

    if (c->offset < c->bufferLen) {
        return parser_unexpected_unparsed_bytes;
    }

    if (c->offset > c->bufferLen) {
        return parser_unexpected_buffer_end;
    }

    return parser_ok;
}

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

parser_error_t _readAddress(parser_context_t *c, pd_Address_t *v) {
    CHECK_INPUT();
    // Based on
    // https://github.com/paritytech/substrate/blob/fc3adc87dc806237eb7371c1d21055eea1702be0/srml/indices/src/address.rs#L66

    uint8_t tmp;
    CHECK_ERROR(_readUInt8(c, &tmp));

    switch (tmp) {
        case 0xFF: {
            v->type = eAddressId;
            v->idPtr = c->buffer + c->offset;
            CTX_CHECK_AND_ADVANCE(c, 32);
            break;
        }
        case 0xFE: {
            compactInt_t ci;
            CHECK_ERROR(_readCompactInt(c, &ci));

            v->type = eAddressIndex;
            CHECK_ERROR(_getValue(&ci, &v->idx));

            if (v->idx <= 0xffffffffu) {
                return parser_unexpected_value;
            }
            break;
        }
        case 0xFD: {
            uint32_t tmpval;
            CHECK_ERROR(_readUInt32(c, &tmpval));
            v->type = eAddressIndex;
            v->idx = tmpval;
            if (v->idx <= 0xFFFF) {
                return parser_unexpected_value;
            }
            break;
        }
        case 0xFC: {
            uint16_t tmpval;
            CHECK_ERROR(_readUInt16(c, &tmpval));
            v->type = eAddressIndex;
            v->idx = tmpval;
            if (v->idx <= 0xEF) {
                return parser_unexpected_value;
            }
            break;
        }
        default:
            if (tmp <= 0xEF) {
                v->type = eAddressIndex;
                v->idx = tmp;
                return parser_ok;
            }

            return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readHash(parser_context_t *c, pd_Hash_t *v) {
    GEN_DEF_READARRAY(32);
}

uint8_t _detectAddressType() {
    char hashstr[65];
    uint8_t pc;

    if (parser_tx_obj.genesisHash._ptr != NULL) {
        _toStringHash(&parser_tx_obj.genesisHash, hashstr, 65, 0, &pc);

        // Compare with known genesis hashes
        // KUSAMA
        if (strcmp(hashstr, COIN_KUSAMA_CC3_GENESIS_HASH) == 0) {
            return 2;
        }
    }

    return 42;
}

parser_error_t _toStringPubkeyAsAddress(const uint8_t *pubkey,
                                        char *outValue, uint16_t outValueLen,
                                        uint8_t pageIdx, uint8_t *pageCount) {
    uint8_t addressType = _detectAddressType();

    if (crypto_SS58EncodePubkey((uint8_t *) bufferUI, sizeof(bufferUI), addressType, pubkey) == 0) {
        return parser_no_data;
    }

    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    if (pageIdx >= *pageCount) {
        return parser_no_data;
    }
    return parser_ok;
}

parser_error_t _toStringAddress(const pd_Address_t *v,
                                char *outValue, uint16_t outValueLen,
                                uint8_t pageIdx, uint8_t *pageCount) {
    MEMZERO(outValue, outValueLen);
    if (v == NULL) {
        return parser_ok;
    }

    *pageCount = 1;
    switch (v->type) {
        case eAddressIndex:
            return parser_not_supported;
        case eAddressId: {
            return _toStringPubkeyAsAddress(v->idPtr,
                                            outValue, outValueLen,
                                            pageIdx, pageCount);
        }
    }

    return parser_ok;
}

parser_error_t _toStringHash(const pd_Hash_t *v,
                             char *outValue, uint16_t outValueLen,
                             uint8_t pageIdx, uint8_t *pageCount) {
    GEN_DEF_TOSTRING_ARRAY(32);
}
