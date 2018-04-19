#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

enum userspace_layers {
  OSX = 0, // default layer for mac
  WIN, // default layer for windows
  SYMB, // symbols and media layer
  HOTS, // hots layer
};

enum userspace_custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  KC_MAKE,
  NEW_SAFE_RANGE
};

#endif
