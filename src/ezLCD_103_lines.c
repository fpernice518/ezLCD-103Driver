/*
 * @file   ezLCD_103_lines.c  <br>
 * @author Frank Pernice <br>
 * @date   November 2013  <br>
 * @brief  source file for drawing lines on the ezLCD+103. <br>
 * @defgroup ezLCD_103_lines Lines
 * @{
 *
 * This source file contains functions for drawing lines on the  
 * ezLCD+103. It includes a generic line-drawing function prototype which works 
 * for lines of all slopes as well as fast line-drawing functions for 
 * horizontal and vertical lines. 
 */
 
/*----------------------------------------------------------------------------*/
/* INCLUDES                                                                   */
/*----------------------------------------------------------------------------*/
#include "ezLCD_103_common.h"

/*----------------------------------------------------------------------------*/
/* FUNCTIONS                                                                  */
/*----------------------------------------------------------------------------*/
void ezLCD_draw_line(int16_t x, int16_t y)
{
 ezLCD_transfer_data_long(0x3F,0);
 ezLCD_transfer_data_long(x >> 8,0);
 ezLCD_transfer_data_long(x & 0xFF,0);
 ezLCD_transfer_data_long(y >> 8,0);
 ezLCD_transfer_data_long(y & 0xFF,1);
}

void ezLCD_draw_h_line(int16_t x)
{
 ezLCD_transfer_data_long(0xA0,0);
 ezLCD_transfer_data_long(x >> 8,0);
 ezLCD_transfer_data_long(x & 0xFF,1);
}

void ezLCD_draw_v_line(int16_t y)
{
 ezLCD_transfer_data_long(0xA1,0);
 ezLCD_transfer_data_long(y >> 8,0);
 ezLCD_transfer_data_long(y & 0xFF,1);
}
/** @} */ /* ezLCD_103_lines */