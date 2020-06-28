/*******************************************************************************
*   (c) 2016 Ledger
*   (c) 2018 Zondax GmbH
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
#include "zxmacros.h"
#include <stdbool.h>

#define ALLOW_LIST_SIZE         128
#define ALLOW_LIST_ITEM_PUBKEY_SIZE    32

typedef struct {
    uint8_t pubkey[ALLOW_LIST_ITEM_PUBKEY_SIZE];
} allowlist_item_t;

// TODO: master pubkey

typedef struct {
    uint8_t signature[64];  // Ed25519
    uint32_t len;
    allowlist_item_t items[ALLOW_LIST_SIZE];
} allowlist_t;

#ifdef __cplusplus
extern "C" {
#endif

bool allowlist_masterkey_is_set();

bool allowlist_masterkey_get(uint8_t *out, size_t outLen);

bool allowlist_masterkey_set(uint8_t *in, size_t inLen);

bool allowlist_is_active();

bool allowlist_validate(uint8_t *address);

bool allowlist_upgrade(uint8_t *new_list_buffer, size_t new_list_buffer_len);

#ifdef __cplusplus
}
#endif
