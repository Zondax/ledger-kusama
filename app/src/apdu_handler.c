/*******************************************************************************
*   (c) 2018, 2019 Zondax GmbH
*   (c) 2016 Ledger
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

#include "app_main.h"

#include <string.h>
#include <os_io_seproxyhal.h>
#include <os.h>
#include <ux.h>

#include "view.h"
#include "actions.h"
#include "tx.h"
#include "addr.h"
#include "crypto.h"
#include "coin.h"
#include "zxmacros.h"

#if defined(APP_RESTRICTED)
#include "allowlist.h"
#endif

void extractHDPath(uint32_t rx, uint32_t offset) {
    if ((rx - offset) < sizeof(uint32_t) * HDPATH_LEN_DEFAULT) {
        THROW(APDU_CODE_WRONG_LENGTH);
    }

    MEMCPY(hdPath, G_io_apdu_buffer + offset, sizeof(uint32_t) * HDPATH_LEN_DEFAULT);

    const bool mainnet = hdPath[0] == HDPATH_0_DEFAULT &&
                         hdPath[1] == HDPATH_1_DEFAULT;

    if (!mainnet) {
        THROW(APDU_CODE_DATA_INVALID);
    }

#if defined(APP_RESTRICTED)
    if (hdPath[2] != HDPATH_2_STASH && hdPath[2] != HDPATH_2_VALIDATOR ) {
        THROW(APDU_CODE_DATA_INVALID);
    }
    if (hdPath[3] != HDPATH_3_DEFAULT ) {
        THROW(APDU_CODE_DATA_INVALID);
    }
    if (hdPath[4] < 0x80000000 ) {
        THROW(APDU_CODE_DATA_INVALID);
    }
#endif

}

__Z_INLINE bool process_chunk(volatile uint32_t *tx, uint32_t rx) {
    zemu_log("process_chunk\n");
    const uint8_t payloadType = G_io_apdu_buffer[OFFSET_PAYLOAD_TYPE];
    if (rx < OFFSET_DATA) {
        THROW(APDU_CODE_WRONG_LENGTH);
    }

    uint32_t added;
    switch (payloadType) {
        case 0:
            zemu_log("process_chunk - init\n");
            tx_initialize();
            tx_reset();
            extractHDPath(rx, OFFSET_DATA);
            return false;
        case 1:
            zemu_log("process_chunk - add \n");
            added = tx_append(&(G_io_apdu_buffer[OFFSET_DATA]), rx - OFFSET_DATA);
            if (added != rx - OFFSET_DATA) {
                THROW(APDU_CODE_OUTPUT_BUFFER_TOO_SMALL);
            }
            return false;
        case 2:
            zemu_log("process_chunk - end \n");
            added = tx_append(&(G_io_apdu_buffer[OFFSET_DATA]), rx - OFFSET_DATA);
            if (added != rx - OFFSET_DATA) {
                THROW(APDU_CODE_OUTPUT_BUFFER_TOO_SMALL);
            }
            return true;
    }

    THROW(APDU_CODE_INVALIDP1P2);
}

#if defined(APP_RESTRICTED)
__Z_INLINE bool process_chunk_update(volatile uint32_t *tx, uint32_t rx) {
    const uint8_t payloadType = G_io_apdu_buffer[OFFSET_PAYLOAD_TYPE];

    if (G_io_apdu_buffer[OFFSET_P2] != 0) {
        THROW(APDU_CODE_INVALIDP1P2);
    }

    if (rx < OFFSET_DATA) {
        THROW(APDU_CODE_WRONG_LENGTH);
    }

    if (payloadType > 2) {
        THROW(APDU_CODE_INVALIDP1P2);
    }

    if (payloadType == 0) {
        tx_initialize();
        tx_reset();
        return false;
    }

    uint32_t added = tx_append(&(G_io_apdu_buffer[OFFSET_DATA]), rx - OFFSET_DATA);
    if (added != rx - OFFSET_DATA) {
        THROW(APDU_CODE_OUTPUT_BUFFER_TOO_SMALL);
    }

    return payloadType == 2;
}
#endif

__Z_INLINE void handle_getversion(volatile uint32_t *flags, volatile uint32_t *tx, uint32_t rx) {
    G_io_apdu_buffer[0] = 0;

#if defined(APP_TESTING)
    G_io_apdu_buffer[0] = 0x01;
#endif

#if defined(APP_RESTRICTED)
    G_io_apdu_buffer[0] = 0x02;
#endif

    G_io_apdu_buffer[1] = (LEDGER_MAJOR_VERSION >> 8) & 0xFF;;
    G_io_apdu_buffer[2] = (LEDGER_MAJOR_VERSION >> 0) & 0xFF;;

    G_io_apdu_buffer[3] = (LEDGER_MINOR_VERSION >> 8) & 0xFF;;
    G_io_apdu_buffer[4] = (LEDGER_MINOR_VERSION >> 0) & 0xFF;;

    G_io_apdu_buffer[5] = (LEDGER_PATCH_VERSION >> 8) & 0xFF;;
    G_io_apdu_buffer[6] = (LEDGER_PATCH_VERSION >> 0) & 0xFF;;

    G_io_apdu_buffer[7] = !IS_UX_ALLOWED;

    G_io_apdu_buffer[8] = (TARGET_ID >> 24) & 0xFF;
    G_io_apdu_buffer[9] = (TARGET_ID >> 16) & 0xFF;
    G_io_apdu_buffer[10] = (TARGET_ID >> 8) & 0xFF;
    G_io_apdu_buffer[11] = (TARGET_ID >> 0) & 0xFF;

    *tx += 12;
    THROW(APDU_CODE_OK);
}

__Z_INLINE void handleGetAddr(volatile uint32_t *flags, volatile uint32_t *tx, uint32_t rx) {
    extractHDPath(rx, OFFSET_DATA);

    uint8_t requireConfirmation = G_io_apdu_buffer[OFFSET_P1];

#if SUPPORT_SR25519
    uint8_t addr_type = G_io_apdu_buffer[OFFSET_P2];
    key_kind_e key_type = get_key_type(addr_type);
#else
    key_kind_e key_type = key_ed25519;
#endif
    zxerr_t zxerr = app_fill_address(key_type);
    if(zxerr != zxerr_ok){
        *tx = 0;
        THROW(APDU_CODE_DATA_INVALID);
    }
    if (requireConfirmation) {
        view_review_init(addr_getItem, addr_getNumItems, app_reply_address);
        view_review_show();
        *flags |= IO_ASYNCH_REPLY;
        return;
    }
    *tx = action_addrResponseLen;
    THROW(APDU_CODE_OK);
}

__Z_INLINE void handleSignSr25519(volatile uint32_t *flags, volatile uint32_t *tx, uint32_t rx) {
    zxerr_t err = app_sign_sr25519();
    if(err != zxerr_ok){
        *tx = 0;
        THROW(APDU_CODE_DATA_INVALID);
    }

    CHECK_APP_CANARY()

    const char *error_msg = tx_parse();
    CHECK_APP_CANARY()
    if (error_msg != NULL) {
        int error_msg_length = strlen(error_msg);
        MEMCPY(G_io_apdu_buffer, error_msg, error_msg_length);
        *tx += (error_msg_length);
        THROW(APDU_CODE_DATA_INVALID);
    }

    view_review_init(tx_getItem, tx_getNumItems, app_return_sr25519);
    view_review_show();
    *flags |= IO_ASYNCH_REPLY;
}

__Z_INLINE void handleSignEd25519(volatile uint32_t *flags, volatile uint32_t *tx, uint32_t rx) {
    const char *error_msg = tx_parse();
    CHECK_APP_CANARY()
    if (error_msg != NULL) {
        int error_msg_length = strlen(error_msg);
        MEMCPY(G_io_apdu_buffer, error_msg, error_msg_length);
        *tx += (error_msg_length);
        THROW(APDU_CODE_DATA_INVALID);
    }

    view_review_init(tx_getItem, tx_getNumItems, app_sign_ed25519);
    view_review_show();
    *flags |= IO_ASYNCH_REPLY;
}

__Z_INLINE void handleSign(volatile uint32_t *flags, volatile uint32_t *tx, uint32_t rx) {
    zemu_log("handleSign\n");
    if (!process_chunk(tx, rx)) {
        THROW(APDU_CODE_OK);
    }
#if SUPPORT_SR25519
    uint8_t addr_type = G_io_apdu_buffer[OFFSET_P2];
    key_kind_e key_type = get_key_type(addr_type);
#else
    key_kind_e key_type = key_ed25519;
#endif
    if (key_type == key_ed25519){
        handleSignEd25519(flags, tx, rx);
    }else if (key_type == key_sr25519){
        handleSignSr25519(flags, tx, rx);
    }else{
        *tx = 0;
        THROW(APDU_CODE_DATA_INVALID);
    }
}

#if defined(APP_RESTRICTED)
__Z_INLINE void handleAllowlistGetMasterkey(volatile uint32_t *flags, volatile uint32_t *tx, uint32_t rx) {
    if (!allowlist_pubkey_is_set()) {
        // has not been set yet
        THROW(APDU_CODE_COMMAND_NOT_ALLOWED);
    }

    if (!allowlist_pubkey_get(G_io_apdu_buffer, 32)) {
        THROW(APDU_CODE_EXECUTION_ERROR);
    }

    *tx = 32;
    THROW(APDU_CODE_OK);
}

void app_allowlist_SetPublicKey() {
    if (!allowlist_pubkey_set(G_io_apdu_buffer + OFFSET_DATA, 32)) {
        set_code(G_io_apdu_buffer, 0, APDU_CODE_EXECUTION_ERROR);
        io_exchange(CHANNEL_APDU | IO_RETURN_AFTER_TX, 2);
    }
    zemu_log_stack("allowlist: pubkey updated");

    set_code(G_io_apdu_buffer, 0, APDU_CODE_OK);
    io_exchange(CHANNEL_APDU | IO_RETURN_AFTER_TX, 2);
}

__Z_INLINE void handleAllowlistSetPublicKey(volatile uint32_t *flags, volatile uint32_t *tx, uint32_t rx) {
    if (allowlist_pubkey_is_set()) {
        // Can only be set once
        THROW(APDU_CODE_COMMAND_NOT_ALLOWED);  // 0x6986
    }

    if (rx != OFFSET_DATA + 32) {
        THROW(APDU_CODE_WRONG_LENGTH);  // 0x6700
    }

    zemu_log_stack("allowlist: try update pubkey");

    view_review_init(allowlist_getItem, allowlist_getNumItems, app_allowlist_SetPublicKey);
    view_review_show();
    *flags |= IO_ASYNCH_REPLY;
}

__Z_INLINE void handleAllowlistGetHash(volatile uint32_t *flags, volatile uint32_t *tx, uint32_t rx) {
    if (!allowlist_is_active()) {
        THROW(APDU_CODE_COMMAND_NOT_ALLOWED);
    }

    allowlist_hash(G_io_apdu_buffer);
    *tx = 32;
    THROW(APDU_CODE_OK);
}

void app_allowlist_Upload() {
    zemu_log_stack("allowlist: try update");
    if (!allowlist_upgrade(tx_get_buffer(), tx_get_buffer_length())) {
        set_code(G_io_apdu_buffer, 0, APDU_CODE_EXECUTION_ERROR);
        io_exchange(CHANNEL_APDU | IO_RETURN_AFTER_TX, 2);
    }

    zemu_log_stack("allowlist: updated");
    set_code(G_io_apdu_buffer, 0, APDU_CODE_OK);
    io_exchange(CHANNEL_APDU | IO_RETURN_AFTER_TX, 2);
}

__Z_INLINE void handleAllowlistUpload(volatile uint32_t *flags, volatile uint32_t *tx, uint32_t rx) {
    if (!allowlist_pubkey_is_set()) {
        zemu_log_stack("allowlist: pubkey has not been set");
        THROW(APDU_CODE_COMMAND_NOT_ALLOWED);
    }

    zemu_log_stack("allowlist: update chunk");
    if (!process_chunk_update(tx, rx)) {
        THROW(APDU_CODE_OK);
    }
    CHECK_APP_CANARY()

    if (!allowlist_list_validate(tx_get_buffer(), tx_get_buffer_length())) {
        // conditions to update allowlist are not satisfied
        THROW(APDU_CODE_EXECUTION_ERROR);
    }

    view_review_init(allowlist_getItem, allowlist_getNumItems, app_allowlist_Upload);
    view_review_show();
    *flags |= IO_ASYNCH_REPLY;
}
#endif

#if defined(APP_TESTING)
#include "rslib.h"

#include "crypto_scalarmult_ristretto255.h"
#include "crypto_core_ristretto255.h"
#include "private/ed25519_ref10.h"
#include "utils.h"
#include "cx.h"
#include "rslib.h"
#include "zxmacros.h"


void c_ristretto_scalarmult_base1(uint8_t *scalar, uint8_t *point){
    zemu_log_stack("old test");
    unsigned char pkrs[crypto_core_ristretto255_BYTES];
    crypto_scalarmult_ristretto255_base(pkrs,scalar);
    MEMCPY(point,pkrs,crypto_core_ristretto255_BYTES);
}

static uint8_t const C_ED25519_G[] = {
  //uncompressed
  0x04,
  //x
  0x21, 0x69, 0x36, 0xd3, 0xcd, 0x6e, 0x53, 0xfe, 0xc0, 0xa4, 0xe2, 0x31, 0xfd, 0xd6, 0xdc, 0x5c,
  0x69, 0x2c, 0xc7, 0x60, 0x95, 0x25, 0xa7, 0xb2, 0xc9, 0x56, 0x2d, 0x60, 0x8f, 0x25, 0xd5, 0x1a,
  //y
  0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66,
  0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x58
};

static uint8_t const ED25519_MOD[] = {
        0xed, 0xd3, 0xf5, 0x5c, 0x1a, 0x63, 0x12, 0x58,
        0xd6, 0x9c, 0xf7, 0xa2, 0xde, 0xf9, 0xde, 0x14,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10,
};

#define SWAP_BYTES(x, y, tmp) { \
                   tmp = x;     \
                   x = y;       \
                   y = tmp;\
}

#define SWAP_ENDIAN(x, tmp) { \
                 for (int i = 0; i < 16; i++){ \
                          SWAP_BYTES(*(x + i), *(x + (31-i)), tmp); \
                 }          \
}

int
crypto_test(unsigned char *q,const unsigned char *n)
{
    zemu_log_stack("new test");
    unsigned char *t = q;
    ge25519_p3     Q;
    unsigned int   i;

    for (i = 0; i < 32; ++i) {
        t[i] = n[31-i];
    }
    t[0] &= 127;
    //ge25519_scalarmult_base(&Q, t);
    uint8_t Pxy[65];
    memcpy(Pxy, C_ED25519_G, sizeof(Pxy));
    cx_ecfp_scalar_mult(CX_CURVE_Ed25519, Pxy, sizeof(Pxy), t, 32);
    uint8_t tmp = 0;
    SWAP_ENDIAN(&Pxy[1], tmp);
    SWAP_ENDIAN(&Pxy[1+32], tmp);

    fe25519_frombytes(Q.X, &Pxy[1]);
    fe25519_frombytes(Q.Y, &Pxy[33]);

    fe25519_1(Q.Z);
    fe25519_mul(Q.T, Q.X, Q.Y);

    ristretto255_p3_tobytes(q, &Q);
    if (sodium_is_zero(q, 32)) {
        return -1;
    }
    return 0;
}


unsigned char const C_ED25519_FIELD[32] = {
    // q:  0x7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffed
    0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xed};

unsigned char const C_FIELD_ZERO[32] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

typedef uint8_t fe25519_ff[32];

typedef struct {
    fe25519_ff X;
    fe25519_ff Y;
    fe25519_ff Z;
    fe25519_ff T;
} ge25519_p3_ff;

static inline void
fe25519_add_ff(fe25519_ff h, const fe25519_ff f, const fe25519_ff g)
{
    cx_math_addm(h, f, g, C_ED25519_FIELD, 32);
}

static inline void
fe25519_sub_ff(fe25519_ff h, const fe25519_ff f, const fe25519_ff g)
{
    cx_math_subm(h, f, g, C_ED25519_FIELD, 32);
}

static inline void
fe25519_mul_ff(fe25519_ff h, const fe25519_ff f, const fe25519_ff g)
{
    cx_math_multm(h, f, g, C_ED25519_FIELD, 32);
}

static inline void
fe25519_sq_ff(fe25519_ff h, const fe25519_ff f)
{
    cx_math_multm(h, f, f, C_ED25519_FIELD, 32);
}

static inline void
fe25519_1_ff(fe25519_ff h)
{
    MEMZERO(&h[0], sizeof(fe25519_ff));
    h[31] = 1;
}

static inline int
fe25519_iszero_ff(fe25519_ff h)
{
    return cx_math_is_zero(h,32);
}


//TODO: maybe replace this with cx_math_pow
static void
fe25519_pow22523_ff(fe25519_ff out, const fe25519_ff z)
{
    fe25519_ff t0, t1, t2;
    int     i;

    fe25519_sq_ff(t0, z);
    fe25519_sq_ff(t1, t0);
    fe25519_sq_ff(t1, t1);
    fe25519_mul_ff(t1, z, t1);
    fe25519_mul_ff(t0, t0, t1);
    fe25519_sq_ff(t0, t0);
    fe25519_mul_ff(t0, t1, t0);
    fe25519_sq_ff(t1, t0);
    for (i = 1; i < 5; ++i) {
        fe25519_sq_ff(t1, t1);
    }
    fe25519_mul_ff(t0, t1, t0);
    fe25519_sq_ff(t1, t0);
    for (i = 1; i < 10; ++i) {
        fe25519_sq_ff(t1, t1);
    }
    fe25519_mul_ff(t1, t1, t0);
    fe25519_sq_ff(t2, t1);
    for (i = 1; i < 20; ++i) {
        fe25519_sq_ff(t2, t2);
    }
    fe25519_mul_ff(t1, t2, t1);
    for (i = 1; i < 11; ++i) {
        fe25519_sq_ff(t1, t1);
    }
    fe25519_mul_ff(t0, t1, t0);
    fe25519_sq_ff(t1, t0);
    for (i = 1; i < 50; ++i) {
        fe25519_sq_ff(t1, t1);
    }
    fe25519_mul_ff(t1, t1, t0);
    fe25519_sq_ff(t2, t1);
    for (i = 1; i < 100; ++i) {
        fe25519_sq_ff(t2, t2);
    }
    fe25519_mul_ff(t1, t2, t1);
    for (i = 1; i < 51; ++i) {
        fe25519_sq_ff(t1, t1);
    }
    fe25519_mul_ff(t0, t1, t0);
    fe25519_sq_ff(t0, t0);
    fe25519_sq_ff(t0, t0);
    fe25519_mul_ff(out, t0, z);
}

static inline int
fe25519_isnegative_ff(const fe25519_ff f)
{
    return f[31] & 1;
}

static inline void
fe25519_neg_ff(const fe25519_ff h, const fe25519_ff f)
{
    cx_math_subm(h, C_FIELD_ZERO, f, C_ED25519_FIELD, 32);
}

static inline void
fe25519_copy_ff(const fe25519_ff h, const fe25519_ff f)
{
    MEMCPY(h, f, sizeof(fe25519_ff));
}

//TODO: check this for constant-time
static void
fe25519_cmov_ff(fe25519_ff f, const fe25519_ff g, unsigned int b)
{
    uint8_t mask = (uint8_t) (-(int8_t) b);
    uint8_t h[32];
    uint8_t x[32];
    for(int i = 0; i < 32; i++){
        h[i] = f[i];
        x[i] = h[i] ^ g[i];
        x[i] &= mask;
        f[i] = f[i] ^ x[i];
    }
}

static inline void
fe25519_cneg_ff(fe25519_ff h, const fe25519_ff f, unsigned int b)
{
    fe25519 negf;

    fe25519_neg_ff(negf, f);
    fe25519_copy_ff(h, f);
    fe25519_cmov_ff(h, negf, b);
}

static inline void
fe25519_abs_ff(fe25519_ff h, const fe25519_ff f)
{
    fe25519_cneg_ff(h, f, fe25519_isnegative_ff(f));
}
static const fe25519_ff fe25519_sqrtm1_ff = {
0x2b, 0x83, 0x24, 0x80, 0x4f, 0xc1, 0xdf, 0x0b, 0x2b, 0x4d,
0x00, 0x99, 0x3d, 0xfb, 0xd7, 0xa7, 0x2f, 0x43, 0x18, 0x06,
0xad, 0x2f, 0xe4, 0x78, 0xc4, 0xee, 0x1b, 0x27, 0x4a, 0x0e, 0xa0, 0xb0
};

static const fe25519_ff ed25519_invsqrtamd_ff = {
0x78, 0x6c, 0x89, 0x05, 0xcf, 0xaf, 0xfc, 0xa2, 0x16, 0xc2,
0x7b, 0x91, 0xfe, 0x01, 0xd8, 0x40, 0x9d, 0x2f, 0x16, 0x17,
0x5a, 0x41, 0x72, 0xbe, 0x99, 0xc8, 0xfd, 0xaa, 0x80, 0x5d, 0x40, 0xea
};

static int
ristretto255_sqrt_ratio_m1_ff(fe25519_ff x, const fe25519_ff u, const fe25519_ff v)
{
    fe25519_ff v3;
    fe25519_ff vxx;
    fe25519_ff m_root_check, p_root_check, f_root_check;
    fe25519_ff x_sqrtm1;
    int     has_m_root, has_p_root, has_f_root;

    fe25519_sq_ff(v3, v);
    fe25519_mul_ff(v3, v3, v); /* v3 = v^3 */
    fe25519_sq_ff(x, v3);
    fe25519_mul_ff(x, x, u);
    fe25519_mul_ff(x, x, v); /* x = uv^7 */

    fe25519_pow22523_ff(x, x); /* x = (uv^7)^((q-5)/8) */
    fe25519_mul_ff(x, x, v3);
    fe25519_mul_ff(x, x, u); /* x = uv^3(uv^7)^((q-5)/8) */

    fe25519_sq_ff(vxx, x);
    fe25519_mul_ff(vxx, vxx, v); /* vx^2 */
    fe25519_sub_ff(m_root_check, vxx, u); /* vx^2-u */
    fe25519_add_ff(p_root_check, vxx, u); /* vx^2+u */
    fe25519_mul_ff(f_root_check, u, fe25519_sqrtm1_ff); /* u*sqrt(-1) */
    fe25519_add_ff(f_root_check, vxx, f_root_check); /* vx^2+u*sqrt(-1) */
    has_m_root = fe25519_iszero_ff(m_root_check);
    has_p_root = fe25519_iszero_ff(p_root_check);
    has_f_root = fe25519_iszero_ff(f_root_check);
    fe25519_mul_ff(x_sqrtm1,x, fe25519_sqrtm1_ff);

    fe25519_cmov_ff(x, x_sqrtm1, has_p_root | has_f_root);
    fe25519_abs_ff(x, x);

    return has_m_root | has_p_root;
}

