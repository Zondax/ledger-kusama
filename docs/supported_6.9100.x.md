# Kusama  6.9100.x

## System

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|fill_block |    | :heavy_check_mark: | :heavy_check_mark: | `Perbill` _ratio <br/> | 
|remark |    | :heavy_check_mark: | :heavy_check_mark: | `Bytes` _remark <br/> | 
|set_heap_pages |    | :heavy_check_mark: | :heavy_check_mark: | `u64` pages <br/> | 
|set_code |    | :heavy_check_mark: | :heavy_check_mark: | `Bytes` code <br/> | 
|set_code_without_checks |    | :heavy_check_mark: | :heavy_check_mark: | `Bytes` code <br/> | 
|set_changes_trie_config |    |   |   | `Option<ChangesTrieConfiguration>` changes_trie_config <br/> | 
|set_storage |    |   |   | `Vec<KeyValue>` items <br/> | 
|kill_storage |    |   |   | `Vec<Key>` keys <br/> | 
|kill_prefix |    |   |   | `Key` prefix <br/>`u32` _subkeys <br/> | 
|remark_with_event |    | :heavy_check_mark: |   | `Bytes` remark <br/> | 

## Babe

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|report_equivocation |    |   |   | `BabeEquivocationProof` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> | 
|report_equivocation_unsigned |    |   |   | `BabeEquivocationProof` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> | 
|plan_config_change |    |   |   | `NextConfigDescriptor` config <br/> | 

## Timestamp

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set |    | :heavy_check_mark: |   | `Compact<Moment>` now <br/> | 

## Indices

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|claim |    | :heavy_check_mark: |   | `AccountIndex` index <br/> | 
|transfer |    | :heavy_check_mark: |   | `AccountId` new <br/>`AccountIndex` index <br/> | 
|free |    | :heavy_check_mark: |   | `AccountIndex` index <br/> | 
|force_transfer |    | :heavy_check_mark: |   | `AccountId` new <br/>`AccountIndex` index <br/>`bool` freeze <br/> | 
|freeze |    | :heavy_check_mark: |   | `AccountIndex` index <br/> | 

## Balances

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|transfer | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupSource` dest <br/>`Compact<Balance>` value <br/> | 
|set_balance |    | :heavy_check_mark: | :heavy_check_mark: | `LookupSource` who <br/>`Compact<Balance>` new_free <br/>`Compact<Balance>` new_reserved <br/> | 
|force_transfer |    | :heavy_check_mark: | :heavy_check_mark: | `LookupSource` source <br/>`LookupSource` dest <br/>`Compact<Balance>` value <br/> | 
|transfer_keep_alive | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupSource` dest <br/>`Compact<Balance>` value <br/> | 
|transfer_all |    | :heavy_check_mark: |   | `LookupSource` dest <br/>`bool` keep_alive <br/> | 

## TransactionPayment

Empty

## Authorship

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_uncles |    |   |   | `Vec<Header>` new_uncles <br/> | 

