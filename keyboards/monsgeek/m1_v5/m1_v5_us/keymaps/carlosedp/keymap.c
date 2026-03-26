// Copyright 2024 yangzheng20003 (@yangzheng20003)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "module.h"
#include "lowpower.h"
#include "wls/wls.h"
#include QMK_KEYBOARD_H

// clang-format off
enum layers {
    _BL = 0,  // Base Layer (Windows)
    _FL,      // Function Layer (Windows)
    _MBL,     // Base Layer (Mac)
    _MFL,     // Function Layer (Mac)
    _FBL      // FN+Shift Layer
};
// clang-format on

enum custom_keycodes {
    CUSTOM_CAPS = SAFE_RANGE,
    KEEP_AWAKE,
};

// Some macros
#define ______ HS_BLACK
#define SFT_GRV MT(MOD_LSFT | MOD_RSFT, KC_GRV) // Shifted Grave Accent
#define WIN_SCR LSG(KC_S)                       // Windows Screenshot
#define MAC_SCR LSG(KC_4)                       // Mac Screenshot
#define MAC_SCC LCSG(KC_4)                      // Mac Screenshot to Clipboard
#define GO__TOP LCTL(KC_HOME)                   // Go to Top
#define GO__BOT LCTL(KC_END)                    // Go to Bottom

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BL] = LAYOUT( /* Base */
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,   KC_MUTE,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  WIN_SCR,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  RM_TOGG,
        MO(_FL),  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,   KC_PGUP,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  SFT_GRV,  KC_UP,    KC_PGDN,
        KC_LCTL,  KC_LCMD,  KC_LALT,                      KC_SPC,                                 KC_RALT,  MO(_FL),  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),


    [_FL] = LAYOUT( /* Function Layer */
        QK_BOOT,  KC_MYCM,  KC_MAIL,  KC_WSCH,  KC_WHOM,  KC_MSEL,  KC_MPLY,  KC_MPRV,  KC_MNXT,  _______,  _______,  _______,  _______,  RM_NEXT,  _______,
        EE_CLR,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RM_SPDD,  RM_SPDU,  _______,  RM_VALU,
        QK_RBT,   KC_BT1,   KC_BT2,   KC_BT3,   KC_2G4,   KC_USB,   _______,  _______,  KC_INS,   _______,  KC_PSCR,  _______,  _______,  _______,  RM_VALD,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  KEEP_AWAKE,_______, RM_TOGG,  RM_SATD,  RM_SATU,            _______,  GO__TOP,
        _______,            _______,  _______,  KC_CALC,  _______,  _______,  _______,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,  MO(_FBL), KC_PGUP,  GO__BOT,
        _______,  GU_TOGG,  _______,                      HS_BATQ,                                _______,  _______,  _______,  KC_HOME,  KC_PGDN,  KC_END),

    [_MBL] = LAYOUT( /* Base (Mac) */
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,   KC_MUTE,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  MAC_SCC,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  RM_TOGG,
        MO(_MFL), KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,   KC_PGUP,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  SFT_GRV,  KC_UP,    KC_PGDN,
        KC_LCTL,  KC_LALT,  KC_LCMD,                      KC_SPC,                                 KC_RCMD,  MO(_MFL), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [_MFL] = LAYOUT( /* Function Layer (Mac) */
        QK_BOOT,  KC_BRID,  KC_BRIU,  KC_MCTL,  HS_SIRI,  _______,  _______,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  RM_NEXT,  _______,
        EE_CLR,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RM_SPDD,  RM_SPDU,  _______,  _______,
        _______,  KC_BT1,   KC_BT2,   KC_BT3,   KC_2G4,   KC_USB,   _______,  _______,  KC_INS,   _______,  KC_PSCR,  _______,  _______,  _______,  RM_VALU,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  KEEP_AWAKE,_______, RM_TOGG,  RM_SATD,  RM_SATU,            _______,  GO__TOP,
        _______,            _______,  _______,  KC_CALC,  _______,  _______,  _______,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,  MO(_FBL), KC_PGUP,  GO__BOT,
        _______,  _______,  _______,                      HS_BATQ,                                _______,  _______,  _______,  KC_HOME,  KC_PGDN,  KC_END),

    [_FBL] = LAYOUT( /* FN+Shift Layer */
        QK_BOOT,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,                      _______,                                _______,  _______,  _______,  _______,  _______,  _______)

};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [1] = {ENCODER_CCW_CW(_______, _______)},
    [2] = {ENCODER_CCW_CW(_______, _______)},
    [3] = {ENCODER_CCW_CW(_______, _______)},
    [4] = {ENCODER_CCW_CW(_______, _______)},
};
#endif
// clang-format on

// Blink function from keyboard
extern void hs_kb_blink(void);

// Keep awake feature
#define KEEP_AWAKE_KEY KC_LSFT
#define KEEP_AWAKE_INTERVAL 5000
uint32_t keep_awake_timer;
bool     keep_awake_pressed = false;

uint32_t keep_awake_callback(uint32_t trigger_time, void *cb_arg) {
    if (keep_awake_pressed) {
        unregister_code(KEEP_AWAKE_KEY);
    } else {
        register_code(KEEP_AWAKE_KEY);
    }
    lpwr_update_timestamp();

    // prevent timeout
    if (*md_getp_state() == MD_STATE_CONNECTED) {
        hs_rgb_blink_set_timer(timer_read32());
    }

    keep_awake_pressed = !keep_awake_pressed;
    return KEEP_AWAKE_INTERVAL;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CUSTOM_CAPS:
            if (record->event.pressed) {
                register_code(KC_LALT);
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_LALT);
                unregister_code(KC_LSFT);
            }
            return false;

        case KEEP_AWAKE: {
            static deferred_token delayed_exec = INVALID_DEFERRED_TOKEN;
            if (record->event.pressed) {
                if (keep_awake_timer) {
                    cancel_deferred_exec(delayed_exec);
                    if (keep_awake_pressed) {
                        unregister_code(KEEP_AWAKE_KEY);
                        keep_awake_pressed = false;
                    }
                    keep_awake_timer = 0;
                    delayed_exec     = INVALID_DEFERRED_TOKEN;
                    md_send_devctrl(MD_SND_CMD_DEVCTRL_SLEEP_BT_EN);
                    md_send_devctrl(MD_SND_CMD_DEVCTRL_SLEEP_2G4_EN);
                } else {
                    delayed_exec = defer_exec(KEEP_AWAKE_INTERVAL, keep_awake_callback, NULL);
                    if (delayed_exec != INVALID_DEFERRED_TOKEN) keep_awake_timer = timer_read();
                    md_send_devctrl(MD_SND_CMD_DEVCTRL_SLEEP_BT_DIS);
                    md_send_devctrl(MD_SND_CMD_DEVCTRL_SLEEP_2G4_DIS);
                }
            }
            return false;
        }
    }

    return true;
}

bool rgb_matrix_indicators_user(void) {
    // Blink J key (index 59) when keep awake is active
    if (keep_awake_timer) {
        if (timer_elapsed(keep_awake_timer) / 500 % 2 == 0) {
            rgb_matrix_set_color(59, 0xFF, 0xFF, 0xFF);
        } else {
            rgb_matrix_set_color(59, 0x00, 0x00, 0x00);
        }
    }

    return true;
}
