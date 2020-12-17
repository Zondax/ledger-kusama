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
#include "rslib.h"

uint32_t hdPath[HDPATH_LEN_DEFAULT];

zxerr_t crypto_extractPublicKey(key_kind_e addressKind, const uint32_t path[HDPATH_LEN_DEFAULT],
                                uint8_t *pubKey, uint16_t pubKeyLen) {
    cx_ecfp_public_key_t cx_publicKey;
    cx_ecfp_private_key_t cx_privateKey;
    uint8_t privateKeyData[64];
    MEMZERO(privateKeyData, 64);

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


            switch (addressKind) {
                case key_ed22519: {
                    cx_ecfp_init_private_key(CX_CURVE_Ed25519, privateKeyData, 32, &cx_privateKey);
                    cx_ecfp_init_public_key(CX_CURVE_Ed25519, NULL, 0, &cx_publicKey);
                    cx_ecfp_generate_pair(CX_CURVE_Ed25519, &cx_publicKey, &cx_privateKey, 1);
                    for (int i = 0; i < 32; i++) {
                        pubKey[i] = cx_publicKey.W[64 - i];
                    }

                    if ((cx_publicKey.W[32] & 1) != 0) {
                        pubKey[31] |= 0x80;
                    }
                    break;
                }
                case key_sr25519:
                    get_sr25519_pk(privateKeyData, pubKey);
                    break;
                default:
                    return zxerr_invalid_crypto_settings;
            }
        }
        FINALLY {
            MEMZERO(&cx_privateKey, sizeof(cx_privateKey));
            MEMZERO(privateKeyData, 64);
        }
    }
    END_TRY;

    return zxerr_ok;
}

zxerr_t crypto_sign_ed25519(uint8_t *signature, uint16_t signatureMaxlen,
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

    uint8_t privateKeyData[64];
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

                    cx_ecfp_private_key_t cx_privateKey;
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
                                                    signature + 1,
                                                    signatureMaxlen - 1,
                                                    &info);
                    MEMZERO(&cx_privateKey, sizeof(cx_privateKey));

                }
    CATCH_ALL {
        *signatureLen = 0;
        return zxerr_unknown;
    };
    FINALLY {
        MEMZERO(signature + signatureLength + 1, signatureMaxlen - signatureLength - 1);
    }
}
END_TRY;
    return zxerr_ok;
}

zxerr_t crypto_sign(uint8_t *signature, uint16_t signatureMaxlen,
                    const uint8_t *message, uint16_t messageLen,
                    uint16_t *signatureLen) {

    BEGIN_TRY
    {
        TRY
        {
            if (signatureMaxlen < MIN_BUFFER_LENGTH){
                        return zxerr_invalid_crypto_settings;
                    }

                    if (messageLen > 0) {
                        // Hash it
                        uint8_t *messageDigest = signature + 220;
                        cx_blake2b_t *ctx = (cx_blake2b_t *) signature;
                        cx_blake2b_init(ctx, 256);
                        cx_hash(&ctx->header, CX_LAST, message, messageLen, messageDigest, 32);
                        MEMCPY_NV(&N_sr25519_signdata.digest, messageDigest, 32);
                    }
                    uint8_t *privateKeyData = signature;
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

                    uint8_t *pubkey = signature + 64;
                    *signature = PREFIX_SIGNATURE_TYPE_SR25519;
                    get_sr25519_pk(privateKeyData, pubkey);
                    MEMCPY_NV(&N_sr25519_signdata.sk, privateKeyData, 64);
                    MEMCPY_NV(&N_sr25519_signdata.pk, pubkey, 32);
                    sign_sr25519(&N_sr25519_signdata.sk, &N_sr25519_signdata.pk, NULL, 0, &N_sr25519_signdata.digest,32, signature, signature + 32);
                    MEMCPY_NV(&N_sr25519_signdata.signature, signature, 64);
                }
        CATCH_ALL {
            return zxerr_unknown;
        };
        FINALLY {
            MEMZERO(signature + 64 + 1, signatureMaxlen - 64 - 1);
        }
    }
    END_TRY;
    return zxerr_ok;
}

zxerr_t crypto_fillAddress(key_kind_e addressKind, uint8_t *buffer, uint16_t bufferLen, uint16_t *addrResponseLen) {
   if (bufferLen < PK_LEN_ED25519 + SS58_ADDRESS_MAX_LEN) {
            return 0;
   }
    MEMZERO(buffer, bufferLen);
    crypto_extractPublicKey(addressKind, hdPath, buffer, bufferLen);
    zemu_log_stack("pk extracted");
    size_t outLen = crypto_SS58EncodePubkey(buffer + PK_LEN_ED25519,
                                            bufferLen - PK_LEN_ED25519,
                                            PK_ADDRESS_TYPE, buffer);

    *addrResponseLen = PK_LEN_ED25519 + outLen;
    return zxerr_ok;
}
