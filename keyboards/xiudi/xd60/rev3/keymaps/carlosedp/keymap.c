#include QMK_KEYBOARD_H
#include "action_layer.h"

// Some macros
#define ______ KC_NO
#define SFT_GRV MT(MOD_LSFT | MOD_RSFT, KC_GRV)
#define WIN_SCR LSG(KC_S)
#define MAC_SCR LSG(KC_4)
#define MAC_SCC LCSG(KC_4)
#define GO__TOP LCTL(KC_HOME)
#define GO__BOT LCTL(KC_END)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* 0: Base Layer - Default Layer
     * |---------------------------------------------------------------|
     * |  Esc~  | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | - | = | Back |
     * |---------------------------------------------------------------|
     * |   Tab  | Q | W | E | R | T | Y | U | I | O | P | [ | ] |   \  |
     * |---------------------------------------------------------------|
     * | FUNCTION | A | S | D | F | G | H | J | K | L | ; | ' | Return |
     * |---------------------------------------------------------------|
     * |Shift   | Z | X | C | V | B | N | M | , | . | / | Sh/`| Up |Del|
     * |---------------------------------------------------------------|
     * |Ctrl|Alt |Cmd |         Space         |Cmd|FUNC|Left|Down|Right|
     * |---------------------------------------------------------------|
     */
    LAYOUT_all(
        QK_GESC,          KC_1,    KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,   KC_BSPC, ______,
        KC_TAB,           KC_Q,    KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,  KC_BSLS,
        MO(1),            KC_A,    KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT, ______,   KC_ENT,
        KC_LSFT, ______,  KC_Z,    KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM, KC_DOT,  KC_SLSH, SFT_GRV, KC_UP,    KC_DEL,
        KC_LCTL, KC_LALT, KC_LGUI,                       KC_SPC,                      KC_RGUI, MO(1),   KC_LEFT, KC_DOWN,  KC_RIGHT
    ),

    /* 1: Function Layer
     * ,------------------------------------------------------------------------|
     * |  ` |F1 | F2 | F3 | F4 | F5 | F6| F7| F8| F9| F10 |  F11  |  F12  | DEL |
     * |------------------------------------------------------------------------|
     * |   |Bl+|Bl-|BlOn|BlOff|Bl |Bl |   |   |   | Play|Bright-|Bright+ |      |
     * |------------------------------------------------------------------------|
     * |FUN|RGB|RGB|RGB |RGB  |RGB|RGB|RGB|RGB|RGB|     |       |    Return     |
     * |------------------------------------------------------------------------|
     * |Shift  |MR1|MP1|MR2|MP2|MSt|   |   |Mute|Vol-| Vol+ | |Shift| PgUp |Ins |
     * |------------------------------------------------------------------------|
     * | Ctrl | Alt | Cmd |         Space            | Cmd |FUNC|Home|PgDn|End  |
     * `------------------------------------------------------------------------|
     */
    LAYOUT_all(
        KC_GRAVE,          KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL, ______,
        ______,            BL_DOWN,  BL_UP,    BL_ON,    BL_OFF,   BL_STEP,  BL_BRTG,  ______,   ______,   ______,   KC_MPLY,  KC_BRID,  KC_BRIU,  ______,
        MO(1),             RM_TOGG,  RM_NEXT,  RM_HUED,  RM_HUEU,  RM_SATD,  RM_SATU,  RM_VALD,  RM_VALU,  ______,   ______,   ______,   ______,   KC_ENT,
        KC_LSFT, ______,   DM_REC1,  DM_PLY1,  DM_REC2,  DM_PLY2,  DM_RSTP,  ______,   KC_MUTE,  KC_VOLD,  KC_VOLU,  ______,   KC_RSFT,  KC_PGUP,  KC_INS,
        KC_LCTL, KC_LALT,  KC_LGUI,                             KC_SPC,                                    KC_RGUI,  MO(1),    KC_HOME,  KC_PGDN,  KC_END),

};
// clang-format on
