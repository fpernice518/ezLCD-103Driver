/*
 * @file   ezLCD_103_coordinates.c  <br>
 * @author Frank Pernice <br>
 * @date   November 2013  <br>
 * @brief  ezLCD coordinate management source file  <br>
 * @defgroup ezLCD_103_coordinates Coordinates
 * @{
 *
 * This source file is used to manage the coordinates of the <b> current
 * position. </b>
 */
 
/*----------------------------------------------------------------------------*/
/* INCLUDES                                                                   */
/*----------------------------------------------------------------------------*/
#include "ezLCD_103_common.h"

/*----------------------------------------------------------------------------*/
/* FUNCTIONS                                                                  */
/*----------------------------------------------------------------------------*/
void ezLCD_set_xy(int16_t x, int16_t y)
{
 ezLCD_transfer_data_long(0x33,0);
 ezLCD_transfer_data_long(x >> 8,0);
 ezLCD_transfer_data_long(x & 0xFF,0);
 ezLCD_transfer_data_long(y >> 8,0);
 ezLCD_transfer_data_long(y & 0xFF,1);
}

void ezLCD_set_x(int16_t x)
{
 ezLCD_transfer_data_long(0x6E,0);
 ezLCD_transfer_data_long(x >> 8,0);
 ezLCD_transfer_data_long(x & 0xFF,1);
}

void ezLCD_set_y(int16_t y)
{
 ezLCD_transfer_data_long(0x6F,0);
 ezLCD_transfer_data_long(y >> 8,0);
 ezLCD_transfer_data_long(y & 0xFF,1);
}

void ezLCD_save_position(uint8_t index)
{
 ezLCD_transfer_data_long(0x35,0);
 ezLCD_transfer_data_long(index,1);
}

void ezLCD_restore_position(uint8_t index)
{
 ezLCD_transfer_data_long(0x36,0);
 ezLCD_transfer_data_long(index,1);
}
/** @} */ /* ezLCD_103_coordinates */