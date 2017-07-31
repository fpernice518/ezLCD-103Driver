/**
 * @file   ezLCD_103_lines.h  <br>
 * @author Frank Pernice <br>
 * @date   November 2013  <br>
 * @brief  Header file for drawing lines on the ezLCD+103. <br>
 * @defgroup ezLCD_103_lines Lines
 * @{
 *
 * This header file contains function prototypes for drawing lines on the  
 * ezLCD+103. It includes a generic line-drawing function prototype which works 
 * for lines of all slopes as well as fast line-drawing function prototypes for 
 * horizontal and vertical lines. 
 *<BR><BR>
 *@b NOTE: it is OK for the user to draw a 
 * line off the screen (either in the positive or negative direction with 
 * endpoints in the set of [-32768,32767]). This may be useful to some users as 
 * the manufacturer touts this as a feature of the display; hence none of these 
 * functions perform bounds checking in order to maintain this feature.
 *
 */
 
#ifndef EZLCD_103_LINES_H
#define EZLCD_103_LINES_H
/*----------------------------------------------------------------------------*/
/* INCLUDES                                                                   */
/*----------------------------------------------------------------------------*/
#include "ezLCD_103_common.h"

/*----------------------------------------------------------------------------*/
/* FUNCTIONS                                                                  */
/*----------------------------------------------------------------------------*/

/** This function is used to draw generic lines of any slope to the screen. 
 *  If the user is only drawing horizontal or vertical lines, it is advised
 *  to use one of the other two functions in this file respectively to  
 *  conserve system resources. The function draws a line between the <b> current
 *  position. </b> and the provided XY coordinate. The <b>current position</b> 
 *  is then updated to the provided XY coordinate.
 *
 *  @par Parameters
 *        - @a x = X coordinate of the line's endpoint; in the set of 
 *                 [-32768,32767].
 *        - @a y = Y coordinate of the line's endpoint; in the set of 
 *                 [-32768,32767].
 *
 *  @par Assumptions
 *       - The user has appropriately set the <b>current position</b> using the
 *         ezLCD_set_xy() function or another function which alters the 
 *         <b>current position</b>.
 *       - The user has set a desired pen size with ezLCD_set_pen_size() or
 *         is willing to use the most recently set pen size.
 *       - The user has chosen a line color with the ezLCD_set_color_rgb()
 *         function or is willing to use the most recently set color.
 */
void ezLCD_draw_line(int16_t x, int16_t y);

/** This function is used to draw horizontal lines only to the screen.
 *  If the user needs to draw a horizontal line, this function is preferred to 
 *  conserve system resources. The function draws a line between the <b> 
 *  current position. </b> and the provided X coordinate. The <b>current 
 *  position</b> is then updated to the provided X coordinate.
 *
 *  @par Parameters
 *        - @a x = X coordinate of the line's endpoint; in the set of 
 *                 [-32768,32767].
 *
 *  @par Assumptions
 *       - The user has appropriately set the <b>current position</b> using the
 *         ezLCD_set_xy() function or another function which alters the 
 *         <b>current position</b>.
 *       - The user has set a desired pen size with ezLCD_set_pen_size() or
 *         is willing to use the most recently set pen size.
 *       - The user has chosen a line color with the ezLCD_set_color_rgb()
 *         function or is willing to use the most recently set color.
 */
void ezLCD_draw_h_line(int16_t x);

/** This function is used to draw vertical lines only to the screen. 
 *  If the user needs to draw a vertical line, this function is preferred to 
 *  conserve system resources. The function draws a line between the <b> current 
 *  position. </b> and the provided Y coordinate. The <b>current position</b> is
 *  then updated to the provided Y coordinate.
 *
 *  @par Parameters
 *       - @a y = Y coordinate of the line's endpoint; in the set of 
 *                 [-32768,32767].
 *
 *  @par Assumptions
 *       - The user has appropriately set the <b>current position</b> using the
 *         ezLCD_set_xy() function or another function which alters the 
 *         <b>current position</b>.
 *       - The user has set a desired pen size with ezLCD_set_pen_size() or
 *         is willing to use the most recently set pen size.
 *       - The user has chosen a line color with the ezLCD_set_color_rgb()
 *         function or is willing to use the most recently set color.
 */
void ezLCD_draw_v_line(int16_t y);


#endif /* EZLCD_103_LINES_H */
/** @} */ /* ezLCD_103_lines */