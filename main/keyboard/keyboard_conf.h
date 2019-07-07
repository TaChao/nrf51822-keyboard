#ifndef _keyboard_conf_h_
#define _keyboard_conf_h_

#include <stdint.h>
#include "nrf_adc.h"
#include "config.h"

#ifdef KEYBOARD_60

#define KEYBOARD_ADC NRF_ADC_CONFIG_INPUT_3
static const uint8_t column_pin_array[MATRIX_COLS] = {29,28,25,22};
static const uint8_t row_pin_array[MATRIX_ROWS] = {1,0,30,24,23};

#define PIN_EXT1  3
#define PIN_EXT2  4
#define PIN_EXT3  5

#define UART_TXD 7
#define UART_RXD 6

#define BOOTLOADER_BUTTON           8

#define LED_CAPS                    PIN_EXT3
#define LED_CHARGING                PIN_EXT1 
#define LED_BLE                     PIN_EXT2

#define UPDATE_IN_PROGRESS_LED      PIN_EXT3
#define ADVERTISING_LED_PIN_NO      PIN_EXT1
#define CONNECTED_LED_PIN_NO        PIN_EXT2

#define LED_POSITIVE

#ifdef LED_POSITIVE
    #define LED_SET(x) nrf_gpio_pin_set(x)
    #define LED_CLEAR(x) nrf_gpio_pin_clear(x)
    #define LED_WRITE(x,b) nrf_gpio_pin_write(x,b)
#else
    #define LED_SET(x) nrf_gpio_pin_clear(x)
    #define LED_CLEAR(x) nrf_gpio_pin_set(x)
    #define LED_WRITE(x,b) nrf_gpio_pin_write(x,!(b))
#endif


#endif
#endif
