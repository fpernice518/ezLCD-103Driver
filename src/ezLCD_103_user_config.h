/**
 * @file   ezLCD_103_user_config.h  <br>
 * @author Frank Pernice <br>
 * @date   November 2013  <br>
 * @brief  User configuration header file.  <br>
 * @defgroup ezLCD_103_user_config User Configuration
 * @{
 *
 * Here the user can make various changes to the library. It stores SPI 
 * settings, port and pin numbers and image properties for the display.
 *
 */
 
/* Used to prevent multiple header file inclusion */
#ifndef EZLCD_USER_CONFIG_H
#define EZLCD_USER_CONFIG_H

/*----------------------------------------------------------------------------*/
/* Includes                                                                   */
/*----------------------------------------------------------------------------*/
/** To change target, change this header file */
#include <iom128.h>


/*----------------------------------------------------------------------------*/
/* PORT CONFIG                                                                */
/*----------------------------------------------------------------------------*/
/** MCU port for the power line */
#define EZLCD_POWER_PORT  PORTB
/** MCU pin within port EZLCD_POWER_PORT for the power line */
#define EZLCD_POWER_PIN   4

/*----------------------------------------------------------------------------*/
/* SPI Settings                                                               */
/*----------------------------------------------------------------------------*/
/** MCU Port where SPI pins reside */
#define EZLCD_SPI_PORT             PORTB
/** Chip Select Pin */ 
#define EZLCD_SS_BAR_PIN           0  
/** Serial Clock Pin */ 
#define EZLCD_SCK_PIN              1
/** Master Out Slave In Pin */ 
#define EZLCD_MOSI_PIN             2
/** Master In Slave Out */ 
#define EZLCD_MISO_PIN             3


/** SPI Interrupt Flag bit position */    
#define EZLCD_SPIF_BIT             7 

/** SPI Status Register */     
#define EZLCD_SPSR                 SPSR
/** SPI Double SCK */
#define EZLCD_SPR2X                0


/** SPI Data Register */ 
#define EZLCD_SPDR                 SPDR
 
/** SPI Control Register */  
#define EZLCD_SPCR                 SPCR
/** SPI Interrupt Enable Bit */
#define EZLCD_SPIE                 7
/** SPI Enable Bit*/
#define EZLCD_SPE                  6
/** SPI Data Order Bit */
#define EZLCD_DORD                 5
/** SPI Master/Slave Mode Bit */
#define EZLCD_MSTR                 4
/** SPI Clock Polarity Bit */
#define EZLCD_CPOL                 3
/** SPI Clock Phase Bit */
#define EZLCD_CPHA                 2
/** SPI Clock Speed Bit 1 */
#define EZLCD_SPR1                 1
/** SPI Clock Speed  Bit 0 */
#define EZLCD_SPR0                 0


/*----------------------------------------------------------------------------*/
/* BITMAP FONT INDICES                                                        */
/*----------------------------------------------------------------------------*/
#define ARIAL_14_INXEX                                     0
#define ARIAL_14_B_INDEX                                   1
#define TIMES_NEW_ROMAN_34_B_INDEX                         2
#define FORTE_26_INDEX                                     3
#define SCRIPT_MT_BOLD_29_B_INDEX                          4
#define ISO_6X10_INDEX                                     5
#define ISO_8X13_INDEX                                     6

/*----------------------------------------------------------------------------*/
/* TRUE TYPE FONT INDICES                                                     */
/*----------------------------------------------------------------------------*/
#define DEJAVUSANS                                         0
#define DEJAVUSANS_BOLD                                    1
#define DEJAVUSANS_BOLDOBLIQUE                             2 
#define DEJAVUSERIF                                        3
#define DEJAVUSERIF_BOLD                                   4
#define DEJAVUSERIF_ITALIC                                 5
#define QUIG                                               6
#define WALTOGRAPH                                         7

