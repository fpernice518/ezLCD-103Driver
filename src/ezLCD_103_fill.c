/*
 * @file   ezLCD_103_fill.c  <br>
 * @author Frank Pernice <br>
 * @date   November 2013  <br>
 * @brief  ezLCD color filling source file  <br>
 * @defgroup ezLCD_103_fill Fill
 * @{
 *
 * This source contains functions which are used to fill a defined area with a 
 * particular color. 
 *
 */
 
/*----------------------------------------------------------------------------*/
/* INCLUDES                                                                   */
/*----------------------------------------------------------------------------*/
#include "ezLCD_103_common.h"

/*----------------------------------------------------------------------------*/
/* FUNCTIONS                                                                  */
/*----------------------------------------------------------------------------*/
void ezLCD_clear(void)
{
 ezLCD_transfer_data(0x21);
}

void ezLCD_fill(void)
{
 ezLCD_transfer_data(0x9B);
}

void ezLCD_fill_bound(uint8_t red, uint8_t green, uint8_t blue)
{
 ezLCD_transfer_data_long(0x9C,0);
 ezLCD_transfer_data_long(red,0);
 ezLCD_transfer_data_long(green,0);
 ezLCD_transfer_data_long(blue,1);
}
/** @} */ /* ezLCD_103_fill */