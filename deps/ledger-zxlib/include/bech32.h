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

#ifdef __cplusplus
extern "C" {
#endif

#include "zxerror.h"

#define MAX_INPUT_SIZE 64

// the following function encodes directly from bytes
// it will internally convert from 8 to 5 bits and return a
// zero-terminated string in output

zxerr_t bech32EncodeFromBytes(char *out,
                              size_t out_len,
                              const char *hrp,
                              const uint8_t *in,
                              size_t in_len,
                              uint8_t pad);

#ifdef __cplusplus
}
#endif
