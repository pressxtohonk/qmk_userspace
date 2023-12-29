#include QMK_KEYBOARD_H

// Layer keys
#define NUM_BSPC LT(NUM, KC_BSPC)
#define FUN_TAB  LT(FUN, KC_TAB)
#define NAV_SPC  LT(NAV, KC_SPC)  
#define SYM_SFT  OSM(MOD_LSFT)

// Home row mods
#define HOME_A   MT(MOD_LCTL, KC_A)
#define HOME_R   MT(MOD_LSFT, KC_R)
#define HOME_S   MT(MOD_LGUI, KC_S)
#define HOME_T   MT(MOD_LALT, KC_T)
#define HOME_N   MT(MOD_LALT, KC_N)
#define HOME_E   MT(MOD_LGUI, KC_E)
#define HOME_I   MT(MOD_LSFT, KC_I)
#define HOME_O   MT(MOD_LCTL, KC_O)

// Utils
#define PREV_TAB C(KC_PGUP)
#define NEXT_TAB C(KC_PGDN)
#define BSPC_WRD C(KC_BSPC)

// Keymaps
enum planck_layers {
  BASE,
  NAV,
  NUM,
  FUN,
  SYM,
  ADJ,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
       KC_Q,    KC_W,    KC_F,    KC_P, _______, XXXXXXX, XXXXXXX, _______,    KC_L,    KC_U,    KC_Y, KC_SCLN,
     HOME_A,  HOME_R,  HOME_S,  HOME_T, FUN_TAB, XXXXXXX, XXXXXXX,NUM_BSPC,  HOME_N,  HOME_E,  HOME_I,  HOME_O,
       KC_Z,    KC_X,    KC_C,    KC_D, SYM_SFT, XXXXXXX, XXXXXXX, NAV_SPC,    KC_H, KC_COMM,  KC_DOT, KC_SLSH
),

[NAV] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    G(KC_4), G(KC_3), G(KC_2), G(KC_1), _______, XXXXXXX, XXXXXXX, _______,PREV_TAB,   KC_UP,NEXT_TAB, _______,
    KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, _______, XXXXXXX, XXXXXXX, _______, KC_LEFT, KC_DOWN,KC_RIGHT, _______,
    C(KC_Z), C(KC_Y), C(KC_V), C(KC_C), KC_BSPC, XXXXXXX, XXXXXXX, NAV_SPC, _______, _______, _______, _______
),

[SYM] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX,  KC_ENT, _______, _______, _______, _______
),

[NUM] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
       KC_0,    KC_1,    KC_2,    KC_3, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______,    KC_4,    KC_5,    KC_6, FUN_TAB, XXXXXXX, XXXXXXX,NUM_BSPC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______,    KC_7,    KC_8,    KC_9, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

[FUN] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, FUN_TAB, _______, _______,NUM_BSPC,   KC_F5,   KC_F6,   KC_F7,   KC_F8,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX,   KC_F9,  KC_F10,  KC_F11,  KC_F12
),

[ADJ] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, RGB_TOG,RGB_RMOD, RGB_MOD, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,TO(BASE), _______, _______,TO(BASE), RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX
),
};

// Layers: NUM + FUN => ADJ
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, NUM, FUN, ADJ);
}

// Combos
const uint16_t PROGMEM ft_combo[] = {KC_F, HOME_T, COMBO_END};
const uint16_t PROGMEM st_combo[] = {HOME_S, HOME_T, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {HOME_S, KC_D, COMBO_END};
const uint16_t PROGMEM nu_combo[] = {HOME_N, KC_U, COMBO_END};
const uint16_t PROGMEM ne_combo[] = {HOME_N, HOME_E, COMBO_END};
const uint16_t PROGMEM he_combo[] = {KC_H, HOME_E, COMBO_END};

const uint16_t PROGMEM wf_combo[] = {KC_F, KC_W, COMBO_END};
const uint16_t PROGMEM rs_combo[] = {HOME_R, HOME_S, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_C, KC_X, COMBO_END};
const uint16_t PROGMEM uy_combo[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM ei_combo[] = {HOME_E, HOME_I, COMBO_END};
const uint16_t PROGMEM comm_dot_combo[] = {KC_COMM, KC_DOT, COMBO_END};

const uint16_t PROGMEM DL_combo[] = {KC_LEFT, KC_DOWN, COMBO_END};
const uint16_t PROGMEM DR_combo[] = {KC_DOWN, KC_RIGHT, COMBO_END};

combo_t key_combos[] = {
  COMBO(ft_combo, KC_G),
  COMBO(st_combo, KC_V),
  COMBO(sd_combo, KC_B),
  COMBO(nu_combo, KC_J),
  COMBO(ne_combo, KC_M),
  COMBO(he_combo, KC_K),
  COMBO(wf_combo, KC_Q),
  COMBO(rs_combo, KC_A),
  COMBO(xc_combo, KC_Z),
  COMBO(uy_combo, KC_SCLN),
  COMBO(ei_combo, KC_O),
  COMBO(comm_dot_combo, KC_SLSH),
  COMBO(DL_combo, KC_HOME),
  COMBO(DR_combo, KC_END),
};

uint16_t COMBO_LEN = sizeof(key_combos) / sizeof(*key_combos);


// Custom behaviour
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SYM_SFT:
            return 500;
        default:
            return TAPPING_TERM;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SYM_SFT:
      // Intercept hold start and emulate layer toggle
      if (!record->tap.count && record->event.pressed) {
        layer_on(SYM);
        return false;
      }
      
      // Intercept hold end and emulate layer toggle
      if (!record->tap.count && !record->event.pressed) {
        layer_off(SYM);
        return false;
      }

      break;
  }
  return true;
}
