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
#include "crypto_scalarmult_ristretto255.h"
#include "crypto_core_ristretto255.h"

#include <iostream>
#include <hexutils.h>

void divide_by_cofactor(uint8_t *key){
    uint8_t low = 0;
    for(int i = 31; i >= 0; i--){
        uint8_t r = key[i] & 0x7;
        key[i] >>=3;
        key[i] += low;
        low = r << 5;
    }
}



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


TEST(SODIUM,crypto_core_basepoint){
    auto str = "e2f2ae0a6abc4e71a884a961c500515f58e30b6aa582dd8db6a65945e08d2d76";
    uint8_t p[32];

    parseHexString(p, sizeof(p), str);

    EXPECT_TRUE(crypto_core_ristretto255_is_valid_point(p));


}

TEST(SODIUM, crypto_core_pkgen) {

    auto pk = "b65abc66a8fdeac1197d03daa6c3791d0c0799a52db6b7127b1cd12d46e34364";
    uint8_t pbytes[32];
    parseHexString(pbytes, sizeof(pbytes), pk);

    EXPECT_TRUE(crypto_core_ristretto255_is_valid_point(pbytes)); //check pubkey is good

    auto sk ="0001020304050607000102030405060700010203040506070001020304050607";
    uint8_t skbytes[32];

    parseHexString(skbytes, sizeof(skbytes), sk);

    divide_by_cofactor(skbytes);

    unsigned char pkrs[crypto_core_ristretto255_BYTES];

    crypto_scalarmult_ristretto255_base(pkrs,skbytes);

    for(int i = 0; i < 32; i++){
        EXPECT_EQ(pkrs[i],pbytes[i]);
    }
}