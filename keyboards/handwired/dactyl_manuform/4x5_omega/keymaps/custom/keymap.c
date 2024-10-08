// Copyright 2021 Andrzej Kotulski (@akotulski)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
// #include "keymap_us_international.h"
// #include "sendstring_us_international.h"
#include "keymap_swiss_de.h"
//#include "features/custom_shift_keys.h"

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
// #define MATRIX_COL_PINS { D4, C6, D7, E6, D0, B5, B7 }
//#define DE_AE UC(0x00E4) //UP(0x00E4, 0x00C4)
//#define DE_UE UC(0x00FC) //UP(0x00FC, 0x00DC)
//#define DE_OE UC(0x00F6) //UP(0x00F6, 0x00D6)


/*
const custom_shift_key_t custom_shift_keys[] = {
  {CH_QUOT, CH_DQUO}, // shift ' is "
  {CH_LBRC, CH_LCBR}, // shift [ is {
  {CH_RBRC, CH_RCBR}, // shift ] is }
  {CH_EQL,  CH_PLUS}, // shift = is +
  {CH_SLSH, CH_QUES}, // shift / is ?
};
uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);
*/

enum custom_keycodes {
    CU_CIRC = SAFE_RANGE,
    CU_TILD,
    CU_GRV,
    CU_TGSL,
    VI_SAVE,
    LN_SED,
};

bool double_tap = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CU_TGSL:
            if (record->event.pressed) { double_tap = !double_tap; }
            break;
        case VI_SAVE:
            if (record->event.pressed) {
                SEND_STRING(":w");
                register_code(KC_ENT);
                unregister_code(KC_ENT);
            }
            break;
        case CU_CIRC:
            if (record->event.pressed) {
                // because shift is being pressed tild_key_override
                unregister_code(KC_LSFT);
                register_code(CH_CIRC);
                if(double_tap){register_code(CH_CIRC);}
            } else {
                unregister_code(CH_CIRC);
                if(double_tap){unregister_code(CH_CIRC);}
                // because shift is being pressed tild_key_override
                register_code(KC_LSFT);
            }
            break;
        case CU_TILD:
            if (record->event.pressed) {
                register_code(KC_RALT);
                register_code(CH_CIRC);
                if(double_tap){register_code(CH_CIRC);}
                unregister_code(KC_RALT);
            } else {
                register_code(KC_RALT);
                unregister_code(CH_CIRC);
                if(double_tap){unregister_code(CH_CIRC);}
                unregister_code(KC_RALT);
            }
            break;
        case CU_GRV:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(CH_CIRC);
                if(double_tap){register_code(CH_CIRC);}
                unregister_code(KC_LSFT);
            } else {
                register_code(KC_LSFT);
                unregister_code(CH_CIRC);
                if(double_tap){unregister_code(CH_CIRC);}
                unregister_code(KC_LSFT);
            }
            break;
    }
    return true;
}

const key_override_t quot_key_override =
    ko_make_basic(MOD_MASK_SHIFT, CH_QUOT, CH_DQUO);  // shift ' is "
const key_override_t lbrc_key_override =
    ko_make_basic(MOD_MASK_SHIFT, CH_LBRC, CH_LABK);  // shift [ is <
const key_override_t rbrc_key_override =
    ko_make_basic(MOD_MASK_SHIFT, CH_RBRC, CH_RABK);  // shift ] is >
const key_override_t lprn_key_override =
    ko_make_basic(MOD_MASK_SHIFT, CH_LCBR, CH_LPRN);  // shift { is (
const key_override_t rprn_key_override =
    ko_make_basic(MOD_MASK_SHIFT, CH_RCBR, CH_RPRN);  // shift } is )
const key_override_t eql_key_override =
    ko_make_basic(MOD_MASK_SHIFT, CH_EQL,  CH_PLUS);  // shift = is +
const key_override_t slsh_key_override =
    ko_make_basic(MOD_MASK_SHIFT, CH_SLSH, CH_QUES);  // shift / is ?
// does not work
const key_override_t tild_key_override =
    ko_make_basic(MOD_MASK_SHIFT, CU_TILD, CU_CIRC);  // shift ~ is ^
const key_override_t dlr_key_override =
    ko_make_basic(MOD_MASK_SHIFT, CH_DLR, CH_PIPE);  // shift $ is |

const key_override_t** key_overrides = (const key_override_t*[]){
    &quot_key_override,
    &lbrc_key_override,
    &rbrc_key_override,
    &lprn_key_override,
    &rprn_key_override,
    &eql_key_override,
    &slsh_key_override,
    //&tild_key_override,
    &dlr_key_override,
    NULL
};

