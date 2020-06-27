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

#define ALLOW_LIST_SIZE         50
#define ALLOW_LIST_ITEM_SIZE    32

typedef struct {
    uint8_t address[ALLOW_LIST_ITEM_SIZE];
} allow_list_item_t;

// TODO: master pubkey

typedef struct {
    uint8_t signature[64];  // Ed25519
    uint8_t len;
    allow_list_item_t items[ALLOW_LIST_SIZE];
} allow_list_t;

#ifdef __cplusplus
extern "C" {
#endif

bool allowlist_is_active();

bool allowlist_validate(uint8_t *address);

void allowlist_update(allow_list_t *new);

#ifdef __cplusplus
}
#endif
