import Zemu from "@zondax/zemu";
import {expect} from "jest";
import {blake2bFinal, blake2bInit, blake2bUpdate} from "blakejs";
import ed25519 from "ed25519-supercop";

export function compareSnapshots(snapshotPrefixTmp, snapshotPrefixGolden, snapshotCount) {
    for (let i = 0; i < snapshotCount; i++) {
        const img1 = Zemu.LoadPng2RGB(`${snapshotPrefixTmp}${i}.png`);
        const img2 = Zemu.LoadPng2RGB(`${snapshotPrefixGolden}${i}.png`);
        expect(img1).toEqual(img2);
    }
}

export const TESTING_ALLOWLIST_SEED = "0000000000000000000000000000000000000000000000000000000000000000"

export function dummyAllowlist() {
    const allowlist_len = Buffer.alloc(4);
    allowlist_len.writeUInt32LE(2);
    const addr1 = Buffer.alloc(64).fill(0) // .from("1234000000000000000000000000000000000000000000000000000000000000", "hex")
    const addr2 = Buffer.alloc(64).fill(0); // .from("5678000000000000000000000000000000000000000000000000000000000000", "hex")
    addr1.write("HFfvSuhgKycuYVk5YnxdDTmpDnjWsnT76nks8fryfSLaD96")
    addr2.write("testtesttesttesttesttesttesttesttesttesttesttes")

    // calculate digest
    const context = blake2bInit(32, null);
    blake2bUpdate(context, allowlist_len);
    blake2bUpdate(context, addr1);
    blake2bUpdate(context, addr2);
    const digest = Buffer.from(blake2bFinal(context));
    console.log(`-------------------- ${digest.toString("hex")}`)

    // sign
    const keypair = ed25519.createKeyPair(TESTING_ALLOWLIST_SEED)
    console.log(`PK : ${keypair.publicKey.toString("hex")}`)
    console.log(`SK : ${keypair.secretKey.toString("hex")}`)

    const allowlist_signature = ed25519.sign(digest, keypair.publicKey, keypair.secretKey)
    console.log(`SIG: ${allowlist_signature.toString("hex")}`)

    return Buffer.concat([allowlist_len, allowlist_signature, addr1, addr2])
}
