/*******************************************************************************
 *  (c) 2019 - 2024 Zondax AG
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

#include "substrate_dispatch_V26.h"
#include "substrate_strings.h"
#include "zxmacros.h"
#include <stdint.h>
#ifdef LEDGER_SPECIFIC
#include "bolos_target.h"
#endif

__Z_INLINE parser_error_t _readMethod_balances_transfer_allow_death_V26(
    parser_context_t* c, pd_balances_transfer_allow_death_V26_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_transfer_V26(
    parser_context_t* c, pd_balances_force_transfer_V26_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->source))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_keep_alive_V26(
    parser_context_t* c, pd_balances_transfer_keep_alive_V26_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_all_V26(
    parser_context_t* c, pd_balances_transfer_all_V26_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readbool(c, &m->keep_alive))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_V26(
    parser_context_t* c, pd_staking_bond_V26_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readRewardDestination(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_extra_V26(
    parser_context_t* c, pd_staking_bond_extra_V26_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_unbond_V26(
    parser_context_t* c, pd_staking_unbond_V26_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_withdraw_unbonded_V26(
    parser_context_t* c, pd_staking_withdraw_unbonded_V26_t* m)
{
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_validate_V26(
    parser_context_t* c, pd_staking_validate_V26_t* m)
{
    CHECK_ERROR(_readValidatorPrefs(c, &m->prefs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_nominate_V26(
    parser_context_t* c, pd_staking_nominate_V26_t* m)
{
    CHECK_ERROR(_readVecAccountIdLookupOfT(c, &m->targets))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill_V26(
    parser_context_t* c, pd_staking_chill_V26_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_payee_V26(
    parser_context_t* c, pd_staking_set_payee_V26_t* m)
{
    CHECK_ERROR(_readRewardDestination(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_controller_V26(
    parser_context_t* c, pd_staking_set_controller_V26_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_payout_stakers_V26(
    parser_context_t* c, pd_staking_payout_stakers_V26_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->validator_stash))
    CHECK_ERROR(_readEraIndex(c, &m->era))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_rebond_V26(
    parser_context_t* c, pd_staking_rebond_V26_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_set_keys_V26(
    parser_context_t* c, pd_session_set_keys_V26_t* m)
{
    CHECK_ERROR(_readKeys(c, &m->keys))
    CHECK_ERROR(_readBytes(c, &m->proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_purge_keys_V26(
    parser_context_t* c, pd_session_purge_keys_V26_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_V26(
    parser_context_t* c, pd_utility_batch_V26_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_all_V26(
    parser_context_t* c, pd_utility_batch_all_V26_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_force_batch_V26(
    parser_context_t* c, pd_utility_force_batch_V26_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
__Z_INLINE parser_error_t _readMethod_system_remark_V26(
    parser_context_t* c, pd_system_remark_V26_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_heap_pages_V26(
    parser_context_t* c, pd_system_set_heap_pages_V26_t* m)
{
    CHECK_ERROR(_readu64(c, &m->pages))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_V26(
    parser_context_t* c, pd_system_set_code_V26_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_without_checks_V26(
    parser_context_t* c, pd_system_set_code_without_checks_V26_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_with_event_V26(
    parser_context_t* c, pd_system_remark_with_event_V26_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_authorize_upgrade_V26(
    parser_context_t* c, pd_system_authorize_upgrade_V26_t* m)
{
    CHECK_ERROR(_readHash(c, &m->code_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_authorize_upgrade_without_checks_V26(
    parser_context_t* c, pd_system_authorize_upgrade_without_checks_V26_t* m)
{
    CHECK_ERROR(_readHash(c, &m->code_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_apply_authorized_upgrade_V26(
    parser_context_t* c, pd_system_apply_authorized_upgrade_V26_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_unreserve_V26(
    parser_context_t* c, pd_balances_force_unreserve_V26_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_upgrade_accounts_V26(
    parser_context_t* c, pd_balances_upgrade_accounts_V26_t* m)
{
    CHECK_ERROR(_readVecAccountId(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_set_balance_V26(
    parser_context_t* c, pd_balances_force_set_balance_V26_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->new_free))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_validator_count_V26(
    parser_context_t* c, pd_staking_set_validator_count_V26_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_increase_validator_count_V26(
    parser_context_t* c, pd_staking_increase_validator_count_V26_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->additional))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_scale_validator_count_V26(
    parser_context_t* c, pd_staking_scale_validator_count_V26_t* m)
{
    CHECK_ERROR(_readPercent(c, &m->factor))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_no_eras_V26(
    parser_context_t* c, pd_staking_force_no_eras_V26_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_V26(
    parser_context_t* c, pd_staking_force_new_era_V26_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_invulnerables_V26(
    parser_context_t* c, pd_staking_set_invulnerables_V26_t* m)
{
    CHECK_ERROR(_readVecAccountId(c, &m->invulnerables))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_unstake_V26(
    parser_context_t* c, pd_staking_force_unstake_V26_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_always_V26(
    parser_context_t* c, pd_staking_force_new_era_always_V26_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_cancel_deferred_slash_V26(
    parser_context_t* c, pd_staking_cancel_deferred_slash_V26_t* m)
{
    CHECK_ERROR(_readEraIndex(c, &m->era))
    CHECK_ERROR(_readVecu32(c, &m->slash_indices))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_reap_stash_V26(
    parser_context_t* c, pd_staking_reap_stash_V26_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_kick_V26(
    parser_context_t* c, pd_staking_kick_V26_t* m)
{
    CHECK_ERROR(_readVecAccountIdLookupOfT(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_staking_configs_V26(
    parser_context_t* c, pd_staking_set_staking_configs_V26_t* m)
{
    CHECK_ERROR(_readConfigOpBalanceOfT(c, &m->min_nominator_bond))
    CHECK_ERROR(_readConfigOpBalanceOfT(c, &m->min_validator_bond))
    CHECK_ERROR(_readConfigOpu32(c, &m->max_nominator_count))
    CHECK_ERROR(_readConfigOpu32(c, &m->max_validator_count))
    CHECK_ERROR(_readConfigOpPercent(c, &m->chill_threshold))
    CHECK_ERROR(_readConfigOpPerbill(c, &m->min_commission))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill_other_V26(
    parser_context_t* c, pd_staking_chill_other_V26_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->stash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_apply_min_commission_V26(
    parser_context_t* c, pd_staking_force_apply_min_commission_V26_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->validator_stash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_min_commission_V26(
    parser_context_t* c, pd_staking_set_min_commission_V26_t* m)
{
    CHECK_ERROR(_readPerbill(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_payout_stakers_by_page_V26(
    parser_context_t* c, pd_staking_payout_stakers_by_page_V26_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->validator_stash))
    CHECK_ERROR(_readEraIndex(c, &m->era))
    CHECK_ERROR(_readPage(c, &m->page))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_update_payee_V26(
    parser_context_t* c, pd_staking_update_payee_V26_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->controller))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_propose_spend_V26(
    parser_context_t* c, pd_treasury_propose_spend_V26_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->beneficiary))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_reject_proposal_V26(
    parser_context_t* c, pd_treasury_reject_proposal_V26_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_approve_proposal_V26(
    parser_context_t* c, pd_treasury_approve_proposal_V26_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_spend_local_V26(
    parser_context_t* c, pd_treasury_spend_local_V26_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->beneficiary))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_remove_approval_V26(
    parser_context_t* c, pd_treasury_remove_approval_V26_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_payout_V26(
    parser_context_t* c, pd_treasury_payout_V26_t* m)
{
    CHECK_ERROR(_readSpendIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_check_status_V26(
    parser_context_t* c, pd_treasury_check_status_V26_t* m)
{
    CHECK_ERROR(_readSpendIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_void_spend_V26(
    parser_context_t* c, pd_treasury_void_spend_V26_t* m)
{
    CHECK_ERROR(_readSpendIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_convictionvoting_vote_V26(
    parser_context_t* c, pd_convictionvoting_vote_V26_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->poll_index))
    CHECK_ERROR(_readAccountVote(c, &m->vote))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_convictionvoting_delegate_V26(
    parser_context_t* c, pd_convictionvoting_delegate_V26_t* m)
{
    CHECK_ERROR(_readClassOf(c, &m->class_))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->to))
    CHECK_ERROR(_readConviction(c, &m->conviction))
    CHECK_ERROR(_readBalanceOf(c, &m->balance))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_convictionvoting_undelegate_V26(
    parser_context_t* c, pd_convictionvoting_undelegate_V26_t* m)
{
    CHECK_ERROR(_readClassOf(c, &m->class_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_convictionvoting_unlock_V26(
    parser_context_t* c, pd_convictionvoting_unlock_V26_t* m)
{
    CHECK_ERROR(_readClassOf(c, &m->class_))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_convictionvoting_remove_vote_V26(
    parser_context_t* c, pd_convictionvoting_remove_vote_V26_t* m)
{
    CHECK_ERROR(_readOptionClassOf(c, &m->class_))
    CHECK_ERROR(_readPollIndexOf(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_convictionvoting_remove_other_vote_V26(
    parser_context_t* c, pd_convictionvoting_remove_other_vote_V26_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->target))
    CHECK_ERROR(_readClassOf(c, &m->class_))
    CHECK_ERROR(_readPollIndexOf(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_referenda_submit_V26(
    parser_context_t* c, pd_referenda_submit_V26_t* m)
{
    CHECK_ERROR(_readBoxPalletsOrigin(c, &m->proposal_origin))
    CHECK_ERROR(_readBoundedCallOfT(c, &m->proposal))
    CHECK_ERROR(_readDispatchTimeBlockNumber(c, &m->enactment_moment))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_referenda_place_decision_deposit_V26(
    parser_context_t* c, pd_referenda_place_decision_deposit_V26_t* m)
{
    CHECK_ERROR(_readReferendumIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_referenda_refund_decision_deposit_V26(
    parser_context_t* c, pd_referenda_refund_decision_deposit_V26_t* m)
{
    CHECK_ERROR(_readReferendumIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_referenda_cancel_V26(
    parser_context_t* c, pd_referenda_cancel_V26_t* m)
{
    CHECK_ERROR(_readReferendumIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_referenda_kill_V26(
    parser_context_t* c, pd_referenda_kill_V26_t* m)
{
    CHECK_ERROR(_readReferendumIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_referenda_nudge_referendum_V26(
    parser_context_t* c, pd_referenda_nudge_referendum_V26_t* m)
{
    CHECK_ERROR(_readReferendumIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_referenda_one_fewer_deciding_V26(
    parser_context_t* c, pd_referenda_one_fewer_deciding_V26_t* m)
{
    CHECK_ERROR(_readTrackIdOf(c, &m->track))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_referenda_refund_submission_deposit_V26(
    parser_context_t* c, pd_referenda_refund_submission_deposit_V26_t* m)
{
    CHECK_ERROR(_readReferendumIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_referenda_set_metadata_V26(
    parser_context_t* c, pd_referenda_set_metadata_V26_t* m)
{
    CHECK_ERROR(_readReferendumIndex(c, &m->index))
    CHECK_ERROR(_readOptionHash(c, &m->maybe_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_dispatch_as_V26(
    parser_context_t* c, pd_utility_dispatch_as_V26_t* m)
{
    CHECK_ERROR(_readBoxPalletsOrigin(c, &m->as_origin))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_with_weight_V26(
    parser_context_t* c, pd_utility_with_weight_V26_t* m)
{
    CHECK_ERROR(_readCall(c, &m->call))
    CHECK_ERROR(_readWeight(c, &m->weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_registrar_V26(
    parser_context_t* c, pd_identity_add_registrar_V26_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_identity_V26(
    parser_context_t* c, pd_identity_set_identity_V26_t* m)
{
    CHECK_ERROR(_readIdentityInfo(c, &m->info))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_subs_V26(
    parser_context_t* c, pd_identity_set_subs_V26_t* m)
{
    CHECK_ERROR(_readVecTupleAccountIdData(c, &m->subs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_clear_identity_V26(
    parser_context_t* c, pd_identity_clear_identity_V26_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_request_judgement_V26(
    parser_context_t* c, pd_identity_request_judgement_V26_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->reg_index))
    CHECK_ERROR(_readCompactu128(c, &m->max_fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_cancel_request_V26(
    parser_context_t* c, pd_identity_cancel_request_V26_t* m)
{
    CHECK_ERROR(_readRegistrarIndex(c, &m->reg_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_fee_V26(
    parser_context_t* c, pd_identity_set_fee_V26_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readCompactu128(c, &m->fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_account_id_V26(
    parser_context_t* c, pd_identity_set_account_id_V26_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_provide_judgement_V26(
    parser_context_t* c, pd_identity_provide_judgement_V26_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->reg_index))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->target))
    CHECK_ERROR(_readJudgementBalanceOfT(c, &m->judgement))
    CHECK_ERROR(_readHash(c, &m->identity))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_kill_identity_V26(
    parser_context_t* c, pd_identity_kill_identity_V26_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_sub_V26(
    parser_context_t* c, pd_identity_add_sub_V26_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->sub))
    CHECK_ERROR(_readData(c, &m->data))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_rename_sub_V26(
    parser_context_t* c, pd_identity_rename_sub_V26_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->sub))
    CHECK_ERROR(_readData(c, &m->data))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_remove_sub_V26(
    parser_context_t* c, pd_identity_remove_sub_V26_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->sub))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_quit_sub_V26(
    parser_context_t* c, pd_identity_quit_sub_V26_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_username_authority_V26(
    parser_context_t* c, pd_identity_add_username_authority_V26_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->authority))
    CHECK_ERROR(_readVecu8(c, &m->suffix))
    CHECK_ERROR(_readu32(c, &m->allocation))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_remove_username_authority_V26(
    parser_context_t* c, pd_identity_remove_username_authority_V26_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->authority))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_proxy_V26(
    parser_context_t* c, pd_proxy_proxy_V26_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->real))
    CHECK_ERROR(_readOptionProxyType(c, &m->force_proxy_type))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_add_proxy_V26(
    parser_context_t* c, pd_proxy_add_proxy_V26_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    CHECK_ERROR(_readProxyType(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_proxy_V26(
    parser_context_t* c, pd_proxy_remove_proxy_V26_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    CHECK_ERROR(_readProxyType(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_proxies_V26(
    parser_context_t* c, pd_proxy_remove_proxies_V26_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_create_pure_V26(
    parser_context_t* c, pd_proxy_create_pure_V26_t* m)
{
    CHECK_ERROR(_readProxyType(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    CHECK_ERROR(_readu16(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_kill_pure_V26(
    parser_context_t* c, pd_proxy_kill_pure_V26_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->spawner))
    CHECK_ERROR(_readProxyType(c, &m->proxy_type))
    CHECK_ERROR(_readu16(c, &m->index))
    CHECK_ERROR(_readCompactu32(c, &m->height))
    CHECK_ERROR(_readCompactu32(c, &m->ext_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_proxy_announced_V26(
    parser_context_t* c, pd_proxy_proxy_announced_V26_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->real))
    CHECK_ERROR(_readOptionProxyType(c, &m->force_proxy_type))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_threshold_1_V26(
    parser_context_t* c, pd_multisig_as_multi_threshold_1_V26_t* m)
{
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_V26(
    parser_context_t* c, pd_multisig_as_multi_V26_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint(c, &m->maybe_timepoint))
    CHECK_ERROR(_readCall(c, &m->call))
    CHECK_ERROR(_readWeight(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_approve_as_multi_V26(
    parser_context_t* c, pd_multisig_approve_as_multi_V26_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint(c, &m->maybe_timepoint))
    CHECK_ERROR(_readH256(c, &m->call_hash))
    CHECK_ERROR(_readWeight(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_cancel_as_multi_V26(
    parser_context_t* c, pd_multisig_cancel_as_multi_V26_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readTimepoint(c, &m->timepoint))
    CHECK_ERROR(_readH256(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_propose_bounty_V26(
    parser_context_t* c, pd_bounties_propose_bounty_V26_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readBytes(c, &m->description))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_approve_bounty_V26(
    parser_context_t* c, pd_bounties_approve_bounty_V26_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_propose_curator_V26(
    parser_context_t* c, pd_bounties_propose_curator_V26_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->curator))
    CHECK_ERROR(_readCompactBalance(c, &m->fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_unassign_curator_V26(
    parser_context_t* c, pd_bounties_unassign_curator_V26_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_accept_curator_V26(
    parser_context_t* c, pd_bounties_accept_curator_V26_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_award_bounty_V26(
    parser_context_t* c, pd_bounties_award_bounty_V26_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->beneficiary))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_claim_bounty_V26(
    parser_context_t* c, pd_bounties_claim_bounty_V26_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_close_bounty_V26(
    parser_context_t* c, pd_bounties_close_bounty_V26_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_extend_bounty_expiry_V26(
    parser_context_t* c, pd_bounties_extend_bounty_expiry_V26_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    CHECK_ERROR(_readBytes(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_childbounties_add_child_bounty_V26(
    parser_context_t* c, pd_childbounties_add_child_bounty_V26_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->parent_bounty_id))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readVecu8(c, &m->description))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_childbounties_propose_curator_V26(
    parser_context_t* c, pd_childbounties_propose_curator_V26_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->parent_bounty_id))
    CHECK_ERROR(_readCompactu32(c, &m->child_bounty_id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->curator))
    CHECK_ERROR(_readCompactBalance(c, &m->fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_childbounties_accept_curator_V26(
    parser_context_t* c, pd_childbounties_accept_curator_V26_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->parent_bounty_id))
    CHECK_ERROR(_readCompactu32(c, &m->child_bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_childbounties_unassign_curator_V26(
    parser_context_t* c, pd_childbounties_unassign_curator_V26_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->parent_bounty_id))
    CHECK_ERROR(_readCompactu32(c, &m->child_bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_childbounties_award_child_bounty_V26(
    parser_context_t* c, pd_childbounties_award_child_bounty_V26_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->parent_bounty_id))
    CHECK_ERROR(_readCompactu32(c, &m->child_bounty_id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->beneficiary))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_childbounties_claim_child_bounty_V26(
    parser_context_t* c, pd_childbounties_claim_child_bounty_V26_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->parent_bounty_id))
    CHECK_ERROR(_readCompactu32(c, &m->child_bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_childbounties_close_child_bounty_V26(
    parser_context_t* c, pd_childbounties_close_child_bounty_V26_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->parent_bounty_id))
    CHECK_ERROR(_readCompactu32(c, &m->child_bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fastunstake_register_fast_unstake_V26(
    parser_context_t* c, pd_fastunstake_register_fast_unstake_V26_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fastunstake_deregister_V26(
    parser_context_t* c, pd_fastunstake_deregister_V26_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fastunstake_control_V26(
    parser_context_t* c, pd_fastunstake_control_V26_t* m)
{
    CHECK_ERROR(_readEraIndex(c, &m->eras_to_check))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_validation_upgrade_cooldown_V26(
    parser_context_t* c, pd_configuration_set_validation_upgrade_cooldown_V26_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_validation_upgrade_delay_V26(
    parser_context_t* c, pd_configuration_set_validation_upgrade_delay_V26_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_code_retention_period_V26(
    parser_context_t* c, pd_configuration_set_code_retention_period_V26_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_code_size_V26(
    parser_context_t* c, pd_configuration_set_max_code_size_V26_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_pov_size_V26(
    parser_context_t* c, pd_configuration_set_max_pov_size_V26_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_head_data_size_V26(
    parser_context_t* c, pd_configuration_set_max_head_data_size_V26_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_coretime_cores_V26(
    parser_context_t* c, pd_configuration_set_coretime_cores_V26_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_on_demand_retries_V26(
    parser_context_t* c, pd_configuration_set_on_demand_retries_V26_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_group_rotation_frequency_V26(
    parser_context_t* c, pd_configuration_set_group_rotation_frequency_V26_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_paras_availability_period_V26(
    parser_context_t* c, pd_configuration_set_paras_availability_period_V26_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_scheduling_lookahead_V26(
    parser_context_t* c, pd_configuration_set_scheduling_lookahead_V26_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_validators_per_core_V26(
    parser_context_t* c, pd_configuration_set_max_validators_per_core_V26_t* m)
{
    CHECK_ERROR(_readOptionu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_validators_V26(
    parser_context_t* c, pd_configuration_set_max_validators_V26_t* m)
{
    CHECK_ERROR(_readOptionu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_dispute_period_V26(
    parser_context_t* c, pd_configuration_set_dispute_period_V26_t* m)
{
    CHECK_ERROR(_readSessionIndex(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_dispute_post_conclusion_acceptance_period_V26(
    parser_context_t* c, pd_configuration_set_dispute_post_conclusion_acceptance_period_V26_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_no_show_slots_V26(
    parser_context_t* c, pd_configuration_set_no_show_slots_V26_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_n_delay_tranches_V26(
    parser_context_t* c, pd_configuration_set_n_delay_tranches_V26_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_zeroth_delay_tranche_width_V26(
    parser_context_t* c, pd_configuration_set_zeroth_delay_tranche_width_V26_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_needed_approvals_V26(
    parser_context_t* c, pd_configuration_set_needed_approvals_V26_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_relay_vrf_modulo_samples_V26(
    parser_context_t* c, pd_configuration_set_relay_vrf_modulo_samples_V26_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_upward_queue_count_V26(
    parser_context_t* c, pd_configuration_set_max_upward_queue_count_V26_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_upward_queue_size_V26(
    parser_context_t* c, pd_configuration_set_max_upward_queue_size_V26_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_downward_message_size_V26(
    parser_context_t* c, pd_configuration_set_max_downward_message_size_V26_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_upward_message_size_V26(
    parser_context_t* c, pd_configuration_set_max_upward_message_size_V26_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_upward_message_num_per_candidate_V26(
    parser_context_t* c, pd_configuration_set_max_upward_message_num_per_candidate_V26_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_open_request_ttl_V26(
    parser_context_t* c, pd_configuration_set_hrmp_open_request_ttl_V26_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_sender_deposit_V26(
    parser_context_t* c, pd_configuration_set_hrmp_sender_deposit_V26_t* m)
{
    CHECK_ERROR(_readBalance(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_recipient_deposit_V26(
    parser_context_t* c, pd_configuration_set_hrmp_recipient_deposit_V26_t* m)
{
    CHECK_ERROR(_readBalance(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_channel_max_capacity_V26(
    parser_context_t* c, pd_configuration_set_hrmp_channel_max_capacity_V26_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_channel_max_total_size_V26(
    parser_context_t* c, pd_configuration_set_hrmp_channel_max_total_size_V26_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_max_parachain_inbound_channels_V26(
    parser_context_t* c, pd_configuration_set_hrmp_max_parachain_inbound_channels_V26_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_channel_max_message_size_V26(
    parser_context_t* c, pd_configuration_set_hrmp_channel_max_message_size_V26_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_max_parachain_outbound_channels_V26(
    parser_context_t* c, pd_configuration_set_hrmp_max_parachain_outbound_channels_V26_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_max_message_num_per_candidate_V26(
    parser_context_t* c, pd_configuration_set_hrmp_max_message_num_per_candidate_V26_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_pvf_voting_ttl_V26(
    parser_context_t* c, pd_configuration_set_pvf_voting_ttl_V26_t* m)
{
    CHECK_ERROR(_readSessionIndex(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_minimum_validation_upgrade_delay_V26(
    parser_context_t* c, pd_configuration_set_minimum_validation_upgrade_delay_V26_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_bypass_consistency_check_V26(
    parser_context_t* c, pd_configuration_set_bypass_consistency_check_V26_t* m)
{
    CHECK_ERROR(_readbool(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_on_demand_base_fee_V26(
    parser_context_t* c, pd_configuration_set_on_demand_base_fee_V26_t* m)
{
    CHECK_ERROR(_readBalance(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_on_demand_fee_variability_V26(
    parser_context_t* c, pd_configuration_set_on_demand_fee_variability_V26_t* m)
{
    CHECK_ERROR(_readPerbill(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_on_demand_queue_max_size_V26(
    parser_context_t* c, pd_configuration_set_on_demand_queue_max_size_V26_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_on_demand_target_queue_utilization_V26(
    parser_context_t* c, pd_configuration_set_on_demand_target_queue_utilization_V26_t* m)
{
    CHECK_ERROR(_readPerbill(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_on_demand_ttl_V26(
    parser_context_t* c, pd_configuration_set_on_demand_ttl_V26_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_minimum_backing_votes_V26(
    parser_context_t* c, pd_configuration_set_minimum_backing_votes_V26_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_node_feature_V26(
    parser_context_t* c, pd_configuration_set_node_feature_V26_t* m)
{
    CHECK_ERROR(_readu8(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->value))
    return parser_ok;
}

#endif

parser_error_t _readMethod_V26(
    parser_context_t* c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_Method_V26_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

    case 1024: /* module 4 call 0 */
        CHECK_ERROR(_readMethod_balances_transfer_allow_death_V26(c, &method->nested.balances_transfer_allow_death_V26))
        break;
    case 1026: /* module 4 call 2 */
        CHECK_ERROR(_readMethod_balances_force_transfer_V26(c, &method->nested.balances_force_transfer_V26))
        break;
    case 1027: /* module 4 call 3 */
        CHECK_ERROR(_readMethod_balances_transfer_keep_alive_V26(c, &method->nested.balances_transfer_keep_alive_V26))
        break;
    case 1028: /* module 4 call 4 */
        CHECK_ERROR(_readMethod_balances_transfer_all_V26(c, &method->nested.balances_transfer_all_V26))
        break;
    case 1536: /* module 6 call 0 */
        CHECK_ERROR(_readMethod_staking_bond_V26(c, &method->nested.staking_bond_V26))
        break;
    case 1537: /* module 6 call 1 */
        CHECK_ERROR(_readMethod_staking_bond_extra_V26(c, &method->nested.staking_bond_extra_V26))
        break;
    case 1538: /* module 6 call 2 */
        CHECK_ERROR(_readMethod_staking_unbond_V26(c, &method->nested.staking_unbond_V26))
        break;
    case 1539: /* module 6 call 3 */
        CHECK_ERROR(_readMethod_staking_withdraw_unbonded_V26(c, &method->nested.staking_withdraw_unbonded_V26))
        break;
    case 1540: /* module 6 call 4 */
        CHECK_ERROR(_readMethod_staking_validate_V26(c, &method->nested.staking_validate_V26))
        break;
    case 1541: /* module 6 call 5 */
        CHECK_ERROR(_readMethod_staking_nominate_V26(c, &method->nested.staking_nominate_V26))
        break;
    case 1542: /* module 6 call 6 */
        CHECK_ERROR(_readMethod_staking_chill_V26(c, &method->nested.staking_chill_V26))
        break;
    case 1543: /* module 6 call 7 */
        CHECK_ERROR(_readMethod_staking_set_payee_V26(c, &method->nested.staking_set_payee_V26))
        break;
    case 1544: /* module 6 call 8 */
        CHECK_ERROR(_readMethod_staking_set_controller_V26(c, &method->nested.staking_set_controller_V26))
        break;
    case 1554: /* module 6 call 18 */
        CHECK_ERROR(_readMethod_staking_payout_stakers_V26(c, &method->nested.staking_payout_stakers_V26))
        break;
    case 1555: /* module 6 call 19 */
        CHECK_ERROR(_readMethod_staking_rebond_V26(c, &method->nested.staking_rebond_V26))
        break;
    case 2048: /* module 8 call 0 */
        CHECK_ERROR(_readMethod_session_set_keys_V26(c, &method->nested.session_set_keys_V26))
        break;
    case 2049: /* module 8 call 1 */
        CHECK_ERROR(_readMethod_session_purge_keys_V26(c, &method->nested.session_purge_keys_V26))
        break;
    case 6144: /* module 24 call 0 */
        CHECK_ERROR(_readMethod_utility_batch_V26(c, &method->basic.utility_batch_V26))
        break;
    case 6146: /* module 24 call 2 */
        CHECK_ERROR(_readMethod_utility_batch_all_V26(c, &method->basic.utility_batch_all_V26))
        break;
    case 6148: /* module 24 call 4 */
        CHECK_ERROR(_readMethod_utility_force_batch_V26(c, &method->basic.utility_force_batch_V26))
        break;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    case 0: /* module 0 call 0 */
        CHECK_ERROR(_readMethod_system_remark_V26(c, &method->nested.system_remark_V26))
        break;
    case 1: /* module 0 call 1 */
        CHECK_ERROR(_readMethod_system_set_heap_pages_V26(c, &method->nested.system_set_heap_pages_V26))
        break;
    case 2: /* module 0 call 2 */
        CHECK_ERROR(_readMethod_system_set_code_V26(c, &method->nested.system_set_code_V26))
        break;
    case 3: /* module 0 call 3 */
        CHECK_ERROR(_readMethod_system_set_code_without_checks_V26(c, &method->nested.system_set_code_without_checks_V26))
        break;
    case 7: /* module 0 call 7 */
        CHECK_ERROR(_readMethod_system_remark_with_event_V26(c, &method->nested.system_remark_with_event_V26))
        break;
    case 9: /* module 0 call 9 */
        CHECK_ERROR(_readMethod_system_authorize_upgrade_V26(c, &method->basic.system_authorize_upgrade_V26))
        break;
    case 10: /* module 0 call 10 */
        CHECK_ERROR(_readMethod_system_authorize_upgrade_without_checks_V26(c, &method->basic.system_authorize_upgrade_without_checks_V26))
        break;
    case 11: /* module 0 call 11 */
        CHECK_ERROR(_readMethod_system_apply_authorized_upgrade_V26(c, &method->basic.system_apply_authorized_upgrade_V26))
        break;
    case 1029: /* module 4 call 5 */
        CHECK_ERROR(_readMethod_balances_force_unreserve_V26(c, &method->basic.balances_force_unreserve_V26))
        break;
    case 1030: /* module 4 call 6 */
        CHECK_ERROR(_readMethod_balances_upgrade_accounts_V26(c, &method->basic.balances_upgrade_accounts_V26))
        break;
    case 1032: /* module 4 call 8 */
        CHECK_ERROR(_readMethod_balances_force_set_balance_V26(c, &method->basic.balances_force_set_balance_V26))
        break;
    case 1545: /* module 6 call 9 */
        CHECK_ERROR(_readMethod_staking_set_validator_count_V26(c, &method->basic.staking_set_validator_count_V26))
        break;
    case 1546: /* module 6 call 10 */
        CHECK_ERROR(_readMethod_staking_increase_validator_count_V26(c, &method->basic.staking_increase_validator_count_V26))
        break;
    case 1547: /* module 6 call 11 */
        CHECK_ERROR(_readMethod_staking_scale_validator_count_V26(c, &method->basic.staking_scale_validator_count_V26))
        break;
    case 1548: /* module 6 call 12 */
        CHECK_ERROR(_readMethod_staking_force_no_eras_V26(c, &method->basic.staking_force_no_eras_V26))
        break;
    case 1549: /* module 6 call 13 */
        CHECK_ERROR(_readMethod_staking_force_new_era_V26(c, &method->basic.staking_force_new_era_V26))
        break;
    case 1550: /* module 6 call 14 */
        CHECK_ERROR(_readMethod_staking_set_invulnerables_V26(c, &method->basic.staking_set_invulnerables_V26))
        break;
    case 1551: /* module 6 call 15 */
        CHECK_ERROR(_readMethod_staking_force_unstake_V26(c, &method->basic.staking_force_unstake_V26))
        break;
    case 1552: /* module 6 call 16 */
        CHECK_ERROR(_readMethod_staking_force_new_era_always_V26(c, &method->basic.staking_force_new_era_always_V26))
        break;
    case 1553: /* module 6 call 17 */
        CHECK_ERROR(_readMethod_staking_cancel_deferred_slash_V26(c, &method->basic.staking_cancel_deferred_slash_V26))
        break;
    case 1556: /* module 6 call 20 */
        CHECK_ERROR(_readMethod_staking_reap_stash_V26(c, &method->basic.staking_reap_stash_V26))
        break;
    case 1557: /* module 6 call 21 */
        CHECK_ERROR(_readMethod_staking_kick_V26(c, &method->basic.staking_kick_V26))
        break;
    case 1558: /* module 6 call 22 */
        CHECK_ERROR(_readMethod_staking_set_staking_configs_V26(c, &method->basic.staking_set_staking_configs_V26))
        break;
    case 1559: /* module 6 call 23 */
        CHECK_ERROR(_readMethod_staking_chill_other_V26(c, &method->basic.staking_chill_other_V26))
        break;
    case 1560: /* module 6 call 24 */
        CHECK_ERROR(_readMethod_staking_force_apply_min_commission_V26(c, &method->basic.staking_force_apply_min_commission_V26))
        break;
    case 1561: /* module 6 call 25 */
        CHECK_ERROR(_readMethod_staking_set_min_commission_V26(c, &method->basic.staking_set_min_commission_V26))
        break;
    case 1562: /* module 6 call 26 */
        CHECK_ERROR(_readMethod_staking_payout_stakers_by_page_V26(c, &method->basic.staking_payout_stakers_by_page_V26))
        break;
    case 1563: /* module 6 call 27 */
        CHECK_ERROR(_readMethod_staking_update_payee_V26(c, &method->basic.staking_update_payee_V26))
        break;
    case 4608: /* module 18 call 0 */
        CHECK_ERROR(_readMethod_treasury_propose_spend_V26(c, &method->basic.treasury_propose_spend_V26))
        break;
    case 4609: /* module 18 call 1 */
        CHECK_ERROR(_readMethod_treasury_reject_proposal_V26(c, &method->basic.treasury_reject_proposal_V26))
        break;
    case 4610: /* module 18 call 2 */
        CHECK_ERROR(_readMethod_treasury_approve_proposal_V26(c, &method->basic.treasury_approve_proposal_V26))
        break;
    case 4611: /* module 18 call 3 */
        CHECK_ERROR(_readMethod_treasury_spend_local_V26(c, &method->basic.treasury_spend_local_V26))
        break;
    case 4612: /* module 18 call 4 */
        CHECK_ERROR(_readMethod_treasury_remove_approval_V26(c, &method->basic.treasury_remove_approval_V26))
        break;
    case 4614: /* module 18 call 6 */
        CHECK_ERROR(_readMethod_treasury_payout_V26(c, &method->basic.treasury_payout_V26))
        break;
    case 4615: /* module 18 call 7 */
        CHECK_ERROR(_readMethod_treasury_check_status_V26(c, &method->basic.treasury_check_status_V26))
        break;
    case 4616: /* module 18 call 8 */
        CHECK_ERROR(_readMethod_treasury_void_spend_V26(c, &method->basic.treasury_void_spend_V26))
        break;
    case 5120: /* module 20 call 0 */
        CHECK_ERROR(_readMethod_convictionvoting_vote_V26(c, &method->nested.convictionvoting_vote_V26))
        break;
    case 5121: /* module 20 call 1 */
        CHECK_ERROR(_readMethod_convictionvoting_delegate_V26(c, &method->nested.convictionvoting_delegate_V26))
        break;
    case 5122: /* module 20 call 2 */
        CHECK_ERROR(_readMethod_convictionvoting_undelegate_V26(c, &method->nested.convictionvoting_undelegate_V26))
        break;
    case 5123: /* module 20 call 3 */
        CHECK_ERROR(_readMethod_convictionvoting_unlock_V26(c, &method->nested.convictionvoting_unlock_V26))
        break;
    case 5124: /* module 20 call 4 */
        CHECK_ERROR(_readMethod_convictionvoting_remove_vote_V26(c, &method->nested.convictionvoting_remove_vote_V26))
        break;
    case 5125: /* module 20 call 5 */
        CHECK_ERROR(_readMethod_convictionvoting_remove_other_vote_V26(c, &method->nested.convictionvoting_remove_other_vote_V26))
        break;
    case 5376: /* module 21 call 0 */
        CHECK_ERROR(_readMethod_referenda_submit_V26(c, &method->basic.referenda_submit_V26))
        break;
    case 5377: /* module 21 call 1 */
        CHECK_ERROR(_readMethod_referenda_place_decision_deposit_V26(c, &method->basic.referenda_place_decision_deposit_V26))
        break;
    case 5378: /* module 21 call 2 */
        CHECK_ERROR(_readMethod_referenda_refund_decision_deposit_V26(c, &method->basic.referenda_refund_decision_deposit_V26))
        break;
    case 5379: /* module 21 call 3 */
        CHECK_ERROR(_readMethod_referenda_cancel_V26(c, &method->basic.referenda_cancel_V26))
        break;
    case 5380: /* module 21 call 4 */
        CHECK_ERROR(_readMethod_referenda_kill_V26(c, &method->basic.referenda_kill_V26))
        break;
    case 5381: /* module 21 call 5 */
        CHECK_ERROR(_readMethod_referenda_nudge_referendum_V26(c, &method->basic.referenda_nudge_referendum_V26))
        break;
    case 5382: /* module 21 call 6 */
        CHECK_ERROR(_readMethod_referenda_one_fewer_deciding_V26(c, &method->basic.referenda_one_fewer_deciding_V26))
        break;
    case 5383: /* module 21 call 7 */
        CHECK_ERROR(_readMethod_referenda_refund_submission_deposit_V26(c, &method->basic.referenda_refund_submission_deposit_V26))
        break;
    case 5384: /* module 21 call 8 */
        CHECK_ERROR(_readMethod_referenda_set_metadata_V26(c, &method->basic.referenda_set_metadata_V26))
        break;
    case 6147: /* module 24 call 3 */
        CHECK_ERROR(_readMethod_utility_dispatch_as_V26(c, &method->basic.utility_dispatch_as_V26))
        break;
    case 6149: /* module 24 call 5 */
        CHECK_ERROR(_readMethod_utility_with_weight_V26(c, &method->basic.utility_with_weight_V26))
        break;
    case 6400: /* module 25 call 0 */
        CHECK_ERROR(_readMethod_identity_add_registrar_V26(c, &method->basic.identity_add_registrar_V26))
        break;
    case 6401: /* module 25 call 1 */
        CHECK_ERROR(_readMethod_identity_set_identity_V26(c, &method->basic.identity_set_identity_V26))
        break;
    case 6402: /* module 25 call 2 */
        CHECK_ERROR(_readMethod_identity_set_subs_V26(c, &method->basic.identity_set_subs_V26))
        break;
    case 6403: /* module 25 call 3 */
        CHECK_ERROR(_readMethod_identity_clear_identity_V26(c, &method->basic.identity_clear_identity_V26))
        break;
    case 6404: /* module 25 call 4 */
        CHECK_ERROR(_readMethod_identity_request_judgement_V26(c, &method->basic.identity_request_judgement_V26))
        break;
    case 6405: /* module 25 call 5 */
        CHECK_ERROR(_readMethod_identity_cancel_request_V26(c, &method->basic.identity_cancel_request_V26))
        break;
    case 6406: /* module 25 call 6 */
        CHECK_ERROR(_readMethod_identity_set_fee_V26(c, &method->basic.identity_set_fee_V26))
        break;
    case 6407: /* module 25 call 7 */
        CHECK_ERROR(_readMethod_identity_set_account_id_V26(c, &method->basic.identity_set_account_id_V26))
        break;
    case 6409: /* module 25 call 9 */
        CHECK_ERROR(_readMethod_identity_provide_judgement_V26(c, &method->basic.identity_provide_judgement_V26))
        break;
    case 6410: /* module 25 call 10 */
        CHECK_ERROR(_readMethod_identity_kill_identity_V26(c, &method->basic.identity_kill_identity_V26))
        break;
    case 6411: /* module 25 call 11 */
        CHECK_ERROR(_readMethod_identity_add_sub_V26(c, &method->basic.identity_add_sub_V26))
        break;
    case 6412: /* module 25 call 12 */
        CHECK_ERROR(_readMethod_identity_rename_sub_V26(c, &method->basic.identity_rename_sub_V26))
        break;
    case 6413: /* module 25 call 13 */
        CHECK_ERROR(_readMethod_identity_remove_sub_V26(c, &method->basic.identity_remove_sub_V26))
        break;
    case 6414: /* module 25 call 14 */
        CHECK_ERROR(_readMethod_identity_quit_sub_V26(c, &method->basic.identity_quit_sub_V26))
        break;
    case 6415: /* module 25 call 15 */
        CHECK_ERROR(_readMethod_identity_add_username_authority_V26(c, &method->basic.identity_add_username_authority_V26))
        break;
    case 6416: /* module 25 call 16 */
        CHECK_ERROR(_readMethod_identity_remove_username_authority_V26(c, &method->basic.identity_remove_username_authority_V26))
        break;
    case 7680: /* module 30 call 0 */
        CHECK_ERROR(_readMethod_proxy_proxy_V26(c, &method->nested.proxy_proxy_V26))
        break;
    case 7681: /* module 30 call 1 */
        CHECK_ERROR(_readMethod_proxy_add_proxy_V26(c, &method->nested.proxy_add_proxy_V26))
        break;
    case 7682: /* module 30 call 2 */
        CHECK_ERROR(_readMethod_proxy_remove_proxy_V26(c, &method->nested.proxy_remove_proxy_V26))
        break;
    case 7683: /* module 30 call 3 */
        CHECK_ERROR(_readMethod_proxy_remove_proxies_V26(c, &method->basic.proxy_remove_proxies_V26))
        break;
    case 7684: /* module 30 call 4 */
        CHECK_ERROR(_readMethod_proxy_create_pure_V26(c, &method->nested.proxy_create_pure_V26))
        break;
    case 7685: /* module 30 call 5 */
        CHECK_ERROR(_readMethod_proxy_kill_pure_V26(c, &method->nested.proxy_kill_pure_V26))
        break;
    case 7689: /* module 30 call 9 */
        CHECK_ERROR(_readMethod_proxy_proxy_announced_V26(c, &method->basic.proxy_proxy_announced_V26))
        break;
    case 7936: /* module 31 call 0 */
        CHECK_ERROR(_readMethod_multisig_as_multi_threshold_1_V26(c, &method->nested.multisig_as_multi_threshold_1_V26))
        break;
    case 7937: /* module 31 call 1 */
        CHECK_ERROR(_readMethod_multisig_as_multi_V26(c, &method->nested.multisig_as_multi_V26))
        break;
    case 7938: /* module 31 call 2 */
        CHECK_ERROR(_readMethod_multisig_approve_as_multi_V26(c, &method->nested.multisig_approve_as_multi_V26))
        break;
    case 7939: /* module 31 call 3 */
        CHECK_ERROR(_readMethod_multisig_cancel_as_multi_V26(c, &method->nested.multisig_cancel_as_multi_V26))
        break;
    case 8960: /* module 35 call 0 */
        CHECK_ERROR(_readMethod_bounties_propose_bounty_V26(c, &method->basic.bounties_propose_bounty_V26))
        break;
    case 8961: /* module 35 call 1 */
        CHECK_ERROR(_readMethod_bounties_approve_bounty_V26(c, &method->basic.bounties_approve_bounty_V26))
        break;
    case 8962: /* module 35 call 2 */
        CHECK_ERROR(_readMethod_bounties_propose_curator_V26(c, &method->basic.bounties_propose_curator_V26))
        break;
    case 8963: /* module 35 call 3 */
        CHECK_ERROR(_readMethod_bounties_unassign_curator_V26(c, &method->basic.bounties_unassign_curator_V26))
        break;
    case 8964: /* module 35 call 4 */
        CHECK_ERROR(_readMethod_bounties_accept_curator_V26(c, &method->basic.bounties_accept_curator_V26))
        break;
    case 8965: /* module 35 call 5 */
        CHECK_ERROR(_readMethod_bounties_award_bounty_V26(c, &method->basic.bounties_award_bounty_V26))
        break;
    case 8966: /* module 35 call 6 */
        CHECK_ERROR(_readMethod_bounties_claim_bounty_V26(c, &method->basic.bounties_claim_bounty_V26))
        break;
    case 8967: /* module 35 call 7 */
        CHECK_ERROR(_readMethod_bounties_close_bounty_V26(c, &method->basic.bounties_close_bounty_V26))
        break;
    case 8968: /* module 35 call 8 */
        CHECK_ERROR(_readMethod_bounties_extend_bounty_expiry_V26(c, &method->basic.bounties_extend_bounty_expiry_V26))
        break;
    case 10240: /* module 40 call 0 */
        CHECK_ERROR(_readMethod_childbounties_add_child_bounty_V26(c, &method->basic.childbounties_add_child_bounty_V26))
        break;
    case 10241: /* module 40 call 1 */
        CHECK_ERROR(_readMethod_childbounties_propose_curator_V26(c, &method->basic.childbounties_propose_curator_V26))
        break;
    case 10242: /* module 40 call 2 */
        CHECK_ERROR(_readMethod_childbounties_accept_curator_V26(c, &method->basic.childbounties_accept_curator_V26))
        break;
    case 10243: /* module 40 call 3 */
        CHECK_ERROR(_readMethod_childbounties_unassign_curator_V26(c, &method->basic.childbounties_unassign_curator_V26))
        break;
    case 10244: /* module 40 call 4 */
        CHECK_ERROR(_readMethod_childbounties_award_child_bounty_V26(c, &method->basic.childbounties_award_child_bounty_V26))
        break;
    case 10245: /* module 40 call 5 */
        CHECK_ERROR(_readMethod_childbounties_claim_child_bounty_V26(c, &method->basic.childbounties_claim_child_bounty_V26))
        break;
    case 10246: /* module 40 call 6 */
        CHECK_ERROR(_readMethod_childbounties_close_child_bounty_V26(c, &method->basic.childbounties_close_child_bounty_V26))
        break;
    case 10752: /* module 42 call 0 */
        CHECK_ERROR(_readMethod_fastunstake_register_fast_unstake_V26(c, &method->nested.fastunstake_register_fast_unstake_V26))
        break;
    case 10753: /* module 42 call 1 */
        CHECK_ERROR(_readMethod_fastunstake_deregister_V26(c, &method->nested.fastunstake_deregister_V26))
        break;
    case 10754: /* module 42 call 2 */
        CHECK_ERROR(_readMethod_fastunstake_control_V26(c, &method->basic.fastunstake_control_V26))
        break;
    case 13056: /* module 51 call 0 */
        CHECK_ERROR(_readMethod_configuration_set_validation_upgrade_cooldown_V26(c, &method->basic.configuration_set_validation_upgrade_cooldown_V26))
        break;
    case 13057: /* module 51 call 1 */
        CHECK_ERROR(_readMethod_configuration_set_validation_upgrade_delay_V26(c, &method->basic.configuration_set_validation_upgrade_delay_V26))
        break;
    case 13058: /* module 51 call 2 */
        CHECK_ERROR(_readMethod_configuration_set_code_retention_period_V26(c, &method->basic.configuration_set_code_retention_period_V26))
        break;
    case 13059: /* module 51 call 3 */
        CHECK_ERROR(_readMethod_configuration_set_max_code_size_V26(c, &method->basic.configuration_set_max_code_size_V26))
        break;
    case 13060: /* module 51 call 4 */
        CHECK_ERROR(_readMethod_configuration_set_max_pov_size_V26(c, &method->basic.configuration_set_max_pov_size_V26))
        break;
    case 13061: /* module 51 call 5 */
        CHECK_ERROR(_readMethod_configuration_set_max_head_data_size_V26(c, &method->basic.configuration_set_max_head_data_size_V26))
        break;
    case 13062: /* module 51 call 6 */
        CHECK_ERROR(_readMethod_configuration_set_coretime_cores_V26(c, &method->basic.configuration_set_coretime_cores_V26))
        break;
    case 13063: /* module 51 call 7 */
        CHECK_ERROR(_readMethod_configuration_set_on_demand_retries_V26(c, &method->basic.configuration_set_on_demand_retries_V26))
        break;
    case 13064: /* module 51 call 8 */
        CHECK_ERROR(_readMethod_configuration_set_group_rotation_frequency_V26(c, &method->basic.configuration_set_group_rotation_frequency_V26))
        break;
    case 13065: /* module 51 call 9 */
        CHECK_ERROR(_readMethod_configuration_set_paras_availability_period_V26(c, &method->basic.configuration_set_paras_availability_period_V26))
        break;
    case 13067: /* module 51 call 11 */
        CHECK_ERROR(_readMethod_configuration_set_scheduling_lookahead_V26(c, &method->basic.configuration_set_scheduling_lookahead_V26))
        break;
    case 13068: /* module 51 call 12 */
        CHECK_ERROR(_readMethod_configuration_set_max_validators_per_core_V26(c, &method->basic.configuration_set_max_validators_per_core_V26))
        break;
    case 13069: /* module 51 call 13 */
        CHECK_ERROR(_readMethod_configuration_set_max_validators_V26(c, &method->basic.configuration_set_max_validators_V26))
        break;
    case 13070: /* module 51 call 14 */
        CHECK_ERROR(_readMethod_configuration_set_dispute_period_V26(c, &method->basic.configuration_set_dispute_period_V26))
        break;
    case 13071: /* module 51 call 15 */
        CHECK_ERROR(_readMethod_configuration_set_dispute_post_conclusion_acceptance_period_V26(c, &method->basic.configuration_set_dispute_post_conclusion_acceptance_period_V26))
        break;
    case 13074: /* module 51 call 18 */
        CHECK_ERROR(_readMethod_configuration_set_no_show_slots_V26(c, &method->basic.configuration_set_no_show_slots_V26))
        break;
    case 13075: /* module 51 call 19 */
        CHECK_ERROR(_readMethod_configuration_set_n_delay_tranches_V26(c, &method->basic.configuration_set_n_delay_tranches_V26))
        break;
    case 13076: /* module 51 call 20 */
        CHECK_ERROR(_readMethod_configuration_set_zeroth_delay_tranche_width_V26(c, &method->basic.configuration_set_zeroth_delay_tranche_width_V26))
        break;
    case 13077: /* module 51 call 21 */
        CHECK_ERROR(_readMethod_configuration_set_needed_approvals_V26(c, &method->basic.configuration_set_needed_approvals_V26))
        break;
    case 13078: /* module 51 call 22 */
        CHECK_ERROR(_readMethod_configuration_set_relay_vrf_modulo_samples_V26(c, &method->basic.configuration_set_relay_vrf_modulo_samples_V26))
        break;
    case 13079: /* module 51 call 23 */
        CHECK_ERROR(_readMethod_configuration_set_max_upward_queue_count_V26(c, &method->basic.configuration_set_max_upward_queue_count_V26))
        break;
    case 13080: /* module 51 call 24 */
        CHECK_ERROR(_readMethod_configuration_set_max_upward_queue_size_V26(c, &method->basic.configuration_set_max_upward_queue_size_V26))
        break;
    case 13081: /* module 51 call 25 */
        CHECK_ERROR(_readMethod_configuration_set_max_downward_message_size_V26(c, &method->basic.configuration_set_max_downward_message_size_V26))
        break;
    case 13083: /* module 51 call 27 */
        CHECK_ERROR(_readMethod_configuration_set_max_upward_message_size_V26(c, &method->basic.configuration_set_max_upward_message_size_V26))
        break;
    case 13084: /* module 51 call 28 */
        CHECK_ERROR(_readMethod_configuration_set_max_upward_message_num_per_candidate_V26(c, &method->basic.configuration_set_max_upward_message_num_per_candidate_V26))
        break;
    case 13085: /* module 51 call 29 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_open_request_ttl_V26(c, &method->basic.configuration_set_hrmp_open_request_ttl_V26))
        break;
    case 13086: /* module 51 call 30 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_sender_deposit_V26(c, &method->basic.configuration_set_hrmp_sender_deposit_V26))
        break;
    case 13087: /* module 51 call 31 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_recipient_deposit_V26(c, &method->basic.configuration_set_hrmp_recipient_deposit_V26))
        break;
    case 13088: /* module 51 call 32 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_channel_max_capacity_V26(c, &method->basic.configuration_set_hrmp_channel_max_capacity_V26))
        break;
    case 13089: /* module 51 call 33 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_channel_max_total_size_V26(c, &method->basic.configuration_set_hrmp_channel_max_total_size_V26))
        break;
    case 13090: /* module 51 call 34 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_max_parachain_inbound_channels_V26(c, &method->basic.configuration_set_hrmp_max_parachain_inbound_channels_V26))
        break;
    case 13092: /* module 51 call 36 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_channel_max_message_size_V26(c, &method->basic.configuration_set_hrmp_channel_max_message_size_V26))
        break;
    case 13093: /* module 51 call 37 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_max_parachain_outbound_channels_V26(c, &method->basic.configuration_set_hrmp_max_parachain_outbound_channels_V26))
        break;
    case 13095: /* module 51 call 39 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_max_message_num_per_candidate_V26(c, &method->basic.configuration_set_hrmp_max_message_num_per_candidate_V26))
        break;
    case 13098: /* module 51 call 42 */
        CHECK_ERROR(_readMethod_configuration_set_pvf_voting_ttl_V26(c, &method->basic.configuration_set_pvf_voting_ttl_V26))
        break;
    case 13099: /* module 51 call 43 */
        CHECK_ERROR(_readMethod_configuration_set_minimum_validation_upgrade_delay_V26(c, &method->basic.configuration_set_minimum_validation_upgrade_delay_V26))
        break;
    case 13100: /* module 51 call 44 */
        CHECK_ERROR(_readMethod_configuration_set_bypass_consistency_check_V26(c, &method->basic.configuration_set_bypass_consistency_check_V26))
        break;
    case 13103: /* module 51 call 47 */
        CHECK_ERROR(_readMethod_configuration_set_on_demand_base_fee_V26(c, &method->basic.configuration_set_on_demand_base_fee_V26))
        break;
    case 13104: /* module 51 call 48 */
        CHECK_ERROR(_readMethod_configuration_set_on_demand_fee_variability_V26(c, &method->basic.configuration_set_on_demand_fee_variability_V26))
        break;
    case 13105: /* module 51 call 49 */
        CHECK_ERROR(_readMethod_configuration_set_on_demand_queue_max_size_V26(c, &method->basic.configuration_set_on_demand_queue_max_size_V26))
        break;
    case 13106: /* module 51 call 50 */
        CHECK_ERROR(_readMethod_configuration_set_on_demand_target_queue_utilization_V26(c, &method->basic.configuration_set_on_demand_target_queue_utilization_V26))
        break;
    case 13107: /* module 51 call 51 */
        CHECK_ERROR(_readMethod_configuration_set_on_demand_ttl_V26(c, &method->basic.configuration_set_on_demand_ttl_V26))
        break;
    case 13108: /* module 51 call 52 */
        CHECK_ERROR(_readMethod_configuration_set_minimum_backing_votes_V26(c, &method->basic.configuration_set_minimum_backing_votes_V26))
        break;
    case 13109: /* module 51 call 53 */
        CHECK_ERROR(_readMethod_configuration_set_node_feature_V26(c, &method->basic.configuration_set_node_feature_V26))
        break;
