/*******************************************************************************
*   (c) 2018, 2019 Zondax GmbH
*   (c) 2016 Ledger
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

#include "app_mode.h"
#include "view.h"
#include "view_internal.h"
#include "actions.h"
#include "apdu_codes.h"
#include "glyphs.h"
#include "bagl.h"
#include "zxmacros.h"
#include "view_templates.h"
#include "tx.h"

#include <string.h>
#include <stdio.h>

#if defined(TARGET_NANOX)

void h_expert_toggle();
void h_expert_update();
void h_review_loop_start();
void h_review_loop_inside();
void h_review_loop_end();

#include "ux.h"
ux_state_t G_ux;
bolos_ux_params_t G_ux_params;
uint8_t flow_inside_loop;


UX_FLOW_DEF_NOCB(ux_idle_flow_1_step, pbb, { &C_icon_app, MENU_MAIN_APP_LINE1, MENU_MAIN_APP_LINE2,});
UX_STEP_CB_INIT(ux_idle_flow_2_step, bn,  h_expert_update(), h_expert_toggle(), { "Expert mode:", viewdata.value, });
UX_FLOW_DEF_NOCB(ux_idle_flow_3_step, bn, { APPVERSION_LINE1, APPVERSION_LINE2, });
UX_FLOW_DEF_NOCB(ux_idle_flow_4_step, bn, { "Developed by:", "Zondax.ch", });
UX_FLOW_DEF_NOCB(ux_idle_flow_5_step, bn, { "License:", "Apache 2.0", });
UX_FLOW_DEF_VALID(ux_idle_flow_6_step, pb, os_sched_exit(-1), { &C_icon_dashboard, "Quit",});

const ux_flow_step_t *const ux_idle_flow [] = {
  &ux_idle_flow_1_step,
  &ux_idle_flow_2_step,
  &ux_idle_flow_3_step,
  &ux_idle_flow_4_step,
  &ux_idle_flow_5_step,
  &ux_idle_flow_6_step,
  FLOW_END_STEP,
};

///////////

UX_STEP_NOCB(ux_error_flow_1_step, bnnn_paging, { .title = viewdata.key, .text = viewdata.value, });
UX_STEP_VALID(ux_error_flow_2_step, pb, h_error_accept(0), { &C_icon_validate_14, "Ok"});

UX_FLOW(
    ux_error_flow,
    &ux_error_flow_1_step,
    &ux_error_flow_2_step
);

///////////
UX_STEP_INIT(ux_review_flow_2_start_step, NULL, NULL, { h_review_loop_start(); });
UX_STEP_NOCB_INIT(ux_review_flow_2_step, bnnn_paging, { h_review_loop_inside(); }, { .title = viewdata.key, .text = viewdata.value, });
UX_STEP_INIT(ux_review_flow_2_end_step, NULL, NULL, { h_review_loop_end(); });

UX_STEP_NOCB(ux_sign_flow_1_step, pbb, { &C_icon_eye, "View", "Transaction" });
UX_STEP_VALID(ux_sign_flow_3_step, pbb, h_sign_accept(0), { &C_icon_validate_14, "Sign", "Transaction" });
UX_STEP_VALID(ux_sign_flow_4_step, pbb, h_sign_reject(0), { &C_icon_crossmark, "Reject", "Transaction" });

const ux_flow_step_t *const ux_sign_flow[] = {
  &ux_sign_flow_1_step,
  &ux_review_flow_2_start_step,
  &ux_review_flow_2_step,
  &ux_review_flow_2_end_step,
  &ux_sign_flow_3_step,
  &ux_sign_flow_4_step,
  FLOW_END_STEP,
};

UX_STEP_NOCB(ux_address_flow_1_step, pbb, { &C_icon_eye, "View", "Address" });
UX_STEP_VALID(ux_address_flow_3_step, pbb, h_address_accept(0), { &C_icon_validate_14, "Accept", "Address" });

const ux_flow_step_t *const ux_address_flow[] = {
  &ux_address_flow_1_step,
  &ux_review_flow_2_start_step,
  &ux_review_flow_2_step,
  &ux_review_flow_2_end_step,
  &ux_address_flow_3_step,
  FLOW_END_STEP,
};

//////////////////////////
//////////////////////////
//////////////////////////
//////////////////////////
//////////////////////////

void h_review_loop_start() {
    if (flow_inside_loop) {
        // coming from right
        h_paging_decrease();
        if (viewdata.itemIdx<0) {
            // exit to the left
            flow_inside_loop = 0;
            ux_flow_prev();
            return;
        }
    } else {
    // coming from left
        h_paging_init();
    }

    zxerr_t err = h_review_update_data();
    switch(err) {
        case zxerr_ok:
        case zxerr_no_data:
            break;
        default:
            view_error_show();
            break;
    }

    ux_flow_next();
}

void h_review_loop_inside() {
    flow_inside_loop = 1;
}

void h_review_loop_end() {
    if (flow_inside_loop) {
        // coming from left
        h_paging_increase();
        zxerr_t err = h_review_update_data();

        switch(err) {
            case zxerr_ok:
                ux_layout_bnnn_paging_reset();
                break;
            case zxerr_no_data: {
                flow_inside_loop = 0;
                ux_flow_next();
                return;
            }
            default:
                view_error_show();
                break;
        }
    } else {
    // coming from right
        h_paging_decrease();
        zxerr_t err = h_review_update_data();

        switch(err) {
            case zxerr_ok:
            case zxerr_no_data:
                break;
            default:
                view_error_show();
                break;
        }
    }

    // move to prev flow but trick paging to show first page
    CUR_FLOW.prev_index = CUR_FLOW.index-2;
    CUR_FLOW.index--;
    ux_flow_relayout();
}

void splitValueField() {
    uint16_t vlen = strlen(viewdata.value);
    if (vlen == 0 ) {
        strcpy(viewdata.value, " ");
    }
}

void h_expert_toggle() {
    app_mode_set_expert(!app_mode_expert());
    ux_flow_init(0, ux_idle_flow, &ux_idle_flow_2_step);
}

void h_expert_update() {
    snprintf(viewdata.value, MAX_CHARS_PER_VALUE1_LINE, "disabled");
    if (app_mode_expert()) {
        snprintf(viewdata.value, MAX_CHARS_PER_VALUE1_LINE, "enabled");
    }
}

//////////////////////////
//////////////////////////
//////////////////////////
//////////////////////////
//////////////////////////

void view_idle_show_impl(uint8_t item_idx) {
    if(G_ux.stack_count == 0) {
        ux_stack_push();
    }
    ux_flow_init(0, ux_idle_flow, NULL);
}

void view_address_show_impl() {
    h_paging_init();
    h_paging_decrease();

    ////
    flow_inside_loop = 0;
    if(G_ux.stack_count == 0) {
        ux_stack_push();
    }
    ux_flow_init(0, ux_address_flow, NULL);
}

void view_sign_show_impl(){
    h_paging_init();
    h_paging_decrease();
    ////
    flow_inside_loop = 0;
    if(G_ux.stack_count == 0) {
        ux_stack_push();
    }
    ux_flow_init(0, ux_sign_flow, NULL);
}

void view_error_show_impl() {
    ux_layout_bnnn_paging_reset();
    if(G_ux.stack_count == 0) {
        ux_stack_push();
    }
    ux_flow_init(0, ux_error_flow, NULL);
}

#endif
