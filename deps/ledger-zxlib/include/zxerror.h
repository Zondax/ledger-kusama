/*******************************************************************************
*   (c) 2018 Zondax GmbH
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

#define CHECK_ZXERR(CALL) { \
    zxerr_t err = CALL;  \
    if (err!=zxerr_ok) return err;}

typedef enum {
    zxerr_ok,
    zxerr_no_data,
    zxerr_buffer_too_small,
    zxerr_out_of_bounds,
    zxerr_encoding_failed,
    zxerr_unknown
} zxerr_t;

#ifdef __cplusplus
}
#endif
