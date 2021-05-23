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

import Zemu, { DEFAULT_START_OPTIONS } from '@zondax/zemu'
import { newKusamaApp } from '@zondax/ledger-polkadot'
import { APP_SEED } from './common'

// @ts-ignore
import { blake2bFinal, blake2bInit, blake2bUpdate } from 'blakejs'

const addon = require('../../tests_tools/neon/native')

const Resolve = require('path').resolve
const APP_PATH = Resolve('../app/output/app_sr25519.elf')

const defaultOptions = {
  ...DEFAULT_START_OPTIONS,
  logging: true,
  custom: `-s "${APP_SEED}"`,
  X11: false,
}

jest.setTimeout(60000)

describe('SR25519', function () {
  test('get address sr25519', async function () {
    const sim = new Zemu(APP_PATH)
    try {
      await sim.start({ ...defaultOptions })
      const app = newKusamaApp(sim.getTransport())

      const resp = await app.getAddress(0x80000000, 0x80000000, 0x80000000, false, 1)

      console.log(resp)

      expect(resp.return_code).toEqual(0x9000)
      expect(resp.error_message).toEqual('No errors')

      const expected_address = 'Cz4vu6J2NHP977ZYZcMCdjmmLgmddKvXRi5TxecuTgFfKww'
      const expected_pk = '121cc87d316d311fe3e3b9c34b1083a29c55f6ebd214b60f59578b0a37007424'

      expect(resp.address).toEqual(expected_address)
      expect(resp.pubKey).toEqual(expected_pk)
    } finally {
      await sim.close()
    }
  })

  test('show address sr25519', async function () {
    const sim = new Zemu(APP_PATH)
    try {
      await sim.start({ ...defaultOptions, model: 'nanos' })
      const app = newKusamaApp(sim.getTransport())

      const respRequest = app.getAddress(0x80000000, 0x80000000, 0x80000000, true, 1)
      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())

      await sim.compareSnapshotsAndAccept('.', 's-show_address_sr25519', 2)

      const resp = await respRequest
      console.log(resp)

      expect(resp.return_code).toEqual(0x9000)
      expect(resp.error_message).toEqual('No errors')

      const expected_address = 'Cz4vu6J2NHP977ZYZcMCdjmmLgmddKvXRi5TxecuTgFfKww'
      const expected_pk = '121cc87d316d311fe3e3b9c34b1083a29c55f6ebd214b60f59578b0a37007424'

      expect(resp.address).toEqual(expected_address)
      expect(resp.pubKey).toEqual(expected_pk)
    } finally {
      await sim.close()
    }
  })

  test('show address - reject sr25519', async function () {
    const sim = new Zemu(APP_PATH)
    try {
      await sim.start({ ...defaultOptions })
      const app = newKusamaApp(sim.getTransport())

      const respRequest = app.getAddress(0x80000000, 0x80000000, 0x80000000, true, 1)
      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())
      await sim.compareSnapshotsAndAccept('.', 's-show_address_reject_sr25519', 3, 2)

      const resp = await respRequest
      console.log(resp)

      expect(resp.return_code).toEqual(0x6986)
      expect(resp.error_message).toEqual('Transaction rejected')
    } finally {
      await sim.close()
    }
  })

  test('sign basic normal', async function () {
    const sim = new Zemu(APP_PATH)
    try {
      await sim.start({ ...defaultOptions })
      const app = newKusamaApp(sim.getTransport())
      const pathAccount = 0x80000000
      const pathChange = 0x80000000
      const pathIndex = 0x80000000

      const txBlobStr =
        '0400008e730faa8a7827ae61b79ceb78b4e7c1caddf371c740292485a611c35e2bec4500d503046d0f3223000005000000b0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafeb0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafe'

      const txBlob = Buffer.from(txBlobStr, 'hex')

      const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex, false, 1)
      const pubKey = Buffer.from(responseAddr.pubKey, 'hex')

      // do not wait here.. we need to navigate
      const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob, 1)
      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())

      await sim.compareSnapshotsAndAccept('.', 's-sign_basic_normal', 5)

      const signatureResponse = await signatureRequest
      console.log(signatureResponse)

      expect(signatureResponse.return_code).toEqual(0x9000)
      expect(signatureResponse.error_message).toEqual('No errors')

      // Now verify the signature
      let prehash = txBlob
      if (txBlob.length > 256) {
        const context = blake2bInit(32, null)
        blake2bUpdate(context, txBlob)
        prehash = Buffer.from(blake2bFinal(context))
      }
      const signingcontext = Buffer.from([])
      const valid = addon.schnorrkel_verify(pubKey, signingcontext, prehash, signatureResponse.signature.slice(1))
      expect(valid).toEqual(true)
    } finally {
      await sim.close()
    }
  })

  test('sign basic expert', async function () {
    const sim = new Zemu(APP_PATH)
    try {
      await sim.start({ ...defaultOptions })
      const app = newKusamaApp(sim.getTransport())
      const pathAccount = 0x80000000
      const pathChange = 0x80000000
      const pathIndex = 0x80000000

      // Change to expert mode so we can skip fields
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()

      const txBlobStr =
        '0400008e730faa8a7827ae61b79ceb78b4e7c1caddf371c740292485a611c35e2bec4500d503046d0f3223000005000000b0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafeb0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafe'

      const txBlob = Buffer.from(txBlobStr, 'hex')

      const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex, false, 1)
      const pubKey = Buffer.from(responseAddr.pubKey, 'hex')

      // do not wait here.. we need to navigate
      const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob, 1)

      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())

      await sim.compareSnapshotsAndAccept('.', 's-sign_basic_expert', 11)

      const signatureResponse = await signatureRequest
      console.log(signatureResponse)

      expect(signatureResponse.return_code).toEqual(0x9000)
      expect(signatureResponse.error_message).toEqual('No errors')

      // Now verify the signature
      let prehash = txBlob
      if (txBlob.length > 256) {
        const context = blake2bInit(32, null)
        blake2bUpdate(context, txBlob)
        prehash = Buffer.from(blake2bFinal(context))
      }
      const signingcontext = Buffer.from([])
      const valid = addon.schnorrkel_verify(pubKey, signingcontext, prehash, signatureResponse.signature.slice(1))
      expect(valid).toEqual(true)
    } finally {
      await sim.close()
    }
  })

  test('sign basic expert - accept shortcut', async function () {
    const sim = new Zemu(APP_PATH)
    try {
      await sim.start({ ...defaultOptions })
      const app = newKusamaApp(sim.getTransport())
      const pathAccount = 0x80000000
      const pathChange = 0x80000000
      const pathIndex = 0x80000000

      // Change to expert mode so we can skip fields
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()

      const txBlobStr =
        '0400008e730faa8a7827ae61b79ceb78b4e7c1caddf371c740292485a611c35e2bec4500d503046d0f3223000005000000b0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafeb0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafe'

      const txBlob = Buffer.from(txBlobStr, 'hex')

      const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex, false, 1)
      const pubKey = Buffer.from(responseAddr.pubKey, 'hex')

      // do not wait here.. we need to navigate
      const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob, 1)

      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())

      // Shortcut to accept menu
      await sim.clickBoth()

      // Accept tx
      await sim.clickBoth()

      const signatureResponse = await signatureRequest
      console.log(signatureResponse)

      expect(signatureResponse.return_code).toEqual(0x9000)
      expect(signatureResponse.error_message).toEqual('No errors')

      // Now verify the signature
      let prehash = txBlob
      if (txBlob.length > 256) {
        const context = blake2bInit(32, null)
        blake2bUpdate(context, txBlob)
        prehash = Buffer.from(blake2bFinal(context))
      }
      const signingcontext = Buffer.from([])
      const valid = addon.schnorrkel_verify(pubKey, signingcontext, prehash, signatureResponse.signature.slice(1))
      expect(valid).toEqual(true)
    } finally {
      await sim.close()
    }
  })

  test('sign large nomination', async function () {
    const sim = new Zemu(APP_PATH)
    try {
      await sim.start({ ...defaultOptions })
      const app = newKusamaApp(sim.getTransport())
      const pathAccount = 0x80000000
      const pathChange = 0x80000000
      const pathIndex = 0x80000000

      const txBlobStr =
        '0605100074dbeae458762c8257fe23d9f05ad82fa994e4f9557800169f1a9b04b3964d6800e46c28d0b59b08570d9b29d470efb5e9ab90c8adc602fd2ff809076ea28bb63b009ac4cd92a3a9f9de8f0af1b6cf6449590de0adbc48ba9c522461c18fe818a32f00522e26c7c869be5d00c45341b6c148e6e4955a60788bc829cd19c2cdec06f80cd5030003d20296493223000005000000b0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafeb0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafe'

      const txBlob = Buffer.from(txBlobStr, 'hex')

      const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex, false, 1)
      const pubKey = Buffer.from(responseAddr.pubKey, 'hex')

      // do not wait here.. we need to navigate
      const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob, 1)
      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())

      await sim.compareSnapshotsAndAccept('.', 's-sign_large_nomination', 10)

      const signatureResponse = await signatureRequest
      console.log(signatureResponse)

      expect(signatureResponse.return_code).toEqual(0x9000)
      expect(signatureResponse.error_message).toEqual('No errors')

      // Now verify the signature
      let prehash = txBlob
      if (txBlob.length > 256) {
        const context = blake2bInit(32, null)
        blake2bUpdate(context, txBlob)
        prehash = Buffer.from(blake2bFinal(context))
      }
      const signingcontext = Buffer.from([])
      const valid = addon.schnorrkel_verify(pubKey, signingcontext, prehash, signatureResponse.signature.slice(1))
      expect(valid).toEqual(true)
    } finally {
      await sim.close()
    }
  })
})
