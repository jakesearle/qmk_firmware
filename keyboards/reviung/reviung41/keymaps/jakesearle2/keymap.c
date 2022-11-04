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
 *
 * TODO::
 * - Move towards 34 key layout
 * - Create a NUM lock under the shift key (TO doesn't work idk)
 * - Fix (semi)colon on norman layout
 */

#include QMK_KEYBOARD_H

enum layer_names {
    /* Main Layers */
    _QWERTY,
    _NORMAN,
    /* Specialty Layers */
    _ANKI,
    _GAMING,
    /* Secondary Layers */
    _NUM,
    _NAV,
    _SYM,
    _FN,
    /* Tertiary Layers */
    _ADJ
};

/*** Layers ***/
/* Main layers */
#define QWERTY DF(_QWERTY)
#define NORMAN DF(_NORMAN)
/* Specialty Layers */
#define ANKI   DF(_ANKI)
#define GAMING DF(_GAMING)
/* Secondary Layers */
#define SYM    MO(_SYM)
#define NUM    TT(_NUM)
#define NAV    MO(_NAV)
#define FN     MO(_FN)
/* Tertiary Layers */
#define ADJ    MO(_ADJ)

/* QWERTY Homerow Mods */
#define CTL_A CTL_T(KC_A)
#define OPT_S OPT_T(KC_S)
#define CMD_D CMD_T(KC_D)
#define SFT_F SFT_T(KC_F)
#define SFT_J SFT_T(KC_J)
#define CMD_K CMD_T(KC_K)
#define OPT_L OPT_T(KC_L)
#define CTL_QU CTL_T(KC_QUOT)
// #define CTL_SC  CTL_T(KC_SCLN)

/* Norman Botrow (Bottom-row) Mods */
#define CTL_Z CTL_T(KC_Z)
#define OPT_X OPT_T(KC_X)
#define CMD_C CMD_T(KC_C)
#define SFT_V SFT_T(KC_V)
#define SFT_M SFT_T(KC_M)
#define CMD_COM CMD_T(KC_COMM)
#define OPT_DOT OPT_T(KC_DOT)
#define CTL_SL CTL_T(KC_SLSH)

/* Shortcuts */
#define S_ENTR KC_SFTENT
#define HOME G(KC_LEFT)
#define END G(KC_RGHT)
#define WORD_L A(KC_LEFT)
#define WORD_R A(KC_RGHT)
#define SS_FULL G(S(KC_3))
#define SS G(S(KC_4))
#define SS_CLIP C(G(S(KC_4)))
#define TAB_L G(S(KC_LBRC))
#define TAB_R G(S(KC_RBRC))
#define DESK_L C(KC_LEFT)
#define DESK_R C(KC_RGHT)
#define SEARCH G(KC_SPC)
#define EMOJI C(G(KC_SPC))
#define MISSION C(KC_UP)

enum custom_keycodes {
    FS_PASS = SAFE_RANGE,
    A_UMLAU,
    O_UMLAU,
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  uint8_t mod_state = get_mods();
  switch (keycode) {
    case FS_PASS:
      if (record->event.pressed) {
        // I know this is for real a bad idea, but whatever
        SEND_STRING("password");
      }
      break;

    case A_UMLAU:
        if (record->event.pressed) {
            SEND_STRING(SS_LALT("u"));
            SEND_STRING("a");
        }
        break;

    case O_UMLAU:
        if (record->event.pressed) {
            SEND_STRING(SS_LALT("u"));
            SEND_STRING("o");
        }

    case KC_COMM:
      if (mod_state & MOD_MASK_SHIFT) {
        if (record->event.pressed) {
          del_mods(MOD_MASK_SHIFT);
          tap_code(KC_SCLN);
          set_mods(mod_state);
        }
        return false;
      }
      break;

    case KC_DOT:
      if (mod_state & MOD_MASK_SHIFT) {
        if (record->event.pressed) {
          // Sends a ':' since it's already shifted
          tap_code(KC_SCLN);
        }
        return false;
      }
      break;
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_reviung41(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  CTL_A,   OPT_S,   CMD_D,   SFT_F,   KC_G,             KC_H,    SFT_J,   CMD_K,   OPT_L,   CTL_QU,  KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                        NUM,     NAV,     KC_SPC,  SYM,     FN),
  [_NORMAN] = LAYOUT_reviung41(
    KC_TAB,  KC_Q,    KC_W,    KC_D,    KC_F,    KC_K,             KC_J,    KC_U,    KC_R,    KC_L,    KC_SCLN, KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_E,    KC_T,    KC_G,             KC_Y,    KC_N,    KC_I,    KC_O,    KC_H,    KC_QUOT,
    KC_LSFT, CTL_Z,   OPT_X,   CMD_C,   SFT_V,   KC_B,             KC_P,    SFT_M,   CMD_COM, OPT_DOT, CTL_SL,  S_ENTR,
                                        NUM,     NAV,     KC_SPC,  SYM,     FN),
  [_ANKI] = LAYOUT_reviung41(
    KC_TAB,  KC_1,    KC_2,    KC_3,    KC_4,    _______,          _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_BSPC,
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    _______,          _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_ENT,
    KC_LSFT, KC_1,    KC_2,    KC_3,    KC_4,    _______,          _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_RSFT,
                                        NUM,     NAV,     KC_SPC,  SYM,     FN),
  [_GAMING] = LAYOUT_reviung41(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                        NUM,     NAV,     KC_SPC,  SYM,     FN),
  [_NUM] = LAYOUT_reviung41(
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, XXXXXXX,          XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX, _______,
    _______, KC_SLSH, KC_ASTR, KC_MINS, KC_PLUS, XXXXXXX,          XXXXXXX, KC_1,    KC_2,    KC_3,    XXXXXXX, _______,
                                        _______, NAV,     KC_SPC,  KC_0,    KC_DOT),
  [_NAV] = LAYOUT_reviung41(
    _______, DESK_L,  DESK_R,  TAB_L,   TAB_R,   KC_VOLU,          HOME,    WORD_L,  WORD_R,  END,     KC_PGUP, _______,
    _______, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, KC_VOLD,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PGDN, _______,
    KC_CAPS, SS_CLIP, SS,      KC_MPRV, KC_MNXT, KC_MPLY,          XXXXXXX, MISSION, XXXXXXX, EMOJI,   SEARCH,  _______,
                                        NUM,     _______, KC_SPC,  ADJ,     FN),
  [_SYM] = LAYOUT_reviung41(
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,          KC_CIRC, KC_AMPR, KC_ASTR, KC_BSLS, KC_PIPE, _______,
    _______, KC_PLUS, KC_EQL,  KC_MINS, KC_UNDS, A_UMLAU,          O_UMLAU, KC_LSFT, KC_LCMD, KC_LOPT, KC_LCTL, _______,
    _______, KC_GRV,  KC_LBRC, KC_LCBR, KC_LPRN, KC_LT,            KC_GT,   KC_RPRN, KC_RCBR, KC_RBRC, KC_TILD, _______,
                                        NUM,     ADJ,     KC_SPC,  _______, FN),
  [_FN] = LAYOUT_reviung41(
    _______, KC_F12,  KC_F7,   KC_F8,   KC_F9,   XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,
    _______, KC_F11,  KC_F4,   KC_F5,   KC_F6,   XXXXXXX,          XXXXXXX, KC_LSFT, KC_LCMD, KC_LOPT, KC_LCTL, _______,
    _______, KC_F10,  KC_F1,   KC_F2,   KC_F3,   XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                        NUM,     NAV,     KC_SPC,  SYM,     _______),
  [_ADJ] = LAYOUT_reviung41(
    _______, QWERTY,  _______, _______, RESET,   _______,          _______, _______, _______, _______, FS_PASS, _______,
    _______, ANKI,    _______, _______, _______, GAMING,           _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, RGB_TOG,          NORMAN,  _______, _______, _______, _______, _______,
                                        _______, _______, _______, _______, _______)
};

const rgblight_segment_t PROGMEM capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS({10, 1, HSV_WHITE});

const rgblight_segment_t PROGMEM num_layer[] = RGBLIGHT_LAYER_SEGMENTS({10, 1, HSV_BLUE});

const rgblight_segment_t PROGMEM nav_layer[] = RGBLIGHT_LAYER_SEGMENTS({10, 1, HSV_CYAN});

const rgblight_segment_t PROGMEM sym_layer[] = RGBLIGHT_LAYER_SEGMENTS({10, 1, HSV_SPRINGGREEN});

const rgblight_segment_t PROGMEM fun_layer[] = RGBLIGHT_LAYER_SEGMENTS({10, 1, HSV_GREEN});

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(capslock_layer, num_layer, nav_layer, sym_layer, fun_layer);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
  rgblight_set_layer_state(0, led_state.caps_lock);
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(_NUM - 3, layer_state_cmp(state, _NUM));
  rgblight_set_layer_state(_NAV - 3, layer_state_cmp(state, _NAV));
  rgblight_set_layer_state(_SYM - 3, layer_state_cmp(state, _SYM));
  rgblight_set_layer_state(_FN - 3, layer_state_cmp(state, _FN));
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
        7, _______, _______, _______, _______, _______, [10]     _______, _______, _______, _______, _______,        2,
  _______, _______, _______,       6, _______, _______,          _______, _______,       3, _______, _______, _______,
                                      _______,       5, _______,       4, _______
*/
