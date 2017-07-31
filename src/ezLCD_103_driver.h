/**
 * @file   ezLCD_103_driver.h  <br>
 * @author Frank Pernice <br>
 * @date   October 2013  <br>
 * @brief  Header file containing all driver code necessary to use the DOGM128
 *         with the ATMega128 (though other MCU's are not ruled out) <br>
 * @defgroup ezLCD_103_driver ezLCD+103 Driver
 * @{
 *
 * This header file contains all header files otherwise described in this 
 * library. Only this file should be included in the user's code.
 * To maximize space, the user may remove some, but not all, of these
 * files (by commenting out its inclusion in this file and detaching it from
 * the project) depending on how the ezLCD+103 is being used. The diagram below
 * illustrates the file dependencies. Those files which are marked in red
 * must never be removed from the library as they are critical to its
 * operation. Those files marked in blue may be removed. However, files which
 * are linked together must be included in the project together. For instance,
 * one cannot include text.h without first including polygons.h, colors.h, and
 * coordinates.h. 
 *
 * @image html ezLCD-hierarchy.png "ezLCD Driver Hierarchy"
 */
 
/* Used to prevent multiple inclusion of the header file */
#ifndef EZLCD_103_DRIVER_ATMEGA128_H
#define EZLCD_103_DRIVER_ATMEGA128_H

/*----------------------------------------------------------------------------*/
/* INCLUDES                                                                   */
/*----------------------------------------------------------------------------*/
#include "ezLCD_103_common.h"
#include "ezLCD_103_user_config.h"
#include "ezLCD_103_colors.h"
#include "ezLCD_103_polygons.h"
#include "ezLCD_103_coordinates.h"
#include "ezLCD_103_pen.h"
#include "ezLCD_103_pixels.h"
#include "ezLCD_103_lines.h"
#include "ezLCD_103_curves.h"
#include "ezLCD_103_fill.h"
#include "ezLCD_103_text.h"
#include "ezLCD_103_buttons.h"
#include "ezLCD_103_frames.h"
#include "ezLCD_103_images.h"
#include "ezLCD_103_system.h"

#endif /* EZLCD_103_DRIVER_ATMEGA128_H */
/** @} */ /* ezLCD_103_driver */