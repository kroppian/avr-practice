
#include "liblcd.h"


void initialize_lcd(void){

  // Setting up the intial controls
  DataDirMrLCDControl |= 1<<LightSwitch | 1<<ReadWrite | 1 << BiPolarMood;

  _delay_ms(15);

  send_a_command(0x01); // Clear screen
  _delay_ms(2);
  send_a_command(0x38); // set it to 8 bit mode
  // we get this from the datasheet
  _delay_us(50);
  // command to display and cursor
  //                    | is the display on or off
  //                     | is the cursor going to be on or off
  //                      | is the cursor going to be blinking
  send_a_command(0b00001110); //
  _delay_us(50);


}



void peek_a_boo(void){

  MrLCDsControl |= 1<<LightSwitch;
  asm volatile ("nop");
  asm volatile ("nop");
 
  MrLCDsControl &= ~(1<<LightSwitch);

}
void send_a_command(unsigned char command){

  check_if_mr_lcd_is_busy();
 // get the command ready to go!
 MrLCDsCrib = command;
 // Turning  off read write, turn off Bipolar mood
 MrLCDsControl &= ~ (1<<ReadWrite|1<<BiPolarMood);
 peek_a_boo();
 MrLCDsCrib = 0;


}
void send_a_character(unsigned char character){

  check_if_mr_lcd_is_busy();
  MrLCDsCrib = character;
  MrLCDsControl  &= ~ (1<<ReadWrite);
  MrLCDsControl  |= (1<<BiPolarMood);
  peek_a_boo();
  MrLCDsCrib = 0;

}

// This is the only time when we're reading from the LCD
// otherwise we're outputting to LCD
void check_if_mr_lcd_is_busy(){
  datadirMrLCDsCrib  = 0;

 
  MrLCDsControl |= 1<<ReadWrite;
  MrLCDsControl &= ~1<<BiPolarMood;
  while(MrLCDsCrib >= 0x80){ // looking pin d7 0b10000000
 
    peek_a_boo();
 
  }

  datadirMrLCDsCrib = 0xFF;

}

void send_a_string(char *  message){

  unsigned short pos = 0;

  while(message[pos] != '\0'){
 
    send_a_character(message[pos]); // e

    pos++;

  }

}

int count_places(int num){

  if(num == 0) return 0;

  return count_places(num / 10) + 1;

}

void send_a_num(unsigned int num){

  if(num == 0) send_a_string("0");

  int number_of_places = count_places(num);
 
  //                                            | for the end of string
  char * num_string = malloc(number_of_places + 1);
  num_string[number_of_places] = '\0';
  while(number_of_places > 0){


    num_string[number_of_places - 1] = ((num % 10) + 48);

    num /= 10;

    number_of_places--;  
  
  }

  send_a_string(num_string);

}

void go_to_lcd_position(unsigned int x, unsigned int y){

  if (y < 0 || y > 1 || x < 0 || x > 15) return; 

  send_a_command(0b10000000 + (y * 64) + x);


}
