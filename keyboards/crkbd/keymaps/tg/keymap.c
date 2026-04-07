#include QMK_KEYBOARD_H
#include "features/achordion.h"


enum custom_keycodes {
  LGUI_A = MT(MOD_LGUI, KC_A),
  LALT_S = MT(MOD_LALT, KC_S),
  LSFT_D = MT(MOD_LSFT, KC_D),
  LCTL_F = MT(MOD_LCTL, KC_F),
  LCTL_J = MT(MOD_LCTL, KC_J),
  RSFT_K = MT(MOD_RSFT, KC_K),
  LALT_L = MT(MOD_LALT, KC_L),
  RGUI_SC = MT(MOD_RGUI, KC_SCLN),

  LSYM_TB = LT(1, KC_TAB),
  LGUI_SP = MT(MOD_LGUI, KC_SPC),
  LNUM_ES = LT(2, KC_ESCAPE),

  LGUI__B = LGUI(KC_B),
  LGUI__N = LGUI(KC_N),

  CTRL_LE = LCTL(KC_LEFT),
  CTRL_RI = LCTL(KC_RGHT),
  SHFT_LE = LSFT(KC_LEFT),
  SHFT_DO = LSFT(KC_DOWN),
  SHFT_UP = LSFT(KC_UP),
  SHFT_RI = LSFT(KC_RGHT),
  SHFT_HO = LSFT(KC_HOME),
  CT_SF_L = LCTL(LSFT(KC_LEFT)),
  SF_PGDN = LSFT(KC_PGDN),
  SF_PGUP = LSFT(KC_PGUP),
  CT_SF_R = LCTL(LSFT(KC_RIGHT)),
  SHFT_EN = LSFT(KC_END),
  TMUX_B = LCTL(KC_B),
};


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case LGUI_T(KC_SPC):
    return LONG_TAPPING_TERM;
  case LSFT_T(KC_D):
    return MIDDLE_TAPPING_TERM;
  case RSFT_T(KC_K):
    return MIDDLE_TAPPING_TERM;
  default:
    return TAPPING_TERM;
  }
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
        KC_CAPS, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    TMUX_B,
        TG(4),   LGUI_A,  LALT_S,  LSFT_D,  LCTL_F,  KC_G,                         KC_H,    LCTL_J,  RSFT_K,  LALT_L,  RGUI_SC, KC_QUOT,
        TG(5),   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
                                            KC_BSPC, LSYM_TB, MO(4),      LGUI_SP, LNUM_ES, KC_ENT
        ),

  [1] = LAYOUT_split_3x6_3(
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
        _______, KC_QUES, KC_COLN, KC_MINS, KC_UNDS, KC_2,                         KC_1,    KC_EQL,  KC_PLUS, KC_LBRC, KC_RBRC, KC_0,
        _______, KC_GRV,  KC_TILD, KC_QUOT, KC_DQUO, KC_LT,                        KC_GT,   KC_BSLS, KC_PIPE, KC_LCBR, KC_RCBR, _______,
                                            KC_LGUI, _______, _______,    _______, MO(3),   _______
        ),

  [2] = LAYOUT_split_3x6_3(
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, _______, MS_BTN3, MS_BTN2, MS_BTN1, _______,                      _______, MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, _______,
        _______, _______, MS_ACL2, MS_ACL1, MS_ACL0, _______,                      _______, MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, _______,
                                            KC_DEL,  MO(3),   _______,    _______, _______, _______
        ),

  [3] = LAYOUT_split_3x6_3(
        QK_BOOT, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   UG_TOGG, UG_HUEU, UG_SATU, UG_VALU, _______,
        _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,                       KC_F12,  UG_NEXT, UG_HUED, UG_SATD, UG_VALD, _______,
                                            _______, _______, _______,    _______, _______, _______
        ),

  [4] = LAYOUT_split_3x6_3(
        _______, _______, _______, _______, _______, _______,                      _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
        TG(4),   _______, _______, _______, _______, _______,                      KC_HOME, CTRL_LE, KC_PGDN, KC_PGUP, CTRL_RI, KC_END,
        _______, _______, _______, _______, _______, LGUI__B,                      LGUI__N, _______, _______, _______, _______, _______,
                                            KC_BSPC, LSYM_TB, _______,    LGUI_SP, LNUM_ES, KC_ENT
                           ),

  [5] = LAYOUT_split_3x6_3(
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, KC_QUES, KC_COLN, KC_MINS, KC_UNDS, KC_2,                         KC_1,    KC_EQL,  KC_PLUS, KC_LBRC, KC_RBRC, KC_0,
        TG(5),   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
                                            KC_BSPC, LSYM_TB, MO(4),      LGUI_SP, LNUM_ES, KC_ENT
                           )

};


#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8
#define L_MOVEMENT 16
#define L_MOVEMENT_SHFT 32


void oled_render_nothing(void) {
  oled_clear();
}


void oled_render_logo(void) {
  oled_clear();
  static const char PROGMEM crkbd_logo[] = {
    0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
    0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
    0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
    0};
  oled_write_P(crkbd_logo, false);
}


void oled_render_other(void) {
  oled_clear();
  oled_write_P(PSTR("INSERT INSERT INSERT INSERT INSERT INSERT INSERT INSERT INSERT INSERT INSERT INSERT INSERT "), false);
}


void oled_layers(void) {
  switch (layer_state) {
  case L_BASE:
    oled_render_nothing();
    break;
  case L_LOWER:
    oled_render_nothing();
    break;
  case L_RAISE:
    oled_render_nothing();
    break;
  case L_MOVEMENT:
    oled_render_logo();
    break;
  case L_MOVEMENT_SHFT:
    oled_render_other();
    break;
  }
}


bool oled_task_user(void) {
  if (is_keyboard_master()) {
    oled_layers();
  } else {
    oled_render_logo();
  }
  return false;
}
#endif // OLED_ENABLE


void matrix_scan_user(void) {
  achordion_task();
}


bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
  switch (tap_hold_keycode) {
    case LSYM_TB:
      return true;
    case LNUM_ES:
      return true;
    case LALT_S:
      return true;
    case MO(4):
      return true;
    case LSFT_D:
      return true;
    case LCTL_F:
        switch (other_keycode) {
        case KC_W:
            return true;
        }
    case LGUI_A:
        switch (other_keycode) {
        case KC_G:
            return true;
        case KC_B:
            return true;
        }
    case RGUI_SC:
        switch (other_keycode) {
        case KC_N:
            return true;
        case KC_H:
            return true;
        }
    case LGUI_SP:
        return true;
  }
  return achordion_opposite_hands(tap_hold_record, other_record);
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_achordion(keycode, record)) { return false; }
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  switch (biton32(state)) {
    case 0:
      rgblight_disable();
      break;
    case 1:
      rgblight_disable();
      break;
    case 2:
      rgblight_disable();
      break;
    case 3:
      rgblight_disable();
      break;
    case 4:
      rgblight_enable();
      rgblight_sethsv_eeprom_helper(0, 255, 255, true);
      break;
    case 5:
      rgblight_enable();
      rgblight_sethsv_eeprom_helper(150, 255, 255, true);
      break;
  }
  return state;
}
