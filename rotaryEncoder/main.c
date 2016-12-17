
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#include "liblcd.h"
#include "librot.h"

int main(void)
{

  DDRC |= 1 << PINC2;
  
  int myNum = 50;

  initialize_lcd();

  initialize_rot(DDRC, PORTC, PINC1, DDRC, PORTC, PINC0);

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




