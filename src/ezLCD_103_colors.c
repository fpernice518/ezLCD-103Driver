/*
 * @file   ezLCD_103_colors.c  <br>
 * @author Frank Pernice <br>
 * @date   November 2013  <br>
 * @brief  ezLCD color management source file  <br>
 * @defgroup ezLCD_103_colors Colors
 * @{
 *
 * This source file is used to manage various color settings used when drawing
 * objects to the ezLCD+103. 
 */

/*----------------------------------------------------------------------------*/
/* INCLUDES                                                                   */
/*----------------------------------------------------------------------------*/
#include "ezLCD_103_common.h"

/*----------------------------------------------------------------------------*/
/* FUNCTIONS                                                                  */
/*----------------------------------------------------------------------------*/

void ezLCD_set_color_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
 ezLCD_transfer_data_long(0x31,0);
 ezLCD_transfer_data_long(red,0);
 ezLCD_transfer_data_long(green,0);
 ezLCD_transfer_data_long(blue,1);
}

void ezLCD_set_alpha(uint8_t alpha)
{
 ezLCD_transfer_data_long(0x20,0);
 ezLCD_transfer_data_long(alpha,1);
}

void ezLCD_set__tr_color_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
 ezLCD_transfer_data_long(0x5A,0);
 ezLCD_transfer_data_long(red,0);
 ezLCD_transfer_data_long(green,0);
 ezLCD_transfer_data_long(blue,1);
}

void ezLCD_tr_color_none(void)
{
 ezLCD_transfer_data(0x5B);
}

void ezLCD_set_background_color(uint8_t red, uint8_t green, uint8_t blue)
{
 ezLCD_transfer_data_long(0x32,0);
 ezLCD_transfer_data_long(red,0);
 ezLCD_transfer_data_long(green,0);
 ezLCD_transfer_data_long(blue,1);
}

void ezLCD_replace_color(uint8_t o_red, uint8_t o_green, uint8_t o_blue,
                         uint8_t n_red, uint8_t n_green, uint8_t n_blue)
{
 ezLCD_transfer_data_long(0x5D,0);
 ezLCD_transfer_data_long(o_red,0);
 ezLCD_transfer_data_long(o_green,0);
 ezLCD_transfer_data_long(o_blue,0);
 ezLCD_transfer_data_long(n_red,0);
 ezLCD_transfer_data_long(n_green,0);
 ezLCD_transfer_data_long(n_blue,1);
}
/** @} */ /* ezLCD_103_colors */