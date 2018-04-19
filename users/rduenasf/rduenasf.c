#include "rduenasf.h"
#include "version.h"


// Defines actions tor my global custom keycodes. Defined in drashna.h file
// Then runs the _keymap's record handier if not processed here
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case KC_L_OSX:
    if (record->event.pressed) {
      set_single_persistent_default_layer(L_OSX);
    }
    return false;
    break;
  case KC_L_WIN:
    if (record->event.pressed) {
      set_single_persistent_default_layer(L_WIN);
    }
    return false;
    break;
  case KC_MAKE:  // Compiles the firmware, and adds the flash command based on keyboard bootloader
    if (!record->event.pressed) {
      SEND_STRING("make -j8 " QMK_KEYBOARD ":" QMK_KEYMAP
#if  (defined(BOOTLOADER_DFU) || defined(BOOTLOADER_LUFA_DFU) || defined(BOOTLOADER_QMK_DFU))
                   ":dfu"
#elif defined(BOOTLOADER_HALFKAY)
                   ":teensy"
#elif defined(BOOTLOADER_CATERINA)
                   ":avrdude"
#endif // bootloader options
                   SS_TAP(X_ENTER));
    }
    return false;
    break;
  case EPRM: // Resets EEPROM
    if (record->event.pressed) {
      eeconfig_init();
    }
    return false;
    break;
  case VRSN: // Prints firmware version
    if (record->event.pressed) {
      SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION ", Built on: " QMK_BUILDDATE);
    }
    return false;
    break;

  case RGB_SLD:
    if (record->event.pressed) {
      #ifdef RGBLIGHT_ENABLE
        rgblight_mode(1);
      #endif
    }
    return false;
    break;
  }
  return true;
}
