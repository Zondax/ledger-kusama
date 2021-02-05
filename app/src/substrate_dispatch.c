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
#include "substrate_dispatch.h"
#include "parser_impl.h"

#include "allowlist.h"
#include "zxmacros.h"
#include <stdint.h>

parser_error_t _readMethod(
    parser_context_t* c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_Method_t* method)
{

    switch (c->tx_obj->transactionVersion) {
    case 4:
        return _readMethod_V4(c, moduleIdx, callIdx, &method->V4);
    case 3:
        return _readMethod_V3(c, moduleIdx, callIdx, &method->V3);
    default:
        return parser_not_supported;
    }
}

uint8_t _getMethod_NumItems(uint32_t transactionVersion, uint8_t moduleIdx, uint8_t callIdx, pd_Method_t* method)
{
    switch (transactionVersion) {
    case 4:
        return _getMethod_NumItems_V4(moduleIdx, callIdx, &method->V4);
    case 3:
        return _getMethod_NumItems_V3(moduleIdx, callIdx, &method->V3);
    default:
        return parser_not_supported;
    }
}

const char* _getMethod_ModuleName(uint32_t transactionVersion, uint8_t moduleIdx)
{
    switch (transactionVersion) {
    case 4:
        return _getMethod_ModuleName_V4(moduleIdx);
    case 3:
        return _getMethod_ModuleName_V3(moduleIdx);
    default:
        return NULL;
    }
}

const char* _getMethod_Name(uint32_t transactionVersion, uint8_t moduleIdx, uint8_t callIdx)
{
    switch (transactionVersion) {
    case 4:
        return _getMethod_Name_V4(moduleIdx, callIdx);
    case 3:
        return _getMethod_Name_V3(moduleIdx, callIdx);
    default:
        return 0;
    }
}

const char* _getMethod_ItemName(uint32_t transactionVersion, uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    switch (transactionVersion) {
    case 4:
        return _getMethod_ItemName_V4(moduleIdx, callIdx, itemIdx);
    case 3:
        return _getMethod_ItemName_V3(moduleIdx, callIdx, itemIdx);
    default:
        return NULL;
    }
}

parser_error_t _getMethod_ItemValue(uint32_t transactionVersion, pd_Method_t* m, uint8_t moduleIdx, uint8_t callIdx,
    uint8_t itemIdx, char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount)
{
    switch (transactionVersion) {
    case 4:
        return _getMethod_ItemValue_V4(&m->V4, moduleIdx, callIdx, itemIdx, outValue,
            outValueLen, pageIdx, pageCount);
    case 3:
        return _getMethod_ItemValue_V3(&m->V3, moduleIdx, callIdx, itemIdx, outValue,
            outValueLen, pageIdx, pageCount);
    default:
        return parser_not_supported;
    }
}

bool _getMethod_ItemIsExpert(uint32_t transactionVersion, uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    switch (transactionVersion) {
    case 4:
        return _getMethod_ItemIsExpert_V4(moduleIdx, callIdx, itemIdx);
    case 3:
        return _getMethod_ItemIsExpert_V3(moduleIdx, callIdx, itemIdx);
    default:
        return false;
    }
}

bool _getMethod_IsNestingSupported(uint32_t transactionVersion, uint8_t moduleIdx, uint8_t callIdx)
{
    switch (transactionVersion) {
    case 4:
        return _getMethod_IsNestingSupported_V4(moduleIdx, callIdx);
    case 3:
        return _getMethod_IsNestingSupported_V3(moduleIdx, callIdx);
    default:
        return false;
    }
}

//Special getters
#if defined(APP_RESTRICTED)
parser_error_t parser_validate_staking_targets(parser_context_t* c)
{
    if (!allowlist_is_active()) {
        return parser_not_allowed;
    }

    const uint8_t* targets_ptr;
    uint64_t targets_lenBuffer;
    uint64_t targets_len;

    switch (c->tx_obj->transactionVersion) {
    case 4: {
        pd_VecLookupSource_V4_t targets = c->tx_obj->method.V4.basic.staking_nominate_V4.targets;
        targets_ptr = targets._ptr;
        targets_lenBuffer = targets._lenBuffer;
        targets_len = targets._len;
        break;
    }
    case 3: {
        pd_VecLookupSource_V3_t targets = c->tx_obj->method.V3.basic.staking_nominate_V3.targets;
        targets_ptr = targets._ptr;
        targets_lenBuffer = targets._lenBuffer;
        targets_len = targets._len;
        break;
    }
    default:
        return parser_not_supported;
    }

    parser_context_t ctx;
    parser_init(&ctx, targets_ptr, targets_lenBuffer);
    switch (c->tx_obj->transactionVersion) {
    case 4: {
        for (uint16_t i = 0; i < targets_len; i++) {
            pd_LookupSource_V4_t lookupSource;
            CHECK_ERROR(_readLookupSource_V4(&ctx, &lookupSource));
            char buffer[100];
            uint8_t dummy;
            CHECK_ERROR(_toStringLookupSource_V4(&lookupSource, buffer, sizeof(buffer), 0, &dummy));
            if (!allowlist_item_validate(buffer)) {
                return parser_not_allowed;
            }
        }
        break;
    }
    case 3: {
        for (uint16_t i = 0; i < targets_len; i++) {
            pd_LookupSource_V3_t lookupSource;
            CHECK_ERROR(_readLookupSource_V3(&ctx, &lookupSource));
            char buffer[100];
            uint8_t dummy;
            CHECK_ERROR(_toStringLookupSource_V3(&lookupSource, buffer, sizeof(buffer), 0, &dummy));
            if (!allowlist_item_validate(buffer)) {
                return parser_not_allowed;
            }
        }
        break;
    }

    default:
        return parser_not_supported;
    }

    return parser_ok;
}
#endif

GEN_DEF_GETCALL(STAKING);
GEN_DEF_GETCALL(STAKING_VALIDATE);
GEN_DEF_GETCALL(STAKING_SET_PAYEE);
GEN_DEF_GETCALL(STAKING_CHILL);
GEN_DEF_GETCALL(STAKING_NOMINATE);
GEN_DEF_GETCALL(SESSION);
GEN_DEF_GETCALL(SESSION_SET_KEYS);
GEN_DEF_GETCALL(SESSION_PURGE_KEYS);
