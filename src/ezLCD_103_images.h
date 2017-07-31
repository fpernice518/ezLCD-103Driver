/**
 * @file   ezLCD_103_images.h  <br>
 * @author Frank Pernice <br>
 * @date   November 2013  <br>
 * @brief  ezLCD image loading header file  <br>
 * @defgroup ezLCD_103_images Images
 * @{
 *
 * This header contains functions that load images to the <b>current frame</b>.
 *
 */
#ifndef IMAGES_H
#define IMAGES_H
/*----------------------------------------------------------------------------*/
/* INCLUDES                                                                   */
/*----------------------------------------------------------------------------*/
#include "ezLCD_103_common.h"

/*----------------------------------------------------------------------------*/
/* FUNCTIONS                                                                  */
/*----------------------------------------------------------------------------*/
/** This function is used to select a picture stored in memory on the ezLCD's
 *  ROM and paint it to the <b>current frame</b>.
 *
 *  @par Parameters
 *       - picture_number = The index of the picture as it appears in the 
 *         <b>UserRom.txt</b> file.
 *
 *  @par Assumptions
 *       - The user has placed an image at the requested index on the 
 *         <b>UserRom.txt</b> file <b>AND REPROGRAMED THE DISPLAY</b> afterwards.
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
void ezLCD_put_picture_rom(uint16_t picture_number);

/** This function is used to select a picture stored on the ezLCD's microSD card
 *  and paint it to the <b>current frame</b>.
 *
 *  @par Parameters
 *       - file_path = The path of the desired image to be painted to the 
 *                     <b>current frame</b>.
 *       - length    = The number of characters in the file_path .
 *
 *  @par Assumptions
 *       - The user has placed an image at the requested file path on the 
 *         microSD card.
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
void ezLCD_put_picture_sd(char file_path[], uint8_t length);

#endif /* IMAGES_H */
/** @} */ /* ezLCD_103_images */