#include QMK_KEYBOARD_H

#include "keymap_german.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _SHIFTED 1
#define _SYMB 2
#define _NAV 3
#define _ADJUST 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SHIFTED,
  SYMB,
  NAV,
  ADJUST,
  DYNAMIC_MACRO_RANGE,
};

#include "dynamic_macro.h"

// Shortcut to make keymap more readable
#define KC_BKSL KC_BSLASH
#define SYM_L   MO(_SYMB)

#define KC_ALAS LALT_T(KC_PAST)
#define KC_CTPL LCTL_T(KC_PSLS)

#define KC_NAGR LT(_NAV, KC_GRV)
#define KC_NAMI LT(_NAV, KC_MINS)

#define KC_ADEN LT(_ADJUST, KC_END)
#define KC_ADPU LT(_ADJUST, KC_PGUP)

// german specific shortcuts
#define DE_LOE LSFT(DE_OE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC  ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,DE_Q    ,DE_W    ,DE_E    ,DE_R    ,DE_T    ,DE_GRV  ,                          KC_F6   ,DE_Y    ,DE_U    ,DE_I    ,DE_O    ,DE_P    ,DE_UE   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_BSPC ,DE_A    ,DE_S    ,DE_D    ,DE_F    ,DE_G    ,KC_INS  ,                          KC_DEL  ,DE_H    ,DE_J    ,DE_K    ,DE_L    ,LT(_NAV,DE_OE),RGUI(DE_AE),
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     MO(_SHIFTED),DE_Z,DE_X    ,DE_C    ,DE_V    ,DE_B    ,KC_APP  ,KC_LGUI ,        KC_HOME ,TG(_SYMB),DE_N   ,DE_M    ,DE_COMM ,DE_DOT  ,DE_SLSH ,DE_SCLN ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_LCTL ,DE_QUOT ,KC_LALT ,KC_LALT ,     MO(_SYMB),   KC_SPC  ,KC_ENT  ,        KC_ENT  ,MO(_NAV),    KC_SPC  ,     KC_RALT ,KC_RALT ,DE_MINS ,KC_RCTL
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_SHIFTED] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     LSFT(KC_ESC  ),LSFT(KC_F1   ),LSFT(KC_F2   ),LSFT(KC_F3   ),LSFT(KC_F4   ),LSFT(KC_F5   ),                                            LSFT(KC_F7   ),LSFT(KC_F8   ),LSFT(KC_F9   ),LSFT(KC_F10  ),LSFT(KC_F11  ),LSFT(KC_F12),
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     LSFT(KC_TAB  ),LSFT(DE_Q    ),LSFT(DE_W    ),LSFT(DE_E    ),LSFT(DE_R    ),LSFT(DE_T    ),LSFT(DE_GRV  ),                          LSFT(KC_F6   ),LSFT(DE_Y    ),LSFT(DE_U    ),LSFT(DE_I    ),LSFT(DE_O    ),LSFT(DE_P    ),LSFT(DE_UE),
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     LSFT(KC_BSPC ),LSFT(DE_A    ),LSFT(DE_S    ),LSFT(DE_D    ),LSFT(DE_F    ),LSFT(DE_G    ),LSFT(KC_INS  ),                          LSFT(KC_DEL  ),LSFT(DE_H    ),LSFT(DE_J    ),LSFT(DE_K    ),LSFT(DE_L    ),LT(2,DE_LOE),RGUI(LSFT(DE_AE)),
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     LSFT(KC_LSFT ),LSFT(DE_Z    ),LSFT(DE_X    ),LSFT(DE_C    ),LSFT(DE_V    ),LSFT(DE_B    ),LSFT(KC_APP  ),LSFT(KC_LGUI ),        LSFT(KC_HOME ),_______   ,LSFT(DE_N    ),LSFT(DE_M    ),DE_LESS,DE_MORE,DE_QST,DE_COLN,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     LSFT(KC_LCTL ),DE_DQOT,MO(2)   ,LSFT(KC_LALT ),     MO(1)   ,    LSFT(KC_SPC  ),LSFT(KC_ENT  ),        LSFT(KC_ENT  ),MO(2)   ,    LSFT(KC_SPC  ),     LSFT(KC_RALT ),LSFT(KC_RALT ),DE_UNDS,LSFT(KC_RCTL)
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_SYMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,DE_CIRC ,DE_SQ2  ,DE_SQ3  ,DE_PARA ,DE_RING ,                                            _______ ,DE_SS   ,KC_PSLS ,KC_PAST ,KC_PMNS ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,DE_EXLM ,DE_AT   ,DE_LCBR ,DE_RCBR ,DE_PIPE ,_______ ,                          _______ ,_______ ,DE_7    ,DE_8    ,DE_9    ,KC_PPLS ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,DE_HASH ,DE_DLR  ,DE_LBRC ,DE_RBRC ,DE_GRV  ,_______ ,                          _______ ,_______ ,DE_4    ,DE_5    ,DE_6    ,KC_PEQL ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,DE_PERC ,DE_CIRC ,DE_LPRN ,DE_RPRN ,DE_TILD ,_______ ,_______ ,        _______ ,_______ ,_______ ,DE_1    ,DE_2    ,DE_3    ,KC_PENT ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    KC_KP_0 ,     DE_DOT  ,DE_COMM ,DE_BSLS ,_______ 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     DYN_REC_START1, DYN_MACRO_PLAY1 ,DYN_MACRO_PLAY2 ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     DYN_REC_START2 ,_______ ,_______ ,DE_EURO ,_______ ,_______ ,_______ ,                          _______ ,KC_PGUP ,KC_HOME ,KC_UP ,KC_END    ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     DYN_REC_STOP ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,KC_PGDN ,KC_LEFT ,KC_DOWN ,KC_RIGHT,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,        _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    _______ ,     _______ ,_______ ,_______ ,_______ 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (!process_record_dynamic_macro(keycode, record)) {
        return false;
    }
	
	return true;
};

void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    switch (layer) {
        case _QWERTY:
            set_led_off;
            break;
        case _SYMB:
            set_led_green;
            break;
        case _NAV:
            set_led_blue;
            break;
        case _ADJUST:
            set_led_red;
            break;
        default:
            break;
    }
};

