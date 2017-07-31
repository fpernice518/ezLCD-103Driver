/*----------------------------------------------------------------------------*/
/* INCLUDES                                                                   */
/*----------------------------------------------------------------------------*/
#include <iom128.h>
#include <intrinsics.h>
#include <avr_macros.h>
#include <stdio.h>

#include "ezLCD_103_driver.h"

/*----------------------------------------------------------------------------*/
/* BUTTON IDs                                                                 */
/*----------------------------------------------------------------------------*/
#define ZERO        0
#define ONE         1
#define TWO         2
#define THREE       3
#define FOUR        4
#define FIVE        5
#define SIX         6
#define SEVEN       7
#define EIGHT       8
#define NINE        9
#define STAR        10
#define POUND       11
#define START       12
#define STOP        13
#define CALIBRATE   14


/*----------------------------------------------------------------------------*/
/* PROTOTYPES                                                                 */
/*----------------------------------------------------------------------------*/
void draw_buttons();
void draw_number_pad(uint8_t num_pad_x, uint8_t num_pad_y);

/*----------------------------------------------------------------------------*/
/* FUNCTIONS                                                                  */
/*----------------------------------------------------------------------------*/
int main (void)
{  
  DDRB  = (1<<EZLCD_POWER_PIN) |    //power pin output
          (0<<EZLCD_MISO_PIN)  |    //MISO pin input
          (1<<EZLCD_MOSI_PIN)  |    //MOSI pin output
          (1<<EZLCD_SCK_PIN)   |    //SCK pin output
          (1<<EZLCD_SS_BAR_PIN);    //SS_BAR pin output
  
  EZLCD_POWER_OFF()
  EZLCD_INIT_SPI();
  __delay_cycles(10000);
  EZLCD_POWER_ON()
  
  /* Wait until display is fully powered and ready */
  while(!ezLCD_ping());

  /* Clear the screen contents */
  ezLCD_clear();
  
  /* Place background image */
  ezLCD_put_picture_rom(BACKGROUND_1_INDEX);
  
  /* Set touch protocol */
  ezLCD_set_touch_protocol(ezButton);
  
  /* Draw buttons on the screen */
  draw_buttons();
  
  /* Initialize the putchar() function */
  ezLCD_init_putchar(5, 5, 165-5, 70-5, 2, 2, 32,32,EZLCD_WHITE,EZLCD_VIOLET);
  
  /* Set the font */
  ezLCD_set_true_type_font(DEJAVUSANS_BOLD,32,32);
  
  while(1)
  {
    /* Wait for button press */
    uint8_t button = ezLCD_wait_for_event();
    
    /* Case on the button */
    if(button == CALIBRATE)
    {
        ezLCD_calibrate_screen();                  /* Calibrate the screen */
        
        /* Reset font, there appears to be a bug with the display itself where 
         *calibrating changes the font size
         */
        ezLCD_set_true_type_font(DEJAVUSANS_BOLD,32,32);
    }
    /* Zero through 9 */
    if(button <= NINE)
       printf("%d",button);            /* Print the button ID to the text box */
    
    /* Change the font mid-program and print a magical character */
    if(button == STAR)
    {
      ezLCD_set_true_type_font(WALTOGRAPH,32,32);
      ezLCD_set_ttf_unicode_base(0x245);
      putchar(2);
      ezLCD_set_true_type_font(DEJAVUSANS_BOLD,32,32);
      ezLCD_set_ttf_unicode_base(0);
    }
    
    /* If Pound button, print Greek letter Delta (TTF Fonts Only!)*/
    if(button == POUND)
    {
      ezLCD_set_ttf_unicode_base(0x394);
      putchar(0);
      ezLCD_set_ttf_unicode_base(0);
     }
    
    /* Clear screen of number pad and text box */
    if(button == STOP)
    {
      ezLCD_set_draw_frame(1);
      ezLCD_deactivate_all_buttons();
      ezLCD_set_xy(0,0);
      ezLCD_put_picture_rom(BACKGROUND_1_INDEX);
      
       ezLCD_button_define_long(14,
                         EZLCD_BUTTON_UP,
                         CALIBRATE_BUTTON_EZLCD_BUTTON_UP_INDEX,
                         CALIBRATE_BUTTON_EZLCD_BUTTON_DOWN_INDEX,
                         CALIBRATE_BUTTON_DISABLED_INDEX,
                         215,
                         115,
                         CALIBRATE_BUTTON_WIDTH,
                         CALIBRATE_BUTTON_HEIGHT);
       ezLCD_button_define_long(START,
                           EZLCD_BUTTON_UP,
                           START_BUTTON_EZLCD_BUTTON_UP_INDEX,
                           START_BUTTON_EZLCD_BUTTON_DOWN_INDEX,
                           START_BUTTON_DISABLED_INDEX,
                           215,
                           5,
                           START_BUTTON_WIDTH,
                           START_BUTTON_HEIGHT);
  
       ezLCD_button_define_long(STOP,
                           EZLCD_BUTTON_UP,
                           STOP_BUTTON_EZLCD_BUTTON_UP_INDEX,
                           STOP_BUTTON_EZLCD_BUTTON_DOWN_INDEX,
                           STOP_BUTTON_DISABLED_INDEX,
                           215,
                           60,
                           STOP_BUTTON_WIDTH,
                           STOP_BUTTON_HEIGHT);
       ezLCD_set_display_frame(1);
    }
    
    /* Restore numberpad and text box */
    if(button == START)
    {
      ezLCD_set_draw_frame(1);
      ezLCD_deactivate_all_buttons();
      ezLCD_set_xy(0,0);
      ezLCD_put_picture_rom(BACKGROUND_1_INDEX);
      draw_buttons();
      ezLCD_init_putchar(5, 5, 165-5, 70-5, 2, 2, 32,32,EZLCD_WHITE,EZLCD_VIOLET);
      ezLCD_set_true_type_font(DEJAVUSANS_BOLD,32,32);
      ezLCD_set_display_frame(1);
    }
  }

}

