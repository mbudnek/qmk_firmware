/* Copyright 2021 @ Keychron (https://www.keychron.com)
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

// clang-format off

enum layers{
  MAC_BASE,
  MAC_FN,
  WIN_BASE,
  WIN_FN
};

enum custom_keycodes {
    KC_SIRI = SAFE_RANGE,
    KC_KVM1,
    KC_KVM2,
    // Key Chords; keys will all be pressed, then all released
    KC_CHORDS_START,
    KC_TASK_VIEW,
    KC_FILE_EXPLORER,
    KC_SCREEN_SHOT,
    KC_CORTANA,
    KC_MUTE_MIC_MAC,
    KC_MUTE_MIC_WIN,
    KC_CHORDS_END
};

#define KC_TASK KC_TASK_VIEW
#define KC_FLXP KC_FILE_EXPLORER
#define KC_SNAP KC_SCREEN_SHOT
#define KC_CRTA KC_CORTANA
#define KC_MMM  KC_MUTE_MIC_MAC
#define KC_MMW  KC_MUTE_MIC_WIN

typedef struct PACKED {
    uint8_t len;
    uint8_t keycode[3];
} key_combination_t;

const key_combination_t key_chord_list[] = {
    {2, {KC_LWIN, KC_TAB}},
    {2, {KC_LWIN, KC_E}},
    {3, {KC_LSFT, KC_LCMD, KC_4}},
    {2, {KC_LWIN, KC_C}},
    {3, {KC_LCMD, KC_LSFT, KC_M}},
    {3, {KC_LCTL, KC_LSFT, KC_M}}
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_108(
        KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_SNAP,  KC_SCRL,  KC_PAUS,  KC_KVM1,  KC_MMM,   KC_VOLD,  KC_VOLU,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,  KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,  KC_P7,    KC_P8,    KC_P9,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,                                 KC_P4,    KC_P5,    KC_P6,    KC_PPLS,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,            KC_UP,              KC_P1,    KC_P2,    KC_P3,
        KC_LCTL,  KC_LCMD,  KC_LOPT,                                KC_SPC,                                 KC_ROPT,  KC_RCMD,  MO(MAC_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,              KC_PDOT,  KC_PENT),
    [MAC_FN] = LAYOUT_ansi_108(
        _______,            KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  KC_SIRI,  _______,  KC_F13,   KC_F14,   KC_F15,   KC_F16,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,                                _______,  _______,  _______,  _______,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,            _______,            _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  KC_MPRV,  KC_MPLY,  KC_MNXT,  _______,            _______,  _______),
    [WIN_BASE] = LAYOUT_ansi_108(
        KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_PSCR,  KC_SCRL,  KC_PAUS,  KC_KVM2,  KC_MMW,   KC_VOLD,  KC_VOLU,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,  KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,  KC_P7,    KC_P8,    KC_P9,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,                                 KC_P4,    KC_P5,    KC_P6,    KC_PPLS,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,            KC_UP,              KC_P1,    KC_P2,    KC_P3,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RWIN,  MO(WIN_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,              KC_PDOT,  KC_PENT),
    [WIN_FN] = LAYOUT_ansi_108(
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,                                _______,  _______,  _______,  _______,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,            _______,            _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  KC_MPRV,  KC_MPLY,  KC_MNXT,  _______,            _______,  _______),
};

// clang-format on

static uint32_t time;

void matrix_scan_user(void) {
    if (time && sync_timer_elapsed32(time) >= 500) {
        time = 0;
        unregister_code(KC_LCMD);
        unregister_code(KC_SPACE);
    }
}

static const uint8_t SCROLL_LOCK_LED_INDEX = 14;
static const uint8_t NUM_LOCK_LED_INDEX = 37;
static const uint8_t N_KEY_LED_INDEX = 84;

bool rgb_matrix_indicators_user(void) {
    bool num_lock = host_keyboard_led_state().num_lock;
    if (IS_LAYER_ON_STATE(default_layer_state, MAC_BASE)) {
        num_lock = true;
    }
    if (!num_lock) {
        rgb_matrix_set_color(NUM_LOCK_LED_INDEX, 255, 255, 255);
    }

    if (host_keyboard_led_state().scroll_lock) {
        rgb_matrix_set_color(SCROLL_LOCK_LED_INDEX, 255, 255, 255);
    }
    if (!keymap_config.nkro) {
        rgb_matrix_set_color(N_KEY_LED_INDEX, 255, 255, 255);
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch(get_highest_layer(state)) {
    case 0:
        default_layer_state_set_kb(default_layer_state);
        break;
    case MAC_FN:
        rgb_matrix_sethsv_noeeprom(150, 255, 255);
        break;
    case WIN_FN:
        rgb_matrix_sethsv_noeeprom(10, 255, 255);
        break;
    }
    return state;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    switch(get_highest_layer(state)) {
    case MAC_BASE:
        rgb_matrix_sethsv_noeeprom(130, 255, 255);
        break;
    case WIN_BASE:
        rgb_matrix_sethsv_noeeprom(15, 255, 255);
        break;
    }
    return state;
}

void kvm_switch_to(uint8_t index, enum layers layer) {
    bool nkro = keymap_config.nkro;
    keymap_config.nkro = false;
    tap_code(KC_SCRL);
    tap_code(KC_SCRL);
    tap_code(index);
    tap_code(KC_NUM);
    tap_code(KC_NUM);
    keymap_config.nkro = nkro;
    default_layer_set(1 << layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MISSION_CONTROL:
            if (record->event.pressed) {
                host_consumer_send(0x29F);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LAUNCHPAD:
            if (record->event.pressed) {
                host_consumer_send(0x2A0);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_SIRI:
            if (record->event.pressed && time == 0) {
                register_code(KC_LCMD);
                register_code(KC_SPACE);
                time = sync_timer_read32();
            } else {
                // Do something else when release
            }
            return false;  // Skip all further processing of this key
        case KC_KVM1:
            if (!record->event.pressed) {
                kvm_switch_to(KC_1, WIN_BASE);
            }
            return false;
        case KC_KVM2:
            if (!record->event.pressed) {
                kvm_switch_to(KC_2, MAC_BASE);
            }
            return false;
        case KC_CHORDS_START ... KC_CHORDS_END:
        {
            const key_combination_t* key_comb = &key_chord_list[keycode - (KC_CHORDS_START + 1)];
            if (record->event.pressed) {
                for (uint8_t i = 0; i < key_comb->len; i++) {
                    register_code(key_comb->keycode[i]);
                }
            } else {
                for (uint8_t i = 0; i < key_comb->len; i++) {
                    unregister_code(key_comb->keycode[i]);
                }
            }
            return false;  // Skip all further processing of this key
        }
        default:
            return true;  // Process all other keycodes normally
    }
}
