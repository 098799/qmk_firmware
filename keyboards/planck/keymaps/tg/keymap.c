#include QMK_KEYBOARD_H


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_D):
            return MIDDLE_TAPPING_TERM;
        case RSFT_T(KC_K):
            return MIDDLE_TAPPING_TERM;
        case RALT_T(KC_LEFT):
            return SHORT_TAPPING_TERM;
        default:
            return TAPPING_TERM;
    }
}


#include "features/caps_word.h"

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_caps_word(keycode, record)) {
    return false;
  }
  return true;
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ortho_4x12(
                          /* TAB   Q     W     E     R     T     Y     U     I     O     P     BCK    */
                          /* ESC   Su(A) Al(S) Sh(D) Ct(F) G     H     Ct(J) Sh(K) Al(L) Su(;) '      */
                          /* SHIFT Z     X     C     V     B     N     M     ,     .     /     S(ENT) */
                          /* TG(7) CTR   ALT   SUP   MO(3) SPACEBAR    MO(4) Agr(L) Dow  Up    Right  */

                          KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,
                          KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,

                          KC_ESCAPE, MT(MOD_LGUI, KC_A), MT(MOD_LALT, KC_S), MT(MOD_LSFT, KC_D), MT(MOD_LCTL, KC_F), KC_G,
                          KC_H, MT(MOD_LCTL, KC_J), MT(MOD_RSFT, KC_K), MT(MOD_LALT, KC_L), MT(MOD_RGUI, KC_SCLN), KC_QUOT,

                          KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,
                          KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENTER,

                          TG(7), KC_LCTL, KC_LALT, KC_LGUI, MO(3), MT(MOD_LGUI, KC_SPC),
                          MT(MOD_LGUI, KC_SPC), LT(4, KC_ESCAPE), RALT_T(KC_LEFT), KC_DOWN, KC_UP, KC_RGHT
                          ),
  [1] = LAYOUT_ortho_4x12(
                          KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,
                          KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,

                          LGUI_T(KC_CAPS), KC_A, KC_S, KC_D, KC_F, KC_G,
                          KC_H, KC_J, KC_K, KC_L, LGUI_T(KC_SCLN), KC_QUOT,

                          KC_LSFT, LCTL_T(KC_Z), LALT_T(KC_X), KC_C, KC_V, KC_B,
                          KC_N, KC_M, KC_COMM, LALT_T(KC_DOT), LCTL_T(KC_SLSH), KC_ENTER,

                          TG(7), KC_LCTL, KC_LALT, KC_LGUI, MO(3), KC_SPC,
                          KC_SPC, MO(4), RALT_T(KC_LEFT), KC_DOWN, KC_UP, KC_RGHT
                          ),
  [2] = LAYOUT_ortho_4x12(
                          KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,
                          KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,

                          KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G,
                          KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,

                          KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,
                          KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENTER,

                          TG(7), KC_LCTL, KC_LALT, KC_LGUI, MO(3), KC_SPC,
                          KC_SPC, MO(4), KC_RALT, KC_DOWN, KC_UP, KC_RGHT
                          ),
  [3] = LAYOUT_ortho_4x12(
                          KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,
                          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DELETE,

                          KC_DELETE, KC_QUES, KC_COLN, KC_MINS, KC_UNDS, KC_QUOT,
                          KC_DQUO, KC_EQL, KC_PLUS, KC_LBRC, KC_RBRC, KC_QUOT,

                          KC_TRNS, KC_QUOT, KC_DQUO, KC_LT, KC_GT, KC_GRV,
                          KC_TILD, KC_BSLS, KC_PIPE, KC_LCBR, KC_RCBR, KC_TRNS,

                          KC_TRNS, KC_TRNS, KC_TRNS, KC_LGUI, KC_TRNS, KC_TRNS,
                          KC_TRNS, MO(6), KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
                          ),
  [4] = LAYOUT_ortho_4x12(
                          KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5,
                          KC_6, KC_7, KC_8, KC_9, KC_0, KC_DELETE,

                          KC_DELETE, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,
                          KC_F6, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_QUOT,

                          KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
                          KC_F12, KC_NUHS, KC_COMM, KC_DOT, KC_SLSH, KC_TRNS,

                          KC_TRNS, KC_TRNS, KC_TRNS, KC_LGUI, MO(6), KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
                          ),
  [5] = LAYOUT_ortho_4x12(
                          KC_1, KC_1, KC_1, KC_1, KC_1, KC_1,
                          KC_1, KC_1, KC_1, KC_1, KC_1, KC_1,

                          KC_NO, KC_Q, KC_W, KC_E, KC_R, KC_T,
                          KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC,

                          KC_NO, KC_A, KC_S, KC_D, KC_F, KC_G,
                          KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,

                          TO(0), KC_NO, KC_NO, KC_C, KC_V, KC_NO,
                          KC_NO, KC_N, KC_M, KC_NO, KC_NO, KC_NO
                          ),
  [6] = LAYOUT_ortho_4x12(
                          KC_TRNS, RESET, DEBUG, RGB_TOG, RGB_MOD, RGB_HUI,
                          RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL,

                          KC_CAPS, KC_SLEP, MU_MOD, AU_ON, AU_OFF, AG_NORM,
                          AG_SWAP, DF(0), DF(1), DF(2), TO(5), KC_TRNS,

                          KC_TRNS, MUV_DE, MUV_IN, MU_ON, MU_OFF, MI_ON,
                          MI_OFF, TERM_ON, TERM_OFF, KC_TRNS, KC_TRNS, KC_TRNS,

                          DF(0), DF(1), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
                          ),
  [7] = LAYOUT_ortho_4x12(
                          KC_TAB, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                          KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_BSPC,

                          KC_CAPS, MT(MOD_LGUI, KC_A), MT(MOD_LALT, KC_S), MT(MOD_LSFT, KC_D), MT(MOD_LCTL, KC_F), KC_NO,
                          KC_HOME, LCTL(KC_LEFT), KC_PGDN, KC_PGUP, LCTL(KC_RGHT), KC_END,

                          KC_LSFT, LCTL_T(KC_Z), LALT_T(KC_X), KC_NO, KC_NO, KC_NO,
                          KC_NO, KC_MS_BTN3, KC_WH_L, KC_WH_R, KC_NO, KC_ENTER,

                          KC_TRNS, KC_LCTL, KC_LALT, KC_LGUI, KC_NO, TG(8),
                          TG(8), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
                          ),
  [8] = LAYOUT_ortho_4x12(
                          KC_TAB, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                          KC_NO, LSFT(KC_LEFT), LSFT(KC_DOWN), LSFT(KC_UP), LSFT(KC_RGHT), KC_BSPC,

                          KC_CAPS, MT(MOD_LGUI, KC_A), MT(MOD_LALT, KC_S), MT(MOD_LSFT, KC_D), MT(MOD_LCTL, KC_F), KC_NO,
                          LSFT(KC_HOME), LCTL(LSFT(KC_LEFT)), LSFT(KC_PGDN), LSFT(KC_PGUP), LCTL(LSFT(KC_RIGHT)), LSFT(KC_END),

                          KC_LSFT, LCTL_T(KC_Z), LALT_T(KC_X), KC_NO, KC_NO, KC_NO,
                          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ENTER,

                          KC_NO, KC_LCTL, KC_LALT, KC_LGUI, KC_NO, KC_TRNS,
                          KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
                          )
};