/*----------------------------------------------------------------------------*/
/* BITMAP IMAGE INDICES                                                       */
/*----------------------------------------------------------------------------*/
/* The following list contains the indices of each image on the display ROM */
#define SPASH_SCREEN_INDEX                                  0
#define BACKGROUND_1_INDEX                                  1

/* Buttons */
#define ZERO_BUTTON_EZLCD_BUTTON_UP_INDEX                   2
#define ZERO_BUTTON_EZLCD_BUTTON_DOWN_INDEX                 3
#define ZERO_BUTTON_DISABLED_INDEX                          4

#define ONE_BUTTON_EZLCD_BUTTON_UP_INDEX                    5
#define ONE_BUTTON_EZLCD_BUTTON_DOWN_INDEX                  6
#define ONE_BUTTON_DISABLED_INDEX                           7

#define TWO_BUTTON_EZLCD_BUTTON_UP_INDEX                    8
#define TWO_BUTTON_EZLCD_BUTTON_DOWN_INDEX                  9
#define TWO_BUTTON_DISABLED_INDEX                           10

#define THREE_BUTTON_EZLCD_BUTTON_UP_INDEX                  11
#define THREE_BUTTON_EZLCD_BUTTON_DOWN_INDEX                12
#define THREE_BUTTON_DISABLED_INDEX                         13

#define FOUR_BUTTON_EZLCD_BUTTON_UP_INDEX                   14
#define FOUR_BUTTON_EZLCD_BUTTON_DOWN_INDEX                 15
#define FOUR_BUTTON_DISABLED_INDEX                          16

#define FIVE_BUTTON_EZLCD_BUTTON_UP_INDEX                   17
#define FIVE_BUTTON_EZLCD_BUTTON_DOWN_INDEX                 18
#define FIVE_BUTTON_DISABLED_INDEX                          19

#define SIX_BUTTON_EZLCD_BUTTON_UP_INDEX                    20
#define SIX_BUTTON_EZLCD_BUTTON_DOWN_INDEX                  21
#define SIX_BUTTON_DISABLED_INDEX                           22

#define SEVEN_BUTTON_EZLCD_BUTTON_UP_INDEX                  23
#define SEVEN_BUTTON_EZLCD_BUTTON_DOWN_INDEX                24
#define SEVEN_BUTTON_DISABLED_INDEX                         25

#define EIGHT_BUTTON_EZLCD_BUTTON_UP_INDEX                  26
#define EIGHT_BUTTON_EZLCD_BUTTON_DOWN_INDEX                27
#define EIGHT_BUTTON_DISABLED_INDEX                         28

#define NINE_BUTTON_EZLCD_BUTTON_UP_INDEX                   29
#define NINE_BUTTON_EZLCD_BUTTON_DOWN_INDEX                 30
#define NINE_BUTTON_DISABLED_INDEX                          31

#define STAR_BUTTON_EZLCD_BUTTON_UP_INDEX                   32
#define STAR_BUTTON_EZLCD_BUTTON_DOWN_INDEX                 33
#define STAR_BUTTON_DISABLED_INDEX                          34

#define POUND_BUTTON_EZLCD_BUTTON_UP_INDEX                  35
#define POUND_BUTTON_EZLCD_BUTTON_DOWN_INDEX                36
#define POUND_BUTTON_DISABLED_INDEX                         37

#define START_BUTTON_EZLCD_BUTTON_UP_INDEX                  38
#define START_BUTTON_EZLCD_BUTTON_DOWN_INDEX                39
#define START_BUTTON_DISABLED_INDEX                         40

#define STOP_BUTTON_EZLCD_BUTTON_UP_INDEX                   41
#define STOP_BUTTON_EZLCD_BUTTON_DOWN_INDEX                 42
#define STOP_BUTTON_DISABLED_INDEX                          43

#define BACK_BUTTON_EZLCD_BUTTON_UP_INDEX                   44
#define BACK_BUTTON_EZLCD_BUTTON_DOWN_INDEX                 45
#define BACK_BUTTON_DISABLED_INDEX                          46

