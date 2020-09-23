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
//! Rust interfaces to Ledger SDK APIs.

#[cfg(test)]
use curve25519_dalek::constants::RISTRETTO_BASEPOINT_POINT;
use curve25519_dalek::scalar::Scalar;

extern "C" {
    fn zemu_log_stack(buffer: *const u8);
    fn check_app_canary();
    fn c_ristretto_scalarmult_base(scalar: *const u8, result: *mut u8);
}

#[cfg(not(test))]
pub fn c_zemu_log_stack(s: &[u8]) {
    unsafe { zemu_log_stack(s.as_ptr()) }
}
#[cfg(test)]
pub fn c_zemu_log_stack(s: &[u8]) {}

pub fn c_check_app_canary() {
    unsafe { check_app_canary() }
}

#[cfg(not(test))]
pub fn libsodium_ristretto_scalarmult_base(scalar: &[u8]) -> [u8; 32] {
    c_zemu_log_stack(b"scalarmult\x00".as_ref());
    let mut result = [0u8; 32];
    unsafe {
        c_ristretto_scalarmult_base(scalar.as_ptr(), result.as_mut_ptr());
    }
    result
}

#[cfg(test)]
pub fn libsodium_ristretto_scalarmult_base(scalar: &[u8]) -> [u8; 32] {
    let mut scalarbytes = [0u8; 32];
    scalarbytes.copy_from_slice(&scalar);
    let x = Scalar::from_bits(scalarbytes);
    let pubkey = x * RISTRETTO_BASEPOINT_POINT;
    pubkey.compress().to_bytes()
}
