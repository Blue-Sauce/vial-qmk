/*  */

#pragma once

#include_next <mcuconf.h>

/* pmw3360 pointer */
/* Set SPI peripheral to use */  // https://docs.qmk.fm/#/platformdev_rp2040?id=selecting-hardware-peripherals-and-drivers
#undef RP_SPI_USE_SPI1
#define RP_SPI_USE_SPI1 TRUE  // GP10-13 (bottom) uses SPI 1 peripheral
