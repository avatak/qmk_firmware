#include QMK_KEYBOARD_H
// #include "bootloader.h"

#ifdef PROTOCOL_LUFA
    #include "lufa.h"
    #include "split_util.h"
#endif

enum layer_number {
  _COLEMAK = 0,
  _NAV,
  _TEX,
  _SYM,
  _NUM,
  _MEDIA,
  _ADJUST
};


/*  Custom keycode definitions */

  /* Layer changes */

      #define ADJUST MO(_ADJUST)
      #define MACWIN MO(_MWIN)
      #define MNAVESC LT(_MNAV, KC_ESC)
      #define MNAVSPC LT(_MNAV, KC_SPC)
      #define NAVESC LT(_NAV, KC_ESC)
      #define NAVSPC LT(_NAV, KC_SPC)
      #define NUMPAD TT(_NUM)
      #define SYMENT LT(_SYM, KC_ENT)
      #define SYMBOL MO(_SYM)
      #define TEXSPC LT(_TEX, KC_SPC)

  /* Custom combination keycodes */

      #define ALTBSPC LALT(KC_BSPC)
      #define ALTCTL LALT(KC_LCTL)
      #define ALTCTLS S(LALT(KC_LCTL))
      #define ALTDEL LALT(KC_DEL)
      #define ALT_F4 LALT(KC_F4)
      #define ALTLEFT LALT(KC_LEFT)
      #define ALTRGHT LALT(KC_RGHT)
      #define ALTSHFT LALT(KC_LSFT)
      #define CTLBSPC LCTL(KC_BSPC)
      #define CTLDEL LCTL(KC_DEL)
      #define CTLLEFT LCTL(KC_LEFT)
      #define CTLPGDN LCTL(KC_PGDN)
      #define CTLPGUP LCTL(KC_PGUP)
      #define CTLRGHT LCTL(KC_RGHT)
      #define CTLZERO LCTL(KC_0)
      #define MACEND LGUI(KC_RIGHT)
      #define MACHOME LGUI(KC_LEFT)
      #define TABLEFT LCTL(LSFT(KC_TAB))
      #define TABRGHT LCTL(KC_TAB)

  /* Dual function keys */

      #define CTLSCLN CTL_T(KC_SCLN)
      #define CTLSLSH CTL_T(KC_SLSH)
      #define GUISCLN GUI_T(KC_SCLN)
      #define GUISLSH GUI_T(KC_SLSH)

  /* Keycodes for moving windows around on osx using magnet */
  /*
      #define MW_CENT LCTL(LALT(KC_F))
      #define MW_CSQR LCTL(LALT(KC_C))
      #define MW_FULL LCTL(LALT(KC_ENT))
      #define MW_LEFT LCTL(LALT(KC_LEFT))
      #define MW_LLFT LCTL(LALT(KC_J))
      #define MW_LOWR LCTL(LALT(KC_DOWN))
      #define MW_LRIT LCTL(LALT(KC_K))
      #define MW_L13 LCTL(LALT(KC_D))
      #define MW_L23 LCTL(LALT(KC_E))
      #define MW_RGHT LCTL(LALT(KC_RIGHT))
      #define MW_R13 LCTL(LALT(KC_G))
      #define MW_R23 LCTL(LALT(KC_T))
      #define MW_ULFT LCTL(LALT(KC_U))
      #define MW_UPPR LCTL(LALT(KC_UP))
      #define MW_URIT LCTL(LALT(KC_I))
*/

