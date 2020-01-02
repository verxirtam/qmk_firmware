#include QMK_KEYBOARD_H

#include "keymap_jp.h"

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
rgblight_config_t RGB_current_config;
#endif

enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  RGBRST
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

//Alt + GRV
#define AGRV LALT(KC_GRV)
//Ctrl + Space
#define CSPC LCTL(KC_SPC)
//英数
#define EISU KC_LANG2
//かな
#define KANA KC_LANG1
//変換
#define HENK KC_INT4
//無変換
#define MHEN KC_INT5

//左ファンクション1キー
#define LFUN1 HENK
//左ファンクション2キー
#define LFUN2 MHEN
//右ファンクション1キー
#define RFUN1 HENK
//右ファンクション2キー
#define RFUN2 MHEN

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* QWERTY
     * ,-------------------------------------------------------.      ,-------------------------------------------------------.
     * |  --  | ESC  |   1  |   2  |   3  |   4  |   5  |   [  |      |   ]  |   6  |   7  |   8  |   9  |   0  | PrSc | Bksp |
     * |------+------+------+------+------+------+------+------|      |------+------+------+------+------+------+------+------|
     * |  --  | Tab  |   Q  |   W  |   E  |   R  |   T  |   -  |      |   =  |   Y  |   U  |   I  |   O  |   P  |   '  | Tab  |
     * |------+------+------+------+------+------+------+------|      |------+------+------+------+------+------+------+------|
     * |  --  | Ctrl |   A  |   S  |   D  |   F  |   G  |   `  |      |   \  |   H  |   J  |   K  |   L  |   ;  | Enter| Enter|
     * |------+------+------+------+------+------+------+------|      |------+------+------+------+------+------+------+------|
     * |  --  | Shift|   Z  |   X  |   C  |   V  |   B  | Menu |      |  Del |   N  |   M  |   ,  |   .  |   /  |  Up  | Shift|
     * |------+------+------+------+------+------+------+------|      |------+------+------+------+------+------+------+------|
     * |  --  |Adjust| GUI  | Alt  |  Fn2 |  Fn1 | Lower| Space|      | Enter| Raise|  Fn1 |  Fn2 |  Alt | Left | Down | Right|
     * `-------------------------------------------------------'      `-------------------------------------------------------'
     */
  [_QWERTY] = LAYOUT(
      XXXXXXX,   KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    JP_LBRC,     JP_RBRC,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PSCR, KC_BSPC,
      XXXXXXX,   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    JP_MINS,     JP_EQL,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    JP_QUOT, KC_TAB,
      XXXXXXX,   KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    JP_GRV,      JP_BSLS,  KC_H,    KC_J,    KC_K,    KC_L,    JP_SCLN, KC_ENT,  KC_ENT,
      XXXXXXX,   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_APP,      KC_DEL,   KC_N,    KC_M,    JP_COMM, JP_DOT,  JP_SLSH, KC_UP,   KC_RSFT,
      XXXXXXX,   ADJUST,  KC_LGUI, KC_LALT, LFUN2,   LFUN1,   LOWER,   KC_SPC,      KC_ENT,   RAISE,  RFUN1,    RFUN2,   KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT
      ),

    /* Lower
     * ,-------------------------------------------------------.      ,-------------------------------------------------------.
     * |  --  |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |   {  |      |   }  |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |      |
     * |------+------+------+------+------+------+------+------|      |------+------+------+------+------+------+------+------|
     * |  --  |      |   !  |   @  |   #  |   $  |   %  |   _  |      |   +  |   ^  |   &  |   *  |   (  |   )  |   "  |      |
     * |------+------+------+------+------+------+------+------|      |------+------+------+------+------+------+------+------|
     * |  --  |      |   1  |   2  |   3  |   4  |   5  |   ~  |      |   |  |   H  |   _  |   +  |   L  |   :  |      |      |
     * |------+------+------+------+------+------+------+------|      |------+------+------+------+------+------+------+------|
     * |  --  |      |   6  |   7  |   8  |   9  |   0  |      |      |      |   N  |   M  |   <  |   >  |   ?  |PageUp|      |
     * |------+-------------+------+------+------+------+------|      |------+------+------+------+------+--------------------|
     * |  --  |      |      |      |      |      |      |      |      |      |      |      |      |      | Home |PageDn|  End |
     * ,-------------------------------------------------------'      `-------------------------------------------------------.
     */
  [_LOWER] = LAYOUT(
      XXXXXXX,   KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   JP_LCBR,     JP_RCBR, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,  _______,
      XXXXXXX,   _______, JP_EXLM, JP_AT,   JP_HASH, JP_DLR,  JP_PERC, JP_UNDS,     JP_PLUS, JP_CIRC, JP_AMPR, JP_ASTR, JP_LPRN, JP_RPRN, JP_DQT,  _______,
      XXXXXXX,   _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    JP_TILD,     JP_PIPE, KC_H,    JP_UNDS, JP_PLUS, KC_L,    JP_COLN, _______, _______,
      XXXXXXX,   _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,     _______, KC_N,    KC_M,    JP_LT,   JP_GT,   JP_QUES, KC_PGUP, _______,
      XXXXXXX,   _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_END

  ),

  /* RAISE
     * ,-------------------------------------------------------.      ,-------------------------------------------------------.
     * |  --  |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |   {  |      |   }  |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |      |
     * |------+------+------+------+------+------+------+------|      |------+------+------+------+------+------+------+------|
     * |  --  |      |   !  |   @  |   #  |   $  |   %  |   _  |      |   +  |   ^  |   &  |   *  |   (  |   )  |   "  |      |
     * |------+------+------+------+------+------+------+------|      |------+------+------+------+------+------+------+------|
     * |  --  |      |   1  |   2  |   3  |   4  |   5  |   ~  |      |   |  |   H  |   -  |   =  |   L  |   :  |      |      |
     * |------+------+------+------+------+------+------+------|      |------+------+------+------+------+------+------+------|
     * |  --  |      |   6  |   7  |   8  |   9  |   0  |      |      |      |   N  |   M  |   <  |   >  |   ?  |PageUp|      |
     * |------+-------------+------+------+------+------+------|      |------+------+------+------+------+--------------------|
     * |  --  |      |      |      |      |      |      |      |      |      |      |      |      |      | Home |PageDn|  End |
     * ,-------------------------------------------------------'      `-------------------------------------------------------.
     */
  [_RAISE] = LAYOUT(
      XXXXXXX,   KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   JP_LCBR,     JP_RCBR, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,  _______,
      XXXXXXX,   _______, JP_EXLM, JP_AT,   JP_HASH, JP_DLR,  JP_PERC, JP_UNDS,     JP_PLUS, JP_CIRC, JP_AMPR, JP_ASTR, JP_LPRN, JP_RPRN, JP_DQT,  _______,
      XXXXXXX,   _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    JP_TILD,     JP_PIPE, KC_H,    JP_MINS, JP_EQL,  KC_L,    JP_COLN, _______, _______,
      XXXXXXX,   _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,     _______, KC_N,    KC_M,    JP_LT,   JP_GT,   JP_QUES, KC_PGUP, _______,
      XXXXXXX,   _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_END

  ),

    /* Adjust
     * ,-------------------------------------------------------.      ,-------------------------------------------------------.
     * |  --  |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------|      |------+------+------+------+------+------+------+------|
     * |  --  |      | RESET|RGBRST|      |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------|      |------+------+------+------+------+------+------+------|
     * |  --  |      |      |  TOG |  HUI |  SAI |  VAI |      |      |      |      |PrnScr|ScrLck| Pause|      |      |      |
     * |------+------+------+------+------+------+------+------|      |------+------+------+------+------+------+------+------|
     * |  --  |      |      |  MOD |  HUD |  SAD |  VAD |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------|      |------+------+------+------+------+------+------+------|
     * |  --  |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
     * `-------------------------------------------------------'      `-------------------------------------------------------'
     */
  [_ADJUST] =  LAYOUT(
      _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, RESET,   RGBRST,  _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______,    _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, _______, _______, _______,
      _______, _______, _______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______,    _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______
      )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
      case QWERTY:
        if (record->event.pressed) {
           print("mode just switched to qwerty and this is a huge string\n");
          set_single_persistent_default_layer(_QWERTY);
        }
        break;

	  case LOWER:
        if (record->event.pressed) {
          layer_on(_LOWER);
          update_tri_layer(_LOWER, _RAISE, _ADJUST);
        } else {
          layer_off(_LOWER);
          update_tri_layer(_LOWER, _RAISE, _ADJUST);
        }
        return false;
        break;

	  case RAISE:
        if (record->event.pressed) {
          layer_on(_RAISE);
          update_tri_layer(_LOWER, _RAISE, _ADJUST);
        } else {
          layer_off(_RAISE);
          update_tri_layer(_LOWER, _RAISE, _ADJUST);
        }
        return false;
        break;

	  case ADJUST:
          if (record->event.pressed) {
            layer_on(_ADJUST);
          } else {
            layer_off(_ADJUST);
          }
        break;

      case RGBRST:
        #ifdef RGBLIGHT_ENABLE
          if (record->event.pressed) {
            eeconfig_update_rgblight_default();
            rgblight_enable();
            RGB_current_config = rgblight_config;
          }
        #endif
        break;
  }
  return true;
}
