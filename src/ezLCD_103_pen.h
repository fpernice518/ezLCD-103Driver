/**
 * @file   ezLCD_103_pen.h  <br>
 * @author Frank Pernice <br>
 * @date   November 2013  <br>
 * @brief  ezLCD pen adjustment header file  <br>
 * @defgroup ezLCD_103_pen Pen
 * @{
 *
 * This header contains functions that control the pen width(size), and height.
 * These parameters are used when drawing shapes to the <b>current frame</b>.
 *
 * Pen height is only used when drawing curves objects such as unfilled circles
 * and arcs. Otherwise it is ignored. The image below illustrates the concepts
 * of pen height and pen width(size).
 *
 * @image html pen.png "Relationship between pen width(size) and height"
 *
 */
#ifndef EZLCD_PEN_H
#define EZLCD_PEN_H
/*----------------------------------------------------------------------------*/
/* INCLUDES                                                                   */
/*----------------------------------------------------------------------------*/
#include "ezLCD_103_common.h"

/*----------------------------------------------------------------------------*/
/* FUNCTIONS                                                                  */
/*----------------------------------------------------------------------------*/
/** This function is used to set the pen size or width; the horizontal dimension
 *  of the drawing pen.
 *
 *  @par Parameters
 *       - size = The desired pen width or size.
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
void ezLCD_set_pen_size(uint8_t size);

/** This function is used to set the pen height; the vertical dimension
 *  of the drawing pen.
 *
 *  @par Parameters
 *       - height = The desired pen height.
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
void ezLCD_set_pen_height(uint8_t height);



#endif /* EZLCD_PEN_H */
/** @} */ /* ezLCD_103_pen */