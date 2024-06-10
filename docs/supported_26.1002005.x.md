# Kusama 26.1002005.x

## System

| Name                             | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                         |
| -------------------------------- | ------ | ------------------ | ------------------ | ------------------ | --------------------------------- |
| Remark                           |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Bytes`remark<br/>                |
| Set heap pages                   |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u64`pages<br/>                   |
| Set code                         |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Bytes`code<br/>                  |
| Set code without checks          |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Vecu8`code<br/>                  |
| Set storage                      |        |                    |                    |                    | `VecKeyValue`items<br/>           |
| Kill storage                     |        |                    |                    |                    | `VecKey`keys<br/>                 |
| Kill prefix                      |        |                    |                    |                    | `Key`prefix<br/>`u32`subkeys<br/> |
| Remark with event                |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Bytes`remark<br/>                |
| Authorize upgrade                |        | :heavy_check_mark: | :heavy_check_mark: |                    | `Hash`code_hash<br/>              |
| Authorize upgrade without checks |        | :heavy_check_mark: | :heavy_check_mark: |                    | `Hash`code_hash<br/>              |
| Apply authorized upgrade         |        | :heavy_check_mark: | :heavy_check_mark: |                    | `Vecu8`code<br/>                  |

## Babe

| Name                         | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                              |
| ---------------------------- | ------ | --------- | ---------------- | ------- | -------------------------------------------------------------------------------------- |
| Report equivocation          |        |           |                  |         | `BoxEquivocationProofHeader`equivocation_proof<br/>`KeyOwnerProof`key_owner_proof<br/> |
| Report equivocation unsigned |        |           |                  |         | `BoxEquivocationProofHeader`equivocation_proof<br/>`KeyOwnerProof`key_owner_proof<br/> |
| Plan config change           |        |           |                  |         | `NextConfigDescriptor`config<br/>                                                      |

## Timestamp

| Name | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments            |
| ---- | ------ | --------- | ---------------- | ------- | -------------------- |
| Set  |        |           |                  |         | `Compactu64`now<br/> |

## Indices

| Name           | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                               |
| -------------- | ------ | --------- | ---------------- | ------- | ----------------------------------------------------------------------- |
| Claim          |        |           |                  |         | `AccountIndex`index<br/>                                                |
| Transfer       |        |           |                  |         | `AccountIdLookupOfT`new\_<br/>`AccountIndex`index<br/>                  |
| Free           |        |           |                  |         | `AccountIndex`index<br/>                                                |
| Force transfer |        |           |                  |         | `AccountIdLookupOfT`new\_<br/>`AccountIndex`index<br/>`bool`freeze<br/> |
| Freeze         |        |           |                  |         | `AccountIndex`index<br/>                                                |

## Balances

| Name                        | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                               |
| --------------------------- | ------------------ | ------------------ | ------------------ | ------------------ | --------------------------------------------------------------------------------------- |
| Transfer allow death        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>                                |
| Force transfer              | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`source<br/>`AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/> |
| Transfer keep alive         | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>                                |
| Transfer all                | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`dest<br/>`bool`keep_alive<br/>                                      |
| Force unreserve             |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`who<br/>`Balance`amount<br/>                                        |
| Upgrade accounts            |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `VecAccountId`who<br/>                                                                  |
| Force set balance           |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`who<br/>`CompactBalance`new_free<br/>                               |
| Force adjust total issuance |                    |                    |                    |                    | `AdjustmentDirection`direction<br/>`CompactBalance`delta<br/>                           |

## Staking

| Name                       | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                                                                                                                                                                                 |
| -------------------------- | ------------------ | ------------------ | ------------------ | ------------------ | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Bond                       | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `CompactBalance`amount<br/>`RewardDestination`payee<br/>                                                                                                                                                                                  |
| Bond extra                 | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `CompactBalance`amount<br/>                                                                                                                                                                                                               |
| Unbond                     | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `CompactBalance`amount<br/>                                                                                                                                                                                                               |
| Withdraw Unbonded          | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u32`num_slashing_spans<br/>                                                                                                                                                                                                              |
| Validate                   | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `ValidatorPrefs`prefs<br/>                                                                                                                                                                                                                |
| Nominate                   | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `VecAccountIdLookupOfT`targets<br/>                                                                                                                                                                                                       |
| Chill                      | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                                                                                                                                                                                                                           |
| Set payee                  | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `RewardDestination`payee<br/>                                                                                                                                                                                                             |
| Set controller             | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                                                                                                                                                                                                                           |
| Set validator count        |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `Compactu32`new\_<br/>                                                                                                                                                                                                                    |
| Increase validator count   |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `Compactu32`additional<br/>                                                                                                                                                                                                               |
| Scale validator count      |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `Percent`factor<br/>                                                                                                                                                                                                                      |
| Force no eras              |                    | :heavy_check_mark: | :heavy_check_mark: |                    |                                                                                                                                                                                                                                           |
| Force new era              |                    | :heavy_check_mark: | :heavy_check_mark: |                    |                                                                                                                                                                                                                                           |
| Set invulnerables          |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `VecAccountId`invulnerables<br/>                                                                                                                                                                                                          |
| Force unstake              |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountId`stash<br/>`u32`num_slashing_spans<br/>                                                                                                                                                                                         |
| Force new era always       |                    | :heavy_check_mark: | :heavy_check_mark: |                    |                                                                                                                                                                                                                                           |
| Cancel deferred slash      |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `EraIndex`era<br/>`Vecu32`slash_indices<br/>                                                                                                                                                                                              |
| Payout stakers             | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountId`validator_stash<br/>`EraIndex`era<br/>                                                                                                                                                                                         |
| Rebond                     | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `CompactBalance`amount<br/>                                                                                                                                                                                                               |
| Reap stash                 |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountId`stash<br/>`u32`num_slashing_spans<br/>                                                                                                                                                                                         |
| Kick                       |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `VecAccountIdLookupOfT`who<br/>                                                                                                                                                                                                           |
| Set staking configs        |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `ConfigOpBalanceOfT`min_nominator_bond<br/>`ConfigOpBalanceOfT`min_validator_bond<br/>`ConfigOpu32`max_nominator_count<br/>`ConfigOpu32`max_validator_count<br/>`ConfigOpPercent`chill_threshold<br/>`ConfigOpPerbill`min_commission<br/> |
| Chill other                |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountId`stash<br/>                                                                                                                                                                                                                     |
| Force apply min commission |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountId`validator_stash<br/>                                                                                                                                                                                                           |
| Set min commission         |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `Perbill`new\_<br/>                                                                                                                                                                                                                       |
| Payout stakers by page     |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountId`validator_stash<br/>`EraIndex`era<br/>`Page`page<br/>                                                                                                                                                                          |
| Update payee               |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountId`controller<br/>                                                                                                                                                                                                                |
| Deprecate controller batch |                    |                    |                    |                    | `BoundedVecAccountIdMaxControllersInDeprecationBatch`controllers<br/>                                                                                                                                                                     |
| Restore ledger             |                    |                    |                    |                    | `AccountId`stash<br/>`OptionAccountId`maybe_controller<br/>`OptionBalance`maybe_total<br/>`OptionBoundedVecUnlockChunkBalanceOfTMaxUnlockingChunks`maybe_unlocking<br/>                                                                   |

