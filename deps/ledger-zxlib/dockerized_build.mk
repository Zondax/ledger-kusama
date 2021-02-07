#*******************************************************************************
#*   (c) 2019-2021 Zondax GmbH
#*
#*  Licensed under the Apache License, Version 2.0 (the "License");
#*  you may not use this file except in compliance with the License.
#*  You may obtain a copy of the License at
#*
#*      http://www.apache.org/licenses/LICENSE-2.0
#*
#*  Unless required by applicable law or agreed to in writing, software
#*  distributed under the License is distributed on an "AS IS" BASIS,
#*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#*  See the License for the specific language governing permissions and
#*  limitations under the License.
#********************************************************************************

.PHONY: all deps build clean load delete check_python show_info_recovery_mode

TESTS_ZEMU_DIR?=$(CURDIR)/tests_zemu
EXAMPLE_VUE_DIR?=$(CURDIR)/example_vue
TESTS_JS_PACKAGE?=
TESTS_JS_DIR?=

LEDGER_SRC=$(CURDIR)/app
DOCKER_APP_SRC=/project
DOCKER_APP_BIN=$(DOCKER_APP_SRC)/app/bin/app.elf

DOCKER_BOLOS_SDKS=/project/deps/nanos-secure-sdk
DOCKER_BOLOS_SDKX=/project/deps/nanox-secure-sdk

# Note: This is not an SSH key, and being public represents no risk
SCP_PUBKEY=049bc79d139c70c83a4b19e8922e5ee3e0080bb14a2e8b0752aa42cda90a1463f689b0fa68c1c0246845c2074787b649d0d8a6c0b97d4607065eee3057bdf16b83
SCP_PRIVKEY=ff701d781f43ce106f72dc26a46b6a83e053b5d07bb3d4ceab79c91ca822a66b

INTERACTIVE:=$(shell [ -t 0 ] && echo 1)
USERID:=$(shell id -u)
$(info USERID                : $(USERID))
$(info TESTS_ZEMU_DIR        : $(TESTS_ZEMU_DIR))
$(info EXAMPLE_VUE_DIR       : $(EXAMPLE_VUE_DIR))
$(info TESTS_JS_DIR          : $(TESTS_JS_DIR))
$(info TESTS_JS_PACKAGE      : $(TESTS_JS_PACKAGE))

DOCKER_IMAGE=zondax/builder-bolos@sha256:0e0097c01ef3c6c964fea8d8b6e3a584f4ff209a04ec68b6b2b4aeab64379c23

ifdef INTERACTIVE
INTERACTIVE_SETTING:="-i"
TTY_SETTING:="-t"
else
INTERACTIVE_SETTING:=
TTY_SETTING:=
endif

define run_docker
	docker run $(TTY_SETTING) $(INTERACTIVE_SETTING) --rm \
	-e SCP_PRIVKEY=$(SCP_PRIVKEY) \
	-e BOLOS_SDK=$(1) \
	-e BOLOS_ENV=/opt/bolos \
	-u $(USERID) \
	-v $(shell pwd):/project \
	-e SUPPORT_SR25519=$(SUPPORT_SR25519) \
	-e COIN=$(COIN) \
	-e APP_TESTING=$(APP_TESTING) \
	$(DOCKER_IMAGE) "$(2)"
endef

all: build

.PHONY: check_python
check_python:
	@python -c 'import sys; sys.exit(3-sys.version_info.major)' || (echo "The python command does not point to Python 3"; exit 1)

.PHONY: deps
deps: check_python
	@echo "Install dependencies"
	$(CURDIR)/deps/ledger-zxlib/scripts/install_deps.sh

.PHONY: pull
pull:
	docker pull $(DOCKER_IMAGE)

.PHONY: build_rustS
build_rustS:
	$(call run_docker,$(DOCKER_BOLOS_SDKS),make -C $(DOCKER_APP_SRC) rust)

.PHONY: build_rustX
build_rustX:
	$(call run_docker,$(DOCKER_BOLOS_SDKX),make -C $(DOCKER_APP_SRC) rust)

