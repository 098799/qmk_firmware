#include QMK_KEYBOARD_H
#include "features/caps_word.h"


bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_caps_word(keycode, record)) {
    return false;
  }
  return true;
}

enum custom_keycodes {
  LGUI_A = MT(MOD_LGUI, KC_A),
  LALT_S = MT(MOD_LALT, KC_S),
  LSFT_D = MT(MOD_LSFT, KC_D),
  LCTL_F = MT(MOD_LCTL, KC_F),
  LCTL_J = MT(MOD_LCTL, KC_J),
  RSFT_K = MT(MOD_RSFT, KC_K),
  LALT_L = MT(MOD_LALT, KC_L),
  RGUI_SC = MT(MOD_RGUI, KC_SCLN),

  LTHR_TB = LT(1, KC_TAB),
  LGUI_SP = MT(MOD_LGUI, KC_SPC),
  FOUR_SP = LT(4, KC_SPC),
  LFOU_ES = LT(2, KC_ESCAPE),

  LGUI__G = LGUI(KC_G),
  LGUI__B = LGUI(KC_B),
  LGUI__N = LGUI(KC_N),
  LGUI__M = LGUI(KC_M),
  LGUI_CO = LGUI(KC_COMM),
  LGUI_DO = LGUI(KC_DOT),
  LGUI_SL = LGUI(KC_SLSH),

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
  [0] = LAYOUT_ortho_4x12(
                          KC_CAPS, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    TMUX_B,
                          TG(4),   LGUI_A,  LALT_S,  LSFT_D,  LCTL_F,  KC_G,    KC_H,    LCTL_J,  RSFT_K,  LALT_L,  RGUI_SC, KC_QUOT,
                          TO(5),   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
                          _______, _______, _______, KC_BSPC, LTHR_TB, FOUR_SP, FOUR_SP, LFOU_ES, KC_ENT,  KC_RALT, _______, _______
                          ),

  [1] = LAYOUT_ortho_4x12(
                          _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
                          _______, KC_QUES, KC_COLN, KC_MINS, KC_UNDS, KC_2,    KC_1,    KC_EQL,  KC_PLUS, KC_LBRC, KC_RBRC, KC_0,
                          _______, KC_GRV,  KC_TILD, KC_QUOT, KC_DQUO, KC_LT,   KC_GT,   KC_BSLS, KC_PIPE, KC_LCBR, KC_RCBR, _______,
                          _______, _______, _______, KC_LGUI, _______, _______, _______, MO(3),   _______, _______, _______, _______
                          ),

  [2] = LAYOUT_ortho_4x12(
                          _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
                          _______, _______, KC_BTN3, KC_BTN2, KC_BTN1, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,
                          _______, _______, KC_ACL2, KC_ACL1, KC_ACL0, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______,
                          _______, _______, _______, KC_DEL,  MO(3),   _______, _______, _______, _______, _______, _______, _______
                          ),

  [3] = LAYOUT_ortho_4x12(
                          RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                          _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______,
                          _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______,
                          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
                          ),

  /* [3] = LAYOUT_ortho_4x12( */
  /*                         KC_TRNS, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL, */
  /*                         KC_CAPS, KC_SLEP, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, DF(0),   DF(1),    DF(2),   KC_TRNS, KC_TRNS, */
  /*                         KC_TRNS, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, KC_TRNS, KC_TRNS, KC_TRNS, */
  /*                         DF(0),   DF(1),   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS */
  /*                         ), */

  [4] = LAYOUT_ortho_4x12(
                          KC_CAPS, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
                          TG(4),   _______, _______, _______, _______, LGUI__G, KC_HOME, CTRL_LE, KC_PGDN, KC_PGUP, CTRL_RI, KC_END,
                          _______, _______, _______, _______, _______, LGUI__B, LGUI__N, LGUI__M, LGUI_CO, LGUI_DO, LGUI_SL, _______,
                          _______, _______, _______, KC_BSPC, LTHR_TB, LGUI_SP, LGUI_SP, LFOU_ES, KC_ENT,  _______, _______, _______
                          ),

  [5] = LAYOUT_ortho_4x12(
                          KC_CAPS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
                          TG(4),   LGUI_A,  LALT_S,  LSFT_D,  LCTL_F,  KC_G,    KC_H,    LCTL_J,  RSFT_K,  LALT_L,  RGUI_SC, KC_QUOT,
                          TG(5),   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
                          _______, _______, _______, KC_BSPC, LTHR_TB, FOUR_SP, FOUR_SP, LFOU_ES, KC_ENT,  KC_RALT, _______, _______
                          )

};

uint32_t layer_state_set_user(uint32_t state) {
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
