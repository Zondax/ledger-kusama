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
#include "substrate_types_V3.h"
#include <stddef.h>
#include <stdint.h>

#define PD_CALL_SYSTEM_V3 0
#define PD_CALL_BABE_V3 1
#define PD_CALL_TIMESTAMP_V3 2
#define PD_CALL_INDICES_V3 3
#define PD_CALL_BALANCES_V3 4
#define PD_CALL_AUTHORSHIP_V3 5
#define PD_CALL_STAKING_V3 6
#define PD_CALL_OFFENCES_V3 7
#define PD_CALL_SESSION_V3 8
#define PD_CALL_GRANDPA_V3 10
#define PD_CALL_IMONLINE_V3 11
#define PD_CALL_AUTHORITYDISCOVERY_V3 12
#define PD_CALL_DEMOCRACY_V3 13
#define PD_CALL_COUNCIL_V3 14
#define PD_CALL_TECHNICALCOMMITTEE_V3 15
#define PD_CALL_ELECTIONSPHRAGMEN_V3 16
#define PD_CALL_TECHNICALMEMBERSHIP_V3 17
#define PD_CALL_TREASURY_V3 18
#define PD_CALL_CLAIMS_V3 19
#define PD_CALL_UTILITY_V3 24
#define PD_CALL_IDENTITY_V3 25
#define PD_CALL_SOCIETY_V3 26
#define PD_CALL_RECOVERY_V3 27
#define PD_CALL_VESTING_V3 28
#define PD_CALL_SCHEDULER_V3 29
#define PD_CALL_PROXY_V3 30
#define PD_CALL_MULTISIG_V3 31
#define PD_CALL_BOUNTIES_V3 35
#define PD_CALL_TIPS_V3 36

#define PD_CALL_SYSTEM_FILL_BLOCK_V3 0
typedef struct {
    pd_Perbill_V3_t _ratio;
} pd_system_fill_block_V3_t;

#define PD_CALL_SYSTEM_REMARK_V3 1
typedef struct {
    pd_Bytes_t _remark;
} pd_system_remark_V3_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V3 2
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V3_t;

#define PD_CALL_SYSTEM_SET_CODE_V3 3
typedef struct {
    pd_Bytes_t code;
} pd_system_set_code_V3_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V3 4
typedef struct {
    pd_Bytes_t code;
} pd_system_set_code_without_checks_V3_t;

#define PD_CALL_SYSTEM_SET_CHANGES_TRIE_CONFIG_V3 5
typedef struct {
    pd_OptionChangesTrieConfiguration_V3_t changes_trie_config;
} pd_system_set_changes_trie_config_V3_t;

#define PD_CALL_SYSTEM_SET_STORAGE_V3 6
typedef struct {
    pd_VecKeyValue_V3_t items;
} pd_system_set_storage_V3_t;

#define PD_CALL_SYSTEM_KILL_STORAGE_V3 7
typedef struct {
    pd_VecKey_V3_t keys;
} pd_system_kill_storage_V3_t;

#define PD_CALL_SYSTEM_KILL_PREFIX_V3 8
typedef struct {
    pd_Key_V3_t prefix;
    pd_u32_t _subkeys;
} pd_system_kill_prefix_V3_t;

#define PD_CALL_BABE_REPORT_EQUIVOCATION_V3 0
typedef struct {
    pd_EquivocationProof_V3_t equivocation_proof;
    pd_KeyOwnerProof_V3_t key_owner_proof;
} pd_babe_report_equivocation_V3_t;

#define PD_CALL_BABE_REPORT_EQUIVOCATION_UNSIGNED_V3 1
typedef struct {
    pd_EquivocationProof_V3_t equivocation_proof;
    pd_KeyOwnerProof_V3_t key_owner_proof;
} pd_babe_report_equivocation_unsigned_V3_t;

#define PD_CALL_TIMESTAMP_SET_V3 0
typedef struct {
    pd_CompactMoment_V3_t now;
} pd_timestamp_set_V3_t;

#define PD_CALL_INDICES_CLAIM_V3 0
typedef struct {
    pd_AccountIndex_V3_t index;
} pd_indices_claim_V3_t;

#define PD_CALL_INDICES_TRANSFER_V3 1
typedef struct {
    pd_AccountId_V3_t new_;
    pd_AccountIndex_V3_t index;
} pd_indices_transfer_V3_t;

#define PD_CALL_INDICES_FREE_V3 2
typedef struct {
    pd_AccountIndex_V3_t index;
} pd_indices_free_V3_t;

#define PD_CALL_INDICES_FORCE_TRANSFER_V3 3
typedef struct {
    pd_AccountId_V3_t new_;
    pd_AccountIndex_V3_t index;
    pd_bool_t freeze;
} pd_indices_force_transfer_V3_t;

#define PD_CALL_INDICES_FREEZE_V3 4
typedef struct {
    pd_AccountIndex_V3_t index;
} pd_indices_freeze_V3_t;

#define PD_CALL_BALANCES_TRANSFER_V3 0
typedef struct {
    pd_LookupSource_t dest;
    pd_CompactBalance_t value;
} pd_balances_transfer_V3_t;