void draw_buttons()
{  
  draw_number_pad(5,80); 
  
  ezLCD_button_define_long(START,
                           EZLCD_BUTTON_UP,
                           START_BUTTON_EZLCD_BUTTON_UP_INDEX,
                           START_BUTTON_EZLCD_BUTTON_DOWN_INDEX,
                           START_BUTTON_DISABLED_INDEX,
                           215,
                           5,
                           START_BUTTON_WIDTH,
                           START_BUTTON_HEIGHT);
  
  ezLCD_button_define_long(STOP,
                           EZLCD_BUTTON_UP,
                           STOP_BUTTON_EZLCD_BUTTON_UP_INDEX,
                           STOP_BUTTON_EZLCD_BUTTON_DOWN_INDEX,
                           STOP_BUTTON_DISABLED_INDEX,
                           215,
                           60,
                           STOP_BUTTON_WIDTH,
                           STOP_BUTTON_HEIGHT);
  
  ezLCD_button_define_long(CALIBRATE,
                           EZLCD_BUTTON_UP,
                           CALIBRATE_BUTTON_EZLCD_BUTTON_UP_INDEX,
                           CALIBRATE_BUTTON_EZLCD_BUTTON_DOWN_INDEX,
                           CALIBRATE_BUTTON_DISABLED_INDEX,
                           215,
                           115,
                           CALIBRATE_BUTTON_WIDTH,
                           CALIBRATE_BUTTON_HEIGHT);
        

}

