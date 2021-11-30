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

#include "substrate_types.h"
#include <stddef.h>
#include <stdint.h>

// Based
// https://github.com/paritytech/substrate/blob/master/node/primitives/src/lib.rs

typedef struct {
    const uint8_t* _ptr;
} pd_AccountId_V7_t;

typedef struct {
    compactInt_t value;
} pd_CompactAccountIndex_V7_t;

typedef struct {
    pd_u32_t digest_interval;
    pd_u32_t digest_levels;
} pd_ChangesTrieConfiguration_V7_t;

typedef struct {
    compactInt_t value;
} pd_CompactPerBill_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ElectionScore_V7_t;

typedef struct {
    const uint8_t* _ptr;
} pd_KeyValue_V7_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Key_V7_t;

typedef struct {
    uint8_t value;
    union {
        pd_AccountId_V7_t id;
        pd_CompactAccountIndex_V7_t index;
        pd_Bytes_t raw;
        const uint8_t* _ptr;
    };
} pd_LookupasStaticLookupSource_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_MultiSignature_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_MultiSigner_V7_t;

typedef struct {
    compactInt_t value;
} pd_Percent_V7_t;

typedef struct {
    uint8_t value;
} pd_ProxyType_V7_t;

typedef struct {
    uint32_t value;
} pd_ReferendumIndex_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_StatementKind_V7_t;

typedef struct {
    pd_BlockNumber_t height;
    uint32_t index;
} pd_Timepoint_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_TupleAccountIdData_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_TupleBalanceOfTBalanceOfTBlockNumber_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_XcmVersion_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_schedulePeriodBlockNumber_V7_t;

typedef struct {
    pd_Call_t call;
} pd_OpaqueCall_V7_t;

typedef struct {
    uint8_t some;
    pd_ChangesTrieConfiguration_V7_t contained;
} pd_OptionChangesTrieConfiguration_V7_t;

typedef struct {
    uint8_t some;
    pd_Timepoint_V7_t contained;
} pd_OptionTimepoint_V7_t;

typedef struct {
    pd_CompactPerBill_V7_t commission;
    pd_bool_t blocked;
} pd_ValidatorPrefs_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecLookupasStaticLookupSource_V7_t;

typedef struct {
    uint32_t value;
} pd_AccountIndex_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_AccountVoteBalanceOfT_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_AuthorityIdasRuntimeAppPublicSignature_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxEquivocationProofHashBlockNumber_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxEquivocationProofHeader_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxIdentityInfoMaxAdditionalFields_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxMultiLocation_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxRawSolutionSolutionOfT_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxTasConfigIProposal_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxVersionedMultiAssets_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxVersionedMultiLocation_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxVersionedXcmTasSysConfigCall_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxVersionedXcmTuple_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_CallHashOfT_V7_t;

typedef struct {
    uint8_t value;
} pd_Conviction_V7_t;

typedef struct {
    const uint8_t* _ptr;
} pd_EcdsaSignature_V7_t;

typedef struct {
    uint32_t value;
} pd_EraIndex_V7_t;

typedef struct {
    const uint8_t* _ptr;
} pd_EthereumAddress_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_HeadData_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_HeartbeatBlockNumber_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_HrmpChannelId_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_IdentityFields_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_JudgementBalanceOfT_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_Judgement_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_KeyOwnerProof_V7_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Keys_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_LeasePeriodOfT_V7_t;

typedef struct {
    uint32_t value;
} pd_MemberCount_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_NextConfigDescriptor_V7_t;

typedef struct {
    uint8_t some;
    pd_AccountId_V7_t contained;
} pd_OptionAccountId_V7_t;

typedef struct {
    uint8_t some;
    pd_ElectionScore_V7_t contained;
} pd_OptionElectionScore_V7_t;

typedef struct {
    uint8_t some;
    pd_MultiSignature_V7_t contained;
} pd_OptionMultiSignature_V7_t;

typedef struct {
    uint8_t some;
    pd_MultiSigner_V7_t contained;
} pd_OptionMultiSigner_V7_t;

typedef struct {
    uint8_t some;
    pd_Percent_V7_t contained;
} pd_OptionPercent_V7_t;

typedef struct {
    uint8_t some;
    pd_ProxyType_V7_t contained;
} pd_OptionProxyType_V7_t;

typedef struct {
    uint8_t some;
    pd_ReferendumIndex_V7_t contained;
} pd_OptionReferendumIndex_V7_t;

typedef struct {
    uint8_t some;
    pd_StatementKind_V7_t contained;
} pd_OptionStatementKind_V7_t;

typedef struct {
    uint8_t some;
    pd_TupleBalanceOfTBalanceOfTBlockNumber_V7_t contained;
} pd_OptionTupleBalanceOfTBalanceOfTBlockNumber_V7_t;

typedef struct {
    uint8_t some;
    pd_XcmVersion_V7_t contained;
} pd_OptionXcmVersion_V7_t;

typedef struct {
    uint8_t some;
    pd_schedulePeriodBlockNumber_V7_t contained;
} pd_OptionschedulePeriodBlockNumber_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_OverweightIndex_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ParaId_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ParachainsInherentDataHeader_V7_t;

typedef struct {
    uint32_t value;
} pd_Perbill_V7_t;

typedef struct {
    uint32_t value;
} pd_RegistrarIndex_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_Renouncing_V7_t;

typedef struct {
    uint8_t value;
} pd_RewardDestination_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_SessionIndex_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_SolutionOrSnapshotSize_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_SupportsAccountId_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ValidationCode_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAccountId_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecKeyValue_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecKey_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTupleAccountIdData_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_VestingInfoBalanceOfTBlockNumber_V7_t;

typedef struct {
    uint64_t value;
} pd_WeightLimit_V7_t;

typedef struct {
    uint64_t value;
} pd_Weight_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_schedulePriority_V7_t;

#ifdef __cplusplus
}
#endif
