#ifndef USERSPACE_CONFIG_H
#define USERSPACE_CONFIG_H

#ifndef QMK_KEYS_PER_SCAN
  #define QMK_KEYS_PER_SCAN 4
#endif // !QMK_KEYS_PER_SCAN

// #define FORCE_NKRO

// this makes it possible to do rolling combos (zx) with keys that
// convert to other keys on hold (z becomes ctrl when you hold it,
// and when this option isn't enabled, z rapidly followed by x
// actually sends Ctrl-x. That's bad.)
#define IGNORE_MOD_TAP_INTERRUPT
#undef PERMISSIVE_HOLD
#undef PREVENT_STUCK_MODIFIERS

// term between a tap and a hold
#ifdef TAPPING_TERM
#undef TAPPING_TERM
#endif
#define TAPPING_TERM 150

// reduce debounce to improve responsiveness
#ifdef DEBOUNCE
#undef DEBOUNCE
#endif
#define DEBOUNCE 3

// Disable action_get_macro and fn_actions, since we don't use these
// and it saves on space in the firmware.
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#endif // !USERSPACE_CONFIG_H
