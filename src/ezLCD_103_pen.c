/*
 * @file   ezLCD_103_pen.c  <br>
 * @author Frank Pernice <br>
 * @date   November 2013  <br>
 * @brief  ezLCD pen adjustment source file  <br>
 * @defgroup ezLCD_103_pen Pen
 * @{
 *
 * This source contains functions that control the pen width(size), and height.
 * These parameters are used when drawing shapes to the <b>current frame</b>.
 *
 *
 */

 /*----------------------------------------------------------------------------*/
/* INCLUDES                                                                   */
/*----------------------------------------------------------------------------*/
#include "ezLCD_103_common.h"

/*----------------------------------------------------------------------------*/
/* FUNCTIONS                                                                  */
/*----------------------------------------------------------------------------*/
void ezLCD_set_pen_size(uint8_t size)
{
 ezLCD_transfer_data_long(0x81,0);
 ezLCD_transfer_data_long(size,1);
}

void ezLCD_set_pen_height(uint8_t height)
{
 ezLCD_transfer_data_long(0x82,0);
 ezLCD_transfer_data_long(height,1);
}
/** @} */ /* ezLCD_103_pen */