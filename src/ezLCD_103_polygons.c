/*
 * @file   ezLCD_103_polygons.c  <br>
 * @author Frank Pernice <br>
 * @date   November 2013  <br>
 * @brief  ezLCD polygon drawing source file  <br>
 * @defgroup ezLCD_103_polygons Polygons
 * @{
 *
 * This source contains functions draw polygons to the <b> current
 * frame</b>. It also has a function ezLCD_set_edit_rectangle() which
 * is used in conjunction with ezLCD_replace_color() to define a rectangular
 * region for editing.
 *
 */
 
/*----------------------------------------------------------------------------*/
/* INCLUDES                                                                   */
/*----------------------------------------------------------------------------*/
#include "ezLCD_103_common.h"

/*----------------------------------------------------------------------------*/
/* FUNCTIONS                                                                  */
/*----------------------------------------------------------------------------*/
void ezLCD_draw_rect(uint16_t x2, uint16_t y2)
{
 ezLCD_transfer_data_long(0xA4,0);
 ezLCD_transfer_data_long(x2 >> 8,0);
 ezLCD_transfer_data_long(x2 & 0xFF,0);
 ezLCD_transfer_data_long(y2 >> 8,0);
 ezLCD_transfer_data_long(y2 & 0xFF,1);
}

void ezLCD_draw_rect_fill(uint16_t x2, uint16_t y2)
{
 ezLCD_transfer_data_long(0xA5,0);
 ezLCD_transfer_data_long(x2 >> 8,0);
 ezLCD_transfer_data_long(x2 & 0xFF,0);
 ezLCD_transfer_data_long(y2 >> 8,0);
 ezLCD_transfer_data_long(y2 & 0xFF,1);
}

 //n = 2 to 255 (n sould be 1 less than total # of verticies, current pos is 
 //first one
void ezLCD_draw_polygon(uint8_t n, uint16_t x[], uint16_t y[])
{
  uint8_t i;
  uint8_t j = n-1;
   
  ezLCD_transfer_data_long(0xA6,0); /* Send command */ 
  ezLCD_transfer_data_long(n,0);    /* Send number of verticies */ 
  
  for(i = 0; i < j; ++i)
  {
    ezLCD_transfer_data_long(x[i] >> 8,0);
    ezLCD_transfer_data_long(x[i] & 0xFF,0);
    ezLCD_transfer_data_long(y[i] >> 8,0);
    ezLCD_transfer_data_long(y[i] & 0xFF,0);
  }
  
    ezLCD_transfer_data_long(x[j] >> 8,0);
    ezLCD_transfer_data_long(x[j] & 0xFF,0);
    ezLCD_transfer_data_long(y[j] >> 8,0);
    ezLCD_transfer_data_long(y[j] & 0xFF,1);
}

void ezLCD_set_edit_rectangle(int16_t x,
                              int16_t y,
                              uint16_t width,
                              uint16_t height)
{
    ezLCD_transfer_data_long(0x5C,0);
    
    ezLCD_transfer_data_long(x >> 8,0);
    ezLCD_transfer_data_long(x & 0xFF,0);
    ezLCD_transfer_data_long(y >> 8,0);
    ezLCD_transfer_data_long(y & 0xFF,0);
    
    ezLCD_transfer_data_long(width >> 8,0);
    ezLCD_transfer_data_long(width & 0xFF,0);
    ezLCD_transfer_data_long(height >> 8,0);
    ezLCD_transfer_data_long(height & 0xFF,0);
}                             
/** @} */ /* ezLCD_103_polygons */