# Kusama  7.9122.x

## SYSTEM

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Fill block |    | :heavy_check_mark: | :heavy_check_mark: | `Perbill` ratio <br/> | 
|Set heap pages |    | :heavy_zcheck_mark: | :heavy_check_mark: | `u64` pages <br/> | 

## BABE

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|

## TIMESTAMP

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set |    | :heavy_check_mark: |   | `Compactu64` now <br/> | 

## INDICES

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Claim |    | :heavy_check_mark: |   | `AccountIndex` index <br/> | 
|Transfer |    | :heavy_check_mark: |   | `AccountId` new_ <br/>`AccountIndex` index <br/> | 
|Free |    | :heavy_check_mark: |   | `AccountIndex` index <br/> | 
|Force transfer |    | :heavy_check_mark: |   | `AccountId` new_ <br/>`AccountIndex` index <br/>`bool` freeze <br/> | 
|Freeze |    | :heavy_check_mark: |   | `AccountIndex` index <br/> | 

## BALANCES

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Transfer | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` dest <br/>`CompactBalance` Amount <br/> | 
|Set balance |    | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` who <br/>`CompactBalance` new_free <br/>`CompactBalance` new_reserved <br/> | 
|Force transfer | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` source <br/>`LookupasStaticLookupSource` dest <br/>`CompactBalance` Amount <br/> | 
|Transfer keep alive | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` dest <br/>`CompactBalance` Amount <br/> | 
|Transfer all | :heavy_check_mark:  | :heavy_check_mark: |   | `LookupasStaticLookupSource` dest <br/>`bool` keep_alive <br/> | 
|Force unreserve |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` who <br/>`Balance` amount <br/> | 

## AUTHORSHIP

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|

## STAKING

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Bond | :heavy_check_mark:  | :heavy_check_mark: |   | `LookupasStaticLookupSource` controller <br/>`CompactBalance` Amount <br/>`RewardDestination` payee <br/> | 
|Bond extra | :heavy_check_mark:  | :heavy_check_mark: |   | `CompactBalance` max_additional <br/> | 
|Unbond | :heavy_check_mark:  | :heavy_check_mark: |   | `CompactBalance` Amount <br/> | 
|Withdraw Unbonded | :heavy_check_mark:  | :heavy_check_mark: |   | `u32` num_slashing_spans <br/> | 
|Validate | :heavy_check_mark:  | :heavy_check_mark: |   | `ValidatorPrefs` prefs <br/> | 
|Nominate | :heavy_check_mark:  | :heavy_check_mark: |   | `VecLookupasStaticLookupSource` targets <br/> | 
|Chill | :heavy_check_mark:  | :heavy_check_mark: |   |  | 
|Set payee | :heavy_check_mark:  | :heavy_check_mark: |   | `RewardDestination` payee <br/> | 
|Set controller | :heavy_check_mark:  | :heavy_check_mark: |   | `LookupasStaticLookupSource` controller <br/> | 
|Set validator count |    | :heavy_check_mark: |   | `Compactu32` new_ <br/> | 
|Increase validator count |    | :heavy_check_mark: |   | `Compactu32` additional <br/> | 
|Force no eras |    | :heavy_check_mark: |   |  | 
|Force new era |    | :heavy_check_mark: |   |  | 
|Force unstake |    | :heavy_check_mark: |   | `AccountId` stash <br/>`u32` num_slashing_spans <br/> | 
|Force new era always |    | :heavy_check_mark: |   |  | 
|Payout stakers | :heavy_check_mark:  | :heavy_check_mark: |   | `AccountId` validator_stash <br/>`EraIndex` era <br/> | 
|Rebond | :heavy_check_mark:  | :heavy_check_mark: |   | `CompactBalance` Amount <br/> | 
|Set history depth |    | :heavy_check_mark: |   | `Compactu32` new_history_depth <br/>`Compactu32` era_items_deleted <br/> | 
|Reap stash |    | :heavy_check_mark: |   | `AccountId` stash <br/>`u32` num_slashing_spans <br/> | 
|Kick |    | :heavy_check_mark: |   | `VecLookupasStaticLookupSource` who <br/> | 
|Chill other |    | :heavy_check_mark: |   | `AccountId` controller <br/> | 

## SESSION

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set keys | :heavy_check_mark:  | :heavy_check_mark: |   | `Keys` keys <br/>`Bytes` proof <br/> | 
|Purge keys | :heavy_check_mark:  | :heavy_check_mark: |   |  | 

## GRANDPA

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Note stalled |    | :heavy_check_mark: |   | `BlockNumber` delay <br/>`BlockNumber` best_finalized_block_number <br/> | 

## IMONLINE

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|

## DEMOCRACY

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Second |    | :heavy_check_mark: |   | `Compactu32` proposal <br/>`Compactu32` seconds_upper_bound <br/> | 
|Emergency cancel |    | :heavy_check_mark: |   | `ReferendumIndex` ref_index <br/> | 
|Cancel referendum |    | :heavy_check_mark: |   | `Compactu32` ref_index <br/> | 
|Cancel queued |    | :heavy_check_mark: |   | `ReferendumIndex` which <br/> | 
|Undelegate |    | :heavy_check_mark: |   |  | 
|Clear public proposals |    | :heavy_check_mark: |   |  | 
|Note preimage |    | :heavy_check_mark: |   | `Bytes` encoded_proposal <br/> | 
|Note preimage operational |    | :heavy_check_mark: |   | `Bytes` encoded_proposal <br/> | 
|Note imminent preimage |    | :heavy_check_mark: |   | `Bytes` encoded_proposal <br/> | 
|Note imminent preimage operational |    | :heavy_check_mark: |   | `Bytes` encoded_proposal <br/> | 
|Remove vote |    | :heavy_check_mark: |   | `ReferendumIndex` index <br/> | 
|Cancel proposal |    | :heavy_check_mark: |   | `Compactu32` prop_index <br/> | 

## COUNCIL

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Vote |    | :heavy_check_mark: |   | `Hash` proposal <br/>`Compactu32` index <br/>`bool` approve <br/> | 
|Close |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/>`Compactu32` index <br/>`Compactu64` proposal_weight_bound <br/>`Compactu32` length_bound <br/> | 
|Disapprove proposal |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/> | 

## TECHNICALCOMMITTEE

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Disapprove proposal |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/> | 

## PHRAGMENELECTION

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Remove voter |    | :heavy_check_mark: |   |  | 
|Submit candidacy |    | :heavy_check_mark: |   | `Compactu32` candidate_count <br/> | 
|Remove member |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` who <br/>`bool` has_replacement <br/> | 
|Clean defunct voters |    | :heavy_check_mark: |   | `u32` num_voters <br/>`u32` num_defunct <br/> | 

