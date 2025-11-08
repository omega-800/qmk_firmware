/* Copyright 2022 LXF-YZP(yuezp)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNKCS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licensKC/>.
 */

#include QMK_KEYBOARD_H
#include "keymap_swiss_de.h"

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

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
    _LOWER,
    _ADJUST
};

/*
enum layer_namKC {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST
};
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] =	LAYOUT(


         KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  CH_DLR,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_BSPC,LALT_T(KC_A),LGUI_T(KC_S),LSFT_T(KC_D),LCTL_T(KC_F),KC_G,             KC_H,RCTL_T(KC_J),RSFT_T(KC_K),RGUI_T(KC_L),RALT_T(CH_LCBR),CH_RCBR,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        CH_QUOT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, CH_COMM,  CH_DOT, CH_MINS, CH_SLSH,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                        KC_LGUI,    KC_RSFT,   RAISE,  KC_ESC,                        KC_SPC,   LOWER,  KC_ENT,  KC_RGUI
                                //`----------------------------------'  `------------------------------------'
	),

    [_LOWER] =	LAYOUT(

        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                         KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_CAPS, KC_BRID, KC_BRIU, KC_MUTE, KC_VOLD, KC_VOLU,                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, CH_LBRC, CH_RBRC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        CU_TILD, CU_CIRC, CU_GRV, KC_MPRV, KC_MPLY, KC_MNXT,                       CU_TGSL,  KC_PGDN, KC_PGUP, CH_ASTR, CH_BSLS, CH_EQL,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                        KC_LGUI,    KC_LSFT,   RAISE,  KC_ESC,                        KC_SPC,   LOWER,  KC_ENT,  KC_RGUI
                                //`-----------------------------------'  `----------------------------------'
	),
	[_RAISE] =	LAYOUT(
        CH_NOT,  CH_PERC, CH_CCED, CH_EURO, CH_BRKP, CH_CENT,                       CH_AT,   CH_7,    CH_8,    CH_9,    CH_EXLM, CH_UDIA,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_DEL,  CH_DEG,  CH_SECT, CH_ASTR, CH_DIAE, CH_PND,                        CH_AMPR, CH_4,    CH_5,    CH_6,    CH_ODIA, CH_ADIA,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        CH_DQUO, KC_SLEP, KC_WAKE, _______, _______, _______,                       CH_HASH, CH_1,    CH_2,    CH_3,    CH_0,   CH_DOT,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                        KC_LGUI,    KC_LSFT,   RAISE,  KC_ESC,                        KC_SPC,   LOWER,  KC_ENT,  KC_RGUI
                                //`----------------------------------'  `------------------------------------'
	),
   [_ADJUST] =	LAYOUT(

        _______, _______,   KC_AT, _______,  KC_DLR, _______,                      _______, _______, _______, _______, _______, KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, _______, KC_AMPR, KC_PIPE, KC_BSLS, _______,                      _______, _______, _______, _______, KC_TILD,  KC_GRV,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, _______, _______, _______, KC_PERC, _______,                      RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, KC_RSFT,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                        KC_LGUI,    KC_LSFT,   RAISE,  KC_ESC,                        KC_SPC,   LOWER,  KC_ENT,  KC_RGUI
                                 //`---------------------------------'  `-----------------------------------'
	)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(KC_BRID, KC_BRIU), ENCODER_CCW_CW(KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP) },
    [_LOWER] = { ENCODER_CCW_CW(/*QK_MOUSE_WHEEL_RIGHT, QK_MOUSE_WHEEL_LEFT*/_______, _______), ENCODER_CCW_CW(QK_BACKLIGHT_DOWN, QK_BACKLIGHT_UP) },
    [_RAISE] = { ENCODER_CCW_CW(/*QK_LED_MATRIX_BRIGHTNESS_DOWN, QK_LED_MATRIX_BRIGHTNESS_UP*/_______, _______), ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) },
    [_ADJUST] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) }
};
#endif
