/*
 * @file   ezLCD_103_curves.c  <br>
 * @author Frank Pernice <br>
 * @date   November 2013  <br>
 * @brief  ezLCD curved images source file  <br>
 * @defgroup ezLCD_103_curves Curves
 * @{
 *
 * This source contains functions which aid in the drawing of curved objects
 * such as circles, ellipses, arcs, and pies. 
 */
 
/*----------------------------------------------------------------------------*/
/* INCLUDES                                                                   */
/*----------------------------------------------------------------------------*/
#include "ezLCD_103_common.h"

/*----------------------------------------------------------------------------*/
/* FUNCTIONS                                                                  */
/*----------------------------------------------------------------------------*/
void ezLCD_draw_circle(uint16_t radius)
{
 ezLCD_transfer_data_long(0x89,0);
 ezLCD_transfer_data_long(radius >> 8,0);
 ezLCD_transfer_data_long(radius & 0xFF,1);
}

void ezLCD_draw_circle_fill(uint16_t radius)
{
 ezLCD_transfer_data_long(0x99,0);
 ezLCD_transfer_data_long(radius >> 8,0);
 ezLCD_transfer_data_long(radius & 0xFF,1);
}

void ezLCD_draw_arc(uint16_t radius, uint16_t start_angle, uint16_t end_angle)
{
 ezLCD_transfer_data_long(0x8F,0);
 ezLCD_transfer_data_long(radius >> 8,0);
 ezLCD_transfer_data_long(radius & 0xFF,0);
 ezLCD_transfer_data_long(start_angle >> 8,0);
 ezLCD_transfer_data_long(start_angle & 0xFF,0);
 ezLCD_transfer_data_long(end_angle >> 8,0);
 ezLCD_transfer_data_long(end_angle & 0xFF,1);
}

void ezLCD_draw_pie(uint16_t radius, uint16_t start_angle, uint16_t end_angle)
{
 ezLCD_transfer_data_long(0x90,0);
 ezLCD_transfer_data_long(radius >> 8,0);
 ezLCD_transfer_data_long(radius & 0xFF,0);
 ezLCD_transfer_data_long(start_angle >> 8,0);
 ezLCD_transfer_data_long(start_angle & 0xFF,0);
 ezLCD_transfer_data_long(end_angle >> 8,0);
 ezLCD_transfer_data_long(end_angle & 0xFF,1);
}


void ezLCD_draw_ellipse(uint16_t semi_major_axis, uint16_t semi_minor_axis)
{
 ezLCD_transfer_data_long(0x8A,0);
 ezLCD_transfer_data_long(semi_major_axis >> 8,0);
 ezLCD_transfer_data_long(semi_major_axis & 0xFF,0);
 ezLCD_transfer_data_long(semi_minor_axis >> 8,0);
 ezLCD_transfer_data_long(semi_minor_axis & 0xFF,1);
}

void ezLCD_draw_ellipse_fill(uint16_t semi_major_axis, uint16_t semi_minor_axis)
{
 ezLCD_transfer_data_long(0x8B,0);
 ezLCD_transfer_data_long(semi_major_axis >> 8,0);
 ezLCD_transfer_data_long(semi_major_axis & 0xFF,0);
 ezLCD_transfer_data_long(semi_minor_axis >> 8,0);
 ezLCD_transfer_data_long(semi_minor_axis & 0xFF,1);
}

void ezLCD_draw_ellipse_arc(uint16_t semi_major_axis, uint16_t semi_minor_axis,
                            uint16_t start_angle, uint16_t end_angle)
{
 ezLCD_transfer_data_long(0x8C,0);
 ezLCD_transfer_data_long(semi_major_axis >> 8,0);
 ezLCD_transfer_data_long(semi_major_axis & 0xFF,0);
 ezLCD_transfer_data_long(semi_minor_axis >> 8,0);
 ezLCD_transfer_data_long(semi_minor_axis & 0xFF,0);
 ezLCD_transfer_data_long(start_angle >> 8,0);
 ezLCD_transfer_data_long(start_angle & 0xFF,0);
 ezLCD_transfer_data_long(end_angle >> 8,0);
 ezLCD_transfer_data_long(end_angle & 0xFF,1);
}

void ezLCD_draw_ellipse_pie(uint16_t semi_major_axis, uint16_t semi_minor_axis,
                            uint16_t start_angle, uint16_t end_angle)
{
 ezLCD_transfer_data_long(0x8E,0);
 ezLCD_transfer_data_long(semi_major_axis >> 8,0);
 ezLCD_transfer_data_long(semi_major_axis & 0xFF,0);
 ezLCD_transfer_data_long(semi_minor_axis >> 8,0);
 ezLCD_transfer_data_long(semi_minor_axis & 0xFF,0);
 ezLCD_transfer_data_long(start_angle >> 8,0);
 ezLCD_transfer_data_long(start_angle & 0xFF,0);
 ezLCD_transfer_data_long(end_angle >> 8,0);
 ezLCD_transfer_data_long(end_angle & 0xFF,1);
}
/** @} */ /* ezLCD_103_curves */