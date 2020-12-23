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
#include "substrate_methods_V3.h"
#include "substrate_types_V3.h"
#include <stddef.h>
#include <stdint.h>

// Read functions
parser_error_t _readAccountId_V3(parser_context_t* c, pd_AccountId_V3_t* v);
parser_error_t _readAccountIndex_V3(parser_context_t* c, pd_AccountIndex_V3_t* v);
parser_error_t _readAccountVoteSplit_V3(parser_context_t* c, pd_AccountVoteSplit_V3_t* v);
parser_error_t _readAccountVoteStandard_V3(parser_context_t* c, pd_AccountVoteStandard_V3_t* v);
parser_error_t _readAccountVote_V3(parser_context_t* c, pd_AccountVote_V3_t* v);
parser_error_t _readCallHashOf_V3(parser_context_t* c, pd_CallHashOf_V3_t* v);
parser_error_t _readCall_V3(parser_context_t* c, pd_Call_V3_t* v);
parser_error_t _readChangesTrieConfiguration_V3(parser_context_t* c, pd_ChangesTrieConfiguration_V3_t* v);
parser_error_t _readCompactAssignments_V3(parser_context_t* c, pd_CompactAssignments_V3_t* v);
parser_error_t _readCompactBountyIndex_V3(parser_context_t* c, pd_CompactBountyIndex_V3_t* v);
parser_error_t _readCompactEraIndex_V3(parser_context_t* c, pd_CompactEraIndex_V3_t* v);
parser_error_t _readCompactMemberCount_V3(parser_context_t* c, pd_CompactMemberCount_V3_t* v);
parser_error_t _readCompactMoment_V3(parser_context_t* c, pd_CompactMoment_V3_t* v);
parser_error_t _readCompactPerBill_V3(parser_context_t* c, pd_CompactPerBill_V3_t* v);
parser_error_t _readCompactPropIndex_V3(parser_context_t* c, pd_CompactPropIndex_V3_t* v);
parser_error_t _readCompactProposalIndex_V3(parser_context_t* c, pd_CompactProposalIndex_V3_t* v);
parser_error_t _readCompactReferendumIndex_V3(parser_context_t* c, pd_CompactReferendumIndex_V3_t* v);
parser_error_t _readCompactRegistrarIndex_V3(parser_context_t* c, pd_CompactRegistrarIndex_V3_t* v);
parser_error_t _readCompactWeight_V3(parser_context_t* c, pd_CompactWeight_V3_t* v);
parser_error_t _readConviction_V3(parser_context_t* c, pd_Conviction_V3_t* v);
parser_error_t _readDefunctVoter_V3(parser_context_t* c, pd_DefunctVoter_V3_t* v);
parser_error_t _readEcdsaSignature_V3(parser_context_t* c, pd_EcdsaSignature_V3_t* v);
parser_error_t _readElectionScore_V3(parser_context_t* c, pd_ElectionScore_V3_t* v);
parser_error_t _readElectionSize_V3(parser_context_t* c, pd_ElectionSize_V3_t* v);
parser_error_t _readEquivocationProof_V3(parser_context_t* c, pd_EquivocationProof_V3_t* v);
parser_error_t _readEraIndex_V3(parser_context_t* c, pd_EraIndex_V3_t* v);
parser_error_t _readEthereumAddress_V3(parser_context_t* c, pd_EthereumAddress_V3_t* v);
parser_error_t _readIdentityFields_V3(parser_context_t* c, pd_IdentityFields_V3_t* v);
parser_error_t _readIdentityInfo_V3(parser_context_t* c, pd_IdentityInfo_V3_t* v);
parser_error_t _readJudgement_V3(parser_context_t* c, pd_Judgement_V3_t* v);
parser_error_t _readKeyOwnerProof_V3(parser_context_t* c, pd_KeyOwnerProof_V3_t* v);
parser_error_t _readKeyValue_V3(parser_context_t* c, pd_KeyValue_V3_t* v);
parser_error_t _readKey_V3(parser_context_t* c, pd_Key_V3_t* v);
parser_error_t _readKeys_V3(parser_context_t* c, pd_Keys_V3_t* v);
parser_error_t _readMemberCount_V3(parser_context_t* c, pd_MemberCount_V3_t* v);
parser_error_t _readOpaqueCall_V3(parser_context_t* c, pd_OpaqueCall_V3_t* v);
parser_error_t _readOptionAccountId_V3(parser_context_t* c, pd_OptionAccountId_V3_t* v);
parser_error_t _readOptionChangesTrieConfiguration_V3(parser_context_t* c, pd_OptionChangesTrieConfiguration_V3_t* v);
parser_error_t _readOptionPeriod_V3(parser_context_t* c, pd_OptionPeriod_V3_t* v);
parser_error_t _readOptionProxyType_V3(parser_context_t* c, pd_OptionProxyType_V3_t* v);
parser_error_t _readOptionReferendumIndex_V3(parser_context_t* c, pd_OptionReferendumIndex_V3_t* v);
parser_error_t _readOptionStatementKind_V3(parser_context_t* c, pd_OptionStatementKind_V3_t* v);
parser_error_t _readOptionTimepoint_V3(parser_context_t* c, pd_OptionTimepoint_V3_t* v);
parser_error_t _readOptionTupleBalanceOfBalanceOfBlockNumber_V3(parser_context_t* c, pd_OptionTupleBalanceOfBalanceOfBlockNumber_V3_t* v);
parser_error_t _readPerbill_V3(parser_context_t* c, pd_Perbill_V3_t* v);
parser_error_t _readPercent_V3(parser_context_t* c, pd_Percent_V3_t* v);
parser_error_t _readPeriod_V3(parser_context_t* c, pd_Period_V3_t* v);
parser_error_t _readPriority_V3(parser_context_t* c, pd_Priority_V3_t* v);
parser_error_t _readProxyType_V3(parser_context_t* c, pd_ProxyType_V3_t* v);
parser_error_t _readReferendumIndex_V3(parser_context_t* c, pd_ReferendumIndex_V3_t* v);
parser_error_t _readRegistrarIndex_V3(parser_context_t* c, pd_RegistrarIndex_V3_t* v);
parser_error_t _readRenouncing_V3(parser_context_t* c, pd_Renouncing_V3_t* v);
parser_error_t _readRewardDestination_V3(parser_context_t* c, pd_RewardDestination_V3_t* v);
parser_error_t _readSignature_V3(parser_context_t* c, pd_Signature_V3_t* v);
parser_error_t _readStatementKind_V3(parser_context_t* c, pd_StatementKind_V3_t* v);
parser_error_t _readStreamDependency_V3(parser_context_t* c, pd_StreamDependency_V3_t* v);
parser_error_t _readTimepoint_V3(parser_context_t* c, pd_Timepoint_V3_t* v);
parser_error_t _readTupleAccountIdData_V3(parser_context_t* c, pd_TupleAccountIdData_V3_t* v);
parser_error_t _readTupleBalanceOfBalanceOfBlockNumber_V3(parser_context_t* c, pd_TupleBalanceOfBalanceOfBlockNumber_V3_t* v);
parser_error_t _readValidatorIndex_V3(parser_context_t* c, pd_ValidatorIndex_V3_t* v);
parser_error_t _readValidatorPrefs_V3(parser_context_t* c, pd_ValidatorPrefs_V3_t* v);
parser_error_t _readVecAccountId_V3(parser_context_t* c, pd_VecAccountId_V3_t* v);
parser_error_t _readVecCall_V3(parser_context_t* c, pd_VecCall_V3_t* v);
parser_error_t _readVecKeyValue_V3(parser_context_t* c, pd_VecKeyValue_V3_t* v);
parser_error_t _readVecKey_V3(parser_context_t* c, pd_VecKey_V3_t* v);
parser_error_t _readVecTupleAccountIdData_V3(parser_context_t* c, pd_VecTupleAccountIdData_V3_t* v);
parser_error_t _readVecValidatorIndex_V3(parser_context_t* c, pd_VecValidatorIndex_V3_t* v);
parser_error_t _readVestingInfo_V3(parser_context_t* c, pd_VestingInfo_V3_t* v);
parser_error_t _readVote_V3(parser_context_t* c, pd_Vote_V3_t* v);
parser_error_t _readWeight_V3(parser_context_t* c, pd_Weight_V3_t* v);
parser_error_t _readu8_array_32_V3(parser_context_t* c, pd_u8_array_32_V3_t* v);

