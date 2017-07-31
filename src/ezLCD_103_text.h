/**
 * @file   ezLCD_103_text.h  <br>
 * @author Frank Pernice <br>
 * @date   November 2013  <br>
 * @brief  ezLCD text management and rendering header file  <br>
 * @defgroup ezLCD_103_text Text
 * @{
 *
 * This header contains functions used for both managing and rendering text.
 * 
 * The ezLCD+103 utilizes two different kinds of fonts: bitmap fonts 
 * (.ezf files) and true type fonts (.ttf) files.
 *
 * Bitmap fonts are essentially just fixed images just like any other images
 * the user may choose to render to the display. They cannot be scaled to larger
 * sizes nor can they be printed with different colors. 
 *
 * Conversely, true type fonts (TTF) are vector fonts whose settings may be
 * modified. These fonts are sensitive to the <b>current color</b> and and
 * may dynamically change size.
 *
 * The table below illustrates the differences between the two font types.
 * For more information, see section 3.5 in the <b>EZLCD+ External Commands 
 * Manual</b>
 *
 * @images html font_diff.png "Difference between bitmap and TTF fonts"
 *
 * In addition to these differences, TTF uses the Unicode system and can have
 * many different characters (currently over 110,000) while bitmap fonts only 
 * have a maximum of 256 characters (ASCII). The ezLCD_set_ttf_unicode_base()
 * function allows us to access the many other characters available un Unicode.
 *
 * To learn more about Unicode and to have a few laughs, please click 
 * <a href="http://www.joelonsoftware.com/articles/Unicode.html">here</a>.
 * 
 *
 */
 
#ifndef EZLCD_TEXT_H
#define EZLCD_TEXT_H
/*----------------------------------------------------------------------------*/
/* INCLUDES                                                                   */
/*----------------------------------------------------------------------------*/
#include "ezLCD_103_common.h"

/*----------------------------------------------------------------------------*/
/* FUNCTIONS                                                                  */
/*----------------------------------------------------------------------------*/

