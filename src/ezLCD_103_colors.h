/**
 * @file   ezLCD_103_colors.h  <br>
 * @author Frank Pernice <br>
 * @date   November 2013  <br>
 * @brief  ezLCD color management header file  <br>
 * @defgroup ezLCD_103_colors Colors
 * @{
 *
 * This header file is used to manage various color settings used when drawing
 * objects to the ezLCD+103. 
 *
 * A number of functions in this category request RGB (Red, Green, Blue)
 * color values. In the RGB color model,  the colors red, green, and blue are
 * added together in different quantities to form a new color as shown in the 
 * image below
 * 
 * @image html RGB_illumination.jpg "RGB Color Mixing"
 *
 * One can specify
 * the quantity of each color with a one byte (8-bit) value for each of the red, 
 * green, and blue quantities. These values are added together to form a 24-bit  
 * number representing a new color. There are a total of 256^3 (or 2^24)  
 * possible colors in the RGB color model. This is a rather daunting number  
 * since there are quite a large number of colors to choose from. As a result, 
 * some macros have been provided in this header file which represent some 
 * common colors. They may be used in place of the three RGB parameters in any 
 * function in this file which requests them as in the shown code snippet below.  
 * The following two lines of code are equivalent.
 * 
 * @code
   ezLCD_set_color_rgb(EZLCD_Violet);
   ezLCD_set_color_rgb(0xEE, 0x82, 0xEE);
   @endcode
 *
 * These macros may also be used by the ezLCD_putchar_init() function, the 
 * ezLCD_fill_bound() function, or any function which requires all three RGB 
 * values (in that order).
 *
 * If the user needs additional colors not defined in this file, there are a
 * number of online resources, 
 * <a href="http://www.rapidtables.com/web/color/RGB_Color.htm">such as 
 * this one</a> ,  which will help the user find the perfect color.
 *
 */

#ifndef EZLCD_COLORS_H
#define EZLCD_COLORS_H
/*----------------------------------------------------------------------------*/
/* INCLUDES                                                                   */
/*----------------------------------------------------------------------------*/
#include "ezLCD_103_common.h"

/*----------------------------------------------------------------------------*/
/* FUNCTIONS                                                                  */
/*----------------------------------------------------------------------------*/
/** RGB values for the color white*/
#define EZLCD_WHITE     0xFF, 0xFF, 0xFF
/** RGB values for the color black*/
#define EZLCD_BLACK     0x00, 0x00, 0x00
/** RGB values for the color blue*/
#define EZLCD_BLUE      0x00, 0x00, 0xFF
/** RGB values for the color red*/
#define EZLCD_RED       0xFF, 0x00, 0x00
/** RGB values for the color green*/
#define EZLCD_GREEN     0x00, 0xFF, 0x00
/** RGB values for the color yellow*/
#define EZLCD_YELLOW    0xFF, 0xFF, 0x00
/** RGB values for the color orange*/
#define EZLCD_ORANGE    0xFF, 0xA5, 0x00
/** RGB values for the color dark blue*/
#define EZLCD_DARK_BLUE 0x00, 0x00, 0x8B
/** RGB values for the color violet*/
#define EZLCD_VIOLET    0xEE, 0x82, 0xEE


/** This function is used to set the @b current @b color. This is used by a 
 *  number of the display's drawing functions. Upon power-up the most recently
 *  used color prior to the last shutdown will be set as the @b current @b 
 *  color. Bitmap images and fonts are @b NOT affected by this function.
 *
 *  @par Parameters
 *        - @a red   = Red color component    [0,255]
 *        - @a green = Green color component  [0,255]
 *        - @a blue  = Blue color component   [0,255]
 *
 *  @par Assumptions
 *       - The user has initialized the MCU's SPI interface with the
 *         EZLCD_INIT_SPI() macro.
 *       - The user has set the MCU's SPI pins to inputs and outputs 
 *         appropriately. <BR><BR>
 *         - SS_BAR = OUTPUT
 *         - SCK    = OUTPUT
 *         - MOSI   = OUTPUT
 *         - MISO   = INPUT
 *
 */
void ezLCD_set_color_rgb(uint8_t red, uint8_t green, uint8_t blue);

/** This function is used to set the transparency of the @b current @b color.
 *  It should be noted that any transparency other than 0 or 255 
 *  (fully transparent or fully opaque respectively) will result in objects 
 *  being painted to the screen somewhat slower. Upon power-up, the default
 *  transparency is 255 (fully opaque).
 *
 *  @par Parameters
 *        - @a alpha = the desired transparency [0,255].
 *
 *  @par Assumptions
 *       - The user has initialized the MCU's SPI interface with the
 *         EZLCD_INIT_SPI() macro.
 *       - The user has set the MCU's SPI pins to inputs and outputs 
 *         appropriately. <BR><BR>
 *         - SS_BAR = OUTPUT
 *         - SCK    = OUTPUT
 *         - MOSI   = OUTPUT
 *         - MISO   = INPUT
 *
 */
