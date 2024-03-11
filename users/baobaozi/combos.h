#pragma once

#include QMK_KEYBOARD_H

#include "baobaozi.h"

// Copyright @filterpaper
// SPDX-License-Identifier: GPL-2.0+

/*
An adaptation of Jane Bernhardt's Combos on Steroids (http://combos.gboards.ca/)
These preprocessors will construct combo source with the following macros in COMBOS_DEF:
COMB(name, keycode_shortcut, combo_sequence...)
SUBS(name, "string to send", combo_sequence...)
ACTN(name, function_call(),  combo_sequence...)

Use the COMB macro to create simple keycode shortcuts with two or more keys
Example: COMB(vol_up, KC_VOLU, KC_Y, KC_U).

Use the SUBS macro for shotcuts to send short strings and phrases
Example: SUBS(which, "which ", KC_W, KC_H).

Use the ACTN macro for combos to call internal functions
Example: ACTN(rgb_tog, rgb_matrix_toggle(), KC_Z, KC_X)
*/

#define COMBOS_DEF "combos.inc"

#define C_ENUM(name, val, ...) cmb_##name,
#define C_DATA(name, val, ...) uint16_t const name##_combo[] PROGMEM = {__VA_ARGS__, COMBO_END};
#define C_TYPE(name, val, ...) [cmb_##name] = COMBO(name##_combo, val),
#define A_TYPE(name, val, ...) [cmb_##name] = COMBO_ACTION(name##_combo),
#define P_SSTR(name, val, ...) case cmb_##name: if (pressed) { SEND_STRING(val); } break;
#define P_ACTN(name, val, ...) case cmb_##name: if (pressed) { val; } break;
#define UNUSED(...)

#define COMB C_ENUM
#define SUBS C_ENUM
#define ACTN C_ENUM
enum combos {
#   include COMBOS_DEF
};

#undef COMB
#undef SUBS
#undef ACTN
#define COMB C_DATA
#define SUBS C_DATA
#define ACTN C_DATA
#include COMBOS_DEF

#undef COMB
#undef SUBS
#undef ACTN
#define COMB C_TYPE
#define SUBS A_TYPE
#define ACTN A_TYPE
combo_t key_combos[] = {
#   include COMBOS_DEF
};

#undef COMB
#undef SUBS
#undef ACTN
#define COMB UNUSED
#define SUBS P_SSTR
#define ACTN P_ACTN
void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
#       include COMBOS_DEF
    }
}

#ifdef COMBO_SHOULD_TRIGGER
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    return (tog_num <= combo_index && combo_index <= tog_fnc) || get_highest_layer(layer_state) <= CMK;
}
#endif

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    // decide by combo->keycode
    // if (KEYCODE_IS_MOD(combo->keycode)) return COMBO_MOD_TERM; // you have to config this yourself if you're using COMBO_TERM_PER_COMBO
    // switch (combo->keycode) {
    //     case KC_X:
    //         return 50;
    // }
    // or with combo index, i.e. its name from enum.
#if defined(MOUSEKEY_ENABLE)
    if (index == cmb_tgnav || index == cmb_qwer || index == cmb_cur) {
#else
    if (index == cmb_tgnav || index == cmb_qwer) {
#endif
        return COMBO_TERM + 10;
    } else if (index == cmb_bspc) {
        return COMBO_TERM - 5;
    }

        return COMBO_TERM;
    // And if you're feeling adventurous, you can even decide by the keys in the chord,
    // i.e. the exact array of keys you defined for the combo.
    // This can be useful if your combos have a common key and you want to apply the
    // same combo term for all of them.
    // if (combo->keys[0] == KC_ENTER) { // if first key in the array is KC_ENTER
    //     return 150;
    // }
}