#endif
    default:
        return parser_unexpected_callIndex;
    }

    return parser_ok;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

const char* _getMethod_ModuleName_V26(uint8_t moduleIdx)
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
#ifndef TARGET_NANOS
#endif
    case 0:
        return STR_MO_SYSTEM;
    case 18:
        return STR_MO_TREASURY;
    case 20:
        return STR_MO_CONVICTIONVOTING;
    case 21:
        return STR_MO_REFERENDA;
    case 25:
        return STR_MO_IDENTITY;
    case 30:
        return STR_MO_PROXY;
    case 31:
        return STR_MO_MULTISIG;
    case 35:
        return STR_MO_BOUNTIES;
    case 40:
        return STR_MO_CHILDBOUNTIES;
    case 42:
        return STR_MO_FASTUNSTAKE;
    case 51:
        return STR_MO_CONFIGURATION;
#endif
    default:
        return NULL;
    }

    return NULL;
}

const char* _getMethod_Name_V26(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1024: /* module 4 call 0 */
        return STR_ME_TRANSFER_ALLOW_DEATH;
    case 1026: /* module 4 call 2 */
        return STR_ME_FORCE_TRANSFER;
    case 1027: /* module 4 call 3 */
        return STR_ME_TRANSFER_KEEP_ALIVE;
    case 1028: /* module 4 call 4 */
        return STR_ME_TRANSFER_ALL;
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
    case 6148: /* module 24 call 4 */
        return STR_ME_FORCE_BATCH;
    default:
        return _getMethod_Name_V26_ParserFull(callPrivIdx);
    }

    return NULL;
}

