// Copyright 2023
// SPDX-License-Identifier: GPL-2.0-or-later

// github.com/qmk/qmk_firmware/blob/master/docs/config_options.md

#pragma once

/* disable action features */
// #define NO_ACTION_TAPPING  // kills MO and LT layer keys!!!

/* BootMagic buttons */  // docs.qmk.fm/#/feature_bootmagic qmk.github.io/qmk_mkdocs/master/en/feature_bootmagic/   #define in config.h at either keyboard or keymap level.  github.com/qmk/qmk_firmware/blob/master/docs/feature_bootmagic.md
#define BOOTMAGIC_KEY_SALT KC_PGUP	        // Bootmagic key. default KC_SPACE
#define BOOTMAGIC_KEY_BOOTLOADER KC_PGDN    // Enter bootloader. default KC_B
#define BOOTMAGIC_KEY_DEBUG_ENABLE KC_BTN3  // Toggle debug over serial. default KC_D
#define BOOTMAGIC_KEY_DEBUG_MATRIX KC_X     // Toggle matrix debug. default KC_X
#define BOOTMAGIC_KEY_DEBUG_KEYBOARD KC_K   // Toggle keyboard debug. default KC_K
#define BOOTMAGIC_KEY_DEBUG_MOUSE KC_M      // Toggle mouse debug. default KC_M
#define BOOTMAGIC_HOST_NKRO KC_N            // Toggle NKRO. default KC_N
// full bootmagic was removed?   github.com/qmk/qmk_firmware/pull/13846/files
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 5         // 05 fwd-most side button, see info.json for row/col

/* SPI PMW3360 setting. */  // docs.qmk.fm/#/feature_pointing_device
#define SPI_DRIVER SPID1       // GP10-13 (bottom) uses SPI 1 peripheral. Must be set in mcuconfig.h
#ifdef SPI_DRIVER
#define SPI_SCK_PIN GP10       // spi0 sck
#define SPI_MOSI_PIN GP11      // spi0 tx
#define SPI_MISO_PIN GP12
#define PMW33XX_CS_PIN GP9     // spi1 sck. ncs can be any usable pin
#define PMW33XX_CPI 1300       // 100-12000, increments of 100. Default 1600. Logitech G300s:1250 dpi via ratslap
//#define CPI_3360 1200        // my own function in keymap.c
#define PMW3360_LIFTOFF_DISTANCE 0x06 // Default 0x02 , goes to at least 0x27
#define POINTING_DEVICE_DEBUG  // testing
#endif

/* encoder wheel settings. */    // docs.qmk.fm/#/feature_encoders
#define ENCODERS_PAD_A { GP2 }
#ifdef ENCODERS_PAD_A
#define ENCODERS_PAD_B { GP0 }
//#define ENCODER_DIRECTION_FLIP  // if scrolling backwards
#define ENCODER_RESOLUTION 2      // how many pulses the encoder registers between each detent
#define DEBOUNCE 5                // default 5 ms
//#define DEBOUNCE_TYPE = sym_eager_pk // sym_defer_g default, wait X ms for no changes. try sym_eager_pk ignore further inputs for X ms
//#define ENCODER_MAP_KEY_DELAY 10 // by default encoder map delay matches value of TAP_CODE_DELAY (default 0) Sets delay between register_code and unregister_code, if you're having issues with it registering properly (common on VUSB boards).
#endif

/* Accelerated-mode mouse key settings */
// docs.qmk.fm/#/feature_mouse_keys  github.com/qmk/qmk_firmware/blob/master/docs/feature_mouse_keys.md#accelerated-mode
// Accel useful for R/L wheel tilt. May not be useful or even used for encoder. Delay & interval should effect encoder (?)
#define MOUSEKEY_WHEEL_DELAY 1 	// Delay between pressing wheel key and wheel movement, default 10
#define MOUSEKEY_WHEEL_INTERVAL 50 		// Time between wheel movements, default 80
#define MOUSEKEY_WHEEL_MAX_SPEED 1 		// Max scroll steps per scroll action, default 8
#define MOUSEKEY_WHEEL_TIME_TO_MAX 100	// Time until maximum scroll speed is reached, default 40

#define TAPPING_TERM 200                // using tap_specific_tapping_term

// Enables support for extended reports (-32767 to 32767, instead of -127 to 127), which may allow for smoother reporting, and prevent maxing out of the reports. Applies to both Pointing Device and Mousekeys.  github.com/qmk/qmk_firmware/blob/master/docs/config_options.md
#define MOUSE_EXTENDED_REPORT

/* RGB settings */  // docs.qmk.fm/#/feature_rgblight  bastardkb_charybdis/3x5/v2/splinky/config.h
#define RGB_DI_PIN GP16  // GP16: rp2040-zero onboard rgb
#ifdef RGB_DI_PIN
// #define RGBW        // qmk.github.io/qmk_mkdocs/master/en/config_options/#rgb-light-configuration
#define WS2812_PIO_USE_PIO1 // Set WS2812 to use PIO1. Default PIO0. github.com/qmk/qmk_firmware/blob/master/docs/ws2812_driver.md#pio
#define RGBLED_NUM 1              // test with 1
#define RGBLIGHT_LAYERS
#define RGBLIGHT_DEFAULT_HUE 180  // 180 violet, default 0 red, when clearing EEPROM
#define RGBLIGHT_DEFAULT_VAL 5    // value (brightness), when clearing EEPROM
#define RGBLIGHT_SLEEP            // If defined, RGB lighting will be switched off when host goes to sleep
#define RGBLIGHT_LAYERS_RETAIN_VAL  // lighting layers retain the current brightness
#define RGBLIGHT_EFFECT_BREATHING
//#define RGBLIGHT_ANIMATIONS
//#define RGBLIGHT_EFFECT_RAINBOW_MOOD
//#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
//#define RGBLIGHT_HUE_STEP 8
//#define RGBLIGHT_SAT_STEP 8
//#define RGBLIGHT_VAL_STEP 8
#define RGB_MATRIX_LED_COUNT 1  // if using rgb key matrix
//#define DRIVER_COUNT 1        // needed for WS2812 ?
#endif

/* Haptic feedback settings */      // docs.qmk.fm/#/feature_haptic_feedback
#define SOLENOID_PIN GP3            // change, test
//#define SOLENOID_PIN_ACTIVE_LOW 	// default:Not defined 	If defined then the switch trigger pin is active low.

/* Double Tap Reset for Bootloader */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U
//#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17     // no regular led present on rp2040-zero

// docs.qmk.fm/#/faq_keymap?id=how-can-i-make-custom-names-for-complex-keycodes
// docs.qmk.fm/#/keycodes?id=modifiers
#define A_TAB RALT(KC_TAB)
#define S_TAB RSFT(KC_TAB)
#define CTL_C RCTL(KC_C)
#define CTL_V RCTL(KC_V)
#define CS_C RCS(KC_C)
#define CS_V RCS(KC_V)
