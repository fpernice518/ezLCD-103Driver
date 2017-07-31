/**
 * @file   ezLCD_103_buttons.h  <br>
 * @author Frank Pernice <br>
 * @date   November 2013  <br>
 * @brief  ezLCD button management and rendering header file  <br>
 * @defgroup ezLCD_103_buttons Buttons
 * @{
 *
 * This header contains functions used for configuring, placing, and polling 
 * buttons on the screen. It is <b>strongly recommended that the user read 
 * section 4 <a href="External Commands Manual.pdf" target="_blank"> of the 
 * ezLCD External Commands manual before continuing</a></b>
 *
 * As the manual states; there are three different ways one can interact with
 * the touch capabilities of the display. Each touch protocol (ezButton,
 * cuButton, or calibratedXY) have different which may be desirable for 
 * different applications. <b>Before the touch screen can begin sending data
 * the user must first choose a button protocol</b>
 . 
 * - The ezButton protocol only sends data back to the screen when an event
 *   occurs. There are two types of events: when a button is pressed and when a 
 *   button is released. The ezButton only broadcasts these events ONCE when
 *   it occurs and never again (until it occurs again). This is the recommended
 *   protocol for new users since it is the easiest one to work with. The 
 *   data packet sent by the display at the occurrence of an event contains
 *   two parts: an ID number and a state as shown below.
 *  
 *   @image html ezButton.png "ezButton event packet"
 *
 * - The cuButton protocol is similar to the ezButton except for some key
 *   differences.
 *   - It broadcasts event information 5 to 20 times per second. 
 *   - In the case of the cuButton, there are also two kinds of events: button 
 *     down and no button pressed. The cuButton event packet is shown below.
 *
 *     @image html cuButton.png "cuButton event packet"
 * 
 *     When no button is pressed, the entire packet (status and ID fields) will
 *     contain all logic 1's. Otherwise, when a button is pressed, the status
 *     bits will be @b 01 and the ID number is dependent on the ID number chosen
 *     by the ezLCD_button_define_long() function.
 *
 *   - The calibratedXY is the most complex protocol to work with and is not
 *     recommended for beginners. In this mode, the entire screen "becomes a
 *     button" independent of any actual buttons placed on the screen. The
 *     ezLCD will broadcast the XY coordinates of the touched pixel on the 
 *     screen in multiple packets. For this protocol, it is recommended that the
 *     user read section 4.1.3  of the <a href="External Commands Manual.pdf"  
 *     target="_blank">ezLCD External Commands manual.</a></b> This protocol
 *     is very well documented and is relatively easy to understand after 
 *     reading this section. This protocol may be useful for things such as
 *     drawing objects to the screen with one's finger.
 *
 * Once the user has selected a protocol, <b>only then</b> may they begin to 
 * place buttons on the screen. If the user places buttons on the screen before
 * setting a protocol, the buttons may be inoperable and may need to be
 * redrawn. See the ezLCD_button_define_long() documentation for insight on
 * button images and placement.
 *
 * Once a touch protocol has been selected and a button is placed on the screen
 * (in the case of ezButton and cuButton), we are ready to begin sensing events.
 * Unfortunately, the only way to detect button or screen presses is by 
 * polling the SPI data register. There is no additional signal that can be used
 * for interrupts. So in order to determine when a button has been pressed, the
 * user must send no-op commands (the number 0) to the screen on the MOSI line 
 * and then read the data that comes back on the MISO line. This is demonstrated
 * by the ezLCD_wait_for_event() function.
 *
 *
 * After receiving data from the display, the microcontroller must choose what
 * to do based on which button was pressed or what portion of the screen was 
 * pressed. While there may be other external activities (such as lighting an
 * LED) that should be performed at the touch of the screen; one must realize
 * that the ezLCD does not automatically replace the EZLCD_BUTTON_UP image
 * with the the EZLCD_BUTTON_DOWN image or vice-versa. Again, read the
 * documentation for ezLCD_button_define_long() if you do not understand what
 * these states are. Upon receiving an event packet, the microcontroller 
 * must then instruct the ezLCD to replace the EZLCD_BUTTON_UP image with the
 * EZLCD_BUTTON_DOWN image or vice-versa using the ezLCD_set_button_state()
 * function. 
 *
 */
