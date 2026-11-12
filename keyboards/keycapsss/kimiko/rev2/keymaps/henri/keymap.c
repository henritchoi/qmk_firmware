/* Copyright 2019 Leo Batyuk
 * Copyright 2020 Drashna Jaelre <@drashna>
 * Copyright 2020 @ben_roe (keycapsss.com)
 * Copyright 2023 @Ex3c4Def
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* QWERTY
 * ,--------------------------------------------.                                   ,----------------------------------------------.
 * |   ESC   |   1  |   2  |   3  |   4  |   5  |                                   |   6  |   7  |   8  |   9  |   0  |  `        |
 * |---------+------+------+------+------+------|                                   |------+------+------+------+------+-----------|
 * |   Tab   |   Q  |   W  |   E  |   R  |   T  |                                   |   Y  |   U  |   I  |   O  |   P  |  -        |
 * |---------+------+------+------+------+------|                                   |------+------+------+------+------+-----------|
 * |  LShift |   A  |   S  |   D  |   F  |   G  |---------------.   ,---------------|   H  |   J  |   K  |   L  |   ;  |  '        |
 * |---------+------+------+------+------+------|  (   |   [    |   |   ]   |   )   |------+------+------+------+------+-----------|
 * |  LCTRL  |   Z  |   X  |   C  |   V  |   B  |------|--------|   |-------|-------|   N  |   M  |   ,  |  .  |   /   |   RShift  |
 * `--------------------------------------------|               /    \              |----------------------------------------------'
 *                         | LCTRL| LALT |LGUI  |Space |LOWER  /      \BackSP|RAISE |Enter| BackSP| Mute |
 *                         `----------------------------------'        '---------------------------------'
 */
 [_QWERTY] = LAYOUT(
    KC_ESC,  KC_1,  KC_2,    KC_3,    KC_4,    KC_5,                                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
    KC_TAB,  KC_Q,  KC_W,    KC_E,    KC_R,    KC_T,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
    KC_LSFT, KC_A      
    ,  KC_S,    KC_D,    KC_F,    KC_G,                                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LCTL, KC_Z,  KC_X,    KC_C,    KC_V,    KC_B,    KC_LPRN, KC_LBRC,  KC_RBRC, TL_UPPR, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                             KC_LCTL, KC_LGUI, KC_LALT,  LT(1, KC_SPC), TL_LOWR, TL_UPPR, LT(2, KC_ENT), KC_BSPC, KC_LCTL, KC_KB_MUTE
),
/* LOWER
* QWERTY
 * ,--------------------------------------------.                                   ,----------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |                                   |  F6  |  F7  |  F8  |  F9  | F10  |  F11      |
 * |---------+------+------+------+------+------|                                   |------+------+------+------+------+-----------|
 * |         |   1  |   2  |   3  |   4  |   5  |                                   |   6  |   7  |   8  |   9  |   0  |  F12      |
 * |---------+------+------+------+------+------|                                   |------+------+------+------+------+-----------|
 * |    `    |   !  |   @  |   #  |   $  |   %  |---------------.   ,---------------|   ^  |   &  |   *  |   (  |   )  |  ~        |
 * |---------+------+------+------+------+------|      |        |   |       |       |------+------+------+------+------+-----------|
 * |         |      | HOME | END  | PGUP | PGDN |------|--------|   |-------|-------|      |   _  |   +  |   {  |   }  |  \        |
 * `--------------------------------------------|               /    \              |----------------------------------------------'
 *                         | LCTRL| LGUI |LALT  |Space |LOWER  /      \RAISE| Enter |BackSP| RGUI | RALT |
 *                         `----------------------------------'        '---------------------------------'
 */
[_LOWER] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                    KC_CIRC, KC_AMPR, KC_KP_ASTERISK, KC_LPRN, KC_RPRN, _______,
    _______, _______ , _______ , _______, _______, _______,_______,_______, _______, _______, XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_BSLS,
                               _______, _______, _______, _______,_______, _______, LT(3, KC_ENT), _______, _______, _______
),
/* RAISE
 * ,--------------------------------------------.                                   ,----------------------------------------------.
 * |         |      |      |      |      |      |                                   |      |      |      |      |      |           |
 * |---------+------+------+------+------+------|                                   |------+------+------+------+------+-----------|
 * |   `     |   1  |   2  |   3  |   4  |   5  |                                   |   6  |   7  |   8  |   9  |   0  |           |
 * |---------+------+------+------+------+------|                                   |------+------+------+------+------+-----------|
 * |  F1     |  F2  |  F3  | F4 |  F5  |  F6  |---------------.   ,---------------|xxxxxx| Left | Down |  Up  |Right |     |     |
 * |---------+------+------+------+------+------|  [   |   [    |   |   [   |   [   |------+------+------+------+------+-----------|
 * |  F7     |  F8  |  F9  | F10  | F11  | F12  |------|--------|   |-------|-------|   +  |   -  |   =  |  [  |   ]   |   \       |
 * `--------------------------------------------|               /    \              |----------------------------------------------'
 *                         | LCTRL| LGUI |LALT  |Space |LOWER  /      \RAISE| Enter |BackSP| RGUI | RALT |
 *                         `----------------------------------'        '---------------------------------'
 */
 [_RAISE] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______, _______,
    _______,  KC_HOME,    KC_END,    KC_PGUP,    KC_PGDN,    _______,                                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______,  KC_LEFT,    KC_DOWN,   KC_UP,   KC_RIGHT,   _______,                                          XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PIPE,
    _______,   _______,   _______,   _______,  _______,  _______,   _______, _______,  _______, _______,  KC_PLUS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
                               _______, _______, _______, LT(3, KC_SPC), _______,  _______, _______,  _______, _______, _______
),
/* ADJUST (Press LOWER and RAISE together)
 * ,--------------------------------------------.                                   ,----------------------------------------------.
 * | QK_BOOT |      |      |      |     |       |                                   |      |      |      |      |      |           |
 * |---------+------+------+------+------+------|                                   |------+------+------+------+------+-----------|
 * | RGB ON  | HUE+ | SAT+ | VAL+ |      |MacWin|                                   | PREV | PLAY | NEXT |      |      |           |
 * |---------+------+------+------+------+------|                                   |------+------+------+------+------+-----------|
 * | MODE    | HUE- | SAT- | VAL- |      |      |---------------.   ,---------------| VOL+ | MUTE | VOL- |      |      |           |
 * |---------+------+------+------+------+------|      |        |   |       |       |------+------+------+------+------+-----------|
 * |         |      | VOL+ | VOL- | BRIU | BRID |------|--------|   |-------|-------|      |      |      |      |       |           |
 * `--------------------------------------------|               /    \              |----------------------------------------------'
 *                         | LCTRL| LGUI |LALT  |Space |LOWER  /      \RAISE| Enter |BackSP| RGUI | RALT |
 *                         `----------------------------------'        '---------------------------------'
 */
[_ADJUST] = LAYOUT(
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    RM_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CG_LSWP,                                     KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     KC_VOLU, KC_MUTE, KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_KB_VOLUME_UP, KC_KB_VOLUME_DOWN, KC_BRIU, KC_BRID, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)
};



#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY] = { ENCODER_CCW_CW(KC_DOWN, KC_UP),          ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_LOWER] =  { ENCODER_CCW_CW(XXXXXXX, KC_TAB),         ENCODER_CCW_CW(KC_LEFT, KC_RGHT)},
    [_RAISE] =  { ENCODER_CCW_CW(XXXXXXX, XXXXXXX),        ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [_ADJUST] = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX),       ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
};
#endif // ENCODER_MAP_ENABLE
