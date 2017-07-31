/*
 * @file   ezLCD_103_buttons.c  <br>
 * @author Frank Pernice <br>
 * @date   November 2013  <br>
 * @brief  ezLCD button management and rendering source file  <br>
 * @defgroup ezLCD_103_buttons Buttons
 * @{
 *
 * This header contains functions used for configuring, placing, and polling 
 * buttons on the screen. It is <b>strongly recommended that the user read 
 * section 4 <a href="External Commands Manual.pdf" target="_blank"> of the 
 * ezLCD External Commands manual before continuing</a></b>
 */
 
/*----------------------------------------------------------------------------*/
/* INCLUDES                                                                   */
/*----------------------------------------------------------------------------*/
#include "ezLCD_103_common.h"
#include "ezLCD_103_buttons.h"

/*----------------------------------------------------------------------------*/
/* FUNCTIONS                                                                  */
/*----------------------------------------------------------------------------*/
void ezLCD_button_define_long(uint8_t id,
                              ezLCD_button_state_t state, 
                              uint16_t index_up,
                              uint16_t index_down,
                              uint16_t index_disabled,
                              uint16_t x,
                              uint16_t y,
                              uint8_t width,
                              uint8_t height)

{
 if(id > 63) return;
 
 ezLCD_transfer_data_long(0xB5,0);
 ezLCD_transfer_data_long(id,0);
 ezLCD_transfer_data_long(state,0);
 
 ezLCD_transfer_data_long(index_up >> 8,0);
 ezLCD_transfer_data_long(index_up & 0xFF,0);
 
 ezLCD_transfer_data_long(index_down >> 8,0);
 ezLCD_transfer_data_long(index_down & 0xFF,0);
 
 ezLCD_transfer_data_long(index_disabled >> 8,0);
 ezLCD_transfer_data_long(index_disabled & 0xFF,0);
 
 ezLCD_transfer_data_long(x >> 8,0);
 ezLCD_transfer_data_long(x & 0xFF,0);
 
 ezLCD_transfer_data_long(y >> 8,0);
 ezLCD_transfer_data_long(y & 0xFF,0);
 
 ezLCD_transfer_data_long(width,0);
 ezLCD_transfer_data_long(height,1);
}


void ezLCD_set_touch_protocol(ezLCD_touch_protocol_t protocol)
{
 ezLCD_transfer_data_long(0xB2,0);
 ezLCD_transfer_data_long(protocol,1);
}

void ezLCD_set_button_state(uint8_t id, ezLCD_button_state_t state)
{
 ezLCD_transfer_data_long(0xB1,0);
 ezLCD_transfer_data_long(id,0);
 ezLCD_transfer_data_long(state,1);
}

void ezLCD_calibrate_screen()
{
  uint8_t finished = 0;
  
  ezLCD_transfer_data(0xB6);
  
  do
  {
    finished = ezLCD_transfer_data(0x00);
  } while(finished != 0x32);
}

void ezLCD_all_buttons_up()
{
  ezLCD_transfer_data(0xB3);
}

//buttons stop responding to touch, does not remove from screen.
void ezLCD_deactivate_all_buttons()
{
  ezLCD_transfer_data(0xB4);
}

uint8_t ezLCD_wait_for_event()
{
  uint8_t released = 0; /* Button Released flag */
  
  int8_t button = -1;   /* Button ID can NEVER be negative, but it can be zero
                         * so we initialize it to -1 to indicate that no button 
                         * has been pressed yet. */  
  
  
  /* Loop until the button has been released */
  while(button == -1 || released == 0)
  { 
    /* Send nop command to display, we only care about the data being sent back
    from the ezLCD.*/
    button = ezLCD_transfer_data(0);
    
    if((button & 0xC0)>>6 == 2) /* If button state is UP */
    
    /* This if statement will only be entered AFTER the below "else if" has been
     * executed since the ezButton does not send any data about buttons which
     * have never been pressed. */
    {
      released = 1;           /*set the released flag to 1 so we may exit loop*/
      /* Return the button image to its UP position */
      ezLCD_set_button_state(button & 0x3F, EZLCD_BUTTON_UP);
    }     
    else if((button & 0xC0)>>6 == 1) /* Else if button state is DOWN */
    {
      /* Set the button image to its DOWN position */
      ezLCD_set_button_state(button & 0x3F, EZLCD_BUTTON_DOWN);
    }
  }
  return button & 0x3F; /*Return the ID of the pressed button, making sure to
                         * mask out the now unneeded status bits.
                         */
}
/** @} */ /* ezLCD_103_buttons */






