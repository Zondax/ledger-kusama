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

import jest, {expect, test} from "jest";
import Zemu from "@zondax/zemu";
import {newKusamaApp} from "@zondax/ledger-polkadot";
import ed25519 from "ed25519-supercop";
import {dummyAllowlist, TESTING_ALLOWLIST_SEED} from "./common";

const Resolve = require("path").resolve;
const APP_PATH = Resolve("../app/bin/app_ledgeracio.elf");

const APP_SEED = "equip will roof matter pink blind book anxiety banner elbow sun young"
let enableX11 = null;

const simOptions = {
    logging: true,
    start_delay: 3000,
    custom: `-s "${APP_SEED}"`,
    X11: enableX11 !== null ? enableX11 : !!process.env["$DISPLAY"]
};

jest.setTimeout(30000)

describe('Ledgeracio', function () {
    test('can start and stop container', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start(simOptions);
        } finally {
            await sim.close();
        }
    });

    test('get app version', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start(simOptions);
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
            await sim.start(simOptions);
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
            await sim.start(simOptions);
            const app = newKusamaApp(sim.getTransport());

            const pk = Buffer.from("1234000000000000000000000000000000000000000000000000000000000000", "hex")

            let req = app.setAllowlistPubKey(pk);
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());
            await sim.clickRight();
            await sim.clickRight();
            await sim.clickBoth();
            let resp = await req;
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
            await sim.start(simOptions);
            const app = newKusamaApp(sim.getTransport());
            const resp = await app.getAllowlistHash();

            console.log(resp);

            expect(resp.return_code).toEqual(0x6986);
            expect(resp.error_message).toEqual("Transaction rejected");
        } finally {
            await sim.close();
        }
    });

    test('create signed allowlist', async function () {
        const allowList = dummyAllowlist(0)
        console.log(allowList)
        expect(allowList.length).toEqual(4 + 4 + 64 * 3)
    });

    test('upload allowlist | no pubkey', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start(simOptions);
            const app = newKusamaApp(sim.getTransport());

            console.log("\n\n------------ Upload allowlist")
            const allowlist = dummyAllowlist(0);
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
            await sim.start(simOptions);
            const app = newKusamaApp(sim.getTransport());

            console.log("\n\n------------ Set pubkey")
            const keypair = ed25519.createKeyPair(TESTING_ALLOWLIST_SEED)
            let req = app.setAllowlistPubKey(keypair.publicKey);
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());
            await sim.clickRight();
            await sim.clickRight();
            await sim.clickBoth();
            let resp = await req;
            expect(resp.return_code).toEqual(0x9000);
            expect(resp.error_message).toEqual("No errors");

            let allowlist = dummyAllowlist(10);
            console.log(`\n\n------------ Upload allowlist : ${allowlist.length} bytes`)
            req = app.uploadAllowlist(allowlist);
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());
            await sim.clickRight();
            await sim.clickRight();
            await sim.clickBoth();
            resp = await req;
            console.log(resp);

            expect(resp.return_code).toEqual(0x9000);
            expect(resp.error_message).toEqual("No errors");

            console.log("\n\n------------ Get allowlist hash")
            resp = await app.getAllowlistHash();
            console.log(resp);
            expect(resp.return_code).toEqual(0x9000);
            expect(resp.error_message).toEqual("No errors");

            console.log(`\n\n------------ Upload allowlist : Again`)
            resp = await app.uploadAllowlist(allowlist);
            console.log(resp);
            expect(resp.return_code).toEqual(0x6400);
            expect(resp.error_message).toEqual("Execution Error");

            console.log(`\n\n------------ Upload allowlist : Again but change nonce`)
            allowlist = dummyAllowlist(11);
            req = app.uploadAllowlist(allowlist);
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());
            await sim.clickRight();
            await sim.clickRight();
            await sim.clickBoth();
            resp = await req;
            console.log(resp);
            expect(resp.return_code).toEqual(0x9000);
            expect(resp.error_message).toEqual("No errors");

            // Change to expert mode so we can skip fields
            await sim.clickRight();
            await sim.clickBoth();
            await sim.clickLeft();

            // Try to sign a nomination included in the allowlist
            let nominate_tx1 = "060508bbd3793ebbb4830ad98e1c97ba3674f793e124ce64e5d9cdabd7813b574c78f45c03385b6f32c9a5861545a20a4de1b2c88a0f206d38e5a0b77386516cfa0a43d5038d2403d2029649e707000003000000b0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafeb0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafe";
            const txBlob1 = Buffer.from(nominate_tx1, "hex");
            const signatureResponse1 = app.sign(0x80000000, 0x80000000, 0x80000000, txBlob1);
            await Zemu.sleep(1000);
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());
            await sim.clickBoth();
            await sim.clickBoth();
            let signature1 = await signatureResponse1;
            expect(signature1.return_code).toEqual(0x9000);
            expect(signature1.error_message).toEqual("No errors");
            console.log(signature1)

            await Zemu.sleep(3000);
            console.log("Try an address that is not allowed")

            // Now try a nominations that is not allowed
            // HDQUMvHtV4kPXkrgp7PoDVGCLEc9qSdwwLWJLzFnsGrKAiM
            const nominate_tx2 = "060504cd39b168d05b1b00cc4cc572c57c57ecad0b6da84b31a28c745c9283184b23c1d503ae11030033158139ae28a3dfaac5fe1560a5e9e05ce707000003000000b0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafeb0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafe";
            const txBlob2 = Buffer.from(nominate_tx2, "hex");
            const signature2 = await app.sign(0x80000000, 0x80000000, 0x80000000, txBlob2);
            await Zemu.sleep(1000);
            await sim.clickBoth();
            await sim.clickBoth();
            expect(signature2.return_code).toEqual(0x6984);
            expect(signature2.error_message).toEqual("Not allowed");

        } finally {
            await sim.close();
        }
    });
});
