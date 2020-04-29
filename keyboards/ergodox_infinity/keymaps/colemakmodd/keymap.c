#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define GAME 3
#define QWRT 4

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
*
* ,--------------------------------------------------.           ,--------------------------------------------------.
* |  ~     |   1  |   2  |   3  |   4  |   5  | LOCK |           | PRSC |   6  |   7  |   8  |   9  |   0  | Layer  |
* |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
* | Tab    |   Q  |   W  |   F  |   P  |   B  |  [   |           |  ]   |   J  |   L  |   U  |   Y  |   ;  |   \    |
* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
* | Lctl   |   A  |   R  |   S  |   T  |   G  |------|           |------|   M  |   N  |   E  |   I  |   O  |     '  |
* |--------+------+------+------+------+------|   -  |           |  =   |------+------+------+------+------+--------|
* | LShift |  Z  |   X  |   C  |   D  |   V   |      |           |      |   K  |   H  |   ,  |   .  |   /  | RShift |
* `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
*   |L_RALT | WIN  | F13 |ALT/MDIA|F14/SYMB|                                 |DN/SYMB |UP/MDIA| LFT  | RGT ||
*   `--------------------------------------'                                  `------------------------------------'
*                                        ,-------------.       ,-------------.
*                                        |PG_UP | PG_DN|       | ESC | Layer |
*                                 ,------|------|------|       |------+--------+------.
*                                 |      |      | Home |       | VOLU |        |      |
*                                 | Space| DEL  |------|       |------|  Enter | BSPC |
*                                 |      |      | End  |       | VOLD |        |      |
*                                 `--------------------'       `----------------------'
*/
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,        KC_1,         KC_2,        KC_3,                 KC_4,         KC_5,         KC_LOCK,
        KC_TAB,         KC_Q,         KC_W,        KC_F,                 KC_P,         KC_B,         KC_LBRC,
        KC_LCTL,        KC_A,         KC_R,        KC_S,                 KC_T,         KC_G,
        KC_LSFT,        KC_Z,         KC_X,        KC_C,                 KC_D,         KC_V,         KC_MINS,
        KC_RALT,        KC_LGUI,      KC_F13,      LT(2,KC_LALT),        LT(1,KC_F14),
                                                   KC_PGUP,              KC_PGDN,
                                                                         KC_HOME,
                                      KC_SPC,      KC_DEL,               KC_END,
        // right hand
        KC_PSCR,         KC_6,         KC_7,                   KC_8,                KC_9,         KC_0,         KC_C,
        KC_RBRC,         KC_J,         KC_L,                   KC_U,                KC_Y,         KC_SCLN,      KC_BSLS,
                         KC_M,         KC_N,                   KC_E,                KC_I,         KC_O,         KC_QUOT,
        KC_EQUAL,        KC_K,         KC_H,                   KC_COMM,             KC_DOT,       KC_SLSH,      KC_RSFT,
                                       LT(1, KC_DOWN),         LT(2, KC_UP),        KC_LEFT,      KC_RIGHT,      KC_MNXT,
                                       KC_VOLD,      KC_VOLU,
                                       KC_PGUP,
                                       KC_PGDN,      KC_ENTER,      KC_BSPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       VRSN,         KC_F1,         KC_F2,      KC_F3,   KC_F4,    KC_F5,     KC_TRNS,
       KC_TRNS,      KC_EXLM,       KC_AT,      KC_LCBR, KC_RCBR,  KC_PIPE,   KC_TRNS,
       KC_TRNS,      KC_HASH,       KC_DLR,     KC_LPRN, KC_RPRN,  KC_GRV,
       KC_TRNS,      KC_PERC,       KC_CIRC,    KC_LBRC, KC_RBRC,  KC_TILD,   KC_TRNS,
          EPRM,      KC_TRNS,       KC_TRNS,    KC_TRNS, KC_TRNS,
                                       KC_TRNS, KC_TRNS,
                                                KC_TRNS,
                               KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_TRNS,      KC_F6,          KC_F7,      KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS,      KC_TRNS,        KC_7,       KC_8,    KC_9,    KC_ASTR, KC_F12,
                     LSFT(KC_SCLN),  KC_4,       KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS,      KC_BSLS,        KC_1,       KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_0,   KC_0,    KC_DOT,    KC_EQL,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_ENTER, KC_BSPC
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                      KC_TRNS, KC_TRNS,
                                               KC_TRNS,
                             KC_TRNS, KC_TRNS, KC_TRNS,
