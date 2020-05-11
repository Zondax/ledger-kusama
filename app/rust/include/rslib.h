#pragma once

#include <stdint.h>

void get_sr25519_pk(const uint8_t *sk_ed25519_expanded, uint8_t *pkd);
