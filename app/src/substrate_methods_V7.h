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
    pd_CompactBalance_t Amount;
    pd_RewardDestination_V7_t payee;
} pd_staking_bond_V7_t;

#define PD_CALL_STAKING_UNBOND_V7 2
typedef struct {
    pd_CompactBalance_t Amount;
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
    pd_CompactBalance_t Amount;
} pd_staking_rebond_V7_t;

#define PD_CALL_UTILITY_BATCH_V7 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V7_t;

#ifdef SUBSTRATE_PARSER_FULL
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

#define PD_CALL_STAKING_BOND_EXTRA_V7 1
typedef struct {
    pd_CompactBalance_t max_additional;
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

#define PD_CALL_STAKING_FORCE_NO_ERAS_V7 12
typedef struct {
} pd_staking_force_no_eras_V7_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_V7 13
typedef struct {
} pd_staking_force_new_era_V7_t;

#define PD_CALL_STAKING_FORCE_UNSTAKE_V7 15
typedef struct {
    pd_AccountId_V7_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_force_unstake_V7_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_ALWAYS_V7 16
typedef struct {
} pd_staking_force_new_era_always_V7_t;

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

#define PD_CALL_STAKING_CHILL_OTHER_V7 24
typedef struct {
    pd_AccountId_V7_t controller;
} pd_staking_chill_other_V7_t;

#define PD_CALL_SESSION_SET_KEYS_V7 0
typedef struct {
    pd_Keys_V7_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V7_t;

#define PD_CALL_SESSION_PURGE_KEYS_V7 1
typedef struct {
} pd_session_purge_keys_V7_t;

#define PD_CALL_GRANDPA_NOTE_STALLED_V7 2
typedef struct {
    pd_BlockNumber_t delay;
    pd_BlockNumber_t best_finalized_block_number;
} pd_grandpa_note_stalled_V7_t;

#define PD_CALL_DEMOCRACY_SECOND_V7 1
typedef struct {
    pd_Compactu32_t proposal;
    pd_Compactu32_t seconds_upper_bound;
} pd_democracy_second_V7_t;

#define PD_CALL_DEMOCRACY_EMERGENCY_CANCEL_V7 3
typedef struct {
    pd_ReferendumIndex_V7_t ref_index;
} pd_democracy_emergency_cancel_V7_t;

#define PD_CALL_DEMOCRACY_CANCEL_REFERENDUM_V7 9
typedef struct {
    pd_Compactu32_t ref_index;
} pd_democracy_cancel_referendum_V7_t;

#define PD_CALL_DEMOCRACY_CANCEL_QUEUED_V7 10
typedef struct {
    pd_ReferendumIndex_V7_t which;
} pd_democracy_cancel_queued_V7_t;

#define PD_CALL_DEMOCRACY_UNDELEGATE_V7 12
typedef struct {
} pd_democracy_undelegate_V7_t;

#define PD_CALL_DEMOCRACY_CLEAR_PUBLIC_PROPOSALS_V7 13
typedef struct {
} pd_democracy_clear_public_proposals_V7_t;

#define PD_CALL_DEMOCRACY_NOTE_PREIMAGE_V7 14
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_preimage_V7_t;

#define PD_CALL_DEMOCRACY_NOTE_PREIMAGE_OPERATIONAL_V7 15
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_preimage_operational_V7_t;

#define PD_CALL_DEMOCRACY_NOTE_IMMINENT_PREIMAGE_V7 16
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_imminent_preimage_V7_t;

#define PD_CALL_DEMOCRACY_NOTE_IMMINENT_PREIMAGE_OPERATIONAL_V7 17
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_imminent_preimage_operational_V7_t;

#define PD_CALL_DEMOCRACY_REMOVE_VOTE_V7 20
typedef struct {
    pd_ReferendumIndex_V7_t index;
} pd_democracy_remove_vote_V7_t;

#define PD_CALL_DEMOCRACY_CANCEL_PROPOSAL_V7 24
typedef struct {
    pd_Compactu32_t prop_index;
} pd_democracy_cancel_proposal_V7_t;

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

#define PD_CALL_TECHNICALCOMMITTEE_DISAPPROVE_PROPOSAL_V7 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_technicalcommittee_disapprove_proposal_V7_t;

#define PD_CALL_PHRAGMENELECTION_REMOVE_VOTER_V7 1
typedef struct {
} pd_phragmenelection_remove_voter_V7_t;

#define PD_CALL_PHRAGMENELECTION_SUBMIT_CANDIDACY_V7 2
typedef struct {
    pd_Compactu32_t candidate_count;
} pd_phragmenelection_submit_candidacy_V7_t;

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
    pd_CompactBalance_t Amount;
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

#define PD_CALL_CLAIMS_CLAIM_ATTEST_V7 2
typedef struct {
    pd_AccountId_V7_t dest;
    pd_EcdsaSignature_V7_t ethereum_signature;
    pd_Bytes_t statement;
} pd_claims_claim_attest_V7_t;

#define PD_CALL_CLAIMS_ATTEST_V7 3
typedef struct {
    pd_Bytes_t statement;
} pd_claims_attest_V7_t;

#define PD_CALL_CLAIMS_MOVE_CLAIM_V7 4
typedef struct {
    pd_EthereumAddress_V7_t old;
    pd_EthereumAddress_V7_t new_;
    pd_OptionAccountId_V7_t maybe_preclaim;
} pd_claims_move_claim_V7_t;

#define PD_CALL_UTILITY_BATCH_ALL_V7 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V7_t;

#define PD_CALL_IDENTITY_ADD_REGISTRAR_V7 0
typedef struct {
    pd_AccountId_V7_t account;
} pd_identity_add_registrar_V7_t;

#define PD_CALL_IDENTITY_CLEAR_IDENTITY_V7 3
typedef struct {
} pd_identity_clear_identity_V7_t;

#define PD_CALL_IDENTITY_REQUEST_JUDGEMENT_V7 4
typedef struct {
    pd_Compactu32_t reg_index;
    pd_Compactu128_t max_fee;
} pd_identity_request_judgement_V7_t;

#define PD_CALL_IDENTITY_CANCEL_REQUEST_V7 5
typedef struct {
    pd_RegistrarIndex_V7_t reg_index;
} pd_identity_cancel_request_V7_t;

#define PD_CALL_IDENTITY_SET_FEE_V7 6
typedef struct {
    pd_Compactu32_t index;
    pd_Compactu128_t fee;
} pd_identity_set_fee_V7_t;

#define PD_CALL_IDENTITY_SET_ACCOUNT_ID_V7 7
typedef struct {
    pd_Compactu32_t index;
    pd_AccountId_V7_t new_;
} pd_identity_set_account_id_V7_t;

#define PD_CALL_IDENTITY_KILL_IDENTITY_V7 10
typedef struct {
    pd_LookupasStaticLookupSource_V7_t target;
} pd_identity_kill_identity_V7_t;

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
    pd_Bytes_t rules;
} pd_society_found_V7_t;

#define PD_CALL_SOCIETY_UNFOUND_V7 8
typedef struct {
} pd_society_unfound_V7_t;

#define PD_CALL_SOCIETY_JUDGE_SUSPENDED_MEMBER_V7 9
typedef struct {
    pd_AccountId_V7_t who;
    pd_bool_t forgive;
} pd_society_judge_suspended_member_V7_t;

#define PD_CALL_SOCIETY_SET_MAX_MEMBERS_V7 11
typedef struct {
    pd_u32_t max;
} pd_society_set_max_members_V7_t;

#define PD_CALL_RECOVERY_SET_RECOVERED_V7 1
typedef struct {
    pd_AccountId_V7_t lost;
    pd_AccountId_V7_t rescuer;
} pd_recovery_set_recovered_V7_t;

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

#define PD_CALL_VESTING_MERGE_SCHEDULES_V7 4
typedef struct {
    pd_u32_t schedule1_index;
    pd_u32_t schedule2_index;
} pd_vesting_merge_schedules_V7_t;

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

#define PD_CALL_PROXY_PROXY_ANNOUNCED_V7 9
typedef struct {
    pd_AccountId_V7_t delegate;
    pd_AccountId_V7_t real;
    pd_OptionProxyType_V7_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_announced_V7_t;

#define PD_CALL_BOUNTIES_PROPOSE_BOUNTY_V7 0
typedef struct {
    pd_CompactBalance_t Amount;
    pd_Bytes_t description;
} pd_bounties_propose_bounty_V7_t;

#define PD_CALL_BOUNTIES_APPROVE_BOUNTY_V7 1
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_approve_bounty_V7_t;

#define PD_CALL_BOUNTIES_PROPOSE_CURATOR_V7 2
typedef struct {
    pd_Compactu32_t bounty_id;
    pd_LookupasStaticLookupSource_V7_t curator;
    pd_CompactBalance_t fee;
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
    pd_Bytes_t remark;
} pd_bounties_extend_bounty_expiry_V7_t;

#define PD_CALL_TIPS_REPORT_AWESOME_V7 0
typedef struct {
    pd_Bytes_t reason;
    pd_AccountId_V7_t who;
} pd_tips_report_awesome_V7_t;

#define PD_CALL_TIPS_RETRACT_TIP_V7 1
typedef struct {
    pd_Hash_t hash;
} pd_tips_retract_tip_V7_t;

#define PD_CALL_TIPS_TIP_NEW_V7 2
typedef struct {
    pd_Bytes_t reason;
    pd_AccountId_V7_t who;
    pd_Compactu128_t tip_value;
} pd_tips_tip_new_V7_t;

#define PD_CALL_TIPS_TIP_V7 3
typedef struct {
    pd_Hash_t hash;
    pd_Compactu128_t tip_value;
} pd_tips_tip_V7_t;

#define PD_CALL_TIPS_CLOSE_TIP_V7 4
typedef struct {
    pd_Hash_t hash;
} pd_tips_close_tip_V7_t;

#define PD_CALL_TIPS_SLASH_TIP_V7 5
typedef struct {
    pd_Hash_t hash;
} pd_tips_slash_tip_V7_t;

#define PD_CALL_GILT_PLACE_BID_V7 0
typedef struct {
    pd_CompactBalance_t amount;
    pd_u32_t duration;
} pd_gilt_place_bid_V7_t;

#define PD_CALL_GILT_RETRACT_BID_V7 1
typedef struct {
    pd_CompactBalance_t amount;
    pd_u32_t duration;
} pd_gilt_retract_bid_V7_t;

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

#define PD_CALL_INITIALIZER_FORCE_APPROVE_V7 0
typedef struct {
    pd_BlockNumber_t up_to;
} pd_initializer_force_approve_V7_t;

#define PD_CALL_HRMP_FORCE_PROCESS_HRMP_OPEN_V7 4
typedef struct {
} pd_hrmp_force_process_hrmp_open_V7_t;

#define PD_CALL_HRMP_FORCE_PROCESS_HRMP_CLOSE_V7 5
typedef struct {
} pd_hrmp_force_process_hrmp_close_V7_t;

#define PD_CALL_REGISTRAR_RESERVE_V7 5
typedef struct {
} pd_registrar_reserve_V7_t;

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
    pd_CompactBalance_t amount;
} pd_auctions_bid_V7_t;

#define PD_CALL_AUCTIONS_CANCEL_AUCTION_V7 2
typedef struct {
} pd_auctions_cancel_auction_V7_t;

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
    pd_timestamp_set_V7_t timestamp_set_V7;
    pd_indices_claim_V7_t indices_claim_V7;
    pd_indices_transfer_V7_t indices_transfer_V7;
    pd_indices_free_V7_t indices_free_V7;
    pd_indices_force_transfer_V7_t indices_force_transfer_V7;
    pd_indices_freeze_V7_t indices_freeze_V7;
    pd_balances_transfer_all_V7_t balances_transfer_all_V7;
    pd_balances_force_unreserve_V7_t balances_force_unreserve_V7;
    pd_staking_bond_extra_V7_t staking_bond_extra_V7;
    pd_staking_withdraw_unbonded_V7_t staking_withdraw_unbonded_V7;
    pd_staking_set_payee_V7_t staking_set_payee_V7;
    pd_staking_set_controller_V7_t staking_set_controller_V7;
    pd_staking_set_validator_count_V7_t staking_set_validator_count_V7;
    pd_staking_increase_validator_count_V7_t staking_increase_validator_count_V7;
    pd_staking_force_no_eras_V7_t staking_force_no_eras_V7;
    pd_staking_force_new_era_V7_t staking_force_new_era_V7;
    pd_staking_force_unstake_V7_t staking_force_unstake_V7;
    pd_staking_force_new_era_always_V7_t staking_force_new_era_always_V7;
    pd_staking_payout_stakers_V7_t staking_payout_stakers_V7;
    pd_staking_set_history_depth_V7_t staking_set_history_depth_V7;
    pd_staking_reap_stash_V7_t staking_reap_stash_V7;
    pd_staking_kick_V7_t staking_kick_V7;
    pd_staking_chill_other_V7_t staking_chill_other_V7;
    pd_session_set_keys_V7_t session_set_keys_V7;
    pd_session_purge_keys_V7_t session_purge_keys_V7;
    pd_grandpa_note_stalled_V7_t grandpa_note_stalled_V7;
    pd_democracy_second_V7_t democracy_second_V7;
    pd_democracy_emergency_cancel_V7_t democracy_emergency_cancel_V7;
    pd_democracy_cancel_referendum_V7_t democracy_cancel_referendum_V7;
    pd_democracy_cancel_queued_V7_t democracy_cancel_queued_V7;
    pd_democracy_undelegate_V7_t democracy_undelegate_V7;
    pd_democracy_clear_public_proposals_V7_t democracy_clear_public_proposals_V7;
    pd_democracy_note_preimage_V7_t democracy_note_preimage_V7;
    pd_democracy_note_preimage_operational_V7_t democracy_note_preimage_operational_V7;
    pd_democracy_note_imminent_preimage_V7_t democracy_note_imminent_preimage_V7;
    pd_democracy_note_imminent_preimage_operational_V7_t democracy_note_imminent_preimage_operational_V7;
    pd_democracy_remove_vote_V7_t democracy_remove_vote_V7;
    pd_democracy_cancel_proposal_V7_t democracy_cancel_proposal_V7;
    pd_council_vote_V7_t council_vote_V7;
    pd_council_close_V7_t council_close_V7;
    pd_council_disapprove_proposal_V7_t council_disapprove_proposal_V7;
    pd_technicalcommittee_disapprove_proposal_V7_t technicalcommittee_disapprove_proposal_V7;
    pd_phragmenelection_remove_voter_V7_t phragmenelection_remove_voter_V7;
    pd_phragmenelection_submit_candidacy_V7_t phragmenelection_submit_candidacy_V7;
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
    pd_claims_claim_attest_V7_t claims_claim_attest_V7;
    pd_claims_attest_V7_t claims_attest_V7;
    pd_claims_move_claim_V7_t claims_move_claim_V7;
    pd_utility_batch_all_V7_t utility_batch_all_V7;
    pd_identity_add_registrar_V7_t identity_add_registrar_V7;
    pd_identity_clear_identity_V7_t identity_clear_identity_V7;
    pd_identity_request_judgement_V7_t identity_request_judgement_V7;
    pd_identity_cancel_request_V7_t identity_cancel_request_V7;
    pd_identity_set_fee_V7_t identity_set_fee_V7;
    pd_identity_set_account_id_V7_t identity_set_account_id_V7;
    pd_identity_kill_identity_V7_t identity_kill_identity_V7;
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
    pd_society_set_max_members_V7_t society_set_max_members_V7;
    pd_recovery_set_recovered_V7_t recovery_set_recovered_V7;
    pd_recovery_initiate_recovery_V7_t recovery_initiate_recovery_V7;
    pd_recovery_vouch_recovery_V7_t recovery_vouch_recovery_V7;
    pd_recovery_claim_recovery_V7_t recovery_claim_recovery_V7;
    pd_recovery_close_recovery_V7_t recovery_close_recovery_V7;
    pd_recovery_remove_recovery_V7_t recovery_remove_recovery_V7;
    pd_recovery_cancel_recovered_V7_t recovery_cancel_recovered_V7;
    pd_vesting_vest_V7_t vesting_vest_V7;
    pd_vesting_vest_other_V7_t vesting_vest_other_V7;
    pd_vesting_merge_schedules_V7_t vesting_merge_schedules_V7;
    pd_proxy_add_proxy_V7_t proxy_add_proxy_V7;
    pd_proxy_remove_proxy_V7_t proxy_remove_proxy_V7;
    pd_proxy_remove_proxies_V7_t proxy_remove_proxies_V7;
    pd_proxy_anonymous_V7_t proxy_anonymous_V7;
    pd_proxy_kill_anonymous_V7_t proxy_kill_anonymous_V7;
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
    pd_gilt_place_bid_V7_t gilt_place_bid_V7;
    pd_gilt_retract_bid_V7_t gilt_retract_bid_V7;
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
    pd_initializer_force_approve_V7_t initializer_force_approve_V7;
    pd_hrmp_force_process_hrmp_open_V7_t hrmp_force_process_hrmp_open_V7;
    pd_hrmp_force_process_hrmp_close_V7_t hrmp_force_process_hrmp_close_V7;
    pd_registrar_reserve_V7_t registrar_reserve_V7;
    pd_auctions_new_auction_V7_t auctions_new_auction_V7;
    pd_auctions_bid_V7_t auctions_bid_V7;
    pd_auctions_cancel_auction_V7_t auctions_cancel_auction_V7;
#endif
} pd_MethodBasic_V7_t;

#define PD_CALL_BALANCES_TRANSFER_V7 0
typedef struct {
    pd_LookupasStaticLookupSource_V7_t dest;
    pd_CompactBalance_t Amount;
} pd_balances_transfer_V7_t;

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_SYSTEM_FILL_BLOCK_V7 0
typedef struct {
    pd_Perbill_V7_t ratio;
} pd_system_fill_block_V7_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V7 2
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V7_t;

#define PD_CALL_BALANCES_SET_BALANCE_V7 1
typedef struct {
    pd_LookupasStaticLookupSource_V7_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_V7_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V7 2
typedef struct {
    pd_LookupasStaticLookupSource_V7_t source;
    pd_LookupasStaticLookupSource_V7_t dest;
    pd_CompactBalance_t Amount;
} pd_balances_force_transfer_V7_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V7 3
typedef struct {
    pd_LookupasStaticLookupSource_V7_t dest;
    pd_CompactBalance_t Amount;
} pd_balances_transfer_keep_alive_V7_t;

#define PD_CALL_PROXY_PROXY_V7 0
typedef struct {
    pd_AccountId_V7_t real;
    pd_OptionProxyType_V7_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_V7_t;

#define PD_CALL_MULTISIG_AS_MULTI_V7 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V7_t other_signatories;
    pd_OptionTimepoint_V7_t maybe_timepoint;
    pd_OpaqueCall_V7_t call;
    pd_bool_t store_call;
    pd_Weight_V7_t max_weight;
} pd_multisig_as_multi_V7_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI_V7 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V7_t other_signatories;
    pd_OptionTimepoint_V7_t maybe_timepoint;
    pd_H256_t call_hash;
    pd_Weight_V7_t max_weight;
} pd_multisig_approve_as_multi_V7_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V7 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V7_t other_signatories;
    pd_Timepoint_V7_t timepoint;
    pd_H256_t call_hash;
} pd_multisig_cancel_as_multi_V7_t;

#endif

typedef union {
    pd_balances_transfer_V7_t balances_transfer_V7;
#ifdef SUBSTRATE_PARSER_FULL
    pd_system_fill_block_V7_t system_fill_block_V7;
    pd_system_set_heap_pages_V7_t system_set_heap_pages_V7;
    pd_balances_set_balance_V7_t balances_set_balance_V7;
    pd_balances_force_transfer_V7_t balances_force_transfer_V7;
    pd_balances_transfer_keep_alive_V7_t balances_transfer_keep_alive_V7;
    pd_proxy_proxy_V7_t proxy_proxy_V7;
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
