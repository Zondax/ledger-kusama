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

use crate::bolos::*;
use core::convert::TryInto;
use core::mem;
use core::panic::PanicInfo;
use core::slice::{from_raw_parts, from_raw_parts_mut};
use curve25519_dalek::scalar::Scalar;
use merlin::Transcript;
use schnorrkel::context::SigningTranscript;
use schnorrkel::{PublicKey, SecretKey};

#[cfg(not(test))]
#[panic_handler]
fn panic(_info: &PanicInfo) -> ! {
    loop {}
}

#[inline(never)]
fn signtranscript_setup(context: &[u8], message: &[u8]) -> Transcript {
    let mut signtranscript = Transcript::new(b"SigningContext");
    signtranscript.append_message(b"", context);
    signtranscript.append_message(b"sign-bytes", message);
    signtranscript.append_message(b"proto-name", b"Schnorr-sig"); //proto name
    signtranscript
}

#[inline(never)]
fn write_R(x: &[u8;32], tr: &mut Transcript, signature: &mut [u8]){
    let R = libsodium_ristretto_scalarmult_base(x);
    tr.append_message(b"sign:R", &R); //R
    signature[0..32].copy_from_slice(&R);
}

#[inline(never)]
fn mult_with_secret(k: &mut Scalar, sk: &[u8]){
    let mut skbytes = [0u8; 32];
    skbytes.copy_from_slice(&sk[0..32]);
    let s = Scalar::from_bits(skbytes);
    *k = *k * s;
}

#[inline(never)]
fn add_witness(k: &mut Scalar, x: [u8;32]) -> [u8;32]{
    let r = Scalar::from_bits(x);
    *k = *k + r;
    k.to_bytes()
}

#[inline(never)]
fn get_challenge_scalar(tr: &mut Transcript) -> Scalar{
    let mut kbytes = [0u8; 64];
    tr.challenge_bytes(b"sign:c", &mut kbytes);
    Scalar::from_bytes_mod_order_wide(&kbytes)
}

//the signing function assumes as input a ristretto key, not a ed25519 key!
#[no_mangle]
pub extern "C" fn sign_sr25519(
    sk_ristretto_expanded_ptr: *const u8,
    context_ptr: *const u8,
    context_len: usize,
    msg_ptr: *const u8,
    msg_len: usize,
    sig_ptr: *mut u8,
) {
    c_zemu_log_stack(b"sign_sr25519\x00".as_ref());

    let sk_ristretto_expanded = unsafe { from_raw_parts(sk_ristretto_expanded_ptr as *const u8, 64) };
    let context = unsafe { from_raw_parts(context_ptr as *const u8, context_len) };
    let message = unsafe { from_raw_parts(msg_ptr as *const u8, msg_len) };
    let signature = unsafe { from_raw_parts_mut(sig_ptr, 64) };

    let mut signtranscript = Transcript::new(b"SigningContext");
    signtranscript.append_message(b"", context);
    signtranscript.append_message(b"sign-bytes", message);
    signtranscript.append_message(b"proto-name", b"Schnorr-sig"); //proto name
    {
        let public = libsodium_ristretto_scalarmult_base(&sk_ristretto_expanded[0..32]);
        signtranscript.append_message(b"sign:pk", &public); //commitpoint: pk
    }

    let x: [u8; 32] = [0xaa; 32]; //fixme

    write_R(&x,&mut signtranscript,signature);

    let mut k = get_challenge_scalar(&mut signtranscript);
    mult_with_secret(&mut k, sk_ristretto_expanded);
    signature[32..].copy_from_slice(&add_witness(&mut k, x));

    signature[63] |= 128;

}

