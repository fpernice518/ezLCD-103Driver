/**
 * @file   ezLCD_103_common.h  <br>
 * @author Frank Pernice <br>
 * @date   November 2013  <br>
 * @brief  Common header file needed by all child headers in this library. <br>
 * @defgroup ezLCD_103_common Common
 * @{
 *
 * This header file contains various macros and functions needed by other child
 * header files in this library. Among them are functions to send SPI data as 
 * well as 
 *
 */
 
/* Used to prevent multiple inclusion of the header file */
#ifndef EZLCD_COMMON_H
#define EZLCD_COMMON_H

/*----------------------------------------------------------------------------*/
/* INCLUDES                                                                   */
/*----------------------------------------------------------------------------*/
#include "ezLCD_103_user_config.h"

/*----------------------------------------------------------------------------*/
/* CONSTANTS                                                                  */
/*----------------------------------------------------------------------------*/

/** Width of the entire display in pixels */
#define EZLCD_WIDTH  320
/** Height of the entire display in pixels */
#define EZLCD_HEIGHT 240

/*----------------------------------------------------------------------------*/
/* MACROS                                                                     */
/*----------------------------------------------------------------------------*/
/** Define SETBIT if not previously defined */
#ifndef SETBIT
#define SETBIT(port,bit) ((port) |= (1 << (bit)))
#endif /* SETBIT */

/** Define CLEARBIT if not previously defined */
#ifndef CLEARBIT
#define CLEARBIT(port,bit) ((port) &= ~(1 << (bit)))
#endif /* CLEARBIT */

/**Initialize SPI communication:                                           <BR>
 * SPIE - SPI Interrupt DISABLED (we will poll instead)                    <BR>
 * SPE  - SPI ENABLED                                                      <BR>
 * DORD - MSB First                                                        <BR>
 * MSTR - Configured as a MASTER                                           <BR>
 * CPOL - Clock Polarity = 0                                               <BR>
 * CPHA - Clock Phase = 0                                                  <BR>
 * SPI  - Clock = f_clk/4          (EA EZLCD+103 can handle up to 4MHz)    <BR>
 * SPR1 - CLEARED                                                          <BR>
 * SPR0 - CLEARED                                                          <BR>
 * SPR2X - CLEARED                                                         <BR>
 */
#ifdef EZLCD_SPR2X
#define EZLCD_INIT_SPI() EZLCD_SPCR = ((0 << EZLCD_SPIE) |                    \
                                      (1 <<  EZLCD_SPE)  |                    \
                                      (0 <<  EZLCD_DORD) |                    \
                                      (1 <<  EZLCD_MSTR) |                    \
                                      (0 <<  EZLCD_CPOL) |                    \
                                      (0 <<  EZLCD_CPHA) |                    \
                                      (0 <<  EZLCD_SPR1) |                    \
                                      (0 <<  EZLCD_SPR0));                    \
                        CLEARBIT(EZLCD_SPSR, EZLCD_SPR2X);
#else
#define EZLCD_INIT_SPI() EZLCD_SPCR = ((0 << EZLCD_SPIE) |                    \
                                      (1 <<  EZLCD_SPE)  |                    \
                                      (0 <<  EZLCD_DORD) |                    \
                                      (1 <<  EZLCD_MSTR) |                    \
                                      (0 <<  EZLCD_CPOL) |                    \
                                      (0 <<  EZLCD_CPHA) |                    \
                                      (0 <<  EZLCD_SPR1) |                    \
                                      (0 <<  EZLCD_SPR0));   
#endif /* SPR2X */                                      

/** Select the EZLCD+103 */
#define EZLCD_SLAVE_SELECT() CLEARBIT(EZLCD_SPI_PORT, EZLCD_SS_BAR_PIN);

/** Deselect the EZLCD+103 */
#define EZLCD_SLAVE_DESELECT() SETBIT(EZLCD_SPI_PORT, EZLCD_SS_BAR_PIN);


/*----------------------------------------------------------------------------*/
/* TYPEDEFS                                                                   */
/*----------------------------------------------------------------------------*/

typedef unsigned char  uint8_t    /** portable 8-bit unsigned integer */  ;
typedef signed char     int8_t    /** portable 8-bit signed integer */    ;
typedef unsigned int  uint16_t    /** portable 16-bit unsigned integer */ ;
typedef signed int     int16_t    /** portable 16-bit signed integer */   ;
typedef unsigned long uint32_t    /** portable 32-bit unsigned number */  ;
typedef unsigned long  int32_t    /** portable 32-bit signed number */    ;

/*----------------------------------------------------------------------------*/
/* FUNCTIONS                                                                  */
/*----------------------------------------------------------------------------*/

/** This function is used to send one byte of data over SPI. It may be modified
 *  should the user choose to use a different serial protocol instead of SPI.
 *
 *  @par Parameters
 *        - @a data = the byte that is to be sent to the SPI slave.
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
 *  @returns The contents of the SPI data register (EZLCD_SPDR) after the
 *           data transfer has completed.
 */
uint8_t ezLCD_transfer_data(uint8_t data);

/** This function is used to send multiple bytes of data over SPI through 
 *  subsequent calls to this function. In other words, it does not unassert the 
 *  chip select until the transmission has been completed. It may be modified 
 *  should the user choose to use a different serial protocol instead of SPI.
 *
 *  @par Parameters
 *        - @a data         = the byte that is to be sent to the SPI slave.
 *        - @a end_transfer = 
 *                            - 0 to continue transfer
 *                            - 1 to end the transfer
 *
 *  @par Assumptions
 *       - The user has initialized the MCU's SPI interface with the
 *         EZLCD_INIT_SPI() macro.
 *       - The user does not deselect the display in between transfers.
 *       - The user has set the MCU's SPI pins to inputs and outputs 
 *         appropriately. <BR><BR>
 *         - SS_BAR = OUTPUT
 *         - SCK    = OUTPUT
 *         - MOSI   = OUTPUT
 *         - MISO   = INPUT
 *
 *  @returns The contents of the SPI data register (EZLCD_SPDR) after each 
 *           subsequent call.
 */
uint8_t ezLCD_transfer_data_long(uint8_t data, uint8_t end_transfer);

#endif /* EZLCD_COMMON_H */
/** @} */ /* ezLCD_103_common */