const char* _getMethod_Name_V26_ParserFull(uint16_t callPrivIdx)
{
    switch (callPrivIdx) {
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    case 0: /* module 0 call 0 */
        return STR_ME_REMARK;
    case 1: /* module 0 call 1 */
        return STR_ME_SET_HEAP_PAGES;
    case 2: /* module 0 call 2 */
        return STR_ME_SET_CODE;
    case 3: /* module 0 call 3 */
        return STR_ME_SET_CODE_WITHOUT_CHECKS;
    case 7: /* module 0 call 7 */
        return STR_ME_REMARK_WITH_EVENT;
    case 9: /* module 0 call 9 */
        return STR_ME_AUTHORIZE_UPGRADE;
    case 10: /* module 0 call 10 */
        return STR_ME_AUTHORIZE_UPGRADE_WITHOUT_CHECKS;
    case 11: /* module 0 call 11 */
        return STR_ME_APPLY_AUTHORIZED_UPGRADE;
    case 1029: /* module 4 call 5 */
        return STR_ME_FORCE_UNRESERVE;
    case 1030: /* module 4 call 6 */
        return STR_ME_UPGRADE_ACCOUNTS;
    case 1032: /* module 4 call 8 */
        return STR_ME_FORCE_SET_BALANCE;
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
        return STR_ME_REAP_STASH;
    case 1557: /* module 6 call 21 */
        return STR_ME_KICK;
    case 1558: /* module 6 call 22 */
        return STR_ME_SET_STAKING_CONFIGS;
    case 1559: /* module 6 call 23 */
        return STR_ME_CHILL_OTHER;
    case 1560: /* module 6 call 24 */
        return STR_ME_FORCE_APPLY_MIN_COMMISSION;
    case 1561: /* module 6 call 25 */
        return STR_ME_SET_MIN_COMMISSION;
    case 1562: /* module 6 call 26 */
        return STR_ME_PAYOUT_STAKERS_BY_PAGE;
    case 1563: /* module 6 call 27 */
        return STR_ME_UPDATE_PAYEE;
    case 4608: /* module 18 call 0 */
        return STR_ME_PROPOSE_SPEND;
    case 4609: /* module 18 call 1 */
        return STR_ME_REJECT_PROPOSAL;
    case 4610: /* module 18 call 2 */
        return STR_ME_APPROVE_PROPOSAL;
    case 4611: /* module 18 call 3 */
        return STR_ME_SPEND_LOCAL;
    case 4612: /* module 18 call 4 */
        return STR_ME_REMOVE_APPROVAL;
    case 4614: /* module 18 call 6 */
        return STR_ME_PAYOUT;
    case 4615: /* module 18 call 7 */
        return STR_ME_CHECK_STATUS;
    case 4616: /* module 18 call 8 */
        return STR_ME_VOID_SPEND;
    case 5120: /* module 20 call 0 */
        return STR_ME_VOTE;
    case 5121: /* module 20 call 1 */
        return STR_ME_DELEGATE;
    case 5122: /* module 20 call 2 */
        return STR_ME_UNDELEGATE;
    case 5123: /* module 20 call 3 */
        return STR_ME_UNLOCK;
    case 5124: /* module 20 call 4 */
        return STR_ME_REMOVE_VOTE;
    case 5125: /* module 20 call 5 */
        return STR_ME_REMOVE_OTHER_VOTE;
    case 5376: /* module 21 call 0 */
        return STR_ME_SUBMIT;
    case 5377: /* module 21 call 1 */
        return STR_ME_PLACE_DECISION_DEPOSIT;
    case 5378: /* module 21 call 2 */
        return STR_ME_REFUND_DECISION_DEPOSIT;
    case 5379: /* module 21 call 3 */
        return STR_ME_CANCEL;
    case 5380: /* module 21 call 4 */
        return STR_ME_KILL;
    case 5381: /* module 21 call 5 */
        return STR_ME_NUDGE_REFERENDUM;
    case 5382: /* module 21 call 6 */
        return STR_ME_ONE_FEWER_DECIDING;
    case 5383: /* module 21 call 7 */
        return STR_ME_REFUND_SUBMISSION_DEPOSIT;
    case 5384: /* module 21 call 8 */
        return STR_ME_SET_METADATA;
    case 6147: /* module 24 call 3 */
        return STR_ME_DISPATCH_AS;
    case 6149: /* module 24 call 5 */
        return STR_ME_WITH_WEIGHT;
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
    case 6415: /* module 25 call 15 */
        return STR_ME_ADD_USERNAME_AUTHORITY;
    case 6416: /* module 25 call 16 */
        return STR_ME_REMOVE_USERNAME_AUTHORITY;
    case 7680: /* module 30 call 0 */
        return STR_ME_PROXY;
    case 7681: /* module 30 call 1 */
        return STR_ME_ADD_PROXY;
    case 7682: /* module 30 call 2 */
        return STR_ME_REMOVE_PROXY;
    case 7683: /* module 30 call 3 */
        return STR_ME_REMOVE_PROXIES;
    case 7684: /* module 30 call 4 */
        return STR_ME_CREATE_PURE;
    case 7685: /* module 30 call 5 */
        return STR_ME_KILL_PURE;
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
    case 10240: /* module 40 call 0 */
        return STR_ME_ADD_CHILD_BOUNTY;
    case 10241: /* module 40 call 1 */
        return STR_ME_PROPOSE_CURATOR;
    case 10242: /* module 40 call 2 */
        return STR_ME_ACCEPT_CURATOR;
    case 10243: /* module 40 call 3 */
        return STR_ME_UNASSIGN_CURATOR;
    case 10244: /* module 40 call 4 */
        return STR_ME_AWARD_CHILD_BOUNTY;
    case 10245: /* module 40 call 5 */
        return STR_ME_CLAIM_CHILD_BOUNTY;
    case 10246: /* module 40 call 6 */
        return STR_ME_CLOSE_CHILD_BOUNTY;
    case 10752: /* module 42 call 0 */
        return STR_ME_REGISTER_FAST_UNSTAKE;
    case 10753: /* module 42 call 1 */
        return STR_ME_DEREGISTER;
    case 10754: /* module 42 call 2 */
        return STR_ME_CONTROL;
    case 13056: /* module 51 call 0 */
        return STR_ME_SET_VALIDATION_UPGRADE_COOLDOWN;
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
        return STR_ME_SET_CORETIME_CORES;
    case 13063: /* module 51 call 7 */
        return STR_ME_SET_ON_DEMAND_RETRIES;
    case 13064: /* module 51 call 8 */
        return STR_ME_SET_GROUP_ROTATION_FREQUENCY;
    case 13065: /* module 51 call 9 */
        return STR_ME_SET_PARAS_AVAILABILITY_PERIOD;
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
    case 13092: /* module 51 call 36 */
        return STR_ME_SET_HRMP_CHANNEL_MAX_MESSAGE_SIZE;
    case 13093: /* module 51 call 37 */
        return STR_ME_SET_HRMP_MAX_PARACHAIN_OUTBOUND_CHANNELS;
    case 13095: /* module 51 call 39 */
        return STR_ME_SET_HRMP_MAX_MESSAGE_NUM_PER_CANDIDATE;
    case 13098: /* module 51 call 42 */
        return STR_ME_SET_PVF_VOTING_TTL;
    case 13099: /* module 51 call 43 */
        return STR_ME_SET_MINIMUM_VALIDATION_UPGRADE_DELAY;
    case 13100: /* module 51 call 44 */
        return STR_ME_SET_BYPASS_CONSISTENCY_CHECK;
    case 13103: /* module 51 call 47 */
        return STR_ME_SET_ON_DEMAND_BASE_FEE;
    case 13104: /* module 51 call 48 */
        return STR_ME_SET_ON_DEMAND_FEE_VARIABILITY;
    case 13105: /* module 51 call 49 */
        return STR_ME_SET_ON_DEMAND_QUEUE_MAX_SIZE;
    case 13106: /* module 51 call 50 */
        return STR_ME_SET_ON_DEMAND_TARGET_QUEUE_UTILIZATION;
    case 13107: /* module 51 call 51 */
        return STR_ME_SET_ON_DEMAND_TTL;
    case 13108: /* module 51 call 52 */
        return STR_ME_SET_MINIMUM_BACKING_VOTES;
    case 13109: /* module 51 call 53 */
        return STR_ME_SET_NODE_FEATURE;
#endif
    default:
        return NULL;
    }

    return NULL;
}

