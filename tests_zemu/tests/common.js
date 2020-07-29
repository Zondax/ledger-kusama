import {blake2bFinal, blake2bInit, blake2bUpdate} from "blakejs";
import ed25519 from "ed25519-supercop";

export const TESTING_ALLOWLIST_SEED = "0000000000000000000000000000000000000000000000000000000000000000"

export function dummyAllowlist() {
    const addresses = [
        "CyNP3N6Xrg7qMVLBX3bqJry9SENkEnwzYoHCv8E7QcJr4z8",
        "J7wUqKjcKUu1UbiSR5VR9eB2rMmNpQyBNePAvcNhyXxjoU2",
    ]

    // Prepare len field
    const allowlist_len = Buffer.alloc(4);
    allowlist_len.writeUInt32LE(addresses.length);

    // Prepare items field
    const addressBuffer = Buffer.alloc(64 * addresses.length, 0);
    for (let i = 0; i < addresses.length; i++) {
        const tmp = Buffer.from(addresses[i])
        tmp.copy(addressBuffer, i * 64)
    }

    // calculate digest
    const context = blake2bInit(32, null);
    blake2bUpdate(context, allowlist_len);
    blake2bUpdate(context, addressBuffer);
    const digest = Buffer.from(blake2bFinal(context));
    console.log(`-------------------- ${digest.toString("hex")}`)

    // sign
    const keypair = ed25519.createKeyPair(TESTING_ALLOWLIST_SEED)
    console.log(`PK : ${keypair.publicKey.toString("hex")}`)
    console.log(`SK : ${keypair.secretKey.toString("hex")}`)

    const allowlist_signature = ed25519.sign(digest, keypair.publicKey, keypair.secretKey)
    console.log(`SIG: ${allowlist_signature.toString("hex")}`)

    return Buffer.concat([allowlist_len, allowlist_signature, addressBuffer])
}