// Defines the keycodes used by our macros in process_record_user

  enum custom_keycodes {
      ALIGN = SAFE_RANGE,
      ARRAY,
      COLEMAC,
      COLEMAK,
      DISPMTH,
      ENUM,
      ITEM,
      ITEMZ,
      LFTRGHT,
      LEMMA,
      LINEMTH,
      RGBRST,
      RGB_MENU,
      SECTN,
      THEOREM,
      QWERTY,
  };


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

 [_COLEMAK] = LAYOUT( \
      KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_INS ,       _______ ,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_BSPC, \
      KC_TAB , KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   , KC_CAPS,       TG(_NUM), KC_J   , KC_L   , KC_U   , KC_Y   , GUISCLN, KC_BSLS, \
      NAVESC , KC_A   , KC_R   , KC_S   , KC_T   , KC_G   , XXXXXXX,       XXXXXXX,  KC_K   , KC_N   , KC_E   , KC_I   , KC_O   , KC_QUOT, \
      KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   , XXXXXXX,       XXXXXXX,  KC_M   , KC_H   , KC_COMM, KC_DOT , CTLSLSH, KC_RSHIFT, \
      ADJUST , KC_LCTL, KC_LGUI, KC_LALT,LCTL(KC_O), NAVSPC, TT(_NUM),     SYMENT ,  TEXSPC, LGUI(KC_TAB), KC_HYPR, S(KC_RALT),LCTL(KC_RALT), MO(_MEDIA) , \
                                                     NAVSPC, TT(_NUM),     SYMENT ,  TEXSPC \
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

  [_NAV] =  LAYOUT( \
      _______, _______, _______, _______, ALT_F4 , _______, _______, _______, _______, _______, _______, _______, _______, _______,\
      _______, _______, CTLPGUP, KC_PGUP, CTLPGDN, _______, _______, _______, _______, TABLEFT, KC_UP  , TABRGHT, _______, S(LCTL(LALT(KC_S))),
      _______, _______, KC_HOME, KC_PGDN, KC_END , _______, _______, _______, CTLLEFT, KC_LEFT, KC_DOWN, KC_RGHT, CTLRGHT, S(KC_F10),\
      _______, _______, _______, KC_CAPS, KC_INS , _______, _______, _______, CTLBSPC, KC_BSPC, KC_DEL , CTLDEL , CTLZERO, _______,\
      _______, _______, _______, _______, _______, _______, _______, _______, KC_ENT,  _______, _______, _______, _______, KC_F12,\
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

  [_TEX] =  LAYOUT( \
      _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , _______, _______, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,\
      _______, SECTN  , ENUM   , ITEMZ  , LFTRGHT, _______, _______, _______, _______, KC_LBRC, KC_RBRC, LINEMTH, DISPMTH, KC_F12,\
      _______, ALIGN  , ARRAY  , _______, ITEM   , _______, _______, _______, _______, KC_LCBR, KC_RCBR, S(KC_9), S(KC_0), _______,\
      _______, LEMMA  , THEOREM, _______, _______, _______, _______, _______, KC_MINS, KC_UNDS, S(KC_EQL),KC_EQL, KC_BSLS, _______,\
      _______, _______, _______, _______, _______, MO(_SYM), _______, _______, _______, _______, _______, _______, _______, _______,\
                                                   MO(_SYM), _______, _______, _______\
      ),


  /* _SYM (Symbols, Numbers, and F Row)
   * ,--------------------------------------------------------------.      ,--------------------------------------------------------------.
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

  [_SYM] =  LAYOUT( \
      _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , _______, _______, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,\
      _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , _______, _______, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
      KC_TILD, KC_EXLM,  KC_AT , KC_HASH, KC_DLR , KC_PERC, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_F12 ,
      KC_GRV , KC_1   ,  KC_2  , KC_3   , KC_4   , KC_5   , _______, _______, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,\
                                                   _______, _______, _______, _______\
      ),


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

  [_NUM] = LAYOUT( \
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

  [_MEDIA] = LAYOUT( \
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

  [_ADJUST] =  LAYOUT( \
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
  [16] = LAYOUT( \
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
                if (clockwise) {
                    tap_code(KC_TAB);
                } else {
                    register_code(KC_LSFT);
                    tap_code(KC_TAB);
                    unregister_code(KC_LSFT);
                }
            }
            // TEX Layer
            else if (IS_LAYER_ON(_TEX)) {
                if (clockwise) {
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
                if (clockwise) {
                    rgblight_increase_hue();
                } else {
                    rgblight_decrease_hue();
                }
            }
            // MEDIA layer
            else if (IS_LAYER_ON(_ADJUST)) {
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
            }
            // DEFAULT
            else {
                if (clockwise) {
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
            if (clockwise) {
                tap_code(KC_PGDN);
            } else {
                tap_code(KC_PGUP);
            }
        }
        // Symbol layer
        else if (IS_LAYER_ON(_SYM)) {
            if (clockwise) {
                tap_code(KC_SPC);
            } else {
                tap_code(KC_BSPC);
            }
        }
        // Adjust layer
        else if (IS_LAYER_ON(_ADJUST)) {
            if (clockwise) {
                rgblight_step();
            } else {
                rgblight_step_reverse();
            }
        }
        // MEDIA layer
            else if (IS_LAYER_ON(_ADJUST)) {
                if (clockwise) {
                    tap_code(KC_MNXT);
                } else {
                    tap_code(KC_MPRV);
                }
            }
        // DEFAULT
        else {
            if (clockwise) {
                tap_code(KC_RGHT);
            } else {
                tap_code(KC_LEFT);
            }
        }
    }
  }
#endif


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            break;
        case RGB_MENU:
            #ifdef RGB_OLED_MENU
                if (record->event.pressed) {
                    if (get_mods() & MOD_MASK_SHIFT) {
                        rgb_encoder_state = (rgb_encoder_state - 1);
                            if (rgb_encoder_state > 5) {
                                rgb_encoder_state = 5;
                            }
                    } else {
                        rgb_encoder_state = (rgb_encoder_state + 1) % 6;
                    }
              }
            #endif
            break;
        case RGBRST:
            #ifdef RGBLIGHT_ENABLE
                if (record->event.pressed) {
                    eeconfig_update_rgblight_default();
                    rgblight_enable();
                }
            #endif
            break;

    // For LaTeX specifically

        case ALIGN:
            if (record->event.pressed) {
                SEND_STRING("\\begin{align*}" SS_TAP(X_ENTER) SS_TAP(X_ENTER) "\\end{align*}" SS_TAP(X_UP) SS_TAP(X_TAB));
            }
            break;
        case ARRAY:
            if (record->event.pressed) {
                SEND_STRING("\\begin{array}{c c}"SS_TAP(X_ENTER) SS_TAP(X_ENTER) "\\end{array}" SS_TAP(X_UP) SS_TAP(X_TAB));
            }
            break;
        case DISPMTH:
            if (record->event.pressed) {
                SEND_STRING("\\[\n\\]" SS_TAP(X_UP) "    ");
            }
            break;
        case ENUM:
            if (record->event.pressed) {
                SEND_STRING("\\begin{enumerate}" SS_TAP(X_ENTER) SS_TAP(X_ENTER) "\\end{enumerate}" SS_TAP(X_UP) SS_TAP(X_TAB) "\\item ");
            }
            break;
        case ITEM:
            if (record->event.pressed) {
                SEND_STRING("\\item");
            }
            break;
        case ITEMZ:
            if (record->event.pressed) {
                SEND_STRING("\\begin{itemize}"SS_TAP(X_ENTER) SS_TAP(X_ENTER) "\\end{itemize}" SS_TAP(X_UP) SS_TAP(X_TAB) "\\item ");
            }
            break;
        case LFTRGHT:
            if (record->event.pressed) {
                SEND_STRING("\\left(  \\right)" SS_LCTRL(SS_TAP(X_LEFT) SS_TAP(X_LEFT)) SS_TAP(X_LEFT));
            }
            break;
        case LEMMA:
            if (record->event.pressed) {
                SEND_STRING("\\begin{lemma}[]"SS_TAP(X_ENTER)SS_TAP(X_ENTER)"\\end{lemma}"SS_TAP(X_UP)SS_TAP(X_TAB));
            }
            break;
        case LINEMTH:
            if (record->event.pressed) {
                tap_code(KC_BSLS);
                register_code(KC_LSFT);
                tap_code(KC_9);
                unregister_code(KC_LSFT);
                tap_code(KC_BSLS);
                register_code(KC_LSFT);
                tap_code(KC_0);
                unregister_code(KC_LSFT);
                tap_code(KC_LEFT);
                tap_code(KC_LEFT);
                tap_code(KC_SPC);
                tap_code(KC_LEFT);
                tap_code(KC_SPC);
            }
            break;
        case SECTN:
            if (record->event.pressed) {
                SEND_STRING("\\section{}"SS_TAP(X_LEFT));
            }
            break;
        case THEOREM:
            if (record->event.pressed) {
                SEND_STRING("\\begin{theorem}[]"SS_TAP(X_ENTER)SS_TAP(X_ENTER)"\\end{theorem}"SS_TAP(X_UP)SS_TAP(X_TAB));
            }
            break;
    }
    return true;
}

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

static void render_logo(void) {
    static const char PROGMEM sol_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };
    oled_write_P(sol_logo, false);
}

static void render_status(void) {
  // Render to mode icon
  static const char PROGMEM sol_icon[] = {
    0x9b,0x9c,0x9d,0x9e,0x9f,
    0xbb,0xbc,0xbd,0xbe,0xbf,
    0xdb,0xdc,0xdd,0xde,0xdf,0
  };
  oled_write_P(sol_icon, false);

  // Define layers here
  oled_write_P(PSTR("\nLayer\n"), false);
  uint8_t layer = layer_state ? biton(layer_state) : biton32(default_layer_state);
  switch (layer) {
    case _COLEMAK:
      oled_write_P(PSTR("COLMK"), false);
      break;
    case _NAV:
      oled_write_P(PSTR("NAV  "), false);
      break;
    case _TEX:
      oled_write_P(PSTR("LaTeX"), false);
      break;
    case _SYM:
      oled_write_P(PSTR("SYM  "), false);
      break;
    case _NUM:
      oled_write_P(PSTR("NUM  "), false);
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

  // Host Keyboard LED Status
    uint8_t led_state = host_keyboard_leds();
    oled_write_P(PSTR("\n-----\n"), false);
    oled_write_P(IS_LED_ON(led_state, USB_LED_NUM_LOCK) ? PSTR("NUMLK") : PSTR("     "), false);
    oled_write_P(IS_LED_ON(led_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLK") : PSTR("     "), false);
    oled_write_P(IS_LED_ON(led_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLK") : PSTR("     "), false);

#ifdef RGB_OLED_MENU
    static char buffer[31] = { 0 };
    snprintf(buffer, sizeof(buffer), "h%3d s%3d v%3d s%3d m%3d e%3d ", rgb_matrix_config.hsv.h, rgb_matrix_config.hsv.s, rgb_matrix_config.hsv.v, rgb_matrix_config.speed, rgb_matrix_config.mode, rgb_matrix_get_flags());
    buffer[4 + rgb_encoder_state * 5] = '<';

    oled_write_P(PSTR("-----"), false);
    oled_write(buffer, false);
#endif
}

void oled_task_user(void) {
  if (is_keyboard_master()) {
    render_status();
  } else {
    render_logo();
    oled_scroll_left();
  }
}

#endif
