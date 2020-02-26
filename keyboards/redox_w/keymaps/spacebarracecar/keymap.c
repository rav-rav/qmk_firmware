#include QMK_KEYBOARD_H

enum layers {
  _QWERTY,
  _SYMB,
  _NAVI,
};

#include "spacebarracecar.h"
#include "dynamic_macro.h"

// Shortcut to make keymap more readable
#define RAV_OE LT(_NAVI, DE_OE)

#define LAY_SYMB MO(_SYMB)
#define LAY_NAVI MO(_NAVI)

#define M1_REC DYN_REC_START1
#define M2_REC DYN_REC_START1
#define M1_PLAY DYN_REC_START1
#define M2_PLAY DYN_REC_START1
#define M_STOP DYN_REC_START1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC  ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,DE_Q    ,DE_W    ,DE_E    ,DE_R    ,DE_T    ,CU_GRV  ,                          KC_F6   ,DE_Y    ,DE_U    ,DE_I    ,DE_O    ,DE_P    ,DE_UE   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_BSPC ,DE_A    ,DE_S    ,DE_D    ,DE_F    ,DE_G    ,KC_INS  ,                          KC_DEL  ,DE_H    ,DE_J    ,DE_K    ,DE_L    ,RAV_OE  ,DE_AE   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     CU_LSFT ,DE_Z    ,DE_X    ,DE_C    ,DE_V    ,DE_B    ,KC_APP  ,KC_LGUI ,        KC_PSCR ,TG(_SYMB),DE_N   ,DE_M    ,CU_COMM ,CU_DOT  ,CU_SLSH ,CU_SCLN ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_LCTL ,CU_QUOT ,KC_LALT ,KC_LALT ,     LAY_SYMB,    KC_SPC  ,KC_ENT  ,        KC_ENT  ,LAY_NAVI,    KC_SPC  ,     KC_RGUI ,KC_RALT ,DE_MINS ,KC_RCTL
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_SYMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,DE_CIRC ,DE_SQ2  ,DE_SQ3  ,DE_PARA ,DE_RING ,                                            _______ ,DE_SS   ,KC_PSLS ,KC_PAST ,KC_PMNS ,KC_VOLU ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,DE_EXLM ,DE_AT   ,DE_LCBR ,DE_RCBR ,DE_PIPE ,_______ ,                          _______ ,_______ ,DE_7    ,DE_8    ,DE_9    ,KC_PPLS ,KC_VOLD ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,DE_HASH ,DE_DLR  ,DE_LPRN ,DE_RPRN ,DE_GRV  ,_______ ,                          _______ ,_______ ,DE_4    ,DE_5    ,DE_6    ,DE_EQL  ,KC_CALC ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,DE_PERC ,DE_CIRC ,DE_LBRC ,DE_RBRC ,DE_AMPR ,_______ ,_______ ,        _______ ,_______ ,_______ ,DE_1    ,DE_2    ,DE_3    ,DE_BSLS ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    DE_0    ,     DE_DOT  ,DE_COMM ,KC_PENT ,_______ 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NAVI] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     M1_REC  ,M1_PLAY ,M2_PLAY ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,KC_VOLU ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     M2_REC  ,_______ ,_______ ,DE_EURO ,_______ ,_______ ,_______ ,                          _______ ,KC_PGUP ,KC_HOME ,KC_UP ,KC_END    ,_______ ,KC_VOLD ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     M_STOP  ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,KC_PGDN ,KC_LEFT ,KC_DOWN ,KC_RIGHT,_______ ,KC_CALC ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,        _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    _______ ,     _______ ,_______ ,_______ ,_______ 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

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
        case _NAVI:
            set_led_red;
            break;
        default:
            break;
    }
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
	if (!process_record_dynamic_macro(keycode, record)) {
        return false;
    }
	
	return true;
};
