#include QMK_KEYBOARD_H
// #include "bootloader.h"

#ifdef PROTOCOL_LUFA
    #include "lufa.h"
    #include "split_util.h"
#endif

#include "avatak.h"
#define ADJ2 TO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 /* Colemak Mod-DH (Base layer)
   * ,--------------------------------------------------------------.      ,--------------------------------------------------------------.
   * |   `    |   1    |    2   |    3   |   4    |   5    | Insert |      | Pgup   |    6   |    7   |   8    |    9   |   0    | Bspace |
   * |--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
   * | Tab    |   Q    |    W   |    F   |   P    |   B    | Caps   |      | Pgdn   |    J   |    L   |    U   |    Y   |GUI_T(;)|   \    |
   * |--------+--------+--------+--------+--------+--------+--------'      `--------+--------+--------+--------+--------+--------+--------|
   * |Esc/Nav |   A    |    R   |    S   |   T    |   G    | ,----.          ,----. |    K   |    N   |    E   |    I   |    O   |   '    |
   * |--------+--------+--------+--------+--------+--------| |OLED|          |OLED| |--------+--------+--------+--------+--------+--------|
   * | Shift  |   Z    |    X   |    C   |   D    |   V    | |    |          |    | |    M   |    H   |    ,   |    .   |CTL_T(/)| Shift  |
   * |--------+--------+--------+--------+--------+--------' `----'          `----' `--------+--------+--------+--------+--------+--------|
   * | Adjust |  Ctrl  |  Gui   |  Alt   |        | ,-----------.              ,-----------. |        |        |        |Sft(Alt)| Media  |
   * `--------+--------+--------+--------+--------' |     |     |              |     |     | `--------------------------------------------'
   *                                                |Space|TT(  |              |Space|Space|
   *            <---Up--- ___ --Down-->             |  /  |_NUM)|              |  /  |  /  |        <--Left--  ___  --Right->
   *                     /   \                      |_NAV |     |              |_SYM |_TEX |                  /   \
   *                     \___/                      `-----------'              `-----------'                  \___/
   */

 [_COLEMAK] = LAYOUT_wrapper( \
      KC_GRV , __NUMBER_L_________________________________, KC_INS ,       _______, __NUMBER_R_________________________________, KC_BSPC, \
      KC_TAB , __COLEMAK_L1_______________________________, KC_CAPS,      TG(_NUM), __COLEMAK_R1_______________________________, KC_BSLS, \
      NAVESC , __COLEMAK_L2_______________________________, XXXXXXX,       XXXXXXX, __COLEMAK_R2_______________________________, KC_QUOT, \
      KC_LSFT, __COLEMAK_L3_______________________________, XXXXXXX,       XXXXXXX, __COLEMAK_R3_______________________________, KC_RSFT, \
      ADJUST , KC_LCTL, KC_LGUI, KC_LALT,LCTL(KC_O), NAVSPC, MO(_i3),     SYMENT ,  TEXSPC, LGUI(KC_TAB), KC_HYPR, S(KC_RALT),LCTL(KC_RALT), MEDIA, \
                                                     NAVSPC, MO(_i3),     SYMENT ,  TEXSPC \
  ),\

  /* _NAV (Navigation layer)
   * ,--------------------------------------------------------------.      ,--------------------------------------------------------------.
   * |        |        |        |        |Alt+F4  |        |        |      |        |        |        |        |        |        |        |
   * |--------+--------+--------+--------+--------+--------+--------|      |--------+------+-----------+-------+--------+--------+--------|
   * |        |        |Ctl+PgDn| PgUp   |Ctl+PgUp|        |        |      |        |      |Ctl+Sft+Tab| Up    |Ctl+Tab |        |        |
   * |--------+--------+--------+--------+--------+--------+--------'      `--------+------+-----------+-------+--------+--------+--------|
   * |        |        |  Home  | PgDn   | End    |        | ,----.          ,----. |        | Left   | Down   | Right  |        |        |
   * |--------+--------+--------+--------+--------+--------| |OLED|          |OLED| |--------+--------+--------+--------+--------+--------|
   * | Mouse  |        |        | Caps   | Insert |        | |    |          |    | |        |        |        |        |        |        |
   * |--------+--------+--------+--------+--------+--------' `----'          `----' `--------+--------+--------+--------+--------+--------|
   * |        |        |        |        |        | ,-----------.              ,-----------. |        |        |        |        |        |
   * `--------+--------+--------+--------+--------' |     |     |              |     |     | `--------------------------------------------'
   *                                                |     |     |              |     |Enter|
   *      <--Shift+Tab--  ___ ----Tab---->          |     |     |              |     |     |        <--PgUp--  ___  --PgDn-->
   *                     /   \                      |     |     |              |     |     |                  /   \
   *                     \___/                      `-----------'              `-----------'                  \___/
   */

  [_NAV] =  LAYOUT_wrapper( \
      _______, _______, _______, _______, WINQUIT, _______, _______, _______, _______, _______, _______, _______, _______, _______,\
      _______, __NAV_L1___________________________________, _______, _______, __NAV_R1___________________________________, S(LCTL(LALT(KC_S))),
      _______, __NAV_L2___________________________________, _______, _______, __NAV_R2___________________________________, KC_APP ,\
      _______, __NAV_L3___________________________________, _______, _______, __NAV_R3___________________________________, _______,\
      ADJ2   , _______, _______, _______, _______, _______, _______, _______, KC_ENT,  _______, _______, _______, _______, KC_F12,\
                                                   _______, _______, _______, KC_ENT \
      ),


  /* _TEX (Macros and useful keys for LaTeX)
   * ,--------------------------------------------------------------.      ,--------------------------------------------------------------.
   * |        |   F1   |  F2    |  F3    |  F4    |  F5    |        |      |        |  F6    |  F7    |  F8    |  F9    |  F10   |  F11   |
   * |--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
   * |        | Section| Enum.  |Itemize |\lft\rgt|        |        |      |        |        |   [    |   ]    |LineMath|DispMath|  F12   |
   * |--------+--------+--------+--------+--------+--------+--------'      `--------+--------+--------+--------+--------+--------+--------|
   * |        | Align* | Array  |        | \item  |        | ,----.          ,----. |        |   {    |   }    |   (    |   )    |        |
   * |--------+--------+--------+--------+--------+--------| |OLED|          |OLED| |--------+--------+--------+--------+--------+--------|
   * |        | Lemma  |Theorem |        |        |        | |    |          |    | |    -   |   _    |   +    |   =    |   \    |        |
   * |--------+--------+--------+--------+--------+--------' `----'          `----' `--------+--------+--------+--------+--------+--------|
   * |        |        |        |        |        | ,-----------.              ,-----------. |        |        |        |        |        |
   * `--------+--------+--------+--------+--------' |     |MO(  |              |     |     | `--------------------------------------------'
   *                                                |     |_SYM |              |     |     |
   *            <--Undo-- ___ --Redo-->             |     |   ) |              |     |     |        <--------  ___  -------->
   *                     /   \                      |     |     |              |     |     |                  /   \
   *                     \___/                      `-----------'              `-----------'                  \___/
   */

  [_TEX] =  LAYOUT_wrapper( \
      _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , _______, _______, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,\
      _______, __TEX_L1___________________________________, _______, _______, __TEX_R1___________________________________, KC_F12 ,\
      _______, __TEX_L2___________________________________, _______, _______, __TEX_R2___________________________________, KC_APP ,\
      _______, __TEX_L3___________________________________, _______, _______, __TEX_R3___________________________________, _______,\
      _______, _______, _______, _______, _______, MO(_SYM), _______, _______, _______, _______, _______, _______, _______, _______,\
                                                   MO(_SYM), _______, _______, _______\
      ),


  /* _SYM (Symbols, Numbers, and F Row)
   * ,----------------------------------------------------------:: Running post-transaction hooks...
(1/1) Arming ConditionNeedsUpdate...
❯ vim
❯ R
zsh: command not found: R
❯ cd qmk_firmware
❯ ls
bin                 common_features.mk  lib                      readme.md                       tests
book.json           common.mk           LICENSE                  requirements-dev.txt            tmk_core
bootloader.mk       Dockerfile          license_GPLv2.md         requirements.txt                users
build_full_test.mk  docs                license_GPLv3.md         rgbkb_sol_rev1_avatak_rev1.hex  util
build_json.mk       Doxyfile            license_Modified_BSD.md  secrets.tar.enc                 Vagrantfile
build_keyboard.mk   doxygen-todo        Makefile                 setup.cfg
build_layout.mk     drivers             message.mk               shell.nix
build_test.mk       keyboards           nose2.cfg                show_options.mk
CODE_OF_CONDUCT.md  layouts             quantum                  testlist.mk
---.      ,--------------------------------------------------------------.
   * |        |   F1   |  F2    |  F3    |  F4    |  F5    |        |      |        |  F6    |  F7    |  F8    |  F9    |  F10   |  F11   |
   * |--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
   * |        |   F1   |  F2    |  F3    |  F4    |  F5    |        |      |        |  F6    |  F7    |  F8    |  F9    |  F10   |  F12   |
   * |--------+--------+--------+--------+--------+--------+--------'      `--------+--------+--------+--------+--------+--------+--------|
   * |   ~    |   !    |   @    |   #    |   $    |   %    | ,----.          ,----. |   ^    |  &     |   *    |   (    |   )    |        |
   * |--------+--------+--------+--------+--------+--------| |OLED|          |OLED| |--------+--------+--------+--------+--------+--------|
   * |   `    |   1    |   2    |   3    |   4    |   5    | |    |          |    | |   6    |  7     |   8    |   9    |   0    |        |
   * |--------+--------+--------+--------+--------+--------' `----'          `----' `--------+--------+--------+--------+--------+--------|
   * |        |        |        |        |        | ,-----------.              ,-----------. |        |        |        |        |        |
   * `--------+--------+--------+--------+--------' |     |     |              |     |     | `--------------------------------------------'
   *                                                |     |     |              |     |     |
   *            <-Enter-- ___ --Space-->            |     |     |              |     |     |      <--B-Space-  ___  --Delete-->
   *                     /   \                      |     |     |              |     |     |                  /   \
   *                     \___/                      `-----------'              `-----------'                  \___/
   */

  [_SYM] =  LAYOUT_wrapper( \
      _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , _______, _______, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,\
      _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , _______, _______, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
      KC_TILD, KC_EXLM,  KC_AT , KC_HASH, KC_DLR , KC_PERC, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_F12 ,
      KC_GRV , KC_1   ,  KC_2  , KC_3   , KC_4   , KC_5   , _______, _______, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,\
                                                   _______, _______, _______, _______\
      ),



  [_i3] = LAYOUT_wrapper( \
      _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______,\
      _______, _______, _______, _______, _______, _______, _______,        _______, _______, LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), _______, _______,\
      _______, _______, _______, _______, _______, _______, _______,        _______, _______, LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), _______, _______,\
      _______, _______, _______, _______, _______, _______, _______,        _______, _______, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), _______, _______,\
      _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______,\
                                                   _______, _______,        _______, _______\
      ),\





  /* Colemak Mod-DH (Base layer)
   * ,--------------------------------------------------------------.      ,--------------------------------------------------------------.
   * |        |        |        |        |        |        |        |      |        |        |        |NumLock |   *    |   /    | BSpace |
   * |--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
   * |        |        |        |        |        |        |        |      |        |        |        |   7    |   8    |   9    |   -    |
   * |--------+--------+--------+--------+--------+--------+--------'      `--------+--------+--------+--------+--------+--------+--------|
   * |        |        |        |        |        |        | ,----.          ,----. |        |        |   4    |   5    |   6    |   +    |
   * |--------+--------+--------+--------+--------+--------| |OLED|          |OLED| |--------+--------+--------+--------+--------+--------|
   * |        |        |        |        |        |        | |    |          |    | |        |        |   1    |   2    |   3    |   =    |
   * |--------+--------+--------+--------+--------+--------' `----'          `----' `--------+--------+--------+--------+--------+--------|
   * |        |        |        |        |        | ,-----------.              ,-----------. |        |   0    |   ,    |    .   |        |
   * `--------+--------+--------+--------+--------' |     |     |              |     |     | `--------------------------------------------'
   *                                                |     |     |              |     |     |
   *            <-------- ___ -------->             |     |     |              |     |     |        <--Left--  ___  --Right->
   *                     /   \                      |     |     |              |     |     |                  /   \
   *                     \___/                      `-----------'              `-----------'                  \___/
   */

  [_NUM] = LAYOUT_wrapper( \
      _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, KC_NLCK, KC_PAST, KC_PSLS, KC_BSPC,\
      _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, KC_P7  , KC_P8  , KC_P9  , KC_PMNS,\
      _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, KC_P4  , KC_P5  , KC_P6  , KC_PPLS,\
      _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, KC_P1  , KC_P2  , KC_P3  , KC_PEQL,\
      _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, KC_P0  , KC_COMM, KC_PDOT, KC_PENT,\
                                                   _______, _______,        _______, _______\
      ),\



  /* _MEDIA (Media controls)
   * ,--------------------------------------------------------------.      ,--------------------------------------------------------------.
   * |        |        |        |        |        |        |        |      |        |        |        |        |        |        | RESET  |
   * |--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
   * |        |        |        | VolUp  |        |        |        |      |        |        |        |        |        |        |        |
   * |--------+--------+--------+--------+--------+--------+--------'      `--------+--------+--------+--------+--------+--------+--------|
   * |        |        |M Prev. | VolDn  | M Next |        | ,----.          ,----. |        |        |        |        |        |        |
   * |--------+--------+--------+--------+--------+--------| |OLED|          |OLED| |--------+--------+--------+--------+--------+--------|
   * |        |        |        |        |        |        | |    |          |    | |        |        |        |        |        |        |
   * |--------+--------+--------+--------+--------+--------' `----'          `----' `--------+--------+--------+--------+--------+--------|
   * |        |        |        |        |        | ,-----------.              ,-----------. |        |        |        |        |        |
   * `--------+--------+--------+--------+--------' |     |     |              |     |     | `--------------------------------------------'
   *                                                |Mute |     |              |Stop |Play/|
   *          <-VolDown-- ___ --VolUp-->            |     |     |              |     |Pause|    <--Media-Prev- ___  --Media-Next->
   *                     /   \                      |     |     |              |     |     |                  /   \
   *                     \___/                      `-----------'              `-----------'                  \___/
   */

  [_MEDIA] = LAYOUT_wrapper( \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET  ,\
      _______, _______, _______, KC_VOLU, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,\
      _______, _______, KC_MPRV, KC_VOLD, KC_MNXT, _______, _______, _______, _______, _______, KC_MPLY, KC_VOLU, _______, _______,\
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT, _______,\
      _______, _______, _______, _______, _______, KC_MUTE, _______, KC_MSTP, KC_MPLY, KC_MPLY, _______, KC_MUTE, _______, _______,\
                                                   KC_MUTE, _______, KC_MSTP, KC_MPLY\
      ),\


  /* _ADJUST
   * ,--------------------------------------------------------------.      ,--------------------------------------------------------------.
   * | RESET  |        |        |        |        |        |        |      |        | Plain  | Swirl  |Gradient|        |        |RGBReset|
   * |--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
   * |        |        |        |        |        |        |        |      |        |        | Hue Dec| Val Up | Hue Inc|        |        |
   * |--------+--------+--------+--------+--------+--------+--------'      `--------+--------+--------+--------+--------+--------+--------|
   * |        |        |        |        |        |        | ,----.          ,----. |        | Sat Dn | Val Dn | Sat Up |        |        |
   * |--------+--------+--------+--------+--------+--------| |OLED|          |OLED| |--------+--------+--------+--------+--------+--------|
   * |        |        |        |        |        |        | |    |          |    | |        |        |        |        |        |        |
   * |--------+--------+--------+--------+--------+--------' `----'          `----' `--------+--------+--------+--------+--------+--------|
   * |        |        |        |        |        | ,-----------.              ,-----------. |        | RGB Tog|        |        |        |
   * `--------+--------+--------+--------+--------' |     |     |              |     |     | `--------------------------------------------'
   *                                                |     |     |              |     |     |
   *     <--RGB-Hue-Dec-- ___ --RGB-Hue-Inc-->      |     |     |              |     |     |  <--RGB-Prv-Mode- ___  --RGB-Next-Mode-->
   *                     /   \                      |     |     |              |     |     |                  /   \
   *                     \___/                      `-----------'              `-----------'                  \___/
   */

  [_ADJUST] =  LAYOUT_wrapper( \
      RESET  , _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, RGBRST ,\
      _______, RGB_TOG, _______, _______, _______, _______, _______,    _______, RGB_SPI, RGB_HUD, RGB_VAI, RGB_HUI, _______, _______,\
      _______, _______, _______, _______, _______, _______, _______,    _______, RGB_SPD, RGB_SAD, RGB_VAD, RGB_SAI, _______, _______,\
      _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,\
      _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, RGB_TOG, _______, _______, _______,\
                                                   _______, _______,    _______, _______
      )\



  /* Colemak Mod-DH (Base layer)
   * ,--------------------------------------------------------------.      ,--------------------------------------------------------------.
   * |        |        |        |        |        |        |        |      |        |        |        |        |        |        |        |
   * |--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
   * |        |        |        |        |        |        |        |      |        |        |        |        |        |        |        |
   * |--------+--------+--------+--------+--------+--------+--------'      `--------+--------+--------+--------+--------+--------+--------|
   * |        |        |        |        |        |        | ,----.          ,----. |        |        |        |        |        |        |
   * |--------+--------+--------+--------+--------+--------| |OLED|          |OLED| |--------+--------+--------+--------+--------+--------|
   * |        |        |        |        |        |        | |    |          |    | |        |        |        |        |        |        |
   * |--------+--------+--------+--------+--------+--------' `----'          `----' `--------+--------+--------+--------+--------+--------|
   * |        |        |        |        |        | ,-----------.              ,-----------. |        |        |        |        |        |
   * `--------+--------+--------+--------+--------' |     |     |              |     |     | `--------------------------------------------'
   *                                                |     |     |              |     |     |
   *            <---Up--- ___ --Down-->             |     |     |              |     |     |        <--Left--  ___  --Right->
   *                     /   \                      |     |     |              |     |     |                  /   \
   *                     \___/                      `-----------'              `-----------'                  \___/
   */