void
ristretto255_p3_tobytes_test(unsigned char *s, const ge25519_p3 *h)
{
    fe25519 den1, den2;
    fe25519 den_inv;
    fe25519 eden;
    fe25519 inv_sqrt;
    fe25519 ix, iy;
    fe25519 one;
    fe25519 s_;
    fe25519 t_z_inv;
    fe25519 u1, u2;
    fe25519 u1_u2u2;
    fe25519 x_, y_;
    fe25519 x_z_inv;
    fe25519 z_inv;
    fe25519 zmy;
    int     rotate;

    fe25519_add(u1, h->Z, h->Y);       /* u1 = Z+Y */
    fe25519_sub(zmy, h->Z, h->Y);      /* zmy = Z-Y */
    fe25519_mul(u1, u1, zmy);          /* u1 = (Z+Y)*(Z-Y) */
    fe25519_mul(u2, h->X, h->Y);       /* u2 = X*Y */

    fe25519_sq(u1_u2u2, u2);           /* u1_u2u2 = u2^2 */
    fe25519_mul(u1_u2u2, u1, u1_u2u2); /* u1_u2u2 = u1*u2^2 */
    fe25519_pow22523_ff(u1_u2u2,u1_u2u2);
    fe25519_1_ff(one);
    ristretto255_sqrt_ratio_m1_ff(inv_sqrt, one, u1_u2u2);

    fe25519_tobytes(s, inv_sqrt);
}