## Session

| Name       | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                        |
| ---------- | ------------------ | ------------------ | ------------------ | ------------------ | -------------------------------- |
| Set keys   | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Keys`keys<br/>`Bytes`proof<br/> |
| Purge keys | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                  |

## Grandpa

| Name                         | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                       |
| ---------------------------- | ------ | --------- | ---------------- | ------- | ----------------------------------------------------------------------------------------------- |
| Report equivocation          |        |           |                  |         | `BoxEquivocationProofHashBlockNumber`equivocation_proof<br/>`KeyOwnerProof`key_owner_proof<br/> |
| Report equivocation unsigned |        |           |                  |         | `BoxEquivocationProofHashBlockNumber`equivocation_proof<br/>`KeyOwnerProof`key_owner_proof<br/> |
| Note stalled                 |        |           |                  |         | `BlockNumber`delay<br/>`BlockNumber`best_finalized_block_number<br/>                            |

## Treasury

| Name             | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                                                                                          |
| ---------------- | ------ | ------------------ | ------------------ | ------- | ---------------------------------------------------------------------------------------------------------------------------------- |
| Propose spend    |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`amount<br/>`AccountIdLookupOfT`beneficiary<br/>                                                                    |
| Reject proposal  |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`proposal_id<br/>                                                                                                       |
| Approve proposal |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`proposal_id<br/>                                                                                                       |
| Spend local      |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`amount<br/>`AccountIdLookupOfT`beneficiary<br/>                                                                    |
| Remove approval  |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`proposal_id<br/>                                                                                                       |
| Spend            |        |                    |                    |         | `BoxAssetKind`asset_kind<br/>`CompactBalance`amount<br/>`BoxBeneficiaryLookupOf`beneficiary<br/>`OptionBlockNumber`valid_from<br/> |
| Payout           |        | :heavy_check_mark: | :heavy_check_mark: |         | `SpendIndex`index<br/>                                                                                                             |
| Check status     |        | :heavy_check_mark: | :heavy_check_mark: |         | `SpendIndex`index<br/>                                                                                                             |
| Void spend       |        | :heavy_check_mark: | :heavy_check_mark: |         | `SpendIndex`index<br/>                                                                                                             |

## ConvictionVoting

| Name              | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                                          |
| ----------------- | ------ | ------------------ | ------------------ | ------------------ | -------------------------------------------------------------------------------------------------- |
| Vote              |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Compactu32`poll_index<br/>`AccountVote`vote<br/>                                                  |
| Delegate          |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `ClassOf`class\_<br/>`AccountIdLookupOfT`to<br/>`Conviction`conviction<br/>`BalanceOf`balance<br/> |
| Undelegate        |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `ClassOf`class\_<br/>                                                                              |
| Unlock            |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `ClassOf`class\_<br/>`AccountIdLookupOfT`target<br/>                                               |
| Remove vote       |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `OptionClassOf`class\_<br/>`PollIndexOf`index<br/>                                                 |
| Remove other vote |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`target<br/>`ClassOf`class\_<br/>`PollIndexOf`index<br/>                        |

## Referenda

| Name                      | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                                                                         |
| ------------------------- | ------ | ------------------ | ------------------ | ------- | ----------------------------------------------------------------------------------------------------------------- |
| Submit                    |        | :heavy_check_mark: | :heavy_check_mark: |         | `BoxPalletsOrigin`proposal_origin<br/>`BoundedCallOfT`proposal<br/>`DispatchTimeBlockNumber`enactment_moment<br/> |
| Place decision deposit    |        | :heavy_check_mark: | :heavy_check_mark: |         | `ReferendumIndex`index<br/>                                                                                       |
| Refund decision deposit   |        | :heavy_check_mark: | :heavy_check_mark: |         | `ReferendumIndex`index<br/>                                                                                       |
| Cancel                    |        | :heavy_check_mark: | :heavy_check_mark: |         | `ReferendumIndex`index<br/>                                                                                       |
| Kill                      |        | :heavy_check_mark: | :heavy_check_mark: |         | `ReferendumIndex`index<br/>                                                                                       |
| Nudge referendum          |        | :heavy_check_mark: | :heavy_check_mark: |         | `ReferendumIndex`index<br/>                                                                                       |
| One fewer deciding        |        | :heavy_check_mark: | :heavy_check_mark: |         | `TrackIdOf`track<br/>                                                                                             |
| Refund submission deposit |        | :heavy_check_mark: | :heavy_check_mark: |         | `ReferendumIndex`index<br/>                                                                                       |
| Set metadata              |        | :heavy_check_mark: | :heavy_check_mark: |         | `ReferendumIndex`index<br/>`OptionHash`maybe_hash<br/>                                                            |

## FellowshipCollective

| Name            | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                    |
| --------------- | ------ | --------- | ---------------- | ------- | ------------------------------------------------------------ |
| Add member      |        |           |                  |         | `AccountIdLookupOfT`who<br/>                                 |
| Promote member  |        |           |                  |         | `AccountIdLookupOfT`who<br/>                                 |
| Demote member   |        |           |                  |         | `AccountIdLookupOfT`who<br/>                                 |
| Remove member   |        |           |                  |         | `AccountIdLookupOfT`who<br/>`Rank`min_rank<br/>              |
| Vote            |        |           |                  |         | `PollIndexOf`poll<br/>`bool`aye<br/>                         |
| Cleanup poll    |        |           |                  |         | `PollIndexOf`poll_index<br/>`u32`max<br/>                    |
| Exchange member |        |           |                  |         | `AccountIdLookupOfT`who<br/>`AccountIdLookupOfT`new_who<br/> |

## FellowshipReferenda

| Name                      | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                         |
| ------------------------- | ------ | --------- | ---------------- | ------- | ----------------------------------------------------------------------------------------------------------------- |
| Submit                    |        |           |                  |         | `BoxPalletsOrigin`proposal_origin<br/>`BoundedCallOfT`proposal<br/>`DispatchTimeBlockNumber`enactment_moment<br/> |
| Place decision deposit    |        |           |                  |         | `ReferendumIndex`index<br/>                                                                                       |
| Refund decision deposit   |        |           |                  |         | `ReferendumIndex`index<br/>                                                                                       |
| Cancel                    |        |           |                  |         | `ReferendumIndex`index<br/>                                                                                       |
| Kill                      |        |           |                  |         | `ReferendumIndex`index<br/>                                                                                       |
| Nudge referendum          |        |           |                  |         | `ReferendumIndex`index<br/>                                                                                       |
| One fewer deciding        |        |           |                  |         | `TrackIdOf`track<br/>                                                                                             |
| Refund submission deposit |        |           |                  |         | `ReferendumIndex`index<br/>                                                                                       |
| Set metadata              |        |           |                  |         | `ReferendumIndex`index<br/>`OptionHash`maybe_hash<br/>                                                            |

