/**
 * @file   ezLCD_103_frames.h  <br>
 * @author Frank Pernice <br>
 * @date   November 2013  <br>
 * @brief  ezLCD frame management header file  <br>
 * @defgroup ezLCD_103_frames Frames
 * @{
 *
 * This header contains functions which are used to set the drawing and display
 * frames. The ezLCD+103 contains 20 individual frames which may be drawn to or
 * displayed. So the user can draw different images to different frames and then
 * choose which frame to render on the screen. This allows for seamless image 
 * rendering with virtually zero lag. This is advantageous when telling the
 * ezLCD to render vector images (such as true type fonts) which may take
 * some time due to the computations involved in rendering these images. 
 * <b>The ezLCD+103 defaults to frame 0 upon power-up.</b>
 *
 * The diagram below illustrates how this works (simplified down to just 3
 * frames for simplicity).
 *
 * @image html frames.png "Block diagram of the framing system"
 *
 */
#ifndef FRAMES_H
#define FRAMES_H
/*----------------------------------------------------------------------------*/
/* INCLUDES                                                                   */
/*----------------------------------------------------------------------------*/
#include "ezLCD_103_common.h"

/*----------------------------------------------------------------------------*/
/* FUNCTIONS                                                                  */
/*----------------------------------------------------------------------------*/
/** This function is used to select the display frame.
 *
 *  @par Parameters
 *       - frame = The frame that is to be displayed on the screen in the set of
 *                 [0,19].
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
void ezLCD_set_display_frame(uint8_t frame);

/** This function is used to select the drawing frame.
 *
 *  @par Parameters
 *       - frame = The frame that is to be drawn on in the set of[0,19].
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
void ezLCD_set_draw_frame(uint8_t frame);

#endif /* FRAMES_H */
/** @} */ /* ezLCD_103_frames */