## TECHNICALMEMBERSHIP

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Add member |    | :heavy_check_mark: |   | `AccountId` who <br/> | 
|Remove member |    | :heavy_check_mark: |   | `AccountId` who <br/> | 
|Swap member |    | :heavy_check_mark: |   | `AccountId` remove <br/>`AccountId` add <br/> | 
|Reset members |    | :heavy_check_mark: |   | `VecAccountId` members <br/> | 
|Change key |    | :heavy_check_mark: |   | `AccountId` new_ <br/> | 
|Set prime |    | :heavy_check_mark: |   | `AccountId` who <br/> | 
|Clear prime |    | :heavy_check_mark: |   |  | 

## TREASURY

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Propose spend |    | :heavy_check_mark: |   | `CompactBalance` Amount <br/>`LookupasStaticLookupSource` beneficiary <br/> | 
|Reject proposal |    | :heavy_check_mark: |   | `Compactu32` proposal_id <br/> | 
|Approve proposal |    | :heavy_check_mark: |   | `Compactu32` proposal_id <br/> | 

## CLAIMS

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Claim |    | :heavy_check_mark: |   | `AccountId` dest <br/>`EcdsaSignature` ethereum_signature <br/> | 
|Claim attest |    | :heavy_check_mark: |   | `AccountId` dest <br/>`EcdsaSignature` ethereum_signature <br/>`Bytes` statement <br/> | 
|Attest |    | :heavy_check_mark: |   | `Bytes` statement <br/> | 
|Move claim |    | :heavy_check_mark: |   | `EthereumAddress` old <br/>`EthereumAddress` new_ <br/>`OptionAccountId` maybe_preclaim <br/> | 

## UTILITY

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Batch | :heavy_check_mark:  | :heavy_check_mark: |   | `VecCall` calls <br/> | 
|Batch all | :heavy_check_mark:  | :heavy_check_mark: |   | `VecCall` calls <br/> | 

## IDENTITY

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Add registrar |    | :heavy_check_mark: |   | `AccountId` account <br/> | 
|Clear identity |    | :heavy_check_mark: |   |  | 
|Request judgement |    | :heavy_check_mark: |   | `Compactu32` reg_index <br/>`Compactu128` max_fee <br/> | 
|Cancel request |    | :heavy_check_mark: |   | `RegistrarIndex` reg_index <br/> | 
|Set fee |    | :heavy_check_mark: |   | `Compactu32` index <br/>`Compactu128` fee <br/> | 
|Set account id |    | :heavy_check_mark: |   | `Compactu32` index <br/>`AccountId` new_ <br/> | 
|Kill identity |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` target <br/> | 
|Remove sub |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` sub <br/> | 
|Quit sub |    | :heavy_check_mark: |   |  | 

