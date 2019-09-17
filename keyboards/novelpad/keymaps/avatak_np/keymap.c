/*
Copyright 2018 Cole Markham

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layer_number {
    _BASE = 0,
    _RAISE, 
    _LOWER,
};

#define LOWZERO LT(_LOWER,KC_P0)
#define RASEENT LT(_RAISE, KC_ENT)
#define SHFTTAB S(KC_TAB)

enum custom_keycodes {
    WK_RED = SAFE_RANGE,
    WK_GREEN,
    WK_BLUE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_NLCK, KC_PSLS, KC_PAST, KC_BSPC,
        KC_P7  , KC_P8  , KC_P9  , KC_PMNS,
        KC_P4  , KC_P5  , KC_P6  , KC_PPLS,
        KC_P1  , KC_P2  , KC_P3  , KC_TAB ,
        LOWZERO, KC_COMM, KC_PDOT, RASEENT
    ),


    [_LOWER] = LAYOUT(
        _______, _______, _______, RESET  ,
        _______, KC_PGUP, _______, _______,
        KC_HOME, KC_PGDN, KC_END , SHFTTAB,
        _______, _______, _______, KC_TAB ,
        _______, _______, _______, _______
    ),

    [_RAISE] = LAYOUT(
        _______, _______, _______, RESET  ,
        _______, _______, _______, _______,
        _______, KC_UP  , _______, _______,
        KC_LEFT, KC_DOWN, KC_RGHT, SHFTTAB,
        _______, _______, _______, _______
    ),

    [3] = LAYOUT(
        _______, BL_STEP, RGB_M_SW, RESET,
        RGB_TOG, RGB_MOD, RGB_M_P,  RGB_M_SN,
        RGB_HUI, RGB_SAI, RGB_VAI,  RGB_M_K,
        RGB_HUD, RGB_SAD, RGB_VAD,  RGB_M_X,
        _______, WK_RED,  WK_GREEN, WK_BLUE
    )
};

void keyboard_post_init_user(void) {
    rgblight_setrgb(0, 255, 0);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case WK_RED:
            if (record->event.pressed) {
                rgblight_show_solid_color(0xFF, 0x00, 0x00);
            } else {
                rgblight_show_solid_color(0xFF, 0xFF, 0xFF);
            }
            return false;
        case WK_GREEN:
            if (record->event.pressed) {
                rgblight_show_solid_color(0x00, 0xFF, 0x00);
            } else {
                rgblight_show_solid_color(0xFF, 0xFF, 0xFF);
            }
            return false;
        case WK_BLUE:
            if (record->event.pressed) {
                rgblight_show_solid_color(0x00, 0x00, 0xFF);
            } else {
                rgblight_show_solid_color(0xFF, 0xFF, 0xFF);
            }
            return false;
    }
    return true;
}