## Whitelist

| Name                                    | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                      |
| --------------------------------------- | ------ | --------- | ---------------- | ------- | ------------------------------------------------------------------------------ |
| Whitelist call                          |        |           |                  |         | `Hash`call_hash<br/>                                                           |
| Remove whitelisted call                 |        |           |                  |         | `Hash`call_hash<br/>                                                           |
| Dispatch whitelisted call               |        |           |                  |         | `Hash`call_hash<br/>`u32`call_encoded_len<br/>`Weight`call_weight_witness<br/> |
| Dispatch whitelisted call with preimage |        |           |                  |         | `Call`call<br/>                                                                |

## Claims

| Name         | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                                         |
| ------------ | ------ | --------- | ---------------- | ------- | ------------------------------------------------------------------------------------------------------------------------------------------------- |
| Claim        |        |           |                  |         | `AccountId`dest<br/>`EcdsaSignature`ethereum_signature<br/>                                                                                       |
| Mint claim   |        |           |                  |         | `EthereumAddress`who<br/>`Balance`amount<br/>`OptionTupleBalanceOfTBalanceOfTBlockNumber`vesting_schedule<br/>`OptionStatementKind`statement<br/> |
| Claim attest |        |           |                  |         | `AccountId`dest<br/>`EcdsaSignature`ethereum_signature<br/>`Bytes`statement<br/>                                                                  |
| Attest       |        |           |                  |         | `Bytes`statement<br/>                                                                                                                             |
| Move claim   |        |           |                  |         | `EthereumAddress`old<br/>`EthereumAddress`new\_<br/>`OptionAccountId`maybe_preclaim<br/>                                                          |

## Utility

| Name          | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                       |
| ------------- | ------------------ | ------------------ | ------------------ | ------- | ----------------------------------------------- |
| Batch         | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `VecCall`calls<br/>                             |
| As derivative |                    |                    |                    |         | `u16`index<br/>`Call`call<br/>                  |
| Batch all     | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `VecCall`calls<br/>                             |
| Dispatch as   |                    | :heavy_check_mark: | :heavy_check_mark: |         | `BoxPalletsOrigin`as_origin<br/>`Call`call<br/> |
| Force batch   | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `VecCall`calls<br/>                             |
| With weight   |                    | :heavy_check_mark: | :heavy_check_mark: |         | `Call`call<br/>`Weight`weight<br/>              |

## Identity