## Staking

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|bond | :heavy_check_mark:  | :heavy_check_mark: |   | `LookupSource` controller <br/>`Compact<BalanceOf>` value <br/>`RewardDestination` payee <br/> | 
|bond_extra | :heavy_check_mark:  | :heavy_check_mark: |   | `Compact<BalanceOf>` max_additional <br/> | 
|unbond | :heavy_check_mark:  | :heavy_check_mark: |   | `Compact<BalanceOf>` value <br/> | 
|withdraw_unbonded | :heavy_check_mark:  | :heavy_check_mark: |   | `u32` num_slashing_spans <br/> | 
|validate | :heavy_check_mark:  | :heavy_check_mark: |   | `ValidatorPrefs` prefs <br/> | 
|nominate | :heavy_check_mark:  | :heavy_check_mark: |   | `Vec<LookupSource>` targets <br/> | 
|chill | :heavy_check_mark:  | :heavy_check_mark: |   |  | 
|set_payee | :heavy_check_mark:  | :heavy_check_mark: |   | `RewardDestination` payee <br/> | 
|set_controller | :heavy_check_mark:  | :heavy_check_mark: |   | `LookupSource` controller <br/> | 
|set_validator_count |    | :heavy_check_mark: |   | `Compact<u32>` new <br/> | 
|increase_validator_count |    | :heavy_check_mark: |   | `Compact<u32>` additional <br/> | 
|scale_validator_count |    |   |   | `Percent` factor <br/> | 
|force_no_eras |    | :heavy_check_mark: |   |  | 
|force_new_era |    | :heavy_check_mark: |   |  | 
|set_invulnerables |    |   |   | `Vec<AccountId>` invulnerables <br/> | 
|force_unstake |    | :heavy_check_mark: |   | `AccountId` stash <br/>`u32` num_slashing_spans <br/> | 
|force_new_era_always |    | :heavy_check_mark: |   |  | 
|cancel_deferred_slash |    | :heavy_check_mark: |   | `EraIndex` era <br/>`Vec<u32>` slash_indices <br/> | 
|payout_stakers | :heavy_check_mark:  | :heavy_check_mark: |   | `AccountId` validator_stash <br/>`EraIndex` era <br/> | 
|rebond | :heavy_check_mark:  | :heavy_check_mark: |   | `Compact<BalanceOf>` value <br/> | 
|set_history_depth |    | :heavy_check_mark: |   | `Compact<EraIndex>` new_history_depth <br/>`Compact<u32>` _era_items_deleted <br/> | 
|reap_stash |    | :heavy_check_mark: |   | `AccountId` stash <br/>`u32` num_slashing_spans <br/> | 
|kick |    | :heavy_check_mark: |   | `Vec<LookupSource>` who <br/> | 
|set_staking_limits |    |   |   | `BalanceOf` min_nominator_bond <br/>`BalanceOf` min_validator_bond <br/>`Option<u32>` max_nominator_count <br/>`Option<u32>` max_validator_count <br/>`Option<Percent>` threshold <br/> | 
|chill_other |    | :heavy_check_mark: |   | `AccountId` controller <br/> | 

## Offences

Empty

## Historical

Empty

## Session

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_keys | :heavy_check_mark:  | :heavy_check_mark: |   | `Keys` keys <br/>`Bytes` proof <br/> | 
|purge_keys | :heavy_check_mark:  | :heavy_check_mark: |   |  | 

## Grandpa

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|report_equivocation |    |   |   | `GrandpaEquivocationProof` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> | 
|report_equivocation_unsigned |    |   |   | `GrandpaEquivocationProof` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> | 
|note_stalled |    | :heavy_check_mark: |   | `BlockNumber` delay <br/>`BlockNumber` best_finalized_block_number <br/> | 

## ImOnline

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|heartbeat |    |   |   | `Heartbeat` heartbeat <br/>`Signature` _signature <br/> | 

## AuthorityDiscovery

Empty

## Democracy

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|propose |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/>`Compact<BalanceOf>` value <br/> | 
|second |    | :heavy_check_mark: |   | `Compact<PropIndex>` proposal <br/>`Compact<u32>` seconds_upper_bound <br/> | 
|vote |    | :heavy_check_mark: |   | `Compact<ReferendumIndex>` ref_index <br/>`AccountVote` vote <br/> | 
|emergency_cancel |    | :heavy_check_mark: |   | `ReferendumIndex` ref_index <br/> | 
|external_propose |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/> | 
|external_propose_majority |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/> | 
|external_propose_default |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/> | 
|fast_track |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/>`BlockNumber` voting_period <br/>`BlockNumber` delay <br/> | 
|veto_external |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/> | 
|cancel_referendum |    | :heavy_check_mark: |   | `Compact<ReferendumIndex>` ref_index <br/> | 
|cancel_queued |    | :heavy_check_mark: |   | `ReferendumIndex` which <br/> | 
|delegate |    | :heavy_check_mark: |   | `AccountId` to <br/>`Conviction` conviction <br/>`BalanceOf` balance <br/> | 
|undelegate |    | :heavy_check_mark: |   |  | 
|clear_public_proposals |    | :heavy_check_mark: |   |  | 
|note_preimage |    | :heavy_check_mark: |   | `Bytes` encoded_proposal <br/> | 
|note_preimage_operational |    | :heavy_check_mark: |   | `Bytes` encoded_proposal <br/> | 
|note_imminent_preimage |    | :heavy_check_mark: |   | `Bytes` encoded_proposal <br/> | 
|note_imminent_preimage_operational |    | :heavy_check_mark: |   | `Bytes` encoded_proposal <br/> | 
|reap_preimage |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/>`Compact<u32>` proposal_len_upper_bound <br/> | 
|unlock |    | :heavy_check_mark: |   | `AccountId` target <br/> | 
|remove_vote |    | :heavy_check_mark: |   | `ReferendumIndex` index <br/> | 
|remove_other_vote |    | :heavy_check_mark: |   | `AccountId` target <br/>`ReferendumIndex` index <br/> | 
|enact_proposal |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/>`ReferendumIndex` index <br/> | 
|blacklist |    |   |   | `Hash` proposal_hash <br/>`Option<ReferendumIndex>` maybe_ref_index <br/> | 
|cancel_proposal |    | :heavy_check_mark: |   | `Compact<PropIndex>` prop_index <br/> | 

