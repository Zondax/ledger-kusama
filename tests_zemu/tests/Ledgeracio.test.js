/** ******************************************************************************
 *  (c) 2020 Zondax GmbH
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
 ******************************************************************************* */

import jest, {expect} from "jest";
import Zemu from "@zondax/zemu";
import {blake2bInit, blake2bUpdate, blake2bFinal} from "blakejs";
import {newKusamaApp} from "@zondax/ledger-polkadot";
import ed25519 from "ed25519-supercop";

const Resolve = require("path").resolve;
const APP_PATH = Resolve("../app/bin/app_ledgeracio.elf");

const APP_SEED = "equip will roof matter pink blind book anxiety banner elbow sun young"
const sim_options = {
    logging: true,
    start_delay: 3000,
    custom: `-s "${APP_SEED}"`
//    ,X11: true
};

jest.setTimeout(30000)

function compareSnapshots(snapshotPrefixTmp, snapshotPrefixGolden, snapshotCount) {
    for (let i = 0; i < snapshotCount; i++) {
        const img1 = Zemu.LoadPng2RGB(`${snapshotPrefixTmp}${i}.png`);
        const img2 = Zemu.LoadPng2RGB(`${snapshotPrefixGolden}${i}.png`);
        expect(img1).toEqual(img2);
    }
}

describe('Basic checks', function () {
    test('can start and stop container', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start(sim_options);
        } finally {
            await sim.close();
        }
    });

    test('get app version', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start(sim_options);
            const app = newKusamaApp(sim.getTransport());
            const resp = await app.getVersion();

            console.log(resp);

            expect(resp.return_code).toEqual(0x9000);
            expect(resp.error_message).toEqual("No errors");
            expect(resp).toHaveProperty("test_mode");
            expect(resp).toHaveProperty("major");
            expect(resp).toHaveProperty("minor");
            expect(resp).toHaveProperty("patch");
        } finally {
            await sim.close();
        }
    });

    test('get allowlist pubkey | unset', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start(sim_options);
            const app = newKusamaApp(sim.getTransport());
            const resp = await app.getAllowlistPubKey();

            console.log(resp);

            expect(resp.return_code).toEqual(0x6986);
            expect(resp.error_message).toEqual("Transaction rejected");
        } finally {
            await sim.close();
        }
    });

    test('set allowlist pubkey', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start(sim_options);
            const app = newKusamaApp(sim.getTransport());

            const pk = Buffer.from("1234000000000000000000000000000000000000000000000000000000000000", "hex")

            let resp = await app.setAllowlistPubKey(pk);
            expect(resp.return_code).toEqual(0x9000);
            expect(resp.error_message).toEqual("No errors");

            // Try setting again
            resp = await app.setAllowlistPubKey(pk);
            expect(resp.return_code).toEqual(0x6986);
            expect(resp.error_message).toEqual("Transaction rejected");

            resp = await app.getAllowlistPubKey();
            console.log(resp);
            expect(resp.return_code).toEqual(0x9000);
            expect(resp.error_message).toEqual("No errors");

            expect(resp.pubkey).toEqual(pk);

        } finally {
            await sim.close();
        }
    });

    test('get allowlist hash | not set yet', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start(sim_options);
            const app = newKusamaApp(sim.getTransport());
            const resp = await app.getAllowlistHash();

            console.log(resp);

            expect(resp.return_code).toEqual(0x6986);
            expect(resp.error_message).toEqual("Transaction rejected");
        } finally {
            await sim.close();
        }
    });

    const TESTING_ALLOWLIST_SEED="0000000000000000000000000000000000000000000000000000000000000000"

    function dummyAllowlist() {
        const allowlist_len = Buffer.alloc(4);
        allowlist_len.writeUInt32LE(2);
        const pk1 = Buffer.from("1234000000000000000000000000000000000000000000000000000000000000", "hex")
        const pk2 = Buffer.from("5678000000000000000000000000000000000000000000000000000000000000", "hex")

        // calculate digest
        const context = blake2bInit(32, null);
        blake2bUpdate(context, allowlist_len);
        blake2bUpdate(context, pk1);
        blake2bUpdate(context, pk2);
        const digest = Buffer.from(blake2bFinal(context));

        // sign
        const keypair = ed25519.createKeyPair(TESTING_ALLOWLIST_SEED)
        console.log(keypair)

        const allowlist_signature = ed25519.sign(digest, keypair.publicKey, keypair.secretKey)
        console.log(allowlist_signature.length)
        console.log(allowlist_signature)

        return Buffer.concat([allowlist_len, allowlist_signature, pk1, pk2])
    }

    test('create signed allowlist', async function () {
        const keypair = ed25519.createKeyPair(TESTING_ALLOWLIST_SEED)
        const allowList = dummyAllowlist()

        console.log(allowList)
        expect(allowList.length).toEqual(132)
    });

    test('upload allowlist | no pubkey', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start(sim_options);
            const app = newKusamaApp(sim.getTransport());

            console.log("\n\n------------ Upload allowlist")
            const allowlist = dummyAllowlist();
            const resp = await app.uploadAllowlist(allowlist);
            console.log(resp);

            expect(resp.return_code).toEqual(0x6986);
            expect(resp.error_message).toEqual("Transaction rejected");
        } finally {
            await sim.close();
        }
    });

    test('upload allowlist | with pubkey set before', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start(sim_options);
            const app = newKusamaApp(sim.getTransport());

            console.log("\n\n------------ Set pubkey")
            const signing_pubkey = Buffer.from("1234000000000000000000000000000000000000000000000000000000000000", "hex")
            let resp = await app.setAllowlistPubKey(signing_pubkey);
            expect(resp.return_code).toEqual(0x9000);
            expect(resp.error_message).toEqual("No errors");

            const allowlist = dummyAllowlist();

            console.log(`\n\n------------ Upload allowlist : ${allowlist.length} bytes`)
            resp = await app.uploadAllowlist(allowlist);
            console.log(resp);

            expect(resp.return_code).toEqual(0x9000);
            expect(resp.error_message).toEqual("No errors");

            console.log("\n\n------------ Get allowlist hash")
            resp = await app.getAllowlistHash();
            console.log(resp);
            // expect(resp.return_code).toEqual(0x9000);
            // expect(resp.error_message).toEqual("No errors");
        } finally {
            await sim.close();
        }
    });

});