// toString functions
parser_error_t _toStringAccountId_V3(
    const pd_AccountId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIndex_V3(
    const pd_AccountIndex_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteSplit_V3(
    const pd_AccountVoteSplit_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteStandard_V3(
    const pd_AccountVoteStandard_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVote_V3(
    const pd_AccountVote_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCallHashOf_V3(
    const pd_CallHashOf_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCall_V3(
    const pd_Call_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringChangesTrieConfiguration_V3(
    const pd_ChangesTrieConfiguration_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAssignments_V3(
    const pd_CompactAssignments_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactBountyIndex_V3(
    const pd_CompactBountyIndex_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactEraIndex_V3(
    const pd_CompactEraIndex_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactMemberCount_V3(
    const pd_CompactMemberCount_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactMoment_V3(
    const pd_CompactMoment_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactPerBill_V3(
    const pd_CompactPerBill_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactPropIndex_V3(
    const pd_CompactPropIndex_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactProposalIndex_V3(
    const pd_CompactProposalIndex_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactReferendumIndex_V3(
    const pd_CompactReferendumIndex_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactRegistrarIndex_V3(
    const pd_CompactRegistrarIndex_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactWeight_V3(
    const pd_CompactWeight_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConviction_V3(
    const pd_Conviction_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDefunctVoter_V3(
    const pd_DefunctVoter_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEcdsaSignature_V3(
    const pd_EcdsaSignature_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringElectionScore_V3(
    const pd_ElectionScore_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringElectionSize_V3(
    const pd_ElectionSize_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEquivocationProof_V3(
    const pd_EquivocationProof_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEraIndex_V3(
    const pd_EraIndex_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEthereumAddress_V3(
    const pd_EthereumAddress_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringIdentityFields_V3(
    const pd_IdentityFields_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringIdentityInfo_V3(
    const pd_IdentityInfo_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJudgement_V3(
    const pd_Judgement_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyOwnerProof_V3(
    const pd_KeyOwnerProof_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyValue_V3(
    const pd_KeyValue_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKey_V3(
    const pd_Key_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys_V3(
    const pd_Keys_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemberCount_V3(
    const pd_MemberCount_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOpaqueCall_V3(
    const pd_OpaqueCall_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionAccountId_V3(
    const pd_OptionAccountId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionChangesTrieConfiguration_V3(
    const pd_OptionChangesTrieConfiguration_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionPeriod_V3(
    const pd_OptionPeriod_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionProxyType_V3(
    const pd_OptionProxyType_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionReferendumIndex_V3(
    const pd_OptionReferendumIndex_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionStatementKind_V3(
    const pd_OptionStatementKind_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTimepoint_V3(
    const pd_OptionTimepoint_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTupleBalanceOfBalanceOfBlockNumber_V3(
    const pd_OptionTupleBalanceOfBalanceOfBlockNumber_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill_V3(
    const pd_Perbill_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPercent_V3(
    const pd_Percent_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPeriod_V3(
    const pd_Period_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPriority_V3(
    const pd_Priority_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProxyType_V3(
    const pd_ProxyType_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringReferendumIndex_V3(
    const pd_ReferendumIndex_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRegistrarIndex_V3(
    const pd_RegistrarIndex_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRenouncing_V3(
    const pd_Renouncing_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRewardDestination_V3(
    const pd_RewardDestination_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSignature_V3(
    const pd_Signature_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringStatementKind_V3(
    const pd_StatementKind_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringStreamDependency_V3(
    const pd_StreamDependency_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTimepoint_V3(
    const pd_Timepoint_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleAccountIdData_V3(
    const pd_TupleAccountIdData_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleBalanceOfBalanceOfBlockNumber_V3(
    const pd_TupleBalanceOfBalanceOfBlockNumber_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidatorIndex_V3(
    const pd_ValidatorIndex_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidatorPrefs_V3(
    const pd_ValidatorPrefs_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId_V3(
    const pd_VecAccountId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecCall_V3(
    const pd_VecCall_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKeyValue_V3(
    const pd_VecKeyValue_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKey_V3(
    const pd_VecKey_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleAccountIdData_V3(
    const pd_VecTupleAccountIdData_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecValidatorIndex_V3(
    const pd_VecValidatorIndex_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVestingInfo_V3(
    const pd_VestingInfo_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVote_V3(
    const pd_Vote_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeight_V3(
    const pd_Weight_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringu8_array_32_V3(
    const pd_u8_array_32_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _readProposal_V3(parser_context_t* c, pd_Proposal_V3_t* v);
parser_error_t _toStringProposal_V3(
    const pd_Proposal_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