/* Used to keep numbers grouped together neatly */
void draw_number_pad(uint8_t num_pad_x, uint8_t num_pad_y)
{
  ezLCD_button_define_long(ZERO,
                          EZLCD_BUTTON_UP,
                          ZERO_BUTTON_EZLCD_BUTTON_UP_INDEX,
                          ZERO_BUTTON_EZLCD_BUTTON_DOWN_INDEX,
                          ZERO_BUTTON_DISABLED_INDEX,
                          num_pad_x + 50 + 5,
                          num_pad_y + 105 + 15,
                          ZERO_BUTTON_WIDTH,
                          ZERO_BUTTON_HEIGHT);
   ezLCD_button_define_long(ONE,
                           EZLCD_BUTTON_UP,
                           ONE_BUTTON_EZLCD_BUTTON_UP_INDEX,
                           ONE_BUTTON_EZLCD_BUTTON_DOWN_INDEX,
                           ONE_BUTTON_DISABLED_INDEX,
                           num_pad_x,
                           num_pad_y,
                           ONE_BUTTON_WIDTH,
                           ONE_BUTTON_HEIGHT);
    
   ezLCD_button_define_long(TWO,
                           EZLCD_BUTTON_UP,
                           TWO_BUTTON_EZLCD_BUTTON_UP_INDEX,
                           TWO_BUTTON_EZLCD_BUTTON_DOWN_INDEX,
                           TWO_BUTTON_DISABLED_INDEX,
                           num_pad_x + 50 + 5,
                           num_pad_y,
                           TWO_BUTTON_WIDTH,
                           TWO_BUTTON_HEIGHT);
   
   ezLCD_button_define_long(THREE,
                           EZLCD_BUTTON_UP,
                           THREE_BUTTON_EZLCD_BUTTON_UP_INDEX,
                           THREE_BUTTON_EZLCD_BUTTON_DOWN_INDEX,
                           THREE_BUTTON_DISABLED_INDEX,
                           num_pad_x + 100 + 10,
                           num_pad_y,
                           THREE_BUTTON_WIDTH,
                           THREE_BUTTON_HEIGHT);
   
   ezLCD_button_define_long(FOUR,
                           EZLCD_BUTTON_UP,
                           FOUR_BUTTON_EZLCD_BUTTON_UP_INDEX,
                           FOUR_BUTTON_EZLCD_BUTTON_DOWN_INDEX,
                           FOUR_BUTTON_DISABLED_INDEX,
                           num_pad_x,
                           num_pad_y + 35 + 5,
                           FOUR_BUTTON_WIDTH,
                           FOUR_BUTTON_HEIGHT);
   
   ezLCD_button_define_long(FIVE,
                           EZLCD_BUTTON_UP,
                           FIVE_BUTTON_EZLCD_BUTTON_UP_INDEX,
                           FIVE_BUTTON_EZLCD_BUTTON_DOWN_INDEX,
                           FIVE_BUTTON_DISABLED_INDEX,
                           num_pad_x + 50 + 5,
                           num_pad_y + 35 + 5,
                           FIVE_BUTTON_WIDTH,
                           FIVE_BUTTON_HEIGHT);
   
   ezLCD_button_define_long(SIX,
                           EZLCD_BUTTON_UP,
                           SIX_BUTTON_EZLCD_BUTTON_UP_INDEX,
                           SIX_BUTTON_EZLCD_BUTTON_DOWN_INDEX,
                           SIX_BUTTON_DISABLED_INDEX,
                           num_pad_x + 100 + 10,
                           num_pad_y + 35 + 5,
                           SIX_BUTTON_WIDTH,
                           SIX_BUTTON_HEIGHT);
   
   ezLCD_button_define_long(SEVEN,
                           EZLCD_BUTTON_UP,
                           SEVEN_BUTTON_EZLCD_BUTTON_UP_INDEX,
                           SEVEN_BUTTON_EZLCD_BUTTON_DOWN_INDEX,
                           SEVEN_BUTTON_DISABLED_INDEX,
                           num_pad_x,
                           num_pad_y + 70 + 10,
                           SEVEN_BUTTON_WIDTH,
                           SEVEN_BUTTON_HEIGHT);
   
   ezLCD_button_define_long(EIGHT,
                           EZLCD_BUTTON_UP,
                           EIGHT_BUTTON_EZLCD_BUTTON_UP_INDEX,
                           EIGHT_BUTTON_EZLCD_BUTTON_DOWN_INDEX,
                           EIGHT_BUTTON_DISABLED_INDEX,
                           num_pad_x + 50 + 5,
                           num_pad_y + 70 + 10,
                           EIGHT_BUTTON_WIDTH,
                           EIGHT_BUTTON_HEIGHT);
   
   ezLCD_button_define_long(NINE,
                           EZLCD_BUTTON_UP,
                           NINE_BUTTON_EZLCD_BUTTON_UP_INDEX,
                           NINE_BUTTON_EZLCD_BUTTON_DOWN_INDEX,
                           NINE_BUTTON_DISABLED_INDEX,
                           num_pad_x + 100 + 10,
                           num_pad_y + 70 + 10,
                           NINE_BUTTON_WIDTH,
                           NINE_BUTTON_HEIGHT);
   
  ezLCD_button_define_long(STAR,
                           EZLCD_BUTTON_UP,
                           STAR_BUTTON_EZLCD_BUTTON_UP_INDEX,
                           STAR_BUTTON_EZLCD_BUTTON_DOWN_INDEX,
                           STAR_BUTTON_DISABLED_INDEX,
                           num_pad_x,
                           num_pad_y + 105 + 15,
                           STAR_BUTTON_WIDTH,
                           STAR_BUTTON_HEIGHT);
   
  ezLCD_button_define_long(POUND,
                           EZLCD_BUTTON_UP,
                           POUND_BUTTON_EZLCD_BUTTON_UP_INDEX,
                           POUND_BUTTON_EZLCD_BUTTON_DOWN_INDEX,
                           POUND_BUTTON_DISABLED_INDEX,
                           num_pad_x + 100 + 10,
                           num_pad_y + 105 + 15,
                           POUND_BUTTON_WIDTH,
                           POUND_BUTTON_HEIGHT);
}