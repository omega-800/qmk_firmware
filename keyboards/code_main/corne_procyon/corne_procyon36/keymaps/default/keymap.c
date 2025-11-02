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
enum layer_namKC {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] =	LAYOUT(
         KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  CH_DLR,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, CH_LCBR, CH_RCBR,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        CH_QUOT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, CH_COMM,  CH_DOT, CH_MINS, CH_SLSH,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                        KC_LGUI,    KC_RSFT,   MO(2),  KC_ESC,                        KC_SPC,   MO(1),  KC_ENT,  KC_RGUI
                                //`----------------------------------'  `------------------------------------'
	),

    [_LOWER] =	LAYOUT(

        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                         KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_BSPC, KC_BRID, KC_BRIU, KC_MUTE, KC_VOLD, KC_VOLU,                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, CH_LBRC, CH_RBRC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        CH_TILD, CH_CIRC/*CU_CIRC*/, CH_GRV /*CU_GRV*/, KC_MPRV, KC_MPLY, KC_MNXT,                       /*CU_TGSL*/_______, _______, _______, CH_ASTR, CH_BSLS, CH_EQL,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                        KC_LGUI,    KC_LSFT,   MO(2),  KC_ESC,                        KC_SPC,   MO(1),  KC_ENT,  KC_RGUI
                                //`-----------------------------------'  `----------------------------------'
	),
	[_RAISE] =	LAYOUT(
        CH_NOT,  CH_PERC, CH_CCED, CH_EURO, CH_BRKP, CH_CENT,                       CH_AT,   CH_7,    CH_8,    CH_9,    CH_EXLM, CH_UDIA,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_DEL,  CH_DEG,  CH_SECT, KC_PGUP, CH_DIAE, CH_PND,                        CH_AMPR, CH_4,    CH_5,    CH_6,    CH_ODIA, CH_ADIA,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, KC_SLEP, KC_WAKE, KC_PGDN, _______, _______,                       CH_HASH, CH_1,    CH_2,    CH_3,    CH_0,   CH_DOT,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                        KC_LGUI,    KC_LSFT,   MO(2),  KC_ESC,                        KC_SPC,   MO(1),  KC_ENT,  KC_RGUI
                                //`----------------------------------'  `------------------------------------'
	),
   [_ADJUST] =	LAYOUT(

        XXXXXXX, XXXXXXX,   KC_AT, XXXXXXX,  KC_DLR, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, XXXXXXX, KC_AMPR, KC_PIPE, KC_BSLS, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TILD,  KC_GRV,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, KC_PERC, XXXXXXX,                      RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, KC_RSFT,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                        KC_LGUI,    KC_LSFT,   MO(2),  KC_ESC,                        KC_SPC,   MO(1),  KC_ENT,  KC_RGUI
                                 //`---------------------------------'  `-----------------------------------'
	)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP) },
    [_LOWER] = { ENCODER_CCW_CW(/*QK_MOUSE_WHEEL_RIGHT, QK_MOUSE_WHEEL_LEFT*/_______, _______), ENCODER_CCW_CW(KC_BRID, KC_BRIU) },
    [_RAISE] = { ENCODER_CCW_CW(/*QK_LED_MATRIX_BRIGHTNESS_DOWN, QK_LED_MATRIX_BRIGHTNESS_UP*/_______, _______), ENCODER_CCW_CW(QK_BACKLIGHT_DOWN, QK_BACKLIGHT_UP) },
    [_ADJUST] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) }
};
#endif
