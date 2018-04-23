#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#include "rduenasf.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[L_OSX] = LAYOUT_ergodox(  // layer 0 : default
    // left hand
    KC_ESCAPE,      KC_1,         KC_2,        KC_3,        KC_4,      KC_5,   KC_6,
    KC_TAB,         KC_Q,         KC_W,        KC_E,        KC_R,      KC_T,   KC_TAB,
    ALL_T(KC_NO),   KC_A,         KC_S,        KC_D,        KC_F,      KC_G,
    KC_LSPO,        KC_Z,         KC_X,        KC_C,        KC_V,      KC_B,   KC_DEL,
    MO(L_SYMB),     KC_LCTL,      KC_LALT,     KC_LEFT,     KC_RIGHT,

              RGUI(KC_C), RGUI(KC_V),
                          KC_LGUI,
    KC_SPACE, KC_BSPACE,  LALT(KC_LGUI),

    // right hand
    KC_6,           KC_7,         KC_8,        KC_9,        KC_0,        KC_MINUS,         KC_EQUAL,
    KC_BSPACE,      KC_Y,         KC_U,        KC_I,        KC_O,        KC_P,             KC_GRAVE,
                    KC_H,         KC_J,        KC_K,        KC_L,        KC_SCOLON,        GUI_T(KC_QUOTE),
    KC_TAB,         KC_N,         KC_M,        KC_COMMA,    KC_DOT,      KC_SLASH,         KC_RSPC,
                                  KC_DOWN,     KC_UP,       KC_LBRACKET, KC_RBRACKET,      KC_RCTRL,

    KC_PGDOWN,      KC_PGUP,
    TG(L_HOTS),
    LALT(KC_LGUI),  _______,   KC_ENTER
),
[L_WIN] = LAYOUT_ergodox(  // layer 0 : default
    // left hand
    KC_ESCAPE,      KC_1,         KC_2,        KC_3,        KC_4,      KC_5,   KC_6,
    KC_TAB,         KC_Q,         KC_W,        KC_E,        KC_R,      KC_T,   KC_TAB,
    ALL_T(KC_NO),   KC_A,         KC_S,        KC_D,        KC_F,      KC_G,
    KC_LSPO,        KC_Z,         KC_X,        KC_C,        KC_V,      KC_B,   KC_DEL,
    MO(L_SYMB),     KC_LCTL,      KC_LALT,     KC_LEFT,     KC_RIGHT,

              LCTL(KC_C), LCTL(KC_V),
                          KC_LALT,
    KC_SPACE, KC_BSPACE,  LALT(KC_LCTL),

    // right hand
    KC_6,           KC_7,         KC_8,        KC_9,        KC_0,        KC_MINUS,         KC_EQUAL,
    KC_BSPACE,      KC_Y,         KC_U,        KC_I,        KC_O,        KC_P,             KC_GRAVE,
                    KC_H,         KC_J,        KC_K,        KC_L,        KC_SCOLON,        ALT_T(KC_QUOTE),
    KC_TAB,         KC_N,         KC_M,        KC_COMMA,    KC_DOT,      KC_SLASH,         KC_RSPC,
                                  KC_DOWN,     KC_UP,       KC_LBRACKET, KC_RBRACKET,      KC_RCTRL,

    KC_PGDOWN,      KC_PGUP,
    TG(L_HOTS),
    LALT(KC_LCTL),  _______,   KC_ENTER
),
// Keymap 1: Symbol Layer
 // L_SYMBOLS
[L_SYMB] = LAYOUT_ergodox(
    // left hand
    _______,        KC_F1,         KC_F2,      KC_F3,       KC_F4,       KC_F5,      _______,
    _______,        KC_EXLM,       KC_AT,      KC_LCBR,     KC_RCBR,     KC_PIPE,    _______,
    KC_F18,         KC_HASH,       KC_DLR,     KC_LPRN,     KC_RPRN,     KC_GRAVE,
    _______,        KC_PERC,       KC_CIRC,    KC_LBRACKET, KC_RBRACKET, KC_TILD,    _______,
    _______,        _______,       _______,    KC_HOME,     KC_END,

                        _______,          RGB_TOG,
                                          _______,
    KC_AUDIO_VOL_DOWN,  KC_AUDIO_VOL_UP,  _______,

    // right hand
    RESET,     KC_F6,    KC_F7,   KC_F8,     KC_F9,    KC_F10,          KC_F11,
    KC_MAKE,   KC_UP,    KC_1,    KC_2,      KC_3,     KC_KP_ASTERISK,  KC_F12,
               KC_DOWN,  KC_4,    KC_5,      KC_6,     KC_KP_PLUS,      KC_L_OSX,
    VRSN,      KC_AMPR,  KC_7,    KC_8,      KC_9,     KC_NONUS_BSLASH, KC_L_WIN,
                         KC_MPP,  KC_DOT,    KC_0,     KC_EQUAL,        _______,

    RGB_M_B,  RGB_M_P,
    RGB_VAD,
    RGB_VAI,  RGB_HUD,  RGB_HUI
),
[L_HOTS] = LAYOUT_ergodox(
    // left hand
    KC_GRAVE,  _______,  _______,  _______,  _______,  _______,  _______,
    KC_TAB,    _______,  _______,  _______,  _______,  _______,  _______,
    KC_F2,     _______,  _______,  _______,  _______,  _______,
    KC_LSHIFT, _______,  _______,  _______,  _______,  _______,  _______,
    KC_LCTL,   KC_LCTL,  KC_LALT,  KC_LALT,  KC_LALT,

              KC_NO,    KC_ESCAPE,
                        KC_PSCREEN,
    _______,  _______,  KC_NO,

    // right hand (skip entirely)
    _______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,
            _______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,

    _______,_______,
    _______,
    _______,_______,_______
),
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_ENABLE
  rgblight_init();
  rgblight_enable();
  #ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
  #endif
#endif
  // set led1 for default eeprom layer if necessary
  uint8_t default_layer = eeconfig_read_default_layer();
  if (default_layer & (1UL << L_WIN)) {
    ergodox_right_led_1_on();
  }
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  uint8_t default_layer = eeconfig_read_default_layer();


  // led1 indicates whether we're on osx or win default layouts
  // led2 indicates symbols/media layer
  // led3 indicates whether we're in gaming mode or not.

  if (default_layer & (1UL << L_WIN)) {
    ergodox_right_led_1_on();
  }

  switch (layer) {
      case L_SYMB:
        ergodox_right_led_2_on();
        break;
      case L_HOTS:
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }

  return state;
};
