import Zemu from "@zondax/zemu";
import path from "path";
import newKusamaApp from "@zondax/ledger-polkadot";
const APP_PATH = path.resolve(`./../../app/bin/app.elf`);
import pkg from 'blakejs';
const {blake2bInit, blake2bUpdate, blake2bFinal} = pkg;

import ed25519 from "ed25519-supercop";

const seed = "equip will roof matter pink blind book anxiety banner elbow sun young"
const SIM_OPTIONS = {
    logging: true,
    start_delay: 4000,
//    X11: true,
    custom: `-s "${seed}" --color LAGOON_BLUE`
};

async function beforeStart() {
    process.on("SIGINT", () => {
        Zemu.default.stopAllEmuContainers(function () {
            process.exit();
        });
    });
    await Zemu.default.checkAndPullImage();
}

async function beforeEnd() {
    await Zemu.default.stopAllEmuContainers();
}

const TESTING_ALLOWLIST_SEED = "0000000000000000000000000000000000000000000000000000000000000000"

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
    console.log(`-------------------- ${digest.toString("hex")}`)

    // sign
    const keypair = ed25519.createKeyPair(TESTING_ALLOWLIST_SEED)
    console.log(`PK : ${keypair.publicKey.toString("hex")}`)
    console.log(`SK : ${keypair.secretKey.toString("hex")}`)

    const allowlist_signature = ed25519.sign(digest, keypair.publicKey, keypair.secretKey)
    console.log(`SIG: ${allowlist_signature.toString("hex")}`)

    return Buffer.concat([allowlist_len, allowlist_signature, pk1, pk2])
}

async function debugScenario(sim, app) {
    const keypair = ed25519.createKeyPair(TESTING_ALLOWLIST_SEED)
    let resp = await app.setAllowlistPubKey(keypair.publicKey);
    console.log(resp)

    const allowlist = dummyAllowlist();
    console.log(`\n\n------------ Upload allowlist : ${allowlist.length} bytes`)
    resp = await app.uploadAllowlist(allowlist);
    console.log(resp);

    console.log("\n\n------------ Get allowlist hash")
    resp = await app.getAllowlistHash();
    console.log(resp.hash.toString("hex"));
}

async function main() {
    await beforeStart();

    if (process.argv.length > 2 && process.argv[2] === "debug") {
        SIM_OPTIONS["custom"] = SIM_OPTIONS["custom"] + " --debug";
    }

    const sim = new Zemu.default(APP_PATH);

    try {
        await sim.start(SIM_OPTIONS);
        const app = newKusamaApp.newKusamaApp(sim.getTransport());

        ////////////
        /// TIP you can use zemu commands here to take the app to the point where you trigger a breakpoint

        await debugScenario(sim, app);

        /// TIP

    } finally {
        await sim.close();
        await beforeEnd();
    }
}

(async () => {
    await main();
})();
