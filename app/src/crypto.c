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

#include "crypto.h"
#include "base58.h"
#include "coin.h"
#include "cx.h"

uint32_t hdPath[HDPATH_LEN_DEFAULT];

zxerr_t crypto_extractPublicKey(const uint32_t path[HDPATH_LEN_DEFAULT],
                                uint8_t *pubKey, uint16_t pubKeyLen) {
    cx_ecfp_public_key_t cx_publicKey;
    cx_ecfp_private_key_t cx_privateKey;
    uint8_t privateKeyData[32];

    if (pubKeyLen < PK_LEN_ED25519) {
        return zxerr_invalid_crypto_settings;
    }

    BEGIN_TRY
    {
        TRY {
            // Generate keys
            os_perso_derive_node_bip32_seed_key(
                    HDW_NORMAL,
                    CX_CURVE_Ed25519,
                    path,
                    HDPATH_LEN_DEFAULT,
                    privateKeyData,
                    NULL,
                    NULL,
                    0);

            cx_ecfp_init_private_key(CX_CURVE_Ed25519, privateKeyData, 32, &cx_privateKey);
            cx_ecfp_init_public_key(CX_CURVE_Ed25519, NULL, 0, &cx_publicKey);
            cx_ecfp_generate_pair(CX_CURVE_Ed25519, &cx_publicKey, &cx_privateKey, 1);
        }
        FINALLY {
            MEMZERO(&cx_privateKey, sizeof(cx_privateKey));
            MEMZERO(privateKeyData, 32);
        }
    }
    END_TRY;

    // Format pubkey
    for (int i = 0; i < 32; i++) {
        pubKey[i] = cx_publicKey.W[64 - i];
    }

    if ((cx_publicKey.W[32] & 1) != 0) {
        pubKey[31] |= 0x80;
    }

    // FIXME: Let's try using this for sr25519

    uint8_t buffer[64];
    MEMZERO(buffer, sizeof(buffer));
    get_sr25519_pk(buffer, pubKey);
}

zxerr_t crypto_sign(uint8_t *signature, uint16_t signatureMaxlen,
                    const uint8_t *message, uint16_t messageLen,
                    uint16_t *signatureLen) {
    const uint8_t *toSign = message;
    uint8_t messageDigest[32];

    if (messageLen > 256) {
        // Hash it
        cx_blake2b_t ctx;
        cx_blake2b_init(&ctx, 256);
        cx_hash(&ctx.header, CX_LAST, message, messageLen, messageDigest, 32);
        toSign = messageDigest;
        messageLen = 32;
    }

    cx_ecfp_private_key_t cx_privateKey;
    uint8_t privateKeyData[32];
    int signatureLength = 0;
    unsigned int info = 0;

    BEGIN_TRY
    {
        TRY
        {
            // Generate keys
            os_perso_derive_node_bip32_seed_key(
                    HDW_NORMAL,
                    CX_CURVE_Ed25519,
                    hdPath,
                    HDPATH_LEN_DEFAULT,
                    privateKeyData,
                    NULL,
                    NULL,
                    0);
            cx_ecfp_init_private_key(CX_CURVE_Ed25519, privateKeyData, 32, &cx_privateKey);

            // Sign
            *signature = PREFIX_SIGNATURE_TYPE_ED25519;
            signatureLength = cx_eddsa_sign(&cx_privateKey,
                                            CX_LAST,
                                            CX_SHA512,
                                            toSign,
                                            messageLen,
                                            NULL,
                                            0,
                                            signature+1,
                                            signatureMaxlen-1,
                                            &info);
        }
        CATCH_ALL {
            return 0;
        };
        FINALLY {
            MEMZERO(&cx_privateKey, sizeof(cx_privateKey));
            MEMZERO(privateKeyData, 32);
        }
    }
    END_TRY;

    return signatureLength + 1;
}

zxerr_t crypto_fillAddress(address_kind_e addressKind, uint8_t *buffer, uint16_t bufferLen, uint16_t *addrResponseLen) {
    if (addressKind != addr_ed22519)

        if (bufferLen < PK_LEN_ED25519 + SS58_ADDRESS_MAX_LEN) {
            return 0;
        }
    MEMZERO(buffer, bufferLen);
    crypto_extractPublicKey(hdPath, buffer, bufferLen);

    size_t outLen = crypto_SS58EncodePubkey(buffer + PK_LEN_ED25519,
                                            bufferLen - PK_LEN_ED25519,
                                            PK_ADDRESS_TYPE, buffer);

    *addrResponseLen = PK_LEN_ED25519 + outLen;

    return PK_LEN_ED25519 + outLen;
}
