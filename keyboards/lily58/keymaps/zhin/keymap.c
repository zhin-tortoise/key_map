#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif


extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                     ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                     |   6  |   7  |   8  |   9  |   0  |   `  |
 * |------+------+------+------+------+------|                     |------+------+------+------+------+------|
 * | Tab  |   q  |   w  |   e  |   r  |   t  |                     |   y  |   u  |   i  |   o  |   p  |      |
 * |------+------+------+------+------+------|                     |------+------+------+------+------+------|
 * |Shift |   a  |   s  |   d  |   f  |   g  |--------.    ,-------|   h  |   j  |   k  |   l  |      |      |
 * |------+------+------+------+------+------|        |    |       |------+------+------+------+------+------|
 * | CTRL |   z  |   x  |   c  |   v  |   b  |--------|    |-------|   n  |   m  |   ,  |      | Alt  |      |
 * `-----------------------------------------/        /     \      \-----------------------------------------'
 *                  |KC_LGUI|BackSP| Space | / LOWER /       \RAISE \  |Enter |Delete|      |
 *                   `---------------------''-------'         '------''---------------------'

 */

/* QWERTY(Shift)
 * ,-----------------------------------------.                     ,-----------------------------------------.
 * | ESC  |   !  |   "  |   #  |   $  |   %  |                     |   &  |   '  |   (  |   )  |   ~  |   `  |
 * |------+------+------+------+------+------|                     |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                     |   Y  |   U  |   I  |   O  |   P  |      |
 * |------+------+------+------+------+------|                     |------+------+------+------+------+------|
 * |Shift |   A  |   S  |   D  |   F  |   G  |--------.    ,-------|   H  |   J  |   K  |   L  |      |      |
 * |------+------+------+------+------+------|        |    |       |------+------+------+------+------+------|
 * | CTRL |   Z  |   X  |   C  |   V  |   B  |--------|    |-------|   N  |   M  |      |      | Alt  |      |
 * `-----------------------------------------/        /     \      \-----------------------------------------'
 *                  |KC_LGUI|BackSP| Space | / LOWER /       \RAISE \  |Enter |Delete|      |
 *                   `---------------------''-------'         '------''---------------------'
 */

  [_QWERTY] = LAYOUT( \
    KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV, \
    KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX, \
    KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    XXXXXXX, XXXXXXX, \
    KC_LCTRL, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,   XXXXXXX,  XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, \
                               KC_LGUI, KC_BSPC, KC_SPC, LOWER,    RAISE,   KC_ENT,  KC_DEL,  XXXXXXX \
  ),

/* LOWER
 * ,------------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6   |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+-------|                    |------+------+------+------+------+------|
 * |______|   =  |   ^  |   ~  |   |  |______ |                    |______|   [  |   ]  |   {  |   }  |______|
 * |------+------+------+------+------+-------|                    |------+------+------+------+------+------|
 * |______|   @  |   `  |   :  |   ;  |______ |-------.    ,-------|______|   +  |   -  |   *  |   /  |______|
 * |------+------+------+------+------+-------|______ |    |______ |------+------+------+------+------+------|
 * |______|   ,  |   .  |   ?  |   _  |______ |-------|    |-------|______|   <  |   >  |   \  |   ?  |______|
 * `------------------------------------------/       /     \      \-----------------------------------------'
 *                   |______ |______|______| /______ /       \______\  |______|______|______|
 *                   `---------------------''-------'         '--------''-------------------'
 */

  [_LOWER] = LAYOUT( \
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,\
    _______, KC_PEQL, KC_CIRC, KC_TILD, KC_PIPE, _______,                   _______, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, _______, \
    _______, KC_AT,   KC_GRV,  KC_COLN, KC_SCLN, _______,                   _______, KC_PPLS, KC_PMNS, KC_PAST, KC_PSLS, _______, \
    _______, KC_COMM, KC_DOT,  KC_QUES, KC_UNDS, _______, _______, _______, _______, KC_LT,   KC_GT,   KC_BSLS, KC_QUES, _______, \
                               _______, _______, _______, _______, _______,  _______, _______, _______\
  ),

/* RAISE
 * ,-----------------------------------------.                    ,------------------------------------------.
 * |______|______|______|______|______|______|                    |______|______|______|______|______ |______|
 * |------+------+------+------+------+------|                    |------+------+------+------+-------+------|
 * |______| Home | End  |______|______|______|                    |______|M_W_L |M_W_U |M_W_D | M_W_R |______|
 * |------+------+------+------+------+------|                    |------+------+------+------+-------+------|
 * |______| AR_L |AR_Up |AR_Dn | AR_R |      |-------.    ,-------|______|M_Left| M_Up |M_Down|M_Right|______|
 * |------+------+------+------+------+------|______ |    |______ |------+------+------+------+-------+------|
 * |______| Cut  | Copy |Paste |______|______|-------|    |-------|______|M_Btn1|M_Btn2|M_btn3|M_btn4 |M_Btn5|
 * `-----------------------------------------/       /     \      \------------------------------------------'
 *                  |______ |______|______| /______ /       \______\  |M_S_0_|M_S_1_|M_S_2_|
 *                  `---------------------''-------'         '--------''-------------------'
 */

  [_RAISE] = LAYOUT( \
    _______, _______, _______, _______,  _______,  _______,                    _______, _______, _______, _______, _______, _______, \
    _______, KC_HOME, KC_END,  _______,  _______,  _______,                    _______, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, _______, \
    _______, KC_LEFT, KC_UP,   KC_DOWN,  KC_RIGHT, _______,                    _______, KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R, _______, \
    _______, KC_CUT,  KC_COPY, KC_PASTE, _______,  _______,  _______, _______, _______, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, KC_BTN5, \
                               _______,  _______,  _______,  _______, _______, KC_ACL0, KC_ACL1, KC_ACL2 \
  ),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LOWER | LGUI | Alt  | /Space  /       \Enter \  |BackSP| RGUI |RAISE |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

    [_ADJUST] = LAYOUT( \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD,\
                               _______, _______, _______, _______, _______,  _______, _______, _______ \
    )
};

int RGB_current_mode;

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
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
  }
  return true;
}
