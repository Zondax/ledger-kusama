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
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "substrate_types.h"
#include "substrate_types_V7.h"
#include <stddef.h>
#include <stdint.h>

#define PD_CALL_SYSTEM_V7 0
#define PD_CALL_BABE_V7 1
#define PD_CALL_TIMESTAMP_V7 2
#define PD_CALL_INDICES_V7 3
#define PD_CALL_BALANCES_V7 4
#define PD_CALL_AUTHORSHIP_V7 5
#define PD_CALL_STAKING_V7 6
#define PD_CALL_SESSION_V7 8
#define PD_CALL_GRANDPA_V7 10
#define PD_CALL_IMONLINE_V7 11
#define PD_CALL_DEMOCRACY_V7 13
#define PD_CALL_COUNCIL_V7 14
#define PD_CALL_TECHNICALCOMMITTEE_V7 15
#define PD_CALL_PHRAGMENELECTION_V7 16
#define PD_CALL_TECHNICALMEMBERSHIP_V7 17
#define PD_CALL_TREASURY_V7 18
#define PD_CALL_CLAIMS_V7 19
#define PD_CALL_UTILITY_V7 24
#define PD_CALL_IDENTITY_V7 25
#define PD_CALL_SOCIETY_V7 26
#define PD_CALL_RECOVERY_V7 27
#define PD_CALL_VESTING_V7 28
#define PD_CALL_SCHEDULER_V7 29
#define PD_CALL_PROXY_V7 30
#define PD_CALL_MULTISIG_V7 31
#define PD_CALL_BOUNTIES_V7 35
#define PD_CALL_TIPS_V7 36
#define PD_CALL_ELECTIONPROVIDERMULTIPHASE_V7 37
#define PD_CALL_GILT_V7 38
#define PD_CALL_BAGSLIST_V7 39
#define PD_CALL_CONFIGURATION_V7 51
#define PD_CALL_PARASSHARED_V7 52
#define PD_CALL_PARAINCLUSION_V7 53
#define PD_CALL_PARAINHERENT_V7 54
#define PD_CALL_PARAS_V7 56
#define PD_CALL_INITIALIZER_V7 57
#define PD_CALL_DMP_V7 58
#define PD_CALL_UMP_V7 59
#define PD_CALL_HRMP_V7 60
#define PD_CALL_REGISTRAR_V7 70
#define PD_CALL_SLOTS_V7 71
#define PD_CALL_AUCTIONS_V7 72
#define PD_CALL_CROWDLOAN_V7 73
#define PD_CALL_XCMPALLET_V7 99

#define PD_CALL_STAKING_BOND_V7 0
typedef struct {
    pd_LookupasStaticLookupSource_V7_t controller;
    pd_Compactu128_V7_t value;
    pd_RewardDestination_V7_t payee;
} pd_staking_bond_V7_t;

#define PD_CALL_STAKING_UNBOND_V7 2
typedef struct {
    pd_Compactu128_V7_t value;
} pd_staking_unbond_V7_t;

#define PD_CALL_STAKING_VALIDATE_V7 4
typedef struct {
    pd_ValidatorPrefs_V7_t prefs;
} pd_staking_validate_V7_t;

#define PD_CALL_STAKING_NOMINATE_V7 5
typedef struct {
    pd_VecLookupasStaticLookupSource_V7_t targets;
} pd_staking_nominate_V7_t;

#define PD_CALL_STAKING_CHILL_V7 6
typedef struct {
} pd_staking_chill_V7_t;

#define PD_CALL_STAKING_REBOND_V7 19
typedef struct {
    pd_Compactu128_V7_t value;
} pd_staking_rebond_V7_t;

#define PD_CALL_UTILITY_BATCH_V7 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V7_t;

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_SYSTEM_REMARK_WITH_EVENT_V7 9
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_with_event_V7_t;

#define PD_CALL_BABE_REPORT_EQUIVOCATION_V7 0
typedef struct {
    pd_BoxEquivocationProofHeader_V7_t equivocation_proof;
    pd_KeyOwnerProof_V7_t key_owner_proof;
} pd_babe_report_equivocation_V7_t;

#define PD_CALL_BABE_REPORT_EQUIVOCATION_UNSIGNED_V7 1
typedef struct {
    pd_BoxEquivocationProofHeader_V7_t equivocation_proof;
    pd_KeyOwnerProof_V7_t key_owner_proof;
} pd_babe_report_equivocation_unsigned_V7_t;

#define PD_CALL_BABE_PLAN_CONFIG_CHANGE_V7 2
typedef struct {
    pd_NextConfigDescriptor_V7_t config;
} pd_babe_plan_config_change_V7_t;

#define PD_CALL_TIMESTAMP_SET_V7 0
typedef struct {
    pd_Compactu64_t now;
} pd_timestamp_set_V7_t;

#define PD_CALL_INDICES_CLAIM_V7 0
typedef struct {
    pd_AccountIndex_V7_t index;
} pd_indices_claim_V7_t;

#define PD_CALL_INDICES_TRANSFER_V7 1
typedef struct {
    pd_AccountId_V7_t new_;
    pd_AccountIndex_V7_t index;
} pd_indices_transfer_V7_t;

#define PD_CALL_INDICES_FREE_V7 2
typedef struct {
    pd_AccountIndex_V7_t index;
} pd_indices_free_V7_t;

#define PD_CALL_INDICES_FORCE_TRANSFER_V7 3
typedef struct {
    pd_AccountId_V7_t new_;
    pd_AccountIndex_V7_t index;
    pd_bool_t freeze;
} pd_indices_force_transfer_V7_t;

#define PD_CALL_INDICES_FREEZE_V7 4
typedef struct {
    pd_AccountIndex_V7_t index;
} pd_indices_freeze_V7_t;

