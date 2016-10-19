
#include "lcdlib.h"
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>


int main(void)
{


  initialize_lcd();

  int i;
  while(1){


    for(i = 0; i < 32; i++){

      go_to_lcd_position(i % 16, (i >= 16));
      send_a_string("x");

      _delay_ms(200);
     
      go_to_lcd_position(i % 16, (i >= 16));
      send_a_string(" ");

    
    }
        
  }

}




