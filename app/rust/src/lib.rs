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
use merlin::{Transcript, TranscriptRngBuilder, TranscriptRng};
use schnorrkel::context::{SigningContext,SigningTranscript};
use schnorrkel::{PublicKey, SecretKey};
use rand::RngCore;

#[cfg(not(test))]
#[panic_handler]
fn panic(_info: &PanicInfo) -> ! {
    loop {}
}

#[inline(never)]
fn signtranscript_setup(context: &[u8], message: &[u8], pk: &[u8]) -> Transcript {
    c_zemu_log_stack(b"setup\x00".as_ref());
    let mut signtranscript = Transcript::new(b"SigningContext");
    signtranscript.append_message(b"", context);
    signtranscript.append_message(b"sign-bytes", message);
    signtranscript.append_message(b"proto-name", b"Schnorr-sig"); //proto name
    signtranscript.append_message(b"sign:pk", pk); //commitpoint: pk
    signtranscript
}

#[inline(never)]
fn compute_r(x: &[u8; 32], signature: &mut [u8]) {
    c_zemu_log_stack(b"writeR\x00".as_ref());
    let r = libsodium_ristretto_scalarmult_base(x);
    signature[0..32].copy_from_slice(&r);
}

#[inline(never)]
fn mult_with_secret(k: &mut Scalar, sk: &[u8]) {
    let mut skbytes = [0u8; 32];
    skbytes.copy_from_slice(&sk[0..32]);
    let s = Scalar::from_bits(skbytes);
    *k = *k * s;
}

#[inline(never)]
fn add_witness(k: &mut Scalar, x: [u8; 32]) -> [u8; 32] {
    let r = Scalar::from_bits(x);
    *k = *k + r;
    k.to_bytes()
}

#[inline(never)]
fn get_challenge_scalar(tr: &mut Transcript) -> Scalar {
    c_zemu_log_stack(b"challenge\x00".as_ref());
    let mut kbytes = [0u8; 64];
    tr.challenge_bytes(b"sign:c", &mut kbytes);
    Scalar::from_bytes_mod_order_wide(&kbytes)
}

#[inline(never)]
fn sign_phase2_challenge(sk_ristretto_expanded: &[u8], pk: &[u8], context: &[u8], message: &[u8], witness: &[u8;32], signature: &mut [u8]){
    c_zemu_log_stack(b"challenge\x00".as_ref());
    let mut signtranscript = signtranscript_setup(context, message, pk);
    signtranscript.append_message(b"sign:R", &signature[0..32]);

    let mut k = get_challenge_scalar(&mut signtranscript);
    mult_with_secret(&mut k, sk_ristretto_expanded);
    signature[32..].copy_from_slice(&add_witness(&mut k, *witness));
    signature[63] |= 128;


}

#[inline(never)]
fn sign_phase1_witness(sk_ristretto_expanded: &[u8], pk: &[u8], context: &[u8], message: &[u8]) -> [u8;32]{
    c_zemu_log_stack(b"witness\x00".as_ref());
    let mut signtranscript = Transcript::new(b"SigningContext");
    signtranscript.append_message(b"", context);
    signtranscript.append_message(b"sign-bytes", message);
    signtranscript.append_message(b"proto-name", b"Schnorr-sig"); //proto name
    signtranscript.append_message(b"sign:pk", pk);
    let mut x = [0u8; 32];
    signtranscript.append_message(b"nonce-bytes",&sk_ristretto_expanded[32..]);
    {
        let random_bytes = {
            let mut bytes = [0u8; 32];
            Trng.fill_bytes(&mut bytes);
            bytes
        };
        signtranscript.append_message(b"rng", &random_bytes);
    }
    signtranscript.challenge_bytes(b"witness-output",&mut x);
    x
}
//the signing function assumes as input a ristretto secret key, not a ed25519 secret key!
#[no_mangle]
pub extern "C" fn sign_sr25519(
    sk_ristretto_expanded_ptr: *const u8,
    pk_ptr : *const u8,
    context_ptr: *const u8,
    context_len: usize,
    msg_ptr: *const u8,
    msg_len: usize,
    sig_ptr: *mut u8,
) {
    c_zemu_log_stack(b"sign_sr25519\x00".as_ref());

    let sk_ristretto_expanded =
        unsafe { from_raw_parts(sk_ristretto_expanded_ptr as *const u8, 64) };
    let pk =
        unsafe { from_raw_parts(pk_ptr as *const u8, 32) };
    let context = unsafe { from_raw_parts(context_ptr as *const u8, context_len) };
    let message = unsafe { from_raw_parts(msg_ptr as *const u8, msg_len) };
    let signature = unsafe { from_raw_parts_mut(sig_ptr, 64) };

    let x = sign_phase1_witness(sk_ristretto_expanded,pk,context,message);
    compute_r(&x, signature);
    sign_phase2_challenge(sk_ristretto_expanded,pk,context,message,&x,signature);
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
    use schnorrkel::{Keypair, PublicKey, SecretKey, Signature, context::*};

    use curve25519_dalek::scalar::Scalar;

    fn init_logging() {
        let _ = env_logger::builder().is_test(true).try_init();
    }

    #[test]
    fn test_sign_verify() {
        let mut sk_ed25519_expanded = [
            0x00, 0x01, 0x02, 0x03, 04, 0x5, 0x06, 0x07, 0x00, 0x01, 0x02, 0x03, 04, 0x5, 0x06,
            0x07, 0x00, 0x01, 0x02, 0x03, 04, 0x5, 0x06, 0x07, 0x00, 0x01, 0x02, 0x03, 04, 0x5,
            0x06, 0x07, 0x00, 0x01, 0x02, 0x03, 04, 0x5, 0x06, 0x07, 0x00, 0x01, 0x02, 0x03, 04,
            0x5, 0x06, 0x07, 0x00, 0x01, 0x02, 0x03, 04, 0x5, 0x06, 0x07, 0x00, 0x01, 0x02, 0x03,
            04, 0x5, 0x06, 0x07,
        ];

        let pk_expected = "b65abc66a8fdeac1197d03daa6c3791d0c0799a52db6b7127b1cd12d46e34364";

        let secret = SecretKey::from_ed25519_bytes(&sk_ed25519_expanded).unwrap();

        let mut pk = [0u8; 32];

        get_sr25519_pk(sk_ed25519_expanded.as_mut_ptr(), pk.as_mut_ptr());

        assert_eq!(hex::encode(pk), pk_expected);

        let context = b"good";
        let msg = "test message".as_bytes();
        let mut signature = [0u8; 64];

        sign_sr25519(
            secret.to_bytes().as_ptr(),
            pk.as_ptr(),
            context.as_ptr(),
            context.len(),
            msg.as_ptr(),
            msg.len(),
            signature.as_mut_ptr(),
        );

        let keypair: Keypair = Keypair::from(secret);

        let mut sigledger = [0u8;64];
        hex::decode_to_slice("48fdbe5cf3524bdd078ac711565d658a3053d10660749959883c4710f49d9948b2d5f829bea6800897dc6ea0150ca11075cc36b75bfcf3712aafb8e1bd10bf8f",&mut sigledger).expect("dec");

        let self_sig = Signature::from_bytes(&signature).unwrap();
        let self_sig_ledger = Signature::from_bytes(&sigledger).unwrap();

        let vers = signing_context(context);

        assert!(keypair.verify(vers.bytes(msg), &self_sig).is_ok(),
                "Verification of a valid signature failed!");
        assert!(keypair.verify(vers.bytes(msg), &self_sig_ledger).is_ok(),
                "Verification of a valid signature from ledger failed!");

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