#ifndef EZLCD_BUTTONS_H
#define EZLCD_BUTTONS_H
/*----------------------------------------------------------------------------*/
/* INCLUDES                                                                   */
/*----------------------------------------------------------------------------*/
#include "ezLCD_103_common.h"

/*----------------------------------------------------------------------------*/
/* TYPEDEFS                                                                   */
/*----------------------------------------------------------------------------*/
/** Enumerated types used by the ezLCD_set_EZLCD_BUTTON_state() and 
  * the ezLCD_button_define_long() functions to defining a button state.
  */
typedef enum { EZLCD_BUTTON_UP = 1,
               EZLCD_BUTTON_DOWN,
               EZLCD_BUTTON_DISABLED,
               EZLCD_BUTTON_INVISIBLE } ezLCD_button_state_t;

/** Enumerated types used by the ezLCD_set_touch_protocol() function to 
  * determine the button mode.
  */               
typedef enum { ezButton = 1,
               cuButton = 2,
               calibratedXY = 64} ezLCD_touch_protocol_t;

/*----------------------------------------------------------------------------*/
/* FUNCTIONS                                                                  */
/*----------------------------------------------------------------------------*/
/** Defines a button and places it on the <b>current frame</b>. 
 *
 *  A button consists of an ID, up to three images, an XY coordinate, and a 
 *  width and height.
 *
 * - The button ID is used to distinguish it from the other buttons on the 
 *   screen. When the screen is touched, it will send the button's ID and its  
 *   state (provided that the touch protocol is set to ezButton or cuButton) in 
 *   a one-byte packet. With this information, the microcontroller can decide
 *   what to do next.
 *   <BR><BR>
 * - The 3 images are the visible part of the button. These are regular bitmap
 *   images which can be designed in an image editor or an online button
 *   making utility such as <a href="http://www.dabuttonfactory.com">Da Button
 *   factory</a>. Each of these images represents how the button appears at
 *   each state (EZLCD_BUTTON_UP, EZLCD_BUTTON_DOWN, or EZLCD_BUTTON_DISABLED). 
 *   So, to give the user indication that they pressed a button, the programmer  
 *   may want to make the image for the EZLCD_BUTTON_DOWN state a lighter color 
 *   than the image for the EZLCD_BUTTON_UP state. They may also want to make 
 *   the image for the  EZLCD_BUTTON_DISABLED state a grayscale color to 
 *   indicate that the button is deactivated and will not do anything if  
 *   pressed. However, this is completely optional (though entirely recommended)
 *   . A button may use the same image for all three button states. However, 
 *   this makes it difficult to give the user proper feedback. If a button image
 *   for a particular state does not exist, the value 0xFF is used instead of
 *   an index. It should be noted that there is a fourth button state, 
 *   EZLCD_BUTTON_INVISIBLE also exists, which removes the button from the  
 *   screen.
 *   <BR><BR>
 * - As with placing any image on the screen, we must indicate an XY 
 *   coordinate for the button's images. Like most bitmap images we have 
 *   placed on the screen so far, this is done from the top-left corner
 *   of the bitmap image. 
 *   <BR><BR>
 * - In order to specify the touch zone of the button, we must 
 *   tell the display how wide and tall we want this area to be. Our button 
 *   images may be larger or smaller than these numbers.
 *   
 *
 *  @b NOTE: Just because a button was placed on the drawing frame and not the
 *           display frame does not mean that the button is not active. The
 *           button will still be active and will still respond to touch
 *           in its area of placement even if it is not visible on the screen
 *           because it has been placed on another frame.
 *
 *  @par Parameters
 *      - @a id = Unique ID number which differentiates the button from others
 *                on the screen. This number is in the set [0,63].
 *      - @a state = The initial state of the button
 *      - @a index_up       = Index of the button's @b UP image on the ROM
 *                            as defined in @b UserRom.txt. If no image exists,
 *                            this value should be set to 0xFFFF.
 *      - @a index_down     = Index of the button's @b DOWN image on the ROM
 *                            as defined in @b UserRom.txt. If no image exists,
 *                            this value should be set to 0xFFFF.
 *      - @a index_disabled = Index of the button's @b DISABLED image on the ROM
 *                            as defined in @b UserRom.txt. If no image exists,
 *                            this value should be set to 0xFFFF.
 *      - @a x              = X coordinate of the buttons top-left corner
 *      - @a y              = Y coordinate of the buttons top-left corner
 *      - @a width          = Button width
 *      - @a height         = Button height
 *
 *  @par Assumptions
 *       - The chosen ID number is unique and is from 0 to 63 only.
 *       - ezLCD_set_touch_protocol() has been called at least once.  
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
void ezLCD_button_define_long(uint8_t id,
                              ezLCD_button_state_t state, 
                              uint16_t index_up,
                              uint16_t index_down,
                              uint16_t index_disabled,
                              uint16_t x,
                              uint16_t y,
                              uint8_t width,
                              uint8_t height);

/** Sets the touch protocol for the entire screen. That is, this setting applies
 *  to all buttons placed on the screen and not just one button.
 *
 * @par Parameters 
 *      - @a protocol = An enumerated type indicating the desired touch 
 *                      protocol. The three possible parameters are 
 *                      <b>ezButton</b>,<b>cuButton</b>,or <b>calibratedXY</b>.
 * @par Assumptions  
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
void ezLCD_set_touch_protocol(ezLCD_touch_protocol_t protocol);

/** Sets the display state of a button and therefore changes the button's 
 *  image on the screen (if supplied).
 *
 * @par Parameters 
 *      - @a id = The ID of the button whose state is to be changed.
 *      - @a state = The desired button state.
 * @par Assumptions  
 *       - The chosen ID number is unique and is from 0 to 63 only.
 *       - ezLCD_set_touch_protocol() has been called at least once.  
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
void ezLCD_set_button_state(uint8_t id, ezLCD_button_state_t state);

/** This function sends a command to the screen to enter its built in 
 *  calibration routine and then waits until the screen has been successfully
 *  calibrated. 
 *
 * @par Assumptions   
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
void ezLCD_calibrate_screen();

/** This function deactivates all buttons so that they no longer respond to 
 *  touch. However, it does not remove their image from the screen or frame.
 *
 * @par Assumptions   
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
void ezLCD_deactivate_all_buttons();

/** This function places all buttons in their UP state and consequently draws
 *  their EZLCD_BUTTON_UP images to the screen.
 *
 * @par Assumptions   
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
void ezLCD_all_buttons_up();

/** This function is provided as an example of how one can poll the screen for 
 *  button events. When called, this function waits indefinitely for a button
 *  to be pressed and then released before returning. The function changes 
 *  button state image in accordance with the button's status. So when any
 *  button is pressed, it will paint that button's EZLCD_BUTTON_DOWN image
 *  to the screen in place of its EZLCD_BUTTON_UP image. It will do the
 *  opposite when the button is released and only then will it return
 *  the pressed button's ID. <b>IT IS STRONGLY RECOMMENDED THAT THE USER
 *  STUDY THIS FUNCTION IN DEPTH SO THAT THEY MAY WRITE THEIR OWN FUNCTIONS TO
 *  DETECT BUTTON PRESSES SINCE THIS FUNCTION MAY NOT BE SUITABLE FOR ALL
 *  APPLICATIONS</b>. This function only works with the ezButton protocol.
 *
 * @par Assumptions 
 *       - The selected touch protocol is ezButton. 
 *       - The buttons being polled are initially in the EZLCD_BUTTON_UP state.
 *       - The user has initialized the MCU's SPI interface with the
 *         EZLCD_INIT_SPI() macro.
 *       - The user has set the MCU's SPI pins to inputs and outputs 
 *         appropriately. <BR><BR>
 *         - SS_BAR = OUTPUT
 *         - SCK    = OUTPUT
 *         - MOSI   = OUTPUT
 *         - MISO   = INPUT
 * @returns
 *           -Returns the ID of he pressed button
 *
 */
uint8_t ezLCD_wait_for_event();

#endif /* EZLCD_BUTTONS_H */
/** @} */ /* ezLCD_103_buttons */