/**
 * @file   ezLCD_103_fill.h  <br>
 * @author Frank Pernice <br>
 * @date   November 2013  <br>
 * @brief  ezLCD color filling header file  <br>
 * @defgroup ezLCD_103_fill Fill
 * @{
 *
 * This header contains functions which are used to fill a defined area with a 
 * particular color. 
 *
 */
#ifndef EZLCD_103_FILL_H
#define EZLCD_103_FILL_H
/*----------------------------------------------------------------------------*/
/* INCLUDES                                                                   */
/*----------------------------------------------------------------------------*/
#include "ezLCD_103_common.h"

/*----------------------------------------------------------------------------*/
/* FUNCTIONS                                                                  */
/*----------------------------------------------------------------------------*/
/** This function is used to clear the entire screen and fill it with the 
 *  <b>current color</b>.
 *
 *  @par Assumptions
 *       - The user has set the <b>current color</b>.
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
void ezLCD_clear(void);

/** This function is used to fill the area surrounding the
 *  <b>current position</b> with the <b>current color</b>. It fills every pixel 
 *  surrounding the  <b>current position</b> which shares the same color. It  
 *  stops when encountering a pixel of a different color. This is similar to the
 *  paint bucket tool in Microsoft Paint or other image editing programs.
 *  
 *  @image html fill.png "Result of the ezLCD_clear() function"
 *
 *  
 *  @par Assumptions
 *       - The user has set the <b>current color</b>.
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
void ezLCD_fill(void);

/** This function is used to fill the area surrounding the
 *  <b>current position</b> with the <b>current color</b>. It fills every pixel 
 *  surrounding the  <b>current position</b> until it hits pixels of the 
 *  specified RGB value.
 *  
 *  @image html fill_bound.png "Result of the ezLCD_clear() function"
 *
 *  @par Parameters
 *       - red   = Red color component [0,255]
 *       - green = Green color component [0,255]
 *       - blue  = Blue color component [0,255]
 *
 *  @par Assumptions
 *       - The user has set the <b>current color</b>.
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
void ezLCD_fill_bound(uint8_t red, uint8_t green, uint8_t blue);

#endif /* EZLCD_103_FILL_H */
/** @} */ /* ezLCD_103_fill */