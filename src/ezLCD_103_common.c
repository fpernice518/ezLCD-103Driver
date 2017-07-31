/*
 * @file   ezLCD_103_common.c  <br>
 * @author Frank Pernice <br>
 * @date   November 2013  <br>
 * @brief  Common source file needed by all child sources in this library. <br>
 * @defgroup ezLCD_103_common Common
 * @{
 *
 * This source file contains various functions needed by other child
 * source files in this library. Among them are functions to send SPI data as 
 * well as 
 *
 */
/*----------------------------------------------------------------------------*/
/* INCLUDES                                                                   */
/*----------------------------------------------------------------------------*/
#include "ezLCD_103_common.h"

/*----------------------------------------------------------------------------*/
/* FUNCTIONS                                                                  */
/*----------------------------------------------------------------------------*/
uint8_t ezLCD_transfer_data(uint8_t data)
{
     EZLCD_SLAVE_SELECT();                         /* Select the slave */
     EZLCD_SPDR = data;                            /* send data */
     while (!(EZLCD_SPSR & (1<<EZLCD_SPIF_BIT)));  /* wait for transmission to complete */
     EZLCD_SLAVE_DESELECT();                       /* Deslelect the slave */
     return EZLCD_SPDR;                            /* return data */
}


/* assumes user hasn't deselected the pin mid-transfer */
uint8_t ezLCD_transfer_data_long(uint8_t data, uint8_t end_transfer)
{
     EZLCD_SLAVE_SELECT();                         /* Select the slave */
     EZLCD_SPDR = data;                            /* send data */
     while (!(EZLCD_SPSR & (1<<EZLCD_SPIF_BIT)));  /* wait for transmission to complete */

     if(end_transfer == 1)
       EZLCD_SLAVE_DESELECT();     /* Deslelect the slave if transfer
                                    * is complete
                                    */

     return EZLCD_SPDR;           /* Return data */
}
/** @} */ /* ezLCD_103_common */