.PHONY: convert_icon
convert_icon:
	@convert $(LEDGER_SRC)/tmp.gif -monochrome -size 16x16 -depth 1 $(LEDGER_SRC)/nanos_icon.gif
	@convert $(LEDGER_SRC)/nanos_icon.gif -crop 14x14+1+1 +repage -negate $(LEDGER_SRC)/nanox_icon.gif

.PHONY: build_icon
build_icon:
	$(info Replacing app icon)
	@cp $(LEDGER_SRC)/nanos_icon.gif $(LEDGER_SRC)/glyphs/icon_app.gif
	@convert $(LEDGER_SRC)/nanos_icon.gif -crop 14x14+1+1 +repage -negate $(LEDGER_SRC)/nanox_icon.gif

.PHONY: build
build: buildS buildX

.PHONY: buildS
buildS: build_icon build_rustS
	$(call run_docker,$(DOCKER_BOLOS_SDKS),make -j `nproc` -C $(DOCKER_APP_SRC))

.PHONY: buildX
buildX: build_icon build_rustX
	$(call run_docker,$(DOCKER_BOLOS_SDKX),make -j `nproc` -C $(DOCKER_APP_SRC))

.PHONY: clean
clean: cleanS cleanX

.PHONY: cleanS
cleanS:
	$(call run_docker,$(DOCKER_BOLOS_SDKS),make -C $(DOCKER_APP_SRC) clean)

.PHONY: cleanX
cleanX:
	$(call run_docker,$(DOCKER_BOLOS_SDKX),make -C $(DOCKER_APP_SRC) clean)

.PHONY: clean_rustS
clean_rustS:
	$(call run_docker,$(DOCKER_BOLOS_SDKS),make -C $(DOCKER_APP_SRC) rust_clean)

.PHONY: clean_rustX
clean_rustX:
	$(call run_docker,$(DOCKER_BOLOS_SDKX),make -C $(DOCKER_APP_SRC) rust_clean)

.PHONY: listvariants
listvariants:
	$(call run_docker,$(DOCKER_BOLOS_SDKS),make -C $(DOCKER_APP_SRC) listvariants)

.PHONY: shellS
shellS:
	$(call run_docker,$(DOCKER_BOLOS_SDKS) -t,bash)

.PHONY: shellX
shellX:
	$(call run_docker,$(DOCKER_BOLOS_SDKX) -t,bash)

.PHONY: load
load:
	${LEDGER_SRC}/pkg/installer_s.sh load

.PHONY: delete
delete:
	${LEDGER_SRC}/pkg/installer_s.sh delete

.PHONY: loadX
loadX:
	${LEDGER_SRC}/pkg/installer_x.sh load

.PHONY: deleteX
deleteX:
	${LEDGER_SRC}/pkg/installer_x.sh delete

.PHONY: show_info_recovery_mode
show_info_recovery_mode:
	@echo "This command requires a Ledger Nano S in recovery mode. To go into recovery mode, follow:"
	@echo " 1. Settings -> Device -> Reset all and confirm"
	@echo " 2. Unplug device, press and hold the right button, plug-in again"
	@echo " 3. Navigate to the main menu"
	@echo "If everything was correct, no PIN needs to be entered."

# This target will initialize the device with the integration testing mnemonic
.PHONY: dev_init
dev_init: show_info_recovery_mode
	@echo "Initializing device with test mnemonic! WARNING TAKES 2 MINUTES AND REQUIRES RECOVERY MODE"
	@python -m ledgerblue.hostOnboard --apdu --id 0 --prefix "" --passphrase "" --pin 5555 --words "equip will roof matter pink blind book anxiety banner elbow sun young"

# This target will initialize the device with the secondary integration testing mnemonic (Bob)
.PHONY: dev_init_secondary
dev_init_secondary: check_python show_info_recovery_mode
	@echo "Initializing device with secondary test mnemonic! WARNING TAKES 2 MINUTES AND REQUIRES RECOVERY MODE"
	@python -m ledgerblue.hostOnboard --apdu --id 0 --prefix "" --passphrase "" --pin 5555 --words "elite vote proof agree february step sibling sand grocery axis false cup"

# This target will setup a custom developer certificate
.PHONY: dev_ca
dev_ca: check_python
	@python -m ledgerblue.setupCustomCA --targetId 0x31100004 --public $(SCP_PUBKEY) --name zondax

