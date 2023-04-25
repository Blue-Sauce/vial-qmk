# MCU name
MCU = RP2040
BOOTLOADER = rp2040

# Vial options
VIA_ENABLE = yes            # needed for Vial
VIAL_ENABLE = yes
#VIALRGB_ENABLE = yes       # more features. in vial.json: "lighting": "vialrgb",  Alt lighting is "lighting": "qmk_rgblight",
#RGB_MATRIX_ENABLE= yes     # needed for VIALRGB_ENABLE
#RGB_MATRIX_DRIVER = WS2812 # needed for RGB_MATRIX_ENABLE
VIAL_INSECURE = yes        # locked features: changing macros, reset to bootloader, Assigning RESET keycode
