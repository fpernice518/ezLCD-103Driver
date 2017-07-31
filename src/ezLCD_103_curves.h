/**
 * @file   ezLCD_103_curves.h  <br>
 * @author Frank Pernice <br>
 * @date   November 2013  <br>
 * @brief  ezLCD curved images header file  <br>
 * @defgroup ezLCD_103_curves Curves
 * @{
 *
 * This header contains functions which aid in the drawing of curved objects
 * such as circles, ellipses, arcs, and pies. 
 
 * Like the EA DOGM128, angles are
 * specified rather unconventionally. In this case, the unit circle is flipped
 * along the line y=x, resulting in the following angle placements:
 *
 * @image html angles.png "Angle placements on the ezLCD+103"
 * Notice that 0 degrees is on the north pole of the Y-axis and 90 degrees
 * is on the east end of the X-axis.
 *
 * <b> NOTE: The EZLCD+103 only understands positive angles from 0-360 degrees.
 *           It does not understand negative angles nor does it understand 
 *           large angles such as 720 degrees. When supplying an angle to
 *           the ezLCD+103, it must be converted to a positive angle between
 *           0 and 360 degrees. Supplying values outside of this range may
 *           result in unusual behavior and a sluggish display for some time
 *           while the display tries to interpret the angle. IT IS HIGHLY
 *           ENCOURAGED TO ONLY SUPPLY THE DISPLAY WITH ANGLES FROM 0-360
 *           DEGREES!</b>
 *
 * Also similar to the EA DOGM128, angles are not specified in degrees and must
 * be converted before being supplied to any functions in this file which may
 * request angles. However, the ezLCD specifies angles with 16-bit precision 
 * rather than 8-bit precision. In order to convert from <b>degrees</b> to <b> 
 * LCD angle units</b> the user should use the following formula
 *
 * <b>LCD Angle Units</b> = <b>degrees</b> * (2048)/45
 * 
 * So, for example: 
 *     - 360 degrees = 16384 LCD angle units = 0 LCD angle units = 0 degrees
 *                      (due to 16-bit overflow).
 *     - 90 degrees = 4096 LCD angle units
 *     - 180 degrees = 8192 LCD angle units
 *     - 270 degrees = 12288 LCD angle units
 *
 * As was the case previously, fractional results from this equation should be 
 * rounded or truncated accordingly.
 *
 */
 
#ifndef EZLCD_CURVES_H
#define EZLCD_CURVES_H
/*----------------------------------------------------------------------------*/
/* INCLUDES                                                                   */
/*----------------------------------------------------------------------------*/
#include "ezLCD_103_common.h"

