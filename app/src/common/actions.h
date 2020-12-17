/*******************************************************************************
*   (c) 2019 Zondax GmbH
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

#include <stdint.h>
#include "crypto.h"
#include "tx.h"
#include "apdu_codes.h"
#include <os_io_seproxyhal.h>
#include "coin.h"
#include "zxerror.h"

extern uint16_t action_addrResponseLen;
extern uint16_t action_signResponseLen;


__Z_INLINE zxerr_t app_sign_standalone() {
    const uint8_t *message = tx_get_buffer();
    const uint16_t messageLength = tx_get_buffer_length();
    uint16_t replyLen = 0;
    zxerr_t err = crypto_sign(G_io_apdu_buffer, IO_APDU_BUFFER_SIZE - 3,
                                    message, messageLength, &replyLen);
    return err;
}

__Z_INLINE void app_sign_ed25519() {
    const uint8_t *message = tx_get_buffer();
    const uint16_t messageLength = tx_get_buffer_length();
    uint16_t replyLen = 0;
    zxerr_t err = crypto_sign_ed25519(G_io_apdu_buffer, IO_APDU_BUFFER_SIZE - 3,
                              message, messageLength, &replyLen);
    if(err != zxerr_ok){
        set_code(G_io_apdu_buffer, 0, APDU_CODE_SIGN_VERIFY_ERROR);
        io_exchange(CHANNEL_APDU | IO_RETURN_AFTER_TX, 2);
    }else {
        set_code(G_io_apdu_buffer, 64, APDU_CODE_OK);
        io_exchange(CHANNEL_APDU | IO_RETURN_AFTER_TX, 64 + 2);
    }
}

__Z_INLINE void app_sign() {
    MEMCPY(G_io_apdu_buffer, &N_sr25519_signdata.signature, 64);
    set_code(G_io_apdu_buffer, 64, APDU_CODE_OK);
    io_exchange(CHANNEL_APDU | IO_RETURN_AFTER_TX, 64 + 2);
}

__Z_INLINE void app_reject() {
    set_code(G_io_apdu_buffer, 0, APDU_CODE_COMMAND_NOT_ALLOWED);
    io_exchange(CHANNEL_APDU | IO_RETURN_AFTER_TX, 2);
}

__Z_INLINE zxerr_t app_fill_address(key_kind_e addressKind) {
    // Put data directly in the apdu buffer
    MEMZERO(G_io_apdu_buffer, IO_APDU_BUFFER_SIZE);
    CHECK_ZXERR(crypto_fillAddress(addressKind,
                                   G_io_apdu_buffer, IO_APDU_BUFFER_SIZE - 2,
                                   &action_addrResponseLen));
    return zxerr_ok;
}

__Z_INLINE key_kind_e get_key_type(uint8_t num){
    if (num == 0x00){
        return key_ed25519;
    }else if (num == 0x01){
        return key_sr25519;
    }else{
        return 0xff;
    }
}

__Z_INLINE void app_reply_error() {
    set_code(G_io_apdu_buffer, 0, APDU_CODE_DATA_INVALID);
    io_exchange(CHANNEL_APDU | IO_RETURN_AFTER_TX, 2);
}

__Z_INLINE void app_reply_address() {
    if (action_addrResponseLen == 0) {
        app_reply_error();
        return;
    }
    set_code(G_io_apdu_buffer, action_addrResponseLen, APDU_CODE_OK);
    io_exchange(CHANNEL_APDU | IO_RETURN_AFTER_TX, action_addrResponseLen + 2);
}
