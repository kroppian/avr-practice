
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#include "liblcd.h"
#include "librot.h"

int main(void)
{

  DDRC |= 1 << PINC2;
  
  int myNum = 0;

  initialize_lcd();

  initialize_rot(DDRC, PORTC, PINC1, DDRC, PORTC, PINC0);

  send_a_string("Hello Daniel!");

  while(1){


    if(rotating() == LEFT){
      go_to_lcd_position(0,1);
      send_a_string("left ");
    }else if(rotating() == RIGHT){
      go_to_lcd_position(0,1);
      send_a_string("right");
    }

  }

}