#define NEXT_BUTTON_EZLCD_BUTTON_UP_INDEX                   47
#define NEXT_BUTTON_EZLCD_BUTTON_DOWN_INDEX                 48
#define NEXT_BUTTON_DISABLED_INDEX                          49

#define CONTINUE_BUTTON_EZLCD_BUTTON_UP_INDEX               50
#define CONTINUE_BUTTON_EZLCD_BUTTON_DOWN_INDEX             51
#define CONTINUE_BUTTON_DISABLED_INDEX                      52

#define CALIBRATE_BUTTON_EZLCD_BUTTON_UP_INDEX              53
#define CALIBRATE_BUTTON_EZLCD_BUTTON_DOWN_INDEX            54
#define CALIBRATE_BUTTON_DISABLED_INDEX                     55

#define SETTINGS_BUTTON_EZLCD_BUTTON_UP_INDEX               56
#define SETTINGS_BUTTON_EZLCD_BUTTON_DOWN_INDEX             57
#define SETTINGS_BUTTON_DISABLED_INDEX                      58



/*----------------------------------------------------------------------------*/
/* BITMAP SIZES                                                               */
/*----------------------------------------------------------------------------*/
/* The following list contains the sizes of all the bitmap images on the display
 * ROM
 */
 
#define SPASH_SCREEN_WIDTH                       320
#define SPASH_SCREEN_HEIGHT                      240

#define BACKGROUND_1_WIDTH                       320
#define BACKGROUND_1_HEIGHT                      240

/* Buttons */
#define ZERO_BUTTON_WIDTH                        50
#define ZERO_BUTTON_HEIGHT                       35

#define ONE_BUTTON_WIDTH                         50
#define ONE_BUTTON_HEIGHT                        35

#define TWO_BUTTON_WIDTH                         50
#define TWO_BUTTON_HEIGHT                        35

#define THREE_BUTTON_WIDTH                       50
#define THREE_BUTTON_HEIGHT                      35

#define FOUR_BUTTON_WIDTH                        50
#define FOUR_BUTTON_HEIGHT                       35
                                                 
#define FIVE_BUTTON_WIDTH                        50
#define FIVE_BUTTON_HEIGHT                       35
                                                 
#define SIX_BUTTON_WIDTH                         50
#define SIX_BUTTON_HEIGHT                        35
                                                 
#define SEVEN_BUTTON_WIDTH                       50
#define SEVEN_BUTTON_HEIGHT                      35

#define EIGHT_BUTTON_WIDTH                       50
#define EIGHT_BUTTON_HEIGHT                      35
                                                 
#define NINE_BUTTON_WIDTH                        50
#define NINE_BUTTON_HEIGHT                       35

#define STAR_BUTTON_WIDTH                        100
#define STAR_BUTTON_HEIGHT                       50

#define POUND_BUTTON_WIDTH                       100
#define POUND_BUTTON_HEIGHT                      50

#define START_BUTTON_WIDTH                       100
#define START_BUTTON_HEIGHT                      50
                                                 
#define STOP_BUTTON_WIDTH                        100
#define STOP_BUTTON_HEIGHT                       50

#define BACK_BUTTON_WIDTH                        100
#define BACK_BUTTON_HEIGHT                       50
                                                 
#define NEXT_BUTTON_WIDTH                        100
#define NEXT_BUTTON_HEIGHT                       50
                                                 
#define CONTINUE_BUTTON_WIDTH                    100
#define CONTINUE_BUTTON_HEIGHT                   50
                                                 
#define CALIBRATE_BUTTON_WIDTH                   100
#define CALIBRATE_BUTTON_HEIGHT                  50

#define SETTINGS_BUTTON_WIDTH                    100
#define SETTINGS_BUTTON_HEIGHT                   50



#endif /* EZLCD_USER_CONFIG_H */
/** @} */ /* ezLCD_103_user_config */