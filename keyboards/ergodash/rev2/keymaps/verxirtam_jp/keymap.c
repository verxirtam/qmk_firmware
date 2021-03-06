#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  UJ_2,
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

//左ファンクションキー
#define LFUN EISU
//右ファンクションキー
#define RFUN HENK


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | ESC  |   1  |   2  |   3  |   4  |   5  |   [  |                    |   ]  |   6  |   7  |   8  |   9  |   0  | Bksp |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   -  |                    |   =  |   Y  |   U  |   I  |   O  |   P  |  '   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |   `  |                    |   \  |   H  |   J  |   K  |   L  |   ;  | Enter|
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |  App |                    |Delete|   N  |   M  |   ,  |   .  |  Up  |  /   |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |ADJUST|  GUI |  ALt | LFUN |||||||| Lower| Space|      ||||||||      | Enter| Raise|||||||| RFUN | Left | Down | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    KC_ESC,  KC_1,    UJ_2,    KC_3,    KC_4,    KC_5,    JP_LBRC,                        JP_RBRC, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    JP_MINS,                        JP_EQL , KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    JP_QUOT, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    JP_GRV ,                        JP_BSLS, KC_H,    KC_J,    KC_K,    KC_L,    JP_SCLN, KC_ENT,  \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_APP ,                        KC_DEL , KC_N,    KC_M,    JP_COMM, JP_DOT,  KC_UP,   JP_SLSH, \
    ADJUST,  KC_LGUI, KC_LALT, LFUN,             LOWER,   KC_SPC ,_______,        _______,KC_ENT , RAISE,            RFUN,    KC_LEFT, KC_DOWN, KC_RGHT  \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |   {  |                    |   }  |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |   !  |   @  |   #  |   $  |   %  |   _  |                    |   +  |   ^  |   &  |   *  |   (  |   )  |   "  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |   1  |   2  |   3  |   4  |   5  |   ~  |                    |   |  |   H  |   _  |   +  |   L  |   :  |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |   6  |   7  |   8  |   9  |   0  |      |                    |      |   N  |   M  |   <  |   >  |PageUp|   ?  |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      | Home |PageDn|  End |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   JP_LCBR,                        JP_RCBR, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,  \
    _______, JP_EXLM, JP_AT,   JP_HASH, JP_DLR,  JP_PERC, JP_UNDS,                        JP_PLUS, JP_CIRC, JP_AMPR, JP_ASTR, JP_LPRN, JP_RPRN, JP_DQT,  \
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    JP_TILD,                        JP_PIPE, KC_H,    JP_UNDS, JP_PLUS, KC_L,    JP_COLN, _______, \
    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,                        _______, KC_N,    KC_M,    JP_LT,   JP_GT,   KC_PGUP, JP_QUES, \
    _______, _______, _______, _______,          _______, _______,_______,        _______,_______, _______,          _______, KC_HOME, KC_PGDN, KC_END   \
  ),

  /* Raise
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |   {  |                    |   }  |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |   !  |   @  |   #  |   $  |   %  |   _  |                    |   +  |   ^  |   &  |   *  |   (  |   )  |  "   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |   1  |   2  |   3  |   4  |   5  |   ~  |                    |   |  |   H  |   -  |   =  |   L  |   :  |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |   6  |   7  |   8  |   9  |   0  |      |                    |      |   N  |   M  |   <  |   >  |PageUp|  ?   |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      | Home |PageDn|  End |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_RAISE] = LAYOUT(
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   JP_LCBR,                        JP_RCBR, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,  \
    _______, JP_EXLM, JP_AT,   JP_HASH, JP_DLR,  JP_PERC, JP_UNDS,                        JP_PLUS, JP_CIRC, JP_AMPR, JP_ASTR, JP_LPRN, JP_RPRN, JP_DQT,  \
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    JP_TILD,                        JP_PIPE, KC_H,    JP_MINS, JP_EQL,  KC_L,    JP_COLN, _______, \
    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,                        _______, KC_N,    KC_M,    JP_LT,   JP_GT,   KC_PGUP, JP_QUES, \
    _______, _______, _______, _______,          _______, _______,_______,        _______,_______, _______,          _______, KC_HOME, KC_PGDN, KC_END   \
),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      | Reset|RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |BL_TOG|BL_BRT|BL_INC|BL_DEC|      |                    |      |      |PrnScr|ScrLck|Pause |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |  HENK|  MHEN|  EISU|  KANA|      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,_______,                       _______, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______, \
    _______, _______, BL_TOGG, BL_BRTG, BL_INC , BL_DEC ,_______,                       _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, _______, _______, \
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______,    HENK,    MHEN,    EISU,    KANA, _______, \
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______  \
  )
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// case UJ_2:                // JIS の「2」と「@」を模擬するための実装
bool process_record_user_uj_2(uint16_t keycode, keyrecord_t *record)
{
    if(record->event.pressed)
    {
        static bool lshift = false;
        static bool rshift = false;
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        if (lshift || rshift)
		{
			//shiftが押されている場合"@"を入力
            if (lshift) unregister_code(KC_LSFT);
            if (rshift) unregister_code(KC_RSFT);
            register_code(  KC_LBRC);//OSが日本語配列の場合の@
            unregister_code(KC_LBRC);
            if (lshift) register_code(KC_LSFT);
            if (rshift) register_code(KC_RSFT);
        }
		else
		{
			//shiftが押されていない場合"2"を入力
            register_code(KC_2);
            unregister_code(KC_2);
		}
    }
    return false;
}



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
         print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
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
      return false;
      break;
    case UJ_2:
	  return process_record_user_uj_2(keycode, record);
	  break;
  }
  return true;
}
