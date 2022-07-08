/* Copyright 2021 Kyle McCreery
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

/*
  TODO
  [X] Just make the layers match the stupid thing again
  [X] tap-slash on rshift
  [X] comma/semicolon and period colon
  [ ] more cool rotary press stuff
  [ ] more cool rotary rotation stuff
  [ ] more cool oled stuff
*/

#include QMK_KEYBOARD_H

/*
 *  _                            _
 * | | _____ _   _  ___ ___   __| | ___  ___
 * | |/ / _ \ | | |/ __/ _ \ / _` |/ _ \/ __|
 * |   <  __/ |_| | (_| (_) | (_| |  __/\__ \
 * |_|\_\___|\__, |\___\___/ \__,_|\___||___/
 *           |___/
 */

enum layer_names {
    _DEF,
    _NAV,
    _SYM,
    _NUM,
    _FN,
};

/* Layer switchers */
#define NAV_SPC LT(_NAV, KC_SPC)
#define SYM_SPC LT(_SYM, KC_SPC)
#define NUM     MO(_NUM)
#define FN      MO(_FN)

/* Renames */
#define SFT_SLA SFT_T(KC_SLSH)

/* Shortcuts */
#define HOME    G(KC_LEFT)
#define END     G(KC_RGHT)
#define WORD_L  A(KC_LEFT)
#define WORD_R  A(KC_RGHT)
#define SS      G(S(KC_4))
#define SS_CLIP C(G(S(KC_4)))
#define TAB_L   G(S(KC_LBRC))
#define TAB_R   G(S(KC_RBRC))
#define DESK_L  C(KC_LEFT)
#define DESK_R  C(KC_RGHT)
#define SEARCH  G(KC_SPC)
#define EMOJI   C(G(KC_SPC))
#define MISSION C(KC_UP)
#define STEP_VU A(S(KC_VOLU))
#define STEP_VD A(S(KC_VOLD))

/* Custom keycodes */
enum custom_keycodes {
    FS_PASS = SAFE_RANGE,
    R_PRESS
};

/*
 *  _
 * | | __ _ _   _  ___ _ __ ___
 * | |/ _` | | | |/ _ \ '__/ __|
 * | | (_| | |_| |  __/ |  \__ \
 * |_|\__,_|\__, |\___|_|  |___/
 *          |___/
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEF] = LAYOUT_all(
                                                                                                                  R_PRESS,
      KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
      KC_ESC,           KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    XXXXXXX, KC_ENT,
      KC_LSFT, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,           SFT_SLA,
      KC_LCTL, KC_LALT, KC_LGUI,          NAV_SPC, NUM,              SYM_SPC,          KC_RGUI, FN,               KC_RCTL),

  [_NAV] = LAYOUT_all(
                                                                                                                  _______,
      _______,          DESK_L,  DESK_R,  TAB_L,   TAB_R,   KC_VOLU, HOME,    WORD_L,  WORD_R,  END,     XXXXXXX, _______,
      _______,          KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_VOLD, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, _______,
      _______, XXXXXXX, SS,      SS_CLIP, KC_MPRV, KC_MNXT, KC_MPLY, XXXXXXX, MISSION, XXXXXXX, EMOJI,            SEARCH,
      _______, _______, _______,          _______, KC_SPC,           SEARCH,           _______, _______,          _______),

  [_SYM] = LAYOUT_all(
                                                                                                                  _______,
      _______,          KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_BSLS, KC_PIPE, _______,
      _______,          KC_PLUS, KC_EQL,  KC_MINS, KC_UNDS, KC_GRV,  KC_TILD, XXXXXXX, KC_QUOT, KC_DQUO, XXXXXXX, _______,
      _______, XXXXXXX, XXXXXXX, KC_LBRC, KC_LCBR, KC_LPRN, KC_LT,   KC_GT,   KC_RPRN, KC_RCBR, KC_RBRC,          KC_SLSH,
      _______, _______, _______,          _______, _______,          _______,          _______, _______,          _______),

  [_NUM] = LAYOUT_all(
                                                                                                                  _______,
      _______,          KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
      _______,          KC_SLSH, KC_ASTR, KC_MINS, KC_PLUS, XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX, _______,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,             _______,
      _______, _______, _______,          _______, _______,          KC_0,             KC_DOT,  _______,          _______),

  [_FN] = LAYOUT_all(
                                                                                                                  _______,
      QK_BOOT,          KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
      _______,          KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LALT,          _______,
      _______, _______, _______,          _______, _______,          _______,          _______, _______,          _______)
};

/* Blank diagram
                                                                                                                  _______,
      _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, _______,
      _______, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
      _______, _______, _______,          _______, _______,          _______,          _______, _______,          _______
*/