| Name                      | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                                                                       |
| ------------------------- | ------ | ------------------ | ------------------ | ------- | --------------------------------------------------------------------------------------------------------------- |
| Add registrar             |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`account<br/>                                                                                |
| Set identity              |        | :heavy_check_mark: | :heavy_check_mark: |         | `IdentityInfo`info<br/>                                                                                         |
| Set subs                  |        | :heavy_check_mark: | :heavy_check_mark: |         | `VecTupleAccountIdData`subs<br/>                                                                                |
| Clear identity            |        | :heavy_check_mark: | :heavy_check_mark: |         |                                                                                                                 |
| Request judgement         |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`reg_index<br/>`Compactu128`max_fee<br/>                                                             |
| Cancel request            |        | :heavy_check_mark: | :heavy_check_mark: |         | `RegistrarIndex`reg_index<br/>                                                                                  |
| Set fee                   |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`index<br/>`Compactu128`fee<br/>                                                                     |
| Set account id            |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`index<br/>`AccountIdLookupOfT`new\_<br/>                                                            |
| Set fields                |        |                    |                    |         | `Compactu32`index<br/>`IdentityInformationasIdentityInformationProviderFieldsIdentifier`fields<br/>             |
| Provide judgement         |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`reg_index<br/>`AccountIdLookupOfT`target<br/>`JudgementBalanceOfT`judgement<br/>`Hash`identity<br/> |
| Kill identity             |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`target<br/>                                                                                 |
| Add sub                   |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`sub<br/>`Data`data<br/>                                                                     |
| Rename sub                |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`sub<br/>`Data`data<br/>                                                                     |
| Remove sub                |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`sub<br/>                                                                                    |
| Quit sub                  |        | :heavy_check_mark: | :heavy_check_mark: |         |                                                                                                                 |
| Add username authority    |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`authority<br/>`Vecu8`suffix<br/>`u32`allocation<br/>                                        |
| Remove username authority |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`authority<br/>                                                                              |
| Set username for          |        |                    |                    |         | `AccountIdLookupOfT`who<br/>`Vecu8`username<br/>`OptionOffchainSignature`signature<br/>                         |
| Accept username           |        |                    |                    |         | `UsernameT`username<br/>                                                                                        |
| Remove expired approval   |        |                    |                    |         | `UsernameT`username<br/>                                                                                        |
| Set primary username      |        |                    |                    |         | `UsernameT`username<br/>                                                                                        |
| Remove dangling username  |        |                    |                    |         | `UsernameT`username<br/>                                                                                        |

## Society

| Name                   | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                                        |
| ---------------------- | ------ | --------- | ---------------- | ------- | ------------------------------------------------------------------------------------------------------------------------------------------------ |
| Bid                    |        |           |                  |         | `BalanceOf`amount<br/>                                                                                                                           |
| Unbid                  |        |           |                  |         |                                                                                                                                                  |
| Vouch                  |        |           |                  |         | `AccountIdLookupOfT`who<br/>`BalanceOf`amount<br/>`BalanceOf`tip<br/>                                                                            |
| Unvouch                |        |           |                  |         |                                                                                                                                                  |
| Vote                   |        |           |                  |         | `AccountIdLookupOfT`candidate<br/>`bool`approve<br/>                                                                                             |
| Defender vote          |        |           |                  |         | `bool`approve<br/>                                                                                                                               |
| Payout                 |        |           |                  |         |                                                                                                                                                  |
| Waive repay            |        |           |                  |         | `BalanceOf`amount<br/>                                                                                                                           |
| Found society          |        |           |                  |         | `AccountIdLookupOfT`founder<br/>`u32`max_members<br/>`u32`max_intake<br/>`u32`max_strikes<br/>`BalanceOf`candidate_deposit<br/>`Vecu8`rules<br/> |
| Dissolve               |        |           |                  |         |                                                                                                                                                  |
| Judge suspended member |        |           |                  |         | `AccountIdLookupOfT`who<br/>`bool`forgive<br/>                                                                                                   |
| Set parameters         |        |           |                  |         | `u32`max_members<br/>`u32`max_intake<br/>`u32`max_strikes<br/>`BalanceOf`candidate_deposit<br/>                                                  |
| Punish skeptic         |        |           |                  |         |                                                                                                                                                  |
| Claim membership       |        |           |                  |         |                                                                                                                                                  |
| Bestow membership      |        |           |                  |         | `AccountId`candidate<br/>                                                                                                                        |
| Kick candidate         |        |           |                  |         | `AccountId`candidate<br/>                                                                                                                        |
| Resign candidacy       |        |           |                  |         |                                                                                                                                                  |
| Drop candidate         |        |           |                  |         | `AccountId`candidate<br/>                                                                                                                        |
| Cleanup candidacy      |        |           |                  |         | `AccountId`candidate<br/>`u32`max<br/>                                                                                                           |
| Cleanup challenge      |        |           |                  |         | `RoundIndex`challenge_round<br/>`u32`max<br/>                                                                                                    |

## Recovery

| Name              | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                   |
| ----------------- | ------ | --------- | ---------------- | ------- | --------------------------------------------------------------------------- |
| As recovered      |        |           |                  |         | `AccountIdLookupOfT`account<br/>`Call`call<br/>                             |
| Set recovered     |        |           |                  |         | `AccountIdLookupOfT`lost<br/>`AccountIdLookupOfT`rescuer<br/>               |
| Create recovery   |        |           |                  |         | `VecAccountId`friends<br/>`u16`threshold<br/>`BlockNumber`delay_period<br/> |
| Initiate recovery |        |           |                  |         | `AccountIdLookupOfT`account<br/>                                            |
| Vouch recovery    |        |           |                  |         | `AccountIdLookupOfT`lost<br/>`AccountIdLookupOfT`rescuer<br/>               |
| Claim recovery    |        |           |                  |         | `AccountIdLookupOfT`account<br/>                                            |
| Close recovery    |        |           |                  |         | `AccountIdLookupOfT`rescuer<br/>                                            |
| Remove recovery   |        |           |                  |         |                                                                             |
| Cancel recovered  |        |           |                  |         | `AccountIdLookupOfT`account<br/>                                            |

## Vesting

| Name                          | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                |
| ----------------------------- | ------ | --------- | ---------------- | ------- | ---------------------------------------------------------------------------------------- |
| Vest                          |        |           |                  |         |                                                                                          |
| Vest other                    |        |           |                  |         | `AccountIdLookupOfT`target<br/>                                                          |
| Vested transfer               |        |           |                  |         | `AccountIdLookupOfT`target<br/>`VestingInfo`schedule<br/>                                |
| Force vested transfer         |        |           |                  |         | `AccountIdLookupOfT`source<br/>`AccountIdLookupOfT`target<br/>`VestingInfo`schedule<br/> |
| Merge schedules               |        |           |                  |         | `u32`schedule1_index<br/>`u32`schedule2_index<br/>                                       |
| Force remove vesting schedule |        |           |                  |         | `LookupasStaticLookupSource`target<br/>`u32`schedule_index<br/>                          |

## Scheduler

| Name                 | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                                  |
| -------------------- | ------ | --------- | ---------------- | ------- | ------------------------------------------------------------------------------------------------------------------------------------------ |
| Schedule             |        |           |                  |         | `BlockNumber`when<br/>`OptionschedulePeriodBlockNumber`maybe_periodic<br/>`schedulePriority`priority<br/>`Call`call<br/>                   |
| Cancel               |        |           |                  |         | `BlockNumber`when<br/>`u32`index<br/>                                                                                                      |
| Schedule named       |        |           |                  |         | `TaskName`id<br/>`BlockNumber`when<br/>`OptionschedulePeriodBlockNumber`maybe_periodic<br/>`schedulePriority`priority<br/>`Call`call<br/>  |
| Cancel named         |        |           |                  |         | `TaskName`id<br/>                                                                                                                          |
| Schedule after       |        |           |                  |         | `BlockNumber`after<br/>`OptionschedulePeriodBlockNumber`maybe_periodic<br/>`schedulePriority`priority<br/>`Call`call<br/>                  |
| Schedule named after |        |           |                  |         | `TaskName`id<br/>`BlockNumber`after<br/>`OptionschedulePeriodBlockNumber`maybe_periodic<br/>`schedulePriority`priority<br/>`Call`call<br/> |

## Proxy

| Name                | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                                                                  |
| ------------------- | ------ | ------------------ | ------------------ | ------------------ | -------------------------------------------------------------------------------------------------------------------------- |
| Proxy               |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`real<br/>`OptionProxyType`force_proxy_type<br/>`Call`call<br/>                                         |
| Add proxy           |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`delegate<br/>`ProxyType`proxy_type<br/>`BlockNumber`delay<br/>                                         |
| Remove proxy        |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`delegate<br/>`ProxyType`proxy_type<br/>`BlockNumber`delay<br/>                                         |
| Remove proxies      |        | :heavy_check_mark: | :heavy_check_mark: |                    |                                                                                                                            |
| Create pure         |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `ProxyType`proxy_type<br/>`BlockNumber`delay<br/>`u16`index<br/>                                                           |
| Kill pure           |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`spawner<br/>`ProxyType`proxy_type<br/>`u16`index<br/>`Compactu32`height<br/>`Compactu32`ext_index<br/> |
| Announce            |        |                    |                    |                    | `AccountIdLookupOfT`real<br/>`CallHashOf`call_hash<br/>                                                                    |
| Remove announcement |        |                    |                    |                    | `AccountIdLookupOfT`real<br/>`CallHashOf`call_hash<br/>                                                                    |
| Reject announcement |        |                    |                    |                    | `AccountIdLookupOfT`delegate<br/>`CallHashOf`call_hash<br/>                                                                |
| Proxy announced     |        | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`delegate<br/>`AccountIdLookupOfT`real<br/>`OptionProxyType`force_proxy_type<br/>`Call`call<br/>        |

## Multisig

| Name                 | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                                                                               |
| -------------------- | ------ | ------------------ | ------------------ | ------------------ | --------------------------------------------------------------------------------------------------------------------------------------- |
| As multi threshold 1 |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `VecAccountId`other_signatories<br/>`Call`call<br/>                                                                                     |
| As multi             |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u16`threshold<br/>`VecAccountId`other_signatories<br/>`OptionTimepoint`maybe_timepoint<br/>`Call`call<br/>`Weight`max_weight<br/>      |
| Approve as multi     |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u16`threshold<br/>`VecAccountId`other_signatories<br/>`OptionTimepoint`maybe_timepoint<br/>`H256`call_hash<br/>`Weight`max_weight<br/> |
| Cancel as multi      |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u16`threshold<br/>`VecAccountId`other_signatories<br/>`Timepoint`timepoint<br/>`H256`call_hash<br/>                                    |

## Preimage

| Name               | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments            |
| ------------------ | ------ | --------- | ---------------- | ------- | -------------------- |
| Note preimage      |        |           |                  |         | `Vecu8`bytes<br/>    |
| Unnote preimage    |        |           |                  |         | `Hash`hash<br/>      |
| Request preimage   |        |           |                  |         | `Hash`hash<br/>      |
| Unrequest preimage |        |           |                  |         | `Hash`hash<br/>      |
| Ensure updated     |        |           |                  |         | `VecHash`hashes<br/> |

## Bounties

| Name                 | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                                          |
| -------------------- | ------ | ------------------ | ------------------ | ------- | ---------------------------------------------------------------------------------- |
| Propose bounty       |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`amount<br/>`Bytes`description<br/>                                 |
| Approve bounty       |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`bounty_id<br/>                                                         |
| Propose curator      |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`bounty_id<br/>`AccountIdLookupOfT`curator<br/>`CompactBalance`fee<br/> |
| Unassign curator     |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`bounty_id<br/>                                                         |
| Accept curator       |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`bounty_id<br/>                                                         |
| Award bounty         |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`bounty_id<br/>`AccountIdLookupOfT`beneficiary<br/>                     |
| Claim bounty         |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`bounty_id<br/>                                                         |
| Close bounty         |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`bounty_id<br/>                                                         |
| Extend bounty expiry |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`bounty_id<br/>`Bytes`remark<br/>                                       |