/*
  [16] = LAYOUT_wrapper( \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,\
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,\
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,\
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,\
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,\
                        _______, _______,          _______, _______, _______, _______,          _______, _______\
      )
*/
};


// For RGBRST Keycode
#if defined(RGB_MATRIX_ENABLE)
void rgb_matrix_increase_flags(void)
{
    switch (rgb_matrix_get_flags()) {
        case LED_FLAG_ALL: {
            rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER);
            rgb_matrix_set_color_all(0, 0, 0);
            }
            break;
        case LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER: {
            rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
            rgb_matrix_set_color_all(0, 0, 0);
            }
            break;
        case LED_FLAG_UNDERGLOW: {
            rgb_matrix_set_flags(LED_FLAG_NONE);
            rgb_matrix_disable_noeeprom();
            }
            break;
        default: {
            rgb_matrix_set_flags(LED_FLAG_ALL);
            rgb_matrix_enable_noeeprom();
            }
            break;
    }
}

void rgb_matrix_decrease_flags(void)
{
    switch (rgb_matrix_get_flags()) {
        case LED_FLAG_ALL: {
            rgb_matrix_set_flags(LED_FLAG_NONE);
            rgb_matrix_disable_noeeprom();
            }
            break;
        case LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER: {
            rgb_matrix_set_flags(LED_FLAG_ALL);
            rgb_matrix_set_color_all(0, 0, 0);
            }
            break;
        case LED_FLAG_UNDERGLOW: {
            rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER);
            rgb_matrix_set_color_all(0, 0, 0);
            }
            break;
        default: {
            rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
            rgb_matrix_enable_noeeprom();
            }
            break;
    }
}
#endif

