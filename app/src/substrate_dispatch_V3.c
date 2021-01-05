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
#include "substrate_dispatch_V3.h"

#include "zxmacros.h"
#include <stdint.h>

__Z_INLINE parser_error_t _readMethod_system_fill_block_V3(
    parser_context_t* c, pd_system_fill_block_V3_t* m)
{
    CHECK_ERROR(_readPerbill_V3(c, &m->_ratio))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_V3(
    parser_context_t* c, pd_system_remark_V3_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->_remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_heap_pages_V3(
    parser_context_t* c, pd_system_set_heap_pages_V3_t* m)
{
    CHECK_ERROR(_readu64(c, &m->pages))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_V3(
    parser_context_t* c, pd_system_set_code_V3_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_without_checks_V3(
    parser_context_t* c, pd_system_set_code_without_checks_V3_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_changes_trie_config_V3(
    parser_context_t* c, pd_system_set_changes_trie_config_V3_t* m)
{
    CHECK_ERROR(_readOptionChangesTrieConfiguration_V3(c, &m->changes_trie_config))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_storage_V3(
    parser_context_t* c, pd_system_set_storage_V3_t* m)
{
    CHECK_ERROR(_readVecKeyValue_V3(c, &m->items))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_kill_storage_V3(
    parser_context_t* c, pd_system_kill_storage_V3_t* m)
{
    CHECK_ERROR(_readVecKey_V3(c, &m->keys))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_kill_prefix_V3(
    parser_context_t* c, pd_system_kill_prefix_V3_t* m)
{
    CHECK_ERROR(_readKey_V3(c, &m->prefix))
    CHECK_ERROR(_readu32(c, &m->_subkeys))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_suicide_V3(
    parser_context_t* c, pd_system_suicide_V3_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_babe_report_equivocation_V3(
    parser_context_t* c, pd_babe_report_equivocation_V3_t* m)
{
    CHECK_ERROR(_readEquivocationProof_V3(c, &m->equivocation_proof))
    CHECK_ERROR(_readKeyOwnerProof_V3(c, &m->key_owner_proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_babe_report_equivocation_unsigned_V3(
    parser_context_t* c, pd_babe_report_equivocation_unsigned_V3_t* m)
{
    CHECK_ERROR(_readEquivocationProof_V3(c, &m->equivocation_proof))
    CHECK_ERROR(_readKeyOwnerProof_V3(c, &m->key_owner_proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_timestamp_set_V3(
    parser_context_t* c, pd_timestamp_set_V3_t* m)
{
    CHECK_ERROR(_readCompactMoment_V3(c, &m->now))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_claim_V3(
    parser_context_t* c, pd_indices_claim_V3_t* m)
{
    CHECK_ERROR(_readAccountIndex_V3(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_transfer_V3(
    parser_context_t* c, pd_indices_transfer_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->new_))
    CHECK_ERROR(_readAccountIndex_V3(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_free_V3(
    parser_context_t* c, pd_indices_free_V3_t* m)
{
    CHECK_ERROR(_readAccountIndex_V3(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_force_transfer_V3(
    parser_context_t* c, pd_indices_force_transfer_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->new_))
    CHECK_ERROR(_readAccountIndex_V3(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->freeze))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_freeze_V3(
    parser_context_t* c, pd_indices_freeze_V3_t* m)
{
    CHECK_ERROR(_readAccountIndex_V3(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_V3(
    parser_context_t* c, pd_balances_transfer_V3_t* m)
{
    CHECK_ERROR(_readLookupSource(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_set_balance_V3(
    parser_context_t* c, pd_balances_set_balance_V3_t* m)
{
    CHECK_ERROR(_readLookupSource(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->new_free))
    CHECK_ERROR(_readCompactBalance(c, &m->new_reserved))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_transfer_V3(
    parser_context_t* c, pd_balances_force_transfer_V3_t* m)
{
    CHECK_ERROR(_readLookupSource(c, &m->source))
    CHECK_ERROR(_readLookupSource(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_keep_alive_V3(
    parser_context_t* c, pd_balances_transfer_keep_alive_V3_t* m)
{
    CHECK_ERROR(_readLookupSource(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_authorship_set_uncles_V3(
    parser_context_t* c, pd_authorship_set_uncles_V3_t* m)
{
    CHECK_ERROR(_readVecHeader(c, &m->new_uncles))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_V3(
    parser_context_t* c, pd_staking_bond_V3_t* m)
{
    CHECK_ERROR(_readLookupSource(c, &m->controller))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    CHECK_ERROR(_readRewardDestination_V3(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_extra_V3(
    parser_context_t* c, pd_staking_bond_extra_V3_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->max_additional))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_unbond_V3(
    parser_context_t* c, pd_staking_unbond_V3_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_withdraw_unbonded_V3(
    parser_context_t* c, pd_staking_withdraw_unbonded_V3_t* m)
{
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_validate_V3(
    parser_context_t* c, pd_staking_validate_V3_t* m)
{
    CHECK_ERROR(_readValidatorPrefs_V3(c, &m->prefs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_nominate_V3(
    parser_context_t* c, pd_staking_nominate_V3_t* m)
{
    CHECK_ERROR(_readVecLookupSource(c, &m->targets))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill_V3(
    parser_context_t* c, pd_staking_chill_V3_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_payee_V3(
    parser_context_t* c, pd_staking_set_payee_V3_t* m)
{
    CHECK_ERROR(_readRewardDestination_V3(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_controller_V3(
    parser_context_t* c, pd_staking_set_controller_V3_t* m)
{
    CHECK_ERROR(_readLookupSource(c, &m->controller))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_validator_count_V3(
    parser_context_t* c, pd_staking_set_validator_count_V3_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_increase_validator_count_V3(
    parser_context_t* c, pd_staking_increase_validator_count_V3_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->additional))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_scale_validator_count_V3(
    parser_context_t* c, pd_staking_scale_validator_count_V3_t* m)
{
    CHECK_ERROR(_readPercent_V3(c, &m->factor))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_no_eras_V3(
    parser_context_t* c, pd_staking_force_no_eras_V3_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_V3(
    parser_context_t* c, pd_staking_force_new_era_V3_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_invulnerables_V3(
    parser_context_t* c, pd_staking_set_invulnerables_V3_t* m)
{
    CHECK_ERROR(_readVecAccountId_V3(c, &m->invulnerables))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_unstake_V3(
    parser_context_t* c, pd_staking_force_unstake_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_always_V3(
    parser_context_t* c, pd_staking_force_new_era_always_V3_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_cancel_deferred_slash_V3(
    parser_context_t* c, pd_staking_cancel_deferred_slash_V3_t* m)
{
    CHECK_ERROR(_readEraIndex_V3(c, &m->era))
    CHECK_ERROR(_readVecu32(c, &m->slash_indices))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_payout_stakers_V3(
    parser_context_t* c, pd_staking_payout_stakers_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->validator_stash))
    CHECK_ERROR(_readEraIndex_V3(c, &m->era))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_rebond_V3(
    parser_context_t* c, pd_staking_rebond_V3_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_history_depth_V3(
    parser_context_t* c, pd_staking_set_history_depth_V3_t* m)
{
    CHECK_ERROR(_readCompactEraIndex_V3(c, &m->new_history_depth))
    CHECK_ERROR(_readCompactu32(c, &m->_era_items_deleted))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_reap_stash_V3(
    parser_context_t* c, pd_staking_reap_stash_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_submit_election_solution_V3(
    parser_context_t* c, pd_staking_submit_election_solution_V3_t* m)
{
    CHECK_ERROR(_readVecValidatorIndex_V3(c, &m->winners))
    CHECK_ERROR(_readCompactAssignments_V3(c, &m->compact))
    CHECK_ERROR(_readElectionScore_V3(c, &m->score))
    CHECK_ERROR(_readEraIndex_V3(c, &m->era))
    CHECK_ERROR(_readElectionSize_V3(c, &m->size))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_submit_election_solution_unsigned_V3(
    parser_context_t* c, pd_staking_submit_election_solution_unsigned_V3_t* m)
{
    CHECK_ERROR(_readVecValidatorIndex_V3(c, &m->winners))
    CHECK_ERROR(_readCompactAssignments_V3(c, &m->compact))
    CHECK_ERROR(_readElectionScore_V3(c, &m->score))
    CHECK_ERROR(_readEraIndex_V3(c, &m->era))
    CHECK_ERROR(_readElectionSize_V3(c, &m->size))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_set_keys_V3(
    parser_context_t* c, pd_session_set_keys_V3_t* m)
{
    CHECK_ERROR(_readKeys_V3(c, &m->keys))
    CHECK_ERROR(_readBytes(c, &m->proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_purge_keys_V3(
    parser_context_t* c, pd_session_purge_keys_V3_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_grandpa_report_equivocation_V3(
    parser_context_t* c, pd_grandpa_report_equivocation_V3_t* m)
{
    CHECK_ERROR(_readEquivocationProof_V3(c, &m->equivocation_proof))
    CHECK_ERROR(_readKeyOwnerProof_V3(c, &m->key_owner_proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_grandpa_report_equivocation_unsigned_V3(
    parser_context_t* c, pd_grandpa_report_equivocation_unsigned_V3_t* m)
{
    CHECK_ERROR(_readEquivocationProof_V3(c, &m->equivocation_proof))
    CHECK_ERROR(_readKeyOwnerProof_V3(c, &m->key_owner_proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_grandpa_note_stalled_V3(
    parser_context_t* c, pd_grandpa_note_stalled_V3_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    CHECK_ERROR(_readBlockNumber(c, &m->best_finalized_block_number))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_imonline_heartbeat_V3(
    parser_context_t* c, pd_imonline_heartbeat_V3_t* m)
{
    CHECK_ERROR(_readHeartbeat(c, &m->heartbeat))
    CHECK_ERROR(_readSignature_V3(c, &m->_signature))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_propose_V3(
    parser_context_t* c, pd_democracy_propose_V3_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_second_V3(
    parser_context_t* c, pd_democracy_second_V3_t* m)
{
    CHECK_ERROR(_readCompactPropIndex_V3(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->seconds_upper_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_vote_V3(
    parser_context_t* c, pd_democracy_vote_V3_t* m)
{
    CHECK_ERROR(_readCompactReferendumIndex_V3(c, &m->ref_index))
    CHECK_ERROR(_readAccountVote_V3(c, &m->vote))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_emergency_cancel_V3(
    parser_context_t* c, pd_democracy_emergency_cancel_V3_t* m)
{
    CHECK_ERROR(_readReferendumIndex_V3(c, &m->ref_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_external_propose_V3(
    parser_context_t* c, pd_democracy_external_propose_V3_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_external_propose_majority_V3(
    parser_context_t* c, pd_democracy_external_propose_majority_V3_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_external_propose_default_V3(
    parser_context_t* c, pd_democracy_external_propose_default_V3_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_fast_track_V3(
    parser_context_t* c, pd_democracy_fast_track_V3_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readBlockNumber(c, &m->voting_period))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_veto_external_V3(
    parser_context_t* c, pd_democracy_veto_external_V3_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_cancel_referendum_V3(
    parser_context_t* c, pd_democracy_cancel_referendum_V3_t* m)
{
    CHECK_ERROR(_readCompactReferendumIndex_V3(c, &m->ref_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_cancel_queued_V3(
    parser_context_t* c, pd_democracy_cancel_queued_V3_t* m)
{
    CHECK_ERROR(_readReferendumIndex_V3(c, &m->which))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_delegate_V3(
    parser_context_t* c, pd_democracy_delegate_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->to))
    CHECK_ERROR(_readConviction_V3(c, &m->conviction))
    CHECK_ERROR(_readBalanceOf_V3(c, &m->balance))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_undelegate_V3(
    parser_context_t* c, pd_democracy_undelegate_V3_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_clear_public_proposals_V3(
    parser_context_t* c, pd_democracy_clear_public_proposals_V3_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_preimage_V3(
    parser_context_t* c, pd_democracy_note_preimage_V3_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_preimage_operational_V3(
    parser_context_t* c, pd_democracy_note_preimage_operational_V3_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_imminent_preimage_V3(
    parser_context_t* c, pd_democracy_note_imminent_preimage_V3_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_imminent_preimage_operational_V3(
    parser_context_t* c, pd_democracy_note_imminent_preimage_operational_V3_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_reap_preimage_V3(
    parser_context_t* c, pd_democracy_reap_preimage_V3_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactu32(c, &m->proposal_len_upper_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_unlock_V3(
    parser_context_t* c, pd_democracy_unlock_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_remove_vote_V3(
    parser_context_t* c, pd_democracy_remove_vote_V3_t* m)
{
    CHECK_ERROR(_readReferendumIndex_V3(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_remove_other_vote_V3(
    parser_context_t* c, pd_democracy_remove_other_vote_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->target))
    CHECK_ERROR(_readReferendumIndex_V3(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_enact_proposal_V3(
    parser_context_t* c, pd_democracy_enact_proposal_V3_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readReferendumIndex_V3(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_blacklist_V3(
    parser_context_t* c, pd_democracy_blacklist_V3_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readOptionReferendumIndex_V3(c, &m->maybe_ref_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_cancel_proposal_V3(
    parser_context_t* c, pd_democracy_cancel_proposal_V3_t* m)
{
    CHECK_ERROR(_readCompactPropIndex_V3(c, &m->prop_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_set_members_V3(
    parser_context_t* c, pd_council_set_members_V3_t* m)
{
    CHECK_ERROR(_readVecAccountId_V3(c, &m->new_members))
    CHECK_ERROR(_readOptionAccountId_V3(c, &m->prime))
    CHECK_ERROR(_readMemberCount_V3(c, &m->old_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_execute_V3(
    parser_context_t* c, pd_council_execute_V3_t* m)
{
    CHECK_ERROR(_readProposal_V3(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_propose_V3(
    parser_context_t* c, pd_council_propose_V3_t* m)
{
    CHECK_ERROR(_readCompactMemberCount_V3(c, &m->threshold))
    CHECK_ERROR(_readProposal_V3(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_vote_V3(
    parser_context_t* c, pd_council_vote_V3_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readCompactProposalIndex_V3(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_close_V3(
    parser_context_t* c, pd_council_close_V3_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactProposalIndex_V3(c, &m->index))
    CHECK_ERROR(_readCompactWeight_V3(c, &m->proposal_weight_bound))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_disapprove_proposal_V3(
    parser_context_t* c, pd_council_disapprove_proposal_V3_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_set_members_V3(
    parser_context_t* c, pd_technicalcommittee_set_members_V3_t* m)
{
    CHECK_ERROR(_readVecAccountId_V3(c, &m->new_members))
    CHECK_ERROR(_readOptionAccountId_V3(c, &m->prime))
    CHECK_ERROR(_readMemberCount_V3(c, &m->old_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_execute_V3(
    parser_context_t* c, pd_technicalcommittee_execute_V3_t* m)
{
    CHECK_ERROR(_readProposal_V3(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_propose_V3(
    parser_context_t* c, pd_technicalcommittee_propose_V3_t* m)
{
    CHECK_ERROR(_readCompactMemberCount_V3(c, &m->threshold))
    CHECK_ERROR(_readProposal_V3(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_vote_V3(
    parser_context_t* c, pd_technicalcommittee_vote_V3_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readCompactProposalIndex_V3(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_close_V3(
    parser_context_t* c, pd_technicalcommittee_close_V3_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactProposalIndex_V3(c, &m->index))
    CHECK_ERROR(_readCompactWeight_V3(c, &m->proposal_weight_bound))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_disapprove_proposal_V3(
    parser_context_t* c, pd_technicalcommittee_disapprove_proposal_V3_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_electionsphragmen_vote_V3(
    parser_context_t* c, pd_electionsphragmen_vote_V3_t* m)
{
    CHECK_ERROR(_readVecAccountId_V3(c, &m->votes))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_electionsphragmen_remove_voter_V3(
    parser_context_t* c, pd_electionsphragmen_remove_voter_V3_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_electionsphragmen_report_defunct_voter_V3(
    parser_context_t* c, pd_electionsphragmen_report_defunct_voter_V3_t* m)
{
    CHECK_ERROR(_readDefunctVoter_V3(c, &m->defunct))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_electionsphragmen_submit_candidacy_V3(
    parser_context_t* c, pd_electionsphragmen_submit_candidacy_V3_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->candidate_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_electionsphragmen_renounce_candidacy_V3(
    parser_context_t* c, pd_electionsphragmen_renounce_candidacy_V3_t* m)
{
    CHECK_ERROR(_readRenouncing_V3(c, &m->renouncing))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_electionsphragmen_remove_member_V3(
    parser_context_t* c, pd_electionsphragmen_remove_member_V3_t* m)
{
    CHECK_ERROR(_readLookupSource(c, &m->who))
    CHECK_ERROR(_readbool(c, &m->has_replacement))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_add_member_V3(
    parser_context_t* c, pd_technicalmembership_add_member_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_remove_member_V3(
    parser_context_t* c, pd_technicalmembership_remove_member_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_swap_member_V3(
    parser_context_t* c, pd_technicalmembership_swap_member_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->remove))
    CHECK_ERROR(_readAccountId_V3(c, &m->add))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_reset_members_V3(
    parser_context_t* c, pd_technicalmembership_reset_members_V3_t* m)
{
    CHECK_ERROR(_readVecAccountId_V3(c, &m->members))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_change_key_V3(
    parser_context_t* c, pd_technicalmembership_change_key_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_set_prime_V3(
    parser_context_t* c, pd_technicalmembership_set_prime_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_clear_prime_V3(
    parser_context_t* c, pd_technicalmembership_clear_prime_V3_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_propose_spend_V3(
    parser_context_t* c, pd_treasury_propose_spend_V3_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    CHECK_ERROR(_readLookupSource(c, &m->beneficiary))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_reject_proposal_V3(
    parser_context_t* c, pd_treasury_reject_proposal_V3_t* m)
{
    CHECK_ERROR(_readCompactProposalIndex_V3(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_approve_proposal_V3(
    parser_context_t* c, pd_treasury_approve_proposal_V3_t* m)
{
    CHECK_ERROR(_readCompactProposalIndex_V3(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_report_awesome_V3(
    parser_context_t* c, pd_treasury_report_awesome_V3_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->reason))
    CHECK_ERROR(_readAccountId_V3(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_retract_tip_V3(
    parser_context_t* c, pd_treasury_retract_tip_V3_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_tip_new_V3(
    parser_context_t* c, pd_treasury_tip_new_V3_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->reason))
    CHECK_ERROR(_readAccountId_V3(c, &m->who))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->tip_value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_tip_V3(
    parser_context_t* c, pd_treasury_tip_V3_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->tip_value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_close_tip_V3(
    parser_context_t* c, pd_treasury_close_tip_V3_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_propose_bounty_V3(
    parser_context_t* c, pd_treasury_propose_bounty_V3_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    CHECK_ERROR(_readBytes(c, &m->description))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_approve_bounty_V3(
    parser_context_t* c, pd_treasury_approve_bounty_V3_t* m)
{
    CHECK_ERROR(_readCompactProposalIndex_V3(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_propose_curator_V3(
    parser_context_t* c, pd_treasury_propose_curator_V3_t* m)
{
    CHECK_ERROR(_readCompactProposalIndex_V3(c, &m->bounty_id))
    CHECK_ERROR(_readLookupSource(c, &m->curator))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_unassign_curator_V3(
    parser_context_t* c, pd_treasury_unassign_curator_V3_t* m)
{
    CHECK_ERROR(_readCompactProposalIndex_V3(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_accept_curator_V3(
    parser_context_t* c, pd_treasury_accept_curator_V3_t* m)
{
    CHECK_ERROR(_readCompactProposalIndex_V3(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_award_bounty_V3(
    parser_context_t* c, pd_treasury_award_bounty_V3_t* m)
{
    CHECK_ERROR(_readCompactProposalIndex_V3(c, &m->bounty_id))
    CHECK_ERROR(_readLookupSource(c, &m->beneficiary))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_claim_bounty_V3(
    parser_context_t* c, pd_treasury_claim_bounty_V3_t* m)
{
    CHECK_ERROR(_readCompactBountyIndex_V3(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_close_bounty_V3(
    parser_context_t* c, pd_treasury_close_bounty_V3_t* m)
{
    CHECK_ERROR(_readCompactBountyIndex_V3(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_extend_bounty_expiry_V3(
    parser_context_t* c, pd_treasury_extend_bounty_expiry_V3_t* m)
{
    CHECK_ERROR(_readCompactBountyIndex_V3(c, &m->bounty_id))
    CHECK_ERROR(_readBytes(c, &m->_remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_claims_claim_V3(
    parser_context_t* c, pd_claims_claim_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->dest))
    CHECK_ERROR(_readEcdsaSignature_V3(c, &m->ethereum_signature))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_claims_mint_claim_V3(
    parser_context_t* c, pd_claims_mint_claim_V3_t* m)
{
    CHECK_ERROR(_readEthereumAddress_V3(c, &m->who))
    CHECK_ERROR(_readBalanceOf_V3(c, &m->value))
    CHECK_ERROR(_readOptionTupleBalanceOfBalanceOfBlockNumber_V3(c, &m->vesting_schedule))
    CHECK_ERROR(_readOptionStatementKind_V3(c, &m->statement))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_claims_claim_attest_V3(
    parser_context_t* c, pd_claims_claim_attest_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->dest))
    CHECK_ERROR(_readEcdsaSignature_V3(c, &m->ethereum_signature))
    CHECK_ERROR(_readBytes(c, &m->statement))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_claims_attest_V3(
    parser_context_t* c, pd_claims_attest_V3_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->statement))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_claims_move_claim_V3(
    parser_context_t* c, pd_claims_move_claim_V3_t* m)
{
    CHECK_ERROR(_readEthereumAddress_V3(c, &m->old))
    CHECK_ERROR(_readEthereumAddress_V3(c, &m->new_))
    CHECK_ERROR(_readOptionAccountId_V3(c, &m->maybe_preclaim))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_V3(
    parser_context_t* c, pd_utility_batch_V3_t* m)
{
    CHECK_ERROR(_readVecCall_V3(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_as_derivative_V3(
    parser_context_t* c, pd_utility_as_derivative_V3_t* m)
{
    CHECK_ERROR(_readu16(c, &m->index))
    CHECK_ERROR(_readCall_V3(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_all_V3(
    parser_context_t* c, pd_utility_batch_all_V3_t* m)
{
    CHECK_ERROR(_readVecCall_V3(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_registrar_V3(
    parser_context_t* c, pd_identity_add_registrar_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_identity_V3(
    parser_context_t* c, pd_identity_set_identity_V3_t* m)
{
    CHECK_ERROR(_readIdentityInfo_V3(c, &m->info))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_subs_V3(
    parser_context_t* c, pd_identity_set_subs_V3_t* m)
{
    CHECK_ERROR(_readVecTupleAccountIdData_V3(c, &m->subs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_clear_identity_V3(
    parser_context_t* c, pd_identity_clear_identity_V3_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_request_judgement_V3(
    parser_context_t* c, pd_identity_request_judgement_V3_t* m)
{
    CHECK_ERROR(_readCompactRegistrarIndex_V3(c, &m->reg_index))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->max_fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_cancel_request_V3(
    parser_context_t* c, pd_identity_cancel_request_V3_t* m)
{
    CHECK_ERROR(_readRegistrarIndex_V3(c, &m->reg_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_fee_V3(
    parser_context_t* c, pd_identity_set_fee_V3_t* m)
{
    CHECK_ERROR(_readCompactRegistrarIndex_V3(c, &m->index))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_account_id_V3(
    parser_context_t* c, pd_identity_set_account_id_V3_t* m)
{
    CHECK_ERROR(_readCompactRegistrarIndex_V3(c, &m->index))
    CHECK_ERROR(_readAccountId_V3(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_fields_V3(
    parser_context_t* c, pd_identity_set_fields_V3_t* m)
{
    CHECK_ERROR(_readCompactRegistrarIndex_V3(c, &m->index))
    CHECK_ERROR(_readIdentityFields_V3(c, &m->fields))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_provide_judgement_V3(
    parser_context_t* c, pd_identity_provide_judgement_V3_t* m)
{
    CHECK_ERROR(_readCompactRegistrarIndex_V3(c, &m->reg_index))
    CHECK_ERROR(_readLookupSource(c, &m->target))
    CHECK_ERROR(_readJudgement_V3(c, &m->judgement))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_kill_identity_V3(
    parser_context_t* c, pd_identity_kill_identity_V3_t* m)
{
    CHECK_ERROR(_readLookupSource(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_sub_V3(
    parser_context_t* c, pd_identity_add_sub_V3_t* m)
{
    CHECK_ERROR(_readLookupSource(c, &m->sub))
    CHECK_ERROR(_readData(c, &m->data))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_rename_sub_V3(
    parser_context_t* c, pd_identity_rename_sub_V3_t* m)
{
    CHECK_ERROR(_readLookupSource(c, &m->sub))
    CHECK_ERROR(_readData(c, &m->data))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_remove_sub_V3(
    parser_context_t* c, pd_identity_remove_sub_V3_t* m)
{
    CHECK_ERROR(_readLookupSource(c, &m->sub))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_quit_sub_V3(
    parser_context_t* c, pd_identity_quit_sub_V3_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_bid_V3(
    parser_context_t* c, pd_society_bid_V3_t* m)
{
    CHECK_ERROR(_readBalanceOf_V3(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_unbid_V3(
    parser_context_t* c, pd_society_unbid_V3_t* m)
{
    CHECK_ERROR(_readu32(c, &m->pos))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_vouch_V3(
    parser_context_t* c, pd_society_vouch_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->who))
    CHECK_ERROR(_readBalanceOf_V3(c, &m->value))
    CHECK_ERROR(_readBalanceOf_V3(c, &m->tip))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_unvouch_V3(
    parser_context_t* c, pd_society_unvouch_V3_t* m)
{
    CHECK_ERROR(_readu32(c, &m->pos))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_vote_V3(
    parser_context_t* c, pd_society_vote_V3_t* m)
{
    CHECK_ERROR(_readLookupSource(c, &m->candidate))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_defender_vote_V3(
    parser_context_t* c, pd_society_defender_vote_V3_t* m)
{
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_payout_V3(
    parser_context_t* c, pd_society_payout_V3_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_found_V3(
    parser_context_t* c, pd_society_found_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->founder))
    CHECK_ERROR(_readu32(c, &m->max_members))
    CHECK_ERROR(_readBytes(c, &m->rules))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_unfound_V3(
    parser_context_t* c, pd_society_unfound_V3_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_judge_suspended_member_V3(
    parser_context_t* c, pd_society_judge_suspended_member_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->who))
    CHECK_ERROR(_readbool(c, &m->forgive))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_judge_suspended_candidate_V3(
    parser_context_t* c, pd_society_judge_suspended_candidate_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->who))
    CHECK_ERROR(_readJudgement_V3(c, &m->judgement))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_set_max_members_V3(
    parser_context_t* c, pd_society_set_max_members_V3_t* m)
{
    CHECK_ERROR(_readu32(c, &m->max))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_as_recovered_V3(
    parser_context_t* c, pd_recovery_as_recovered_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->account))
    CHECK_ERROR(_readCall_V3(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_set_recovered_V3(
    parser_context_t* c, pd_recovery_set_recovered_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->lost))
    CHECK_ERROR(_readAccountId_V3(c, &m->rescuer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_create_recovery_V3(
    parser_context_t* c, pd_recovery_create_recovery_V3_t* m)
{
    CHECK_ERROR(_readVecAccountId_V3(c, &m->friends))
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readBlockNumber(c, &m->delay_period))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_initiate_recovery_V3(
    parser_context_t* c, pd_recovery_initiate_recovery_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_vouch_recovery_V3(
    parser_context_t* c, pd_recovery_vouch_recovery_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->lost))
    CHECK_ERROR(_readAccountId_V3(c, &m->rescuer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_claim_recovery_V3(
    parser_context_t* c, pd_recovery_claim_recovery_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_close_recovery_V3(
    parser_context_t* c, pd_recovery_close_recovery_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->rescuer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_remove_recovery_V3(
    parser_context_t* c, pd_recovery_remove_recovery_V3_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_cancel_recovered_V3(
    parser_context_t* c, pd_recovery_cancel_recovered_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vest_V3(
    parser_context_t* c, pd_vesting_vest_V3_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vest_other_V3(
    parser_context_t* c, pd_vesting_vest_other_V3_t* m)
{
    CHECK_ERROR(_readLookupSource(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vested_transfer_V3(
    parser_context_t* c, pd_vesting_vested_transfer_V3_t* m)
{
    CHECK_ERROR(_readLookupSource(c, &m->target))
    CHECK_ERROR(_readVestingInfo_V3(c, &m->schedule))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_force_vested_transfer_V3(
    parser_context_t* c, pd_vesting_force_vested_transfer_V3_t* m)
{
    CHECK_ERROR(_readLookupSource(c, &m->source))
    CHECK_ERROR(_readLookupSource(c, &m->target))
    CHECK_ERROR(_readVestingInfo_V3(c, &m->schedule))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_V3(
    parser_context_t* c, pd_scheduler_schedule_V3_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->when))
    CHECK_ERROR(_readOptionPeriod_V3(c, &m->maybe_periodic))
    CHECK_ERROR(_readPriority_V3(c, &m->priority))
    CHECK_ERROR(_readCall_V3(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_cancel_V3(
    parser_context_t* c, pd_scheduler_cancel_V3_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->when))
    CHECK_ERROR(_readu32(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_named_V3(
    parser_context_t* c, pd_scheduler_schedule_named_V3_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->id))
    CHECK_ERROR(_readBlockNumber(c, &m->when))
    CHECK_ERROR(_readOptionPeriod_V3(c, &m->maybe_periodic))
    CHECK_ERROR(_readPriority_V3(c, &m->priority))
    CHECK_ERROR(_readCall_V3(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_cancel_named_V3(
    parser_context_t* c, pd_scheduler_cancel_named_V3_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_after_V3(
    parser_context_t* c, pd_scheduler_schedule_after_V3_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->after))
    CHECK_ERROR(_readOptionPeriod_V3(c, &m->maybe_periodic))
    CHECK_ERROR(_readPriority_V3(c, &m->priority))
    CHECK_ERROR(_readCall_V3(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_named_after_V3(
    parser_context_t* c, pd_scheduler_schedule_named_after_V3_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->id))
    CHECK_ERROR(_readBlockNumber(c, &m->after))
    CHECK_ERROR(_readOptionPeriod_V3(c, &m->maybe_periodic))
    CHECK_ERROR(_readPriority_V3(c, &m->priority))
    CHECK_ERROR(_readCall_V3(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_proxy_V3(
    parser_context_t* c, pd_proxy_proxy_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->real))
    CHECK_ERROR(_readOptionProxyType_V3(c, &m->force_proxy_type))
    CHECK_ERROR(_readCall_V3(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_add_proxy_V3(
    parser_context_t* c, pd_proxy_add_proxy_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->delegate))
    CHECK_ERROR(_readProxyType_V3(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_proxy_V3(
    parser_context_t* c, pd_proxy_remove_proxy_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->delegate))
    CHECK_ERROR(_readProxyType_V3(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_proxies_V3(
    parser_context_t* c, pd_proxy_remove_proxies_V3_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_anonymous_V3(
    parser_context_t* c, pd_proxy_anonymous_V3_t* m)
{
    CHECK_ERROR(_readProxyType_V3(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    CHECK_ERROR(_readu16(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_kill_anonymous_V3(
    parser_context_t* c, pd_proxy_kill_anonymous_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->spawner))
    CHECK_ERROR(_readProxyType_V3(c, &m->proxy_type))
    CHECK_ERROR(_readu16(c, &m->index))
    CHECK_ERROR(_readCompactBlockNumber(c, &m->height))
    CHECK_ERROR(_readCompactu32(c, &m->ext_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_announce_V3(
    parser_context_t* c, pd_proxy_announce_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->real))
    CHECK_ERROR(_readCallHashOf_V3(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_announcement_V3(
    parser_context_t* c, pd_proxy_remove_announcement_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->real))
    CHECK_ERROR(_readCallHashOf_V3(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_reject_announcement_V3(
    parser_context_t* c, pd_proxy_reject_announcement_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->delegate))
    CHECK_ERROR(_readCallHashOf_V3(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_proxy_announced_V3(
    parser_context_t* c, pd_proxy_proxy_announced_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->delegate))
    CHECK_ERROR(_readAccountId_V3(c, &m->real))
    CHECK_ERROR(_readOptionProxyType_V3(c, &m->force_proxy_type))
    CHECK_ERROR(_readCall_V3(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_threshold_1_V3(
    parser_context_t* c, pd_multisig_as_multi_threshold_1_V3_t* m)
{
    CHECK_ERROR(_readVecAccountId_V3(c, &m->other_signatories))
    CHECK_ERROR(_readCall_V3(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_V3(
    parser_context_t* c, pd_multisig_as_multi_V3_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V3(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint_V3(c, &m->maybe_timepoint))
    CHECK_ERROR(_readOpaqueCall_V3(c, &m->call))
    CHECK_ERROR(_readbool(c, &m->store_call))
    CHECK_ERROR(_readWeight_V3(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_approve_as_multi_V3(
    parser_context_t* c, pd_multisig_approve_as_multi_V3_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V3(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint_V3(c, &m->maybe_timepoint))
    CHECK_ERROR(_readu8_array_32_V3(c, &m->call_hash))
    CHECK_ERROR(_readWeight_V3(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_cancel_as_multi_V3(
    parser_context_t* c, pd_multisig_cancel_as_multi_V3_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V3(c, &m->other_signatories))
    CHECK_ERROR(_readTimepoint_V3(c, &m->timepoint))
    CHECK_ERROR(_readu8_array_32_V3(c, &m->call_hash))
    return parser_ok;
}

parser_error_t _readMethodBasic_V3(
    parser_context_t* c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_MethodBasic_V3_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 0: /* module 0 call 0 */
        CHECK_ERROR(_readMethod_system_fill_block_V3(c, &method->system_fill_block_V3))
        break;
    case 1: /* module 0 call 1 */
        CHECK_ERROR(_readMethod_system_remark_V3(c, &method->system_remark_V3))
        break;
    case 2: /* module 0 call 2 */
        CHECK_ERROR(_readMethod_system_set_heap_pages_V3(c, &method->system_set_heap_pages_V3))
        break;
    case 3: /* module 0 call 3 */
        CHECK_ERROR(_readMethod_system_set_code_V3(c, &method->system_set_code_V3))
        break;
    case 4: /* module 0 call 4 */
        CHECK_ERROR(_readMethod_system_set_code_without_checks_V3(c, &method->system_set_code_without_checks_V3))
        break;
    case 5: /* module 0 call 5 */
        CHECK_ERROR(_readMethod_system_set_changes_trie_config_V3(c, &method->system_set_changes_trie_config_V3))
        break;
    case 6: /* module 0 call 6 */
        CHECK_ERROR(_readMethod_system_set_storage_V3(c, &method->system_set_storage_V3))
        break;
    case 7: /* module 0 call 7 */
        CHECK_ERROR(_readMethod_system_kill_storage_V3(c, &method->system_kill_storage_V3))
        break;
    case 8: /* module 0 call 8 */
        CHECK_ERROR(_readMethod_system_kill_prefix_V3(c, &method->system_kill_prefix_V3))
        break;
    case 9: /* module 0 call 9 */
        CHECK_ERROR(_readMethod_system_suicide_V3(c, &method->system_suicide_V3))
        break;
    case 256: /* module 1 call 0 */
        CHECK_ERROR(_readMethod_babe_report_equivocation_V3(c, &method->babe_report_equivocation_V3))
        break;
    case 257: /* module 1 call 1 */
        CHECK_ERROR(_readMethod_babe_report_equivocation_unsigned_V3(c, &method->babe_report_equivocation_unsigned_V3))
        break;
    case 512: /* module 2 call 0 */
        CHECK_ERROR(_readMethod_timestamp_set_V3(c, &method->timestamp_set_V3))
        break;
    case 768: /* module 3 call 0 */
        CHECK_ERROR(_readMethod_indices_claim_V3(c, &method->indices_claim_V3))
        break;
    case 769: /* module 3 call 1 */
        CHECK_ERROR(_readMethod_indices_transfer_V3(c, &method->indices_transfer_V3))
        break;
    case 770: /* module 3 call 2 */
        CHECK_ERROR(_readMethod_indices_free_V3(c, &method->indices_free_V3))
        break;
    case 771: /* module 3 call 3 */
        CHECK_ERROR(_readMethod_indices_force_transfer_V3(c, &method->indices_force_transfer_V3))
        break;
    case 772: /* module 3 call 4 */
        CHECK_ERROR(_readMethod_indices_freeze_V3(c, &method->indices_freeze_V3))
        break;
    case 1024: /* module 4 call 0 */
        CHECK_ERROR(_readMethod_balances_transfer_V3(c, &method->balances_transfer_V3))
        break;
    case 1025: /* module 4 call 1 */
        CHECK_ERROR(_readMethod_balances_set_balance_V3(c, &method->balances_set_balance_V3))
        break;
    case 1026: /* module 4 call 2 */
        CHECK_ERROR(_readMethod_balances_force_transfer_V3(c, &method->balances_force_transfer_V3))
        break;
    case 1027: /* module 4 call 3 */
        CHECK_ERROR(_readMethod_balances_transfer_keep_alive_V3(c, &method->balances_transfer_keep_alive_V3))
        break;
    case 1280: /* module 5 call 0 */
        CHECK_ERROR(_readMethod_authorship_set_uncles_V3(c, &method->authorship_set_uncles_V3))
        break;
    case 1536: /* module 6 call 0 */
        CHECK_ERROR(_readMethod_staking_bond_V3(c, &method->staking_bond_V3))
        break;
    case 1537: /* module 6 call 1 */
        CHECK_ERROR(_readMethod_staking_bond_extra_V3(c, &method->staking_bond_extra_V3))
        break;
    case 1538: /* module 6 call 2 */
        CHECK_ERROR(_readMethod_staking_unbond_V3(c, &method->staking_unbond_V3))
        break;
    case 1539: /* module 6 call 3 */
        CHECK_ERROR(_readMethod_staking_withdraw_unbonded_V3(c, &method->staking_withdraw_unbonded_V3))
        break;
    case 1540: /* module 6 call 4 */
        CHECK_ERROR(_readMethod_staking_validate_V3(c, &method->staking_validate_V3))
        break;
    case 1541: /* module 6 call 5 */
        CHECK_ERROR(_readMethod_staking_nominate_V3(c, &method->staking_nominate_V3))
        break;
    case 1542: /* module 6 call 6 */
        CHECK_ERROR(_readMethod_staking_chill_V3(c, &method->staking_chill_V3))
        break;
    case 1543: /* module 6 call 7 */
        CHECK_ERROR(_readMethod_staking_set_payee_V3(c, &method->staking_set_payee_V3))
        break;
    case 1544: /* module 6 call 8 */
        CHECK_ERROR(_readMethod_staking_set_controller_V3(c, &method->staking_set_controller_V3))
        break;
    case 1545: /* module 6 call 9 */
        CHECK_ERROR(_readMethod_staking_set_validator_count_V3(c, &method->staking_set_validator_count_V3))
        break;
    case 1546: /* module 6 call 10 */
        CHECK_ERROR(_readMethod_staking_increase_validator_count_V3(c, &method->staking_increase_validator_count_V3))
        break;
    case 1547: /* module 6 call 11 */
        CHECK_ERROR(_readMethod_staking_scale_validator_count_V3(c, &method->staking_scale_validator_count_V3))
        break;
    case 1548: /* module 6 call 12 */
        CHECK_ERROR(_readMethod_staking_force_no_eras_V3(c, &method->staking_force_no_eras_V3))
        break;
    case 1549: /* module 6 call 13 */
        CHECK_ERROR(_readMethod_staking_force_new_era_V3(c, &method->staking_force_new_era_V3))
        break;
    case 1550: /* module 6 call 14 */
        CHECK_ERROR(_readMethod_staking_set_invulnerables_V3(c, &method->staking_set_invulnerables_V3))
        break;
    case 1551: /* module 6 call 15 */
        CHECK_ERROR(_readMethod_staking_force_unstake_V3(c, &method->staking_force_unstake_V3))
        break;
    case 1552: /* module 6 call 16 */
        CHECK_ERROR(_readMethod_staking_force_new_era_always_V3(c, &method->staking_force_new_era_always_V3))
        break;
    case 1553: /* module 6 call 17 */
        CHECK_ERROR(_readMethod_staking_cancel_deferred_slash_V3(c, &method->staking_cancel_deferred_slash_V3))
        break;
    case 1554: /* module 6 call 18 */
        CHECK_ERROR(_readMethod_staking_payout_stakers_V3(c, &method->staking_payout_stakers_V3))
        break;
    case 1555: /* module 6 call 19 */
        CHECK_ERROR(_readMethod_staking_rebond_V3(c, &method->staking_rebond_V3))
        break;
    case 1556: /* module 6 call 20 */
        CHECK_ERROR(_readMethod_staking_set_history_depth_V3(c, &method->staking_set_history_depth_V3))
        break;
    case 1557: /* module 6 call 21 */
        CHECK_ERROR(_readMethod_staking_reap_stash_V3(c, &method->staking_reap_stash_V3))
        break;
    case 1558: /* module 6 call 22 */
        CHECK_ERROR(_readMethod_staking_submit_election_solution_V3(c, &method->staking_submit_election_solution_V3))
        break;
    case 1559: /* module 6 call 23 */
        CHECK_ERROR(_readMethod_staking_submit_election_solution_unsigned_V3(c, &method->staking_submit_election_solution_unsigned_V3))
        break;
    case 2048: /* module 8 call 0 */
        CHECK_ERROR(_readMethod_session_set_keys_V3(c, &method->session_set_keys_V3))
        break;
    case 2049: /* module 8 call 1 */
        CHECK_ERROR(_readMethod_session_purge_keys_V3(c, &method->session_purge_keys_V3))
        break;
    case 2560: /* module 10 call 0 */
        CHECK_ERROR(_readMethod_grandpa_report_equivocation_V3(c, &method->grandpa_report_equivocation_V3))
        break;
    case 2561: /* module 10 call 1 */
        CHECK_ERROR(_readMethod_grandpa_report_equivocation_unsigned_V3(c, &method->grandpa_report_equivocation_unsigned_V3))
        break;
    case 2562: /* module 10 call 2 */
        CHECK_ERROR(_readMethod_grandpa_note_stalled_V3(c, &method->grandpa_note_stalled_V3))
        break;
    case 2816: /* module 11 call 0 */
        CHECK_ERROR(_readMethod_imonline_heartbeat_V3(c, &method->imonline_heartbeat_V3))
        break;
    case 3328: /* module 13 call 0 */
        CHECK_ERROR(_readMethod_democracy_propose_V3(c, &method->democracy_propose_V3))
        break;
    case 3329: /* module 13 call 1 */
        CHECK_ERROR(_readMethod_democracy_second_V3(c, &method->democracy_second_V3))
        break;
    case 3330: /* module 13 call 2 */
        CHECK_ERROR(_readMethod_democracy_vote_V3(c, &method->democracy_vote_V3))
        break;
    case 3331: /* module 13 call 3 */
        CHECK_ERROR(_readMethod_democracy_emergency_cancel_V3(c, &method->democracy_emergency_cancel_V3))
        break;
    case 3332: /* module 13 call 4 */
        CHECK_ERROR(_readMethod_democracy_external_propose_V3(c, &method->democracy_external_propose_V3))
        break;
    case 3333: /* module 13 call 5 */
        CHECK_ERROR(_readMethod_democracy_external_propose_majority_V3(c, &method->democracy_external_propose_majority_V3))
        break;
    case 3334: /* module 13 call 6 */
        CHECK_ERROR(_readMethod_democracy_external_propose_default_V3(c, &method->democracy_external_propose_default_V3))
        break;
    case 3335: /* module 13 call 7 */
        CHECK_ERROR(_readMethod_democracy_fast_track_V3(c, &method->democracy_fast_track_V3))
        break;
    case 3336: /* module 13 call 8 */
        CHECK_ERROR(_readMethod_democracy_veto_external_V3(c, &method->democracy_veto_external_V3))
        break;
    case 3337: /* module 13 call 9 */
        CHECK_ERROR(_readMethod_democracy_cancel_referendum_V3(c, &method->democracy_cancel_referendum_V3))
        break;
    case 3338: /* module 13 call 10 */
        CHECK_ERROR(_readMethod_democracy_cancel_queued_V3(c, &method->democracy_cancel_queued_V3))
        break;
    case 3339: /* module 13 call 11 */
        CHECK_ERROR(_readMethod_democracy_delegate_V3(c, &method->democracy_delegate_V3))
        break;
    case 3340: /* module 13 call 12 */
        CHECK_ERROR(_readMethod_democracy_undelegate_V3(c, &method->democracy_undelegate_V3))
        break;
    case 3341: /* module 13 call 13 */
        CHECK_ERROR(_readMethod_democracy_clear_public_proposals_V3(c, &method->democracy_clear_public_proposals_V3))
        break;
    case 3342: /* module 13 call 14 */
        CHECK_ERROR(_readMethod_democracy_note_preimage_V3(c, &method->democracy_note_preimage_V3))
        break;
    case 3343: /* module 13 call 15 */
        CHECK_ERROR(_readMethod_democracy_note_preimage_operational_V3(c, &method->democracy_note_preimage_operational_V3))
        break;
    case 3344: /* module 13 call 16 */
        CHECK_ERROR(_readMethod_democracy_note_imminent_preimage_V3(c, &method->democracy_note_imminent_preimage_V3))
        break;
    case 3345: /* module 13 call 17 */
        CHECK_ERROR(_readMethod_democracy_note_imminent_preimage_operational_V3(c, &method->democracy_note_imminent_preimage_operational_V3))
        break;
    case 3346: /* module 13 call 18 */
        CHECK_ERROR(_readMethod_democracy_reap_preimage_V3(c, &method->democracy_reap_preimage_V3))
        break;
    case 3347: /* module 13 call 19 */
        CHECK_ERROR(_readMethod_democracy_unlock_V3(c, &method->democracy_unlock_V3))
        break;
    case 3348: /* module 13 call 20 */
        CHECK_ERROR(_readMethod_democracy_remove_vote_V3(c, &method->democracy_remove_vote_V3))
        break;
    case 3349: /* module 13 call 21 */
        CHECK_ERROR(_readMethod_democracy_remove_other_vote_V3(c, &method->democracy_remove_other_vote_V3))
        break;
    case 3350: /* module 13 call 22 */
        CHECK_ERROR(_readMethod_democracy_enact_proposal_V3(c, &method->democracy_enact_proposal_V3))
        break;
    case 3351: /* module 13 call 23 */
        CHECK_ERROR(_readMethod_democracy_blacklist_V3(c, &method->democracy_blacklist_V3))
        break;
    case 3352: /* module 13 call 24 */
        CHECK_ERROR(_readMethod_democracy_cancel_proposal_V3(c, &method->democracy_cancel_proposal_V3))
        break;
    case 3584: /* module 14 call 0 */
        CHECK_ERROR(_readMethod_council_set_members_V3(c, &method->council_set_members_V3))
        break;
    case 3587: /* module 14 call 3 */
        CHECK_ERROR(_readMethod_council_vote_V3(c, &method->council_vote_V3))
        break;
    case 3588: /* module 14 call 4 */
        CHECK_ERROR(_readMethod_council_close_V3(c, &method->council_close_V3))
        break;
    case 3589: /* module 14 call 5 */
        CHECK_ERROR(_readMethod_council_disapprove_proposal_V3(c, &method->council_disapprove_proposal_V3))
        break;
    case 3840: /* module 15 call 0 */
        CHECK_ERROR(_readMethod_technicalcommittee_set_members_V3(c, &method->technicalcommittee_set_members_V3))
        break;
    case 3843: /* module 15 call 3 */
        CHECK_ERROR(_readMethod_technicalcommittee_vote_V3(c, &method->technicalcommittee_vote_V3))
        break;
    case 3844: /* module 15 call 4 */
        CHECK_ERROR(_readMethod_technicalcommittee_close_V3(c, &method->technicalcommittee_close_V3))
        break;
    case 3845: /* module 15 call 5 */
        CHECK_ERROR(_readMethod_technicalcommittee_disapprove_proposal_V3(c, &method->technicalcommittee_disapprove_proposal_V3))
        break;
    case 4096: /* module 16 call 0 */
        CHECK_ERROR(_readMethod_electionsphragmen_vote_V3(c, &method->electionsphragmen_vote_V3))
        break;
    case 4097: /* module 16 call 1 */
        CHECK_ERROR(_readMethod_electionsphragmen_remove_voter_V3(c, &method->electionsphragmen_remove_voter_V3))
        break;
    case 4098: /* module 16 call 2 */
        CHECK_ERROR(_readMethod_electionsphragmen_report_defunct_voter_V3(c, &method->electionsphragmen_report_defunct_voter_V3))
        break;
    case 4099: /* module 16 call 3 */
        CHECK_ERROR(_readMethod_electionsphragmen_submit_candidacy_V3(c, &method->electionsphragmen_submit_candidacy_V3))
        break;
    case 4100: /* module 16 call 4 */
        CHECK_ERROR(_readMethod_electionsphragmen_renounce_candidacy_V3(c, &method->electionsphragmen_renounce_candidacy_V3))
        break;
    case 4101: /* module 16 call 5 */
        CHECK_ERROR(_readMethod_electionsphragmen_remove_member_V3(c, &method->electionsphragmen_remove_member_V3))
        break;
    case 4352: /* module 17 call 0 */
        CHECK_ERROR(_readMethod_technicalmembership_add_member_V3(c, &method->technicalmembership_add_member_V3))
        break;
    case 4353: /* module 17 call 1 */
        CHECK_ERROR(_readMethod_technicalmembership_remove_member_V3(c, &method->technicalmembership_remove_member_V3))
        break;
    case 4354: /* module 17 call 2 */
        CHECK_ERROR(_readMethod_technicalmembership_swap_member_V3(c, &method->technicalmembership_swap_member_V3))
        break;
    case 4355: /* module 17 call 3 */
        CHECK_ERROR(_readMethod_technicalmembership_reset_members_V3(c, &method->technicalmembership_reset_members_V3))
        break;
    case 4356: /* module 17 call 4 */
        CHECK_ERROR(_readMethod_technicalmembership_change_key_V3(c, &method->technicalmembership_change_key_V3))
        break;
    case 4357: /* module 17 call 5 */
        CHECK_ERROR(_readMethod_technicalmembership_set_prime_V3(c, &method->technicalmembership_set_prime_V3))
        break;
    case 4358: /* module 17 call 6 */
        CHECK_ERROR(_readMethod_technicalmembership_clear_prime_V3(c, &method->technicalmembership_clear_prime_V3))
        break;
    case 4608: /* module 18 call 0 */
        CHECK_ERROR(_readMethod_treasury_propose_spend_V3(c, &method->treasury_propose_spend_V3))
        break;
    case 4609: /* module 18 call 1 */
        CHECK_ERROR(_readMethod_treasury_reject_proposal_V3(c, &method->treasury_reject_proposal_V3))
        break;
    case 4610: /* module 18 call 2 */
        CHECK_ERROR(_readMethod_treasury_approve_proposal_V3(c, &method->treasury_approve_proposal_V3))
        break;
    case 4611: /* module 18 call 3 */
        CHECK_ERROR(_readMethod_treasury_report_awesome_V3(c, &method->treasury_report_awesome_V3))
        break;
    case 4612: /* module 18 call 4 */
        CHECK_ERROR(_readMethod_treasury_retract_tip_V3(c, &method->treasury_retract_tip_V3))
        break;
    case 4613: /* module 18 call 5 */
        CHECK_ERROR(_readMethod_treasury_tip_new_V3(c, &method->treasury_tip_new_V3))
        break;
    case 4614: /* module 18 call 6 */
        CHECK_ERROR(_readMethod_treasury_tip_V3(c, &method->treasury_tip_V3))
        break;
    case 4615: /* module 18 call 7 */
        CHECK_ERROR(_readMethod_treasury_close_tip_V3(c, &method->treasury_close_tip_V3))
        break;
    case 4616: /* module 18 call 8 */
        CHECK_ERROR(_readMethod_treasury_propose_bounty_V3(c, &method->treasury_propose_bounty_V3))
        break;
    case 4617: /* module 18 call 9 */
        CHECK_ERROR(_readMethod_treasury_approve_bounty_V3(c, &method->treasury_approve_bounty_V3))
        break;
    case 4618: /* module 18 call 10 */
        CHECK_ERROR(_readMethod_treasury_propose_curator_V3(c, &method->treasury_propose_curator_V3))
        break;
    case 4619: /* module 18 call 11 */
        CHECK_ERROR(_readMethod_treasury_unassign_curator_V3(c, &method->treasury_unassign_curator_V3))
        break;
    case 4620: /* module 18 call 12 */
        CHECK_ERROR(_readMethod_treasury_accept_curator_V3(c, &method->treasury_accept_curator_V3))
        break;
    case 4621: /* module 18 call 13 */
        CHECK_ERROR(_readMethod_treasury_award_bounty_V3(c, &method->treasury_award_bounty_V3))
        break;
    case 4622: /* module 18 call 14 */
        CHECK_ERROR(_readMethod_treasury_claim_bounty_V3(c, &method->treasury_claim_bounty_V3))
        break;
    case 4623: /* module 18 call 15 */
        CHECK_ERROR(_readMethod_treasury_close_bounty_V3(c, &method->treasury_close_bounty_V3))
        break;
    case 4624: /* module 18 call 16 */
        CHECK_ERROR(_readMethod_treasury_extend_bounty_expiry_V3(c, &method->treasury_extend_bounty_expiry_V3))
        break;
    case 4864: /* module 19 call 0 */
        CHECK_ERROR(_readMethod_claims_claim_V3(c, &method->claims_claim_V3))
        break;
    case 4865: /* module 19 call 1 */
        CHECK_ERROR(_readMethod_claims_mint_claim_V3(c, &method->claims_mint_claim_V3))
        break;
    case 4866: /* module 19 call 2 */
        CHECK_ERROR(_readMethod_claims_claim_attest_V3(c, &method->claims_claim_attest_V3))
        break;
    case 4867: /* module 19 call 3 */
        CHECK_ERROR(_readMethod_claims_attest_V3(c, &method->claims_attest_V3))
        break;
    case 4868: /* module 19 call 4 */
        CHECK_ERROR(_readMethod_claims_move_claim_V3(c, &method->claims_move_claim_V3))
        break;
    case 6144: /* module 24 call 0 */
        CHECK_ERROR(_readMethod_utility_batch_V3(c, &method->utility_batch_V3))
        break;
    case 6145: /* module 24 call 1 */
        CHECK_ERROR(_readMethod_utility_as_derivative_V3(c, &method->utility_as_derivative_V3))
        break;
    case 6146: /* module 24 call 2 */
        CHECK_ERROR(_readMethod_utility_batch_all_V3(c, &method->utility_batch_all_V3))
        break;
    case 6400: /* module 25 call 0 */
        CHECK_ERROR(_readMethod_identity_add_registrar_V3(c, &method->identity_add_registrar_V3))
        break;
    case 6401: /* module 25 call 1 */
        CHECK_ERROR(_readMethod_identity_set_identity_V3(c, &method->identity_set_identity_V3))
        break;
    case 6402: /* module 25 call 2 */
        CHECK_ERROR(_readMethod_identity_set_subs_V3(c, &method->identity_set_subs_V3))
        break;
    case 6403: /* module 25 call 3 */
        CHECK_ERROR(_readMethod_identity_clear_identity_V3(c, &method->identity_clear_identity_V3))
        break;
    case 6404: /* module 25 call 4 */
        CHECK_ERROR(_readMethod_identity_request_judgement_V3(c, &method->identity_request_judgement_V3))
        break;
    case 6405: /* module 25 call 5 */
        CHECK_ERROR(_readMethod_identity_cancel_request_V3(c, &method->identity_cancel_request_V3))
        break;
    case 6406: /* module 25 call 6 */
        CHECK_ERROR(_readMethod_identity_set_fee_V3(c, &method->identity_set_fee_V3))
        break;
    case 6407: /* module 25 call 7 */
        CHECK_ERROR(_readMethod_identity_set_account_id_V3(c, &method->identity_set_account_id_V3))
        break;
    case 6408: /* module 25 call 8 */
        CHECK_ERROR(_readMethod_identity_set_fields_V3(c, &method->identity_set_fields_V3))
        break;
    case 6409: /* module 25 call 9 */
        CHECK_ERROR(_readMethod_identity_provide_judgement_V3(c, &method->identity_provide_judgement_V3))
        break;
    case 6410: /* module 25 call 10 */
        CHECK_ERROR(_readMethod_identity_kill_identity_V3(c, &method->identity_kill_identity_V3))
        break;
    case 6411: /* module 25 call 11 */
        CHECK_ERROR(_readMethod_identity_add_sub_V3(c, &method->identity_add_sub_V3))
        break;
    case 6412: /* module 25 call 12 */
        CHECK_ERROR(_readMethod_identity_rename_sub_V3(c, &method->identity_rename_sub_V3))
        break;
    case 6413: /* module 25 call 13 */
        CHECK_ERROR(_readMethod_identity_remove_sub_V3(c, &method->identity_remove_sub_V3))
        break;
    case 6414: /* module 25 call 14 */
        CHECK_ERROR(_readMethod_identity_quit_sub_V3(c, &method->identity_quit_sub_V3))
        break;
    case 6656: /* module 26 call 0 */
        CHECK_ERROR(_readMethod_society_bid_V3(c, &method->society_bid_V3))
        break;
    case 6657: /* module 26 call 1 */
        CHECK_ERROR(_readMethod_society_unbid_V3(c, &method->society_unbid_V3))
        break;
    case 6658: /* module 26 call 2 */
        CHECK_ERROR(_readMethod_society_vouch_V3(c, &method->society_vouch_V3))
        break;
    case 6659: /* module 26 call 3 */
        CHECK_ERROR(_readMethod_society_unvouch_V3(c, &method->society_unvouch_V3))
        break;
    case 6660: /* module 26 call 4 */
        CHECK_ERROR(_readMethod_society_vote_V3(c, &method->society_vote_V3))
        break;
    case 6661: /* module 26 call 5 */
        CHECK_ERROR(_readMethod_society_defender_vote_V3(c, &method->society_defender_vote_V3))
        break;
    case 6662: /* module 26 call 6 */
        CHECK_ERROR(_readMethod_society_payout_V3(c, &method->society_payout_V3))
        break;
    case 6663: /* module 26 call 7 */
        CHECK_ERROR(_readMethod_society_found_V3(c, &method->society_found_V3))
        break;
    case 6664: /* module 26 call 8 */
        CHECK_ERROR(_readMethod_society_unfound_V3(c, &method->society_unfound_V3))
        break;
    case 6665: /* module 26 call 9 */
        CHECK_ERROR(_readMethod_society_judge_suspended_member_V3(c, &method->society_judge_suspended_member_V3))
        break;
    case 6666: /* module 26 call 10 */
        CHECK_ERROR(_readMethod_society_judge_suspended_candidate_V3(c, &method->society_judge_suspended_candidate_V3))
        break;
    case 6667: /* module 26 call 11 */
        CHECK_ERROR(_readMethod_society_set_max_members_V3(c, &method->society_set_max_members_V3))
        break;
    case 6912: /* module 27 call 0 */
        CHECK_ERROR(_readMethod_recovery_as_recovered_V3(c, &method->recovery_as_recovered_V3))
        break;
    case 6913: /* module 27 call 1 */
        CHECK_ERROR(_readMethod_recovery_set_recovered_V3(c, &method->recovery_set_recovered_V3))
        break;
    case 6914: /* module 27 call 2 */
        CHECK_ERROR(_readMethod_recovery_create_recovery_V3(c, &method->recovery_create_recovery_V3))
        break;
    case 6915: /* module 27 call 3 */
        CHECK_ERROR(_readMethod_recovery_initiate_recovery_V3(c, &method->recovery_initiate_recovery_V3))
        break;
    case 6916: /* module 27 call 4 */
        CHECK_ERROR(_readMethod_recovery_vouch_recovery_V3(c, &method->recovery_vouch_recovery_V3))
        break;
    case 6917: /* module 27 call 5 */
        CHECK_ERROR(_readMethod_recovery_claim_recovery_V3(c, &method->recovery_claim_recovery_V3))
        break;
    case 6918: /* module 27 call 6 */
        CHECK_ERROR(_readMethod_recovery_close_recovery_V3(c, &method->recovery_close_recovery_V3))
        break;
    case 6919: /* module 27 call 7 */
        CHECK_ERROR(_readMethod_recovery_remove_recovery_V3(c, &method->recovery_remove_recovery_V3))
        break;
    case 6920: /* module 27 call 8 */
        CHECK_ERROR(_readMethod_recovery_cancel_recovered_V3(c, &method->recovery_cancel_recovered_V3))
        break;
    case 7168: /* module 28 call 0 */
        CHECK_ERROR(_readMethod_vesting_vest_V3(c, &method->vesting_vest_V3))
        break;
    case 7169: /* module 28 call 1 */
        CHECK_ERROR(_readMethod_vesting_vest_other_V3(c, &method->vesting_vest_other_V3))
        break;
    case 7170: /* module 28 call 2 */
        CHECK_ERROR(_readMethod_vesting_vested_transfer_V3(c, &method->vesting_vested_transfer_V3))
        break;
    case 7171: /* module 28 call 3 */
        CHECK_ERROR(_readMethod_vesting_force_vested_transfer_V3(c, &method->vesting_force_vested_transfer_V3))
        break;
    case 7424: /* module 29 call 0 */
        CHECK_ERROR(_readMethod_scheduler_schedule_V3(c, &method->scheduler_schedule_V3))
        break;
    case 7425: /* module 29 call 1 */
        CHECK_ERROR(_readMethod_scheduler_cancel_V3(c, &method->scheduler_cancel_V3))
        break;
    case 7426: /* module 29 call 2 */
        CHECK_ERROR(_readMethod_scheduler_schedule_named_V3(c, &method->scheduler_schedule_named_V3))
        break;
    case 7427: /* module 29 call 3 */
        CHECK_ERROR(_readMethod_scheduler_cancel_named_V3(c, &method->scheduler_cancel_named_V3))
        break;
    case 7428: /* module 29 call 4 */
        CHECK_ERROR(_readMethod_scheduler_schedule_after_V3(c, &method->scheduler_schedule_after_V3))
        break;
    case 7429: /* module 29 call 5 */
        CHECK_ERROR(_readMethod_scheduler_schedule_named_after_V3(c, &method->scheduler_schedule_named_after_V3))
        break;
    case 7680: /* module 30 call 0 */
        CHECK_ERROR(_readMethod_proxy_proxy_V3(c, &method->proxy_proxy_V3))
        break;
    case 7681: /* module 30 call 1 */
        CHECK_ERROR(_readMethod_proxy_add_proxy_V3(c, &method->proxy_add_proxy_V3))
        break;
    case 7682: /* module 30 call 2 */
        CHECK_ERROR(_readMethod_proxy_remove_proxy_V3(c, &method->proxy_remove_proxy_V3))
        break;
    case 7683: /* module 30 call 3 */
        CHECK_ERROR(_readMethod_proxy_remove_proxies_V3(c, &method->proxy_remove_proxies_V3))
        break;
    case 7684: /* module 30 call 4 */
        CHECK_ERROR(_readMethod_proxy_anonymous_V3(c, &method->proxy_anonymous_V3))
        break;
    case 7685: /* module 30 call 5 */
        CHECK_ERROR(_readMethod_proxy_kill_anonymous_V3(c, &method->proxy_kill_anonymous_V3))
        break;
    case 7686: /* module 30 call 6 */
        CHECK_ERROR(_readMethod_proxy_announce_V3(c, &method->proxy_announce_V3))
        break;
    case 7687: /* module 30 call 7 */
        CHECK_ERROR(_readMethod_proxy_remove_announcement_V3(c, &method->proxy_remove_announcement_V3))
        break;
    case 7688: /* module 30 call 8 */
        CHECK_ERROR(_readMethod_proxy_reject_announcement_V3(c, &method->proxy_reject_announcement_V3))
        break;
    case 7689: /* module 30 call 9 */
        CHECK_ERROR(_readMethod_proxy_proxy_announced_V3(c, &method->proxy_proxy_announced_V3))
        break;
    case 7936: /* module 31 call 0 */
        CHECK_ERROR(_readMethod_multisig_as_multi_threshold_1_V3(c, &method->multisig_as_multi_threshold_1_V3))
        break;
    case 7937: /* module 31 call 1 */
        CHECK_ERROR(_readMethod_multisig_as_multi_V3(c, &method->multisig_as_multi_V3))
        break;
    case 7938: /* module 31 call 2 */
        CHECK_ERROR(_readMethod_multisig_approve_as_multi_V3(c, &method->multisig_approve_as_multi_V3))
        break;
    case 7939: /* module 31 call 3 */
        CHECK_ERROR(_readMethod_multisig_cancel_as_multi_V3(c, &method->multisig_cancel_as_multi_V3))
        break;
    default:
        return parser_unexpected_callIndex;
    }

    return parser_ok;
}

parser_error_t _readMethod_V3(
    parser_context_t* c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_Method_V3_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 0: /* module 0 call 0 */
        CHECK_ERROR(_readMethod_system_fill_block_V3(c, &method->basic.system_fill_block_V3))
        break;
    case 1: /* module 0 call 1 */
        CHECK_ERROR(_readMethod_system_remark_V3(c, &method->basic.system_remark_V3))
        break;
    case 2: /* module 0 call 2 */
        CHECK_ERROR(_readMethod_system_set_heap_pages_V3(c, &method->basic.system_set_heap_pages_V3))
        break;
    case 3: /* module 0 call 3 */
        CHECK_ERROR(_readMethod_system_set_code_V3(c, &method->basic.system_set_code_V3))
        break;
    case 4: /* module 0 call 4 */
        CHECK_ERROR(_readMethod_system_set_code_without_checks_V3(c, &method->basic.system_set_code_without_checks_V3))
        break;
    case 5: /* module 0 call 5 */
        CHECK_ERROR(_readMethod_system_set_changes_trie_config_V3(c, &method->basic.system_set_changes_trie_config_V3))
        break;
    case 6: /* module 0 call 6 */
        CHECK_ERROR(_readMethod_system_set_storage_V3(c, &method->basic.system_set_storage_V3))
        break;
    case 7: /* module 0 call 7 */
        CHECK_ERROR(_readMethod_system_kill_storage_V3(c, &method->basic.system_kill_storage_V3))
        break;
    case 8: /* module 0 call 8 */
        CHECK_ERROR(_readMethod_system_kill_prefix_V3(c, &method->basic.system_kill_prefix_V3))
        break;
    case 9: /* module 0 call 9 */
        CHECK_ERROR(_readMethod_system_suicide_V3(c, &method->basic.system_suicide_V3))
        break;
    case 256: /* module 1 call 0 */
        CHECK_ERROR(_readMethod_babe_report_equivocation_V3(c, &method->basic.babe_report_equivocation_V3))
        break;
    case 257: /* module 1 call 1 */
        CHECK_ERROR(_readMethod_babe_report_equivocation_unsigned_V3(c, &method->basic.babe_report_equivocation_unsigned_V3))
        break;
    case 512: /* module 2 call 0 */
        CHECK_ERROR(_readMethod_timestamp_set_V3(c, &method->basic.timestamp_set_V3))
        break;
    case 768: /* module 3 call 0 */
        CHECK_ERROR(_readMethod_indices_claim_V3(c, &method->basic.indices_claim_V3))
        break;
    case 769: /* module 3 call 1 */
        CHECK_ERROR(_readMethod_indices_transfer_V3(c, &method->basic.indices_transfer_V3))
        break;
    case 770: /* module 3 call 2 */
        CHECK_ERROR(_readMethod_indices_free_V3(c, &method->basic.indices_free_V3))
        break;
    case 771: /* module 3 call 3 */
        CHECK_ERROR(_readMethod_indices_force_transfer_V3(c, &method->basic.indices_force_transfer_V3))
        break;
    case 772: /* module 3 call 4 */
        CHECK_ERROR(_readMethod_indices_freeze_V3(c, &method->basic.indices_freeze_V3))
        break;
    case 1024: /* module 4 call 0 */
        CHECK_ERROR(_readMethod_balances_transfer_V3(c, &method->basic.balances_transfer_V3))
        break;
    case 1025: /* module 4 call 1 */
        CHECK_ERROR(_readMethod_balances_set_balance_V3(c, &method->basic.balances_set_balance_V3))
        break;
    case 1026: /* module 4 call 2 */
        CHECK_ERROR(_readMethod_balances_force_transfer_V3(c, &method->basic.balances_force_transfer_V3))
        break;
    case 1027: /* module 4 call 3 */
        CHECK_ERROR(_readMethod_balances_transfer_keep_alive_V3(c, &method->basic.balances_transfer_keep_alive_V3))
        break;
    case 1280: /* module 5 call 0 */
        CHECK_ERROR(_readMethod_authorship_set_uncles_V3(c, &method->basic.authorship_set_uncles_V3))
        break;
    case 1536: /* module 6 call 0 */
        CHECK_ERROR(_readMethod_staking_bond_V3(c, &method->basic.staking_bond_V3))
        break;
    case 1537: /* module 6 call 1 */
        CHECK_ERROR(_readMethod_staking_bond_extra_V3(c, &method->basic.staking_bond_extra_V3))
        break;
    case 1538: /* module 6 call 2 */
        CHECK_ERROR(_readMethod_staking_unbond_V3(c, &method->basic.staking_unbond_V3))
        break;
    case 1539: /* module 6 call 3 */
        CHECK_ERROR(_readMethod_staking_withdraw_unbonded_V3(c, &method->basic.staking_withdraw_unbonded_V3))
        break;
    case 1540: /* module 6 call 4 */
        CHECK_ERROR(_readMethod_staking_validate_V3(c, &method->basic.staking_validate_V3))
        break;
    case 1541: /* module 6 call 5 */
        CHECK_ERROR(_readMethod_staking_nominate_V3(c, &method->basic.staking_nominate_V3))
        break;
    case 1542: /* module 6 call 6 */
        CHECK_ERROR(_readMethod_staking_chill_V3(c, &method->basic.staking_chill_V3))
        break;
    case 1543: /* module 6 call 7 */
        CHECK_ERROR(_readMethod_staking_set_payee_V3(c, &method->basic.staking_set_payee_V3))
        break;
    case 1544: /* module 6 call 8 */
        CHECK_ERROR(_readMethod_staking_set_controller_V3(c, &method->basic.staking_set_controller_V3))
        break;
    case 1545: /* module 6 call 9 */
        CHECK_ERROR(_readMethod_staking_set_validator_count_V3(c, &method->basic.staking_set_validator_count_V3))
        break;
    case 1546: /* module 6 call 10 */
        CHECK_ERROR(_readMethod_staking_increase_validator_count_V3(c, &method->basic.staking_increase_validator_count_V3))
        break;
    case 1547: /* module 6 call 11 */
        CHECK_ERROR(_readMethod_staking_scale_validator_count_V3(c, &method->basic.staking_scale_validator_count_V3))
        break;
    case 1548: /* module 6 call 12 */
        CHECK_ERROR(_readMethod_staking_force_no_eras_V3(c, &method->basic.staking_force_no_eras_V3))
        break;
    case 1549: /* module 6 call 13 */
        CHECK_ERROR(_readMethod_staking_force_new_era_V3(c, &method->basic.staking_force_new_era_V3))
        break;
    case 1550: /* module 6 call 14 */
        CHECK_ERROR(_readMethod_staking_set_invulnerables_V3(c, &method->basic.staking_set_invulnerables_V3))
        break;
    case 1551: /* module 6 call 15 */
        CHECK_ERROR(_readMethod_staking_force_unstake_V3(c, &method->basic.staking_force_unstake_V3))
        break;
    case 1552: /* module 6 call 16 */
        CHECK_ERROR(_readMethod_staking_force_new_era_always_V3(c, &method->basic.staking_force_new_era_always_V3))
        break;
    case 1553: /* module 6 call 17 */
        CHECK_ERROR(_readMethod_staking_cancel_deferred_slash_V3(c, &method->basic.staking_cancel_deferred_slash_V3))
        break;
    case 1554: /* module 6 call 18 */
        CHECK_ERROR(_readMethod_staking_payout_stakers_V3(c, &method->basic.staking_payout_stakers_V3))
        break;
    case 1555: /* module 6 call 19 */
        CHECK_ERROR(_readMethod_staking_rebond_V3(c, &method->basic.staking_rebond_V3))
        break;
    case 1556: /* module 6 call 20 */
        CHECK_ERROR(_readMethod_staking_set_history_depth_V3(c, &method->basic.staking_set_history_depth_V3))
        break;
    case 1557: /* module 6 call 21 */
        CHECK_ERROR(_readMethod_staking_reap_stash_V3(c, &method->basic.staking_reap_stash_V3))
        break;
    case 1558: /* module 6 call 22 */
        CHECK_ERROR(_readMethod_staking_submit_election_solution_V3(c, &method->basic.staking_submit_election_solution_V3))
        break;
    case 1559: /* module 6 call 23 */
        CHECK_ERROR(_readMethod_staking_submit_election_solution_unsigned_V3(c, &method->basic.staking_submit_election_solution_unsigned_V3))
        break;
    case 2048: /* module 8 call 0 */
        CHECK_ERROR(_readMethod_session_set_keys_V3(c, &method->basic.session_set_keys_V3))
        break;
    case 2049: /* module 8 call 1 */
        CHECK_ERROR(_readMethod_session_purge_keys_V3(c, &method->basic.session_purge_keys_V3))
        break;
    case 2560: /* module 10 call 0 */
        CHECK_ERROR(_readMethod_grandpa_report_equivocation_V3(c, &method->basic.grandpa_report_equivocation_V3))
        break;
    case 2561: /* module 10 call 1 */
        CHECK_ERROR(_readMethod_grandpa_report_equivocation_unsigned_V3(c, &method->basic.grandpa_report_equivocation_unsigned_V3))
        break;
    case 2562: /* module 10 call 2 */
        CHECK_ERROR(_readMethod_grandpa_note_stalled_V3(c, &method->basic.grandpa_note_stalled_V3))
        break;
    case 2816: /* module 11 call 0 */
        CHECK_ERROR(_readMethod_imonline_heartbeat_V3(c, &method->basic.imonline_heartbeat_V3))
        break;
    case 3328: /* module 13 call 0 */
        CHECK_ERROR(_readMethod_democracy_propose_V3(c, &method->basic.democracy_propose_V3))
        break;
    case 3329: /* module 13 call 1 */
        CHECK_ERROR(_readMethod_democracy_second_V3(c, &method->basic.democracy_second_V3))
        break;
    case 3330: /* module 13 call 2 */
        CHECK_ERROR(_readMethod_democracy_vote_V3(c, &method->basic.democracy_vote_V3))
        break;
    case 3331: /* module 13 call 3 */
        CHECK_ERROR(_readMethod_democracy_emergency_cancel_V3(c, &method->basic.democracy_emergency_cancel_V3))
        break;
    case 3332: /* module 13 call 4 */
        CHECK_ERROR(_readMethod_democracy_external_propose_V3(c, &method->basic.democracy_external_propose_V3))
        break;
    case 3333: /* module 13 call 5 */
        CHECK_ERROR(_readMethod_democracy_external_propose_majority_V3(c, &method->basic.democracy_external_propose_majority_V3))
        break;
    case 3334: /* module 13 call 6 */
        CHECK_ERROR(_readMethod_democracy_external_propose_default_V3(c, &method->basic.democracy_external_propose_default_V3))
        break;
    case 3335: /* module 13 call 7 */
        CHECK_ERROR(_readMethod_democracy_fast_track_V3(c, &method->basic.democracy_fast_track_V3))
        break;
    case 3336: /* module 13 call 8 */
        CHECK_ERROR(_readMethod_democracy_veto_external_V3(c, &method->basic.democracy_veto_external_V3))
        break;
    case 3337: /* module 13 call 9 */
        CHECK_ERROR(_readMethod_democracy_cancel_referendum_V3(c, &method->basic.democracy_cancel_referendum_V3))
        break;
    case 3338: /* module 13 call 10 */
        CHECK_ERROR(_readMethod_democracy_cancel_queued_V3(c, &method->basic.democracy_cancel_queued_V3))
        break;
    case 3339: /* module 13 call 11 */
        CHECK_ERROR(_readMethod_democracy_delegate_V3(c, &method->basic.democracy_delegate_V3))
        break;
    case 3340: /* module 13 call 12 */
        CHECK_ERROR(_readMethod_democracy_undelegate_V3(c, &method->basic.democracy_undelegate_V3))
        break;
    case 3341: /* module 13 call 13 */
        CHECK_ERROR(_readMethod_democracy_clear_public_proposals_V3(c, &method->basic.democracy_clear_public_proposals_V3))
        break;
    case 3342: /* module 13 call 14 */
        CHECK_ERROR(_readMethod_democracy_note_preimage_V3(c, &method->basic.democracy_note_preimage_V3))
        break;
    case 3343: /* module 13 call 15 */
        CHECK_ERROR(_readMethod_democracy_note_preimage_operational_V3(c, &method->basic.democracy_note_preimage_operational_V3))
        break;
    case 3344: /* module 13 call 16 */
        CHECK_ERROR(_readMethod_democracy_note_imminent_preimage_V3(c, &method->basic.democracy_note_imminent_preimage_V3))
        break;
    case 3345: /* module 13 call 17 */
        CHECK_ERROR(_readMethod_democracy_note_imminent_preimage_operational_V3(c, &method->basic.democracy_note_imminent_preimage_operational_V3))
        break;
    case 3346: /* module 13 call 18 */
        CHECK_ERROR(_readMethod_democracy_reap_preimage_V3(c, &method->basic.democracy_reap_preimage_V3))
        break;
    case 3347: /* module 13 call 19 */
        CHECK_ERROR(_readMethod_democracy_unlock_V3(c, &method->basic.democracy_unlock_V3))
        break;
    case 3348: /* module 13 call 20 */
        CHECK_ERROR(_readMethod_democracy_remove_vote_V3(c, &method->basic.democracy_remove_vote_V3))
        break;
    case 3349: /* module 13 call 21 */
        CHECK_ERROR(_readMethod_democracy_remove_other_vote_V3(c, &method->basic.democracy_remove_other_vote_V3))
        break;
    case 3350: /* module 13 call 22 */
        CHECK_ERROR(_readMethod_democracy_enact_proposal_V3(c, &method->basic.democracy_enact_proposal_V3))
        break;
    case 3351: /* module 13 call 23 */
        CHECK_ERROR(_readMethod_democracy_blacklist_V3(c, &method->basic.democracy_blacklist_V3))
        break;
    case 3352: /* module 13 call 24 */
        CHECK_ERROR(_readMethod_democracy_cancel_proposal_V3(c, &method->basic.democracy_cancel_proposal_V3))
        break;
    case 3584: /* module 14 call 0 */
        CHECK_ERROR(_readMethod_council_set_members_V3(c, &method->basic.council_set_members_V3))
        break;
    case 3585: /* module 14 call 1 */
        CHECK_ERROR(_readMethod_council_execute_V3(c, &method->nested.council_execute_V3))
        break;
    case 3586: /* module 14 call 2 */
        CHECK_ERROR(_readMethod_council_propose_V3(c, &method->nested.council_propose_V3))
        break;
    case 3587: /* module 14 call 3 */
        CHECK_ERROR(_readMethod_council_vote_V3(c, &method->basic.council_vote_V3))
        break;
    case 3588: /* module 14 call 4 */
        CHECK_ERROR(_readMethod_council_close_V3(c, &method->basic.council_close_V3))
        break;
    case 3589: /* module 14 call 5 */
        CHECK_ERROR(_readMethod_council_disapprove_proposal_V3(c, &method->basic.council_disapprove_proposal_V3))
        break;
    case 3840: /* module 15 call 0 */
        CHECK_ERROR(_readMethod_technicalcommittee_set_members_V3(c, &method->basic.technicalcommittee_set_members_V3))
        break;
    case 3841: /* module 15 call 1 */
        CHECK_ERROR(_readMethod_technicalcommittee_execute_V3(c, &method->nested.technicalcommittee_execute_V3))
        break;
    case 3842: /* module 15 call 2 */
        CHECK_ERROR(_readMethod_technicalcommittee_propose_V3(c, &method->nested.technicalcommittee_propose_V3))
        break;
    case 3843: /* module 15 call 3 */
        CHECK_ERROR(_readMethod_technicalcommittee_vote_V3(c, &method->basic.technicalcommittee_vote_V3))
        break;
    case 3844: /* module 15 call 4 */
        CHECK_ERROR(_readMethod_technicalcommittee_close_V3(c, &method->basic.technicalcommittee_close_V3))
        break;
    case 3845: /* module 15 call 5 */
        CHECK_ERROR(_readMethod_technicalcommittee_disapprove_proposal_V3(c, &method->basic.technicalcommittee_disapprove_proposal_V3))
        break;
    case 4096: /* module 16 call 0 */
        CHECK_ERROR(_readMethod_electionsphragmen_vote_V3(c, &method->basic.electionsphragmen_vote_V3))
        break;
    case 4097: /* module 16 call 1 */
        CHECK_ERROR(_readMethod_electionsphragmen_remove_voter_V3(c, &method->basic.electionsphragmen_remove_voter_V3))
        break;
    case 4098: /* module 16 call 2 */
        CHECK_ERROR(_readMethod_electionsphragmen_report_defunct_voter_V3(c, &method->basic.electionsphragmen_report_defunct_voter_V3))
        break;
    case 4099: /* module 16 call 3 */
        CHECK_ERROR(_readMethod_electionsphragmen_submit_candidacy_V3(c, &method->basic.electionsphragmen_submit_candidacy_V3))
        break;
    case 4100: /* module 16 call 4 */
        CHECK_ERROR(_readMethod_electionsphragmen_renounce_candidacy_V3(c, &method->basic.electionsphragmen_renounce_candidacy_V3))
        break;
    case 4101: /* module 16 call 5 */
        CHECK_ERROR(_readMethod_electionsphragmen_remove_member_V3(c, &method->basic.electionsphragmen_remove_member_V3))
        break;
    case 4352: /* module 17 call 0 */
        CHECK_ERROR(_readMethod_technicalmembership_add_member_V3(c, &method->basic.technicalmembership_add_member_V3))
        break;
    case 4353: /* module 17 call 1 */
        CHECK_ERROR(_readMethod_technicalmembership_remove_member_V3(c, &method->basic.technicalmembership_remove_member_V3))
        break;
    case 4354: /* module 17 call 2 */
        CHECK_ERROR(_readMethod_technicalmembership_swap_member_V3(c, &method->basic.technicalmembership_swap_member_V3))
        break;
    case 4355: /* module 17 call 3 */
        CHECK_ERROR(_readMethod_technicalmembership_reset_members_V3(c, &method->basic.technicalmembership_reset_members_V3))
        break;
    case 4356: /* module 17 call 4 */
        CHECK_ERROR(_readMethod_technicalmembership_change_key_V3(c, &method->basic.technicalmembership_change_key_V3))
        break;
    case 4357: /* module 17 call 5 */
        CHECK_ERROR(_readMethod_technicalmembership_set_prime_V3(c, &method->basic.technicalmembership_set_prime_V3))
        break;
    case 4358: /* module 17 call 6 */
        CHECK_ERROR(_readMethod_technicalmembership_clear_prime_V3(c, &method->basic.technicalmembership_clear_prime_V3))
        break;
    case 4608: /* module 18 call 0 */
        CHECK_ERROR(_readMethod_treasury_propose_spend_V3(c, &method->basic.treasury_propose_spend_V3))
        break;
    case 4609: /* module 18 call 1 */
        CHECK_ERROR(_readMethod_treasury_reject_proposal_V3(c, &method->basic.treasury_reject_proposal_V3))
        break;
    case 4610: /* module 18 call 2 */
        CHECK_ERROR(_readMethod_treasury_approve_proposal_V3(c, &method->basic.treasury_approve_proposal_V3))
        break;
    case 4611: /* module 18 call 3 */
        CHECK_ERROR(_readMethod_treasury_report_awesome_V3(c, &method->basic.treasury_report_awesome_V3))
        break;
    case 4612: /* module 18 call 4 */
        CHECK_ERROR(_readMethod_treasury_retract_tip_V3(c, &method->basic.treasury_retract_tip_V3))
        break;
    case 4613: /* module 18 call 5 */
        CHECK_ERROR(_readMethod_treasury_tip_new_V3(c, &method->basic.treasury_tip_new_V3))
        break;
    case 4614: /* module 18 call 6 */
        CHECK_ERROR(_readMethod_treasury_tip_V3(c, &method->basic.treasury_tip_V3))
        break;
    case 4615: /* module 18 call 7 */
        CHECK_ERROR(_readMethod_treasury_close_tip_V3(c, &method->basic.treasury_close_tip_V3))
        break;
    case 4616: /* module 18 call 8 */
        CHECK_ERROR(_readMethod_treasury_propose_bounty_V3(c, &method->basic.treasury_propose_bounty_V3))
        break;
    case 4617: /* module 18 call 9 */
        CHECK_ERROR(_readMethod_treasury_approve_bounty_V3(c, &method->basic.treasury_approve_bounty_V3))
        break;
    case 4618: /* module 18 call 10 */
        CHECK_ERROR(_readMethod_treasury_propose_curator_V3(c, &method->basic.treasury_propose_curator_V3))
        break;
    case 4619: /* module 18 call 11 */
        CHECK_ERROR(_readMethod_treasury_unassign_curator_V3(c, &method->basic.treasury_unassign_curator_V3))
        break;
    case 4620: /* module 18 call 12 */
        CHECK_ERROR(_readMethod_treasury_accept_curator_V3(c, &method->basic.treasury_accept_curator_V3))
        break;
    case 4621: /* module 18 call 13 */
        CHECK_ERROR(_readMethod_treasury_award_bounty_V3(c, &method->basic.treasury_award_bounty_V3))
        break;
    case 4622: /* module 18 call 14 */
        CHECK_ERROR(_readMethod_treasury_claim_bounty_V3(c, &method->basic.treasury_claim_bounty_V3))
        break;
    case 4623: /* module 18 call 15 */
        CHECK_ERROR(_readMethod_treasury_close_bounty_V3(c, &method->basic.treasury_close_bounty_V3))
        break;
    case 4624: /* module 18 call 16 */
        CHECK_ERROR(_readMethod_treasury_extend_bounty_expiry_V3(c, &method->basic.treasury_extend_bounty_expiry_V3))
        break;
    case 4864: /* module 19 call 0 */
        CHECK_ERROR(_readMethod_claims_claim_V3(c, &method->basic.claims_claim_V3))
        break;
    case 4865: /* module 19 call 1 */
        CHECK_ERROR(_readMethod_claims_mint_claim_V3(c, &method->basic.claims_mint_claim_V3))
        break;
    case 4866: /* module 19 call 2 */
        CHECK_ERROR(_readMethod_claims_claim_attest_V3(c, &method->basic.claims_claim_attest_V3))
        break;
    case 4867: /* module 19 call 3 */
        CHECK_ERROR(_readMethod_claims_attest_V3(c, &method->basic.claims_attest_V3))
        break;
    case 4868: /* module 19 call 4 */
        CHECK_ERROR(_readMethod_claims_move_claim_V3(c, &method->basic.claims_move_claim_V3))
        break;
    case 6144: /* module 24 call 0 */
        CHECK_ERROR(_readMethod_utility_batch_V3(c, &method->basic.utility_batch_V3))
        break;
    case 6145: /* module 24 call 1 */
        CHECK_ERROR(_readMethod_utility_as_derivative_V3(c, &method->basic.utility_as_derivative_V3))
        break;
    case 6146: /* module 24 call 2 */
        CHECK_ERROR(_readMethod_utility_batch_all_V3(c, &method->basic.utility_batch_all_V3))
        break;
    case 6400: /* module 25 call 0 */
        CHECK_ERROR(_readMethod_identity_add_registrar_V3(c, &method->basic.identity_add_registrar_V3))
        break;
    case 6401: /* module 25 call 1 */
        CHECK_ERROR(_readMethod_identity_set_identity_V3(c, &method->basic.identity_set_identity_V3))
        break;
    case 6402: /* module 25 call 2 */
        CHECK_ERROR(_readMethod_identity_set_subs_V3(c, &method->basic.identity_set_subs_V3))
        break;
    case 6403: /* module 25 call 3 */
        CHECK_ERROR(_readMethod_identity_clear_identity_V3(c, &method->basic.identity_clear_identity_V3))
        break;
    case 6404: /* module 25 call 4 */
        CHECK_ERROR(_readMethod_identity_request_judgement_V3(c, &method->basic.identity_request_judgement_V3))
        break;
    case 6405: /* module 25 call 5 */
        CHECK_ERROR(_readMethod_identity_cancel_request_V3(c, &method->basic.identity_cancel_request_V3))
        break;
    case 6406: /* module 25 call 6 */
        CHECK_ERROR(_readMethod_identity_set_fee_V3(c, &method->basic.identity_set_fee_V3))
        break;
    case 6407: /* module 25 call 7 */
        CHECK_ERROR(_readMethod_identity_set_account_id_V3(c, &method->basic.identity_set_account_id_V3))
        break;
    case 6408: /* module 25 call 8 */
        CHECK_ERROR(_readMethod_identity_set_fields_V3(c, &method->basic.identity_set_fields_V3))
        break;
    case 6409: /* module 25 call 9 */
        CHECK_ERROR(_readMethod_identity_provide_judgement_V3(c, &method->basic.identity_provide_judgement_V3))
        break;
    case 6410: /* module 25 call 10 */
        CHECK_ERROR(_readMethod_identity_kill_identity_V3(c, &method->basic.identity_kill_identity_V3))
        break;
    case 6411: /* module 25 call 11 */
        CHECK_ERROR(_readMethod_identity_add_sub_V3(c, &method->basic.identity_add_sub_V3))
        break;
    case 6412: /* module 25 call 12 */
        CHECK_ERROR(_readMethod_identity_rename_sub_V3(c, &method->basic.identity_rename_sub_V3))
        break;
    case 6413: /* module 25 call 13 */
        CHECK_ERROR(_readMethod_identity_remove_sub_V3(c, &method->basic.identity_remove_sub_V3))
        break;
    case 6414: /* module 25 call 14 */
        CHECK_ERROR(_readMethod_identity_quit_sub_V3(c, &method->basic.identity_quit_sub_V3))
        break;
    case 6656: /* module 26 call 0 */
        CHECK_ERROR(_readMethod_society_bid_V3(c, &method->basic.society_bid_V3))
        break;
    case 6657: /* module 26 call 1 */
        CHECK_ERROR(_readMethod_society_unbid_V3(c, &method->basic.society_unbid_V3))
        break;
    case 6658: /* module 26 call 2 */
        CHECK_ERROR(_readMethod_society_vouch_V3(c, &method->basic.society_vouch_V3))
        break;
    case 6659: /* module 26 call 3 */
        CHECK_ERROR(_readMethod_society_unvouch_V3(c, &method->basic.society_unvouch_V3))
        break;
    case 6660: /* module 26 call 4 */
        CHECK_ERROR(_readMethod_society_vote_V3(c, &method->basic.society_vote_V3))
        break;
    case 6661: /* module 26 call 5 */
        CHECK_ERROR(_readMethod_society_defender_vote_V3(c, &method->basic.society_defender_vote_V3))
        break;
    case 6662: /* module 26 call 6 */
        CHECK_ERROR(_readMethod_society_payout_V3(c, &method->basic.society_payout_V3))
        break;
    case 6663: /* module 26 call 7 */
        CHECK_ERROR(_readMethod_society_found_V3(c, &method->basic.society_found_V3))
        break;
    case 6664: /* module 26 call 8 */
        CHECK_ERROR(_readMethod_society_unfound_V3(c, &method->basic.society_unfound_V3))
        break;
    case 6665: /* module 26 call 9 */
        CHECK_ERROR(_readMethod_society_judge_suspended_member_V3(c, &method->basic.society_judge_suspended_member_V3))
        break;
    case 6666: /* module 26 call 10 */
        CHECK_ERROR(_readMethod_society_judge_suspended_candidate_V3(c, &method->basic.society_judge_suspended_candidate_V3))
        break;
    case 6667: /* module 26 call 11 */
        CHECK_ERROR(_readMethod_society_set_max_members_V3(c, &method->basic.society_set_max_members_V3))
        break;
    case 6912: /* module 27 call 0 */
        CHECK_ERROR(_readMethod_recovery_as_recovered_V3(c, &method->basic.recovery_as_recovered_V3))
        break;
    case 6913: /* module 27 call 1 */
        CHECK_ERROR(_readMethod_recovery_set_recovered_V3(c, &method->basic.recovery_set_recovered_V3))
        break;
    case 6914: /* module 27 call 2 */
        CHECK_ERROR(_readMethod_recovery_create_recovery_V3(c, &method->basic.recovery_create_recovery_V3))
        break;
    case 6915: /* module 27 call 3 */
        CHECK_ERROR(_readMethod_recovery_initiate_recovery_V3(c, &method->basic.recovery_initiate_recovery_V3))
        break;
    case 6916: /* module 27 call 4 */
        CHECK_ERROR(_readMethod_recovery_vouch_recovery_V3(c, &method->basic.recovery_vouch_recovery_V3))
        break;
    case 6917: /* module 27 call 5 */
        CHECK_ERROR(_readMethod_recovery_claim_recovery_V3(c, &method->basic.recovery_claim_recovery_V3))
        break;
    case 6918: /* module 27 call 6 */
        CHECK_ERROR(_readMethod_recovery_close_recovery_V3(c, &method->basic.recovery_close_recovery_V3))
        break;
    case 6919: /* module 27 call 7 */
        CHECK_ERROR(_readMethod_recovery_remove_recovery_V3(c, &method->basic.recovery_remove_recovery_V3))
        break;
    case 6920: /* module 27 call 8 */
        CHECK_ERROR(_readMethod_recovery_cancel_recovered_V3(c, &method->basic.recovery_cancel_recovered_V3))
        break;
    case 7168: /* module 28 call 0 */
        CHECK_ERROR(_readMethod_vesting_vest_V3(c, &method->basic.vesting_vest_V3))
        break;
    case 7169: /* module 28 call 1 */
        CHECK_ERROR(_readMethod_vesting_vest_other_V3(c, &method->basic.vesting_vest_other_V3))
        break;
    case 7170: /* module 28 call 2 */
        CHECK_ERROR(_readMethod_vesting_vested_transfer_V3(c, &method->basic.vesting_vested_transfer_V3))
        break;
    case 7171: /* module 28 call 3 */
        CHECK_ERROR(_readMethod_vesting_force_vested_transfer_V3(c, &method->basic.vesting_force_vested_transfer_V3))
        break;
    case 7424: /* module 29 call 0 */
        CHECK_ERROR(_readMethod_scheduler_schedule_V3(c, &method->basic.scheduler_schedule_V3))
        break;
    case 7425: /* module 29 call 1 */
        CHECK_ERROR(_readMethod_scheduler_cancel_V3(c, &method->basic.scheduler_cancel_V3))
        break;
    case 7426: /* module 29 call 2 */
        CHECK_ERROR(_readMethod_scheduler_schedule_named_V3(c, &method->basic.scheduler_schedule_named_V3))
        break;
    case 7427: /* module 29 call 3 */
        CHECK_ERROR(_readMethod_scheduler_cancel_named_V3(c, &method->basic.scheduler_cancel_named_V3))
        break;
    case 7428: /* module 29 call 4 */
        CHECK_ERROR(_readMethod_scheduler_schedule_after_V3(c, &method->basic.scheduler_schedule_after_V3))
        break;
    case 7429: /* module 29 call 5 */
        CHECK_ERROR(_readMethod_scheduler_schedule_named_after_V3(c, &method->basic.scheduler_schedule_named_after_V3))
        break;
    case 7680: /* module 30 call 0 */
        CHECK_ERROR(_readMethod_proxy_proxy_V3(c, &method->basic.proxy_proxy_V3))
        break;
    case 7681: /* module 30 call 1 */
        CHECK_ERROR(_readMethod_proxy_add_proxy_V3(c, &method->basic.proxy_add_proxy_V3))
        break;
    case 7682: /* module 30 call 2 */
        CHECK_ERROR(_readMethod_proxy_remove_proxy_V3(c, &method->basic.proxy_remove_proxy_V3))
        break;
    case 7683: /* module 30 call 3 */
        CHECK_ERROR(_readMethod_proxy_remove_proxies_V3(c, &method->basic.proxy_remove_proxies_V3))
        break;
    case 7684: /* module 30 call 4 */
        CHECK_ERROR(_readMethod_proxy_anonymous_V3(c, &method->basic.proxy_anonymous_V3))
        break;
    case 7685: /* module 30 call 5 */
        CHECK_ERROR(_readMethod_proxy_kill_anonymous_V3(c, &method->basic.proxy_kill_anonymous_V3))
        break;
    case 7686: /* module 30 call 6 */
        CHECK_ERROR(_readMethod_proxy_announce_V3(c, &method->basic.proxy_announce_V3))
        break;
    case 7687: /* module 30 call 7 */
        CHECK_ERROR(_readMethod_proxy_remove_announcement_V3(c, &method->basic.proxy_remove_announcement_V3))
        break;
    case 7688: /* module 30 call 8 */
        CHECK_ERROR(_readMethod_proxy_reject_announcement_V3(c, &method->basic.proxy_reject_announcement_V3))
        break;
    case 7689: /* module 30 call 9 */
        CHECK_ERROR(_readMethod_proxy_proxy_announced_V3(c, &method->basic.proxy_proxy_announced_V3))
        break;
    case 7936: /* module 31 call 0 */
        CHECK_ERROR(_readMethod_multisig_as_multi_threshold_1_V3(c, &method->basic.multisig_as_multi_threshold_1_V3))
        break;
    case 7937: /* module 31 call 1 */
        CHECK_ERROR(_readMethod_multisig_as_multi_V3(c, &method->basic.multisig_as_multi_V3))
        break;
    case 7938: /* module 31 call 2 */
        CHECK_ERROR(_readMethod_multisig_approve_as_multi_V3(c, &method->basic.multisig_approve_as_multi_V3))
        break;
    case 7939: /* module 31 call 3 */
        CHECK_ERROR(_readMethod_multisig_cancel_as_multi_V3(c, &method->basic.multisig_cancel_as_multi_V3))
        break;
    default:
        return parser_unexpected_callIndex;
    }

    return parser_ok;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

const char* _getMethod_ModuleName_V3(uint8_t moduleIdx)
{
    switch (moduleIdx) {
    case 0:
        return "System";
    case 1:
        return "Babe";
    case 2:
        return "Timestamp";
    case 3:
        return "Indices";
    case 4:
        return "Balances";
    case 5:
        return "Authorship";
    case 6:
        return "Staking";
    case 7:
        return "Offences";
    case 8:
        return "Session";
    case 10:
        return "Grandpa";
    case 11:
        return "Imonline";
    case 12:
        return "Authoritydiscovery";
    case 13:
        return "Democracy";
    case 14:
        return "Council";
    case 15:
        return "Technicalcommittee";
    case 16:
        return "Electionsphragmen";
    case 17:
        return "Technicalmembership";
    case 18:
        return "Treasury";
    case 19:
        return "Claims";
    case 24:
        return "Utility";
    case 25:
        return "Identity";
    case 26:
        return "Society";
    case 27:
        return "Recovery";
    case 28:
        return "Vesting";
    case 29:
        return "Scheduler";
    case 30:
        return "Proxy";
    case 31:
        return "Multisig";
    default:
        return NULL;
    }

    return NULL;
}

const char* _getMethod_Name_V3(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 0: /* module 0 call 0 */
        return "Fill block";
    case 1: /* module 0 call 1 */
        return "Remark";
    case 2: /* module 0 call 2 */
        return "Set heap pages";
    case 3: /* module 0 call 3 */
        return "Set code";
    case 4: /* module 0 call 4 */
        return "Set code without checks";
    case 5: /* module 0 call 5 */
        return "Set changes trie config";
    case 6: /* module 0 call 6 */
        return "Set storage";
    case 7: /* module 0 call 7 */
        return "Kill storage";
    case 8: /* module 0 call 8 */
        return "Kill prefix";
    case 9: /* module 0 call 9 */
        return "Suicide";
    case 256: /* module 1 call 0 */
        return "Report equivocation";
    case 257: /* module 1 call 1 */
        return "Report equivocation unsigned";
    case 512: /* module 2 call 0 */
        return "Set";
    case 768: /* module 3 call 0 */
        return "Claim";
    case 769: /* module 3 call 1 */
        return "Transfer";
    case 770: /* module 3 call 2 */
        return "Free";
    case 771: /* module 3 call 3 */
        return "Force transfer";
    case 772: /* module 3 call 4 */
        return "Freeze";
    case 1024: /* module 4 call 0 */
        return "Transfer";
    case 1025: /* module 4 call 1 */
        return "Set balance";
    case 1026: /* module 4 call 2 */
        return "Force transfer";
    case 1027: /* module 4 call 3 */
        return "Transfer keep alive";
    case 1280: /* module 5 call 0 */
        return "Set uncles";
    case 1536: /* module 6 call 0 */
        return "Bond";
    case 1537: /* module 6 call 1 */
        return "Bond extra";
    case 1538: /* module 6 call 2 */
        return "Unbond";
    case 1539: /* module 6 call 3 */
        return "Withdraw unbonded";
    case 1540: /* module 6 call 4 */
        return "Validate";
    case 1541: /* module 6 call 5 */
        return "Nominate";
    case 1542: /* module 6 call 6 */
        return "Chill";
    case 1543: /* module 6 call 7 */
        return "Set payee";
    case 1544: /* module 6 call 8 */
        return "Set controller";
    case 1545: /* module 6 call 9 */
        return "Set validator count";
    case 1546: /* module 6 call 10 */
        return "Increase validator count";
    case 1547: /* module 6 call 11 */
        return "Scale validator count";
    case 1548: /* module 6 call 12 */
        return "Force no eras";
    case 1549: /* module 6 call 13 */
        return "Force new era";
    case 1550: /* module 6 call 14 */
        return "Set invulnerables";
    case 1551: /* module 6 call 15 */
        return "Force unstake";
    case 1552: /* module 6 call 16 */
        return "Force new era always";
    case 1553: /* module 6 call 17 */
        return "Cancel deferred slash";
    case 1554: /* module 6 call 18 */
        return "Payout stakers";
    case 1555: /* module 6 call 19 */
        return "Rebond";
    case 1556: /* module 6 call 20 */
        return "Set history depth";
    case 1557: /* module 6 call 21 */
        return "Reap stash";
    case 1558: /* module 6 call 22 */
        return "Submit election solution";
    case 1559: /* module 6 call 23 */
        return "Submit election solution unsigned";
    case 2048: /* module 8 call 0 */
        return "Set keys";
    case 2049: /* module 8 call 1 */
        return "Purge keys";
    case 2560: /* module 10 call 0 */
        return "Report equivocation";
    case 2561: /* module 10 call 1 */
        return "Report equivocation unsigned";
    case 2562: /* module 10 call 2 */
        return "Note stalled";
    case 2816: /* module 11 call 0 */
        return "Heartbeat";
    case 3328: /* module 13 call 0 */
        return "Propose";
    case 3329: /* module 13 call 1 */
        return "Second";
    case 3330: /* module 13 call 2 */
        return "Vote";
    case 3331: /* module 13 call 3 */
        return "Emergency cancel";
    case 3332: /* module 13 call 4 */
        return "External propose";
    case 3333: /* module 13 call 5 */
        return "External propose majority";
    case 3334: /* module 13 call 6 */
        return "External propose default";
    case 3335: /* module 13 call 7 */
        return "Fast track";
    case 3336: /* module 13 call 8 */
        return "Veto external";
    case 3337: /* module 13 call 9 */
        return "Cancel referendum";
    case 3338: /* module 13 call 10 */
        return "Cancel queued";
    case 3339: /* module 13 call 11 */
        return "Delegate";
    case 3340: /* module 13 call 12 */
        return "Undelegate";
    case 3341: /* module 13 call 13 */
        return "Clear public proposals";
    case 3342: /* module 13 call 14 */
        return "Note preimage";
    case 3343: /* module 13 call 15 */
        return "Note preimage operational";
    case 3344: /* module 13 call 16 */
        return "Note imminent preimage";
    case 3345: /* module 13 call 17 */
        return "Note imminent preimage operational";
    case 3346: /* module 13 call 18 */
        return "Reap preimage";
    case 3347: /* module 13 call 19 */
        return "Unlock";
    case 3348: /* module 13 call 20 */
        return "Remove vote";
    case 3349: /* module 13 call 21 */
        return "Remove other vote";
    case 3350: /* module 13 call 22 */
        return "Enact proposal";
    case 3351: /* module 13 call 23 */
        return "Blacklist";
    case 3352: /* module 13 call 24 */
        return "Cancel proposal";
    case 3584: /* module 14 call 0 */
        return "Set members";
    case 3585: /* module 14 call 1 */
        return "Execute";
    case 3586: /* module 14 call 2 */
        return "Propose";
    case 3587: /* module 14 call 3 */
        return "Vote";
    case 3588: /* module 14 call 4 */
        return "Close";
    case 3589: /* module 14 call 5 */
        return "Disapprove proposal";
    case 3840: /* module 15 call 0 */
        return "Set members";
    case 3841: /* module 15 call 1 */
        return "Execute";
    case 3842: /* module 15 call 2 */
        return "Propose";
    case 3843: /* module 15 call 3 */
        return "Vote";
    case 3844: /* module 15 call 4 */
        return "Close";
    case 3845: /* module 15 call 5 */
        return "Disapprove proposal";
    case 4096: /* module 16 call 0 */
        return "Vote";
    case 4097: /* module 16 call 1 */
        return "Remove voter";
    case 4098: /* module 16 call 2 */
        return "Report defunct voter";
    case 4099: /* module 16 call 3 */
        return "Submit candidacy";
    case 4100: /* module 16 call 4 */
        return "Renounce candidacy";
    case 4101: /* module 16 call 5 */
        return "Remove member";
    case 4352: /* module 17 call 0 */
        return "Add member";
    case 4353: /* module 17 call 1 */
        return "Remove member";
    case 4354: /* module 17 call 2 */
        return "Swap member";
    case 4355: /* module 17 call 3 */
        return "Reset members";
    case 4356: /* module 17 call 4 */
        return "Change key";
    case 4357: /* module 17 call 5 */
        return "Set prime";
    case 4358: /* module 17 call 6 */
        return "Clear prime";
    case 4608: /* module 18 call 0 */
        return "Propose spend";
    case 4609: /* module 18 call 1 */
        return "Reject proposal";
    case 4610: /* module 18 call 2 */
        return "Approve proposal";
    case 4611: /* module 18 call 3 */
        return "Report awesome";
    case 4612: /* module 18 call 4 */
        return "Retract tip";
    case 4613: /* module 18 call 5 */
        return "Tip new";
    case 4614: /* module 18 call 6 */
        return "Tip";
    case 4615: /* module 18 call 7 */
        return "Close tip";
    case 4616: /* module 18 call 8 */
        return "Propose bounty";
    case 4617: /* module 18 call 9 */
        return "Approve bounty";
    case 4618: /* module 18 call 10 */
        return "Propose curator";
    case 4619: /* module 18 call 11 */
        return "Unassign curator";
    case 4620: /* module 18 call 12 */
        return "Accept curator";
    case 4621: /* module 18 call 13 */
        return "Award bounty";
    case 4622: /* module 18 call 14 */
        return "Claim bounty";
    case 4623: /* module 18 call 15 */
        return "Close bounty";
    case 4624: /* module 18 call 16 */
        return "Extend bounty expiry";
    case 4864: /* module 19 call 0 */
        return "Claim";
    case 4865: /* module 19 call 1 */
        return "Mint claim";
    case 4866: /* module 19 call 2 */
        return "Claim attest";
    case 4867: /* module 19 call 3 */
        return "Attest";
    case 4868: /* module 19 call 4 */
        return "Move claim";
    case 6144: /* module 24 call 0 */
        return "Batch";
    case 6145: /* module 24 call 1 */
        return "As derivative";
    case 6146: /* module 24 call 2 */
        return "Batch all";
    case 6400: /* module 25 call 0 */
        return "Add registrar";
    case 6401: /* module 25 call 1 */
        return "Set identity";
    case 6402: /* module 25 call 2 */
        return "Set subs";
    case 6403: /* module 25 call 3 */
        return "Clear identity";
    case 6404: /* module 25 call 4 */
        return "Request judgement";
    case 6405: /* module 25 call 5 */
        return "Cancel request";
    case 6406: /* module 25 call 6 */
        return "Set fee";
    case 6407: /* module 25 call 7 */
        return "Set account id";
    case 6408: /* module 25 call 8 */
        return "Set fields";
    case 6409: /* module 25 call 9 */
        return "Provide judgement";
    case 6410: /* module 25 call 10 */
        return "Kill identity";
    case 6411: /* module 25 call 11 */
        return "Add sub";
    case 6412: /* module 25 call 12 */
        return "Rename sub";
    case 6413: /* module 25 call 13 */
        return "Remove sub";
    case 6414: /* module 25 call 14 */
        return "Quit sub";
    case 6656: /* module 26 call 0 */
        return "Bid";
    case 6657: /* module 26 call 1 */
        return "Unbid";
    case 6658: /* module 26 call 2 */
        return "Vouch";
    case 6659: /* module 26 call 3 */
        return "Unvouch";
    case 6660: /* module 26 call 4 */
        return "Vote";
    case 6661: /* module 26 call 5 */
        return "Defender vote";
    case 6662: /* module 26 call 6 */
        return "Payout";
    case 6663: /* module 26 call 7 */
        return "Found";
    case 6664: /* module 26 call 8 */
        return "Unfound";
    case 6665: /* module 26 call 9 */
        return "Judge suspended member";
    case 6666: /* module 26 call 10 */
        return "Judge suspended candidate";
    case 6667: /* module 26 call 11 */
        return "Set max members";
    case 6912: /* module 27 call 0 */
        return "As recovered";
    case 6913: /* module 27 call 1 */
        return "Set recovered";
    case 6914: /* module 27 call 2 */
        return "Create recovery";
    case 6915: /* module 27 call 3 */
        return "Initiate recovery";
    case 6916: /* module 27 call 4 */
        return "Vouch recovery";
    case 6917: /* module 27 call 5 */
        return "Claim recovery";
    case 6918: /* module 27 call 6 */
        return "Close recovery";
    case 6919: /* module 27 call 7 */
        return "Remove recovery";
    case 6920: /* module 27 call 8 */
        return "Cancel recovered";
    case 7168: /* module 28 call 0 */
        return "Vest";
    case 7169: /* module 28 call 1 */
        return "Vest other";
    case 7170: /* module 28 call 2 */
        return "Vested transfer";
    case 7171: /* module 28 call 3 */
        return "Force vested transfer";
    case 7424: /* module 29 call 0 */
        return "Schedule";
    case 7425: /* module 29 call 1 */
        return "Cancel";
    case 7426: /* module 29 call 2 */
        return "Schedule named";
    case 7427: /* module 29 call 3 */
        return "Cancel named";
    case 7428: /* module 29 call 4 */
        return "Schedule after";
    case 7429: /* module 29 call 5 */
        return "Schedule named after";
    case 7680: /* module 30 call 0 */
        return "Proxy";
    case 7681: /* module 30 call 1 */
        return "Add proxy";
    case 7682: /* module 30 call 2 */
        return "Remove proxy";
    case 7683: /* module 30 call 3 */
        return "Remove proxies";
    case 7684: /* module 30 call 4 */
        return "Anonymous";
    case 7685: /* module 30 call 5 */
        return "Kill anonymous";
    case 7686: /* module 30 call 6 */
        return "Announce";
    case 7687: /* module 30 call 7 */
        return "Remove announcement";
    case 7688: /* module 30 call 8 */
        return "Reject announcement";
    case 7689: /* module 30 call 9 */
        return "Proxy announced";
    case 7936: /* module 31 call 0 */
        return "As multi threshold 1";
    case 7937: /* module 31 call 1 */
        return "As multi";
    case 7938: /* module 31 call 2 */
        return "Approve as multi";
    case 7939: /* module 31 call 3 */
        return "Cancel as multi";
    default:
        return NULL;
    }

    return NULL;
}

uint8_t _getMethod_NumItems_V3(uint8_t moduleIdx, uint8_t callIdx, pd_Method_V3_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 0: /* module 0 call 0 */
        return 1;
    case 1: /* module 0 call 1 */
        return 1;
    case 2: /* module 0 call 2 */
        return 1;
    case 3: /* module 0 call 3 */
        return 1;
    case 4: /* module 0 call 4 */
        return 1;
    case 5: /* module 0 call 5 */
        return 1;
    case 6: /* module 0 call 6 */
        return 1;
    case 7: /* module 0 call 7 */
        return 1;
    case 8: /* module 0 call 8 */
        return 2;
    case 9: /* module 0 call 9 */
        return 0;
    case 256: /* module 1 call 0 */
        return 2;
    case 257: /* module 1 call 1 */
        return 2;
    case 512: /* module 2 call 0 */
        return 1;
    case 768: /* module 3 call 0 */
        return 1;
    case 769: /* module 3 call 1 */
        return 2;
    case 770: /* module 3 call 2 */
        return 1;
    case 771: /* module 3 call 3 */
        return 3;
    case 772: /* module 3 call 4 */
        return 1;
    case 1024: /* module 4 call 0 */
        return 2;
    case 1025: /* module 4 call 1 */
        return 3;
    case 1026: /* module 4 call 2 */
        return 3;
    case 1027: /* module 4 call 3 */
        return 2;
    case 1280: /* module 5 call 0 */
        return 1;
    case 1536: /* module 6 call 0 */
        return 3;
    case 1537: /* module 6 call 1 */
        return 1;
    case 1538: /* module 6 call 2 */
        return 1;
    case 1539: /* module 6 call 3 */
        return 1;
    case 1540: /* module 6 call 4 */
        return 1;
    case 1541: /* module 6 call 5 */
        return 1;
    case 1542: /* module 6 call 6 */
        return 0;
    case 1543: /* module 6 call 7 */
        return 1;
    case 1544: /* module 6 call 8 */
        return 1;
    case 1545: /* module 6 call 9 */
        return 1;
    case 1546: /* module 6 call 10 */
        return 1;
    case 1547: /* module 6 call 11 */
        return 1;
    case 1548: /* module 6 call 12 */
        return 0;
    case 1549: /* module 6 call 13 */
        return 0;
    case 1550: /* module 6 call 14 */
        return 1;
    case 1551: /* module 6 call 15 */
        return 2;
    case 1552: /* module 6 call 16 */
        return 0;
    case 1553: /* module 6 call 17 */
        return 2;
    case 1554: /* module 6 call 18 */
        return 2;
    case 1555: /* module 6 call 19 */
        return 1;
    case 1556: /* module 6 call 20 */
        return 2;
    case 1557: /* module 6 call 21 */
        return 2;
    case 1558: /* module 6 call 22 */
        return 5;
    case 1559: /* module 6 call 23 */
        return 5;
    case 2048: /* module 8 call 0 */
        return 2;
    case 2049: /* module 8 call 1 */
        return 0;
    case 2560: /* module 10 call 0 */
        return 2;
    case 2561: /* module 10 call 1 */
        return 2;
    case 2562: /* module 10 call 2 */
        return 2;
    case 2816: /* module 11 call 0 */
        return 2;
    case 3328: /* module 13 call 0 */
        return 2;
    case 3329: /* module 13 call 1 */
        return 2;
    case 3330: /* module 13 call 2 */
        return 2;
    case 3331: /* module 13 call 3 */
        return 1;
    case 3332: /* module 13 call 4 */
        return 1;
    case 3333: /* module 13 call 5 */
        return 1;
    case 3334: /* module 13 call 6 */
        return 1;
    case 3335: /* module 13 call 7 */
        return 3;
    case 3336: /* module 13 call 8 */
        return 1;
    case 3337: /* module 13 call 9 */
        return 1;
    case 3338: /* module 13 call 10 */
        return 1;
    case 3339: /* module 13 call 11 */
        return 3;
    case 3340: /* module 13 call 12 */
        return 0;
    case 3341: /* module 13 call 13 */
        return 0;
    case 3342: /* module 13 call 14 */
        return 1;
    case 3343: /* module 13 call 15 */
        return 1;
    case 3344: /* module 13 call 16 */
        return 1;
    case 3345: /* module 13 call 17 */
        return 1;
    case 3346: /* module 13 call 18 */
        return 2;
    case 3347: /* module 13 call 19 */
        return 1;
    case 3348: /* module 13 call 20 */
        return 1;
    case 3349: /* module 13 call 21 */
        return 2;
    case 3350: /* module 13 call 22 */
        return 2;
    case 3351: /* module 13 call 23 */
        return 2;
    case 3352: /* module 13 call 24 */
        return 1;
    case 3584: /* module 14 call 0 */
        return 3;
    case 3585: /* module 14 call 1 */
        return 2;
    case 3586: /* module 14 call 2 */
        return 3;
    case 3587: /* module 14 call 3 */
        return 3;
    case 3588: /* module 14 call 4 */
        return 4;
    case 3589: /* module 14 call 5 */
        return 1;
    case 3840: /* module 15 call 0 */
        return 3;
    case 3841: /* module 15 call 1 */
        return 2;
    case 3842: /* module 15 call 2 */
        return 3;
    case 3843: /* module 15 call 3 */
        return 3;
    case 3844: /* module 15 call 4 */
        return 4;
    case 3845: /* module 15 call 5 */
        return 1;
    case 4096: /* module 16 call 0 */
        return 2;
    case 4097: /* module 16 call 1 */
        return 0;
    case 4098: /* module 16 call 2 */
        return 1;
    case 4099: /* module 16 call 3 */
        return 1;
    case 4100: /* module 16 call 4 */
        return 1;
    case 4101: /* module 16 call 5 */
        return 2;
    case 4352: /* module 17 call 0 */
        return 1;
    case 4353: /* module 17 call 1 */
        return 1;
    case 4354: /* module 17 call 2 */
        return 2;
    case 4355: /* module 17 call 3 */
        return 1;
    case 4356: /* module 17 call 4 */
        return 1;
    case 4357: /* module 17 call 5 */
        return 1;
    case 4358: /* module 17 call 6 */
        return 0;
    case 4608: /* module 18 call 0 */
        return 2;
    case 4609: /* module 18 call 1 */
        return 1;
    case 4610: /* module 18 call 2 */
        return 1;
    case 4611: /* module 18 call 3 */
        return 2;
    case 4612: /* module 18 call 4 */
        return 1;
    case 4613: /* module 18 call 5 */
        return 3;
    case 4614: /* module 18 call 6 */
        return 2;
    case 4615: /* module 18 call 7 */
        return 1;
    case 4616: /* module 18 call 8 */
        return 2;
    case 4617: /* module 18 call 9 */
        return 1;
    case 4618: /* module 18 call 10 */
        return 3;
    case 4619: /* module 18 call 11 */
        return 1;
    case 4620: /* module 18 call 12 */
        return 1;
    case 4621: /* module 18 call 13 */
        return 2;
    case 4622: /* module 18 call 14 */
        return 1;
    case 4623: /* module 18 call 15 */
        return 1;
    case 4624: /* module 18 call 16 */
        return 2;
    case 4864: /* module 19 call 0 */
        return 2;
    case 4865: /* module 19 call 1 */
        return 4;
    case 4866: /* module 19 call 2 */
        return 3;
    case 4867: /* module 19 call 3 */
        return 1;
    case 4868: /* module 19 call 4 */
        return 3;
    case 6144: /* module 24 call 0 */
        return 1;
    case 6145: /* module 24 call 1 */
        return 2;
    case 6146: /* module 24 call 2 */
        return 1;
    case 6400: /* module 25 call 0 */
        return 1;
    case 6401: /* module 25 call 1 */
        return 1;
    case 6402: /* module 25 call 2 */
        return 1;
    case 6403: /* module 25 call 3 */
        return 0;
    case 6404: /* module 25 call 4 */
        return 2;
    case 6405: /* module 25 call 5 */
        return 1;
    case 6406: /* module 25 call 6 */
        return 2;
    case 6407: /* module 25 call 7 */
        return 2;
    case 6408: /* module 25 call 8 */
        return 2;
    case 6409: /* module 25 call 9 */
        return 3;
    case 6410: /* module 25 call 10 */
        return 1;
    case 6411: /* module 25 call 11 */
        return 2;
    case 6412: /* module 25 call 12 */
        return 2;
    case 6413: /* module 25 call 13 */
        return 1;
    case 6414: /* module 25 call 14 */
        return 0;
    case 6656: /* module 26 call 0 */
        return 1;
    case 6657: /* module 26 call 1 */
        return 1;
    case 6658: /* module 26 call 2 */
        return 3;
    case 6659: /* module 26 call 3 */
        return 1;
    case 6660: /* module 26 call 4 */
        return 2;
    case 6661: /* module 26 call 5 */
        return 1;
    case 6662: /* module 26 call 6 */
        return 0;
    case 6663: /* module 26 call 7 */
        return 3;
    case 6664: /* module 26 call 8 */
        return 0;
    case 6665: /* module 26 call 9 */
        return 2;
    case 6666: /* module 26 call 10 */
        return 2;
    case 6667: /* module 26 call 11 */
        return 1;
    case 6912: /* module 27 call 0 */
        return 2;
    case 6913: /* module 27 call 1 */
        return 2;
    case 6914: /* module 27 call 2 */
        return 3;
    case 6915: /* module 27 call 3 */
        return 1;
    case 6916: /* module 27 call 4 */
        return 2;
    case 6917: /* module 27 call 5 */
        return 1;
    case 6918: /* module 27 call 6 */
        return 1;
    case 6919: /* module 27 call 7 */
        return 0;
    case 6920: /* module 27 call 8 */
        return 1;
    case 7168: /* module 28 call 0 */
        return 0;
    case 7169: /* module 28 call 1 */
        return 1;
    case 7170: /* module 28 call 2 */
        return 2;
    case 7171: /* module 28 call 3 */
        return 3;
    case 7424: /* module 29 call 0 */
        return 4;
    case 7425: /* module 29 call 1 */
        return 2;
    case 7426: /* module 29 call 2 */
        return 5;
    case 7427: /* module 29 call 3 */
        return 1;
    case 7428: /* module 29 call 4 */
        return 4;
    case 7429: /* module 29 call 5 */
        return 5;
    case 7680: /* module 30 call 0 */
        return 3;
    case 7681: /* module 30 call 1 */
        return 3;
    case 7682: /* module 30 call 2 */
        return 3;
    case 7683: /* module 30 call 3 */
        return 0;
    case 7684: /* module 30 call 4 */
        return 3;
    case 7685: /* module 30 call 5 */
        return 5;
    case 7686: /* module 30 call 6 */
        return 2;
    case 7687: /* module 30 call 7 */
        return 2;
    case 7688: /* module 30 call 8 */
        return 2;
    case 7689: /* module 30 call 9 */
        return 4;
    case 7936: /* module 31 call 0 */
        return 2;
    case 7937: /* module 31 call 1 */
        return 6;
    case 7938: /* module 31 call 2 */
        return 5;
    case 7939: /* module 31 call 3 */
        return 4;
    default:
        return 0;
    }

    return 0;
}

const char* _getMethod_ItemName_V3(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0:
            return "Ratio";
        default:
            return NULL;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0:
            return "Remark";
        default:
            return NULL;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0:
            return "Pages";
        default:
            return NULL;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0:
            return "Code";
        default:
            return NULL;
        }
    case 4: /* module 0 call 4 */
        switch (itemIdx) {
        case 0:
            return "Code";
        default:
            return NULL;
        }
    case 5: /* module 0 call 5 */
        switch (itemIdx) {
        case 0:
            return "Changes trie config";
        default:
            return NULL;
        }
    case 6: /* module 0 call 6 */
        switch (itemIdx) {
        case 0:
            return "Items";
        default:
            return NULL;
        }
    case 7: /* module 0 call 7 */
        switch (itemIdx) {
        case 0:
            return "Keys";
        default:
            return NULL;
        }
    case 8: /* module 0 call 8 */
        switch (itemIdx) {
        case 0:
            return "Prefix";
        case 1:
            return "Subkeys";
        default:
            return NULL;
        }
    case 9: /* module 0 call 9 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 256: /* module 1 call 0 */
        switch (itemIdx) {
        case 0:
            return "Equivocation proof";
        case 1:
            return "Key owner proof";
        default:
            return NULL;
        }
    case 257: /* module 1 call 1 */
        switch (itemIdx) {
        case 0:
            return "Equivocation proof";
        case 1:
            return "Key owner proof";
        default:
            return NULL;
        }
    case 512: /* module 2 call 0 */
        switch (itemIdx) {
        case 0:
            return "Now";
        default:
            return NULL;
        }
    case 768: /* module 3 call 0 */
        switch (itemIdx) {
        case 0:
            return "Index";
        default:
            return NULL;
        }
    case 769: /* module 3 call 1 */
        switch (itemIdx) {
        case 0:
            return "New";
        case 1:
            return "Index";
        default:
            return NULL;
        }
    case 770: /* module 3 call 2 */
        switch (itemIdx) {
        case 0:
            return "Index";
        default:
            return NULL;
        }
    case 771: /* module 3 call 3 */
        switch (itemIdx) {
        case 0:
            return "New";
        case 1:
            return "Index";
        case 2:
            return "Freeze";
        default:
            return NULL;
        }
    case 772: /* module 3 call 4 */
        switch (itemIdx) {
        case 0:
            return "Index";
        default:
            return NULL;
        }
    case 1024: /* module 4 call 0 */
        switch (itemIdx) {
        case 0:
            return "Dest";
        case 1:
            return "Amount";
        default:
            return NULL;
        }
    case 1025: /* module 4 call 1 */
        switch (itemIdx) {
        case 0:
            return "Who";
        case 1:
            return "New free";
        case 2:
            return "New reserved";
        default:
            return NULL;
        }
    case 1026: /* module 4 call 2 */
        switch (itemIdx) {
        case 0:
            return "Source";
        case 1:
            return "Dest";
        case 2:
            return "Amount";
        default:
            return NULL;
        }
    case 1027: /* module 4 call 3 */
        switch (itemIdx) {
        case 0:
            return "Dest";
        case 1:
            return "Amount";
        default:
            return NULL;
        }
    case 1280: /* module 5 call 0 */
        switch (itemIdx) {
        case 0:
            return "New uncles";
        default:
            return NULL;
        }
    case 1536: /* module 6 call 0 */
        switch (itemIdx) {
        case 0:
            return "Controller";
        case 1:
            return "Amount";
        case 2:
            return "Payee";
        default:
            return NULL;
        }
    case 1537: /* module 6 call 1 */
        switch (itemIdx) {
        case 0:
            return "Max additional";
        default:
            return NULL;
        }
    case 1538: /* module 6 call 2 */
        switch (itemIdx) {
        case 0:
            return "Amount";
        default:
            return NULL;
        }
    case 1539: /* module 6 call 3 */
        switch (itemIdx) {
        case 0:
            return "Num slashing spans";
        default:
            return NULL;
        }
    case 1540: /* module 6 call 4 */
        switch (itemIdx) {
        case 0:
            return "Prefs";
        default:
            return NULL;
        }
    case 1541: /* module 6 call 5 */
        switch (itemIdx) {
        case 0:
            return "Targets";
        default:
            return NULL;
        }
    case 1542: /* module 6 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 1543: /* module 6 call 7 */
        switch (itemIdx) {
        case 0:
            return "Payee";
        default:
            return NULL;
        }
    case 1544: /* module 6 call 8 */
        switch (itemIdx) {
        case 0:
            return "Controller";
        default:
            return NULL;
        }
    case 1545: /* module 6 call 9 */
        switch (itemIdx) {
        case 0:
            return "New";
        default:
            return NULL;
        }
    case 1546: /* module 6 call 10 */
        switch (itemIdx) {
        case 0:
            return "Additional";
        default:
            return NULL;
        }
    case 1547: /* module 6 call 11 */
        switch (itemIdx) {
        case 0:
            return "Factor";
        default:
            return NULL;
        }
    case 1548: /* module 6 call 12 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 1549: /* module 6 call 13 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 1550: /* module 6 call 14 */
        switch (itemIdx) {
        case 0:
            return "Invulnerables";
        default:
            return NULL;
        }
    case 1551: /* module 6 call 15 */
        switch (itemIdx) {
        case 0:
            return "Stash";
        case 1:
            return "Num slashing spans";
        default:
            return NULL;
        }
    case 1552: /* module 6 call 16 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 1553: /* module 6 call 17 */
        switch (itemIdx) {
        case 0:
            return "Era";
        case 1:
            return "Slash indices";
        default:
            return NULL;
        }
    case 1554: /* module 6 call 18 */
        switch (itemIdx) {
        case 0:
            return "Validator stash";
        case 1:
            return "Era";
        default:
            return NULL;
        }
    case 1555: /* module 6 call 19 */
        switch (itemIdx) {
        case 0:
            return "Amount";
        default:
            return NULL;
        }
    case 1556: /* module 6 call 20 */
        switch (itemIdx) {
        case 0:
            return "New history depth";
        case 1:
            return "Era items deleted";
        default:
            return NULL;
        }
    case 1557: /* module 6 call 21 */
        switch (itemIdx) {
        case 0:
            return "Stash";
        case 1:
            return "Num slashing spans";
        default:
            return NULL;
        }
    case 1558: /* module 6 call 22 */
        switch (itemIdx) {
        case 0:
            return "Winners";
        case 1:
            return "Compact";
        case 2:
            return "Score";
        case 3:
            return "Era";
        case 4:
            return "Size";
        default:
            return NULL;
        }
    case 1559: /* module 6 call 23 */
        switch (itemIdx) {
        case 0:
            return "Winners";
        case 1:
            return "Compact";
        case 2:
            return "Score";
        case 3:
            return "Era";
        case 4:
            return "Size";
        default:
            return NULL;
        }
    case 2048: /* module 8 call 0 */
        switch (itemIdx) {
        case 0:
            return "Keys";
        case 1:
            return "Proof";
        default:
            return NULL;
        }
    case 2049: /* module 8 call 1 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0:
            return "Equivocation proof";
        case 1:
            return "Key owner proof";
        default:
            return NULL;
        }
    case 2561: /* module 10 call 1 */
        switch (itemIdx) {
        case 0:
            return "Equivocation proof";
        case 1:
            return "Key owner proof";
        default:
            return NULL;
        }
    case 2562: /* module 10 call 2 */
        switch (itemIdx) {
        case 0:
            return "Delay";
        case 1:
            return "Best finalized block number";
        default:
            return NULL;
        }
    case 2816: /* module 11 call 0 */
        switch (itemIdx) {
        case 0:
            return "Heartbeat";
        case 1:
            return "Signature";
        default:
            return NULL;
        }
    case 3328: /* module 13 call 0 */
        switch (itemIdx) {
        case 0:
            return "Proposal hash";
        case 1:
            return "Amount";
        default:
            return NULL;
        }
    case 3329: /* module 13 call 1 */
        switch (itemIdx) {
        case 0:
            return "Proposal";
        case 1:
            return "Seconds upper bound";
        default:
            return NULL;
        }
    case 3330: /* module 13 call 2 */
        switch (itemIdx) {
        case 0:
            return "Ref index";
        case 1:
            return "Vote";
        default:
            return NULL;
        }
    case 3331: /* module 13 call 3 */
        switch (itemIdx) {
        case 0:
            return "Ref index";
        default:
            return NULL;
        }
    case 3332: /* module 13 call 4 */
        switch (itemIdx) {
        case 0:
            return "Proposal hash";
        default:
            return NULL;
        }
    case 3333: /* module 13 call 5 */
        switch (itemIdx) {
        case 0:
            return "Proposal hash";
        default:
            return NULL;
        }
    case 3334: /* module 13 call 6 */
        switch (itemIdx) {
        case 0:
            return "Proposal hash";
        default:
            return NULL;
        }
    case 3335: /* module 13 call 7 */
        switch (itemIdx) {
        case 0:
            return "Proposal hash";
        case 1:
            return "Voting period";
        case 2:
            return "Delay";
        default:
            return NULL;
        }
    case 3336: /* module 13 call 8 */
        switch (itemIdx) {
        case 0:
            return "Proposal hash";
        default:
            return NULL;
        }
    case 3337: /* module 13 call 9 */
        switch (itemIdx) {
        case 0:
            return "Ref index";
        default:
            return NULL;
        }
    case 3338: /* module 13 call 10 */
        switch (itemIdx) {
        case 0:
            return "Which";
        default:
            return NULL;
        }
    case 3339: /* module 13 call 11 */
        switch (itemIdx) {
        case 0:
            return "To";
        case 1:
            return "Conviction";
        case 2:
            return "Balance";
        default:
            return NULL;
        }
    case 3340: /* module 13 call 12 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 3341: /* module 13 call 13 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 3342: /* module 13 call 14 */
        switch (itemIdx) {
        case 0:
            return "Encoded proposal";
        default:
            return NULL;
        }
    case 3343: /* module 13 call 15 */
        switch (itemIdx) {
        case 0:
            return "Encoded proposal";
        default:
            return NULL;
        }
    case 3344: /* module 13 call 16 */
        switch (itemIdx) {
        case 0:
            return "Encoded proposal";
        default:
            return NULL;
        }
    case 3345: /* module 13 call 17 */
        switch (itemIdx) {
        case 0:
            return "Encoded proposal";
        default:
            return NULL;
        }
    case 3346: /* module 13 call 18 */
        switch (itemIdx) {
        case 0:
            return "Proposal hash";
        case 1:
            return "Proposal len upper bound";
        default:
            return NULL;
        }
    case 3347: /* module 13 call 19 */
        switch (itemIdx) {
        case 0:
            return "Target";
        default:
            return NULL;
        }
    case 3348: /* module 13 call 20 */
        switch (itemIdx) {
        case 0:
            return "Index";
        default:
            return NULL;
        }
    case 3349: /* module 13 call 21 */
        switch (itemIdx) {
        case 0:
            return "Target";
        case 1:
            return "Index";
        default:
            return NULL;
        }
    case 3350: /* module 13 call 22 */
        switch (itemIdx) {
        case 0:
            return "Proposal hash";
        case 1:
            return "Index";
        default:
            return NULL;
        }
    case 3351: /* module 13 call 23 */
        switch (itemIdx) {
        case 0:
            return "Proposal hash";
        case 1:
            return "Maybe ref index";
        default:
            return NULL;
        }
    case 3352: /* module 13 call 24 */
        switch (itemIdx) {
        case 0:
            return "Prop index";
        default:
            return NULL;
        }
    case 3584: /* module 14 call 0 */
        switch (itemIdx) {
        case 0:
            return "New members";
        case 1:
            return "Prime";
        case 2:
            return "Old count";
        default:
            return NULL;
        }
    case 3585: /* module 14 call 1 */
        switch (itemIdx) {
        case 0:
            return "Proposal";
        case 1:
            return "Length bound";
        default:
            return NULL;
        }
    case 3586: /* module 14 call 2 */
        switch (itemIdx) {
        case 0:
            return "Threshold";
        case 1:
            return "Proposal";
        case 2:
            return "Length bound";
        default:
            return NULL;
        }
    case 3587: /* module 14 call 3 */
        switch (itemIdx) {
        case 0:
            return "Proposal";
        case 1:
            return "Index";
        case 2:
            return "Approve";
        default:
            return NULL;
        }
    case 3588: /* module 14 call 4 */
        switch (itemIdx) {
        case 0:
            return "Proposal hash";
        case 1:
            return "Index";
        case 2:
            return "Proposal weight bound";
        case 3:
            return "Length bound";
        default:
            return NULL;
        }
    case 3589: /* module 14 call 5 */
        switch (itemIdx) {
        case 0:
            return "Proposal hash";
        default:
            return NULL;
        }
    case 3840: /* module 15 call 0 */
        switch (itemIdx) {
        case 0:
            return "New members";
        case 1:
            return "Prime";
        case 2:
            return "Old count";
        default:
            return NULL;
        }
    case 3841: /* module 15 call 1 */
        switch (itemIdx) {
        case 0:
            return "Proposal";
        case 1:
            return "Length bound";
        default:
            return NULL;
        }
    case 3842: /* module 15 call 2 */
        switch (itemIdx) {
        case 0:
            return "Threshold";
        case 1:
            return "Proposal";
        case 2:
            return "Length bound";
        default:
            return NULL;
        }
    case 3843: /* module 15 call 3 */
        switch (itemIdx) {
        case 0:
            return "Proposal";
        case 1:
            return "Index";
        case 2:
            return "Approve";
        default:
            return NULL;
        }
    case 3844: /* module 15 call 4 */
        switch (itemIdx) {
        case 0:
            return "Proposal hash";
        case 1:
            return "Index";
        case 2:
            return "Proposal weight bound";
        case 3:
            return "Length bound";
        default:
            return NULL;
        }
    case 3845: /* module 15 call 5 */
        switch (itemIdx) {
        case 0:
            return "Proposal hash";
        default:
            return NULL;
        }
    case 4096: /* module 16 call 0 */
        switch (itemIdx) {
        case 0:
            return "Votes";
        case 1:
            return "Amount";
        default:
            return NULL;
        }
    case 4097: /* module 16 call 1 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 4098: /* module 16 call 2 */
        switch (itemIdx) {
        case 0:
            return "Defunct";
        default:
            return NULL;
        }
    case 4099: /* module 16 call 3 */
        switch (itemIdx) {
        case 0:
            return "Candidate count";
        default:
            return NULL;
        }
    case 4100: /* module 16 call 4 */
        switch (itemIdx) {
        case 0:
            return "Renouncing";
        default:
            return NULL;
        }
    case 4101: /* module 16 call 5 */
        switch (itemIdx) {
        case 0:
            return "Who";
        case 1:
            return "Has replacement";
        default:
            return NULL;
        }
    case 4352: /* module 17 call 0 */
        switch (itemIdx) {
        case 0:
            return "Who";
        default:
            return NULL;
        }
    case 4353: /* module 17 call 1 */
        switch (itemIdx) {
        case 0:
            return "Who";
        default:
            return NULL;
        }
    case 4354: /* module 17 call 2 */
        switch (itemIdx) {
        case 0:
            return "Remove";
        case 1:
            return "Add";
        default:
            return NULL;
        }
    case 4355: /* module 17 call 3 */
        switch (itemIdx) {
        case 0:
            return "Members";
        default:
            return NULL;
        }
    case 4356: /* module 17 call 4 */
        switch (itemIdx) {
        case 0:
            return "New";
        default:
            return NULL;
        }
    case 4357: /* module 17 call 5 */
        switch (itemIdx) {
        case 0:
            return "Who";
        default:
            return NULL;
        }
    case 4358: /* module 17 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 4608: /* module 18 call 0 */
        switch (itemIdx) {
        case 0:
            return "Amount";
        case 1:
            return "Beneficiary";
        default:
            return NULL;
        }
    case 4609: /* module 18 call 1 */
        switch (itemIdx) {
        case 0:
            return "Proposal id";
        default:
            return NULL;
        }
    case 4610: /* module 18 call 2 */
        switch (itemIdx) {
        case 0:
            return "Proposal id";
        default:
            return NULL;
        }
    case 4611: /* module 18 call 3 */
        switch (itemIdx) {
        case 0:
            return "Reason";
        case 1:
            return "Who";
        default:
            return NULL;
        }
    case 4612: /* module 18 call 4 */
        switch (itemIdx) {
        case 0:
            return "Hash";
        default:
            return NULL;
        }
    case 4613: /* module 18 call 5 */
        switch (itemIdx) {
        case 0:
            return "Reason";
        case 1:
            return "Who";
        case 2:
            return "Tip value";
        default:
            return NULL;
        }
    case 4614: /* module 18 call 6 */
        switch (itemIdx) {
        case 0:
            return "Hash";
        case 1:
            return "Tip value";
        default:
            return NULL;
        }
    case 4615: /* module 18 call 7 */
        switch (itemIdx) {
        case 0:
            return "Hash";
        default:
            return NULL;
        }
    case 4616: /* module 18 call 8 */
        switch (itemIdx) {
        case 0:
            return "Amount";
        case 1:
            return "Description";
        default:
            return NULL;
        }
    case 4617: /* module 18 call 9 */
        switch (itemIdx) {
        case 0:
            return "Bounty id";
        default:
            return NULL;
        }
    case 4618: /* module 18 call 10 */
        switch (itemIdx) {
        case 0:
            return "Bounty id";
        case 1:
            return "Curator";
        case 2:
            return "Fee";
        default:
            return NULL;
        }
    case 4619: /* module 18 call 11 */
        switch (itemIdx) {
        case 0:
            return "Bounty id";
        default:
            return NULL;
        }
    case 4620: /* module 18 call 12 */
        switch (itemIdx) {
        case 0:
            return "Bounty id";
        default:
            return NULL;
        }
    case 4621: /* module 18 call 13 */
        switch (itemIdx) {
        case 0:
            return "Bounty id";
        case 1:
            return "Beneficiary";
        default:
            return NULL;
        }
    case 4622: /* module 18 call 14 */
        switch (itemIdx) {
        case 0:
            return "Bounty id";
        default:
            return NULL;
        }
    case 4623: /* module 18 call 15 */
        switch (itemIdx) {
        case 0:
            return "Bounty id";
        default:
            return NULL;
        }
    case 4624: /* module 18 call 16 */
        switch (itemIdx) {
        case 0:
            return "Bounty id";
        case 1:
            return "Remark";
        default:
            return NULL;
        }
    case 4864: /* module 19 call 0 */
        switch (itemIdx) {
        case 0:
            return "Dest";
        case 1:
            return "Ethereum signature";
        default:
            return NULL;
        }
    case 4865: /* module 19 call 1 */
        switch (itemIdx) {
        case 0:
            return "Who";
        case 1:
            return "Amount";
        case 2:
            return "Vesting schedule";
        case 3:
            return "Statement";
        default:
            return NULL;
        }
    case 4866: /* module 19 call 2 */
        switch (itemIdx) {
        case 0:
            return "Dest";
        case 1:
            return "Ethereum signature";
        case 2:
            return "Statement";
        default:
            return NULL;
        }
    case 4867: /* module 19 call 3 */
        switch (itemIdx) {
        case 0:
            return "Statement";
        default:
            return NULL;
        }
    case 4868: /* module 19 call 4 */
        switch (itemIdx) {
        case 0:
            return "Old";
        case 1:
            return "New";
        case 2:
            return "Maybe preclaim";
        default:
            return NULL;
        }
    case 6144: /* module 24 call 0 */
        switch (itemIdx) {
        case 0:
            return "Calls";
        default:
            return NULL;
        }
    case 6145: /* module 24 call 1 */
        switch (itemIdx) {
        case 0:
            return "Index";
        case 1:
            return "Call";
        default:
            return NULL;
        }
    case 6146: /* module 24 call 2 */
        switch (itemIdx) {
        case 0:
            return "Calls";
        default:
            return NULL;
        }
    case 6400: /* module 25 call 0 */
        switch (itemIdx) {
        case 0:
            return "Account";
        default:
            return NULL;
        }
    case 6401: /* module 25 call 1 */
        switch (itemIdx) {
        case 0:
            return "Info";
        default:
            return NULL;
        }
    case 6402: /* module 25 call 2 */
        switch (itemIdx) {
        case 0:
            return "Subs";
        default:
            return NULL;
        }
    case 6403: /* module 25 call 3 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6404: /* module 25 call 4 */
        switch (itemIdx) {
        case 0:
            return "Reg index";
        case 1:
            return "Max fee";
        default:
            return NULL;
        }
    case 6405: /* module 25 call 5 */
        switch (itemIdx) {
        case 0:
            return "Reg index";
        default:
            return NULL;
        }
    case 6406: /* module 25 call 6 */
        switch (itemIdx) {
        case 0:
            return "Index";
        case 1:
            return "Fee";
        default:
            return NULL;
        }
    case 6407: /* module 25 call 7 */
        switch (itemIdx) {
        case 0:
            return "Index";
        case 1:
            return "New";
        default:
            return NULL;
        }
    case 6408: /* module 25 call 8 */
        switch (itemIdx) {
        case 0:
            return "Index";
        case 1:
            return "Fields";
        default:
            return NULL;
        }
    case 6409: /* module 25 call 9 */
        switch (itemIdx) {
        case 0:
            return "Reg index";
        case 1:
            return "Target";
        case 2:
            return "Judgement";
        default:
            return NULL;
        }
    case 6410: /* module 25 call 10 */
        switch (itemIdx) {
        case 0:
            return "Target";
        default:
            return NULL;
        }
    case 6411: /* module 25 call 11 */
        switch (itemIdx) {
        case 0:
            return "Sub";
        case 1:
            return "Data";
        default:
            return NULL;
        }
    case 6412: /* module 25 call 12 */
        switch (itemIdx) {
        case 0:
            return "Sub";
        case 1:
            return "Data";
        default:
            return NULL;
        }
    case 6413: /* module 25 call 13 */
        switch (itemIdx) {
        case 0:
            return "Sub";
        default:
            return NULL;
        }
    case 6414: /* module 25 call 14 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6656: /* module 26 call 0 */
        switch (itemIdx) {
        case 0:
            return "Amount";
        default:
            return NULL;
        }
    case 6657: /* module 26 call 1 */
        switch (itemIdx) {
        case 0:
            return "Pos";
        default:
            return NULL;
        }
    case 6658: /* module 26 call 2 */
        switch (itemIdx) {
        case 0:
            return "Who";
        case 1:
            return "Amount";
        case 2:
            return "Tip";
        default:
            return NULL;
        }
    case 6659: /* module 26 call 3 */
        switch (itemIdx) {
        case 0:
            return "Pos";
        default:
            return NULL;
        }
    case 6660: /* module 26 call 4 */
        switch (itemIdx) {
        case 0:
            return "Candidate";
        case 1:
            return "Approve";
        default:
            return NULL;
        }
    case 6661: /* module 26 call 5 */
        switch (itemIdx) {
        case 0:
            return "Approve";
        default:
            return NULL;
        }
    case 6662: /* module 26 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6663: /* module 26 call 7 */
        switch (itemIdx) {
        case 0:
            return "Founder";
        case 1:
            return "Max members";
        case 2:
            return "Rules";
        default:
            return NULL;
        }
    case 6664: /* module 26 call 8 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6665: /* module 26 call 9 */
        switch (itemIdx) {
        case 0:
            return "Who";
        case 1:
            return "Forgive";
        default:
            return NULL;
        }
    case 6666: /* module 26 call 10 */
        switch (itemIdx) {
        case 0:
            return "Who";
        case 1:
            return "Judgement";
        default:
            return NULL;
        }
    case 6667: /* module 26 call 11 */
        switch (itemIdx) {
        case 0:
            return "Max";
        default:
            return NULL;
        }
    case 6912: /* module 27 call 0 */
        switch (itemIdx) {
        case 0:
            return "Account";
        case 1:
            return "Call";
        default:
            return NULL;
        }
    case 6913: /* module 27 call 1 */
        switch (itemIdx) {
        case 0:
            return "Lost";
        case 1:
            return "Rescuer";
        default:
            return NULL;
        }
    case 6914: /* module 27 call 2 */
        switch (itemIdx) {
        case 0:
            return "Friends";
        case 1:
            return "Threshold";
        case 2:
            return "Delay period";
        default:
            return NULL;
        }
    case 6915: /* module 27 call 3 */
        switch (itemIdx) {
        case 0:
            return "Account";
        default:
            return NULL;
        }
    case 6916: /* module 27 call 4 */
        switch (itemIdx) {
        case 0:
            return "Lost";
        case 1:
            return "Rescuer";
        default:
            return NULL;
        }
    case 6917: /* module 27 call 5 */
        switch (itemIdx) {
        case 0:
            return "Account";
        default:
            return NULL;
        }
    case 6918: /* module 27 call 6 */
        switch (itemIdx) {
        case 0:
            return "Rescuer";
        default:
            return NULL;
        }
    case 6919: /* module 27 call 7 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6920: /* module 27 call 8 */
        switch (itemIdx) {
        case 0:
            return "Account";
        default:
            return NULL;
        }
    case 7168: /* module 28 call 0 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 7169: /* module 28 call 1 */
        switch (itemIdx) {
        case 0:
            return "Target";
        default:
            return NULL;
        }
    case 7170: /* module 28 call 2 */
        switch (itemIdx) {
        case 0:
            return "Target";
        case 1:
            return "Schedule";
        default:
            return NULL;
        }
    case 7171: /* module 28 call 3 */
        switch (itemIdx) {
        case 0:
            return "Source";
        case 1:
            return "Target";
        case 2:
            return "Schedule";
        default:
            return NULL;
        }
    case 7424: /* module 29 call 0 */
        switch (itemIdx) {
        case 0:
            return "When";
        case 1:
            return "Maybe periodic";
        case 2:
            return "Priority";
        case 3:
            return "Call";
        default:
            return NULL;
        }
    case 7425: /* module 29 call 1 */
        switch (itemIdx) {
        case 0:
            return "When";
        case 1:
            return "Index";
        default:
            return NULL;
        }
    case 7426: /* module 29 call 2 */
        switch (itemIdx) {
        case 0:
            return "Id";
        case 1:
            return "When";
        case 2:
            return "Maybe periodic";
        case 3:
            return "Priority";
        case 4:
            return "Call";
        default:
            return NULL;
        }
    case 7427: /* module 29 call 3 */
        switch (itemIdx) {
        case 0:
            return "Id";
        default:
            return NULL;
        }
    case 7428: /* module 29 call 4 */
        switch (itemIdx) {
        case 0:
            return "After";
        case 1:
            return "Maybe periodic";
        case 2:
            return "Priority";
        case 3:
            return "Call";
        default:
            return NULL;
        }
    case 7429: /* module 29 call 5 */
        switch (itemIdx) {
        case 0:
            return "Id";
        case 1:
            return "After";
        case 2:
            return "Maybe periodic";
        case 3:
            return "Priority";
        case 4:
            return "Call";
        default:
            return NULL;
        }
    case 7680: /* module 30 call 0 */
        switch (itemIdx) {
        case 0:
            return "Real";
        case 1:
            return "Force proxy type";
        case 2:
            return "Call";
        default:
            return NULL;
        }
    case 7681: /* module 30 call 1 */
        switch (itemIdx) {
        case 0:
            return "Delegate";
        case 1:
            return "Proxy type";
        case 2:
            return "Delay";
        default:
            return NULL;
        }
    case 7682: /* module 30 call 2 */
        switch (itemIdx) {
        case 0:
            return "Delegate";
        case 1:
            return "Proxy type";
        case 2:
            return "Delay";
        default:
            return NULL;
        }
    case 7683: /* module 30 call 3 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 7684: /* module 30 call 4 */
        switch (itemIdx) {
        case 0:
            return "Proxy type";
        case 1:
            return "Delay";
        case 2:
            return "Index";
        default:
            return NULL;
        }
    case 7685: /* module 30 call 5 */
        switch (itemIdx) {
        case 0:
            return "Spawner";
        case 1:
            return "Proxy type";
        case 2:
            return "Index";
        case 3:
            return "Height";
        case 4:
            return "Ext index";
        default:
            return NULL;
        }
    case 7686: /* module 30 call 6 */
        switch (itemIdx) {
        case 0:
            return "Real";
        case 1:
            return "Call hash";
        default:
            return NULL;
        }
    case 7687: /* module 30 call 7 */
        switch (itemIdx) {
        case 0:
            return "Real";
        case 1:
            return "Call hash";
        default:
            return NULL;
        }
    case 7688: /* module 30 call 8 */
        switch (itemIdx) {
        case 0:
            return "Delegate";
        case 1:
            return "Call hash";
        default:
            return NULL;
        }
    case 7689: /* module 30 call 9 */
        switch (itemIdx) {
        case 0:
            return "Delegate";
        case 1:
            return "Real";
        case 2:
            return "Force proxy type";
        case 3:
            return "Call";
        default:
            return NULL;
        }
    case 7936: /* module 31 call 0 */
        switch (itemIdx) {
        case 0:
            return "Other signatories";
        case 1:
            return "Call";
        default:
            return NULL;
        }
    case 7937: /* module 31 call 1 */
        switch (itemIdx) {
        case 0:
            return "Threshold";
        case 1:
            return "Other signatories";
        case 2:
            return "Maybe timepoint";
        case 3:
            return "Call";
        case 4:
            return "Store call";
        case 5:
            return "Max weight";
        default:
            return NULL;
        }
    case 7938: /* module 31 call 2 */
        switch (itemIdx) {
        case 0:
            return "Threshold";
        case 1:
            return "Other signatories";
        case 2:
            return "Maybe timepoint";
        case 3:
            return "Call hash";
        case 4:
            return "Max weight";
        default:
            return NULL;
        }
    case 7939: /* module 31 call 3 */
        switch (itemIdx) {
        case 0:
            return "Threshold";
        case 1:
            return "Other signatories";
        case 2:
            return "Timepoint";
        case 3:
            return "Call hash";
        default:
            return NULL;
        }
    default:
        return NULL;
    }

    return NULL;
}

parser_error_t _getMethod_ItemValue_V3(
    pd_Method_V3_t* m,
    uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0: /* system_fill_block_V3 - _ratio */;
            return _toStringPerbill_V3(
                &m->basic.system_fill_block_V3._ratio,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0: /* system_remark_V3 - _remark */;
            return _toStringBytes(
                &m->basic.system_remark_V3._remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0: /* system_set_heap_pages_V3 - pages */;
            return _toStringu64(
                &m->basic.system_set_heap_pages_V3.pages,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0: /* system_set_code_V3 - code */;
            return _toStringBytes(
                &m->basic.system_set_code_V3.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4: /* module 0 call 4 */
        switch (itemIdx) {
        case 0: /* system_set_code_without_checks_V3 - code */;
            return _toStringBytes(
                &m->basic.system_set_code_without_checks_V3.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5: /* module 0 call 5 */
        switch (itemIdx) {
        case 0: /* system_set_changes_trie_config_V3 - changes_trie_config */;
            return _toStringOptionChangesTrieConfiguration_V3(
                &m->basic.system_set_changes_trie_config_V3.changes_trie_config,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6: /* module 0 call 6 */
        switch (itemIdx) {
        case 0: /* system_set_storage_V3 - items */;
            return _toStringVecKeyValue_V3(
                &m->basic.system_set_storage_V3.items,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7: /* module 0 call 7 */
        switch (itemIdx) {
        case 0: /* system_kill_storage_V3 - keys */;
            return _toStringVecKey_V3(
                &m->basic.system_kill_storage_V3.keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8: /* module 0 call 8 */
        switch (itemIdx) {
        case 0: /* system_kill_prefix_V3 - prefix */;
            return _toStringKey_V3(
                &m->basic.system_kill_prefix_V3.prefix,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* system_kill_prefix_V3 - _subkeys */;
            return _toStringu32(
                &m->basic.system_kill_prefix_V3._subkeys,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9: /* module 0 call 9 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 256: /* module 1 call 0 */
        switch (itemIdx) {
        case 0: /* babe_report_equivocation_V3 - equivocation_proof */;
            return _toStringEquivocationProof_V3(
                &m->basic.babe_report_equivocation_V3.equivocation_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* babe_report_equivocation_V3 - key_owner_proof */;
            return _toStringKeyOwnerProof_V3(
                &m->basic.babe_report_equivocation_V3.key_owner_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 257: /* module 1 call 1 */
        switch (itemIdx) {
        case 0: /* babe_report_equivocation_unsigned_V3 - equivocation_proof */;
            return _toStringEquivocationProof_V3(
                &m->basic.babe_report_equivocation_unsigned_V3.equivocation_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* babe_report_equivocation_unsigned_V3 - key_owner_proof */;
            return _toStringKeyOwnerProof_V3(
                &m->basic.babe_report_equivocation_unsigned_V3.key_owner_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 512: /* module 2 call 0 */
        switch (itemIdx) {
        case 0: /* timestamp_set_V3 - now */;
            return _toStringCompactMoment_V3(
                &m->basic.timestamp_set_V3.now,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 768: /* module 3 call 0 */
        switch (itemIdx) {
        case 0: /* indices_claim_V3 - index */;
            return _toStringAccountIndex_V3(
                &m->basic.indices_claim_V3.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 769: /* module 3 call 1 */
        switch (itemIdx) {
        case 0: /* indices_transfer_V3 - new_ */;
            return _toStringAccountId_V3(
                &m->basic.indices_transfer_V3.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* indices_transfer_V3 - index */;
            return _toStringAccountIndex_V3(
                &m->basic.indices_transfer_V3.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 770: /* module 3 call 2 */
        switch (itemIdx) {
        case 0: /* indices_free_V3 - index */;
            return _toStringAccountIndex_V3(
                &m->basic.indices_free_V3.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 771: /* module 3 call 3 */
        switch (itemIdx) {
        case 0: /* indices_force_transfer_V3 - new_ */;
            return _toStringAccountId_V3(
                &m->basic.indices_force_transfer_V3.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* indices_force_transfer_V3 - index */;
            return _toStringAccountIndex_V3(
                &m->basic.indices_force_transfer_V3.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* indices_force_transfer_V3 - freeze */;
            return _toStringbool(
                &m->basic.indices_force_transfer_V3.freeze,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 772: /* module 3 call 4 */
        switch (itemIdx) {
        case 0: /* indices_freeze_V3 - index */;
            return _toStringAccountIndex_V3(
                &m->basic.indices_freeze_V3.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1024: /* module 4 call 0 */
        switch (itemIdx) {
        case 0: /* balances_transfer_V3 - dest */;
            return _toStringLookupSource(
                &m->basic.balances_transfer_V3.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_V3 - value */;
            return _toStringCompactBalance(
                &m->basic.balances_transfer_V3.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1025: /* module 4 call 1 */
        switch (itemIdx) {
        case 0: /* balances_set_balance_V3 - who */;
            return _toStringLookupSource(
                &m->basic.balances_set_balance_V3.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_set_balance_V3 - new_free */;
            return _toStringCompactBalance(
                &m->basic.balances_set_balance_V3.new_free,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_set_balance_V3 - new_reserved */;
            return _toStringCompactBalance(
                &m->basic.balances_set_balance_V3.new_reserved,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1026: /* module 4 call 2 */
        switch (itemIdx) {
        case 0: /* balances_force_transfer_V3 - source */;
            return _toStringLookupSource(
                &m->basic.balances_force_transfer_V3.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_transfer_V3 - dest */;
            return _toStringLookupSource(
                &m->basic.balances_force_transfer_V3.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_force_transfer_V3 - value */;
            return _toStringCompactBalance(
                &m->basic.balances_force_transfer_V3.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1027: /* module 4 call 3 */
        switch (itemIdx) {
        case 0: /* balances_transfer_keep_alive_V3 - dest */;
            return _toStringLookupSource(
                &m->basic.balances_transfer_keep_alive_V3.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_keep_alive_V3 - value */;
            return _toStringCompactBalance(
                &m->basic.balances_transfer_keep_alive_V3.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1280: /* module 5 call 0 */
        switch (itemIdx) {
        case 0: /* authorship_set_uncles_V3 - new_uncles */;
            return _toStringVecHeader(
                &m->basic.authorship_set_uncles_V3.new_uncles,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1536: /* module 6 call 0 */
        switch (itemIdx) {
        case 0: /* staking_bond_V3 - controller */;
            return _toStringLookupSource(
                &m->basic.staking_bond_V3.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_bond_V3 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.staking_bond_V3.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* staking_bond_V3 - payee */;
            return _toStringRewardDestination_V3(
                &m->basic.staking_bond_V3.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1537: /* module 6 call 1 */
        switch (itemIdx) {
        case 0: /* staking_bond_extra_V3 - max_additional */;
            return _toStringCompactBalanceOf(
                &m->basic.staking_bond_extra_V3.max_additional,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1538: /* module 6 call 2 */
        switch (itemIdx) {
        case 0: /* staking_unbond_V3 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.staking_unbond_V3.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1539: /* module 6 call 3 */
        switch (itemIdx) {
        case 0: /* staking_withdraw_unbonded_V3 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_withdraw_unbonded_V3.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1540: /* module 6 call 4 */
        switch (itemIdx) {
        case 0: /* staking_validate_V3 - prefs */;
            return _toStringValidatorPrefs_V3(
                &m->basic.staking_validate_V3.prefs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1541: /* module 6 call 5 */
        switch (itemIdx) {
        case 0: /* staking_nominate_V3 - targets */;
            return _toStringVecLookupSource(
                &m->basic.staking_nominate_V3.targets,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1542: /* module 6 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1543: /* module 6 call 7 */
        switch (itemIdx) {
        case 0: /* staking_set_payee_V3 - payee */;
            return _toStringRewardDestination_V3(
                &m->basic.staking_set_payee_V3.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1544: /* module 6 call 8 */
        switch (itemIdx) {
        case 0: /* staking_set_controller_V3 - controller */;
            return _toStringLookupSource(
                &m->basic.staking_set_controller_V3.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1545: /* module 6 call 9 */
        switch (itemIdx) {
        case 0: /* staking_set_validator_count_V3 - new_ */;
            return _toStringCompactu32(
                &m->basic.staking_set_validator_count_V3.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1546: /* module 6 call 10 */
        switch (itemIdx) {
        case 0: /* staking_increase_validator_count_V3 - additional */;
            return _toStringCompactu32(
                &m->basic.staking_increase_validator_count_V3.additional,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1547: /* module 6 call 11 */
        switch (itemIdx) {
        case 0: /* staking_scale_validator_count_V3 - factor */;
            return _toStringPercent_V3(
                &m->basic.staking_scale_validator_count_V3.factor,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1548: /* module 6 call 12 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1549: /* module 6 call 13 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1550: /* module 6 call 14 */
        switch (itemIdx) {
        case 0: /* staking_set_invulnerables_V3 - invulnerables */;
            return _toStringVecAccountId_V3(
                &m->basic.staking_set_invulnerables_V3.invulnerables,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1551: /* module 6 call 15 */
        switch (itemIdx) {
        case 0: /* staking_force_unstake_V3 - stash */;
            return _toStringAccountId_V3(
                &m->basic.staking_force_unstake_V3.stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_force_unstake_V3 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_force_unstake_V3.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1552: /* module 6 call 16 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1553: /* module 6 call 17 */
        switch (itemIdx) {
        case 0: /* staking_cancel_deferred_slash_V3 - era */;
            return _toStringEraIndex_V3(
                &m->basic.staking_cancel_deferred_slash_V3.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_cancel_deferred_slash_V3 - slash_indices */;
            return _toStringVecu32(
                &m->basic.staking_cancel_deferred_slash_V3.slash_indices,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1554: /* module 6 call 18 */
        switch (itemIdx) {
        case 0: /* staking_payout_stakers_V3 - validator_stash */;
            return _toStringAccountId_V3(
                &m->basic.staking_payout_stakers_V3.validator_stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_payout_stakers_V3 - era */;
            return _toStringEraIndex_V3(
                &m->basic.staking_payout_stakers_V3.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1555: /* module 6 call 19 */
        switch (itemIdx) {
        case 0: /* staking_rebond_V3 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.staking_rebond_V3.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1556: /* module 6 call 20 */
        switch (itemIdx) {
        case 0: /* staking_set_history_depth_V3 - new_history_depth */;
            return _toStringCompactEraIndex_V3(
                &m->basic.staking_set_history_depth_V3.new_history_depth,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_set_history_depth_V3 - _era_items_deleted */;
            return _toStringCompactu32(
                &m->basic.staking_set_history_depth_V3._era_items_deleted,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1557: /* module 6 call 21 */
        switch (itemIdx) {
        case 0: /* staking_reap_stash_V3 - stash */;
            return _toStringAccountId_V3(
                &m->basic.staking_reap_stash_V3.stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_reap_stash_V3 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_reap_stash_V3.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1558: /* module 6 call 22 */
        switch (itemIdx) {
        case 0: /* staking_submit_election_solution_V3 - winners */;
            return _toStringVecValidatorIndex_V3(
                &m->basic.staking_submit_election_solution_V3.winners,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_submit_election_solution_V3 - compact */;
            return _toStringCompactAssignments_V3(
                &m->basic.staking_submit_election_solution_V3.compact,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* staking_submit_election_solution_V3 - score */;
            return _toStringElectionScore_V3(
                &m->basic.staking_submit_election_solution_V3.score,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* staking_submit_election_solution_V3 - era */;
            return _toStringEraIndex_V3(
                &m->basic.staking_submit_election_solution_V3.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* staking_submit_election_solution_V3 - size */;
            return _toStringElectionSize_V3(
                &m->basic.staking_submit_election_solution_V3.size,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1559: /* module 6 call 23 */
        switch (itemIdx) {
        case 0: /* staking_submit_election_solution_unsigned_V3 - winners */;
            return _toStringVecValidatorIndex_V3(
                &m->basic.staking_submit_election_solution_unsigned_V3.winners,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_submit_election_solution_unsigned_V3 - compact */;
            return _toStringCompactAssignments_V3(
                &m->basic.staking_submit_election_solution_unsigned_V3.compact,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* staking_submit_election_solution_unsigned_V3 - score */;
            return _toStringElectionScore_V3(
                &m->basic.staking_submit_election_solution_unsigned_V3.score,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* staking_submit_election_solution_unsigned_V3 - era */;
            return _toStringEraIndex_V3(
                &m->basic.staking_submit_election_solution_unsigned_V3.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* staking_submit_election_solution_unsigned_V3 - size */;
            return _toStringElectionSize_V3(
                &m->basic.staking_submit_election_solution_unsigned_V3.size,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2048: /* module 8 call 0 */
        switch (itemIdx) {
        case 0: /* session_set_keys_V3 - keys */;
            return _toStringKeys_V3(
                &m->basic.session_set_keys_V3.keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* session_set_keys_V3 - proof */;
            return _toStringBytes(
                &m->basic.session_set_keys_V3.proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2049: /* module 8 call 1 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0: /* grandpa_report_equivocation_V3 - equivocation_proof */;
            return _toStringEquivocationProof_V3(
                &m->basic.grandpa_report_equivocation_V3.equivocation_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* grandpa_report_equivocation_V3 - key_owner_proof */;
            return _toStringKeyOwnerProof_V3(
                &m->basic.grandpa_report_equivocation_V3.key_owner_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2561: /* module 10 call 1 */
        switch (itemIdx) {
        case 0: /* grandpa_report_equivocation_unsigned_V3 - equivocation_proof */;
            return _toStringEquivocationProof_V3(
                &m->basic.grandpa_report_equivocation_unsigned_V3.equivocation_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* grandpa_report_equivocation_unsigned_V3 - key_owner_proof */;
            return _toStringKeyOwnerProof_V3(
                &m->basic.grandpa_report_equivocation_unsigned_V3.key_owner_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2562: /* module 10 call 2 */
        switch (itemIdx) {
        case 0: /* grandpa_note_stalled_V3 - delay */;
            return _toStringBlockNumber(
                &m->basic.grandpa_note_stalled_V3.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* grandpa_note_stalled_V3 - best_finalized_block_number */;
            return _toStringBlockNumber(
                &m->basic.grandpa_note_stalled_V3.best_finalized_block_number,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2816: /* module 11 call 0 */
        switch (itemIdx) {
        case 0: /* imonline_heartbeat_V3 - heartbeat */;
            return _toStringHeartbeat(
                &m->basic.imonline_heartbeat_V3.heartbeat,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* imonline_heartbeat_V3 - _signature */;
            return _toStringSignature_V3(
                &m->basic.imonline_heartbeat_V3._signature,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3328: /* module 13 call 0 */
        switch (itemIdx) {
        case 0: /* democracy_propose_V3 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_propose_V3.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_propose_V3 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.democracy_propose_V3.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3329: /* module 13 call 1 */
        switch (itemIdx) {
        case 0: /* democracy_second_V3 - proposal */;
            return _toStringCompactPropIndex_V3(
                &m->basic.democracy_second_V3.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_second_V3 - seconds_upper_bound */;
            return _toStringCompactu32(
                &m->basic.democracy_second_V3.seconds_upper_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3330: /* module 13 call 2 */
        switch (itemIdx) {
        case 0: /* democracy_vote_V3 - ref_index */;
            return _toStringCompactReferendumIndex_V3(
                &m->basic.democracy_vote_V3.ref_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_vote_V3 - vote */;
            return _toStringAccountVote_V3(
                &m->basic.democracy_vote_V3.vote,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3331: /* module 13 call 3 */
        switch (itemIdx) {
        case 0: /* democracy_emergency_cancel_V3 - ref_index */;
            return _toStringReferendumIndex_V3(
                &m->basic.democracy_emergency_cancel_V3.ref_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3332: /* module 13 call 4 */
        switch (itemIdx) {
        case 0: /* democracy_external_propose_V3 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_external_propose_V3.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3333: /* module 13 call 5 */
        switch (itemIdx) {
        case 0: /* democracy_external_propose_majority_V3 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_external_propose_majority_V3.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3334: /* module 13 call 6 */
        switch (itemIdx) {
        case 0: /* democracy_external_propose_default_V3 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_external_propose_default_V3.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3335: /* module 13 call 7 */
        switch (itemIdx) {
        case 0: /* democracy_fast_track_V3 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_fast_track_V3.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_fast_track_V3 - voting_period */;
            return _toStringBlockNumber(
                &m->basic.democracy_fast_track_V3.voting_period,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* democracy_fast_track_V3 - delay */;
            return _toStringBlockNumber(
                &m->basic.democracy_fast_track_V3.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3336: /* module 13 call 8 */
        switch (itemIdx) {
        case 0: /* democracy_veto_external_V3 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_veto_external_V3.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3337: /* module 13 call 9 */
        switch (itemIdx) {
        case 0: /* democracy_cancel_referendum_V3 - ref_index */;
            return _toStringCompactReferendumIndex_V3(
                &m->basic.democracy_cancel_referendum_V3.ref_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3338: /* module 13 call 10 */
        switch (itemIdx) {
        case 0: /* democracy_cancel_queued_V3 - which */;
            return _toStringReferendumIndex_V3(
                &m->basic.democracy_cancel_queued_V3.which,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3339: /* module 13 call 11 */
        switch (itemIdx) {
        case 0: /* democracy_delegate_V3 - to */;
            return _toStringAccountId_V3(
                &m->basic.democracy_delegate_V3.to,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_delegate_V3 - conviction */;
            return _toStringConviction_V3(
                &m->basic.democracy_delegate_V3.conviction,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* democracy_delegate_V3 - balance */;
            return _toStringBalanceOf_V3(
                &m->basic.democracy_delegate_V3.balance,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3340: /* module 13 call 12 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 3341: /* module 13 call 13 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 3342: /* module 13 call 14 */
        switch (itemIdx) {
        case 0: /* democracy_note_preimage_V3 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_preimage_V3.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3343: /* module 13 call 15 */
        switch (itemIdx) {
        case 0: /* democracy_note_preimage_operational_V3 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_preimage_operational_V3.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3344: /* module 13 call 16 */
        switch (itemIdx) {
        case 0: /* democracy_note_imminent_preimage_V3 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_imminent_preimage_V3.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3345: /* module 13 call 17 */
        switch (itemIdx) {
        case 0: /* democracy_note_imminent_preimage_operational_V3 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_imminent_preimage_operational_V3.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3346: /* module 13 call 18 */
        switch (itemIdx) {
        case 0: /* democracy_reap_preimage_V3 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_reap_preimage_V3.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_reap_preimage_V3 - proposal_len_upper_bound */;
            return _toStringCompactu32(
                &m->basic.democracy_reap_preimage_V3.proposal_len_upper_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3347: /* module 13 call 19 */
        switch (itemIdx) {
        case 0: /* democracy_unlock_V3 - target */;
            return _toStringAccountId_V3(
                &m->basic.democracy_unlock_V3.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3348: /* module 13 call 20 */
        switch (itemIdx) {
        case 0: /* democracy_remove_vote_V3 - index */;
            return _toStringReferendumIndex_V3(
                &m->basic.democracy_remove_vote_V3.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3349: /* module 13 call 21 */
        switch (itemIdx) {
        case 0: /* democracy_remove_other_vote_V3 - target */;
            return _toStringAccountId_V3(
                &m->basic.democracy_remove_other_vote_V3.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_remove_other_vote_V3 - index */;
            return _toStringReferendumIndex_V3(
                &m->basic.democracy_remove_other_vote_V3.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3350: /* module 13 call 22 */
        switch (itemIdx) {
        case 0: /* democracy_enact_proposal_V3 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_enact_proposal_V3.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_enact_proposal_V3 - index */;
            return _toStringReferendumIndex_V3(
                &m->basic.democracy_enact_proposal_V3.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3351: /* module 13 call 23 */
        switch (itemIdx) {
        case 0: /* democracy_blacklist_V3 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_blacklist_V3.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_blacklist_V3 - maybe_ref_index */;
            return _toStringOptionReferendumIndex_V3(
                &m->basic.democracy_blacklist_V3.maybe_ref_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3352: /* module 13 call 24 */
        switch (itemIdx) {
        case 0: /* democracy_cancel_proposal_V3 - prop_index */;
            return _toStringCompactPropIndex_V3(
                &m->basic.democracy_cancel_proposal_V3.prop_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3584: /* module 14 call 0 */
        switch (itemIdx) {
        case 0: /* council_set_members_V3 - new_members */;
            return _toStringVecAccountId_V3(
                &m->basic.council_set_members_V3.new_members,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_set_members_V3 - prime */;
            return _toStringOptionAccountId_V3(
                &m->basic.council_set_members_V3.prime,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_set_members_V3 - old_count */;
            return _toStringMemberCount_V3(
                &m->basic.council_set_members_V3.old_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3585: /* module 14 call 1 */
        switch (itemIdx) {
        case 0: /* council_execute_V3 - proposal */;
            return _toStringProposal_V3(
                &m->nested.council_execute_V3.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_execute_V3 - length_bound */;
            return _toStringCompactu32(
                &m->nested.council_execute_V3.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3586: /* module 14 call 2 */
        switch (itemIdx) {
        case 0: /* council_propose_V3 - threshold */;
            return _toStringCompactMemberCount_V3(
                &m->nested.council_propose_V3.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_propose_V3 - proposal */;
            return _toStringProposal_V3(
                &m->nested.council_propose_V3.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_propose_V3 - length_bound */;
            return _toStringCompactu32(
                &m->nested.council_propose_V3.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3587: /* module 14 call 3 */
        switch (itemIdx) {
        case 0: /* council_vote_V3 - proposal */;
            return _toStringHash(
                &m->basic.council_vote_V3.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_vote_V3 - index */;
            return _toStringCompactProposalIndex_V3(
                &m->basic.council_vote_V3.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_vote_V3 - approve */;
            return _toStringbool(
                &m->basic.council_vote_V3.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3588: /* module 14 call 4 */
        switch (itemIdx) {
        case 0: /* council_close_V3 - proposal_hash */;
            return _toStringHash(
                &m->basic.council_close_V3.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_close_V3 - index */;
            return _toStringCompactProposalIndex_V3(
                &m->basic.council_close_V3.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_close_V3 - proposal_weight_bound */;
            return _toStringCompactWeight_V3(
                &m->basic.council_close_V3.proposal_weight_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* council_close_V3 - length_bound */;
            return _toStringCompactu32(
                &m->basic.council_close_V3.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3589: /* module 14 call 5 */
        switch (itemIdx) {
        case 0: /* council_disapprove_proposal_V3 - proposal_hash */;
            return _toStringHash(
                &m->basic.council_disapprove_proposal_V3.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3840: /* module 15 call 0 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_set_members_V3 - new_members */;
            return _toStringVecAccountId_V3(
                &m->basic.technicalcommittee_set_members_V3.new_members,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_set_members_V3 - prime */;
            return _toStringOptionAccountId_V3(
                &m->basic.technicalcommittee_set_members_V3.prime,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_set_members_V3 - old_count */;
            return _toStringMemberCount_V3(
                &m->basic.technicalcommittee_set_members_V3.old_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3841: /* module 15 call 1 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_execute_V3 - proposal */;
            return _toStringProposal_V3(
                &m->nested.technicalcommittee_execute_V3.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_execute_V3 - length_bound */;
            return _toStringCompactu32(
                &m->nested.technicalcommittee_execute_V3.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3842: /* module 15 call 2 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_propose_V3 - threshold */;
            return _toStringCompactMemberCount_V3(
                &m->nested.technicalcommittee_propose_V3.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_propose_V3 - proposal */;
            return _toStringProposal_V3(
                &m->nested.technicalcommittee_propose_V3.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_propose_V3 - length_bound */;
            return _toStringCompactu32(
                &m->nested.technicalcommittee_propose_V3.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3843: /* module 15 call 3 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_vote_V3 - proposal */;
            return _toStringHash(
                &m->basic.technicalcommittee_vote_V3.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_vote_V3 - index */;
            return _toStringCompactProposalIndex_V3(
                &m->basic.technicalcommittee_vote_V3.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_vote_V3 - approve */;
            return _toStringbool(
                &m->basic.technicalcommittee_vote_V3.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3844: /* module 15 call 4 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_close_V3 - proposal_hash */;
            return _toStringHash(
                &m->basic.technicalcommittee_close_V3.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_close_V3 - index */;
            return _toStringCompactProposalIndex_V3(
                &m->basic.technicalcommittee_close_V3.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_close_V3 - proposal_weight_bound */;
            return _toStringCompactWeight_V3(
                &m->basic.technicalcommittee_close_V3.proposal_weight_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* technicalcommittee_close_V3 - length_bound */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_close_V3.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3845: /* module 15 call 5 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_disapprove_proposal_V3 - proposal_hash */;
            return _toStringHash(
                &m->basic.technicalcommittee_disapprove_proposal_V3.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4096: /* module 16 call 0 */
        switch (itemIdx) {
        case 0: /* electionsphragmen_vote_V3 - votes */;
            return _toStringVecAccountId_V3(
                &m->basic.electionsphragmen_vote_V3.votes,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* electionsphragmen_vote_V3 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.electionsphragmen_vote_V3.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4097: /* module 16 call 1 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 4098: /* module 16 call 2 */
        switch (itemIdx) {
        case 0: /* electionsphragmen_report_defunct_voter_V3 - defunct */;
            return _toStringDefunctVoter_V3(
                &m->basic.electionsphragmen_report_defunct_voter_V3.defunct,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4099: /* module 16 call 3 */
        switch (itemIdx) {
        case 0: /* electionsphragmen_submit_candidacy_V3 - candidate_count */;
            return _toStringCompactu32(
                &m->basic.electionsphragmen_submit_candidacy_V3.candidate_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4100: /* module 16 call 4 */
        switch (itemIdx) {
        case 0: /* electionsphragmen_renounce_candidacy_V3 - renouncing */;
            return _toStringRenouncing_V3(
                &m->basic.electionsphragmen_renounce_candidacy_V3.renouncing,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4101: /* module 16 call 5 */
        switch (itemIdx) {
        case 0: /* electionsphragmen_remove_member_V3 - who */;
            return _toStringLookupSource(
                &m->basic.electionsphragmen_remove_member_V3.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* electionsphragmen_remove_member_V3 - has_replacement */;
            return _toStringbool(
                &m->basic.electionsphragmen_remove_member_V3.has_replacement,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4352: /* module 17 call 0 */
        switch (itemIdx) {
        case 0: /* technicalmembership_add_member_V3 - who */;
            return _toStringAccountId_V3(
                &m->basic.technicalmembership_add_member_V3.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4353: /* module 17 call 1 */
        switch (itemIdx) {
        case 0: /* technicalmembership_remove_member_V3 - who */;
            return _toStringAccountId_V3(
                &m->basic.technicalmembership_remove_member_V3.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4354: /* module 17 call 2 */
        switch (itemIdx) {
        case 0: /* technicalmembership_swap_member_V3 - remove */;
            return _toStringAccountId_V3(
                &m->basic.technicalmembership_swap_member_V3.remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalmembership_swap_member_V3 - add */;
            return _toStringAccountId_V3(
                &m->basic.technicalmembership_swap_member_V3.add,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4355: /* module 17 call 3 */
        switch (itemIdx) {
        case 0: /* technicalmembership_reset_members_V3 - members */;
            return _toStringVecAccountId_V3(
                &m->basic.technicalmembership_reset_members_V3.members,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4356: /* module 17 call 4 */
        switch (itemIdx) {
        case 0: /* technicalmembership_change_key_V3 - new_ */;
            return _toStringAccountId_V3(
                &m->basic.technicalmembership_change_key_V3.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4357: /* module 17 call 5 */
        switch (itemIdx) {
        case 0: /* technicalmembership_set_prime_V3 - who */;
            return _toStringAccountId_V3(
                &m->basic.technicalmembership_set_prime_V3.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4358: /* module 17 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 4608: /* module 18 call 0 */
        switch (itemIdx) {
        case 0: /* treasury_propose_spend_V3 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.treasury_propose_spend_V3.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* treasury_propose_spend_V3 - beneficiary */;
            return _toStringLookupSource(
                &m->basic.treasury_propose_spend_V3.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4609: /* module 18 call 1 */
        switch (itemIdx) {
        case 0: /* treasury_reject_proposal_V3 - proposal_id */;
            return _toStringCompactProposalIndex_V3(
                &m->basic.treasury_reject_proposal_V3.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4610: /* module 18 call 2 */
        switch (itemIdx) {
        case 0: /* treasury_approve_proposal_V3 - proposal_id */;
            return _toStringCompactProposalIndex_V3(
                &m->basic.treasury_approve_proposal_V3.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4611: /* module 18 call 3 */
        switch (itemIdx) {
        case 0: /* treasury_report_awesome_V3 - reason */;
            return _toStringBytes(
                &m->basic.treasury_report_awesome_V3.reason,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* treasury_report_awesome_V3 - who */;
            return _toStringAccountId_V3(
                &m->basic.treasury_report_awesome_V3.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4612: /* module 18 call 4 */
        switch (itemIdx) {
        case 0: /* treasury_retract_tip_V3 - hash */;
            return _toStringHash(
                &m->basic.treasury_retract_tip_V3.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4613: /* module 18 call 5 */
        switch (itemIdx) {
        case 0: /* treasury_tip_new_V3 - reason */;
            return _toStringBytes(
                &m->basic.treasury_tip_new_V3.reason,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* treasury_tip_new_V3 - who */;
            return _toStringAccountId_V3(
                &m->basic.treasury_tip_new_V3.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* treasury_tip_new_V3 - tip_value */;
            return _toStringCompactBalanceOf(
                &m->basic.treasury_tip_new_V3.tip_value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4614: /* module 18 call 6 */
        switch (itemIdx) {
        case 0: /* treasury_tip_V3 - hash */;
            return _toStringHash(
                &m->basic.treasury_tip_V3.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* treasury_tip_V3 - tip_value */;
            return _toStringCompactBalanceOf(
                &m->basic.treasury_tip_V3.tip_value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4615: /* module 18 call 7 */
        switch (itemIdx) {
        case 0: /* treasury_close_tip_V3 - hash */;
            return _toStringHash(
                &m->basic.treasury_close_tip_V3.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4616: /* module 18 call 8 */
        switch (itemIdx) {
        case 0: /* treasury_propose_bounty_V3 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.treasury_propose_bounty_V3.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* treasury_propose_bounty_V3 - description */;
            return _toStringBytes(
                &m->basic.treasury_propose_bounty_V3.description,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4617: /* module 18 call 9 */
        switch (itemIdx) {
        case 0: /* treasury_approve_bounty_V3 - bounty_id */;
            return _toStringCompactProposalIndex_V3(
                &m->basic.treasury_approve_bounty_V3.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4618: /* module 18 call 10 */
        switch (itemIdx) {
        case 0: /* treasury_propose_curator_V3 - bounty_id */;
            return _toStringCompactProposalIndex_V3(
                &m->basic.treasury_propose_curator_V3.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* treasury_propose_curator_V3 - curator */;
            return _toStringLookupSource(
                &m->basic.treasury_propose_curator_V3.curator,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* treasury_propose_curator_V3 - fee */;
            return _toStringCompactBalanceOf(
                &m->basic.treasury_propose_curator_V3.fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4619: /* module 18 call 11 */
        switch (itemIdx) {
        case 0: /* treasury_unassign_curator_V3 - bounty_id */;
            return _toStringCompactProposalIndex_V3(
                &m->basic.treasury_unassign_curator_V3.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4620: /* module 18 call 12 */
        switch (itemIdx) {
        case 0: /* treasury_accept_curator_V3 - bounty_id */;
            return _toStringCompactProposalIndex_V3(
                &m->basic.treasury_accept_curator_V3.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4621: /* module 18 call 13 */
        switch (itemIdx) {
        case 0: /* treasury_award_bounty_V3 - bounty_id */;
            return _toStringCompactProposalIndex_V3(
                &m->basic.treasury_award_bounty_V3.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* treasury_award_bounty_V3 - beneficiary */;
            return _toStringLookupSource(
                &m->basic.treasury_award_bounty_V3.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4622: /* module 18 call 14 */
        switch (itemIdx) {
        case 0: /* treasury_claim_bounty_V3 - bounty_id */;
            return _toStringCompactBountyIndex_V3(
                &m->basic.treasury_claim_bounty_V3.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4623: /* module 18 call 15 */
        switch (itemIdx) {
        case 0: /* treasury_close_bounty_V3 - bounty_id */;
            return _toStringCompactBountyIndex_V3(
                &m->basic.treasury_close_bounty_V3.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4624: /* module 18 call 16 */
        switch (itemIdx) {
        case 0: /* treasury_extend_bounty_expiry_V3 - bounty_id */;
            return _toStringCompactBountyIndex_V3(
                &m->basic.treasury_extend_bounty_expiry_V3.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* treasury_extend_bounty_expiry_V3 - _remark */;
            return _toStringBytes(
                &m->basic.treasury_extend_bounty_expiry_V3._remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4864: /* module 19 call 0 */
        switch (itemIdx) {
        case 0: /* claims_claim_V3 - dest */;
            return _toStringAccountId_V3(
                &m->basic.claims_claim_V3.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* claims_claim_V3 - ethereum_signature */;
            return _toStringEcdsaSignature_V3(
                &m->basic.claims_claim_V3.ethereum_signature,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4865: /* module 19 call 1 */
        switch (itemIdx) {
        case 0: /* claims_mint_claim_V3 - who */;
            return _toStringEthereumAddress_V3(
                &m->basic.claims_mint_claim_V3.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* claims_mint_claim_V3 - value */;
            return _toStringBalanceOf_V3(
                &m->basic.claims_mint_claim_V3.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* claims_mint_claim_V3 - vesting_schedule */;
            return _toStringOptionTupleBalanceOfBalanceOfBlockNumber_V3(
                &m->basic.claims_mint_claim_V3.vesting_schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* claims_mint_claim_V3 - statement */;
            return _toStringOptionStatementKind_V3(
                &m->basic.claims_mint_claim_V3.statement,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4866: /* module 19 call 2 */
        switch (itemIdx) {
        case 0: /* claims_claim_attest_V3 - dest */;
            return _toStringAccountId_V3(
                &m->basic.claims_claim_attest_V3.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* claims_claim_attest_V3 - ethereum_signature */;
            return _toStringEcdsaSignature_V3(
                &m->basic.claims_claim_attest_V3.ethereum_signature,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* claims_claim_attest_V3 - statement */;
            return _toStringBytes(
                &m->basic.claims_claim_attest_V3.statement,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4867: /* module 19 call 3 */
        switch (itemIdx) {
        case 0: /* claims_attest_V3 - statement */;
            return _toStringBytes(
                &m->basic.claims_attest_V3.statement,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4868: /* module 19 call 4 */
        switch (itemIdx) {
        case 0: /* claims_move_claim_V3 - old */;
            return _toStringEthereumAddress_V3(
                &m->basic.claims_move_claim_V3.old,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* claims_move_claim_V3 - new_ */;
            return _toStringEthereumAddress_V3(
                &m->basic.claims_move_claim_V3.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* claims_move_claim_V3 - maybe_preclaim */;
            return _toStringOptionAccountId_V3(
                &m->basic.claims_move_claim_V3.maybe_preclaim,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6144: /* module 24 call 0 */
        switch (itemIdx) {
        case 0: /* utility_batch_V3 - calls */;
            return _toStringVecCall_V3(
                &m->basic.utility_batch_V3.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6145: /* module 24 call 1 */
        switch (itemIdx) {
        case 0: /* utility_as_derivative_V3 - index */;
            return _toStringu16(
                &m->basic.utility_as_derivative_V3.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* utility_as_derivative_V3 - call */;
            return _toStringCall_V3(
                &m->basic.utility_as_derivative_V3.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6146: /* module 24 call 2 */
        switch (itemIdx) {
        case 0: /* utility_batch_all_V3 - calls */;
            return _toStringVecCall_V3(
                &m->basic.utility_batch_all_V3.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6400: /* module 25 call 0 */
        switch (itemIdx) {
        case 0: /* identity_add_registrar_V3 - account */;
            return _toStringAccountId_V3(
                &m->basic.identity_add_registrar_V3.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6401: /* module 25 call 1 */
        switch (itemIdx) {
        case 0: /* identity_set_identity_V3 - info */;
            return _toStringIdentityInfo_V3(
                &m->basic.identity_set_identity_V3.info,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6402: /* module 25 call 2 */
        switch (itemIdx) {
        case 0: /* identity_set_subs_V3 - subs */;
            return _toStringVecTupleAccountIdData_V3(
                &m->basic.identity_set_subs_V3.subs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6403: /* module 25 call 3 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 6404: /* module 25 call 4 */
        switch (itemIdx) {
        case 0: /* identity_request_judgement_V3 - reg_index */;
            return _toStringCompactRegistrarIndex_V3(
                &m->basic.identity_request_judgement_V3.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_request_judgement_V3 - max_fee */;
            return _toStringCompactBalanceOf(
                &m->basic.identity_request_judgement_V3.max_fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6405: /* module 25 call 5 */
        switch (itemIdx) {
        case 0: /* identity_cancel_request_V3 - reg_index */;
            return _toStringRegistrarIndex_V3(
                &m->basic.identity_cancel_request_V3.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6406: /* module 25 call 6 */
        switch (itemIdx) {
        case 0: /* identity_set_fee_V3 - index */;
            return _toStringCompactRegistrarIndex_V3(
                &m->basic.identity_set_fee_V3.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_fee_V3 - fee */;
            return _toStringCompactBalanceOf(
                &m->basic.identity_set_fee_V3.fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6407: /* module 25 call 7 */
        switch (itemIdx) {
        case 0: /* identity_set_account_id_V3 - index */;
            return _toStringCompactRegistrarIndex_V3(
                &m->basic.identity_set_account_id_V3.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_account_id_V3 - new_ */;
            return _toStringAccountId_V3(
                &m->basic.identity_set_account_id_V3.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6408: /* module 25 call 8 */
        switch (itemIdx) {
        case 0: /* identity_set_fields_V3 - index */;
            return _toStringCompactRegistrarIndex_V3(
                &m->basic.identity_set_fields_V3.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_fields_V3 - fields */;
            return _toStringIdentityFields_V3(
                &m->basic.identity_set_fields_V3.fields,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6409: /* module 25 call 9 */
        switch (itemIdx) {
        case 0: /* identity_provide_judgement_V3 - reg_index */;
            return _toStringCompactRegistrarIndex_V3(
                &m->basic.identity_provide_judgement_V3.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_provide_judgement_V3 - target */;
            return _toStringLookupSource(
                &m->basic.identity_provide_judgement_V3.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* identity_provide_judgement_V3 - judgement */;
            return _toStringJudgement_V3(
                &m->basic.identity_provide_judgement_V3.judgement,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6410: /* module 25 call 10 */
        switch (itemIdx) {
        case 0: /* identity_kill_identity_V3 - target */;
            return _toStringLookupSource(
                &m->basic.identity_kill_identity_V3.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6411: /* module 25 call 11 */
        switch (itemIdx) {
        case 0: /* identity_add_sub_V3 - sub */;
            return _toStringLookupSource(
                &m->basic.identity_add_sub_V3.sub,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_add_sub_V3 - data */;
            return _toStringData(
                &m->basic.identity_add_sub_V3.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6412: /* module 25 call 12 */
        switch (itemIdx) {
        case 0: /* identity_rename_sub_V3 - sub */;
            return _toStringLookupSource(
                &m->basic.identity_rename_sub_V3.sub,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_rename_sub_V3 - data */;
            return _toStringData(
                &m->basic.identity_rename_sub_V3.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6413: /* module 25 call 13 */
        switch (itemIdx) {
        case 0: /* identity_remove_sub_V3 - sub */;
            return _toStringLookupSource(
                &m->basic.identity_remove_sub_V3.sub,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6414: /* module 25 call 14 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 6656: /* module 26 call 0 */
        switch (itemIdx) {
        case 0: /* society_bid_V3 - value */;
            return _toStringBalanceOf_V3(
                &m->basic.society_bid_V3.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6657: /* module 26 call 1 */
        switch (itemIdx) {
        case 0: /* society_unbid_V3 - pos */;
            return _toStringu32(
                &m->basic.society_unbid_V3.pos,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6658: /* module 26 call 2 */
        switch (itemIdx) {
        case 0: /* society_vouch_V3 - who */;
            return _toStringAccountId_V3(
                &m->basic.society_vouch_V3.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* society_vouch_V3 - value */;
            return _toStringBalanceOf_V3(
                &m->basic.society_vouch_V3.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* society_vouch_V3 - tip */;
            return _toStringBalanceOf_V3(
                &m->basic.society_vouch_V3.tip,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6659: /* module 26 call 3 */
        switch (itemIdx) {
        case 0: /* society_unvouch_V3 - pos */;
            return _toStringu32(
                &m->basic.society_unvouch_V3.pos,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6660: /* module 26 call 4 */
        switch (itemIdx) {
        case 0: /* society_vote_V3 - candidate */;
            return _toStringLookupSource(
                &m->basic.society_vote_V3.candidate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* society_vote_V3 - approve */;
            return _toStringbool(
                &m->basic.society_vote_V3.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6661: /* module 26 call 5 */
        switch (itemIdx) {
        case 0: /* society_defender_vote_V3 - approve */;
            return _toStringbool(
                &m->basic.society_defender_vote_V3.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6662: /* module 26 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 6663: /* module 26 call 7 */
        switch (itemIdx) {
        case 0: /* society_found_V3 - founder */;
            return _toStringAccountId_V3(
                &m->basic.society_found_V3.founder,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* society_found_V3 - max_members */;
            return _toStringu32(
                &m->basic.society_found_V3.max_members,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* society_found_V3 - rules */;
            return _toStringBytes(
                &m->basic.society_found_V3.rules,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6664: /* module 26 call 8 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 6665: /* module 26 call 9 */
        switch (itemIdx) {
        case 0: /* society_judge_suspended_member_V3 - who */;
            return _toStringAccountId_V3(
                &m->basic.society_judge_suspended_member_V3.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* society_judge_suspended_member_V3 - forgive */;
            return _toStringbool(
                &m->basic.society_judge_suspended_member_V3.forgive,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6666: /* module 26 call 10 */
        switch (itemIdx) {
        case 0: /* society_judge_suspended_candidate_V3 - who */;
            return _toStringAccountId_V3(
                &m->basic.society_judge_suspended_candidate_V3.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* society_judge_suspended_candidate_V3 - judgement */;
            return _toStringJudgement_V3(
                &m->basic.society_judge_suspended_candidate_V3.judgement,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6667: /* module 26 call 11 */
        switch (itemIdx) {
        case 0: /* society_set_max_members_V3 - max */;
            return _toStringu32(
                &m->basic.society_set_max_members_V3.max,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6912: /* module 27 call 0 */
        switch (itemIdx) {
        case 0: /* recovery_as_recovered_V3 - account */;
            return _toStringAccountId_V3(
                &m->basic.recovery_as_recovered_V3.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* recovery_as_recovered_V3 - call */;
            return _toStringCall_V3(
                &m->basic.recovery_as_recovered_V3.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6913: /* module 27 call 1 */
        switch (itemIdx) {
        case 0: /* recovery_set_recovered_V3 - lost */;
            return _toStringAccountId_V3(
                &m->basic.recovery_set_recovered_V3.lost,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* recovery_set_recovered_V3 - rescuer */;
            return _toStringAccountId_V3(
                &m->basic.recovery_set_recovered_V3.rescuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6914: /* module 27 call 2 */
        switch (itemIdx) {
        case 0: /* recovery_create_recovery_V3 - friends */;
            return _toStringVecAccountId_V3(
                &m->basic.recovery_create_recovery_V3.friends,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* recovery_create_recovery_V3 - threshold */;
            return _toStringu16(
                &m->basic.recovery_create_recovery_V3.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* recovery_create_recovery_V3 - delay_period */;
            return _toStringBlockNumber(
                &m->basic.recovery_create_recovery_V3.delay_period,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6915: /* module 27 call 3 */
        switch (itemIdx) {
        case 0: /* recovery_initiate_recovery_V3 - account */;
            return _toStringAccountId_V3(
                &m->basic.recovery_initiate_recovery_V3.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6916: /* module 27 call 4 */
        switch (itemIdx) {
        case 0: /* recovery_vouch_recovery_V3 - lost */;
            return _toStringAccountId_V3(
                &m->basic.recovery_vouch_recovery_V3.lost,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* recovery_vouch_recovery_V3 - rescuer */;
            return _toStringAccountId_V3(
                &m->basic.recovery_vouch_recovery_V3.rescuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6917: /* module 27 call 5 */
        switch (itemIdx) {
        case 0: /* recovery_claim_recovery_V3 - account */;
            return _toStringAccountId_V3(
                &m->basic.recovery_claim_recovery_V3.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6918: /* module 27 call 6 */
        switch (itemIdx) {
        case 0: /* recovery_close_recovery_V3 - rescuer */;
            return _toStringAccountId_V3(
                &m->basic.recovery_close_recovery_V3.rescuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6919: /* module 27 call 7 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 6920: /* module 27 call 8 */
        switch (itemIdx) {
        case 0: /* recovery_cancel_recovered_V3 - account */;
            return _toStringAccountId_V3(
                &m->basic.recovery_cancel_recovered_V3.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7168: /* module 28 call 0 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 7169: /* module 28 call 1 */
        switch (itemIdx) {
        case 0: /* vesting_vest_other_V3 - target */;
            return _toStringLookupSource(
                &m->basic.vesting_vest_other_V3.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7170: /* module 28 call 2 */
        switch (itemIdx) {
        case 0: /* vesting_vested_transfer_V3 - target */;
            return _toStringLookupSource(
                &m->basic.vesting_vested_transfer_V3.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_vested_transfer_V3 - schedule */;
            return _toStringVestingInfo_V3(
                &m->basic.vesting_vested_transfer_V3.schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7171: /* module 28 call 3 */
        switch (itemIdx) {
        case 0: /* vesting_force_vested_transfer_V3 - source */;
            return _toStringLookupSource(
                &m->basic.vesting_force_vested_transfer_V3.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_force_vested_transfer_V3 - target */;
            return _toStringLookupSource(
                &m->basic.vesting_force_vested_transfer_V3.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* vesting_force_vested_transfer_V3 - schedule */;
            return _toStringVestingInfo_V3(
                &m->basic.vesting_force_vested_transfer_V3.schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7424: /* module 29 call 0 */
        switch (itemIdx) {
        case 0: /* scheduler_schedule_V3 - when */;
            return _toStringBlockNumber(
                &m->basic.scheduler_schedule_V3.when,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_schedule_V3 - maybe_periodic */;
            return _toStringOptionPeriod_V3(
                &m->basic.scheduler_schedule_V3.maybe_periodic,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* scheduler_schedule_V3 - priority */;
            return _toStringPriority_V3(
                &m->basic.scheduler_schedule_V3.priority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* scheduler_schedule_V3 - call */;
            return _toStringCall_V3(
                &m->basic.scheduler_schedule_V3.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7425: /* module 29 call 1 */
        switch (itemIdx) {
        case 0: /* scheduler_cancel_V3 - when */;
            return _toStringBlockNumber(
                &m->basic.scheduler_cancel_V3.when,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_cancel_V3 - index */;
            return _toStringu32(
                &m->basic.scheduler_cancel_V3.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7426: /* module 29 call 2 */
        switch (itemIdx) {
        case 0: /* scheduler_schedule_named_V3 - id */;
            return _toStringBytes(
                &m->basic.scheduler_schedule_named_V3.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_schedule_named_V3 - when */;
            return _toStringBlockNumber(
                &m->basic.scheduler_schedule_named_V3.when,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* scheduler_schedule_named_V3 - maybe_periodic */;
            return _toStringOptionPeriod_V3(
                &m->basic.scheduler_schedule_named_V3.maybe_periodic,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* scheduler_schedule_named_V3 - priority */;
            return _toStringPriority_V3(
                &m->basic.scheduler_schedule_named_V3.priority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* scheduler_schedule_named_V3 - call */;
            return _toStringCall_V3(
                &m->basic.scheduler_schedule_named_V3.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7427: /* module 29 call 3 */
        switch (itemIdx) {
        case 0: /* scheduler_cancel_named_V3 - id */;
            return _toStringBytes(
                &m->basic.scheduler_cancel_named_V3.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7428: /* module 29 call 4 */
        switch (itemIdx) {
        case 0: /* scheduler_schedule_after_V3 - after */;
            return _toStringBlockNumber(
                &m->basic.scheduler_schedule_after_V3.after,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_schedule_after_V3 - maybe_periodic */;
            return _toStringOptionPeriod_V3(
                &m->basic.scheduler_schedule_after_V3.maybe_periodic,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* scheduler_schedule_after_V3 - priority */;
            return _toStringPriority_V3(
                &m->basic.scheduler_schedule_after_V3.priority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* scheduler_schedule_after_V3 - call */;
            return _toStringCall_V3(
                &m->basic.scheduler_schedule_after_V3.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7429: /* module 29 call 5 */
        switch (itemIdx) {
        case 0: /* scheduler_schedule_named_after_V3 - id */;
            return _toStringBytes(
                &m->basic.scheduler_schedule_named_after_V3.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_schedule_named_after_V3 - after */;
            return _toStringBlockNumber(
                &m->basic.scheduler_schedule_named_after_V3.after,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* scheduler_schedule_named_after_V3 - maybe_periodic */;
            return _toStringOptionPeriod_V3(
                &m->basic.scheduler_schedule_named_after_V3.maybe_periodic,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* scheduler_schedule_named_after_V3 - priority */;
            return _toStringPriority_V3(
                &m->basic.scheduler_schedule_named_after_V3.priority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* scheduler_schedule_named_after_V3 - call */;
            return _toStringCall_V3(
                &m->basic.scheduler_schedule_named_after_V3.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7680: /* module 30 call 0 */
        switch (itemIdx) {
        case 0: /* proxy_proxy_V3 - real */;
            return _toStringAccountId_V3(
                &m->basic.proxy_proxy_V3.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_proxy_V3 - force_proxy_type */;
            return _toStringOptionProxyType_V3(
                &m->basic.proxy_proxy_V3.force_proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_proxy_V3 - call */;
            return _toStringCall_V3(
                &m->basic.proxy_proxy_V3.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7681: /* module 30 call 1 */
        switch (itemIdx) {
        case 0: /* proxy_add_proxy_V3 - delegate */;
            return _toStringAccountId_V3(
                &m->basic.proxy_add_proxy_V3.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_add_proxy_V3 - proxy_type */;
            return _toStringProxyType_V3(
                &m->basic.proxy_add_proxy_V3.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_add_proxy_V3 - delay */;
            return _toStringBlockNumber(
                &m->basic.proxy_add_proxy_V3.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7682: /* module 30 call 2 */
        switch (itemIdx) {
        case 0: /* proxy_remove_proxy_V3 - delegate */;
            return _toStringAccountId_V3(
                &m->basic.proxy_remove_proxy_V3.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_remove_proxy_V3 - proxy_type */;
            return _toStringProxyType_V3(
                &m->basic.proxy_remove_proxy_V3.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_remove_proxy_V3 - delay */;
            return _toStringBlockNumber(
                &m->basic.proxy_remove_proxy_V3.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7683: /* module 30 call 3 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 7684: /* module 30 call 4 */
        switch (itemIdx) {
        case 0: /* proxy_anonymous_V3 - proxy_type */;
            return _toStringProxyType_V3(
                &m->basic.proxy_anonymous_V3.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_anonymous_V3 - delay */;
            return _toStringBlockNumber(
                &m->basic.proxy_anonymous_V3.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_anonymous_V3 - index */;
            return _toStringu16(
                &m->basic.proxy_anonymous_V3.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7685: /* module 30 call 5 */
        switch (itemIdx) {
        case 0: /* proxy_kill_anonymous_V3 - spawner */;
            return _toStringAccountId_V3(
                &m->basic.proxy_kill_anonymous_V3.spawner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_kill_anonymous_V3 - proxy_type */;
            return _toStringProxyType_V3(
                &m->basic.proxy_kill_anonymous_V3.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_kill_anonymous_V3 - index */;
            return _toStringu16(
                &m->basic.proxy_kill_anonymous_V3.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* proxy_kill_anonymous_V3 - height */;
            return _toStringCompactBlockNumber(
                &m->basic.proxy_kill_anonymous_V3.height,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* proxy_kill_anonymous_V3 - ext_index */;
            return _toStringCompactu32(
                &m->basic.proxy_kill_anonymous_V3.ext_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7686: /* module 30 call 6 */
        switch (itemIdx) {
        case 0: /* proxy_announce_V3 - real */;
            return _toStringAccountId_V3(
                &m->basic.proxy_announce_V3.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_announce_V3 - call_hash */;
            return _toStringCallHashOf_V3(
                &m->basic.proxy_announce_V3.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7687: /* module 30 call 7 */
        switch (itemIdx) {
        case 0: /* proxy_remove_announcement_V3 - real */;
            return _toStringAccountId_V3(
                &m->basic.proxy_remove_announcement_V3.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_remove_announcement_V3 - call_hash */;
            return _toStringCallHashOf_V3(
                &m->basic.proxy_remove_announcement_V3.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7688: /* module 30 call 8 */
        switch (itemIdx) {
        case 0: /* proxy_reject_announcement_V3 - delegate */;
            return _toStringAccountId_V3(
                &m->basic.proxy_reject_announcement_V3.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_reject_announcement_V3 - call_hash */;
            return _toStringCallHashOf_V3(
                &m->basic.proxy_reject_announcement_V3.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7689: /* module 30 call 9 */
        switch (itemIdx) {
        case 0: /* proxy_proxy_announced_V3 - delegate */;
            return _toStringAccountId_V3(
                &m->basic.proxy_proxy_announced_V3.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_proxy_announced_V3 - real */;
            return _toStringAccountId_V3(
                &m->basic.proxy_proxy_announced_V3.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_proxy_announced_V3 - force_proxy_type */;
            return _toStringOptionProxyType_V3(
                &m->basic.proxy_proxy_announced_V3.force_proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* proxy_proxy_announced_V3 - call */;
            return _toStringCall_V3(
                &m->basic.proxy_proxy_announced_V3.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7936: /* module 31 call 0 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_threshold_1_V3 - other_signatories */;
            return _toStringVecAccountId_V3(
                &m->basic.multisig_as_multi_threshold_1_V3.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_threshold_1_V3 - call */;
            return _toStringCall_V3(
                &m->basic.multisig_as_multi_threshold_1_V3.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7937: /* module 31 call 1 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_V3 - threshold */;
            return _toStringu16(
                &m->basic.multisig_as_multi_V3.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_V3 - other_signatories */;
            return _toStringVecAccountId_V3(
                &m->basic.multisig_as_multi_V3.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_as_multi_V3 - maybe_timepoint */;
            return _toStringOptionTimepoint_V3(
                &m->basic.multisig_as_multi_V3.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_as_multi_V3 - call */;
            return _toStringOpaqueCall_V3(
                &m->basic.multisig_as_multi_V3.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_as_multi_V3 - store_call */;
            return _toStringbool(
                &m->basic.multisig_as_multi_V3.store_call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* multisig_as_multi_V3 - max_weight */;
            return _toStringWeight_V3(
                &m->basic.multisig_as_multi_V3.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7938: /* module 31 call 2 */
        switch (itemIdx) {
        case 0: /* multisig_approve_as_multi_V3 - threshold */;
            return _toStringu16(
                &m->basic.multisig_approve_as_multi_V3.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_approve_as_multi_V3 - other_signatories */;
            return _toStringVecAccountId_V3(
                &m->basic.multisig_approve_as_multi_V3.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_approve_as_multi_V3 - maybe_timepoint */;
            return _toStringOptionTimepoint_V3(
                &m->basic.multisig_approve_as_multi_V3.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_approve_as_multi_V3 - call_hash */;
            return _toStringu8_array_32_V3(
                &m->basic.multisig_approve_as_multi_V3.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_approve_as_multi_V3 - max_weight */;
            return _toStringWeight_V3(
                &m->basic.multisig_approve_as_multi_V3.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7939: /* module 31 call 3 */
        switch (itemIdx) {
        case 0: /* multisig_cancel_as_multi_V3 - threshold */;
            return _toStringu16(
                &m->basic.multisig_cancel_as_multi_V3.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_cancel_as_multi_V3 - other_signatories */;
            return _toStringVecAccountId_V3(
                &m->basic.multisig_cancel_as_multi_V3.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_cancel_as_multi_V3 - timepoint */;
            return _toStringTimepoint_V3(
                &m->basic.multisig_cancel_as_multi_V3.timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_cancel_as_multi_V3 - call_hash */;
            return _toStringu8_array_32_V3(
                &m->basic.multisig_cancel_as_multi_V3.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    default:
        return parser_ok;
    }

    return parser_ok;
}