## SOCIETY

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Bid |    | :heavy_check_mark: |   | `Balance` Amount <br/> | 
|Unbid |    | :heavy_check_mark: |   | `u32` pos <br/> | 
|Vouch |    | :heavy_check_mark: |   | `AccountId` who <br/>`Balance` Amount <br/>`Balance` tip <br/> | 
|Unvouch |    | :heavy_check_mark: |   | `u32` pos <br/> | 
|Vote |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` candidate <br/>`bool` approve <br/> | 
|Defender vote |    | :heavy_check_mark: |   | `bool` approve <br/> | 
|Payout |    | :heavy_check_mark: |   |  | 
|Found |    | :heavy_check_mark: |   | `AccountId` founder <br/>`u32` max_members <br/>`Bytes` rules <br/> | 
|Unfound |    | :heavy_check_mark: |   |  | 
|Judge suspended member |    | :heavy_check_mark: |   | `AccountId` who <br/>`bool` forgive <br/> | 
|Set max members |    | :heavy_check_mark: |   | `u32` max <br/> | 

## RECOVERY

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set recovered |    | :heavy_check_mark: |   | `AccountId` lost <br/>`AccountId` rescuer <br/> | 
|Initiate recovery |    | :heavy_check_mark: |   | `AccountId` account <br/> | 
|Vouch recovery |    | :heavy_check_mark: |   | `AccountId` lost <br/>`AccountId` rescuer <br/> | 
|Claim recovery |    | :heavy_check_mark: |   | `AccountId` account <br/> | 
|Close recovery |    | :heavy_check_mark: |   | `AccountId` rescuer <br/> | 
|Remove recovery |    | :heavy_check_mark: |   |  | 
|Cancel recovered |    | :heavy_check_mark: |   | `AccountId` account <br/> | 

## VESTING

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Vest |    | :heavy_check_mark: |   |  | 
|Vest other |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` target <br/> | 
|Merge schedules |    | :heavy_check_mark: |   | `u32` schedule1_index <br/>`u32` schedule2_index <br/> | 

## SCHEDULER

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|

