/*
 * @file   ezLCD_103_pixels.c  <br>
 * @author Frank Pernice <br>
 * @date   November 2013  <br>
 * @brief  ezLCD pixel drawing source file  <br>
 * @defgroup ezLCD_103_pixels Pixels
 * @{
 *
 * This source contains functions that plot single pixels to the <b> current
 * frame</b>.
 *
 */
 
/*----------------------------------------------------------------------------*/
/* INCLUDES                                                                   */
/*----------------------------------------------------------------------------*/
#include "ezLCD_103_common.h"

/*----------------------------------------------------------------------------*/
/* FUNCTIONS                                                                  */
/*----------------------------------------------------------------------------*/
void ezLCD_set_plot_pixel(void)
{
 ezLCD_transfer_data(0x26);
}

void ezLCD_set_plot_pixel_xy(uint16_t x, uint16_t y)
{
 ezLCD_transfer_data_long(0x3E,0);
 ezLCD_transfer_data_long(x >> 8,0);
 ezLCD_transfer_data_long(x & 0xFF,0);
 ezLCD_transfer_data_long(y >> 8,0);
 ezLCD_transfer_data_long(y & 0xFF,1);
}
/** @} */ /* ezLCD_103_pixels */