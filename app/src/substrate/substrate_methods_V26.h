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
#pragma once

#ifdef __cplusplus
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"

extern "C" {
#endif

#include "substrate_types.h"
#include "substrate_types_V26.h"
#include <stddef.h>
#include <stdint.h>
#ifdef LEDGER_SPECIFIC
#include "bolos_target.h"
#endif

#define PD_CALL_SYSTEM_V26 0
#define PD_CALL_BALANCES_V26 4
#define PD_CALL_STAKING_V26 6
#define PD_CALL_SESSION_V26 8
#define PD_CALL_TREASURY_V26 18
#define PD_CALL_CONVICTIONVOTING_V26 20
#define PD_CALL_REFERENDA_V26 21
#define PD_CALL_UTILITY_V26 24
#define PD_CALL_IDENTITY_V26 25
#define PD_CALL_PROXY_V26 30
#define PD_CALL_MULTISIG_V26 31
#define PD_CALL_BOUNTIES_V26 35
#define PD_CALL_CHILDBOUNTIES_V26 40
#define PD_CALL_FASTUNSTAKE_V26 42
#define PD_CALL_CONFIGURATION_V26 51

#define PD_CALL_UTILITY_BATCH_V26 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V26_t;

#define PD_CALL_UTILITY_BATCH_ALL_V26 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V26_t;

#define PD_CALL_UTILITY_FORCE_BATCH_V26 4
typedef struct {
    pd_VecCall_t calls;
} pd_utility_force_batch_V26_t;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif

#define PD_CALL_SYSTEM_AUTHORIZE_UPGRADE_V26 9
typedef struct {
    pd_Hash_t code_hash;
} pd_system_authorize_upgrade_V26_t;

#define PD_CALL_SYSTEM_AUTHORIZE_UPGRADE_WITHOUT_CHECKS_V26 10
typedef struct {
    pd_Hash_t code_hash;
} pd_system_authorize_upgrade_without_checks_V26_t;

#define PD_CALL_SYSTEM_APPLY_AUTHORIZED_UPGRADE_V26 11
typedef struct {
    pd_Vecu8_t code;
} pd_system_apply_authorized_upgrade_V26_t;

#define PD_CALL_BALANCES_FORCE_UNRESERVE_V26 5
typedef struct {
    pd_AccountIdLookupOfT_t who;
    pd_Balance_t amount;
} pd_balances_force_unreserve_V26_t;

#define PD_CALL_BALANCES_UPGRADE_ACCOUNTS_V26 6
typedef struct {
    pd_VecAccountId_t who;
} pd_balances_upgrade_accounts_V26_t;

#define PD_CALL_BALANCES_FORCE_SET_BALANCE_V26 8
typedef struct {
    pd_AccountIdLookupOfT_t who;
    pd_CompactBalance_t new_free;
} pd_balances_force_set_balance_V26_t;

#define PD_CALL_STAKING_SET_VALIDATOR_COUNT_V26 9
typedef struct {
    pd_Compactu32_t new_;
} pd_staking_set_validator_count_V26_t;

#define PD_CALL_STAKING_INCREASE_VALIDATOR_COUNT_V26 10
typedef struct {
    pd_Compactu32_t additional;
} pd_staking_increase_validator_count_V26_t;

#define PD_CALL_STAKING_SCALE_VALIDATOR_COUNT_V26 11
typedef struct {
    pd_Percent_t factor;
} pd_staking_scale_validator_count_V26_t;

#define PD_CALL_STAKING_FORCE_NO_ERAS_V26 12
typedef struct {
} pd_staking_force_no_eras_V26_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_V26 13
typedef struct {
} pd_staking_force_new_era_V26_t;

#define PD_CALL_STAKING_SET_INVULNERABLES_V26 14
typedef struct {
    pd_VecAccountId_t invulnerables;
} pd_staking_set_invulnerables_V26_t;

#define PD_CALL_STAKING_FORCE_UNSTAKE_V26 15
typedef struct {
    pd_AccountId_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_force_unstake_V26_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_ALWAYS_V26 16
typedef struct {
} pd_staking_force_new_era_always_V26_t;

#define PD_CALL_STAKING_CANCEL_DEFERRED_SLASH_V26 17
typedef struct {
    pd_EraIndex_t era;
    pd_Vecu32_t slash_indices;
} pd_staking_cancel_deferred_slash_V26_t;

#define PD_CALL_STAKING_REAP_STASH_V26 20
typedef struct {
    pd_AccountId_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_reap_stash_V26_t;

#define PD_CALL_STAKING_KICK_V26 21
typedef struct {
    pd_VecAccountIdLookupOfT_t who;
} pd_staking_kick_V26_t;

#define PD_CALL_STAKING_SET_STAKING_CONFIGS_V26 22
typedef struct {
    pd_ConfigOpBalanceOfT_t min_nominator_bond;
    pd_ConfigOpBalanceOfT_t min_validator_bond;
    pd_ConfigOpu32_t max_nominator_count;
    pd_ConfigOpu32_t max_validator_count;
    pd_ConfigOpPercent_t chill_threshold;
    pd_ConfigOpPerbill_t min_commission;
} pd_staking_set_staking_configs_V26_t;

#define PD_CALL_STAKING_CHILL_OTHER_V26 23
typedef struct {
    pd_AccountId_t stash;
} pd_staking_chill_other_V26_t;

#define PD_CALL_STAKING_FORCE_APPLY_MIN_COMMISSION_V26 24
typedef struct {
    pd_AccountId_t validator_stash;
} pd_staking_force_apply_min_commission_V26_t;

#define PD_CALL_STAKING_SET_MIN_COMMISSION_V26 25
typedef struct {
    pd_Perbill_t new_;
} pd_staking_set_min_commission_V26_t;

#define PD_CALL_STAKING_PAYOUT_STAKERS_BY_PAGE_V26 26
typedef struct {
    pd_AccountId_t validator_stash;
    pd_EraIndex_t era;
    pd_Page_t page;
} pd_staking_payout_stakers_by_page_V26_t;

#define PD_CALL_STAKING_UPDATE_PAYEE_V26 27
typedef struct {
    pd_AccountId_t controller;
} pd_staking_update_payee_V26_t;

#define PD_CALL_TREASURY_PROPOSE_SPEND_V26 0
typedef struct {
    pd_CompactBalance_t amount;
    pd_AccountIdLookupOfT_t beneficiary;
} pd_treasury_propose_spend_V26_t;

#define PD_CALL_TREASURY_REJECT_PROPOSAL_V26 1
typedef struct {
    pd_Compactu32_t proposal_id;
} pd_treasury_reject_proposal_V26_t;

#define PD_CALL_TREASURY_APPROVE_PROPOSAL_V26 2
typedef struct {
    pd_Compactu32_t proposal_id;
} pd_treasury_approve_proposal_V26_t;

#define PD_CALL_TREASURY_SPEND_LOCAL_V26 3
typedef struct {
    pd_CompactBalance_t amount;
    pd_AccountIdLookupOfT_t beneficiary;
} pd_treasury_spend_local_V26_t;

#define PD_CALL_TREASURY_REMOVE_APPROVAL_V26 4
typedef struct {
    pd_Compactu32_t proposal_id;
} pd_treasury_remove_approval_V26_t;

#define PD_CALL_TREASURY_PAYOUT_V26 6
typedef struct {
    pd_SpendIndex_t index;
} pd_treasury_payout_V26_t;

#define PD_CALL_TREASURY_CHECK_STATUS_V26 7
typedef struct {
    pd_SpendIndex_t index;
} pd_treasury_check_status_V26_t;

#define PD_CALL_TREASURY_VOID_SPEND_V26 8
typedef struct {
    pd_SpendIndex_t index;
} pd_treasury_void_spend_V26_t;

#define PD_CALL_REFERENDA_SUBMIT_V26 0
typedef struct {
    pd_BoxPalletsOrigin_t proposal_origin;
    pd_BoundedCallOfT_t proposal;
    pd_DispatchTimeBlockNumber_t enactment_moment;
} pd_referenda_submit_V26_t;

#define PD_CALL_REFERENDA_PLACE_DECISION_DEPOSIT_V26 1
typedef struct {
    pd_ReferendumIndex_t index;
} pd_referenda_place_decision_deposit_V26_t;

#define PD_CALL_REFERENDA_REFUND_DECISION_DEPOSIT_V26 2
typedef struct {
    pd_ReferendumIndex_t index;
} pd_referenda_refund_decision_deposit_V26_t;

#define PD_CALL_REFERENDA_CANCEL_V26 3
typedef struct {
    pd_ReferendumIndex_t index;
} pd_referenda_cancel_V26_t;

#define PD_CALL_REFERENDA_KILL_V26 4
typedef struct {
    pd_ReferendumIndex_t index;
} pd_referenda_kill_V26_t;

#define PD_CALL_REFERENDA_NUDGE_REFERENDUM_V26 5
typedef struct {
    pd_ReferendumIndex_t index;
} pd_referenda_nudge_referendum_V26_t;

#define PD_CALL_REFERENDA_ONE_FEWER_DECIDING_V26 6
typedef struct {
    pd_TrackIdOf_t track;
} pd_referenda_one_fewer_deciding_V26_t;

#define PD_CALL_REFERENDA_REFUND_SUBMISSION_DEPOSIT_V26 7
typedef struct {
    pd_ReferendumIndex_t index;
} pd_referenda_refund_submission_deposit_V26_t;

#define PD_CALL_REFERENDA_SET_METADATA_V26 8
typedef struct {
    pd_ReferendumIndex_t index;
    pd_OptionHash_t maybe_hash;
} pd_referenda_set_metadata_V26_t;

#define PD_CALL_UTILITY_DISPATCH_AS_V26 3
typedef struct {
    pd_BoxPalletsOrigin_t as_origin;
    pd_Call_t call;
} pd_utility_dispatch_as_V26_t;

#define PD_CALL_UTILITY_WITH_WEIGHT_V26 5
typedef struct {
    pd_Call_t call;
    pd_Weight_t weight;
} pd_utility_with_weight_V26_t;

#define PD_CALL_IDENTITY_ADD_REGISTRAR_V26 0
typedef struct {
    pd_AccountIdLookupOfT_t account;
} pd_identity_add_registrar_V26_t;

#define PD_CALL_IDENTITY_SET_IDENTITY_V26 1
typedef struct {
    pd_IdentityInfo_t info;
} pd_identity_set_identity_V26_t;

#define PD_CALL_IDENTITY_SET_SUBS_V26 2
typedef struct {
    pd_VecTupleAccountIdData_t subs;
} pd_identity_set_subs_V26_t;

#define PD_CALL_IDENTITY_CLEAR_IDENTITY_V26 3
typedef struct {
} pd_identity_clear_identity_V26_t;

#define PD_CALL_IDENTITY_REQUEST_JUDGEMENT_V26 4
typedef struct {
    pd_Compactu32_t reg_index;
    pd_Compactu128_t max_fee;
} pd_identity_request_judgement_V26_t;

#define PD_CALL_IDENTITY_CANCEL_REQUEST_V26 5
typedef struct {
    pd_RegistrarIndex_t reg_index;
} pd_identity_cancel_request_V26_t;

#define PD_CALL_IDENTITY_SET_FEE_V26 6
typedef struct {
    pd_Compactu32_t index;
    pd_Compactu128_t fee;
} pd_identity_set_fee_V26_t;

#define PD_CALL_IDENTITY_SET_ACCOUNT_ID_V26 7
typedef struct {
    pd_Compactu32_t index;
    pd_AccountIdLookupOfT_t new_;
} pd_identity_set_account_id_V26_t;

#define PD_CALL_IDENTITY_PROVIDE_JUDGEMENT_V26 9
typedef struct {
    pd_Compactu32_t reg_index;
    pd_AccountIdLookupOfT_t target;
    pd_JudgementBalanceOfT_t judgement;
    pd_Hash_t identity;
} pd_identity_provide_judgement_V26_t;

#define PD_CALL_IDENTITY_KILL_IDENTITY_V26 10
typedef struct {
    pd_AccountIdLookupOfT_t target;
} pd_identity_kill_identity_V26_t;

#define PD_CALL_IDENTITY_ADD_SUB_V26 11
typedef struct {
    pd_AccountIdLookupOfT_t sub;
    pd_Data_t data;
} pd_identity_add_sub_V26_t;

#define PD_CALL_IDENTITY_RENAME_SUB_V26 12
typedef struct {
    pd_AccountIdLookupOfT_t sub;
    pd_Data_t data;
} pd_identity_rename_sub_V26_t;

#define PD_CALL_IDENTITY_REMOVE_SUB_V26 13
typedef struct {
    pd_AccountIdLookupOfT_t sub;
} pd_identity_remove_sub_V26_t;

#define PD_CALL_IDENTITY_QUIT_SUB_V26 14
typedef struct {
} pd_identity_quit_sub_V26_t;

#define PD_CALL_IDENTITY_ADD_USERNAME_AUTHORITY_V26 15
typedef struct {
    pd_AccountIdLookupOfT_t authority;
    pd_Vecu8_t suffix;
    pd_u32_t allocation;
} pd_identity_add_username_authority_V26_t;

#define PD_CALL_IDENTITY_REMOVE_USERNAME_AUTHORITY_V26 16
typedef struct {
    pd_AccountIdLookupOfT_t authority;
} pd_identity_remove_username_authority_V26_t;

#define PD_CALL_PROXY_REMOVE_PROXIES_V26 3
typedef struct {
} pd_proxy_remove_proxies_V26_t;

#define PD_CALL_PROXY_PROXY_ANNOUNCED_V26 9
typedef struct {
    pd_AccountIdLookupOfT_t delegate;
    pd_AccountIdLookupOfT_t real;
    pd_OptionProxyType_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_announced_V26_t;

#define PD_CALL_BOUNTIES_PROPOSE_BOUNTY_V26 0
typedef struct {
    pd_CompactBalance_t amount;
    pd_Bytes_t description;
} pd_bounties_propose_bounty_V26_t;

#define PD_CALL_BOUNTIES_APPROVE_BOUNTY_V26 1
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_approve_bounty_V26_t;

#define PD_CALL_BOUNTIES_PROPOSE_CURATOR_V26 2
typedef struct {
    pd_Compactu32_t bounty_id;
    pd_AccountIdLookupOfT_t curator;
    pd_CompactBalance_t fee;
} pd_bounties_propose_curator_V26_t;

#define PD_CALL_BOUNTIES_UNASSIGN_CURATOR_V26 3
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_unassign_curator_V26_t;

#define PD_CALL_BOUNTIES_ACCEPT_CURATOR_V26 4
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_accept_curator_V26_t;

#define PD_CALL_BOUNTIES_AWARD_BOUNTY_V26 5
typedef struct {
    pd_Compactu32_t bounty_id;
    pd_AccountIdLookupOfT_t beneficiary;
} pd_bounties_award_bounty_V26_t;

#define PD_CALL_BOUNTIES_CLAIM_BOUNTY_V26 6
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_claim_bounty_V26_t;

#define PD_CALL_BOUNTIES_CLOSE_BOUNTY_V26 7
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_close_bounty_V26_t;

#define PD_CALL_BOUNTIES_EXTEND_BOUNTY_EXPIRY_V26 8
typedef struct {
    pd_Compactu32_t bounty_id;
    pd_Bytes_t remark;
} pd_bounties_extend_bounty_expiry_V26_t;

#define PD_CALL_CHILDBOUNTIES_ADD_CHILD_BOUNTY_V26 0
typedef struct {
    pd_Compactu32_t parent_bounty_id;
    pd_CompactBalance_t amount;
    pd_Vecu8_t description;
} pd_childbounties_add_child_bounty_V26_t;

#define PD_CALL_CHILDBOUNTIES_PROPOSE_CURATOR_V26 1
typedef struct {
    pd_Compactu32_t parent_bounty_id;
    pd_Compactu32_t child_bounty_id;
    pd_AccountIdLookupOfT_t curator;
    pd_CompactBalance_t fee;
} pd_childbounties_propose_curator_V26_t;

#define PD_CALL_CHILDBOUNTIES_ACCEPT_CURATOR_V26 2
typedef struct {
    pd_Compactu32_t parent_bounty_id;
    pd_Compactu32_t child_bounty_id;
} pd_childbounties_accept_curator_V26_t;

#define PD_CALL_CHILDBOUNTIES_UNASSIGN_CURATOR_V26 3
typedef struct {
    pd_Compactu32_t parent_bounty_id;
    pd_Compactu32_t child_bounty_id;
} pd_childbounties_unassign_curator_V26_t;

#define PD_CALL_CHILDBOUNTIES_AWARD_CHILD_BOUNTY_V26 4
typedef struct {
    pd_Compactu32_t parent_bounty_id;
    pd_Compactu32_t child_bounty_id;
    pd_AccountIdLookupOfT_t beneficiary;
} pd_childbounties_award_child_bounty_V26_t;

#define PD_CALL_CHILDBOUNTIES_CLAIM_CHILD_BOUNTY_V26 5
typedef struct {
    pd_Compactu32_t parent_bounty_id;
    pd_Compactu32_t child_bounty_id;
} pd_childbounties_claim_child_bounty_V26_t;

#define PD_CALL_CHILDBOUNTIES_CLOSE_CHILD_BOUNTY_V26 6
typedef struct {
    pd_Compactu32_t parent_bounty_id;
    pd_Compactu32_t child_bounty_id;
} pd_childbounties_close_child_bounty_V26_t;

#define PD_CALL_FASTUNSTAKE_CONTROL_V26 2
typedef struct {
    pd_EraIndex_t eras_to_check;
} pd_fastunstake_control_V26_t;

#define PD_CALL_CONFIGURATION_SET_VALIDATION_UPGRADE_COOLDOWN_V26 0
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_validation_upgrade_cooldown_V26_t;

#define PD_CALL_CONFIGURATION_SET_VALIDATION_UPGRADE_DELAY_V26 1
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_validation_upgrade_delay_V26_t;

#define PD_CALL_CONFIGURATION_SET_CODE_RETENTION_PERIOD_V26 2
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_code_retention_period_V26_t;

#define PD_CALL_CONFIGURATION_SET_MAX_CODE_SIZE_V26 3
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_code_size_V26_t;

#define PD_CALL_CONFIGURATION_SET_MAX_POV_SIZE_V26 4
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_pov_size_V26_t;

#define PD_CALL_CONFIGURATION_SET_MAX_HEAD_DATA_SIZE_V26 5
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_head_data_size_V26_t;

#define PD_CALL_CONFIGURATION_SET_CORETIME_CORES_V26 6
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_coretime_cores_V26_t;

#define PD_CALL_CONFIGURATION_SET_ON_DEMAND_RETRIES_V26 7
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_on_demand_retries_V26_t;

#define PD_CALL_CONFIGURATION_SET_GROUP_ROTATION_FREQUENCY_V26 8
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_group_rotation_frequency_V26_t;

#define PD_CALL_CONFIGURATION_SET_PARAS_AVAILABILITY_PERIOD_V26 9
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_paras_availability_period_V26_t;

#define PD_CALL_CONFIGURATION_SET_SCHEDULING_LOOKAHEAD_V26 11
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_scheduling_lookahead_V26_t;

#define PD_CALL_CONFIGURATION_SET_MAX_VALIDATORS_PER_CORE_V26 12
typedef struct {
    pd_Optionu32_t new_;
} pd_configuration_set_max_validators_per_core_V26_t;

#define PD_CALL_CONFIGURATION_SET_MAX_VALIDATORS_V26 13
typedef struct {
    pd_Optionu32_t new_;
} pd_configuration_set_max_validators_V26_t;

#define PD_CALL_CONFIGURATION_SET_DISPUTE_PERIOD_V26 14
typedef struct {
    pd_SessionIndex_t new_;
} pd_configuration_set_dispute_period_V26_t;

#define PD_CALL_CONFIGURATION_SET_DISPUTE_POST_CONCLUSION_ACCEPTANCE_PERIOD_V26 15
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_dispute_post_conclusion_acceptance_period_V26_t;

#define PD_CALL_CONFIGURATION_SET_NO_SHOW_SLOTS_V26 18
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_no_show_slots_V26_t;

#define PD_CALL_CONFIGURATION_SET_N_DELAY_TRANCHES_V26 19
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_n_delay_tranches_V26_t;

#define PD_CALL_CONFIGURATION_SET_ZEROTH_DELAY_TRANCHE_WIDTH_V26 20
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_zeroth_delay_tranche_width_V26_t;

#define PD_CALL_CONFIGURATION_SET_NEEDED_APPROVALS_V26 21
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_needed_approvals_V26_t;

#define PD_CALL_CONFIGURATION_SET_RELAY_VRF_MODULO_SAMPLES_V26 22
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_relay_vrf_modulo_samples_V26_t;

#define PD_CALL_CONFIGURATION_SET_MAX_UPWARD_QUEUE_COUNT_V26 23
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_upward_queue_count_V26_t;

#define PD_CALL_CONFIGURATION_SET_MAX_UPWARD_QUEUE_SIZE_V26 24
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_upward_queue_size_V26_t;

#define PD_CALL_CONFIGURATION_SET_MAX_DOWNWARD_MESSAGE_SIZE_V26 25
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_downward_message_size_V26_t;

#define PD_CALL_CONFIGURATION_SET_MAX_UPWARD_MESSAGE_SIZE_V26 27
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_upward_message_size_V26_t;

#define PD_CALL_CONFIGURATION_SET_MAX_UPWARD_MESSAGE_NUM_PER_CANDIDATE_V26 28
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_upward_message_num_per_candidate_V26_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_OPEN_REQUEST_TTL_V26 29
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_open_request_ttl_V26_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_SENDER_DEPOSIT_V26 30
typedef struct {
    pd_Balance_t new_;
} pd_configuration_set_hrmp_sender_deposit_V26_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_RECIPIENT_DEPOSIT_V26 31
typedef struct {
    pd_Balance_t new_;
} pd_configuration_set_hrmp_recipient_deposit_V26_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_CHANNEL_MAX_CAPACITY_V26 32
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_channel_max_capacity_V26_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_CHANNEL_MAX_TOTAL_SIZE_V26 33
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_channel_max_total_size_V26_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_PARACHAIN_INBOUND_CHANNELS_V26 34
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_parachain_inbound_channels_V26_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_CHANNEL_MAX_MESSAGE_SIZE_V26 36
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_channel_max_message_size_V26_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_PARACHAIN_OUTBOUND_CHANNELS_V26 37
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_parachain_outbound_channels_V26_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_MESSAGE_NUM_PER_CANDIDATE_V26 39
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_message_num_per_candidate_V26_t;

#define PD_CALL_CONFIGURATION_SET_PVF_VOTING_TTL_V26 42
typedef struct {
    pd_SessionIndex_t new_;
} pd_configuration_set_pvf_voting_ttl_V26_t;

#define PD_CALL_CONFIGURATION_SET_MINIMUM_VALIDATION_UPGRADE_DELAY_V26 43
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_minimum_validation_upgrade_delay_V26_t;

#define PD_CALL_CONFIGURATION_SET_BYPASS_CONSISTENCY_CHECK_V26 44
typedef struct {
    pd_bool_t new_;
} pd_configuration_set_bypass_consistency_check_V26_t;

#define PD_CALL_CONFIGURATION_SET_ON_DEMAND_BASE_FEE_V26 47
typedef struct {
    pd_Balance_t new_;
} pd_configuration_set_on_demand_base_fee_V26_t;

#define PD_CALL_CONFIGURATION_SET_ON_DEMAND_FEE_VARIABILITY_V26 48
typedef struct {
    pd_Perbill_t new_;
} pd_configuration_set_on_demand_fee_variability_V26_t;

#define PD_CALL_CONFIGURATION_SET_ON_DEMAND_QUEUE_MAX_SIZE_V26 49
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_on_demand_queue_max_size_V26_t;

#define PD_CALL_CONFIGURATION_SET_ON_DEMAND_TARGET_QUEUE_UTILIZATION_V26 50
typedef struct {
    pd_Perbill_t new_;
} pd_configuration_set_on_demand_target_queue_utilization_V26_t;

#define PD_CALL_CONFIGURATION_SET_ON_DEMAND_TTL_V26 51
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_on_demand_ttl_V26_t;

#define PD_CALL_CONFIGURATION_SET_MINIMUM_BACKING_VOTES_V26 52
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_minimum_backing_votes_V26_t;

#define PD_CALL_CONFIGURATION_SET_NODE_FEATURE_V26 53
typedef struct {
    pd_u8_t index;
    pd_bool_t value;
} pd_configuration_set_node_feature_V26_t;

#endif

typedef union {
    pd_utility_batch_V26_t utility_batch_V26;
    pd_utility_batch_all_V26_t utility_batch_all_V26;
    pd_utility_force_batch_V26_t utility_force_batch_V26;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    pd_system_authorize_upgrade_V26_t system_authorize_upgrade_V26;
    pd_system_authorize_upgrade_without_checks_V26_t system_authorize_upgrade_without_checks_V26;
    pd_system_apply_authorized_upgrade_V26_t system_apply_authorized_upgrade_V26;
    pd_balances_force_unreserve_V26_t balances_force_unreserve_V26;
    pd_balances_upgrade_accounts_V26_t balances_upgrade_accounts_V26;
    pd_balances_force_set_balance_V26_t balances_force_set_balance_V26;
    pd_staking_set_validator_count_V26_t staking_set_validator_count_V26;
    pd_staking_increase_validator_count_V26_t staking_increase_validator_count_V26;
    pd_staking_scale_validator_count_V26_t staking_scale_validator_count_V26;
    pd_staking_force_no_eras_V26_t staking_force_no_eras_V26;
    pd_staking_force_new_era_V26_t staking_force_new_era_V26;
    pd_staking_set_invulnerables_V26_t staking_set_invulnerables_V26;
    pd_staking_force_unstake_V26_t staking_force_unstake_V26;
    pd_staking_force_new_era_always_V26_t staking_force_new_era_always_V26;
    pd_staking_cancel_deferred_slash_V26_t staking_cancel_deferred_slash_V26;
    pd_staking_reap_stash_V26_t staking_reap_stash_V26;
    pd_staking_kick_V26_t staking_kick_V26;
    pd_staking_set_staking_configs_V26_t staking_set_staking_configs_V26;
    pd_staking_chill_other_V26_t staking_chill_other_V26;
    pd_staking_force_apply_min_commission_V26_t staking_force_apply_min_commission_V26;
    pd_staking_set_min_commission_V26_t staking_set_min_commission_V26;
    pd_staking_payout_stakers_by_page_V26_t staking_payout_stakers_by_page_V26;
    pd_staking_update_payee_V26_t staking_update_payee_V26;
    pd_treasury_propose_spend_V26_t treasury_propose_spend_V26;
    pd_treasury_reject_proposal_V26_t treasury_reject_proposal_V26;
    pd_treasury_approve_proposal_V26_t treasury_approve_proposal_V26;
    pd_treasury_spend_local_V26_t treasury_spend_local_V26;
    pd_treasury_remove_approval_V26_t treasury_remove_approval_V26;
    pd_treasury_payout_V26_t treasury_payout_V26;
    pd_treasury_check_status_V26_t treasury_check_status_V26;
    pd_treasury_void_spend_V26_t treasury_void_spend_V26;
    pd_referenda_submit_V26_t referenda_submit_V26;
    pd_referenda_place_decision_deposit_V26_t referenda_place_decision_deposit_V26;
    pd_referenda_refund_decision_deposit_V26_t referenda_refund_decision_deposit_V26;
    pd_referenda_cancel_V26_t referenda_cancel_V26;
    pd_referenda_kill_V26_t referenda_kill_V26;
    pd_referenda_nudge_referendum_V26_t referenda_nudge_referendum_V26;
    pd_referenda_one_fewer_deciding_V26_t referenda_one_fewer_deciding_V26;
    pd_referenda_refund_submission_deposit_V26_t referenda_refund_submission_deposit_V26;
    pd_referenda_set_metadata_V26_t referenda_set_metadata_V26;
    pd_utility_dispatch_as_V26_t utility_dispatch_as_V26;
    pd_utility_with_weight_V26_t utility_with_weight_V26;
    pd_identity_add_registrar_V26_t identity_add_registrar_V26;
    pd_identity_set_identity_V26_t identity_set_identity_V26;
    pd_identity_set_subs_V26_t identity_set_subs_V26;
    pd_identity_clear_identity_V26_t identity_clear_identity_V26;
    pd_identity_request_judgement_V26_t identity_request_judgement_V26;
    pd_identity_cancel_request_V26_t identity_cancel_request_V26;
    pd_identity_set_fee_V26_t identity_set_fee_V26;
    pd_identity_set_account_id_V26_t identity_set_account_id_V26;
    pd_identity_provide_judgement_V26_t identity_provide_judgement_V26;
    pd_identity_kill_identity_V26_t identity_kill_identity_V26;
    pd_identity_add_sub_V26_t identity_add_sub_V26;
    pd_identity_rename_sub_V26_t identity_rename_sub_V26;
    pd_identity_remove_sub_V26_t identity_remove_sub_V26;
    pd_identity_quit_sub_V26_t identity_quit_sub_V26;
    pd_identity_add_username_authority_V26_t identity_add_username_authority_V26;
    pd_identity_remove_username_authority_V26_t identity_remove_username_authority_V26;
    pd_proxy_remove_proxies_V26_t proxy_remove_proxies_V26;
    pd_proxy_proxy_announced_V26_t proxy_proxy_announced_V26;
    pd_bounties_propose_bounty_V26_t bounties_propose_bounty_V26;
    pd_bounties_approve_bounty_V26_t bounties_approve_bounty_V26;
    pd_bounties_propose_curator_V26_t bounties_propose_curator_V26;
    pd_bounties_unassign_curator_V26_t bounties_unassign_curator_V26;
    pd_bounties_accept_curator_V26_t bounties_accept_curator_V26;
    pd_bounties_award_bounty_V26_t bounties_award_bounty_V26;
    pd_bounties_claim_bounty_V26_t bounties_claim_bounty_V26;
    pd_bounties_close_bounty_V26_t bounties_close_bounty_V26;
    pd_bounties_extend_bounty_expiry_V26_t bounties_extend_bounty_expiry_V26;
    pd_childbounties_add_child_bounty_V26_t childbounties_add_child_bounty_V26;
    pd_childbounties_propose_curator_V26_t childbounties_propose_curator_V26;
    pd_childbounties_accept_curator_V26_t childbounties_accept_curator_V26;
    pd_childbounties_unassign_curator_V26_t childbounties_unassign_curator_V26;
    pd_childbounties_award_child_bounty_V26_t childbounties_award_child_bounty_V26;
    pd_childbounties_claim_child_bounty_V26_t childbounties_claim_child_bounty_V26;
    pd_childbounties_close_child_bounty_V26_t childbounties_close_child_bounty_V26;
    pd_fastunstake_control_V26_t fastunstake_control_V26;
    pd_configuration_set_validation_upgrade_cooldown_V26_t configuration_set_validation_upgrade_cooldown_V26;
    pd_configuration_set_validation_upgrade_delay_V26_t configuration_set_validation_upgrade_delay_V26;
    pd_configuration_set_code_retention_period_V26_t configuration_set_code_retention_period_V26;
    pd_configuration_set_max_code_size_V26_t configuration_set_max_code_size_V26;
    pd_configuration_set_max_pov_size_V26_t configuration_set_max_pov_size_V26;
    pd_configuration_set_max_head_data_size_V26_t configuration_set_max_head_data_size_V26;
    pd_configuration_set_coretime_cores_V26_t configuration_set_coretime_cores_V26;
    pd_configuration_set_on_demand_retries_V26_t configuration_set_on_demand_retries_V26;
    pd_configuration_set_group_rotation_frequency_V26_t configuration_set_group_rotation_frequency_V26;
    pd_configuration_set_paras_availability_period_V26_t configuration_set_paras_availability_period_V26;
    pd_configuration_set_scheduling_lookahead_V26_t configuration_set_scheduling_lookahead_V26;
    pd_configuration_set_max_validators_per_core_V26_t configuration_set_max_validators_per_core_V26;
    pd_configuration_set_max_validators_V26_t configuration_set_max_validators_V26;
    pd_configuration_set_dispute_period_V26_t configuration_set_dispute_period_V26;
    pd_configuration_set_dispute_post_conclusion_acceptance_period_V26_t configuration_set_dispute_post_conclusion_acceptance_period_V26;
    pd_configuration_set_no_show_slots_V26_t configuration_set_no_show_slots_V26;
    pd_configuration_set_n_delay_tranches_V26_t configuration_set_n_delay_tranches_V26;
    pd_configuration_set_zeroth_delay_tranche_width_V26_t configuration_set_zeroth_delay_tranche_width_V26;
    pd_configuration_set_needed_approvals_V26_t configuration_set_needed_approvals_V26;
    pd_configuration_set_relay_vrf_modulo_samples_V26_t configuration_set_relay_vrf_modulo_samples_V26;
    pd_configuration_set_max_upward_queue_count_V26_t configuration_set_max_upward_queue_count_V26;
    pd_configuration_set_max_upward_queue_size_V26_t configuration_set_max_upward_queue_size_V26;
    pd_configuration_set_max_downward_message_size_V26_t configuration_set_max_downward_message_size_V26;
    pd_configuration_set_max_upward_message_size_V26_t configuration_set_max_upward_message_size_V26;
    pd_configuration_set_max_upward_message_num_per_candidate_V26_t configuration_set_max_upward_message_num_per_candidate_V26;
    pd_configuration_set_hrmp_open_request_ttl_V26_t configuration_set_hrmp_open_request_ttl_V26;
    pd_configuration_set_hrmp_sender_deposit_V26_t configuration_set_hrmp_sender_deposit_V26;
    pd_configuration_set_hrmp_recipient_deposit_V26_t configuration_set_hrmp_recipient_deposit_V26;
    pd_configuration_set_hrmp_channel_max_capacity_V26_t configuration_set_hrmp_channel_max_capacity_V26;
    pd_configuration_set_hrmp_channel_max_total_size_V26_t configuration_set_hrmp_channel_max_total_size_V26;
    pd_configuration_set_hrmp_max_parachain_inbound_channels_V26_t configuration_set_hrmp_max_parachain_inbound_channels_V26;
    pd_configuration_set_hrmp_channel_max_message_size_V26_t configuration_set_hrmp_channel_max_message_size_V26;
    pd_configuration_set_hrmp_max_parachain_outbound_channels_V26_t configuration_set_hrmp_max_parachain_outbound_channels_V26;
    pd_configuration_set_hrmp_max_message_num_per_candidate_V26_t configuration_set_hrmp_max_message_num_per_candidate_V26;
    pd_configuration_set_pvf_voting_ttl_V26_t configuration_set_pvf_voting_ttl_V26;
    pd_configuration_set_minimum_validation_upgrade_delay_V26_t configuration_set_minimum_validation_upgrade_delay_V26;
    pd_configuration_set_bypass_consistency_check_V26_t configuration_set_bypass_consistency_check_V26;
    pd_configuration_set_on_demand_base_fee_V26_t configuration_set_on_demand_base_fee_V26;
    pd_configuration_set_on_demand_fee_variability_V26_t configuration_set_on_demand_fee_variability_V26;
    pd_configuration_set_on_demand_queue_max_size_V26_t configuration_set_on_demand_queue_max_size_V26;
    pd_configuration_set_on_demand_target_queue_utilization_V26_t configuration_set_on_demand_target_queue_utilization_V26;
    pd_configuration_set_on_demand_ttl_V26_t configuration_set_on_demand_ttl_V26;
    pd_configuration_set_minimum_backing_votes_V26_t configuration_set_minimum_backing_votes_V26;
    pd_configuration_set_node_feature_V26_t configuration_set_node_feature_V26;
#endif
} pd_MethodBasic_V26_t;

#define PD_CALL_BALANCES_TRANSFER_ALLOW_DEATH_V26 0
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_allow_death_V26_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V26 2
typedef struct {
    pd_AccountIdLookupOfT_t source;
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_force_transfer_V26_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V26 3
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_keep_alive_V26_t;

#define PD_CALL_BALANCES_TRANSFER_ALL_V26 4
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_V26_t;

#define PD_CALL_STAKING_BOND_V26 0
typedef struct {
    pd_CompactBalance_t amount;
    pd_RewardDestination_t payee;
} pd_staking_bond_V26_t;

#define PD_CALL_STAKING_BOND_EXTRA_V26 1
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_bond_extra_V26_t;

#define PD_CALL_STAKING_UNBOND_V26 2
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_unbond_V26_t;

#define PD_CALL_STAKING_WITHDRAW_UNBONDED_V26 3
typedef struct {
    pd_u32_t num_slashing_spans;
} pd_staking_withdraw_unbonded_V26_t;

#define PD_CALL_STAKING_VALIDATE_V26 4
typedef struct {
    pd_ValidatorPrefs_t prefs;
} pd_staking_validate_V26_t;

#define PD_CALL_STAKING_NOMINATE_V26 5
typedef struct {
    pd_VecAccountIdLookupOfT_t targets;
} pd_staking_nominate_V26_t;

#define PD_CALL_STAKING_CHILL_V26 6
typedef struct {
} pd_staking_chill_V26_t;

#define PD_CALL_STAKING_SET_PAYEE_V26 7
typedef struct {
    pd_RewardDestination_t payee;
} pd_staking_set_payee_V26_t;

#define PD_CALL_STAKING_SET_CONTROLLER_V26 8
typedef struct {
} pd_staking_set_controller_V26_t;

#define PD_CALL_STAKING_PAYOUT_STAKERS_V26 18
typedef struct {
    pd_AccountId_t validator_stash;
    pd_EraIndex_t era;
} pd_staking_payout_stakers_V26_t;

#define PD_CALL_STAKING_REBOND_V26 19
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_rebond_V26_t;

#define PD_CALL_SESSION_SET_KEYS_V26 0
typedef struct {
    pd_Keys_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V26_t;

#define PD_CALL_SESSION_PURGE_KEYS_V26 1
typedef struct {
} pd_session_purge_keys_V26_t;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
#define PD_CALL_SYSTEM_REMARK_V26 0
typedef struct {
    pd_Bytes_t remark;
} pd_system_remark_V26_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V26 1
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V26_t;

#define PD_CALL_SYSTEM_SET_CODE_V26 2
typedef struct {
    pd_Bytes_t code;
} pd_system_set_code_V26_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V26 3
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_without_checks_V26_t;

#define PD_CALL_SYSTEM_REMARK_WITH_EVENT_V26 7
typedef struct {
    pd_Bytes_t remark;
} pd_system_remark_with_event_V26_t;

#define PD_CALL_CONVICTIONVOTING_VOTE_V26 0
typedef struct {
    pd_Compactu32_t poll_index;
    pd_AccountVote_t vote;
} pd_convictionvoting_vote_V26_t;

#define PD_CALL_CONVICTIONVOTING_DELEGATE_V26 1
typedef struct {
    pd_ClassOf_t class_;
    pd_AccountIdLookupOfT_t to;
    pd_Conviction_t conviction;
    pd_BalanceOf_t balance;
} pd_convictionvoting_delegate_V26_t;

#define PD_CALL_CONVICTIONVOTING_UNDELEGATE_V26 2
typedef struct {
    pd_ClassOf_t class_;
} pd_convictionvoting_undelegate_V26_t;

#define PD_CALL_CONVICTIONVOTING_UNLOCK_V26 3
typedef struct {
    pd_ClassOf_t class_;
    pd_AccountIdLookupOfT_t target;
} pd_convictionvoting_unlock_V26_t;

#define PD_CALL_CONVICTIONVOTING_REMOVE_VOTE_V26 4
typedef struct {
    pd_OptionClassOf_t class_;
    pd_PollIndexOf_t index;
} pd_convictionvoting_remove_vote_V26_t;

#define PD_CALL_CONVICTIONVOTING_REMOVE_OTHER_VOTE_V26 5
typedef struct {
    pd_AccountIdLookupOfT_t target;
    pd_ClassOf_t class_;
    pd_PollIndexOf_t index;
} pd_convictionvoting_remove_other_vote_V26_t;

#define PD_CALL_PROXY_PROXY_V26 0
typedef struct {
    pd_AccountIdLookupOfT_t real;
    pd_OptionProxyType_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_V26_t;

#define PD_CALL_PROXY_ADD_PROXY_V26 1
typedef struct {
    pd_AccountIdLookupOfT_t delegate;
    pd_ProxyType_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_add_proxy_V26_t;

#define PD_CALL_PROXY_REMOVE_PROXY_V26 2
typedef struct {
    pd_AccountIdLookupOfT_t delegate;
    pd_ProxyType_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_remove_proxy_V26_t;

#define PD_CALL_PROXY_CREATE_PURE_V26 4
typedef struct {
    pd_ProxyType_t proxy_type;
    pd_BlockNumber_t delay;
    pd_u16_t index;
} pd_proxy_create_pure_V26_t;

#define PD_CALL_PROXY_KILL_PURE_V26 5
typedef struct {
    pd_AccountIdLookupOfT_t spawner;
    pd_ProxyType_t proxy_type;
    pd_u16_t index;
    pd_Compactu32_t height;
    pd_Compactu32_t ext_index;
} pd_proxy_kill_pure_V26_t;

#define PD_CALL_MULTISIG_AS_MULTI_THRESHOLD_1_V26 0
typedef struct {
    pd_VecAccountId_t other_signatories;
    pd_Call_t call;
} pd_multisig_as_multi_threshold_1_V26_t;

#define PD_CALL_MULTISIG_AS_MULTI_V26 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_t other_signatories;
    pd_OptionTimepoint_t maybe_timepoint;
    pd_Call_t call;
    pd_Weight_t max_weight;
} pd_multisig_as_multi_V26_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI_V26 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_t other_signatories;
    pd_OptionTimepoint_t maybe_timepoint;
    pd_H256_t call_hash;
    pd_Weight_t max_weight;
} pd_multisig_approve_as_multi_V26_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V26 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_t other_signatories;
    pd_Timepoint_t timepoint;
    pd_H256_t call_hash;
} pd_multisig_cancel_as_multi_V26_t;

#define PD_CALL_FASTUNSTAKE_REGISTER_FAST_UNSTAKE_V26 0
typedef struct {
} pd_fastunstake_register_fast_unstake_V26_t;

#define PD_CALL_FASTUNSTAKE_DEREGISTER_V26 1
typedef struct {
} pd_fastunstake_deregister_V26_t;

#endif

typedef union {
    pd_balances_transfer_allow_death_V26_t balances_transfer_allow_death_V26;
    pd_balances_force_transfer_V26_t balances_force_transfer_V26;
    pd_balances_transfer_keep_alive_V26_t balances_transfer_keep_alive_V26;
    pd_balances_transfer_all_V26_t balances_transfer_all_V26;
    pd_staking_bond_V26_t staking_bond_V26;
    pd_staking_bond_extra_V26_t staking_bond_extra_V26;
    pd_staking_unbond_V26_t staking_unbond_V26;
    pd_staking_withdraw_unbonded_V26_t staking_withdraw_unbonded_V26;
    pd_staking_validate_V26_t staking_validate_V26;
    pd_staking_nominate_V26_t staking_nominate_V26;
    pd_staking_chill_V26_t staking_chill_V26;
    pd_staking_set_payee_V26_t staking_set_payee_V26;
    pd_staking_set_controller_V26_t staking_set_controller_V26;
    pd_staking_payout_stakers_V26_t staking_payout_stakers_V26;
    pd_staking_rebond_V26_t staking_rebond_V26;
    pd_session_set_keys_V26_t session_set_keys_V26;
    pd_session_purge_keys_V26_t session_purge_keys_V26;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    pd_system_remark_V26_t system_remark_V26;
    pd_system_set_heap_pages_V26_t system_set_heap_pages_V26;
    pd_system_set_code_V26_t system_set_code_V26;
    pd_system_set_code_without_checks_V26_t system_set_code_without_checks_V26;
    pd_system_remark_with_event_V26_t system_remark_with_event_V26;
    pd_convictionvoting_vote_V26_t convictionvoting_vote_V26;
    pd_convictionvoting_delegate_V26_t convictionvoting_delegate_V26;
    pd_convictionvoting_undelegate_V26_t convictionvoting_undelegate_V26;
    pd_convictionvoting_unlock_V26_t convictionvoting_unlock_V26;
    pd_convictionvoting_remove_vote_V26_t convictionvoting_remove_vote_V26;
    pd_convictionvoting_remove_other_vote_V26_t convictionvoting_remove_other_vote_V26;
    pd_proxy_proxy_V26_t proxy_proxy_V26;
    pd_proxy_add_proxy_V26_t proxy_add_proxy_V26;
    pd_proxy_remove_proxy_V26_t proxy_remove_proxy_V26;
    pd_proxy_create_pure_V26_t proxy_create_pure_V26;
    pd_proxy_kill_pure_V26_t proxy_kill_pure_V26;
    pd_multisig_as_multi_threshold_1_V26_t multisig_as_multi_threshold_1_V26;
    pd_multisig_as_multi_V26_t multisig_as_multi_V26;
    pd_multisig_approve_as_multi_V26_t multisig_approve_as_multi_V26;
    pd_multisig_cancel_as_multi_V26_t multisig_cancel_as_multi_V26;
    pd_fastunstake_register_fast_unstake_V26_t fastunstake_register_fast_unstake_V26;
    pd_fastunstake_deregister_V26_t fastunstake_deregister_V26;
#endif
} pd_MethodNested_V26_t;

typedef union {
    pd_MethodBasic_V26_t basic;
    pd_MethodNested_V26_t nested;
} pd_Method_V26_t;

#ifdef __cplusplus
}
#pragma clang diagnostic pop
#endif