## Council

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_members |    |   |   | `Vec<AccountId>` new_members <br/>`Option<AccountId>` prime <br/>`MemberCount` old_count <br/> | 
|execute |    |   |   | `Proposal` proposal <br/>`Compact<u32>` length_bound <br/> | 
|propose |    |   |   | `Compact<MemberCount>` threshold <br/>`Proposal` proposal <br/>`Compact<u32>` length_bound <br/> | 
|vote |    | :heavy_check_mark: |   | `Hash` proposal <br/>`Compact<ProposalIndex>` index <br/>`bool` approve <br/> | 
|close |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/>`Compact<ProposalIndex>` index <br/>`Compact<Weight>` proposal_weight_bound <br/>`Compact<u32>` length_bound <br/> | 
|disapprove_proposal |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/> | 

## TechnicalCommittee

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_members |    | :heavy_check_mark: |   | `Vec<AccountId>` new_members <br/>`Option<AccountId>` prime <br/>`MemberCount` old_count <br/> | 
|execute |    |   |   | `Proposal` proposal <br/>`Compact<u32>` length_bound <br/> | 
|propose |    |   |   | `Compact<MemberCount>` threshold <br/>`Proposal` proposal <br/>`Compact<u32>` length_bound <br/> | 
|vote |    | :heavy_check_mark: |   | `Hash` proposal <br/>`Compact<ProposalIndex>` index <br/>`bool` approve <br/> | 
|close |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/>`Compact<ProposalIndex>` index <br/>`Compact<Weight>` proposal_weight_bound <br/>`Compact<u32>` length_bound <br/> | 
|disapprove_proposal |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/> | 

## PhragmenElection

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|vote |    | :heavy_check_mark: |   | `Vec<AccountId>` votes <br/>`Compact<BalanceOf>` value <br/> | 
|remove_voter |    | :heavy_check_mark: |   |  | 
|submit_candidacy |    | :heavy_check_mark: |   | `Compact<u32>` candidate_count <br/> | 
|renounce_candidacy |    |   |   | `Renouncing` renouncing <br/> | 
|remove_member |    | :heavy_check_mark: |   | `LookupSource` who <br/>`bool` has_replacement <br/> | 
|clean_defunct_voters |    | :heavy_check_mark: |   | `u32` _num_voters <br/>`u32` _num_defunct <br/> | 

## TechnicalMembership

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|add_member |    | :heavy_check_mark: |   | `AccountId` who <br/> | 
|remove_member |    | :heavy_check_mark: |   | `AccountId` who <br/> | 
|swap_member |    | :heavy_check_mark: |   | `AccountId` remove <br/>`AccountId` add <br/> | 
|reset_members |    | :heavy_check_mark: |   | `Vec<AccountId>` members <br/> | 
|change_key |    | :heavy_check_mark: |   | `AccountId` new <br/> | 
|set_prime |    | :heavy_check_mark: |   | `AccountId` who <br/> | 
|clear_prime |    | :heavy_check_mark: |   |  | 

## Treasury

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|propose_spend |    | :heavy_check_mark: |   | `Compact<BalanceOf>` value <br/>`LookupSource` beneficiary <br/> | 
|reject_proposal |    | :heavy_check_mark: |   | `Compact<ProposalIndex>` proposal_id <br/> | 
|approve_proposal |    | :heavy_check_mark: |   | `Compact<ProposalIndex>` proposal_id <br/> | 

