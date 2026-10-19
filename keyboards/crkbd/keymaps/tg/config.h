#pragma once

#define SPLIT_USB_DETECT


#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"


#define LONG_TAPPING_TERM 220
#define TAPPING_TERM 180
#define MIDDLE_TAPPING_TERM 160
#define SHORT_TAPPING_TERM 120
#define TAP_DANCE_TAPPING_TERM 250

#define TAPPING_TOGGLE 3
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD


// Accelerating mouse (ramp, NO inertia/coast) — like the TOTEM: a slow precise start
// for small selections, ramping up to a fast max for long drags, stops dead on release.
//   start speed = MOVE_DELTA / INTERVAL          = 4/16ms  ~= 250 px/s  (precise)
//   max speed   = MOVE_DELTA*MAX_SPEED / INTERVAL = 48/16ms ~= 3000 px/s (long drags)
//   ramp to max = TIME_TO_MAX * INTERVAL         = 32*16ms ~= 0.5 s of holding
#define MOUSEKEY_DELAY       0
#define MOUSEKEY_INTERVAL    16
#define MOUSEKEY_MOVE_DELTA  4
#define MOUSEKEY_MAX_SPEED   12
#define MOUSEKEY_TIME_TO_MAX 32
