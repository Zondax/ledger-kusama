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
#include "bignum.h"
#include "coin.h"
#include "parser_impl.h"
#include "substrate_dispatch_V5.h"
#include "substrate_strings.h"

#include <stddef.h>
#include <stdint.h>
#include <zxmacros.h>

parser_error_t _readCompactActiveIndex_V5(parser_context_t* c, pd_CompactActiveIndex_V5_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readCompactAuctionIndex_V5(parser_context_t* c, pd_CompactAuctionIndex_V5_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readCompactBountyIndex_V5(parser_context_t* c, pd_CompactBountyIndex_V5_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readCompactEraIndex_V5(parser_context_t* c, pd_CompactEraIndex_V5_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readCompactLeasePeriodOf_V5(parser_context_t* c, pd_CompactLeasePeriodOf_V5_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readCompactMemberCount_V5(parser_context_t* c, pd_CompactMemberCount_V5_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readCompactMoment_V5(parser_context_t* c, pd_CompactMoment_V5_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readCompactParaId_V5(parser_context_t* c, pd_CompactParaId_V5_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readCompactPerquintill_V5(parser_context_t* c, pd_CompactPerquintill_V5_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readCompactPropIndex_V5(parser_context_t* c, pd_CompactPropIndex_V5_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readCompactProposalIndex_V5(parser_context_t* c, pd_CompactProposalIndex_V5_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readCompactReferendumIndex_V5(parser_context_t* c, pd_CompactReferendumIndex_V5_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readCompactRegistrarIndex_V5(parser_context_t* c, pd_CompactRegistrarIndex_V5_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readCompactWeight_V5(parser_context_t* c, pd_CompactWeight_V5_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readAccountId_V5(parser_context_t* c, pd_AccountId_V5_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readAccountIndex_V5(parser_context_t* c, pd_AccountIndex_V5_t* v)
{
    return _readUInt32(c, &v->value);
}

parser_error_t _readAccountVoteSplit_V5(parser_context_t* c, pd_AccountVoteSplit_V5_t* v)
{
    CHECK_ERROR(_readBalanceOf(c, &v->aye))
    CHECK_ERROR(_readBalanceOf(c, &v->nay))
    return parser_ok;
}

parser_error_t _readAccountVoteStandard_V5(parser_context_t* c, pd_AccountVoteStandard_V5_t* v)
{
    CHECK_ERROR(_readVote_V5(c, &v->vote))
    CHECK_ERROR(_readBalanceOf(c, &v->balance))
    return parser_ok;
}

parser_error_t _readAccountVote_V5(parser_context_t* c, pd_AccountVote_V5_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))

    switch (v->value) {
    case 0:
        CHECK_ERROR(_readAccountVoteStandard_V5(c, &v->voteStandard))
        break;
    case 1:
        CHECK_ERROR(_readAccountVoteSplit_V5(c, &v->voteSplit))
        break;
    default:
        break;
    }

    return parser_ok;
}

parser_error_t _readBabeEquivocationProof_V5(parser_context_t* c, pd_BabeEquivocationProof_V5_t* v)
{
    return parser_not_supported;
}

parser_error_t _readCallHashOf_V5(parser_context_t* c, pd_CallHashOf_V5_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readChangesTrieConfiguration_V5(parser_context_t* c, pd_ChangesTrieConfiguration_V5_t* v)
{
    CHECK_ERROR(_readu32(c, &v->digest_interval))
    CHECK_ERROR(_readu32(c, &v->digest_levels))
    return parser_ok;
}

parser_error_t _readCompactAccountIndex_V5(parser_context_t* c, pd_CompactAccountIndex_V5_t* v)
{
    return _readCompactInt(c, &v->value);
}

parser_error_t _readCompactPerBill_V5(parser_context_t* c, pd_CompactPerBill_V5_t* v)
{
    return _readCompactInt(c, &v->value);
}

parser_error_t _readConviction_V5(parser_context_t* c, pd_Conviction_V5_t* v)
{
    CHECK_INPUT()

    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value > 5) {
        return parser_value_out_of_range;
    }

    return parser_ok;
}

parser_error_t _readEcdsaSignature_V5(parser_context_t* c, pd_EcdsaSignature_V5_t* v) {
    GEN_DEF_READARRAY(65)
}

parser_error_t _readElectionScore_V5(parser_context_t* c, pd_ElectionScore_V5_t* v)
{
    return parser_not_supported;
}

parser_error_t _readEraIndex_V5(parser_context_t* c, pd_EraIndex_V5_t* v)
{
    return _readUInt32(c, &v->value);
}

parser_error_t _readEthereumAddress_V5(parser_context_t* c, pd_EthereumAddress_V5_t* v) {
    GEN_DEF_READARRAY(20)
}

parser_error_t _readGrandpaEquivocationProof_V5(parser_context_t* c, pd_GrandpaEquivocationProof_V5_t* v)
{
    return parser_not_supported;
}

parser_error_t _readHeadData_V5(parser_context_t* c, pd_HeadData_V5_t* v)
{
    return parser_not_supported;
}

parser_error_t _readHrmpChannelId_V5(parser_context_t* c, pd_HrmpChannelId_V5_t* v)
{
    return parser_not_supported;
}

parser_error_t _readIdentityFields_V5(parser_context_t* c, pd_IdentityFields_V5_t* v)
{
    return parser_not_supported;
}

parser_error_t _readIdentityInfo_V5(parser_context_t* c, pd_IdentityInfo_V5_t* v)
{
    CHECK_ERROR(_readVecTupleDataData(c, &v->additional))
    CHECK_ERROR(_readData(c, &v->display))
    CHECK_ERROR(_readData(c, &v->legal))
    CHECK_ERROR(_readData(c, &v->web))
    CHECK_ERROR(_readData(c, &v->riot))
    CHECK_ERROR(_readData(c, &v->email))
    CHECK_ERROR(_readOptionu8_array_20(c, &v->pgp_fingerprint))
    CHECK_ERROR(_readData(c, &v->image))
    CHECK_ERROR(_readData(c, &v->twitter))
    return parser_ok;
}

parser_error_t _readIdentityJudgement_V5(parser_context_t* c, pd_IdentityJudgement_V5_t* v)
{
    return parser_not_supported;
}

parser_error_t _readKeyOwnerProof_V5(parser_context_t* c, pd_KeyOwnerProof_V5_t* v)
{
    return parser_not_supported;
}

parser_error_t _readKeyValue_V5(parser_context_t* c, pd_KeyValue_V5_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readKey_V5(parser_context_t* c, pd_Key_V5_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readKeys_V5(parser_context_t* c, pd_Keys_V5_t* v) {
    GEN_DEF_READARRAY(6 * 32)
}

parser_error_t _readLeasePeriodOf_V5(parser_context_t* c, pd_LeasePeriodOf_V5_t* v)
{
    return parser_not_supported;
}

parser_error_t _readLookupSource_V5(parser_context_t* c, pd_LookupSource_V5_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Id
        CHECK_ERROR(_readAccountId_V5(c, &v->id))
        break;
    case 1: // Index
        CHECK_ERROR(_readCompactAccountIndex_V5(c, &v->index))
        break;
    case 2: // Raw
        CHECK_ERROR(_readBytes(c, &v->raw))
        break;
    case 3: // Address32
        GEN_DEF_READARRAY(32)
    case 4: // Address20
        GEN_DEF_READARRAY(20)
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readMemberCount_V5(parser_context_t* c, pd_MemberCount_V5_t* v)
{
    return _readUInt32(c, &v->value);
}

parser_error_t _readMultiAsset_V5(parser_context_t* c, pd_MultiAsset_V5_t* v)
{
    return parser_not_supported;
}

parser_error_t _readMultiLocation_V5(parser_context_t* c, pd_MultiLocation_V5_t* v)
{
    return parser_not_supported;
}

parser_error_t _readMultiSignature_V5(parser_context_t* c, pd_MultiSignature_V5_t* v)
{
    return parser_not_supported;
}

parser_error_t _readMultiSigner_V5(parser_context_t* c, pd_MultiSigner_V5_t* v)
{
    return parser_not_supported;
}

parser_error_t _readNextConfigDescriptor_V5(parser_context_t* c, pd_NextConfigDescriptor_V5_t* v)
{
    return parser_not_supported;
}

parser_error_t _readOpaqueCall_V5(parser_context_t* c, pd_OpaqueCall_V5_t* v)
{
    // Encoded as Byte[], array size comes first
    uint8_t size;
    CHECK_ERROR(_readUInt8(c, &size))
    return _readCall(c, &v->call);
}

parser_error_t _readParaId_V5(parser_context_t* c, pd_ParaId_V5_t* v)
{
    return parser_not_supported;
}

parser_error_t _readParachainsInherentData_V5(parser_context_t* c, pd_ParachainsInherentData_V5_t* v)
{
    return parser_not_supported;
}

parser_error_t _readPerbill_V5(parser_context_t* c, pd_Perbill_V5_t* v)
{
    return _readUInt32(c, &v->value);
}

parser_error_t _readPercent_V5(parser_context_t* c, pd_Percent_V5_t* v)
{
    return _readCompactInt(c, &v->value);
}

parser_error_t _readPeriod_V5(parser_context_t* c, pd_Period_V5_t* v)
{
    return _readUInt64(c, &v->value);
}

parser_error_t _readPriority_V5(parser_context_t* c, pd_Priority_V5_t* v)
{
    CHECK_ERROR(_readu32(c, &v->stream_id))
    CHECK_ERROR(_readStreamDependency_V5(c, &v->dependency))
    return parser_ok;
}

parser_error_t _readProxyType_V5(parser_context_t* c, pd_ProxyType_V5_t* v)
{
    CHECK_INPUT()

    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value > 3) {
        return parser_value_out_of_range;
    }

    return parser_ok;
}

parser_error_t _readRawSolution_V5(parser_context_t* c, pd_RawSolution_V5_t* v)
{
    return parser_not_supported;
}

parser_error_t _readReadySolution_V5(parser_context_t* c, pd_ReadySolution_V5_t* v)
{
    return parser_not_supported;
}

parser_error_t _readReferendumIndex_V5(parser_context_t* c, pd_ReferendumIndex_V5_t* v)
{
    return _readUInt32(c, &v->value);
}

parser_error_t _readRegistrarIndex_V5(parser_context_t* c, pd_RegistrarIndex_V5_t* v)
{
    return _readUInt32(c, &v->value);
}

parser_error_t _readRenouncing_V5(parser_context_t* c, pd_Renouncing_V5_t* v)
{
    return parser_not_supported;
}

parser_error_t _readRewardDestination_V5(parser_context_t* c, pd_RewardDestination_V5_t* v)
{
    CHECK_INPUT()

    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value > 2) {
        return parser_value_out_of_range;
    }

    return parser_ok;
}

parser_error_t _readSessionIndex_V5(parser_context_t* c, pd_SessionIndex_V5_t* v)
{
    return parser_not_supported;
}

parser_error_t _readSignature_V5(parser_context_t* c, pd_Signature_V5_t* v) {
    GEN_DEF_READARRAY(64)
}

parser_error_t _readSocietyJudgement_V5(parser_context_t* c, pd_SocietyJudgement_V5_t* v)
{
    return parser_not_supported;
}

parser_error_t _readSolutionOrSnapshotSize_V5(parser_context_t* c, pd_SolutionOrSnapshotSize_V5_t* v)
{
    return parser_not_supported;
}

parser_error_t _readStatementKind_V5(parser_context_t* c, pd_StatementKind_V5_t* v)
{
    return parser_not_supported;
}

parser_error_t _readStreamDependency_V5(parser_context_t* c, pd_StreamDependency_V5_t* v)
{
    CHECK_ERROR(_readu32(c, &v->dependency_id))
    CHECK_ERROR(_readUInt8(c, &v->weight))
    CHECK_ERROR(_readbool(c, &v->is_exclusive))
    return parser_ok;
}

parser_error_t _readTimepoint_V5(parser_context_t* c, pd_Timepoint_V5_t* v)
{
    CHECK_ERROR(_readBlockNumber(c, &v->height))
    CHECK_ERROR(_readu32(c, &v->index))
    return parser_ok;
}

parser_error_t _readTupleAccountIdData_V5(parser_context_t* c, pd_TupleAccountIdData_V5_t* v)
{
    return parser_not_supported;
}

parser_error_t _readTupleBalanceOfBalanceOfBlockNumber_V5(parser_context_t* c, pd_TupleBalanceOfBalanceOfBlockNumber_V5_t* v)
{
    CHECK_ERROR(_readBalanceOf(c, &v->balance1))
    CHECK_ERROR(_readBalanceOf(c, &v->balance2))
    CHECK_ERROR(_readBlockNumber(c, &v->blockNumber))
    return parser_ok;
}

parser_error_t _readValidationCode_V5(parser_context_t* c, pd_ValidationCode_V5_t* v)
{
    return parser_not_supported;
}

parser_error_t _readValidatorPrefs_V5(parser_context_t* c, pd_ValidatorPrefs_V5_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactPerBill_V5(c, &v->commission))
    CHECK_ERROR(_readbool(c, &v->blocked))
    return parser_ok;
}

parser_error_t _readVestingInfo_V5(parser_context_t* c, pd_VestingInfo_V5_t* v)
{
    CHECK_ERROR(_readBalanceOf(c, &v->locked))
    CHECK_ERROR(_readBalanceOf(c, &v->per_block))
    CHECK_ERROR(_readBlockNumber(c, &v->starting_block))
    return parser_ok;
}

parser_error_t _readVote_V5(parser_context_t* c, pd_Vote_V5_t* v)
{
    CHECK_INPUT()
    uint8_t b;
    CHECK_ERROR(_readUInt8(c, &b))

    v->aye = (b & 0x80u) >> 7u;
    v->conviction.value = b & 0x7Fu;

    if (v->conviction.value > 5) {
        return parser_value_out_of_range;
    }

    return parser_ok;
}

parser_error_t _readWeight_V5(parser_context_t* c, pd_Weight_V5_t* v)
{
    return _readUInt64(c, &v->value);
}

parser_error_t _readXcm_V5(parser_context_t* c, pd_Xcm_V5_t* v)
{
    return parser_not_supported;
}

parser_error_t _readu8_array_32_V5(parser_context_t* c, pd_u8_array_32_V5_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readVecAccountId_V5(parser_context_t* c, pd_VecAccountId_V5_t* v) {
    GEN_DEF_READVECTOR(AccountId_V5)
}

parser_error_t _readVecKeyValue_V5(parser_context_t* c, pd_VecKeyValue_V5_t* v) {
    GEN_DEF_READVECTOR(KeyValue_V5)
}

parser_error_t _readVecKey_V5(parser_context_t* c, pd_VecKey_V5_t* v) {
    GEN_DEF_READVECTOR(Key_V5)
}

parser_error_t _readVecLookupSource_V5(parser_context_t* c, pd_VecLookupSource_V5_t* v) {
    GEN_DEF_READVECTOR(LookupSource_V5)
}

parser_error_t _readVecMultiAsset_V5(parser_context_t* c, pd_VecMultiAsset_V5_t* v) {
    GEN_DEF_READVECTOR(MultiAsset_V5)
}

parser_error_t _readVecTupleAccountIdData_V5(parser_context_t* c, pd_VecTupleAccountIdData_V5_t* v) {
    GEN_DEF_READVECTOR(TupleAccountIdData_V5)
}

parser_error_t _readOptionAccountId_V5(parser_context_t* c, pd_OptionAccountId_V5_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readAccountId_V5(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionChangesTrieConfiguration_V5(parser_context_t* c, pd_OptionChangesTrieConfiguration_V5_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readChangesTrieConfiguration_V5(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionElectionScore_V5(parser_context_t* c, pd_OptionElectionScore_V5_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readElectionScore_V5(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionMultiSignature_V5(parser_context_t* c, pd_OptionMultiSignature_V5_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readMultiSignature_V5(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionMultiSigner_V5(parser_context_t* c, pd_OptionMultiSigner_V5_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readMultiSigner_V5(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionPeriod_V5(parser_context_t* c, pd_OptionPeriod_V5_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readPeriod_V5(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionProxyType_V5(parser_context_t* c, pd_OptionProxyType_V5_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readProxyType_V5(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionReferendumIndex_V5(parser_context_t* c, pd_OptionReferendumIndex_V5_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readReferendumIndex_V5(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionStatementKind_V5(parser_context_t* c, pd_OptionStatementKind_V5_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readStatementKind_V5(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionTimepoint_V5(parser_context_t* c, pd_OptionTimepoint_V5_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readTimepoint_V5(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionTupleBalanceOfBalanceOfBlockNumber_V5(parser_context_t* c, pd_OptionTupleBalanceOfBalanceOfBlockNumber_V5_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readTupleBalanceOfBalanceOfBlockNumber_V5(c, &v->contained))
    }
    return parser_ok;
}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////

parser_error_t _toStringCompactActiveIndex_V5(
    const pd_CompactActiveIndex_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, 0, "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactAuctionIndex_V5(
    const pd_CompactAuctionIndex_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, 0, "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactBountyIndex_V5(
    const pd_CompactBountyIndex_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, 0, "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactEraIndex_V5(
    const pd_CompactEraIndex_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, 0, "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactLeasePeriodOf_V5(
    const pd_CompactLeasePeriodOf_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, 0, "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactMemberCount_V5(
    const pd_CompactMemberCount_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, 0, "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactMoment_V5(
    const pd_CompactMoment_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, 0, "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactParaId_V5(
    const pd_CompactParaId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, 0, "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactPerquintill_V5(
    const pd_CompactPerquintill_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, 0, "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactPropIndex_V5(
    const pd_CompactPropIndex_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, 0, "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactProposalIndex_V5(
    const pd_CompactProposalIndex_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, 0, "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactReferendumIndex_V5(
    const pd_CompactReferendumIndex_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, 0, "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactRegistrarIndex_V5(
    const pd_CompactRegistrarIndex_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, 0, "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactWeight_V5(
    const pd_CompactWeight_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, 0, "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAccountId_V5(
    const pd_AccountId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringPubkeyAsAddress(v->_ptr, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAccountIndex_V5(
    const pd_AccountIndex_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAccountVoteSplit_V5(
    const pd_AccountVoteSplit_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    // First measure number of pages
    uint8_t pages[3];

    pages[0] = 1;
    CHECK_ERROR(_toStringBalanceOf(&v->aye, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringBalanceOf(&v->nay, outValue, outValueLen, 0, &pages[2]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx < pages[0]) {
        snprintf(outValue, outValueLen, "Split");
        return parser_ok;
    }
    pageIdx -= pages[0];

    /////////
    /////////

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringBalanceOf(&v->aye, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    /////////
    /////////

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringBalanceOf(&v->nay, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    // pageIdx -= pages[2];

    /////////
    /////////

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAccountVoteStandard_V5(
    const pd_AccountVoteStandard_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    // First measure number of pages
    uint8_t pages[3];

    pages[0] = 1;
    CHECK_ERROR(_toStringVote_V5(&v->vote, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringBalanceOf(&v->balance, outValue, outValueLen, 0, &pages[2]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        snprintf(outValue, outValueLen, "Standard");
        return parser_ok;
    }
    pageIdx -= pages[0];

    /////////
    /////////

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringVote_V5(&v->vote, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    /////////
    /////////

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringBalanceOf(&v->balance, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    // pageIdx -= pages[2];

    /////////
    /////////

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAccountVote_V5(
    const pd_AccountVote_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0:
        _toStringAccountVoteStandard_V5(&v->voteStandard, outValue, outValueLen, pageIdx, pageCount);
        break;
    case 1:
        _toStringAccountVoteSplit_V5(&v->voteSplit, outValue, outValueLen, pageIdx, pageCount);
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringBabeEquivocationProof_V5(
    const pd_BabeEquivocationProof_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringCallHashOf_V5(
    const pd_CallHashOf_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringChangesTrieConfiguration_V5(
    const pd_ChangesTrieConfiguration_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // Get all pages first
    uint8_t pages[2];
    CHECK_ERROR(_toStringu32(&v->digest_interval, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu32(&v->digest_levels, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringu32(&v->digest_interval, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu32(&v->digest_levels, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringCompactAccountIndex_V5(
    const pd_CompactAccountIndex_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(&v->value, 0, 0, "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactPerBill_V5(
    const pd_CompactPerBill_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // 9 but shift 2 to show as percentage
    return _toStringCompactInt(&v->value, 7, '%', "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringConviction_V5(
    const pd_Conviction_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "None");
        break;
    case 1:
        snprintf(outValue, outValueLen, "Locked1x");
        break;
    case 2:
        snprintf(outValue, outValueLen, "Locked2x");
        break;
    case 3:
        snprintf(outValue, outValueLen, "Locked3x");
        break;
    case 4:
        snprintf(outValue, outValueLen, "Locked4x");
        break;
    case 5:
        snprintf(outValue, outValueLen, "Locked5x");
        break;
    default:
        return parser_print_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringEcdsaSignature_V5(
    const pd_EcdsaSignature_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(65)
}

parser_error_t _toStringElectionScore_V5(
    const pd_ElectionScore_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringEraIndex_V5(
    const pd_EraIndex_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringEthereumAddress_V5(
    const pd_EthereumAddress_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(20)
}

parser_error_t _toStringGrandpaEquivocationProof_V5(
    const pd_GrandpaEquivocationProof_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringHeadData_V5(
    const pd_HeadData_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringHrmpChannelId_V5(
    const pd_HrmpChannelId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringIdentityFields_V5(
    const pd_IdentityFields_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringIdentityInfo_V5(
    const pd_IdentityInfo_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[9];
    CHECK_ERROR(_toStringVecTupleDataData(&v->additional, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringData(&v->display, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringData(&v->legal, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringData(&v->web, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringData(&v->riot, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringData(&v->email, outValue, outValueLen, 0, &pages[5]))
    CHECK_ERROR(_toStringOptionu8_array_20(&v->pgp_fingerprint, outValue, outValueLen, 0, &pages[6]))
    CHECK_ERROR(_toStringData(&v->image, outValue, outValueLen, 0, &pages[7]))
    CHECK_ERROR(_toStringData(&v->twitter, outValue, outValueLen, 0, &pages[8]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringVecTupleDataData(&v->additional, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    /////////
    /////////

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringData(&v->display, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    /////////
    /////////

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringData(&v->legal, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    /////////
    /////////

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringData(&v->web, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    /////////
    /////////

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringData(&v->riot, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    /////////
    /////////

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringData(&v->email, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    /////////
    /////////

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringOptionu8_array_20(&v->pgp_fingerprint, outValue, outValueLen, pageIdx, &pages[6]))
        return parser_ok;
    }
    pageIdx -= pages[6];

    /////////
    /////////

    if (pageIdx < pages[7]) {
        CHECK_ERROR(_toStringData(&v->image, outValue, outValueLen, pageIdx, &pages[7]))
        return parser_ok;
    }
    pageIdx -= pages[7];

    /////////
    /////////

    if (pageIdx < pages[8]) {
        CHECK_ERROR(_toStringData(&v->twitter, outValue, outValueLen, pageIdx, &pages[8]))
        return parser_ok;
    }
    // pageIdx -= pages[8];

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringIdentityJudgement_V5(
    const pd_IdentityJudgement_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringKeyOwnerProof_V5(
    const pd_KeyOwnerProof_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringKeyValue_V5(
    const pd_KeyValue_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringKey_V5(
    const pd_Key_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringKeys_V5(
    const pd_Keys_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(6 * 32)
}

parser_error_t _toStringLeasePeriodOf_V5(
    const pd_LeasePeriodOf_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringLookupSource_V5(
    const pd_LookupSource_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Id
        CHECK_ERROR(_toStringAccountId_V5(&v->id, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // Index
        CHECK_ERROR(_toStringCompactAccountIndex_V5(&v->index, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // Raw
        CHECK_ERROR(_toStringBytes(&v->raw, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 3: // Address32
    {
        GEN_DEF_TOSTRING_ARRAY(32)
    }
    case 4: // Address20
    {
        GEN_DEF_TOSTRING_ARRAY(20)
    }
    default:
        return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringMemberCount_V5(
    const pd_MemberCount_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringMultiAsset_V5(
    const pd_MultiAsset_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringMultiLocation_V5(
    const pd_MultiLocation_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringMultiSignature_V5(
    const pd_MultiSignature_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringMultiSigner_V5(
    const pd_MultiSigner_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringNextConfigDescriptor_V5(
    const pd_NextConfigDescriptor_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringOpaqueCall_V5(
    const pd_OpaqueCall_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCall(&v->call, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringParaId_V5(
    const pd_ParaId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringParachainsInherentData_V5(
    const pd_ParachainsInherentData_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringPerbill_V5(
    const pd_Perbill_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[100];
    char ratioBuffer[80];
    MEMSET(outValue, 0, outValueLen);
    MEMSET(ratioBuffer, 0, sizeof(ratioBuffer));
    MEMSET(bufferUI, 0, sizeof(bufferUI));
    *pageCount = 1;

    if (fpuint64_to_str(ratioBuffer, sizeof(ratioBuffer), v->value, 7) == 0) {
        return parser_unexpected_value;
    }

    snprintf(bufferUI, sizeof(bufferUI), "%s%%", ratioBuffer);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}

parser_error_t _toStringPercent_V5(
    const pd_Percent_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // 9 but shift 2 to show as percentage
    return _toStringCompactInt(&v->value, 7, '%', "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringPeriod_V5(
    const pd_Period_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringPriority_V5(
    const pd_Priority_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // Get all pages first
    uint8_t pages[2];
    CHECK_ERROR(_toStringu32(&v->stream_id, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringStreamDependency_V5(&v->dependency, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringu32(&v->stream_id, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringStreamDependency_V5(&v->dependency, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringProxyType_V5(
    const pd_ProxyType_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "Any");
        break;
    case 1:
        snprintf(outValue, outValueLen, "NonTransfer");
        break;
    case 2:
        snprintf(outValue, outValueLen, "Governance");
        break;
    case 3:
        snprintf(outValue, outValueLen, "Staking");
        break;
    default:
        return parser_print_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringRawSolution_V5(
    const pd_RawSolution_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringReadySolution_V5(
    const pd_ReadySolution_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringReferendumIndex_V5(
    const pd_ReferendumIndex_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringRegistrarIndex_V5(
    const pd_RegistrarIndex_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringRenouncing_V5(
    const pd_Renouncing_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringRewardDestination_V5(
    const pd_RewardDestination_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "Staked");
        break;
    case 1:
        snprintf(outValue, outValueLen, "Stash");
        break;
    case 2:
        snprintf(outValue, outValueLen, "Controller");
        break;
    default:
        return parser_print_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringSessionIndex_V5(
    const pd_SessionIndex_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringSignature_V5(
    const pd_Signature_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(64)
}

parser_error_t _toStringSocietyJudgement_V5(
    const pd_SocietyJudgement_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringSolutionOrSnapshotSize_V5(
    const pd_SolutionOrSnapshotSize_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringStatementKind_V5(
    const pd_StatementKind_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringStreamDependency_V5(
    const pd_StreamDependency_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[3];
    CHECK_ERROR(_toStringu32(&v->dependency_id, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu16((const pd_u16_t*)&v->weight, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringbool(&v->is_exclusive, outValue, outValueLen, 0, &pages[2]))

    *pageCount = pages[0] + pages[1] + pages[2];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringu32(&v->dependency_id, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu16((const pd_u16_t*)&v->weight, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringbool(&v->is_exclusive, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTimepoint_V5(
    const pd_Timepoint_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringBlockNumber(&v->height, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu32(&v->index, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringBlockNumber(&v->height, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu32(&v->index, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTupleAccountIdData_V5(
    const pd_TupleAccountIdData_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringTupleBalanceOfBalanceOfBlockNumber_V5(
    const pd_TupleBalanceOfBalanceOfBlockNumber_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[3];
    CHECK_ERROR(_toStringBalanceOf(&v->balance1, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringBalanceOf(&v->balance2, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringBlockNumber(&v->blockNumber, outValue, outValueLen, 0, &pages[2]))

    *pageCount = pages[0] + pages[1] + pages[2];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringBalanceOf(&v->balance1, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringBalanceOf(&v->balance2, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringBlockNumber(&v->blockNumber, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringValidationCode_V5(
    const pd_ValidationCode_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringValidatorPrefs_V5(
    const pd_ValidatorPrefs_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    uint8_t pages[2];
    CHECK_ERROR(_toStringCompactPerBill_V5(&v->commission, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringbool(&v->blocked, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactPerBill_V5(&v->commission, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringbool(&v->blocked, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringVestingInfo_V5(
    const pd_VestingInfo_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[3];
    CHECK_ERROR(_toStringBalanceOf(&v->locked, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringBalanceOf(&v->per_block, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringBlockNumber(&v->starting_block, outValue, outValueLen, 0, &pages[2]))

    *pageCount = pages[0] + pages[1] + pages[2];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringBalanceOf(&v->locked, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringBalanceOf(&v->per_block, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringBlockNumber(&v->starting_block, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringVote_V5(
    const pd_Vote_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    CHECK_PARSER_ERR(_toStringbool(&v->aye, outValue, outValueLen, pageIdx, pageCount))
    uint16_t offset = strlen(outValue);
    outValue[offset++] = ' ';
    CHECK_PARSER_ERR(_toStringConviction_V5(&v->conviction,
        outValue + offset,
        outValueLen - offset,
        pageIdx,
        pageCount))
    *pageCount = 1;
    return parser_ok;
}

parser_error_t _toStringWeight_V5(
    const pd_Weight_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringXcm_V5(
    const pd_Xcm_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringu8_array_32_V5(
    const pd_u8_array_32_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringVecAccountId_V5(
    const pd_VecAccountId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(AccountId_V5)
}

parser_error_t _toStringVecKeyValue_V5(
    const pd_VecKeyValue_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(KeyValue_V5)
}

parser_error_t _toStringVecKey_V5(
    const pd_VecKey_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Key_V5)
}

parser_error_t _toStringVecLookupSource_V5(
    const pd_VecLookupSource_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(LookupSource_V5)
}

parser_error_t _toStringVecMultiAsset_V5(
    const pd_VecMultiAsset_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(MultiAsset_V5)
}

parser_error_t _toStringVecTupleAccountIdData_V5(
    const pd_VecTupleAccountIdData_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(TupleAccountIdData_V5)
}

parser_error_t _toStringOptionAccountId_V5(
    const pd_OptionAccountId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringAccountId_V5(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount))
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionChangesTrieConfiguration_V5(
    const pd_OptionChangesTrieConfiguration_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringChangesTrieConfiguration_V5(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount))
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionElectionScore_V5(
    const pd_OptionElectionScore_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringElectionScore_V5(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount))
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionMultiSignature_V5(
    const pd_OptionMultiSignature_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringMultiSignature_V5(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount))
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionMultiSigner_V5(
    const pd_OptionMultiSigner_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringMultiSigner_V5(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount))
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionPeriod_V5(
    const pd_OptionPeriod_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringPeriod_V5(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount))
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionProxyType_V5(
    const pd_OptionProxyType_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringProxyType_V5(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount))
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionReferendumIndex_V5(
    const pd_OptionReferendumIndex_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringReferendumIndex_V5(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount))
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionStatementKind_V5(
    const pd_OptionStatementKind_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringStatementKind_V5(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount))
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionTimepoint_V5(
    const pd_OptionTimepoint_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringTimepoint_V5(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount))
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionTupleBalanceOfBalanceOfBlockNumber_V5(
    const pd_OptionTupleBalanceOfBalanceOfBlockNumber_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringTupleBalanceOfBalanceOfBlockNumber_V5(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount))
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}
