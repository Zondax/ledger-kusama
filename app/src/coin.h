/*******************************************************************************
*  (c) 2020 Zondax GmbH
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
extern "C" {
#endif

#define CLA                             0x99

#define HDPATH_LEN_DEFAULT   5
#define HDPATH_0_DEFAULT     (0x80000000 | 0x2c)
#define HDPATH_1_DEFAULT     (0x80000000 | 0x1b2)       // 434

#define PK_LEN_ED25519       32u

typedef enum {
    addr_ed22519     = 0,
    addr_sr25519     = 1
} address_kind_e;

#define VIEW_ADDRESS_OFFSET_ED25519         (PK_LEN_ED25519)

// Coin Specific
#define PK_ADDRESS_TYPE                     COIN_ADDR_TYPE_KUSAMA
#define SUPPORTED_TX_VERSION                LEDGER_MAJOR_VERSION
#define SUPPORTED_SPEC_VERSION              LEDGER_MINOR_VERSION
#define SUPPORTED_MINIMUM_SPEC_VERSION      2008

#define COIN_AMOUNT_DECIMAL_PLACES          12
#define CRYPTO_BLOB_SKIP_BYTES              0

#define COIN_GENESIS_HASH                   "b0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafe"
#define COIN_NAME                           "Kusama"

#if defined(APP_STANDARD)
#include "coin_standard.h"
#elif defined(APP_RESTRICTED)
#include "coin_restricted.h"
#else
#error "APP VARIANT IS NOT SUPPORTED"
#endif

#ifdef __cplusplus
}
#endif
