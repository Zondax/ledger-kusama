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
#include "substrate_types_V4.h"
#include <stddef.h>
#include <stdint.h>

#define PD_CALL_SYSTEM_V4 0
#define PD_CALL_BABE_V4 1
#define PD_CALL_TIMESTAMP_V4 2
#define PD_CALL_INDICES_V4 3
#define PD_CALL_BALANCES_V4 4
#define PD_CALL_AUTHORSHIP_V4 5
#define PD_CALL_STAKING_V4 6
#define PD_CALL_OFFENCES_V4 7
#define PD_CALL_SESSION_V4 8
#define PD_CALL_GRANDPA_V4 10
#define PD_CALL_IMONLINE_V4 11
#define PD_CALL_AUTHORITYDISCOVERY_V4 12
#define PD_CALL_DEMOCRACY_V4 13
#define PD_CALL_COUNCIL_V4 14
#define PD_CALL_TECHNICALCOMMITTEE_V4 15
#define PD_CALL_ELECTIONSPHRAGMEN_V4 16
#define PD_CALL_TECHNICALMEMBERSHIP_V4 17
#define PD_CALL_TREASURY_V4 18
#define PD_CALL_CLAIMS_V4 19
#define PD_CALL_UTILITY_V4 24
#define PD_CALL_IDENTITY_V4 25
#define PD_CALL_SOCIETY_V4 26
#define PD_CALL_RECOVERY_V4 27
#define PD_CALL_VESTING_V4 28
#define PD_CALL_SCHEDULER_V4 29
#define PD_CALL_PROXY_V4 30
#define PD_CALL_MULTISIG_V4 31
#define PD_CALL_BOUNTIES_V4 35
#define PD_CALL_TIPS_V4 36

#define PD_CALL_SYSTEM_FILL_BLOCK_V4 0
typedef struct {
    pd_Perbill_V4_t _ratio;
} pd_system_fill_block_V4_t;

#define PD_CALL_SYSTEM_REMARK_V4 1
typedef struct {
    pd_Bytes_t _remark;
} pd_system_remark_V4_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V4 2
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V4_t;

#define PD_CALL_SYSTEM_SET_CODE_V4 3
typedef struct {
    pd_Bytes_t code;
} pd_system_set_code_V4_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V4 4
typedef struct {
    pd_Bytes_t code;
} pd_system_set_code_without_checks_V4_t;

#define PD_CALL_SYSTEM_SET_CHANGES_TRIE_CONFIG_V4 5
typedef struct {
    pd_OptionChangesTrieConfiguration_V4_t changes_trie_config;
} pd_system_set_changes_trie_config_V4_t;

#define PD_CALL_SYSTEM_SET_STORAGE_V4 6
typedef struct {
    pd_VecKeyValue_V4_t items;
} pd_system_set_storage_V4_t;

#define PD_CALL_SYSTEM_KILL_STORAGE_V4 7
typedef struct {
    pd_VecKey_V4_t keys;
} pd_system_kill_storage_V4_t;

#define PD_CALL_SYSTEM_KILL_PREFIX_V4 8
typedef struct {
    pd_Key_V4_t prefix;
    pd_u32_t _subkeys;
} pd_system_kill_prefix_V4_t;

#define PD_CALL_BABE_REPORT_EQUIVOCATION_V4 0
typedef struct {
    pd_EquivocationProof_V4_t equivocation_proof;
    pd_KeyOwnerProof_V4_t key_owner_proof;
} pd_babe_report_equivocation_V4_t;

#define PD_CALL_BABE_REPORT_EQUIVOCATION_UNSIGNED_V4 1
typedef struct {
    pd_EquivocationProof_V4_t equivocation_proof;
    pd_KeyOwnerProof_V4_t key_owner_proof;
} pd_babe_report_equivocation_unsigned_V4_t;

#define PD_CALL_TIMESTAMP_SET_V4 0
typedef struct {
    pd_CompactMoment_V4_t now;
} pd_timestamp_set_V4_t;

#define PD_CALL_INDICES_CLAIM_V4 0
typedef struct {
    pd_AccountIndex_V4_t index;
} pd_indices_claim_V4_t;

#define PD_CALL_INDICES_TRANSFER_V4 1
typedef struct {
    pd_AccountId_V4_t new_;
    pd_AccountIndex_V4_t index;
} pd_indices_transfer_V4_t;

#define PD_CALL_INDICES_FREE_V4 2
typedef struct {
    pd_AccountIndex_V4_t index;
} pd_indices_free_V4_t;

#define PD_CALL_INDICES_FORCE_TRANSFER_V4 3
typedef struct {
    pd_AccountId_V4_t new_;
    pd_AccountIndex_V4_t index;
    pd_bool_t freeze;
} pd_indices_force_transfer_V4_t;

#define PD_CALL_INDICES_FREEZE_V4 4
typedef struct {
    pd_AccountIndex_V4_t index;
} pd_indices_freeze_V4_t;

#define PD_CALL_BALANCES_TRANSFER_V4 0
typedef struct {
    pd_LookupSource_t dest;
    pd_CompactBalance_t value;
} pd_balances_transfer_V4_t;