#[no_mangle]
pub extern "C" fn get_sr25519_pk(sk_ed25519_expanded_ptr: *mut u8, pk_sr25519_ptr: *mut u8) {
    c_zemu_log_stack(b"get_sr25519_pk\x00".as_ref());

    let sk_ed25519_expanded = unsafe { from_raw_parts_mut(sk_ed25519_expanded_ptr, 64) };
    let pk_sr25519 = unsafe { from_raw_parts_mut(pk_sr25519_ptr, 32) };

    let secret: SecretKey = SecretKey::from_ed25519_bytes(&sk_ed25519_expanded[..]).unwrap();

    sk_ed25519_expanded.copy_from_slice(&secret.to_bytes());
    c_zemu_log_stack(b"from_ed25519_bytes\x00".as_ref());

    //let public: PublicKey = secret.to_public();
    let public = libsodium_ristretto_scalarmult_base(&sk_ed25519_expanded[0..32]);

    c_zemu_log_stack(b"secret.to_public\x00".as_ref());

    pk_sr25519.copy_from_slice(&public)
}

#[cfg(test)]
mod tests {
    use crate::*;
    use log::{debug, info};
    use schnorrkel::{Keypair, PublicKey, SecretKey, Signature};

    use curve25519_dalek::scalar::Scalar;

    fn init_logging() {
        let _ = env_logger::builder().is_test(true).try_init();
    }

    #[test]
    fn test_sig() {
        let mut sk_ed25519_expanded = [
            0x00, 0x01, 0x02, 0x03, 04, 0x5, 0x06, 0x07, 0x00, 0x01, 0x02, 0x03, 04, 0x5, 0x06,
            0x07, 0x00, 0x01, 0x02, 0x03, 04, 0x5, 0x06, 0x07, 0x00, 0x01, 0x02, 0x03, 04, 0x5,
            0x06, 0x07, 0x00, 0x01, 0x02, 0x03, 04, 0x5, 0x06, 0x07, 0x00, 0x01, 0x02, 0x03, 04,
            0x5, 0x06, 0x07, 0x00, 0x01, 0x02, 0x03, 04, 0x5, 0x06, 0x07, 0x00, 0x01, 0x02, 0x03,
            04, 0x5, 0x06, 0x07,
        ];

        let mut pk = [0u8;32];

        get_sr25519_pk(sk_ed25519_expanded.as_mut_ptr(), pk.as_mut_ptr());

        let context = b"good";

        let msg = "test message".as_bytes();
        let mut signature = [0u8; 64];

        sign_sr25519(
            sk_ed25519_expanded.as_ptr(),
            context.as_ptr(),
            context.len(),
            msg.as_ptr(),
            msg.len(),
            signature.as_mut_ptr(),
        );

        assert_eq!(signature[..], [0u8; 64][..]);
    }

    #[test]
    fn get_public_key_c() {
        init_logging();

        let mut sk_ed25519_expanded = [
            0x00, 0x01, 0x02, 0x03, 04, 0x5, 0x06, 0x07, 0x00, 0x01, 0x02, 0x03, 04, 0x5, 0x06,
            0x07, 0x00, 0x01, 0x02, 0x03, 04, 0x5, 0x06, 0x07, 0x00, 0x01, 0x02, 0x03, 04, 0x5,
            0x06, 0x07, 0x00, 0x01, 0x02, 0x03, 04, 0x5, 0x06, 0x07, 0x00, 0x01, 0x02, 0x03, 04,
            0x5, 0x06, 0x07, 0x00, 0x01, 0x02, 0x03, 04, 0x5, 0x06, 0x07, 0x00, 0x01, 0x02, 0x03,
            04, 0x5, 0x06, 0x07,
        ];
        let pk_expected = "b65abc66a8fdeac1197d03daa6c3791d0c0799a52db6b7127b1cd12d46e34364";

        let mut pk = [0u8; 32];
        get_sr25519_pk(sk_ed25519_expanded.as_mut_ptr(), pk.as_mut_ptr());

        info!("{:?}", hex::encode(pk));
        assert_eq!(hex::encode(pk), pk_expected);
    }
}