// right hand
  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
  KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                     KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_WBAK
),

/* Keymap 0: Game layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LOCK |           | MUTE |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   F  |   P  |   B  |  [   |           |  ]   |   J  |   L  |   U  |   Y  |   ;  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Lctl   |   A  |   R  |   S  |   T  |   G  |------|           |------|   M  |   N  |   E  |   I  |   O  |' / RCTL |
 * |--------+------+------+------+------+------|   -  |           |  =    |------+------+------+------+------+--------|
 * | LShift |  Z  |   X  |   C  |   D  |   V   |      |           |      |   K  |   H  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |L_ALT | WIN  |AltShf|PU/MDA | PD/SYMB|                                 |DN/SYMB|UP/MDIA| LFT| RGT | KC_MNXT|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | PRSR | Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | VOLU |        |      |
 *                                 | Space| DEL  |------|       |------|  Enter | BSPC |
 *                                 |      |      | End  |       | VOLD |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[GAME] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,        KC_1,         KC_2,        KC_3,                 KC_4,         KC_5,         KC_LOCK,
        KC_TAB,         KC_Q,         KC_W,        KC_F,                 KC_P,         KC_B,         KC_LBRC,
        KC_LCTL,        KC_A,         KC_R,        KC_S,                 KC_T,         KC_G,
        KC_LSFT,        KC_Z,         KC_X,        KC_C,                 KC_D,         KC_V,         KC_MINS,
        KC_RALT,        KC_LGUI,      KC_F13,      LT(2,KC_LALT),        LT(1,KC_F14),
                                                   KC_PGUP,              KC_PGDN,
                                                                         KC_HOME,
                                      KC_SPC,      KC_DEL,               KC_END,
        // right hand
        KC_PSCR,         KC_6,         KC_7,                   KC_8,                KC_9,         KC_0,         KC_C,
        KC_RBRC,         KC_J,         KC_L,                   KC_U,                KC_Y,         KC_SCLN,      KC_BSLS,
                         KC_M,         KC_N,                   KC_E,                KC_I,         KC_O,         KC_QUOT,
        KC_EQUAL,        KC_K,         KC_H,                   KC_COMM,             KC_DOT,       KC_SLSH,      KC_RSFT,
                                       LT(1, KC_DOWN),         LT(2, KC_UP),        KC_LEFT,      KC_RIGHT,      KC_MNXT,
                                       KC_VOLD,      KC_VOLU,
                                       KC_PGUP,
                                       KC_PGDN,      KC_ENTER,      KC_BSPC
    ),
    [QWRT] = LAYOUT_ergodox(  // layer 0 : default
            // left hand
            KC_ESC,        KC_1,         KC_2,        KC_3,                 KC_4,         KC_5,         KC_LOCK,
            KC_TAB,         KC_Q,         KC_W,        KC_F,                 KC_P,         KC_B,         KC_LBRC,
            KC_LCTL,        KC_A,         KC_R,        KC_S,                 KC_T,         KC_G,
            KC_LSFT,        KC_Z,         KC_X,        KC_C,                 KC_D,         KC_V,         KC_MINS,
            KC_RALT,        KC_LGUI,      KC_F13,      LT(2,KC_LALT),        LT(1,KC_F14),
                                                       KC_PGUP,              KC_PGDN,
                                                                             KC_HOME,
                                          KC_SPC,      KC_DEL,               KC_END,
            // right hand
            KC_PSCR,         KC_6,         KC_7,                   KC_8,                KC_9,         KC_0,         KC_C,
            KC_RBRC,         KC_J,         KC_L,                   KC_U,                KC_Y,         KC_SCLN,      KC_BSLS,
                             KC_M,         KC_N,                   KC_E,                KC_I,         KC_O,         KC_QUOT,
            KC_EQUAL,        KC_K,         KC_H,                   KC_COMM,             KC_DOT,       KC_SLSH,      KC_RSFT,
                                           LT(1, KC_DOWN),         LT(2, KC_UP),        KC_LEFT,      KC_RIGHT,      KC_MNXT,
                                           KC_VOLD,      KC_VOLU,
                                           KC_PGUP,
                                           KC_PGDN,      KC_ENTER,      KC_BSPC
        ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
