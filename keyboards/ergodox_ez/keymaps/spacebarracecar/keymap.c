#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
  _BASE,
  _SYMB,
  _NAVI,
};

#include "spacebarracecar.h"

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
[_BASE] = LAYOUT_ergodox(
  // left hand
  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC  ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,  CU_GRV,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,DE_Q    ,DE_W    ,DE_E    ,DE_R    ,DE_T    ,  KC_INS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤        │
     KC_BSPC ,DE_A    ,DE_S    ,DE_D    ,DE_F    ,DE_G    ,//──────┤
  //├────────┼────────┼────────┼────────┼────────┼────────┤        │
     CU_LSFT ,DE_Z    ,DE_X    ,DE_C    ,DE_V    ,DE_B    ,  KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┴────────┘
     KC_LCTL ,CU_QUOT ,KC_LALT ,KC_LALT ,LAY_SYMB,
  //└────────┴────────┴────────┴────────┴────────┘                 ┌────────┬────────┐
                                                                      KC_APP, KC_LGUI,
  //                                                      ┌────────┼────────┼────────┤
                                                                              KC_HOME,
  //                                                      │        │        ├────────┤
                                                             KC_SPC,  KC_ENT,  KC_END,
  //                                                      └────────┴────────┴────────┘
  
  // right hand
  //                  ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
                       KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12  ,
  //                  ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
                       KC_INS  ,DE_Y    ,DE_U    ,DE_I    ,DE_O    ,DE_P    ,DE_UE   ,
  //                  │        ├────────┼────────┼────────┼────────┼────────┼────────┤
                                DE_H    ,DE_J    ,DE_K    ,DE_L    ,RAV_OE  ,DE_AE   ,
  //                  ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
                       KC_DEL  ,DE_N    ,DE_M    ,CU_COMM ,CU_DOT  ,CU_SLSH ,CU_SCLN ,
  //                  └────────┴────────┼────────┼────────┼────────┼────────┼────────┤
                                         KC_SPC  ,KC_RGUI ,KC_RALT ,DE_MINS ,KC_RCTL ,
  //┌────────┬────────┐                 └────────┴────────┴────────┴────────┴────────┘
     KC_PSCR ,TG(_SYMB),
  //├────────┼────────┼────────┐
     KC_PGUP ,//      │        │
  //├────────┤        │        │
     KC_PGDN , KC_ENT , KC_SPC
  //└────────┴────────┴────────┘
),

[_SYMB] = LAYOUT_ergodox(
  // left hand
  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,DE_CIRC ,DE_SQ2  ,DE_SQ3  ,DE_PARA ,DE_RING ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,DE_EXLM ,DE_AT   ,DE_LCBR ,DE_RCBR ,DE_PIPE ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤        │
     _______ ,DE_HASH ,DE_DLR  ,DE_LBRC ,DE_RBRC ,DE_GRV  ,//──────┤
  //├────────┼────────┼────────┼────────┼────────┼────────┤        │
     _______ ,DE_PERC ,DE_CIRC ,DE_LPRN ,DE_RPRN ,DE_TILD ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┴────────┘
     _______ ,_______ ,_______ ,_______ ,_______ ,
  //└────────┴────────┴────────┴────────┴────────┘                 ┌────────┬────────┐
                                                                    _______ ,_______ ,
  //                                                      ┌────────┼────────┼────────┤
                                                                             _______ ,
  //                                                      │        │        ├────────┤
                                                           _______ ,_______ ,_______ ,
  //                                                      └────────┴────────┴────────┘
  
  // right hand
  //                  ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
                       _______ ,_______ ,DE_SS   ,KC_PSLS ,KC_PAST ,KC_PMNS ,KC_VOLU ,
  //                  ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
                       _______ ,_______ ,DE_7    ,DE_8    ,DE_9    ,KC_PPLS ,KC_VOLD ,
  //                  │        ├────────┼────────┼────────┼────────┼────────┼────────┤
                                _______ ,DE_4    ,DE_5    ,DE_6    ,KC_PEQL ,KC_CALC ,
  //                  ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
                       _______ ,_______ ,DE_1    ,DE_2    ,DE_3    ,DE_BSLS ,_______ ,
  //                  └────────┴────────┼────────┼────────┼────────┼────────┼────────┤
                                         DE_0    ,DE_DOT  ,DE_COMM ,KC_PENT ,_______ ,
  //┌────────┬────────┐                 └────────┴────────┴────────┴────────┴────────┘
     _______ ,_______ ,
  //├────────┼────────┼────────┐
     _______ ,//      │        │
  //├────────┤        │        │
     _______ ,_______ ,_______
  //└────────┴────────┴────────┘
),

[_NAVI] = LAYOUT_ergodox(
  // left hand
  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     M1_REC  ,M1_PLAY ,M2_PLAY ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     M2_REC  ,_______ ,_______ ,DE_EURO ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤        │
     M_STOP  ,_______ ,_______ ,_______ ,_______ ,_______ ,//──────┤
  //├────────┼────────┼────────┼────────┼────────┼────────┤        │
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┴────────┘
     _______ ,_______ ,_______ ,_______ ,_______ ,
  //└────────┴────────┴────────┴────────┴────────┘                 ┌────────┬────────┐
                                                                    _______ ,_______ ,
  //                                                      ┌────────┼────────┼────────┤
                                                                             _______ ,
  //                                                      │        │        ├────────┤
                                                           _______ ,_______ ,_______ ,
  //                                                      └────────┴────────┴────────┘
  
  // right hand
  //                  ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
                       _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,KC_VOLU ,
  //                  ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
                       _______ ,KC_PGUP ,KC_HOME ,KC_UP   ,KC_END  ,_______ ,KC_VOLD ,
  //                  │        ├────────┼────────┼────────┼────────┼────────┼────────┤
                                KC_PGDN ,KC_LEFT ,KC_DOWN ,KC_RIGHT,_______ ,KC_CALC ,
  //                  ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
                       _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //                  └────────┴────────┼────────┼────────┼────────┼────────┼────────┤
                                         _______ ,_______ ,_______ ,_______ ,_______ ,
  //┌────────┬────────┐                 └────────┴────────┴────────┴────────┴────────┘
     _______ ,_______ ,
  //├────────┼────────┼────────┐
     _______ ,//      │        │
  //├────────┤        │        │
     _______ ,_______ ,_______
  //└────────┴────────┴────────┘
),
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