# This target will setup a custom developer certificate
.PHONY: dev_caX
dev_caX: check_python
	@python -m ledgerblue.setupCustomCA --targetId 0x33000004 --public $(SCP_PUBKEY) --name zondax

.PHONY: dev_ca_delete
dev_ca_delete: check_python
	@python -m ledgerblue.resetCustomCA --targetId 0x31100004

# This target will setup a custom developer certificate
.PHONY: dev_ca2
dev_ca2: check_python
	@python -m ledgerblue.setupCustomCA --targetId 0x33000004 --public $(SCP_PUBKEY) --name zondax

.PHONY: dev_ca_delete2
dev_ca_delete2: check_python
	@python -m ledgerblue.resetCustomCA --targetId 0x33000004

########################## VUE Section ###############################

.PHONY: vue_install_js_link
ifeq ($(TESTS_JS_DIR),)
vue_install_js_link:
	@echo "No local package defined"
else
vue_install_js_link:
	# First unlink everything
	cd $(TESTS_JS_DIR) && yarn unlink || true
	cd $(EXAMPLE_VUE_DIR) && yarn unlink $(TESTS_JS_PACKAGE) || true
#	# Now build and link
	cd $(TESTS_JS_DIR) && yarn install && yarn build && yarn link || true
	cd $(EXAMPLE_VUE_DIR) && yarn link $(TESTS_JS_PACKAGE) && yarn install || true
	@echo
	# List linked packages
	@echo
	@cd $(EXAMPLE_VUE_DIR) && ( ls -l node_modules ; ls -l node_modules/@* ) | grep ^l || true
	@echo
endif

.PHONY: vue
vue: vue_install_js_link
	cd $(EXAMPLE_VUE_DIR) && yarn install && yarn serve

########################## VUE Section ###############################

.PHONY: zemu_install_js_link
ifeq ($(TESTS_JS_DIR),)
zemu_install_js_link:
	@echo "No local package defined"
else
zemu_install_js_link:
	# First unlink everything
	cd $(TESTS_JS_DIR) && yarn unlink || true
	cd $(TESTS_ZEMU_DIR) && yarn unlink $(TESTS_JS_PACKAGE) || true
	# Now build and link
	cd $(TESTS_JS_DIR) && yarn install && yarn build && yarn link || true
	cd $(TESTS_ZEMU_DIR) && yarn link $(TESTS_JS_PACKAGE) && yarn install || true
	@echo
	# List linked packages
	@echo
	@cd $(TESTS_ZEMU_DIR) && ( ls -l node_modules ; ls -l node_modules/@* ) | grep ^l || true
	@echo
endif

.PHONY: zemu_install
zemu_install: zemu_install_js_link
	# and now install everything
	cd $(TESTS_ZEMU_DIR) && yarn install

.PHONY: zemu
zemu:
	cd $(TESTS_ZEMU_DIR)/tools && node debug.mjs $(COIN)

.PHONY: zemu_val
zemu_val:
	cd $(TESTS_ZEMU_DIR)/tools && node debug_val.mjs

.PHONY: zemu_debug
zemu_debug:
	cd $(TESTS_ZEMU_DIR)/tools && node debug.mjs $(COIN) debug

########################## TEST Section ###############################

.PHONY: zemu_test
zemu_test:
	cd $(TESTS_ZEMU_DIR) && yarn test$(COIN)

.PHONY: rust_test
rust_test:
	cd app/rust && cargo test

.PHONY: cpp_test
cpp_test:
	mkdir -p build && cd build && cmake -DCMAKE_BUILD_TYPE=Debug .. && make
	cd build && GTEST_COLOR=1 ASAN_OPTIONS=detect_leaks=0 ctest -VV

########################## FUZZING Section ###############################

.PHONY: fuzz_build
fuzz_build:
	cmake -B build -DCMAKE_C_COMPILER=clang-10 -DCMAKE_CXX_COMPILER=clang++-10 -DCMAKE_BUILD_TYPE=Debug -DENABLE_FUZZING=1 -DENABLE_SANITIZERS=1 .
	make -C build

.PHONY: fuzz
fuzz: fuzz_build
	./fuzz/run-fuzzers.py

.PHONY: fuzz_crash
fuzz_crash: fuzz_build
	./fuzz/run-fuzz-crashes.py
