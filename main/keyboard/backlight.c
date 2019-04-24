/* Copyright (c) 2015 Nordic Semiconductor. All Rights Reserved.
 *
 * The information contained herein is property of Nordic Semiconductor ASA.
 * Terms and conditions of usage are described in detail in NORDIC
 * SEMICONDUCTOR STANDARD SOFTWARE LICENSE AGREEMENT.
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRANTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 *
 */

/** @file
 *
 * @defgroup low_power_pwm_example_main main.c
 * @{
 * @ingroup low_power_pwm_example
 * @brief Low Power PWM Example Application main file.
 *
 *
 */
 
#include <stdbool.h>
#include <stdint.h>
#include "nrf_delay.h"
#include "nrf_gpio.h"
#include "keyboard_conf.h"
#include "app_error.h"
#include "sdk_errors.h"
#include "app_timer.h"
#include "app_util_platform.h"
#include "low_power_pwm.h"
#include "nordic_common.h"
#include "backlight.h"

/*Ticks before change duty cycle of each LED*/
#define TICKS_BEFORE_CHANGE_0   500
#define TICKS_BEFORE_CHANGE_1   300
#define TICKS_BEFORE_CHANGE_2   200

static low_power_pwm_t low_power_pwm_0;
static low_power_pwm_t low_power_pwm_1;
static low_power_pwm_t low_power_pwm_2;

/**
 * @brief Function to be called in timer interrupt.
 *
 * @param[in] p_context     General purpose pointer (unused).
 */
void pwm_handler(void * p_context)
{
   /* uint8_t new_duty_cycle;
    static uint16_t led_0, led_1, led_2;
    uint32_t err_code;
    UNUSED_PARAMETER(p_context);
    
    low_power_pwm_t * pwm_instance = (low_power_pwm_t*)p_context;
    
    if(pwm_instance->bit_mask == LED_0_MASK)
    {
        led_0++;
        
        if(led_0 > TICKS_BEFORE_CHANGE_0)
        {
            new_duty_cycle = pwm_instance->period - pwm_instance->duty_cycle;
            err_code = low_power_pwm_duty_set(pwm_instance, new_duty_cycle);
            led_0 = 0;
            APP_ERROR_CHECK(err_code);
        }
    }
    else if(pwm_instance->bit_mask == LED_1_MASK)
    {
        led_1++;

        if(led_1 > TICKS_BEFORE_CHANGE_1)
        {
            new_duty_cycle = pwm_instance->period - pwm_instance->duty_cycle;
            err_code = low_power_pwm_duty_set(pwm_instance, new_duty_cycle);
            led_1 = 0;
            APP_ERROR_CHECK(err_code);
        }
    }else if(pwm_instance->bit_mask == LED_2_MASK)
    {
        led_2++;

        if(led_2 > TICKS_BEFORE_CHANGE_2)
        {
            new_duty_cycle = pwm_instance->period - pwm_instance->duty_cycle;
            err_code = low_power_pwm_duty_set(pwm_instance, new_duty_cycle);
            led_2 = 0;
            APP_ERROR_CHECK(err_code);
        }
    }
    else
    {

    }           */
}
/**
 * @brief Function to initalize low_power_pwm instances.
 *
 */

void low_power_init(void)
{
    uint32_t err_code;
    low_power_pwm_config_t low_power_pwm_config;
	
    APP_TIMER_DEF(lpp_timer_0);
    low_power_pwm_config.active_high = false;
    low_power_pwm_config.period = 220;
    low_power_pwm_config.bit_mask = LED_0_MASK;
    low_power_pwm_config.p_timer_id = &lpp_timer_0;
    
    err_code = low_power_pwm_init((&low_power_pwm_0), &low_power_pwm_config, pwm_handler);
    APP_ERROR_CHECK(err_code);
    err_code = low_power_pwm_duty_set(&low_power_pwm_0, 20);
    APP_ERROR_CHECK(err_code);
    
    APP_TIMER_DEF(lpp_timer_1);
    low_power_pwm_config.active_high = false;
    low_power_pwm_config.period = 200;
    low_power_pwm_config.bit_mask = LED_1_MASK;
    low_power_pwm_config.p_timer_id = &lpp_timer_1;
    
    err_code = low_power_pwm_init((&low_power_pwm_1), &low_power_pwm_config, pwm_handler);
    APP_ERROR_CHECK(err_code);
    err_code = low_power_pwm_duty_set(&low_power_pwm_1, 150);
    APP_ERROR_CHECK(err_code);
    
    APP_TIMER_DEF(lpp_timer_2);
    low_power_pwm_config.active_high = false;
    low_power_pwm_config.period = 200;
    low_power_pwm_config.bit_mask = LED_2_MASK;
    low_power_pwm_config.p_timer_id = &lpp_timer_2;
    
    err_code = low_power_pwm_init((&low_power_pwm_2), &low_power_pwm_config, pwm_handler);
    APP_ERROR_CHECK(err_code);
    err_code = low_power_pwm_duty_set(&low_power_pwm_2, 150);
    APP_ERROR_CHECK(err_code);    
    
    err_code = low_power_pwm_start((&low_power_pwm_0), low_power_pwm_0.bit_mask);
    APP_ERROR_CHECK(err_code);
    err_code = low_power_pwm_start((&low_power_pwm_1), low_power_pwm_1.bit_mask);
    APP_ERROR_CHECK(err_code);
    err_code = low_power_pwm_start((&low_power_pwm_2), low_power_pwm_2.bit_mask);
    APP_ERROR_CHECK(err_code);

}