#define PD_CALL_BALANCES_SET_BALANCE_V3 1
typedef struct {
    pd_LookupSource_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_V3_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V3 2
typedef struct {
    pd_LookupSource_t source;
    pd_LookupSource_t dest;
    pd_CompactBalance_t value;
} pd_balances_force_transfer_V3_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V3 3
typedef struct {
    pd_LookupSource_t dest;
    pd_CompactBalance_t value;
} pd_balances_transfer_keep_alive_V3_t;

#define PD_CALL_AUTHORSHIP_SET_UNCLES_V3 0
typedef struct {
    pd_VecHeader_t new_uncles;
} pd_authorship_set_uncles_V3_t;

#define PD_CALL_STAKING_BOND_V3 0
typedef struct {
    pd_LookupSource_t controller;
    pd_CompactBalanceOf_t value;
    pd_RewardDestination_V3_t payee;
} pd_staking_bond_V3_t;

#define PD_CALL_STAKING_BOND_EXTRA_V3 1
typedef struct {
    pd_CompactBalanceOf_t max_additional;
} pd_staking_bond_extra_V3_t;

#define PD_CALL_STAKING_UNBOND_V3 2
typedef struct {
    pd_CompactBalanceOf_t value;
} pd_staking_unbond_V3_t;

#define PD_CALL_STAKING_WITHDRAW_UNBONDED_V3 3
typedef struct {
    pd_u32_t num_slashing_spans;
} pd_staking_withdraw_unbonded_V3_t;

#define PD_CALL_STAKING_VALIDATE_V3 4
typedef struct {
    pd_ValidatorPrefs_V3_t prefs;
} pd_staking_validate_V3_t;

#define PD_CALL_STAKING_NOMINATE_V3 5
typedef struct {
    pd_VecLookupSource_t targets;
} pd_staking_nominate_V3_t;

#define PD_CALL_STAKING_CHILL_V3 6
typedef struct {
} pd_staking_chill_V3_t;

#define PD_CALL_STAKING_SET_PAYEE_V3 7
typedef struct {
    pd_RewardDestination_V3_t payee;
} pd_staking_set_payee_V3_t;

#define PD_CALL_STAKING_SET_CONTROLLER_V3 8
typedef struct {
    pd_LookupSource_t controller;
} pd_staking_set_controller_V3_t;

#define PD_CALL_STAKING_SET_VALIDATOR_COUNT_V3 9
typedef struct {
    pd_Compactu32_t new_;
} pd_staking_set_validator_count_V3_t;

#define PD_CALL_STAKING_INCREASE_VALIDATOR_COUNT_V3 10
typedef struct {
    pd_Compactu32_t additional;
} pd_staking_increase_validator_count_V3_t;

#define PD_CALL_STAKING_SCALE_VALIDATOR_COUNT_V3 11
typedef struct {
    pd_Percent_V3_t factor;
} pd_staking_scale_validator_count_V3_t;

#define PD_CALL_STAKING_FORCE_NO_ERAS_V3 12
typedef struct {
} pd_staking_force_no_eras_V3_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_V3 13
typedef struct {
} pd_staking_force_new_era_V3_t;

#define PD_CALL_STAKING_SET_INVULNERABLES_V3 14
typedef struct {
    pd_VecAccountId_V3_t invulnerables;
} pd_staking_set_invulnerables_V3_t;

#define PD_CALL_STAKING_FORCE_UNSTAKE_V3 15
typedef struct {
    pd_AccountId_V3_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_force_unstake_V3_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_ALWAYS_V3 16
typedef struct {
} pd_staking_force_new_era_always_V3_t;

#define PD_CALL_STAKING_CANCEL_DEFERRED_SLASH_V3 17
typedef struct {
    pd_EraIndex_V3_t era;
    pd_Vecu32_t slash_indices;
} pd_staking_cancel_deferred_slash_V3_t;

#define PD_CALL_STAKING_PAYOUT_STAKERS_V3 18
typedef struct {
    pd_AccountId_V3_t validator_stash;
    pd_EraIndex_V3_t era;
} pd_staking_payout_stakers_V3_t;

#define PD_CALL_STAKING_REBOND_V3 19
typedef struct {
    pd_CompactBalanceOf_t value;
} pd_staking_rebond_V3_t;

#define PD_CALL_STAKING_SET_HISTORY_DEPTH_V3 20
typedef struct {
    pd_CompactEraIndex_V3_t new_history_depth;
    pd_Compactu32_t _era_items_deleted;
} pd_staking_set_history_depth_V3_t;

#define PD_CALL_STAKING_REAP_STASH_V3 21
typedef struct {
    pd_AccountId_V3_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_reap_stash_V3_t;

#define PD_CALL_STAKING_SUBMIT_ELECTION_SOLUTION_V3 22
typedef struct {
    pd_VecValidatorIndex_V3_t winners;
    pd_CompactAssignments_V3_t compact;
    pd_ElectionScore_V3_t score;
    pd_EraIndex_V3_t era;
    pd_ElectionSize_V3_t size;
} pd_staking_submit_election_solution_V3_t;

#define PD_CALL_STAKING_SUBMIT_ELECTION_SOLUTION_UNSIGNED_V3 23
typedef struct {
    pd_VecValidatorIndex_V3_t winners;
    pd_CompactAssignments_V3_t compact;
    pd_ElectionScore_V3_t score;
    pd_EraIndex_V3_t era;
    pd_ElectionSize_V3_t size;
} pd_staking_submit_election_solution_unsigned_V3_t;

#define PD_CALL_STAKING_KICK_V3 24
typedef struct {
    pd_VecLookupSource_t who;
} pd_staking_kick_V3_t;

#define PD_CALL_SESSION_SET_KEYS_V3 0
typedef struct {
    pd_Keys_V3_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V3_t;

#define PD_CALL_SESSION_PURGE_KEYS_V3 1
typedef struct {
} pd_session_purge_keys_V3_t;

#define PD_CALL_GRANDPA_REPORT_EQUIVOCATION_V3 0
typedef struct {
    pd_EquivocationProof_V3_t equivocation_proof;
    pd_KeyOwnerProof_V3_t key_owner_proof;
} pd_grandpa_report_equivocation_V3_t;

#define PD_CALL_GRANDPA_REPORT_EQUIVOCATION_UNSIGNED_V3 1
typedef struct {
    pd_EquivocationProof_V3_t equivocation_proof;
    pd_KeyOwnerProof_V3_t key_owner_proof;
} pd_grandpa_report_equivocation_unsigned_V3_t;

#define PD_CALL_GRANDPA_NOTE_STALLED_V3 2
typedef struct {
    pd_BlockNumber_t delay;
    pd_BlockNumber_t best_finalized_block_number;
} pd_grandpa_note_stalled_V3_t;

#define PD_CALL_IMONLINE_HEARTBEAT_V3 0
typedef struct {
    pd_Heartbeat_t heartbeat;
    pd_Signature_V3_t _signature;
} pd_imonline_heartbeat_V3_t;

#define PD_CALL_DEMOCRACY_PROPOSE_V3 0
typedef struct {
    pd_Hash_t proposal_hash;
    pd_CompactBalanceOf_t value;
} pd_democracy_propose_V3_t;

#define PD_CALL_DEMOCRACY_SECOND_V3 1
typedef struct {
    pd_CompactPropIndex_V3_t proposal;
    pd_Compactu32_t seconds_upper_bound;
} pd_democracy_second_V3_t;

#define PD_CALL_DEMOCRACY_VOTE_V3 2
typedef struct {
    pd_CompactReferendumIndex_V3_t ref_index;
    pd_AccountVote_V3_t vote;
} pd_democracy_vote_V3_t;

#define PD_CALL_DEMOCRACY_EMERGENCY_CANCEL_V3 3
typedef struct {
    pd_ReferendumIndex_V3_t ref_index;
} pd_democracy_emergency_cancel_V3_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_V3 4
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_V3_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_MAJORITY_V3 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_majority_V3_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_DEFAULT_V3 6
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_default_V3_t;

#define PD_CALL_DEMOCRACY_FAST_TRACK_V3 7
typedef struct {
    pd_Hash_t proposal_hash;
    pd_BlockNumber_t voting_period;
    pd_BlockNumber_t delay;
} pd_democracy_fast_track_V3_t;

#define PD_CALL_DEMOCRACY_VETO_EXTERNAL_V3 8
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_veto_external_V3_t;

#define PD_CALL_DEMOCRACY_CANCEL_REFERENDUM_V3 9
typedef struct {
    pd_CompactReferendumIndex_V3_t ref_index;
} pd_democracy_cancel_referendum_V3_t;

#define PD_CALL_DEMOCRACY_CANCEL_QUEUED_V3 10
typedef struct {
    pd_ReferendumIndex_V3_t which;
} pd_democracy_cancel_queued_V3_t;

#define PD_CALL_DEMOCRACY_DELEGATE_V3 11
typedef struct {
    pd_AccountId_V3_t to;
    pd_Conviction_V3_t conviction;
    pd_BalanceOf_t balance;
} pd_democracy_delegate_V3_t;

#define PD_CALL_DEMOCRACY_UNDELEGATE_V3 12
typedef struct {
} pd_democracy_undelegate_V3_t;

#define PD_CALL_DEMOCRACY_CLEAR_PUBLIC_PROPOSALS_V3 13
typedef struct {
} pd_democracy_clear_public_proposals_V3_t;

#define PD_CALL_DEMOCRACY_NOTE_PREIMAGE_V3 14
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_preimage_V3_t;

#define PD_CALL_DEMOCRACY_NOTE_PREIMAGE_OPERATIONAL_V3 15
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_preimage_operational_V3_t;

#define PD_CALL_DEMOCRACY_NOTE_IMMINENT_PREIMAGE_V3 16
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_imminent_preimage_V3_t;

#define PD_CALL_DEMOCRACY_NOTE_IMMINENT_PREIMAGE_OPERATIONAL_V3 17
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_imminent_preimage_operational_V3_t;

#define PD_CALL_DEMOCRACY_REAP_PREIMAGE_V3 18
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t proposal_len_upper_bound;
} pd_democracy_reap_preimage_V3_t;

#define PD_CALL_DEMOCRACY_UNLOCK_V3 19
typedef struct {
    pd_AccountId_V3_t target;
} pd_democracy_unlock_V3_t;

#define PD_CALL_DEMOCRACY_REMOVE_VOTE_V3 20
typedef struct {
    pd_ReferendumIndex_V3_t index;
} pd_democracy_remove_vote_V3_t;

#define PD_CALL_DEMOCRACY_REMOVE_OTHER_VOTE_V3 21
typedef struct {
    pd_AccountId_V3_t target;
    pd_ReferendumIndex_V3_t index;
} pd_democracy_remove_other_vote_V3_t;

#define PD_CALL_DEMOCRACY_ENACT_PROPOSAL_V3 22
typedef struct {
    pd_Hash_t proposal_hash;
    pd_ReferendumIndex_V3_t index;
} pd_democracy_enact_proposal_V3_t;

#define PD_CALL_DEMOCRACY_BLACKLIST_V3 23
typedef struct {
    pd_Hash_t proposal_hash;
    pd_OptionReferendumIndex_V3_t maybe_ref_index;
} pd_democracy_blacklist_V3_t;

#define PD_CALL_DEMOCRACY_CANCEL_PROPOSAL_V3 24
typedef struct {
    pd_CompactPropIndex_V3_t prop_index;
} pd_democracy_cancel_proposal_V3_t;

#define PD_CALL_COUNCIL_SET_MEMBERS_V3 0
typedef struct {
    pd_VecAccountId_V3_t new_members;
    pd_OptionAccountId_V3_t prime;
    pd_MemberCount_V3_t old_count;
} pd_council_set_members_V3_t;

#define PD_CALL_COUNCIL_EXECUTE_V3 1
typedef struct {
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_council_execute_V3_t;

#define PD_CALL_COUNCIL_PROPOSE_V3 2
typedef struct {
    pd_CompactMemberCount_V3_t threshold;
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_council_propose_V3_t;

#define PD_CALL_COUNCIL_VOTE_V3 3
typedef struct {
    pd_Hash_t proposal;
    pd_CompactProposalIndex_V3_t index;
    pd_bool_t approve;
} pd_council_vote_V3_t;

#define PD_CALL_COUNCIL_CLOSE_V3 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_CompactProposalIndex_V3_t index;
    pd_CompactWeight_V3_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_council_close_V3_t;

#define PD_CALL_COUNCIL_DISAPPROVE_PROPOSAL_V3 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_council_disapprove_proposal_V3_t;

#define PD_CALL_TECHNICALCOMMITTEE_SET_MEMBERS_V3 0
typedef struct {
    pd_VecAccountId_V3_t new_members;
    pd_OptionAccountId_V3_t prime;
    pd_MemberCount_V3_t old_count;
} pd_technicalcommittee_set_members_V3_t;

#define PD_CALL_TECHNICALCOMMITTEE_EXECUTE_V3 1
typedef struct {
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_execute_V3_t;

#define PD_CALL_TECHNICALCOMMITTEE_PROPOSE_V3 2
typedef struct {
    pd_CompactMemberCount_V3_t threshold;
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_propose_V3_t;

#define PD_CALL_TECHNICALCOMMITTEE_VOTE_V3 3
typedef struct {
    pd_Hash_t proposal;
    pd_CompactProposalIndex_V3_t index;
    pd_bool_t approve;
} pd_technicalcommittee_vote_V3_t;

#define PD_CALL_TECHNICALCOMMITTEE_CLOSE_V3 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_CompactProposalIndex_V3_t index;
    pd_CompactWeight_V3_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_close_V3_t;

#define PD_CALL_TECHNICALCOMMITTEE_DISAPPROVE_PROPOSAL_V3 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_technicalcommittee_disapprove_proposal_V3_t;

#define PD_CALL_ELECTIONSPHRAGMEN_VOTE_V3 0
typedef struct {
    pd_VecAccountId_V3_t votes;
    pd_CompactBalanceOf_t value;
} pd_electionsphragmen_vote_V3_t;

#define PD_CALL_ELECTIONSPHRAGMEN_REMOVE_VOTER_V3 1
typedef struct {
} pd_electionsphragmen_remove_voter_V3_t;

#define PD_CALL_ELECTIONSPHRAGMEN_SUBMIT_CANDIDACY_V3 2
typedef struct {
    pd_Compactu32_t candidate_count;
} pd_electionsphragmen_submit_candidacy_V3_t;

#define PD_CALL_ELECTIONSPHRAGMEN_RENOUNCE_CANDIDACY_V3 3
typedef struct {
    pd_Renouncing_V3_t renouncing;
} pd_electionsphragmen_renounce_candidacy_V3_t;

#define PD_CALL_ELECTIONSPHRAGMEN_REMOVE_MEMBER_V3 4
typedef struct {
    pd_LookupSource_t who;
    pd_bool_t has_replacement;
} pd_electionsphragmen_remove_member_V3_t;

#define PD_CALL_ELECTIONSPHRAGMEN_CLEAN_DEFUNCT_VOTERS_V3 5
typedef struct {
    pd_u32_t _num_voters;
    pd_u32_t _num_defunct;
} pd_electionsphragmen_clean_defunct_voters_V3_t;

#define PD_CALL_TECHNICALMEMBERSHIP_ADD_MEMBER_V3 0
typedef struct {
    pd_AccountId_V3_t who;
} pd_technicalmembership_add_member_V3_t;

#define PD_CALL_TECHNICALMEMBERSHIP_REMOVE_MEMBER_V3 1
typedef struct {
    pd_AccountId_V3_t who;
} pd_technicalmembership_remove_member_V3_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SWAP_MEMBER_V3 2
typedef struct {
    pd_AccountId_V3_t remove;
    pd_AccountId_V3_t add;
} pd_technicalmembership_swap_member_V3_t;

#define PD_CALL_TECHNICALMEMBERSHIP_RESET_MEMBERS_V3 3
typedef struct {
    pd_VecAccountId_V3_t members;
} pd_technicalmembership_reset_members_V3_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CHANGE_KEY_V3 4
typedef struct {
    pd_AccountId_V3_t new_;
} pd_technicalmembership_change_key_V3_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SET_PRIME_V3 5
typedef struct {
    pd_AccountId_V3_t who;
} pd_technicalmembership_set_prime_V3_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CLEAR_PRIME_V3 6
typedef struct {
} pd_technicalmembership_clear_prime_V3_t;

#define PD_CALL_TREASURY_PROPOSE_SPEND_V3 0
typedef struct {
    pd_CompactBalanceOf_t value;
    pd_LookupSource_t beneficiary;
} pd_treasury_propose_spend_V3_t;

#define PD_CALL_TREASURY_REJECT_PROPOSAL_V3 1
typedef struct {
    pd_CompactProposalIndex_V3_t proposal_id;
} pd_treasury_reject_proposal_V3_t;

#define PD_CALL_TREASURY_APPROVE_PROPOSAL_V3 2
typedef struct {
    pd_CompactProposalIndex_V3_t proposal_id;
} pd_treasury_approve_proposal_V3_t;

#define PD_CALL_CLAIMS_CLAIM_V3 0
typedef struct {
    pd_AccountId_V3_t dest;
    pd_EcdsaSignature_V3_t ethereum_signature;
} pd_claims_claim_V3_t;

#define PD_CALL_CLAIMS_MINT_CLAIM_V3 1
typedef struct {
    pd_EthereumAddress_V3_t who;
    pd_BalanceOf_t value;
    pd_OptionTupleBalanceOfBalanceOfBlockNumber_V3_t vesting_schedule;
    pd_OptionStatementKind_V3_t statement;
} pd_claims_mint_claim_V3_t;

#define PD_CALL_CLAIMS_CLAIM_ATTEST_V3 2
typedef struct {
    pd_AccountId_V3_t dest;
    pd_EcdsaSignature_V3_t ethereum_signature;
    pd_Bytes_t statement;
} pd_claims_claim_attest_V3_t;

#define PD_CALL_CLAIMS_ATTEST_V3 3
typedef struct {
    pd_Bytes_t statement;
} pd_claims_attest_V3_t;

#define PD_CALL_CLAIMS_MOVE_CLAIM_V3 4
typedef struct {
    pd_EthereumAddress_V3_t old;
    pd_EthereumAddress_V3_t new_;
    pd_OptionAccountId_V3_t maybe_preclaim;
} pd_claims_move_claim_V3_t;

#define PD_CALL_UTILITY_BATCH_V3 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V3_t;

#define PD_CALL_UTILITY_AS_DERIVATIVE_V3 1
typedef struct {
    pd_u16_t index;
    pd_Call_t call;
} pd_utility_as_derivative_V3_t;

#define PD_CALL_UTILITY_BATCH_ALL_V3 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V3_t;

#define PD_CALL_IDENTITY_ADD_REGISTRAR_V3 0
typedef struct {
    pd_AccountId_V3_t account;
} pd_identity_add_registrar_V3_t;

#define PD_CALL_IDENTITY_SET_IDENTITY_V3 1
typedef struct {
    pd_IdentityInfo_V3_t info;
} pd_identity_set_identity_V3_t;

#define PD_CALL_IDENTITY_SET_SUBS_V3 2
typedef struct {
    pd_VecTupleAccountIdData_V3_t subs;
} pd_identity_set_subs_V3_t;

#define PD_CALL_IDENTITY_CLEAR_IDENTITY_V3 3
typedef struct {
} pd_identity_clear_identity_V3_t;

#define PD_CALL_IDENTITY_REQUEST_JUDGEMENT_V3 4
typedef struct {
    pd_CompactRegistrarIndex_V3_t reg_index;
    pd_CompactBalanceOf_t max_fee;
} pd_identity_request_judgement_V3_t;

#define PD_CALL_IDENTITY_CANCEL_REQUEST_V3 5
typedef struct {
    pd_RegistrarIndex_V3_t reg_index;
} pd_identity_cancel_request_V3_t;

#define PD_CALL_IDENTITY_SET_FEE_V3 6
typedef struct {
    pd_CompactRegistrarIndex_V3_t index;
    pd_CompactBalanceOf_t fee;
} pd_identity_set_fee_V3_t;

#define PD_CALL_IDENTITY_SET_ACCOUNT_ID_V3 7
typedef struct {
    pd_CompactRegistrarIndex_V3_t index;
    pd_AccountId_V3_t new_;
} pd_identity_set_account_id_V3_t;

#define PD_CALL_IDENTITY_SET_FIELDS_V3 8
typedef struct {
    pd_CompactRegistrarIndex_V3_t index;
    pd_IdentityFields_V3_t fields;
} pd_identity_set_fields_V3_t;

#define PD_CALL_IDENTITY_PROVIDE_JUDGEMENT_V3 9
typedef struct {
    pd_CompactRegistrarIndex_V3_t reg_index;
    pd_LookupSource_t target;
    pd_Judgement_V3_t judgement;
} pd_identity_provide_judgement_V3_t;

#define PD_CALL_IDENTITY_KILL_IDENTITY_V3 10
typedef struct {
    pd_LookupSource_t target;
} pd_identity_kill_identity_V3_t;

#define PD_CALL_IDENTITY_ADD_SUB_V3 11
typedef struct {
    pd_LookupSource_t sub;
    pd_Data_t data;
} pd_identity_add_sub_V3_t;

#define PD_CALL_IDENTITY_RENAME_SUB_V3 12
typedef struct {
    pd_LookupSource_t sub;
    pd_Data_t data;
} pd_identity_rename_sub_V3_t;

#define PD_CALL_IDENTITY_REMOVE_SUB_V3 13
typedef struct {
    pd_LookupSource_t sub;
} pd_identity_remove_sub_V3_t;

#define PD_CALL_IDENTITY_QUIT_SUB_V3 14
typedef struct {
} pd_identity_quit_sub_V3_t;

#define PD_CALL_SOCIETY_BID_V3 0
typedef struct {
    pd_BalanceOf_t value;
} pd_society_bid_V3_t;

#define PD_CALL_SOCIETY_UNBID_V3 1
typedef struct {
    pd_u32_t pos;
} pd_society_unbid_V3_t;

#define PD_CALL_SOCIETY_VOUCH_V3 2
typedef struct {
    pd_AccountId_V3_t who;
    pd_BalanceOf_t value;
    pd_BalanceOf_t tip;
} pd_society_vouch_V3_t;

#define PD_CALL_SOCIETY_UNVOUCH_V3 3
typedef struct {
    pd_u32_t pos;
} pd_society_unvouch_V3_t;

#define PD_CALL_SOCIETY_VOTE_V3 4
typedef struct {
    pd_LookupSource_t candidate;
    pd_bool_t approve;
} pd_society_vote_V3_t;

#define PD_CALL_SOCIETY_DEFENDER_VOTE_V3 5
typedef struct {
    pd_bool_t approve;
} pd_society_defender_vote_V3_t;

#define PD_CALL_SOCIETY_PAYOUT_V3 6
typedef struct {
} pd_society_payout_V3_t;

#define PD_CALL_SOCIETY_FOUND_V3 7
typedef struct {
    pd_AccountId_V3_t founder;
    pd_u32_t max_members;
    pd_Bytes_t rules;
} pd_society_found_V3_t;

#define PD_CALL_SOCIETY_UNFOUND_V3 8
typedef struct {
} pd_society_unfound_V3_t;

#define PD_CALL_SOCIETY_JUDGE_SUSPENDED_MEMBER_V3 9
typedef struct {
    pd_AccountId_V3_t who;
    pd_bool_t forgive;
} pd_society_judge_suspended_member_V3_t;

#define PD_CALL_SOCIETY_JUDGE_SUSPENDED_CANDIDATE_V3 10
typedef struct {
    pd_AccountId_V3_t who;
    pd_Judgement_V3_t judgement;
} pd_society_judge_suspended_candidate_V3_t;

#define PD_CALL_SOCIETY_SET_MAX_MEMBERS_V3 11
typedef struct {
    pd_u32_t max;
} pd_society_set_max_members_V3_t;

#define PD_CALL_RECOVERY_AS_RECOVERED_V3 0
typedef struct {
    pd_AccountId_V3_t account;
    pd_Call_t call;
} pd_recovery_as_recovered_V3_t;

#define PD_CALL_RECOVERY_SET_RECOVERED_V3 1
typedef struct {
    pd_AccountId_V3_t lost;
    pd_AccountId_V3_t rescuer;
} pd_recovery_set_recovered_V3_t;

#define PD_CALL_RECOVERY_CREATE_RECOVERY_V3 2
typedef struct {
    pd_VecAccountId_V3_t friends;
    pd_u16_t threshold;
    pd_BlockNumber_t delay_period;
} pd_recovery_create_recovery_V3_t;

#define PD_CALL_RECOVERY_INITIATE_RECOVERY_V3 3
typedef struct {
    pd_AccountId_V3_t account;
} pd_recovery_initiate_recovery_V3_t;

#define PD_CALL_RECOVERY_VOUCH_RECOVERY_V3 4
typedef struct {
    pd_AccountId_V3_t lost;
    pd_AccountId_V3_t rescuer;
} pd_recovery_vouch_recovery_V3_t;

#define PD_CALL_RECOVERY_CLAIM_RECOVERY_V3 5
typedef struct {
    pd_AccountId_V3_t account;
} pd_recovery_claim_recovery_V3_t;

#define PD_CALL_RECOVERY_CLOSE_RECOVERY_V3 6
typedef struct {
    pd_AccountId_V3_t rescuer;
} pd_recovery_close_recovery_V3_t;

#define PD_CALL_RECOVERY_REMOVE_RECOVERY_V3 7
typedef struct {
} pd_recovery_remove_recovery_V3_t;

#define PD_CALL_RECOVERY_CANCEL_RECOVERED_V3 8
typedef struct {
    pd_AccountId_V3_t account;
} pd_recovery_cancel_recovered_V3_t;

#define PD_CALL_VESTING_VEST_V3 0
typedef struct {
} pd_vesting_vest_V3_t;

#define PD_CALL_VESTING_VEST_OTHER_V3 1
typedef struct {
    pd_LookupSource_t target;
} pd_vesting_vest_other_V3_t;

#define PD_CALL_VESTING_VESTED_TRANSFER_V3 2
typedef struct {
    pd_LookupSource_t target;
    pd_VestingInfo_V3_t schedule;
} pd_vesting_vested_transfer_V3_t;

#define PD_CALL_VESTING_FORCE_VESTED_TRANSFER_V3 3
typedef struct {
    pd_LookupSource_t source;
    pd_LookupSource_t target;
    pd_VestingInfo_V3_t schedule;
} pd_vesting_force_vested_transfer_V3_t;

#define PD_CALL_SCHEDULER_SCHEDULE_V3 0
typedef struct {
    pd_BlockNumber_t when;
    pd_OptionPeriod_V3_t maybe_periodic;
    pd_Priority_V3_t priority;
    pd_Call_t call;
} pd_scheduler_schedule_V3_t;

#define PD_CALL_SCHEDULER_CANCEL_V3 1
typedef struct {
    pd_BlockNumber_t when;
    pd_u32_t index;
} pd_scheduler_cancel_V3_t;

#define PD_CALL_SCHEDULER_SCHEDULE_NAMED_V3 2
typedef struct {
    pd_Bytes_t id;
    pd_BlockNumber_t when;
    pd_OptionPeriod_V3_t maybe_periodic;
    pd_Priority_V3_t priority;
    pd_Call_t call;
} pd_scheduler_schedule_named_V3_t;

#define PD_CALL_SCHEDULER_CANCEL_NAMED_V3 3
typedef struct {
    pd_Bytes_t id;
} pd_scheduler_cancel_named_V3_t;

#define PD_CALL_SCHEDULER_SCHEDULE_AFTER_V3 4
typedef struct {
    pd_BlockNumber_t after;
    pd_OptionPeriod_V3_t maybe_periodic;
    pd_Priority_V3_t priority;
    pd_Call_t call;
} pd_scheduler_schedule_after_V3_t;

#define PD_CALL_SCHEDULER_SCHEDULE_NAMED_AFTER_V3 5
typedef struct {
    pd_Bytes_t id;
    pd_BlockNumber_t after;
    pd_OptionPeriod_V3_t maybe_periodic;
    pd_Priority_V3_t priority;
    pd_Call_t call;
} pd_scheduler_schedule_named_after_V3_t;

#define PD_CALL_PROXY_PROXY_V3 0
typedef struct {
    pd_AccountId_V3_t real;
    pd_OptionProxyType_V3_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_V3_t;

#define PD_CALL_PROXY_ADD_PROXY_V3 1
typedef struct {
    pd_AccountId_V3_t delegate;
    pd_ProxyType_V3_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_add_proxy_V3_t;

#define PD_CALL_PROXY_REMOVE_PROXY_V3 2
typedef struct {
    pd_AccountId_V3_t delegate;
    pd_ProxyType_V3_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_remove_proxy_V3_t;

#define PD_CALL_PROXY_REMOVE_PROXIES_V3 3
typedef struct {
} pd_proxy_remove_proxies_V3_t;

#define PD_CALL_PROXY_ANONYMOUS_V3 4
typedef struct {
    pd_ProxyType_V3_t proxy_type;
    pd_BlockNumber_t delay;
    pd_u16_t index;
} pd_proxy_anonymous_V3_t;

#define PD_CALL_PROXY_KILL_ANONYMOUS_V3 5
typedef struct {
    pd_AccountId_V3_t spawner;
    pd_ProxyType_V3_t proxy_type;
    pd_u16_t index;
    pd_CompactBlockNumber_t height;
    pd_Compactu32_t ext_index;
} pd_proxy_kill_anonymous_V3_t;

#define PD_CALL_PROXY_ANNOUNCE_V3 6
typedef struct {
    pd_AccountId_V3_t real;
    pd_CallHashOf_V3_t call_hash;
} pd_proxy_announce_V3_t;

#define PD_CALL_PROXY_REMOVE_ANNOUNCEMENT_V3 7
typedef struct {
    pd_AccountId_V3_t real;
    pd_CallHashOf_V3_t call_hash;
} pd_proxy_remove_announcement_V3_t;

#define PD_CALL_PROXY_REJECT_ANNOUNCEMENT_V3 8
typedef struct {
    pd_AccountId_V3_t delegate;
    pd_CallHashOf_V3_t call_hash;
} pd_proxy_reject_announcement_V3_t;

#define PD_CALL_PROXY_PROXY_ANNOUNCED_V3 9
typedef struct {
    pd_AccountId_V3_t delegate;
    pd_AccountId_V3_t real;
    pd_OptionProxyType_V3_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_announced_V3_t;

#define PD_CALL_MULTISIG_AS_MULTI_THRESHOLD_1_V3 0
typedef struct {
    pd_VecAccountId_V3_t other_signatories;
    pd_Call_t call;
} pd_multisig_as_multi_threshold_1_V3_t;

#define PD_CALL_MULTISIG_AS_MULTI_V3 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V3_t other_signatories;
    pd_OptionTimepoint_V3_t maybe_timepoint;
    pd_OpaqueCall_V3_t call;
    pd_bool_t store_call;
    pd_Weight_V3_t max_weight;
} pd_multisig_as_multi_V3_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI_V3 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V3_t other_signatories;
    pd_OptionTimepoint_V3_t maybe_timepoint;
    pd_u8_array_32_V3_t call_hash;
    pd_Weight_V3_t max_weight;
} pd_multisig_approve_as_multi_V3_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V3 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V3_t other_signatories;
    pd_Timepoint_V3_t timepoint;
    pd_u8_array_32_V3_t call_hash;
} pd_multisig_cancel_as_multi_V3_t;

#define PD_CALL_BOUNTIES_PROPOSE_BOUNTY_V3 0
typedef struct {
    pd_CompactBalanceOf_t value;
    pd_Bytes_t description;
} pd_bounties_propose_bounty_V3_t;

#define PD_CALL_BOUNTIES_APPROVE_BOUNTY_V3 1
typedef struct {
    pd_CompactBountyIndex_V3_t bounty_id;
} pd_bounties_approve_bounty_V3_t;

#define PD_CALL_BOUNTIES_PROPOSE_CURATOR_V3 2
typedef struct {
    pd_CompactBountyIndex_V3_t bounty_id;
    pd_LookupSource_t curator;
    pd_CompactBalanceOf_t fee;
} pd_bounties_propose_curator_V3_t;

#define PD_CALL_BOUNTIES_UNASSIGN_CURATOR_V3 3
typedef struct {
    pd_CompactBountyIndex_V3_t bounty_id;
} pd_bounties_unassign_curator_V3_t;

#define PD_CALL_BOUNTIES_ACCEPT_CURATOR_V3 4
typedef struct {
    pd_CompactBountyIndex_V3_t bounty_id;
} pd_bounties_accept_curator_V3_t;

#define PD_CALL_BOUNTIES_AWARD_BOUNTY_V3 5
typedef struct {
    pd_CompactBountyIndex_V3_t bounty_id;
    pd_LookupSource_t beneficiary;
} pd_bounties_award_bounty_V3_t;

#define PD_CALL_BOUNTIES_CLAIM_BOUNTY_V3 6
typedef struct {
    pd_CompactBountyIndex_V3_t bounty_id;
} pd_bounties_claim_bounty_V3_t;

#define PD_CALL_BOUNTIES_CLOSE_BOUNTY_V3 7
typedef struct {
    pd_CompactBountyIndex_V3_t bounty_id;
} pd_bounties_close_bounty_V3_t;

#define PD_CALL_BOUNTIES_EXTEND_BOUNTY_EXPIRY_V3 8
typedef struct {
    pd_CompactBountyIndex_V3_t bounty_id;
    pd_Bytes_t _remark;
} pd_bounties_extend_bounty_expiry_V3_t;

#define PD_CALL_TIPS_REPORT_AWESOME_V3 0
typedef struct {
    pd_Bytes_t reason;
    pd_AccountId_V3_t who;
} pd_tips_report_awesome_V3_t;

#define PD_CALL_TIPS_RETRACT_TIP_V3 1
typedef struct {
    pd_Hash_t hash;
} pd_tips_retract_tip_V3_t;

#define PD_CALL_TIPS_TIP_NEW_V3 2
typedef struct {
    pd_Bytes_t reason;
    pd_AccountId_V3_t who;
    pd_CompactBalanceOf_t tip_value;
} pd_tips_tip_new_V3_t;

#define PD_CALL_TIPS_TIP_V3 3
typedef struct {
    pd_Hash_t hash;
    pd_CompactBalanceOf_t tip_value;
} pd_tips_tip_V3_t;

#define PD_CALL_TIPS_CLOSE_TIP_V3 4
typedef struct {
    pd_Hash_t hash;
} pd_tips_close_tip_V3_t;

#define PD_CALL_TIPS_SLASH_TIP_V3 5
typedef struct {
    pd_Hash_t hash;
} pd_tips_slash_tip_V3_t;

typedef union {
    pd_system_fill_block_V3_t system_fill_block_V3;
    pd_system_remark_V3_t system_remark_V3;
    pd_system_set_heap_pages_V3_t system_set_heap_pages_V3;
    pd_system_set_code_V3_t system_set_code_V3;
    pd_system_set_code_without_checks_V3_t system_set_code_without_checks_V3;
    pd_system_set_changes_trie_config_V3_t system_set_changes_trie_config_V3;
    pd_system_set_storage_V3_t system_set_storage_V3;
    pd_system_kill_storage_V3_t system_kill_storage_V3;
    pd_system_kill_prefix_V3_t system_kill_prefix_V3;
    pd_babe_report_equivocation_V3_t babe_report_equivocation_V3;
    pd_babe_report_equivocation_unsigned_V3_t babe_report_equivocation_unsigned_V3;
    pd_timestamp_set_V3_t timestamp_set_V3;
    pd_indices_claim_V3_t indices_claim_V3;
    pd_indices_transfer_V3_t indices_transfer_V3;
    pd_indices_free_V3_t indices_free_V3;
    pd_indices_force_transfer_V3_t indices_force_transfer_V3;
    pd_indices_freeze_V3_t indices_freeze_V3;
    pd_balances_transfer_V3_t balances_transfer_V3;
    pd_balances_set_balance_V3_t balances_set_balance_V3;
    pd_balances_force_transfer_V3_t balances_force_transfer_V3;
    pd_balances_transfer_keep_alive_V3_t balances_transfer_keep_alive_V3;
    pd_authorship_set_uncles_V3_t authorship_set_uncles_V3;
    pd_staking_bond_V3_t staking_bond_V3;
    pd_staking_bond_extra_V3_t staking_bond_extra_V3;
    pd_staking_unbond_V3_t staking_unbond_V3;
    pd_staking_withdraw_unbonded_V3_t staking_withdraw_unbonded_V3;
    pd_staking_validate_V3_t staking_validate_V3;
    pd_staking_nominate_V3_t staking_nominate_V3;
    pd_staking_chill_V3_t staking_chill_V3;
    pd_staking_set_payee_V3_t staking_set_payee_V3;
    pd_staking_set_controller_V3_t staking_set_controller_V3;
    pd_staking_set_validator_count_V3_t staking_set_validator_count_V3;
    pd_staking_increase_validator_count_V3_t staking_increase_validator_count_V3;
    pd_staking_scale_validator_count_V3_t staking_scale_validator_count_V3;
    pd_staking_force_no_eras_V3_t staking_force_no_eras_V3;
    pd_staking_force_new_era_V3_t staking_force_new_era_V3;
    pd_staking_set_invulnerables_V3_t staking_set_invulnerables_V3;
    pd_staking_force_unstake_V3_t staking_force_unstake_V3;
    pd_staking_force_new_era_always_V3_t staking_force_new_era_always_V3;
    pd_staking_cancel_deferred_slash_V3_t staking_cancel_deferred_slash_V3;
    pd_staking_payout_stakers_V3_t staking_payout_stakers_V3;
    pd_staking_rebond_V3_t staking_rebond_V3;
    pd_staking_set_history_depth_V3_t staking_set_history_depth_V3;
    pd_staking_reap_stash_V3_t staking_reap_stash_V3;
    pd_staking_submit_election_solution_V3_t staking_submit_election_solution_V3;
    pd_staking_submit_election_solution_unsigned_V3_t staking_submit_election_solution_unsigned_V3;
    pd_staking_kick_V3_t staking_kick_V3;
    pd_session_set_keys_V3_t session_set_keys_V3;
    pd_session_purge_keys_V3_t session_purge_keys_V3;
    pd_grandpa_report_equivocation_V3_t grandpa_report_equivocation_V3;
    pd_grandpa_report_equivocation_unsigned_V3_t grandpa_report_equivocation_unsigned_V3;
    pd_grandpa_note_stalled_V3_t grandpa_note_stalled_V3;
    pd_imonline_heartbeat_V3_t imonline_heartbeat_V3;
    pd_democracy_propose_V3_t democracy_propose_V3;
    pd_democracy_second_V3_t democracy_second_V3;
    pd_democracy_vote_V3_t democracy_vote_V3;
    pd_democracy_emergency_cancel_V3_t democracy_emergency_cancel_V3;
    pd_democracy_external_propose_V3_t democracy_external_propose_V3;
    pd_democracy_external_propose_majority_V3_t democracy_external_propose_majority_V3;
    pd_democracy_external_propose_default_V3_t democracy_external_propose_default_V3;
    pd_democracy_fast_track_V3_t democracy_fast_track_V3;
    pd_democracy_veto_external_V3_t democracy_veto_external_V3;
    pd_democracy_cancel_referendum_V3_t democracy_cancel_referendum_V3;
    pd_democracy_cancel_queued_V3_t democracy_cancel_queued_V3;
    pd_democracy_delegate_V3_t democracy_delegate_V3;
    pd_democracy_undelegate_V3_t democracy_undelegate_V3;
    pd_democracy_clear_public_proposals_V3_t democracy_clear_public_proposals_V3;
    pd_democracy_note_preimage_V3_t democracy_note_preimage_V3;
    pd_democracy_note_preimage_operational_V3_t democracy_note_preimage_operational_V3;
    pd_democracy_note_imminent_preimage_V3_t democracy_note_imminent_preimage_V3;
    pd_democracy_note_imminent_preimage_operational_V3_t democracy_note_imminent_preimage_operational_V3;
    pd_democracy_reap_preimage_V3_t democracy_reap_preimage_V3;
    pd_democracy_unlock_V3_t democracy_unlock_V3;
    pd_democracy_remove_vote_V3_t democracy_remove_vote_V3;
    pd_democracy_remove_other_vote_V3_t democracy_remove_other_vote_V3;
    pd_democracy_enact_proposal_V3_t democracy_enact_proposal_V3;
    pd_democracy_blacklist_V3_t democracy_blacklist_V3;
    pd_democracy_cancel_proposal_V3_t democracy_cancel_proposal_V3;
    pd_council_set_members_V3_t council_set_members_V3;
    pd_council_execute_V3_t council_execute_V3;
    pd_council_propose_V3_t council_propose_V3;
    pd_council_vote_V3_t council_vote_V3;
    pd_council_close_V3_t council_close_V3;
    pd_council_disapprove_proposal_V3_t council_disapprove_proposal_V3;
    pd_technicalcommittee_set_members_V3_t technicalcommittee_set_members_V3;
    pd_technicalcommittee_execute_V3_t technicalcommittee_execute_V3;
    pd_technicalcommittee_propose_V3_t technicalcommittee_propose_V3;
    pd_technicalcommittee_vote_V3_t technicalcommittee_vote_V3;
    pd_technicalcommittee_close_V3_t technicalcommittee_close_V3;
    pd_technicalcommittee_disapprove_proposal_V3_t technicalcommittee_disapprove_proposal_V3;
    pd_electionsphragmen_vote_V3_t electionsphragmen_vote_V3;
    pd_electionsphragmen_remove_voter_V3_t electionsphragmen_remove_voter_V3;
    pd_electionsphragmen_submit_candidacy_V3_t electionsphragmen_submit_candidacy_V3;
    pd_electionsphragmen_renounce_candidacy_V3_t electionsphragmen_renounce_candidacy_V3;
    pd_electionsphragmen_remove_member_V3_t electionsphragmen_remove_member_V3;
    pd_electionsphragmen_clean_defunct_voters_V3_t electionsphragmen_clean_defunct_voters_V3;
    pd_technicalmembership_add_member_V3_t technicalmembership_add_member_V3;
    pd_technicalmembership_remove_member_V3_t technicalmembership_remove_member_V3;
    pd_technicalmembership_swap_member_V3_t technicalmembership_swap_member_V3;
    pd_technicalmembership_reset_members_V3_t technicalmembership_reset_members_V3;
    pd_technicalmembership_change_key_V3_t technicalmembership_change_key_V3;
    pd_technicalmembership_set_prime_V3_t technicalmembership_set_prime_V3;
    pd_technicalmembership_clear_prime_V3_t technicalmembership_clear_prime_V3;
    pd_treasury_propose_spend_V3_t treasury_propose_spend_V3;
    pd_treasury_reject_proposal_V3_t treasury_reject_proposal_V3;
    pd_treasury_approve_proposal_V3_t treasury_approve_proposal_V3;
    pd_claims_claim_V3_t claims_claim_V3;
    pd_claims_mint_claim_V3_t claims_mint_claim_V3;
    pd_claims_claim_attest_V3_t claims_claim_attest_V3;
    pd_claims_attest_V3_t claims_attest_V3;
    pd_claims_move_claim_V3_t claims_move_claim_V3;
    pd_utility_batch_V3_t utility_batch_V3;
    pd_utility_as_derivative_V3_t utility_as_derivative_V3;
    pd_utility_batch_all_V3_t utility_batch_all_V3;
    pd_identity_add_registrar_V3_t identity_add_registrar_V3;
    pd_identity_set_identity_V3_t identity_set_identity_V3;
    pd_identity_set_subs_V3_t identity_set_subs_V3;
    pd_identity_clear_identity_V3_t identity_clear_identity_V3;
    pd_identity_request_judgement_V3_t identity_request_judgement_V3;
    pd_identity_cancel_request_V3_t identity_cancel_request_V3;
    pd_identity_set_fee_V3_t identity_set_fee_V3;
    pd_identity_set_account_id_V3_t identity_set_account_id_V3;
    pd_identity_set_fields_V3_t identity_set_fields_V3;
    pd_identity_provide_judgement_V3_t identity_provide_judgement_V3;
    pd_identity_kill_identity_V3_t identity_kill_identity_V3;
    pd_identity_add_sub_V3_t identity_add_sub_V3;
    pd_identity_rename_sub_V3_t identity_rename_sub_V3;
    pd_identity_remove_sub_V3_t identity_remove_sub_V3;
    pd_identity_quit_sub_V3_t identity_quit_sub_V3;
    pd_society_bid_V3_t society_bid_V3;
    pd_society_unbid_V3_t society_unbid_V3;
    pd_society_vouch_V3_t society_vouch_V3;
    pd_society_unvouch_V3_t society_unvouch_V3;
    pd_society_vote_V3_t society_vote_V3;
    pd_society_defender_vote_V3_t society_defender_vote_V3;
    pd_society_payout_V3_t society_payout_V3;
    pd_society_found_V3_t society_found_V3;
    pd_society_unfound_V3_t society_unfound_V3;
    pd_society_judge_suspended_member_V3_t society_judge_suspended_member_V3;
    pd_society_judge_suspended_candidate_V3_t society_judge_suspended_candidate_V3;
    pd_society_set_max_members_V3_t society_set_max_members_V3;
    pd_recovery_as_recovered_V3_t recovery_as_recovered_V3;
    pd_recovery_set_recovered_V3_t recovery_set_recovered_V3;
    pd_recovery_create_recovery_V3_t recovery_create_recovery_V3;
    pd_recovery_initiate_recovery_V3_t recovery_initiate_recovery_V3;
    pd_recovery_vouch_recovery_V3_t recovery_vouch_recovery_V3;
    pd_recovery_claim_recovery_V3_t recovery_claim_recovery_V3;
    pd_recovery_close_recovery_V3_t recovery_close_recovery_V3;
    pd_recovery_remove_recovery_V3_t recovery_remove_recovery_V3;
    pd_recovery_cancel_recovered_V3_t recovery_cancel_recovered_V3;
    pd_vesting_vest_V3_t vesting_vest_V3;
    pd_vesting_vest_other_V3_t vesting_vest_other_V3;
    pd_vesting_vested_transfer_V3_t vesting_vested_transfer_V3;
    pd_vesting_force_vested_transfer_V3_t vesting_force_vested_transfer_V3;
    pd_scheduler_schedule_V3_t scheduler_schedule_V3;
    pd_scheduler_cancel_V3_t scheduler_cancel_V3;
    pd_scheduler_schedule_named_V3_t scheduler_schedule_named_V3;
    pd_scheduler_cancel_named_V3_t scheduler_cancel_named_V3;
    pd_scheduler_schedule_after_V3_t scheduler_schedule_after_V3;
    pd_scheduler_schedule_named_after_V3_t scheduler_schedule_named_after_V3;
    pd_proxy_proxy_V3_t proxy_proxy_V3;
    pd_proxy_add_proxy_V3_t proxy_add_proxy_V3;
    pd_proxy_remove_proxy_V3_t proxy_remove_proxy_V3;
    pd_proxy_remove_proxies_V3_t proxy_remove_proxies_V3;
    pd_proxy_anonymous_V3_t proxy_anonymous_V3;
    pd_proxy_kill_anonymous_V3_t proxy_kill_anonymous_V3;
    pd_proxy_announce_V3_t proxy_announce_V3;
    pd_proxy_remove_announcement_V3_t proxy_remove_announcement_V3;
    pd_proxy_reject_announcement_V3_t proxy_reject_announcement_V3;
    pd_proxy_proxy_announced_V3_t proxy_proxy_announced_V3;
    pd_multisig_as_multi_threshold_1_V3_t multisig_as_multi_threshold_1_V3;
    pd_multisig_as_multi_V3_t multisig_as_multi_V3;
    pd_multisig_approve_as_multi_V3_t multisig_approve_as_multi_V3;
    pd_multisig_cancel_as_multi_V3_t multisig_cancel_as_multi_V3;
    pd_bounties_propose_bounty_V3_t bounties_propose_bounty_V3;
    pd_bounties_approve_bounty_V3_t bounties_approve_bounty_V3;
    pd_bounties_propose_curator_V3_t bounties_propose_curator_V3;
    pd_bounties_unassign_curator_V3_t bounties_unassign_curator_V3;
    pd_bounties_accept_curator_V3_t bounties_accept_curator_V3;
    pd_bounties_award_bounty_V3_t bounties_award_bounty_V3;
    pd_bounties_claim_bounty_V3_t bounties_claim_bounty_V3;
    pd_bounties_close_bounty_V3_t bounties_close_bounty_V3;
    pd_bounties_extend_bounty_expiry_V3_t bounties_extend_bounty_expiry_V3;
    pd_tips_report_awesome_V3_t tips_report_awesome_V3;
    pd_tips_retract_tip_V3_t tips_retract_tip_V3;
    pd_tips_tip_new_V3_t tips_tip_new_V3;
    pd_tips_tip_V3_t tips_tip_V3;
    pd_tips_close_tip_V3_t tips_close_tip_V3;
    pd_tips_slash_tip_V3_t tips_slash_tip_V3;
} pd_MethodBasic_V3_t;

typedef union {
} pd_MethodNested_V3_t;

typedef union {
    pd_MethodBasic_V3_t basic;
    pd_MethodNested_V3_t nested;
} pd_Method_V3_t;

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop
