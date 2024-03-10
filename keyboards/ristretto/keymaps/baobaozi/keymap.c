#include QMK_KEYBOARD_H

#include "baobaozi.h"

/* Re-pass though to allow templates to be used */
#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT_wrapper(
        // ┌─ Extra ─┬─── Q ───┬─── W ───┬─── F ───┬─── P ───┬─── G ───┐                  ┌─── J ───┬─── L ───┬─── U ───┬─── Y ───┬─── ; ───┬─ Extra ─┐
            KC_TAB   ,_________________ROW_TOP_COLMK_L_________________,                   _________________ROW_TOP_COLMK_R_________________,KC_BSPC  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                  ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            LTN(GRV) ,_________________ROW_MID_COLMK_L_________________,                   _________________ROW_MID_COLMK_R_________________,LTN(ENT) ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                  ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            OS(LSFT) ,_________________ROW_BOT_COLMK_L_________________,                   _________________ROW_BOT_COLMK_R_________________,OS(RSFT) ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤    ┌─────────┐   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            __T_L4___,KC_0     ,KC_1     ,__T_L3___,__T_L2___,__T_L1___,     KC_5     ,    __T_R1___,__T_R2___,__T_R2B__,KC_2     ,KC_3     ,__T_R3___
        // └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘    └─────────┘   └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
    ),

    [_QWERTY] = LAYOUT_wrapper(
        // ┌─ Extra ─┬─── Q ───┬─── W ───┬─── F ───┬─── P ───┬─── G ───┐                  ┌─── J ───┬─── L ───┬─── U ───┬─── Y ───┬─── ; ───┬─ Extra ─┐
            _______  ,_________________ROW_TOP_QWERT_L_________________,                   _________________ROW_TOP_QWERT_R_________________,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                  ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_________________ROW_MID_QWERT_L_________________,                   _________________ROW_MID_QWERT_R_________________,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                  ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_________________ROW_BOT_QWERT_L_________________,                   _________________ROW_BOT_QWERT_R_________________,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤    ┌─────────┐   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,     _______  ,    _______  ,_______  ,_______  ,_______  ,_______  ,_______
        // └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘    └─────────┘   └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
    ),

    [_NAV] = LAYOUT_wrapper(
        // ┌─ Extra ─┬─── Q ───┬─── W ───┬─── F ───┬─── P ───┬─── G ───┐                  ┌─── J ───┬─── L ───┬─── U ───┬─── Y ───┬─── ; ───┬─ Extra ─┐
            _______  ,_________________ROW_TOP_NAV_L___________________,                   _________________ROW_TOP_NAV_R___________________,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                  ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_________________ROW_MID_NAV_L___________________,                   _________________ROW_MID_NAV_R___________________,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                  ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_________________ROW_BOT_NAV_L___________________,                   _________________ROW_BOT_NAV_R___________________,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤    ┌─────────┐   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,     _______  ,    _______  ,_______  ,_______  ,_______  ,_______  ,_______
        // └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘    └─────────┘   └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
    ),

#if defined(TEST_SYN)
    [_SYN] = LAYOUT_wrapper(
        // ┌─ Extra ─┬─── Q ───┬─── W ───┬─── F ───┬─── P ───┬─── G ───┐                  ┌─── J ───┬─── L ───┬─── U ───┬─── Y ───┬─── ; ───┬─ Extra ─┐
            _______  ,_________________ROW_TOP_SYN_L___________________,                   _________________ROW_TOP_SYN_R___________________,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                  ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_________________ROW_MID_SYN_L___________________,                   _________________ROW_MID_SYN_R___________________,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                  ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_________________ROW_BOT_SYN_L___________________,                   _________________ROW_BOT_SYN_R___________________,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤    ┌─────────┐   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,     _______  ,    _______  ,_______  ,_______  ,_______  ,_______  ,_______
        // └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘    └─────────┘   └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
    ),
#else
    [_SYM] = LAYOUT_wrapper(
        // ┌─ Extra ─┬─── Q ───┬─── W ───┬─── F ───┬─── P ───┬─── G ───┐                  ┌─── J ───┬─── L ───┬─── U ───┬─── Y ───┬─── ; ───┬─ Extra ─┐
            _______  ,_________________ROW_TOP_SYM_L___________________,                   _________________ROW_TOP_SYM_R___________________,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                  ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_________________ROW_MID_SYM_L___________________,                   _________________ROW_MID_SYM_R___________________,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                  ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_________________ROW_BOT_SYM_L___________________,                   _________________ROW_BOT_SYM_R___________________,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤    ┌─────────┐   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,     _______  ,    _______  ,_______  ,_______  ,_______  ,_______  ,_______
        // └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘    └─────────┘   └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
    ),

    [_NUM] = LAYOUT_wrapper(
        // ┌─ Extra ─┬─── Q ───┬─── W ───┬─── F ───┬─── P ───┬─── G ───┐                  ┌─── J ───┬─── L ───┬─── U ───┬─── Y ───┬─── ; ───┬─ Extra ─┐
            _______  ,_________________ROW_TOP_NUM_L___________________,                   _________________ROW_TOP_NUM_R___________________,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                  ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_________________ROW_MID_NUM_L___________________,                   _________________ROW_MID_NUM_R___________________,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                  ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_________________ROW_BOT_NUM_L___________________,                   _________________ROW_BOT_NUM_R___________________,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤    ┌─────────┐   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,     _______  ,    _______  ,_______  ,_______  ,_______  ,_______  ,_______
        // └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘    └─────────┘   └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
    ),
#endif

    [_CUR] = LAYOUT_wrapper(
        // ┌─ Extra ─┬─── Q ───┬─── W ───┬─── F ───┬─── P ───┬─── G ───┐                  ┌─── J ───┬─── L ───┬─── U ───┬─── Y ───┬─── ; ───┬─ Extra ─┐
            _______  ,_________________ROW_TOP_CUR_L___________________,                   _________________ROW_TOP_CUR_R___________________,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                  ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_________________ROW_MID_CUR_L___________________,                   _________________ROW_MID_CUR_R___________________,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                  ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_________________ROW_BOT_CUR_L___________________,                   _________________ROW_BOT_CUR_R___________________,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤    ┌─────────┐   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,     _______  ,    _______  ,_______  ,_______  ,_______  ,_______  ,_______
        // └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘    └─────────┘   └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
    ),

    [_FNC] = LAYOUT_wrapper(
        // ┌─ Extra ─┬─── Q ───┬─── W ───┬─── F ───┬─── P ───┬─── G ───┐                  ┌─── J ───┬─── L ───┬─── U ───┬─── Y ───┬─── ; ───┬─ Extra ─┐
            _______  ,_________________ROW_TOP_FNC_L___________________,                   _________________ROW_TOP_FNC_R___________________,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                  ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_________________ROW_MID_FNC_L___________________,                   _________________ROW_MID_FNC_R___________________,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                  ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_________________ROW_BOT_FNC_L___________________,                   _________________ROW_BOT_FNC_R___________________,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤    ┌─────────┐   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,     _______  ,    _______  ,_______  ,_______  ,_______  ,_______  ,_______
        // └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘    └─────────┘   └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
    ),

    [_KB] = LAYOUT_wrapper(
        // ┌─ Extra ─┬─── Q ───┬─── W ───┬─── F ───┬─── P ───┬─── G ───┐                  ┌─── J ───┬─── L ───┬─── U ───┬─── Y ───┬─── ; ───┬─ Extra ─┐
            _______  ,_________________ROW_TOP_KB_L____________________,                   _________________ROW_TOP_KB_R____________________,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                  ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_________________ROW_MID_KB_L____________________,                   _________________ROW_MID_KB_R____________________,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                  ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_________________ROW_BOT_KB_L____________________,                   _________________ROW_BOT_KB_R____________________,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤    ┌─────────┐   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,     _______  ,    _______  ,_______  ,_______  ,_______  ,_______  ,_______
        // └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘    └─────────┘   └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
    ),
};

#if defined(ENCODER_ENABLE)
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) { return false; }
    if(index == 0) {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
            }
        }
    return true;
}
#endif

#if defined(OLED_ENABLE)
#include <stdio.h>
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

void render_mod_status(uint8_t modifiers) {
    led_t led_state = host_keyboard_led_state();

    oled_write_P(modifiers & MOD_MASK_GUI ? PSTR(">cmd\n\n") : PSTR(" cmd\n\n"), false);
    oled_write_P(modifiers & MOD_MASK_ALT ? PSTR(">opt\n\n") : PSTR(" opt\n\n"), false);
    oled_write_P(modifiers & MOD_MASK_CTRL ? PSTR(">ctl\n\n") : PSTR(" ctl\n\n"), false);
    oled_write_P(modifiers & MOD_MASK_SHIFT ? PSTR(">sft\n\n") : PSTR(" sft\n\n"), false);
    oled_write_P(led_state.caps_lock ? PSTR(">cap\n") : PSTR(" cap\n"), false);
}

bool oled_task_user(void) {
    if (get_highest_layer(layer_state) == _FNC) {
        // You also have access to a `default_layer_state` for when you DF … so you can tell difference between which default layer you’re on
        oled_write_P(PSTR("\n FNC\n F12\n"), false);
    } else if (get_highest_layer(layer_state) == _KB) {
        oled_write_P(PSTR("\n KB\n act\n"), false);
    } else if (get_highest_layer(layer_state) == _CUR) {
        oled_write_P(PSTR("\n CUR\n sor\n"), false);
#if defined(TEST_SYN)
    } else if (get_highest_layer(layer_state) == _SYN) {
        oled_write_P(PSTR("\n SYN\n 1@3\n"), false);
#else
    } else if (get_highest_layer(layer_state) == _SYM) {
        oled_write_P(PSTR("\n SYM\n !@#\n"), false);
    } else if (get_highest_layer(layer_state) == _NUM) {
        oled_write_P(PSTR("\n NUM\n 123\n"), false);
#endif
    } else if (get_highest_layer(layer_state) == _NAV) {
        oled_write_P(PSTR("\n NAV\n mov\n"), false);
    } else if (get_highest_layer(layer_state) == _QWERTY) {
        oled_write_P(PSTR("\n QWE\n sux\n"), false);
    } else {
        oled_write_P(PSTR("\n CMK\n yay\n"), false);
    }

    oled_write_P(PSTR(" --- \n"), false);
    render_mod_status(get_mods()|get_oneshot_mods());

    return false;
}
#endif