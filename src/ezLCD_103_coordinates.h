/**
 * @file   ezLCD_103_coordinates.h  <br>
 * @author Frank Pernice <br>
 * @date   November 2013  <br>
 * @brief  ezLCD coordinate management header file  <br>
 * @defgroup ezLCD_103_coordinates Coordinates
 * @{
 *
 * This header file is used to manage the coordinates of the <b> current
 * position. </b>
 *
 * A most drawing functions in this library utilize the <b>current position </b>.
 * The <b>current position </b> can be thought of as a cursor; it indicates
 * the point or starting point where some activity will occur. This value
 * is stored internally on the ezLCD+103 and cannot be read back.
 *
 * Even though the display is 320 pixels wide by 240 pixels tall, the 
 * <b>current position </b> may assume values off of the screen in both the
 * negative and positive direction. This will result in objects being drawn
 * partially or completely off screen.
 *
 * The coordinate system is rather unconventional in comparison to the standard
 * Cartesian coordinate system. In this coordinate system, Y values increase
 * as one moves south while X values increase as one moves east as they do
 * in the regular Cartesian system. Imagine that the screen takes up a portion
 * of the fourth quadrant of the Cartesian plane; however, we take the absolute
 * value of the Y-coordinate. This concept is illustrated in the image below.
 *
 * @image html coordinates.png "Coordinate System of the ezLCD+103"
 *
 */
#ifndef COORDINATES_H
#define COORDINATES_H
/*----------------------------------------------------------------------------*/
/* INCLUDES                                                                   */
/*----------------------------------------------------------------------------*/
#include "ezLCD_103_common.h"

/*----------------------------------------------------------------------------*/
/* FUNCTIONS                                                                  */
/*----------------------------------------------------------------------------*/
/** This function is used to set the XY coordinates of the 
 *  <b>current position</b>.
 *
 *  @par Parameters
 *        - @a x = X coordinate value in the set of [-32768, 32767].
 *        - @a y = Y coordinate value in the set of [-32768, 32767].
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
void ezLCD_set_xy(int16_t x, int16_t y);

/** This function is used to set the X coordinate of the 
 *  <b>current position </b>.
 *
 *  @par Parameters
 *        - @a x = X coordinate value in the set of [-32768, 32767].
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
void ezLCD_set_x(int16_t x);

/** This function is used to set the Y coordinate of the 
 *  <b>current position </b>.
 *
 *  @par Parameters
 *        - @a y = Y coordinate value in the set of [-32768, 32767].
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
void ezLCD_set_y(int16_t y);

/** This function is used save the <b>current position </b> for later use.
 *
 *  @par Parameters
 *        - @a index = index in memory where the <b>current position </b> should be 
 *                     saved. This value is in the set of [0, 255].
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
void ezLCD_save_position(uint8_t index);

/** This function is used restore the <b>current position </b> from memory.
 *
 *  @par Parameters
 *        - @a index = index in memory where the <b>current position </b> should be 
 *                     restored from. This value is in the set of [0, 255].
 *
 *  @par Assumptions
 *       - The user has previously saved the requested current position
 *         using the ezLCD_save_position() function.
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
void ezLCD_restore_position(uint8_t index);


#endif /* COORDINATES_H */
/** @} */ /* ezLCD_103_coordinates */