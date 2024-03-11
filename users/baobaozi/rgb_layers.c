#include "baobaozi.h"

const rgblight_segment_t PROGMEM colemak_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLIGHT_LED_COUNT, 170, 255, 255}
);
const rgblight_segment_t PROGMEM qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLIGHT_LED_COUNT/2, 170, 255, 150},
    {RGBLIGHT_LED_COUNT/2, RGBLIGHT_LED_COUNT, 0, 0, 100}
);
const rgblight_segment_t PROGMEM nav_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLIGHT_LED_COUNT, HSV_GOLD}
);
const rgblight_segment_t PROGMEM sym_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLIGHT_LED_COUNT, HSV_MAGENTA}
);
const rgblight_segment_t PROGMEM num_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLIGHT_LED_COUNT, HSV_CYAN}
);
const rgblight_segment_t PROGMEM syn_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLIGHT_LED_COUNT, HSV_CYAN}
);
const rgblight_segment_t PROGMEM cur_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLIGHT_LED_COUNT, HSV_WHITE}
);
const rgblight_segment_t PROGMEM kb_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLIGHT_LED_COUNT/2, 115, 250, 175}, // between springgreen and turquoise
    {RGBLIGHT_LED_COUNT/2, RGBLIGHT_LED_COUNT, 70, 255, 150} // between springgreen and turquoise
);
// const rgblight_segment_t PROGMEM shift_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, RGBLIGHT_LED_COUNT, 0, 21, 255}
// );
// as later layers take precedence, we want capslock layer to override
// but for some reason on ymd67, capslock colour layer doesn’t work anyway. shrug.
const rgblight_segment_t PROGMEM capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLIGHT_LED_COUNT, 0, 255, 200}
    // {7, 2, HSV_RED}
);

// Now define the array of layers. Later layers take precedence
// const rgblight_segment_t *const PROGMEM rgb_light_layers[] = {
const rgblight_segment_t *const PROGMEM rgb_light_layers[] = RGBLIGHT_LAYERS_LIST(
    colemak_layer,
    qwerty_layer,
    nav_layer,
#if defined(TEST_SYN)
     syn_layer,
#else
     sym_layer,
     num_layer,
#endif
    cur_layer,
    kb_layer,
    // shift_layer,
    capslock_layer
);

layer_state_t layer_state_set_user(layer_state_t state) {
    // uint8_t layer = biton32(state);
    dprintf("in layer_state_set_user: %u\n", state);
    // Both layers will light up if both kb layers are active
    // rgblight_set_layer_state(0, layer_state_cmp(state, _COLEMAK));
    rgblight_set_layer_state(1, layer_state_cmp(state, _QWERTY));
    rgblight_set_layer_state(2, layer_state_cmp(state, _NAV));
#if defined(TEST_SYN)
    rgblight_set_layer_state(3, layer_state_cmp(state, _SYN));
    rgblight_set_layer_state(4, layer_state_cmp(state, _CUR));
    rgblight_set_layer_state(5, layer_state_cmp(state, _KB));
#else
     rgblight_set_layer_state(3, layer_state_cmp(state, _SYM));
     rgblight_set_layer_state(4, layer_state_cmp(state, _NUM));
    rgblight_set_layer_state(5, layer_state_cmp(state, _CUR));
    rgblight_set_layer_state(6, layer_state_cmp(state, _KB));
#endif

    // RGB Modes
    // 1 = Static
    // 2-5 = Breathing
    // 6-8 = Rainbow
    // 9-14 = Swirl
    // 15-20 = Snake
    // 21-24 = Nightrider
    // 25 = Christmas
    // 26-30 = Static Gradient

    // switch (layer) {
    //     case _QWERTY:
    //         rgblight_mode(desired);
    //         break;

    //     case _LOWER: // If we're in swirl mode, then speed up the swirls, otherwise breathe
    //         check = rgblight_get_mode();
    //         if (check > 8 && check < 15) {
    //             rgblight_mode(14);
    //         } else {
    //             rgblight_mode(5);
    //         }
    //         break;
    // }

    // if (layer_state_cmp(state, _COLEMAK)) {
    //     dprintf("HIHIHI in layer_state_is(0): %u\n", layer_state_cmp(state, _COLEMAK));
    //     rgblight_sethsv_noeeprom(170, 255, 255);
    //     wait_us(175);  // Add a slight delay between color and mode to ensure it's processed correctly
    //     rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
    // }
    // wish this worked …
    // if (layer_state_cmp(state, _QWERTY)) {
    //     dprintf("HIHIHI in layer_state_is(0): %u\n", layer_state_cmp(state, _QWERTY) == 1);
    //     rgblight_mode(RGBLIGHT_MODE_BREATHING);
    // } else {
    //     rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
    // }

    // if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
    //     rgblight_sethsv_range(HSV_RED, 0, RGBLIGHT_LED_COUNT);
    // }

    return state;
}

// bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
//     uint8_t active_mods = get_mods();
//     uint8_t active_oneshot_mods = get_oneshot_mods();

//     if (record->event.pressed && (active_mods & MOD_MASK_SHIFT || active_oneshot_mods & MOD_MASK_SHIFT)) {
//         rgblight_set_layer_state(7, true);
//     }

//     return true;
// }

bool led_update_user(led_t led_state) {
    dprintf("in led_update_user: cap=%u\n", led_state.caps_lock);
    rgblight_set_layer_state(7, led_state.caps_lock);
    // if (led_state.caps_lock) {
    //     rgblight_sethsv(HSV_RED);
    // }

    return true;
}

void keyboard_post_init_user(void) {
    // // set initial animation type (in that I don’t want it)
    // rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
    // // set the default colour
    // rgblight_sethsv_range(HSV_CYAN, 0, RGBLIGHT_LED_COUNT);
    // Enable the LED layers
    rgblight_layers = rgb_light_layers;
    // drashna’s fix for weird lights
    rgblight_enable_noeeprom();
    layer_state_set_user(0);
    // rgblight_mode(RGBLIGHT_MODE_KNIGHT);
}
