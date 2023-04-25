# docs.qmk.fm/#/platformdev_rp2040?id=generic-rp2040-board
BOARD = GENERIC_RP_RP2040

# qmk.github.io/qmk_mkdocs/master/en/feature_bootmagic/
BOOTMAGIC_ENABLE = yes

#VIA_ENABLE = yes

# Debug #
CONSOLE_ENABLE = yes

# For timers. And led_indicator commands #
# github.com/qmk/qmk_firmware/blob/master/keyboards/ploopyco/trackball_nano/keymaps/lkbm/rules.mk
DEFERRED_EXEC_ENABLE = yes

# Allows switching to nkro by button toggle
# Still defaults / starts in 6kro, #define FORCE_NKRO in config.h to start in nkro. Button toggle saves to eeprom.
NKRO_ENABLE = no

TAP_DANCE_ENABLE=yes

# Mouse keys, Audio control and System control #
# Can also be defined in info.json but rules.mk takes precedence. "extrakey": true, "mousekey": true,
MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes

# docs.qmk.fm/#/feature_key_overrides
KEY_OVERRIDE_ENABLE = yes
# docs.qmk.fm/#/feature_combo
#COMBO_ENABLE = yes

# Enable pointer and driver #
# docs.qmk.fm/#/feature_pointing_device
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = pmw3360
###SERIAL_DRIVER = vendor

# docs.qmk.fm/#/feature_encoders
# VIA www.caniusevia.com/docs/layouts#rotary-encoders
ENCODER_ENABLE = yes
ENCODER_MAP_ENABLE = yes

# rp2040 RGB #
# github.com/qmk/qmk_firmware/blob/master/docs/ws2812_driver.md#pio
RGBLIGHT_ENABLE = yes
WS2812_DRIVER = vendor

# docs.qmk.fm/#/feature_haptic_feedback
#HAPTIC_ENABLE = yes
#HAPTIC_DRIVER += SOLENOID