#ifdef RGB_OLED_MENU
uint8_t rgb_encoder_state = 4;

typedef void (*rgb_matrix_f)(void);

const rgb_matrix_f rgb_matrix_functions[6][2] = {
    { rgb_matrix_increase_hue, rgb_matrix_decrease_hue },
    { rgb_matrix_increase_sat, rgb_matrix_decrease_sat },
    { rgb_matrix_increase_val, rgb_matrix_decrease_val },
    { rgb_matrix_increase_speed, rgb_matrix_decrease_speed },
    { rgb_matrix_step, rgb_matrix_step_reverse },
    { rgb_matrix_increase_flags, rgb_matrix_decrease_flags }
};
#endif

#ifdef ENCODER_ENABLE
    void encoder_update_user(uint8_t index, bool clockwise) {

// LEFT KNOB

        if (index == 0) {
            // NAV LAYER
            if (IS_LAYER_ON(_NAV)) {
                if (!clockwise) {
                    tap_code(KC_TAB);
                } else {
                    register_code(KC_LSFT);
                    tap_code(KC_TAB);
                    unregister_code(KC_LSFT);
                }
            }
            // TEX Layer
            else if (IS_LAYER_ON(_TEX)) {
                if (!clockwise) {
                    register_code(KC_LSFT);
                    register_code(KC_LCTL);
                    tap_code(KC_Z);
                    unregister_code(KC_LSFT);
                    unregister_code(KC_LCTL);
                }
                else {
                    register_code(KC_LCTL);
                    tap_code(KC_Z);
                    unregister_code(KC_LSFT);
                }
            }
            // ADJUST layer
            else if (IS_LAYER_ON(_ADJUST)) {
                if (!clockwise) {
                    rgblight_increase_hue();
                } else {
                    rgblight_decrease_hue();
                }
            }
            // MEDIA layer
            else if (IS_LAYER_ON(_ADJUST)) {
                if (!clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
            }
            // DEFAULT
            else {
                if (!clockwise) {
                    tap_code(KC_DOWN);
                } else {
                    tap_code(KC_UP);
                }
            }
        }

// RIGHT KNOB

    else if (index == 1) {
        //  NAV LAYER
        if (IS_LAYER_ON(_NAV)) {
            if (!clockwise) {
                tap_code(KC_PGDN);
            } else {
                tap_code(KC_PGUP);
            }
        }
        // Symbol layer
        else if (IS_LAYER_ON(_SYM)) {
            if (!clockwise) {
                tap_code(KC_SPC);
            } else {
                tap_code(KC_BSPC);
            }
        }
        // Adjust layer
        else if (IS_LAYER_ON(_ADJUST)) {
            if (!clockwise) {
                rgblight_step();
            } else {
                rgblight_step_reverse();
            }
        }
        // MEDIA layer
            else if (IS_LAYER_ON(_ADJUST)) {
                if (!clockwise) {
                    tap_code(KC_MNXT);
                } else {
                    tap_code(KC_MPRV);
                }
            }
        // DEFAULT
        else {
            if (!clockwise) {
                tap_code(KC_RGHT);
            } else {
                tap_code(KC_LEFT);
            }
        }
    }
  }
#endif
// OLED Driver Logic
#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master())
        return OLED_ROTATION_270;
    else if (!is_keyboard_master())
        return OLED_ROTATION_180;
    else
        return rotation;
}

