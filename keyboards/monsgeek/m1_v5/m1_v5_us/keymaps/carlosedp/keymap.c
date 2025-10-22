// Copyright 2024 yangzheng20003 (@yangzheng20003)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "module.h"
#include "wls/wls.h"
#include QMK_KEYBOARD_H

// External variable to track wireless connection blink
extern uint32_t wls_rgb_indicator_timer;

enum layers {
    _BL = 0,
    _FL,
    _MBL,
    _MFL,
    _FBL,
};

enum custom_keycodes {
    HS_BATQ = SAFE_RANGE,
    CUSTOM_CAPS,
    KEEP_AWAKE,
};

#define ______ HS_BLACK

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BL] = LAYOUT( /* Base */
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,   KC_MUTE,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_HOME,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_PGUP,
        CUSTOM_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,   KC_PGDN,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,    KC_END,
        KC_LCTL,  KC_LCMD,  KC_LALT,                      KC_SPC,                                 KC_RALT,  MO(_FL),  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [_FL] = LAYOUT( /* Function Layer */
        QK_BOOT,  KC_MYCM,  KC_MAIL,  KC_WSCH,  KC_WHOM,  KC_MSEL,  KC_MPLY,  KC_MPRV,  KC_MNXT,  _______,  _______,  _______,  _______,  RGB_MOD,  _______,
        EE_CLR,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RGB_SPD,  RGB_SPI,  _______,  _______,
        QK_RBT,  _______,  _______,   KC_BT1,   KC_BT2,   KC_BT3,   KC_2G4,   KC_USB,   KC_INS,   _______,  KC_PSCR,  _______,  _______,  _______,  _______,
        KC_CAPS,  _______, _______,  _______,  _______,   _______,  _______,  KEEP_AWAKE,  _______,  RGB_TOG,  _______,  _______,            _______,  _______,
        _______,            _______,  _______,  KC_CALC,  _______,  _______,  _______,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,  MO(_FBL), RGB_VAI,  _______,
        _______,   GU_TOGG,  _______,                     HS_BATQ,                                _______,  _______,  _______,  RGB_SAI,  RGB_VAD,  RGB_SAD),

    [_MBL] = LAYOUT( /* Base (Mac) */
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,   KC_MUTE,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_HOME,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_PGUP,
        CUSTOM_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,   KC_PGDN,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,    KC_END,
        KC_LCTL,  KC_LALT,  KC_LCMD,                      KC_SPC,                                 KC_RCMD,  MO(_MFL), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [_MFL] = LAYOUT( /* Function Layer (Mac) */
        _______,  KC_BRID,  KC_BRIU,  KC_MCTL,  _______,  _______,  _______,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  RGB_MOD,  _______,
        EE_CLR,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RGB_SPD,  RGB_SPI,  _______,  _______,
        _______,  _______,  _______,   KC_BT1,   KC_BT2,   KC_BT3,   KC_2G4,   KC_USB,   KC_INS,   _______,  KC_PSCR,  _______,  _______,  _______,  _______,
        KC_CAPS,  _______,  _______,  _______,  _______,  _______,  _______,  KEEP_AWAKE,  _______,  RGB_TOG,  _______,  _______,            _______,  _______,
        _______,            _______,  _______,  KC_CALC,  _______,  _______,  _______,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,  MO(_FBL), RGB_VAI,  _______,
        _______,  _______,  _______,                      HS_BATQ,                                _______,  _______,  _______,  RGB_SAI,  RGB_VAD,  RGB_SAD),
    [_FBL] = LAYOUT( /* ? */
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

bool            rk_bat_req_flag;
bool            rgb_was_enabled_before_bat_check;
bool            rgb_was_enabled_before_wls_blink;
bool            rgb_was_enabled_before_low_batt;
bool            low_battery_active;
static uint32_t last_wls_blink_state = 0;

uint32_t blink_timer;
void     m1v5_blink(void) {
    blink_timer = timer_read32();
}

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

    // prevent timeout
    if (*md_getp_state() == MD_STATE_CONNECTED) {
        hs_rgb_blink_set_timer(timer_read32());
    }

    keep_awake_pressed = !keep_awake_pressed;
    return 5000;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CUSTOM_CAPS: {
            if (record->event.pressed) {
                register_code(KC_LALT);
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_LALT);
                unregister_code(KC_LSFT);
            }

            return false;
        } break;

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
                } else {
                    delayed_exec = defer_exec(KEEP_AWAKE_INTERVAL, keep_awake_callback, NULL);
                    if (delayed_exec != INVALID_DEFERRED_TOKEN) keep_awake_timer = timer_read();
                }
                return false;
            }

            return false;
        } break;

        case HS_BATQ: {
            if (record->event.pressed) {
                // Save current RGB state
                rgb_was_enabled_before_bat_check = rgb_matrix_is_enabled();
                gpio_write_pin_high(LED_POWER_EN_PIN); // Enable LED power to show battery
                rgb_matrix_enable_noeeprom();          // Enable RGB matrix temporarily
            } else {
                // Restore previous RGB state
                if (!rgb_was_enabled_before_bat_check) {
                    rgb_matrix_disable_noeeprom();
                    gpio_write_pin_low(LED_POWER_EN_PIN);
                }
            }
            rk_bat_req_flag = record->event.pressed;
            return false;
        } break;

        // Start/refresh the wireless indicator blink on connection mode switches
        case KC_BT1:
        case KC_BT2:
        case KC_BT3:
        case KC_2G4:
        case KC_USB: {
            if (record->event.pressed) {
                // Kick the blink timer so the user sees immediate feedback
                hs_rgb_blink_set_timer(timer_read32());
            }
            return true; // allow the key to be processed normally
        } break;
    }

    return true;
}

// Ensure the connection-mode blink indicator works even when RGB is toggled off.
// This hook runs regardless of the rgb_matrix enable state.
void housekeeping_task_user(void) {
    // Persistently indicate low battery by forcing RGB on and powering LEDs
    uint8_t bat_pct = *md_getp_bat();
    if (bat_pct <= 20) {
        if (!low_battery_active) {
            rgb_was_enabled_before_low_batt = rgb_matrix_is_enabled();
            gpio_write_pin_high(LED_POWER_EN_PIN);
            rgb_matrix_enable_noeeprom();
            low_battery_active = true;
        }
    } else {
        if (low_battery_active) {
            if (!rgb_was_enabled_before_low_batt) {
                rgb_matrix_disable_noeeprom();
                gpio_write_pin_low(LED_POWER_EN_PIN);
            }
            low_battery_active = false;
        }
    }

    // Handle wireless connection blink indicator
    if (wls_rgb_indicator_timer) {
        if (!last_wls_blink_state) {
            // Blink just started - save RGB state and enable
            rgb_was_enabled_before_wls_blink = rgb_matrix_is_enabled();
            gpio_write_pin_high(LED_POWER_EN_PIN);
            rgb_matrix_enable_noeeprom();
        }
        last_wls_blink_state = 1;
    } else {
        if (last_wls_blink_state) {
            // Blink just finished - restore RGB state
            if (!rgb_was_enabled_before_wls_blink && !low_battery_active) {
                rgb_matrix_disable_noeeprom();
            }
        }
        last_wls_blink_state = 0;
    }

    // Keep LED power in sync with current needs so RGB_TOG can turn LEDs back on after a blink
    // Power is required if any of these are true: low battery overlay, wireless blink active, or RGB is enabled
    bool need_led_power = low_battery_active || (wls_rgb_indicator_timer != 0) || rgb_matrix_is_enabled();
    if (need_led_power) {
        gpio_write_pin_high(LED_POWER_EN_PIN);
    } else {
        gpio_write_pin_low(LED_POWER_EN_PIN);
    }
}

bool rgb_matrix_indicators_user() {
    // NOTE: Wireless indicator enable/restore is handled in housekeeping_task_user

    if (blink_timer) {
        if ((timer_elapsed32(blink_timer) / 250) % 2 == 0) {
            rgb_matrix_set_color_all(0xFF, 0xFF, 0xFF);
        } else {
            rgb_matrix_set_color_all(0x00, 0x00, 0x00);
        }

        if (timer_elapsed32(blink_timer) > 1250) {
            blink_timer = 0;
        }
        return false;
    }

    if (rk_bat_req_flag) {
        rgb_matrix_set_color_all(0x00, 0x00, 0x00);
        for (uint8_t i = 0; i < 10; i++) {
            uint8_t mi_index[10] = RGB_MATRIX_BAT_INDEX_MAP;
            if ((i < (*md_getp_bat() / 10)) || (i < 1)) {
                if (*md_getp_bat() >= (IM_BAT_REQ_LEVEL1_VAL)) {
                    rgb_matrix_set_color(mi_index[i], IM_BAT_REQ_LEVEL1_COLOR);
                } else if (*md_getp_bat() >= (IM_BAT_REQ_LEVEL2_VAL)) {
                    rgb_matrix_set_color(mi_index[i], IM_BAT_REQ_LEVEL2_COLOR);
                } else {
                    rgb_matrix_set_color(mi_index[i], IM_BAT_REQ_LEVEL3_COLOR);
                }
            } else {
                rgb_matrix_set_color(mi_index[i], 0x00, 0x00, 0x00);
            }
        }

        return false;
    }

    if (keep_awake_timer) {
        if (timer_elapsed(keep_awake_timer) / 500 % 2 == 0) {
            rgb_matrix_set_color(59, 0xFF, 0xFF, 0xFF);
        } else {
            rgb_matrix_set_color(59, 0x00, 0x00, 0x00);
        }
    }

    // Overlay: when low battery is active, blink the battery bar indices red
    if (low_battery_active) {
        uint8_t bat          = *md_getp_bat();
        uint8_t mi_index[10] = RGB_MATRIX_BAT_INDEX_MAP;
        bool    on           = ((timer_read32() / 500) % 2) == 0; // 500ms blink cadence
        for (uint8_t i = 0; i < 10; i++) {
            if ((i < (bat / 10)) || (i < 1)) {
                if (on) {
                    rgb_matrix_set_color(mi_index[i], 0xFF, 0x00, 0x00);
                } else {
                    rgb_matrix_set_color(mi_index[i], 0x00, 0x00, 0x00);
                }
            }
        }
    }

    return true;
}