void
ristretto255_p3_tobytes_sdk(unsigned char *s, const ge25519_p3_ff *h)
{
    fe25519_ff den1, den2;
    fe25519_ff den_inv;
    fe25519_ff eden;
    fe25519_ff inv_sqrt;
    fe25519_ff ix, iy;
    fe25519_ff one;
    fe25519_ff s_;
    fe25519_ff t_z_inv;
    fe25519_ff u1, u2;
    fe25519_ff u1_u2u2;
    fe25519_ff x_, y_;
    fe25519_ff x_z_inv;
    fe25519_ff z_inv;
    fe25519_ff zmy;
    int     rotate;

    fe25519_add_ff(u1, h->Z, h->Y);       /* u1 = Z+Y */
    fe25519_sub_ff(zmy, h->Z, h->Y);      /* zmy = Z-Y */
    fe25519_mul_ff(u1, u1, zmy);          /* u1 = (Z+Y)*(Z-Y) */
    fe25519_mul_ff(u2, h->X, h->Y);       /* u2 = X*Y */

    fe25519_sq_ff(u1_u2u2, u2);           /* u1_u2u2 = u2^2 */
    fe25519_mul_ff(u1_u2u2, u1, u1_u2u2); /* u1_u2u2 = u1*u2^2 */

    fe25519_pow22523_ff(u1_u2u2,u1_u2u2);

    fe25519_1_ff(one);
    ristretto255_sqrt_ratio_m1_ff(inv_sqrt, one, u1_u2u2);

    fe25519_mul_ff(den1, inv_sqrt, u1);
    fe25519_mul_ff(den2, inv_sqrt, u2);
    fe25519_mul_ff(z_inv, den1, den2);
    fe25519_mul_ff(z_inv, z_inv, h->T);

    fe25519_mul_ff(ix, h->X, fe25519_sqrtm1_ff);

    fe25519_mul_ff(iy, h->Y, fe25519_sqrtm1_ff);

    fe25519_mul_ff(eden, den1, ed25519_invsqrtamd_ff);

    fe25519_mul_ff(t_z_inv, h->T, z_inv);
    rotate = fe25519_isnegative_ff(t_z_inv);

    fe25519_copy_ff(x_, h->X);
    fe25519_copy_ff(y_, h->Y);
    fe25519_copy_ff(den_inv, den2);

    fe25519_cmov_ff(x_, iy, rotate);
    fe25519_cmov_ff(y_, ix, rotate);
    fe25519_cmov_ff(den_inv, eden, rotate);

    fe25519_mul_ff(x_z_inv, x_, z_inv);
    fe25519_cneg_ff(y_, y_, fe25519_isnegative_ff(x_z_inv));

    fe25519_sub_ff(s_, h->Z, y_);
    fe25519_mul_ff(s_, den_inv, s_);
    fe25519_abs_ff(s_, s_);

    MEMCPY(s, s_, sizeof(fe25519_ff));

}

