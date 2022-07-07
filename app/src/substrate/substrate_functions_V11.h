/*******************************************************************************
 *  (c) 2019 - 2022 Zondax GmbH
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

#ifdef __cplusplus
extern "C" {
#endif

#include "parser_common.h"
#include "substrate_methods_V11.h"
#include "substrate_types_V11.h"
#include <stddef.h>
#include <stdint.h>

// Read functions
parser_error_t _readAccountId_V11(parser_context_t* c, pd_AccountId_V11_t* v);
parser_error_t _readAccountIndex_V11(parser_context_t* c, pd_AccountIndex_V11_t* v);
parser_error_t _readAccountVoteSplit_V11(parser_context_t* c, pd_AccountVoteSplit_V11_t* v);
parser_error_t _readAccountVoteStandard_V11(parser_context_t* c, pd_AccountVoteStandard_V11_t* v);
parser_error_t _readAccountVote_V11(parser_context_t* c, pd_AccountVote_V11_t* v);
parser_error_t _readBondExtraBalanceOfT_V11(parser_context_t* c, pd_BondExtraBalanceOfT_V11_t* v);
parser_error_t _readCompactAccountIndex_V11(parser_context_t* c, pd_CompactAccountIndex_V11_t* v);
parser_error_t _readCompactPerBill_V11(parser_context_t* c, pd_CompactPerBill_V11_t* v);
parser_error_t _readConfigOpAccountId_V11(parser_context_t* c, pd_ConfigOpAccountId_V11_t* v);
parser_error_t _readConfigOpBalanceOfT_V11(parser_context_t* c, pd_ConfigOpBalanceOfT_V11_t* v);
parser_error_t _readConfigOpu32_V11(parser_context_t* c, pd_ConfigOpu32_V11_t* v);
parser_error_t _readConviction_V11(parser_context_t* c, pd_Conviction_V11_t* v);
parser_error_t _readEcdsaPublic_V11(parser_context_t* c, pd_EcdsaPublic_V11_t* v);
parser_error_t _readEcdsaSignature_V11(parser_context_t* c, pd_EcdsaSignature_V11_t* v);
parser_error_t _readEd25519Public_V11(parser_context_t* c, pd_Ed25519Public_V11_t* v);
parser_error_t _readEd25519Signature_V11(parser_context_t* c, pd_Ed25519Signature_V11_t* v);
parser_error_t _readEraIndex_V11(parser_context_t* c, pd_EraIndex_V11_t* v);
parser_error_t _readEthereumAddress_V11(parser_context_t* c, pd_EthereumAddress_V11_t* v);
parser_error_t _readKeys_V11(parser_context_t* c, pd_Keys_V11_t* v);
parser_error_t _readLookupasStaticLookupSource_V11(parser_context_t* c, pd_LookupasStaticLookupSource_V11_t* v);
parser_error_t _readMemberCount_V11(parser_context_t* c, pd_MemberCount_V11_t* v);
parser_error_t _readMultiSignature_V11(parser_context_t* c, pd_MultiSignature_V11_t* v);
parser_error_t _readMultiSigner_V11(parser_context_t* c, pd_MultiSigner_V11_t* v);
parser_error_t _readOpaqueCall_V11(parser_context_t* c, pd_OpaqueCall_V11_t* v);
parser_error_t _readOptionAccountId_V11(parser_context_t* c, pd_OptionAccountId_V11_t* v);
parser_error_t _readOptionMultiSignature_V11(parser_context_t* c, pd_OptionMultiSignature_V11_t* v);
parser_error_t _readOptionMultiSigner_V11(parser_context_t* c, pd_OptionMultiSigner_V11_t* v);
parser_error_t _readOptionProxyType_V11(parser_context_t* c, pd_OptionProxyType_V11_t* v);
parser_error_t _readOptionTimepoint_V11(parser_context_t* c, pd_OptionTimepoint_V11_t* v);
parser_error_t _readParaId_V11(parser_context_t* c, pd_ParaId_V11_t* v);
parser_error_t _readPerbill_V11(parser_context_t* c, pd_Perbill_V11_t* v);
parser_error_t _readPoolId_V11(parser_context_t* c, pd_PoolId_V11_t* v);
parser_error_t _readPoolState_V11(parser_context_t* c, pd_PoolState_V11_t* v);
parser_error_t _readProxyType_V11(parser_context_t* c, pd_ProxyType_V11_t* v);
parser_error_t _readReferendumIndex_V11(parser_context_t* c, pd_ReferendumIndex_V11_t* v);
parser_error_t _readRegistrarIndex_V11(parser_context_t* c, pd_RegistrarIndex_V11_t* v);
parser_error_t _readRewardDestination_V11(parser_context_t* c, pd_RewardDestination_V11_t* v);
parser_error_t _readSessionIndex_V11(parser_context_t* c, pd_SessionIndex_V11_t* v);
parser_error_t _readSr25519Public_V11(parser_context_t* c, pd_Sr25519Public_V11_t* v);
parser_error_t _readSr25519Signature_V11(parser_context_t* c, pd_Sr25519Signature_V11_t* v);
parser_error_t _readTimepoint_V11(parser_context_t* c, pd_Timepoint_V11_t* v);
parser_error_t _readValidatorPrefs_V11(parser_context_t* c, pd_ValidatorPrefs_V11_t* v);
parser_error_t _readVecAccountId_V11(parser_context_t* c, pd_VecAccountId_V11_t* v);
parser_error_t _readVecLookupasStaticLookupSource_V11(parser_context_t* c, pd_VecLookupasStaticLookupSource_V11_t* v);
parser_error_t _readVestingInfo_V11(parser_context_t* c, pd_VestingInfo_V11_t* v);
parser_error_t _readVote_V11(parser_context_t* c, pd_Vote_V11_t* v);
parser_error_t _readWeight_V11(parser_context_t* c, pd_Weight_V11_t* v);

// toString functions
parser_error_t _toStringAccountId_V11(
    const pd_AccountId_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIndex_V11(
    const pd_AccountIndex_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteSplit_V11(
    const pd_AccountVoteSplit_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteStandard_V11(
    const pd_AccountVoteStandard_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVote_V11(
    const pd_AccountVote_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBondExtraBalanceOfT_V11(
    const pd_BondExtraBalanceOfT_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAccountIndex_V11(
    const pd_CompactAccountIndex_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactPerBill_V11(
    const pd_CompactPerBill_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConfigOpAccountId_V11(
    const pd_ConfigOpAccountId_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConfigOpBalanceOfT_V11(
    const pd_ConfigOpBalanceOfT_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConfigOpu32_V11(
    const pd_ConfigOpu32_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConviction_V11(
    const pd_Conviction_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEcdsaPublic_V11(
    const pd_EcdsaPublic_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEcdsaSignature_V11(
    const pd_EcdsaSignature_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEd25519Public_V11(
    const pd_Ed25519Public_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEd25519Signature_V11(
    const pd_Ed25519Signature_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEraIndex_V11(
    const pd_EraIndex_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEthereumAddress_V11(
    const pd_EthereumAddress_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys_V11(
    const pd_Keys_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLookupasStaticLookupSource_V11(
    const pd_LookupasStaticLookupSource_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemberCount_V11(
    const pd_MemberCount_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiSignature_V11(
    const pd_MultiSignature_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiSigner_V11(
    const pd_MultiSigner_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOpaqueCall_V11(
    const pd_OpaqueCall_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionAccountId_V11(
    const pd_OptionAccountId_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMultiSignature_V11(
    const pd_OptionMultiSignature_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMultiSigner_V11(
    const pd_OptionMultiSigner_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionProxyType_V11(
    const pd_OptionProxyType_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTimepoint_V11(
    const pd_OptionTimepoint_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringParaId_V11(
    const pd_ParaId_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill_V11(
    const pd_Perbill_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPoolId_V11(
    const pd_PoolId_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPoolState_V11(
    const pd_PoolState_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProxyType_V11(
    const pd_ProxyType_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringReferendumIndex_V11(
    const pd_ReferendumIndex_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRegistrarIndex_V11(
    const pd_RegistrarIndex_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRewardDestination_V11(
    const pd_RewardDestination_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSessionIndex_V11(
    const pd_SessionIndex_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSr25519Public_V11(
    const pd_Sr25519Public_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSr25519Signature_V11(
    const pd_Sr25519Signature_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTimepoint_V11(
    const pd_Timepoint_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidatorPrefs_V11(
    const pd_ValidatorPrefs_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId_V11(
    const pd_VecAccountId_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecLookupasStaticLookupSource_V11(
    const pd_VecLookupasStaticLookupSource_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVestingInfo_V11(
    const pd_VestingInfo_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVote_V11(
    const pd_Vote_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeight_V11(
    const pd_Weight_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