## ChildBounties

| Name               | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                                                                                 |
| ------------------ | ------ | ------------------ | ------------------ | ------- | ------------------------------------------------------------------------------------------------------------------------- |
| Add child bounty   |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`parent_bounty_id<br/>`CompactBalance`amount<br/>`Vecu8`description<br/>                                       |
| Propose curator    |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`parent_bounty_id<br/>`Compactu32`child_bounty_id<br/>`AccountIdLookupOfT`curator<br/>`CompactBalance`fee<br/> |
| Accept curator     |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`parent_bounty_id<br/>`Compactu32`child_bounty_id<br/>                                                         |
| Unassign curator   |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`parent_bounty_id<br/>`Compactu32`child_bounty_id<br/>                                                         |
| Award child bounty |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`parent_bounty_id<br/>`Compactu32`child_bounty_id<br/>`AccountIdLookupOfT`beneficiary<br/>                     |
| Claim child bounty |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`parent_bounty_id<br/>`Compactu32`child_bounty_id<br/>                                                         |
| Close child bounty |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`parent_bounty_id<br/>`Compactu32`child_bounty_id<br/>                                                         |

## ElectionProviderMultiPhase

| Name                          | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                  |
| ----------------------------- | ------ | --------- | ---------------- | ------- | ------------------------------------------------------------------------------------------ |
| Submit unsigned               |        |           |                  |         | `BoxRawSolutionSolutionOfMinerConfig`raw_solution<br/>`SolutionOrSnapshotSize`witness<br/> |
| Set minimum untrusted score   |        |           |                  |         | `OptionElectionScore`maybe_next_score<br/>                                                 |
| Set emergency election result |        |           |                  |         | `SupportsAccountId`supports<br/>                                                           |
| Submit                        |        |           |                  |         | `BoxRawSolutionSolutionOfMinerConfig`raw_solution<br/>                                     |
| Governance fallback           |        |           |                  |         | `Optionu32`maybe_max_voters<br/>`Optionu32`maybe_max_targets<br/>                          |

## Nis

| Name          | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                      |
| ------------- | ------ | --------- | ---------------- | ------- | -------------------------------------------------------------- |
| Place bid     |        |           |                  |         | `Compactu128`amount<br/>`u32`duration<br/>                     |
| Retract bid   |        |           |                  |         | `Compactu128`amount<br/>`u32`duration<br/>                     |
| Fund deficit  |        |           |                  |         |                                                                |
| Thaw private  |        |           |                  |         | `Compactu32`index<br/>`OptionPerquintill`maybe_proportion<br/> |
| Thaw communal |        |           |                  |         | `Compactu32`index<br/>                                         |
| Communify     |        |           |                  |         | `Compactu32`index<br/>                                         |
| Privatize     |        |           |                  |         | `Compactu32`index<br/>                                         |

## NisCounterpartBalances

| Name                        | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                            |
| --------------------------- | ------ | --------- | ---------------- | ------- | ------------------------------------------------------------------------------------ |
| Transfer allow death        |        |           |                  |         | `AccountIdLookupOfT`dest<br/>`Compactu128`amount<br/>                                |
| Force transfer              |        |           |                  |         | `AccountIdLookupOfT`source<br/>`AccountIdLookupOfT`dest<br/>`Compactu128`amount<br/> |
| Transfer keep alive         |        |           |                  |         | `AccountIdLookupOfT`dest<br/>`Compactu128`amount<br/>                                |
| Transfer all                |        |           |                  |         | `AccountIdLookupOfT`dest<br/>`bool`keep_alive<br/>                                   |
| Force unreserve             |        |           |                  |         | `AccountIdLookupOfT`who<br/>`Balance`amount<br/>                                     |
| Upgrade accounts            |        |           |                  |         | `VecAccountId`who<br/>                                                               |
| Force set balance           |        |           |                  |         | `AccountIdLookupOfT`who<br/>`Compactu128`new_free<br/>                               |
| Force adjust total issuance |        |           |                  |         | `AdjustmentDirection`direction<br/>`Compactu128`delta<br/>                           |

## VoterList

| Name                  | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                        |
| --------------------- | ------ | --------- | ---------------- | ------- | ---------------------------------------------------------------- |
| Rebag                 |        |           |                  |         | `AccountIdLookupOfT`dislocated<br/>                              |
| Put in front of       |        |           |                  |         | `AccountIdLookupOfT`lighter<br/>                                 |
| Put in front of other |        |           |                  |         | `AccountIdLookupOfT`heavier<br/>`AccountIdLookupOfT`lighter<br/> |

## NominationPools

| Name                            | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                                                                                                               |
| ------------------------------- | ------ | --------- | ---------------- | ------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Join                            |        |           |                  |         | `CompactBalance`amount<br/>`PoolId`pool_id<br/>                                                                                                                                                                         |
| Bond extra                      |        |           |                  |         | `BondExtraBalanceOfT`extra<br/>                                                                                                                                                                                         |
| Claim payout                    |        |           |                  |         |                                                                                                                                                                                                                         |
| Unbond                          |        |           |                  |         | `AccountIdLookupOfT`member_account<br/>`CompactBalance`unbonding_points<br/>                                                                                                                                            |
| Pool withdraw unbonded          |        |           |                  |         | `PoolId`pool_id<br/>`u32`num_slashing_spans<br/>                                                                                                                                                                        |
| Withdraw Unbonded               |        |           |                  |         | `AccountIdLookupOfT`member_account<br/>`u32`num_slashing_spans<br/>                                                                                                                                                     |
| Create                          |        |           |                  |         | `CompactBalance`amount<br/>`AccountIdLookupOfT`root<br/>`AccountIdLookupOfT`nominator<br/>`AccountIdLookupOfT`bouncer<br/>                                                                                              |
| Create with pool id             |        |           |                  |         | `CompactBalance`amount<br/>`AccountIdLookupOfT`root<br/>`AccountIdLookupOfT`nominator<br/>`AccountIdLookupOfT`bouncer<br/>`PoolId`pool_id<br/>                                                                          |
| Nominate                        |        |           |                  |         | `PoolId`pool_id<br/>`VecAccountId`validators<br/>                                                                                                                                                                       |
| Set state                       |        |           |                  |         | `PoolId`pool_id<br/>`PoolState`state<br/>                                                                                                                                                                               |
| Set metadata                    |        |           |                  |         | `PoolId`pool_id<br/>`Vecu8`metadata<br/>                                                                                                                                                                                |
| Set configs                     |        |           |                  |         | `ConfigOpBalanceOfT`min_join_bond<br/>`ConfigOpBalanceOfT`min_create_bond<br/>`ConfigOpu32`max_pools<br/>`ConfigOpu32`max_members<br/>`ConfigOpu32`max_members_per_pool<br/>`ConfigOpPerbill`global_max_commission<br/> |
| Update roles                    |        |           |                  |         | `PoolId`pool_id<br/>`ConfigOpAccountId`new_root<br/>`ConfigOpAccountId`new_nominator<br/>`ConfigOpAccountId`new_bouncer<br/>                                                                                            |
| Chill                           |        |           |                  |         | `PoolId`pool_id<br/>                                                                                                                                                                                                    |
| Bond extra other                |        |           |                  |         | `AccountIdLookupOfT`member<br/>`BondExtraBalanceOfT`extra<br/>                                                                                                                                                          |
| Set claim permission            |        |           |                  |         | `ClaimPermission`permission<br/>                                                                                                                                                                                        |
| Claim payout other              |        |           |                  |         | `AccountId`other<br/>                                                                                                                                                                                                   |
| Set commission                  |        |           |                  |         | `PoolId`pool_id<br/>`OptionTuplePerbillAccountId`new_commission<br/>                                                                                                                                                    |
| Set commission max              |        |           |                  |         | `PoolId`pool_id<br/>`Perbill`max_commission<br/>                                                                                                                                                                        |
| Set commission change rate      |        |           |                  |         | `PoolId`pool_id<br/>`CommissionChangeRateBlockNumber`change_rate<br/>                                                                                                                                                   |
| Claim commission                |        |           |                  |         | `PoolId`pool_id<br/>                                                                                                                                                                                                    |
| Adjust pool deposit             |        |           |                  |         | `PoolId`pool_id<br/>                                                                                                                                                                                                    |
| Set commission claim permission |        |           |                  |         | `PoolId`pool_id<br/>`OptionCommissionClaimPermissionAccountId`permission<br/>                                                                                                                                           |

## FastUnstake

| Name                  | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                    |
| --------------------- | ------ | ------------------ | ------------------ | ------------------ | ---------------------------- |
| Register fast unstake |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                              |
| Deregister            |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                              |
| Control               |        | :heavy_check_mark: | :heavy_check_mark: |                    | `EraIndex`eras_to_check<br/> |

## Configuration

| Name                                          | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                        |
| --------------------------------------------- | ------ | ------------------ | ------------------ | ------- | -------------------------------- |
| Set validation upgrade cooldown               |        | :heavy_check_mark: | :heavy_check_mark: |         | `BlockNumber`new\_<br/>          |
| Set validation upgrade delay                  |        | :heavy_check_mark: | :heavy_check_mark: |         | `BlockNumber`new\_<br/>          |
| Set code retention period                     |        | :heavy_check_mark: | :heavy_check_mark: |         | `BlockNumber`new\_<br/>          |
| Set max code size                             |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                  |
| Set max pov size                              |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                  |
| Set max head data size                        |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                  |
| Set coretime cores                            |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                  |
| Set on demand retries                         |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                  |
| Set group rotation frequency                  |        | :heavy_check_mark: | :heavy_check_mark: |         | `BlockNumber`new\_<br/>          |
| Set paras availability period                 |        | :heavy_check_mark: | :heavy_check_mark: |         | `BlockNumber`new\_<br/>          |
| Set scheduling lookahead                      |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                  |
| Set max validators per core                   |        | :heavy_check_mark: | :heavy_check_mark: |         | `Optionu32`new\_<br/>            |
| Set max validators                            |        | :heavy_check_mark: | :heavy_check_mark: |         | `Optionu32`new\_<br/>            |
| Set dispute period                            |        | :heavy_check_mark: | :heavy_check_mark: |         | `SessionIndex`new\_<br/>         |
| Set dispute post conclusion acceptance period |        | :heavy_check_mark: | :heavy_check_mark: |         | `BlockNumber`new\_<br/>          |
| Set no show slots                             |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                  |
| Set n delay tranches                          |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                  |
| Set zeroth delay tranche width                |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                  |
| Set needed approvals                          |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                  |
| Set relay vrf modulo samples                  |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                  |
| Set max upward queue count                    |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                  |
| Set max upward queue size                     |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                  |
| Set max downward message size                 |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                  |
| Set max upward message size                   |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                  |
| Set max upward message num per candidate      |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                  |
| Set hrmp open request ttl                     |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                  |
| Set hrmp sender deposit                       |        | :heavy_check_mark: | :heavy_check_mark: |         | `Balance`new\_<br/>              |
| Set hrmp recipient deposit                    |        | :heavy_check_mark: | :heavy_check_mark: |         | `Balance`new\_<br/>              |
| Set hrmp channel max capacity                 |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                  |
| Set hrmp channel max total size               |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                  |
| Set hrmp max parachain inbound channels       |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                  |
| Set hrmp channel max message size             |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                  |
| Set hrmp max parachain outbound channels      |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                  |
| Set hrmp max message num per candidate        |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                  |
| Set pvf voting ttl                            |        | :heavy_check_mark: | :heavy_check_mark: |         | `SessionIndex`new\_<br/>         |
| Set minimum validation upgrade delay          |        | :heavy_check_mark: | :heavy_check_mark: |         | `BlockNumber`new\_<br/>          |
| Set bypass consistency check                  |        | :heavy_check_mark: | :heavy_check_mark: |         | `bool`new\_<br/>                 |
| Set async backing params                      |        |                    |                    |         | `AsyncBackingParams`new\_<br/>   |
| Set executor params                           |        |                    |                    |         | `ExecutorParams`new\_<br/>       |
| Set on demand base fee                        |        | :heavy_check_mark: | :heavy_check_mark: |         | `Balance`new\_<br/>              |
| Set on demand fee variability                 |        | :heavy_check_mark: | :heavy_check_mark: |         | `Perbill`new\_<br/>              |
| Set on demand queue max size                  |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                  |
| Set on demand target queue utilization        |        | :heavy_check_mark: | :heavy_check_mark: |         | `Perbill`new\_<br/>              |
| Set on demand ttl                             |        | :heavy_check_mark: | :heavy_check_mark: |         | `BlockNumber`new\_<br/>          |
| Set minimum backing votes                     |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                  |
| Set node feature                              |        | :heavy_check_mark: | :heavy_check_mark: |         | `u8`index<br/>`bool`value<br/>   |
| Set approval voting params                    |        |                    |                    |         | `ApprovalVotingParams`new\_<br/> |

## ParasShared

| Name | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments |
| ---- | ------ | --------- | ---------------- | ------- | --------- |

## ParaInclusion

| Name | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments |
| ---- | ------ | --------- | ---------------- | ------- | --------- |

## ParaInherent

| Name  | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                               |
| ----- | ------ | --------- | ---------------- | ------- | --------------------------------------- |
| Enter |        |           |                  |         | `ParachainsInherentDataHeader`data<br/> |

## Paras

| Name                          | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                           |
| ----------------------------- | ------ | --------- | ---------------- | ------- | ----------------------------------------------------------------------------------- |
| Force set current code        |        |           |                  |         | `ParaId`para<br/>`ValidationCode`new_code<br/>                                      |
| Force set current head        |        |           |                  |         | `ParaId`para<br/>`HeadData`new_head<br/>                                            |
| Force schedule code upgrade   |        |           |                  |         | `ParaId`para<br/>`ValidationCode`new_code<br/>`BlockNumber`relay_parent_number<br/> |
| Force note new head           |        |           |                  |         | `ParaId`para<br/>`HeadData`new_head<br/>                                            |
| Force queue action            |        |           |                  |         | `ParaId`para<br/>                                                                   |
| Add trusted validation code   |        |           |                  |         | `ValidationCode`validation_code<br/>                                                |
| Poke unused validation code   |        |           |                  |         | `ValidationCodeHash`validation_code_hash<br/>                                       |
| Include pvf check statement   |        |           |                  |         | `PvfCheckStatement`stmt<br/>`ValidatorSignature`signature<br/>                      |
| Force set most recent context |        |           |                  |         | `ParaId`para<br/>`BlockNumber`context<br/>                                          |

## Initializer

| Name          | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments               |
| ------------- | ------ | --------- | ---------------- | ------- | ----------------------- |
| Force approve |        |           |                  |         | `BlockNumber`up_to<br/> |

## Hrmp

| Name                          | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                 |
| ----------------------------- | ------ | --------- | ---------------- | ------- | ----------------------------------------------------------------------------------------- |
| Hrmp init open channel        |        |           |                  |         | `ParaId`recipient<br/>`u32`proposed_max_capacity<br/>`u32`proposed_max_message_size<br/>  |
| Hrmp accept open channel      |        |           |                  |         | `ParaId`sender<br/>                                                                       |
| Hrmp close channel            |        |           |                  |         | `HrmpChannelId`channel_id<br/>                                                            |
| Force clean hrmp              |        |           |                  |         | `ParaId`para<br/>`u32`num_inbound<br/>`u32`num_outbound<br/>                              |
| Force process hrmp open       |        |           |                  |         | `u32`channels<br/>                                                                        |
| Force process hrmp close      |        |           |                  |         | `u32`channels<br/>                                                                        |
| Hrmp cancel open request      |        |           |                  |         | `HrmpChannelId`channel_id<br/>`u32`open_requests<br/>                                     |
| Force open hrmp channel       |        |           |                  |         | `ParaId`sender<br/>`ParaId`recipient<br/>`u32`max_capacity<br/>`u32`max_message_size<br/> |
| Establish system channel      |        |           |                  |         | `ParaId`sender<br/>`ParaId`recipient<br/>                                                 |
| Poke channel deposits         |        |           |                  |         | `ParaId`sender<br/>`ParaId`recipient<br/>                                                 |
| Establish channel with system |        |           |                  |         | `ParaId`target_system_chain<br/>                                                          |

## ParasDisputes

| Name           | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments |
| -------------- | ------ | --------- | ---------------- | ------- | --------- |
| Force unfreeze |        |           |                  |         |           |

## ParasSlashing

| Name                         | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                              |
| ---------------------------- | ------ | --------- | ---------------- | ------- | ---------------------------------------------------------------------- |
| Report dispute lost unsigned |        |           |                  |         | `BoxDisputeProof`dispute_proof<br/>`KeyOwnerProof`key_owner_proof<br/> |

## OnDemandAssignmentProvider

| Name                    | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                    |
| ----------------------- | ------ | --------- | ---------------- | ------- | -------------------------------------------- |
| Place order allow death |        |           |                  |         | `Balance`max_amount<br/>`ParaId`para_id<br/> |
| Place order keep alive  |        |           |                  |         | `Balance`max_amount<br/>`ParaId`para_id<br/> |

## Registrar

| Name                  | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                              |
| --------------------- | ------ | --------- | ---------------- | ------- | ---------------------------------------------------------------------------------------------------------------------- |
| Register              |        |           |                  |         | `ParaId`id<br/>`HeadData`genesis_head<br/>`ValidationCode`validation_code<br/>                                         |
| Force register        |        |           |                  |         | `AccountId`who<br/>`Balance`deposit<br/>`ParaId`id<br/>`HeadData`genesis_head<br/>`ValidationCode`validation_code<br/> |
| Deregister            |        |           |                  |         | `ParaId`id<br/>                                                                                                        |
| Swap                  |        |           |                  |         | `ParaId`id<br/>`ParaId`other<br/>                                                                                      |
| Remove lock           |        |           |                  |         | `ParaId`para<br/>                                                                                                      |
| Reserve               |        |           |                  |         |                                                                                                                        |
| Add lock              |        |           |                  |         | `ParaId`para<br/>                                                                                                      |
| Schedule code upgrade |        |           |                  |         | `ParaId`para<br/>`ValidationCode`new_code<br/>                                                                         |
| Set current head      |        |           |                  |         | `ParaId`para<br/>`HeadData`new_head<br/>                                                                               |

## Slots

| Name             | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                     |
| ---------------- | ------ | --------- | ---------------- | ------- | ----------------------------------------------------------------------------------------------------------------------------- |
| Force lease      |        |           |                  |         | `ParaId`para<br/>`AccountId`leaser<br/>`Balance`amount<br/>`LeasePeriodOfT`period_begin<br/>`LeasePeriodOfT`period_count<br/> |
| Clear all leases |        |           |                  |         | `ParaId`para<br/>                                                                                                             |
| Trigger onboard  |        |           |                  |         | `ParaId`para<br/>                                                                                                             |

## Auctions

| Name           | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                           |
| -------------- | ------ | --------- | ---------------- | ------- | ----------------------------------------------------------------------------------------------------------------------------------- |
| New auction    |        |           |                  |         | `Compactu32`duration<br/>`Compactu32`lease_period_index<br/>                                                                        |
| Bid            |        |           |                  |         | `Compactu32`para<br/>`Compactu32`auction_index<br/>`Compactu32`first_slot<br/>`Compactu32`last_slot<br/>`CompactBalance`amount<br/> |
| Cancel auction |        |           |                  |         |                                                                                                                                     |

## Crowdloan

| Name           | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                                                |
| -------------- | ------ | --------- | ---------------- | ------- | -------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Create         |        |           |                  |         | `Compactu32`index<br/>`Compactu128`cap<br/>`Compactu32`first_period<br/>`Compactu32`last_period<br/>`Compactu32`end<br/>`OptionMultiSigner`verifier<br/> |
| Contribute     |        |           |                  |         | `Compactu32`index<br/>`Compactu128`amount<br/>`OptionMultiSignature`signature<br/>                                                                       |
| Withdraw       |        |           |                  |         | `AccountId`who<br/>`Compactu32`index<br/>                                                                                                                |
| Refund         |        |           |                  |         | `Compactu32`index<br/>                                                                                                                                   |
| Dissolve       |        |           |                  |         | `Compactu32`index<br/>                                                                                                                                   |
| Edit           |        |           |                  |         | `Compactu32`index<br/>`Compactu128`cap<br/>`Compactu32`first_period<br/>`Compactu32`last_period<br/>`Compactu32`end<br/>`OptionMultiSigner`verifier<br/> |
| Add memo       |        |           |                  |         | `ParaId`index<br/>`Vecu8`memo<br/>                                                                                                                       |
| Poke           |        |           |                  |         | `ParaId`index<br/>                                                                                                                                       |
| Contribute all |        |           |                  |         | `Compactu32`index<br/>`OptionMultiSignature`signature<br/>                                                                                               |

## Coretime

| Name               | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                            |
| ------------------ | ------ | --------- | ---------------- | ------- | ------------------------------------------------------------------------------------------------------------------------------------ |
| Request core count |        |           |                  |         | `u16`count<br/>                                                                                                                      |
| Assign core        |        |           |                  |         | `BrokerCoreIndex`core<br/>`BlockNumber`begin<br/>`VecTupleCoreAssignmentPartsOf57600`assignment<br/>`OptionBlockNumber`end_hint<br/> |

## XcmPallet

| Name                                | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                                                                                                                                                           |
| ----------------------------------- | ------ | --------- | ---------------- | ------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Send                                |        |           |                  |         | `BoxVersionedLocation`dest<br/>`BoxVersionedXcmTuple`message<br/>                                                                                                                                                                                                   |
| Teleport assets                     |        |           |                  |         | `BoxVersionedLocation`dest<br/>`BoxVersionedLocation`beneficiary<br/>`BoxVersionedAssets`assets<br/>`u32`fee_asset_item<br/>                                                                                                                                        |
| Reserve transfer assets             |        |           |                  |         | `BoxVersionedLocation`dest<br/>`BoxVersionedLocation`beneficiary<br/>`BoxVersionedAssets`assets<br/>`u32`fee_asset_item<br/>                                                                                                                                        |
| Execute                             |        |           |                  |         | `BoxVersionedXcmTasConfigRuntimeCall`message<br/>`Weight`max_weight<br/>                                                                                                                                                                                            |
| Force xcm version                   |        |           |                  |         | `BoxLocation`location<br/>`XcmVersion`version<br/>                                                                                                                                                                                                                  |
| Force default xcm version           |        |           |                  |         | `OptionXcmVersion`maybe_xcm_version<br/>                                                                                                                                                                                                                            |
| Force subscribe version notify      |        |           |                  |         | `BoxVersionedLocation`location<br/>                                                                                                                                                                                                                                 |
| Force unsubscribe version notify    |        |           |                  |         | `BoxVersionedLocation`location<br/>                                                                                                                                                                                                                                 |
| Limited reserve transfer assets     |        |           |                  |         | `BoxVersionedLocation`dest<br/>`BoxVersionedLocation`beneficiary<br/>`BoxVersionedAssets`assets<br/>`u32`fee_asset_item<br/>`WeightLimit`weight_limit<br/>                                                                                                          |
| Limited teleport assets             |        |           |                  |         | `BoxVersionedLocation`dest<br/>`BoxVersionedLocation`beneficiary<br/>`BoxVersionedAssets`assets<br/>`u32`fee_asset_item<br/>`WeightLimit`weight_limit<br/>                                                                                                          |
| Force suspension                    |        |           |                  |         | `bool`suspended<br/>                                                                                                                                                                                                                                                |
| Transfer assets                     |        |           |                  |         | `BoxVersionedLocation`dest<br/>`BoxVersionedLocation`beneficiary<br/>`BoxVersionedAssets`assets<br/>`u32`fee_asset_item<br/>`WeightLimit`weight_limit<br/>                                                                                                          |
| Claim assets                        |        |           |                  |         | `BoxVersionedAssets`assets<br/>`BoxVersionedLocation`beneficiary<br/>                                                                                                                                                                                               |
| Transfer assets using type and then |        |           |                  |         | `BoxVersionedLocation`dest<br/>`BoxVersionedAssets`assets<br/>`BoxTransferType`assets_transfer_type<br/>`BoxVersionedAssetId`remote_fees_id<br/>`BoxTransferType`fees_transfer_type<br/>`BoxVersionedXcmTuple`custom_xcm_on_dest<br/>`WeightLimit`weight_limit<br/> |

## MessageQueue

| Name               | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                          |
| ------------------ | ------ | --------- | ---------------- | ------- | -------------------------------------------------------------------------------------------------- |
| Reap page          |        |           |                  |         | `MessageOriginOfT`message_origin<br/>`PageIndex`page_index<br/>                                    |
| Execute overweight |        |           |                  |         | `MessageOriginOfT`message_origin<br/>`PageIndex`page<br/>`Size`index<br/>`Weight`weight_limit<br/> |

## AssetRate

| Name   | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                         |
| ------ | ------ | --------- | ---------------- | ------- | ------------------------------------------------- |
| Create |        |           |                  |         | `BoxAssetKind`asset_kind<br/>`FixedU128`rate<br/> |
| Update |        |           |                  |         | `BoxAssetKind`asset_kind<br/>`FixedU128`rate<br/> |
| Remove |        |           |                  |         | `BoxAssetKind`asset_kind<br/>                     |

## Beefy

| Name                         | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                                |
| ---------------------------- | ------ | --------- | ---------------- | ------- | ---------------------------------------------------------------------------------------------------------------------------------------- |
| Report equivocation          |        |           |                  |         | `BoxEquivocationProofBlockNumberForTBeefyIdBeefyIdasRuntimeAppPublicSignature`equivocation_proof<br/>`KeyOwnerProof`key_owner_proof<br/> |
| Report equivocation unsigned |        |           |                  |         | `BoxEquivocationProofBlockNumberForTBeefyIdBeefyIdasRuntimeAppPublicSignature`equivocation_proof<br/>`KeyOwnerProof`key_owner_proof<br/> |
| Set new genesis              |        |           |                  |         | `BlockNumber`delay_in_blocks<br/>                                                                                                        |

## IdentityMigrator

| Name          | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments           |
| ------------- | ------ | --------- | ---------------- | ------- | ------------------- |
| Reap identity |        |           |                  |         | `AccountId`who<br/> |
| Poke deposit  |        |           |                  |         | `AccountId`who<br/> |
