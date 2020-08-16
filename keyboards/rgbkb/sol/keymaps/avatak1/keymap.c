#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif

#include "avatak.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
   * ,------------------------------------------------.  ,------------------------------------------------.
   * | GESC |   1  |   2  |   3  |   4  |   5  |   -  |  |   =  |   6  |   7  |   8  |   9  |   0  | BkSp |
   * |------+------+------+------+------+------|------|  |------|------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   [  |  |   ]  |   Y  |   U  |   I  |   O  |   P  |   \  |
   * |------+------+------+------+------+------|------|  |------|------+------+------+------+------+------|
   * |FN(CAPS)| A  |   S  |   D  |   F  |   G  |   (  |  |   )  |   H  |   J  |   K  |   L  |   ;  |   '  |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
   * |Shift |   Z  |   X  |   C  |   V  |   B  |   {  |  |   }  |   N  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
   * | Ctrl |  Win |  Alt |  RGB | ADJ  | Space| DEL  | | Enter| Space|  FN  | Left | Down | Up   |Right |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------'
   *                                    | Space| DEL  |  | Enter| Space|
   *                                    `-------------'  `-------------'
   */
  [_CLMK] = LAYOUT_wrapper( \
        KC_GRV , __NUM_L____________________________________, _______,   _______, __NUM_R____________________________________, KC_BSPC, \
        KC_TAB , __CLMK_L1__________________________________, _______,   _______, __CLMK_R1__________________________________, KC_BSLS, \
        NAVESC , __CLMK_L2__________________________________, XXXXXXX,   XXXXXXX, __CLMK_R2__________________________________, KC_QUOT, \
        KC_LSFT, __CLMK_L3__________________________________, XXXXXXX,   XXXXXXX, __CLMK_R3__________________________________, KC_RSFT, \
        ADJUST , KC_LCTL, KC_LGUI, KC_LALT, _______, NAVSPC , NUMTAP ,   SYMENT , TEXSPC , _______, CTLSHFT, ALTCTL , ALTSHFT, MO(_MEDIA)  , \
                                                     NAVSPC , NUMTAP ,   SYMENT , TEXSPC \
    ),

  [_NAV] = LAYOUT_wrapper( \
        _______, __NAV_L0___________________________________, _______,   _______, _______, _______, _______, _______, _______, _______, \
        _______, __NAV_L1___________________________________, _______,   _______, __NAV_R1___________________________________, _______, \
        _______, __NAV_L2___________________________________, XXXXXXX,   XXXXXXX, __NAV_R2___________________________________, KC_APP , \
        _______, __NAV_L3___________________________________, XXXXXXX,   XXXXXXX, __NAV_R3___________________________________, _______, \
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, KC_F12 , \
                                                     _______, _______,   _______, _______ \
    ),

    [_TEX] = LAYOUT_wrapper( \
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, \
        _______, __TEX_L1___________________________________, _______,   _______, __TEX_R1___________________________________, _______, \
        _______, __TEX_L2___________________________________, XXXXXXX,   XXXXXXX, __TEX_R2___________________________________, _______, \
        _______, __TEX_L3___________________________________, XXXXXXX,   XXXXXXX, __TEX_R3___________________________________, _______, \
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, \
                                                     _______, _______,   _______, _______ \
    ),

    [_SYM] = LAYOUT_wrapper( \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, __SYM_L1___________________________________, _______, _______, __SYM_R1___________________________________, KC_F11 , \
        KC_TILD, __SYM_L2___________________________________, XXXXXXX, XXXXXXX, __SYM_R2___________________________________, KC_F12 , \
        KC_GRV , __SYM_L3___________________________________, XXXXXXX, XXXXXXX, __SYM_R3___________________________________, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                                                     _______, _______, _______, _______ \
    ),

    [_NUM] = LAYOUT_wrapper( \
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, __NP_0____________________________, \
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, __NP_1____________________________, \
        _______, _______, _______, _______, _______, _______, XXXXXXX,   XXXXXXX, _______, _______, __NP_2____________________________, \
        _______, _______, _______, _______, _______, _______, XXXXXXX,   XXXXXXX, _______, _______, __NP_3____________________________, \
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, __NP_4____________________________, \
                                                     _______, _______,   _______, _______ \
    ),

    [_MEDIA] = LAYOUT_wrapper( \
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, XXXXXXX,   XXXXXXX, _______, _______, KC_MPLY, KC_VOLU, _______, _______, \
        _______, _______, _______, _______, _______, _______, XXXXXXX,   XXXXXXX, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT, _______, \
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, KC_MUTE, _______, _______, \
                                                     _______, _______,   _______, _______ \
    ),

    [_ADJ] = LAYOUT_wrapper( \
        RESET  , _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, \
        _______, __ADJ_L1___________________________________, _______,  _______, __ADJ_R1___________________________________, _______, \
        _______, __ADJ_L2___________________________________, XXXXXXX,  XXXXXXX, __ADJ_R2___________________________________, _______, \
        _______, __ADJ_L3___________________________________, XXXXXXX,  XXXXXXX, __ADJ_R3___________________________________, _______, \
        _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, \
                                                     _______, _______,  _______, _______ \
    )
};
