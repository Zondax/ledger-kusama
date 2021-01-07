/*******************************************************************************
*   (c) 2020 Zondax GmbH
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
#![no_std]
#![no_builtins]
#![allow(dead_code, unused_imports)]

mod bolos;

#[cfg(test)]
#[macro_use]
extern crate hex_literal;
extern crate core;

fn debug(_msg: &str) {}

use crate::bolos::c_zemu_log_stack;
use core::convert::TryInto;
use core::mem;
use core::panic::PanicInfo;
use core::slice::{from_raw_parts, from_raw_parts_mut};
use schnorrkel::{PublicKey, SecretKey};

#[cfg(not(test))]
#[panic_handler]
fn panic(_info: &PanicInfo) -> ! {
    loop {}
}

#[no_mangle]
pub extern "C" fn get_sr25519_pk(sk_ed25519_expanded_ptr: *const u8, pk_sr25519_ptr: *mut u8) {
    c_zemu_log_stack(b"get_sr25519_pk\x00".as_ref());

    let sk_ed25519_expanded = unsafe { from_raw_parts(sk_ed25519_expanded_ptr as *const u8, 64) };
    let pk_sr25519 = unsafe { from_raw_parts_mut(pk_sr25519_ptr, 32) };

    let secret: SecretKey = SecretKey::from_ed25519_bytes(&sk_ed25519_expanded[..]).unwrap();
    c_zemu_log_stack(b"from_ed25519_bytes\x00".as_ref());

    let public: PublicKey = secret.to_public();
    c_zemu_log_stack(b"secret.to_public\x00".as_ref());

    pk_sr25519.copy_from_slice(&public.to_bytes())
}

#[cfg(test)]
mod tests {
    use crate::*;
    use log::{debug, info};
    use schnorrkel::{Keypair, PublicKey, SecretKey, Signature};

    fn init_logging() {
        let _ = env_logger::builder().is_test(true).try_init();
    }

    #[test]
    fn get_public_key_c() {
        init_logging();

        let sk_ed25519_expanded = [
            0x00, 0x01, 0x02, 0x03, 04, 0x5, 0x06, 0x07, 0x00, 0x01, 0x02, 0x03, 04, 0x5, 0x06,
            0x07, 0x00, 0x01, 0x02, 0x03, 04, 0x5, 0x06, 0x07, 0x00, 0x01, 0x02, 0x03, 04, 0x5,
            0x06, 0x07, 0x00, 0x01, 0x02, 0x03, 04, 0x5, 0x06, 0x07, 0x00, 0x01, 0x02, 0x03, 04,
            0x5, 0x06, 0x07, 0x00, 0x01, 0x02, 0x03, 04, 0x5, 0x06, 0x07, 0x00, 0x01, 0x02, 0x03,
            04, 0x5, 0x06, 0x07,
        ];
        let pk_expected = "b65abc66a8fdeac1197d03daa6c3791d0c0799a52db6b7127b1cd12d46e34364";

        let mut pk = [0u8; 32];
        get_sr25519_pk(sk_ed25519_expanded.as_ptr(), pk.as_mut_ptr());

        info!("{:?}", hex::encode(pk));
        assert_eq!(hex::encode(pk), pk_expected);
    }
}
