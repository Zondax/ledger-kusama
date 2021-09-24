# Ledger Kusama App (eXpeCT ChAoS)

[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)
[![GithubActions](https://github.com/zondax/ledger-kusama/actions/workflows/main.yaml/badge.svg)](https://github.com/Zondax/ledger-kusama/blob/main/.github/workflows/main.yaml)

-------------------

![zondax](docs/zondax.jpg)

_Please visit our website at [zondax.ch](zondax.ch)_

------------------
This project contains the Kusama app (https://kusama.network/) for Ledger Nano S and X.

- Ledger Nano S/X BOLOS app
- Specs / Documentation
- C++ unit tests
- Zemu tests

For more information: [How to build](docs/build.md)

## ATTENTION

Please:

- **Do not use in production**
- **Do not use a Ledger device with funds for development purposes.**
- **Have a separate and marked device that is used ONLY for development and testing**

# Kusama  5.9070.x

## System

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|fill_block |    | :white_check_mark: | :white_check_mark: | `Perbill` _ratio <br/> |
|remark |    | :white_check_mark: | :white_check_mark: | `Bytes` _remark <br/> |
|set_heap_pages |    | :white_check_mark: | :white_check_mark: | `u64` pages <br/> |
|set_code |    | :white_check_mark: | :white_check_mark: | `Bytes` code <br/> |
|set_code_without_checks |    | :white_check_mark: | :white_check_mark: | `Bytes` code <br/> |
|set_changes_trie_config |    |   |   | `Option<ChangesTrieConfiguration>` changes_trie_config <br/> |
|set_storage |    |   |   | `Vec<KeyValue>` items <br/> |
|kill_storage |    |   |   | `Vec<Key>` keys <br/> |
|kill_prefix |    |   |   | `Key` prefix <br/>`u32` _subkeys <br/> |
|remark_with_event |    | :white_check_mark: |   | `Bytes` remark <br/> |

## RandomnessCollectiveFlip

Empty

## Babe

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|report_equivocation |    |   |   | `BabeEquivocationProof` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> |
|report_equivocation_unsigned |    |   |   | `BabeEquivocationProof` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> |
|plan_config_change |    |   |   | `NextConfigDescriptor` config <br/> |

## Timestamp

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|set |    | :white_check_mark: |   | `Compact<Moment>` now <br/> |

## Indices

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|claim |    | :white_check_mark: |   | `AccountIndex` index <br/> |
|transfer |    | :white_check_mark: |   | `AccountId` new <br/>`AccountIndex` index <br/> |
|free |    | :white_check_mark: |   | `AccountIndex` index <br/> |
|force_transfer |    | :white_check_mark: |   | `AccountId` new <br/>`AccountIndex` index <br/>`bool` freeze <br/> |
|freeze |    | :white_check_mark: |   | `AccountIndex` index <br/> |

## Balances

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|transfer | :white_check_mark:  | :white_check_mark: | :white_check_mark: | `LookupSource` dest <br/>`Compact<Balance>` value <br/> |
|set_balance |    | :white_check_mark: | :white_check_mark: | `LookupSource` who <br/>`Compact<Balance>` new_free <br/>`Compact<Balance>` new_reserved <br/> |
|force_transfer |    | :white_check_mark: | :white_check_mark: | `LookupSource` source <br/>`LookupSource` dest <br/>`Compact<Balance>` value <br/> |
|transfer_keep_alive | :white_check_mark:  | :white_check_mark: | :white_check_mark: | `LookupSource` dest <br/>`Compact<Balance>` value <br/> |
|transfer_all |    | :white_check_mark: |   | `LookupSource` dest <br/>`bool` keep_alive <br/> |

## TransactionPayment

Empty

## Authorship

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_uncles |    |   |   | `Vec<Header>` new_uncles <br/> |

## Staking

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|bond | :white_check_mark:  | :white_check_mark: |   | `LookupSource` controller <br/>`Compact<BalanceOf>` value <br/>`RewardDestination` payee <br/> |
|bond_extra | :white_check_mark:  | :white_check_mark: |   | `Compact<BalanceOf>` max_additional <br/> |
|unbond | :white_check_mark:  | :white_check_mark: |   | `Compact<BalanceOf>` value <br/> |
|withdraw_unbonded | :white_check_mark:  | :white_check_mark: |   | `u32` num_slashing_spans <br/> |
|validate | :white_check_mark:  | :white_check_mark: |   | `ValidatorPrefs` prefs <br/> |
|nominate | :white_check_mark:  | :white_check_mark: |   | `Vec<LookupSource>` targets <br/> |
|chill | :white_check_mark:  | :white_check_mark: |   |  |
|set_payee | :white_check_mark:  | :white_check_mark: |   | `RewardDestination` payee <br/> |
|set_controller | :white_check_mark:  | :white_check_mark: |   | `LookupSource` controller <br/> |
|set_validator_count |    | :white_check_mark: |   | `Compact<u32>` new <br/> |
|increase_validator_count |    | :white_check_mark: |   | `Compact<u32>` additional <br/> |
|scale_validator_count |    |   |   | `Percent` factor <br/> |
|force_no_eras |    | :white_check_mark: |   |  |
|force_new_era |    | :white_check_mark: |   |  |
|set_invulnerables |    |   |   | `Vec<AccountId>` invulnerables <br/> |
|force_unstake |    | :white_check_mark: |   | `AccountId` stash <br/>`u32` num_slashing_spans <br/> |
|force_new_era_always |    | :white_check_mark: |   |  |
|cancel_deferred_slash |    | :white_check_mark: |   | `EraIndex` era <br/>`Vec<u32>` slash_indices <br/> |
|payout_stakers | :white_check_mark:  | :white_check_mark: |   | `AccountId` validator_stash <br/>`EraIndex` era <br/> |
|rebond | :white_check_mark:  | :white_check_mark: |   | `Compact<BalanceOf>` value <br/> |
|set_history_depth |    | :white_check_mark: |   | `Compact<EraIndex>` new_history_depth <br/>`Compact<u32>` _era_items_deleted <br/> |
|reap_stash |    | :white_check_mark: |   | `AccountId` stash <br/>`u32` num_slashing_spans <br/> |
|kick |    | :white_check_mark: |   | `Vec<LookupSource>` who <br/> |
|update_staking_limits |    | :white_check_mark: |   | `BalanceOf` min_nominator_bond <br/>`BalanceOf` min_validator_bond <br/>`Option<u32>` max_nominator_count <br/>`Option<u32>` max_validator_count <br/> |
|chill_other |    | :white_check_mark: |   | `AccountId` controller <br/> |

## Offences

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|

## Historical

Empty

## Session

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_keys | :white_check_mark:  | :white_check_mark: |   | `Keys` keys <br/>`Bytes` proof <br/> |
|purge_keys | :white_check_mark:  | :white_check_mark: |   |  |

## Grandpa

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|report_equivocation |    |   |   | `GrandpaEquivocationProof` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> |
|report_equivocation_unsigned |    |   |   | `GrandpaEquivocationProof` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> |
|note_stalled |    | :white_check_mark: |   | `BlockNumber` delay <br/>`BlockNumber` best_finalized_block_number <br/> |

## ImOnline

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|heartbeat |    |   |   | `Heartbeat` heartbeat <br/>`Signature` _signature <br/> |

## AuthorityDiscovery

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|

## Democracy

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|propose |    | :white_check_mark: |   | `Hash` proposal_hash <br/>`Compact<BalanceOf>` value <br/> |
|second |    | :white_check_mark: |   | `Compact<PropIndex>` proposal <br/>`Compact<u32>` seconds_upper_bound <br/> |
|vote |    | :white_check_mark: |   | `Compact<ReferendumIndex>` ref_index <br/>`AccountVote` vote <br/> |
|emergency_cancel |    | :white_check_mark: |   | `ReferendumIndex` ref_index <br/> |
|external_propose |    | :white_check_mark: |   | `Hash` proposal_hash <br/> |
|external_propose_majority |    | :white_check_mark: |   | `Hash` proposal_hash <br/> |
|external_propose_default |    | :white_check_mark: |   | `Hash` proposal_hash <br/> |
|fast_track |    | :white_check_mark: |   | `Hash` proposal_hash <br/>`BlockNumber` voting_period <br/>`BlockNumber` delay <br/> |
|veto_external |    | :white_check_mark: |   | `Hash` proposal_hash <br/> |
|cancel_referendum |    | :white_check_mark: |   | `Compact<ReferendumIndex>` ref_index <br/> |
|cancel_queued |    | :white_check_mark: |   | `ReferendumIndex` which <br/> |
|delegate |    | :white_check_mark: |   | `AccountId` to <br/>`Conviction` conviction <br/>`BalanceOf` balance <br/> |
|undelegate |    | :white_check_mark: |   |  |
|clear_public_proposals |    | :white_check_mark: |   |  |
|note_preimage |    | :white_check_mark: |   | `Bytes` encoded_proposal <br/> |
|note_preimage_operational |    | :white_check_mark: |   | `Bytes` encoded_proposal <br/> |
|note_imminent_preimage |    | :white_check_mark: |   | `Bytes` encoded_proposal <br/> |
|note_imminent_preimage_operational |    | :white_check_mark: |   | `Bytes` encoded_proposal <br/> |
|reap_preimage |    | :white_check_mark: |   | `Hash` proposal_hash <br/>`Compact<u32>` proposal_len_upper_bound <br/> |
|unlock |    | :white_check_mark: |   | `AccountId` target <br/> |
|remove_vote |    | :white_check_mark: |   | `ReferendumIndex` index <br/> |
|remove_other_vote |    | :white_check_mark: |   | `AccountId` target <br/>`ReferendumIndex` index <br/> |
|enact_proposal |    | :white_check_mark: |   | `Hash` proposal_hash <br/>`ReferendumIndex` index <br/> |
|blacklist |    |   |   | `Hash` proposal_hash <br/>`Option<ReferendumIndex>` maybe_ref_index <br/> |
|cancel_proposal |    | :white_check_mark: |   | `Compact<PropIndex>` prop_index <br/> |

## Council

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_members |    |   |   | `Vec<AccountId>` new_members <br/>`Option<AccountId>` prime <br/>`MemberCount` old_count <br/> |
|execute |    |   |   | `Proposal` proposal <br/>`Compact<u32>` length_bound <br/> |
|propose |    |   |   | `Compact<MemberCount>` threshold <br/>`Proposal` proposal <br/>`Compact<u32>` length_bound <br/> |
|vote |    | :white_check_mark: |   | `Hash` proposal <br/>`Compact<ProposalIndex>` index <br/>`bool` approve <br/> |
|close |    | :white_check_mark: |   | `Hash` proposal_hash <br/>`Compact<ProposalIndex>` index <br/>`Compact<Weight>` proposal_weight_bound <br/>`Compact<u32>` length_bound <br/> |
|disapprove_proposal |    | :white_check_mark: |   | `Hash` proposal_hash <br/> |

## TechnicalCommittee

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_members |    | :white_check_mark: |   | `Vec<AccountId>` new_members <br/>`Option<AccountId>` prime <br/>`MemberCount` old_count <br/> |
|execute |    |   |   | `Proposal` proposal <br/>`Compact<u32>` length_bound <br/> |
|propose |    |   |   | `Compact<MemberCount>` threshold <br/>`Proposal` proposal <br/>`Compact<u32>` length_bound <br/> |
|vote |    | :white_check_mark: |   | `Hash` proposal <br/>`Compact<ProposalIndex>` index <br/>`bool` approve <br/> |
|close |    | :white_check_mark: |   | `Hash` proposal_hash <br/>`Compact<ProposalIndex>` index <br/>`Compact<Weight>` proposal_weight_bound <br/>`Compact<u32>` length_bound <br/> |
|disapprove_proposal |    | :white_check_mark: |   | `Hash` proposal_hash <br/> |

## PhragmenElection

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|vote |    | :white_check_mark: |   | `Vec<AccountId>` votes <br/>`Compact<BalanceOf>` value <br/> |
|remove_voter |    | :white_check_mark: |   |  |
|submit_candidacy |    | :white_check_mark: |   | `Compact<u32>` candidate_count <br/> |
|renounce_candidacy |    |   |   | `Renouncing` renouncing <br/> |
|remove_member |    | :white_check_mark: |   | `LookupSource` who <br/>`bool` has_replacement <br/> |
|clean_defunct_voters |    | :white_check_mark: |   | `u32` _num_voters <br/>`u32` _num_defunct <br/> |

## TechnicalMembership

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|add_member |    | :white_check_mark: |   | `AccountId` who <br/> |
|remove_member |    | :white_check_mark: |   | `AccountId` who <br/> |
|swap_member |    | :white_check_mark: |   | `AccountId` remove <br/>`AccountId` add <br/> |
|reset_members |    | :white_check_mark: |   | `Vec<AccountId>` members <br/> |
|change_key |    | :white_check_mark: |   | `AccountId` new <br/> |
|set_prime |    | :white_check_mark: |   | `AccountId` who <br/> |
|clear_prime |    | :white_check_mark: |   |  |

## Treasury

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|propose_spend |    | :white_check_mark: |   | `Compact<BalanceOf>` value <br/>`LookupSource` beneficiary <br/> |
|reject_proposal |    | :white_check_mark: |   | `Compact<ProposalIndex>` proposal_id <br/> |
|approve_proposal |    | :white_check_mark: |   | `Compact<ProposalIndex>` proposal_id <br/> |

## Claims

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|claim |    | :white_check_mark: |   | `AccountId` dest <br/>`EcdsaSignature` ethereum_signature <br/> |
|mint_claim |    |   |   | `EthereumAddress` who <br/>`BalanceOf` value <br/>`Option<(BalanceOf,BalanceOf,BlockNumber)>` vesting_schedule <br/>`Option<StatementKind>` statement <br/> |
|claim_attest |    | :white_check_mark: |   | `AccountId` dest <br/>`EcdsaSignature` ethereum_signature <br/>`Bytes` statement <br/> |
|attest |    | :white_check_mark: |   | `Bytes` statement <br/> |
|move_claim |    | :white_check_mark: |   | `EthereumAddress` old <br/>`EthereumAddress` new <br/>`Option<AccountId>` maybe_preclaim <br/> |

## Utility

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|batch | :white_check_mark:  | :white_check_mark: |   | `Vec<Call>` calls <br/> |
|as_derivative |    |   |   | `u16` index <br/>`Call` call <br/> |
|batch_all | :white_check_mark:  | :white_check_mark: |   | `Vec<Call>` calls <br/> |

## Identity

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|add_registrar |    | :white_check_mark: |   | `AccountId` account <br/> |
|set_identity |    |   |   | `IdentityInfo` info <br/> |
|set_subs |    |   |   | `Vec<(AccountId,Data)>` subs <br/> |
|clear_identity |    | :white_check_mark: |   |  |
|request_judgement |    | :white_check_mark: |   | `Compact<RegistrarIndex>` reg_index <br/>`Compact<BalanceOf>` max_fee <br/> |
|cancel_request |    | :white_check_mark: |   | `RegistrarIndex` reg_index <br/> |
|set_fee |    | :white_check_mark: |   | `Compact<RegistrarIndex>` index <br/>`Compact<BalanceOf>` fee <br/> |
|set_account_id |    | :white_check_mark: |   | `Compact<RegistrarIndex>` index <br/>`AccountId` new <br/> |
|set_fields |    |   |   | `Compact<RegistrarIndex>` index <br/>`IdentityFields` fields <br/> |
|provide_judgement |    |   |   | `Compact<RegistrarIndex>` reg_index <br/>`LookupSource` target <br/>`IdentityJudgement` judgement <br/> |
|kill_identity |    | :white_check_mark: |   | `LookupSource` target <br/> |
|add_sub |    |   |   | `LookupSource` sub <br/>`Data` data <br/> |
|rename_sub |    |   |   | `LookupSource` sub <br/>`Data` data <br/> |
|remove_sub |    | :white_check_mark: |   | `LookupSource` sub <br/> |
|quit_sub |    | :white_check_mark: |   |  |

## Society

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|bid |    | :white_check_mark: |   | `BalanceOf` value <br/> |
|unbid |    | :white_check_mark: |   | `u32` pos <br/> |
|vouch |    | :white_check_mark: |   | `AccountId` who <br/>`BalanceOf` value <br/>`BalanceOf` tip <br/> |
|unvouch |    | :white_check_mark: |   | `u32` pos <br/> |
|vote |    | :white_check_mark: |   | `LookupSource` candidate <br/>`bool` approve <br/> |
|defender_vote |    | :white_check_mark: |   | `bool` approve <br/> |
|payout |    | :white_check_mark: |   |  |
|found |    | :white_check_mark: |   | `AccountId` founder <br/>`u32` max_members <br/>`Bytes` rules <br/> |
|unfound |    | :white_check_mark: |   |  |
|judge_suspended_member |    | :white_check_mark: |   | `AccountId` who <br/>`bool` forgive <br/> |
|judge_suspended_candidate |    |   |   | `AccountId` who <br/>`SocietyJudgement` judgement <br/> |
|set_max_members |    | :white_check_mark: |   | `u32` max <br/> |

## Recovery

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|as_recovered |    |   |   | `AccountId` account <br/>`Call` call <br/> |
|set_recovered |    | :white_check_mark: |   | `AccountId` lost <br/>`AccountId` rescuer <br/> |
|create_recovery |    |   |   | `Vec<AccountId>` friends <br/>`u16` threshold <br/>`BlockNumber` delay_period <br/> |
|initiate_recovery |    | :white_check_mark: |   | `AccountId` account <br/> |
|vouch_recovery |    | :white_check_mark: |   | `AccountId` lost <br/>`AccountId` rescuer <br/> |
|claim_recovery |    | :white_check_mark: |   | `AccountId` account <br/> |
|close_recovery |    | :white_check_mark: |   | `AccountId` rescuer <br/> |
|remove_recovery |    | :white_check_mark: |   |  |
|cancel_recovered |    | :white_check_mark: |   | `AccountId` account <br/> |

## Vesting

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|vest |    | :white_check_mark: |   |  |
|vest_other |    | :white_check_mark: |   | `LookupSource` target <br/> |
|vested_transfer |    | :white_check_mark: |   | `LookupSource` target <br/>`VestingInfo` schedule <br/> |
|force_vested_transfer |    | :white_check_mark: |   | `LookupSource` source <br/>`LookupSource` target <br/>`VestingInfo` schedule <br/> |

## Scheduler

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|schedule |    |   |   | `BlockNumber` when <br/>`Option<Period>` maybe_periodic <br/>`Priority` priority <br/>`Call` call <br/> |
|cancel |    |   |   | `BlockNumber` when <br/>`u32` index <br/> |
|schedule_named |    |   |   | `Bytes` id <br/>`BlockNumber` when <br/>`Option<Period>` maybe_periodic <br/>`Priority` priority <br/>`Call` call <br/> |
|cancel_named |    |   |   | `Bytes` id <br/> |
|schedule_after |    |   |   | `BlockNumber` after <br/>`Option<Period>` maybe_periodic <br/>`Priority` priority <br/>`Call` call <br/> |
|schedule_named_after |    |   |   | `Bytes` id <br/>`BlockNumber` after <br/>`Option<Period>` maybe_periodic <br/>`Priority` priority <br/>`Call` call <br/> |

## Proxy

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|proxy |    | :white_check_mark: | :white_check_mark: | `AccountId` real <br/>`Option<ProxyType>` force_proxy_type <br/>`Call` call <br/> |
|add_proxy |    | :white_check_mark: |   | `AccountId` delegate <br/>`ProxyType` proxy_type <br/>`BlockNumber` delay <br/> |
|remove_proxy |    | :white_check_mark: |   | `AccountId` delegate <br/>`ProxyType` proxy_type <br/>`BlockNumber` delay <br/> |
|remove_proxies |    | :white_check_mark: |   |  |
|anonymous |    | :white_check_mark: |   | `ProxyType` proxy_type <br/>`BlockNumber` delay <br/>`u16` index <br/> |
|kill_anonymous |    | :white_check_mark: |   | `AccountId` spawner <br/>`ProxyType` proxy_type <br/>`u16` index <br/>`Compact<BlockNumber>` height <br/>`Compact<u32>` ext_index <br/> |
|announce |    | :white_check_mark: |   | `AccountId` real <br/>`CallHashOf` call_hash <br/> |
|remove_announcement |    | :white_check_mark: |   | `AccountId` real <br/>`CallHashOf` call_hash <br/> |
|reject_announcement |    | :white_check_mark: |   | `AccountId` delegate <br/>`CallHashOf` call_hash <br/> |
|proxy_announced |    | :white_check_mark: |   | `AccountId` delegate <br/>`AccountId` real <br/>`Option<ProxyType>` force_proxy_type <br/>`Call` call <br/> |

## Multisig

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|as_multi_threshold_1 |    | :white_check_mark: | :white_check_mark: | `Vec<AccountId>` other_signatories <br/>`Call` call <br/> |
|as_multi |    | :white_check_mark: | :white_check_mark: | `u16` threshold <br/>`Vec<AccountId>` other_signatories <br/>`Option<Timepoint>` maybe_timepoint <br/>`OpaqueCall` call <br/>`bool` store_call <br/>`Weight` max_weight <br/> |
|approve_as_multi |    | :white_check_mark: | :white_check_mark: | `u16` threshold <br/>`Vec<AccountId>` other_signatories <br/>`Option<Timepoint>` maybe_timepoint <br/>`[u8;32]` call_hash <br/>`Weight` max_weight <br/> |
|cancel_as_multi |    | :white_check_mark: | :white_check_mark: | `u16` threshold <br/>`Vec<AccountId>` other_signatories <br/>`Timepoint` timepoint <br/>`[u8;32]` call_hash <br/> |

## Bounties

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|propose_bounty |    | :white_check_mark: |   | `Compact<BalanceOf>` value <br/>`Bytes` description <br/> |
|approve_bounty |    | :white_check_mark: |   | `Compact<BountyIndex>` bounty_id <br/> |
|propose_curator |    | :white_check_mark: |   | `Compact<BountyIndex>` bounty_id <br/>`LookupSource` curator <br/>`Compact<BalanceOf>` fee <br/> |
|unassign_curator |    | :white_check_mark: |   | `Compact<BountyIndex>` bounty_id <br/> |
|accept_curator |    | :white_check_mark: |   | `Compact<BountyIndex>` bounty_id <br/> |
|award_bounty |    | :white_check_mark: |   | `Compact<BountyIndex>` bounty_id <br/>`LookupSource` beneficiary <br/> |
|claim_bounty |    | :white_check_mark: |   | `Compact<BountyIndex>` bounty_id <br/> |
|close_bounty |    | :white_check_mark: |   | `Compact<BountyIndex>` bounty_id <br/> |
|extend_bounty_expiry |    | :white_check_mark: |   | `Compact<BountyIndex>` bounty_id <br/>`Bytes` _remark <br/> |

## Tips

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|report_awesome |    | :white_check_mark: |   | `Bytes` reason <br/>`AccountId` who <br/> |
|retract_tip |    | :white_check_mark: |   | `Hash` hash <br/> |
|tip_new |    | :white_check_mark: |   | `Bytes` reason <br/>`AccountId` who <br/>`Compact<BalanceOf>` tip_value <br/> |
|tip |    | :white_check_mark: |   | `Hash` hash <br/>`Compact<BalanceOf>` tip_value <br/> |
|close_tip |    | :white_check_mark: |   | `Hash` hash <br/> |
|slash_tip |    | :white_check_mark: |   | `Hash` hash <br/> |

## ElectionProviderMultiPhase

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|submit_unsigned |    |   |   | `RawSolution` solution <br/>`SolutionOrSnapshotSize` witness <br/> |
|set_minimum_untrusted_score |    |   |   | `Option<ElectionScore>` maybe_next_score <br/> |
|set_emergency_election_result |    |   |   | `ReadySolution` solution <br/> |

## Gilt

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|place_bid |    | :white_check_mark: |   | `Compact<BalanceOf>` amount <br/>`u32` duration <br/> |
|retract_bid |    | :white_check_mark: |   | `Compact<BalanceOf>` amount <br/>`u32` duration <br/> |
|set_target |    |   |   | `Compact<Perquintill>` target <br/> |
|thaw |    |   |   | `Compact<ActiveIndex>` index <br/> |

## ParachainsOrigin

Empty

## ParachainsConfiguration

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_validation_upgrade_frequency |    | :white_check_mark: |   | `BlockNumber` new <br/> |
|set_validation_upgrade_delay |    | :white_check_mark: |   | `BlockNumber` new <br/> |
|set_code_retention_period |    | :white_check_mark: |   | `BlockNumber` new <br/> |
|set_max_code_size |    | :white_check_mark: |   | `u32` new <br/> |
|set_max_pov_size |    | :white_check_mark: |   | `u32` new <br/> |
|set_max_head_data_size |    | :white_check_mark: |   | `u32` new <br/> |
|set_parathread_cores |    | :white_check_mark: |   | `u32` new <br/> |
|set_parathread_retries |    | :white_check_mark: |   | `u32` new <br/> |
|set_group_rotation_frequency |    | :white_check_mark: |   | `BlockNumber` new <br/> |
|set_chain_availability_period |    | :white_check_mark: |   | `BlockNumber` new <br/> |
|set_thread_availability_period |    | :white_check_mark: |   | `BlockNumber` new <br/> |
|set_scheduling_lookahead |    | :white_check_mark: |   | `u32` new <br/> |
|set_max_validators_per_core |    | :white_check_mark: |   | `Option<u32>` new <br/> |
|set_max_validators |    | :white_check_mark: |   | `Option<u32>` new <br/> |
|set_dispute_period |    |   |   | `SessionIndex` new <br/> |
|set_dispute_post_conclusion_acceptance_period |    | :white_check_mark: |   | `BlockNumber` new <br/> |
|set_dispute_max_spam_slots |    | :white_check_mark: |   | `u32` new <br/> |
|set_dispute_conclusion_by_time_out_period |    | :white_check_mark: |   | `BlockNumber` new <br/> |
|set_no_show_slots |    | :white_check_mark: |   | `u32` new <br/> |
|set_n_delay_tranches |    | :white_check_mark: |   | `u32` new <br/> |
|set_zeroth_delay_tranche_width |    | :white_check_mark: |   | `u32` new <br/> |
|set_needed_approvals |    | :white_check_mark: |   | `u32` new <br/> |
|set_relay_vrf_modulo_samples |    | :white_check_mark: |   | `u32` new <br/> |
|set_max_upward_queue_count |    | :white_check_mark: |   | `u32` new <br/> |
|set_max_upward_queue_size |    | :white_check_mark: |   | `u32` new <br/> |
|set_max_downward_message_size |    | :white_check_mark: |   | `u32` new <br/> |
|set_ump_service_total_weight |    | :white_check_mark: |   | `Weight` new <br/> |
|set_max_upward_message_size |    | :white_check_mark: |   | `u32` new <br/> |
|set_max_upward_message_num_per_candidate |    | :white_check_mark: |   | `u32` new <br/> |
|set_hrmp_open_request_ttl |    | :white_check_mark: |   | `u32` new <br/> |
|set_hrmp_sender_deposit |    | :white_check_mark: |   | `Balance` new <br/> |
|set_hrmp_recipient_deposit |    | :white_check_mark: |   | `Balance` new <br/> |
|set_hrmp_channel_max_capacity |    | :white_check_mark: |   | `u32` new <br/> |
|set_hrmp_channel_max_total_size |    | :white_check_mark: |   | `u32` new <br/> |
|set_hrmp_max_parachain_inbound_channels |    | :white_check_mark: |   | `u32` new <br/> |
|set_hrmp_max_parathread_inbound_channels |    | :white_check_mark: |   | `u32` new <br/> |
|set_hrmp_channel_max_message_size |    | :white_check_mark: |   | `u32` new <br/> |
|set_hrmp_max_parachain_outbound_channels |    | :white_check_mark: |   | `u32` new <br/> |
|set_hrmp_max_parathread_outbound_channels |    | :white_check_mark: |   | `u32` new <br/> |
|set_hrmp_max_message_num_per_candidate |    | :white_check_mark: |   | `u32` new <br/> |

## ParasShared

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|

## ParasInclusion

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|

## ParasInherent

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|enter |    |   |   | `ParachainsInherentData` data <br/> |

## ParasScheduler

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|

## Paras

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|force_set_current_code |    |   |   | `ParaId` para <br/>`ValidationCode` new_code <br/> |
|force_set_current_head |    |   |   | `ParaId` para <br/>`HeadData` new_head <br/> |
|force_schedule_code_upgrade |    |   |   | `ParaId` para <br/>`ValidationCode` new_code <br/>`BlockNumber` expected_at <br/> |
|force_note_new_head |    |   |   | `ParaId` para <br/>`HeadData` new_head <br/> |
|force_queue_action |    |   |   | `ParaId` para <br/> |

## ParasInitializer

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|force_approve |    | :white_check_mark: |   | `BlockNumber` up_to <br/> |

## ParasDmp

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|

## ParasUmp

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|

## ParasHrmp

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|hrmp_init_open_channel |    |   |   | `ParaId` recipient <br/>`u32` proposed_max_capacity <br/>`u32` proposed_max_message_size <br/> |
|hrmp_accept_open_channel |    |   |   | `ParaId` sender <br/> |
|hrmp_close_channel |    |   |   | `HrmpChannelId` channel_id <br/> |
|force_clean_hrmp |    |   |   | `ParaId` para <br/> |
|force_process_hrmp_open |    | :white_check_mark: |   |  |
|force_process_hrmp_close |    | :white_check_mark: |   |  |

## ParasSessionInfo

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|

## Registrar

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|register |    |   |   | `ParaId` id <br/>`HeadData` genesis_head <br/>`ValidationCode` validation_code <br/> |
|force_register |    |   |   | `AccountId` who <br/>`BalanceOf` deposit <br/>`ParaId` id <br/>`HeadData` genesis_head <br/>`ValidationCode` validation_code <br/> |
|deregister |    |   |   | `ParaId` id <br/> |
|swap |    |   |   | `ParaId` id <br/>`ParaId` other <br/> |
|force_remove_lock |    |   |   | `ParaId` para <br/> |
|reserve |    | :white_check_mark: |   |  |

## Slots

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|force_lease |    |   |   | `ParaId` para <br/>`AccountId` leaser <br/>`BalanceOf` amount <br/>`LeasePeriodOf` period_begin <br/>`LeasePeriodOf` period_count <br/> |
|clear_all_leases |    |   |   | `ParaId` para <br/> |
|trigger_onboard |    |   |   | `ParaId` para <br/> |

## Auctions

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|new_auction |    | :white_check_mark: |   | `Compact<BlockNumber>` duration <br/>`Compact<LeasePeriodOf>` lease_period_index <br/> |
|bid |    | :white_check_mark: |   | `Compact<ParaId>` para <br/>`Compact<AuctionIndex>` auction_index <br/>`Compact<LeasePeriodOf>` first_slot <br/>`Compact<LeasePeriodOf>` last_slot <br/>`Compact<BalanceOf>` amount <br/> |
|cancel_auction |    | :white_check_mark: |   |  |

## Crowdloan

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|create |    |   |   | `Compact<ParaId>` index <br/>`Compact<BalanceOf>` cap <br/>`Compact<LeasePeriodOf>` first_period <br/>`Compact<LeasePeriodOf>` last_period <br/>`Compact<BlockNumber>` end <br/>`Option<MultiSigner>` verifier <br/> |
|contribute |    |   |   | `Compact<ParaId>` index <br/>`Compact<BalanceOf>` value <br/>`Option<MultiSignature>` signature <br/> |
|withdraw |    | :white_check_mark: |   | `AccountId` who <br/>`Compact<ParaId>` index <br/> |
|refund |    | :white_check_mark: |   | `Compact<ParaId>` index <br/> |
|dissolve |    | :white_check_mark: |   | `Compact<ParaId>` index <br/> |
|edit |    |   |   | `Compact<ParaId>` index <br/>`Compact<BalanceOf>` cap <br/>`Compact<LeasePeriodOf>` first_period <br/>`Compact<LeasePeriodOf>` last_period <br/>`Compact<BlockNumber>` end <br/>`Option<MultiSigner>` verifier <br/> |
|add_memo |    |   |   | `ParaId` index <br/>`Bytes` memo <br/> |
|poke |    |   |   | `ParaId` index <br/> |

## XcmPallet

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|send |    |   |   | `MultiLocation` dest <br/>`Xcm` message <br/> |
|teleport_assets |    |   |   | `MultiLocation` dest <br/>`MultiLocation` beneficiary <br/>`Vec<MultiAsset>` assets <br/>`Weight` dest_weight <br/> |
|reserve_transfer_assets |    |   |   | `MultiLocation` dest <br/>`MultiLocation` beneficiary <br/>`Vec<MultiAsset>` assets <br/>`Weight` dest_weight <br/> |
|execute |    |   |   | `Xcm` message <br/>`Weight` max_weight <br/> |

