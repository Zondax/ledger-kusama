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
#include "substrate_methods_V7.h"
#include "substrate_types_V7.h"
#include <stddef.h>
#include <stdint.h>

// Read functions
parser_error_t _readAccountId_V7(parser_context_t* c, pd_AccountId_V7_t* v);
parser_error_t _readAccountIndex_V7(parser_context_t* c, pd_AccountIndex_V7_t* v);
parser_error_t _readAccountVoteBalanceOfT_V7(parser_context_t* c, pd_AccountVoteBalanceOfT_V7_t* v);
parser_error_t _readAuthorityIdasRuntimeAppPublicSignature_V7(parser_context_t* c, pd_AuthorityIdasRuntimeAppPublicSignature_V7_t* v);
parser_error_t _readBoxEquivocationProofHashBlockNumber_V7(parser_context_t* c, pd_BoxEquivocationProofHashBlockNumber_V7_t* v);
parser_error_t _readBoxEquivocationProofHeader_V7(parser_context_t* c, pd_BoxEquivocationProofHeader_V7_t* v);
parser_error_t _readBoxIdentityInfoMaxAdditionalFields_V7(parser_context_t* c, pd_BoxIdentityInfoMaxAdditionalFields_V7_t* v);
parser_error_t _readBoxMultiLocation_V7(parser_context_t* c, pd_BoxMultiLocation_V7_t* v);
parser_error_t _readBoxRawSolutionSolutionOfT_V7(parser_context_t* c, pd_BoxRawSolutionSolutionOfT_V7_t* v);
parser_error_t _readBoxTasConfigIProposal_V7(parser_context_t* c, pd_BoxTasConfigIProposal_V7_t* v);
parser_error_t _readBoxVersionedMultiAssets_V7(parser_context_t* c, pd_BoxVersionedMultiAssets_V7_t* v);
parser_error_t _readBoxVersionedMultiLocation_V7(parser_context_t* c, pd_BoxVersionedMultiLocation_V7_t* v);
parser_error_t _readBoxVersionedXcmTasSysConfigCall_V7(parser_context_t* c, pd_BoxVersionedXcmTasSysConfigCall_V7_t* v);
parser_error_t _readBoxVersionedXcmTuple_V7(parser_context_t* c, pd_BoxVersionedXcmTuple_V7_t* v);
parser_error_t _readCallHashOfT_V7(parser_context_t* c, pd_CallHashOfT_V7_t* v);
parser_error_t _readChangesTrieConfiguration_V7(parser_context_t* c, pd_ChangesTrieConfiguration_V7_t* v);
parser_error_t _readCompactAccountIndex_V7(parser_context_t* c, pd_CompactAccountIndex_V7_t* v);
parser_error_t _readCompactPerBill_V7(parser_context_t* c, pd_CompactPerBill_V7_t* v);
parser_error_t _readConviction_V7(parser_context_t* c, pd_Conviction_V7_t* v);
parser_error_t _readEcdsaSignature_V7(parser_context_t* c, pd_EcdsaSignature_V7_t* v);
parser_error_t _readElectionScore_V7(parser_context_t* c, pd_ElectionScore_V7_t* v);
parser_error_t _readEraIndex_V7(parser_context_t* c, pd_EraIndex_V7_t* v);
parser_error_t _readEthereumAddress_V7(parser_context_t* c, pd_EthereumAddress_V7_t* v);
parser_error_t _readHeadData_V7(parser_context_t* c, pd_HeadData_V7_t* v);
parser_error_t _readHeartbeatBlockNumber_V7(parser_context_t* c, pd_HeartbeatBlockNumber_V7_t* v);
parser_error_t _readHrmpChannelId_V7(parser_context_t* c, pd_HrmpChannelId_V7_t* v);
parser_error_t _readIdentityFields_V7(parser_context_t* c, pd_IdentityFields_V7_t* v);
parser_error_t _readJudgementBalanceOfT_V7(parser_context_t* c, pd_JudgementBalanceOfT_V7_t* v);
parser_error_t _readJudgement_V7(parser_context_t* c, pd_Judgement_V7_t* v);
parser_error_t _readKeyOwnerProof_V7(parser_context_t* c, pd_KeyOwnerProof_V7_t* v);
parser_error_t _readKeyValue_V7(parser_context_t* c, pd_KeyValue_V7_t* v);
parser_error_t _readKey_V7(parser_context_t* c, pd_Key_V7_t* v);
parser_error_t _readKeys_V7(parser_context_t* c, pd_Keys_V7_t* v);
parser_error_t _readLeasePeriodOfT_V7(parser_context_t* c, pd_LeasePeriodOfT_V7_t* v);
parser_error_t _readLookupasStaticLookupSource_V7(parser_context_t* c, pd_LookupasStaticLookupSource_V7_t* v);
parser_error_t _readMemberCount_V7(parser_context_t* c, pd_MemberCount_V7_t* v);
parser_error_t _readMultiSignature_V7(parser_context_t* c, pd_MultiSignature_V7_t* v);
parser_error_t _readMultiSigner_V7(parser_context_t* c, pd_MultiSigner_V7_t* v);
parser_error_t _readNextConfigDescriptor_V7(parser_context_t* c, pd_NextConfigDescriptor_V7_t* v);
parser_error_t _readOpaqueCall_V7(parser_context_t* c, pd_OpaqueCall_V7_t* v);
parser_error_t _readOptionAccountId_V7(parser_context_t* c, pd_OptionAccountId_V7_t* v);
parser_error_t _readOptionChangesTrieConfiguration_V7(parser_context_t* c, pd_OptionChangesTrieConfiguration_V7_t* v);
parser_error_t _readOptionElectionScore_V7(parser_context_t* c, pd_OptionElectionScore_V7_t* v);
parser_error_t _readOptionMultiSignature_V7(parser_context_t* c, pd_OptionMultiSignature_V7_t* v);
parser_error_t _readOptionMultiSigner_V7(parser_context_t* c, pd_OptionMultiSigner_V7_t* v);
parser_error_t _readOptionPercent_V7(parser_context_t* c, pd_OptionPercent_V7_t* v);
parser_error_t _readOptionProxyType_V7(parser_context_t* c, pd_OptionProxyType_V7_t* v);
parser_error_t _readOptionReferendumIndex_V7(parser_context_t* c, pd_OptionReferendumIndex_V7_t* v);
parser_error_t _readOptionStatementKind_V7(parser_context_t* c, pd_OptionStatementKind_V7_t* v);
parser_error_t _readOptionTimepoint_V7(parser_context_t* c, pd_OptionTimepoint_V7_t* v);
parser_error_t _readOptionTupleBalanceOfTBalanceOfTBlockNumber_V7(parser_context_t* c, pd_OptionTupleBalanceOfTBalanceOfTBlockNumber_V7_t* v);
parser_error_t _readOptionXcmVersion_V7(parser_context_t* c, pd_OptionXcmVersion_V7_t* v);
parser_error_t _readOptionschedulePeriodBlockNumber_V7(parser_context_t* c, pd_OptionschedulePeriodBlockNumber_V7_t* v);
parser_error_t _readOverweightIndex_V7(parser_context_t* c, pd_OverweightIndex_V7_t* v);
parser_error_t _readParaId_V7(parser_context_t* c, pd_ParaId_V7_t* v);
parser_error_t _readParachainsInherentDataHeader_V7(parser_context_t* c, pd_ParachainsInherentDataHeader_V7_t* v);
parser_error_t _readPerbill_V7(parser_context_t* c, pd_Perbill_V7_t* v);
parser_error_t _readPercent_V7(parser_context_t* c, pd_Percent_V7_t* v);
parser_error_t _readProxyType_V7(parser_context_t* c, pd_ProxyType_V7_t* v);
parser_error_t _readReferendumIndex_V7(parser_context_t* c, pd_ReferendumIndex_V7_t* v);
parser_error_t _readRegistrarIndex_V7(parser_context_t* c, pd_RegistrarIndex_V7_t* v);
parser_error_t _readRenouncing_V7(parser_context_t* c, pd_Renouncing_V7_t* v);
parser_error_t _readRewardDestination_V7(parser_context_t* c, pd_RewardDestination_V7_t* v);
parser_error_t _readSessionIndex_V7(parser_context_t* c, pd_SessionIndex_V7_t* v);
parser_error_t _readSolutionOrSnapshotSize_V7(parser_context_t* c, pd_SolutionOrSnapshotSize_V7_t* v);
parser_error_t _readStatementKind_V7(parser_context_t* c, pd_StatementKind_V7_t* v);
parser_error_t _readSupportsAccountId_V7(parser_context_t* c, pd_SupportsAccountId_V7_t* v);
parser_error_t _readTimepoint_V7(parser_context_t* c, pd_Timepoint_V7_t* v);
parser_error_t _readTupleAccountIdData_V7(parser_context_t* c, pd_TupleAccountIdData_V7_t* v);
parser_error_t _readTupleBalanceOfTBalanceOfTBlockNumber_V7(parser_context_t* c, pd_TupleBalanceOfTBalanceOfTBlockNumber_V7_t* v);
parser_error_t _readValidationCode_V7(parser_context_t* c, pd_ValidationCode_V7_t* v);
parser_error_t _readValidatorPrefs_V7(parser_context_t* c, pd_ValidatorPrefs_V7_t* v);
parser_error_t _readVecAccountId_V7(parser_context_t* c, pd_VecAccountId_V7_t* v);
parser_error_t _readVecKeyValue_V7(parser_context_t* c, pd_VecKeyValue_V7_t* v);
parser_error_t _readVecKey_V7(parser_context_t* c, pd_VecKey_V7_t* v);
parser_error_t _readVecLookupasStaticLookupSource_V7(parser_context_t* c, pd_VecLookupasStaticLookupSource_V7_t* v);
parser_error_t _readVecTupleAccountIdData_V7(parser_context_t* c, pd_VecTupleAccountIdData_V7_t* v);
parser_error_t _readVestingInfoBalanceOfTBlockNumber_V7(parser_context_t* c, pd_VestingInfoBalanceOfTBlockNumber_V7_t* v);
parser_error_t _readWeight_V7(parser_context_t* c, pd_Weight_V7_t* v);
parser_error_t _readXcmVersion_V7(parser_context_t* c, pd_XcmVersion_V7_t* v);
parser_error_t _readschedulePeriodBlockNumber_V7(parser_context_t* c, pd_schedulePeriodBlockNumber_V7_t* v);
parser_error_t _readschedulePriority_V7(parser_context_t* c, pd_schedulePriority_V7_t* v);

