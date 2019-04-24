/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CONFIG_H
#define CONFIG_H

#ifdef BLE60
#define KEYBOARD_60
#else
#error PLEASE SPECIFIC ONE KEYBOARD
#endif

/* HID Device descriptor parameter */
#define VENDOR_ID       0x1915
#define PRODUCT_ID      0xEEEE
#define DEVICE_VER      0x0001
#define MANUFACTURER    "Lotlab"
#define DESCRIPTION     BLE keyboard base t.m.k firmware

#ifdef KEYBOARD_60

    #define PRODUCT         "GT-BLE60"

    /* key matrix size */
    #define MATRIX_ROWS 5
    #define MATRIX_COLS 14
    
    #define KEYBOARD_DEBUG         //启用此选项，通电后不需要按键就启动蓝牙,但无法通过power_sleep按键手动关机;如果关闭，开启蓝牙需要按Space+U，但可手动关机。
    #define KEYBOARD_REVD          //键盘硬件版本配置
    
    #define UART_SUPPORT
    //#define BLE_LINK_SEC         //启用此选项，蓝牙配对时要求输入密码,并启用MITM
#endif

/* 采用内部32K晶振 */
#define USE_RC_CLOCK

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE    2

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

// 定义Bootmagic按键
#define BOOTMAGIC_KEY_BOOT              KC_U /* boot! */            //此参数定义启动时开启蓝牙的按键(Space+U)
#define BOOTMAGIC_KEY_ERASE_BOND        KC_E /* erase bond info */    //此参数定义启动时擦除蓝牙配对信息的按键（Space+E）

// 键盘省电参数
#define SLEEP_SLOW_TIMEOUT 120                // 键盘闲置多久后转入慢速扫描模式 (s)
#define SLEEP_OFF_TIMEOUT  900               // 键盘闲置多久后转入自动关机 (s)
//#define BLE_IDLE_TIMEOUT 60                  // 蓝牙离线后多久转入自动关机 (s)，必须小于SLEEP_OFF_TIMEOUT
#define KEYBOARD_FAST_SCAN_INTERVAL 8        // 通常模式下，多久扫描一次键盘 (ms)
#define KEYBOARD_SLOW_SCAN_INTERVAL 100      // 慢速模式下，多久扫描一次键盘 (ms)


/**
 * 在检测到有按键改变后即立刻退出慢速扫描模式，而不是等待完整一轮消抖后再退出。
 * 可能可以缓解慢速扫描模式下第一次按键后响应时间过长的问题。
 **/
#define SLOW_MODE_EARLY_EXIT

// LED自动熄灭时长(ms)，设为0则不自动熄灭
#define LED_AUTOOFF_TIME 0

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

/* period of tapping(ms) */
#define TAPPING_TERM    200
/* tap count needed for toggling a feature */
#define TAPPING_TOGGLE  3
/* Oneshot timeout(ms) */
#define ONESHOT_TIMEOUT 300

/* Boot Magic salt key: Space */
#define BOOTMAGIC_KEY_SALT      KC_SPACE

#define BOOTMAGIC_ENABLE
#define EXTRAKEY_ENABLE
#define USB_6KRO_ENABLE
#define COMMAND_ENABLE

/* fix led state on android */
#define LED_STATE_FIX

#endif
