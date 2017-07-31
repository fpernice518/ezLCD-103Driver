/**
 * @file   ezLCD_103_polygons.h  <br>
 * @author Frank Pernice <br>
 * @date   November 2013  <br>
 * @brief  ezLCD polygon drawing header file  <br>
 * @defgroup ezLCD_103_polygons Polygons
 * @{
 *
 * This header contains functions draw polygons to the <b> current
 * frame</b>. It also has a function ezLCD_set_edit_rectangle() which
 * is used in conjunction with ezLCD_replace_color() to define a rectangular
 * region for editing.
 *
 */
#ifndef EZLCD_POLYGONS_H
#define EZLCD_POLYGONS_H
/*----------------------------------------------------------------------------*/
/* INCLUDES                                                                   */
/*----------------------------------------------------------------------------*/
#include "ezLCD_103_common.h"

/*----------------------------------------------------------------------------*/
/* FUNCTIONS                                                                  */
/*----------------------------------------------------------------------------*/

/** This function is used to draw an unfilled rectangle from the <b>current  
 *  position</b> to the specified XY coordinate in the <b>current color</b>.
 *
 *  @par Parameters
 *       - x2 = X coordinate of the corner opposite the current position.
 *       - y2 = Y coordinate of the corner opposite the current position.
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
void ezLCD_draw_rect(uint16_t x2, uint16_t y2);

/** This function is used to draw a filled rectangle from the <b>current  
 *  position</b> to the specified XY coordinate in the <b>current color</b>.
 *
 *  @par Parameters
 *       - x2 = X coordinate of the corner opposite the current position.
 *       - y2 = Y coordinate of the corner opposite the current position.
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
void ezLCD_draw_rect_fill(uint16_t x2, uint16_t y2);

/** Draws an <b>n sided</b> polygon filled with the <b>current color</b>. The 
 *  first vertex is located at the <b>current position</b>.
 *
 *  @image html polygon.png "Example of polygon drawing"
 *
 *  @par Parameters
 *       - n  = The number of vertices on the polygon
 *       - x[] = X coordinates of the verticies (exclusing the current position)
 *       - y[] = Y coordinates of the verticies (exclusing the current position)
 *
 *  @par Assumptions
 *       - Both arrays are filled as follows for some number @b i:
 *           - x[i] and y[i] implies  that coordinate (x[i],y[i]) is a vertex of 
 *             the polygon. 
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
void ezLCD_draw_polygon(uint8_t n, uint16_t x[], uint16_t y[]);

/** Defines a rectangular region for editing by the ezLCD_replace_color()
 *  function. 
 *
 *  @par Parameters
 *       - x = X coordinate of the upper-left hand corner of the rectangular 
 *             region.
 *       - y = Y coordinate of the upper-left hand corner of the rectangular
 *             region.
 *
 *       - width  = Width of the rectangular region to be edited.
 *       - height = Height of the rectangular region to be edited.
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
void ezLCD_set_edit_rectangle(int16_t x,
                              int16_t y,
                              uint16_t width,
                              uint16_t height);

#endif /* EZLCD_POLYGONS_H */
/** @} */ /* ezLCD_103_polygons */