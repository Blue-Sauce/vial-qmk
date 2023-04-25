#pragma once

/* pmw3360 pointer */
// docs.qmk.fm/#/platformdev_rp2040?id=selecting-hardware-peripherals-and-drivers
/* Enable SPI */
// chibios.sourceforge.net/docs3/hal/group___s_p_i.html
#define HAL_USE_SPI TRUE   // required for SPI driver
#define SPI_USE_WAIT TRUE  // Necessary? Enables synchronous APIs. Disabling saves both code and data space.
#define SPI_SELECT_MODE SPI_SELECT_MODE_PAD  // Necessary? Handling method for SPI CS line. Disabling saves both code and data space.

/* Enable I2C */
// chibios.sourceforge.net/docs3/hal/group___s_p_i.html
// #define HAL_USE_I2C TRUE   // required for I2C driver

#include_next <halconf.h>
