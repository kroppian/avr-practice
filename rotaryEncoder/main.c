
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#define BTN_COUNT 2
#define CONFIDENCE 1


#include "liblcd.h"
#include "libbtn.h"


int main(void)
{

  DDRC |= 1 << PINC2;
  DDRC &= (1 << PINC1);
  DDRC &= (1 << PINC0);
  
  int myNum = 0;

  initialize_lcd();

  send_a_string("Hello again, Ian");
  go_to_lcd_position(0,1);
  send_a_num(myNum);

  while(1){

    // if the thing is turning 
    if(pressed(PINC,PINC1,0)){
    
      myNum++; 
      // Flip the light
      PORTC ^= 1 << PINC2;

      // increase the number
      go_to_lcd_position(0,1);
      send_a_num(myNum);

    }


  }

  /*int i;
  while(1){


    for(i = 0; i < 32; i++){

      go_to_lcd_position(i % 16, (i >= 16));
      send_a_string("x");

      _delay_ms(200);
     
      go_to_lcd_position(i % 16, (i >= 16));
      send_a_string(" ");

    
    }
        
  }*/

  

}




