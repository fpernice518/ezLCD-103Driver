/**
 * @file   ezLCD_103_pixels.h  <br>
 * @author Frank Pernice <br>
 * @date   November 2013  <br>
 * @brief  ezLCD pixel drawing header file  <br>
 * @defgroup ezLCD_103_pixels Pixels
 * @{
 *
 * This header contains functions that plot single pixels to the <b> current
 * frame</b>.
 *
 */

#ifndef EZLCD_PIXELS_H
#define EZLCD_PIXELS_H
/*----------------------------------------------------------------------------*/
/* INCLUDES                                                                   */
/*----------------------------------------------------------------------------*/
#include "ezLCD_103_common.h"

/*----------------------------------------------------------------------------*/
/* FUNCTIONS                                                                  */
/*----------------------------------------------------------------------------*/
/** This function is used to plot a single pixel at the <b>current position</b>
 *  in the <b>current color</b>.
 *
 *  @par Assumptions
 *       - The user has initialized the MCU's SPI interface with the
 *         EZLCD_INIT_SPI() macro.
 *       - The user has set the MCU's SPI pins to inputs and outputs 
 *         appropriately. <BR><BR>
 *         - SS_BAR = OUTPUT
 *         - SCK    = OUTPUT
 *         - MOSI   = OUTPUT
 *         - MISO   = INPUT
 *
 */ 
void ezLCD_set_plot_pixel(void);

/** This function is used to plot a single pixel at the specified XY coordinate
 *  in the <b>current color</b>.
 *
 *  @par Parameters
 *       - x = X coordinate of the desired pixel
 *       - y = Y coordinate of the desired pixel
 *
 *  @par Assumptions
 *       - The user has initialized the MCU's SPI interface with the
 *         EZLCD_INIT_SPI() macro.
 *       - The user has set the MCU's SPI pins to inputs and outputs 
 *         appropriately. <BR><BR>
 *         - SS_BAR = OUTPUT
 *         - SCK    = OUTPUT
 *         - MOSI   = OUTPUT
 *         - MISO   = INPUT
 *
 */ 
void ezLCD_set_plot_pixel_xy(uint16_t x, uint16_t y);

#endif /* EZLCD_PIXELS_H */
/** @} */ /* ezLCD_103_pixels */