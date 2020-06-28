/*******************************************************************************
*   (c) 2020 Zondax GmbH
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

#if defined(APP_RESTRICTED)

#include "os.h"
#include "cx.h"
#include "allowlist.h"

typedef struct {
    uint8_t has_been_set;
    uint8_t master_publickey[32];
} allowlist_internal_t;

allowlist_t NV_CONST
N_allowlist_impl __attribute__ ((aligned(64)));
allowlist_internal_t NV_CONST
N_allowlist_internal_impl __attribute__ ((aligned(64)));

#define N_allowlist (*(NV_VOLATILE allowlist_t *)PIC(&N_allowlist_impl))
#define N_allowlist_internal (*(NV_VOLATILE allowlist_internal_t *)PIC(&N_allowlist_internal_impl))

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

bool allowlist_masterkey_is_set() {
    return N_allowlist_internal.has_been_set;
}

bool allowlist_masterkey_get(uint8_t *out, size_t outLen) {
    if (!allowlist_masterkey_is_set()) {
        return false;
    }
    return false;
}

bool allowlist_masterkey_set(uint8_t *in, size_t inLen) {
    return false;
}

bool allowlist_is_active() {
    return allowlist_masterkey_is_set() && N_allowlist.len > 0;
}

bool allowlist_validate(uint8_t *address) {
    if (!allowlist_is_active()) {
        return false;
    }

    if (N_allowlist.len >= ALLOW_LIST_SIZE) {
        return false;
    }

    for (size_t i = 0; i < N_allowlist.len; i++) {
        uint8_t * p = (uint8_t *) PIC(N_allowlist.items[i].pubkey);
        if (MEMCMP(p, address, 32) == 0) {
            return true;
        }
    }

    return false;
}

bool allowlist_check_valid(uint8_t *new_list_buffer, size_t new_list_buffer_len) {
    if (!allowlist_masterkey_is_set()) {
        return false;
    }

    if (new_list_buffer == NULL) {
        return false;
    }

    const size_t header_size = sizeof(allowlist_t) - sizeof(allowlist_item_t) * ALLOW_LIST_ITEM_PUBKEY_SIZE;
    if (new_list_buffer_len < header_size) {
        // new list does not have enough data to contain the header
        return false;
    }

    // Let's check number of items
    allowlist_t *new_list = (allowlist_t *) new_list_buffer;
    if (new_list->len >= ALLOW_LIST_SIZE) {
        return false;
    }

    // Check size is correct. Header (signature+len) + items * len
    const size_t expected_size = header_size + sizeof(allowlist_item_t) * new_list->len;
    if (new_list_buffer_len != expected_size) {
        // Invalid size
        return false;
    }

    // Hash allowlist (len + items)
    uint8_t digest[32];

    cx_blake2b_t ctx;
    cx_blake2b_init(&ctx, 256);
    cx_hash(&ctx.header, CX_LAST, (uint8_t *) &new_list->len, sizeof(new_list->len), NULL, 0);
    cx_hash(&ctx.header, 0, (uint8_t *) new_list->items, sizeof(allowlist_item_t) * new_list->len, digest, sizeof(digest));

//    // TODO: confirm Ed25519 signature is valid
//    cx_ecfp_public_key_t cx_publicKey;
////    cx_ecfp_init_public_key(CX_CURVE_Ed25519, rawkey, rawkey_len, &cx_publicKey);
//    cx_ecfp_init_public_key(CX_CURVE_Ed25519, NULL, 0, &cx_publicKey);
//
//    return cx_eddsa_verify(&cx_publicKey,
//                           0, CX_SHA512,
//                           digest, sizeof(digest),
//                           NULL, 0,
//                           new_list->signature, sizeof(new_list->signature)) != 0;
    return false;
}

bool allowlist_upgrade(uint8_t *new_list_buffer, size_t new_list_buffer_len) {
    if (!allowlist_check_valid(new_list_buffer, new_list_buffer_len)) {
        // conditions to update allowlist are not satisfied
        return false;
    }

    // TODO: overwrite current allow list
    return true;
}

#endif
