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

#include "allow_list.h"

#if defined(TARGET_NANOS)
allow_list_t N_allowlist_impl __attribute__ ((aligned(64)));
#define N_allowlist (*(allow_list_t *)PIC(&N_allowlist_impl))

#elif defined(TARGET_NANOX)
allow_list_t const N_allowlist_impl __attribute__ ((aligned(64)));
#define N_allowlist (*(volatile allow_list_t *)PIC(&N_allowlist_impl))
#endif


#if defined(TARGET_NANOS) || defined(TARGET_NANOX)
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

bool allowlist_is_active() {
    // TODO: check there is a master key
    if (N_allowlist.len == 0) {
        return false;
    }
    return true;
}

bool allowlist_validate(uint8_t *address) {
    if (!allowlist_is_active()) {
        return false;
    }

    for (size_t i=0; i<N_allowlist.len && i<ALLOW_LIST_SIZE; i++) {
        uint8_t *p = (uint8_t *)PIC(N_allowlist.items[i].address);
        if ( MEMCMP(p, address, 32) == 0 ) {
            return true;
        }
    }

    return false;
}

void allowlist_update(allow_list_t *new) {
    // TODO: check there is a master key
    // TODO: confirm signature is valid
    // TODO: restrict len to ALLOW_LIST_SIZE
    // TODO: overwrite current allow list
}

#else
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

bool allowlist_is_active() {
    return false;
}

bool allowlist_validate(uint8_t *address) {
    return false;
}

void allowlist_update(allow_list_t *new) { }

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

#endif