/** Sets the desired bitmap font as the <b>current font</b>. 
 *
 *  @par Parameters
 *       - @a font number = The index in the <b>UserRom.txt</b> file where the 
 *         desired bitmap font is located.
 *
 *  @par Assumptions
 *       - The desired font's file path has been placed in the
 *         <b>UserRom.txt</b> file and the font itself is on the microSD card.
 *          - Once the above has been completed, the display must be 
 *            reprogrammed.
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
void ezLCD_set_bitmap_font(uint8_t font_number);


/** Sets the desired TTF font as the <b>current font</b>. 
 *
 *  @par Parameters
 *       - @a font number = The index in the <b>UserRom.txt</b> file where the 
 *         @a desired TTF font is located.
 *       - @a height = The height in pixels of the selected TTF.
 *       - @a width  = The width in pixels of the selected TTF. 
 *          - When the width is set to zero, it will be automatically set
 *            to an optimal value by the ezLCD.
 *
 *  @par Assumptions
 *       - The desired font's file path has been placed in the
 *         <b>UserRom.txt</b> file and the font itself is on the microSD card.
 *          - Once the above has been completed, the display must be 
 *            reprogrammed.
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
void ezLCD_set_true_type_font(uint8_t font_number,
                              uint8_t height,
                              uint8_t width);
                              
/** Initialization function for putchar(). An initialization function is needed
 *  for putchar() because we must first define the portion of the 
 *  <b>current frame</b> in which we want to write characters.
 *  Just like the ezLCD_set_edit_rect() function is used to define the area 
 *  which is editable by the ezLCD_replace_color() function, the goal of this 
 *  function is to define the allowable area in which putchar() may write to. 
 *  The diagram below illustrates the necessary parameters for this function.
 *
 *  @image html text_box.png "Text Box Illustration"
 *
 *  This function also draws the text box to the <b>current frame</b>. 
 *  See the image below:
 *  
 *  @image html empty_tb.jpg "Empty Text Box"
 *
 *  @image html full_tb.jpg "Full Text Box"
 *  
 *
 *  @par Parameters
 *       - @a x      = X coordinate of top-left corner of the text box.
 *       - @a y      = Y coordinate of top-left corner of the text box.
 *       - @a width  = Text box width.
 *       - @a height = Text box height
 *       - @a bezel_width  = Bezel width.
 *       - @a bezel_height = Bezel height
 *       - @a font_width   = Font width
 *         - <b>NOTE:</b> when using a TTF, the width must be a constant. That
 *                        is, when calling the ezLCD_set_true_type_font()
 *                        function, the provided @b width <b>MUST NOT</b> be 0. 
 *       - @a font_height  = Font Height
 *       - @a tb_red     = Text Box Red color component [0,255]
 *       - @a tb_green   = Text Box Green color component [0,255]
 *       - @a tb_blue    = Text Box Blue color component [0,255]
 *       - @a text_red   = Font Red color component [0,255]
 *       - @a text_green = Font Green color component [0,255]
 *       - @a text_blue  = Font Blue color component [0,255]
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
                        uint8_t text_blue);

/** Places a single character on the <b>current frame</b>. *
 *
 *  @par Parameters
 *       - @a c = The desired character
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
void ezLCD_putchar(char c);

/** Places a single character on the <b>current frame</b> backed with a 
 *  background color set by ezLCD_set_background_color().
 *
 *  @par Parameters
 *       - @a c = The desired character
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
void ezLCD_putchar_bg(char c);


/** Places a single character on the <b>current frame</b> bound by the 
 *  text box created with ezLCD_init_putchar(). The reason for bounding
 *  the text to a single area is so that printf() will work as expected.
 *  The newline character will force a line feed and a carriage return
 *  just like an old typewriter. When the end of the bounded region is reached
 *  the text box will be cleared and text will be written from the top-left
 * corner once again.
 *
 *  @par Parameters
 *       - @a c = The desired character
 *
 *  @par Assumptions
 *       - The user has properly sized the text box for the text they plan to 
 *         print.
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
int putchar(int c);

/** Used to set the TTF Unicode base. TTFs consist of many different characters 
 *  that need to be addressed; however, it is desirable to only send one byte to 
 *  the display whenever possible. It is also desirable to use the same text 
 *  writing functions for both bitmap fonts and TTFs. In order to do this, we 
 *  need to set different base characters in order to access different
 *  characters using an  8-bit code. Suppose we want to print some foreign 
 *  letters to the display. More often than not, this character will reside  
 *  very high up in the Unicode character set. Suppose we want to write the  
 *  capital Greek letter delta to the <b>current frame</b>. Capital delta's 
 *  Unicode mapping is U+0394 (or decimal number 916) where 0394 is in 
 *  hexadecimal. Clearly, we cannot simply address this letter with an 8-bit 
 *  code directly.
 *
 *  Instead, what we can do is add an offset to the character base. That is the
 *  role of this function. Since delta is 0x394 in Unicode, we can set the
 *  base character to 0x394 and then print out character 0 as follows (assume
 *  that ezLCD_init_putchar() has already been called for simplicity):
 *
 * @code
    ezLCD_set_ttf_unicode_base(0x394);
    putchar(0);
   @endcode
 * 
 * We could also print capital delta by setting the base character to 0x394-1 =
 * 0x393 or 915 decimal. Then we could print character 1 as follows:
 
 * @code
    ezLCD_set_ttf_unicode_base(0x393);
    putchar(1);
   @endcode
 * In either case, the same character delta is printed to the frame.
 * This scheme gives us access to the base character and the 255 characters 
 * above it in the Unicode table.
 *
 * For a complete listing of Unicode characters and their encodings, please
 * click <a href="http://unicode-table.com/en/">here</a>.
 *  
 *
 *  @par Parameters
 *       - @a base = The desired Unicode base character.
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
 */  
void ezLCD_set_ttf_unicode_base(uint16_t base);

#endif /* EZLCD_TEXT_H */
/** @} */ /* ezLCD_103_text */