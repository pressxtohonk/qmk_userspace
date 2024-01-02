#include QMK_KEYBOARD_H

// Home row mods
#define HOME_A    CTL_T(KC_A)
#define HOME_O    CTL_T(KC_O)
#define HOME_R    SFT_T(KC_R)
#define HOME_I    SFT_T(KC_I)
#define HOME_S    GUI_T(KC_S)
#define HOME_E    GUI_T(KC_E)
#define HOME_T    ALT_T(KC_T)
#define HOME_N    ALT_T(KC_N)

// Tap-hold thumb keys
#define SYM_TAB     LT(SYM, KC_TAB)
#define NUM_LEAD    LT(NUM, QK_LEAD) // Can be replaced with a custom key
#define NAV_SPC     LT(NAV, KC_SPC)
#define OSM_SFT     OSM(MOD_LSFT)

// Nav shortcuts
#define PREV_TAB    C(KC_PGUP)
#define NEXT_TAB    C(KC_PGDN)
#define BSPC_WRD    C(KC_BSPC)

enum layers {
  BASE,
  SYM,
  NUM,
  NAV,
  ADJ,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE] = LAYOUT_planck_grid(
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    _______, _______, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
    HOME_A,  HOME_R,  HOME_S,  HOME_T,  KC_V,    _______, _______, KC_M,    HOME_N,  HOME_E,  HOME_I,  HOME_O ,
    KC_Z,    KC_X,    KC_C,    KC_D,    KC_B,    _______, _______, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
    _______, _______, _______, SYM_TAB, OSM_SFT, _______, _______, NUM_LEAD,NAV_SPC, _______, _______, _______
),

[SYM] = LAYOUT_planck_grid(
    S(KC_1), S(KC_2), S(KC_3), S(KC_4), XXXXXXX, _______, _______, KC_GRV,  KC_LCBR, KC_RCBR, KC_UNDS, XXXXXXX,
    S(KC_5), S(KC_6), S(KC_7), S(KC_8), XXXXXXX, _______, _______, KC_QUOT, KC_LPRN, KC_RPRN, KC_COLN,  KC_EQL,
    KC_SLSH, KC_ASTR, KC_MINS, KC_PLUS, XXXXXXX, _______, _______, KC_DQUO, KC_LBRC, KC_RBRC, KC_PIPE, KC_BSLS,
    _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX,  KC_ENT, _______, _______, _______
),

[NUM] = LAYOUT_planck_grid(
       KC_0,    KC_1,    KC_2,    KC_3, XXXXXXX, _______, _______, XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,
    XXXXXXX,    KC_4,    KC_5,    KC_6, XXXXXXX, _______, _______, XXXXXXX,   KC_F5,   KC_F6,   KC_F7,   KC_F8,
    XXXXXXX,    KC_7,    KC_8,    KC_9, XXXXXXX, _______, _______, XXXXXXX,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
    _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, TO(ADJ), _______, _______, _______
),

[NAV] = LAYOUT_planck_grid(
    G(KC_4), G(KC_3), G(KC_2), G(KC_1), XXXXXXX, _______, _______, XXXXXXX,PREV_TAB,   KC_UP,NEXT_TAB, XXXXXXX,
    KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, XXXXXXX, _______, _______, XXXXXXX, KC_LEFT, KC_DOWN,KC_RIGHT, XXXXXXX,
    C(KC_Z), C(KC_Y), C(KC_V), C(KC_C), XXXXXXX, _______, _______, XXXXXXX, KC_BSPC,  KC_ENT,  KC_DEL, XXXXXXX,
    _______, _______, _______, KC_BSPC,BSPC_WRD, _______, _______, TO(ADJ), XXXXXXX, _______, _______, _______
),

[ADJ] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, AC_TOGG, XXXXXXX, _______, _______, XXXXXXX, RGB_TOG, RGB_MOD,RGB_RMOD, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_VOLU, KC_BRIU, XXXXXXX, _______, _______, XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_VOLD, KC_BRID, XXXXXXX, _______, _______, XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX,
    _______, _______, _______, _______,TO(BASE), _______, _______, TO(BASE),XXXXXXX, _______, _______, _______
)

};


// Inner row letters
const uint16_t PROGMEM ft_combo[] = {KC_F, HOME_T, COMBO_END};
const uint16_t PROGMEM st_combo[] = {HOME_S, HOME_T, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {HOME_S, KC_D, COMBO_END};

const uint16_t PROGMEM nu_combo[] = {HOME_N, KC_U, COMBO_END};
const uint16_t PROGMEM ne_combo[] = {HOME_N, HOME_E, COMBO_END};
const uint16_t PROGMEM he_combo[] = {KC_H, HOME_E, COMBO_END};

// Outer row keys
const uint16_t PROGMEM wf_combo[] = {KC_F, KC_W, COMBO_END};
const uint16_t PROGMEM rs_combo[] = {HOME_R, HOME_S, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_C, KC_X, COMBO_END};
const uint16_t PROGMEM uy_combo[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM ei_combo[] = {HOME_E, HOME_I, COMBO_END};
const uint16_t PROGMEM comm_dot_combo[] = {KC_COMM, KC_DOT, COMBO_END};

// Better arrow keys
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

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case OSM_SFT:
            return 500;
        default:
            return TAPPING_TERM;
    }
}


void leader_end_user(void) {
    // Hardware shortcuts
    if (leader_sequence_three_keys(KC_L, KC_E, KC_D)) {
        rgblight_toggle(); // l, e, d => toggles led
        return; 
    }
    
    if (leader_sequence_five_keys(KC_R, KC_E, KC_S, KC_E, KC_T)) {
        bootloader_jump(); // r, e, s, e, t => bootloader mode
        return;
    }    
}

bool process_leader_user(keyrecord_t *record) {
    if (record->tap.count && record->event.pressed) {
        // Intercept tap
        if (!leader_sequence_active()) {
            leader_start(); // Single tap
        } else {
            tap_code16(KC_ESC); // Double tap
        }
    } else {
        // Intercept hold
        if (record->event.pressed) {
            layer_on(NUM); // hold start 
        } else {
            layer_off(NUM); // hold end
        }
    }
    
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NUM_LEAD:
            return process_leader_user(record);
        default:
            return true;
    }
}