static const fe25519 fe25519_sqrtm1 = {
    6111485, 4156064, -27798727, 12243468, -25904040, 120897, 20826367, -7060776, 6093568, -1986012
};


void handleTest(volatile uint32_t *flags, volatile uint32_t *tx, uint32_t rx) {
    uint8_t pubkey[32];
    MEMZERO(G_io_apdu_buffer, IO_APDU_BUFFER_SIZE);

//     You can add anything that helps testing here.
    zemu_log_stack("handleTest");

    uint8_t skbytes[64] = {
            0x00, 0x01, 0x02, 0x03, 04, 0x5, 0x06, 0x07, 0x00, 0x01, 0x02, 0x03, 04, 0x5, 0x06,
            0x07, 0x00, 0x01, 0x02, 0x03, 04, 0x5, 0x06, 0x07, 0x00, 0x01, 0x02, 0x03, 04, 0x5,
            0x06, 0x07, 0x00, 0x01, 0x02, 0x03, 04, 0x5, 0x06, 0x07, 0x00, 0x01, 0x02, 0x03, 04,
            0x5, 0x06, 0x07, 0x00, 0x01, 0x02, 0x03, 04, 0x5, 0x06, 0x07, 0x00, 0x01, 0x02, 0x03,
            04, 0x5, 0x06, 0x07};

    unsigned char *n = skbytes;
    unsigned char *t = skbytes;
    unsigned int   i;

    for (i = 0; i < 32; ++i) {
        t[i] = n[31-i];
    }
    t[0] &= 127;
    uint8_t Pxy[65];
    memcpy(Pxy, C_ED25519_G, sizeof(Pxy));
    cx_ecfp_scalar_mult(CX_CURVE_Ed25519, Pxy, sizeof(Pxy), t, 32);

    ge25519_p3_ff Q_ff;
    MEMZERO(&Q_ff, sizeof(ge25519_p3_ff));
    MEMCPY(Q_ff.X, &Pxy[1],32);
    MEMCPY(Q_ff.Y, &Pxy[33],32);
    fe25519_1_ff(Q_ff.Z);

    G_io_apdu_buffer[32] = 0xaa;
    G_io_apdu_buffer[33] = 0xaa;

    uint8_t tmp = 0;
    ristretto255_p3_tobytes_sdk(G_io_apdu_buffer + 34, &Q_ff);
    SWAP_ENDIAN(G_io_apdu_buffer + 34, tmp);
    *tx = 66;
    THROW(APDU_CODE_OK);
}
#endif