uint8_t _getMethod_NumItems_V26(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1024: /* module 4 call 0 */
        return 2;
    case 1026: /* module 4 call 2 */
        return 3;
    case 1027: /* module 4 call 3 */
        return 2;
    case 1028: /* module 4 call 4 */
        return 2;
    case 1536: /* module 6 call 0 */
        return 2;
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
        return 0;
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
    case 6148: /* module 24 call 4 */
        return 1;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    case 0: /* module 0 call 0 */
        return 1;
    case 1: /* module 0 call 1 */
        return 1;
    case 2: /* module 0 call 2 */
        return 1;
    case 3: /* module 0 call 3 */
        return 1;
    case 7: /* module 0 call 7 */
        return 1;
    case 9: /* module 0 call 9 */
        return 1;
    case 10: /* module 0 call 10 */
        return 1;
    case 11: /* module 0 call 11 */
        return 1;
    case 1029: /* module 4 call 5 */
        return 2;
    case 1030: /* module 4 call 6 */
        return 1;
    case 1032: /* module 4 call 8 */
        return 2;
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
        return 1;
    case 1558: /* module 6 call 22 */
        return 6;
    case 1559: /* module 6 call 23 */
        return 1;
    case 1560: /* module 6 call 24 */
        return 1;
    case 1561: /* module 6 call 25 */
        return 1;
    case 1562: /* module 6 call 26 */
        return 3;
    case 1563: /* module 6 call 27 */
        return 1;
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
    case 4614: /* module 18 call 6 */
        return 1;
    case 4615: /* module 18 call 7 */
        return 1;
    case 4616: /* module 18 call 8 */
        return 1;
    case 5120: /* module 20 call 0 */
        return 2;
    case 5121: /* module 20 call 1 */
        return 4;
    case 5122: /* module 20 call 2 */
        return 1;
    case 5123: /* module 20 call 3 */
        return 2;
    case 5124: /* module 20 call 4 */
        return 2;
    case 5125: /* module 20 call 5 */
        return 3;
    case 5376: /* module 21 call 0 */
        return 3;
    case 5377: /* module 21 call 1 */
        return 1;
    case 5378: /* module 21 call 2 */
        return 1;
    case 5379: /* module 21 call 3 */
        return 1;
    case 5380: /* module 21 call 4 */
        return 1;
    case 5381: /* module 21 call 5 */
        return 1;
    case 5382: /* module 21 call 6 */
        return 1;
    case 5383: /* module 21 call 7 */
        return 1;
    case 5384: /* module 21 call 8 */
        return 2;
    case 6147: /* module 24 call 3 */
        return 2;
    case 6149: /* module 24 call 5 */
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
    case 6409: /* module 25 call 9 */
        return 4;
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
    case 6415: /* module 25 call 15 */
        return 3;
    case 6416: /* module 25 call 16 */
        return 1;
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
    case 7689: /* module 30 call 9 */
        return 4;
    case 7936: /* module 31 call 0 */
        return 2;
    case 7937: /* module 31 call 1 */
        return 5;
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
    case 10240: /* module 40 call 0 */
        return 3;
    case 10241: /* module 40 call 1 */
        return 4;
    case 10242: /* module 40 call 2 */
        return 2;
    case 10243: /* module 40 call 3 */
        return 2;
    case 10244: /* module 40 call 4 */
        return 3;
    case 10245: /* module 40 call 5 */
        return 2;
    case 10246: /* module 40 call 6 */
        return 2;
    case 10752: /* module 42 call 0 */
        return 0;
    case 10753: /* module 42 call 1 */
        return 0;
    case 10754: /* module 42 call 2 */
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
    case 13092: /* module 51 call 36 */
        return 1;
    case 13093: /* module 51 call 37 */
        return 1;
    case 13095: /* module 51 call 39 */
        return 1;
    case 13098: /* module 51 call 42 */
        return 1;
    case 13099: /* module 51 call 43 */
        return 1;
    case 13100: /* module 51 call 44 */
        return 1;
    case 13103: /* module 51 call 47 */
        return 1;
    case 13104: /* module 51 call 48 */
        return 1;
    case 13105: /* module 51 call 49 */
        return 1;
    case 13106: /* module 51 call 50 */
        return 1;
    case 13107: /* module 51 call 51 */
        return 1;
    case 13108: /* module 51 call 52 */
        return 1;
    case 13109: /* module 51 call 53 */
        return 2;
#endif
    default:
        return 0;
    }

    return 0;
}