/*----------------------------------------------------------------------------*/
/* FUNCTIONS                                                                  */
/*----------------------------------------------------------------------------*/
/** This function is used to draw an unfilled circle as shown below from the
 *  <b> current position </b> in the <b> current color </b> at the 
 *  <b> current pen width </b> and <b> current pen height </b>.
 *
 *  @image html circle_unfilled.png "Unfilled Circle"
 *
 *  @par Parameters
 *        - @a radius = the radius of the circle in the set [0,65535].
 *
 *  @par Assumptions
 *       - The user has set the <b>current position </b>,the <b>current color
 *         </b>, the <b>current pen width</b>, and the <b>current pen height</b>
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
void ezLCD_draw_circle(uint16_t radius);

/** This function is used to draw a filled circle as shown below from the
 *  <b> current position </b> in the <b> current color </b>.
 *
 *  @image html circle_filled.png "Filled Circle"
 *
 *  @par Parameters
 *        - @a radius = the radius of the circle in the set [0,65535].
 *
 *  @par Assumptions
 *       - The user has set the <b>current position </b> and the <b>current 
 *         color</b>.
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
void ezLCD_draw_circle_fill(uint16_t radius);

/** This function is used to draw an arc as shown below from the
 *  <b> current position </b> in the <b> current color </b> at the 
 *  <b> current pen width </b> and <b> current pen height </b>.
 *  @image html arc.png "Arc"
 *
 *  @par Parameters
 *        - @a radius = the radius of the arc in the set [0,65535].
 *        - @a start_angle = the angle at which drawing will begin in the set
 *                           [0,16384].
 *        - @a end_angle = the angle at which drawing will end in the set
 *                           [0,16384].
 *
 *  @par Assumptions
 *       - The user does not exceed the angle limits. The ezLCD+103 only
 *         understands positive angles from 0 to 360 degrees. Anything
 *         greater renders extremely slowly and is undefined.
 *       - The user has set the <b>current position </b>,the <b>current color
 *         </b>, the <b>current pen width</b>, and the <b>current pen height</b>
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
void ezLCD_draw_arc(uint16_t radius, uint16_t start_angle, uint16_t end_angle);

/** This function is used to draw a pie as shown below from the
 *  <b> current position </b> in the <b> current color </b>.
 *  @image html pie.png "Pie"
 *
 *  @par Parameters
 *        - @a radius = the radius of the arc in the set [0,65535].
 *        - @a start_angle = the angle at which drawing will begin in the set
 *                           [0,16384].
 *        - @a end_angle = the angle at which drawing will end in the set
 *                           [0,16384].
 *
 *  @par Assumptions
 *       - The user does not exceed the angle limits. The ezLCD+103 only
 *         understands positive angles from 0 to 360 degrees. Anything
 *         greater renders extremely slowly and is undefined.
 *       - The user has set the <b>current position </b> and the <b>current 
 *         color</b>.
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
void ezLCD_draw_pie(uint16_t radius, uint16_t start_angle, uint16_t end_angle);

/** This function is used to draw an unfilled ellipse as shown below from the
 *  <b> current position </b> in the <b> current color </b> at the 
 *  <b> current pen width </b> and <b> current pen height </b>.
 *  @image html ellipse_unfilled.png "Unfilled Ellipse"
 *
 *  @par Parameters
 *        - @a semi_major_axis = length of the semi-major axis (length @b a in  
 *                               the image above.) in the set [0,65535].
 *        - @a semi_minor_axis = length of the semi-minor axis (length @b b in  
 *                               the image above.) in the set [0,65535].
 *
 *  @par Assumptions
 *       - The user has set the <b>current position </b>,the <b>current color
 *         </b>, the <b>current pen width</b>, and the <b>current pen height</b>
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
void ezLCD_draw_ellipse(uint16_t semi_major_axis, uint16_t semi_minor_axis);

/** This function is used to draw a filled ellipse as shown below from the
 *  <b> current position </b> in the <b> current color </b>. 
 *  @image html ellipse_filled.png "Filled Ellipse"
 *
 *  @par Parameters
 *        - @a semi_major_axis = length of the semi-major axis (length @b a in  
 *                               the image above.) in the set [0,65535].
 *        - @a semi_minor_axis = length of the semi-minor axis (length @b b in  
 *                               the image above.) in the set [0,65535].
 *
 *  @par Assumptions
 *       - The user has set the <b>current position </b> and the <b>current 
 *         color</b>.
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
void ezLCD_draw_ellipse_fill(uint16_t semi_major_axis, uint16_t semi_minor_axis);

/** This function is used to draw a elliptical arc as shown below from the
 *  <b> current position </b> in the <b> current color </b>at the 
 *  <b> current pen width </b> and <b> current pen height </b>.
 *  @image html ellipse_arc.png "Elliptical Arc"
 *
 *  @par Parameters
 *        - @a semi_major_axis = length of the semi-major axis (length @b a in  
 *                               the image above.) in the set [0,65535].
 *        - @a semi_minor_axis = length of the semi-minor axis (length @b b in  
 *                               the image above.) in the set [0,65535].
 *        - @a start_angle = the angle at which drawing will begin in the set
 *                           [0,16384].
 *        - @a end_angle = the angle at which drawing will end in the set
 *                           [0,16384].
 *
 *  @par Assumptions
 *       - The user does not exceed the angle limits. The ezLCD+103 only
 *         understands positive angles from 0 to 360 degrees. Anything
 *         greater renders extremely slowly and is undefined.
 *       - The user has set the <b>current position </b>,the <b>current color
 *         </b>, the <b>current pen width</b>, and the <b>current pen height</b>
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
void ezLCD_draw_ellipse_arc(uint16_t semi_major_axis, uint16_t semi_minor_axis,
                            uint16_t start_angle, uint16_t end_angle);

                            
/** This function is used to draw a elliptical pie as shown below from the
 *  <b> current position </b> in the <b> current color</b>.
 *  @image html ellipse_pie.png "Elliptical Pie"
 *
 *  @par Parameters
 *        - @a semi_major_axis = length of the semi-major axis (length @b a in  
 *                               the image above.) in the set [0,65535].
 *        - @a semi_minor_axis = length of the semi-minor axis (length @b b in  
 *                               the image above.) in the set [0,65535].
 *        - @a start_angle = the angle at which drawing will begin in the set
 *                           [0,16384].
 *        - @a end_angle = the angle at which drawing will end in the set
 *                           [0,16384].
 *
 *  @par Assumptions
 *       - The user does not exceed the angle limits. The ezLCD+103 only
 *         understands positive angles from 0 to 360 degrees. Anything
 *         greater renders extremely slowly and is undefined.
 *       - The user has set the <b>current position </b> and the <b>current 
 *         color</b>.
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
void ezLCD_draw_ellipse_pie(uint16_t semi_major_axis, uint16_t semi_minor_axis,
                            uint16_t start_angle, uint16_t end_angle);


#endif /* EZLCD_CURVES_H */
/** @} */ /* ezLCD_103_curves */