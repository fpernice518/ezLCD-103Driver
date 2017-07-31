/**
 * @file   ezLCD_103_system.h  <br>
 * @author Frank Pernice <br>
 * @date   November 2013  <br>
 * @brief  ezLCD system management header file  <br>
 * @defgroup ezLCD_103_system System
 * @{
 *
 * This header contains functions and macros which manage miscellaneous system 
 * settings such as brightness, backlight, and power settings. It also contains
 * a function to ping the display (that is, determine if the screen is ready
 * to receive more commands.
 *
 */

#ifndef EZLCD_SYSTEM_H
#define EZLCD_SYSTEM_H
/*----------------------------------------------------------------------------*/
/* INCLUDES                                                                   */
/*----------------------------------------------------------------------------*/
#include "ezLCD_103_common.h"

/*----------------------------------------------------------------------------*/
/* MACROS                                                                     */
/*----------------------------------------------------------------------------*/
/** Used to turn the ezLCD+103 on */
#define EZLCD_POWER_ON()  SETBIT(EZLCD_POWER_PORT,EZLCD_POWER_PIN);
/** Used to turn the ezLCD+103 off */
#define EZLCD_POWER_OFF() CLEARBIT(EZLCD_POWER_PORT,EZLCD_POWER_PIN);

/*----------------------------------------------------------------------------*/
/* FUNCTIONS                                                                  */
/*----------------------------------------------------------------------------*/
/** Sets the display brightness. This function does not change the default
 *  start-up brightness defined in <b>UserConfig.txt</b>
 *
 *  @par Parameters
 *       - brightness = The desired brightness level in the set of [0,255].
 *                      Higher numbers imply higher brightnesses. 
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
void ezLCD_set_brightness(uint8_t brightness);

/** Turns off the backlight. 
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
void ezLCD_backlight_off(void);

/** Turns on the backlight. 
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
void ezLCD_backlight_on(void);

/** Pings the ezLCD to determine if it is ready to receive commands. If 
 *  the user's code isn't operating as expected, it may be likely that he
 *  or she is sending data to the screen too fast. The user should
 *  call this function continuously until it returns a 1 before 
 *  resuming other commands. 
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
 *  @returns 
 *         - 1 if ready
 *         - 0 otherwise.
 *
 */
uint8_t ezLCD_ping();

#endif /* EZLCD_SYSTEM_H */
/** @} */ /* ezLCD_103_system */