#define PD_CALL_BALANCES_SET_BALANCE_V4 1
typedef struct {
    pd_LookupSource_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_V4_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V4 2
typedef struct {
    pd_LookupSource_t source;
    pd_LookupSource_t dest;
    pd_CompactBalance_t value;
} pd_balances_force_transfer_V4_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V4 3
typedef struct {
    pd_LookupSource_t dest;
    pd_CompactBalance_t value;
} pd_balances_transfer_keep_alive_V4_t;

#define PD_CALL_AUTHORSHIP_SET_UNCLES_V4 0
typedef struct {
    pd_VecHeader_t new_uncles;
} pd_authorship_set_uncles_V4_t;

#define PD_CALL_STAKING_BOND_V4 0
typedef struct {
    pd_LookupSource_t controller;
    pd_CompactBalanceOf_t value;
    pd_RewardDestination_V4_t payee;
} pd_staking_bond_V4_t;

#define PD_CALL_STAKING_BOND_EXTRA_V4 1
typedef struct {
    pd_CompactBalanceOf_t max_additional;
} pd_staking_bond_extra_V4_t;

#define PD_CALL_STAKING_UNBOND_V4 2
typedef struct {
    pd_CompactBalanceOf_t value;
} pd_staking_unbond_V4_t;

#define PD_CALL_STAKING_WITHDRAW_UNBONDED_V4 3
typedef struct {
    pd_u32_t num_slashing_spans;
} pd_staking_withdraw_unbonded_V4_t;

#define PD_CALL_STAKING_VALIDATE_V4 4
typedef struct {
    pd_ValidatorPrefs_V4_t prefs;
} pd_staking_validate_V4_t;

#define PD_CALL_STAKING_NOMINATE_V4 5
typedef struct {
    pd_VecLookupSource_t targets;
} pd_staking_nominate_V4_t;

#define PD_CALL_STAKING_CHILL_V4 6
typedef struct {
} pd_staking_chill_V4_t;

#define PD_CALL_STAKING_SET_PAYEE_V4 7
typedef struct {
    pd_RewardDestination_V4_t payee;
} pd_staking_set_payee_V4_t;

#define PD_CALL_STAKING_SET_CONTROLLER_V4 8
typedef struct {
    pd_LookupSource_t controller;
} pd_staking_set_controller_V4_t;

#define PD_CALL_STAKING_SET_VALIDATOR_COUNT_V4 9
typedef struct {
    pd_Compactu32_t new_;
} pd_staking_set_validator_count_V4_t;

#define PD_CALL_STAKING_INCREASE_VALIDATOR_COUNT_V4 10
typedef struct {
    pd_Compactu32_t additional;
} pd_staking_increase_validator_count_V4_t;

#define PD_CALL_STAKING_SCALE_VALIDATOR_COUNT_V4 11
typedef struct {
    pd_Percent_V4_t factor;
} pd_staking_scale_validator_count_V4_t;

#define PD_CALL_STAKING_FORCE_NO_ERAS_V4 12
typedef struct {
} pd_staking_force_no_eras_V4_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_V4 13
typedef struct {
} pd_staking_force_new_era_V4_t;

#define PD_CALL_STAKING_SET_INVULNERABLES_V4 14
typedef struct {
    pd_VecAccountId_V4_t invulnerables;
} pd_staking_set_invulnerables_V4_t;

#define PD_CALL_STAKING_FORCE_UNSTAKE_V4 15
typedef struct {
    pd_AccountId_V4_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_force_unstake_V4_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_ALWAYS_V4 16
typedef struct {
} pd_staking_force_new_era_always_V4_t;

#define PD_CALL_STAKING_CANCEL_DEFERRED_SLASH_V4 17
typedef struct {
    pd_EraIndex_V4_t era;
    pd_Vecu32_t slash_indices;
} pd_staking_cancel_deferred_slash_V4_t;

#define PD_CALL_STAKING_PAYOUT_STAKERS_V4 18
typedef struct {
    pd_AccountId_V4_t validator_stash;
    pd_EraIndex_V4_t era;
} pd_staking_payout_stakers_V4_t;

#define PD_CALL_STAKING_REBOND_V4 19
typedef struct {
    pd_CompactBalanceOf_t value;
} pd_staking_rebond_V4_t;

#define PD_CALL_STAKING_SET_HISTORY_DEPTH_V4 20
typedef struct {
    pd_CompactEraIndex_V4_t new_history_depth;
    pd_Compactu32_t _era_items_deleted;
} pd_staking_set_history_depth_V4_t;

#define PD_CALL_STAKING_REAP_STASH_V4 21
typedef struct {
    pd_AccountId_V4_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_reap_stash_V4_t;

#define PD_CALL_STAKING_SUBMIT_ELECTION_SOLUTION_V4 22
typedef struct {
    pd_VecValidatorIndex_V4_t winners;
    pd_CompactAssignments_V4_t compact;
    pd_ElectionScore_V4_t score;
    pd_EraIndex_V4_t era;
    pd_ElectionSize_V4_t size;
} pd_staking_submit_election_solution_V4_t;

#define PD_CALL_STAKING_SUBMIT_ELECTION_SOLUTION_UNSIGNED_V4 23
typedef struct {
    pd_VecValidatorIndex_V4_t winners;
    pd_CompactAssignments_V4_t compact;
    pd_ElectionScore_V4_t score;
    pd_EraIndex_V4_t era;
    pd_ElectionSize_V4_t size;
} pd_staking_submit_election_solution_unsigned_V4_t;

#define PD_CALL_STAKING_KICK_V4 24
typedef struct {
    pd_VecLookupSource_t who;
} pd_staking_kick_V4_t;

#define PD_CALL_SESSION_SET_KEYS_V4 0
typedef struct {
    pd_Keys_V4_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V4_t;

#define PD_CALL_SESSION_PURGE_KEYS_V4 1
typedef struct {
} pd_session_purge_keys_V4_t;

#define PD_CALL_GRANDPA_REPORT_EQUIVOCATION_V4 0
typedef struct {
    pd_EquivocationProof_V4_t equivocation_proof;
    pd_KeyOwnerProof_V4_t key_owner_proof;
} pd_grandpa_report_equivocation_V4_t;

#define PD_CALL_GRANDPA_REPORT_EQUIVOCATION_UNSIGNED_V4 1
typedef struct {
    pd_EquivocationProof_V4_t equivocation_proof;
    pd_KeyOwnerProof_V4_t key_owner_proof;
} pd_grandpa_report_equivocation_unsigned_V4_t;

#define PD_CALL_GRANDPA_NOTE_STALLED_V4 2
typedef struct {
    pd_BlockNumber_t delay;
    pd_BlockNumber_t best_finalized_block_number;
} pd_grandpa_note_stalled_V4_t;

#define PD_CALL_IMONLINE_HEARTBEAT_V4 0
typedef struct {
    pd_Heartbeat_t heartbeat;
    pd_Signature_V4_t _signature;
} pd_imonline_heartbeat_V4_t;

#define PD_CALL_DEMOCRACY_PROPOSE_V4 0
typedef struct {
    pd_Hash_t proposal_hash;
    pd_CompactBalanceOf_t value;
} pd_democracy_propose_V4_t;

#define PD_CALL_DEMOCRACY_SECOND_V4 1
typedef struct {
    pd_CompactPropIndex_V4_t proposal;
    pd_Compactu32_t seconds_upper_bound;
} pd_democracy_second_V4_t;

#define PD_CALL_DEMOCRACY_VOTE_V4 2
typedef struct {
    pd_CompactReferendumIndex_V4_t ref_index;
    pd_AccountVote_V4_t vote;
} pd_democracy_vote_V4_t;

#define PD_CALL_DEMOCRACY_EMERGENCY_CANCEL_V4 3
typedef struct {
    pd_ReferendumIndex_V4_t ref_index;
} pd_democracy_emergency_cancel_V4_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_V4 4
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_V4_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_MAJORITY_V4 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_majority_V4_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_DEFAULT_V4 6
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_default_V4_t;

#define PD_CALL_DEMOCRACY_FAST_TRACK_V4 7
typedef struct {
    pd_Hash_t proposal_hash;
    pd_BlockNumber_t voting_period;
    pd_BlockNumber_t delay;
} pd_democracy_fast_track_V4_t;

#define PD_CALL_DEMOCRACY_VETO_EXTERNAL_V4 8
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_veto_external_V4_t;

#define PD_CALL_DEMOCRACY_CANCEL_REFERENDUM_V4 9
typedef struct {
    pd_CompactReferendumIndex_V4_t ref_index;
} pd_democracy_cancel_referendum_V4_t;

#define PD_CALL_DEMOCRACY_CANCEL_QUEUED_V4 10
typedef struct {
    pd_ReferendumIndex_V4_t which;
} pd_democracy_cancel_queued_V4_t;

#define PD_CALL_DEMOCRACY_DELEGATE_V4 11
typedef struct {
    pd_AccountId_V4_t to;
    pd_Conviction_V4_t conviction;
    pd_BalanceOf_t balance;
} pd_democracy_delegate_V4_t;

#define PD_CALL_DEMOCRACY_UNDELEGATE_V4 12
typedef struct {
} pd_democracy_undelegate_V4_t;

#define PD_CALL_DEMOCRACY_CLEAR_PUBLIC_PROPOSALS_V4 13
typedef struct {
} pd_democracy_clear_public_proposals_V4_t;

#define PD_CALL_DEMOCRACY_NOTE_PREIMAGE_V4 14
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_preimage_V4_t;

#define PD_CALL_DEMOCRACY_NOTE_PREIMAGE_OPERATIONAL_V4 15
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_preimage_operational_V4_t;

#define PD_CALL_DEMOCRACY_NOTE_IMMINENT_PREIMAGE_V4 16
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_imminent_preimage_V4_t;

#define PD_CALL_DEMOCRACY_NOTE_IMMINENT_PREIMAGE_OPERATIONAL_V4 17
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_imminent_preimage_operational_V4_t;

#define PD_CALL_DEMOCRACY_REAP_PREIMAGE_V4 18
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t proposal_len_upper_bound;
} pd_democracy_reap_preimage_V4_t;

#define PD_CALL_DEMOCRACY_UNLOCK_V4 19
typedef struct {
    pd_AccountId_V4_t target;
} pd_democracy_unlock_V4_t;

#define PD_CALL_DEMOCRACY_REMOVE_VOTE_V4 20
typedef struct {
    pd_ReferendumIndex_V4_t index;
} pd_democracy_remove_vote_V4_t;

#define PD_CALL_DEMOCRACY_REMOVE_OTHER_VOTE_V4 21
typedef struct {
    pd_AccountId_V4_t target;
    pd_ReferendumIndex_V4_t index;
} pd_democracy_remove_other_vote_V4_t;

#define PD_CALL_DEMOCRACY_ENACT_PROPOSAL_V4 22
typedef struct {
    pd_Hash_t proposal_hash;
    pd_ReferendumIndex_V4_t index;
} pd_democracy_enact_proposal_V4_t;

#define PD_CALL_DEMOCRACY_BLACKLIST_V4 23
typedef struct {
    pd_Hash_t proposal_hash;
    pd_OptionReferendumIndex_V4_t maybe_ref_index;
} pd_democracy_blacklist_V4_t;

#define PD_CALL_DEMOCRACY_CANCEL_PROPOSAL_V4 24
typedef struct {
    pd_CompactPropIndex_V4_t prop_index;
} pd_democracy_cancel_proposal_V4_t;

#define PD_CALL_COUNCIL_SET_MEMBERS_V4 0
typedef struct {
    pd_VecAccountId_V4_t new_members;
    pd_OptionAccountId_V4_t prime;
    pd_MemberCount_V4_t old_count;
} pd_council_set_members_V4_t;

#define PD_CALL_COUNCIL_EXECUTE_V4 1
typedef struct {
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_council_execute_V4_t;

#define PD_CALL_COUNCIL_PROPOSE_V4 2
typedef struct {
    pd_CompactMemberCount_V4_t threshold;
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_council_propose_V4_t;

#define PD_CALL_COUNCIL_VOTE_V4 3
typedef struct {
    pd_Hash_t proposal;
    pd_CompactProposalIndex_V4_t index;
    pd_bool_t approve;
} pd_council_vote_V4_t;

#define PD_CALL_COUNCIL_CLOSE_V4 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_CompactProposalIndex_V4_t index;
    pd_CompactWeight_V4_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_council_close_V4_t;

#define PD_CALL_COUNCIL_DISAPPROVE_PROPOSAL_V4 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_council_disapprove_proposal_V4_t;

#define PD_CALL_TECHNICALCOMMITTEE_SET_MEMBERS_V4 0
typedef struct {
    pd_VecAccountId_V4_t new_members;
    pd_OptionAccountId_V4_t prime;
    pd_MemberCount_V4_t old_count;
} pd_technicalcommittee_set_members_V4_t;

#define PD_CALL_TECHNICALCOMMITTEE_EXECUTE_V4 1
typedef struct {
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_execute_V4_t;

#define PD_CALL_TECHNICALCOMMITTEE_PROPOSE_V4 2
typedef struct {
    pd_CompactMemberCount_V4_t threshold;
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_propose_V4_t;

#define PD_CALL_TECHNICALCOMMITTEE_VOTE_V4 3
typedef struct {
    pd_Hash_t proposal;
    pd_CompactProposalIndex_V4_t index;
    pd_bool_t approve;
} pd_technicalcommittee_vote_V4_t;

#define PD_CALL_TECHNICALCOMMITTEE_CLOSE_V4 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_CompactProposalIndex_V4_t index;
    pd_CompactWeight_V4_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_close_V4_t;

#define PD_CALL_TECHNICALCOMMITTEE_DISAPPROVE_PROPOSAL_V4 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_technicalcommittee_disapprove_proposal_V4_t;

#define PD_CALL_ELECTIONSPHRAGMEN_VOTE_V4 0
typedef struct {
    pd_VecAccountId_V4_t votes;
    pd_CompactBalanceOf_t value;
} pd_electionsphragmen_vote_V4_t;

#define PD_CALL_ELECTIONSPHRAGMEN_REMOVE_VOTER_V4 1
typedef struct {
} pd_electionsphragmen_remove_voter_V4_t;

#define PD_CALL_ELECTIONSPHRAGMEN_SUBMIT_CANDIDACY_V4 2
typedef struct {
    pd_Compactu32_t candidate_count;
} pd_electionsphragmen_submit_candidacy_V4_t;

#define PD_CALL_ELECTIONSPHRAGMEN_RENOUNCE_CANDIDACY_V4 3
typedef struct {
    pd_Renouncing_V4_t renouncing;
} pd_electionsphragmen_renounce_candidacy_V4_t;

#define PD_CALL_ELECTIONSPHRAGMEN_REMOVE_MEMBER_V4 4
typedef struct {
    pd_LookupSource_t who;
    pd_bool_t has_replacement;
} pd_electionsphragmen_remove_member_V4_t;

#define PD_CALL_ELECTIONSPHRAGMEN_CLEAN_DEFUNCT_VOTERS_V4 5
typedef struct {
    pd_u32_t _num_voters;
    pd_u32_t _num_defunct;
} pd_electionsphragmen_clean_defunct_voters_V4_t;

#define PD_CALL_TECHNICALMEMBERSHIP_ADD_MEMBER_V4 0
typedef struct {
    pd_AccountId_V4_t who;
} pd_technicalmembership_add_member_V4_t;

#define PD_CALL_TECHNICALMEMBERSHIP_REMOVE_MEMBER_V4 1
typedef struct {
    pd_AccountId_V4_t who;
} pd_technicalmembership_remove_member_V4_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SWAP_MEMBER_V4 2
typedef struct {
    pd_AccountId_V4_t remove;
    pd_AccountId_V4_t add;
} pd_technicalmembership_swap_member_V4_t;

#define PD_CALL_TECHNICALMEMBERSHIP_RESET_MEMBERS_V4 3
typedef struct {
    pd_VecAccountId_V4_t members;
} pd_technicalmembership_reset_members_V4_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CHANGE_KEY_V4 4
typedef struct {
    pd_AccountId_V4_t new_;
} pd_technicalmembership_change_key_V4_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SET_PRIME_V4 5
typedef struct {
    pd_AccountId_V4_t who;
} pd_technicalmembership_set_prime_V4_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CLEAR_PRIME_V4 6
typedef struct {
} pd_technicalmembership_clear_prime_V4_t;

#define PD_CALL_TREASURY_PROPOSE_SPEND_V4 0
typedef struct {
    pd_CompactBalanceOf_t value;
    pd_LookupSource_t beneficiary;
} pd_treasury_propose_spend_V4_t;

#define PD_CALL_TREASURY_REJECT_PROPOSAL_V4 1
typedef struct {
    pd_CompactProposalIndex_V4_t proposal_id;
} pd_treasury_reject_proposal_V4_t;

#define PD_CALL_TREASURY_APPROVE_PROPOSAL_V4 2
typedef struct {
    pd_CompactProposalIndex_V4_t proposal_id;
} pd_treasury_approve_proposal_V4_t;

#define PD_CALL_CLAIMS_CLAIM_V4 0
typedef struct {
    pd_AccountId_V4_t dest;
    pd_EcdsaSignature_V4_t ethereum_signature;
} pd_claims_claim_V4_t;

#define PD_CALL_CLAIMS_MINT_CLAIM_V4 1
typedef struct {
    pd_EthereumAddress_V4_t who;
    pd_BalanceOf_t value;
    pd_OptionTupleBalanceOfBalanceOfBlockNumber_V4_t vesting_schedule;
    pd_OptionStatementKind_V4_t statement;
} pd_claims_mint_claim_V4_t;

#define PD_CALL_CLAIMS_CLAIM_ATTEST_V4 2
typedef struct {
    pd_AccountId_V4_t dest;
    pd_EcdsaSignature_V4_t ethereum_signature;
    pd_Bytes_t statement;
} pd_claims_claim_attest_V4_t;

#define PD_CALL_CLAIMS_ATTEST_V4 3
typedef struct {
    pd_Bytes_t statement;
} pd_claims_attest_V4_t;

#define PD_CALL_CLAIMS_MOVE_CLAIM_V4 4
typedef struct {
    pd_EthereumAddress_V4_t old;
    pd_EthereumAddress_V4_t new_;
    pd_OptionAccountId_V4_t maybe_preclaim;
} pd_claims_move_claim_V4_t;

#define PD_CALL_UTILITY_BATCH_V4 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V4_t;

#define PD_CALL_UTILITY_AS_DERIVATIVE_V4 1
typedef struct {
    pd_u16_t index;
    pd_Call_t call;
} pd_utility_as_derivative_V4_t;

#define PD_CALL_UTILITY_BATCH_ALL_V4 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V4_t;

#define PD_CALL_IDENTITY_ADD_REGISTRAR_V4 0
typedef struct {
    pd_AccountId_V4_t account;
} pd_identity_add_registrar_V4_t;

#define PD_CALL_IDENTITY_SET_IDENTITY_V4 1
typedef struct {
    pd_IdentityInfo_V4_t info;
} pd_identity_set_identity_V4_t;

#define PD_CALL_IDENTITY_SET_SUBS_V4 2
typedef struct {
    pd_VecTupleAccountIdData_V4_t subs;
} pd_identity_set_subs_V4_t;

#define PD_CALL_IDENTITY_CLEAR_IDENTITY_V4 3
typedef struct {
} pd_identity_clear_identity_V4_t;

#define PD_CALL_IDENTITY_REQUEST_JUDGEMENT_V4 4
typedef struct {
    pd_CompactRegistrarIndex_V4_t reg_index;
    pd_CompactBalanceOf_t max_fee;
} pd_identity_request_judgement_V4_t;

#define PD_CALL_IDENTITY_CANCEL_REQUEST_V4 5
typedef struct {
    pd_RegistrarIndex_V4_t reg_index;
} pd_identity_cancel_request_V4_t;

#define PD_CALL_IDENTITY_SET_FEE_V4 6
typedef struct {
    pd_CompactRegistrarIndex_V4_t index;
    pd_CompactBalanceOf_t fee;
} pd_identity_set_fee_V4_t;

#define PD_CALL_IDENTITY_SET_ACCOUNT_ID_V4 7
typedef struct {
    pd_CompactRegistrarIndex_V4_t index;
    pd_AccountId_V4_t new_;
} pd_identity_set_account_id_V4_t;

#define PD_CALL_IDENTITY_SET_FIELDS_V4 8
typedef struct {
    pd_CompactRegistrarIndex_V4_t index;
    pd_IdentityFields_V4_t fields;
} pd_identity_set_fields_V4_t;

#define PD_CALL_IDENTITY_PROVIDE_JUDGEMENT_V4 9
typedef struct {
    pd_CompactRegistrarIndex_V4_t reg_index;
    pd_LookupSource_t target;
    pd_Judgement_V4_t judgement;
} pd_identity_provide_judgement_V4_t;

#define PD_CALL_IDENTITY_KILL_IDENTITY_V4 10
typedef struct {
    pd_LookupSource_t target;
} pd_identity_kill_identity_V4_t;

#define PD_CALL_IDENTITY_ADD_SUB_V4 11
typedef struct {
    pd_LookupSource_t sub;
    pd_Data_t data;
} pd_identity_add_sub_V4_t;

#define PD_CALL_IDENTITY_RENAME_SUB_V4 12
typedef struct {
    pd_LookupSource_t sub;
    pd_Data_t data;
} pd_identity_rename_sub_V4_t;

#define PD_CALL_IDENTITY_REMOVE_SUB_V4 13
typedef struct {
    pd_LookupSource_t sub;
} pd_identity_remove_sub_V4_t;

#define PD_CALL_IDENTITY_QUIT_SUB_V4 14
typedef struct {
} pd_identity_quit_sub_V4_t;

#define PD_CALL_SOCIETY_BID_V4 0
typedef struct {
    pd_BalanceOf_t value;
} pd_society_bid_V4_t;

#define PD_CALL_SOCIETY_UNBID_V4 1
typedef struct {
    pd_u32_t pos;
} pd_society_unbid_V4_t;

#define PD_CALL_SOCIETY_VOUCH_V4 2
typedef struct {
    pd_AccountId_V4_t who;
    pd_BalanceOf_t value;
    pd_BalanceOf_t tip;
} pd_society_vouch_V4_t;

#define PD_CALL_SOCIETY_UNVOUCH_V4 3
typedef struct {
    pd_u32_t pos;
} pd_society_unvouch_V4_t;

#define PD_CALL_SOCIETY_VOTE_V4 4
typedef struct {
    pd_LookupSource_t candidate;
    pd_bool_t approve;
} pd_society_vote_V4_t;

#define PD_CALL_SOCIETY_DEFENDER_VOTE_V4 5
typedef struct {
    pd_bool_t approve;
} pd_society_defender_vote_V4_t;

#define PD_CALL_SOCIETY_PAYOUT_V4 6
typedef struct {
} pd_society_payout_V4_t;

#define PD_CALL_SOCIETY_FOUND_V4 7
typedef struct {
    pd_AccountId_V4_t founder;
    pd_u32_t max_members;
    pd_Bytes_t rules;
} pd_society_found_V4_t;

#define PD_CALL_SOCIETY_UNFOUND_V4 8
typedef struct {
} pd_society_unfound_V4_t;

#define PD_CALL_SOCIETY_JUDGE_SUSPENDED_MEMBER_V4 9
typedef struct {
    pd_AccountId_V4_t who;
    pd_bool_t forgive;
} pd_society_judge_suspended_member_V4_t;

#define PD_CALL_SOCIETY_JUDGE_SUSPENDED_CANDIDATE_V4 10
typedef struct {
    pd_AccountId_V4_t who;
    pd_Judgement_V4_t judgement;
} pd_society_judge_suspended_candidate_V4_t;

#define PD_CALL_SOCIETY_SET_MAX_MEMBERS_V4 11
typedef struct {
    pd_u32_t max;
} pd_society_set_max_members_V4_t;

#define PD_CALL_RECOVERY_AS_RECOVERED_V4 0
typedef struct {
    pd_AccountId_V4_t account;
    pd_Call_t call;
} pd_recovery_as_recovered_V4_t;

#define PD_CALL_RECOVERY_SET_RECOVERED_V4 1
typedef struct {
    pd_AccountId_V4_t lost;
    pd_AccountId_V4_t rescuer;
} pd_recovery_set_recovered_V4_t;

#define PD_CALL_RECOVERY_CREATE_RECOVERY_V4 2
typedef struct {
    pd_VecAccountId_V4_t friends;
    pd_u16_t threshold;
    pd_BlockNumber_t delay_period;
} pd_recovery_create_recovery_V4_t;

#define PD_CALL_RECOVERY_INITIATE_RECOVERY_V4 3
typedef struct {
    pd_AccountId_V4_t account;
} pd_recovery_initiate_recovery_V4_t;

#define PD_CALL_RECOVERY_VOUCH_RECOVERY_V4 4
typedef struct {
    pd_AccountId_V4_t lost;
    pd_AccountId_V4_t rescuer;
} pd_recovery_vouch_recovery_V4_t;

#define PD_CALL_RECOVERY_CLAIM_RECOVERY_V4 5
typedef struct {
    pd_AccountId_V4_t account;
} pd_recovery_claim_recovery_V4_t;

#define PD_CALL_RECOVERY_CLOSE_RECOVERY_V4 6
typedef struct {
    pd_AccountId_V4_t rescuer;
} pd_recovery_close_recovery_V4_t;

#define PD_CALL_RECOVERY_REMOVE_RECOVERY_V4 7
typedef struct {
} pd_recovery_remove_recovery_V4_t;

#define PD_CALL_RECOVERY_CANCEL_RECOVERED_V4 8
typedef struct {
    pd_AccountId_V4_t account;
} pd_recovery_cancel_recovered_V4_t;

#define PD_CALL_VESTING_VEST_V4 0
typedef struct {
} pd_vesting_vest_V4_t;

#define PD_CALL_VESTING_VEST_OTHER_V4 1
typedef struct {
    pd_LookupSource_t target;
} pd_vesting_vest_other_V4_t;

#define PD_CALL_VESTING_VESTED_TRANSFER_V4 2
typedef struct {
    pd_LookupSource_t target;
    pd_VestingInfo_V4_t schedule;
} pd_vesting_vested_transfer_V4_t;

#define PD_CALL_VESTING_FORCE_VESTED_TRANSFER_V4 3
typedef struct {
    pd_LookupSource_t source;
    pd_LookupSource_t target;
    pd_VestingInfo_V4_t schedule;
} pd_vesting_force_vested_transfer_V4_t;

#define PD_CALL_SCHEDULER_SCHEDULE_V4 0
typedef struct {
    pd_BlockNumber_t when;
    pd_OptionPeriod_V4_t maybe_periodic;
    pd_Priority_V4_t priority;
    pd_Call_t call;
} pd_scheduler_schedule_V4_t;

#define PD_CALL_SCHEDULER_CANCEL_V4 1
typedef struct {
    pd_BlockNumber_t when;
    pd_u32_t index;
} pd_scheduler_cancel_V4_t;

#define PD_CALL_SCHEDULER_SCHEDULE_NAMED_V4 2
typedef struct {
    pd_Bytes_t id;
    pd_BlockNumber_t when;
    pd_OptionPeriod_V4_t maybe_periodic;
    pd_Priority_V4_t priority;
    pd_Call_t call;
} pd_scheduler_schedule_named_V4_t;

#define PD_CALL_SCHEDULER_CANCEL_NAMED_V4 3
typedef struct {
    pd_Bytes_t id;
} pd_scheduler_cancel_named_V4_t;

#define PD_CALL_SCHEDULER_SCHEDULE_AFTER_V4 4
typedef struct {
    pd_BlockNumber_t after;
    pd_OptionPeriod_V4_t maybe_periodic;
    pd_Priority_V4_t priority;
    pd_Call_t call;
} pd_scheduler_schedule_after_V4_t;

#define PD_CALL_SCHEDULER_SCHEDULE_NAMED_AFTER_V4 5
typedef struct {
    pd_Bytes_t id;
    pd_BlockNumber_t after;
    pd_OptionPeriod_V4_t maybe_periodic;
    pd_Priority_V4_t priority;
    pd_Call_t call;
} pd_scheduler_schedule_named_after_V4_t;

#define PD_CALL_PROXY_PROXY_V4 0
typedef struct {
    pd_AccountId_V4_t real;
    pd_OptionProxyType_V4_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_V4_t;

#define PD_CALL_PROXY_ADD_PROXY_V4 1
typedef struct {
    pd_AccountId_V4_t delegate;
    pd_ProxyType_V4_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_add_proxy_V4_t;

#define PD_CALL_PROXY_REMOVE_PROXY_V4 2
typedef struct {
    pd_AccountId_V4_t delegate;
    pd_ProxyType_V4_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_remove_proxy_V4_t;

#define PD_CALL_PROXY_REMOVE_PROXIES_V4 3
typedef struct {
} pd_proxy_remove_proxies_V4_t;

#define PD_CALL_PROXY_ANONYMOUS_V4 4
typedef struct {
    pd_ProxyType_V4_t proxy_type;
    pd_BlockNumber_t delay;
    pd_u16_t index;
} pd_proxy_anonymous_V4_t;

#define PD_CALL_PROXY_KILL_ANONYMOUS_V4 5
typedef struct {
    pd_AccountId_V4_t spawner;
    pd_ProxyType_V4_t proxy_type;
    pd_u16_t index;
    pd_CompactBlockNumber_t height;
    pd_Compactu32_t ext_index;
} pd_proxy_kill_anonymous_V4_t;

#define PD_CALL_PROXY_ANNOUNCE_V4 6
typedef struct {
    pd_AccountId_V4_t real;
    pd_CallHashOf_V4_t call_hash;
} pd_proxy_announce_V4_t;

#define PD_CALL_PROXY_REMOVE_ANNOUNCEMENT_V4 7
typedef struct {
    pd_AccountId_V4_t real;
    pd_CallHashOf_V4_t call_hash;
} pd_proxy_remove_announcement_V4_t;

#define PD_CALL_PROXY_REJECT_ANNOUNCEMENT_V4 8
typedef struct {
    pd_AccountId_V4_t delegate;
    pd_CallHashOf_V4_t call_hash;
} pd_proxy_reject_announcement_V4_t;

#define PD_CALL_PROXY_PROXY_ANNOUNCED_V4 9
typedef struct {
    pd_AccountId_V4_t delegate;
    pd_AccountId_V4_t real;
    pd_OptionProxyType_V4_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_announced_V4_t;

#define PD_CALL_MULTISIG_AS_MULTI_THRESHOLD_1_V4 0
typedef struct {
    pd_VecAccountId_V4_t other_signatories;
    pd_Call_t call;
} pd_multisig_as_multi_threshold_1_V4_t;

#define PD_CALL_MULTISIG_AS_MULTI_V4 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V4_t other_signatories;
    pd_OptionTimepoint_V4_t maybe_timepoint;
    pd_OpaqueCall_V4_t call;
    pd_bool_t store_call;
    pd_Weight_V4_t max_weight;
} pd_multisig_as_multi_V4_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI_V4 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V4_t other_signatories;
    pd_OptionTimepoint_V4_t maybe_timepoint;
    pd_u8_array_32_V4_t call_hash;
    pd_Weight_V4_t max_weight;
} pd_multisig_approve_as_multi_V4_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V4 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V4_t other_signatories;
    pd_Timepoint_V4_t timepoint;
    pd_u8_array_32_V4_t call_hash;
} pd_multisig_cancel_as_multi_V4_t;

#define PD_CALL_BOUNTIES_PROPOSE_BOUNTY_V4 0
typedef struct {
    pd_CompactBalanceOf_t value;
    pd_Bytes_t description;
} pd_bounties_propose_bounty_V4_t;

#define PD_CALL_BOUNTIES_APPROVE_BOUNTY_V4 1
typedef struct {
    pd_CompactBountyIndex_V4_t bounty_id;
} pd_bounties_approve_bounty_V4_t;

#define PD_CALL_BOUNTIES_PROPOSE_CURATOR_V4 2
typedef struct {
    pd_CompactBountyIndex_V4_t bounty_id;
    pd_LookupSource_t curator;
    pd_CompactBalanceOf_t fee;
} pd_bounties_propose_curator_V4_t;

#define PD_CALL_BOUNTIES_UNASSIGN_CURATOR_V4 3
typedef struct {
    pd_CompactBountyIndex_V4_t bounty_id;
} pd_bounties_unassign_curator_V4_t;

#define PD_CALL_BOUNTIES_ACCEPT_CURATOR_V4 4
typedef struct {
    pd_CompactBountyIndex_V4_t bounty_id;
} pd_bounties_accept_curator_V4_t;

#define PD_CALL_BOUNTIES_AWARD_BOUNTY_V4 5
typedef struct {
    pd_CompactBountyIndex_V4_t bounty_id;
    pd_LookupSource_t beneficiary;
} pd_bounties_award_bounty_V4_t;

#define PD_CALL_BOUNTIES_CLAIM_BOUNTY_V4 6
typedef struct {
    pd_CompactBountyIndex_V4_t bounty_id;
} pd_bounties_claim_bounty_V4_t;

#define PD_CALL_BOUNTIES_CLOSE_BOUNTY_V4 7
typedef struct {
    pd_CompactBountyIndex_V4_t bounty_id;
} pd_bounties_close_bounty_V4_t;

#define PD_CALL_BOUNTIES_EXTEND_BOUNTY_EXPIRY_V4 8
typedef struct {
    pd_CompactBountyIndex_V4_t bounty_id;
    pd_Bytes_t _remark;
} pd_bounties_extend_bounty_expiry_V4_t;

#define PD_CALL_TIPS_REPORT_AWESOME_V4 0
typedef struct {
    pd_Bytes_t reason;
    pd_AccountId_V4_t who;
} pd_tips_report_awesome_V4_t;

#define PD_CALL_TIPS_RETRACT_TIP_V4 1
typedef struct {
    pd_Hash_t hash;
} pd_tips_retract_tip_V4_t;

#define PD_CALL_TIPS_TIP_NEW_V4 2
typedef struct {
    pd_Bytes_t reason;
    pd_AccountId_V4_t who;
    pd_CompactBalanceOf_t tip_value;
} pd_tips_tip_new_V4_t;

#define PD_CALL_TIPS_TIP_V4 3
typedef struct {
    pd_Hash_t hash;
    pd_CompactBalanceOf_t tip_value;
} pd_tips_tip_V4_t;

#define PD_CALL_TIPS_CLOSE_TIP_V4 4
typedef struct {
    pd_Hash_t hash;
} pd_tips_close_tip_V4_t;

#define PD_CALL_TIPS_SLASH_TIP_V4 5
typedef struct {
    pd_Hash_t hash;
} pd_tips_slash_tip_V4_t;

typedef union {
    pd_system_fill_block_V4_t system_fill_block_V4;
    pd_system_remark_V4_t system_remark_V4;
    pd_system_set_heap_pages_V4_t system_set_heap_pages_V4;
    pd_system_set_code_V4_t system_set_code_V4;
    pd_system_set_code_without_checks_V4_t system_set_code_without_checks_V4;
    pd_system_set_changes_trie_config_V4_t system_set_changes_trie_config_V4;
    pd_system_set_storage_V4_t system_set_storage_V4;
    pd_system_kill_storage_V4_t system_kill_storage_V4;
    pd_system_kill_prefix_V4_t system_kill_prefix_V4;
    pd_babe_report_equivocation_V4_t babe_report_equivocation_V4;
    pd_babe_report_equivocation_unsigned_V4_t babe_report_equivocation_unsigned_V4;
    pd_timestamp_set_V4_t timestamp_set_V4;
    pd_indices_claim_V4_t indices_claim_V4;
    pd_indices_transfer_V4_t indices_transfer_V4;
    pd_indices_free_V4_t indices_free_V4;
    pd_indices_force_transfer_V4_t indices_force_transfer_V4;
    pd_indices_freeze_V4_t indices_freeze_V4;
    pd_balances_transfer_V4_t balances_transfer_V4;
    pd_balances_set_balance_V4_t balances_set_balance_V4;
    pd_balances_force_transfer_V4_t balances_force_transfer_V4;
    pd_balances_transfer_keep_alive_V4_t balances_transfer_keep_alive_V4;
    pd_authorship_set_uncles_V4_t authorship_set_uncles_V4;
    pd_staking_bond_V4_t staking_bond_V4;
    pd_staking_bond_extra_V4_t staking_bond_extra_V4;
    pd_staking_unbond_V4_t staking_unbond_V4;
    pd_staking_withdraw_unbonded_V4_t staking_withdraw_unbonded_V4;
    pd_staking_validate_V4_t staking_validate_V4;
    pd_staking_nominate_V4_t staking_nominate_V4;
    pd_staking_chill_V4_t staking_chill_V4;
    pd_staking_set_payee_V4_t staking_set_payee_V4;
    pd_staking_set_controller_V4_t staking_set_controller_V4;
    pd_staking_set_validator_count_V4_t staking_set_validator_count_V4;
    pd_staking_increase_validator_count_V4_t staking_increase_validator_count_V4;
    pd_staking_scale_validator_count_V4_t staking_scale_validator_count_V4;
    pd_staking_force_no_eras_V4_t staking_force_no_eras_V4;
    pd_staking_force_new_era_V4_t staking_force_new_era_V4;
    pd_staking_set_invulnerables_V4_t staking_set_invulnerables_V4;
    pd_staking_force_unstake_V4_t staking_force_unstake_V4;
    pd_staking_force_new_era_always_V4_t staking_force_new_era_always_V4;
    pd_staking_cancel_deferred_slash_V4_t staking_cancel_deferred_slash_V4;
    pd_staking_payout_stakers_V4_t staking_payout_stakers_V4;
    pd_staking_rebond_V4_t staking_rebond_V4;
    pd_staking_set_history_depth_V4_t staking_set_history_depth_V4;
    pd_staking_reap_stash_V4_t staking_reap_stash_V4;
    pd_staking_submit_election_solution_V4_t staking_submit_election_solution_V4;
    pd_staking_submit_election_solution_unsigned_V4_t staking_submit_election_solution_unsigned_V4;
    pd_staking_kick_V4_t staking_kick_V4;
    pd_session_set_keys_V4_t session_set_keys_V4;
    pd_session_purge_keys_V4_t session_purge_keys_V4;
    pd_grandpa_report_equivocation_V4_t grandpa_report_equivocation_V4;
    pd_grandpa_report_equivocation_unsigned_V4_t grandpa_report_equivocation_unsigned_V4;
    pd_grandpa_note_stalled_V4_t grandpa_note_stalled_V4;
    pd_imonline_heartbeat_V4_t imonline_heartbeat_V4;
    pd_democracy_propose_V4_t democracy_propose_V4;
    pd_democracy_second_V4_t democracy_second_V4;
    pd_democracy_vote_V4_t democracy_vote_V4;
    pd_democracy_emergency_cancel_V4_t democracy_emergency_cancel_V4;
    pd_democracy_external_propose_V4_t democracy_external_propose_V4;
    pd_democracy_external_propose_majority_V4_t democracy_external_propose_majority_V4;
    pd_democracy_external_propose_default_V4_t democracy_external_propose_default_V4;
    pd_democracy_fast_track_V4_t democracy_fast_track_V4;
    pd_democracy_veto_external_V4_t democracy_veto_external_V4;
    pd_democracy_cancel_referendum_V4_t democracy_cancel_referendum_V4;
    pd_democracy_cancel_queued_V4_t democracy_cancel_queued_V4;
    pd_democracy_delegate_V4_t democracy_delegate_V4;
    pd_democracy_undelegate_V4_t democracy_undelegate_V4;
    pd_democracy_clear_public_proposals_V4_t democracy_clear_public_proposals_V4;
    pd_democracy_note_preimage_V4_t democracy_note_preimage_V4;
    pd_democracy_note_preimage_operational_V4_t democracy_note_preimage_operational_V4;
    pd_democracy_note_imminent_preimage_V4_t democracy_note_imminent_preimage_V4;
    pd_democracy_note_imminent_preimage_operational_V4_t democracy_note_imminent_preimage_operational_V4;
    pd_democracy_reap_preimage_V4_t democracy_reap_preimage_V4;
    pd_democracy_unlock_V4_t democracy_unlock_V4;
    pd_democracy_remove_vote_V4_t democracy_remove_vote_V4;
    pd_democracy_remove_other_vote_V4_t democracy_remove_other_vote_V4;
    pd_democracy_enact_proposal_V4_t democracy_enact_proposal_V4;
    pd_democracy_blacklist_V4_t democracy_blacklist_V4;
    pd_democracy_cancel_proposal_V4_t democracy_cancel_proposal_V4;
    pd_council_set_members_V4_t council_set_members_V4;
    pd_council_execute_V4_t council_execute_V4;
    pd_council_propose_V4_t council_propose_V4;
    pd_council_vote_V4_t council_vote_V4;
    pd_council_close_V4_t council_close_V4;
    pd_council_disapprove_proposal_V4_t council_disapprove_proposal_V4;
    pd_technicalcommittee_set_members_V4_t technicalcommittee_set_members_V4;
    pd_technicalcommittee_execute_V4_t technicalcommittee_execute_V4;
    pd_technicalcommittee_propose_V4_t technicalcommittee_propose_V4;
    pd_technicalcommittee_vote_V4_t technicalcommittee_vote_V4;
    pd_technicalcommittee_close_V4_t technicalcommittee_close_V4;
    pd_technicalcommittee_disapprove_proposal_V4_t technicalcommittee_disapprove_proposal_V4;
    pd_electionsphragmen_vote_V4_t electionsphragmen_vote_V4;
    pd_electionsphragmen_remove_voter_V4_t electionsphragmen_remove_voter_V4;
    pd_electionsphragmen_submit_candidacy_V4_t electionsphragmen_submit_candidacy_V4;
    pd_electionsphragmen_renounce_candidacy_V4_t electionsphragmen_renounce_candidacy_V4;
    pd_electionsphragmen_remove_member_V4_t electionsphragmen_remove_member_V4;
    pd_electionsphragmen_clean_defunct_voters_V4_t electionsphragmen_clean_defunct_voters_V4;
    pd_technicalmembership_add_member_V4_t technicalmembership_add_member_V4;
    pd_technicalmembership_remove_member_V4_t technicalmembership_remove_member_V4;
    pd_technicalmembership_swap_member_V4_t technicalmembership_swap_member_V4;
    pd_technicalmembership_reset_members_V4_t technicalmembership_reset_members_V4;
    pd_technicalmembership_change_key_V4_t technicalmembership_change_key_V4;
    pd_technicalmembership_set_prime_V4_t technicalmembership_set_prime_V4;
    pd_technicalmembership_clear_prime_V4_t technicalmembership_clear_prime_V4;
    pd_treasury_propose_spend_V4_t treasury_propose_spend_V4;
    pd_treasury_reject_proposal_V4_t treasury_reject_proposal_V4;
    pd_treasury_approve_proposal_V4_t treasury_approve_proposal_V4;
    pd_claims_claim_V4_t claims_claim_V4;
    pd_claims_mint_claim_V4_t claims_mint_claim_V4;
    pd_claims_claim_attest_V4_t claims_claim_attest_V4;
    pd_claims_attest_V4_t claims_attest_V4;
    pd_claims_move_claim_V4_t claims_move_claim_V4;
    pd_utility_batch_V4_t utility_batch_V4;
    pd_utility_as_derivative_V4_t utility_as_derivative_V4;
    pd_utility_batch_all_V4_t utility_batch_all_V4;
    pd_identity_add_registrar_V4_t identity_add_registrar_V4;
    pd_identity_set_identity_V4_t identity_set_identity_V4;
    pd_identity_set_subs_V4_t identity_set_subs_V4;
    pd_identity_clear_identity_V4_t identity_clear_identity_V4;
    pd_identity_request_judgement_V4_t identity_request_judgement_V4;
    pd_identity_cancel_request_V4_t identity_cancel_request_V4;
    pd_identity_set_fee_V4_t identity_set_fee_V4;
    pd_identity_set_account_id_V4_t identity_set_account_id_V4;
    pd_identity_set_fields_V4_t identity_set_fields_V4;
    pd_identity_provide_judgement_V4_t identity_provide_judgement_V4;
    pd_identity_kill_identity_V4_t identity_kill_identity_V4;
    pd_identity_add_sub_V4_t identity_add_sub_V4;
    pd_identity_rename_sub_V4_t identity_rename_sub_V4;
    pd_identity_remove_sub_V4_t identity_remove_sub_V4;
    pd_identity_quit_sub_V4_t identity_quit_sub_V4;
    pd_society_bid_V4_t society_bid_V4;
    pd_society_unbid_V4_t society_unbid_V4;
    pd_society_vouch_V4_t society_vouch_V4;
    pd_society_unvouch_V4_t society_unvouch_V4;
    pd_society_vote_V4_t society_vote_V4;
    pd_society_defender_vote_V4_t society_defender_vote_V4;
    pd_society_payout_V4_t society_payout_V4;
    pd_society_found_V4_t society_found_V4;
    pd_society_unfound_V4_t society_unfound_V4;
    pd_society_judge_suspended_member_V4_t society_judge_suspended_member_V4;
    pd_society_judge_suspended_candidate_V4_t society_judge_suspended_candidate_V4;
    pd_society_set_max_members_V4_t society_set_max_members_V4;
    pd_recovery_as_recovered_V4_t recovery_as_recovered_V4;
    pd_recovery_set_recovered_V4_t recovery_set_recovered_V4;
    pd_recovery_create_recovery_V4_t recovery_create_recovery_V4;
    pd_recovery_initiate_recovery_V4_t recovery_initiate_recovery_V4;
    pd_recovery_vouch_recovery_V4_t recovery_vouch_recovery_V4;
    pd_recovery_claim_recovery_V4_t recovery_claim_recovery_V4;
    pd_recovery_close_recovery_V4_t recovery_close_recovery_V4;
    pd_recovery_remove_recovery_V4_t recovery_remove_recovery_V4;
    pd_recovery_cancel_recovered_V4_t recovery_cancel_recovered_V4;
    pd_vesting_vest_V4_t vesting_vest_V4;
    pd_vesting_vest_other_V4_t vesting_vest_other_V4;
    pd_vesting_vested_transfer_V4_t vesting_vested_transfer_V4;
    pd_vesting_force_vested_transfer_V4_t vesting_force_vested_transfer_V4;
    pd_scheduler_schedule_V4_t scheduler_schedule_V4;
    pd_scheduler_cancel_V4_t scheduler_cancel_V4;
    pd_scheduler_schedule_named_V4_t scheduler_schedule_named_V4;
    pd_scheduler_cancel_named_V4_t scheduler_cancel_named_V4;
    pd_scheduler_schedule_after_V4_t scheduler_schedule_after_V4;
    pd_scheduler_schedule_named_after_V4_t scheduler_schedule_named_after_V4;
    pd_proxy_proxy_V4_t proxy_proxy_V4;
    pd_proxy_add_proxy_V4_t proxy_add_proxy_V4;
    pd_proxy_remove_proxy_V4_t proxy_remove_proxy_V4;
    pd_proxy_remove_proxies_V4_t proxy_remove_proxies_V4;
    pd_proxy_anonymous_V4_t proxy_anonymous_V4;
    pd_proxy_kill_anonymous_V4_t proxy_kill_anonymous_V4;
    pd_proxy_announce_V4_t proxy_announce_V4;
    pd_proxy_remove_announcement_V4_t proxy_remove_announcement_V4;
    pd_proxy_reject_announcement_V4_t proxy_reject_announcement_V4;
    pd_proxy_proxy_announced_V4_t proxy_proxy_announced_V4;
    pd_multisig_as_multi_threshold_1_V4_t multisig_as_multi_threshold_1_V4;
    pd_multisig_as_multi_V4_t multisig_as_multi_V4;
    pd_multisig_approve_as_multi_V4_t multisig_approve_as_multi_V4;
    pd_multisig_cancel_as_multi_V4_t multisig_cancel_as_multi_V4;
    pd_bounties_propose_bounty_V4_t bounties_propose_bounty_V4;
    pd_bounties_approve_bounty_V4_t bounties_approve_bounty_V4;
    pd_bounties_propose_curator_V4_t bounties_propose_curator_V4;
    pd_bounties_unassign_curator_V4_t bounties_unassign_curator_V4;
    pd_bounties_accept_curator_V4_t bounties_accept_curator_V4;
    pd_bounties_award_bounty_V4_t bounties_award_bounty_V4;
    pd_bounties_claim_bounty_V4_t bounties_claim_bounty_V4;
    pd_bounties_close_bounty_V4_t bounties_close_bounty_V4;
    pd_bounties_extend_bounty_expiry_V4_t bounties_extend_bounty_expiry_V4;
    pd_tips_report_awesome_V4_t tips_report_awesome_V4;
    pd_tips_retract_tip_V4_t tips_retract_tip_V4;
    pd_tips_tip_new_V4_t tips_tip_new_V4;
    pd_tips_tip_V4_t tips_tip_V4;
    pd_tips_close_tip_V4_t tips_close_tip_V4;
    pd_tips_slash_tip_V4_t tips_slash_tip_V4;
} pd_MethodBasic_V4_t;

typedef union {
} pd_MethodNested_V4_t;

typedef union {
    pd_MethodBasic_V4_t basic;
    pd_MethodNested_V4_t nested;
} pd_Method_V4_t;

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop
