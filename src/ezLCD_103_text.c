/*
 * @file   ezLCD_103_text.c  <br>
 * @author Frank Pernice <br>
 * @date   November 2013  <br>
 * @brief  ezLCD text management and rendering source file  <br>
 * @defgroup ezLCD_103_text Text
 * @{
 *
 * This source contains functions used for both managing and rendering text.
 */

/*----------------------------------------------------------------------------*/
/* INCLUDES                                                                   */
/*----------------------------------------------------------------------------*/
#include "ezLCD_103_common.h"
#include "ezLCD_103_coordinates.h"
#include "ezLCD_103_polygons.h"
#include "ezLCD_103_colors.h"

/*----------------------------------------------------------------------------*/
/* FUNCTIONS                                                                  */
/*----------------------------------------------------------------------------*/
void ezLCD_set_bitmap_font(uint8_t font_number)
{
  ezLCD_transfer_data_long(0x2B,0);
  ezLCD_transfer_data_long(font_number,1);
}

//width == 0 -> calculate width automatically
void ezLCD_set_true_type_font(uint8_t font_number,
                              uint8_t height,
                              uint8_t width)
{
    ezLCD_transfer_data_long(0x91,0);
    ezLCD_transfer_data_long(font_number,0);
    ezLCD_transfer_data_long(height,0);
    ezLCD_transfer_data_long(width,1);
}

void ezLCD_set_ttf_unicode_base(uint16_t base)
{
 ezLCD_transfer_data_long(0x93,0);
 ezLCD_transfer_data_long(base >> 8,0);
 ezLCD_transfer_data_long(base & 0xFF,0);
}


static uint16_t text_box_x;
static uint16_t text_box_y;
static uint16_t text_box_width;
static uint16_t text_box_height;
static uint8_t  box_bezel_width;
static uint8_t  box_bezel_height;
static uint8_t  font_h;
static uint8_t  font_w;
static uint16_t x_pos;
static uint16_t y_pos;

static uint8_t tb_r;
static uint8_t tb_g;
static uint8_t tb_b;

static uint8_t text_r;
static uint8_t text_g;
static uint8_t text_b;


void ezLCD_init_putchar(uint16_t x,
                        uint16_t y,
                        uint16_t width,
                        uint16_t height,
                        uint8_t bezel_width,
                        uint8_t bezel_height,
                        uint8_t font_width,
                        uint8_t font_height,
                        uint8_t tb_red,
                        uint8_t tb_green,
                        uint8_t tb_blue,
                        uint8_t text_red,
                        uint8_t text_green,
                        uint8_t text_blue)
{
  /* Set XY coordinates of top-left corner of text box */
  text_box_x       = x;
  text_box_y       = y;
  /* Set height and width of text box */
  text_box_width   = width;
  text_box_height  = height;
  
  /* Set bezel widths for neatness */
  box_bezel_width  = bezel_width;
  box_bezel_height = bezel_height;
  
  /* Set font dimensions */
  font_h           = font_height;
  font_w           = font_width;
  
  /* Set starting character coordinates */
  x_pos            = text_box_x + box_bezel_width;
  y_pos            = text_box_y + box_bezel_height;
  
  /* Set Text Box Colors */
   tb_r = tb_red;
   tb_g = tb_green;
   tb_b = tb_blue;
   
  /* Set Text Colors */
   text_r = text_red;
   text_g = text_green;
   text_b = text_blue;
   
  /* Draw Text Box */
  ezLCD_set_color_rgb(tb_red, tb_green, tb_blue);
  ezLCD_set_xy(text_box_x, text_box_y);
  ezLCD_draw_rect_fill(text_box_x + text_box_width, text_box_y + text_box_height);
  
  /* Initialize text color */
  ezLCD_set_color_rgb(text_r, text_g, text_b);
  
}


void ezLCD_putchar(char c)
{
 ezLCD_transfer_data_long(0x2C,0);
 ezLCD_transfer_data_long(c,1);
}

void ezLCD_putchar_bg(char c)
{
 ezLCD_transfer_data_long(0x3C,0);
 ezLCD_transfer_data_long(c,1);
}

int putchar(int c)
{
  ezLCD_set_color_rgb(text_r, text_g, text_b);
  
  if(x_pos >= (text_box_x + text_box_width + box_bezel_width - font_w) || c == '\n')
  {
    y_pos += font_h + 2;
    x_pos  = text_box_x + box_bezel_width;
  }
  
  if((y_pos + font_h) >= (text_box_y + text_box_height - box_bezel_height))
  {
    /* Draw Text Box */
    ezLCD_set_color_rgb(tb_r, tb_g, tb_b);
    ezLCD_set_xy(text_box_x, text_box_y);
    ezLCD_draw_rect_fill(text_box_x + text_box_width, text_box_y + text_box_height);
    /* Reset Text Color */
    ezLCD_set_color_rgb(text_r, text_g, text_b);
    /* Reset Y coordinate */
    y_pos = text_box_y + box_bezel_height;
  }
  /* Set the character's coordinates */
  ezLCD_set_xy(x_pos, y_pos);
  
  /* if not a new-line character, print the character to the screen */
  if(c != '\n')
  {
    ezLCD_putchar(c);
    x_pos += (font_w + 1);/* Some padding so letters aren't squeezed together */
  }
  
  return c;
}
/** @} */ /* ezLCD_103_text */
