/*
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
// Default layout for RAMA WORKS KARA

// Hold escape while plugging in to reset

#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _FUNC,
    _MISC
};

/* Shortcuts */
#define HOME    G(KC_LEFT)
#define END     G(KC_RGHT)
#define WORD_L  A(KC_LEFT)
#define WORD_R  A(KC_RGHT)
#define SS_FULL G(S(KC_3))
#define SS      G(S(KC_4))
#define SS_CLIP C(G(S(KC_4)))
#define TAB_L   G(S(KC_LBRC))
#define TAB_R   G(S(KC_RBRC))
#define DESK_L  C(KC_LEFT)
#define DESK_R  C(KC_RGHT)
#define SEARCH  G(KC_SPC)
#define EMOJI   C(G(KC_SPC))
#define MISSION C(KC_UP)
#define CTL_CAP LCTL_T(KC_ESC)

/* Layers */
#define FUNC  MO(_FUNC)
#define MISC  MO(_MISC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// Default layer
[_BASE] = LAYOUT_60_hhkb(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_DEL,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
    CTL_CAP, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, FUNC,
                KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RGUI, KC_RALT),

// Function layer
[_FUNC] = LAYOUT_60_hhkb(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,  _______,
    _______, DESK_L,  DESK_R,  TAB_L,   TAB_R,   KC_VOLU, _______, _______, _______, HOME,    WORD_L,  KC_UP,   WORD_R, _______,
    _______, _______, _______, _______, _______, KC_VOLD, _______, _______, _______, END,     KC_LEFT, KC_RGHT, KC_LCTL,
    _______, SS_CLIP, SS,      KC_MPRV, KC_MNXT, KC_MPLY, _______, MISSION, _______, EMOJI,   KC_DOWN, _______, _______,
                _______, _______,                            _______,                            _______, MISC),
// Miscellaneous layer
[_MISC] = LAYOUT_60_hhkb(
    _______, EF_DEC,  EF_INC,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,
    _______, _______, _______, _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                _______, _______,                            _______,                            _______, _______)
};