// Render to mode icon
  static const char PROGMEM sol_icon[] = {
    0x9b,0x9c,0x9d,0x9e,0x9f,
    0xbb,0xbc,0xbd,0xbe,0xbf,
    0xdb,0xdc,0xdd,0xde,0xdf,0
  };


void render_layer_state(void) {
    oled_write_P(PSTR("\nLayer"), false);
    oled_write_P(PSTR("-----"), false);
    uint8_t layer = layer_state ? biton(layer_state) : biton32(default_layer_state);
    switch (layer) {
        case _COLEMAK:
            oled_write_P(PSTR("COLMK"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("  NAV"), false);
            break;
        case _TEX:
            oled_write_P(PSTR("LaTeX"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("SYMBL"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("NUMPD"), false);
            break;
        case _MOUSE:
            oled_write_P(PSTR("MOUSE"), false);
            break;
        case _MEDIA:
            oled_write_P(PSTR("MEDIA"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("ADJST"), false);
            break;
        default:
            oled_write_P(PSTR("UNDEF"), false);
        }
    oled_write_P(PSTR("\n"), false);
}

void render_keylock_status(uint8_t led_usb_state) {
    uint8_t led_state = host_keyboard_leds();
    oled_write_P(PSTR("Locks"), false);
    oled_write_P(PSTR("-----"), false);
    oled_write_P(IS_LED_ON(led_state, USB_LED_NUM_LOCK) ? PSTR("N") : PSTR(" "), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(IS_LED_ON(led_state, USB_LED_CAPS_LOCK) ? PSTR("C") : PSTR(" "), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(IS_LED_ON(led_state, USB_LED_SCROLL_LOCK) ? PSTR("S") : PSTR(" "), false);
}

void render_mod_status(uint8_t modifiers) {
    oled_write_P(PSTR("\nMods "), false);
    oled_write_P(PSTR("-----"), false);
    oled_write_P((modifiers & MOD_MASK_SHIFT) ? PSTR("S") : PSTR(" "), false);
    oled_write_P((modifiers & MOD_MASK_CTRL) ? PSTR("C") : PSTR(" "), false);
    oled_write_P((modifiers & MOD_MASK_ALT) ? PSTR("A") : PSTR(" "), false);
    oled_write_P((modifiers & MOD_MASK_GUI) ? PSTR("G") : PSTR(" "), false);
}

void render_status_main(void) {
    /* Show Keyboard Layout  */
    render_layer_state();
    render_keylock_status(host_keyboard_leds());
    render_mod_status(get_mods());
}

static void render_logo(void) {
    static const char PROGMEM sol_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };
    oled_write_P(sol_logo, false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_write_P(sol_icon, false);
        render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_logo();
        //oled_scroll_left();
    }
}

#endif