void ezLCD_set_alpha(uint8_t alpha);

/** This function is used to set the @b transparent @b color of the display.
 *  Of course , the term @b transparent @b color is somewhat of an oxymoron. 
 *  By @transparent @b color, we mean the color which is to be ignored during
 *  bitmap image drawing. Those students who have taken CSE 219 should be 
 *  relatively familiar with this concept. Some bitmap image files, such as 
 *  .jpg images, do not natively support transparency. However, in some
 *  situations, we would like to treat a portion of the image as transparent.
 *  In order to do this, we design the image with a "sacrificial" color which
 *  will not be painted to the screen when the image is drawn.
 *
 *  Suppose we have the image below:
 * @image html transparent_color1.png "Image with sacrificial color shown"
 *
 * Now suppose we choose our sacrificial color to be orange. When the image
 * is drawn to the screen, the orange color will not be drawn; we will only
 * see the red circle drawn to the screen as shown below.
 *
 * @image html transparent_color2.png "Image with sacrificial color removed"
 *
 *  @par Parameters
 *        - @a red   = Red color component
 *        - @a green = Green color component
 *        - @a blue  = Blue color component
 *
 *  @par Assumptions
 *       - The user has initialized the MCU's SPI interface with the
 *         EZLCD_INIT_SPI() macro.
 *       - The user has set the MCU's SPI pins to inputs and outputs 
 *         appropriately. <BR><BR>
 *         - SS_BAR = OUTPUT
 *         - SCK    = OUTPUT
 *         - MOSI   = OUTPUT
 *         - MISO   = INPUT
 *
 */
void ezLCD_set__tr_color_rgb(uint8_t red, uint8_t green, uint8_t blue);

 /** This function is used to set the @b transparent @b color to "none". When 
 *  called, every color in a bitmap image or font will be painted to the screen;
 *  no color will be ignored. For more information about transparent colors, see
 *  ezLCD_set__tr_color_rgb().
 *
 *
 *  @par Assumptions
 *       - The user has initialized the MCU's SPI interface with the
 *         EZLCD_INIT_SPI() macro.
 *       - The user has set the MCU's SPI pins to inputs and outputs 
 *         appropriately. <BR><BR>
 *         - SS_BAR = OUTPUT
 *         - SCK    = OUTPUT
 *         - MOSI   = OUTPUT
 *         - MISO   = INPUT
 *
 */
void ezLCD_tr_color_none(void);

/** This function is used to set the @b background @b color. By background color
 *  we do not mean the background of the entire display, but rather the 
 *  "secondary color." This parameter is useful for some functions, such as
 *   ezLCD_putchar_bg(), which utilize a secondary color. The following code 
 *   snippet will result in white text on a black background (for simplicity,
 *   assume that the ezLCD_init_putchar() function was already called):
 *
    @code
    ezLCD_set_color_rgb(EZLCD_WHITE);
    ezLCD_set_background_color(EZLCD_BLACK);
    printf("White text on a black background");
    @endcode
    
    @image html background_color.png "Result of above code"
 *
 *  @par Parameters
 *        - @a red   = Red color component
 *        - @a green = Green color component
 *        - @a blue  = Blue color component
 *
 *  @par Assumptions
 *       - The user has initialized the MCU's SPI interface with the
 *         EZLCD_INIT_SPI() macro.
 *       - The user has set the MCU's SPI pins to inputs and outputs 
 *         appropriately. <BR><BR>
 *         - SS_BAR = OUTPUT
 *         - SCK    = OUTPUT
 *         - MOSI   = OUTPUT
 *         - MISO   = INPUT
 *
 */
void ezLCD_set_background_color(uint8_t red, uint8_t green, uint8_t blue);

/** This function is used to replace a color within the rectangular region
 *  previously specified by the ezLCD_set_edit_rectangle() function
 *
 *  @par Parameters
 *        - @a red   = Red color component
 *        - @a green = Green color component
 *        - @a blue  = Blue color component
 *
 *  @par Assumptions
 *       - The user has specified a rectangular region in which to edit via the 
 *         ezLCD_set_edit_rectangle() function
 *       - The user has initialized the MCU's SPI interface with the
 *         EZLCD_INIT_SPI() macro.
 *       - The user has set the MCU's SPI pins to inputs and outputs 
 *         appropriately. <BR><BR>
 *         - SS_BAR = OUTPUT
 *         - SCK    = OUTPUT
 *         - MOSI   = OUTPUT
 *         - MISO   = INPUT
 *
 */
void ezLCD_replace_color(uint8_t o_red, uint8_t o_green, uint8_t o_blue,
                         uint8_t n_red, uint8_t n_green, uint8_t n_blue);

#endif /* EZLCD_COLORS_H */
/** @} */ /* ezLCD_103_colors */