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

#include "gmock/gmock.h"
#include "crypto_core_ristretto255.h"

#include <iostream>
#include <hexutils.h>

TEST(SODIUM, check_compilation) {
    auto v = crypto_core_ristretto255_hashbytes();
    EXPECT_EQ(v, 64);
}

TEST(SODIUM, crypto_core_ristretto255_is_valid_point) {
    /* Non-square x^2 */
    auto badPoint = "26948d35ca62e643e26a83177332e6b6afeb9d08e4268b650f1f5bbd8d81d371";
    uint8_t p[32];

    parseHexString(p, sizeof(p), badPoint);
    EXPECT_FALSE(crypto_core_ristretto255_is_valid_point(p));
}