const char* _getMethod_ItemName_V26(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1024: /* module 4 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
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
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1027: /* module 4 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
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
    case 1536: /* module 6 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_payee;
        default:
            return NULL;
        }
    case 1537: /* module 6 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1538: /* module 6 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
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
            return STR_IT_amount;
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
    case 6148: /* module 24 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remark;
        default:
            return NULL;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pages;
        default:
            return NULL;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
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
    case 7: /* module 0 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remark;
        default:
            return NULL;
        }
    case 9: /* module 0 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code_hash;
        default:
            return NULL;
        }
    case 10: /* module 0 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code_hash;
        default:
            return NULL;
        }
    case 11: /* module 0 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        default:
            return NULL;
        }
    case 1029: /* module 4 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1030: /* module 4 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 1032: /* module 4 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_new_free;
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
            return STR_IT_stash;
        case 1:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 1557: /* module 6 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 1558: /* module 6 call 22 */
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
            return STR_IT_chill_threshold;
        case 5:
            return STR_IT_min_commission;
        default:
            return NULL;
        }
    case 1559: /* module 6 call 23 */
        switch (itemIdx) {
        case 0:
            return STR_IT_stash;
        default:
            return NULL;
        }
    case 1560: /* module 6 call 24 */
        switch (itemIdx) {
        case 0:
            return STR_IT_validator_stash;
        default:
            return NULL;
        }
    case 1561: /* module 6 call 25 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 1562: /* module 6 call 26 */
        switch (itemIdx) {
        case 0:
            return STR_IT_validator_stash;
        case 1:
            return STR_IT_era;
        case 2:
            return STR_IT_page;
        default:
            return NULL;
        }
    case 1563: /* module 6 call 27 */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        default:
            return NULL;
        }
    case 4608: /* module 18 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
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
    case 4611: /* module 18 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_beneficiary;
        default:
            return NULL;
        }
    case 4612: /* module 18 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_id;
        default:
            return NULL;
        }
    case 4614: /* module 18 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 4615: /* module 18 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 4616: /* module 18 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 5120: /* module 20 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_poll_index;
        case 1:
            return STR_IT_vote;
        default:
            return NULL;
        }
    case 5121: /* module 20 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_class_;
        case 1:
            return STR_IT_to;
        case 2:
            return STR_IT_conviction;
        case 3:
            return STR_IT_balance;
        default:
            return NULL;
        }
    case 5122: /* module 20 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_class_;
        default:
            return NULL;
        }
    case 5123: /* module 20 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_class_;
        case 1:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 5124: /* module 20 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_class_;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 5125: /* module 20 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        case 1:
            return STR_IT_class_;
        case 2:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 5376: /* module 21 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_origin;
        case 1:
            return STR_IT_proposal;
        case 2:
            return STR_IT_enactment_moment;
        default:
            return NULL;
        }
    case 5377: /* module 21 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 5378: /* module 21 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 5379: /* module 21 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 5380: /* module 21 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 5381: /* module 21 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 5382: /* module 21 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_track;
        default:
            return NULL;
        }
    case 5383: /* module 21 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 5384: /* module 21 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_maybe_hash;
        default:
            return NULL;
        }
    case 6147: /* module 24 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_as_origin;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 6149: /* module 24 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call;
        case 1:
            return STR_IT_weight;
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
    case 6409: /* module 25 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reg_index;
        case 1:
            return STR_IT_target;
        case 2:
            return STR_IT_judgement;
        case 3:
            return STR_IT_identity;
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
    case 6415: /* module 25 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_authority;
        case 1:
            return STR_IT_suffix;
        case 2:
            return STR_IT_allocation;
        default:
            return NULL;
        }
    case 6416: /* module 25 call 16 */
        switch (itemIdx) {
        case 0:
            return STR_IT_authority;
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
            return STR_IT_amount;
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
            return STR_IT_remark;
        default:
            return NULL;
        }
    case 10240: /* module 40 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_parent_bounty_id;
        case 1:
            return STR_IT_amount;
        case 2:
            return STR_IT_description;
        default:
            return NULL;
        }
    case 10241: /* module 40 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_parent_bounty_id;
        case 1:
            return STR_IT_child_bounty_id;
        case 2:
            return STR_IT_curator;
        case 3:
            return STR_IT_fee;
        default:
            return NULL;
        }
    case 10242: /* module 40 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_parent_bounty_id;
        case 1:
            return STR_IT_child_bounty_id;
        default:
            return NULL;
        }
    case 10243: /* module 40 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_parent_bounty_id;
        case 1:
            return STR_IT_child_bounty_id;
        default:
            return NULL;
        }
    case 10244: /* module 40 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_parent_bounty_id;
        case 1:
            return STR_IT_child_bounty_id;
        case 2:
            return STR_IT_beneficiary;
        default:
            return NULL;
        }
    case 10245: /* module 40 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_parent_bounty_id;
        case 1:
            return STR_IT_child_bounty_id;
        default:
            return NULL;
        }
    case 10246: /* module 40 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_parent_bounty_id;
        case 1:
            return STR_IT_child_bounty_id;
        default:
            return NULL;
        }
    case 10752: /* module 42 call 0 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 10753: /* module 42 call 1 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 10754: /* module 42 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_eras_to_check;
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
            return STR_IT_new_;
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
    case 13095: /* module 51 call 39 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13098: /* module 51 call 42 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13099: /* module 51 call 43 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13100: /* module 51 call 44 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13103: /* module 51 call 47 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13104: /* module 51 call 48 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13105: /* module 51 call 49 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13106: /* module 51 call 50 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13107: /* module 51 call 51 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13108: /* module 51 call 52 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13109: /* module 51 call 53 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_value;
        default:
            return NULL;
        }
#endif
    default:
        return NULL;
    }

    return NULL;
}

parser_error_t _getMethod_ItemValue_V26(
    pd_Method_V26_t* m,
    uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1024: /* module 4 call 0 */
        switch (itemIdx) {
        case 0: /* balances_transfer_allow_death_V26 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_transfer_allow_death_V26.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_allow_death_V26 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_allow_death_V26.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1026: /* module 4 call 2 */
        switch (itemIdx) {
        case 0: /* balances_force_transfer_V26 - source */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_force_transfer_V26.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_transfer_V26 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_force_transfer_V26.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_force_transfer_V26 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_force_transfer_V26.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1027: /* module 4 call 3 */
        switch (itemIdx) {
        case 0: /* balances_transfer_keep_alive_V26 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_transfer_keep_alive_V26.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_keep_alive_V26 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_keep_alive_V26.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1028: /* module 4 call 4 */
        switch (itemIdx) {
        case 0: /* balances_transfer_all_V26 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_transfer_all_V26.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_all_V26 - keep_alive */;
            return _toStringbool(
                &m->nested.balances_transfer_all_V26.keep_alive,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1536: /* module 6 call 0 */
        switch (itemIdx) {
        case 0: /* staking_bond_V26 - amount */;
            return _toStringCompactBalance(
                &m->nested.staking_bond_V26.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_bond_V26 - payee */;
            return _toStringRewardDestination(
                &m->nested.staking_bond_V26.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1537: /* module 6 call 1 */
        switch (itemIdx) {
        case 0: /* staking_bond_extra_V26 - amount */;
            return _toStringCompactBalance(
                &m->nested.staking_bond_extra_V26.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1538: /* module 6 call 2 */
        switch (itemIdx) {
        case 0: /* staking_unbond_V26 - amount */;
            return _toStringCompactBalance(
                &m->nested.staking_unbond_V26.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1539: /* module 6 call 3 */
        switch (itemIdx) {
        case 0: /* staking_withdraw_unbonded_V26 - num_slashing_spans */;
            return _toStringu32(
                &m->nested.staking_withdraw_unbonded_V26.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1540: /* module 6 call 4 */
        switch (itemIdx) {
        case 0: /* staking_validate_V26 - prefs */;
            return _toStringValidatorPrefs(
                &m->nested.staking_validate_V26.prefs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1541: /* module 6 call 5 */
        switch (itemIdx) {
        case 0: /* staking_nominate_V26 - targets */;
            return _toStringVecAccountIdLookupOfT(
                &m->nested.staking_nominate_V26.targets,
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
        case 0: /* staking_set_payee_V26 - payee */;
            return _toStringRewardDestination(
                &m->nested.staking_set_payee_V26.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1544: /* module 6 call 8 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1554: /* module 6 call 18 */
        switch (itemIdx) {
        case 0: /* staking_payout_stakers_V26 - validator_stash */;
            return _toStringAccountId(
                &m->nested.staking_payout_stakers_V26.validator_stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_payout_stakers_V26 - era */;
            return _toStringEraIndex(
                &m->nested.staking_payout_stakers_V26.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1555: /* module 6 call 19 */
        switch (itemIdx) {
        case 0: /* staking_rebond_V26 - amount */;
            return _toStringCompactBalance(
                &m->nested.staking_rebond_V26.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2048: /* module 8 call 0 */
        switch (itemIdx) {
        case 0: /* session_set_keys_V26 - keys */;
            return _toStringKeys(
                &m->nested.session_set_keys_V26.keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* session_set_keys_V26 - proof */;
            return _toStringBytes(
                &m->nested.session_set_keys_V26.proof,
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
        case 0: /* utility_batch_V26 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_V26.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6146: /* module 24 call 2 */
        switch (itemIdx) {
        case 0: /* utility_batch_all_V26 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_all_V26.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6148: /* module 24 call 4 */
        switch (itemIdx) {
        case 0: /* utility_force_batch_V26 - calls */;
            return _toStringVecCall(
                &m->basic.utility_force_batch_V26.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0: /* system_remark_V26 - remark */;
            return _toStringBytes(
                &m->nested.system_remark_V26.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0: /* system_set_heap_pages_V26 - pages */;
            return _toStringu64(
                &m->nested.system_set_heap_pages_V26.pages,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0: /* system_set_code_V26 - code */;
            return _toStringBytes(
                &m->nested.system_set_code_V26.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0: /* system_set_code_without_checks_V26 - code */;
            return _toStringVecu8(
                &m->nested.system_set_code_without_checks_V26.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7: /* module 0 call 7 */
        switch (itemIdx) {
        case 0: /* system_remark_with_event_V26 - remark */;
            return _toStringBytes(
                &m->nested.system_remark_with_event_V26.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9: /* module 0 call 9 */
        switch (itemIdx) {
        case 0: /* system_authorize_upgrade_V26 - code_hash */;
            return _toStringHash(
                &m->basic.system_authorize_upgrade_V26.code_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10: /* module 0 call 10 */
        switch (itemIdx) {
        case 0: /* system_authorize_upgrade_without_checks_V26 - code_hash */;
            return _toStringHash(
                &m->basic.system_authorize_upgrade_without_checks_V26.code_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11: /* module 0 call 11 */
        switch (itemIdx) {
        case 0: /* system_apply_authorized_upgrade_V26 - code */;
            return _toStringVecu8(
                &m->basic.system_apply_authorized_upgrade_V26.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1029: /* module 4 call 5 */
        switch (itemIdx) {
        case 0: /* balances_force_unreserve_V26 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.balances_force_unreserve_V26.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_unreserve_V26 - amount */;
            return _toStringBalance(
                &m->basic.balances_force_unreserve_V26.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1030: /* module 4 call 6 */
        switch (itemIdx) {
        case 0: /* balances_upgrade_accounts_V26 - who */;
            return _toStringVecAccountId(
                &m->basic.balances_upgrade_accounts_V26.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1032: /* module 4 call 8 */
        switch (itemIdx) {
        case 0: /* balances_force_set_balance_V26 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.balances_force_set_balance_V26.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_set_balance_V26 - new_free */;
            return _toStringCompactBalance(
                &m->basic.balances_force_set_balance_V26.new_free,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1545: /* module 6 call 9 */
        switch (itemIdx) {
        case 0: /* staking_set_validator_count_V26 - new_ */;
            return _toStringCompactu32(
                &m->basic.staking_set_validator_count_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1546: /* module 6 call 10 */
        switch (itemIdx) {
        case 0: /* staking_increase_validator_count_V26 - additional */;
            return _toStringCompactu32(
                &m->basic.staking_increase_validator_count_V26.additional,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1547: /* module 6 call 11 */
        switch (itemIdx) {
        case 0: /* staking_scale_validator_count_V26 - factor */;
            return _toStringPercent(
                &m->basic.staking_scale_validator_count_V26.factor,
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
        case 0: /* staking_set_invulnerables_V26 - invulnerables */;
            return _toStringVecAccountId(
                &m->basic.staking_set_invulnerables_V26.invulnerables,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1551: /* module 6 call 15 */
        switch (itemIdx) {
        case 0: /* staking_force_unstake_V26 - stash */;
            return _toStringAccountId(
                &m->basic.staking_force_unstake_V26.stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_force_unstake_V26 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_force_unstake_V26.num_slashing_spans,
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
        case 0: /* staking_cancel_deferred_slash_V26 - era */;
            return _toStringEraIndex(
                &m->basic.staking_cancel_deferred_slash_V26.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_cancel_deferred_slash_V26 - slash_indices */;
            return _toStringVecu32(
                &m->basic.staking_cancel_deferred_slash_V26.slash_indices,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1556: /* module 6 call 20 */
        switch (itemIdx) {
        case 0: /* staking_reap_stash_V26 - stash */;
            return _toStringAccountId(
                &m->basic.staking_reap_stash_V26.stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_reap_stash_V26 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_reap_stash_V26.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1557: /* module 6 call 21 */
        switch (itemIdx) {
        case 0: /* staking_kick_V26 - who */;
            return _toStringVecAccountIdLookupOfT(
                &m->basic.staking_kick_V26.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1558: /* module 6 call 22 */
        switch (itemIdx) {
        case 0: /* staking_set_staking_configs_V26 - min_nominator_bond */;
            return _toStringConfigOpBalanceOfT(
                &m->basic.staking_set_staking_configs_V26.min_nominator_bond,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_set_staking_configs_V26 - min_validator_bond */;
            return _toStringConfigOpBalanceOfT(
                &m->basic.staking_set_staking_configs_V26.min_validator_bond,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* staking_set_staking_configs_V26 - max_nominator_count */;
            return _toStringConfigOpu32(
                &m->basic.staking_set_staking_configs_V26.max_nominator_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* staking_set_staking_configs_V26 - max_validator_count */;
            return _toStringConfigOpu32(
                &m->basic.staking_set_staking_configs_V26.max_validator_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* staking_set_staking_configs_V26 - chill_threshold */;
            return _toStringConfigOpPercent(
                &m->basic.staking_set_staking_configs_V26.chill_threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* staking_set_staking_configs_V26 - min_commission */;
            return _toStringConfigOpPerbill(
                &m->basic.staking_set_staking_configs_V26.min_commission,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1559: /* module 6 call 23 */
        switch (itemIdx) {
        case 0: /* staking_chill_other_V26 - stash */;
            return _toStringAccountId(
                &m->basic.staking_chill_other_V26.stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1560: /* module 6 call 24 */
        switch (itemIdx) {
        case 0: /* staking_force_apply_min_commission_V26 - validator_stash */;
            return _toStringAccountId(
                &m->basic.staking_force_apply_min_commission_V26.validator_stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1561: /* module 6 call 25 */
        switch (itemIdx) {
        case 0: /* staking_set_min_commission_V26 - new_ */;
            return _toStringPerbill(
                &m->basic.staking_set_min_commission_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1562: /* module 6 call 26 */
        switch (itemIdx) {
        case 0: /* staking_payout_stakers_by_page_V26 - validator_stash */;
            return _toStringAccountId(
                &m->basic.staking_payout_stakers_by_page_V26.validator_stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_payout_stakers_by_page_V26 - era */;
            return _toStringEraIndex(
                &m->basic.staking_payout_stakers_by_page_V26.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* staking_payout_stakers_by_page_V26 - page */;
            return _toStringPage(
                &m->basic.staking_payout_stakers_by_page_V26.page,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1563: /* module 6 call 27 */
        switch (itemIdx) {
        case 0: /* staking_update_payee_V26 - controller */;
            return _toStringAccountId(
                &m->basic.staking_update_payee_V26.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4608: /* module 18 call 0 */
        switch (itemIdx) {
        case 0: /* treasury_propose_spend_V26 - amount */;
            return _toStringCompactBalance(
                &m->basic.treasury_propose_spend_V26.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* treasury_propose_spend_V26 - beneficiary */;
            return _toStringAccountIdLookupOfT(
                &m->basic.treasury_propose_spend_V26.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4609: /* module 18 call 1 */
        switch (itemIdx) {
        case 0: /* treasury_reject_proposal_V26 - proposal_id */;
            return _toStringCompactu32(
                &m->basic.treasury_reject_proposal_V26.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4610: /* module 18 call 2 */
        switch (itemIdx) {
        case 0: /* treasury_approve_proposal_V26 - proposal_id */;
            return _toStringCompactu32(
                &m->basic.treasury_approve_proposal_V26.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4611: /* module 18 call 3 */
        switch (itemIdx) {
        case 0: /* treasury_spend_local_V26 - amount */;
            return _toStringCompactBalance(
                &m->basic.treasury_spend_local_V26.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* treasury_spend_local_V26 - beneficiary */;
            return _toStringAccountIdLookupOfT(
                &m->basic.treasury_spend_local_V26.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4612: /* module 18 call 4 */
        switch (itemIdx) {
        case 0: /* treasury_remove_approval_V26 - proposal_id */;
            return _toStringCompactu32(
                &m->basic.treasury_remove_approval_V26.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4614: /* module 18 call 6 */
        switch (itemIdx) {
        case 0: /* treasury_payout_V26 - index */;
            return _toStringSpendIndex(
                &m->basic.treasury_payout_V26.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4615: /* module 18 call 7 */
        switch (itemIdx) {
        case 0: /* treasury_check_status_V26 - index */;
            return _toStringSpendIndex(
                &m->basic.treasury_check_status_V26.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4616: /* module 18 call 8 */
        switch (itemIdx) {
        case 0: /* treasury_void_spend_V26 - index */;
            return _toStringSpendIndex(
                &m->basic.treasury_void_spend_V26.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5120: /* module 20 call 0 */
        switch (itemIdx) {
        case 0: /* convictionvoting_vote_V26 - poll_index */;
            return _toStringCompactu32(
                &m->nested.convictionvoting_vote_V26.poll_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* convictionvoting_vote_V26 - vote */;
            return _toStringAccountVote(
                &m->nested.convictionvoting_vote_V26.vote,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5121: /* module 20 call 1 */
        switch (itemIdx) {
        case 0: /* convictionvoting_delegate_V26 - class_ */;
            return _toStringClassOf(
                &m->nested.convictionvoting_delegate_V26.class_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* convictionvoting_delegate_V26 - to */;
            return _toStringAccountIdLookupOfT(
                &m->nested.convictionvoting_delegate_V26.to,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* convictionvoting_delegate_V26 - conviction */;
            return _toStringConviction(
                &m->nested.convictionvoting_delegate_V26.conviction,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* convictionvoting_delegate_V26 - balance */;
            return _toStringBalanceOf(
                &m->nested.convictionvoting_delegate_V26.balance,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5122: /* module 20 call 2 */
        switch (itemIdx) {
        case 0: /* convictionvoting_undelegate_V26 - class_ */;
            return _toStringClassOf(
                &m->nested.convictionvoting_undelegate_V26.class_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5123: /* module 20 call 3 */
        switch (itemIdx) {
        case 0: /* convictionvoting_unlock_V26 - class_ */;
            return _toStringClassOf(
                &m->nested.convictionvoting_unlock_V26.class_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* convictionvoting_unlock_V26 - target */;
            return _toStringAccountIdLookupOfT(
                &m->nested.convictionvoting_unlock_V26.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5124: /* module 20 call 4 */
        switch (itemIdx) {
        case 0: /* convictionvoting_remove_vote_V26 - class_ */;
            return _toStringOptionClassOf(
                &m->nested.convictionvoting_remove_vote_V26.class_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* convictionvoting_remove_vote_V26 - index */;
            return _toStringPollIndexOf(
                &m->nested.convictionvoting_remove_vote_V26.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5125: /* module 20 call 5 */
        switch (itemIdx) {
        case 0: /* convictionvoting_remove_other_vote_V26 - target */;
            return _toStringAccountIdLookupOfT(
                &m->nested.convictionvoting_remove_other_vote_V26.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* convictionvoting_remove_other_vote_V26 - class_ */;
            return _toStringClassOf(
                &m->nested.convictionvoting_remove_other_vote_V26.class_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* convictionvoting_remove_other_vote_V26 - index */;
            return _toStringPollIndexOf(
                &m->nested.convictionvoting_remove_other_vote_V26.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5376: /* module 21 call 0 */
        switch (itemIdx) {
        case 0: /* referenda_submit_V26 - proposal_origin */;
            return _toStringBoxPalletsOrigin(
                &m->basic.referenda_submit_V26.proposal_origin,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* referenda_submit_V26 - proposal */;
            return _toStringBoundedCallOfT(
                &m->basic.referenda_submit_V26.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* referenda_submit_V26 - enactment_moment */;
            return _toStringDispatchTimeBlockNumber(
                &m->basic.referenda_submit_V26.enactment_moment,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5377: /* module 21 call 1 */
        switch (itemIdx) {
        case 0: /* referenda_place_decision_deposit_V26 - index */;
            return _toStringReferendumIndex(
                &m->basic.referenda_place_decision_deposit_V26.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5378: /* module 21 call 2 */
        switch (itemIdx) {
        case 0: /* referenda_refund_decision_deposit_V26 - index */;
            return _toStringReferendumIndex(
                &m->basic.referenda_refund_decision_deposit_V26.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5379: /* module 21 call 3 */
        switch (itemIdx) {
        case 0: /* referenda_cancel_V26 - index */;
            return _toStringReferendumIndex(
                &m->basic.referenda_cancel_V26.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5380: /* module 21 call 4 */
        switch (itemIdx) {
        case 0: /* referenda_kill_V26 - index */;
            return _toStringReferendumIndex(
                &m->basic.referenda_kill_V26.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5381: /* module 21 call 5 */
        switch (itemIdx) {
        case 0: /* referenda_nudge_referendum_V26 - index */;
            return _toStringReferendumIndex(
                &m->basic.referenda_nudge_referendum_V26.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5382: /* module 21 call 6 */
        switch (itemIdx) {
        case 0: /* referenda_one_fewer_deciding_V26 - track */;
            return _toStringTrackIdOf(
                &m->basic.referenda_one_fewer_deciding_V26.track,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5383: /* module 21 call 7 */
        switch (itemIdx) {
        case 0: /* referenda_refund_submission_deposit_V26 - index */;
            return _toStringReferendumIndex(
                &m->basic.referenda_refund_submission_deposit_V26.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5384: /* module 21 call 8 */
        switch (itemIdx) {
        case 0: /* referenda_set_metadata_V26 - index */;
            return _toStringReferendumIndex(
                &m->basic.referenda_set_metadata_V26.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* referenda_set_metadata_V26 - maybe_hash */;
            return _toStringOptionHash(
                &m->basic.referenda_set_metadata_V26.maybe_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6147: /* module 24 call 3 */
        switch (itemIdx) {
        case 0: /* utility_dispatch_as_V26 - as_origin */;
            return _toStringBoxPalletsOrigin(
                &m->basic.utility_dispatch_as_V26.as_origin,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* utility_dispatch_as_V26 - call */;
            return _toStringCall(
                &m->basic.utility_dispatch_as_V26.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6149: /* module 24 call 5 */
        switch (itemIdx) {
        case 0: /* utility_with_weight_V26 - call */;
            return _toStringCall(
                &m->basic.utility_with_weight_V26.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* utility_with_weight_V26 - weight */;
            return _toStringWeight(
                &m->basic.utility_with_weight_V26.weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6400: /* module 25 call 0 */
        switch (itemIdx) {
        case 0: /* identity_add_registrar_V26 - account */;
            return _toStringAccountIdLookupOfT(
                &m->basic.identity_add_registrar_V26.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6401: /* module 25 call 1 */
        switch (itemIdx) {
        case 0: /* identity_set_identity_V26 - info */;
            return _toStringIdentityInfo(
                &m->basic.identity_set_identity_V26.info,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6402: /* module 25 call 2 */
        switch (itemIdx) {
        case 0: /* identity_set_subs_V26 - subs */;
            return _toStringVecTupleAccountIdData(
                &m->basic.identity_set_subs_V26.subs,
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
        case 0: /* identity_request_judgement_V26 - reg_index */;
            return _toStringCompactu32(
                &m->basic.identity_request_judgement_V26.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_request_judgement_V26 - max_fee */;
            return _toStringCompactu128(
                &m->basic.identity_request_judgement_V26.max_fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6405: /* module 25 call 5 */
        switch (itemIdx) {
        case 0: /* identity_cancel_request_V26 - reg_index */;
            return _toStringRegistrarIndex(
                &m->basic.identity_cancel_request_V26.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6406: /* module 25 call 6 */
        switch (itemIdx) {
        case 0: /* identity_set_fee_V26 - index */;
            return _toStringCompactu32(
                &m->basic.identity_set_fee_V26.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_fee_V26 - fee */;
            return _toStringCompactu128(
                &m->basic.identity_set_fee_V26.fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6407: /* module 25 call 7 */
        switch (itemIdx) {
        case 0: /* identity_set_account_id_V26 - index */;
            return _toStringCompactu32(
                &m->basic.identity_set_account_id_V26.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_account_id_V26 - new_ */;
            return _toStringAccountIdLookupOfT(
                &m->basic.identity_set_account_id_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6409: /* module 25 call 9 */
        switch (itemIdx) {
        case 0: /* identity_provide_judgement_V26 - reg_index */;
            return _toStringCompactu32(
                &m->basic.identity_provide_judgement_V26.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_provide_judgement_V26 - target */;
            return _toStringAccountIdLookupOfT(
                &m->basic.identity_provide_judgement_V26.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* identity_provide_judgement_V26 - judgement */;
            return _toStringJudgementBalanceOfT(
                &m->basic.identity_provide_judgement_V26.judgement,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* identity_provide_judgement_V26 - identity */;
            return _toStringHash(
                &m->basic.identity_provide_judgement_V26.identity,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6410: /* module 25 call 10 */
        switch (itemIdx) {
        case 0: /* identity_kill_identity_V26 - target */;
            return _toStringAccountIdLookupOfT(
                &m->basic.identity_kill_identity_V26.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6411: /* module 25 call 11 */
        switch (itemIdx) {
        case 0: /* identity_add_sub_V26 - sub */;
            return _toStringAccountIdLookupOfT(
                &m->basic.identity_add_sub_V26.sub,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_add_sub_V26 - data */;
            return _toStringData(
                &m->basic.identity_add_sub_V26.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6412: /* module 25 call 12 */
        switch (itemIdx) {
        case 0: /* identity_rename_sub_V26 - sub */;
            return _toStringAccountIdLookupOfT(
                &m->basic.identity_rename_sub_V26.sub,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_rename_sub_V26 - data */;
            return _toStringData(
                &m->basic.identity_rename_sub_V26.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6413: /* module 25 call 13 */
        switch (itemIdx) {
        case 0: /* identity_remove_sub_V26 - sub */;
            return _toStringAccountIdLookupOfT(
                &m->basic.identity_remove_sub_V26.sub,
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
    case 6415: /* module 25 call 15 */
        switch (itemIdx) {
        case 0: /* identity_add_username_authority_V26 - authority */;
            return _toStringAccountIdLookupOfT(
                &m->basic.identity_add_username_authority_V26.authority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_add_username_authority_V26 - suffix */;
            return _toStringVecu8(
                &m->basic.identity_add_username_authority_V26.suffix,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* identity_add_username_authority_V26 - allocation */;
            return _toStringu32(
                &m->basic.identity_add_username_authority_V26.allocation,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6416: /* module 25 call 16 */
        switch (itemIdx) {
        case 0: /* identity_remove_username_authority_V26 - authority */;
            return _toStringAccountIdLookupOfT(
                &m->basic.identity_remove_username_authority_V26.authority,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7680: /* module 30 call 0 */
        switch (itemIdx) {
        case 0: /* proxy_proxy_V26 - real */;
            return _toStringAccountIdLookupOfT(
                &m->nested.proxy_proxy_V26.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_proxy_V26 - force_proxy_type */;
            return _toStringOptionProxyType(
                &m->nested.proxy_proxy_V26.force_proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_proxy_V26 - call */;
            return _toStringCall(
                &m->nested.proxy_proxy_V26.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7681: /* module 30 call 1 */
        switch (itemIdx) {
        case 0: /* proxy_add_proxy_V26 - delegate */;
            return _toStringAccountIdLookupOfT(
                &m->nested.proxy_add_proxy_V26.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_add_proxy_V26 - proxy_type */;
            return _toStringProxyType(
                &m->nested.proxy_add_proxy_V26.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_add_proxy_V26 - delay */;
            return _toStringBlockNumber(
                &m->nested.proxy_add_proxy_V26.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7682: /* module 30 call 2 */
        switch (itemIdx) {
        case 0: /* proxy_remove_proxy_V26 - delegate */;
            return _toStringAccountIdLookupOfT(
                &m->nested.proxy_remove_proxy_V26.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_remove_proxy_V26 - proxy_type */;
            return _toStringProxyType(
                &m->nested.proxy_remove_proxy_V26.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_remove_proxy_V26 - delay */;
            return _toStringBlockNumber(
                &m->nested.proxy_remove_proxy_V26.delay,
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
        case 0: /* proxy_create_pure_V26 - proxy_type */;
            return _toStringProxyType(
                &m->nested.proxy_create_pure_V26.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_create_pure_V26 - delay */;
            return _toStringBlockNumber(
                &m->nested.proxy_create_pure_V26.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_create_pure_V26 - index */;
            return _toStringu16(
                &m->nested.proxy_create_pure_V26.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7685: /* module 30 call 5 */
        switch (itemIdx) {
        case 0: /* proxy_kill_pure_V26 - spawner */;
            return _toStringAccountIdLookupOfT(
                &m->nested.proxy_kill_pure_V26.spawner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_kill_pure_V26 - proxy_type */;
            return _toStringProxyType(
                &m->nested.proxy_kill_pure_V26.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_kill_pure_V26 - index */;
            return _toStringu16(
                &m->nested.proxy_kill_pure_V26.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* proxy_kill_pure_V26 - height */;
            return _toStringCompactu32(
                &m->nested.proxy_kill_pure_V26.height,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* proxy_kill_pure_V26 - ext_index */;
            return _toStringCompactu32(
                &m->nested.proxy_kill_pure_V26.ext_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7689: /* module 30 call 9 */
        switch (itemIdx) {
        case 0: /* proxy_proxy_announced_V26 - delegate */;
            return _toStringAccountIdLookupOfT(
                &m->basic.proxy_proxy_announced_V26.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_proxy_announced_V26 - real */;
            return _toStringAccountIdLookupOfT(
                &m->basic.proxy_proxy_announced_V26.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_proxy_announced_V26 - force_proxy_type */;
            return _toStringOptionProxyType(
                &m->basic.proxy_proxy_announced_V26.force_proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* proxy_proxy_announced_V26 - call */;
            return _toStringCall(
                &m->basic.proxy_proxy_announced_V26.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7936: /* module 31 call 0 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_threshold_1_V26 - other_signatories */;
            return _toStringVecAccountId(
                &m->nested.multisig_as_multi_threshold_1_V26.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_threshold_1_V26 - call */;
            return _toStringCall(
                &m->nested.multisig_as_multi_threshold_1_V26.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7937: /* module 31 call 1 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_V26 - threshold */;
            return _toStringu16(
                &m->nested.multisig_as_multi_V26.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_V26 - other_signatories */;
            return _toStringVecAccountId(
                &m->nested.multisig_as_multi_V26.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_as_multi_V26 - maybe_timepoint */;
            return _toStringOptionTimepoint(
                &m->nested.multisig_as_multi_V26.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_as_multi_V26 - call */;
            return _toStringCall(
                &m->nested.multisig_as_multi_V26.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_as_multi_V26 - max_weight */;
            return _toStringWeight(
                &m->nested.multisig_as_multi_V26.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7938: /* module 31 call 2 */
        switch (itemIdx) {
        case 0: /* multisig_approve_as_multi_V26 - threshold */;
            return _toStringu16(
                &m->nested.multisig_approve_as_multi_V26.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_approve_as_multi_V26 - other_signatories */;
            return _toStringVecAccountId(
                &m->nested.multisig_approve_as_multi_V26.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_approve_as_multi_V26 - maybe_timepoint */;
            return _toStringOptionTimepoint(
                &m->nested.multisig_approve_as_multi_V26.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_approve_as_multi_V26 - call_hash */;
            return _toStringH256(
                &m->nested.multisig_approve_as_multi_V26.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_approve_as_multi_V26 - max_weight */;
            return _toStringWeight(
                &m->nested.multisig_approve_as_multi_V26.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7939: /* module 31 call 3 */
        switch (itemIdx) {
        case 0: /* multisig_cancel_as_multi_V26 - threshold */;
            return _toStringu16(
                &m->nested.multisig_cancel_as_multi_V26.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_cancel_as_multi_V26 - other_signatories */;
            return _toStringVecAccountId(
                &m->nested.multisig_cancel_as_multi_V26.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_cancel_as_multi_V26 - timepoint */;
            return _toStringTimepoint(
                &m->nested.multisig_cancel_as_multi_V26.timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_cancel_as_multi_V26 - call_hash */;
            return _toStringH256(
                &m->nested.multisig_cancel_as_multi_V26.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8960: /* module 35 call 0 */
        switch (itemIdx) {
        case 0: /* bounties_propose_bounty_V26 - amount */;
            return _toStringCompactBalance(
                &m->basic.bounties_propose_bounty_V26.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bounties_propose_bounty_V26 - description */;
            return _toStringBytes(
                &m->basic.bounties_propose_bounty_V26.description,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8961: /* module 35 call 1 */
        switch (itemIdx) {
        case 0: /* bounties_approve_bounty_V26 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_approve_bounty_V26.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8962: /* module 35 call 2 */
        switch (itemIdx) {
        case 0: /* bounties_propose_curator_V26 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_propose_curator_V26.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bounties_propose_curator_V26 - curator */;
            return _toStringAccountIdLookupOfT(
                &m->basic.bounties_propose_curator_V26.curator,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* bounties_propose_curator_V26 - fee */;
            return _toStringCompactBalance(
                &m->basic.bounties_propose_curator_V26.fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8963: /* module 35 call 3 */
        switch (itemIdx) {
        case 0: /* bounties_unassign_curator_V26 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_unassign_curator_V26.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8964: /* module 35 call 4 */
        switch (itemIdx) {
        case 0: /* bounties_accept_curator_V26 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_accept_curator_V26.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8965: /* module 35 call 5 */
        switch (itemIdx) {
        case 0: /* bounties_award_bounty_V26 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_award_bounty_V26.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bounties_award_bounty_V26 - beneficiary */;
            return _toStringAccountIdLookupOfT(
                &m->basic.bounties_award_bounty_V26.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8966: /* module 35 call 6 */
        switch (itemIdx) {
        case 0: /* bounties_claim_bounty_V26 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_claim_bounty_V26.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8967: /* module 35 call 7 */
        switch (itemIdx) {
        case 0: /* bounties_close_bounty_V26 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_close_bounty_V26.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8968: /* module 35 call 8 */
        switch (itemIdx) {
        case 0: /* bounties_extend_bounty_expiry_V26 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_extend_bounty_expiry_V26.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bounties_extend_bounty_expiry_V26 - remark */;
            return _toStringBytes(
                &m->basic.bounties_extend_bounty_expiry_V26.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10240: /* module 40 call 0 */
        switch (itemIdx) {
        case 0: /* childbounties_add_child_bounty_V26 - parent_bounty_id */;
            return _toStringCompactu32(
                &m->basic.childbounties_add_child_bounty_V26.parent_bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* childbounties_add_child_bounty_V26 - amount */;
            return _toStringCompactBalance(
                &m->basic.childbounties_add_child_bounty_V26.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* childbounties_add_child_bounty_V26 - description */;
            return _toStringVecu8(
                &m->basic.childbounties_add_child_bounty_V26.description,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10241: /* module 40 call 1 */
        switch (itemIdx) {
        case 0: /* childbounties_propose_curator_V26 - parent_bounty_id */;
            return _toStringCompactu32(
                &m->basic.childbounties_propose_curator_V26.parent_bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* childbounties_propose_curator_V26 - child_bounty_id */;
            return _toStringCompactu32(
                &m->basic.childbounties_propose_curator_V26.child_bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* childbounties_propose_curator_V26 - curator */;
            return _toStringAccountIdLookupOfT(
                &m->basic.childbounties_propose_curator_V26.curator,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* childbounties_propose_curator_V26 - fee */;
            return _toStringCompactBalance(
                &m->basic.childbounties_propose_curator_V26.fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10242: /* module 40 call 2 */
        switch (itemIdx) {
        case 0: /* childbounties_accept_curator_V26 - parent_bounty_id */;
            return _toStringCompactu32(
                &m->basic.childbounties_accept_curator_V26.parent_bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* childbounties_accept_curator_V26 - child_bounty_id */;
            return _toStringCompactu32(
                &m->basic.childbounties_accept_curator_V26.child_bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10243: /* module 40 call 3 */
        switch (itemIdx) {
        case 0: /* childbounties_unassign_curator_V26 - parent_bounty_id */;
            return _toStringCompactu32(
                &m->basic.childbounties_unassign_curator_V26.parent_bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* childbounties_unassign_curator_V26 - child_bounty_id */;
            return _toStringCompactu32(
                &m->basic.childbounties_unassign_curator_V26.child_bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10244: /* module 40 call 4 */
        switch (itemIdx) {
        case 0: /* childbounties_award_child_bounty_V26 - parent_bounty_id */;
            return _toStringCompactu32(
                &m->basic.childbounties_award_child_bounty_V26.parent_bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* childbounties_award_child_bounty_V26 - child_bounty_id */;
            return _toStringCompactu32(
                &m->basic.childbounties_award_child_bounty_V26.child_bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* childbounties_award_child_bounty_V26 - beneficiary */;
            return _toStringAccountIdLookupOfT(
                &m->basic.childbounties_award_child_bounty_V26.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10245: /* module 40 call 5 */
        switch (itemIdx) {
        case 0: /* childbounties_claim_child_bounty_V26 - parent_bounty_id */;
            return _toStringCompactu32(
                &m->basic.childbounties_claim_child_bounty_V26.parent_bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* childbounties_claim_child_bounty_V26 - child_bounty_id */;
            return _toStringCompactu32(
                &m->basic.childbounties_claim_child_bounty_V26.child_bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10246: /* module 40 call 6 */
        switch (itemIdx) {
        case 0: /* childbounties_close_child_bounty_V26 - parent_bounty_id */;
            return _toStringCompactu32(
                &m->basic.childbounties_close_child_bounty_V26.parent_bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* childbounties_close_child_bounty_V26 - child_bounty_id */;
            return _toStringCompactu32(
                &m->basic.childbounties_close_child_bounty_V26.child_bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10752: /* module 42 call 0 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 10753: /* module 42 call 1 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 10754: /* module 42 call 2 */
        switch (itemIdx) {
        case 0: /* fastunstake_control_V26 - eras_to_check */;
            return _toStringEraIndex(
                &m->basic.fastunstake_control_V26.eras_to_check,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13056: /* module 51 call 0 */
        switch (itemIdx) {
        case 0: /* configuration_set_validation_upgrade_cooldown_V26 - new_ */;
            return _toStringBlockNumber(
                &m->basic.configuration_set_validation_upgrade_cooldown_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13057: /* module 51 call 1 */
        switch (itemIdx) {
        case 0: /* configuration_set_validation_upgrade_delay_V26 - new_ */;
            return _toStringBlockNumber(
                &m->basic.configuration_set_validation_upgrade_delay_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13058: /* module 51 call 2 */
        switch (itemIdx) {
        case 0: /* configuration_set_code_retention_period_V26 - new_ */;
            return _toStringBlockNumber(
                &m->basic.configuration_set_code_retention_period_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13059: /* module 51 call 3 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_code_size_V26 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_max_code_size_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13060: /* module 51 call 4 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_pov_size_V26 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_max_pov_size_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13061: /* module 51 call 5 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_head_data_size_V26 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_max_head_data_size_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13062: /* module 51 call 6 */
        switch (itemIdx) {
        case 0: /* configuration_set_coretime_cores_V26 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_coretime_cores_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13063: /* module 51 call 7 */
        switch (itemIdx) {
        case 0: /* configuration_set_on_demand_retries_V26 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_on_demand_retries_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13064: /* module 51 call 8 */
        switch (itemIdx) {
        case 0: /* configuration_set_group_rotation_frequency_V26 - new_ */;
            return _toStringBlockNumber(
                &m->basic.configuration_set_group_rotation_frequency_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13065: /* module 51 call 9 */
        switch (itemIdx) {
        case 0: /* configuration_set_paras_availability_period_V26 - new_ */;
            return _toStringBlockNumber(
                &m->basic.configuration_set_paras_availability_period_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13067: /* module 51 call 11 */
        switch (itemIdx) {
        case 0: /* configuration_set_scheduling_lookahead_V26 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_scheduling_lookahead_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13068: /* module 51 call 12 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_validators_per_core_V26 - new_ */;
            return _toStringOptionu32(
                &m->basic.configuration_set_max_validators_per_core_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13069: /* module 51 call 13 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_validators_V26 - new_ */;
            return _toStringOptionu32(
                &m->basic.configuration_set_max_validators_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13070: /* module 51 call 14 */
        switch (itemIdx) {
        case 0: /* configuration_set_dispute_period_V26 - new_ */;
            return _toStringSessionIndex(
                &m->basic.configuration_set_dispute_period_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13071: /* module 51 call 15 */
        switch (itemIdx) {
        case 0: /* configuration_set_dispute_post_conclusion_acceptance_period_V26 - new_ */;
            return _toStringBlockNumber(
                &m->basic.configuration_set_dispute_post_conclusion_acceptance_period_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13074: /* module 51 call 18 */
        switch (itemIdx) {
        case 0: /* configuration_set_no_show_slots_V26 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_no_show_slots_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13075: /* module 51 call 19 */
        switch (itemIdx) {
        case 0: /* configuration_set_n_delay_tranches_V26 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_n_delay_tranches_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13076: /* module 51 call 20 */
        switch (itemIdx) {
        case 0: /* configuration_set_zeroth_delay_tranche_width_V26 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_zeroth_delay_tranche_width_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13077: /* module 51 call 21 */
        switch (itemIdx) {
        case 0: /* configuration_set_needed_approvals_V26 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_needed_approvals_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13078: /* module 51 call 22 */
        switch (itemIdx) {
        case 0: /* configuration_set_relay_vrf_modulo_samples_V26 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_relay_vrf_modulo_samples_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13079: /* module 51 call 23 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_upward_queue_count_V26 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_max_upward_queue_count_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13080: /* module 51 call 24 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_upward_queue_size_V26 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_max_upward_queue_size_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13081: /* module 51 call 25 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_downward_message_size_V26 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_max_downward_message_size_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13083: /* module 51 call 27 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_upward_message_size_V26 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_max_upward_message_size_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13084: /* module 51 call 28 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_upward_message_num_per_candidate_V26 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_max_upward_message_num_per_candidate_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13085: /* module 51 call 29 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_open_request_ttl_V26 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_hrmp_open_request_ttl_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13086: /* module 51 call 30 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_sender_deposit_V26 - new_ */;
            return _toStringBalance(
                &m->basic.configuration_set_hrmp_sender_deposit_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13087: /* module 51 call 31 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_recipient_deposit_V26 - new_ */;
            return _toStringBalance(
                &m->basic.configuration_set_hrmp_recipient_deposit_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13088: /* module 51 call 32 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_channel_max_capacity_V26 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_hrmp_channel_max_capacity_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13089: /* module 51 call 33 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_channel_max_total_size_V26 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_hrmp_channel_max_total_size_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13090: /* module 51 call 34 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_max_parachain_inbound_channels_V26 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_hrmp_max_parachain_inbound_channels_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13092: /* module 51 call 36 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_channel_max_message_size_V26 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_hrmp_channel_max_message_size_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13093: /* module 51 call 37 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_max_parachain_outbound_channels_V26 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_hrmp_max_parachain_outbound_channels_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13095: /* module 51 call 39 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_max_message_num_per_candidate_V26 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_hrmp_max_message_num_per_candidate_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13098: /* module 51 call 42 */
        switch (itemIdx) {
        case 0: /* configuration_set_pvf_voting_ttl_V26 - new_ */;
            return _toStringSessionIndex(
                &m->basic.configuration_set_pvf_voting_ttl_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13099: /* module 51 call 43 */
        switch (itemIdx) {
        case 0: /* configuration_set_minimum_validation_upgrade_delay_V26 - new_ */;
            return _toStringBlockNumber(
                &m->basic.configuration_set_minimum_validation_upgrade_delay_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13100: /* module 51 call 44 */
        switch (itemIdx) {
        case 0: /* configuration_set_bypass_consistency_check_V26 - new_ */;
            return _toStringbool(
                &m->basic.configuration_set_bypass_consistency_check_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13103: /* module 51 call 47 */
        switch (itemIdx) {
        case 0: /* configuration_set_on_demand_base_fee_V26 - new_ */;
            return _toStringBalance(
                &m->basic.configuration_set_on_demand_base_fee_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13104: /* module 51 call 48 */
        switch (itemIdx) {
        case 0: /* configuration_set_on_demand_fee_variability_V26 - new_ */;
            return _toStringPerbill(
                &m->basic.configuration_set_on_demand_fee_variability_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13105: /* module 51 call 49 */
        switch (itemIdx) {
        case 0: /* configuration_set_on_demand_queue_max_size_V26 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_on_demand_queue_max_size_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13106: /* module 51 call 50 */
        switch (itemIdx) {
        case 0: /* configuration_set_on_demand_target_queue_utilization_V26 - new_ */;
            return _toStringPerbill(
                &m->basic.configuration_set_on_demand_target_queue_utilization_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13107: /* module 51 call 51 */
        switch (itemIdx) {
        case 0: /* configuration_set_on_demand_ttl_V26 - new_ */;
            return _toStringBlockNumber(
                &m->basic.configuration_set_on_demand_ttl_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13108: /* module 51 call 52 */
        switch (itemIdx) {
        case 0: /* configuration_set_minimum_backing_votes_V26 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_minimum_backing_votes_V26.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13109: /* module 51 call 53 */
        switch (itemIdx) {
        case 0: /* configuration_set_node_feature_V26 - index */;
            return _toStringu8(
                &m->basic.configuration_set_node_feature_V26.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* configuration_set_node_feature_V26 - value */;
            return _toStringbool(
                &m->basic.configuration_set_node_feature_V26.value,
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

bool _getMethod_ItemIsExpert_V26(uint8_t moduleIdx, uint8_t callIdx, __Z_UNUSED uint8_t itemIdx)
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
    case 1556: // Staking:Reap stash
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

bool _getMethod_IsNestingSupported_V26(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 9: // System:Authorize upgrade
    case 10: // System:Authorize upgrade without checks
    case 11: // System:Apply authorized upgrade
    case 1029: // Balances:Force unreserve
    case 1030: // Balances:Upgrade accounts
    case 1032: // Balances:Force set balance
    case 1545: // Staking:Set validator count
    case 1546: // Staking:Increase validator count
    case 1547: // Staking:Scale validator count
    case 1548: // Staking:Force no eras
    case 1549: // Staking:Force new era
    case 1550: // Staking:Set invulnerables
    case 1551: // Staking:Force unstake
    case 1552: // Staking:Force new era always
    case 1553: // Staking:Cancel deferred slash
    case 1556: // Staking:Reap stash
    case 1557: // Staking:Kick
    case 1558: // Staking:Set staking configs
    case 1559: // Staking:Chill other
    case 1560: // Staking:Force apply min commission
    case 1561: // Staking:Set min commission
    case 1562: // Staking:Payout stakers by page
    case 1563: // Staking:Update payee
    case 4608: // Treasury:Propose spend
    case 4609: // Treasury:Reject proposal
    case 4610: // Treasury:Approve proposal
    case 4611: // Treasury:Spend local
    case 4612: // Treasury:Remove approval
    case 4614: // Treasury:Payout
    case 4615: // Treasury:Check status
    case 4616: // Treasury:Void spend
    case 5376: // Referenda:Submit
    case 5377: // Referenda:Place decision deposit
    case 5378: // Referenda:Refund decision deposit
    case 5379: // Referenda:Cancel
    case 5380: // Referenda:Kill
    case 5381: // Referenda:Nudge referendum
    case 5382: // Referenda:One fewer deciding
    case 5383: // Referenda:Refund submission deposit
    case 5384: // Referenda:Set metadata
    case 6144: // Utility:Batch
    case 6146: // Utility:Batch all
    case 6147: // Utility:Dispatch as
    case 6148: // Utility:Force batch
    case 6149: // Utility:With weight
    case 6400: // Identity:Add registrar
    case 6401: // Identity:Set identity
    case 6402: // Identity:Set subs
    case 6403: // Identity:Clear identity
    case 6404: // Identity:Request judgement
    case 6405: // Identity:Cancel request
    case 6406: // Identity:Set fee
    case 6407: // Identity:Set account id
    case 6409: // Identity:Provide judgement
    case 6410: // Identity:Kill identity
    case 6411: // Identity:Add sub
    case 6412: // Identity:Rename sub
    case 6413: // Identity:Remove sub
    case 6414: // Identity:Quit sub
    case 6415: // Identity:Add username authority
    case 6416: // Identity:Remove username authority
    case 7683: // Proxy:Remove proxies
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
    case 10240: // ChildBounties:Add child bounty
    case 10241: // ChildBounties:Propose curator
    case 10242: // ChildBounties:Accept curator
    case 10243: // ChildBounties:Unassign curator
    case 10244: // ChildBounties:Award child bounty
    case 10245: // ChildBounties:Claim child bounty
    case 10246: // ChildBounties:Close child bounty
    case 10754: // FastUnstake:Control
    case 13056: // Configuration:Set validation upgrade cooldown
    case 13057: // Configuration:Set validation upgrade delay
    case 13058: // Configuration:Set code retention period
    case 13059: // Configuration:Set max code size
    case 13060: // Configuration:Set max pov size
    case 13061: // Configuration:Set max head data size
    case 13062: // Configuration:Set coretime cores
    case 13063: // Configuration:Set on demand retries
    case 13064: // Configuration:Set group rotation frequency
    case 13065: // Configuration:Set paras availability period
    case 13067: // Configuration:Set scheduling lookahead
    case 13068: // Configuration:Set max validators per core
    case 13069: // Configuration:Set max validators
    case 13070: // Configuration:Set dispute period
    case 13071: // Configuration:Set dispute post conclusion acceptance period
    case 13074: // Configuration:Set no show slots
    case 13075: // Configuration:Set n delay tranches
    case 13076: // Configuration:Set zeroth delay tranche width
    case 13077: // Configuration:Set needed approvals
    case 13078: // Configuration:Set relay vrf modulo samples
    case 13079: // Configuration:Set max upward queue count
    case 13080: // Configuration:Set max upward queue size
    case 13081: // Configuration:Set max downward message size
    case 13083: // Configuration:Set max upward message size
    case 13084: // Configuration:Set max upward message num per candidate
    case 13085: // Configuration:Set hrmp open request ttl
    case 13086: // Configuration:Set hrmp sender deposit
    case 13087: // Configuration:Set hrmp recipient deposit
    case 13088: // Configuration:Set hrmp channel max capacity
    case 13089: // Configuration:Set hrmp channel max total size
    case 13090: // Configuration:Set hrmp max parachain inbound channels
    case 13092: // Configuration:Set hrmp channel max message size
    case 13093: // Configuration:Set hrmp max parachain outbound channels
    case 13095: // Configuration:Set hrmp max message num per candidate
    case 13098: // Configuration:Set pvf voting ttl
    case 13099: // Configuration:Set minimum validation upgrade delay
    case 13100: // Configuration:Set bypass consistency check
    case 13103: // Configuration:Set on demand base fee
    case 13104: // Configuration:Set on demand fee variability
    case 13105: // Configuration:Set on demand queue max size
    case 13106: // Configuration:Set on demand target queue utilization
    case 13107: // Configuration:Set on demand ttl
    case 13108: // Configuration:Set minimum backing votes
    case 13109: // Configuration:Set node feature
        return false;
    default:
        return true;
    }
}