// toString functions
parser_error_t _toStringAccountId_V7(
    const pd_AccountId_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIndex_V7(
    const pd_AccountIndex_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteBalanceOfT_V7(
    const pd_AccountVoteBalanceOfT_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAuthorityIdasRuntimeAppPublicSignature_V7(
    const pd_AuthorityIdasRuntimeAppPublicSignature_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxEquivocationProofHashBlockNumber_V7(
    const pd_BoxEquivocationProofHashBlockNumber_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxEquivocationProofHeader_V7(
    const pd_BoxEquivocationProofHeader_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxIdentityInfoMaxAdditionalFields_V7(
    const pd_BoxIdentityInfoMaxAdditionalFields_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxMultiLocation_V7(
    const pd_BoxMultiLocation_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxRawSolutionSolutionOfT_V7(
    const pd_BoxRawSolutionSolutionOfT_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxTasConfigIProposal_V7(
    const pd_BoxTasConfigIProposal_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedMultiAssets_V7(
    const pd_BoxVersionedMultiAssets_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedMultiLocation_V7(
    const pd_BoxVersionedMultiLocation_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedXcmTasSysConfigCall_V7(
    const pd_BoxVersionedXcmTasSysConfigCall_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedXcmTuple_V7(
    const pd_BoxVersionedXcmTuple_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCallHashOfT_V7(
    const pd_CallHashOfT_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringChangesTrieConfiguration_V7(
    const pd_ChangesTrieConfiguration_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAccountIndex_V7(
    const pd_CompactAccountIndex_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactPerBill_V7(
    const pd_CompactPerBill_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConviction_V7(
    const pd_Conviction_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEcdsaSignature_V7(
    const pd_EcdsaSignature_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringElectionScore_V7(
    const pd_ElectionScore_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEraIndex_V7(
    const pd_EraIndex_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEthereumAddress_V7(
    const pd_EthereumAddress_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringHeadData_V7(
    const pd_HeadData_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringHeartbeatBlockNumber_V7(
    const pd_HeartbeatBlockNumber_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringHrmpChannelId_V7(
    const pd_HrmpChannelId_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringIdentityFields_V7(
    const pd_IdentityFields_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJudgementBalanceOfT_V7(
    const pd_JudgementBalanceOfT_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJudgement_V7(
    const pd_Judgement_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyOwnerProof_V7(
    const pd_KeyOwnerProof_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyValue_V7(
    const pd_KeyValue_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKey_V7(
    const pd_Key_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys_V7(
    const pd_Keys_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLeasePeriodOfT_V7(
    const pd_LeasePeriodOfT_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLookupasStaticLookupSource_V7(
    const pd_LookupasStaticLookupSource_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemberCount_V7(
    const pd_MemberCount_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiSignature_V7(
    const pd_MultiSignature_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiSigner_V7(
    const pd_MultiSigner_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringNextConfigDescriptor_V7(
    const pd_NextConfigDescriptor_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOpaqueCall_V7(
    const pd_OpaqueCall_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionAccountId_V7(
    const pd_OptionAccountId_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionChangesTrieConfiguration_V7(
    const pd_OptionChangesTrieConfiguration_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionElectionScore_V7(
    const pd_OptionElectionScore_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMultiSignature_V7(
    const pd_OptionMultiSignature_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMultiSigner_V7(
    const pd_OptionMultiSigner_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionPercent_V7(
    const pd_OptionPercent_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionProxyType_V7(
    const pd_OptionProxyType_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionReferendumIndex_V7(
    const pd_OptionReferendumIndex_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionStatementKind_V7(
    const pd_OptionStatementKind_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTimepoint_V7(
    const pd_OptionTimepoint_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTupleBalanceOfTBalanceOfTBlockNumber_V7(
    const pd_OptionTupleBalanceOfTBalanceOfTBlockNumber_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionXcmVersion_V7(
    const pd_OptionXcmVersion_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionschedulePeriodBlockNumber_V7(
    const pd_OptionschedulePeriodBlockNumber_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOverweightIndex_V7(
    const pd_OverweightIndex_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringParaId_V7(
    const pd_ParaId_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringParachainsInherentDataHeader_V7(
    const pd_ParachainsInherentDataHeader_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill_V7(
    const pd_Perbill_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPercent_V7(
    const pd_Percent_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProxyType_V7(
    const pd_ProxyType_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringReferendumIndex_V7(
    const pd_ReferendumIndex_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRegistrarIndex_V7(
    const pd_RegistrarIndex_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRenouncing_V7(
    const pd_Renouncing_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRewardDestination_V7(
    const pd_RewardDestination_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSessionIndex_V7(
    const pd_SessionIndex_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSolutionOrSnapshotSize_V7(
    const pd_SolutionOrSnapshotSize_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringStatementKind_V7(
    const pd_StatementKind_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSupportsAccountId_V7(
    const pd_SupportsAccountId_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTimepoint_V7(
    const pd_Timepoint_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleAccountIdData_V7(
    const pd_TupleAccountIdData_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleBalanceOfTBalanceOfTBlockNumber_V7(
    const pd_TupleBalanceOfTBalanceOfTBlockNumber_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidationCode_V7(
    const pd_ValidationCode_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidatorPrefs_V7(
    const pd_ValidatorPrefs_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId_V7(
    const pd_VecAccountId_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKeyValue_V7(
    const pd_VecKeyValue_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKey_V7(
    const pd_VecKey_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecLookupasStaticLookupSource_V7(
    const pd_VecLookupasStaticLookupSource_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleAccountIdData_V7(
    const pd_VecTupleAccountIdData_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVestingInfoBalanceOfTBlockNumber_V7(
    const pd_VestingInfoBalanceOfTBlockNumber_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeight_V7(
    const pd_Weight_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringXcmVersion_V7(
    const pd_XcmVersion_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringschedulePeriodBlockNumber_V7(
    const pd_schedulePeriodBlockNumber_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringschedulePriority_V7(
    const pd_schedulePriority_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
