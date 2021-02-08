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

#ifdef __cplusplus
extern "C" {
#endif

#include "parser_common.h"
#include "substrate_methods_V4.h"
#include "substrate_types_V4.h"
#include <stddef.h>
#include <stdint.h>

// Read functions
parser_error_t _readAccountId_V4(parser_context_t* c, pd_AccountId_V4_t* v);
parser_error_t _readAccountIndex_V4(parser_context_t* c, pd_AccountIndex_V4_t* v);
parser_error_t _readAccountVoteSplit_V4(parser_context_t* c, pd_AccountVoteSplit_V4_t* v);
parser_error_t _readAccountVoteStandard_V4(parser_context_t* c, pd_AccountVoteStandard_V4_t* v);
parser_error_t _readAccountVote_V4(parser_context_t* c, pd_AccountVote_V4_t* v);
parser_error_t _readCallHashOf_V4(parser_context_t* c, pd_CallHashOf_V4_t* v);
parser_error_t _readChangesTrieConfiguration_V4(parser_context_t* c, pd_ChangesTrieConfiguration_V4_t* v);
parser_error_t _readCompactAccountIndex_V4(parser_context_t* c, pd_CompactAccountIndex_V4_t* v);
parser_error_t _readCompactAssignments_V4(parser_context_t* c, pd_CompactAssignments_V4_t* v);
parser_error_t _readCompactBountyIndex_V4(parser_context_t* c, pd_CompactBountyIndex_V4_t* v);
parser_error_t _readCompactEraIndex_V4(parser_context_t* c, pd_CompactEraIndex_V4_t* v);
parser_error_t _readCompactMemberCount_V4(parser_context_t* c, pd_CompactMemberCount_V4_t* v);
parser_error_t _readCompactMoment_V4(parser_context_t* c, pd_CompactMoment_V4_t* v);
parser_error_t _readCompactPerBill_V4(parser_context_t* c, pd_CompactPerBill_V4_t* v);
parser_error_t _readCompactPropIndex_V4(parser_context_t* c, pd_CompactPropIndex_V4_t* v);
parser_error_t _readCompactProposalIndex_V4(parser_context_t* c, pd_CompactProposalIndex_V4_t* v);
parser_error_t _readCompactReferendumIndex_V4(parser_context_t* c, pd_CompactReferendumIndex_V4_t* v);
parser_error_t _readCompactRegistrarIndex_V4(parser_context_t* c, pd_CompactRegistrarIndex_V4_t* v);
parser_error_t _readCompactWeight_V4(parser_context_t* c, pd_CompactWeight_V4_t* v);
parser_error_t _readConviction_V4(parser_context_t* c, pd_Conviction_V4_t* v);
parser_error_t _readEcdsaSignature_V4(parser_context_t* c, pd_EcdsaSignature_V4_t* v);
parser_error_t _readElectionScore_V4(parser_context_t* c, pd_ElectionScore_V4_t* v);
parser_error_t _readElectionSize_V4(parser_context_t* c, pd_ElectionSize_V4_t* v);
parser_error_t _readEquivocationProof_V4(parser_context_t* c, pd_EquivocationProof_V4_t* v);
parser_error_t _readEraIndex_V4(parser_context_t* c, pd_EraIndex_V4_t* v);
parser_error_t _readEthereumAddress_V4(parser_context_t* c, pd_EthereumAddress_V4_t* v);
parser_error_t _readIdentityFields_V4(parser_context_t* c, pd_IdentityFields_V4_t* v);
parser_error_t _readIdentityInfo_V4(parser_context_t* c, pd_IdentityInfo_V4_t* v);
parser_error_t _readJudgement_V4(parser_context_t* c, pd_Judgement_V4_t* v);
parser_error_t _readKeyOwnerProof_V4(parser_context_t* c, pd_KeyOwnerProof_V4_t* v);
parser_error_t _readKeyValue_V4(parser_context_t* c, pd_KeyValue_V4_t* v);
parser_error_t _readKey_V4(parser_context_t* c, pd_Key_V4_t* v);
parser_error_t _readKeys_V4(parser_context_t* c, pd_Keys_V4_t* v);
parser_error_t _readLookupSource_V4(parser_context_t* c, pd_LookupSource_V4_t* v);
parser_error_t _readMemberCount_V4(parser_context_t* c, pd_MemberCount_V4_t* v);
parser_error_t _readOpaqueCall_V4(parser_context_t* c, pd_OpaqueCall_V4_t* v);
parser_error_t _readOptionAccountId_V4(parser_context_t* c, pd_OptionAccountId_V4_t* v);
parser_error_t _readOptionChangesTrieConfiguration_V4(parser_context_t* c, pd_OptionChangesTrieConfiguration_V4_t* v);
parser_error_t _readOptionPeriod_V4(parser_context_t* c, pd_OptionPeriod_V4_t* v);
parser_error_t _readOptionProxyType_V4(parser_context_t* c, pd_OptionProxyType_V4_t* v);
parser_error_t _readOptionReferendumIndex_V4(parser_context_t* c, pd_OptionReferendumIndex_V4_t* v);
parser_error_t _readOptionStatementKind_V4(parser_context_t* c, pd_OptionStatementKind_V4_t* v);
parser_error_t _readOptionTimepoint_V4(parser_context_t* c, pd_OptionTimepoint_V4_t* v);
parser_error_t _readOptionTupleBalanceOfBalanceOfBlockNumber_V4(parser_context_t* c, pd_OptionTupleBalanceOfBalanceOfBlockNumber_V4_t* v);
parser_error_t _readPerbill_V4(parser_context_t* c, pd_Perbill_V4_t* v);
parser_error_t _readPercent_V4(parser_context_t* c, pd_Percent_V4_t* v);
parser_error_t _readPeriod_V4(parser_context_t* c, pd_Period_V4_t* v);
parser_error_t _readPriority_V4(parser_context_t* c, pd_Priority_V4_t* v);
parser_error_t _readProxyType_V4(parser_context_t* c, pd_ProxyType_V4_t* v);
parser_error_t _readReferendumIndex_V4(parser_context_t* c, pd_ReferendumIndex_V4_t* v);
parser_error_t _readRegistrarIndex_V4(parser_context_t* c, pd_RegistrarIndex_V4_t* v);
parser_error_t _readRenouncing_V4(parser_context_t* c, pd_Renouncing_V4_t* v);
parser_error_t _readRewardDestination_V4(parser_context_t* c, pd_RewardDestination_V4_t* v);
parser_error_t _readSignature_V4(parser_context_t* c, pd_Signature_V4_t* v);
parser_error_t _readStatementKind_V4(parser_context_t* c, pd_StatementKind_V4_t* v);
parser_error_t _readStreamDependency_V4(parser_context_t* c, pd_StreamDependency_V4_t* v);
parser_error_t _readTimepoint_V4(parser_context_t* c, pd_Timepoint_V4_t* v);
parser_error_t _readTupleAccountIdData_V4(parser_context_t* c, pd_TupleAccountIdData_V4_t* v);
parser_error_t _readTupleBalanceOfBalanceOfBlockNumber_V4(parser_context_t* c, pd_TupleBalanceOfBalanceOfBlockNumber_V4_t* v);
parser_error_t _readValidatorIndex_V4(parser_context_t* c, pd_ValidatorIndex_V4_t* v);
parser_error_t _readValidatorPrefs_V4(parser_context_t* c, pd_ValidatorPrefs_V4_t* v);
parser_error_t _readVecAccountId_V4(parser_context_t* c, pd_VecAccountId_V4_t* v);
parser_error_t _readVecKeyValue_V4(parser_context_t* c, pd_VecKeyValue_V4_t* v);
parser_error_t _readVecKey_V4(parser_context_t* c, pd_VecKey_V4_t* v);
parser_error_t _readVecLookupSource_V4(parser_context_t* c, pd_VecLookupSource_V4_t* v);
parser_error_t _readVecTupleAccountIdData_V4(parser_context_t* c, pd_VecTupleAccountIdData_V4_t* v);
parser_error_t _readVecValidatorIndex_V4(parser_context_t* c, pd_VecValidatorIndex_V4_t* v);
parser_error_t _readVestingInfo_V4(parser_context_t* c, pd_VestingInfo_V4_t* v);
parser_error_t _readVote_V4(parser_context_t* c, pd_Vote_V4_t* v);
parser_error_t _readWeight_V4(parser_context_t* c, pd_Weight_V4_t* v);
parser_error_t _readu8_array_32_V4(parser_context_t* c, pd_u8_array_32_V4_t* v);

// toString functions
parser_error_t _toStringAccountId_V4(
    const pd_AccountId_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIndex_V4(
    const pd_AccountIndex_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteSplit_V4(
    const pd_AccountVoteSplit_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteStandard_V4(
    const pd_AccountVoteStandard_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVote_V4(
    const pd_AccountVote_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCallHashOf_V4(
    const pd_CallHashOf_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringChangesTrieConfiguration_V4(
    const pd_ChangesTrieConfiguration_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAccountIndex_V4(
    const pd_CompactAccountIndex_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAssignments_V4(
    const pd_CompactAssignments_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactBountyIndex_V4(
    const pd_CompactBountyIndex_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactEraIndex_V4(
    const pd_CompactEraIndex_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactMemberCount_V4(
    const pd_CompactMemberCount_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactMoment_V4(
    const pd_CompactMoment_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactPerBill_V4(
    const pd_CompactPerBill_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactPropIndex_V4(
    const pd_CompactPropIndex_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactProposalIndex_V4(
    const pd_CompactProposalIndex_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactReferendumIndex_V4(
    const pd_CompactReferendumIndex_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactRegistrarIndex_V4(
    const pd_CompactRegistrarIndex_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactWeight_V4(
    const pd_CompactWeight_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConviction_V4(
    const pd_Conviction_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEcdsaSignature_V4(
    const pd_EcdsaSignature_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringElectionScore_V4(
    const pd_ElectionScore_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringElectionSize_V4(
    const pd_ElectionSize_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEquivocationProof_V4(
    const pd_EquivocationProof_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEraIndex_V4(
    const pd_EraIndex_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEthereumAddress_V4(
    const pd_EthereumAddress_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringIdentityFields_V4(
    const pd_IdentityFields_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringIdentityInfo_V4(
    const pd_IdentityInfo_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJudgement_V4(
    const pd_Judgement_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyOwnerProof_V4(
    const pd_KeyOwnerProof_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyValue_V4(
    const pd_KeyValue_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKey_V4(
    const pd_Key_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys_V4(
    const pd_Keys_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLookupSource_V4(
    const pd_LookupSource_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemberCount_V4(
    const pd_MemberCount_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOpaqueCall_V4(
    const pd_OpaqueCall_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionAccountId_V4(
    const pd_OptionAccountId_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionChangesTrieConfiguration_V4(
    const pd_OptionChangesTrieConfiguration_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionPeriod_V4(
    const pd_OptionPeriod_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionProxyType_V4(
    const pd_OptionProxyType_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionReferendumIndex_V4(
    const pd_OptionReferendumIndex_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionStatementKind_V4(
    const pd_OptionStatementKind_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTimepoint_V4(
    const pd_OptionTimepoint_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTupleBalanceOfBalanceOfBlockNumber_V4(
    const pd_OptionTupleBalanceOfBalanceOfBlockNumber_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill_V4(
    const pd_Perbill_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPercent_V4(
    const pd_Percent_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPeriod_V4(
    const pd_Period_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPriority_V4(
    const pd_Priority_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProxyType_V4(
    const pd_ProxyType_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringReferendumIndex_V4(
    const pd_ReferendumIndex_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRegistrarIndex_V4(
    const pd_RegistrarIndex_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRenouncing_V4(
    const pd_Renouncing_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRewardDestination_V4(
    const pd_RewardDestination_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSignature_V4(
    const pd_Signature_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringStatementKind_V4(
    const pd_StatementKind_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringStreamDependency_V4(
    const pd_StreamDependency_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTimepoint_V4(
    const pd_Timepoint_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleAccountIdData_V4(
    const pd_TupleAccountIdData_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleBalanceOfBalanceOfBlockNumber_V4(
    const pd_TupleBalanceOfBalanceOfBlockNumber_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidatorIndex_V4(
    const pd_ValidatorIndex_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidatorPrefs_V4(
    const pd_ValidatorPrefs_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId_V4(
    const pd_VecAccountId_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKeyValue_V4(
    const pd_VecKeyValue_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKey_V4(
    const pd_VecKey_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecLookupSource_V4(
    const pd_VecLookupSource_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleAccountIdData_V4(
    const pd_VecTupleAccountIdData_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecValidatorIndex_V4(
    const pd_VecValidatorIndex_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVestingInfo_V4(
    const pd_VestingInfo_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVote_V4(
    const pd_Vote_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeight_V4(
    const pd_Weight_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringu8_array_32_V4(
    const pd_u8_array_32_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
