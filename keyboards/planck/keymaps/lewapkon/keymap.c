/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _GAME,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  GAME
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Ent/St|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  | Ctrl |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise |AltGr | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,    KC_Y,    KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC       },
  {KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,  KC_G,    KC_H,    KC_J,  KC_K,    KC_L,    KC_SCLN, RSFT_T(KC_ENT)},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,    KC_N,    KC_M,  KC_COMM, KC_DOT,  KC_UP,   KC_RCTL       },
  {BL_TOGG, KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPC,  KC_SPC,  RAISE, KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT       }
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Del  |  F1  |  F2  |  F3  |  F4  |      |   7  |   8  |   9  |   +  |   *  |  \   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |      |   4  |   5  |   6  |   =  |   _  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |      |   1  |   2  |   3  |   -  |   /  |  ?   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |   0  |   .  |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, KC_7,    KC_8,    KC_9, KC_PLUS, KC_ASTR, KC_BSLS},
  {_______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, KC_4,    KC_5,    KC_6, KC_EQL,  KC_UNDS, KC_PIPE},
  {_______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_1,    KC_2,    KC_3, KC_MINS, KC_SLSH, KC_QUES},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_0, KC_DOT,  _______, _______}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |      | Next | Vol- | Vol+ | Play | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   `  |   '  |   {  |   [  |   (  |   ^  |      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   "  |   }  |   ]  |   )  |   &  |      |Pg Up |Pg Dn | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, KC_DEL },
  {KC_GRV,  KC_QUOT, KC_LCBR, KC_LBRC, KC_LPRN, KC_CIRC, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______},
  {_______, KC_DQUO, KC_RCBR, KC_RBRC, KC_RPRN, KC_AMPR, _______, KC_PGUP, KC_PGDN, KC_HOME, KC_END,  _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Game
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Alt  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Shift|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Ctrl |   Z  |   X  |   C  |   V  |    Space    |   B  |   N  |   M  |Lower |Raise |
 * `-----------------------------------------------------------------------------------'
 */
[_GAME] = {
  {KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LALT},
  {KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT },
  {KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_SPC,  KC_SPC,  KC_B,    KC_N,    KC_M,    LOWER,   RAISE  }

},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty| Game |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL },
  {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  GAME,     _______, _______, _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______}
}

};

#ifdef AUDIO_ENABLE
  float game_song[][2]     = SONG(ONE_UP_SOUND);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case GAME:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(game_song);
        #endif
        set_single_persistent_default_layer(_GAME);
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
  }
  return true;
}
