#include <inttypes.h>
#include "os.h"
#include "cx.h"
#include "crypto_scalarmult_ristretto255.h"
#include "crypto_core_ristretto255.h"

void c_ristretto_scalarmult_base(uint8_t *scalar, uint8_t *point){
    unsigned char pkrs[crypto_core_ristretto255_BYTES];
    crypto_scalarmult_ristretto255_base(pkrs,scalar);
    memcpy(point,pkrs,crypto_core_ristretto255_BYTES);
}
