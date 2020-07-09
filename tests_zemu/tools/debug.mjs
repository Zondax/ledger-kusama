import Zemu from "@zondax/zemu";
import path from "path";
import newKusamaApp from "@zondax/ledger-polkadot";

const APP_PATH = path.resolve(`./../../app/bin/app.elf`);

const seed = "equip will roof matter pink blind book anxiety banner elbow sun young"
const SIM_OPTIONS = {
    logging: true,
    start_delay: 4000,
    X11: true,
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

function dummyAllowlist() {
    const allowlist_signature = Buffer.from("12340000000000000000000000000000000000000000000000000000000000001234000000000000000000000000000000000000000000000000000000000000", "hex")
    const allowlist_len = Buffer.alloc(4);
    allowlist_len.writeUInt32LE(2);
    const pk1 = Buffer.from("1234000000000000000000000000000000000000000000000000000000000000", "hex")
    const pk2 = Buffer.from("5678000000000000000000000000000000000000000000000000000000000000", "hex")
    return Buffer.concat([allowlist_len, allowlist_signature, pk1, pk2])
}

async function debugScenario(sim, app) {
    const signing_pubkey = Buffer.from("1234000000000000000000000000000000000000000000000000000000000000", "hex")
    let resp = await app.setAllowlistPubKey(signing_pubkey);
    console.log(resp)

    const allowlist = dummyAllowlist();
    console.log(`\n\n------------ Upload allowlist : ${allowlist.length} bytes`)
    resp = await app.uploadAllowlist(allowlist);
    console.log(resp);

    console.log("\n\n------------ Get allowlist hash")
    resp = await app.getAllowlistHash();
    console.log(resp);
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
