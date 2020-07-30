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
        case _COLEMAC:
            oled_write_P(PSTR("CLMAC"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("  NAV"), false);
            break;
        case _TEX:
            oled_write_P(PSTR("LaTeX"), false);
            break;
        case _MNAV:
            oled_write_P(PSTR(" MNAV"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("SYMBL"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("NUMPD"), false);
            break;
        case _MWIN:
            oled_write_P(PSTR(" MWIN"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("  ADJ"), false);
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
