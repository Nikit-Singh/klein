#include QMK_KEYBOARD_H

#undef TAPPING_TERM
#define TAPPING_TERM 400

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

#undef PERMISSIVE_HOLD
#undef HOLD_ON_OTHER_KEY_PRESS

// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    64

enum klein_keymap_layers {
    L_BASE = 0,
    L_NUM,
    L_SYM,
    L_NAV,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐      [4]   [5]    ┌───┐
      *           │ 1 ├───┐           ┌───┤ 8 │
      *           └───┤ 2 ├───┐   ┌───┤ 7 ├───┘
      *               └───┤ 3 │   │ 6 ├───┘
      *                   └───┘   └───┘
      */
  [L_BASE] = LAYOUT_split_3x5_4(
  // ╭─────────────────────────────────────────────────────────────╮                      ╭────────────────────────────────────────────────────────────────╮
      KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,                        KC_Y, KC_U,         KC_I,         KC_O,         KC_P,
  // ├─────────────────────────────────────────────────────────────┤                      ├────────────────────────────────────────────────────────────────┤
      LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,                        KC_H, RSFT_T(KC_J), RCTL_T(KC_K), LALT_T(KC_L), RGUI_T(KC_SCLN),
  // ├─────────────────────────────────────────────────────────────┤                      ├────────────────────────────────────────────────────────────────┤
      LCTL_T(KC_Z),         KC_X,         KC_C,     KC_V,     KC_B,                        KC_N, KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
  // ╰─────────────────────────────────────────────────────────────╯                      ╰────────────────────────────────────────────────────────────────╯
      KC_ESC, LT(L_SYM, KC_TAB), LT(L_NAV, KC_SPC), QK_BOOT,                               QK_BOOT, LT(L_NAV, KC_BSPC), LT(L_NUM, KC_ENT),  KC_DEL
  // ╰───────────────────────────────────────────────────────────────────╯              ╰─────────────────────────────────────────────────────────────────╯
  ),

    [L_NUM] = LAYOUT_split_3x5_4(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
         KC_1,   KC_2,   KC_3,   KC_4,   KC_5,               KC_6, KC_7,   KC_8,   KC_9,   KC_0,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
        LGUI_T(KC_EXLM), LALT_T(KC_AT), LCTL_T(KC_HASH), LSFT_T(KC_DLR), KC_PERC,    KC_CIRC, RSFT_T(KC_AMPR), RCTL_T(KC_ASTR), LALT_T(KC_TILD), RGUI_T(KC_GRV),
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
         KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,  KC_F7, KC_F8, KC_F9, KC_F10,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                      KC_NO, KC_NO, KC_NO, QK_BOOT,    QK_BOOT, KC_BSPC, KC_F11, KC_F12
  //                 ╰─────────────────────────────╯ ╰────────────────────────────────╯
  ),

    [L_SYM] = LAYOUT_split_3x5_4(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
         KC_PLUS, KC_UNDS, KC_NO, KC_NO, KC_NO,     KC_PIPE, KC_LPRN,   KC_RPRN,   KC_MINUS,   KC_EQL,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
         KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_CAPS,  KC_BSLS, RSFT_T(KC_LCBR), RCTL_T(KC_RCBR), LALT_T(KC_QUOT), RGUI_T(KC_DQT),
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,            KC_NO,  KC_LBRC, KC_RBRC, KC_NO, KC_NO,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                      KC_NO, KC_NO, KC_NO, QK_BOOT,    QK_BOOT, KC_BSPC, KC_ENT, KC_DEL
  //                 ╰─────────────────────────────╯ ╰────────────────────────────────╯
  ),

   [L_NAV] = LAYOUT_split_3x5_4(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
         KC_WH_L, KC_BTN1, KC_BTN3, KC_BTN2, KC_WH_R,       KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_BSPC,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
         KC_WH_U, KC_WH_D, LGUI(KC_BSPC), LCTL(KC_BSPC), KC_BSPC,    KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_PSCR,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
         KC_NO,   KC_NO,   KC_NO, KC_MSTP, KC_MUTE,    KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                   KC_DOT, KC_0, KC_MINS, QK_BOOT,    QK_BOOT, KC_BSPC, KC_ENT, KC_DEL
  //              ╰────────────────────────────────╯ ╰────────────────────────────────╯
  ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [L_BASE] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [L_NUM] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [L_SYM] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [L_NAV] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
};
#endif