## PROXY

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Proxy |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` real <br/>`OptionProxyType` force_proxy_type <br/>`Call` call <br/> | 
|Add proxy |    | :heavy_check_mark: |   | `AccountId` delegate <br/>`ProxyType` proxy_type <br/>`BlockNumber` delay <br/> | 
|Remove proxy |    | :heavy_check_mark: |   | `AccountId` delegate <br/>`ProxyType` proxy_type <br/>`BlockNumber` delay <br/> | 
|Remove proxies |    | :heavy_check_mark: |   |  | 
|Anonymous |    | :heavy_check_mark: |   | `ProxyType` proxy_type <br/>`BlockNumber` delay <br/>`u16` index <br/> | 
|Kill anonymous |    | :heavy_check_mark: |   | `AccountId` spawner <br/>`ProxyType` proxy_type <br/>`u16` index <br/>`Compactu32` height <br/>`Compactu32` ext_index <br/> | 
|Proxy announced |    | :heavy_check_mark: |   | `AccountId` delegate <br/>`AccountId` real <br/>`OptionProxyType` force_proxy_type <br/>`Call` call <br/> | 

## MULTISIG

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|As multi |    | :heavy_check_mark: | :heavy_check_mark: | `u16` threshold <br/>`VecAccountId` other_signatories <br/>`OptionTimepoint` maybe_timepoint <br/>`OpaqueCall` call <br/>`bool` store_call <br/>`Weight` max_weight <br/> | 
|Approve as multi |    | :heavy_check_mark: | :heavy_check_mark: | `u16` threshold <br/>`VecAccountId` other_signatories <br/>`OptionTimepoint` maybe_timepoint <br/>`H256` call_hash <br/>`Weight` max_weight <br/> | 
|Cancel as multi |    | :heavy_check_mark: | :heavy_check_mark: | `u16` threshold <br/>`VecAccountId` other_signatories <br/>`Timepoint` timepoint <br/>`H256` call_hash <br/> | 

## BOUNTIES

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Propose bounty |    | :heavy_check_mark: |   | `CompactBalance` Amount <br/>`Bytes` description <br/> | 
|Approve bounty |    | :heavy_check_mark: |   | `Compactu32` bounty_id <br/> | 
|Propose curator |    | :heavy_check_mark: |   | `Compactu32` bounty_id <br/>`LookupasStaticLookupSource` curator <br/>`CompactBalance` fee <br/> | 
|Unassign curator |    | :heavy_check_mark: |   | `Compactu32` bounty_id <br/> | 
|Accept curator |    | :heavy_check_mark: |   | `Compactu32` bounty_id <br/> | 
|Award bounty |    | :heavy_check_mark: |   | `Compactu32` bounty_id <br/>`LookupasStaticLookupSource` beneficiary <br/> | 
|Claim bounty |    | :heavy_check_mark: |   | `Compactu32` bounty_id <br/> | 
|Close bounty |    | :heavy_check_mark: |   | `Compactu32` bounty_id <br/> | 
|Extend bounty expiry |    | :heavy_check_mark: |   | `Compactu32` bounty_id <br/>`Bytes` remark <br/> | 

## TIPS

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Report awesome |    | :heavy_check_mark: |   | `Bytes` reason <br/>`AccountId` who <br/> | 
|Retract tip |    | :heavy_check_mark: |   | `Hash` hash <br/> | 
|Tip new |    | :heavy_check_mark: |   | `Bytes` reason <br/>`AccountId` who <br/>`Compactu128` tip_value <br/> | 
|Tip |    | :heavy_check_mark: |   | `Hash` hash <br/>`Compactu128` tip_value <br/> | 
|Close tip |    | :heavy_check_mark: |   | `Hash` hash <br/> | 
|Slash tip |    | :heavy_check_mark: |   | `Hash` hash <br/> | 

## ELECTIONPROVIDERMULTIPHASE

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|

## GILT

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Place bid |    | :heavy_check_mark: |   | `CompactBalance` amount <br/>`u32` duration <br/> | 
|Retract bid |    | :heavy_check_mark: |   | `CompactBalance` amount <br/>`u32` duration <br/> | 

## BAGSLIST

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Rebag |    | :heavy_check_mark: |   | `AccountId` dislocated <br/> | 

## CONFIGURATION

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set validation upgrade frequency |    | :heavy_check_mark: |   | `BlockNumber` new_ <br/> | 
|Set validation upgrade delay |    | :heavy_check_mark: |   | `BlockNumber` new_ <br/> | 
|Set code retention period |    | :heavy_check_mark: |   | `BlockNumber` new_ <br/> | 
|Set max code size |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set max pov size |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set max head data size |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set parathread cores |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set parathread retries |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set group rotation frequency |    | :heavy_check_mark: |   | `BlockNumber` new_ <br/> | 
|Set chain availability period |    | :heavy_check_mark: |   | `BlockNumber` new_ <br/> | 
|Set thread availability period |    | :heavy_check_mark: |   | `BlockNumber` new_ <br/> | 
|Set scheduling lookahead |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set max validators per core |    | :heavy_check_mark: |   | `Optionu32` new_ <br/> | 
|Set max validators |    | :heavy_check_mark: |   | `Optionu32` new_ <br/> | 
|Set dispute post conclusion acceptance period |    | :heavy_check_mark: |   | `BlockNumber` new_ <br/> | 
|Set dispute max spam slots |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set dispute conclusion by time out period |    | :heavy_check_mark: |   | `BlockNumber` new_ <br/> | 
|Set no show slots |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set n delay tranches |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set zeroth delay tranche width |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set needed approvals |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set relay vrf modulo samples |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set max upward queue count |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set max upward queue size |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set max downward message size |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set ump service total weight |    | :heavy_check_mark: |   | `Weight` new_ <br/> | 
|Set max upward message size |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set max upward message num per candidate |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set hrmp open request ttl |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set hrmp recipient deposit |    | :heavy_check_mark: |   | `Balance` new_ <br/> | 
|Set hrmp channel max capacity |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set hrmp channel max total size |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set hrmp max parachain inbound channels |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set hrmp max parathread inbound channels |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set hrmp channel max message size |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set hrmp max parachain outbound channels |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set hrmp max parathread outbound channels |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set hrmp max message num per candidate |    | :heavy_check_mark: |   | `u32` new_ <br/> | 
|Set ump max individual weight |    | :heavy_check_mark: |   | `Weight` new_ <br/> | 

## PARASSHARED

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|

## PARAINCLUSION

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|

## PARAINHERENT

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|

## PARAS

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|

## INITIALIZER

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Force approve |    | :heavy_check_mark: |   | `BlockNumber` up_to <br/> | 

## DMP

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|

## UMP

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|

## HRMP

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Force process hrmp open |    | :heavy_check_mark: |   |  | 
|Force process hrmp close |    | :heavy_check_mark: |   |  | 

## REGISTRAR

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Reserve |    | :heavy_check_mark: |   |  | 

## SLOTS

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|

## AUCTIONS

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|New auction |    | :heavy_check_mark: |   | `Compactu32` duration <br/>`Compactu32` lease_period_index <br/> | 
|Bid |    | :heavy_check_mark: |   | `Compactu32` para <br/>`Compactu32` auction_index <br/>`Compactu32` first_slot <br/>`Compactu32` last_slot <br/>`CompactBalance` amount <br/> | 
|Cancel auction |    | :heavy_check_mark: |   |  | 

## CROWDLOAN

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|

## XCMPALLET

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|

