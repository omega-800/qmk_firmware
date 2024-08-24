// Copyright 2021 Andrzej Kotulski (@akotulski)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
// #include "keymap_german.h"

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
// #define MATRIX_COL_PINS { D4, C6, D7, E6, D0, B5, B7 }
#define DE_AE UP(0x00E4, 0x00C4)
#define DE_UE UP(0x00FC, 0x00DC)
#define DE_OE UP(0x00F6, 0x00D6)

enum layer_names {
    _BASE,
    _RAISE,
    _LOWER
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base (qwerty)
     * +-----------------------------------------+                             +-----------------------------------------+
     * | TAB  |   q  |   w  |   e  |   r  |   t  |                             |   z  |   u  |   i  |   o  |   p  |   ü  |
     * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     * | BSP  |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ö  |   ä  |
     * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     * | SHFT |   y  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   /  |      |
     * +------+------+------+------+------+------+                             +------+------+------+------+------+------+
     *               |  [   |   ]  |      |      |                             |      |      |   =  |   -  |
     *        +------+------+------+-------------+                             +-------------+------+------+------+
     *        |      |      |      |                                                         |      |      |      |
     *        +------+------+------+                                                         +------+------+------+
     */
    [_BASE] = LAYOUT_omega(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,               KC_Z,    KC_U,    KC_I,    KC_O,    KC_P,     DE_UE,
        KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,               KC_H,    KC_J,    KC_K,    KC_L,    DE_OE,    DE_AE,
        KC_LSFT, KC_Y,    KC_X,    KC_C,    KC_V,    KC_B,               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_BSLS,
                          KC_LBRC, KC_RBRC, RAISE,   KC_ESC,             KC_DEL,  LOWER,   KC_EQL,  KC_MINS,
                 KC_LGUI, KC_LALT, KC_HOME,                                                KC_END,  KC_ENT,  KC_SPC
    ),

    [_LOWER] = LAYOUT_omega(
        _______, _______, _______, _______, _______, KC_LBRC,             KC_RBRC, KC_P7,   KC_P8,   KC_P9,   QK_BOOT, KC_PLUS,
        _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END , KC_LPRN,             KC_RPRN, KC_P4,   KC_P5,   KC_P6,   KC_MINS, KC_PIPE,
        _______, _______, _______, _______, _______, _______,             _______, KC_P1,   KC_P2,   KC_P3,   KC_EQL,  KC_UNDS,
        _______, _______, _______, KC_PSCR,                                                 _______, _______, _______, KC_P0,
                          _______, _______, _______,                               _______, _______, _______
    ),

    [_RAISE] = LAYOUT_omega(
        _______, QK_BOOT, _______, _______, _______, KC_LBRC,             KC_RBRC, _______, KC_NUM, KC_INS,  KC_SCRL, KC_MUTE,
        _______, KC_LEFT, KC_UP  , KC_DOWN, KC_RGHT, KC_LPRN,             KC_RPRN, KC_MPRV, KC_MPLY, KC_MNXT, _______, KC_VOLU,
        _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, KC_VOLD,
        _______, _______, _______, _______,                                                 _______, _______, KC_EQL,  _______,
                          _______, _______, _______,                               _______, _______, _______
    )
};

