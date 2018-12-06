
#include QMK_KEYBOARD_H

// Used for SHIFT_ESC
#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL 1
#define _NL 2

#define _______ KC_TRNS


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*======================================================================================================================*/
  /*======================================================================================================================*/
  /* Keymap _BL: (Base Layer) Default Layer
   * ,-----------------------------------------------------------.
   * |Esc~| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |
   * |-----------------------------------------------------------|
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift     |
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space            |Alt |FN  |_FL |Ctrl |
   * `-----------------------------------------------------------'
   */
[_BL] = LAYOUT_60_ansi(
  F(0),    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC, \
  KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS, \
  KC_CAPS, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,        KC_ENT , \
  KC_LSFT,         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,        KC_RSFT, \
  KC_LCTL, KC_LGUI,KC_LALT,                KC_SPC,                                 KC_RALT,MO(_FL),TO(_FL),KC_RCTL),

  /*======================================================================================================================*/
  /*======================================================================================================================*/
  /* Keymap _FL: Function Layer
   * ,-----------------------------------------------------------.
   * |'  |F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|DELETE |
   * |-----------------------------------------------------------|
   * |     |NO | ^ |NO |   |   |RST|DBG|   |   |PSC|SLC|PAU|     |
   * |-----------------------------------------------------------|
   * |NO    |<- | v |-> |NO |   |   |   |   |INS|HOM|UP |        |
   * |-----------------------------------------------------------|
   * |        |   |   |BL-|BL+|BL |BBT|   |   |END|DWN|          |
   * |-----------------------------------------------------------|
   * |    |_BL |    |                        |    |    |_NL |    |
   * `-----------------------------------------------------------'
   */
[_FL] = LAYOUT_60_ansi(
  KC_GRV ,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_6   ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_DEL , \
  _______,KC_NO  ,KC_UP  ,KC_NO  ,_______,_______,RESET  ,DEBUG  ,_______,_______,KC_PSCR,KC_SLCK,KC_PAUS,_______, \
  KC_NO  ,KC_LEFT,KC_DOWN,KC_RGHT,KC_NO  ,_______,_______,_______,_______,KC_INS ,KC_HOME,KC_PGUP,        _______, \
  _______,        _______,_______,BL_DEC ,BL_INC ,BL_TOGG,BL_BRTG,_______,_______,KC_END ,KC_PGDOWN,      _______, \
  _______,TO(_BL),_______,                _______,                                _______,_______,TO(_NL),_______),

  /*======================================================================================================================*/
  /*======================================================================================================================*/
  /* Keymap _NL: Numpad Layer
   * ,-----------------------------------------------------------.
   * |   |  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|Nu-|Nu+|       |
   * |-----------------------------------------------------------|
   * |     |   |   |   |   |   |   |  4|  5|  6|   |   |   |     |
   * |-----------------------------------------------------------|
   * |      |   |   |   |   |   |   |  1|  2|  3|Nu*|   |        |
   * |-----------------------------------------------------------|
   * |        |   |   |   |   |   |   |  0|  0|Nu.|Nu/|          |
   * |-----------------------------------------------------------|
   * |    |_BL |    |                        |    |    |_BL |    |
   * `-----------------------------------------------------------'
   */
[_NL] = LAYOUT_60_ansi(
  _______,KC_P1  ,KC_P2  ,KC_P3  ,KC_P4  ,KC_P5  ,KC_P6  ,KC_P7  ,KC_P8  ,KC_P9  ,KC_0   ,KC_PMNS,KC_PPLS,_______, \
  _______,_______,_______,_______,_______,_______,_______,KC_P4  ,KC_P5  ,KC_P6  ,_______,_______,_______,_______, \
  _______,_______,_______,_______,_______,_______,_______,KC_P1  ,KC_P2  ,KC_P3  ,KC_PAST,_______,        _______, \
  _______,        _______,_______,_______,_______,_______,_______,KC_P0  ,KC_P0  ,KC_PDOT,KC_PSLS,        _______, \
  _______,TO(_BL),_______,                _______,                                _______,_______,TO(_BL),_______),

  /*======================================================================================================================*/
  /*======================================================================================================================*/
};

enum function_id {
    SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(SHIFT_ESC),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t shift_esc_shift_mask;
  switch (id) {
    case SHIFT_ESC:
      shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
      if (record->event.pressed) {
        if (shift_esc_shift_mask) {
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        if (shift_esc_shift_mask) {
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
  }
}


//////////////////////////////////////////
// 下記は追加した関数
//////////////////////////////////////////

/*
//レイヤー切替時にLEDの発光モードを変更する
uint32_t layer_state_set_user(uint32_t state)
{
    switch (biton32(state))
	{
    case _FL:
		//printf("layer: _FL");
		#ifdef BACKLIGHT_BREATHING
			//printf(", BACKLIGHT_BREATHING");
			//バックライトLEDのモード変更
			breathing_enable();
		#endif
		break;
    default: //  for any other layers, or the default layer
		//printf("layer: _BL");
		#ifdef BACKLIGHT_BREATHING
			//printf(", BACKLIGHT_BREATHING");
			//バックライトLEDのモード変更
			breathing_disable();
		#endif
		break;
    }
  return state;
}
*/

