/*
 * @file   ezLCD_103_system.c  <br>
 * @author Frank Pernice <br>
 * @date   November 2013  <br>
 * @brief  ezLCD system management source file  <br>
 * @defgroup ezLCD_103_system System
 * @{
 *
 * This source contains functions which manage miscellaneous system 
 * settings such as brightness, backlight, and power settings. It also contains
 * a function to ping the display (that is, determine if the screen is ready
 * to receive more commands.
 *
 */
 
/*----------------------------------------------------------------------------*/
/* INCLUDES                                                                   */
/*----------------------------------------------------------------------------*/
#include "ezLCD_103_common.h"

/*----------------------------------------------------------------------------*/
/* FUNCTIONS                                                                  */
/*----------------------------------------------------------------------------*/

void ezLCD_backlight_on(void)
{
  ezLCD_transfer_data(0x22);
}

void ezLCD_backlight_off(void)
{
  ezLCD_transfer_data(0x23);
}

void ezLCD_set_brightness(uint8_t brightness)
{
  ezLCD_transfer_data_long(0x80,0);
  ezLCD_transfer_data_long(brightness,1);
}

uint8_t ezLCD_ping()
{
  uint8_t pong;
  
  ezLCD_transfer_data(0x83);
  pong = ezLCD_transfer_data(0x00);
  
  if(pong == 0x38) return 1;
  else return 0;
}
/** @} */ /* ezLCD_103_system */

