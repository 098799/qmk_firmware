#include QMK_KEYBOARD_H


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        /* case LSFT_T(KC_D): */
        /*     return MIDDLE_TAPPING_TERM; */
        /* case RSFT_T(KC_K): */
        /*     return MIDDLE_TAPPING_TERM; */
        default:
            return TAPPING_TERM;
    }
}


#include "features/caps_word.h"

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_caps_word(keycode, record)) { return false; }
  // Your macros ...

  return true;
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
        KC_GRV, KC_1,               KC_2,               KC_3,               KC_4,               KC_5,   KC_6,   KC_7,               KC_8,               KC_9,               KC_0,                  KC_MINS,     KC_EQL,    KC_BSPC,     TG(2),
        KC_TAB, KC_Q,               KC_W,               KC_E,               KC_R,               KC_T,   KC_Y,   KC_U,               KC_I,               KC_O,               KC_P,                  KC_LBRC,     KC_RBRC,   KC_BSLS,     KC_END,
        KC_ESC, MT(MOD_LGUI, KC_A), MT(MOD_LALT, KC_S), MT(MOD_LSFT, KC_D), MT(MOD_LCTL, KC_F), KC_G,   KC_H,   MT(MOD_LCTL, KC_J), MT(MOD_RSFT, KC_K), MT(MOD_LALT, KC_L), MT(MOD_RGUI, KC_SCLN), KC_QUOT,     KC_ENT,
        KC_LSFT,KC_Z,               KC_X,               KC_C,               KC_V,               KC_B,   KC_N,   KC_M,               KC_COMM,            KC_DOT,             KC_SLSH,               KC_ENTER,               KC_UP,
        KC_LCTL,KC_LGUI,            KC_LALT,                                MT(MOD_LGUI, KC_SPC),                                   KC_RALT,            KC_RCTL,            MO(1),                              KC_LEFT,   KC_DOWN,     KC_RGHT
    ),

  [1] = LAYOUT(
        KC_GRV, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_DELETE,     RESET,
        _______,_______,_______,_______,_______,_______,_______,_______,KC_PSCR,KC_SLCK,KC_PAUS,_______,_______,_______,     _______,
        KC_CAPS,_______,_______,_______,_______,_______,_______,_______,KC_HOME,KC_PGUP,_______,_______,     _______,
        _______,_______,_______,_______,_______,_______,_______,_______,KC_END, KC_PGDN,_______,_______,     _______,
        _______,_______,_______,                _______,                _______,_______,MO(1),       _______,_______,_______
    ),

  [2] = LAYOUT(
        KC_GRV, KC_1,               KC_2,               KC_3,               KC_4,               KC_5,   KC_6,   KC_7,               KC_8,               KC_9,               KC_0,                  KC_MINS,     KC_EQL,    KC_BSPC,     KC_TRNS,
        KC_TAB, KC_Q,               KC_W,               KC_E,               KC_R,               KC_T,   KC_Y,   KC_U,               KC_I,               KC_O,               KC_P,                  KC_BSPC,     KC_RBRC,   KC_BSLS,     KC_END,
        KC_ESC, MT(MOD_LGUI, KC_A), MT(MOD_LALT, KC_S), MT(MOD_LSFT, KC_D), MT(MOD_LCTL, KC_F), KC_G,   KC_H,   MT(MOD_LCTL, KC_J), MT(MOD_RSFT, KC_K), MT(MOD_LALT, KC_L), MT(MOD_RGUI, KC_SCLN), KC_QUOT,     KC_ENT,
        KC_LSFT,KC_Z,               KC_X,               KC_C,               KC_V,               KC_B,   KC_N,   KC_M,               KC_COMM,            KC_DOT,             KC_SLSH,               KC_ENTER,               KC_UP,
        TG(4)  ,KC_LGUI,            KC_LALT,                                LT(3, KC_SPC),                                          KC_RALT,            KC_RCTL,            MO(1),                              KC_LEFT,   KC_DOWN,     KC_RGHT
    ),

  [3] = LAYOUT(
        KC_GRV,   KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,  KC_EQL, KC_DELETE, KC_HOME,
        KC_TILD,  KC_EXLM, KC_AT,  KC_HASH,KC_DLR, KC_PERC,KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_LBRC,  KC_RBRC,KC_BSLS,   KC_END,
        KC_DELETE,KC_QUES, KC_COLN,KC_MINS,KC_UNDS,KC_QUOT,KC_DQUO,KC_EQL, KC_PLUS,KC_LBRC,KC_RBRC,KC_QUOT,  KC_ENT,
        KC_LSFT,  KC_QUOT, KC_DQUO,KC_LT,  KC_GT,  KC_GRV, KC_TILD,KC_BSLS,KC_PIPE,KC_LCBR,KC_RCBR,KC_ENTER,         KC_UP,
        KC_LCTL,  KC_LGUI, KC_LALT,        LT(3, KC_SPC),          KC_RALT,KC_RCTL,MO(1),                    KC_LEFT,KC_DOWN,KC_RGHT
    ),

  [4] = LAYOUT(
        _______,_______,_______,_______,_______,_______,_______,_______      ,_______,_______,_______      ,_______,_______,KC_BSPC,     _______,
        KC_TAB ,_______,_______,_______,_______,_______,_______,KC_LEFT      ,KC_DOWN,KC_UP  ,KC_RGHT      ,KC_BSPC,_______,_______,     _______,
        _______,_______,_______,_______,_______,_______,KC_HOME,LCTL(KC_LEFT),KC_PGDN,KC_PGUP,LCTL(KC_RGHT),KC_END ,       KC_ENTER,
        _______,_______,_______,_______,_______,_______,_______,_______      ,_______,_______,_______      ,_______,       _______  ,
        KC_TRNS,_______,_______,                TG(5)  ,                      _______,_______,_______      ,       _______,_______  ,_______
    ),

  [5] = LAYOUT(
        _______,_______,_______,_______,_______,_______,_______      ,_______            ,_______      ,_______      ,_______             ,_______     ,_______,KC_BSPC,     _______,
        KC_TAB ,_______,_______,_______,_______,_______,_______      ,LSFT(KC_LEFT)      ,LSFT(KC_DOWN),LSFT(KC_UP)  ,LSFT(KC_RGHT)       ,KC_BSPC     ,_______,_______,     _______,
        _______,_______,_______,_______,_______,_______,LSFT(KC_HOME),LCTL(LSFT(KC_LEFT)),LSFT(KC_PGDN),LSFT(KC_PGUP),LCTL(LSFT(KC_RIGHT)),LSFT(KC_END),       KC_ENTER,
        _______,_______,_______,_______,_______,_______,_______      ,_______            ,_______      ,_______      ,_______             ,_______     ,       _______  ,
        KC_TRNS,_______,_______,                KC_TRNS,                                  _______      ,_______      ,_______             ,            _______,_______  ,_______

    ),
};

/* void hook_layer_change(uint32_t layer_state) */
/* { */
/*     // lights LED on Insert when layer 2 is enabled */
/*     if (layer_state & (1L<<2)) { */
/*         PORTB &= ~(1<<5); */
/*         DDRB &= ~(1<<5); */
/*     } else { */
/*         PORTB |=  (1<<5); */
/*         DDRB |=  (1<<5); */
/*     } */
/* } */
