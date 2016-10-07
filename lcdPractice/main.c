#include <avr/io.h>
#include <util/delay.h>

#define MrLCDsCrib      PORTB
#define MrLCDsControl   PORTD
#define LightSwitch     5
#define ReadWrite       7
#define BiPolarMood     2
#define DataDirMrLCDControl DDRD
#define datadirMrLCDsCrib     DDRB

void check_if_mr_lcd_is_busy(void);
void peek_a_boo(void);
void send_a_command(unsigned char command);
void send_a_character(unsigned char character);

int main(void)
{

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


  send_a_character(0x48); // H
  send_a_character(0x65); // e
  send_a_character(0x6C); // l
  send_a_character(0x6C); // l
  send_a_character(0x6F); // o
  send_a_character(0x20); // 
  send_a_character(0x77); // w
  send_a_character(0x6F); // o
  send_a_character(0x72); // r
  send_a_character(0x6C); // l
  send_a_character(0x64); // d
  send_a_character(0x21); // !
  send_a_character(0x21); // !
  send_a_character(0x21); // !

  while(1){}

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


