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
  LFOU_ES = LT(2, KC_ESCAPE),
  RALT_LE = RALT_T(KC_ENTER),

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
};

enum {
    W_K,
    Q_K,
};


qk_tap_dance_action_t tap_dance_actions[] = {
  [W_K] = ACTION_TAP_DANCE_DOUBLE(KC_W, LALT(KC_BSPC)),
  [Q_K] = ACTION_TAP_DANCE_DOUBLE(KC_Q, LALT(KC_D)),
};


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_D):
            return MIDDLE_TAPPING_TERM;
        case RSFT_T(KC_K):
            return MIDDLE_TAPPING_TERM;
        case RALT_T(KC_ENTER):
            return SHORT_TAPPING_TERM;
        case TD(Q_K):
            return TAP_DANCE_TAPPING_TERM;
        case TD(W_K):
            return TAP_DANCE_TAPPING_TERM;
        default:
            return TAPPING_TERM;
    }
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ortho_4x12(
                          _______, TD(Q_K), TD(W_K), KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
                          _______, LGUI_A,  LALT_S,  LSFT_D,  LCTL_F,  KC_G,    KC_H,    LCTL_J,  RSFT_K,  LALT_L,  RGUI_SC, KC_QUOT,
                          _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
                          TG(4),   _______, _______, KC_BSPC, LTHR_TB, LGUI_SP, LGUI_SP, LFOU_ES, KC_ENT,  KC_RALT, _______, _______
                          ),
  [1] = LAYOUT_ortho_4x12(
                          KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
                          KC_DEL , KC_QUES, KC_COLN, KC_MINS, KC_UNDS, KC_QUOT, KC_DQUO, KC_EQL,  KC_PLUS, KC_LBRC, KC_RBRC, KC_QUOT,
                          KC_TRNS, KC_QUOT, KC_DQUO, KC_LT,   KC_GT,   KC_GRV,  KC_TILD, KC_BSLS, KC_PIPE, KC_LCBR, KC_RCBR, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL,  KC_TRNS, KC_TRNS, KC_TRNS, MO(3),   KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
                          ),
  [2] = LAYOUT_ortho_4x12(
                          KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
                          KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_QUOT,
                          KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_COMM, KC_DOT,  KC_SLSH, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL,  MO(3),   KC_TRNS, KC_TRNS, KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
                          ),
  [3] = LAYOUT_ortho_4x12(
                          KC_TRNS, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL,
                          KC_CAPS, KC_SLEP, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, DF(0),   DF(1),    DF(2),   KC_TRNS, KC_TRNS,
                          KC_TRNS, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, KC_TRNS, KC_TRNS, KC_TRNS,
                          DF(0),   DF(1),   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS
                          ),
  [4] = LAYOUT_ortho_4x12(
                          KC_TAB,  _______, _______, _______, TO(0),   _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSPC,
                          _______, _______, _______, _______, _______, KC_END,  KC_HOME, CTRL_LE, KC_PGDN, KC_PGUP, CTRL_RI, KC_END,
                          _______, _______, _______, _______, TO(0),   _______, _______, KC_BTN3, KC_WH_L, KC_WH_R, KC_END,  _______,
                          KC_TRNS, _______, _______, _______, _______, TG(5),   TG(5),   _______, _______, _______, _______, _______
                          ),
  [5] = LAYOUT_ortho_4x12(
                          KC_TAB,  _______, _______, _______, _______, _______, _______, SHFT_LE, SHFT_DO, SHFT_UP, SHFT_RI, KC_BSPC,
                          _______, _______, _______, _______, _______, _______, SHFT_HO, CT_SF_L, SF_PGDN, SF_PGUP, CT_SF_R, SHFT_EN,
                          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                          KC_TRNS, _______, _______, _______, _______, KC_TRNS, KC_TRNS, _______, _______, _______, _______, _______
                          )
};
