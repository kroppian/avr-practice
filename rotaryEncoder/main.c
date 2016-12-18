
#include <avr/io.h>
#include <stdlib.h>

#include "liblcd.h"
#include "librot.h"

int main(void)
{

  // Flashy debug button 
  DDRC |= 1 << PINC2;
 
  // our heroic rotary pins
  DDRC &= (1 << PINC1);
  DDRC &= (1 << PINC0);

  int myNum = 50;

  initialize_lcd();

  initialize_rot(PINSETC, PINC1, PINSETC, PINC0);

  send_a_string("Turn to + or -!");

  int is_rotating = 0;

  while(1){

    if(! is_rotating && rotating() == LEFT){
      go_to_lcd_position(0,1);
      myNum--;
      send_a_num(myNum);
      is_rotating = 1;
    }else if(! is_rotating && rotating() == RIGHT){
      go_to_lcd_position(0,1);
      myNum++;
      is_rotating = 1;
      send_a_num(myNum);
    }else if(rotating() == NO_ROT) {
      is_rotating = 0; 
    }

  }

}




