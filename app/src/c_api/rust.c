#include <inttypes.h>
#include "os.h"
#include "cx.h"
#include "ristretto.h"
#include "zxmacros.h"

void c_ristretto_scalarmult_base(uint8_t *scalar, uint8_t *point){
    unsigned char pkrs[RISTRETTO_BYTES];
    crypto_scalarmult_ristretto255_base_sdk(pkrs,scalar);
    MEMCPY(point,pkrs,RISTRETTO_BYTES);
}
