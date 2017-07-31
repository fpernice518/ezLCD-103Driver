/*
 * @file   ezLCD_103_images.c  <br>
 * @author Frank Pernice <br>
 * @date   November 2013  <br>
 * @brief  ezLCD image loading source file  <br>
 * @defgroup ezLCD_103_images Images
 * @{
 *
 * This source contains functions that load images to the <b>current frame</b>.
 *
 */
 
/*----------------------------------------------------------------------------*/
/* INCLUDES                                                                   */
/*----------------------------------------------------------------------------*/
#include "ezLCD_103_common.h"

/*----------------------------------------------------------------------------*/
/* FUNCTIONS                                                                  */
/*----------------------------------------------------------------------------*/
void ezLCD_put_picture_rom(uint16_t picture_number)
{
 ezLCD_transfer_data_long(0x59,0);
 ezLCD_transfer_data_long(picture_number >> 8,0);
 ezLCD_transfer_data_long(picture_number & 0xFF,1);
}

void ezLCD_put_picture_sd(char file_path[], uint8_t length)
{
 uint8_t i;
 
 ezLCD_transfer_data_long(0x70,0);
 
 for(i=0; i < length; ++i)
   ezLCD_transfer_data_long(file_path[i],0);
 
 ezLCD_transfer_data_long(0x00,0);
 
}
/** @} */ /* ezLCD_103_images */
