/*******************************************************************************
*   (c) 2018 Zondax GmbH
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
#include "zxmacros.h"
#include "utf8.h"

size_t asciify(char *utf8_in_ascii_out) {
    return asciify_ext(utf8_in_ascii_out, utf8_in_ascii_out);
}

size_t asciify_ext(const char *utf8_in, char *ascii_only_out) {
    void *p = (void *) utf8_in;
    char *q = ascii_only_out;

    // utf8valid returns zero on success
    while (*((char *) p) && utf8valid(p) == 0) {
        utf8_int32_t tmp_codepoint = 0;
        p = utf8codepoint(p, &tmp_codepoint);
        *q = (char) ((tmp_codepoint >= 32 && tmp_codepoint <= (int32_t) 0x7F) ? tmp_codepoint : '.');
        q++;
    }

    // Terminate string
    *q = 0;
    return q - ascii_only_out;
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"

void handle_stack_overflow() {
    zemu_log("!!!!!!!!!!!!!!!!!!!!!! CANARY TRIGGERED!!! STACK OVERFLOW DETECTED\n");
#if defined (TARGET_NANOS) || defined(TARGET_NANOX)
    io_seproxyhal_se_reset();
#else
    while (1);
#endif
}

#pragma clang diagnostic pop

__Z_UNUSED void check_app_canary() {
#if defined (TARGET_NANOS) || defined(TARGET_NANOX)
    if (app_stack_canary != APP_STACK_CANARY_MAGIC) handle_stack_overflow();
#endif
}

#if defined(ZEMU_LOGGING) && (defined (TARGET_NANOS) || defined(TARGET_NANOX))
void zemu_log_stack(const char *ctx) {
#define STACK_SHIFT 20
    void* p = NULL;
    char buf[70];
    snprintf(buf, sizeof(buf), "|SP| %p %p (%d) : %s\n",
            &app_stack_canary,
            ((void*)&p)+STACK_SHIFT,
            (uint32_t)((void*)&p)+STACK_SHIFT - (uint32_t)&app_stack_canary,
            ctx);
    zemu_log(buf);
    (void) ctx;
}
#else

void zemu_log_stack(__Z_UNUSED const char *ctx) {}

#endif


#if defined(ZEMU_LOGGING) && (defined (TARGET_NANOS) || defined(TARGET_NANOX))
void zemu_trace(const char *file, uint32_t line) {
    char buf[200];
    snprintf(buf, sizeof(buf), "|TRACE| %s:%d\n", file, line);
    zemu_log(buf);
}
#else

void zemu_trace(__Z_UNUSED const char *file, __Z_UNUSED uint32_t line) {}

#endif