#define PD_CALL_BALANCES_TRANSFER_ALL_V7 4
typedef struct {
    pd_LookupasStaticLookupSource_V7_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_V7_t;

#define PD_CALL_BALANCES_FORCE_UNRESERVE_V7 5
typedef struct {
    pd_LookupasStaticLookupSource_V7_t who;
    pd_Balance_t amount;
} pd_balances_force_unreserve_V7_t;

#define PD_CALL_AUTHORSHIP_SET_UNCLES_V7 0
typedef struct {
    pd_VecHeader_t new_uncles;
} pd_authorship_set_uncles_V7_t;

#define PD_CALL_STAKING_BOND_EXTRA_V7 1
typedef struct {
    pd_Compactu128_V7_t max_additional;
} pd_staking_bond_extra_V7_t;

#define PD_CALL_STAKING_WITHDRAW_UNBONDED_V7 3
typedef struct {
    pd_u32_t num_slashing_spans;
} pd_staking_withdraw_unbonded_V7_t;

#define PD_CALL_STAKING_SET_PAYEE_V7 7
typedef struct {
    pd_RewardDestination_V7_t payee;
} pd_staking_set_payee_V7_t;

#define PD_CALL_STAKING_SET_CONTROLLER_V7 8
typedef struct {
    pd_LookupasStaticLookupSource_V7_t controller;
} pd_staking_set_controller_V7_t;

#define PD_CALL_STAKING_SET_VALIDATOR_COUNT_V7 9
typedef struct {
    pd_Compactu32_t new_;
} pd_staking_set_validator_count_V7_t;

#define PD_CALL_STAKING_INCREASE_VALIDATOR_COUNT_V7 10
typedef struct {
    pd_Compactu32_t additional;
} pd_staking_increase_validator_count_V7_t;

#define PD_CALL_STAKING_SCALE_VALIDATOR_COUNT_V7 11
typedef struct {
    pd_Percent_V7_t factor;
} pd_staking_scale_validator_count_V7_t;

#define PD_CALL_STAKING_FORCE_NO_ERAS_V7 12
typedef struct {
} pd_staking_force_no_eras_V7_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_V7 13
typedef struct {
} pd_staking_force_new_era_V7_t;

#define PD_CALL_STAKING_SET_INVULNERABLES_V7 14
typedef struct {
    pd_VecAccountId_V7_t invulnerables;
} pd_staking_set_invulnerables_V7_t;

#define PD_CALL_STAKING_FORCE_UNSTAKE_V7 15
typedef struct {
    pd_AccountId_V7_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_force_unstake_V7_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_ALWAYS_V7 16
typedef struct {
} pd_staking_force_new_era_always_V7_t;

#define PD_CALL_STAKING_CANCEL_DEFERRED_SLASH_V7 17
typedef struct {
    pd_EraIndex_V7_t era;
    pd_Vecu32_t slash_indices;
} pd_staking_cancel_deferred_slash_V7_t;

#define PD_CALL_STAKING_PAYOUT_STAKERS_V7 18
typedef struct {
    pd_AccountId_V7_t validator_stash;
    pd_EraIndex_V7_t era;
} pd_staking_payout_stakers_V7_t;

#define PD_CALL_STAKING_SET_HISTORY_DEPTH_V7 20
typedef struct {
    pd_Compactu32_t new_history_depth;
    pd_Compactu32_t era_items_deleted;
} pd_staking_set_history_depth_V7_t;

#define PD_CALL_STAKING_REAP_STASH_V7 21
typedef struct {
    pd_AccountId_V7_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_reap_stash_V7_t;

#define PD_CALL_STAKING_KICK_V7 22
typedef struct {
    pd_VecLookupasStaticLookupSource_V7_t who;
} pd_staking_kick_V7_t;

#define PD_CALL_STAKING_SET_STAKING_LIMITS_V7 23
typedef struct {
    pd_Balance_t min_nominator_bond;
    pd_Balance_t min_validator_bond;
    pd_Optionu32_t max_nominator_count;
    pd_Optionu32_t max_validator_count;
    pd_OptionPercent_V7_t threshold;
} pd_staking_set_staking_limits_V7_t;

#define PD_CALL_STAKING_CHILL_OTHER_V7 24
typedef struct {
    pd_AccountId_V7_t controller;
} pd_staking_chill_other_V7_t;

#define PD_CALL_SESSION_SET_KEYS_V7 0
typedef struct {
    pd_Keys_V7_t keys;
    pd_Vecu8_t proof;
} pd_session_set_keys_V7_t;

#define PD_CALL_SESSION_PURGE_KEYS_V7 1
typedef struct {
} pd_session_purge_keys_V7_t;

#define PD_CALL_GRANDPA_REPORT_EQUIVOCATION_V7 0
typedef struct {
    pd_BoxEquivocationProofHashBlockNumber_V7_t equivocation_proof;
    pd_KeyOwnerProof_V7_t key_owner_proof;
} pd_grandpa_report_equivocation_V7_t;

#define PD_CALL_GRANDPA_REPORT_EQUIVOCATION_UNSIGNED_V7 1
typedef struct {
    pd_BoxEquivocationProofHashBlockNumber_V7_t equivocation_proof;
    pd_KeyOwnerProof_V7_t key_owner_proof;
} pd_grandpa_report_equivocation_unsigned_V7_t;

#define PD_CALL_GRANDPA_NOTE_STALLED_V7 2
typedef struct {
    pd_BlockNumber_t delay;
    pd_BlockNumber_t best_finalized_block_number;
} pd_grandpa_note_stalled_V7_t;

#define PD_CALL_IMONLINE_HEARTBEAT_V7 0
typedef struct {
    pd_HeartbeatBlockNumber_V7_t heartbeat;
    pd_AuthorityIdasRuntimeAppPublicSignature_V7_t signature;
} pd_imonline_heartbeat_V7_t;

#define PD_CALL_DEMOCRACY_PROPOSE_V7 0
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu128_V7_t value;
} pd_democracy_propose_V7_t;

#define PD_CALL_DEMOCRACY_SECOND_V7 1
typedef struct {
    pd_Compactu32_t proposal;
    pd_Compactu32_t seconds_upper_bound;
} pd_democracy_second_V7_t;

#define PD_CALL_DEMOCRACY_VOTE_V7 2
typedef struct {
    pd_Compactu32_t ref_index;
    pd_AccountVoteBalanceOfT_V7_t vote;
} pd_democracy_vote_V7_t;

#define PD_CALL_DEMOCRACY_EMERGENCY_CANCEL_V7 3
typedef struct {
    pd_ReferendumIndex_V7_t ref_index;
} pd_democracy_emergency_cancel_V7_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_V7 4
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_V7_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_MAJORITY_V7 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_majority_V7_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_DEFAULT_V7 6
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_default_V7_t;

#define PD_CALL_DEMOCRACY_FAST_TRACK_V7 7
typedef struct {
    pd_Hash_t proposal_hash;
    pd_BlockNumber_t voting_period;
    pd_BlockNumber_t delay;
} pd_democracy_fast_track_V7_t;

#define PD_CALL_DEMOCRACY_VETO_EXTERNAL_V7 8
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_veto_external_V7_t;

#define PD_CALL_DEMOCRACY_CANCEL_REFERENDUM_V7 9
typedef struct {
    pd_Compactu32_t ref_index;
} pd_democracy_cancel_referendum_V7_t;

#define PD_CALL_DEMOCRACY_CANCEL_QUEUED_V7 10
typedef struct {
    pd_ReferendumIndex_V7_t which;
} pd_democracy_cancel_queued_V7_t;

#define PD_CALL_DEMOCRACY_DELEGATE_V7 11
typedef struct {
    pd_AccountId_V7_t to;
    pd_Conviction_V7_t conviction;
    pd_Balance_t balance;
} pd_democracy_delegate_V7_t;

#define PD_CALL_DEMOCRACY_UNDELEGATE_V7 12
typedef struct {
} pd_democracy_undelegate_V7_t;

#define PD_CALL_DEMOCRACY_CLEAR_PUBLIC_PROPOSALS_V7 13
typedef struct {
} pd_democracy_clear_public_proposals_V7_t;

#define PD_CALL_DEMOCRACY_NOTE_PREIMAGE_V7 14
typedef struct {
    pd_Vecu8_t encoded_proposal;
} pd_democracy_note_preimage_V7_t;

#define PD_CALL_DEMOCRACY_NOTE_PREIMAGE_OPERATIONAL_V7 15
typedef struct {
    pd_Vecu8_t encoded_proposal;
} pd_democracy_note_preimage_operational_V7_t;

#define PD_CALL_DEMOCRACY_NOTE_IMMINENT_PREIMAGE_V7 16
typedef struct {
    pd_Vecu8_t encoded_proposal;
} pd_democracy_note_imminent_preimage_V7_t;

#define PD_CALL_DEMOCRACY_NOTE_IMMINENT_PREIMAGE_OPERATIONAL_V7 17
typedef struct {
    pd_Vecu8_t encoded_proposal;
} pd_democracy_note_imminent_preimage_operational_V7_t;

#define PD_CALL_DEMOCRACY_REAP_PREIMAGE_V7 18
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t proposal_len_upper_bound;
} pd_democracy_reap_preimage_V7_t;

#define PD_CALL_DEMOCRACY_UNLOCK_V7 19
typedef struct {
    pd_AccountId_V7_t target;
} pd_democracy_unlock_V7_t;

#define PD_CALL_DEMOCRACY_REMOVE_VOTE_V7 20
typedef struct {
    pd_ReferendumIndex_V7_t index;
} pd_democracy_remove_vote_V7_t;

#define PD_CALL_DEMOCRACY_REMOVE_OTHER_VOTE_V7 21
typedef struct {
    pd_AccountId_V7_t target;
    pd_ReferendumIndex_V7_t index;
} pd_democracy_remove_other_vote_V7_t;

#define PD_CALL_DEMOCRACY_ENACT_PROPOSAL_V7 22
typedef struct {
    pd_Hash_t proposal_hash;
    pd_ReferendumIndex_V7_t index;
} pd_democracy_enact_proposal_V7_t;

#define PD_CALL_DEMOCRACY_BLACKLIST_V7 23
typedef struct {
    pd_Hash_t proposal_hash;
    pd_OptionReferendumIndex_V7_t maybe_ref_index;
} pd_democracy_blacklist_V7_t;

#define PD_CALL_DEMOCRACY_CANCEL_PROPOSAL_V7 24
typedef struct {
    pd_Compactu32_t prop_index;
} pd_democracy_cancel_proposal_V7_t;

#define PD_CALL_COUNCIL_SET_MEMBERS_V7 0
typedef struct {
    pd_VecAccountId_V7_t new_members;
    pd_OptionAccountId_V7_t prime;
    pd_MemberCount_V7_t old_count;
} pd_council_set_members_V7_t;

#define PD_CALL_COUNCIL_EXECUTE_V7 1
typedef struct {
    pd_BoxTasConfigIProposal_V7_t proposal;
    pd_Compactu32_t length_bound;
} pd_council_execute_V7_t;

#define PD_CALL_COUNCIL_PROPOSE_V7 2
typedef struct {
    pd_Compactu32_t threshold;
    pd_BoxTasConfigIProposal_V7_t proposal;
    pd_Compactu32_t length_bound;
} pd_council_propose_V7_t;

#define PD_CALL_COUNCIL_VOTE_V7 3
typedef struct {
    pd_Hash_t proposal;
    pd_Compactu32_t index;
    pd_bool_t approve;
} pd_council_vote_V7_t;

#define PD_CALL_COUNCIL_CLOSE_V7 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t index;
    pd_Compactu64_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_council_close_V7_t;

#define PD_CALL_COUNCIL_DISAPPROVE_PROPOSAL_V7 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_council_disapprove_proposal_V7_t;

#define PD_CALL_TECHNICALCOMMITTEE_SET_MEMBERS_V7 0
typedef struct {
    pd_VecAccountId_V7_t new_members;
    pd_OptionAccountId_V7_t prime;
    pd_MemberCount_V7_t old_count;
} pd_technicalcommittee_set_members_V7_t;

#define PD_CALL_TECHNICALCOMMITTEE_EXECUTE_V7 1
typedef struct {
    pd_BoxTasConfigIProposal_V7_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_execute_V7_t;

#define PD_CALL_TECHNICALCOMMITTEE_PROPOSE_V7 2
typedef struct {
    pd_Compactu32_t threshold;
    pd_BoxTasConfigIProposal_V7_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_propose_V7_t;

#define PD_CALL_TECHNICALCOMMITTEE_VOTE_V7 3
typedef struct {
    pd_Hash_t proposal;
    pd_Compactu32_t index;
    pd_bool_t approve;
} pd_technicalcommittee_vote_V7_t;

#define PD_CALL_TECHNICALCOMMITTEE_CLOSE_V7 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t index;
    pd_Compactu64_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_close_V7_t;

#define PD_CALL_TECHNICALCOMMITTEE_DISAPPROVE_PROPOSAL_V7 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_technicalcommittee_disapprove_proposal_V7_t;

#define PD_CALL_PHRAGMENELECTION_VOTE_V7 0
typedef struct {
    pd_VecAccountId_V7_t votes;
    pd_Compactu128_V7_t value;
} pd_phragmenelection_vote_V7_t;

#define PD_CALL_PHRAGMENELECTION_REMOVE_VOTER_V7 1
typedef struct {
} pd_phragmenelection_remove_voter_V7_t;

#define PD_CALL_PHRAGMENELECTION_SUBMIT_CANDIDACY_V7 2
typedef struct {
    pd_Compactu32_t candidate_count;
} pd_phragmenelection_submit_candidacy_V7_t;

#define PD_CALL_PHRAGMENELECTION_RENOUNCE_CANDIDACY_V7 3
typedef struct {
    pd_Renouncing_V7_t renouncing;
} pd_phragmenelection_renounce_candidacy_V7_t;

#define PD_CALL_PHRAGMENELECTION_REMOVE_MEMBER_V7 4
typedef struct {
    pd_LookupasStaticLookupSource_V7_t who;
    pd_bool_t has_replacement;
} pd_phragmenelection_remove_member_V7_t;

#define PD_CALL_PHRAGMENELECTION_CLEAN_DEFUNCT_VOTERS_V7 5
typedef struct {
    pd_u32_t num_voters;
    pd_u32_t num_defunct;
} pd_phragmenelection_clean_defunct_voters_V7_t;

#define PD_CALL_TECHNICALMEMBERSHIP_ADD_MEMBER_V7 0
typedef struct {
    pd_AccountId_V7_t who;
} pd_technicalmembership_add_member_V7_t;

#define PD_CALL_TECHNICALMEMBERSHIP_REMOVE_MEMBER_V7 1
typedef struct {
    pd_AccountId_V7_t who;
} pd_technicalmembership_remove_member_V7_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SWAP_MEMBER_V7 2
typedef struct {
    pd_AccountId_V7_t remove;
    pd_AccountId_V7_t add;
} pd_technicalmembership_swap_member_V7_t;

#define PD_CALL_TECHNICALMEMBERSHIP_RESET_MEMBERS_V7 3
typedef struct {
    pd_VecAccountId_V7_t members;
} pd_technicalmembership_reset_members_V7_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CHANGE_KEY_V7 4
typedef struct {
    pd_AccountId_V7_t new_;
} pd_technicalmembership_change_key_V7_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SET_PRIME_V7 5
typedef struct {
    pd_AccountId_V7_t who;
} pd_technicalmembership_set_prime_V7_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CLEAR_PRIME_V7 6
typedef struct {
} pd_technicalmembership_clear_prime_V7_t;

#define PD_CALL_TREASURY_PROPOSE_SPEND_V7 0
typedef struct {
    pd_Compactu128_V7_t value;
    pd_LookupasStaticLookupSource_V7_t beneficiary;
} pd_treasury_propose_spend_V7_t;

#define PD_CALL_TREASURY_REJECT_PROPOSAL_V7 1
typedef struct {
    pd_Compactu32_t proposal_id;
} pd_treasury_reject_proposal_V7_t;

#define PD_CALL_TREASURY_APPROVE_PROPOSAL_V7 2
typedef struct {
    pd_Compactu32_t proposal_id;
} pd_treasury_approve_proposal_V7_t;

#define PD_CALL_CLAIMS_CLAIM_V7 0
typedef struct {
    pd_AccountId_V7_t dest;
    pd_EcdsaSignature_V7_t ethereum_signature;
} pd_claims_claim_V7_t;

#define PD_CALL_CLAIMS_MINT_CLAIM_V7 1
typedef struct {
    pd_EthereumAddress_V7_t who;
    pd_Balance_t Amount;
    pd_OptionTupleBalanceOfTBalanceOfTBlockNumber_V7_t vesting_schedule;
    pd_OptionStatementKind_V7_t statement;
} pd_claims_mint_claim_V7_t;

#define PD_CALL_CLAIMS_CLAIM_ATTEST_V7 2
typedef struct {
    pd_AccountId_V7_t dest;
    pd_EcdsaSignature_V7_t ethereum_signature;
    pd_Vecu8_t statement;
} pd_claims_claim_attest_V7_t;

#define PD_CALL_CLAIMS_ATTEST_V7 3
typedef struct {
    pd_Vecu8_t statement;
} pd_claims_attest_V7_t;

#define PD_CALL_CLAIMS_MOVE_CLAIM_V7 4
typedef struct {
    pd_EthereumAddress_V7_t old;
    pd_EthereumAddress_V7_t new_;
    pd_OptionAccountId_V7_t maybe_preclaim;
} pd_claims_move_claim_V7_t;

#define PD_CALL_UTILITY_AS_DERIVATIVE_V7 1
typedef struct {
    pd_u16_t index;
    pd_BoxTasConfigCall_V7_t call;
} pd_utility_as_derivative_V7_t;

#define PD_CALL_UTILITY_BATCH_ALL_V7 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V7_t;

#define PD_CALL_IDENTITY_ADD_REGISTRAR_V7 0
typedef struct {
    pd_AccountId_V7_t account;
} pd_identity_add_registrar_V7_t;

#define PD_CALL_IDENTITY_SET_IDENTITY_V7 1
typedef struct {
    pd_BoxIdentityInfoMaxAdditionalFields_V7_t info;
} pd_identity_set_identity_V7_t;

#define PD_CALL_IDENTITY_SET_SUBS_V7 2
typedef struct {
    pd_VecTupleAccountIdData_V7_t subs;
} pd_identity_set_subs_V7_t;

#define PD_CALL_IDENTITY_CLEAR_IDENTITY_V7 3
typedef struct {
} pd_identity_clear_identity_V7_t;

#define PD_CALL_IDENTITY_REQUEST_JUDGEMENT_V7 4
typedef struct {
    pd_Compactu32_t reg_index;
    pd_Compactu128_V7_t max_fee;
} pd_identity_request_judgement_V7_t;

#define PD_CALL_IDENTITY_CANCEL_REQUEST_V7 5
typedef struct {
    pd_RegistrarIndex_V7_t reg_index;
} pd_identity_cancel_request_V7_t;

#define PD_CALL_IDENTITY_SET_FEE_V7 6
typedef struct {
    pd_Compactu32_t index;
    pd_Compactu128_V7_t fee;
} pd_identity_set_fee_V7_t;

#define PD_CALL_IDENTITY_SET_ACCOUNT_ID_V7 7
typedef struct {
    pd_Compactu32_t index;
    pd_AccountId_V7_t new_;
} pd_identity_set_account_id_V7_t;

#define PD_CALL_IDENTITY_SET_FIELDS_V7 8
typedef struct {
    pd_Compactu32_t index;
    pd_IdentityFields_V7_t fields;
} pd_identity_set_fields_V7_t;

#define PD_CALL_IDENTITY_PROVIDE_JUDGEMENT_V7 9
typedef struct {
    pd_Compactu32_t reg_index;
    pd_LookupasStaticLookupSource_V7_t target;
    pd_JudgementBalanceOfT_V7_t judgement;
} pd_identity_provide_judgement_V7_t;

#define PD_CALL_IDENTITY_KILL_IDENTITY_V7 10
typedef struct {
    pd_LookupasStaticLookupSource_V7_t target;
} pd_identity_kill_identity_V7_t;

#define PD_CALL_IDENTITY_ADD_SUB_V7 11
typedef struct {
    pd_LookupasStaticLookupSource_V7_t sub;
    pd_Data_t data;
} pd_identity_add_sub_V7_t;

#define PD_CALL_IDENTITY_RENAME_SUB_V7 12
typedef struct {
    pd_LookupasStaticLookupSource_V7_t sub;
    pd_Data_t data;
} pd_identity_rename_sub_V7_t;

#define PD_CALL_IDENTITY_REMOVE_SUB_V7 13
typedef struct {
    pd_LookupasStaticLookupSource_V7_t sub;
} pd_identity_remove_sub_V7_t;

#define PD_CALL_IDENTITY_QUIT_SUB_V7 14
typedef struct {
} pd_identity_quit_sub_V7_t;

#define PD_CALL_SOCIETY_BID_V7 0
typedef struct {
    pd_Balance_t Amount;
} pd_society_bid_V7_t;

#define PD_CALL_SOCIETY_UNBID_V7 1
typedef struct {
    pd_u32_t pos;
} pd_society_unbid_V7_t;

#define PD_CALL_SOCIETY_VOUCH_V7 2
typedef struct {
    pd_AccountId_V7_t who;
    pd_Balance_t Amount;
    pd_Balance_t tip;
} pd_society_vouch_V7_t;

#define PD_CALL_SOCIETY_UNVOUCH_V7 3
typedef struct {
    pd_u32_t pos;
} pd_society_unvouch_V7_t;

#define PD_CALL_SOCIETY_VOTE_V7 4
typedef struct {
    pd_LookupasStaticLookupSource_V7_t candidate;
    pd_bool_t approve;
} pd_society_vote_V7_t;

#define PD_CALL_SOCIETY_DEFENDER_VOTE_V7 5
typedef struct {
    pd_bool_t approve;
} pd_society_defender_vote_V7_t;

#define PD_CALL_SOCIETY_PAYOUT_V7 6
typedef struct {
} pd_society_payout_V7_t;

#define PD_CALL_SOCIETY_FOUND_V7 7
typedef struct {
    pd_AccountId_V7_t founder;
    pd_u32_t max_members;
    pd_Vecu8_t rules;
} pd_society_found_V7_t;

#define PD_CALL_SOCIETY_UNFOUND_V7 8
typedef struct {
} pd_society_unfound_V7_t;

#define PD_CALL_SOCIETY_JUDGE_SUSPENDED_MEMBER_V7 9
typedef struct {
    pd_AccountId_V7_t who;
    pd_bool_t forgive;
} pd_society_judge_suspended_member_V7_t;

#define PD_CALL_SOCIETY_JUDGE_SUSPENDED_CANDIDATE_V7 10
typedef struct {
    pd_AccountId_V7_t who;
    pd_Judgement_V7_t judgement;
} pd_society_judge_suspended_candidate_V7_t;

#define PD_CALL_SOCIETY_SET_MAX_MEMBERS_V7 11
typedef struct {
    pd_u32_t max;
} pd_society_set_max_members_V7_t;

#define PD_CALL_RECOVERY_AS_RECOVERED_V7 0
typedef struct {
    pd_AccountId_V7_t account;
    pd_BoxTasConfigCall_V7_t call;
} pd_recovery_as_recovered_V7_t;

#define PD_CALL_RECOVERY_SET_RECOVERED_V7 1
typedef struct {
    pd_AccountId_V7_t lost;
    pd_AccountId_V7_t rescuer;
} pd_recovery_set_recovered_V7_t;

#define PD_CALL_RECOVERY_CREATE_RECOVERY_V7 2
typedef struct {
    pd_VecAccountId_V7_t friends;
    pd_u16_t threshold;
    pd_BlockNumber_t delay_period;
} pd_recovery_create_recovery_V7_t;

#define PD_CALL_RECOVERY_INITIATE_RECOVERY_V7 3
typedef struct {
    pd_AccountId_V7_t account;
} pd_recovery_initiate_recovery_V7_t;

#define PD_CALL_RECOVERY_VOUCH_RECOVERY_V7 4
typedef struct {
    pd_AccountId_V7_t lost;
    pd_AccountId_V7_t rescuer;
} pd_recovery_vouch_recovery_V7_t;

#define PD_CALL_RECOVERY_CLAIM_RECOVERY_V7 5
typedef struct {
    pd_AccountId_V7_t account;
} pd_recovery_claim_recovery_V7_t;

#define PD_CALL_RECOVERY_CLOSE_RECOVERY_V7 6
typedef struct {
    pd_AccountId_V7_t rescuer;
} pd_recovery_close_recovery_V7_t;

#define PD_CALL_RECOVERY_REMOVE_RECOVERY_V7 7
typedef struct {
} pd_recovery_remove_recovery_V7_t;

#define PD_CALL_RECOVERY_CANCEL_RECOVERED_V7 8
typedef struct {
    pd_AccountId_V7_t account;
} pd_recovery_cancel_recovered_V7_t;

#define PD_CALL_VESTING_VEST_V7 0
typedef struct {
} pd_vesting_vest_V7_t;

#define PD_CALL_VESTING_VEST_OTHER_V7 1
typedef struct {
    pd_LookupasStaticLookupSource_V7_t target;
} pd_vesting_vest_other_V7_t;

#define PD_CALL_VESTING_VESTED_TRANSFER_V7 2
typedef struct {
    pd_LookupasStaticLookupSource_V7_t target;
    pd_VestingInfoBalanceOfTBlockNumber_V7_t schedule;
} pd_vesting_vested_transfer_V7_t;

#define PD_CALL_VESTING_FORCE_VESTED_TRANSFER_V7 3
typedef struct {
    pd_LookupasStaticLookupSource_V7_t source;
    pd_LookupasStaticLookupSource_V7_t target;
    pd_VestingInfoBalanceOfTBlockNumber_V7_t schedule;
} pd_vesting_force_vested_transfer_V7_t;

#define PD_CALL_VESTING_MERGE_SCHEDULES_V7 4
typedef struct {
    pd_u32_t schedule1_index;
    pd_u32_t schedule2_index;
} pd_vesting_merge_schedules_V7_t;

#define PD_CALL_SCHEDULER_SCHEDULE_V7 0
typedef struct {
    pd_BlockNumber_t when;
    pd_OptionschedulePeriodBlockNumber_V7_t maybe_periodic;
    pd_schedulePriority_V7_t priority;
    pd_BoxTasConfigCall_V7_t call;
} pd_scheduler_schedule_V7_t;

#define PD_CALL_SCHEDULER_CANCEL_V7 1
typedef struct {
    pd_BlockNumber_t when;
    pd_u32_t index;
} pd_scheduler_cancel_V7_t;

#define PD_CALL_SCHEDULER_SCHEDULE_NAMED_V7 2
typedef struct {
    pd_Vecu8_t id;
    pd_BlockNumber_t when;
    pd_OptionschedulePeriodBlockNumber_V7_t maybe_periodic;
    pd_schedulePriority_V7_t priority;
    pd_BoxTasConfigCall_V7_t call;
} pd_scheduler_schedule_named_V7_t;

#define PD_CALL_SCHEDULER_CANCEL_NAMED_V7 3
typedef struct {
    pd_Vecu8_t id;
} pd_scheduler_cancel_named_V7_t;

#define PD_CALL_SCHEDULER_SCHEDULE_AFTER_V7 4
typedef struct {
    pd_BlockNumber_t after;
    pd_OptionschedulePeriodBlockNumber_V7_t maybe_periodic;
    pd_schedulePriority_V7_t priority;
    pd_BoxTasConfigCall_V7_t call;
} pd_scheduler_schedule_after_V7_t;

#define PD_CALL_SCHEDULER_SCHEDULE_NAMED_AFTER_V7 5
typedef struct {
    pd_Vecu8_t id;
    pd_BlockNumber_t after;
    pd_OptionschedulePeriodBlockNumber_V7_t maybe_periodic;
    pd_schedulePriority_V7_t priority;
    pd_BoxTasConfigCall_V7_t call;
} pd_scheduler_schedule_named_after_V7_t;

#define PD_CALL_PROXY_ADD_PROXY_V7 1
typedef struct {
    pd_AccountId_V7_t delegate;
    pd_ProxyType_V7_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_add_proxy_V7_t;

#define PD_CALL_PROXY_REMOVE_PROXY_V7 2
typedef struct {
    pd_AccountId_V7_t delegate;
    pd_ProxyType_V7_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_remove_proxy_V7_t;

#define PD_CALL_PROXY_REMOVE_PROXIES_V7 3
typedef struct {
} pd_proxy_remove_proxies_V7_t;

#define PD_CALL_PROXY_ANONYMOUS_V7 4
typedef struct {
    pd_ProxyType_V7_t proxy_type;
    pd_BlockNumber_t delay;
    pd_u16_t index;
} pd_proxy_anonymous_V7_t;

#define PD_CALL_PROXY_KILL_ANONYMOUS_V7 5
typedef struct {
    pd_AccountId_V7_t spawner;
    pd_ProxyType_V7_t proxy_type;
    pd_u16_t index;
    pd_Compactu32_t height;
    pd_Compactu32_t ext_index;
} pd_proxy_kill_anonymous_V7_t;

#define PD_CALL_PROXY_ANNOUNCE_V7 6
typedef struct {
    pd_AccountId_V7_t real;
    pd_CallHashOfT_V7_t call_hash;
} pd_proxy_announce_V7_t;

#define PD_CALL_PROXY_REMOVE_ANNOUNCEMENT_V7 7
typedef struct {
    pd_AccountId_V7_t real;
    pd_CallHashOfT_V7_t call_hash;
} pd_proxy_remove_announcement_V7_t;

#define PD_CALL_PROXY_REJECT_ANNOUNCEMENT_V7 8
typedef struct {
    pd_AccountId_V7_t delegate;
    pd_CallHashOfT_V7_t call_hash;
} pd_proxy_reject_announcement_V7_t;

#define PD_CALL_PROXY_PROXY_ANNOUNCED_V7 9
typedef struct {
    pd_AccountId_V7_t delegate;
    pd_AccountId_V7_t real;
    pd_OptionProxyType_V7_t force_proxy_type;
    pd_BoxTasConfigCall_V7_t call;
} pd_proxy_proxy_announced_V7_t;

#define PD_CALL_BOUNTIES_PROPOSE_BOUNTY_V7 0
typedef struct {
    pd_Compactu128_V7_t value;
    pd_Vecu8_t description;
} pd_bounties_propose_bounty_V7_t;

#define PD_CALL_BOUNTIES_APPROVE_BOUNTY_V7 1
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_approve_bounty_V7_t;

#define PD_CALL_BOUNTIES_PROPOSE_CURATOR_V7 2
typedef struct {
    pd_Compactu32_t bounty_id;
    pd_LookupasStaticLookupSource_V7_t curator;
    pd_Compactu128_V7_t fee;
} pd_bounties_propose_curator_V7_t;

#define PD_CALL_BOUNTIES_UNASSIGN_CURATOR_V7 3
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_unassign_curator_V7_t;

#define PD_CALL_BOUNTIES_ACCEPT_CURATOR_V7 4
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_accept_curator_V7_t;

#define PD_CALL_BOUNTIES_AWARD_BOUNTY_V7 5
typedef struct {
    pd_Compactu32_t bounty_id;
    pd_LookupasStaticLookupSource_V7_t beneficiary;
} pd_bounties_award_bounty_V7_t;

#define PD_CALL_BOUNTIES_CLAIM_BOUNTY_V7 6
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_claim_bounty_V7_t;

#define PD_CALL_BOUNTIES_CLOSE_BOUNTY_V7 7
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_close_bounty_V7_t;

#define PD_CALL_BOUNTIES_EXTEND_BOUNTY_EXPIRY_V7 8
typedef struct {
    pd_Compactu32_t bounty_id;
    pd_Vecu8_t remark;
} pd_bounties_extend_bounty_expiry_V7_t;

#define PD_CALL_TIPS_REPORT_AWESOME_V7 0
typedef struct {
    pd_Vecu8_t reason;
    pd_AccountId_V7_t who;
} pd_tips_report_awesome_V7_t;

#define PD_CALL_TIPS_RETRACT_TIP_V7 1
typedef struct {
    pd_Hash_t hash;
} pd_tips_retract_tip_V7_t;

#define PD_CALL_TIPS_TIP_NEW_V7 2
typedef struct {
    pd_Vecu8_t reason;
    pd_AccountId_V7_t who;
    pd_Compactu128_V7_t tip_value;
} pd_tips_tip_new_V7_t;

#define PD_CALL_TIPS_TIP_V7 3
typedef struct {
    pd_Hash_t hash;
    pd_Compactu128_V7_t tip_value;
} pd_tips_tip_V7_t;

#define PD_CALL_TIPS_CLOSE_TIP_V7 4
typedef struct {
    pd_Hash_t hash;
} pd_tips_close_tip_V7_t;

#define PD_CALL_TIPS_SLASH_TIP_V7 5
typedef struct {
    pd_Hash_t hash;
} pd_tips_slash_tip_V7_t;

#define PD_CALL_ELECTIONPROVIDERMULTIPHASE_SUBMIT_UNSIGNED_V7 0
typedef struct {
    pd_BoxRawSolutionSolutionOfT_V7_t raw_solution;
    pd_SolutionOrSnapshotSize_V7_t witness;
} pd_electionprovidermultiphase_submit_unsigned_V7_t;

#define PD_CALL_ELECTIONPROVIDERMULTIPHASE_SET_MINIMUM_UNTRUSTED_SCORE_V7 1
typedef struct {
    pd_OptionElectionScore_V7_t maybe_next_score;
} pd_electionprovidermultiphase_set_minimum_untrusted_score_V7_t;

#define PD_CALL_ELECTIONPROVIDERMULTIPHASE_SET_EMERGENCY_ELECTION_RESULT_V7 2
typedef struct {
    pd_SupportsAccountId_V7_t supports;
} pd_electionprovidermultiphase_set_emergency_election_result_V7_t;

#define PD_CALL_ELECTIONPROVIDERMULTIPHASE_SUBMIT_V7 3
typedef struct {
    pd_BoxRawSolutionSolutionOfT_V7_t raw_solution;
    pd_u32_t num_signed_submissions;
} pd_electionprovidermultiphase_submit_V7_t;

#define PD_CALL_GILT_PLACE_BID_V7 0
typedef struct {
    pd_Compactu128_V7_t amount;
    pd_u32_t duration;
} pd_gilt_place_bid_V7_t;

#define PD_CALL_GILT_RETRACT_BID_V7 1
typedef struct {
    pd_Compactu128_V7_t amount;
    pd_u32_t duration;
} pd_gilt_retract_bid_V7_t;

#define PD_CALL_GILT_SET_TARGET_V7 2
typedef struct {
    pd_Compactu64_t target;
} pd_gilt_set_target_V7_t;

#define PD_CALL_GILT_THAW_V7 3
typedef struct {
    pd_Compactu32_t index;
} pd_gilt_thaw_V7_t;

#define PD_CALL_BAGSLIST_REBAG_V7 0
typedef struct {
    pd_AccountId_V7_t dislocated;
} pd_bagslist_rebag_V7_t;

#define PD_CALL_CONFIGURATION_SET_VALIDATION_UPGRADE_FREQUENCY_V7 0
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_validation_upgrade_frequency_V7_t;

#define PD_CALL_CONFIGURATION_SET_VALIDATION_UPGRADE_DELAY_V7 1
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_validation_upgrade_delay_V7_t;

#define PD_CALL_CONFIGURATION_SET_CODE_RETENTION_PERIOD_V7 2
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_code_retention_period_V7_t;

#define PD_CALL_CONFIGURATION_SET_MAX_CODE_SIZE_V7 3
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_code_size_V7_t;

#define PD_CALL_CONFIGURATION_SET_MAX_POV_SIZE_V7 4
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_pov_size_V7_t;

#define PD_CALL_CONFIGURATION_SET_MAX_HEAD_DATA_SIZE_V7 5
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_head_data_size_V7_t;

#define PD_CALL_CONFIGURATION_SET_PARATHREAD_CORES_V7 6
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_parathread_cores_V7_t;

#define PD_CALL_CONFIGURATION_SET_PARATHREAD_RETRIES_V7 7
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_parathread_retries_V7_t;

#define PD_CALL_CONFIGURATION_SET_GROUP_ROTATION_FREQUENCY_V7 8
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_group_rotation_frequency_V7_t;

#define PD_CALL_CONFIGURATION_SET_CHAIN_AVAILABILITY_PERIOD_V7 9
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_chain_availability_period_V7_t;

#define PD_CALL_CONFIGURATION_SET_THREAD_AVAILABILITY_PERIOD_V7 10
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_thread_availability_period_V7_t;

#define PD_CALL_CONFIGURATION_SET_SCHEDULING_LOOKAHEAD_V7 11
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_scheduling_lookahead_V7_t;

#define PD_CALL_CONFIGURATION_SET_MAX_VALIDATORS_PER_CORE_V7 12
typedef struct {
    pd_Optionu32_t new_;
} pd_configuration_set_max_validators_per_core_V7_t;

#define PD_CALL_CONFIGURATION_SET_MAX_VALIDATORS_V7 13
typedef struct {
    pd_Optionu32_t new_;
} pd_configuration_set_max_validators_V7_t;

#define PD_CALL_CONFIGURATION_SET_DISPUTE_PERIOD_V7 14
typedef struct {
    pd_SessionIndex_V7_t new_;
} pd_configuration_set_dispute_period_V7_t;

#define PD_CALL_CONFIGURATION_SET_DISPUTE_POST_CONCLUSION_ACCEPTANCE_PERIOD_V7 15
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_dispute_post_conclusion_acceptance_period_V7_t;

#define PD_CALL_CONFIGURATION_SET_DISPUTE_MAX_SPAM_SLOTS_V7 16
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_dispute_max_spam_slots_V7_t;

#define PD_CALL_CONFIGURATION_SET_DISPUTE_CONCLUSION_BY_TIME_OUT_PERIOD_V7 17
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_dispute_conclusion_by_time_out_period_V7_t;

#define PD_CALL_CONFIGURATION_SET_NO_SHOW_SLOTS_V7 18
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_no_show_slots_V7_t;

#define PD_CALL_CONFIGURATION_SET_N_DELAY_TRANCHES_V7 19
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_n_delay_tranches_V7_t;

#define PD_CALL_CONFIGURATION_SET_ZEROTH_DELAY_TRANCHE_WIDTH_V7 20
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_zeroth_delay_tranche_width_V7_t;

#define PD_CALL_CONFIGURATION_SET_NEEDED_APPROVALS_V7 21
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_needed_approvals_V7_t;

#define PD_CALL_CONFIGURATION_SET_RELAY_VRF_MODULO_SAMPLES_V7 22
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_relay_vrf_modulo_samples_V7_t;

#define PD_CALL_CONFIGURATION_SET_MAX_UPWARD_QUEUE_COUNT_V7 23
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_upward_queue_count_V7_t;

#define PD_CALL_CONFIGURATION_SET_MAX_UPWARD_QUEUE_SIZE_V7 24
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_upward_queue_size_V7_t;

#define PD_CALL_CONFIGURATION_SET_MAX_DOWNWARD_MESSAGE_SIZE_V7 25
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_downward_message_size_V7_t;

#define PD_CALL_CONFIGURATION_SET_UMP_SERVICE_TOTAL_WEIGHT_V7 26
typedef struct {
    pd_Weight_V7_t new_;
} pd_configuration_set_ump_service_total_weight_V7_t;

#define PD_CALL_CONFIGURATION_SET_MAX_UPWARD_MESSAGE_SIZE_V7 27
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_upward_message_size_V7_t;

#define PD_CALL_CONFIGURATION_SET_MAX_UPWARD_MESSAGE_NUM_PER_CANDIDATE_V7 28
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_upward_message_num_per_candidate_V7_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_OPEN_REQUEST_TTL_V7 29
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_open_request_ttl_V7_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_SENDER_DEPOSIT_V7 30
typedef struct {
    pd_Balance_t new_;
} pd_configuration_set_hrmp_sender_deposit_V7_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_RECIPIENT_DEPOSIT_V7 31
typedef struct {
    pd_Balance_t new_;
} pd_configuration_set_hrmp_recipient_deposit_V7_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_CHANNEL_MAX_CAPACITY_V7 32
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_channel_max_capacity_V7_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_CHANNEL_MAX_TOTAL_SIZE_V7 33
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_channel_max_total_size_V7_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_PARACHAIN_INBOUND_CHANNELS_V7 34
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_parachain_inbound_channels_V7_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_PARATHREAD_INBOUND_CHANNELS_V7 35
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_parathread_inbound_channels_V7_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_CHANNEL_MAX_MESSAGE_SIZE_V7 36
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_channel_max_message_size_V7_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_PARACHAIN_OUTBOUND_CHANNELS_V7 37
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_parachain_outbound_channels_V7_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_PARATHREAD_OUTBOUND_CHANNELS_V7 38
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_parathread_outbound_channels_V7_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_MESSAGE_NUM_PER_CANDIDATE_V7 39
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_message_num_per_candidate_V7_t;

#define PD_CALL_CONFIGURATION_SET_UMP_MAX_INDIVIDUAL_WEIGHT_V7 40
typedef struct {
    pd_Weight_V7_t new_;
} pd_configuration_set_ump_max_individual_weight_V7_t;

#define PD_CALL_PARAINHERENT_ENTER_V7 0
typedef struct {
    pd_ParachainsInherentDataHeader_V7_t data;
} pd_parainherent_enter_V7_t;

#define PD_CALL_PARAS_FORCE_SET_CURRENT_CODE_V7 0
typedef struct {
    pd_ParaId_V7_t para;
    pd_ValidationCode_V7_t new_code;
} pd_paras_force_set_current_code_V7_t;

#define PD_CALL_PARAS_FORCE_SET_CURRENT_HEAD_V7 1
typedef struct {
    pd_ParaId_V7_t para;
    pd_HeadData_V7_t new_head;
} pd_paras_force_set_current_head_V7_t;

#define PD_CALL_PARAS_FORCE_SCHEDULE_CODE_UPGRADE_V7 2
typedef struct {
    pd_ParaId_V7_t para;
    pd_ValidationCode_V7_t new_code;
    pd_BlockNumber_t relay_parent_number;
} pd_paras_force_schedule_code_upgrade_V7_t;

#define PD_CALL_PARAS_FORCE_NOTE_NEW_HEAD_V7 3
typedef struct {
    pd_ParaId_V7_t para;
    pd_HeadData_V7_t new_head;
} pd_paras_force_note_new_head_V7_t;

#define PD_CALL_PARAS_FORCE_QUEUE_ACTION_V7 4
typedef struct {
    pd_ParaId_V7_t para;
} pd_paras_force_queue_action_V7_t;

#define PD_CALL_INITIALIZER_FORCE_APPROVE_V7 0
typedef struct {
    pd_BlockNumber_t up_to;
} pd_initializer_force_approve_V7_t;

#define PD_CALL_UMP_SERVICE_OVERWEIGHT_V7 0
typedef struct {
    pd_OverweightIndex_V7_t index;
    pd_Weight_V7_t weight_limit;
} pd_ump_service_overweight_V7_t;

#define PD_CALL_HRMP_HRMP_INIT_OPEN_CHANNEL_V7 0
typedef struct {
    pd_ParaId_V7_t recipient;
    pd_u32_t proposed_max_capacity;
    pd_u32_t proposed_max_message_size;
} pd_hrmp_hrmp_init_open_channel_V7_t;

#define PD_CALL_HRMP_HRMP_ACCEPT_OPEN_CHANNEL_V7 1
typedef struct {
    pd_ParaId_V7_t sender;
} pd_hrmp_hrmp_accept_open_channel_V7_t;

#define PD_CALL_HRMP_HRMP_CLOSE_CHANNEL_V7 2
typedef struct {
    pd_HrmpChannelId_V7_t channel_id;
} pd_hrmp_hrmp_close_channel_V7_t;

#define PD_CALL_HRMP_FORCE_CLEAN_HRMP_V7 3
typedef struct {
    pd_ParaId_V7_t para;
} pd_hrmp_force_clean_hrmp_V7_t;

#define PD_CALL_HRMP_FORCE_PROCESS_HRMP_OPEN_V7 4
typedef struct {
} pd_hrmp_force_process_hrmp_open_V7_t;

#define PD_CALL_HRMP_FORCE_PROCESS_HRMP_CLOSE_V7 5
typedef struct {
} pd_hrmp_force_process_hrmp_close_V7_t;

#define PD_CALL_HRMP_HRMP_CANCEL_OPEN_REQUEST_V7 6
typedef struct {
    pd_HrmpChannelId_V7_t channel_id;
} pd_hrmp_hrmp_cancel_open_request_V7_t;

#define PD_CALL_REGISTRAR_REGISTER_V7 0
typedef struct {
    pd_ParaId_V7_t id;
    pd_HeadData_V7_t genesis_head;
    pd_ValidationCode_V7_t validation_code;
} pd_registrar_register_V7_t;

#define PD_CALL_REGISTRAR_FORCE_REGISTER_V7 1
typedef struct {
    pd_AccountId_V7_t who;
    pd_Balance_t deposit;
    pd_ParaId_V7_t id;
    pd_HeadData_V7_t genesis_head;
    pd_ValidationCode_V7_t validation_code;
} pd_registrar_force_register_V7_t;

#define PD_CALL_REGISTRAR_DEREGISTER_V7 2
typedef struct {
    pd_ParaId_V7_t id;
} pd_registrar_deregister_V7_t;

#define PD_CALL_REGISTRAR_SWAP_V7 3
typedef struct {
    pd_ParaId_V7_t id;
    pd_ParaId_V7_t other;
} pd_registrar_swap_V7_t;

#define PD_CALL_REGISTRAR_FORCE_REMOVE_LOCK_V7 4
typedef struct {
    pd_ParaId_V7_t para;
} pd_registrar_force_remove_lock_V7_t;

#define PD_CALL_REGISTRAR_RESERVE_V7 5
typedef struct {
} pd_registrar_reserve_V7_t;

#define PD_CALL_SLOTS_FORCE_LEASE_V7 0
typedef struct {
    pd_ParaId_V7_t para;
    pd_AccountId_V7_t leaser;
    pd_Balance_t amount;
    pd_LeasePeriodOfT_V7_t period_begin;
    pd_LeasePeriodOfT_V7_t period_count;
} pd_slots_force_lease_V7_t;

#define PD_CALL_SLOTS_CLEAR_ALL_LEASES_V7 1
typedef struct {
    pd_ParaId_V7_t para;
} pd_slots_clear_all_leases_V7_t;

#define PD_CALL_SLOTS_TRIGGER_ONBOARD_V7 2
typedef struct {
    pd_ParaId_V7_t para;
} pd_slots_trigger_onboard_V7_t;

#define PD_CALL_AUCTIONS_NEW_AUCTION_V7 0
typedef struct {
    pd_Compactu32_t duration;
    pd_Compactu32_t lease_period_index;
} pd_auctions_new_auction_V7_t;

#define PD_CALL_AUCTIONS_BID_V7 1
typedef struct {
    pd_Compactu32_t para;
    pd_Compactu32_t auction_index;
    pd_Compactu32_t first_slot;
    pd_Compactu32_t last_slot;
    pd_Compactu128_V7_t amount;
} pd_auctions_bid_V7_t;

#define PD_CALL_AUCTIONS_CANCEL_AUCTION_V7 2
typedef struct {
} pd_auctions_cancel_auction_V7_t;

#define PD_CALL_CROWDLOAN_CREATE_V7 0
typedef struct {
    pd_Compactu32_t index;
    pd_Compactu128_V7_t cap;
    pd_Compactu32_t first_period;
    pd_Compactu32_t last_period;
    pd_Compactu32_t end;
    pd_OptionMultiSigner_V7_t verifier;
} pd_crowdloan_create_V7_t;

#define PD_CALL_CROWDLOAN_CONTRIBUTE_V7 1
typedef struct {
    pd_Compactu32_t index;
    pd_Compactu128_V7_t value;
    pd_OptionMultiSignature_V7_t signature;
} pd_crowdloan_contribute_V7_t;

#define PD_CALL_CROWDLOAN_WITHDRAW_V7 2
typedef struct {
    pd_AccountId_V7_t who;
    pd_Compactu32_t index;
} pd_crowdloan_withdraw_V7_t;

#define PD_CALL_CROWDLOAN_REFUND_V7 3
typedef struct {
    pd_Compactu32_t index;
} pd_crowdloan_refund_V7_t;

#define PD_CALL_CROWDLOAN_DISSOLVE_V7 4
typedef struct {
    pd_Compactu32_t index;
} pd_crowdloan_dissolve_V7_t;

#define PD_CALL_CROWDLOAN_EDIT_V7 5
typedef struct {
    pd_Compactu32_t index;
    pd_Compactu128_V7_t cap;
    pd_Compactu32_t first_period;
    pd_Compactu32_t last_period;
    pd_Compactu32_t end;
    pd_OptionMultiSigner_V7_t verifier;
} pd_crowdloan_edit_V7_t;

#define PD_CALL_CROWDLOAN_ADD_MEMO_V7 6
typedef struct {
    pd_ParaId_V7_t index;
    pd_Vecu8_t memo;
} pd_crowdloan_add_memo_V7_t;

#define PD_CALL_CROWDLOAN_POKE_V7 7
typedef struct {
    pd_ParaId_V7_t index;
} pd_crowdloan_poke_V7_t;

#define PD_CALL_XCMPALLET_SEND_V7 0
typedef struct {
    pd_BoxVersionedMultiLocation_V7_t dest;
    pd_BoxVersionedXcmTuple_V7_t message;
} pd_xcmpallet_send_V7_t;

#define PD_CALL_XCMPALLET_TELEPORT_ASSETS_V7 1
typedef struct {
    pd_BoxVersionedMultiLocation_V7_t dest;
    pd_BoxVersionedMultiLocation_V7_t beneficiary;
    pd_BoxVersionedMultiAssets_V7_t assets;
    pd_u32_t fee_asset_item;
} pd_xcmpallet_teleport_assets_V7_t;

#define PD_CALL_XCMPALLET_RESERVE_TRANSFER_ASSETS_V7 2
typedef struct {
    pd_BoxVersionedMultiLocation_V7_t dest;
    pd_BoxVersionedMultiLocation_V7_t beneficiary;
    pd_BoxVersionedMultiAssets_V7_t assets;
    pd_u32_t fee_asset_item;
} pd_xcmpallet_reserve_transfer_assets_V7_t;

#define PD_CALL_XCMPALLET_EXECUTE_V7 3
typedef struct {
    pd_BoxVersionedXcmTasSysConfigCall_V7_t message;
    pd_Weight_V7_t max_weight;
} pd_xcmpallet_execute_V7_t;

#define PD_CALL_XCMPALLET_FORCE_XCM_VERSION_V7 4
typedef struct {
    pd_BoxMultiLocation_V7_t location;
    pd_XcmVersion_V7_t xcm_version;
} pd_xcmpallet_force_xcm_version_V7_t;

#define PD_CALL_XCMPALLET_FORCE_DEFAULT_XCM_VERSION_V7 5
typedef struct {
    pd_OptionXcmVersion_V7_t maybe_xcm_version;
} pd_xcmpallet_force_default_xcm_version_V7_t;

#define PD_CALL_XCMPALLET_FORCE_SUBSCRIBE_VERSION_NOTIFY_V7 6
typedef struct {
    pd_BoxVersionedMultiLocation_V7_t location;
} pd_xcmpallet_force_subscribe_version_notify_V7_t;

#define PD_CALL_XCMPALLET_FORCE_UNSUBSCRIBE_VERSION_NOTIFY_V7 7
typedef struct {
    pd_BoxVersionedMultiLocation_V7_t location;
} pd_xcmpallet_force_unsubscribe_version_notify_V7_t;

#endif

typedef union {
    pd_staking_bond_V7_t staking_bond_V7;
    pd_staking_unbond_V7_t staking_unbond_V7;
    pd_staking_validate_V7_t staking_validate_V7;
    pd_staking_nominate_V7_t staking_nominate_V7;
    pd_staking_chill_V7_t staking_chill_V7;
    pd_staking_rebond_V7_t staking_rebond_V7;
    pd_utility_batch_V7_t utility_batch_V7;
#ifdef SUBSTRATE_PARSER_FULL
    pd_system_remark_with_event_V7_t system_remark_with_event_V7;
    pd_babe_report_equivocation_V7_t babe_report_equivocation_V7;
    pd_babe_report_equivocation_unsigned_V7_t babe_report_equivocation_unsigned_V7;
    pd_babe_plan_config_change_V7_t babe_plan_config_change_V7;
    pd_timestamp_set_V7_t timestamp_set_V7;
    pd_indices_claim_V7_t indices_claim_V7;
    pd_indices_transfer_V7_t indices_transfer_V7;
    pd_indices_free_V7_t indices_free_V7;
    pd_indices_force_transfer_V7_t indices_force_transfer_V7;
    pd_indices_freeze_V7_t indices_freeze_V7;
    pd_balances_transfer_all_V7_t balances_transfer_all_V7;
    pd_balances_force_unreserve_V7_t balances_force_unreserve_V7;
    pd_authorship_set_uncles_V7_t authorship_set_uncles_V7;
    pd_staking_bond_extra_V7_t staking_bond_extra_V7;
    pd_staking_withdraw_unbonded_V7_t staking_withdraw_unbonded_V7;
    pd_staking_set_payee_V7_t staking_set_payee_V7;
    pd_staking_set_controller_V7_t staking_set_controller_V7;
    pd_staking_set_validator_count_V7_t staking_set_validator_count_V7;
    pd_staking_increase_validator_count_V7_t staking_increase_validator_count_V7;
    pd_staking_scale_validator_count_V7_t staking_scale_validator_count_V7;
    pd_staking_force_no_eras_V7_t staking_force_no_eras_V7;
    pd_staking_force_new_era_V7_t staking_force_new_era_V7;
    pd_staking_set_invulnerables_V7_t staking_set_invulnerables_V7;
    pd_staking_force_unstake_V7_t staking_force_unstake_V7;
    pd_staking_force_new_era_always_V7_t staking_force_new_era_always_V7;
    pd_staking_cancel_deferred_slash_V7_t staking_cancel_deferred_slash_V7;
    pd_staking_payout_stakers_V7_t staking_payout_stakers_V7;
    pd_staking_set_history_depth_V7_t staking_set_history_depth_V7;
    pd_staking_reap_stash_V7_t staking_reap_stash_V7;
    pd_staking_kick_V7_t staking_kick_V7;
    pd_staking_set_staking_limits_V7_t staking_set_staking_limits_V7;
    pd_staking_chill_other_V7_t staking_chill_other_V7;
    pd_session_set_keys_V7_t session_set_keys_V7;
    pd_session_purge_keys_V7_t session_purge_keys_V7;
    pd_grandpa_report_equivocation_V7_t grandpa_report_equivocation_V7;
    pd_grandpa_report_equivocation_unsigned_V7_t grandpa_report_equivocation_unsigned_V7;
    pd_grandpa_note_stalled_V7_t grandpa_note_stalled_V7;
    pd_imonline_heartbeat_V7_t imonline_heartbeat_V7;
    pd_democracy_propose_V7_t democracy_propose_V7;
    pd_democracy_second_V7_t democracy_second_V7;
    pd_democracy_vote_V7_t democracy_vote_V7;
    pd_democracy_emergency_cancel_V7_t democracy_emergency_cancel_V7;
    pd_democracy_external_propose_V7_t democracy_external_propose_V7;
    pd_democracy_external_propose_majority_V7_t democracy_external_propose_majority_V7;
    pd_democracy_external_propose_default_V7_t democracy_external_propose_default_V7;
    pd_democracy_fast_track_V7_t democracy_fast_track_V7;
    pd_democracy_veto_external_V7_t democracy_veto_external_V7;
    pd_democracy_cancel_referendum_V7_t democracy_cancel_referendum_V7;
    pd_democracy_cancel_queued_V7_t democracy_cancel_queued_V7;
    pd_democracy_delegate_V7_t democracy_delegate_V7;
    pd_democracy_undelegate_V7_t democracy_undelegate_V7;
    pd_democracy_clear_public_proposals_V7_t democracy_clear_public_proposals_V7;
    pd_democracy_note_preimage_V7_t democracy_note_preimage_V7;
    pd_democracy_note_preimage_operational_V7_t democracy_note_preimage_operational_V7;
    pd_democracy_note_imminent_preimage_V7_t democracy_note_imminent_preimage_V7;
    pd_democracy_note_imminent_preimage_operational_V7_t democracy_note_imminent_preimage_operational_V7;
    pd_democracy_reap_preimage_V7_t democracy_reap_preimage_V7;
    pd_democracy_unlock_V7_t democracy_unlock_V7;
    pd_democracy_remove_vote_V7_t democracy_remove_vote_V7;
    pd_democracy_remove_other_vote_V7_t democracy_remove_other_vote_V7;
    pd_democracy_enact_proposal_V7_t democracy_enact_proposal_V7;
    pd_democracy_blacklist_V7_t democracy_blacklist_V7;
    pd_democracy_cancel_proposal_V7_t democracy_cancel_proposal_V7;
    pd_council_set_members_V7_t council_set_members_V7;
    pd_council_execute_V7_t council_execute_V7;
    pd_council_propose_V7_t council_propose_V7;
    pd_council_vote_V7_t council_vote_V7;
    pd_council_close_V7_t council_close_V7;
    pd_council_disapprove_proposal_V7_t council_disapprove_proposal_V7;
    pd_technicalcommittee_set_members_V7_t technicalcommittee_set_members_V7;
    pd_technicalcommittee_execute_V7_t technicalcommittee_execute_V7;
    pd_technicalcommittee_propose_V7_t technicalcommittee_propose_V7;
    pd_technicalcommittee_vote_V7_t technicalcommittee_vote_V7;
    pd_technicalcommittee_close_V7_t technicalcommittee_close_V7;
    pd_technicalcommittee_disapprove_proposal_V7_t technicalcommittee_disapprove_proposal_V7;
    pd_phragmenelection_vote_V7_t phragmenelection_vote_V7;
    pd_phragmenelection_remove_voter_V7_t phragmenelection_remove_voter_V7;
    pd_phragmenelection_submit_candidacy_V7_t phragmenelection_submit_candidacy_V7;
    pd_phragmenelection_renounce_candidacy_V7_t phragmenelection_renounce_candidacy_V7;
    pd_phragmenelection_remove_member_V7_t phragmenelection_remove_member_V7;
    pd_phragmenelection_clean_defunct_voters_V7_t phragmenelection_clean_defunct_voters_V7;
    pd_technicalmembership_add_member_V7_t technicalmembership_add_member_V7;
    pd_technicalmembership_remove_member_V7_t technicalmembership_remove_member_V7;
    pd_technicalmembership_swap_member_V7_t technicalmembership_swap_member_V7;
    pd_technicalmembership_reset_members_V7_t technicalmembership_reset_members_V7;
    pd_technicalmembership_change_key_V7_t technicalmembership_change_key_V7;
    pd_technicalmembership_set_prime_V7_t technicalmembership_set_prime_V7;
    pd_technicalmembership_clear_prime_V7_t technicalmembership_clear_prime_V7;
    pd_treasury_propose_spend_V7_t treasury_propose_spend_V7;
    pd_treasury_reject_proposal_V7_t treasury_reject_proposal_V7;
    pd_treasury_approve_proposal_V7_t treasury_approve_proposal_V7;
    pd_claims_claim_V7_t claims_claim_V7;
    pd_claims_mint_claim_V7_t claims_mint_claim_V7;
    pd_claims_claim_attest_V7_t claims_claim_attest_V7;
    pd_claims_attest_V7_t claims_attest_V7;
    pd_claims_move_claim_V7_t claims_move_claim_V7;
    pd_utility_as_derivative_V7_t utility_as_derivative_V7;
    pd_utility_batch_all_V7_t utility_batch_all_V7;
    pd_identity_add_registrar_V7_t identity_add_registrar_V7;
    pd_identity_set_identity_V7_t identity_set_identity_V7;
    pd_identity_set_subs_V7_t identity_set_subs_V7;
    pd_identity_clear_identity_V7_t identity_clear_identity_V7;
    pd_identity_request_judgement_V7_t identity_request_judgement_V7;
    pd_identity_cancel_request_V7_t identity_cancel_request_V7;
    pd_identity_set_fee_V7_t identity_set_fee_V7;
    pd_identity_set_account_id_V7_t identity_set_account_id_V7;
    pd_identity_set_fields_V7_t identity_set_fields_V7;
    pd_identity_provide_judgement_V7_t identity_provide_judgement_V7;
    pd_identity_kill_identity_V7_t identity_kill_identity_V7;
    pd_identity_add_sub_V7_t identity_add_sub_V7;
    pd_identity_rename_sub_V7_t identity_rename_sub_V7;
    pd_identity_remove_sub_V7_t identity_remove_sub_V7;
    pd_identity_quit_sub_V7_t identity_quit_sub_V7;
    pd_society_bid_V7_t society_bid_V7;
    pd_society_unbid_V7_t society_unbid_V7;
    pd_society_vouch_V7_t society_vouch_V7;
    pd_society_unvouch_V7_t society_unvouch_V7;
    pd_society_vote_V7_t society_vote_V7;
    pd_society_defender_vote_V7_t society_defender_vote_V7;
    pd_society_payout_V7_t society_payout_V7;
    pd_society_found_V7_t society_found_V7;
    pd_society_unfound_V7_t society_unfound_V7;
    pd_society_judge_suspended_member_V7_t society_judge_suspended_member_V7;
    pd_society_judge_suspended_candidate_V7_t society_judge_suspended_candidate_V7;
    pd_society_set_max_members_V7_t society_set_max_members_V7;
    pd_recovery_as_recovered_V7_t recovery_as_recovered_V7;
    pd_recovery_set_recovered_V7_t recovery_set_recovered_V7;
    pd_recovery_create_recovery_V7_t recovery_create_recovery_V7;
    pd_recovery_initiate_recovery_V7_t recovery_initiate_recovery_V7;
    pd_recovery_vouch_recovery_V7_t recovery_vouch_recovery_V7;
    pd_recovery_claim_recovery_V7_t recovery_claim_recovery_V7;
    pd_recovery_close_recovery_V7_t recovery_close_recovery_V7;
    pd_recovery_remove_recovery_V7_t recovery_remove_recovery_V7;
    pd_recovery_cancel_recovered_V7_t recovery_cancel_recovered_V7;
    pd_vesting_vest_V7_t vesting_vest_V7;
    pd_vesting_vest_other_V7_t vesting_vest_other_V7;
    pd_vesting_vested_transfer_V7_t vesting_vested_transfer_V7;
    pd_vesting_force_vested_transfer_V7_t vesting_force_vested_transfer_V7;
    pd_vesting_merge_schedules_V7_t vesting_merge_schedules_V7;
    pd_scheduler_schedule_V7_t scheduler_schedule_V7;
    pd_scheduler_cancel_V7_t scheduler_cancel_V7;
    pd_scheduler_schedule_named_V7_t scheduler_schedule_named_V7;
    pd_scheduler_cancel_named_V7_t scheduler_cancel_named_V7;
    pd_scheduler_schedule_after_V7_t scheduler_schedule_after_V7;
    pd_scheduler_schedule_named_after_V7_t scheduler_schedule_named_after_V7;
    pd_proxy_add_proxy_V7_t proxy_add_proxy_V7;
    pd_proxy_remove_proxy_V7_t proxy_remove_proxy_V7;
    pd_proxy_remove_proxies_V7_t proxy_remove_proxies_V7;
    pd_proxy_anonymous_V7_t proxy_anonymous_V7;
    pd_proxy_kill_anonymous_V7_t proxy_kill_anonymous_V7;
    pd_proxy_announce_V7_t proxy_announce_V7;
    pd_proxy_remove_announcement_V7_t proxy_remove_announcement_V7;
    pd_proxy_reject_announcement_V7_t proxy_reject_announcement_V7;
    pd_proxy_proxy_announced_V7_t proxy_proxy_announced_V7;
    pd_bounties_propose_bounty_V7_t bounties_propose_bounty_V7;
    pd_bounties_approve_bounty_V7_t bounties_approve_bounty_V7;
    pd_bounties_propose_curator_V7_t bounties_propose_curator_V7;
    pd_bounties_unassign_curator_V7_t bounties_unassign_curator_V7;
    pd_bounties_accept_curator_V7_t bounties_accept_curator_V7;
    pd_bounties_award_bounty_V7_t bounties_award_bounty_V7;
    pd_bounties_claim_bounty_V7_t bounties_claim_bounty_V7;
    pd_bounties_close_bounty_V7_t bounties_close_bounty_V7;
    pd_bounties_extend_bounty_expiry_V7_t bounties_extend_bounty_expiry_V7;
    pd_tips_report_awesome_V7_t tips_report_awesome_V7;
    pd_tips_retract_tip_V7_t tips_retract_tip_V7;
    pd_tips_tip_new_V7_t tips_tip_new_V7;
    pd_tips_tip_V7_t tips_tip_V7;
    pd_tips_close_tip_V7_t tips_close_tip_V7;
    pd_tips_slash_tip_V7_t tips_slash_tip_V7;
    pd_electionprovidermultiphase_submit_unsigned_V7_t electionprovidermultiphase_submit_unsigned_V7;
    pd_electionprovidermultiphase_set_minimum_untrusted_score_V7_t electionprovidermultiphase_set_minimum_untrusted_score_V7;
    pd_electionprovidermultiphase_set_emergency_election_result_V7_t electionprovidermultiphase_set_emergency_election_result_V7;
    pd_electionprovidermultiphase_submit_V7_t electionprovidermultiphase_submit_V7;
    pd_gilt_place_bid_V7_t gilt_place_bid_V7;
    pd_gilt_retract_bid_V7_t gilt_retract_bid_V7;
    pd_gilt_set_target_V7_t gilt_set_target_V7;
    pd_gilt_thaw_V7_t gilt_thaw_V7;
    pd_bagslist_rebag_V7_t bagslist_rebag_V7;
    pd_configuration_set_validation_upgrade_frequency_V7_t configuration_set_validation_upgrade_frequency_V7;
    pd_configuration_set_validation_upgrade_delay_V7_t configuration_set_validation_upgrade_delay_V7;
    pd_configuration_set_code_retention_period_V7_t configuration_set_code_retention_period_V7;
    pd_configuration_set_max_code_size_V7_t configuration_set_max_code_size_V7;
    pd_configuration_set_max_pov_size_V7_t configuration_set_max_pov_size_V7;
    pd_configuration_set_max_head_data_size_V7_t configuration_set_max_head_data_size_V7;
    pd_configuration_set_parathread_cores_V7_t configuration_set_parathread_cores_V7;
    pd_configuration_set_parathread_retries_V7_t configuration_set_parathread_retries_V7;
    pd_configuration_set_group_rotation_frequency_V7_t configuration_set_group_rotation_frequency_V7;
    pd_configuration_set_chain_availability_period_V7_t configuration_set_chain_availability_period_V7;
    pd_configuration_set_thread_availability_period_V7_t configuration_set_thread_availability_period_V7;
    pd_configuration_set_scheduling_lookahead_V7_t configuration_set_scheduling_lookahead_V7;
    pd_configuration_set_max_validators_per_core_V7_t configuration_set_max_validators_per_core_V7;
    pd_configuration_set_max_validators_V7_t configuration_set_max_validators_V7;
    pd_configuration_set_dispute_period_V7_t configuration_set_dispute_period_V7;
    pd_configuration_set_dispute_post_conclusion_acceptance_period_V7_t configuration_set_dispute_post_conclusion_acceptance_period_V7;
    pd_configuration_set_dispute_max_spam_slots_V7_t configuration_set_dispute_max_spam_slots_V7;
    pd_configuration_set_dispute_conclusion_by_time_out_period_V7_t configuration_set_dispute_conclusion_by_time_out_period_V7;
    pd_configuration_set_no_show_slots_V7_t configuration_set_no_show_slots_V7;
    pd_configuration_set_n_delay_tranches_V7_t configuration_set_n_delay_tranches_V7;
    pd_configuration_set_zeroth_delay_tranche_width_V7_t configuration_set_zeroth_delay_tranche_width_V7;
    pd_configuration_set_needed_approvals_V7_t configuration_set_needed_approvals_V7;
    pd_configuration_set_relay_vrf_modulo_samples_V7_t configuration_set_relay_vrf_modulo_samples_V7;
    pd_configuration_set_max_upward_queue_count_V7_t configuration_set_max_upward_queue_count_V7;
    pd_configuration_set_max_upward_queue_size_V7_t configuration_set_max_upward_queue_size_V7;
    pd_configuration_set_max_downward_message_size_V7_t configuration_set_max_downward_message_size_V7;
    pd_configuration_set_ump_service_total_weight_V7_t configuration_set_ump_service_total_weight_V7;
    pd_configuration_set_max_upward_message_size_V7_t configuration_set_max_upward_message_size_V7;
    pd_configuration_set_max_upward_message_num_per_candidate_V7_t configuration_set_max_upward_message_num_per_candidate_V7;
    pd_configuration_set_hrmp_open_request_ttl_V7_t configuration_set_hrmp_open_request_ttl_V7;
    pd_configuration_set_hrmp_sender_deposit_V7_t configuration_set_hrmp_sender_deposit_V7;
    pd_configuration_set_hrmp_recipient_deposit_V7_t configuration_set_hrmp_recipient_deposit_V7;
    pd_configuration_set_hrmp_channel_max_capacity_V7_t configuration_set_hrmp_channel_max_capacity_V7;
    pd_configuration_set_hrmp_channel_max_total_size_V7_t configuration_set_hrmp_channel_max_total_size_V7;
    pd_configuration_set_hrmp_max_parachain_inbound_channels_V7_t configuration_set_hrmp_max_parachain_inbound_channels_V7;
    pd_configuration_set_hrmp_max_parathread_inbound_channels_V7_t configuration_set_hrmp_max_parathread_inbound_channels_V7;
    pd_configuration_set_hrmp_channel_max_message_size_V7_t configuration_set_hrmp_channel_max_message_size_V7;
    pd_configuration_set_hrmp_max_parachain_outbound_channels_V7_t configuration_set_hrmp_max_parachain_outbound_channels_V7;
    pd_configuration_set_hrmp_max_parathread_outbound_channels_V7_t configuration_set_hrmp_max_parathread_outbound_channels_V7;
    pd_configuration_set_hrmp_max_message_num_per_candidate_V7_t configuration_set_hrmp_max_message_num_per_candidate_V7;
    pd_configuration_set_ump_max_individual_weight_V7_t configuration_set_ump_max_individual_weight_V7;
    pd_parainherent_enter_V7_t parainherent_enter_V7;
    pd_paras_force_set_current_code_V7_t paras_force_set_current_code_V7;
    pd_paras_force_set_current_head_V7_t paras_force_set_current_head_V7;
    pd_paras_force_schedule_code_upgrade_V7_t paras_force_schedule_code_upgrade_V7;
    pd_paras_force_note_new_head_V7_t paras_force_note_new_head_V7;
    pd_paras_force_queue_action_V7_t paras_force_queue_action_V7;
    pd_initializer_force_approve_V7_t initializer_force_approve_V7;
    pd_ump_service_overweight_V7_t ump_service_overweight_V7;
    pd_hrmp_hrmp_init_open_channel_V7_t hrmp_hrmp_init_open_channel_V7;
    pd_hrmp_hrmp_accept_open_channel_V7_t hrmp_hrmp_accept_open_channel_V7;
    pd_hrmp_hrmp_close_channel_V7_t hrmp_hrmp_close_channel_V7;
    pd_hrmp_force_clean_hrmp_V7_t hrmp_force_clean_hrmp_V7;
    pd_hrmp_force_process_hrmp_open_V7_t hrmp_force_process_hrmp_open_V7;
    pd_hrmp_force_process_hrmp_close_V7_t hrmp_force_process_hrmp_close_V7;
    pd_hrmp_hrmp_cancel_open_request_V7_t hrmp_hrmp_cancel_open_request_V7;
    pd_registrar_register_V7_t registrar_register_V7;
    pd_registrar_force_register_V7_t registrar_force_register_V7;
    pd_registrar_deregister_V7_t registrar_deregister_V7;
    pd_registrar_swap_V7_t registrar_swap_V7;
    pd_registrar_force_remove_lock_V7_t registrar_force_remove_lock_V7;
    pd_registrar_reserve_V7_t registrar_reserve_V7;
    pd_slots_force_lease_V7_t slots_force_lease_V7;
    pd_slots_clear_all_leases_V7_t slots_clear_all_leases_V7;
    pd_slots_trigger_onboard_V7_t slots_trigger_onboard_V7;
    pd_auctions_new_auction_V7_t auctions_new_auction_V7;
    pd_auctions_bid_V7_t auctions_bid_V7;
    pd_auctions_cancel_auction_V7_t auctions_cancel_auction_V7;
    pd_crowdloan_create_V7_t crowdloan_create_V7;
    pd_crowdloan_contribute_V7_t crowdloan_contribute_V7;
    pd_crowdloan_withdraw_V7_t crowdloan_withdraw_V7;
    pd_crowdloan_refund_V7_t crowdloan_refund_V7;
    pd_crowdloan_dissolve_V7_t crowdloan_dissolve_V7;
    pd_crowdloan_edit_V7_t crowdloan_edit_V7;
    pd_crowdloan_add_memo_V7_t crowdloan_add_memo_V7;
    pd_crowdloan_poke_V7_t crowdloan_poke_V7;
    pd_xcmpallet_send_V7_t xcmpallet_send_V7;
    pd_xcmpallet_teleport_assets_V7_t xcmpallet_teleport_assets_V7;
    pd_xcmpallet_reserve_transfer_assets_V7_t xcmpallet_reserve_transfer_assets_V7;
    pd_xcmpallet_execute_V7_t xcmpallet_execute_V7;
    pd_xcmpallet_force_xcm_version_V7_t xcmpallet_force_xcm_version_V7;
    pd_xcmpallet_force_default_xcm_version_V7_t xcmpallet_force_default_xcm_version_V7;
    pd_xcmpallet_force_subscribe_version_notify_V7_t xcmpallet_force_subscribe_version_notify_V7;
    pd_xcmpallet_force_unsubscribe_version_notify_V7_t xcmpallet_force_unsubscribe_version_notify_V7;
#endif
} pd_MethodBasic_V7_t;

#define PD_CALL_BALANCES_TRANSFER_V7 0
typedef struct {
    pd_LookupasStaticLookupSource_V7_t dest;
    pd_Compactu128_V7_t value;
} pd_balances_transfer_V7_t;

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_SYSTEM_FILL_BLOCK_V7 0
typedef struct {
    pd_Perbill_V7_t ratio;
} pd_system_fill_block_V7_t;

#define PD_CALL_SYSTEM_REMARK_V7 1
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_V7_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V7 2
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V7_t;

#define PD_CALL_SYSTEM_SET_CODE_V7 3
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_V7_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V7 4
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_without_checks_V7_t;

#define PD_CALL_SYSTEM_SET_CHANGES_TRIE_CONFIG_V7 5
typedef struct {
    pd_OptionChangesTrieConfiguration_V7_t changes_trie_config;
} pd_system_set_changes_trie_config_V7_t;

#define PD_CALL_SYSTEM_SET_STORAGE_V7 6
typedef struct {
    pd_VecKeyValue_V7_t items;
} pd_system_set_storage_V7_t;

#define PD_CALL_SYSTEM_KILL_STORAGE_V7 7
typedef struct {
    pd_VecKey_V7_t keys;
} pd_system_kill_storage_V7_t;

#define PD_CALL_SYSTEM_KILL_PREFIX_V7 8
typedef struct {
    pd_Key_V7_t prefix;
    pd_u32_t subkeys;
} pd_system_kill_prefix_V7_t;

#define PD_CALL_BALANCES_SET_BALANCE_V7 1
typedef struct {
    pd_LookupasStaticLookupSource_V7_t who;
    pd_Compactu128_V7_t new_free;
    pd_Compactu128_V7_t new_reserved;
} pd_balances_set_balance_V7_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V7 2
typedef struct {
    pd_LookupasStaticLookupSource_V7_t source;
    pd_LookupasStaticLookupSource_V7_t dest;
    pd_Compactu128_V7_t value;
} pd_balances_force_transfer_V7_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V7 3
typedef struct {
    pd_LookupasStaticLookupSource_V7_t dest;
    pd_Compactu128_V7_t value;
} pd_balances_transfer_keep_alive_V7_t;

#define PD_CALL_PROXY_PROXY_V7 0
typedef struct {
    pd_AccountId_V7_t real;
    pd_OptionProxyType_V7_t force_proxy_type;
    pd_BoxTasConfigCall_V7_t call;
} pd_proxy_proxy_V7_t;

#define PD_CALL_MULTISIG_AS_MULTI_THRESHOLD_1_V7 0
typedef struct {
    pd_VecAccountId_V7_t other_signatories;
    pd_BoxTasConfigCall_V7_t call;
} pd_multisig_as_multi_threshold_1_V7_t;

#define PD_CALL_MULTISIG_AS_MULTI_V7 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V7_t other_signatories;
    pd_OptionTimepointBlockNumber_V7_t maybe_timepoint;
    pd_OpaqueCall_V7_t call;
    pd_bool_t store_call;
    pd_Weight_V7_t max_weight;
} pd_multisig_as_multi_V7_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI_V7 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V7_t other_signatories;
    pd_OptionTimepointBlockNumber_V7_t maybe_timepoint;
    pd_u8_array_32_V7_t call_hash;
    pd_Weight_V7_t max_weight;
} pd_multisig_approve_as_multi_V7_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V7 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V7_t other_signatories;
    pd_TimepointBlockNumber_V7_t timepoint;
    pd_u8_array_32_V7_t call_hash;
} pd_multisig_cancel_as_multi_V7_t;

#endif

typedef union {
    pd_balances_transfer_V7_t balances_transfer_V7;
#ifdef SUBSTRATE_PARSER_FULL
    pd_system_fill_block_V7_t system_fill_block_V7;
    pd_system_remark_V7_t system_remark_V7;
    pd_system_set_heap_pages_V7_t system_set_heap_pages_V7;
    pd_system_set_code_V7_t system_set_code_V7;
    pd_system_set_code_without_checks_V7_t system_set_code_without_checks_V7;
    pd_system_set_changes_trie_config_V7_t system_set_changes_trie_config_V7;
    pd_system_set_storage_V7_t system_set_storage_V7;
    pd_system_kill_storage_V7_t system_kill_storage_V7;
    pd_system_kill_prefix_V7_t system_kill_prefix_V7;
    pd_balances_set_balance_V7_t balances_set_balance_V7;
    pd_balances_force_transfer_V7_t balances_force_transfer_V7;
    pd_balances_transfer_keep_alive_V7_t balances_transfer_keep_alive_V7;
    pd_proxy_proxy_V7_t proxy_proxy_V7;
    pd_multisig_as_multi_threshold_1_V7_t multisig_as_multi_threshold_1_V7;
    pd_multisig_as_multi_V7_t multisig_as_multi_V7;
    pd_multisig_approve_as_multi_V7_t multisig_approve_as_multi_V7;
    pd_multisig_cancel_as_multi_V7_t multisig_cancel_as_multi_V7;
#endif
} pd_MethodNested_V7_t;

typedef union {
    pd_MethodBasic_V7_t basic;
    pd_MethodNested_V7_t nested;
} pd_Method_V7_t;

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop
