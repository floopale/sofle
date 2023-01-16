 /* Copyright 2022 Adam Shoemaker
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
  // SOFLE RGB
#include <stdio.h>

#include QMK_KEYBOARD_H

enum sofle_layers 
{
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST
};

// Custom key codes
#define KC_ALTESC LALT_T(KC_ESC)

enum custom_keycodes 
{
    KC_QWERTY = SAFE_RANGE,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST
};

/* TEMPLATE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | trans| trans| trans| trans| trans| trans|                    | trans| trans| trans| trans| trans| trans|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | trans| trans| trans| trans| trans| trans|                    | trans| trans| trans| trans| trans| trans|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | trans| trans| trans| trans| trans| trans|-------.    ,-------| trans| trans| trans| trans| trans| trans|
 * |------+------+------+------+------+------|  trans|    | trans |------+------+------+------+------+------|
 * | trans| trans| trans| trans| trans| trans|-------|    |-------| trans| trans| trans| trans| trans| trans|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | trans| trans| trans| trans| /trans  /       \trans \  |trans | trans| trans| trans|
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
//[_TEMPLATE] = LAYOUT(
//  //,---------------------------------------------------.                     ,---------------------------------------------------.
//    _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
//  //|------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+---------|
//    _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
//  //|------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+---------|
//    _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
//  //|------+--------+--------+--------+--------+--------|   ===  |   |  ===   |--------+--------+--------+--------+--------+---------|
//    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
//  //|------+--------+--------+--------+--------+--------|   ===  |   |  ===   |--------+--------+--------+--------+--------+---------|
//                      _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
//  //                \--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------/
//),

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  del |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| MUTE  |    | >/||  |------+------+------+------+------+------|
 * | LCTR |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |LShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |LOWER | WIN  |ALT/ESC|LOWER| /SPACE  /       \Enter \  |RAISE |  WIN | RCTR | RAISE |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT(
                   //,---------------------------------------------------.                     ,---------------------------------------------------.
                      KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_DEL,
                   //|------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+---------|
                      KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
                   //|------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+---------|
                     KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
                   //|------+--------+--------+--------+--------+--------|   ===  |   |  ===   |--------+--------+--------+--------+--------+---------|
                    KC_LCTRL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,     KC_MPLY,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_LSFT,
                   //|------+--------+--------+--------+--------+--------|   ===  |   |  ===   |--------+--------+--------+--------+--------+---------|
                                      KC_LOWER, KC_LGUI,KC_ALTESC,KC_LOWER, KC_SPC,      KC_ENT,KC_RAISE, KC_LGUI,KC_RCTRL, KC_RAISE
                   //                \--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------/
                   ),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |  F1  |  F2  |  F3  |  F4  |  F5  |                    | trans| trans| trans| trans| trans| trans|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | trans|  F6  |  F7  |  F8  |  F9  | F10  |                    | trans| trans| trans|   [  |   ]  | trans|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | trans| F11  | F12  | trans|   $  |   %  |-------.    ,-------|   -  |   =  | trans|   {  |   }  | trans|
 * |------+------+------+------+------+------|  trans|    | trans |------+------+------+------+------+------|
 * | trans| trans| trans| trans|   {  |   }  |-------|    |-------|   _  |   +  | trans|   |  |  \   | trans|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | trans| trans| trans| trans| /trans  /       \trans \  |trans | trans| trans| trans|
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_LOWER] = LAYOUT(
                  //,---------------------------------------------------.                     ,---------------------------------------------------.
                     KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       _______, _______, _______, _______, _______, _______,
                  //|------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+---------|
                    _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                       _______, _______, _______, KC_LBRC, KC_RBRC, _______,
                  //|------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+---------|
                    _______,  KC_F11,  KC_F12, _______, _______, _______,                       KC_MINS,  KC_EQL, _______, KC_LCBR, KC_RCBR, _______,
                  //|------+--------+--------+--------+--------+--------|   ===  |   |  ===   |--------+--------+--------+--------+--------+---------|
                    _______, _______, _______, _______, _______, _______, KC_MPRV,     KC_MNXT, KC_UNDS, KC_PLUS, _______, KC_PIPE, KC_BSLS, _______,
                  //|------+--------+--------+--------+--------+--------|   ===  |   |  ===   |--------+--------+--------+--------+--------+---------|
                                      _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
                  //                \--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------/
                ),

/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ESC | trans| trans| trans| trans| trans|                    | trans| trans| trans| trans| trans| trans|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | trans| trans| trans| trans| trans| trans|                    | trans| trans|  up  | trans| pgup | trans|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | trans| trans| trans| trans| trans| trans|-------.    ,-------| trans| left | down | right| pgdwn| trans|
 * |------+------+------+------+------+------|  trans|    | trans |------+------+------+------+------+------|
 * | trans| trans| trans| trans| trans| trans|-------|    |-------| trans| trans| trans|   |  |   \  | print|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | trans| trans| trans| trans| /trans  /       \trans \  |trans | trans| trans| trans|
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
                  //,---------------------------------------------------.                     ,---------------------------------------------------.
                     KC_ESC, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
                  //|------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+---------|
                    _______, _______, _______, _______, _______, _______,                       _______, _______,   KC_UP, _______, KC_PGUP, _______,
                  //|------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+---------|
                    _______, _______, _______, _______, _______, _______,                       _______, KC_LEFT, KC_DOWN,KC_RIGHT, KC_PGDN, _______,
                  //|------+--------+--------+--------+--------+--------|   ===  |   |  ===   |--------+--------+--------+--------+--------+---------|
                    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, KC_PIPE, KC_BSLS, KC_PSCR,
                  //|------+--------+--------+--------+--------+--------|   ===  |   |  ===   |--------+--------+--------+--------+--------+---------|
                                      _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
                  //                \--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------/
                ),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |eeprst| trans| trans| trans| trans| trans|                    | trans| trans| trans| trans| trans| trans|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |qmk_bt| trans| trans| trans| trans| trans|                    | trans| trans| trans| trans| trans| trans|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |toggle| hue u| sat u| bri u| sp u | trans|-------.    ,-------| trans| trans| trans| trans| trans| trans|
 * |------+------+------+------+------+------|  trans|    | trans |------+------+------+------+------+------|
 * | mode | hue d| sat d| bri d| sp d | trans|-------|    |-------| trans| trans| trans| trans| trans| trans|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | trans| trans| trans| trans| /trans  /       \trans \  |trans | trans| trans| trans|
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_ADJUST] = LAYOUT(
                     //,---------------------------------------------------.                     ,---------------------------------------------------.
                       EEP_RST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX,  KC_PWR, XXXXXXX, KC_SLEP,
                     //|------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+---------|
                       QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                     //|------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+---------|
                       RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                     //|------+--------+--------+--------+--------+--------|   ===  |   |  ===   |--------+--------+--------+--------+--------+---------|
                       RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                     //|------+--------+--------+--------+--------+--------|   ===  |   |  ===   |--------+--------+--------+--------+--------+---------|
                                         _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
                     //                \--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------/
                   )

///* NUMPAD
// * ,-----------------------------------------.                    ,-----------------------------------------.
// * | trans|      |      |      |      |      |                    |      |NumLck|      |      |      |      |
// * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
// * |  `   |      |      |      |      |      |                    |   ^  |   7  |   8  |   9  |   *  |      |
// * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
// * | trans|      |      |      |      |      |-------.    ,-------|   -  |   4  |   5  |   6  |      |   |  |
// * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
// * | trans|      |      |      |      |      |-------|    |-------|   +  |   1  |   2  |   3  |   \  | Shift|
// * `-----------------------------------------/       /     \      \-----------------------------------------'
// *            | Bspc | WIN  |LOWER | Enter| /Space  /       \Enter \  |SPACE | 0    |  .   | RAlt |
// *            |      |      |      |      |/       /         \      \ |      |      |      |      |
// *            `----------------------------------'           '------''---------------------------'
// */
//[_NUMPAD] = LAYOUT(
//  //,------------------------------------------------.                    ,---------------------------------------------------.
//  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   _______, KC_NLCK, XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX,
//  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
//  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_CIRC, KC_P7,  KC_P8,   KC_P9,   KC_ASTR, XXXXXXX,
//  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
//  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_MINS, KC_P4,  KC_P5,   KC_P6,   KC_EQL,  KC_PIPE,
//  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
//  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,_______,   _______,KC_PLUS, KC_P1,  KC_P2,   KC_P3,   KC_SLSH, _______,
//  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
//              _______, OSM(MOD_MEH), _______, _______, _______,   _______, _______,  KC_P0,   KC_PDOT, _______
//  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
//),
//
///* SWITCH
// * ,-----------------------------------------.                    ,-----------------------------------------.
// * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
// * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
// * | qwer | cole |col_dh| low  | raise| adj  |                    |numpad|      |      |      |      |QK_BOOT |
// * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
// * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |EEP_RST|
// * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
// * | SLEEP|      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
// * `-----------------------------------------/       /     \      \-----------------------------------------'
// *            | Bspc | WIN  |LOWER | Enter| /Space  /       \Enter \  |SPACE | 0    |  .   | RAlt |
// *            |      |      |      |      |/       /         \      \ |      |      |      |      |
// *            `----------------------------------'           '------''---------------------------'
// */
//  // layer switcher
//[_SWITCH] = LAYOUT(
//  //,------------------------------------------------.                    ,---------------------------------------------------.
//  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX,
//  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
//  TO(0),   TO(1),   TO(2),   TO(3),   TO(4),   TO(5),                      TO(6),   KC_NO,   KC_NO,   KC_NO,   KC_NO,   QK_BOOT,
//  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
//  KC_NO,   KC_NO, KC_BRIU,   KC_NO,   KC_NO,   KC_NO,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   EEP_RST,
//  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
//  KC_SYSTEM_SLEEP,KC_NO,KC_NO,KC_NO,  KC_NO,   KC_NO, KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
//  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
//                  KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
//  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
//
//	),
};

#ifdef RGB_MATRIX_ENABLE

uint8_t get_saturated_v(uint8_t v, uint8_t max_v)
{
    if (v > max_v)
    {
        return max_v;
    }
    
    return v;
}

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) 
{
    const uint8_t max_v = rgb_matrix_get_val();
    
    // Limit brightness on useful colors
    HSV hsv_green  = {HSV_GREEN};
    HSV hsv_yellow = {HSV_YELLOW};
    HSV hsv_cyan   = {HSV_CYAN};
    HSV hsv_pink   = {HSV_MAGENTA};
    
    hsv_green.v  = get_saturated_v(hsv_green.v,  max_v);
    hsv_yellow.v = get_saturated_v(hsv_yellow.v, max_v); 
    hsv_cyan.v   = get_saturated_v(hsv_cyan.v,   max_v);
    hsv_pink.v   = get_saturated_v(hsv_pink.v,   max_v);
     
    const RGB rgb_green  = hsv_to_rgb(hsv_green);
    const RGB rgb_yellow = hsv_to_rgb(hsv_yellow);
    const RGB rgb_cyan   = hsv_to_rgb(hsv_cyan);
    const RGB rgb_pink   = hsv_to_rgb(hsv_pink);

    // Change indicator state
    for (uint8_t i = led_min; i <= led_max; i++) 
    {
        switch (get_highest_layer(layer_state))
        {
            case _QWERTY:
                // Set indicator light only on base layer
                if ( (g_led_config.flags[i] & LED_FLAG_INDICATOR) > 0 )
                {
                    rgb_matrix_set_color(i, rgb_cyan.r, rgb_cyan.g, rgb_cyan.b);
                }
                break;
            case _LOWER:
                // Set indicator light only on base layer
                if ( ((g_led_config.flags[i] & LED_FLAG_INDICATOR) > 0) ||
                     ((g_led_config.flags[i] & LED_FLAG_UNDERGLOW) > 0) )
                {
                    rgb_matrix_set_color(i, rgb_green.r, rgb_green.g, rgb_green.b);
                }
                break;
            case _RAISE:
                // Set indicator light only on base layer
                if ( ((g_led_config.flags[i] & LED_FLAG_INDICATOR) > 0) ||
                     ((g_led_config.flags[i] & LED_FLAG_UNDERGLOW) > 0) )
                {
                    rgb_matrix_set_color(i, rgb_yellow.r, rgb_yellow.g, rgb_yellow.b);
                }
                break;
            case _ADJUST:
                // Set indicator light only on base layer
                if ( ((g_led_config.flags[i] & LED_FLAG_INDICATOR) > 0) ||
                     ((g_led_config.flags[i] & LED_FLAG_UNDERGLOW) > 0) )
                {
                    rgb_matrix_set_color(i, rgb_pink.r, rgb_pink.g, rgb_pink.b);
                }
                break;
            default:
                break;
        }

    }

}

#endif

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) 
{
    //if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    //}
    //return rotation;
}

void render_space(void) 
{
    oled_write_P(PSTR("     "), false);
}

void render_mod_status_gui_alt(uint8_t modifiers) 
{
    static const char PROGMEM gui_off_1[] = {0x85, 0x86, 0};
    static const char PROGMEM gui_off_2[] = {0xa5, 0xa6, 0};
    static const char PROGMEM gui_on_1[] = {0x8d, 0x8e, 0};
    static const char PROGMEM gui_on_2[] = {0xad, 0xae, 0};

    static const char PROGMEM alt_off_1[] = {0x87, 0x88, 0};
    static const char PROGMEM alt_off_2[] = {0xa7, 0xa8, 0};
    static const char PROGMEM alt_on_1[] = {0x8f, 0x90, 0};
    static const char PROGMEM alt_on_2[] = {0xaf, 0xb0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if (modifiers & MOD_MASK_GUI) 
    {
        oled_write_P(gui_on_1, false);
    } 
    else 
    {
        oled_write_P(gui_off_1, false);
    }

    if ((modifiers & MOD_MASK_GUI) && (modifiers & MOD_MASK_ALT)) 
    {
        oled_write_P(on_on_1, false);
    } 
    else if (modifiers & MOD_MASK_GUI) 
    {
        oled_write_P(on_off_1, false);
    } 
    else if (modifiers & MOD_MASK_ALT) 
    {
        oled_write_P(off_on_1, false);
    } 
    else 
    {
        oled_write_P(off_off_1, false);
    }

    if (modifiers & MOD_MASK_ALT) 
    {
        oled_write_P(alt_on_1, false);
    }  
    else 
    {
        oled_write_P(alt_off_1, false);
    }

    if (modifiers & MOD_MASK_GUI) 
    {
        oled_write_P(gui_on_2, false);
    } 
    else 
    {
        oled_write_P(gui_off_2, false);
    }

    if (modifiers & MOD_MASK_GUI & MOD_MASK_ALT) 
    {
        oled_write_P(on_on_2, false);
    } 
    else if (modifiers & MOD_MASK_GUI) 
    {
        oled_write_P(on_off_2, false);
    }
    else if (modifiers & MOD_MASK_ALT) 
    {
        oled_write_P(off_on_2, false);
    } 
    else 
    {
        oled_write_P(off_off_2, false);
    }

    if (modifiers & MOD_MASK_ALT) 
    {
        oled_write_P(alt_on_2, false);
    } 
    else 
    {
        oled_write_P(alt_off_2, false);
    }
}

void render_mod_status_ctrl_shift(uint8_t modifiers) 
{
    static const char PROGMEM ctrl_off_1[] = {0x89, 0x8a, 0};
    static const char PROGMEM ctrl_off_2[] = {0xa9, 0xaa, 0};
    static const char PROGMEM ctrl_on_1[] = {0x91, 0x92, 0};
    static const char PROGMEM ctrl_on_2[] = {0xb1, 0xb2, 0};

    static const char PROGMEM shift_off_1[] = {0x8b, 0x8c, 0};
    static const char PROGMEM shift_off_2[] = {0xab, 0xac, 0};
    static const char PROGMEM shift_on_1[] = {0xcd, 0xce, 0};
    static const char PROGMEM shift_on_2[] = {0xcf, 0xd0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_CTRL) 
    {
        oled_write_P(ctrl_on_1, false);
    } 
    else 
    {
        oled_write_P(ctrl_off_1, false);
    }

    if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_SHIFT)) 
    {
        oled_write_P(on_on_1, false);
    } 
    else if (modifiers & MOD_MASK_CTRL) 
    {
        oled_write_P(on_off_1, false);
    } 
    else if (modifiers & MOD_MASK_SHIFT) 
    {
        oled_write_P(off_on_1, false);
    } 
    else 
    {
        oled_write_P(off_off_1, false);
    }

    if (modifiers & MOD_MASK_SHIFT) 
    {
        oled_write_P(shift_on_1, false);
    } 
    else 
    {
        oled_write_P(shift_off_1, false);
    }

    if(modifiers & MOD_MASK_CTRL) 
    {
        oled_write_P(ctrl_on_2, false);
    } 
    else 
    {
        oled_write_P(ctrl_off_2, false);
    }

    if (modifiers & MOD_MASK_CTRL & MOD_MASK_SHIFT) 
    {
        oled_write_P(on_on_2, false);
    } 
    else if(modifiers & MOD_MASK_CTRL) 
    {
        oled_write_P(on_off_2, false);
    } 
    else if (modifiers & MOD_MASK_SHIFT) 
    {
        oled_write_P(off_on_2, false);
    } 
    else 
    {
        oled_write_P(off_off_2, false);
    }

    if (modifiers & MOD_MASK_SHIFT) 
    {
        oled_write_P(shift_on_2, false);
    } 
    else 
    {
        oled_write_P(shift_off_2, false);
    }
}

void render_logo(void) 
{
    static const char PROGMEM shoe_logo[] = {0x80, 0x81, 0x82, 0x83, 0x84,
                                             0xa0, 0xa1, 0xa2, 0xa3, 0xa4,
                                             0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0};
    oled_write_P(shoe_logo, false);
    oled_write_P(PSTR(" shoe"), false);
}

void render_layer_state(void) 
{
    static const char PROGMEM default_layer[] = {0x20, 0x94, 0x95, 0x96, 0x20,
                                                 0x20, 0xb4, 0xb5, 0xb6, 0x20,
                                                 0x20, 0xd4, 0xd5, 0xd6, 0x20, 0};
                                                 
    static const char PROGMEM raise_layer[]   = {0x20, 0x97, 0x98, 0x99, 0x20,
                                                 0x20, 0xb7, 0xb8, 0xb9, 0x20,
                                                 0x20, 0xd7, 0xd8, 0xd9, 0x20, 0};
                                                 
    static const char PROGMEM lower_layer[]   = {0x20, 0x9a, 0x9b, 0x9c, 0x20,
                                                 0x20, 0xba, 0xbb, 0xbc, 0x20,
                                                 0x20, 0xda, 0xdb, 0xdc, 0x20, 0};
                                                 
    static const char PROGMEM adjust_layer[]  = {0x20, 0x9d, 0x9e, 0x9f, 0x20,
                                                 0x20, 0xbd, 0xbe, 0xbf, 0x20,
                                                 0x20, 0xdd, 0xde, 0xdf, 0x20, 0};
                                                 
    if (layer_state_is(_ADJUST)) 
    {
        oled_write_P(adjust_layer, false);
    } 
    else if (layer_state_is(_LOWER)) 
    {
        oled_write_P(lower_layer, false);
    } 
    else if (layer_state_is(_RAISE)) 
    {
        oled_write_P(raise_layer, false);
    } 
    else 
    {
        oled_write_P(default_layer, false);
    }
}

bool oled_task_user(void) 
{
    // Renders the current keyboard state (layers and mods)
    render_logo();
    render_space();
    render_layer_state();
    render_space();
    render_mod_status_gui_alt(get_mods()|get_oneshot_mods());
    render_mod_status_ctrl_shift(get_mods()|get_oneshot_mods());
    return false;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) 
{
    switch (keycode) 
    {            
        case KC_LOWER:
            if (record->event.pressed) 
            {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } 
            else 
            {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            
            return false;

        case KC_RAISE:
            if (record->event.pressed) 
            {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } 
            else 
            {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }

            return false;

        case KC_ADJUST:
            if (record->event.pressed) 
            {
                layer_on(_ADJUST);
            } 
            else 
            {
                layer_off(_ADJUST);
            }

            return false;

    }

    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
		if (clockwise) {
            tap_code(KC_PGDOWN);
        } else {
            tap_code(KC_PGUP);
        }
	}
    return true;
}

#endif
