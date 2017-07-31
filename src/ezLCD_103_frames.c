/*
 * @file   ezLCD_103_frames.c  <br>
 * @author Frank Pernice <br>
 * @date   November 2013  <br>
 * @brief  ezLCD frame management source file  <br>
 * @defgroup ezLCD_103_frames Frames
 * @{
 *
 * This source contains functions which are used to set the drawing and display
 * frames. 
 */
 
/*----------------------------------------------------------------------------*/
/* INCLUDES                                                                   */
/*----------------------------------------------------------------------------*/
#include "ezLCD_103_common.h"

/*----------------------------------------------------------------------------*/
/* FUNCTIONS                                                                  */
/*----------------------------------------------------------------------------*/
void ezLCD_set_display_frame(uint8_t frame)
{
 ezLCD_transfer_data_long(0x52,0);
 ezLCD_transfer_data_long(frame,1);
}

void ezLCD_set_draw_frame(uint8_t frame)
{
 ezLCD_transfer_data_long(0x51,0);
 ezLCD_transfer_data_long(frame,1);
}
/** @} */ /* ezLCD_103_frames */