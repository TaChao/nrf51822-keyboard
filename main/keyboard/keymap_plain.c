/**
 * @brief 基础键盘配列
 * 
 * @file keymap_plain.c
 * @author Jim Jiang
 * @date 2018-05-13
 */
#include "keymap_common.h"
#include "keyboard_fn.h"


#ifdef KEYBOARD_60

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 KEYMAP(
    KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
    KC_P7, KC_P8, KC_P9, KC_PPLS,
    KC_P4, KC_P5, KC_P6, 
    KC_P1, KC_P2, KC_P3, KC_PENT,
    KC_P0, KC_PDOT),
};

const action_t PROGMEM fn_actions[] = {
	
};
#endif