## Claims

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|claim |    | :heavy_check_mark: |   | `AccountId` dest <br/>`EcdsaSignature` ethereum_signature <br/> | 
|mint_claim |    |   |   | `EthereumAddress` who <br/>`BalanceOf` value <br/>`Option<(BalanceOf,BalanceOf,BlockNumber)>` vesting_schedule <br/>`Option<StatementKind>` statement <br/> | 
|claim_attest |    | :heavy_check_mark: |   | `AccountId` dest <br/>`EcdsaSignature` ethereum_signature <br/>`Bytes` statement <br/> | 
|attest |    | :heavy_check_mark: |   | `Bytes` statement <br/> | 
|move_claim |    | :heavy_check_mark: |   | `EthereumAddress` old <br/>`EthereumAddress` new <br/>`Option<AccountId>` maybe_preclaim <br/> | 

## Utility

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|batch | :heavy_check_mark:  | :heavy_check_mark: |   | `Vec<Call>` calls <br/> | 
|as_derivative |    |   |   | `u16` index <br/>`Call` call <br/> | 
|batch_all | :heavy_check_mark:  | :heavy_check_mark: |   | `Vec<Call>` calls <br/> | 

## Identity

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|add_registrar |    | :heavy_check_mark: |   | `AccountId` account <br/> | 
|set_identity |    |   |   | `IdentityInfo` info <br/> | 
|set_subs |    |   |   | `Vec<(AccountId,Data)>` subs <br/> | 
|clear_identity |    | :heavy_check_mark: |   |  | 
|request_judgement |    | :heavy_check_mark: |   | `Compact<RegistrarIndex>` reg_index <br/>`Compact<BalanceOf>` max_fee <br/> | 
|cancel_request |    | :heavy_check_mark: |   | `RegistrarIndex` reg_index <br/> | 
|set_fee |    | :heavy_check_mark: |   | `Compact<RegistrarIndex>` index <br/>`Compact<BalanceOf>` fee <br/> | 
|set_account_id |    | :heavy_check_mark: |   | `Compact<RegistrarIndex>` index <br/>`AccountId` new <br/> | 
|set_fields |    |   |   | `Compact<RegistrarIndex>` index <br/>`IdentityFields` fields <br/> | 
|provide_judgement |    |   |   | `Compact<RegistrarIndex>` reg_index <br/>`LookupSource` target <br/>`IdentityJudgement` judgement <br/> | 
|kill_identity |    | :heavy_check_mark: |   | `LookupSource` target <br/> | 
|add_sub |    |   |   | `LookupSource` sub <br/>`Data` data <br/> | 
|rename_sub |    |   |   | `LookupSource` sub <br/>`Data` data <br/> | 
|remove_sub |    | :heavy_check_mark: |   | `LookupSource` sub <br/> | 
|quit_sub |    | :heavy_check_mark: |   |  | 

## Society

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|bid |    | :heavy_check_mark: |   | `BalanceOf` value <br/> | 
|unbid |    | :heavy_check_mark: |   | `u32` pos <br/> | 
|vouch |    | :heavy_check_mark: |   | `AccountId` who <br/>`BalanceOf` value <br/>`BalanceOf` tip <br/> | 
|unvouch |    | :heavy_check_mark: |   | `u32` pos <br/> | 
|vote |    | :heavy_check_mark: |   | `LookupSource` candidate <br/>`bool` approve <br/> | 
|defender_vote |    | :heavy_check_mark: |   | `bool` approve <br/> | 
|payout |    | :heavy_check_mark: |   |  | 
|found |    | :heavy_check_mark: |   | `AccountId` founder <br/>`u32` max_members <br/>`Bytes` rules <br/> | 
|unfound |    | :heavy_check_mark: |   |  | 
|judge_suspended_member |    | :heavy_check_mark: |   | `AccountId` who <br/>`bool` forgive <br/> | 
|judge_suspended_candidate |    |   |   | `AccountId` who <br/>`SocietyJudgement` judgement <br/> | 
|set_max_members |    | :heavy_check_mark: |   | `u32` max <br/> | 

