#pragma once

#include <stdint.h>

void get_sr25519_pk(uint8_t *sk_ed25519_expanded, uint8_t *pkd);

void sign_sr25519(const uint8_t *sk_ed25519_expanded, const uint8_t *pk, const uint8_t *context_ptr, uint32_t context_len, const uint8_t *msg_ptr, uint32_t msg_len, uint8_t *sig_ptr, uint8_t *buffer);