enum layer_names {
    _BASE,
    _RAISE,
    _LOWER
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base
     *        *----------------------------------+              +----------------------------------+    ------+
     *        |   q  |   w  |   e  |   r  |   t  |              |   z  |   u  |   i  |   o  |   p  |      $|  |
     *        +------+------+------+------+------|              |------+------+------+------+------+    ------|
     *        |   a  |   s  |   d  |   f  |   g  |              |   h  |   j  |   k  |   l  |  $|  |      })  |
     *        +------+------+------+------+------|              |------+------+------+------+------+    ------|
     *        |   y  |   x  |   c  |   v  |   b  |              |   n  |   m  |  ,;  |  .:  |  -_  |     SHFT |
     *        *------+------+------+-------------+              +-------------+------+------+------+    ------+
     *               |  ~^  |  '"  |                                          |  =+  |  /?  |
     *               +-------------+                                          +-------------+
     *
     *               +------*--------------------+              +--------------------+------+
     *               | CTRL | TAB  |  RA  | ???? |              | CAPS |  LO  | SHFT |  ENT |
     *               +------+------+------+------+              +------+------+------+------+
     *                             |  SUP | ESC  |              |  SPC | LALT |
     *                             +-------------+              +-------------+
     */
    [_BASE] = LAYOUT_omega(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     //CH_DLR,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,               KC_H,    KC_J,    KC_K,    KC_L,    CH_DLR,   //CH_RCBR,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,               KC_N,    KC_M,    CH_COMM, CH_DOT,  CH_MINS,  //KC_RSFT,
                 CU_TILD, CH_QUOT, RAISE,   _______,            KC_CAPS, LOWER,   CH_EQL,  CH_SLSH,
                 KC_LCTL, KC_TAB,  KC_LGUI, KC_ESC,             KC_SPC,  KC_LALT, KC_RSFT, KC_ENT
    ),

    /* Lower
     *         +----------------------------------+             +----------------------------------+
     *         |  <   |  >   |  {   |  }   |  !   |             | BRID | BRIU | MUTE | VOLD | VOLU |
     *         |------+------+------+------+------|             |------+------+------+------+------|
     *         |  [   |  ]   |  (   |  )   |  €   |             | LEFT | DOWN |  UP  | RGHT | TGSL |
     *         |------+------+------+------+------|             |------+------+------+------+------|
     *         |      |      | PSCR | MON? |  %   |             | CLR  | FIND | MPRV | MPLY | MNXT |
     *         +------+------+------+-------------+             +-------------+------+------+------+
     *                |  ^   |  `°  |                                         |  *   |  \   |
     *                +-------------+                                         +-------------+
     */
    [_LOWER] = LAYOUT_omega(
        _______, _______, _______, _______, _______,             KC_BRID, KC_BRIU, KC_MUTE, KC_VOLD, KC_VOLU, //KC_F12,
        _______, _______, _______, _______, _______,             KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, CU_TGSL, //CH_LBRC, CH_RBRC,
        _______, _______, _______, _______, _______,             KC_CLR,  KC_FIND, KC_MPRV, KC_MPLY, KC_MNXT, //_______,
                 CU_CIRC, CU_GRV,  _______, _______,             KC_BSPC, _______, CH_ASTR, CH_BSLS,
                 KC_RCTL, KC_TAB,  KC_LGUI, KC_ESC,              KC_SPC,  KC_LALT, KC_RSFT, KC_ENT
    ),

    /* Upper
     *         +----------------------------------+              +----------------------------------+
     *         |  F1  |  F2  |  F3  |  F4  |  ¢ç  |              |  @!  |  7   |  8   |  9   |  ü   |
     *         |------+------+------+------+------|              |------+------+------+------+------|
     *         |  F5  |  F6  |  F7  |  F8  |  £§  |              |  &€  |  4   |  5   |  6   |  ä   |
     *         |------+------+------+------+------|              |------+------+------+------+------|
     *         |  F9  |  F10 |  F11 |  F12 |  ¨¬  |              |  #%  |  1   |  2   |  3   |  ö   |
     *         +------+------+------+-------------+              +-------------+------+------+------+
     *                |      |      |                                          |  0   |  .   |
     *                +-------------+                                          +-------------+
     */
    [_RAISE] = LAYOUT_omega(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,             CH_AT,   CH_7,    CH_8,    CH_9,    CH_UDIA,
        KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,             CH_AMPR, CH_4,    CH_5,    CH_6,    CH_ADIA,
        KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,             CH_HASH, CH_1,    CH_2,    CH_3,    CH_ODIA,
                 _______, _______, _______, _______,             _______, _______, CH_0,    CH_DOT,
                 KC_RCTL, KC_TAB,  KC_LGUI, KC_ESC,              KC_SPC,  KC_RALT, KC_RSFT, KC_ENT
    )
};