## Recovery

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|as_recovered |    |   |   | `AccountId` account <br/>`Call` call <br/> | 
|set_recovered |    | :heavy_check_mark: |   | `AccountId` lost <br/>`AccountId` rescuer <br/> | 
|create_recovery |    |   |   | `Vec<AccountId>` friends <br/>`u16` threshold <br/>`BlockNumber` delay_period <br/> | 
|initiate_recovery |    | :heavy_check_mark: |   | `AccountId` account <br/> | 
|vouch_recovery |    | :heavy_check_mark: |   | `AccountId` lost <br/>`AccountId` rescuer <br/> | 
|claim_recovery |    | :heavy_check_mark: |   | `AccountId` account <br/> | 
|close_recovery |    | :heavy_check_mark: |   | `AccountId` rescuer <br/> | 
|remove_recovery |    | :heavy_check_mark: |   |  | 
|cancel_recovered |    | :heavy_check_mark: |   | `AccountId` account <br/> | 

## Vesting

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|vest |    | :heavy_check_mark: |   |  | 
|vest_other |    | :heavy_check_mark: |   | `LookupSource` target <br/> | 
|vested_transfer |    | :heavy_check_mark: |   | `LookupSource` target <br/>`VestingInfo` schedule <br/> | 
|force_vested_transfer |    | :heavy_check_mark: |   | `LookupSource` source <br/>`LookupSource` target <br/>`VestingInfo` schedule <br/> | 

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
|proxy |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` real <br/>`Option<ProxyType>` force_proxy_type <br/>`Call` call <br/> | 
|add_proxy |    | :heavy_check_mark: |   | `AccountId` delegate <br/>`ProxyType` proxy_type <br/>`BlockNumber` delay <br/> | 
|remove_proxy |    | :heavy_check_mark: |   | `AccountId` delegate <br/>`ProxyType` proxy_type <br/>`BlockNumber` delay <br/> | 
|remove_proxies |    | :heavy_check_mark: |   |  | 
|anonymous |    | :heavy_check_mark: |   | `ProxyType` proxy_type <br/>`BlockNumber` delay <br/>`u16` index <br/> | 
|kill_anonymous |    | :heavy_check_mark: |   | `AccountId` spawner <br/>`ProxyType` proxy_type <br/>`u16` index <br/>`Compact<BlockNumber>` height <br/>`Compact<u32>` ext_index <br/> | 
|announce |    | :heavy_check_mark: |   | `AccountId` real <br/>`CallHashOf` call_hash <br/> | 
|remove_announcement |    | :heavy_check_mark: |   | `AccountId` real <br/>`CallHashOf` call_hash <br/> | 
|reject_announcement |    | :heavy_check_mark: |   | `AccountId` delegate <br/>`CallHashOf` call_hash <br/> | 
|proxy_announced |    | :heavy_check_mark: |   | `AccountId` delegate <br/>`AccountId` real <br/>`Option<ProxyType>` force_proxy_type <br/>`Call` call <br/> | 

## Multisig

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|as_multi_threshold_1 |    | :heavy_check_mark: | :heavy_check_mark: | `Vec<AccountId>` other_signatories <br/>`Call` call <br/> | 
|as_multi |    | :heavy_check_mark: | :heavy_check_mark: | `u16` threshold <br/>`Vec<AccountId>` other_signatories <br/>`Option<Timepoint>` maybe_timepoint <br/>`OpaqueCall` call <br/>`bool` store_call <br/>`Weight` max_weight <br/> | 
|approve_as_multi |    | :heavy_check_mark: | :heavy_check_mark: | `u16` threshold <br/>`Vec<AccountId>` other_signatories <br/>`Option<Timepoint>` maybe_timepoint <br/>`[u8;32]` call_hash <br/>`Weight` max_weight <br/> | 
|cancel_as_multi |    | :heavy_check_mark: | :heavy_check_mark: | `u16` threshold <br/>`Vec<AccountId>` other_signatories <br/>`Timepoint` timepoint <br/>`[u8;32]` call_hash <br/> | 

## Bounties

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|propose_bounty |    | :heavy_check_mark: |   | `Compact<BalanceOf>` value <br/>`Bytes` description <br/> | 
|approve_bounty |    | :heavy_check_mark: |   | `Compact<BountyIndex>` bounty_id <br/> | 
|propose_curator |    | :heavy_check_mark: |   | `Compact<BountyIndex>` bounty_id <br/>`LookupSource` curator <br/>`Compact<BalanceOf>` fee <br/> | 
|unassign_curator |    | :heavy_check_mark: |   | `Compact<BountyIndex>` bounty_id <br/> | 
|accept_curator |    | :heavy_check_mark: |   | `Compact<BountyIndex>` bounty_id <br/> | 
|award_bounty |    | :heavy_check_mark: |   | `Compact<BountyIndex>` bounty_id <br/>`LookupSource` beneficiary <br/> | 
|claim_bounty |    | :heavy_check_mark: |   | `Compact<BountyIndex>` bounty_id <br/> | 
|close_bounty |    | :heavy_check_mark: |   | `Compact<BountyIndex>` bounty_id <br/> | 
|extend_bounty_expiry |    | :heavy_check_mark: |   | `Compact<BountyIndex>` bounty_id <br/>`Bytes` _remark <br/> | 

## Tips

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|report_awesome |    | :heavy_check_mark: |   | `Bytes` reason <br/>`AccountId` who <br/> | 
|retract_tip |    | :heavy_check_mark: |   | `Hash` hash <br/> | 
|tip_new |    | :heavy_check_mark: |   | `Bytes` reason <br/>`AccountId` who <br/>`Compact<BalanceOf>` tip_value <br/> | 
|tip |    | :heavy_check_mark: |   | `Hash` hash <br/>`Compact<BalanceOf>` tip_value <br/> | 
|close_tip |    | :heavy_check_mark: |   | `Hash` hash <br/> | 
|slash_tip |    | :heavy_check_mark: |   | `Hash` hash <br/> | 

## ElectionProviderMultiPhase

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|submit_unsigned |    |   |   | `RawSolution` raw_solution <br/>`SolutionOrSnapshotSize` witness <br/> | 
|set_minimum_untrusted_score |    |   |   | `Option<ElectionScore>` maybe_next_score <br/> | 
|set_emergency_election_result |    |   |   | `Supports` supports <br/> | 
|submit |    |   |   | `RawSolution` raw_solution <br/>`u32` num_signed_submissions <br/> | 

## Gilt

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|place_bid |    | :heavy_check_mark: |   | `Compact<BalanceOf>` amount <br/>`u32` duration <br/> | 
|retract_bid |    | :heavy_check_mark: |   | `Compact<BalanceOf>` amount <br/>`u32` duration <br/> | 
|set_target |    |   |   | `Compact<Perquintill>` target <br/> | 
|thaw |    |   |   | `Compact<ActiveIndex>` index <br/> | 

## ParachainsOrigin

Empty

## Configuration

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_validation_upgrade_frequency |    | :heavy_check_mark: |   | `BlockNumber` new <br/> | 
|set_validation_upgrade_delay |    | :heavy_check_mark: |   | `BlockNumber` new <br/> | 
|set_code_retention_period |    | :heavy_check_mark: |   | `BlockNumber` new <br/> | 
|set_max_code_size |    | :heavy_check_mark: |   | `u32` new <br/> | 
|set_max_pov_size |    | :heavy_check_mark: |   | `u32` new <br/> | 
|set_max_head_data_size |    | :heavy_check_mark: |   | `u32` new <br/> | 
|set_parathread_cores |    | :heavy_check_mark: |   | `u32` new <br/> | 
|set_parathread_retries |    | :heavy_check_mark: |   | `u32` new <br/> | 
|set_group_rotation_frequency |    | :heavy_check_mark: |   | `BlockNumber` new <br/> | 
|set_chain_availability_period |    | :heavy_check_mark: |   | `BlockNumber` new <br/> | 
|set_thread_availability_period |    | :heavy_check_mark: |   | `BlockNumber` new <br/> | 
|set_scheduling_lookahead |    | :heavy_check_mark: |   | `u32` new <br/> | 
|set_max_validators_per_core |    | :heavy_check_mark: |   | `Option<u32>` new <br/> | 
|set_max_validators |    | :heavy_check_mark: |   | `Option<u32>` new <br/> | 
|set_dispute_period |    |   |   | `SessionIndex` new <br/> | 
|set_dispute_post_conclusion_acceptance_period |    | :heavy_check_mark: |   | `BlockNumber` new <br/> | 
|set_dispute_max_spam_slots |    | :heavy_check_mark: |   | `u32` new <br/> | 
|set_dispute_conclusion_by_time_out_period |    | :heavy_check_mark: |   | `BlockNumber` new <br/> | 
|set_no_show_slots |    | :heavy_check_mark: |   | `u32` new <br/> | 
|set_n_delay_tranches |    | :heavy_check_mark: |   | `u32` new <br/> | 
|set_zeroth_delay_tranche_width |    | :heavy_check_mark: |   | `u32` new <br/> | 
|set_needed_approvals |    | :heavy_check_mark: |   | `u32` new <br/> | 
|set_relay_vrf_modulo_samples |    | :heavy_check_mark: |   | `u32` new <br/> | 
|set_max_upward_queue_count |    | :heavy_check_mark: |   | `u32` new <br/> | 
|set_max_upward_queue_size |    | :heavy_check_mark: |   | `u32` new <br/> | 
|set_max_downward_message_size |    | :heavy_check_mark: |   | `u32` new <br/> | 
|set_ump_service_total_weight |    | :heavy_check_mark: |   | `Weight` new <br/> | 
|set_max_upward_message_size |    | :heavy_check_mark: |   | `u32` new <br/> | 
|set_max_upward_message_num_per_candidate |    | :heavy_check_mark: |   | `u32` new <br/> | 
|set_hrmp_open_request_ttl |    | :heavy_check_mark: |   | `u32` _new <br/> | 
|set_hrmp_sender_deposit |    | :heavy_check_mark: |   | `Balance` new <br/> | 
|set_hrmp_recipient_deposit |    | :heavy_check_mark: |   | `Balance` new <br/> | 
|set_hrmp_channel_max_capacity |    | :heavy_check_mark: |   | `u32` new <br/> | 
|set_hrmp_channel_max_total_size |    | :heavy_check_mark: |   | `u32` new <br/> | 
|set_hrmp_max_parachain_inbound_channels |    | :heavy_check_mark: |   | `u32` new <br/> | 
|set_hrmp_max_parathread_inbound_channels |    | :heavy_check_mark: |   | `u32` new <br/> | 
|set_hrmp_channel_max_message_size |    | :heavy_check_mark: |   | `u32` new <br/> | 
|set_hrmp_max_parachain_outbound_channels |    | :heavy_check_mark: |   | `u32` new <br/> | 
|set_hrmp_max_parathread_outbound_channels |    | :heavy_check_mark: |   | `u32` new <br/> | 
|set_hrmp_max_message_num_per_candidate |    | :heavy_check_mark: |   | `u32` new <br/> | 
|set_ump_max_individual_weight |    | :heavy_check_mark: |   | `Weight` new <br/> | 

## ParasShared

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|

## ParaInclusion

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|

## ParaInherent

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|enter |    |   |   | `ParachainsInherentData` data <br/> | 

## ParaScheduler

Empty

## Paras

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|force_set_current_code |    |   |   | `ParaId` para <br/>`ValidationCode` new_code <br/> | 
|force_set_current_head |    |   |   | `ParaId` para <br/>`HeadData` new_head <br/> | 
|force_schedule_code_upgrade |    |   |   | `ParaId` para <br/>`ValidationCode` new_code <br/>`BlockNumber` relay_parent_number <br/> | 
|force_note_new_head |    |   |   | `ParaId` para <br/>`HeadData` new_head <br/> | 
|force_queue_action |    |   |   | `ParaId` para <br/> | 

## Initializer

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|force_approve |    | :heavy_check_mark: |   | `BlockNumber` up_to <br/> | 

## Dmp

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|

## Ump

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|service_overweight |    |   |   | `OverweightIndex` index <br/>`Weight` weight_limit <br/> | 

## Hrmp

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|hrmp_init_open_channel |    |   |   | `ParaId` recipient <br/>`u32` proposed_max_capacity <br/>`u32` proposed_max_message_size <br/> | 
|hrmp_accept_open_channel |    |   |   | `ParaId` sender <br/> | 
|hrmp_close_channel |    |   |   | `HrmpChannelId` channel_id <br/> | 
|force_clean_hrmp |    |   |   | `ParaId` para <br/> | 
|force_process_hrmp_open |    | :heavy_check_mark: |   |  | 
|force_process_hrmp_close |    | :heavy_check_mark: |   |  | 
|hrmp_cancel_open_request |    |   |   | `HrmpChannelId` channel_id <br/> | 

## ParaSessionInfo

Empty

## Registrar

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|register |    |   |   | `ParaId` id <br/>`HeadData` genesis_head <br/>`ValidationCode` validation_code <br/> | 
|force_register |    |   |   | `AccountId` who <br/>`BalanceOf` deposit <br/>`ParaId` id <br/>`HeadData` genesis_head <br/>`ValidationCode` validation_code <br/> | 
|deregister |    |   |   | `ParaId` id <br/> | 
|swap |    |   |   | `ParaId` id <br/>`ParaId` other <br/> | 
|force_remove_lock |    |   |   | `ParaId` para <br/> | 
|reserve |    | :heavy_check_mark: |   |  | 

## Slots

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|force_lease |    |   |   | `ParaId` para <br/>`AccountId` leaser <br/>`BalanceOf` amount <br/>`LeasePeriodOf` period_begin <br/>`LeasePeriodOf` period_count <br/> | 
|clear_all_leases |    |   |   | `ParaId` para <br/> | 
|trigger_onboard |    |   |   | `ParaId` para <br/> | 

## Auctions

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|new_auction |    | :heavy_check_mark: |   | `Compact<BlockNumber>` duration <br/>`Compact<LeasePeriodOf>` lease_period_index <br/> | 
|bid |    | :heavy_check_mark: |   | `Compact<ParaId>` para <br/>`Compact<AuctionIndex>` auction_index <br/>`Compact<LeasePeriodOf>` first_slot <br/>`Compact<LeasePeriodOf>` last_slot <br/>`Compact<BalanceOf>` amount <br/> | 
|cancel_auction |    | :heavy_check_mark: |   |  | 

## Crowdloan

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|create |    |   |   | `Compact<ParaId>` index <br/>`Compact<BalanceOf>` cap <br/>`Compact<LeasePeriodOf>` first_period <br/>`Compact<LeasePeriodOf>` last_period <br/>`Compact<BlockNumber>` end <br/>`Option<MultiSigner>` verifier <br/> | 
|contribute |    |   |   | `Compact<ParaId>` index <br/>`Compact<BalanceOf>` value <br/>`Option<MultiSignature>` signature <br/> | 
|withdraw |    | :heavy_check_mark: |   | `AccountId` who <br/>`Compact<ParaId>` index <br/> | 
|refund |    | :heavy_check_mark: |   | `Compact<ParaId>` index <br/> | 
|dissolve |    | :heavy_check_mark: |   | `Compact<ParaId>` index <br/> | 
|edit |    |   |   | `Compact<ParaId>` index <br/>`Compact<BalanceOf>` cap <br/>`Compact<LeasePeriodOf>` first_period <br/>`Compact<LeasePeriodOf>` last_period <br/>`Compact<BlockNumber>` end <br/>`Option<MultiSigner>` verifier <br/> | 
|add_memo |    |   |   | `ParaId` index <br/>`Bytes` memo <br/> | 
|poke |    |   |   | `ParaId` index <br/> | 

## XcmPallet

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|send |    |   |   | `VersionedMultiLocation` dest <br/>`VersionedXcm` message <br/> | 
|teleport_assets |    |   |   | `VersionedMultiLocation` dest <br/>`VersionedMultiLocation` beneficiary <br/>`VersionedMultiAssets` assets <br/>`u32` fee_asset_item <br/>`Weight` dest_weight <br/> | 
|reserve_transfer_assets |    |   |   | `VersionedMultiLocation` dest <br/>`VersionedMultiLocation` beneficiary <br/>`VersionedMultiAssets` assets <br/>`u32` fee_asset_item <br/>`Weight` dest_weight <br/> | 
|execute |    |   |   | `VersionedXcm` message <br/>`Weight` max_weight <br/> | 