void handleApdu(volatile uint32_t *flags, volatile uint32_t *tx, uint32_t rx) {
    uint16_t sw = 0;

    BEGIN_TRY
    {
        TRY
        {
            if (G_io_apdu_buffer[OFFSET_CLA] != CLA) {
                THROW(APDU_CODE_CLA_NOT_SUPPORTED);
            }

            if (rx < APDU_MIN_LENGTH) {
                THROW(APDU_CODE_WRONG_LENGTH);
            }

            switch (G_io_apdu_buffer[OFFSET_INS]) {
                case INS_GET_VERSION: {
                    handle_getversion(flags, tx, rx);
                    break;
                }

                case INS_GET_ADDR: {
                    if( os_global_pin_is_validated() != BOLOS_UX_OK ) {
                        THROW(APDU_CODE_COMMAND_NOT_ALLOWED);
                    }
                    handleGetAddr(flags, tx, rx);
                    break;
                }

                case INS_SIGN: {
                    if( os_global_pin_is_validated() != BOLOS_UX_OK ) {
                        THROW(APDU_CODE_COMMAND_NOT_ALLOWED);
                    }
                    handleSign(flags, tx, rx);
                    break;
                }

#if defined(APP_RESTRICTED)
                    // Allow list commands
                    case INS_ALLOWLIST_GET_PUBKEY: {
                        if( os_global_pin_is_validated() != BOLOS_UX_OK ) {
                            THROW(APDU_CODE_COMMAND_NOT_ALLOWED);
                        }
                        handleAllowlistGetMasterkey(flags, tx, rx);
                        break;
                    }

                    case INS_ALLOWLIST_SET_PUBKEY: {
                        if( os_global_pin_is_validated() != BOLOS_UX_OK ) {
                            THROW(APDU_CODE_COMMAND_NOT_ALLOWED);
                        }
                        handleAllowlistSetPublicKey(flags, tx, rx);
                        break;
                    }

                    case INS_ALLOWLIST_GET_HASH: {
                        if( os_global_pin_is_validated() != BOLOS_UX_OK ) {
                            THROW(APDU_CODE_COMMAND_NOT_ALLOWED);
                        }
                        handleAllowlistGetHash(flags, tx, rx);
                        break;
                    }

                    case INS_ALLOWLIST_UPLOAD: {
                        if( os_global_pin_is_validated() != BOLOS_UX_OK ) {
                            THROW(APDU_CODE_COMMAND_NOT_ALLOWED);
                        }
                        handleAllowlistUpload(flags, tx, rx);
                        break;
                    }
#endif
#if defined(APP_TESTING)
                    case INS_TEST: {
                    handleTest(flags, tx, rx);
                    THROW(APDU_CODE_OK);
                    break;
                }
#endif
                default:
                    THROW(APDU_CODE_INS_NOT_SUPPORTED);
            }
        }
        CATCH(EXCEPTION_IO_RESET)
        {
            THROW(EXCEPTION_IO_RESET);
        }
        CATCH_OTHER(e)
        {
            switch (e & 0xF000) {
                case 0x6000:
                case APDU_CODE_OK:
                    sw = e;
                    break;
                default:
                    sw = 0x6800 | (e & 0x7FF);
                    break;
            }
            G_io_apdu_buffer[*tx] = sw >> 8;
            G_io_apdu_buffer[*tx + 1] = sw;
            *tx += 2;
        }
        FINALLY
        {
        }
    }
    END_TRY;
}
