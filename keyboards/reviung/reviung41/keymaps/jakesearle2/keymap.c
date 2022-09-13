/* Copyright 2020 gtips
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
 *
 * Compile: $qmk compile --keyboard reviung41 --keymap jakesearle2
 * Flash: $qmk flash --keyboard reviung41 --keymap jakesearle2
 */

#include QMK_KEYBOARD_H

enum layer_names {
    _QWERTY,
    _NUM,
    _NAV,
    _SYM,
    _FN,
};

/* Default layers */
#define QWERTY DF(_)
#define COLEMAK M(_COLEMAK)

/* Layers */
#define SYM     MO(_SYM)
#define NUM     MO(_NUM)
#define NAV     MO(_NAV)
#define FN      MO(_FN)

/* QWERTY Homerow Mods */
#define CTL_A   CTL_T(KC_A)
#define OPT_S   OPT_T(KC_S)
#define CMD_D   CMD_T(KC_D)
#define SFT_F   SFT_T(KC_F)
#define SFT_J   SFT_T(KC_J)
#define CMD_K   CMD_T(KC_K)
#define OPT_L   OPT_T(KC_L)
#define CTL_SC  CTL_T(KC_SCLN)

/* Shortcuts */
#define S_ENTR  KC_SFTENT
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

enum custom_keycodes {
    FS_PASS = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case FS_PASS:
        if (record->event.pressed) {
            // I know this is for real a bad idea, but whatever
            SEND_STRING("password");
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_reviung41(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_ESC,  CTL_A,   OPT_S,   CMD_D,   SFT_F,   KC_G,             KC_H,    SFT_J,   CMD_K,   OPT_L,   CTL_SC,  KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, S_ENTR,
                                            NUM,     NAV,     KC_SPC,  SYM,     FN),
    [_NUM] = LAYOUT_reviung41(
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, XXXXXXX,          KC_PLUS, KC_4,    KC_5,    KC_6,    KC_MINS, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          KC_ASTR, KC_1,    KC_2,    KC_3,    KC_SLSH, _______,
                                            _______, NAV,     KC_SPC,  KC_0,    KC_DOT),
    [_NAV] = LAYOUT_reviung41(
        _______, DESK_L,  DESK_R,  TAB_L,   TAB_R,   KC_VOLU,          HOME,    WORD_L,  WORD_R,  END,     KC_PGUP, _______,
        _______, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, KC_VOLD,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PGDN, _______,
        KC_CAPS, SS_CLIP, SS,      KC_MPRV, KC_MNXT, KC_MPLY,          XXXXXXX, MISSION, XXXXXXX, EMOJI,   SEARCH,  _______,
                                            NUM,     _______, KC_SPC,  SYM,     FN),
    [_SYM] = LAYOUT_reviung41(
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,          KC_CIRC, KC_AMPR, KC_ASTR, KC_BSLS, KC_PIPE, _______,
        _______, KC_PLUS, KC_EQL,  KC_MINS, KC_UNDS, XXXXXXX,          XXXXXXX, KC_LSFT, KC_LCMD, KC_LOPT, KC_LCTL, _______,
        _______, KC_GRV,  KC_LBRC, KC_LCBR, KC_LPRN, KC_LT,            KC_GT,   KC_RPRN, KC_RCBR, KC_RBRC, KC_TILD, _______,
                                            NUM,     NAV,     KC_SPC,  _______, FN),
    [_FN] = LAYOUT_reviung41(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
        _______, KC_F11,  KC_F12,  XXXXXXX, FS_PASS, XXXXXXX,          XXXXXXX, KC_LSFT, KC_LCMD, KC_LOPT, KC_LCTL, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                            NUM,     NAV,     KC_SPC,  SYM,     _______)

};

const rgblight_segment_t PROGMEM capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {10, 1, HSV_WHITE}
);

const rgblight_segment_t PROGMEM num_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {10, 1, HSV_BLUE}
);

const rgblight_segment_t PROGMEM nav_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {10, 1, HSV_CYAN}
);

const rgblight_segment_t PROGMEM sym_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {10, 1, HSV_SPRINGGREEN}
);

const rgblight_segment_t PROGMEM fun_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {10, 1, HSV_GREEN}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    capslock_layer,
    num_layer,
    nav_layer,
    sym_layer,
    fun_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(_NUM, layer_state_cmp(state, _NUM));
    rgblight_set_layer_state(_NAV, layer_state_cmp(state, _NAV));
    rgblight_set_layer_state(_SYM, layer_state_cmp(state, _SYM));
    rgblight_set_layer_state(_FN, layer_state_cmp(state, _FN));
    return state;
}

/* Blank Grid
        _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______, _______, _______
*/

/* RGB locations
 * If you're looking at the board from the back, this is roughly where the RGB
 * locations are, except for the middle LED, which is on the top of the board
    _______, _______,       8, _______,       9, _______,          _______,       0, _______,       1, _______, _______,
          7, _______, _______, _______, _______, _______,   [10]   _______, _______, _______, _______, _______,        2,
    _______, _______, _______,       6, _______, _______,          _______, _______,       3, _______, _______, _______,
                                        _______,       5, _______,       4, _______
*/
