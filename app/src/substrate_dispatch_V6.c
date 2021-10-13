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

#include "substrate_dispatch_V6.h"
#include "substrate_strings.h"
#include "zxmacros.h"
#include <stdint.h>

__Z_INLINE parser_error_t _readMethod_balances_transfer_V6(
    parser_context_t* c, pd_balances_transfer_V6_t* m)
{
    CHECK_ERROR(_readLookupSource_V6(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_keep_alive_V6(
    parser_context_t* c, pd_balances_transfer_keep_alive_V6_t* m)
{
    CHECK_ERROR(_readLookupSource_V6(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_V6(
    parser_context_t* c, pd_staking_bond_V6_t* m)
{
    CHECK_ERROR(_readLookupSource_V6(c, &m->controller))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    CHECK_ERROR(_readRewardDestination_V6(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_extra_V6(
    parser_context_t* c, pd_staking_bond_extra_V6_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->max_additional))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_unbond_V6(
    parser_context_t* c, pd_staking_unbond_V6_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_withdraw_unbonded_V6(
    parser_context_t* c, pd_staking_withdraw_unbonded_V6_t* m)
{
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_validate_V6(
    parser_context_t* c, pd_staking_validate_V6_t* m)
{
    CHECK_ERROR(_readValidatorPrefs_V6(c, &m->prefs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_nominate_V6(
    parser_context_t* c, pd_staking_nominate_V6_t* m)
{
    CHECK_ERROR(_readVecLookupSource_V6(c, &m->targets))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill_V6(
    parser_context_t* c, pd_staking_chill_V6_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_payee_V6(
    parser_context_t* c, pd_staking_set_payee_V6_t* m)
{
    CHECK_ERROR(_readRewardDestination_V6(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_controller_V6(
    parser_context_t* c, pd_staking_set_controller_V6_t* m)
{
    CHECK_ERROR(_readLookupSource_V6(c, &m->controller))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_payout_stakers_V6(
    parser_context_t* c, pd_staking_payout_stakers_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->validator_stash))
    CHECK_ERROR(_readEraIndex_V6(c, &m->era))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_rebond_V6(
    parser_context_t* c, pd_staking_rebond_V6_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_set_keys_V6(
    parser_context_t* c, pd_session_set_keys_V6_t* m)
{
    CHECK_ERROR(_readKeys_V6(c, &m->keys))
    CHECK_ERROR(_readBytes(c, &m->proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_purge_keys_V6(
    parser_context_t* c, pd_session_purge_keys_V6_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_V6(
    parser_context_t* c, pd_utility_batch_V6_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_all_V6(
    parser_context_t* c, pd_utility_batch_all_V6_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

#ifdef SUBSTRATE_PARSER_FULL
__Z_INLINE parser_error_t _readMethod_system_fill_block_V6(
    parser_context_t* c, pd_system_fill_block_V6_t* m)
{
    CHECK_ERROR(_readPerbill_V6(c, &m->_ratio))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_V6(
    parser_context_t* c, pd_system_remark_V6_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->_remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_heap_pages_V6(
    parser_context_t* c, pd_system_set_heap_pages_V6_t* m)
{
    CHECK_ERROR(_readu64(c, &m->pages))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_V6(
    parser_context_t* c, pd_system_set_code_V6_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_without_checks_V6(
    parser_context_t* c, pd_system_set_code_without_checks_V6_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_changes_trie_config_V6(
    parser_context_t* c, pd_system_set_changes_trie_config_V6_t* m)
{
    CHECK_ERROR(_readOptionChangesTrieConfiguration_V6(c, &m->changes_trie_config))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_storage_V6(
    parser_context_t* c, pd_system_set_storage_V6_t* m)
{
    CHECK_ERROR(_readVecKeyValue_V6(c, &m->items))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_kill_storage_V6(
    parser_context_t* c, pd_system_kill_storage_V6_t* m)
{
    CHECK_ERROR(_readVecKey_V6(c, &m->keys))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_kill_prefix_V6(
    parser_context_t* c, pd_system_kill_prefix_V6_t* m)
{
    CHECK_ERROR(_readKey_V6(c, &m->prefix))
    CHECK_ERROR(_readu32(c, &m->_subkeys))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_with_event_V6(
    parser_context_t* c, pd_system_remark_with_event_V6_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_babe_report_equivocation_V6(
    parser_context_t* c, pd_babe_report_equivocation_V6_t* m)
{
    CHECK_ERROR(_readBabeEquivocationProof_V6(c, &m->equivocation_proof))
    CHECK_ERROR(_readKeyOwnerProof_V6(c, &m->key_owner_proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_babe_report_equivocation_unsigned_V6(
    parser_context_t* c, pd_babe_report_equivocation_unsigned_V6_t* m)
{
    CHECK_ERROR(_readBabeEquivocationProof_V6(c, &m->equivocation_proof))
    CHECK_ERROR(_readKeyOwnerProof_V6(c, &m->key_owner_proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_babe_plan_config_change_V6(
    parser_context_t* c, pd_babe_plan_config_change_V6_t* m)
{
    CHECK_ERROR(_readNextConfigDescriptor_V6(c, &m->config))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_timestamp_set_V6(
    parser_context_t* c, pd_timestamp_set_V6_t* m)
{
    CHECK_ERROR(_readCompactMoment_V6(c, &m->now))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_claim_V6(
    parser_context_t* c, pd_indices_claim_V6_t* m)
{
    CHECK_ERROR(_readAccountIndex_V6(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_transfer_V6(
    parser_context_t* c, pd_indices_transfer_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->new_))
    CHECK_ERROR(_readAccountIndex_V6(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_free_V6(
    parser_context_t* c, pd_indices_free_V6_t* m)
{
    CHECK_ERROR(_readAccountIndex_V6(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_force_transfer_V6(
    parser_context_t* c, pd_indices_force_transfer_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->new_))
    CHECK_ERROR(_readAccountIndex_V6(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->freeze))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_freeze_V6(
    parser_context_t* c, pd_indices_freeze_V6_t* m)
{
    CHECK_ERROR(_readAccountIndex_V6(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_set_balance_V6(
    parser_context_t* c, pd_balances_set_balance_V6_t* m)
{
    CHECK_ERROR(_readLookupSource_V6(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->new_free))
    CHECK_ERROR(_readCompactBalance(c, &m->new_reserved))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_transfer_V6(
    parser_context_t* c, pd_balances_force_transfer_V6_t* m)
{
    CHECK_ERROR(_readLookupSource_V6(c, &m->source))
    CHECK_ERROR(_readLookupSource_V6(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_all_V6(
    parser_context_t* c, pd_balances_transfer_all_V6_t* m)
{
    CHECK_ERROR(_readLookupSource_V6(c, &m->dest))
    CHECK_ERROR(_readbool(c, &m->keep_alive))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_authorship_set_uncles_V6(
    parser_context_t* c, pd_authorship_set_uncles_V6_t* m)
{
    CHECK_ERROR(_readVecHeader(c, &m->new_uncles))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_validator_count_V6(
    parser_context_t* c, pd_staking_set_validator_count_V6_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_increase_validator_count_V6(
    parser_context_t* c, pd_staking_increase_validator_count_V6_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->additional))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_scale_validator_count_V6(
    parser_context_t* c, pd_staking_scale_validator_count_V6_t* m)
{
    CHECK_ERROR(_readPercent_V6(c, &m->factor))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_no_eras_V6(
    parser_context_t* c, pd_staking_force_no_eras_V6_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_V6(
    parser_context_t* c, pd_staking_force_new_era_V6_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_invulnerables_V6(
    parser_context_t* c, pd_staking_set_invulnerables_V6_t* m)
{
    CHECK_ERROR(_readVecAccountId_V6(c, &m->invulnerables))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_unstake_V6(
    parser_context_t* c, pd_staking_force_unstake_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_always_V6(
    parser_context_t* c, pd_staking_force_new_era_always_V6_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_cancel_deferred_slash_V6(
    parser_context_t* c, pd_staking_cancel_deferred_slash_V6_t* m)
{
    CHECK_ERROR(_readEraIndex_V6(c, &m->era))
    CHECK_ERROR(_readVecu32(c, &m->slash_indices))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_history_depth_V6(
    parser_context_t* c, pd_staking_set_history_depth_V6_t* m)
{
    CHECK_ERROR(_readCompactEraIndex_V6(c, &m->new_history_depth))
    CHECK_ERROR(_readCompactu32(c, &m->_era_items_deleted))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_reap_stash_V6(
    parser_context_t* c, pd_staking_reap_stash_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_kick_V6(
    parser_context_t* c, pd_staking_kick_V6_t* m)
{
    CHECK_ERROR(_readVecLookupSource_V6(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_staking_limits_V6(
    parser_context_t* c, pd_staking_set_staking_limits_V6_t* m)
{
    CHECK_ERROR(_readBalanceOf(c, &m->min_nominator_bond))
    CHECK_ERROR(_readBalanceOf(c, &m->min_validator_bond))
    CHECK_ERROR(_readOptionu32(c, &m->max_nominator_count))
    CHECK_ERROR(_readOptionu32(c, &m->max_validator_count))
    CHECK_ERROR(_readOptionPercent_V6(c, &m->threshold))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill_other_V6(
    parser_context_t* c, pd_staking_chill_other_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->controller))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_grandpa_report_equivocation_V6(
    parser_context_t* c, pd_grandpa_report_equivocation_V6_t* m)
{
    CHECK_ERROR(_readGrandpaEquivocationProof_V6(c, &m->equivocation_proof))
    CHECK_ERROR(_readKeyOwnerProof_V6(c, &m->key_owner_proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_grandpa_report_equivocation_unsigned_V6(
    parser_context_t* c, pd_grandpa_report_equivocation_unsigned_V6_t* m)
{
    CHECK_ERROR(_readGrandpaEquivocationProof_V6(c, &m->equivocation_proof))
    CHECK_ERROR(_readKeyOwnerProof_V6(c, &m->key_owner_proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_grandpa_note_stalled_V6(
    parser_context_t* c, pd_grandpa_note_stalled_V6_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    CHECK_ERROR(_readBlockNumber(c, &m->best_finalized_block_number))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_imonline_heartbeat_V6(
    parser_context_t* c, pd_imonline_heartbeat_V6_t* m)
{
    CHECK_ERROR(_readHeartbeat(c, &m->heartbeat))
    CHECK_ERROR(_readSignature_V6(c, &m->_signature))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_propose_V6(
    parser_context_t* c, pd_democracy_propose_V6_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_second_V6(
    parser_context_t* c, pd_democracy_second_V6_t* m)
{
    CHECK_ERROR(_readCompactPropIndex_V6(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->seconds_upper_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_vote_V6(
    parser_context_t* c, pd_democracy_vote_V6_t* m)
{
    CHECK_ERROR(_readCompactReferendumIndex_V6(c, &m->ref_index))
    CHECK_ERROR(_readAccountVote_V6(c, &m->vote))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_emergency_cancel_V6(
    parser_context_t* c, pd_democracy_emergency_cancel_V6_t* m)
{
    CHECK_ERROR(_readReferendumIndex_V6(c, &m->ref_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_external_propose_V6(
    parser_context_t* c, pd_democracy_external_propose_V6_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_external_propose_majority_V6(
    parser_context_t* c, pd_democracy_external_propose_majority_V6_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_external_propose_default_V6(
    parser_context_t* c, pd_democracy_external_propose_default_V6_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_fast_track_V6(
    parser_context_t* c, pd_democracy_fast_track_V6_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readBlockNumber(c, &m->voting_period))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_veto_external_V6(
    parser_context_t* c, pd_democracy_veto_external_V6_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_cancel_referendum_V6(
    parser_context_t* c, pd_democracy_cancel_referendum_V6_t* m)
{
    CHECK_ERROR(_readCompactReferendumIndex_V6(c, &m->ref_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_cancel_queued_V6(
    parser_context_t* c, pd_democracy_cancel_queued_V6_t* m)
{
    CHECK_ERROR(_readReferendumIndex_V6(c, &m->which))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_delegate_V6(
    parser_context_t* c, pd_democracy_delegate_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->to))
    CHECK_ERROR(_readConviction_V6(c, &m->conviction))
    CHECK_ERROR(_readBalanceOf(c, &m->balance))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_undelegate_V6(
    parser_context_t* c, pd_democracy_undelegate_V6_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_clear_public_proposals_V6(
    parser_context_t* c, pd_democracy_clear_public_proposals_V6_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_preimage_V6(
    parser_context_t* c, pd_democracy_note_preimage_V6_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_preimage_operational_V6(
    parser_context_t* c, pd_democracy_note_preimage_operational_V6_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_imminent_preimage_V6(
    parser_context_t* c, pd_democracy_note_imminent_preimage_V6_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_imminent_preimage_operational_V6(
    parser_context_t* c, pd_democracy_note_imminent_preimage_operational_V6_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_reap_preimage_V6(
    parser_context_t* c, pd_democracy_reap_preimage_V6_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactu32(c, &m->proposal_len_upper_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_unlock_V6(
    parser_context_t* c, pd_democracy_unlock_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_remove_vote_V6(
    parser_context_t* c, pd_democracy_remove_vote_V6_t* m)
{
    CHECK_ERROR(_readReferendumIndex_V6(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_remove_other_vote_V6(
    parser_context_t* c, pd_democracy_remove_other_vote_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->target))
    CHECK_ERROR(_readReferendumIndex_V6(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_enact_proposal_V6(
    parser_context_t* c, pd_democracy_enact_proposal_V6_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readReferendumIndex_V6(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_blacklist_V6(
    parser_context_t* c, pd_democracy_blacklist_V6_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readOptionReferendumIndex_V6(c, &m->maybe_ref_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_cancel_proposal_V6(
    parser_context_t* c, pd_democracy_cancel_proposal_V6_t* m)
{
    CHECK_ERROR(_readCompactPropIndex_V6(c, &m->prop_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_set_members_V6(
    parser_context_t* c, pd_council_set_members_V6_t* m)
{
    CHECK_ERROR(_readVecAccountId_V6(c, &m->new_members))
    CHECK_ERROR(_readOptionAccountId_V6(c, &m->prime))
    CHECK_ERROR(_readMemberCount_V6(c, &m->old_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_execute_V6(
    parser_context_t* c, pd_council_execute_V6_t* m)
{
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_propose_V6(
    parser_context_t* c, pd_council_propose_V6_t* m)
{
    CHECK_ERROR(_readCompactMemberCount_V6(c, &m->threshold))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_vote_V6(
    parser_context_t* c, pd_council_vote_V6_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readCompactProposalIndex_V6(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_close_V6(
    parser_context_t* c, pd_council_close_V6_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactProposalIndex_V6(c, &m->index))
    CHECK_ERROR(_readCompactWeight_V6(c, &m->proposal_weight_bound))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_disapprove_proposal_V6(
    parser_context_t* c, pd_council_disapprove_proposal_V6_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_set_members_V6(
    parser_context_t* c, pd_technicalcommittee_set_members_V6_t* m)
{
    CHECK_ERROR(_readVecAccountId_V6(c, &m->new_members))
    CHECK_ERROR(_readOptionAccountId_V6(c, &m->prime))
    CHECK_ERROR(_readMemberCount_V6(c, &m->old_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_execute_V6(
    parser_context_t* c, pd_technicalcommittee_execute_V6_t* m)
{
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_propose_V6(
    parser_context_t* c, pd_technicalcommittee_propose_V6_t* m)
{
    CHECK_ERROR(_readCompactMemberCount_V6(c, &m->threshold))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_vote_V6(
    parser_context_t* c, pd_technicalcommittee_vote_V6_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readCompactProposalIndex_V6(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_close_V6(
    parser_context_t* c, pd_technicalcommittee_close_V6_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactProposalIndex_V6(c, &m->index))
    CHECK_ERROR(_readCompactWeight_V6(c, &m->proposal_weight_bound))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_disapprove_proposal_V6(
    parser_context_t* c, pd_technicalcommittee_disapprove_proposal_V6_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_phragmenelection_vote_V6(
    parser_context_t* c, pd_phragmenelection_vote_V6_t* m)
{
    CHECK_ERROR(_readVecAccountId_V6(c, &m->votes))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_phragmenelection_remove_voter_V6(
    parser_context_t* c, pd_phragmenelection_remove_voter_V6_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_phragmenelection_submit_candidacy_V6(
    parser_context_t* c, pd_phragmenelection_submit_candidacy_V6_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->candidate_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_phragmenelection_renounce_candidacy_V6(
    parser_context_t* c, pd_phragmenelection_renounce_candidacy_V6_t* m)
{
    CHECK_ERROR(_readRenouncing_V6(c, &m->renouncing))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_phragmenelection_remove_member_V6(
    parser_context_t* c, pd_phragmenelection_remove_member_V6_t* m)
{
    CHECK_ERROR(_readLookupSource_V6(c, &m->who))
    CHECK_ERROR(_readbool(c, &m->has_replacement))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_phragmenelection_clean_defunct_voters_V6(
    parser_context_t* c, pd_phragmenelection_clean_defunct_voters_V6_t* m)
{
    CHECK_ERROR(_readu32(c, &m->_num_voters))
    CHECK_ERROR(_readu32(c, &m->_num_defunct))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_add_member_V6(
    parser_context_t* c, pd_technicalmembership_add_member_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_remove_member_V6(
    parser_context_t* c, pd_technicalmembership_remove_member_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_swap_member_V6(
    parser_context_t* c, pd_technicalmembership_swap_member_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->remove))
    CHECK_ERROR(_readAccountId_V6(c, &m->add))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_reset_members_V6(
    parser_context_t* c, pd_technicalmembership_reset_members_V6_t* m)
{
    CHECK_ERROR(_readVecAccountId_V6(c, &m->members))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_change_key_V6(
    parser_context_t* c, pd_technicalmembership_change_key_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_set_prime_V6(
    parser_context_t* c, pd_technicalmembership_set_prime_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_clear_prime_V6(
    parser_context_t* c, pd_technicalmembership_clear_prime_V6_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_propose_spend_V6(
    parser_context_t* c, pd_treasury_propose_spend_V6_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    CHECK_ERROR(_readLookupSource_V6(c, &m->beneficiary))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_reject_proposal_V6(
    parser_context_t* c, pd_treasury_reject_proposal_V6_t* m)
{
    CHECK_ERROR(_readCompactProposalIndex_V6(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_approve_proposal_V6(
    parser_context_t* c, pd_treasury_approve_proposal_V6_t* m)
{
    CHECK_ERROR(_readCompactProposalIndex_V6(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_claims_claim_V6(
    parser_context_t* c, pd_claims_claim_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->dest))
    CHECK_ERROR(_readEcdsaSignature_V6(c, &m->ethereum_signature))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_claims_mint_claim_V6(
    parser_context_t* c, pd_claims_mint_claim_V6_t* m)
{
    CHECK_ERROR(_readEthereumAddress_V6(c, &m->who))
    CHECK_ERROR(_readBalanceOf(c, &m->value))
    CHECK_ERROR(_readOptionTupleBalanceOfBalanceOfBlockNumber_V6(c, &m->vesting_schedule))
    CHECK_ERROR(_readOptionStatementKind_V6(c, &m->statement))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_claims_claim_attest_V6(
    parser_context_t* c, pd_claims_claim_attest_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->dest))
    CHECK_ERROR(_readEcdsaSignature_V6(c, &m->ethereum_signature))
    CHECK_ERROR(_readBytes(c, &m->statement))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_claims_attest_V6(
    parser_context_t* c, pd_claims_attest_V6_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->statement))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_claims_move_claim_V6(
    parser_context_t* c, pd_claims_move_claim_V6_t* m)
{
    CHECK_ERROR(_readEthereumAddress_V6(c, &m->old))
    CHECK_ERROR(_readEthereumAddress_V6(c, &m->new_))
    CHECK_ERROR(_readOptionAccountId_V6(c, &m->maybe_preclaim))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_as_derivative_V6(
    parser_context_t* c, pd_utility_as_derivative_V6_t* m)
{
    CHECK_ERROR(_readu16(c, &m->index))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_registrar_V6(
    parser_context_t* c, pd_identity_add_registrar_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_identity_V6(
    parser_context_t* c, pd_identity_set_identity_V6_t* m)
{
    CHECK_ERROR(_readIdentityInfo_V6(c, &m->info))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_subs_V6(
    parser_context_t* c, pd_identity_set_subs_V6_t* m)
{
    CHECK_ERROR(_readVecTupleAccountIdData_V6(c, &m->subs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_clear_identity_V6(
    parser_context_t* c, pd_identity_clear_identity_V6_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_request_judgement_V6(
    parser_context_t* c, pd_identity_request_judgement_V6_t* m)
{
    CHECK_ERROR(_readCompactRegistrarIndex_V6(c, &m->reg_index))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->max_fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_cancel_request_V6(
    parser_context_t* c, pd_identity_cancel_request_V6_t* m)
{
    CHECK_ERROR(_readRegistrarIndex_V6(c, &m->reg_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_fee_V6(
    parser_context_t* c, pd_identity_set_fee_V6_t* m)
{
    CHECK_ERROR(_readCompactRegistrarIndex_V6(c, &m->index))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_account_id_V6(
    parser_context_t* c, pd_identity_set_account_id_V6_t* m)
{
    CHECK_ERROR(_readCompactRegistrarIndex_V6(c, &m->index))
    CHECK_ERROR(_readAccountId_V6(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_fields_V6(
    parser_context_t* c, pd_identity_set_fields_V6_t* m)
{
    CHECK_ERROR(_readCompactRegistrarIndex_V6(c, &m->index))
    CHECK_ERROR(_readIdentityFields_V6(c, &m->fields))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_provide_judgement_V6(
    parser_context_t* c, pd_identity_provide_judgement_V6_t* m)
{
    CHECK_ERROR(_readCompactRegistrarIndex_V6(c, &m->reg_index))
    CHECK_ERROR(_readLookupSource_V6(c, &m->target))
    CHECK_ERROR(_readIdentityJudgement_V6(c, &m->judgement))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_kill_identity_V6(
    parser_context_t* c, pd_identity_kill_identity_V6_t* m)
{
    CHECK_ERROR(_readLookupSource_V6(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_sub_V6(
    parser_context_t* c, pd_identity_add_sub_V6_t* m)
{
    CHECK_ERROR(_readLookupSource_V6(c, &m->sub))
    CHECK_ERROR(_readData(c, &m->data))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_rename_sub_V6(
    parser_context_t* c, pd_identity_rename_sub_V6_t* m)
{
    CHECK_ERROR(_readLookupSource_V6(c, &m->sub))
    CHECK_ERROR(_readData(c, &m->data))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_remove_sub_V6(
    parser_context_t* c, pd_identity_remove_sub_V6_t* m)
{
    CHECK_ERROR(_readLookupSource_V6(c, &m->sub))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_quit_sub_V6(
    parser_context_t* c, pd_identity_quit_sub_V6_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_bid_V6(
    parser_context_t* c, pd_society_bid_V6_t* m)
{
    CHECK_ERROR(_readBalanceOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_unbid_V6(
    parser_context_t* c, pd_society_unbid_V6_t* m)
{
    CHECK_ERROR(_readu32(c, &m->pos))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_vouch_V6(
    parser_context_t* c, pd_society_vouch_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->who))
    CHECK_ERROR(_readBalanceOf(c, &m->value))
    CHECK_ERROR(_readBalanceOf(c, &m->tip))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_unvouch_V6(
    parser_context_t* c, pd_society_unvouch_V6_t* m)
{
    CHECK_ERROR(_readu32(c, &m->pos))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_vote_V6(
    parser_context_t* c, pd_society_vote_V6_t* m)
{
    CHECK_ERROR(_readLookupSource_V6(c, &m->candidate))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_defender_vote_V6(
    parser_context_t* c, pd_society_defender_vote_V6_t* m)
{
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_payout_V6(
    parser_context_t* c, pd_society_payout_V6_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_found_V6(
    parser_context_t* c, pd_society_found_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->founder))
    CHECK_ERROR(_readu32(c, &m->max_members))
    CHECK_ERROR(_readBytes(c, &m->rules))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_unfound_V6(
    parser_context_t* c, pd_society_unfound_V6_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_judge_suspended_member_V6(
    parser_context_t* c, pd_society_judge_suspended_member_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->who))
    CHECK_ERROR(_readbool(c, &m->forgive))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_judge_suspended_candidate_V6(
    parser_context_t* c, pd_society_judge_suspended_candidate_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->who))
    CHECK_ERROR(_readSocietyJudgement_V6(c, &m->judgement))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_set_max_members_V6(
    parser_context_t* c, pd_society_set_max_members_V6_t* m)
{
    CHECK_ERROR(_readu32(c, &m->max))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_as_recovered_V6(
    parser_context_t* c, pd_recovery_as_recovered_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->account))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_set_recovered_V6(
    parser_context_t* c, pd_recovery_set_recovered_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->lost))
    CHECK_ERROR(_readAccountId_V6(c, &m->rescuer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_create_recovery_V6(
    parser_context_t* c, pd_recovery_create_recovery_V6_t* m)
{
    CHECK_ERROR(_readVecAccountId_V6(c, &m->friends))
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readBlockNumber(c, &m->delay_period))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_initiate_recovery_V6(
    parser_context_t* c, pd_recovery_initiate_recovery_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_vouch_recovery_V6(
    parser_context_t* c, pd_recovery_vouch_recovery_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->lost))
    CHECK_ERROR(_readAccountId_V6(c, &m->rescuer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_claim_recovery_V6(
    parser_context_t* c, pd_recovery_claim_recovery_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_close_recovery_V6(
    parser_context_t* c, pd_recovery_close_recovery_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->rescuer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_remove_recovery_V6(
    parser_context_t* c, pd_recovery_remove_recovery_V6_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_cancel_recovered_V6(
    parser_context_t* c, pd_recovery_cancel_recovered_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vest_V6(
    parser_context_t* c, pd_vesting_vest_V6_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vest_other_V6(
    parser_context_t* c, pd_vesting_vest_other_V6_t* m)
{
    CHECK_ERROR(_readLookupSource_V6(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vested_transfer_V6(
    parser_context_t* c, pd_vesting_vested_transfer_V6_t* m)
{
    CHECK_ERROR(_readLookupSource_V6(c, &m->target))
    CHECK_ERROR(_readVestingInfo_V6(c, &m->schedule))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_force_vested_transfer_V6(
    parser_context_t* c, pd_vesting_force_vested_transfer_V6_t* m)
{
    CHECK_ERROR(_readLookupSource_V6(c, &m->source))
    CHECK_ERROR(_readLookupSource_V6(c, &m->target))
    CHECK_ERROR(_readVestingInfo_V6(c, &m->schedule))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_V6(
    parser_context_t* c, pd_scheduler_schedule_V6_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->when))
    CHECK_ERROR(_readOptionPeriod_V6(c, &m->maybe_periodic))
    CHECK_ERROR(_readPriority_V6(c, &m->priority))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_cancel_V6(
    parser_context_t* c, pd_scheduler_cancel_V6_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->when))
    CHECK_ERROR(_readu32(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_named_V6(
    parser_context_t* c, pd_scheduler_schedule_named_V6_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->id))
    CHECK_ERROR(_readBlockNumber(c, &m->when))
    CHECK_ERROR(_readOptionPeriod_V6(c, &m->maybe_periodic))
    CHECK_ERROR(_readPriority_V6(c, &m->priority))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_cancel_named_V6(
    parser_context_t* c, pd_scheduler_cancel_named_V6_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_after_V6(
    parser_context_t* c, pd_scheduler_schedule_after_V6_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->after))
    CHECK_ERROR(_readOptionPeriod_V6(c, &m->maybe_periodic))
    CHECK_ERROR(_readPriority_V6(c, &m->priority))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_named_after_V6(
    parser_context_t* c, pd_scheduler_schedule_named_after_V6_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->id))
    CHECK_ERROR(_readBlockNumber(c, &m->after))
    CHECK_ERROR(_readOptionPeriod_V6(c, &m->maybe_periodic))
    CHECK_ERROR(_readPriority_V6(c, &m->priority))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_proxy_V6(
    parser_context_t* c, pd_proxy_proxy_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->real))
    CHECK_ERROR(_readOptionProxyType_V6(c, &m->force_proxy_type))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_add_proxy_V6(
    parser_context_t* c, pd_proxy_add_proxy_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->delegate))
    CHECK_ERROR(_readProxyType_V6(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_proxy_V6(
    parser_context_t* c, pd_proxy_remove_proxy_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->delegate))
    CHECK_ERROR(_readProxyType_V6(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_proxies_V6(
    parser_context_t* c, pd_proxy_remove_proxies_V6_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_anonymous_V6(
    parser_context_t* c, pd_proxy_anonymous_V6_t* m)
{
    CHECK_ERROR(_readProxyType_V6(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    CHECK_ERROR(_readu16(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_kill_anonymous_V6(
    parser_context_t* c, pd_proxy_kill_anonymous_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->spawner))
    CHECK_ERROR(_readProxyType_V6(c, &m->proxy_type))
    CHECK_ERROR(_readu16(c, &m->index))
    CHECK_ERROR(_readCompactBlockNumber(c, &m->height))
    CHECK_ERROR(_readCompactu32(c, &m->ext_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_announce_V6(
    parser_context_t* c, pd_proxy_announce_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->real))
    CHECK_ERROR(_readCallHashOf_V6(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_announcement_V6(
    parser_context_t* c, pd_proxy_remove_announcement_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->real))
    CHECK_ERROR(_readCallHashOf_V6(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_reject_announcement_V6(
    parser_context_t* c, pd_proxy_reject_announcement_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->delegate))
    CHECK_ERROR(_readCallHashOf_V6(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_proxy_announced_V6(
    parser_context_t* c, pd_proxy_proxy_announced_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->delegate))
    CHECK_ERROR(_readAccountId_V6(c, &m->real))
    CHECK_ERROR(_readOptionProxyType_V6(c, &m->force_proxy_type))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_threshold_1_V6(
    parser_context_t* c, pd_multisig_as_multi_threshold_1_V6_t* m)
{
    CHECK_ERROR(_readVecAccountId_V6(c, &m->other_signatories))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_V6(
    parser_context_t* c, pd_multisig_as_multi_V6_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V6(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint_V6(c, &m->maybe_timepoint))
    CHECK_ERROR(_readOpaqueCall_V6(c, &m->call))
    CHECK_ERROR(_readbool(c, &m->store_call))
    CHECK_ERROR(_readWeight_V6(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_approve_as_multi_V6(
    parser_context_t* c, pd_multisig_approve_as_multi_V6_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V6(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint_V6(c, &m->maybe_timepoint))
    CHECK_ERROR(_readu8_array_32_V6(c, &m->call_hash))
    CHECK_ERROR(_readWeight_V6(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_cancel_as_multi_V6(
    parser_context_t* c, pd_multisig_cancel_as_multi_V6_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V6(c, &m->other_signatories))
    CHECK_ERROR(_readTimepoint_V6(c, &m->timepoint))
    CHECK_ERROR(_readu8_array_32_V6(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_propose_bounty_V6(
    parser_context_t* c, pd_bounties_propose_bounty_V6_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    CHECK_ERROR(_readBytes(c, &m->description))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_approve_bounty_V6(
    parser_context_t* c, pd_bounties_approve_bounty_V6_t* m)
{
    CHECK_ERROR(_readCompactBountyIndex_V6(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_propose_curator_V6(
    parser_context_t* c, pd_bounties_propose_curator_V6_t* m)
{
    CHECK_ERROR(_readCompactBountyIndex_V6(c, &m->bounty_id))
    CHECK_ERROR(_readLookupSource_V6(c, &m->curator))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_unassign_curator_V6(
    parser_context_t* c, pd_bounties_unassign_curator_V6_t* m)
{
    CHECK_ERROR(_readCompactBountyIndex_V6(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_accept_curator_V6(
    parser_context_t* c, pd_bounties_accept_curator_V6_t* m)
{
    CHECK_ERROR(_readCompactBountyIndex_V6(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_award_bounty_V6(
    parser_context_t* c, pd_bounties_award_bounty_V6_t* m)
{
    CHECK_ERROR(_readCompactBountyIndex_V6(c, &m->bounty_id))
    CHECK_ERROR(_readLookupSource_V6(c, &m->beneficiary))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_claim_bounty_V6(
    parser_context_t* c, pd_bounties_claim_bounty_V6_t* m)
{
    CHECK_ERROR(_readCompactBountyIndex_V6(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_close_bounty_V6(
    parser_context_t* c, pd_bounties_close_bounty_V6_t* m)
{
    CHECK_ERROR(_readCompactBountyIndex_V6(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_extend_bounty_expiry_V6(
    parser_context_t* c, pd_bounties_extend_bounty_expiry_V6_t* m)
{
    CHECK_ERROR(_readCompactBountyIndex_V6(c, &m->bounty_id))
    CHECK_ERROR(_readBytes(c, &m->_remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_tips_report_awesome_V6(
    parser_context_t* c, pd_tips_report_awesome_V6_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->reason))
    CHECK_ERROR(_readAccountId_V6(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_tips_retract_tip_V6(
    parser_context_t* c, pd_tips_retract_tip_V6_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_tips_tip_new_V6(
    parser_context_t* c, pd_tips_tip_new_V6_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->reason))
    CHECK_ERROR(_readAccountId_V6(c, &m->who))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->tip_value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_tips_tip_V6(
    parser_context_t* c, pd_tips_tip_V6_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->tip_value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_tips_close_tip_V6(
    parser_context_t* c, pd_tips_close_tip_V6_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_tips_slash_tip_V6(
    parser_context_t* c, pd_tips_slash_tip_V6_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_electionprovidermultiphase_submit_unsigned_V6(
    parser_context_t* c, pd_electionprovidermultiphase_submit_unsigned_V6_t* m)
{
    CHECK_ERROR(_readRawSolution_V6(c, &m->raw_solution))
    CHECK_ERROR(_readSolutionOrSnapshotSize_V6(c, &m->witness))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_electionprovidermultiphase_set_minimum_untrusted_score_V6(
    parser_context_t* c, pd_electionprovidermultiphase_set_minimum_untrusted_score_V6_t* m)
{
    CHECK_ERROR(_readOptionElectionScore_V6(c, &m->maybe_next_score))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_electionprovidermultiphase_set_emergency_election_result_V6(
    parser_context_t* c, pd_electionprovidermultiphase_set_emergency_election_result_V6_t* m)
{
    CHECK_ERROR(_readSupports_V6(c, &m->supports))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_electionprovidermultiphase_submit_V6(
    parser_context_t* c, pd_electionprovidermultiphase_submit_V6_t* m)
{
    CHECK_ERROR(_readRawSolution_V6(c, &m->raw_solution))
    CHECK_ERROR(_readu32(c, &m->num_signed_submissions))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_gilt_place_bid_V6(
    parser_context_t* c, pd_gilt_place_bid_V6_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->amount))
    CHECK_ERROR(_readu32(c, &m->duration))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_gilt_retract_bid_V6(
    parser_context_t* c, pd_gilt_retract_bid_V6_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->amount))
    CHECK_ERROR(_readu32(c, &m->duration))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_gilt_set_target_V6(
    parser_context_t* c, pd_gilt_set_target_V6_t* m)
{
    CHECK_ERROR(_readCompactPerquintill_V6(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_gilt_thaw_V6(
    parser_context_t* c, pd_gilt_thaw_V6_t* m)
{
    CHECK_ERROR(_readCompactActiveIndex_V6(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_validation_upgrade_frequency_V6(
    parser_context_t* c, pd_configuration_set_validation_upgrade_frequency_V6_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_validation_upgrade_delay_V6(
    parser_context_t* c, pd_configuration_set_validation_upgrade_delay_V6_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_code_retention_period_V6(
    parser_context_t* c, pd_configuration_set_code_retention_period_V6_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_code_size_V6(
    parser_context_t* c, pd_configuration_set_max_code_size_V6_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_pov_size_V6(
    parser_context_t* c, pd_configuration_set_max_pov_size_V6_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_head_data_size_V6(
    parser_context_t* c, pd_configuration_set_max_head_data_size_V6_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_parathread_cores_V6(
    parser_context_t* c, pd_configuration_set_parathread_cores_V6_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_parathread_retries_V6(
    parser_context_t* c, pd_configuration_set_parathread_retries_V6_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_group_rotation_frequency_V6(
    parser_context_t* c, pd_configuration_set_group_rotation_frequency_V6_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_chain_availability_period_V6(
    parser_context_t* c, pd_configuration_set_chain_availability_period_V6_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_thread_availability_period_V6(
    parser_context_t* c, pd_configuration_set_thread_availability_period_V6_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_scheduling_lookahead_V6(
    parser_context_t* c, pd_configuration_set_scheduling_lookahead_V6_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_validators_per_core_V6(
    parser_context_t* c, pd_configuration_set_max_validators_per_core_V6_t* m)
{
    CHECK_ERROR(_readOptionu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_validators_V6(
    parser_context_t* c, pd_configuration_set_max_validators_V6_t* m)
{
    CHECK_ERROR(_readOptionu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_dispute_period_V6(
    parser_context_t* c, pd_configuration_set_dispute_period_V6_t* m)
{
    CHECK_ERROR(_readSessionIndex_V6(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_dispute_post_conclusion_acceptance_period_V6(
    parser_context_t* c, pd_configuration_set_dispute_post_conclusion_acceptance_period_V6_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_dispute_max_spam_slots_V6(
    parser_context_t* c, pd_configuration_set_dispute_max_spam_slots_V6_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_dispute_conclusion_by_time_out_period_V6(
    parser_context_t* c, pd_configuration_set_dispute_conclusion_by_time_out_period_V6_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_no_show_slots_V6(
    parser_context_t* c, pd_configuration_set_no_show_slots_V6_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_n_delay_tranches_V6(
    parser_context_t* c, pd_configuration_set_n_delay_tranches_V6_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_zeroth_delay_tranche_width_V6(
    parser_context_t* c, pd_configuration_set_zeroth_delay_tranche_width_V6_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_needed_approvals_V6(
    parser_context_t* c, pd_configuration_set_needed_approvals_V6_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_relay_vrf_modulo_samples_V6(
    parser_context_t* c, pd_configuration_set_relay_vrf_modulo_samples_V6_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_upward_queue_count_V6(
    parser_context_t* c, pd_configuration_set_max_upward_queue_count_V6_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_upward_queue_size_V6(
    parser_context_t* c, pd_configuration_set_max_upward_queue_size_V6_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_downward_message_size_V6(
    parser_context_t* c, pd_configuration_set_max_downward_message_size_V6_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_ump_service_total_weight_V6(
    parser_context_t* c, pd_configuration_set_ump_service_total_weight_V6_t* m)
{
    CHECK_ERROR(_readWeight_V6(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_upward_message_size_V6(
    parser_context_t* c, pd_configuration_set_max_upward_message_size_V6_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_upward_message_num_per_candidate_V6(
    parser_context_t* c, pd_configuration_set_max_upward_message_num_per_candidate_V6_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_open_request_ttl_V6(
    parser_context_t* c, pd_configuration_set_hrmp_open_request_ttl_V6_t* m)
{
    CHECK_ERROR(_readu32(c, &m->_new))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_sender_deposit_V6(
    parser_context_t* c, pd_configuration_set_hrmp_sender_deposit_V6_t* m)
{
    CHECK_ERROR(_readBalance(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_recipient_deposit_V6(
    parser_context_t* c, pd_configuration_set_hrmp_recipient_deposit_V6_t* m)
{
    CHECK_ERROR(_readBalance(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_channel_max_capacity_V6(
    parser_context_t* c, pd_configuration_set_hrmp_channel_max_capacity_V6_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_channel_max_total_size_V6(
    parser_context_t* c, pd_configuration_set_hrmp_channel_max_total_size_V6_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_max_parachain_inbound_channels_V6(
    parser_context_t* c, pd_configuration_set_hrmp_max_parachain_inbound_channels_V6_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_max_parathread_inbound_channels_V6(
    parser_context_t* c, pd_configuration_set_hrmp_max_parathread_inbound_channels_V6_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_channel_max_message_size_V6(
    parser_context_t* c, pd_configuration_set_hrmp_channel_max_message_size_V6_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_max_parachain_outbound_channels_V6(
    parser_context_t* c, pd_configuration_set_hrmp_max_parachain_outbound_channels_V6_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_max_parathread_outbound_channels_V6(
    parser_context_t* c, pd_configuration_set_hrmp_max_parathread_outbound_channels_V6_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_max_message_num_per_candidate_V6(
    parser_context_t* c, pd_configuration_set_hrmp_max_message_num_per_candidate_V6_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_ump_max_individual_weight_V6(
    parser_context_t* c, pd_configuration_set_ump_max_individual_weight_V6_t* m)
{
    CHECK_ERROR(_readWeight_V6(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_parainherent_enter_V6(
    parser_context_t* c, pd_parainherent_enter_V6_t* m)
{
    CHECK_ERROR(_readParachainsInherentData_V6(c, &m->data))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_paras_force_set_current_code_V6(
    parser_context_t* c, pd_paras_force_set_current_code_V6_t* m)
{
    CHECK_ERROR(_readParaId_V6(c, &m->para))
    CHECK_ERROR(_readValidationCode_V6(c, &m->new_code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_paras_force_set_current_head_V6(
    parser_context_t* c, pd_paras_force_set_current_head_V6_t* m)
{
    CHECK_ERROR(_readParaId_V6(c, &m->para))
    CHECK_ERROR(_readHeadData_V6(c, &m->new_head))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_paras_force_schedule_code_upgrade_V6(
    parser_context_t* c, pd_paras_force_schedule_code_upgrade_V6_t* m)
{
    CHECK_ERROR(_readParaId_V6(c, &m->para))
    CHECK_ERROR(_readValidationCode_V6(c, &m->new_code))
    CHECK_ERROR(_readBlockNumber(c, &m->relay_parent_number))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_paras_force_note_new_head_V6(
    parser_context_t* c, pd_paras_force_note_new_head_V6_t* m)
{
    CHECK_ERROR(_readParaId_V6(c, &m->para))
    CHECK_ERROR(_readHeadData_V6(c, &m->new_head))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_paras_force_queue_action_V6(
    parser_context_t* c, pd_paras_force_queue_action_V6_t* m)
{
    CHECK_ERROR(_readParaId_V6(c, &m->para))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_initializer_force_approve_V6(
    parser_context_t* c, pd_initializer_force_approve_V6_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->up_to))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_ump_service_overweight_V6(
    parser_context_t* c, pd_ump_service_overweight_V6_t* m)
{
    CHECK_ERROR(_readOverweightIndex_V6(c, &m->index))
    CHECK_ERROR(_readWeight_V6(c, &m->weight_limit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_hrmp_hrmp_init_open_channel_V6(
    parser_context_t* c, pd_hrmp_hrmp_init_open_channel_V6_t* m)
{
    CHECK_ERROR(_readParaId_V6(c, &m->recipient))
    CHECK_ERROR(_readu32(c, &m->proposed_max_capacity))
    CHECK_ERROR(_readu32(c, &m->proposed_max_message_size))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_hrmp_hrmp_accept_open_channel_V6(
    parser_context_t* c, pd_hrmp_hrmp_accept_open_channel_V6_t* m)
{
    CHECK_ERROR(_readParaId_V6(c, &m->sender))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_hrmp_hrmp_close_channel_V6(
    parser_context_t* c, pd_hrmp_hrmp_close_channel_V6_t* m)
{
    CHECK_ERROR(_readHrmpChannelId_V6(c, &m->channel_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_hrmp_force_clean_hrmp_V6(
    parser_context_t* c, pd_hrmp_force_clean_hrmp_V6_t* m)
{
    CHECK_ERROR(_readParaId_V6(c, &m->para))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_hrmp_force_process_hrmp_open_V6(
    parser_context_t* c, pd_hrmp_force_process_hrmp_open_V6_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_hrmp_force_process_hrmp_close_V6(
    parser_context_t* c, pd_hrmp_force_process_hrmp_close_V6_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_hrmp_hrmp_cancel_open_request_V6(
    parser_context_t* c, pd_hrmp_hrmp_cancel_open_request_V6_t* m)
{
    CHECK_ERROR(_readHrmpChannelId_V6(c, &m->channel_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_registrar_register_V6(
    parser_context_t* c, pd_registrar_register_V6_t* m)
{
    CHECK_ERROR(_readParaId_V6(c, &m->id))
    CHECK_ERROR(_readHeadData_V6(c, &m->genesis_head))
    CHECK_ERROR(_readValidationCode_V6(c, &m->validation_code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_registrar_force_register_V6(
    parser_context_t* c, pd_registrar_force_register_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->who))
    CHECK_ERROR(_readBalanceOf(c, &m->deposit))
    CHECK_ERROR(_readParaId_V6(c, &m->id))
    CHECK_ERROR(_readHeadData_V6(c, &m->genesis_head))
    CHECK_ERROR(_readValidationCode_V6(c, &m->validation_code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_registrar_deregister_V6(
    parser_context_t* c, pd_registrar_deregister_V6_t* m)
{
    CHECK_ERROR(_readParaId_V6(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_registrar_swap_V6(
    parser_context_t* c, pd_registrar_swap_V6_t* m)
{
    CHECK_ERROR(_readParaId_V6(c, &m->id))
    CHECK_ERROR(_readParaId_V6(c, &m->other))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_registrar_force_remove_lock_V6(
    parser_context_t* c, pd_registrar_force_remove_lock_V6_t* m)
{
    CHECK_ERROR(_readParaId_V6(c, &m->para))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_registrar_reserve_V6(
    parser_context_t* c, pd_registrar_reserve_V6_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_slots_force_lease_V6(
    parser_context_t* c, pd_slots_force_lease_V6_t* m)
{
    CHECK_ERROR(_readParaId_V6(c, &m->para))
    CHECK_ERROR(_readAccountId_V6(c, &m->leaser))
    CHECK_ERROR(_readBalanceOf(c, &m->amount))
    CHECK_ERROR(_readLeasePeriodOf_V6(c, &m->period_begin))
    CHECK_ERROR(_readLeasePeriodOf_V6(c, &m->period_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_slots_clear_all_leases_V6(
    parser_context_t* c, pd_slots_clear_all_leases_V6_t* m)
{
    CHECK_ERROR(_readParaId_V6(c, &m->para))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_slots_trigger_onboard_V6(
    parser_context_t* c, pd_slots_trigger_onboard_V6_t* m)
{
    CHECK_ERROR(_readParaId_V6(c, &m->para))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_auctions_new_auction_V6(
    parser_context_t* c, pd_auctions_new_auction_V6_t* m)
{
    CHECK_ERROR(_readCompactBlockNumber(c, &m->duration))
    CHECK_ERROR(_readCompactLeasePeriodOf_V6(c, &m->lease_period_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_auctions_bid_V6(
    parser_context_t* c, pd_auctions_bid_V6_t* m)
{
    CHECK_ERROR(_readCompactParaId_V6(c, &m->para))
    CHECK_ERROR(_readCompactAuctionIndex_V6(c, &m->auction_index))
    CHECK_ERROR(_readCompactLeasePeriodOf_V6(c, &m->first_slot))
    CHECK_ERROR(_readCompactLeasePeriodOf_V6(c, &m->last_slot))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_auctions_cancel_auction_V6(
    parser_context_t* c, pd_auctions_cancel_auction_V6_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloan_create_V6(
    parser_context_t* c, pd_crowdloan_create_V6_t* m)
{
    CHECK_ERROR(_readCompactParaId_V6(c, &m->index))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->cap))
    CHECK_ERROR(_readCompactLeasePeriodOf_V6(c, &m->first_period))
    CHECK_ERROR(_readCompactLeasePeriodOf_V6(c, &m->last_period))
    CHECK_ERROR(_readCompactBlockNumber(c, &m->end))
    CHECK_ERROR(_readOptionMultiSigner_V6(c, &m->verifier))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloan_contribute_V6(
    parser_context_t* c, pd_crowdloan_contribute_V6_t* m)
{
    CHECK_ERROR(_readCompactParaId_V6(c, &m->index))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    CHECK_ERROR(_readOptionMultiSignature_V6(c, &m->signature))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloan_withdraw_V6(
    parser_context_t* c, pd_crowdloan_withdraw_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->who))
    CHECK_ERROR(_readCompactParaId_V6(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloan_refund_V6(
    parser_context_t* c, pd_crowdloan_refund_V6_t* m)
{
    CHECK_ERROR(_readCompactParaId_V6(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloan_dissolve_V6(
    parser_context_t* c, pd_crowdloan_dissolve_V6_t* m)
{
    CHECK_ERROR(_readCompactParaId_V6(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloan_edit_V6(
    parser_context_t* c, pd_crowdloan_edit_V6_t* m)
{
    CHECK_ERROR(_readCompactParaId_V6(c, &m->index))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->cap))
    CHECK_ERROR(_readCompactLeasePeriodOf_V6(c, &m->first_period))
    CHECK_ERROR(_readCompactLeasePeriodOf_V6(c, &m->last_period))
    CHECK_ERROR(_readCompactBlockNumber(c, &m->end))
    CHECK_ERROR(_readOptionMultiSigner_V6(c, &m->verifier))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloan_add_memo_V6(
    parser_context_t* c, pd_crowdloan_add_memo_V6_t* m)
{
    CHECK_ERROR(_readParaId_V6(c, &m->index))
    CHECK_ERROR(_readBytes(c, &m->memo))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloan_poke_V6(
    parser_context_t* c, pd_crowdloan_poke_V6_t* m)
{
    CHECK_ERROR(_readParaId_V6(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpallet_send_V6(
    parser_context_t* c, pd_xcmpallet_send_V6_t* m)
{
    CHECK_ERROR(_readVersionedMultiLocation_V6(c, &m->dest))
    CHECK_ERROR(_readVersionedXcm_V6(c, &m->message))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpallet_teleport_assets_V6(
    parser_context_t* c, pd_xcmpallet_teleport_assets_V6_t* m)
{
    CHECK_ERROR(_readVersionedMultiLocation_V6(c, &m->dest))
    CHECK_ERROR(_readVersionedMultiLocation_V6(c, &m->beneficiary))
    CHECK_ERROR(_readVersionedMultiAssets_V6(c, &m->assets))
    CHECK_ERROR(_readu32(c, &m->fee_asset_item))
    CHECK_ERROR(_readWeight_V6(c, &m->dest_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpallet_reserve_transfer_assets_V6(
    parser_context_t* c, pd_xcmpallet_reserve_transfer_assets_V6_t* m)
{
    CHECK_ERROR(_readVersionedMultiLocation_V6(c, &m->dest))
    CHECK_ERROR(_readVersionedMultiLocation_V6(c, &m->beneficiary))
    CHECK_ERROR(_readVersionedMultiAssets_V6(c, &m->assets))
    CHECK_ERROR(_readu32(c, &m->fee_asset_item))
    CHECK_ERROR(_readWeight_V6(c, &m->dest_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpallet_execute_V6(
    parser_context_t* c, pd_xcmpallet_execute_V6_t* m)
{
    CHECK_ERROR(_readVersionedXcm_V6(c, &m->message))
    CHECK_ERROR(_readWeight_V6(c, &m->max_weight))
    return parser_ok;
}

#endif

parser_error_t _readMethod_V6(
    parser_context_t* c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_Method_V6_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

    case 1024: /* module 4 call 0 */
        CHECK_ERROR(_readMethod_balances_transfer_V6(c, &method->nested.balances_transfer_V6))
        break;
    case 1027: /* module 4 call 3 */
        CHECK_ERROR(_readMethod_balances_transfer_keep_alive_V6(c, &method->nested.balances_transfer_keep_alive_V6))
        break;
    case 1536: /* module 6 call 0 */
        CHECK_ERROR(_readMethod_staking_bond_V6(c, &method->basic.staking_bond_V6))
        break;
    case 1537: /* module 6 call 1 */
        CHECK_ERROR(_readMethod_staking_bond_extra_V6(c, &method->basic.staking_bond_extra_V6))
        break;
    case 1538: /* module 6 call 2 */
        CHECK_ERROR(_readMethod_staking_unbond_V6(c, &method->basic.staking_unbond_V6))
        break;
    case 1539: /* module 6 call 3 */
        CHECK_ERROR(_readMethod_staking_withdraw_unbonded_V6(c, &method->basic.staking_withdraw_unbonded_V6))
        break;
    case 1540: /* module 6 call 4 */
        CHECK_ERROR(_readMethod_staking_validate_V6(c, &method->basic.staking_validate_V6))
        break;
    case 1541: /* module 6 call 5 */
        CHECK_ERROR(_readMethod_staking_nominate_V6(c, &method->basic.staking_nominate_V6))
        break;
    case 1542: /* module 6 call 6 */
        CHECK_ERROR(_readMethod_staking_chill_V6(c, &method->basic.staking_chill_V6))
        break;
    case 1543: /* module 6 call 7 */
        CHECK_ERROR(_readMethod_staking_set_payee_V6(c, &method->basic.staking_set_payee_V6))
        break;
    case 1544: /* module 6 call 8 */
        CHECK_ERROR(_readMethod_staking_set_controller_V6(c, &method->basic.staking_set_controller_V6))
        break;
    case 1554: /* module 6 call 18 */
        CHECK_ERROR(_readMethod_staking_payout_stakers_V6(c, &method->basic.staking_payout_stakers_V6))
        break;
    case 1555: /* module 6 call 19 */
        CHECK_ERROR(_readMethod_staking_rebond_V6(c, &method->basic.staking_rebond_V6))
        break;
    case 2048: /* module 8 call 0 */
        CHECK_ERROR(_readMethod_session_set_keys_V6(c, &method->basic.session_set_keys_V6))
        break;
    case 2049: /* module 8 call 1 */
        CHECK_ERROR(_readMethod_session_purge_keys_V6(c, &method->basic.session_purge_keys_V6))
        break;
    case 6144: /* module 24 call 0 */
        CHECK_ERROR(_readMethod_utility_batch_V6(c, &method->basic.utility_batch_V6))
        break;
    case 6146: /* module 24 call 2 */
        CHECK_ERROR(_readMethod_utility_batch_all_V6(c, &method->basic.utility_batch_all_V6))
        break;

#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        CHECK_ERROR(_readMethod_system_fill_block_V6(c, &method->nested.system_fill_block_V6))
        break;
    case 1: /* module 0 call 1 */
        CHECK_ERROR(_readMethod_system_remark_V6(c, &method->nested.system_remark_V6))
        break;
    case 2: /* module 0 call 2 */
        CHECK_ERROR(_readMethod_system_set_heap_pages_V6(c, &method->nested.system_set_heap_pages_V6))
        break;
    case 3: /* module 0 call 3 */
        CHECK_ERROR(_readMethod_system_set_code_V6(c, &method->nested.system_set_code_V6))
        break;
    case 4: /* module 0 call 4 */
        CHECK_ERROR(_readMethod_system_set_code_without_checks_V6(c, &method->nested.system_set_code_without_checks_V6))
        break;
    case 5: /* module 0 call 5 */
        CHECK_ERROR(_readMethod_system_set_changes_trie_config_V6(c, &method->nested.system_set_changes_trie_config_V6))
        break;
    case 6: /* module 0 call 6 */
        CHECK_ERROR(_readMethod_system_set_storage_V6(c, &method->nested.system_set_storage_V6))
        break;
    case 7: /* module 0 call 7 */
        CHECK_ERROR(_readMethod_system_kill_storage_V6(c, &method->nested.system_kill_storage_V6))
        break;
    case 8: /* module 0 call 8 */
        CHECK_ERROR(_readMethod_system_kill_prefix_V6(c, &method->nested.system_kill_prefix_V6))
        break;
    case 9: /* module 0 call 9 */
        CHECK_ERROR(_readMethod_system_remark_with_event_V6(c, &method->basic.system_remark_with_event_V6))
        break;
    case 256: /* module 1 call 0 */
        CHECK_ERROR(_readMethod_babe_report_equivocation_V6(c, &method->basic.babe_report_equivocation_V6))
        break;
    case 257: /* module 1 call 1 */
        CHECK_ERROR(_readMethod_babe_report_equivocation_unsigned_V6(c, &method->basic.babe_report_equivocation_unsigned_V6))
        break;
    case 258: /* module 1 call 2 */
        CHECK_ERROR(_readMethod_babe_plan_config_change_V6(c, &method->basic.babe_plan_config_change_V6))
        break;
    case 512: /* module 2 call 0 */
        CHECK_ERROR(_readMethod_timestamp_set_V6(c, &method->basic.timestamp_set_V6))
        break;
    case 768: /* module 3 call 0 */
        CHECK_ERROR(_readMethod_indices_claim_V6(c, &method->basic.indices_claim_V6))
        break;
    case 769: /* module 3 call 1 */
        CHECK_ERROR(_readMethod_indices_transfer_V6(c, &method->basic.indices_transfer_V6))
        break;
    case 770: /* module 3 call 2 */
        CHECK_ERROR(_readMethod_indices_free_V6(c, &method->basic.indices_free_V6))
        break;
    case 771: /* module 3 call 3 */
        CHECK_ERROR(_readMethod_indices_force_transfer_V6(c, &method->basic.indices_force_transfer_V6))
        break;
    case 772: /* module 3 call 4 */
        CHECK_ERROR(_readMethod_indices_freeze_V6(c, &method->basic.indices_freeze_V6))
        break;
    case 1025: /* module 4 call 1 */
        CHECK_ERROR(_readMethod_balances_set_balance_V6(c, &method->nested.balances_set_balance_V6))
        break;
    case 1026: /* module 4 call 2 */
        CHECK_ERROR(_readMethod_balances_force_transfer_V6(c, &method->nested.balances_force_transfer_V6))
        break;
    case 1028: /* module 4 call 4 */
        CHECK_ERROR(_readMethod_balances_transfer_all_V6(c, &method->basic.balances_transfer_all_V6))
        break;
    case 1280: /* module 5 call 0 */
        CHECK_ERROR(_readMethod_authorship_set_uncles_V6(c, &method->basic.authorship_set_uncles_V6))
        break;
    case 1545: /* module 6 call 9 */
        CHECK_ERROR(_readMethod_staking_set_validator_count_V6(c, &method->basic.staking_set_validator_count_V6))
        break;
    case 1546: /* module 6 call 10 */
        CHECK_ERROR(_readMethod_staking_increase_validator_count_V6(c, &method->basic.staking_increase_validator_count_V6))
        break;
    case 1547: /* module 6 call 11 */
        CHECK_ERROR(_readMethod_staking_scale_validator_count_V6(c, &method->basic.staking_scale_validator_count_V6))
        break;
    case 1548: /* module 6 call 12 */
        CHECK_ERROR(_readMethod_staking_force_no_eras_V6(c, &method->basic.staking_force_no_eras_V6))
        break;
    case 1549: /* module 6 call 13 */
        CHECK_ERROR(_readMethod_staking_force_new_era_V6(c, &method->basic.staking_force_new_era_V6))
        break;
    case 1550: /* module 6 call 14 */
        CHECK_ERROR(_readMethod_staking_set_invulnerables_V6(c, &method->basic.staking_set_invulnerables_V6))
        break;
    case 1551: /* module 6 call 15 */
        CHECK_ERROR(_readMethod_staking_force_unstake_V6(c, &method->basic.staking_force_unstake_V6))
        break;
    case 1552: /* module 6 call 16 */
        CHECK_ERROR(_readMethod_staking_force_new_era_always_V6(c, &method->basic.staking_force_new_era_always_V6))
        break;
    case 1553: /* module 6 call 17 */
        CHECK_ERROR(_readMethod_staking_cancel_deferred_slash_V6(c, &method->basic.staking_cancel_deferred_slash_V6))
        break;
    case 1556: /* module 6 call 20 */
        CHECK_ERROR(_readMethod_staking_set_history_depth_V6(c, &method->basic.staking_set_history_depth_V6))
        break;
    case 1557: /* module 6 call 21 */
        CHECK_ERROR(_readMethod_staking_reap_stash_V6(c, &method->basic.staking_reap_stash_V6))
        break;
    case 1558: /* module 6 call 22 */
        CHECK_ERROR(_readMethod_staking_kick_V6(c, &method->basic.staking_kick_V6))
        break;
    case 1559: /* module 6 call 23 */
        CHECK_ERROR(_readMethod_staking_set_staking_limits_V6(c, &method->basic.staking_set_staking_limits_V6))
        break;
    case 1560: /* module 6 call 24 */
        CHECK_ERROR(_readMethod_staking_chill_other_V6(c, &method->basic.staking_chill_other_V6))
        break;
    case 2560: /* module 10 call 0 */
        CHECK_ERROR(_readMethod_grandpa_report_equivocation_V6(c, &method->basic.grandpa_report_equivocation_V6))
        break;
    case 2561: /* module 10 call 1 */
        CHECK_ERROR(_readMethod_grandpa_report_equivocation_unsigned_V6(c, &method->basic.grandpa_report_equivocation_unsigned_V6))
        break;
    case 2562: /* module 10 call 2 */
        CHECK_ERROR(_readMethod_grandpa_note_stalled_V6(c, &method->basic.grandpa_note_stalled_V6))
        break;
    case 2816: /* module 11 call 0 */
        CHECK_ERROR(_readMethod_imonline_heartbeat_V6(c, &method->basic.imonline_heartbeat_V6))
        break;
    case 3328: /* module 13 call 0 */
        CHECK_ERROR(_readMethod_democracy_propose_V6(c, &method->basic.democracy_propose_V6))
        break;
    case 3329: /* module 13 call 1 */
        CHECK_ERROR(_readMethod_democracy_second_V6(c, &method->basic.democracy_second_V6))
        break;
    case 3330: /* module 13 call 2 */
        CHECK_ERROR(_readMethod_democracy_vote_V6(c, &method->basic.democracy_vote_V6))
        break;
    case 3331: /* module 13 call 3 */
        CHECK_ERROR(_readMethod_democracy_emergency_cancel_V6(c, &method->basic.democracy_emergency_cancel_V6))
        break;
    case 3332: /* module 13 call 4 */
        CHECK_ERROR(_readMethod_democracy_external_propose_V6(c, &method->basic.democracy_external_propose_V6))
        break;
    case 3333: /* module 13 call 5 */
        CHECK_ERROR(_readMethod_democracy_external_propose_majority_V6(c, &method->basic.democracy_external_propose_majority_V6))
        break;
    case 3334: /* module 13 call 6 */
        CHECK_ERROR(_readMethod_democracy_external_propose_default_V6(c, &method->basic.democracy_external_propose_default_V6))
        break;
    case 3335: /* module 13 call 7 */
        CHECK_ERROR(_readMethod_democracy_fast_track_V6(c, &method->basic.democracy_fast_track_V6))
        break;
    case 3336: /* module 13 call 8 */
        CHECK_ERROR(_readMethod_democracy_veto_external_V6(c, &method->basic.democracy_veto_external_V6))
        break;
    case 3337: /* module 13 call 9 */
        CHECK_ERROR(_readMethod_democracy_cancel_referendum_V6(c, &method->basic.democracy_cancel_referendum_V6))
        break;
    case 3338: /* module 13 call 10 */
        CHECK_ERROR(_readMethod_democracy_cancel_queued_V6(c, &method->basic.democracy_cancel_queued_V6))
        break;
    case 3339: /* module 13 call 11 */
        CHECK_ERROR(_readMethod_democracy_delegate_V6(c, &method->basic.democracy_delegate_V6))
        break;
    case 3340: /* module 13 call 12 */
        CHECK_ERROR(_readMethod_democracy_undelegate_V6(c, &method->basic.democracy_undelegate_V6))
        break;
    case 3341: /* module 13 call 13 */
        CHECK_ERROR(_readMethod_democracy_clear_public_proposals_V6(c, &method->basic.democracy_clear_public_proposals_V6))
        break;
    case 3342: /* module 13 call 14 */
        CHECK_ERROR(_readMethod_democracy_note_preimage_V6(c, &method->basic.democracy_note_preimage_V6))
        break;
    case 3343: /* module 13 call 15 */
        CHECK_ERROR(_readMethod_democracy_note_preimage_operational_V6(c, &method->basic.democracy_note_preimage_operational_V6))
        break;
    case 3344: /* module 13 call 16 */
        CHECK_ERROR(_readMethod_democracy_note_imminent_preimage_V6(c, &method->basic.democracy_note_imminent_preimage_V6))
        break;
    case 3345: /* module 13 call 17 */
        CHECK_ERROR(_readMethod_democracy_note_imminent_preimage_operational_V6(c, &method->basic.democracy_note_imminent_preimage_operational_V6))
        break;
    case 3346: /* module 13 call 18 */
        CHECK_ERROR(_readMethod_democracy_reap_preimage_V6(c, &method->basic.democracy_reap_preimage_V6))
        break;
    case 3347: /* module 13 call 19 */
        CHECK_ERROR(_readMethod_democracy_unlock_V6(c, &method->basic.democracy_unlock_V6))
        break;
    case 3348: /* module 13 call 20 */
        CHECK_ERROR(_readMethod_democracy_remove_vote_V6(c, &method->basic.democracy_remove_vote_V6))
        break;
    case 3349: /* module 13 call 21 */
        CHECK_ERROR(_readMethod_democracy_remove_other_vote_V6(c, &method->basic.democracy_remove_other_vote_V6))
        break;
    case 3350: /* module 13 call 22 */
        CHECK_ERROR(_readMethod_democracy_enact_proposal_V6(c, &method->basic.democracy_enact_proposal_V6))
        break;
    case 3351: /* module 13 call 23 */
        CHECK_ERROR(_readMethod_democracy_blacklist_V6(c, &method->basic.democracy_blacklist_V6))
        break;
    case 3352: /* module 13 call 24 */
        CHECK_ERROR(_readMethod_democracy_cancel_proposal_V6(c, &method->basic.democracy_cancel_proposal_V6))
        break;
    case 3584: /* module 14 call 0 */
        CHECK_ERROR(_readMethod_council_set_members_V6(c, &method->basic.council_set_members_V6))
        break;
    case 3585: /* module 14 call 1 */
        CHECK_ERROR(_readMethod_council_execute_V6(c, &method->basic.council_execute_V6))
        break;
    case 3586: /* module 14 call 2 */
        CHECK_ERROR(_readMethod_council_propose_V6(c, &method->basic.council_propose_V6))
        break;
    case 3587: /* module 14 call 3 */
        CHECK_ERROR(_readMethod_council_vote_V6(c, &method->basic.council_vote_V6))
        break;
    case 3588: /* module 14 call 4 */
        CHECK_ERROR(_readMethod_council_close_V6(c, &method->basic.council_close_V6))
        break;
    case 3589: /* module 14 call 5 */
        CHECK_ERROR(_readMethod_council_disapprove_proposal_V6(c, &method->basic.council_disapprove_proposal_V6))
        break;
    case 3840: /* module 15 call 0 */
        CHECK_ERROR(_readMethod_technicalcommittee_set_members_V6(c, &method->basic.technicalcommittee_set_members_V6))
        break;
    case 3841: /* module 15 call 1 */
        CHECK_ERROR(_readMethod_technicalcommittee_execute_V6(c, &method->basic.technicalcommittee_execute_V6))
        break;
    case 3842: /* module 15 call 2 */
        CHECK_ERROR(_readMethod_technicalcommittee_propose_V6(c, &method->basic.technicalcommittee_propose_V6))
        break;
    case 3843: /* module 15 call 3 */
        CHECK_ERROR(_readMethod_technicalcommittee_vote_V6(c, &method->basic.technicalcommittee_vote_V6))
        break;
    case 3844: /* module 15 call 4 */
        CHECK_ERROR(_readMethod_technicalcommittee_close_V6(c, &method->basic.technicalcommittee_close_V6))
        break;
    case 3845: /* module 15 call 5 */
        CHECK_ERROR(_readMethod_technicalcommittee_disapprove_proposal_V6(c, &method->basic.technicalcommittee_disapprove_proposal_V6))
        break;
    case 4096: /* module 16 call 0 */
        CHECK_ERROR(_readMethod_phragmenelection_vote_V6(c, &method->basic.phragmenelection_vote_V6))
        break;
    case 4097: /* module 16 call 1 */
        CHECK_ERROR(_readMethod_phragmenelection_remove_voter_V6(c, &method->basic.phragmenelection_remove_voter_V6))
        break;
    case 4098: /* module 16 call 2 */
        CHECK_ERROR(_readMethod_phragmenelection_submit_candidacy_V6(c, &method->basic.phragmenelection_submit_candidacy_V6))
        break;
    case 4099: /* module 16 call 3 */
        CHECK_ERROR(_readMethod_phragmenelection_renounce_candidacy_V6(c, &method->basic.phragmenelection_renounce_candidacy_V6))
        break;
    case 4100: /* module 16 call 4 */
        CHECK_ERROR(_readMethod_phragmenelection_remove_member_V6(c, &method->basic.phragmenelection_remove_member_V6))
        break;
    case 4101: /* module 16 call 5 */
        CHECK_ERROR(_readMethod_phragmenelection_clean_defunct_voters_V6(c, &method->basic.phragmenelection_clean_defunct_voters_V6))
        break;
    case 4352: /* module 17 call 0 */
        CHECK_ERROR(_readMethod_technicalmembership_add_member_V6(c, &method->basic.technicalmembership_add_member_V6))
        break;
    case 4353: /* module 17 call 1 */
        CHECK_ERROR(_readMethod_technicalmembership_remove_member_V6(c, &method->basic.technicalmembership_remove_member_V6))
        break;
    case 4354: /* module 17 call 2 */
        CHECK_ERROR(_readMethod_technicalmembership_swap_member_V6(c, &method->basic.technicalmembership_swap_member_V6))
        break;
    case 4355: /* module 17 call 3 */
        CHECK_ERROR(_readMethod_technicalmembership_reset_members_V6(c, &method->basic.technicalmembership_reset_members_V6))
        break;
    case 4356: /* module 17 call 4 */
        CHECK_ERROR(_readMethod_technicalmembership_change_key_V6(c, &method->basic.technicalmembership_change_key_V6))
        break;
    case 4357: /* module 17 call 5 */
        CHECK_ERROR(_readMethod_technicalmembership_set_prime_V6(c, &method->basic.technicalmembership_set_prime_V6))
        break;
    case 4358: /* module 17 call 6 */
        CHECK_ERROR(_readMethod_technicalmembership_clear_prime_V6(c, &method->basic.technicalmembership_clear_prime_V6))
        break;
    case 4608: /* module 18 call 0 */
        CHECK_ERROR(_readMethod_treasury_propose_spend_V6(c, &method->basic.treasury_propose_spend_V6))
        break;
    case 4609: /* module 18 call 1 */
        CHECK_ERROR(_readMethod_treasury_reject_proposal_V6(c, &method->basic.treasury_reject_proposal_V6))
        break;
    case 4610: /* module 18 call 2 */
        CHECK_ERROR(_readMethod_treasury_approve_proposal_V6(c, &method->basic.treasury_approve_proposal_V6))
        break;
    case 4864: /* module 19 call 0 */
        CHECK_ERROR(_readMethod_claims_claim_V6(c, &method->basic.claims_claim_V6))
        break;
    case 4865: /* module 19 call 1 */
        CHECK_ERROR(_readMethod_claims_mint_claim_V6(c, &method->basic.claims_mint_claim_V6))
        break;
    case 4866: /* module 19 call 2 */
        CHECK_ERROR(_readMethod_claims_claim_attest_V6(c, &method->basic.claims_claim_attest_V6))
        break;
    case 4867: /* module 19 call 3 */
        CHECK_ERROR(_readMethod_claims_attest_V6(c, &method->basic.claims_attest_V6))
        break;
    case 4868: /* module 19 call 4 */
        CHECK_ERROR(_readMethod_claims_move_claim_V6(c, &method->basic.claims_move_claim_V6))
        break;
    case 6145: /* module 24 call 1 */
        CHECK_ERROR(_readMethod_utility_as_derivative_V6(c, &method->basic.utility_as_derivative_V6))
        break;
    case 6400: /* module 25 call 0 */
        CHECK_ERROR(_readMethod_identity_add_registrar_V6(c, &method->basic.identity_add_registrar_V6))
        break;
    case 6401: /* module 25 call 1 */
        CHECK_ERROR(_readMethod_identity_set_identity_V6(c, &method->basic.identity_set_identity_V6))
        break;
    case 6402: /* module 25 call 2 */
        CHECK_ERROR(_readMethod_identity_set_subs_V6(c, &method->basic.identity_set_subs_V6))
        break;
    case 6403: /* module 25 call 3 */
        CHECK_ERROR(_readMethod_identity_clear_identity_V6(c, &method->basic.identity_clear_identity_V6))
        break;
    case 6404: /* module 25 call 4 */
        CHECK_ERROR(_readMethod_identity_request_judgement_V6(c, &method->basic.identity_request_judgement_V6))
        break;
    case 6405: /* module 25 call 5 */
        CHECK_ERROR(_readMethod_identity_cancel_request_V6(c, &method->basic.identity_cancel_request_V6))
        break;
    case 6406: /* module 25 call 6 */
        CHECK_ERROR(_readMethod_identity_set_fee_V6(c, &method->basic.identity_set_fee_V6))
        break;
    case 6407: /* module 25 call 7 */
        CHECK_ERROR(_readMethod_identity_set_account_id_V6(c, &method->basic.identity_set_account_id_V6))
        break;
    case 6408: /* module 25 call 8 */
        CHECK_ERROR(_readMethod_identity_set_fields_V6(c, &method->basic.identity_set_fields_V6))
        break;
    case 6409: /* module 25 call 9 */
        CHECK_ERROR(_readMethod_identity_provide_judgement_V6(c, &method->basic.identity_provide_judgement_V6))
        break;
    case 6410: /* module 25 call 10 */
        CHECK_ERROR(_readMethod_identity_kill_identity_V6(c, &method->basic.identity_kill_identity_V6))
        break;
    case 6411: /* module 25 call 11 */
        CHECK_ERROR(_readMethod_identity_add_sub_V6(c, &method->basic.identity_add_sub_V6))
        break;
    case 6412: /* module 25 call 12 */
        CHECK_ERROR(_readMethod_identity_rename_sub_V6(c, &method->basic.identity_rename_sub_V6))
        break;
    case 6413: /* module 25 call 13 */
        CHECK_ERROR(_readMethod_identity_remove_sub_V6(c, &method->basic.identity_remove_sub_V6))
        break;
    case 6414: /* module 25 call 14 */
        CHECK_ERROR(_readMethod_identity_quit_sub_V6(c, &method->basic.identity_quit_sub_V6))
        break;
    case 6656: /* module 26 call 0 */
        CHECK_ERROR(_readMethod_society_bid_V6(c, &method->basic.society_bid_V6))
        break;
    case 6657: /* module 26 call 1 */
        CHECK_ERROR(_readMethod_society_unbid_V6(c, &method->basic.society_unbid_V6))
        break;
    case 6658: /* module 26 call 2 */
        CHECK_ERROR(_readMethod_society_vouch_V6(c, &method->basic.society_vouch_V6))
        break;
    case 6659: /* module 26 call 3 */
        CHECK_ERROR(_readMethod_society_unvouch_V6(c, &method->basic.society_unvouch_V6))
        break;
    case 6660: /* module 26 call 4 */
        CHECK_ERROR(_readMethod_society_vote_V6(c, &method->basic.society_vote_V6))
        break;
    case 6661: /* module 26 call 5 */
        CHECK_ERROR(_readMethod_society_defender_vote_V6(c, &method->basic.society_defender_vote_V6))
        break;
    case 6662: /* module 26 call 6 */
        CHECK_ERROR(_readMethod_society_payout_V6(c, &method->basic.society_payout_V6))
        break;
    case 6663: /* module 26 call 7 */
        CHECK_ERROR(_readMethod_society_found_V6(c, &method->basic.society_found_V6))
        break;
    case 6664: /* module 26 call 8 */
        CHECK_ERROR(_readMethod_society_unfound_V6(c, &method->basic.society_unfound_V6))
        break;
    case 6665: /* module 26 call 9 */
        CHECK_ERROR(_readMethod_society_judge_suspended_member_V6(c, &method->basic.society_judge_suspended_member_V6))
        break;
    case 6666: /* module 26 call 10 */
        CHECK_ERROR(_readMethod_society_judge_suspended_candidate_V6(c, &method->basic.society_judge_suspended_candidate_V6))
        break;
    case 6667: /* module 26 call 11 */
        CHECK_ERROR(_readMethod_society_set_max_members_V6(c, &method->basic.society_set_max_members_V6))
        break;
    case 6912: /* module 27 call 0 */
        CHECK_ERROR(_readMethod_recovery_as_recovered_V6(c, &method->basic.recovery_as_recovered_V6))
        break;
    case 6913: /* module 27 call 1 */
        CHECK_ERROR(_readMethod_recovery_set_recovered_V6(c, &method->basic.recovery_set_recovered_V6))
        break;
    case 6914: /* module 27 call 2 */
        CHECK_ERROR(_readMethod_recovery_create_recovery_V6(c, &method->basic.recovery_create_recovery_V6))
        break;
    case 6915: /* module 27 call 3 */
        CHECK_ERROR(_readMethod_recovery_initiate_recovery_V6(c, &method->basic.recovery_initiate_recovery_V6))
        break;
    case 6916: /* module 27 call 4 */
        CHECK_ERROR(_readMethod_recovery_vouch_recovery_V6(c, &method->basic.recovery_vouch_recovery_V6))
        break;
    case 6917: /* module 27 call 5 */
        CHECK_ERROR(_readMethod_recovery_claim_recovery_V6(c, &method->basic.recovery_claim_recovery_V6))
        break;
    case 6918: /* module 27 call 6 */
        CHECK_ERROR(_readMethod_recovery_close_recovery_V6(c, &method->basic.recovery_close_recovery_V6))
        break;
    case 6919: /* module 27 call 7 */
        CHECK_ERROR(_readMethod_recovery_remove_recovery_V6(c, &method->basic.recovery_remove_recovery_V6))
        break;
    case 6920: /* module 27 call 8 */
        CHECK_ERROR(_readMethod_recovery_cancel_recovered_V6(c, &method->basic.recovery_cancel_recovered_V6))
        break;
    case 7168: /* module 28 call 0 */
        CHECK_ERROR(_readMethod_vesting_vest_V6(c, &method->basic.vesting_vest_V6))
        break;
    case 7169: /* module 28 call 1 */
        CHECK_ERROR(_readMethod_vesting_vest_other_V6(c, &method->basic.vesting_vest_other_V6))
        break;
    case 7170: /* module 28 call 2 */
        CHECK_ERROR(_readMethod_vesting_vested_transfer_V6(c, &method->basic.vesting_vested_transfer_V6))
        break;
    case 7171: /* module 28 call 3 */
        CHECK_ERROR(_readMethod_vesting_force_vested_transfer_V6(c, &method->basic.vesting_force_vested_transfer_V6))
        break;
    case 7424: /* module 29 call 0 */
        CHECK_ERROR(_readMethod_scheduler_schedule_V6(c, &method->basic.scheduler_schedule_V6))
        break;
    case 7425: /* module 29 call 1 */
        CHECK_ERROR(_readMethod_scheduler_cancel_V6(c, &method->basic.scheduler_cancel_V6))
        break;
    case 7426: /* module 29 call 2 */
        CHECK_ERROR(_readMethod_scheduler_schedule_named_V6(c, &method->basic.scheduler_schedule_named_V6))
        break;
    case 7427: /* module 29 call 3 */
        CHECK_ERROR(_readMethod_scheduler_cancel_named_V6(c, &method->basic.scheduler_cancel_named_V6))
        break;
    case 7428: /* module 29 call 4 */
        CHECK_ERROR(_readMethod_scheduler_schedule_after_V6(c, &method->basic.scheduler_schedule_after_V6))
        break;
    case 7429: /* module 29 call 5 */
        CHECK_ERROR(_readMethod_scheduler_schedule_named_after_V6(c, &method->basic.scheduler_schedule_named_after_V6))
        break;
    case 7680: /* module 30 call 0 */
        CHECK_ERROR(_readMethod_proxy_proxy_V6(c, &method->nested.proxy_proxy_V6))
        break;
    case 7681: /* module 30 call 1 */
        CHECK_ERROR(_readMethod_proxy_add_proxy_V6(c, &method->basic.proxy_add_proxy_V6))
        break;
    case 7682: /* module 30 call 2 */
        CHECK_ERROR(_readMethod_proxy_remove_proxy_V6(c, &method->basic.proxy_remove_proxy_V6))
        break;
    case 7683: /* module 30 call 3 */
        CHECK_ERROR(_readMethod_proxy_remove_proxies_V6(c, &method->basic.proxy_remove_proxies_V6))
        break;
    case 7684: /* module 30 call 4 */
        CHECK_ERROR(_readMethod_proxy_anonymous_V6(c, &method->basic.proxy_anonymous_V6))
        break;
    case 7685: /* module 30 call 5 */
        CHECK_ERROR(_readMethod_proxy_kill_anonymous_V6(c, &method->basic.proxy_kill_anonymous_V6))
        break;
    case 7686: /* module 30 call 6 */
        CHECK_ERROR(_readMethod_proxy_announce_V6(c, &method->basic.proxy_announce_V6))
        break;
    case 7687: /* module 30 call 7 */
        CHECK_ERROR(_readMethod_proxy_remove_announcement_V6(c, &method->basic.proxy_remove_announcement_V6))
        break;
    case 7688: /* module 30 call 8 */
        CHECK_ERROR(_readMethod_proxy_reject_announcement_V6(c, &method->basic.proxy_reject_announcement_V6))
        break;
    case 7689: /* module 30 call 9 */
        CHECK_ERROR(_readMethod_proxy_proxy_announced_V6(c, &method->basic.proxy_proxy_announced_V6))
        break;
    case 7936: /* module 31 call 0 */
        CHECK_ERROR(_readMethod_multisig_as_multi_threshold_1_V6(c, &method->nested.multisig_as_multi_threshold_1_V6))
        break;
    case 7937: /* module 31 call 1 */
        CHECK_ERROR(_readMethod_multisig_as_multi_V6(c, &method->nested.multisig_as_multi_V6))
        break;
    case 7938: /* module 31 call 2 */
        CHECK_ERROR(_readMethod_multisig_approve_as_multi_V6(c, &method->nested.multisig_approve_as_multi_V6))
        break;
    case 7939: /* module 31 call 3 */
        CHECK_ERROR(_readMethod_multisig_cancel_as_multi_V6(c, &method->nested.multisig_cancel_as_multi_V6))
        break;
    case 8960: /* module 35 call 0 */
        CHECK_ERROR(_readMethod_bounties_propose_bounty_V6(c, &method->basic.bounties_propose_bounty_V6))
        break;
    case 8961: /* module 35 call 1 */
        CHECK_ERROR(_readMethod_bounties_approve_bounty_V6(c, &method->basic.bounties_approve_bounty_V6))
        break;
    case 8962: /* module 35 call 2 */
        CHECK_ERROR(_readMethod_bounties_propose_curator_V6(c, &method->basic.bounties_propose_curator_V6))
        break;
    case 8963: /* module 35 call 3 */
        CHECK_ERROR(_readMethod_bounties_unassign_curator_V6(c, &method->basic.bounties_unassign_curator_V6))
        break;
    case 8964: /* module 35 call 4 */
        CHECK_ERROR(_readMethod_bounties_accept_curator_V6(c, &method->basic.bounties_accept_curator_V6))
        break;
    case 8965: /* module 35 call 5 */
        CHECK_ERROR(_readMethod_bounties_award_bounty_V6(c, &method->basic.bounties_award_bounty_V6))
        break;
    case 8966: /* module 35 call 6 */
        CHECK_ERROR(_readMethod_bounties_claim_bounty_V6(c, &method->basic.bounties_claim_bounty_V6))
        break;
    case 8967: /* module 35 call 7 */
        CHECK_ERROR(_readMethod_bounties_close_bounty_V6(c, &method->basic.bounties_close_bounty_V6))
        break;
    case 8968: /* module 35 call 8 */
        CHECK_ERROR(_readMethod_bounties_extend_bounty_expiry_V6(c, &method->basic.bounties_extend_bounty_expiry_V6))
        break;
    case 9216: /* module 36 call 0 */
        CHECK_ERROR(_readMethod_tips_report_awesome_V6(c, &method->basic.tips_report_awesome_V6))
        break;
    case 9217: /* module 36 call 1 */
        CHECK_ERROR(_readMethod_tips_retract_tip_V6(c, &method->basic.tips_retract_tip_V6))
        break;
    case 9218: /* module 36 call 2 */
        CHECK_ERROR(_readMethod_tips_tip_new_V6(c, &method->basic.tips_tip_new_V6))
        break;
    case 9219: /* module 36 call 3 */
        CHECK_ERROR(_readMethod_tips_tip_V6(c, &method->basic.tips_tip_V6))
        break;
    case 9220: /* module 36 call 4 */
        CHECK_ERROR(_readMethod_tips_close_tip_V6(c, &method->basic.tips_close_tip_V6))
        break;
    case 9221: /* module 36 call 5 */
        CHECK_ERROR(_readMethod_tips_slash_tip_V6(c, &method->basic.tips_slash_tip_V6))
        break;
    case 9472: /* module 37 call 0 */
        CHECK_ERROR(_readMethod_electionprovidermultiphase_submit_unsigned_V6(c, &method->basic.electionprovidermultiphase_submit_unsigned_V6))
        break;
    case 9473: /* module 37 call 1 */
        CHECK_ERROR(_readMethod_electionprovidermultiphase_set_minimum_untrusted_score_V6(c, &method->basic.electionprovidermultiphase_set_minimum_untrusted_score_V6))
        break;
    case 9474: /* module 37 call 2 */
        CHECK_ERROR(_readMethod_electionprovidermultiphase_set_emergency_election_result_V6(c, &method->basic.electionprovidermultiphase_set_emergency_election_result_V6))
        break;
    case 9475: /* module 37 call 3 */
        CHECK_ERROR(_readMethod_electionprovidermultiphase_submit_V6(c, &method->basic.electionprovidermultiphase_submit_V6))
        break;
    case 9728: /* module 38 call 0 */
        CHECK_ERROR(_readMethod_gilt_place_bid_V6(c, &method->basic.gilt_place_bid_V6))
        break;
    case 9729: /* module 38 call 1 */
        CHECK_ERROR(_readMethod_gilt_retract_bid_V6(c, &method->basic.gilt_retract_bid_V6))
        break;
    case 9730: /* module 38 call 2 */
        CHECK_ERROR(_readMethod_gilt_set_target_V6(c, &method->basic.gilt_set_target_V6))
        break;
    case 9731: /* module 38 call 3 */
        CHECK_ERROR(_readMethod_gilt_thaw_V6(c, &method->basic.gilt_thaw_V6))
        break;
    case 13056: /* module 51 call 0 */
        CHECK_ERROR(_readMethod_configuration_set_validation_upgrade_frequency_V6(c, &method->basic.configuration_set_validation_upgrade_frequency_V6))
        break;
    case 13057: /* module 51 call 1 */
        CHECK_ERROR(_readMethod_configuration_set_validation_upgrade_delay_V6(c, &method->basic.configuration_set_validation_upgrade_delay_V6))
        break;
    case 13058: /* module 51 call 2 */
        CHECK_ERROR(_readMethod_configuration_set_code_retention_period_V6(c, &method->basic.configuration_set_code_retention_period_V6))
        break;
    case 13059: /* module 51 call 3 */
        CHECK_ERROR(_readMethod_configuration_set_max_code_size_V6(c, &method->basic.configuration_set_max_code_size_V6))
        break;
    case 13060: /* module 51 call 4 */
        CHECK_ERROR(_readMethod_configuration_set_max_pov_size_V6(c, &method->basic.configuration_set_max_pov_size_V6))
        break;
    case 13061: /* module 51 call 5 */
        CHECK_ERROR(_readMethod_configuration_set_max_head_data_size_V6(c, &method->basic.configuration_set_max_head_data_size_V6))
        break;
    case 13062: /* module 51 call 6 */
        CHECK_ERROR(_readMethod_configuration_set_parathread_cores_V6(c, &method->basic.configuration_set_parathread_cores_V6))
        break;
    case 13063: /* module 51 call 7 */
        CHECK_ERROR(_readMethod_configuration_set_parathread_retries_V6(c, &method->basic.configuration_set_parathread_retries_V6))
        break;
    case 13064: /* module 51 call 8 */
        CHECK_ERROR(_readMethod_configuration_set_group_rotation_frequency_V6(c, &method->basic.configuration_set_group_rotation_frequency_V6))
        break;
    case 13065: /* module 51 call 9 */
        CHECK_ERROR(_readMethod_configuration_set_chain_availability_period_V6(c, &method->basic.configuration_set_chain_availability_period_V6))
        break;
    case 13066: /* module 51 call 10 */
        CHECK_ERROR(_readMethod_configuration_set_thread_availability_period_V6(c, &method->basic.configuration_set_thread_availability_period_V6))
        break;
    case 13067: /* module 51 call 11 */
        CHECK_ERROR(_readMethod_configuration_set_scheduling_lookahead_V6(c, &method->basic.configuration_set_scheduling_lookahead_V6))
        break;
    case 13068: /* module 51 call 12 */
        CHECK_ERROR(_readMethod_configuration_set_max_validators_per_core_V6(c, &method->basic.configuration_set_max_validators_per_core_V6))
        break;
    case 13069: /* module 51 call 13 */
        CHECK_ERROR(_readMethod_configuration_set_max_validators_V6(c, &method->basic.configuration_set_max_validators_V6))
        break;
    case 13070: /* module 51 call 14 */
        CHECK_ERROR(_readMethod_configuration_set_dispute_period_V6(c, &method->basic.configuration_set_dispute_period_V6))
        break;
    case 13071: /* module 51 call 15 */
        CHECK_ERROR(_readMethod_configuration_set_dispute_post_conclusion_acceptance_period_V6(c, &method->basic.configuration_set_dispute_post_conclusion_acceptance_period_V6))
        break;
    case 13072: /* module 51 call 16 */
        CHECK_ERROR(_readMethod_configuration_set_dispute_max_spam_slots_V6(c, &method->basic.configuration_set_dispute_max_spam_slots_V6))
        break;
    case 13073: /* module 51 call 17 */
        CHECK_ERROR(_readMethod_configuration_set_dispute_conclusion_by_time_out_period_V6(c, &method->basic.configuration_set_dispute_conclusion_by_time_out_period_V6))
        break;
    case 13074: /* module 51 call 18 */
        CHECK_ERROR(_readMethod_configuration_set_no_show_slots_V6(c, &method->basic.configuration_set_no_show_slots_V6))
        break;
    case 13075: /* module 51 call 19 */
        CHECK_ERROR(_readMethod_configuration_set_n_delay_tranches_V6(c, &method->basic.configuration_set_n_delay_tranches_V6))
        break;
    case 13076: /* module 51 call 20 */
        CHECK_ERROR(_readMethod_configuration_set_zeroth_delay_tranche_width_V6(c, &method->basic.configuration_set_zeroth_delay_tranche_width_V6))
        break;
    case 13077: /* module 51 call 21 */
        CHECK_ERROR(_readMethod_configuration_set_needed_approvals_V6(c, &method->basic.configuration_set_needed_approvals_V6))
        break;
    case 13078: /* module 51 call 22 */
        CHECK_ERROR(_readMethod_configuration_set_relay_vrf_modulo_samples_V6(c, &method->basic.configuration_set_relay_vrf_modulo_samples_V6))
        break;
    case 13079: /* module 51 call 23 */
        CHECK_ERROR(_readMethod_configuration_set_max_upward_queue_count_V6(c, &method->basic.configuration_set_max_upward_queue_count_V6))
        break;
    case 13080: /* module 51 call 24 */
        CHECK_ERROR(_readMethod_configuration_set_max_upward_queue_size_V6(c, &method->basic.configuration_set_max_upward_queue_size_V6))
        break;
    case 13081: /* module 51 call 25 */
        CHECK_ERROR(_readMethod_configuration_set_max_downward_message_size_V6(c, &method->basic.configuration_set_max_downward_message_size_V6))
        break;
    case 13082: /* module 51 call 26 */
        CHECK_ERROR(_readMethod_configuration_set_ump_service_total_weight_V6(c, &method->basic.configuration_set_ump_service_total_weight_V6))
        break;
    case 13083: /* module 51 call 27 */
        CHECK_ERROR(_readMethod_configuration_set_max_upward_message_size_V6(c, &method->basic.configuration_set_max_upward_message_size_V6))
        break;
    case 13084: /* module 51 call 28 */
        CHECK_ERROR(_readMethod_configuration_set_max_upward_message_num_per_candidate_V6(c, &method->basic.configuration_set_max_upward_message_num_per_candidate_V6))
        break;
    case 13085: /* module 51 call 29 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_open_request_ttl_V6(c, &method->basic.configuration_set_hrmp_open_request_ttl_V6))
        break;
    case 13086: /* module 51 call 30 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_sender_deposit_V6(c, &method->basic.configuration_set_hrmp_sender_deposit_V6))
        break;
    case 13087: /* module 51 call 31 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_recipient_deposit_V6(c, &method->basic.configuration_set_hrmp_recipient_deposit_V6))
        break;
    case 13088: /* module 51 call 32 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_channel_max_capacity_V6(c, &method->basic.configuration_set_hrmp_channel_max_capacity_V6))
        break;
    case 13089: /* module 51 call 33 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_channel_max_total_size_V6(c, &method->basic.configuration_set_hrmp_channel_max_total_size_V6))
        break;
    case 13090: /* module 51 call 34 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_max_parachain_inbound_channels_V6(c, &method->basic.configuration_set_hrmp_max_parachain_inbound_channels_V6))
        break;
    case 13091: /* module 51 call 35 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_max_parathread_inbound_channels_V6(c, &method->basic.configuration_set_hrmp_max_parathread_inbound_channels_V6))
        break;
    case 13092: /* module 51 call 36 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_channel_max_message_size_V6(c, &method->basic.configuration_set_hrmp_channel_max_message_size_V6))
        break;
    case 13093: /* module 51 call 37 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_max_parachain_outbound_channels_V6(c, &method->basic.configuration_set_hrmp_max_parachain_outbound_channels_V6))
        break;
    case 13094: /* module 51 call 38 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_max_parathread_outbound_channels_V6(c, &method->basic.configuration_set_hrmp_max_parathread_outbound_channels_V6))
        break;
    case 13095: /* module 51 call 39 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_max_message_num_per_candidate_V6(c, &method->basic.configuration_set_hrmp_max_message_num_per_candidate_V6))
        break;
    case 13096: /* module 51 call 40 */
        CHECK_ERROR(_readMethod_configuration_set_ump_max_individual_weight_V6(c, &method->basic.configuration_set_ump_max_individual_weight_V6))
        break;
    case 13824: /* module 54 call 0 */
        CHECK_ERROR(_readMethod_parainherent_enter_V6(c, &method->basic.parainherent_enter_V6))
        break;
    case 14336: /* module 56 call 0 */
        CHECK_ERROR(_readMethod_paras_force_set_current_code_V6(c, &method->basic.paras_force_set_current_code_V6))
        break;
    case 14337: /* module 56 call 1 */
        CHECK_ERROR(_readMethod_paras_force_set_current_head_V6(c, &method->basic.paras_force_set_current_head_V6))
        break;
    case 14338: /* module 56 call 2 */
        CHECK_ERROR(_readMethod_paras_force_schedule_code_upgrade_V6(c, &method->basic.paras_force_schedule_code_upgrade_V6))
        break;
    case 14339: /* module 56 call 3 */
        CHECK_ERROR(_readMethod_paras_force_note_new_head_V6(c, &method->basic.paras_force_note_new_head_V6))
        break;
    case 14340: /* module 56 call 4 */
        CHECK_ERROR(_readMethod_paras_force_queue_action_V6(c, &method->basic.paras_force_queue_action_V6))
        break;
    case 14592: /* module 57 call 0 */
        CHECK_ERROR(_readMethod_initializer_force_approve_V6(c, &method->basic.initializer_force_approve_V6))
        break;
    case 15104: /* module 59 call 0 */
        CHECK_ERROR(_readMethod_ump_service_overweight_V6(c, &method->basic.ump_service_overweight_V6))
        break;
    case 15360: /* module 60 call 0 */
        CHECK_ERROR(_readMethod_hrmp_hrmp_init_open_channel_V6(c, &method->basic.hrmp_hrmp_init_open_channel_V6))
        break;
    case 15361: /* module 60 call 1 */
        CHECK_ERROR(_readMethod_hrmp_hrmp_accept_open_channel_V6(c, &method->basic.hrmp_hrmp_accept_open_channel_V6))
        break;
    case 15362: /* module 60 call 2 */
        CHECK_ERROR(_readMethod_hrmp_hrmp_close_channel_V6(c, &method->basic.hrmp_hrmp_close_channel_V6))
        break;
    case 15363: /* module 60 call 3 */
        CHECK_ERROR(_readMethod_hrmp_force_clean_hrmp_V6(c, &method->basic.hrmp_force_clean_hrmp_V6))
        break;
    case 15364: /* module 60 call 4 */
        CHECK_ERROR(_readMethod_hrmp_force_process_hrmp_open_V6(c, &method->basic.hrmp_force_process_hrmp_open_V6))
        break;
    case 15365: /* module 60 call 5 */
        CHECK_ERROR(_readMethod_hrmp_force_process_hrmp_close_V6(c, &method->basic.hrmp_force_process_hrmp_close_V6))
        break;
    case 15366: /* module 60 call 6 */
        CHECK_ERROR(_readMethod_hrmp_hrmp_cancel_open_request_V6(c, &method->basic.hrmp_hrmp_cancel_open_request_V6))
        break;
    case 17920: /* module 70 call 0 */
        CHECK_ERROR(_readMethod_registrar_register_V6(c, &method->basic.registrar_register_V6))
        break;
    case 17921: /* module 70 call 1 */
        CHECK_ERROR(_readMethod_registrar_force_register_V6(c, &method->basic.registrar_force_register_V6))
        break;
    case 17922: /* module 70 call 2 */
        CHECK_ERROR(_readMethod_registrar_deregister_V6(c, &method->basic.registrar_deregister_V6))
        break;
    case 17923: /* module 70 call 3 */
        CHECK_ERROR(_readMethod_registrar_swap_V6(c, &method->basic.registrar_swap_V6))
        break;
    case 17924: /* module 70 call 4 */
        CHECK_ERROR(_readMethod_registrar_force_remove_lock_V6(c, &method->basic.registrar_force_remove_lock_V6))
        break;
    case 17925: /* module 70 call 5 */
        CHECK_ERROR(_readMethod_registrar_reserve_V6(c, &method->basic.registrar_reserve_V6))
        break;
    case 18176: /* module 71 call 0 */
        CHECK_ERROR(_readMethod_slots_force_lease_V6(c, &method->basic.slots_force_lease_V6))
        break;
    case 18177: /* module 71 call 1 */
        CHECK_ERROR(_readMethod_slots_clear_all_leases_V6(c, &method->basic.slots_clear_all_leases_V6))
        break;
    case 18178: /* module 71 call 2 */
        CHECK_ERROR(_readMethod_slots_trigger_onboard_V6(c, &method->basic.slots_trigger_onboard_V6))
        break;
    case 18432: /* module 72 call 0 */
        CHECK_ERROR(_readMethod_auctions_new_auction_V6(c, &method->basic.auctions_new_auction_V6))
        break;
    case 18433: /* module 72 call 1 */
        CHECK_ERROR(_readMethod_auctions_bid_V6(c, &method->basic.auctions_bid_V6))
        break;
    case 18434: /* module 72 call 2 */
        CHECK_ERROR(_readMethod_auctions_cancel_auction_V6(c, &method->basic.auctions_cancel_auction_V6))
        break;
    case 18688: /* module 73 call 0 */
        CHECK_ERROR(_readMethod_crowdloan_create_V6(c, &method->basic.crowdloan_create_V6))
        break;
    case 18689: /* module 73 call 1 */
        CHECK_ERROR(_readMethod_crowdloan_contribute_V6(c, &method->basic.crowdloan_contribute_V6))
        break;
    case 18690: /* module 73 call 2 */
        CHECK_ERROR(_readMethod_crowdloan_withdraw_V6(c, &method->basic.crowdloan_withdraw_V6))
        break;
    case 18691: /* module 73 call 3 */
        CHECK_ERROR(_readMethod_crowdloan_refund_V6(c, &method->basic.crowdloan_refund_V6))
        break;
    case 18692: /* module 73 call 4 */
        CHECK_ERROR(_readMethod_crowdloan_dissolve_V6(c, &method->basic.crowdloan_dissolve_V6))
        break;
    case 18693: /* module 73 call 5 */
        CHECK_ERROR(_readMethod_crowdloan_edit_V6(c, &method->basic.crowdloan_edit_V6))
        break;
    case 18694: /* module 73 call 6 */
        CHECK_ERROR(_readMethod_crowdloan_add_memo_V6(c, &method->basic.crowdloan_add_memo_V6))
        break;
    case 18695: /* module 73 call 7 */
        CHECK_ERROR(_readMethod_crowdloan_poke_V6(c, &method->basic.crowdloan_poke_V6))
        break;
    case 25344: /* module 99 call 0 */
        CHECK_ERROR(_readMethod_xcmpallet_send_V6(c, &method->basic.xcmpallet_send_V6))
        break;
    case 25345: /* module 99 call 1 */
        CHECK_ERROR(_readMethod_xcmpallet_teleport_assets_V6(c, &method->basic.xcmpallet_teleport_assets_V6))
        break;
    case 25346: /* module 99 call 2 */
        CHECK_ERROR(_readMethod_xcmpallet_reserve_transfer_assets_V6(c, &method->basic.xcmpallet_reserve_transfer_assets_V6))
        break;
    case 25347: /* module 99 call 3 */
        CHECK_ERROR(_readMethod_xcmpallet_execute_V6(c, &method->basic.xcmpallet_execute_V6))
        break;
#endif
    default:
        return parser_not_supported;
    }

    return parser_ok;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

const char* _getMethod_ModuleName_V6(uint8_t moduleIdx)
{
    switch (moduleIdx) {
    case 4:
        return STR_MO_BALANCES;
    case 6:
        return STR_MO_STAKING;
    case 8:
        return STR_MO_SESSION;
    case 24:
        return STR_MO_UTILITY;
#ifdef SUBSTRATE_PARSER_FULL
    case 0:
        return STR_MO_SYSTEM;
    case 1:
        return STR_MO_BABE;
    case 2:
        return STR_MO_TIMESTAMP;
    case 3:
        return STR_MO_INDICES;
    case 5:
        return STR_MO_AUTHORSHIP;
    case 10:
        return STR_MO_GRANDPA;
    case 11:
        return STR_MO_IMONLINE;
    case 13:
        return STR_MO_DEMOCRACY;
    case 14:
        return STR_MO_COUNCIL;
    case 15:
        return STR_MO_TECHNICALCOMMITTEE;
    case 16:
        return STR_MO_PHRAGMENELECTION;
    case 17:
        return STR_MO_TECHNICALMEMBERSHIP;
    case 18:
        return STR_MO_TREASURY;
    case 19:
        return STR_MO_CLAIMS;
    case 25:
        return STR_MO_IDENTITY;
    case 26:
        return STR_MO_SOCIETY;
    case 27:
        return STR_MO_RECOVERY;
    case 28:
        return STR_MO_VESTING;
    case 29:
        return STR_MO_SCHEDULER;
    case 30:
        return STR_MO_PROXY;
    case 31:
        return STR_MO_MULTISIG;
    case 35:
        return STR_MO_BOUNTIES;
    case 36:
        return STR_MO_TIPS;
    case 37:
        return STR_MO_ELECTIONPROVIDERMULTIPHASE;
    case 38:
        return STR_MO_GILT;
    case 51:
        return STR_MO_CONFIGURATION;
    case 52:
        return STR_MO_PARASSHARED;
    case 53:
        return STR_MO_PARAINCLUSION;
    case 54:
        return STR_MO_PARAINHERENT;
    case 56:
        return STR_MO_PARAS;
    case 57:
        return STR_MO_INITIALIZER;
    case 58:
        return STR_MO_DMP;
    case 59:
        return STR_MO_UMP;
    case 60:
        return STR_MO_HRMP;
    case 70:
        return STR_MO_REGISTRAR;
    case 71:
        return STR_MO_SLOTS;
    case 72:
        return STR_MO_AUCTIONS;
    case 73:
        return STR_MO_CROWDLOAN;
    case 99:
        return STR_MO_XCMPALLET;
#endif
    default:
        return NULL;
    }

    return NULL;
}

const char* _getMethod_Name_V6(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1024: /* module 4 call 0 */
        return STR_ME_TRANSFER;
    case 1027: /* module 4 call 3 */
        return STR_ME_TRANSFER_KEEP_ALIVE;
    case 1536: /* module 6 call 0 */
        return STR_ME_BOND;
    case 1537: /* module 6 call 1 */
        return STR_ME_BOND_EXTRA;
    case 1538: /* module 6 call 2 */
        return STR_ME_UNBOND;
    case 1539: /* module 6 call 3 */
        return STR_ME_WITHDRAW_UNBONDED;
    case 1540: /* module 6 call 4 */
        return STR_ME_VALIDATE;
    case 1541: /* module 6 call 5 */
        return STR_ME_NOMINATE;
    case 1542: /* module 6 call 6 */
        return STR_ME_CHILL;
    case 1543: /* module 6 call 7 */
        return STR_ME_SET_PAYEE;
    case 1544: /* module 6 call 8 */
        return STR_ME_SET_CONTROLLER;
    case 1554: /* module 6 call 18 */
        return STR_ME_PAYOUT_STAKERS;
    case 1555: /* module 6 call 19 */
        return STR_ME_REBOND;
    case 2048: /* module 8 call 0 */
        return STR_ME_SET_KEYS;
    case 2049: /* module 8 call 1 */
        return STR_ME_PURGE_KEYS;
    case 6144: /* module 24 call 0 */
        return STR_ME_BATCH;
    case 6146: /* module 24 call 2 */
        return STR_ME_BATCH_ALL;
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        return STR_ME_FILL_BLOCK;
    case 1: /* module 0 call 1 */
        return STR_ME_REMARK;
    case 2: /* module 0 call 2 */
        return STR_ME_SET_HEAP_PAGES;
    case 3: /* module 0 call 3 */
        return STR_ME_SET_CODE;
    case 4: /* module 0 call 4 */
        return STR_ME_SET_CODE_WITHOUT_CHECKS;
    case 5: /* module 0 call 5 */
        return STR_ME_SET_CHANGES_TRIE_CONFIG;
    case 6: /* module 0 call 6 */
        return STR_ME_SET_STORAGE;
    case 7: /* module 0 call 7 */
        return STR_ME_KILL_STORAGE;
    case 8: /* module 0 call 8 */
        return STR_ME_KILL_PREFIX;
    case 9: /* module 0 call 9 */
        return STR_ME_REMARK_WITH_EVENT;
    case 256: /* module 1 call 0 */
        return STR_ME_REPORT_EQUIVOCATION;
    case 257: /* module 1 call 1 */
        return STR_ME_REPORT_EQUIVOCATION_UNSIGNED;
    case 258: /* module 1 call 2 */
        return STR_ME_PLAN_CONFIG_CHANGE;
    case 512: /* module 2 call 0 */
        return STR_ME_SET;
    case 768: /* module 3 call 0 */
        return STR_ME_CLAIM;
    case 769: /* module 3 call 1 */
        return STR_ME_TRANSFER;
    case 770: /* module 3 call 2 */
        return STR_ME_FREE;
    case 771: /* module 3 call 3 */
        return STR_ME_FORCE_TRANSFER;
    case 772: /* module 3 call 4 */
        return STR_ME_FREEZE;
    case 1025: /* module 4 call 1 */
        return STR_ME_SET_BALANCE;
    case 1026: /* module 4 call 2 */
        return STR_ME_FORCE_TRANSFER;
    case 1028: /* module 4 call 4 */
        return STR_ME_TRANSFER_ALL;
    case 1280: /* module 5 call 0 */
        return STR_ME_SET_UNCLES;
    case 1545: /* module 6 call 9 */
        return STR_ME_SET_VALIDATOR_COUNT;
    case 1546: /* module 6 call 10 */
        return STR_ME_INCREASE_VALIDATOR_COUNT;
    case 1547: /* module 6 call 11 */
        return STR_ME_SCALE_VALIDATOR_COUNT;
    case 1548: /* module 6 call 12 */
        return STR_ME_FORCE_NO_ERAS;
    case 1549: /* module 6 call 13 */
        return STR_ME_FORCE_NEW_ERA;
    case 1550: /* module 6 call 14 */
        return STR_ME_SET_INVULNERABLES;
    case 1551: /* module 6 call 15 */
        return STR_ME_FORCE_UNSTAKE;
    case 1552: /* module 6 call 16 */
        return STR_ME_FORCE_NEW_ERA_ALWAYS;
    case 1553: /* module 6 call 17 */
        return STR_ME_CANCEL_DEFERRED_SLASH;
    case 1556: /* module 6 call 20 */
        return STR_ME_SET_HISTORY_DEPTH;
    case 1557: /* module 6 call 21 */
        return STR_ME_REAP_STASH;
    case 1558: /* module 6 call 22 */
        return STR_ME_KICK;
    case 1559: /* module 6 call 23 */
        return STR_ME_SET_STAKING_LIMITS;
    case 1560: /* module 6 call 24 */
        return STR_ME_CHILL_OTHER;
    case 2560: /* module 10 call 0 */
        return STR_ME_REPORT_EQUIVOCATION;
    case 2561: /* module 10 call 1 */
        return STR_ME_REPORT_EQUIVOCATION_UNSIGNED;
    case 2562: /* module 10 call 2 */
        return STR_ME_NOTE_STALLED;
    case 2816: /* module 11 call 0 */
        return STR_ME_HEARTBEAT;
    case 3328: /* module 13 call 0 */
        return STR_ME_PROPOSE;
    case 3329: /* module 13 call 1 */
        return STR_ME_SECOND;
    case 3330: /* module 13 call 2 */
        return STR_ME_VOTE;
    case 3331: /* module 13 call 3 */
        return STR_ME_EMERGENCY_CANCEL;
    case 3332: /* module 13 call 4 */
        return STR_ME_EXTERNAL_PROPOSE;
    case 3333: /* module 13 call 5 */
        return STR_ME_EXTERNAL_PROPOSE_MAJORITY;
    case 3334: /* module 13 call 6 */
        return STR_ME_EXTERNAL_PROPOSE_DEFAULT;
    case 3335: /* module 13 call 7 */
        return STR_ME_FAST_TRACK;
    case 3336: /* module 13 call 8 */
        return STR_ME_VETO_EXTERNAL;
    case 3337: /* module 13 call 9 */
        return STR_ME_CANCEL_REFERENDUM;
    case 3338: /* module 13 call 10 */
        return STR_ME_CANCEL_QUEUED;
    case 3339: /* module 13 call 11 */
        return STR_ME_DELEGATE;
    case 3340: /* module 13 call 12 */
        return STR_ME_UNDELEGATE;
    case 3341: /* module 13 call 13 */
        return STR_ME_CLEAR_PUBLIC_PROPOSALS;
    case 3342: /* module 13 call 14 */
        return STR_ME_NOTE_PREIMAGE;
    case 3343: /* module 13 call 15 */
        return STR_ME_NOTE_PREIMAGE_OPERATIONAL;
    case 3344: /* module 13 call 16 */
        return STR_ME_NOTE_IMMINENT_PREIMAGE;
    case 3345: /* module 13 call 17 */
        return STR_ME_NOTE_IMMINENT_PREIMAGE_OPERATIONAL;
    case 3346: /* module 13 call 18 */
        return STR_ME_REAP_PREIMAGE;
    case 3347: /* module 13 call 19 */
        return STR_ME_UNLOCK;
    case 3348: /* module 13 call 20 */
        return STR_ME_REMOVE_VOTE;
    case 3349: /* module 13 call 21 */
        return STR_ME_REMOVE_OTHER_VOTE;
    case 3350: /* module 13 call 22 */
        return STR_ME_ENACT_PROPOSAL;
    case 3351: /* module 13 call 23 */
        return STR_ME_BLACKLIST;
    case 3352: /* module 13 call 24 */
        return STR_ME_CANCEL_PROPOSAL;
    case 3584: /* module 14 call 0 */
        return STR_ME_SET_MEMBERS;
    case 3585: /* module 14 call 1 */
        return STR_ME_EXECUTE;
    case 3586: /* module 14 call 2 */
        return STR_ME_PROPOSE;
    case 3587: /* module 14 call 3 */
        return STR_ME_VOTE;
    case 3588: /* module 14 call 4 */
        return STR_ME_CLOSE;
    case 3589: /* module 14 call 5 */
        return STR_ME_DISAPPROVE_PROPOSAL;
    case 3840: /* module 15 call 0 */
        return STR_ME_SET_MEMBERS;
    case 3841: /* module 15 call 1 */
        return STR_ME_EXECUTE;
    case 3842: /* module 15 call 2 */
        return STR_ME_PROPOSE;
    case 3843: /* module 15 call 3 */
        return STR_ME_VOTE;
    case 3844: /* module 15 call 4 */
        return STR_ME_CLOSE;
    case 3845: /* module 15 call 5 */
        return STR_ME_DISAPPROVE_PROPOSAL;
    case 4096: /* module 16 call 0 */
        return STR_ME_VOTE;
    case 4097: /* module 16 call 1 */
        return STR_ME_REMOVE_VOTER;
    case 4098: /* module 16 call 2 */
        return STR_ME_SUBMIT_CANDIDACY;
    case 4099: /* module 16 call 3 */
        return STR_ME_RENOUNCE_CANDIDACY;
    case 4100: /* module 16 call 4 */
        return STR_ME_REMOVE_MEMBER;
    case 4101: /* module 16 call 5 */
        return STR_ME_CLEAN_DEFUNCT_VOTERS;
    case 4352: /* module 17 call 0 */
        return STR_ME_ADD_MEMBER;
    case 4353: /* module 17 call 1 */
        return STR_ME_REMOVE_MEMBER;
    case 4354: /* module 17 call 2 */
        return STR_ME_SWAP_MEMBER;
    case 4355: /* module 17 call 3 */
        return STR_ME_RESET_MEMBERS;
    case 4356: /* module 17 call 4 */
        return STR_ME_CHANGE_KEY;
    case 4357: /* module 17 call 5 */
        return STR_ME_SET_PRIME;
    case 4358: /* module 17 call 6 */
        return STR_ME_CLEAR_PRIME;
    case 4608: /* module 18 call 0 */
        return STR_ME_PROPOSE_SPEND;
    case 4609: /* module 18 call 1 */
        return STR_ME_REJECT_PROPOSAL;
    case 4610: /* module 18 call 2 */
        return STR_ME_APPROVE_PROPOSAL;
    case 4864: /* module 19 call 0 */
        return STR_ME_CLAIM;
    case 4865: /* module 19 call 1 */
        return STR_ME_MINT_CLAIM;
    case 4866: /* module 19 call 2 */
        return STR_ME_CLAIM_ATTEST;
    case 4867: /* module 19 call 3 */
        return STR_ME_ATTEST;
    case 4868: /* module 19 call 4 */
        return STR_ME_MOVE_CLAIM;
    case 6145: /* module 24 call 1 */
        return STR_ME_AS_DERIVATIVE;
    case 6400: /* module 25 call 0 */
        return STR_ME_ADD_REGISTRAR;
    case 6401: /* module 25 call 1 */
        return STR_ME_SET_IDENTITY;
    case 6402: /* module 25 call 2 */
        return STR_ME_SET_SUBS;
    case 6403: /* module 25 call 3 */
        return STR_ME_CLEAR_IDENTITY;
    case 6404: /* module 25 call 4 */
        return STR_ME_REQUEST_JUDGEMENT;
    case 6405: /* module 25 call 5 */
        return STR_ME_CANCEL_REQUEST;
    case 6406: /* module 25 call 6 */
        return STR_ME_SET_FEE;
    case 6407: /* module 25 call 7 */
        return STR_ME_SET_ACCOUNT_ID;
    case 6408: /* module 25 call 8 */
        return STR_ME_SET_FIELDS;
    case 6409: /* module 25 call 9 */
        return STR_ME_PROVIDE_JUDGEMENT;
    case 6410: /* module 25 call 10 */
        return STR_ME_KILL_IDENTITY;
    case 6411: /* module 25 call 11 */
        return STR_ME_ADD_SUB;
    case 6412: /* module 25 call 12 */
        return STR_ME_RENAME_SUB;
    case 6413: /* module 25 call 13 */
        return STR_ME_REMOVE_SUB;
    case 6414: /* module 25 call 14 */
        return STR_ME_QUIT_SUB;
    case 6656: /* module 26 call 0 */
        return STR_ME_BID;
    case 6657: /* module 26 call 1 */
        return STR_ME_UNBID;
    case 6658: /* module 26 call 2 */
        return STR_ME_VOUCH;
    case 6659: /* module 26 call 3 */
        return STR_ME_UNVOUCH;
    case 6660: /* module 26 call 4 */
        return STR_ME_VOTE;
    case 6661: /* module 26 call 5 */
        return STR_ME_DEFENDER_VOTE;
    case 6662: /* module 26 call 6 */
        return STR_ME_PAYOUT;
    case 6663: /* module 26 call 7 */
        return STR_ME_FOUND;
    case 6664: /* module 26 call 8 */
        return STR_ME_UNFOUND;
    case 6665: /* module 26 call 9 */
        return STR_ME_JUDGE_SUSPENDED_MEMBER;
    case 6666: /* module 26 call 10 */
        return STR_ME_JUDGE_SUSPENDED_CANDIDATE;
    case 6667: /* module 26 call 11 */
        return STR_ME_SET_MAX_MEMBERS;
    case 6912: /* module 27 call 0 */
        return STR_ME_AS_RECOVERED;
    case 6913: /* module 27 call 1 */
        return STR_ME_SET_RECOVERED;
    case 6914: /* module 27 call 2 */
        return STR_ME_CREATE_RECOVERY;
    case 6915: /* module 27 call 3 */
        return STR_ME_INITIATE_RECOVERY;
    case 6916: /* module 27 call 4 */
        return STR_ME_VOUCH_RECOVERY;
    case 6917: /* module 27 call 5 */
        return STR_ME_CLAIM_RECOVERY;
    case 6918: /* module 27 call 6 */
        return STR_ME_CLOSE_RECOVERY;
    case 6919: /* module 27 call 7 */
        return STR_ME_REMOVE_RECOVERY;
    case 6920: /* module 27 call 8 */
        return STR_ME_CANCEL_RECOVERED;
    case 7168: /* module 28 call 0 */
        return STR_ME_VEST;
    case 7169: /* module 28 call 1 */
        return STR_ME_VEST_OTHER;
    case 7170: /* module 28 call 2 */
        return STR_ME_VESTED_TRANSFER;
    case 7171: /* module 28 call 3 */
        return STR_ME_FORCE_VESTED_TRANSFER;
    case 7424: /* module 29 call 0 */
        return STR_ME_SCHEDULE;
    case 7425: /* module 29 call 1 */
        return STR_ME_CANCEL;
    case 7426: /* module 29 call 2 */
        return STR_ME_SCHEDULE_NAMED;
    case 7427: /* module 29 call 3 */
        return STR_ME_CANCEL_NAMED;
    case 7428: /* module 29 call 4 */
        return STR_ME_SCHEDULE_AFTER;
    case 7429: /* module 29 call 5 */
        return STR_ME_SCHEDULE_NAMED_AFTER;
    case 7680: /* module 30 call 0 */
        return STR_ME_PROXY;
    case 7681: /* module 30 call 1 */
        return STR_ME_ADD_PROXY;
    case 7682: /* module 30 call 2 */
        return STR_ME_REMOVE_PROXY;
    case 7683: /* module 30 call 3 */
        return STR_ME_REMOVE_PROXIES;
    case 7684: /* module 30 call 4 */
        return STR_ME_ANONYMOUS;
    case 7685: /* module 30 call 5 */
        return STR_ME_KILL_ANONYMOUS;
    case 7686: /* module 30 call 6 */
        return STR_ME_ANNOUNCE;
    case 7687: /* module 30 call 7 */
        return STR_ME_REMOVE_ANNOUNCEMENT;
    case 7688: /* module 30 call 8 */
        return STR_ME_REJECT_ANNOUNCEMENT;
    case 7689: /* module 30 call 9 */
        return STR_ME_PROXY_ANNOUNCED;
    case 7936: /* module 31 call 0 */
        return STR_ME_AS_MULTI_THRESHOLD_1;
    case 7937: /* module 31 call 1 */
        return STR_ME_AS_MULTI;
    case 7938: /* module 31 call 2 */
        return STR_ME_APPROVE_AS_MULTI;
    case 7939: /* module 31 call 3 */
        return STR_ME_CANCEL_AS_MULTI;
    case 8960: /* module 35 call 0 */
        return STR_ME_PROPOSE_BOUNTY;
    case 8961: /* module 35 call 1 */
        return STR_ME_APPROVE_BOUNTY;
    case 8962: /* module 35 call 2 */
        return STR_ME_PROPOSE_CURATOR;
    case 8963: /* module 35 call 3 */
        return STR_ME_UNASSIGN_CURATOR;
    case 8964: /* module 35 call 4 */
        return STR_ME_ACCEPT_CURATOR;
    case 8965: /* module 35 call 5 */
        return STR_ME_AWARD_BOUNTY;
    case 8966: /* module 35 call 6 */
        return STR_ME_CLAIM_BOUNTY;
    case 8967: /* module 35 call 7 */
        return STR_ME_CLOSE_BOUNTY;
    case 8968: /* module 35 call 8 */
        return STR_ME_EXTEND_BOUNTY_EXPIRY;
    case 9216: /* module 36 call 0 */
        return STR_ME_REPORT_AWESOME;
    case 9217: /* module 36 call 1 */
        return STR_ME_RETRACT_TIP;
    case 9218: /* module 36 call 2 */
        return STR_ME_TIP_NEW;
    case 9219: /* module 36 call 3 */
        return STR_ME_TIP;
    case 9220: /* module 36 call 4 */
        return STR_ME_CLOSE_TIP;
    case 9221: /* module 36 call 5 */
        return STR_ME_SLASH_TIP;
    case 9472: /* module 37 call 0 */
        return STR_ME_SUBMIT_UNSIGNED;
    case 9473: /* module 37 call 1 */
        return STR_ME_SET_MINIMUM_UNTRUSTED_SCORE;
    case 9474: /* module 37 call 2 */
        return STR_ME_SET_EMERGENCY_ELECTION_RESULT;
    case 9475: /* module 37 call 3 */
        return STR_ME_SUBMIT;
    case 9728: /* module 38 call 0 */
        return STR_ME_PLACE_BID;
    case 9729: /* module 38 call 1 */
        return STR_ME_RETRACT_BID;
    case 9730: /* module 38 call 2 */
        return STR_ME_SET_TARGET;
    case 9731: /* module 38 call 3 */
        return STR_ME_THAW;
    case 13056: /* module 51 call 0 */
        return STR_ME_SET_VALIDATION_UPGRADE_FREQUENCY;
    case 13057: /* module 51 call 1 */
        return STR_ME_SET_VALIDATION_UPGRADE_DELAY;
    case 13058: /* module 51 call 2 */
        return STR_ME_SET_CODE_RETENTION_PERIOD;
    case 13059: /* module 51 call 3 */
        return STR_ME_SET_MAX_CODE_SIZE;
    case 13060: /* module 51 call 4 */
        return STR_ME_SET_MAX_POV_SIZE;
    case 13061: /* module 51 call 5 */
        return STR_ME_SET_MAX_HEAD_DATA_SIZE;
    case 13062: /* module 51 call 6 */
        return STR_ME_SET_PARATHREAD_CORES;
    case 13063: /* module 51 call 7 */
        return STR_ME_SET_PARATHREAD_RETRIES;
    case 13064: /* module 51 call 8 */
        return STR_ME_SET_GROUP_ROTATION_FREQUENCY;
    case 13065: /* module 51 call 9 */
        return STR_ME_SET_CHAIN_AVAILABILITY_PERIOD;
    case 13066: /* module 51 call 10 */
        return STR_ME_SET_THREAD_AVAILABILITY_PERIOD;
    case 13067: /* module 51 call 11 */
        return STR_ME_SET_SCHEDULING_LOOKAHEAD;
    case 13068: /* module 51 call 12 */
        return STR_ME_SET_MAX_VALIDATORS_PER_CORE;
    case 13069: /* module 51 call 13 */
        return STR_ME_SET_MAX_VALIDATORS;
    case 13070: /* module 51 call 14 */
        return STR_ME_SET_DISPUTE_PERIOD;
    case 13071: /* module 51 call 15 */
        return STR_ME_SET_DISPUTE_POST_CONCLUSION_ACCEPTANCE_PERIOD;
    case 13072: /* module 51 call 16 */
        return STR_ME_SET_DISPUTE_MAX_SPAM_SLOTS;
    case 13073: /* module 51 call 17 */
        return STR_ME_SET_DISPUTE_CONCLUSION_BY_TIME_OUT_PERIOD;
    case 13074: /* module 51 call 18 */
        return STR_ME_SET_NO_SHOW_SLOTS;
    case 13075: /* module 51 call 19 */
        return STR_ME_SET_N_DELAY_TRANCHES;
    case 13076: /* module 51 call 20 */
        return STR_ME_SET_ZEROTH_DELAY_TRANCHE_WIDTH;
    case 13077: /* module 51 call 21 */
        return STR_ME_SET_NEEDED_APPROVALS;
    case 13078: /* module 51 call 22 */
        return STR_ME_SET_RELAY_VRF_MODULO_SAMPLES;
    case 13079: /* module 51 call 23 */
        return STR_ME_SET_MAX_UPWARD_QUEUE_COUNT;
    case 13080: /* module 51 call 24 */
        return STR_ME_SET_MAX_UPWARD_QUEUE_SIZE;
    case 13081: /* module 51 call 25 */
        return STR_ME_SET_MAX_DOWNWARD_MESSAGE_SIZE;
    case 13082: /* module 51 call 26 */
        return STR_ME_SET_UMP_SERVICE_TOTAL_WEIGHT;
    case 13083: /* module 51 call 27 */
        return STR_ME_SET_MAX_UPWARD_MESSAGE_SIZE;
    case 13084: /* module 51 call 28 */
        return STR_ME_SET_MAX_UPWARD_MESSAGE_NUM_PER_CANDIDATE;
    case 13085: /* module 51 call 29 */
        return STR_ME_SET_HRMP_OPEN_REQUEST_TTL;
    case 13086: /* module 51 call 30 */
        return STR_ME_SET_HRMP_SENDER_DEPOSIT;
    case 13087: /* module 51 call 31 */
        return STR_ME_SET_HRMP_RECIPIENT_DEPOSIT;
    case 13088: /* module 51 call 32 */
        return STR_ME_SET_HRMP_CHANNEL_MAX_CAPACITY;
    case 13089: /* module 51 call 33 */
        return STR_ME_SET_HRMP_CHANNEL_MAX_TOTAL_SIZE;
    case 13090: /* module 51 call 34 */
        return STR_ME_SET_HRMP_MAX_PARACHAIN_INBOUND_CHANNELS;
    case 13091: /* module 51 call 35 */
        return STR_ME_SET_HRMP_MAX_PARATHREAD_INBOUND_CHANNELS;
    case 13092: /* module 51 call 36 */
        return STR_ME_SET_HRMP_CHANNEL_MAX_MESSAGE_SIZE;
    case 13093: /* module 51 call 37 */
        return STR_ME_SET_HRMP_MAX_PARACHAIN_OUTBOUND_CHANNELS;
    case 13094: /* module 51 call 38 */
        return STR_ME_SET_HRMP_MAX_PARATHREAD_OUTBOUND_CHANNELS;
    case 13095: /* module 51 call 39 */
        return STR_ME_SET_HRMP_MAX_MESSAGE_NUM_PER_CANDIDATE;
    case 13096: /* module 51 call 40 */
        return STR_ME_SET_UMP_MAX_INDIVIDUAL_WEIGHT;
    case 13824: /* module 54 call 0 */
        return STR_ME_ENTER;
    case 14336: /* module 56 call 0 */
        return STR_ME_FORCE_SET_CURRENT_CODE;
    case 14337: /* module 56 call 1 */
        return STR_ME_FORCE_SET_CURRENT_HEAD;
    case 14338: /* module 56 call 2 */
        return STR_ME_FORCE_SCHEDULE_CODE_UPGRADE;
    case 14339: /* module 56 call 3 */
        return STR_ME_FORCE_NOTE_NEW_HEAD;
    case 14340: /* module 56 call 4 */
        return STR_ME_FORCE_QUEUE_ACTION;
    case 14592: /* module 57 call 0 */
        return STR_ME_FORCE_APPROVE;
    case 15104: /* module 59 call 0 */
        return STR_ME_SERVICE_OVERWEIGHT;
    case 15360: /* module 60 call 0 */
        return STR_ME_HRMP_INIT_OPEN_CHANNEL;
    case 15361: /* module 60 call 1 */
        return STR_ME_HRMP_ACCEPT_OPEN_CHANNEL;
    case 15362: /* module 60 call 2 */
        return STR_ME_HRMP_CLOSE_CHANNEL;
    case 15363: /* module 60 call 3 */
        return STR_ME_FORCE_CLEAN_HRMP;
    case 15364: /* module 60 call 4 */
        return STR_ME_FORCE_PROCESS_HRMP_OPEN;
    case 15365: /* module 60 call 5 */
        return STR_ME_FORCE_PROCESS_HRMP_CLOSE;
    case 15366: /* module 60 call 6 */
        return STR_ME_HRMP_CANCEL_OPEN_REQUEST;
    case 17920: /* module 70 call 0 */
        return STR_ME_REGISTER;
    case 17921: /* module 70 call 1 */
        return STR_ME_FORCE_REGISTER;
    case 17922: /* module 70 call 2 */
        return STR_ME_DEREGISTER;
    case 17923: /* module 70 call 3 */
        return STR_ME_SWAP;
    case 17924: /* module 70 call 4 */
        return STR_ME_FORCE_REMOVE_LOCK;
    case 17925: /* module 70 call 5 */
        return STR_ME_RESERVE;
    case 18176: /* module 71 call 0 */
        return STR_ME_FORCE_LEASE;
    case 18177: /* module 71 call 1 */
        return STR_ME_CLEAR_ALL_LEASES;
    case 18178: /* module 71 call 2 */
        return STR_ME_TRIGGER_ONBOARD;
    case 18432: /* module 72 call 0 */
        return STR_ME_NEW_AUCTION;
    case 18433: /* module 72 call 1 */
        return STR_ME_BID;
    case 18434: /* module 72 call 2 */
        return STR_ME_CANCEL_AUCTION;
    case 18688: /* module 73 call 0 */
        return STR_ME_CREATE;
    case 18689: /* module 73 call 1 */
        return STR_ME_CONTRIBUTE;
    case 18690: /* module 73 call 2 */
        return STR_ME_WITHDRAW;
    case 18691: /* module 73 call 3 */
        return STR_ME_REFUND;
    case 18692: /* module 73 call 4 */
        return STR_ME_DISSOLVE;
    case 18693: /* module 73 call 5 */
        return STR_ME_EDIT;
    case 18694: /* module 73 call 6 */
        return STR_ME_ADD_MEMO;
    case 18695: /* module 73 call 7 */
        return STR_ME_POKE;
    case 25344: /* module 99 call 0 */
        return STR_ME_SEND;
    case 25345: /* module 99 call 1 */
        return STR_ME_TELEPORT_ASSETS;
    case 25346: /* module 99 call 2 */
        return STR_ME_RESERVE_TRANSFER_ASSETS;
    case 25347: /* module 99 call 3 */
        return STR_ME_EXECUTE;
#endif
    default:
        return NULL;
    }

    return NULL;
}

uint8_t _getMethod_NumItems_V6(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1024: /* module 4 call 0 */
        return 2;
    case 1027: /* module 4 call 3 */
        return 2;
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
    case 1554: /* module 6 call 18 */
        return 2;
    case 1555: /* module 6 call 19 */
        return 1;
    case 2048: /* module 8 call 0 */
        return 2;
    case 2049: /* module 8 call 1 */
        return 0;
    case 6144: /* module 24 call 0 */
        return 1;
    case 6146: /* module 24 call 2 */
        return 1;
#ifdef SUBSTRATE_PARSER_FULL
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
        return 1;
    case 256: /* module 1 call 0 */
        return 2;
    case 257: /* module 1 call 1 */
        return 2;
    case 258: /* module 1 call 2 */
        return 1;
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
    case 1025: /* module 4 call 1 */
        return 3;
    case 1026: /* module 4 call 2 */
        return 3;
    case 1028: /* module 4 call 4 */
        return 2;
    case 1280: /* module 5 call 0 */
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
    case 1556: /* module 6 call 20 */
        return 2;
    case 1557: /* module 6 call 21 */
        return 2;
    case 1558: /* module 6 call 22 */
        return 1;
    case 1559: /* module 6 call 23 */
        return 5;
    case 1560: /* module 6 call 24 */
        return 1;
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
        return 2;
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
    case 6145: /* module 24 call 1 */
        return 2;
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
    case 8960: /* module 35 call 0 */
        return 2;
    case 8961: /* module 35 call 1 */
        return 1;
    case 8962: /* module 35 call 2 */
        return 3;
    case 8963: /* module 35 call 3 */
        return 1;
    case 8964: /* module 35 call 4 */
        return 1;
    case 8965: /* module 35 call 5 */
        return 2;
    case 8966: /* module 35 call 6 */
        return 1;
    case 8967: /* module 35 call 7 */
        return 1;
    case 8968: /* module 35 call 8 */
        return 2;
    case 9216: /* module 36 call 0 */
        return 2;
    case 9217: /* module 36 call 1 */
        return 1;
    case 9218: /* module 36 call 2 */
        return 3;
    case 9219: /* module 36 call 3 */
        return 2;
    case 9220: /* module 36 call 4 */
        return 1;
    case 9221: /* module 36 call 5 */
        return 1;
    case 9472: /* module 37 call 0 */
        return 2;
    case 9473: /* module 37 call 1 */
        return 1;
    case 9474: /* module 37 call 2 */
        return 1;
    case 9475: /* module 37 call 3 */
        return 2;
    case 9728: /* module 38 call 0 */
        return 2;
    case 9729: /* module 38 call 1 */
        return 2;
    case 9730: /* module 38 call 2 */
        return 1;
    case 9731: /* module 38 call 3 */
        return 1;
    case 13056: /* module 51 call 0 */
        return 1;
    case 13057: /* module 51 call 1 */
        return 1;
    case 13058: /* module 51 call 2 */
        return 1;
    case 13059: /* module 51 call 3 */
        return 1;
    case 13060: /* module 51 call 4 */
        return 1;
    case 13061: /* module 51 call 5 */
        return 1;
    case 13062: /* module 51 call 6 */
        return 1;
    case 13063: /* module 51 call 7 */
        return 1;
    case 13064: /* module 51 call 8 */
        return 1;
    case 13065: /* module 51 call 9 */
        return 1;
    case 13066: /* module 51 call 10 */
        return 1;
    case 13067: /* module 51 call 11 */
        return 1;
    case 13068: /* module 51 call 12 */
        return 1;
    case 13069: /* module 51 call 13 */
        return 1;
    case 13070: /* module 51 call 14 */
        return 1;
    case 13071: /* module 51 call 15 */
        return 1;
    case 13072: /* module 51 call 16 */
        return 1;
    case 13073: /* module 51 call 17 */
        return 1;
    case 13074: /* module 51 call 18 */
        return 1;
    case 13075: /* module 51 call 19 */
        return 1;
    case 13076: /* module 51 call 20 */
        return 1;
    case 13077: /* module 51 call 21 */
        return 1;
    case 13078: /* module 51 call 22 */
        return 1;
    case 13079: /* module 51 call 23 */
        return 1;
    case 13080: /* module 51 call 24 */
        return 1;
    case 13081: /* module 51 call 25 */
        return 1;
    case 13082: /* module 51 call 26 */
        return 1;
    case 13083: /* module 51 call 27 */
        return 1;
    case 13084: /* module 51 call 28 */
        return 1;
    case 13085: /* module 51 call 29 */
        return 1;
    case 13086: /* module 51 call 30 */
        return 1;
    case 13087: /* module 51 call 31 */
        return 1;
    case 13088: /* module 51 call 32 */
        return 1;
    case 13089: /* module 51 call 33 */
        return 1;
    case 13090: /* module 51 call 34 */
        return 1;
    case 13091: /* module 51 call 35 */
        return 1;
    case 13092: /* module 51 call 36 */
        return 1;
    case 13093: /* module 51 call 37 */
        return 1;
    case 13094: /* module 51 call 38 */
        return 1;
    case 13095: /* module 51 call 39 */
        return 1;
    case 13096: /* module 51 call 40 */
        return 1;
    case 13824: /* module 54 call 0 */
        return 1;
    case 14336: /* module 56 call 0 */
        return 2;
    case 14337: /* module 56 call 1 */
        return 2;
    case 14338: /* module 56 call 2 */
        return 3;
    case 14339: /* module 56 call 3 */
        return 2;
    case 14340: /* module 56 call 4 */
        return 1;
    case 14592: /* module 57 call 0 */
        return 1;
    case 15104: /* module 59 call 0 */
        return 2;
    case 15360: /* module 60 call 0 */
        return 3;
    case 15361: /* module 60 call 1 */
        return 1;
    case 15362: /* module 60 call 2 */
        return 1;
    case 15363: /* module 60 call 3 */
        return 1;
    case 15364: /* module 60 call 4 */
        return 0;
    case 15365: /* module 60 call 5 */
        return 0;
    case 15366: /* module 60 call 6 */
        return 1;
    case 17920: /* module 70 call 0 */
        return 3;
    case 17921: /* module 70 call 1 */
        return 5;
    case 17922: /* module 70 call 2 */
        return 1;
    case 17923: /* module 70 call 3 */
        return 2;
    case 17924: /* module 70 call 4 */
        return 1;
    case 17925: /* module 70 call 5 */
        return 0;
    case 18176: /* module 71 call 0 */
        return 5;
    case 18177: /* module 71 call 1 */
        return 1;
    case 18178: /* module 71 call 2 */
        return 1;
    case 18432: /* module 72 call 0 */
        return 2;
    case 18433: /* module 72 call 1 */
        return 5;
    case 18434: /* module 72 call 2 */
        return 0;
    case 18688: /* module 73 call 0 */
        return 6;
    case 18689: /* module 73 call 1 */
        return 3;
    case 18690: /* module 73 call 2 */
        return 2;
    case 18691: /* module 73 call 3 */
        return 1;
    case 18692: /* module 73 call 4 */
        return 1;
    case 18693: /* module 73 call 5 */
        return 6;
    case 18694: /* module 73 call 6 */
        return 2;
    case 18695: /* module 73 call 7 */
        return 1;
    case 25344: /* module 99 call 0 */
        return 2;
    case 25345: /* module 99 call 1 */
        return 5;
    case 25346: /* module 99 call 2 */
        return 5;
    case 25347: /* module 99 call 3 */
        return 2;
#endif
    default:
        return 0;
    }

    return 0;
}

const char* _getMethod_ItemName_V6(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1024: /* module 4 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 1027: /* module 4 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 1536: /* module 6 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        case 1:
            return STR_IT_value;
        case 2:
            return STR_IT_payee;
        default:
            return NULL;
        }
    case 1537: /* module 6 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_max_additional;
        default:
            return NULL;
        }
    case 1538: /* module 6 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 1539: /* module 6 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 1540: /* module 6 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_prefs;
        default:
            return NULL;
        }
    case 1541: /* module 6 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_targets;
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
            return STR_IT_payee;
        default:
            return NULL;
        }
    case 1544: /* module 6 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        default:
            return NULL;
        }
    case 1554: /* module 6 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_validator_stash;
        case 1:
            return STR_IT_era;
        default:
            return NULL;
        }
    case 1555: /* module 6 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 2048: /* module 8 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_keys;
        case 1:
            return STR_IT_proof;
        default:
            return NULL;
        }
    case 2049: /* module 8 call 1 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6144: /* module 24 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
    case 6146: /* module 24 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT__ratio;
        default:
            return NULL;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT__remark;
        default:
            return NULL;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pages;
        default:
            return NULL;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        default:
            return NULL;
        }
    case 4: /* module 0 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        default:
            return NULL;
        }
    case 5: /* module 0 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_changes_trie_config;
        default:
            return NULL;
        }
    case 6: /* module 0 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_items;
        default:
            return NULL;
        }
    case 7: /* module 0 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_keys;
        default:
            return NULL;
        }
    case 8: /* module 0 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_prefix;
        case 1:
            return STR_IT__subkeys;
        default:
            return NULL;
        }
    case 9: /* module 0 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remark;
        default:
            return NULL;
        }
    case 256: /* module 1 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_equivocation_proof;
        case 1:
            return STR_IT_key_owner_proof;
        default:
            return NULL;
        }
    case 257: /* module 1 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_equivocation_proof;
        case 1:
            return STR_IT_key_owner_proof;
        default:
            return NULL;
        }
    case 258: /* module 1 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_config;
        default:
            return NULL;
        }
    case 512: /* module 2 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_now;
        default:
            return NULL;
        }
    case 768: /* module 3 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 769: /* module 3 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 770: /* module 3 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 771: /* module 3 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_freeze;
        default:
            return NULL;
        }
    case 772: /* module 3 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 1025: /* module 4 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_new_free;
        case 2:
            return STR_IT_new_reserved;
        default:
            return NULL;
        }
    case 1026: /* module 4 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_source;
        case 1:
            return STR_IT_dest;
        case 2:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 1028: /* module 4 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_keep_alive;
        default:
            return NULL;
        }
    case 1280: /* module 5 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_uncles;
        default:
            return NULL;
        }
    case 1545: /* module 6 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 1546: /* module 6 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_additional;
        default:
            return NULL;
        }
    case 1547: /* module 6 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_factor;
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
            return STR_IT_invulnerables;
        default:
            return NULL;
        }
    case 1551: /* module 6 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_stash;
        case 1:
            return STR_IT_num_slashing_spans;
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
            return STR_IT_era;
        case 1:
            return STR_IT_slash_indices;
        default:
            return NULL;
        }
    case 1556: /* module 6 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_history_depth;
        case 1:
            return STR_IT__era_items_deleted;
        default:
            return NULL;
        }
    case 1557: /* module 6 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_stash;
        case 1:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 1558: /* module 6 call 22 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 1559: /* module 6 call 23 */
        switch (itemIdx) {
        case 0:
            return STR_IT_min_nominator_bond;
        case 1:
            return STR_IT_min_validator_bond;
        case 2:
            return STR_IT_max_nominator_count;
        case 3:
            return STR_IT_max_validator_count;
        case 4:
            return STR_IT_threshold;
        default:
            return NULL;
        }
    case 1560: /* module 6 call 24 */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        default:
            return NULL;
        }
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_equivocation_proof;
        case 1:
            return STR_IT_key_owner_proof;
        default:
            return NULL;
        }
    case 2561: /* module 10 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_equivocation_proof;
        case 1:
            return STR_IT_key_owner_proof;
        default:
            return NULL;
        }
    case 2562: /* module 10 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delay;
        case 1:
            return STR_IT_best_finalized_block_number;
        default:
            return NULL;
        }
    case 2816: /* module 11 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_heartbeat;
        case 1:
            return STR_IT__signature;
        default:
            return NULL;
        }
    case 3328: /* module 13 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 3329: /* module 13 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_seconds_upper_bound;
        default:
            return NULL;
        }
    case 3330: /* module 13 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ref_index;
        case 1:
            return STR_IT_vote;
        default:
            return NULL;
        }
    case 3331: /* module 13 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ref_index;
        default:
            return NULL;
        }
    case 3332: /* module 13 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 3333: /* module 13 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 3334: /* module 13 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 3335: /* module 13 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_voting_period;
        case 2:
            return STR_IT_delay;
        default:
            return NULL;
        }
    case 3336: /* module 13 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 3337: /* module 13 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ref_index;
        default:
            return NULL;
        }
    case 3338: /* module 13 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_which;
        default:
            return NULL;
        }
    case 3339: /* module 13 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_to;
        case 1:
            return STR_IT_conviction;
        case 2:
            return STR_IT_balance;
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
            return STR_IT_encoded_proposal;
        default:
            return NULL;
        }
    case 3343: /* module 13 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_encoded_proposal;
        default:
            return NULL;
        }
    case 3344: /* module 13 call 16 */
        switch (itemIdx) {
        case 0:
            return STR_IT_encoded_proposal;
        default:
            return NULL;
        }
    case 3345: /* module 13 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_encoded_proposal;
        default:
            return NULL;
        }
    case 3346: /* module 13 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_proposal_len_upper_bound;
        default:
            return NULL;
        }
    case 3347: /* module 13 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 3348: /* module 13 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 3349: /* module 13 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 3350: /* module 13 call 22 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 3351: /* module 13 call 23 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_maybe_ref_index;
        default:
            return NULL;
        }
    case 3352: /* module 13 call 24 */
        switch (itemIdx) {
        case 0:
            return STR_IT_prop_index;
        default:
            return NULL;
        }
    case 3584: /* module 14 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_members;
        case 1:
            return STR_IT_prime;
        case 2:
            return STR_IT_old_count;
        default:
            return NULL;
        }
    case 3585: /* module 14 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 3586: /* module 14 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_proposal;
        case 2:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 3587: /* module 14 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_approve;
        default:
            return NULL;
        }
    case 3588: /* module 14 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_proposal_weight_bound;
        case 3:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 3589: /* module 14 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 3840: /* module 15 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_members;
        case 1:
            return STR_IT_prime;
        case 2:
            return STR_IT_old_count;
        default:
            return NULL;
        }
    case 3841: /* module 15 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 3842: /* module 15 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_proposal;
        case 2:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 3843: /* module 15 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_approve;
        default:
            return NULL;
        }
    case 3844: /* module 15 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_proposal_weight_bound;
        case 3:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 3845: /* module 15 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 4096: /* module 16 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_votes;
        case 1:
            return STR_IT_value;
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
            return STR_IT_candidate_count;
        default:
            return NULL;
        }
    case 4099: /* module 16 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_renouncing;
        default:
            return NULL;
        }
    case 4100: /* module 16 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_has_replacement;
        default:
            return NULL;
        }
    case 4101: /* module 16 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT__num_voters;
        case 1:
            return STR_IT__num_defunct;
        default:
            return NULL;
        }
    case 4352: /* module 17 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 4353: /* module 17 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 4354: /* module 17 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remove;
        case 1:
            return STR_IT_add;
        default:
            return NULL;
        }
    case 4355: /* module 17 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_members;
        default:
            return NULL;
        }
    case 4356: /* module 17 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 4357: /* module 17 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
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
            return STR_IT_value;
        case 1:
            return STR_IT_beneficiary;
        default:
            return NULL;
        }
    case 4609: /* module 18 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_id;
        default:
            return NULL;
        }
    case 4610: /* module 18 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_id;
        default:
            return NULL;
        }
    case 4864: /* module 19 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_ethereum_signature;
        default:
            return NULL;
        }
    case 4865: /* module 19 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_value;
        case 2:
            return STR_IT_vesting_schedule;
        case 3:
            return STR_IT_statement;
        default:
            return NULL;
        }
    case 4866: /* module 19 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_ethereum_signature;
        case 2:
            return STR_IT_statement;
        default:
            return NULL;
        }
    case 4867: /* module 19 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_statement;
        default:
            return NULL;
        }
    case 4868: /* module 19 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_old;
        case 1:
            return STR_IT_new_;
        case 2:
            return STR_IT_maybe_preclaim;
        default:
            return NULL;
        }
    case 6145: /* module 24 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 6400: /* module 25 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_account;
        default:
            return NULL;
        }
    case 6401: /* module 25 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_info;
        default:
            return NULL;
        }
    case 6402: /* module 25 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_subs;
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
            return STR_IT_reg_index;
        case 1:
            return STR_IT_max_fee;
        default:
            return NULL;
        }
    case 6405: /* module 25 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reg_index;
        default:
            return NULL;
        }
    case 6406: /* module 25 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_fee;
        default:
            return NULL;
        }
    case 6407: /* module 25 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 6408: /* module 25 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_fields;
        default:
            return NULL;
        }
    case 6409: /* module 25 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reg_index;
        case 1:
            return STR_IT_target;
        case 2:
            return STR_IT_judgement;
        default:
            return NULL;
        }
    case 6410: /* module 25 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 6411: /* module 25 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_sub;
        case 1:
            return STR_IT_data;
        default:
            return NULL;
        }
    case 6412: /* module 25 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_sub;
        case 1:
            return STR_IT_data;
        default:
            return NULL;
        }
    case 6413: /* module 25 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_sub;
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
            return STR_IT_value;
        default:
            return NULL;
        }
    case 6657: /* module 26 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pos;
        default:
            return NULL;
        }
    case 6658: /* module 26 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_value;
        case 2:
            return STR_IT_tip;
        default:
            return NULL;
        }
    case 6659: /* module 26 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pos;
        default:
            return NULL;
        }
    case 6660: /* module 26 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_candidate;
        case 1:
            return STR_IT_approve;
        default:
            return NULL;
        }
    case 6661: /* module 26 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_approve;
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
            return STR_IT_founder;
        case 1:
            return STR_IT_max_members;
        case 2:
            return STR_IT_rules;
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
            return STR_IT_who;
        case 1:
            return STR_IT_forgive;
        default:
            return NULL;
        }
    case 6666: /* module 26 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_judgement;
        default:
            return NULL;
        }
    case 6667: /* module 26 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_max;
        default:
            return NULL;
        }
    case 6912: /* module 27 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_account;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 6913: /* module 27 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_lost;
        case 1:
            return STR_IT_rescuer;
        default:
            return NULL;
        }
    case 6914: /* module 27 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_friends;
        case 1:
            return STR_IT_threshold;
        case 2:
            return STR_IT_delay_period;
        default:
            return NULL;
        }
    case 6915: /* module 27 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_account;
        default:
            return NULL;
        }
    case 6916: /* module 27 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_lost;
        case 1:
            return STR_IT_rescuer;
        default:
            return NULL;
        }
    case 6917: /* module 27 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_account;
        default:
            return NULL;
        }
    case 6918: /* module 27 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_rescuer;
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
            return STR_IT_account;
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
            return STR_IT_target;
        default:
            return NULL;
        }
    case 7170: /* module 28 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        case 1:
            return STR_IT_schedule;
        default:
            return NULL;
        }
    case 7171: /* module 28 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_source;
        case 1:
            return STR_IT_target;
        case 2:
            return STR_IT_schedule;
        default:
            return NULL;
        }
    case 7424: /* module 29 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_when;
        case 1:
            return STR_IT_maybe_periodic;
        case 2:
            return STR_IT_priority;
        case 3:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 7425: /* module 29 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_when;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 7426: /* module 29 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_when;
        case 2:
            return STR_IT_maybe_periodic;
        case 3:
            return STR_IT_priority;
        case 4:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 7427: /* module 29 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 7428: /* module 29 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_after;
        case 1:
            return STR_IT_maybe_periodic;
        case 2:
            return STR_IT_priority;
        case 3:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 7429: /* module 29 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_after;
        case 2:
            return STR_IT_maybe_periodic;
        case 3:
            return STR_IT_priority;
        case 4:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 7680: /* module 30 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_real;
        case 1:
            return STR_IT_force_proxy_type;
        case 2:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 7681: /* module 30 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_proxy_type;
        case 2:
            return STR_IT_delay;
        default:
            return NULL;
        }
    case 7682: /* module 30 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_proxy_type;
        case 2:
            return STR_IT_delay;
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
            return STR_IT_proxy_type;
        case 1:
            return STR_IT_delay;
        case 2:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 7685: /* module 30 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_spawner;
        case 1:
            return STR_IT_proxy_type;
        case 2:
            return STR_IT_index;
        case 3:
            return STR_IT_height;
        case 4:
            return STR_IT_ext_index;
        default:
            return NULL;
        }
    case 7686: /* module 30 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_real;
        case 1:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 7687: /* module 30 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_real;
        case 1:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 7688: /* module 30 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 7689: /* module 30 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_real;
        case 2:
            return STR_IT_force_proxy_type;
        case 3:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 7936: /* module 31 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_other_signatories;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 7937: /* module 31 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_maybe_timepoint;
        case 3:
            return STR_IT_call;
        case 4:
            return STR_IT_store_call;
        case 5:
            return STR_IT_max_weight;
        default:
            return NULL;
        }
    case 7938: /* module 31 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_maybe_timepoint;
        case 3:
            return STR_IT_call_hash;
        case 4:
            return STR_IT_max_weight;
        default:
            return NULL;
        }
    case 7939: /* module 31 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_timepoint;
        case 3:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 8960: /* module 35 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_value;
        case 1:
            return STR_IT_description;
        default:
            return NULL;
        }
    case 8961: /* module 35 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 8962: /* module 35 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        case 1:
            return STR_IT_curator;
        case 2:
            return STR_IT_fee;
        default:
            return NULL;
        }
    case 8963: /* module 35 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 8964: /* module 35 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 8965: /* module 35 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        case 1:
            return STR_IT_beneficiary;
        default:
            return NULL;
        }
    case 8966: /* module 35 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 8967: /* module 35 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 8968: /* module 35 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        case 1:
            return STR_IT__remark;
        default:
            return NULL;
        }
    case 9216: /* module 36 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reason;
        case 1:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 9217: /* module 36 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
    case 9218: /* module 36 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reason;
        case 1:
            return STR_IT_who;
        case 2:
            return STR_IT_tip_value;
        default:
            return NULL;
        }
    case 9219: /* module 36 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        case 1:
            return STR_IT_tip_value;
        default:
            return NULL;
        }
    case 9220: /* module 36 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
    case 9221: /* module 36 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
    case 9472: /* module 37 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_raw_solution;
        case 1:
            return STR_IT_witness;
        default:
            return NULL;
        }
    case 9473: /* module 37 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_maybe_next_score;
        default:
            return NULL;
        }
    case 9474: /* module 37 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_supports;
        default:
            return NULL;
        }
    case 9475: /* module 37 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_raw_solution;
        case 1:
            return STR_IT_num_signed_submissions;
        default:
            return NULL;
        }
    case 9728: /* module 38 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_duration;
        default:
            return NULL;
        }
    case 9729: /* module 38 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_duration;
        default:
            return NULL;
        }
    case 9730: /* module 38 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 9731: /* module 38 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 13056: /* module 51 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13057: /* module 51 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13058: /* module 51 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13059: /* module 51 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13060: /* module 51 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13061: /* module 51 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13062: /* module 51 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13063: /* module 51 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13064: /* module 51 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13065: /* module 51 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13066: /* module 51 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13067: /* module 51 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13068: /* module 51 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13069: /* module 51 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13070: /* module 51 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13071: /* module 51 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13072: /* module 51 call 16 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13073: /* module 51 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13074: /* module 51 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13075: /* module 51 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13076: /* module 51 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13077: /* module 51 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13078: /* module 51 call 22 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13079: /* module 51 call 23 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13080: /* module 51 call 24 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13081: /* module 51 call 25 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13082: /* module 51 call 26 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13083: /* module 51 call 27 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13084: /* module 51 call 28 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13085: /* module 51 call 29 */
        switch (itemIdx) {
        case 0:
            return STR_IT__new;
        default:
            return NULL;
        }
    case 13086: /* module 51 call 30 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13087: /* module 51 call 31 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13088: /* module 51 call 32 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13089: /* module 51 call 33 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13090: /* module 51 call 34 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13091: /* module 51 call 35 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13092: /* module 51 call 36 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13093: /* module 51 call 37 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13094: /* module 51 call 38 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13095: /* module 51 call 39 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13096: /* module 51 call 40 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13824: /* module 54 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_data;
        default:
            return NULL;
        }
    case 14336: /* module 56 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_para;
        case 1:
            return STR_IT_new_code;
        default:
            return NULL;
        }
    case 14337: /* module 56 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_para;
        case 1:
            return STR_IT_new_head;
        default:
            return NULL;
        }
    case 14338: /* module 56 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_para;
        case 1:
            return STR_IT_new_code;
        case 2:
            return STR_IT_relay_parent_number;
        default:
            return NULL;
        }
    case 14339: /* module 56 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_para;
        case 1:
            return STR_IT_new_head;
        default:
            return NULL;
        }
    case 14340: /* module 56 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_para;
        default:
            return NULL;
        }
    case 14592: /* module 57 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_up_to;
        default:
            return NULL;
        }
    case 15104: /* module 59 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_weight_limit;
        default:
            return NULL;
        }
    case 15360: /* module 60 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_recipient;
        case 1:
            return STR_IT_proposed_max_capacity;
        case 2:
            return STR_IT_proposed_max_message_size;
        default:
            return NULL;
        }
    case 15361: /* module 60 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_sender;
        default:
            return NULL;
        }
    case 15362: /* module 60 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_channel_id;
        default:
            return NULL;
        }
    case 15363: /* module 60 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_para;
        default:
            return NULL;
        }
    case 15364: /* module 60 call 4 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 15365: /* module 60 call 5 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 15366: /* module 60 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_channel_id;
        default:
            return NULL;
        }
    case 17920: /* module 70 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_genesis_head;
        case 2:
            return STR_IT_validation_code;
        default:
            return NULL;
        }
    case 17921: /* module 70 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_deposit;
        case 2:
            return STR_IT_id;
        case 3:
            return STR_IT_genesis_head;
        case 4:
            return STR_IT_validation_code;
        default:
            return NULL;
        }
    case 17922: /* module 70 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 17923: /* module 70 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_other;
        default:
            return NULL;
        }
    case 17924: /* module 70 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_para;
        default:
            return NULL;
        }
    case 17925: /* module 70 call 5 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 18176: /* module 71 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_para;
        case 1:
            return STR_IT_leaser;
        case 2:
            return STR_IT_amount;
        case 3:
            return STR_IT_period_begin;
        case 4:
            return STR_IT_period_count;
        default:
            return NULL;
        }
    case 18177: /* module 71 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_para;
        default:
            return NULL;
        }
    case 18178: /* module 71 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_para;
        default:
            return NULL;
        }
    case 18432: /* module 72 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_duration;
        case 1:
            return STR_IT_lease_period_index;
        default:
            return NULL;
        }
    case 18433: /* module 72 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_para;
        case 1:
            return STR_IT_auction_index;
        case 2:
            return STR_IT_first_slot;
        case 3:
            return STR_IT_last_slot;
        case 4:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 18434: /* module 72 call 2 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 18688: /* module 73 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_cap;
        case 2:
            return STR_IT_first_period;
        case 3:
            return STR_IT_last_period;
        case 4:
            return STR_IT_end;
        case 5:
            return STR_IT_verifier;
        default:
            return NULL;
        }
    case 18689: /* module 73 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_value;
        case 2:
            return STR_IT_signature;
        default:
            return NULL;
        }
    case 18690: /* module 73 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 18691: /* module 73 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 18692: /* module 73 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 18693: /* module 73 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_cap;
        case 2:
            return STR_IT_first_period;
        case 3:
            return STR_IT_last_period;
        case 4:
            return STR_IT_end;
        case 5:
            return STR_IT_verifier;
        default:
            return NULL;
        }
    case 18694: /* module 73 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_memo;
        default:
            return NULL;
        }
    case 18695: /* module 73 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 25344: /* module 99 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_message;
        default:
            return NULL;
        }
    case 25345: /* module 99 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_beneficiary;
        case 2:
            return STR_IT_assets;
        case 3:
            return STR_IT_fee_asset_item;
        case 4:
            return STR_IT_dest_weight;
        default:
            return NULL;
        }
    case 25346: /* module 99 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_beneficiary;
        case 2:
            return STR_IT_assets;
        case 3:
            return STR_IT_fee_asset_item;
        case 4:
            return STR_IT_dest_weight;
        default:
            return NULL;
        }
    case 25347: /* module 99 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_message;
        case 1:
            return STR_IT_max_weight;
        default:
            return NULL;
        }
#endif
    default:
        return NULL;
    }

    return NULL;
}

parser_error_t _getMethod_ItemValue_V6(
    pd_Method_V6_t* m,
    uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1024: /* module 4 call 0 */
        switch (itemIdx) {
        case 0: /* balances_transfer_V6 - dest */;
            return _toStringLookupSource_V6(
                &m->nested.balances_transfer_V6.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_V6 - value */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_V6.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1027: /* module 4 call 3 */
        switch (itemIdx) {
        case 0: /* balances_transfer_keep_alive_V6 - dest */;
            return _toStringLookupSource_V6(
                &m->nested.balances_transfer_keep_alive_V6.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_keep_alive_V6 - value */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_keep_alive_V6.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1536: /* module 6 call 0 */
        switch (itemIdx) {
        case 0: /* staking_bond_V6 - controller */;
            return _toStringLookupSource_V6(
                &m->basic.staking_bond_V6.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_bond_V6 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.staking_bond_V6.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* staking_bond_V6 - payee */;
            return _toStringRewardDestination_V6(
                &m->basic.staking_bond_V6.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1537: /* module 6 call 1 */
        switch (itemIdx) {
        case 0: /* staking_bond_extra_V6 - max_additional */;
            return _toStringCompactBalanceOf(
                &m->basic.staking_bond_extra_V6.max_additional,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1538: /* module 6 call 2 */
        switch (itemIdx) {
        case 0: /* staking_unbond_V6 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.staking_unbond_V6.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1539: /* module 6 call 3 */
        switch (itemIdx) {
        case 0: /* staking_withdraw_unbonded_V6 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_withdraw_unbonded_V6.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1540: /* module 6 call 4 */
        switch (itemIdx) {
        case 0: /* staking_validate_V6 - prefs */;
            return _toStringValidatorPrefs_V6(
                &m->basic.staking_validate_V6.prefs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1541: /* module 6 call 5 */
        switch (itemIdx) {
        case 0: /* staking_nominate_V6 - targets */;
            return _toStringVecLookupSource_V6(
                &m->basic.staking_nominate_V6.targets,
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
        case 0: /* staking_set_payee_V6 - payee */;
            return _toStringRewardDestination_V6(
                &m->basic.staking_set_payee_V6.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1544: /* module 6 call 8 */
        switch (itemIdx) {
        case 0: /* staking_set_controller_V6 - controller */;
            return _toStringLookupSource_V6(
                &m->basic.staking_set_controller_V6.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1554: /* module 6 call 18 */
        switch (itemIdx) {
        case 0: /* staking_payout_stakers_V6 - validator_stash */;
            return _toStringAccountId_V6(
                &m->basic.staking_payout_stakers_V6.validator_stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_payout_stakers_V6 - era */;
            return _toStringEraIndex_V6(
                &m->basic.staking_payout_stakers_V6.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1555: /* module 6 call 19 */
        switch (itemIdx) {
        case 0: /* staking_rebond_V6 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.staking_rebond_V6.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2048: /* module 8 call 0 */
        switch (itemIdx) {
        case 0: /* session_set_keys_V6 - keys */;
            return _toStringKeys_V6(
                &m->basic.session_set_keys_V6.keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* session_set_keys_V6 - proof */;
            return _toStringBytes(
                &m->basic.session_set_keys_V6.proof,
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
    case 6144: /* module 24 call 0 */
        switch (itemIdx) {
        case 0: /* utility_batch_V6 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_V6.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6146: /* module 24 call 2 */
        switch (itemIdx) {
        case 0: /* utility_batch_all_V6 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_all_V6.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0: /* system_fill_block_V6 - _ratio */;
            return _toStringPerbill_V6(
                &m->nested.system_fill_block_V6._ratio,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0: /* system_remark_V6 - _remark */;
            return _toStringBytes(
                &m->nested.system_remark_V6._remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0: /* system_set_heap_pages_V6 - pages */;
            return _toStringu64(
                &m->nested.system_set_heap_pages_V6.pages,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0: /* system_set_code_V6 - code */;
            return _toStringBytes(
                &m->nested.system_set_code_V6.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4: /* module 0 call 4 */
        switch (itemIdx) {
        case 0: /* system_set_code_without_checks_V6 - code */;
            return _toStringBytes(
                &m->nested.system_set_code_without_checks_V6.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5: /* module 0 call 5 */
        switch (itemIdx) {
        case 0: /* system_set_changes_trie_config_V6 - changes_trie_config */;
            return _toStringOptionChangesTrieConfiguration_V6(
                &m->nested.system_set_changes_trie_config_V6.changes_trie_config,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6: /* module 0 call 6 */
        switch (itemIdx) {
        case 0: /* system_set_storage_V6 - items */;
            return _toStringVecKeyValue_V6(
                &m->nested.system_set_storage_V6.items,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7: /* module 0 call 7 */
        switch (itemIdx) {
        case 0: /* system_kill_storage_V6 - keys */;
            return _toStringVecKey_V6(
                &m->nested.system_kill_storage_V6.keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8: /* module 0 call 8 */
        switch (itemIdx) {
        case 0: /* system_kill_prefix_V6 - prefix */;
            return _toStringKey_V6(
                &m->nested.system_kill_prefix_V6.prefix,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* system_kill_prefix_V6 - _subkeys */;
            return _toStringu32(
                &m->nested.system_kill_prefix_V6._subkeys,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9: /* module 0 call 9 */
        switch (itemIdx) {
        case 0: /* system_remark_with_event_V6 - remark */;
            return _toStringBytes(
                &m->basic.system_remark_with_event_V6.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 256: /* module 1 call 0 */
        switch (itemIdx) {
        case 0: /* babe_report_equivocation_V6 - equivocation_proof */;
            return _toStringBabeEquivocationProof_V6(
                &m->basic.babe_report_equivocation_V6.equivocation_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* babe_report_equivocation_V6 - key_owner_proof */;
            return _toStringKeyOwnerProof_V6(
                &m->basic.babe_report_equivocation_V6.key_owner_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 257: /* module 1 call 1 */
        switch (itemIdx) {
        case 0: /* babe_report_equivocation_unsigned_V6 - equivocation_proof */;
            return _toStringBabeEquivocationProof_V6(
                &m->basic.babe_report_equivocation_unsigned_V6.equivocation_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* babe_report_equivocation_unsigned_V6 - key_owner_proof */;
            return _toStringKeyOwnerProof_V6(
                &m->basic.babe_report_equivocation_unsigned_V6.key_owner_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 258: /* module 1 call 2 */
        switch (itemIdx) {
        case 0: /* babe_plan_config_change_V6 - config */;
            return _toStringNextConfigDescriptor_V6(
                &m->basic.babe_plan_config_change_V6.config,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 512: /* module 2 call 0 */
        switch (itemIdx) {
        case 0: /* timestamp_set_V6 - now */;
            return _toStringCompactMoment_V6(
                &m->basic.timestamp_set_V6.now,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 768: /* module 3 call 0 */
        switch (itemIdx) {
        case 0: /* indices_claim_V6 - index */;
            return _toStringAccountIndex_V6(
                &m->basic.indices_claim_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 769: /* module 3 call 1 */
        switch (itemIdx) {
        case 0: /* indices_transfer_V6 - new_ */;
            return _toStringAccountId_V6(
                &m->basic.indices_transfer_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* indices_transfer_V6 - index */;
            return _toStringAccountIndex_V6(
                &m->basic.indices_transfer_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 770: /* module 3 call 2 */
        switch (itemIdx) {
        case 0: /* indices_free_V6 - index */;
            return _toStringAccountIndex_V6(
                &m->basic.indices_free_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 771: /* module 3 call 3 */
        switch (itemIdx) {
        case 0: /* indices_force_transfer_V6 - new_ */;
            return _toStringAccountId_V6(
                &m->basic.indices_force_transfer_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* indices_force_transfer_V6 - index */;
            return _toStringAccountIndex_V6(
                &m->basic.indices_force_transfer_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* indices_force_transfer_V6 - freeze */;
            return _toStringbool(
                &m->basic.indices_force_transfer_V6.freeze,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 772: /* module 3 call 4 */
        switch (itemIdx) {
        case 0: /* indices_freeze_V6 - index */;
            return _toStringAccountIndex_V6(
                &m->basic.indices_freeze_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1025: /* module 4 call 1 */
        switch (itemIdx) {
        case 0: /* balances_set_balance_V6 - who */;
            return _toStringLookupSource_V6(
                &m->nested.balances_set_balance_V6.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_set_balance_V6 - new_free */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_V6.new_free,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_set_balance_V6 - new_reserved */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_V6.new_reserved,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1026: /* module 4 call 2 */
        switch (itemIdx) {
        case 0: /* balances_force_transfer_V6 - source */;
            return _toStringLookupSource_V6(
                &m->nested.balances_force_transfer_V6.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_transfer_V6 - dest */;
            return _toStringLookupSource_V6(
                &m->nested.balances_force_transfer_V6.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_force_transfer_V6 - value */;
            return _toStringCompactBalance(
                &m->nested.balances_force_transfer_V6.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1028: /* module 4 call 4 */
        switch (itemIdx) {
        case 0: /* balances_transfer_all_V6 - dest */;
            return _toStringLookupSource_V6(
                &m->basic.balances_transfer_all_V6.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_all_V6 - keep_alive */;
            return _toStringbool(
                &m->basic.balances_transfer_all_V6.keep_alive,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1280: /* module 5 call 0 */
        switch (itemIdx) {
        case 0: /* authorship_set_uncles_V6 - new_uncles */;
            return _toStringVecHeader(
                &m->basic.authorship_set_uncles_V6.new_uncles,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1545: /* module 6 call 9 */
        switch (itemIdx) {
        case 0: /* staking_set_validator_count_V6 - new_ */;
            return _toStringCompactu32(
                &m->basic.staking_set_validator_count_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1546: /* module 6 call 10 */
        switch (itemIdx) {
        case 0: /* staking_increase_validator_count_V6 - additional */;
            return _toStringCompactu32(
                &m->basic.staking_increase_validator_count_V6.additional,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1547: /* module 6 call 11 */
        switch (itemIdx) {
        case 0: /* staking_scale_validator_count_V6 - factor */;
            return _toStringPercent_V6(
                &m->basic.staking_scale_validator_count_V6.factor,
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
        case 0: /* staking_set_invulnerables_V6 - invulnerables */;
            return _toStringVecAccountId_V6(
                &m->basic.staking_set_invulnerables_V6.invulnerables,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1551: /* module 6 call 15 */
        switch (itemIdx) {
        case 0: /* staking_force_unstake_V6 - stash */;
            return _toStringAccountId_V6(
                &m->basic.staking_force_unstake_V6.stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_force_unstake_V6 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_force_unstake_V6.num_slashing_spans,
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
        case 0: /* staking_cancel_deferred_slash_V6 - era */;
            return _toStringEraIndex_V6(
                &m->basic.staking_cancel_deferred_slash_V6.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_cancel_deferred_slash_V6 - slash_indices */;
            return _toStringVecu32(
                &m->basic.staking_cancel_deferred_slash_V6.slash_indices,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1556: /* module 6 call 20 */
        switch (itemIdx) {
        case 0: /* staking_set_history_depth_V6 - new_history_depth */;
            return _toStringCompactEraIndex_V6(
                &m->basic.staking_set_history_depth_V6.new_history_depth,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_set_history_depth_V6 - _era_items_deleted */;
            return _toStringCompactu32(
                &m->basic.staking_set_history_depth_V6._era_items_deleted,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1557: /* module 6 call 21 */
        switch (itemIdx) {
        case 0: /* staking_reap_stash_V6 - stash */;
            return _toStringAccountId_V6(
                &m->basic.staking_reap_stash_V6.stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_reap_stash_V6 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_reap_stash_V6.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1558: /* module 6 call 22 */
        switch (itemIdx) {
        case 0: /* staking_kick_V6 - who */;
            return _toStringVecLookupSource_V6(
                &m->basic.staking_kick_V6.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1559: /* module 6 call 23 */
        switch (itemIdx) {
        case 0: /* staking_set_staking_limits_V6 - min_nominator_bond */;
            return _toStringBalanceOf(
                &m->basic.staking_set_staking_limits_V6.min_nominator_bond,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_set_staking_limits_V6 - min_validator_bond */;
            return _toStringBalanceOf(
                &m->basic.staking_set_staking_limits_V6.min_validator_bond,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* staking_set_staking_limits_V6 - max_nominator_count */;
            return _toStringOptionu32(
                &m->basic.staking_set_staking_limits_V6.max_nominator_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* staking_set_staking_limits_V6 - max_validator_count */;
            return _toStringOptionu32(
                &m->basic.staking_set_staking_limits_V6.max_validator_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* staking_set_staking_limits_V6 - threshold */;
            return _toStringOptionPercent_V6(
                &m->basic.staking_set_staking_limits_V6.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1560: /* module 6 call 24 */
        switch (itemIdx) {
        case 0: /* staking_chill_other_V6 - controller */;
            return _toStringAccountId_V6(
                &m->basic.staking_chill_other_V6.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0: /* grandpa_report_equivocation_V6 - equivocation_proof */;
            return _toStringGrandpaEquivocationProof_V6(
                &m->basic.grandpa_report_equivocation_V6.equivocation_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* grandpa_report_equivocation_V6 - key_owner_proof */;
            return _toStringKeyOwnerProof_V6(
                &m->basic.grandpa_report_equivocation_V6.key_owner_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2561: /* module 10 call 1 */
        switch (itemIdx) {
        case 0: /* grandpa_report_equivocation_unsigned_V6 - equivocation_proof */;
            return _toStringGrandpaEquivocationProof_V6(
                &m->basic.grandpa_report_equivocation_unsigned_V6.equivocation_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* grandpa_report_equivocation_unsigned_V6 - key_owner_proof */;
            return _toStringKeyOwnerProof_V6(
                &m->basic.grandpa_report_equivocation_unsigned_V6.key_owner_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2562: /* module 10 call 2 */
        switch (itemIdx) {
        case 0: /* grandpa_note_stalled_V6 - delay */;
            return _toStringBlockNumber(
                &m->basic.grandpa_note_stalled_V6.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* grandpa_note_stalled_V6 - best_finalized_block_number */;
            return _toStringBlockNumber(
                &m->basic.grandpa_note_stalled_V6.best_finalized_block_number,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2816: /* module 11 call 0 */
        switch (itemIdx) {
        case 0: /* imonline_heartbeat_V6 - heartbeat */;
            return _toStringHeartbeat(
                &m->basic.imonline_heartbeat_V6.heartbeat,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* imonline_heartbeat_V6 - _signature */;
            return _toStringSignature_V6(
                &m->basic.imonline_heartbeat_V6._signature,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3328: /* module 13 call 0 */
        switch (itemIdx) {
        case 0: /* democracy_propose_V6 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_propose_V6.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_propose_V6 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.democracy_propose_V6.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3329: /* module 13 call 1 */
        switch (itemIdx) {
        case 0: /* democracy_second_V6 - proposal */;
            return _toStringCompactPropIndex_V6(
                &m->basic.democracy_second_V6.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_second_V6 - seconds_upper_bound */;
            return _toStringCompactu32(
                &m->basic.democracy_second_V6.seconds_upper_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3330: /* module 13 call 2 */
        switch (itemIdx) {
        case 0: /* democracy_vote_V6 - ref_index */;
            return _toStringCompactReferendumIndex_V6(
                &m->basic.democracy_vote_V6.ref_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_vote_V6 - vote */;
            return _toStringAccountVote_V6(
                &m->basic.democracy_vote_V6.vote,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3331: /* module 13 call 3 */
        switch (itemIdx) {
        case 0: /* democracy_emergency_cancel_V6 - ref_index */;
            return _toStringReferendumIndex_V6(
                &m->basic.democracy_emergency_cancel_V6.ref_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3332: /* module 13 call 4 */
        switch (itemIdx) {
        case 0: /* democracy_external_propose_V6 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_external_propose_V6.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3333: /* module 13 call 5 */
        switch (itemIdx) {
        case 0: /* democracy_external_propose_majority_V6 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_external_propose_majority_V6.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3334: /* module 13 call 6 */
        switch (itemIdx) {
        case 0: /* democracy_external_propose_default_V6 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_external_propose_default_V6.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3335: /* module 13 call 7 */
        switch (itemIdx) {
        case 0: /* democracy_fast_track_V6 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_fast_track_V6.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_fast_track_V6 - voting_period */;
            return _toStringBlockNumber(
                &m->basic.democracy_fast_track_V6.voting_period,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* democracy_fast_track_V6 - delay */;
            return _toStringBlockNumber(
                &m->basic.democracy_fast_track_V6.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3336: /* module 13 call 8 */
        switch (itemIdx) {
        case 0: /* democracy_veto_external_V6 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_veto_external_V6.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3337: /* module 13 call 9 */
        switch (itemIdx) {
        case 0: /* democracy_cancel_referendum_V6 - ref_index */;
            return _toStringCompactReferendumIndex_V6(
                &m->basic.democracy_cancel_referendum_V6.ref_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3338: /* module 13 call 10 */
        switch (itemIdx) {
        case 0: /* democracy_cancel_queued_V6 - which */;
            return _toStringReferendumIndex_V6(
                &m->basic.democracy_cancel_queued_V6.which,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3339: /* module 13 call 11 */
        switch (itemIdx) {
        case 0: /* democracy_delegate_V6 - to */;
            return _toStringAccountId_V6(
                &m->basic.democracy_delegate_V6.to,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_delegate_V6 - conviction */;
            return _toStringConviction_V6(
                &m->basic.democracy_delegate_V6.conviction,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* democracy_delegate_V6 - balance */;
            return _toStringBalanceOf(
                &m->basic.democracy_delegate_V6.balance,
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
        case 0: /* democracy_note_preimage_V6 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_preimage_V6.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3343: /* module 13 call 15 */
        switch (itemIdx) {
        case 0: /* democracy_note_preimage_operational_V6 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_preimage_operational_V6.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3344: /* module 13 call 16 */
        switch (itemIdx) {
        case 0: /* democracy_note_imminent_preimage_V6 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_imminent_preimage_V6.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3345: /* module 13 call 17 */
        switch (itemIdx) {
        case 0: /* democracy_note_imminent_preimage_operational_V6 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_imminent_preimage_operational_V6.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3346: /* module 13 call 18 */
        switch (itemIdx) {
        case 0: /* democracy_reap_preimage_V6 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_reap_preimage_V6.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_reap_preimage_V6 - proposal_len_upper_bound */;
            return _toStringCompactu32(
                &m->basic.democracy_reap_preimage_V6.proposal_len_upper_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3347: /* module 13 call 19 */
        switch (itemIdx) {
        case 0: /* democracy_unlock_V6 - target */;
            return _toStringAccountId_V6(
                &m->basic.democracy_unlock_V6.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3348: /* module 13 call 20 */
        switch (itemIdx) {
        case 0: /* democracy_remove_vote_V6 - index */;
            return _toStringReferendumIndex_V6(
                &m->basic.democracy_remove_vote_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3349: /* module 13 call 21 */
        switch (itemIdx) {
        case 0: /* democracy_remove_other_vote_V6 - target */;
            return _toStringAccountId_V6(
                &m->basic.democracy_remove_other_vote_V6.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_remove_other_vote_V6 - index */;
            return _toStringReferendumIndex_V6(
                &m->basic.democracy_remove_other_vote_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3350: /* module 13 call 22 */
        switch (itemIdx) {
        case 0: /* democracy_enact_proposal_V6 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_enact_proposal_V6.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_enact_proposal_V6 - index */;
            return _toStringReferendumIndex_V6(
                &m->basic.democracy_enact_proposal_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3351: /* module 13 call 23 */
        switch (itemIdx) {
        case 0: /* democracy_blacklist_V6 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_blacklist_V6.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_blacklist_V6 - maybe_ref_index */;
            return _toStringOptionReferendumIndex_V6(
                &m->basic.democracy_blacklist_V6.maybe_ref_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3352: /* module 13 call 24 */
        switch (itemIdx) {
        case 0: /* democracy_cancel_proposal_V6 - prop_index */;
            return _toStringCompactPropIndex_V6(
                &m->basic.democracy_cancel_proposal_V6.prop_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3584: /* module 14 call 0 */
        switch (itemIdx) {
        case 0: /* council_set_members_V6 - new_members */;
            return _toStringVecAccountId_V6(
                &m->basic.council_set_members_V6.new_members,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_set_members_V6 - prime */;
            return _toStringOptionAccountId_V6(
                &m->basic.council_set_members_V6.prime,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_set_members_V6 - old_count */;
            return _toStringMemberCount_V6(
                &m->basic.council_set_members_V6.old_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3585: /* module 14 call 1 */
        switch (itemIdx) {
        case 0: /* council_execute_V6 - proposal */;
            return _toStringProposal(
                &m->basic.council_execute_V6.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_execute_V6 - length_bound */;
            return _toStringCompactu32(
                &m->basic.council_execute_V6.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3586: /* module 14 call 2 */
        switch (itemIdx) {
        case 0: /* council_propose_V6 - threshold */;
            return _toStringCompactMemberCount_V6(
                &m->basic.council_propose_V6.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_propose_V6 - proposal */;
            return _toStringProposal(
                &m->basic.council_propose_V6.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_propose_V6 - length_bound */;
            return _toStringCompactu32(
                &m->basic.council_propose_V6.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3587: /* module 14 call 3 */
        switch (itemIdx) {
        case 0: /* council_vote_V6 - proposal */;
            return _toStringHash(
                &m->basic.council_vote_V6.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_vote_V6 - index */;
            return _toStringCompactProposalIndex_V6(
                &m->basic.council_vote_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_vote_V6 - approve */;
            return _toStringbool(
                &m->basic.council_vote_V6.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3588: /* module 14 call 4 */
        switch (itemIdx) {
        case 0: /* council_close_V6 - proposal_hash */;
            return _toStringHash(
                &m->basic.council_close_V6.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_close_V6 - index */;
            return _toStringCompactProposalIndex_V6(
                &m->basic.council_close_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_close_V6 - proposal_weight_bound */;
            return _toStringCompactWeight_V6(
                &m->basic.council_close_V6.proposal_weight_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* council_close_V6 - length_bound */;
            return _toStringCompactu32(
                &m->basic.council_close_V6.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3589: /* module 14 call 5 */
        switch (itemIdx) {
        case 0: /* council_disapprove_proposal_V6 - proposal_hash */;
            return _toStringHash(
                &m->basic.council_disapprove_proposal_V6.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3840: /* module 15 call 0 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_set_members_V6 - new_members */;
            return _toStringVecAccountId_V6(
                &m->basic.technicalcommittee_set_members_V6.new_members,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_set_members_V6 - prime */;
            return _toStringOptionAccountId_V6(
                &m->basic.technicalcommittee_set_members_V6.prime,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_set_members_V6 - old_count */;
            return _toStringMemberCount_V6(
                &m->basic.technicalcommittee_set_members_V6.old_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3841: /* module 15 call 1 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_execute_V6 - proposal */;
            return _toStringProposal(
                &m->basic.technicalcommittee_execute_V6.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_execute_V6 - length_bound */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_execute_V6.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3842: /* module 15 call 2 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_propose_V6 - threshold */;
            return _toStringCompactMemberCount_V6(
                &m->basic.technicalcommittee_propose_V6.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_propose_V6 - proposal */;
            return _toStringProposal(
                &m->basic.technicalcommittee_propose_V6.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_propose_V6 - length_bound */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_propose_V6.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3843: /* module 15 call 3 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_vote_V6 - proposal */;
            return _toStringHash(
                &m->basic.technicalcommittee_vote_V6.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_vote_V6 - index */;
            return _toStringCompactProposalIndex_V6(
                &m->basic.technicalcommittee_vote_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_vote_V6 - approve */;
            return _toStringbool(
                &m->basic.technicalcommittee_vote_V6.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3844: /* module 15 call 4 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_close_V6 - proposal_hash */;
            return _toStringHash(
                &m->basic.technicalcommittee_close_V6.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_close_V6 - index */;
            return _toStringCompactProposalIndex_V6(
                &m->basic.technicalcommittee_close_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_close_V6 - proposal_weight_bound */;
            return _toStringCompactWeight_V6(
                &m->basic.technicalcommittee_close_V6.proposal_weight_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* technicalcommittee_close_V6 - length_bound */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_close_V6.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3845: /* module 15 call 5 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_disapprove_proposal_V6 - proposal_hash */;
            return _toStringHash(
                &m->basic.technicalcommittee_disapprove_proposal_V6.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4096: /* module 16 call 0 */
        switch (itemIdx) {
        case 0: /* phragmenelection_vote_V6 - votes */;
            return _toStringVecAccountId_V6(
                &m->basic.phragmenelection_vote_V6.votes,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* phragmenelection_vote_V6 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.phragmenelection_vote_V6.value,
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
        case 0: /* phragmenelection_submit_candidacy_V6 - candidate_count */;
            return _toStringCompactu32(
                &m->basic.phragmenelection_submit_candidacy_V6.candidate_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4099: /* module 16 call 3 */
        switch (itemIdx) {
        case 0: /* phragmenelection_renounce_candidacy_V6 - renouncing */;
            return _toStringRenouncing_V6(
                &m->basic.phragmenelection_renounce_candidacy_V6.renouncing,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4100: /* module 16 call 4 */
        switch (itemIdx) {
        case 0: /* phragmenelection_remove_member_V6 - who */;
            return _toStringLookupSource_V6(
                &m->basic.phragmenelection_remove_member_V6.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* phragmenelection_remove_member_V6 - has_replacement */;
            return _toStringbool(
                &m->basic.phragmenelection_remove_member_V6.has_replacement,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4101: /* module 16 call 5 */
        switch (itemIdx) {
        case 0: /* phragmenelection_clean_defunct_voters_V6 - _num_voters */;
            return _toStringu32(
                &m->basic.phragmenelection_clean_defunct_voters_V6._num_voters,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* phragmenelection_clean_defunct_voters_V6 - _num_defunct */;
            return _toStringu32(
                &m->basic.phragmenelection_clean_defunct_voters_V6._num_defunct,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4352: /* module 17 call 0 */
        switch (itemIdx) {
        case 0: /* technicalmembership_add_member_V6 - who */;
            return _toStringAccountId_V6(
                &m->basic.technicalmembership_add_member_V6.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4353: /* module 17 call 1 */
        switch (itemIdx) {
        case 0: /* technicalmembership_remove_member_V6 - who */;
            return _toStringAccountId_V6(
                &m->basic.technicalmembership_remove_member_V6.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4354: /* module 17 call 2 */
        switch (itemIdx) {
        case 0: /* technicalmembership_swap_member_V6 - remove */;
            return _toStringAccountId_V6(
                &m->basic.technicalmembership_swap_member_V6.remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalmembership_swap_member_V6 - add */;
            return _toStringAccountId_V6(
                &m->basic.technicalmembership_swap_member_V6.add,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4355: /* module 17 call 3 */
        switch (itemIdx) {
        case 0: /* technicalmembership_reset_members_V6 - members */;
            return _toStringVecAccountId_V6(
                &m->basic.technicalmembership_reset_members_V6.members,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4356: /* module 17 call 4 */
        switch (itemIdx) {
        case 0: /* technicalmembership_change_key_V6 - new_ */;
            return _toStringAccountId_V6(
                &m->basic.technicalmembership_change_key_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4357: /* module 17 call 5 */
        switch (itemIdx) {
        case 0: /* technicalmembership_set_prime_V6 - who */;
            return _toStringAccountId_V6(
                &m->basic.technicalmembership_set_prime_V6.who,
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
        case 0: /* treasury_propose_spend_V6 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.treasury_propose_spend_V6.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* treasury_propose_spend_V6 - beneficiary */;
            return _toStringLookupSource_V6(
                &m->basic.treasury_propose_spend_V6.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4609: /* module 18 call 1 */
        switch (itemIdx) {
        case 0: /* treasury_reject_proposal_V6 - proposal_id */;
            return _toStringCompactProposalIndex_V6(
                &m->basic.treasury_reject_proposal_V6.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4610: /* module 18 call 2 */
        switch (itemIdx) {
        case 0: /* treasury_approve_proposal_V6 - proposal_id */;
            return _toStringCompactProposalIndex_V6(
                &m->basic.treasury_approve_proposal_V6.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4864: /* module 19 call 0 */
        switch (itemIdx) {
        case 0: /* claims_claim_V6 - dest */;
            return _toStringAccountId_V6(
                &m->basic.claims_claim_V6.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* claims_claim_V6 - ethereum_signature */;
            return _toStringEcdsaSignature_V6(
                &m->basic.claims_claim_V6.ethereum_signature,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4865: /* module 19 call 1 */
        switch (itemIdx) {
        case 0: /* claims_mint_claim_V6 - who */;
            return _toStringEthereumAddress_V6(
                &m->basic.claims_mint_claim_V6.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* claims_mint_claim_V6 - value */;
            return _toStringBalanceOf(
                &m->basic.claims_mint_claim_V6.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* claims_mint_claim_V6 - vesting_schedule */;
            return _toStringOptionTupleBalanceOfBalanceOfBlockNumber_V6(
                &m->basic.claims_mint_claim_V6.vesting_schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* claims_mint_claim_V6 - statement */;
            return _toStringOptionStatementKind_V6(
                &m->basic.claims_mint_claim_V6.statement,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4866: /* module 19 call 2 */
        switch (itemIdx) {
        case 0: /* claims_claim_attest_V6 - dest */;
            return _toStringAccountId_V6(
                &m->basic.claims_claim_attest_V6.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* claims_claim_attest_V6 - ethereum_signature */;
            return _toStringEcdsaSignature_V6(
                &m->basic.claims_claim_attest_V6.ethereum_signature,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* claims_claim_attest_V6 - statement */;
            return _toStringBytes(
                &m->basic.claims_claim_attest_V6.statement,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4867: /* module 19 call 3 */
        switch (itemIdx) {
        case 0: /* claims_attest_V6 - statement */;
            return _toStringBytes(
                &m->basic.claims_attest_V6.statement,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4868: /* module 19 call 4 */
        switch (itemIdx) {
        case 0: /* claims_move_claim_V6 - old */;
            return _toStringEthereumAddress_V6(
                &m->basic.claims_move_claim_V6.old,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* claims_move_claim_V6 - new_ */;
            return _toStringEthereumAddress_V6(
                &m->basic.claims_move_claim_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* claims_move_claim_V6 - maybe_preclaim */;
            return _toStringOptionAccountId_V6(
                &m->basic.claims_move_claim_V6.maybe_preclaim,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6145: /* module 24 call 1 */
        switch (itemIdx) {
        case 0: /* utility_as_derivative_V6 - index */;
            return _toStringu16(
                &m->basic.utility_as_derivative_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* utility_as_derivative_V6 - call */;
            return _toStringCall(
                &m->basic.utility_as_derivative_V6.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6400: /* module 25 call 0 */
        switch (itemIdx) {
        case 0: /* identity_add_registrar_V6 - account */;
            return _toStringAccountId_V6(
                &m->basic.identity_add_registrar_V6.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6401: /* module 25 call 1 */
        switch (itemIdx) {
        case 0: /* identity_set_identity_V6 - info */;
            return _toStringIdentityInfo_V6(
                &m->basic.identity_set_identity_V6.info,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6402: /* module 25 call 2 */
        switch (itemIdx) {
        case 0: /* identity_set_subs_V6 - subs */;
            return _toStringVecTupleAccountIdData_V6(
                &m->basic.identity_set_subs_V6.subs,
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
        case 0: /* identity_request_judgement_V6 - reg_index */;
            return _toStringCompactRegistrarIndex_V6(
                &m->basic.identity_request_judgement_V6.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_request_judgement_V6 - max_fee */;
            return _toStringCompactBalanceOf(
                &m->basic.identity_request_judgement_V6.max_fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6405: /* module 25 call 5 */
        switch (itemIdx) {
        case 0: /* identity_cancel_request_V6 - reg_index */;
            return _toStringRegistrarIndex_V6(
                &m->basic.identity_cancel_request_V6.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6406: /* module 25 call 6 */
        switch (itemIdx) {
        case 0: /* identity_set_fee_V6 - index */;
            return _toStringCompactRegistrarIndex_V6(
                &m->basic.identity_set_fee_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_fee_V6 - fee */;
            return _toStringCompactBalanceOf(
                &m->basic.identity_set_fee_V6.fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6407: /* module 25 call 7 */
        switch (itemIdx) {
        case 0: /* identity_set_account_id_V6 - index */;
            return _toStringCompactRegistrarIndex_V6(
                &m->basic.identity_set_account_id_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_account_id_V6 - new_ */;
            return _toStringAccountId_V6(
                &m->basic.identity_set_account_id_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6408: /* module 25 call 8 */
        switch (itemIdx) {
        case 0: /* identity_set_fields_V6 - index */;
            return _toStringCompactRegistrarIndex_V6(
                &m->basic.identity_set_fields_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_fields_V6 - fields */;
            return _toStringIdentityFields_V6(
                &m->basic.identity_set_fields_V6.fields,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6409: /* module 25 call 9 */
        switch (itemIdx) {
        case 0: /* identity_provide_judgement_V6 - reg_index */;
            return _toStringCompactRegistrarIndex_V6(
                &m->basic.identity_provide_judgement_V6.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_provide_judgement_V6 - target */;
            return _toStringLookupSource_V6(
                &m->basic.identity_provide_judgement_V6.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* identity_provide_judgement_V6 - judgement */;
            return _toStringIdentityJudgement_V6(
                &m->basic.identity_provide_judgement_V6.judgement,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6410: /* module 25 call 10 */
        switch (itemIdx) {
        case 0: /* identity_kill_identity_V6 - target */;
            return _toStringLookupSource_V6(
                &m->basic.identity_kill_identity_V6.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6411: /* module 25 call 11 */
        switch (itemIdx) {
        case 0: /* identity_add_sub_V6 - sub */;
            return _toStringLookupSource_V6(
                &m->basic.identity_add_sub_V6.sub,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_add_sub_V6 - data */;
            return _toStringData(
                &m->basic.identity_add_sub_V6.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6412: /* module 25 call 12 */
        switch (itemIdx) {
        case 0: /* identity_rename_sub_V6 - sub */;
            return _toStringLookupSource_V6(
                &m->basic.identity_rename_sub_V6.sub,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_rename_sub_V6 - data */;
            return _toStringData(
                &m->basic.identity_rename_sub_V6.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6413: /* module 25 call 13 */
        switch (itemIdx) {
        case 0: /* identity_remove_sub_V6 - sub */;
            return _toStringLookupSource_V6(
                &m->basic.identity_remove_sub_V6.sub,
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
        case 0: /* society_bid_V6 - value */;
            return _toStringBalanceOf(
                &m->basic.society_bid_V6.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6657: /* module 26 call 1 */
        switch (itemIdx) {
        case 0: /* society_unbid_V6 - pos */;
            return _toStringu32(
                &m->basic.society_unbid_V6.pos,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6658: /* module 26 call 2 */
        switch (itemIdx) {
        case 0: /* society_vouch_V6 - who */;
            return _toStringAccountId_V6(
                &m->basic.society_vouch_V6.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* society_vouch_V6 - value */;
            return _toStringBalanceOf(
                &m->basic.society_vouch_V6.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* society_vouch_V6 - tip */;
            return _toStringBalanceOf(
                &m->basic.society_vouch_V6.tip,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6659: /* module 26 call 3 */
        switch (itemIdx) {
        case 0: /* society_unvouch_V6 - pos */;
            return _toStringu32(
                &m->basic.society_unvouch_V6.pos,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6660: /* module 26 call 4 */
        switch (itemIdx) {
        case 0: /* society_vote_V6 - candidate */;
            return _toStringLookupSource_V6(
                &m->basic.society_vote_V6.candidate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* society_vote_V6 - approve */;
            return _toStringbool(
                &m->basic.society_vote_V6.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6661: /* module 26 call 5 */
        switch (itemIdx) {
        case 0: /* society_defender_vote_V6 - approve */;
            return _toStringbool(
                &m->basic.society_defender_vote_V6.approve,
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
        case 0: /* society_found_V6 - founder */;
            return _toStringAccountId_V6(
                &m->basic.society_found_V6.founder,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* society_found_V6 - max_members */;
            return _toStringu32(
                &m->basic.society_found_V6.max_members,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* society_found_V6 - rules */;
            return _toStringBytes(
                &m->basic.society_found_V6.rules,
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
        case 0: /* society_judge_suspended_member_V6 - who */;
            return _toStringAccountId_V6(
                &m->basic.society_judge_suspended_member_V6.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* society_judge_suspended_member_V6 - forgive */;
            return _toStringbool(
                &m->basic.society_judge_suspended_member_V6.forgive,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6666: /* module 26 call 10 */
        switch (itemIdx) {
        case 0: /* society_judge_suspended_candidate_V6 - who */;
            return _toStringAccountId_V6(
                &m->basic.society_judge_suspended_candidate_V6.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* society_judge_suspended_candidate_V6 - judgement */;
            return _toStringSocietyJudgement_V6(
                &m->basic.society_judge_suspended_candidate_V6.judgement,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6667: /* module 26 call 11 */
        switch (itemIdx) {
        case 0: /* society_set_max_members_V6 - max */;
            return _toStringu32(
                &m->basic.society_set_max_members_V6.max,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6912: /* module 27 call 0 */
        switch (itemIdx) {
        case 0: /* recovery_as_recovered_V6 - account */;
            return _toStringAccountId_V6(
                &m->basic.recovery_as_recovered_V6.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* recovery_as_recovered_V6 - call */;
            return _toStringCall(
                &m->basic.recovery_as_recovered_V6.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6913: /* module 27 call 1 */
        switch (itemIdx) {
        case 0: /* recovery_set_recovered_V6 - lost */;
            return _toStringAccountId_V6(
                &m->basic.recovery_set_recovered_V6.lost,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* recovery_set_recovered_V6 - rescuer */;
            return _toStringAccountId_V6(
                &m->basic.recovery_set_recovered_V6.rescuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6914: /* module 27 call 2 */
        switch (itemIdx) {
        case 0: /* recovery_create_recovery_V6 - friends */;
            return _toStringVecAccountId_V6(
                &m->basic.recovery_create_recovery_V6.friends,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* recovery_create_recovery_V6 - threshold */;
            return _toStringu16(
                &m->basic.recovery_create_recovery_V6.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* recovery_create_recovery_V6 - delay_period */;
            return _toStringBlockNumber(
                &m->basic.recovery_create_recovery_V6.delay_period,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6915: /* module 27 call 3 */
        switch (itemIdx) {
        case 0: /* recovery_initiate_recovery_V6 - account */;
            return _toStringAccountId_V6(
                &m->basic.recovery_initiate_recovery_V6.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6916: /* module 27 call 4 */
        switch (itemIdx) {
        case 0: /* recovery_vouch_recovery_V6 - lost */;
            return _toStringAccountId_V6(
                &m->basic.recovery_vouch_recovery_V6.lost,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* recovery_vouch_recovery_V6 - rescuer */;
            return _toStringAccountId_V6(
                &m->basic.recovery_vouch_recovery_V6.rescuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6917: /* module 27 call 5 */
        switch (itemIdx) {
        case 0: /* recovery_claim_recovery_V6 - account */;
            return _toStringAccountId_V6(
                &m->basic.recovery_claim_recovery_V6.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6918: /* module 27 call 6 */
        switch (itemIdx) {
        case 0: /* recovery_close_recovery_V6 - rescuer */;
            return _toStringAccountId_V6(
                &m->basic.recovery_close_recovery_V6.rescuer,
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
        case 0: /* recovery_cancel_recovered_V6 - account */;
            return _toStringAccountId_V6(
                &m->basic.recovery_cancel_recovered_V6.account,
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
        case 0: /* vesting_vest_other_V6 - target */;
            return _toStringLookupSource_V6(
                &m->basic.vesting_vest_other_V6.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7170: /* module 28 call 2 */
        switch (itemIdx) {
        case 0: /* vesting_vested_transfer_V6 - target */;
            return _toStringLookupSource_V6(
                &m->basic.vesting_vested_transfer_V6.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_vested_transfer_V6 - schedule */;
            return _toStringVestingInfo_V6(
                &m->basic.vesting_vested_transfer_V6.schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7171: /* module 28 call 3 */
        switch (itemIdx) {
        case 0: /* vesting_force_vested_transfer_V6 - source */;
            return _toStringLookupSource_V6(
                &m->basic.vesting_force_vested_transfer_V6.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_force_vested_transfer_V6 - target */;
            return _toStringLookupSource_V6(
                &m->basic.vesting_force_vested_transfer_V6.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* vesting_force_vested_transfer_V6 - schedule */;
            return _toStringVestingInfo_V6(
                &m->basic.vesting_force_vested_transfer_V6.schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7424: /* module 29 call 0 */
        switch (itemIdx) {
        case 0: /* scheduler_schedule_V6 - when */;
            return _toStringBlockNumber(
                &m->basic.scheduler_schedule_V6.when,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_schedule_V6 - maybe_periodic */;
            return _toStringOptionPeriod_V6(
                &m->basic.scheduler_schedule_V6.maybe_periodic,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* scheduler_schedule_V6 - priority */;
            return _toStringPriority_V6(
                &m->basic.scheduler_schedule_V6.priority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* scheduler_schedule_V6 - call */;
            return _toStringCall(
                &m->basic.scheduler_schedule_V6.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7425: /* module 29 call 1 */
        switch (itemIdx) {
        case 0: /* scheduler_cancel_V6 - when */;
            return _toStringBlockNumber(
                &m->basic.scheduler_cancel_V6.when,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_cancel_V6 - index */;
            return _toStringu32(
                &m->basic.scheduler_cancel_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7426: /* module 29 call 2 */
        switch (itemIdx) {
        case 0: /* scheduler_schedule_named_V6 - id */;
            return _toStringBytes(
                &m->basic.scheduler_schedule_named_V6.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_schedule_named_V6 - when */;
            return _toStringBlockNumber(
                &m->basic.scheduler_schedule_named_V6.when,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* scheduler_schedule_named_V6 - maybe_periodic */;
            return _toStringOptionPeriod_V6(
                &m->basic.scheduler_schedule_named_V6.maybe_periodic,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* scheduler_schedule_named_V6 - priority */;
            return _toStringPriority_V6(
                &m->basic.scheduler_schedule_named_V6.priority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* scheduler_schedule_named_V6 - call */;
            return _toStringCall(
                &m->basic.scheduler_schedule_named_V6.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7427: /* module 29 call 3 */
        switch (itemIdx) {
        case 0: /* scheduler_cancel_named_V6 - id */;
            return _toStringBytes(
                &m->basic.scheduler_cancel_named_V6.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7428: /* module 29 call 4 */
        switch (itemIdx) {
        case 0: /* scheduler_schedule_after_V6 - after */;
            return _toStringBlockNumber(
                &m->basic.scheduler_schedule_after_V6.after,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_schedule_after_V6 - maybe_periodic */;
            return _toStringOptionPeriod_V6(
                &m->basic.scheduler_schedule_after_V6.maybe_periodic,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* scheduler_schedule_after_V6 - priority */;
            return _toStringPriority_V6(
                &m->basic.scheduler_schedule_after_V6.priority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* scheduler_schedule_after_V6 - call */;
            return _toStringCall(
                &m->basic.scheduler_schedule_after_V6.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7429: /* module 29 call 5 */
        switch (itemIdx) {
        case 0: /* scheduler_schedule_named_after_V6 - id */;
            return _toStringBytes(
                &m->basic.scheduler_schedule_named_after_V6.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_schedule_named_after_V6 - after */;
            return _toStringBlockNumber(
                &m->basic.scheduler_schedule_named_after_V6.after,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* scheduler_schedule_named_after_V6 - maybe_periodic */;
            return _toStringOptionPeriod_V6(
                &m->basic.scheduler_schedule_named_after_V6.maybe_periodic,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* scheduler_schedule_named_after_V6 - priority */;
            return _toStringPriority_V6(
                &m->basic.scheduler_schedule_named_after_V6.priority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* scheduler_schedule_named_after_V6 - call */;
            return _toStringCall(
                &m->basic.scheduler_schedule_named_after_V6.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7680: /* module 30 call 0 */
        switch (itemIdx) {
        case 0: /* proxy_proxy_V6 - real */;
            return _toStringAccountId_V6(
                &m->nested.proxy_proxy_V6.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_proxy_V6 - force_proxy_type */;
            return _toStringOptionProxyType_V6(
                &m->nested.proxy_proxy_V6.force_proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_proxy_V6 - call */;
            return _toStringCall(
                &m->nested.proxy_proxy_V6.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7681: /* module 30 call 1 */
        switch (itemIdx) {
        case 0: /* proxy_add_proxy_V6 - delegate */;
            return _toStringAccountId_V6(
                &m->basic.proxy_add_proxy_V6.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_add_proxy_V6 - proxy_type */;
            return _toStringProxyType_V6(
                &m->basic.proxy_add_proxy_V6.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_add_proxy_V6 - delay */;
            return _toStringBlockNumber(
                &m->basic.proxy_add_proxy_V6.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7682: /* module 30 call 2 */
        switch (itemIdx) {
        case 0: /* proxy_remove_proxy_V6 - delegate */;
            return _toStringAccountId_V6(
                &m->basic.proxy_remove_proxy_V6.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_remove_proxy_V6 - proxy_type */;
            return _toStringProxyType_V6(
                &m->basic.proxy_remove_proxy_V6.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_remove_proxy_V6 - delay */;
            return _toStringBlockNumber(
                &m->basic.proxy_remove_proxy_V6.delay,
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
        case 0: /* proxy_anonymous_V6 - proxy_type */;
            return _toStringProxyType_V6(
                &m->basic.proxy_anonymous_V6.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_anonymous_V6 - delay */;
            return _toStringBlockNumber(
                &m->basic.proxy_anonymous_V6.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_anonymous_V6 - index */;
            return _toStringu16(
                &m->basic.proxy_anonymous_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7685: /* module 30 call 5 */
        switch (itemIdx) {
        case 0: /* proxy_kill_anonymous_V6 - spawner */;
            return _toStringAccountId_V6(
                &m->basic.proxy_kill_anonymous_V6.spawner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_kill_anonymous_V6 - proxy_type */;
            return _toStringProxyType_V6(
                &m->basic.proxy_kill_anonymous_V6.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_kill_anonymous_V6 - index */;
            return _toStringu16(
                &m->basic.proxy_kill_anonymous_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* proxy_kill_anonymous_V6 - height */;
            return _toStringCompactBlockNumber(
                &m->basic.proxy_kill_anonymous_V6.height,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* proxy_kill_anonymous_V6 - ext_index */;
            return _toStringCompactu32(
                &m->basic.proxy_kill_anonymous_V6.ext_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7686: /* module 30 call 6 */
        switch (itemIdx) {
        case 0: /* proxy_announce_V6 - real */;
            return _toStringAccountId_V6(
                &m->basic.proxy_announce_V6.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_announce_V6 - call_hash */;
            return _toStringCallHashOf_V6(
                &m->basic.proxy_announce_V6.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7687: /* module 30 call 7 */
        switch (itemIdx) {
        case 0: /* proxy_remove_announcement_V6 - real */;
            return _toStringAccountId_V6(
                &m->basic.proxy_remove_announcement_V6.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_remove_announcement_V6 - call_hash */;
            return _toStringCallHashOf_V6(
                &m->basic.proxy_remove_announcement_V6.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7688: /* module 30 call 8 */
        switch (itemIdx) {
        case 0: /* proxy_reject_announcement_V6 - delegate */;
            return _toStringAccountId_V6(
                &m->basic.proxy_reject_announcement_V6.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_reject_announcement_V6 - call_hash */;
            return _toStringCallHashOf_V6(
                &m->basic.proxy_reject_announcement_V6.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7689: /* module 30 call 9 */
        switch (itemIdx) {
        case 0: /* proxy_proxy_announced_V6 - delegate */;
            return _toStringAccountId_V6(
                &m->basic.proxy_proxy_announced_V6.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_proxy_announced_V6 - real */;
            return _toStringAccountId_V6(
                &m->basic.proxy_proxy_announced_V6.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_proxy_announced_V6 - force_proxy_type */;
            return _toStringOptionProxyType_V6(
                &m->basic.proxy_proxy_announced_V6.force_proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* proxy_proxy_announced_V6 - call */;
            return _toStringCall(
                &m->basic.proxy_proxy_announced_V6.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7936: /* module 31 call 0 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_threshold_1_V6 - other_signatories */;
            return _toStringVecAccountId_V6(
                &m->nested.multisig_as_multi_threshold_1_V6.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_threshold_1_V6 - call */;
            return _toStringCall(
                &m->nested.multisig_as_multi_threshold_1_V6.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7937: /* module 31 call 1 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_V6 - threshold */;
            return _toStringu16(
                &m->nested.multisig_as_multi_V6.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_V6 - other_signatories */;
            return _toStringVecAccountId_V6(
                &m->nested.multisig_as_multi_V6.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_as_multi_V6 - maybe_timepoint */;
            return _toStringOptionTimepoint_V6(
                &m->nested.multisig_as_multi_V6.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_as_multi_V6 - call */;
            return _toStringOpaqueCall_V6(
                &m->nested.multisig_as_multi_V6.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_as_multi_V6 - store_call */;
            return _toStringbool(
                &m->nested.multisig_as_multi_V6.store_call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* multisig_as_multi_V6 - max_weight */;
            return _toStringWeight_V6(
                &m->nested.multisig_as_multi_V6.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7938: /* module 31 call 2 */
        switch (itemIdx) {
        case 0: /* multisig_approve_as_multi_V6 - threshold */;
            return _toStringu16(
                &m->nested.multisig_approve_as_multi_V6.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_approve_as_multi_V6 - other_signatories */;
            return _toStringVecAccountId_V6(
                &m->nested.multisig_approve_as_multi_V6.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_approve_as_multi_V6 - maybe_timepoint */;
            return _toStringOptionTimepoint_V6(
                &m->nested.multisig_approve_as_multi_V6.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_approve_as_multi_V6 - call_hash */;
            return _toStringu8_array_32_V6(
                &m->nested.multisig_approve_as_multi_V6.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_approve_as_multi_V6 - max_weight */;
            return _toStringWeight_V6(
                &m->nested.multisig_approve_as_multi_V6.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7939: /* module 31 call 3 */
        switch (itemIdx) {
        case 0: /* multisig_cancel_as_multi_V6 - threshold */;
            return _toStringu16(
                &m->nested.multisig_cancel_as_multi_V6.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_cancel_as_multi_V6 - other_signatories */;
            return _toStringVecAccountId_V6(
                &m->nested.multisig_cancel_as_multi_V6.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_cancel_as_multi_V6 - timepoint */;
            return _toStringTimepoint_V6(
                &m->nested.multisig_cancel_as_multi_V6.timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_cancel_as_multi_V6 - call_hash */;
            return _toStringu8_array_32_V6(
                &m->nested.multisig_cancel_as_multi_V6.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8960: /* module 35 call 0 */
        switch (itemIdx) {
        case 0: /* bounties_propose_bounty_V6 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.bounties_propose_bounty_V6.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bounties_propose_bounty_V6 - description */;
            return _toStringBytes(
                &m->basic.bounties_propose_bounty_V6.description,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8961: /* module 35 call 1 */
        switch (itemIdx) {
        case 0: /* bounties_approve_bounty_V6 - bounty_id */;
            return _toStringCompactBountyIndex_V6(
                &m->basic.bounties_approve_bounty_V6.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8962: /* module 35 call 2 */
        switch (itemIdx) {
        case 0: /* bounties_propose_curator_V6 - bounty_id */;
            return _toStringCompactBountyIndex_V6(
                &m->basic.bounties_propose_curator_V6.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bounties_propose_curator_V6 - curator */;
            return _toStringLookupSource_V6(
                &m->basic.bounties_propose_curator_V6.curator,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* bounties_propose_curator_V6 - fee */;
            return _toStringCompactBalanceOf(
                &m->basic.bounties_propose_curator_V6.fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8963: /* module 35 call 3 */
        switch (itemIdx) {
        case 0: /* bounties_unassign_curator_V6 - bounty_id */;
            return _toStringCompactBountyIndex_V6(
                &m->basic.bounties_unassign_curator_V6.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8964: /* module 35 call 4 */
        switch (itemIdx) {
        case 0: /* bounties_accept_curator_V6 - bounty_id */;
            return _toStringCompactBountyIndex_V6(
                &m->basic.bounties_accept_curator_V6.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8965: /* module 35 call 5 */
        switch (itemIdx) {
        case 0: /* bounties_award_bounty_V6 - bounty_id */;
            return _toStringCompactBountyIndex_V6(
                &m->basic.bounties_award_bounty_V6.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bounties_award_bounty_V6 - beneficiary */;
            return _toStringLookupSource_V6(
                &m->basic.bounties_award_bounty_V6.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8966: /* module 35 call 6 */
        switch (itemIdx) {
        case 0: /* bounties_claim_bounty_V6 - bounty_id */;
            return _toStringCompactBountyIndex_V6(
                &m->basic.bounties_claim_bounty_V6.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8967: /* module 35 call 7 */
        switch (itemIdx) {
        case 0: /* bounties_close_bounty_V6 - bounty_id */;
            return _toStringCompactBountyIndex_V6(
                &m->basic.bounties_close_bounty_V6.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8968: /* module 35 call 8 */
        switch (itemIdx) {
        case 0: /* bounties_extend_bounty_expiry_V6 - bounty_id */;
            return _toStringCompactBountyIndex_V6(
                &m->basic.bounties_extend_bounty_expiry_V6.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bounties_extend_bounty_expiry_V6 - _remark */;
            return _toStringBytes(
                &m->basic.bounties_extend_bounty_expiry_V6._remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9216: /* module 36 call 0 */
        switch (itemIdx) {
        case 0: /* tips_report_awesome_V6 - reason */;
            return _toStringBytes(
                &m->basic.tips_report_awesome_V6.reason,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* tips_report_awesome_V6 - who */;
            return _toStringAccountId_V6(
                &m->basic.tips_report_awesome_V6.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9217: /* module 36 call 1 */
        switch (itemIdx) {
        case 0: /* tips_retract_tip_V6 - hash */;
            return _toStringHash(
                &m->basic.tips_retract_tip_V6.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9218: /* module 36 call 2 */
        switch (itemIdx) {
        case 0: /* tips_tip_new_V6 - reason */;
            return _toStringBytes(
                &m->basic.tips_tip_new_V6.reason,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* tips_tip_new_V6 - who */;
            return _toStringAccountId_V6(
                &m->basic.tips_tip_new_V6.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* tips_tip_new_V6 - tip_value */;
            return _toStringCompactBalanceOf(
                &m->basic.tips_tip_new_V6.tip_value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9219: /* module 36 call 3 */
        switch (itemIdx) {
        case 0: /* tips_tip_V6 - hash */;
            return _toStringHash(
                &m->basic.tips_tip_V6.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* tips_tip_V6 - tip_value */;
            return _toStringCompactBalanceOf(
                &m->basic.tips_tip_V6.tip_value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9220: /* module 36 call 4 */
        switch (itemIdx) {
        case 0: /* tips_close_tip_V6 - hash */;
            return _toStringHash(
                &m->basic.tips_close_tip_V6.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9221: /* module 36 call 5 */
        switch (itemIdx) {
        case 0: /* tips_slash_tip_V6 - hash */;
            return _toStringHash(
                &m->basic.tips_slash_tip_V6.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9472: /* module 37 call 0 */
        switch (itemIdx) {
        case 0: /* electionprovidermultiphase_submit_unsigned_V6 - raw_solution */;
            return _toStringRawSolution_V6(
                &m->basic.electionprovidermultiphase_submit_unsigned_V6.raw_solution,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* electionprovidermultiphase_submit_unsigned_V6 - witness */;
            return _toStringSolutionOrSnapshotSize_V6(
                &m->basic.electionprovidermultiphase_submit_unsigned_V6.witness,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9473: /* module 37 call 1 */
        switch (itemIdx) {
        case 0: /* electionprovidermultiphase_set_minimum_untrusted_score_V6 - maybe_next_score */;
            return _toStringOptionElectionScore_V6(
                &m->basic.electionprovidermultiphase_set_minimum_untrusted_score_V6.maybe_next_score,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9474: /* module 37 call 2 */
        switch (itemIdx) {
        case 0: /* electionprovidermultiphase_set_emergency_election_result_V6 - supports */;
            return _toStringSupports_V6(
                &m->basic.electionprovidermultiphase_set_emergency_election_result_V6.supports,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9475: /* module 37 call 3 */
        switch (itemIdx) {
        case 0: /* electionprovidermultiphase_submit_V6 - raw_solution */;
            return _toStringRawSolution_V6(
                &m->basic.electionprovidermultiphase_submit_V6.raw_solution,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* electionprovidermultiphase_submit_V6 - num_signed_submissions */;
            return _toStringu32(
                &m->basic.electionprovidermultiphase_submit_V6.num_signed_submissions,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9728: /* module 38 call 0 */
        switch (itemIdx) {
        case 0: /* gilt_place_bid_V6 - amount */;
            return _toStringCompactBalanceOf(
                &m->basic.gilt_place_bid_V6.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* gilt_place_bid_V6 - duration */;
            return _toStringu32(
                &m->basic.gilt_place_bid_V6.duration,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9729: /* module 38 call 1 */
        switch (itemIdx) {
        case 0: /* gilt_retract_bid_V6 - amount */;
            return _toStringCompactBalanceOf(
                &m->basic.gilt_retract_bid_V6.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* gilt_retract_bid_V6 - duration */;
            return _toStringu32(
                &m->basic.gilt_retract_bid_V6.duration,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9730: /* module 38 call 2 */
        switch (itemIdx) {
        case 0: /* gilt_set_target_V6 - target */;
            return _toStringCompactPerquintill_V6(
                &m->basic.gilt_set_target_V6.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9731: /* module 38 call 3 */
        switch (itemIdx) {
        case 0: /* gilt_thaw_V6 - index */;
            return _toStringCompactActiveIndex_V6(
                &m->basic.gilt_thaw_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13056: /* module 51 call 0 */
        switch (itemIdx) {
        case 0: /* configuration_set_validation_upgrade_frequency_V6 - new_ */;
            return _toStringBlockNumber(
                &m->basic.configuration_set_validation_upgrade_frequency_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13057: /* module 51 call 1 */
        switch (itemIdx) {
        case 0: /* configuration_set_validation_upgrade_delay_V6 - new_ */;
            return _toStringBlockNumber(
                &m->basic.configuration_set_validation_upgrade_delay_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13058: /* module 51 call 2 */
        switch (itemIdx) {
        case 0: /* configuration_set_code_retention_period_V6 - new_ */;
            return _toStringBlockNumber(
                &m->basic.configuration_set_code_retention_period_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13059: /* module 51 call 3 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_code_size_V6 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_max_code_size_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13060: /* module 51 call 4 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_pov_size_V6 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_max_pov_size_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13061: /* module 51 call 5 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_head_data_size_V6 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_max_head_data_size_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13062: /* module 51 call 6 */
        switch (itemIdx) {
        case 0: /* configuration_set_parathread_cores_V6 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_parathread_cores_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13063: /* module 51 call 7 */
        switch (itemIdx) {
        case 0: /* configuration_set_parathread_retries_V6 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_parathread_retries_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13064: /* module 51 call 8 */
        switch (itemIdx) {
        case 0: /* configuration_set_group_rotation_frequency_V6 - new_ */;
            return _toStringBlockNumber(
                &m->basic.configuration_set_group_rotation_frequency_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13065: /* module 51 call 9 */
        switch (itemIdx) {
        case 0: /* configuration_set_chain_availability_period_V6 - new_ */;
            return _toStringBlockNumber(
                &m->basic.configuration_set_chain_availability_period_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13066: /* module 51 call 10 */
        switch (itemIdx) {
        case 0: /* configuration_set_thread_availability_period_V6 - new_ */;
            return _toStringBlockNumber(
                &m->basic.configuration_set_thread_availability_period_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13067: /* module 51 call 11 */
        switch (itemIdx) {
        case 0: /* configuration_set_scheduling_lookahead_V6 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_scheduling_lookahead_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13068: /* module 51 call 12 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_validators_per_core_V6 - new_ */;
            return _toStringOptionu32(
                &m->basic.configuration_set_max_validators_per_core_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13069: /* module 51 call 13 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_validators_V6 - new_ */;
            return _toStringOptionu32(
                &m->basic.configuration_set_max_validators_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13070: /* module 51 call 14 */
        switch (itemIdx) {
        case 0: /* configuration_set_dispute_period_V6 - new_ */;
            return _toStringSessionIndex_V6(
                &m->basic.configuration_set_dispute_period_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13071: /* module 51 call 15 */
        switch (itemIdx) {
        case 0: /* configuration_set_dispute_post_conclusion_acceptance_period_V6 - new_ */;
            return _toStringBlockNumber(
                &m->basic.configuration_set_dispute_post_conclusion_acceptance_period_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13072: /* module 51 call 16 */
        switch (itemIdx) {
        case 0: /* configuration_set_dispute_max_spam_slots_V6 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_dispute_max_spam_slots_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13073: /* module 51 call 17 */
        switch (itemIdx) {
        case 0: /* configuration_set_dispute_conclusion_by_time_out_period_V6 - new_ */;
            return _toStringBlockNumber(
                &m->basic.configuration_set_dispute_conclusion_by_time_out_period_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13074: /* module 51 call 18 */
        switch (itemIdx) {
        case 0: /* configuration_set_no_show_slots_V6 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_no_show_slots_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13075: /* module 51 call 19 */
        switch (itemIdx) {
        case 0: /* configuration_set_n_delay_tranches_V6 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_n_delay_tranches_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13076: /* module 51 call 20 */
        switch (itemIdx) {
        case 0: /* configuration_set_zeroth_delay_tranche_width_V6 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_zeroth_delay_tranche_width_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13077: /* module 51 call 21 */
        switch (itemIdx) {
        case 0: /* configuration_set_needed_approvals_V6 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_needed_approvals_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13078: /* module 51 call 22 */
        switch (itemIdx) {
        case 0: /* configuration_set_relay_vrf_modulo_samples_V6 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_relay_vrf_modulo_samples_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13079: /* module 51 call 23 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_upward_queue_count_V6 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_max_upward_queue_count_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13080: /* module 51 call 24 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_upward_queue_size_V6 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_max_upward_queue_size_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13081: /* module 51 call 25 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_downward_message_size_V6 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_max_downward_message_size_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13082: /* module 51 call 26 */
        switch (itemIdx) {
        case 0: /* configuration_set_ump_service_total_weight_V6 - new_ */;
            return _toStringWeight_V6(
                &m->basic.configuration_set_ump_service_total_weight_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13083: /* module 51 call 27 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_upward_message_size_V6 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_max_upward_message_size_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13084: /* module 51 call 28 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_upward_message_num_per_candidate_V6 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_max_upward_message_num_per_candidate_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13085: /* module 51 call 29 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_open_request_ttl_V6 - _new */;
            return _toStringu32(
                &m->basic.configuration_set_hrmp_open_request_ttl_V6._new,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13086: /* module 51 call 30 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_sender_deposit_V6 - new_ */;
            return _toStringBalance(
                &m->basic.configuration_set_hrmp_sender_deposit_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13087: /* module 51 call 31 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_recipient_deposit_V6 - new_ */;
            return _toStringBalance(
                &m->basic.configuration_set_hrmp_recipient_deposit_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13088: /* module 51 call 32 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_channel_max_capacity_V6 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_hrmp_channel_max_capacity_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13089: /* module 51 call 33 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_channel_max_total_size_V6 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_hrmp_channel_max_total_size_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13090: /* module 51 call 34 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_max_parachain_inbound_channels_V6 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_hrmp_max_parachain_inbound_channels_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13091: /* module 51 call 35 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_max_parathread_inbound_channels_V6 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_hrmp_max_parathread_inbound_channels_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13092: /* module 51 call 36 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_channel_max_message_size_V6 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_hrmp_channel_max_message_size_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13093: /* module 51 call 37 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_max_parachain_outbound_channels_V6 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_hrmp_max_parachain_outbound_channels_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13094: /* module 51 call 38 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_max_parathread_outbound_channels_V6 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_hrmp_max_parathread_outbound_channels_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13095: /* module 51 call 39 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_max_message_num_per_candidate_V6 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_hrmp_max_message_num_per_candidate_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13096: /* module 51 call 40 */
        switch (itemIdx) {
        case 0: /* configuration_set_ump_max_individual_weight_V6 - new_ */;
            return _toStringWeight_V6(
                &m->basic.configuration_set_ump_max_individual_weight_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13824: /* module 54 call 0 */
        switch (itemIdx) {
        case 0: /* parainherent_enter_V6 - data */;
            return _toStringParachainsInherentData_V6(
                &m->basic.parainherent_enter_V6.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14336: /* module 56 call 0 */
        switch (itemIdx) {
        case 0: /* paras_force_set_current_code_V6 - para */;
            return _toStringParaId_V6(
                &m->basic.paras_force_set_current_code_V6.para,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* paras_force_set_current_code_V6 - new_code */;
            return _toStringValidationCode_V6(
                &m->basic.paras_force_set_current_code_V6.new_code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14337: /* module 56 call 1 */
        switch (itemIdx) {
        case 0: /* paras_force_set_current_head_V6 - para */;
            return _toStringParaId_V6(
                &m->basic.paras_force_set_current_head_V6.para,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* paras_force_set_current_head_V6 - new_head */;
            return _toStringHeadData_V6(
                &m->basic.paras_force_set_current_head_V6.new_head,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14338: /* module 56 call 2 */
        switch (itemIdx) {
        case 0: /* paras_force_schedule_code_upgrade_V6 - para */;
            return _toStringParaId_V6(
                &m->basic.paras_force_schedule_code_upgrade_V6.para,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* paras_force_schedule_code_upgrade_V6 - new_code */;
            return _toStringValidationCode_V6(
                &m->basic.paras_force_schedule_code_upgrade_V6.new_code,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* paras_force_schedule_code_upgrade_V6 - relay_parent_number */;
            return _toStringBlockNumber(
                &m->basic.paras_force_schedule_code_upgrade_V6.relay_parent_number,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14339: /* module 56 call 3 */
        switch (itemIdx) {
        case 0: /* paras_force_note_new_head_V6 - para */;
            return _toStringParaId_V6(
                &m->basic.paras_force_note_new_head_V6.para,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* paras_force_note_new_head_V6 - new_head */;
            return _toStringHeadData_V6(
                &m->basic.paras_force_note_new_head_V6.new_head,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14340: /* module 56 call 4 */
        switch (itemIdx) {
        case 0: /* paras_force_queue_action_V6 - para */;
            return _toStringParaId_V6(
                &m->basic.paras_force_queue_action_V6.para,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14592: /* module 57 call 0 */
        switch (itemIdx) {
        case 0: /* initializer_force_approve_V6 - up_to */;
            return _toStringBlockNumber(
                &m->basic.initializer_force_approve_V6.up_to,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15104: /* module 59 call 0 */
        switch (itemIdx) {
        case 0: /* ump_service_overweight_V6 - index */;
            return _toStringOverweightIndex_V6(
                &m->basic.ump_service_overweight_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* ump_service_overweight_V6 - weight_limit */;
            return _toStringWeight_V6(
                &m->basic.ump_service_overweight_V6.weight_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15360: /* module 60 call 0 */
        switch (itemIdx) {
        case 0: /* hrmp_hrmp_init_open_channel_V6 - recipient */;
            return _toStringParaId_V6(
                &m->basic.hrmp_hrmp_init_open_channel_V6.recipient,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* hrmp_hrmp_init_open_channel_V6 - proposed_max_capacity */;
            return _toStringu32(
                &m->basic.hrmp_hrmp_init_open_channel_V6.proposed_max_capacity,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* hrmp_hrmp_init_open_channel_V6 - proposed_max_message_size */;
            return _toStringu32(
                &m->basic.hrmp_hrmp_init_open_channel_V6.proposed_max_message_size,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15361: /* module 60 call 1 */
        switch (itemIdx) {
        case 0: /* hrmp_hrmp_accept_open_channel_V6 - sender */;
            return _toStringParaId_V6(
                &m->basic.hrmp_hrmp_accept_open_channel_V6.sender,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15362: /* module 60 call 2 */
        switch (itemIdx) {
        case 0: /* hrmp_hrmp_close_channel_V6 - channel_id */;
            return _toStringHrmpChannelId_V6(
                &m->basic.hrmp_hrmp_close_channel_V6.channel_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15363: /* module 60 call 3 */
        switch (itemIdx) {
        case 0: /* hrmp_force_clean_hrmp_V6 - para */;
            return _toStringParaId_V6(
                &m->basic.hrmp_force_clean_hrmp_V6.para,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15364: /* module 60 call 4 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 15365: /* module 60 call 5 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 15366: /* module 60 call 6 */
        switch (itemIdx) {
        case 0: /* hrmp_hrmp_cancel_open_request_V6 - channel_id */;
            return _toStringHrmpChannelId_V6(
                &m->basic.hrmp_hrmp_cancel_open_request_V6.channel_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 17920: /* module 70 call 0 */
        switch (itemIdx) {
        case 0: /* registrar_register_V6 - id */;
            return _toStringParaId_V6(
                &m->basic.registrar_register_V6.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* registrar_register_V6 - genesis_head */;
            return _toStringHeadData_V6(
                &m->basic.registrar_register_V6.genesis_head,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* registrar_register_V6 - validation_code */;
            return _toStringValidationCode_V6(
                &m->basic.registrar_register_V6.validation_code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 17921: /* module 70 call 1 */
        switch (itemIdx) {
        case 0: /* registrar_force_register_V6 - who */;
            return _toStringAccountId_V6(
                &m->basic.registrar_force_register_V6.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* registrar_force_register_V6 - deposit */;
            return _toStringBalanceOf(
                &m->basic.registrar_force_register_V6.deposit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* registrar_force_register_V6 - id */;
            return _toStringParaId_V6(
                &m->basic.registrar_force_register_V6.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* registrar_force_register_V6 - genesis_head */;
            return _toStringHeadData_V6(
                &m->basic.registrar_force_register_V6.genesis_head,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* registrar_force_register_V6 - validation_code */;
            return _toStringValidationCode_V6(
                &m->basic.registrar_force_register_V6.validation_code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 17922: /* module 70 call 2 */
        switch (itemIdx) {
        case 0: /* registrar_deregister_V6 - id */;
            return _toStringParaId_V6(
                &m->basic.registrar_deregister_V6.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 17923: /* module 70 call 3 */
        switch (itemIdx) {
        case 0: /* registrar_swap_V6 - id */;
            return _toStringParaId_V6(
                &m->basic.registrar_swap_V6.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* registrar_swap_V6 - other */;
            return _toStringParaId_V6(
                &m->basic.registrar_swap_V6.other,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 17924: /* module 70 call 4 */
        switch (itemIdx) {
        case 0: /* registrar_force_remove_lock_V6 - para */;
            return _toStringParaId_V6(
                &m->basic.registrar_force_remove_lock_V6.para,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 17925: /* module 70 call 5 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 18176: /* module 71 call 0 */
        switch (itemIdx) {
        case 0: /* slots_force_lease_V6 - para */;
            return _toStringParaId_V6(
                &m->basic.slots_force_lease_V6.para,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* slots_force_lease_V6 - leaser */;
            return _toStringAccountId_V6(
                &m->basic.slots_force_lease_V6.leaser,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* slots_force_lease_V6 - amount */;
            return _toStringBalanceOf(
                &m->basic.slots_force_lease_V6.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* slots_force_lease_V6 - period_begin */;
            return _toStringLeasePeriodOf_V6(
                &m->basic.slots_force_lease_V6.period_begin,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* slots_force_lease_V6 - period_count */;
            return _toStringLeasePeriodOf_V6(
                &m->basic.slots_force_lease_V6.period_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18177: /* module 71 call 1 */
        switch (itemIdx) {
        case 0: /* slots_clear_all_leases_V6 - para */;
            return _toStringParaId_V6(
                &m->basic.slots_clear_all_leases_V6.para,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18178: /* module 71 call 2 */
        switch (itemIdx) {
        case 0: /* slots_trigger_onboard_V6 - para */;
            return _toStringParaId_V6(
                &m->basic.slots_trigger_onboard_V6.para,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18432: /* module 72 call 0 */
        switch (itemIdx) {
        case 0: /* auctions_new_auction_V6 - duration */;
            return _toStringCompactBlockNumber(
                &m->basic.auctions_new_auction_V6.duration,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* auctions_new_auction_V6 - lease_period_index */;
            return _toStringCompactLeasePeriodOf_V6(
                &m->basic.auctions_new_auction_V6.lease_period_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18433: /* module 72 call 1 */
        switch (itemIdx) {
        case 0: /* auctions_bid_V6 - para */;
            return _toStringCompactParaId_V6(
                &m->basic.auctions_bid_V6.para,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* auctions_bid_V6 - auction_index */;
            return _toStringCompactAuctionIndex_V6(
                &m->basic.auctions_bid_V6.auction_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* auctions_bid_V6 - first_slot */;
            return _toStringCompactLeasePeriodOf_V6(
                &m->basic.auctions_bid_V6.first_slot,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* auctions_bid_V6 - last_slot */;
            return _toStringCompactLeasePeriodOf_V6(
                &m->basic.auctions_bid_V6.last_slot,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* auctions_bid_V6 - amount */;
            return _toStringCompactBalanceOf(
                &m->basic.auctions_bid_V6.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18434: /* module 72 call 2 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 18688: /* module 73 call 0 */
        switch (itemIdx) {
        case 0: /* crowdloan_create_V6 - index */;
            return _toStringCompactParaId_V6(
                &m->basic.crowdloan_create_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* crowdloan_create_V6 - cap */;
            return _toStringCompactBalanceOf(
                &m->basic.crowdloan_create_V6.cap,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* crowdloan_create_V6 - first_period */;
            return _toStringCompactLeasePeriodOf_V6(
                &m->basic.crowdloan_create_V6.first_period,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* crowdloan_create_V6 - last_period */;
            return _toStringCompactLeasePeriodOf_V6(
                &m->basic.crowdloan_create_V6.last_period,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* crowdloan_create_V6 - end */;
            return _toStringCompactBlockNumber(
                &m->basic.crowdloan_create_V6.end,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* crowdloan_create_V6 - verifier */;
            return _toStringOptionMultiSigner_V6(
                &m->basic.crowdloan_create_V6.verifier,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18689: /* module 73 call 1 */
        switch (itemIdx) {
        case 0: /* crowdloan_contribute_V6 - index */;
            return _toStringCompactParaId_V6(
                &m->basic.crowdloan_contribute_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* crowdloan_contribute_V6 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.crowdloan_contribute_V6.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* crowdloan_contribute_V6 - signature */;
            return _toStringOptionMultiSignature_V6(
                &m->basic.crowdloan_contribute_V6.signature,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18690: /* module 73 call 2 */
        switch (itemIdx) {
        case 0: /* crowdloan_withdraw_V6 - who */;
            return _toStringAccountId_V6(
                &m->basic.crowdloan_withdraw_V6.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* crowdloan_withdraw_V6 - index */;
            return _toStringCompactParaId_V6(
                &m->basic.crowdloan_withdraw_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18691: /* module 73 call 3 */
        switch (itemIdx) {
        case 0: /* crowdloan_refund_V6 - index */;
            return _toStringCompactParaId_V6(
                &m->basic.crowdloan_refund_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18692: /* module 73 call 4 */
        switch (itemIdx) {
        case 0: /* crowdloan_dissolve_V6 - index */;
            return _toStringCompactParaId_V6(
                &m->basic.crowdloan_dissolve_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18693: /* module 73 call 5 */
        switch (itemIdx) {
        case 0: /* crowdloan_edit_V6 - index */;
            return _toStringCompactParaId_V6(
                &m->basic.crowdloan_edit_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* crowdloan_edit_V6 - cap */;
            return _toStringCompactBalanceOf(
                &m->basic.crowdloan_edit_V6.cap,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* crowdloan_edit_V6 - first_period */;
            return _toStringCompactLeasePeriodOf_V6(
                &m->basic.crowdloan_edit_V6.first_period,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* crowdloan_edit_V6 - last_period */;
            return _toStringCompactLeasePeriodOf_V6(
                &m->basic.crowdloan_edit_V6.last_period,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* crowdloan_edit_V6 - end */;
            return _toStringCompactBlockNumber(
                &m->basic.crowdloan_edit_V6.end,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* crowdloan_edit_V6 - verifier */;
            return _toStringOptionMultiSigner_V6(
                &m->basic.crowdloan_edit_V6.verifier,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18694: /* module 73 call 6 */
        switch (itemIdx) {
        case 0: /* crowdloan_add_memo_V6 - index */;
            return _toStringParaId_V6(
                &m->basic.crowdloan_add_memo_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* crowdloan_add_memo_V6 - memo */;
            return _toStringBytes(
                &m->basic.crowdloan_add_memo_V6.memo,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18695: /* module 73 call 7 */
        switch (itemIdx) {
        case 0: /* crowdloan_poke_V6 - index */;
            return _toStringParaId_V6(
                &m->basic.crowdloan_poke_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 25344: /* module 99 call 0 */
        switch (itemIdx) {
        case 0: /* xcmpallet_send_V6 - dest */;
            return _toStringVersionedMultiLocation_V6(
                &m->basic.xcmpallet_send_V6.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* xcmpallet_send_V6 - message */;
            return _toStringVersionedXcm_V6(
                &m->basic.xcmpallet_send_V6.message,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 25345: /* module 99 call 1 */
        switch (itemIdx) {
        case 0: /* xcmpallet_teleport_assets_V6 - dest */;
            return _toStringVersionedMultiLocation_V6(
                &m->basic.xcmpallet_teleport_assets_V6.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* xcmpallet_teleport_assets_V6 - beneficiary */;
            return _toStringVersionedMultiLocation_V6(
                &m->basic.xcmpallet_teleport_assets_V6.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* xcmpallet_teleport_assets_V6 - assets */;
            return _toStringVersionedMultiAssets_V6(
                &m->basic.xcmpallet_teleport_assets_V6.assets,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* xcmpallet_teleport_assets_V6 - fee_asset_item */;
            return _toStringu32(
                &m->basic.xcmpallet_teleport_assets_V6.fee_asset_item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* xcmpallet_teleport_assets_V6 - dest_weight */;
            return _toStringWeight_V6(
                &m->basic.xcmpallet_teleport_assets_V6.dest_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 25346: /* module 99 call 2 */
        switch (itemIdx) {
        case 0: /* xcmpallet_reserve_transfer_assets_V6 - dest */;
            return _toStringVersionedMultiLocation_V6(
                &m->basic.xcmpallet_reserve_transfer_assets_V6.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* xcmpallet_reserve_transfer_assets_V6 - beneficiary */;
            return _toStringVersionedMultiLocation_V6(
                &m->basic.xcmpallet_reserve_transfer_assets_V6.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* xcmpallet_reserve_transfer_assets_V6 - assets */;
            return _toStringVersionedMultiAssets_V6(
                &m->basic.xcmpallet_reserve_transfer_assets_V6.assets,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* xcmpallet_reserve_transfer_assets_V6 - fee_asset_item */;
            return _toStringu32(
                &m->basic.xcmpallet_reserve_transfer_assets_V6.fee_asset_item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* xcmpallet_reserve_transfer_assets_V6 - dest_weight */;
            return _toStringWeight_V6(
                &m->basic.xcmpallet_reserve_transfer_assets_V6.dest_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 25347: /* module 99 call 3 */
        switch (itemIdx) {
        case 0: /* xcmpallet_execute_V6 - message */;
            return _toStringVersionedXcm_V6(
                &m->basic.xcmpallet_execute_V6.message,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* xcmpallet_execute_V6 - max_weight */;
            return _toStringWeight_V6(
                &m->basic.xcmpallet_execute_V6.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#endif
    default:
        return parser_ok;
    }

    return parser_ok;
}

bool _getMethod_ItemIsExpert_V6(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1539: // Staking:Withdraw Unbonded
        switch (itemIdx) {
        case 0: // Num slashing spans
            return true;
        default:
            return false;
        }
    case 1551: // Staking:Force unstake
        switch (itemIdx) {
        case 1: // Num slashing spans
            return true;
        default:
            return false;
        }
    case 1557: // Staking:Reap stash
        switch (itemIdx) {
        case 1: // Num slashing spans
            return true;
        default:
            return false;
        }

    default:
        return false;
    }
}

bool _getMethod_IsNestingSupported_V6(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 9: // System:Remark with event
    case 256: // Babe:Report equivocation
    case 257: // Babe:Report equivocation unsigned
    case 258: // Babe:Plan config change
    case 512: // Timestamp:Set
    case 768: // Indices:Claim
    case 769: // Indices:Transfer
    case 770: // Indices:Free
    case 771: // Indices:Force transfer
    case 772: // Indices:Freeze
    case 1028: // Balances:Transfer all
    case 1280: // Authorship:Set uncles
    case 1536: // Staking:Bond
    case 1537: // Staking:Bond extra
    case 1538: // Staking:Unbond
    case 1539: // Staking:Withdraw Unbonded
    case 1540: // Staking:Validate
    case 1541: // Staking:Nominate
    case 1542: // Staking:Chill
    case 1543: // Staking:Set payee
    case 1544: // Staking:Set controller
    case 1545: // Staking:Set validator count
    case 1546: // Staking:Increase validator count
    case 1547: // Staking:Scale validator count
    case 1548: // Staking:Force no eras
    case 1549: // Staking:Force new era
    case 1550: // Staking:Set invulnerables
    case 1551: // Staking:Force unstake
    case 1552: // Staking:Force new era always
    case 1553: // Staking:Cancel deferred slash
    case 1554: // Staking:Payout stakers
    case 1555: // Staking:Rebond
    case 1556: // Staking:Set history depth
    case 1557: // Staking:Reap stash
    case 1558: // Staking:Kick
    case 1559: // Staking:Set staking limits
    case 1560: // Staking:Chill other
    case 2048: // Session:Set keys
    case 2049: // Session:Purge keys
    case 2560: // Grandpa:Report equivocation
    case 2561: // Grandpa:Report equivocation unsigned
    case 2562: // Grandpa:Note stalled
    case 2816: // ImOnline:Heartbeat
    case 3328: // Democracy:Propose
    case 3329: // Democracy:Second
    case 3330: // Democracy:Vote
    case 3331: // Democracy:Emergency cancel
    case 3332: // Democracy:External propose
    case 3333: // Democracy:External propose majority
    case 3334: // Democracy:External propose default
    case 3335: // Democracy:Fast track
    case 3336: // Democracy:Veto external
    case 3337: // Democracy:Cancel referendum
    case 3338: // Democracy:Cancel queued
    case 3339: // Democracy:Delegate
    case 3340: // Democracy:Undelegate
    case 3341: // Democracy:Clear public proposals
    case 3342: // Democracy:Note preimage
    case 3343: // Democracy:Note preimage operational
    case 3344: // Democracy:Note imminent preimage
    case 3345: // Democracy:Note imminent preimage operational
    case 3346: // Democracy:Reap preimage
    case 3347: // Democracy:Unlock
    case 3348: // Democracy:Remove vote
    case 3349: // Democracy:Remove other vote
    case 3350: // Democracy:Enact proposal
    case 3351: // Democracy:Blacklist
    case 3352: // Democracy:Cancel proposal
    case 3584: // Council:Set members
    case 3585: // Council:Execute
    case 3586: // Council:Propose
    case 3587: // Council:Vote
    case 3588: // Council:Close
    case 3589: // Council:Disapprove proposal
    case 3840: // TechnicalCommittee:Set members
    case 3841: // TechnicalCommittee:Execute
    case 3842: // TechnicalCommittee:Propose
    case 3843: // TechnicalCommittee:Vote
    case 3844: // TechnicalCommittee:Close
    case 3845: // TechnicalCommittee:Disapprove proposal
    case 4096: // PhragmenElection:Vote
    case 4097: // PhragmenElection:Remove voter
    case 4098: // PhragmenElection:Submit candidacy
    case 4099: // PhragmenElection:Renounce candidacy
    case 4100: // PhragmenElection:Remove member
    case 4101: // PhragmenElection:Clean defunct voters
    case 4352: // TechnicalMembership:Add member
    case 4353: // TechnicalMembership:Remove member
    case 4354: // TechnicalMembership:Swap member
    case 4355: // TechnicalMembership:Reset members
    case 4356: // TechnicalMembership:Change key
    case 4357: // TechnicalMembership:Set prime
    case 4358: // TechnicalMembership:Clear prime
    case 4608: // Treasury:Propose spend
    case 4609: // Treasury:Reject proposal
    case 4610: // Treasury:Approve proposal
    case 4864: // Claims:Claim
    case 4865: // Claims:Mint claim
    case 4866: // Claims:Claim attest
    case 4867: // Claims:Attest
    case 4868: // Claims:Move claim
    case 6144: // Utility:Batch
    case 6145: // Utility:As derivative
    case 6146: // Utility:Batch all
    case 6400: // Identity:Add registrar
    case 6401: // Identity:Set identity
    case 6402: // Identity:Set subs
    case 6403: // Identity:Clear identity
    case 6404: // Identity:Request judgement
    case 6405: // Identity:Cancel request
    case 6406: // Identity:Set fee
    case 6407: // Identity:Set account id
    case 6408: // Identity:Set fields
    case 6409: // Identity:Provide judgement
    case 6410: // Identity:Kill identity
    case 6411: // Identity:Add sub
    case 6412: // Identity:Rename sub
    case 6413: // Identity:Remove sub
    case 6414: // Identity:Quit sub
    case 6656: // Society:Bid
    case 6657: // Society:Unbid
    case 6658: // Society:Vouch
    case 6659: // Society:Unvouch
    case 6660: // Society:Vote
    case 6661: // Society:Defender vote
    case 6662: // Society:Payout
    case 6663: // Society:Found
    case 6664: // Society:Unfound
    case 6665: // Society:Judge suspended member
    case 6666: // Society:Judge suspended candidate
    case 6667: // Society:Set max members
    case 6912: // Recovery:As recovered
    case 6913: // Recovery:Set recovered
    case 6914: // Recovery:Create recovery
    case 6915: // Recovery:Initiate recovery
    case 6916: // Recovery:Vouch recovery
    case 6917: // Recovery:Claim recovery
    case 6918: // Recovery:Close recovery
    case 6919: // Recovery:Remove recovery
    case 6920: // Recovery:Cancel recovered
    case 7168: // Vesting:Vest
    case 7169: // Vesting:Vest other
    case 7170: // Vesting:Vested transfer
    case 7171: // Vesting:Force vested transfer
    case 7424: // Scheduler:Schedule
    case 7425: // Scheduler:Cancel
    case 7426: // Scheduler:Schedule named
    case 7427: // Scheduler:Cancel named
    case 7428: // Scheduler:Schedule after
    case 7429: // Scheduler:Schedule named after
    case 7681: // Proxy:Add proxy
    case 7682: // Proxy:Remove proxy
    case 7683: // Proxy:Remove proxies
    case 7684: // Proxy:Anonymous
    case 7685: // Proxy:Kill anonymous
    case 7686: // Proxy:Announce
    case 7687: // Proxy:Remove announcement
    case 7688: // Proxy:Reject announcement
    case 7689: // Proxy:Proxy announced
    case 8960: // Bounties:Propose bounty
    case 8961: // Bounties:Approve bounty
    case 8962: // Bounties:Propose curator
    case 8963: // Bounties:Unassign curator
    case 8964: // Bounties:Accept curator
    case 8965: // Bounties:Award bounty
    case 8966: // Bounties:Claim bounty
    case 8967: // Bounties:Close bounty
    case 8968: // Bounties:Extend bounty expiry
    case 9216: // Tips:Report awesome
    case 9217: // Tips:Retract tip
    case 9218: // Tips:Tip new
    case 9219: // Tips:Tip
    case 9220: // Tips:Close tip
    case 9221: // Tips:Slash tip
    case 9472: // ElectionProviderMultiPhase:Submit unsigned
    case 9473: // ElectionProviderMultiPhase:Set minimum untrusted score
    case 9474: // ElectionProviderMultiPhase:Set emergency election result
    case 9475: // ElectionProviderMultiPhase:Submit
    case 9728: // Gilt:Place bid
    case 9729: // Gilt:Retract bid
    case 9730: // Gilt:Set target
    case 9731: // Gilt:Thaw
    case 13056: // Configuration:Set validation upgrade frequency
    case 13057: // Configuration:Set validation upgrade delay
    case 13058: // Configuration:Set code retention period
    case 13059: // Configuration:Set max code size
    case 13060: // Configuration:Set max pov size
    case 13061: // Configuration:Set max head data size
    case 13062: // Configuration:Set parathread cores
    case 13063: // Configuration:Set parathread retries
    case 13064: // Configuration:Set group rotation frequency
    case 13065: // Configuration:Set chain availability period
    case 13066: // Configuration:Set thread availability period
    case 13067: // Configuration:Set scheduling lookahead
    case 13068: // Configuration:Set max validators per core
    case 13069: // Configuration:Set max validators
    case 13070: // Configuration:Set dispute period
    case 13071: // Configuration:Set dispute post conclusion acceptance period
    case 13072: // Configuration:Set dispute max spam slots
    case 13073: // Configuration:Set dispute conclusion by time out period
    case 13074: // Configuration:Set no show slots
    case 13075: // Configuration:Set n delay tranches
    case 13076: // Configuration:Set zeroth delay tranche width
    case 13077: // Configuration:Set needed approvals
    case 13078: // Configuration:Set relay vrf modulo samples
    case 13079: // Configuration:Set max upward queue count
    case 13080: // Configuration:Set max upward queue size
    case 13081: // Configuration:Set max downward message size
    case 13082: // Configuration:Set ump service total weight
    case 13083: // Configuration:Set max upward message size
    case 13084: // Configuration:Set max upward message num per candidate
    case 13085: // Configuration:Set hrmp open request ttl
    case 13086: // Configuration:Set hrmp sender deposit
    case 13087: // Configuration:Set hrmp recipient deposit
    case 13088: // Configuration:Set hrmp channel max capacity
    case 13089: // Configuration:Set hrmp channel max total size
    case 13090: // Configuration:Set hrmp max parachain inbound channels
    case 13091: // Configuration:Set hrmp max parathread inbound channels
    case 13092: // Configuration:Set hrmp channel max message size
    case 13093: // Configuration:Set hrmp max parachain outbound channels
    case 13094: // Configuration:Set hrmp max parathread outbound channels
    case 13095: // Configuration:Set hrmp max message num per candidate
    case 13096: // Configuration:Set ump max individual weight
    case 13824: // ParaInherent:Enter
    case 14336: // Paras:Force set current code
    case 14337: // Paras:Force set current head
    case 14338: // Paras:Force schedule code upgrade
    case 14339: // Paras:Force note new head
    case 14340: // Paras:Force queue action
    case 14592: // Initializer:Force approve
    case 15104: // Ump:Service overweight
    case 15360: // Hrmp:Hrmp init open channel
    case 15361: // Hrmp:Hrmp accept open channel
    case 15362: // Hrmp:Hrmp close channel
    case 15363: // Hrmp:Force clean hrmp
    case 15364: // Hrmp:Force process hrmp open
    case 15365: // Hrmp:Force process hrmp close
    case 15366: // Hrmp:Hrmp cancel open request
    case 17920: // Registrar:Register
    case 17921: // Registrar:Force register
    case 17922: // Registrar:Deregister
    case 17923: // Registrar:Swap
    case 17924: // Registrar:Force remove lock
    case 17925: // Registrar:Reserve
    case 18176: // Slots:Force lease
    case 18177: // Slots:Clear all leases
    case 18178: // Slots:Trigger onboard
    case 18432: // Auctions:New auction
    case 18433: // Auctions:Bid
    case 18434: // Auctions:Cancel auction
    case 18688: // Crowdloan:Create
    case 18689: // Crowdloan:Contribute
    case 18690: // Crowdloan:Withdraw
    case 18691: // Crowdloan:Refund
    case 18692: // Crowdloan:Dissolve
    case 18693: // Crowdloan:Edit
    case 18694: // Crowdloan:Add memo
    case 18695: // Crowdloan:Poke
    case 25344: // XcmPallet:Send
    case 25345: // XcmPallet:Teleport assets
    case 25346: // XcmPallet:Reserve transfer assets
    case 25347: // XcmPallet:Execute
        return false;
    default:
        return true;
    }
}