/*
 *                 _                    _             _
 *   ___ _   _ ___| |_ ___  _ __ ___   | | ___   __ _(_) ___
 *  / __| | | / __| __/ _ \| '_ ` _ \  | |/ _ \ / _` | |/ __|
 * | (__| |_| \__ \ || (_) | | | | | | | | (_) | (_| | | (__
 *  \___|\__,_|___/\__\___/|_| |_| |_| |_|\___/ \__, |_|\___|
 *                                              |___/
 */

bool type_password(keyrecord_t *record) {
    if (record->event.pressed) {
        // I know this is for real a bad idea, but whatever
        SEND_STRING("super_secret_password");
    }
    return true;
}

bool handle_rotary_encode_press(keyrecord_t *record, uint8_t mod_state) {
    // If shifted
    if (IS_LAYER_ON(_FN) && record->event.pressed) {
        // return type_password(record);
        if (record->event.pressed) {
            tap_code16(FS_PASS);
        }
    } else if (IS_LAYER_ON(_NAV) && record->event.pressed) {
        tap_code16(G(KC_W));
    } else if (mod_state & MOD_MASK_SHIFT) {
        if (record->event.pressed) {
            // Cancel the shift
            del_mods(MOD_MASK_SHIFT);
            tap_code16(SEARCH);
            // Re-enable the shift
            set_mods(mod_state);
        }
        return false;
    } else {
        // No mods
        if (record->event.pressed) {
            tap_code(KC_MPLY);
        }
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t mod_state = get_mods();
    switch (keycode) {
        case FS_PASS: {
            return type_password(record);
        }
        case KC_COMM: {
            if (mod_state & MOD_MASK_SHIFT) {
                if (record->event.pressed) {
                    del_mods(MOD_MASK_SHIFT);
                    tap_code(KC_SCLN);
                    set_mods(mod_state);
                }
                return false;
            }
            return true;
        }
        case KC_DOT: {
            if (mod_state & MOD_MASK_SHIFT) {
                if (record->event.pressed) {
                    // Sends a ':' since it's already shifted
                    tap_code(KC_SCLN);
                }
                return false;
            }
            return true;
        }
        case R_PRESS: {
            return handle_rotary_encode_press(record, mod_state);
        }
    }
    return true;
};

/*
 *            _                                              _
 *  _ __ ___ | |_ __ _ _ __ _   _    ___ _ __   ___ ___   __| | ___ _ __
 * | '__/ _ \| __/ _` | '__| | | |  / _ \ '_ \ / __/ _ \ / _` |/ _ \ '__|
 * | | | (_) | || (_| | |  | |_| | |  __/ | | | (_| (_) | (_| |  __/ |
 * |_|  \___/ \__\__,_|_|   \__, |  \___|_| |_|\___\___/ \__,_|\___|_|
 *                          |___/
 */

/* Rules:
 *
 *
 */

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    // TODO: GUI = cmd+tab
    // Shift / nav layer = GS[/]
    switch (index) {
        // Use first (and only) encoder
        case 0:
            // uint8_t mod_state = get_mods();
            if (IS_LAYER_ON(_NAV)) {
                // Nav layer: Tab switching
                if (clockwise)
                    tap_code16(TAB_R);
                else
                    tap_code16(TAB_L);
            } else {
                // Default: volume control
                if (clockwise)
                    tap_code16(STEP_VU);
                else
                    tap_code16(STEP_VD);
            }
            break;
    }
    return true;
}
#endif

/*
 *        _          _
 *   ___ | | ___  __| |
 *  / _ \| |/ _ \/ _` |
 * | (_) | |  __/ (_| |
 *  \___/|_|\___|\__,_|
 */

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
}

static void render_name(void) {
    static const char PROGMEM mercutio_name[] = {
        0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0x95, 0xB5, 0x96, 0xD5, 0xB6, 0xB6,
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };
    oled_write_P(mercutio_name, false);
}

bool oled_task_user(void) {
    render_name();
    return false;
}
#endif
