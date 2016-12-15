
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#include "liblcd.h"

int main(void)
{

  DDRC |= 1 << PINC2;
  DDRC &= (1 << PINC1);
  DDRC &= (1 << PINC0);
  
  int myNum = 0;

  initialize_lcd();

  initialize_rot(DDRC, PORTC, PINC1, DDRC, PORTC, PINC0);

  send_a_string("Hello again, Ian");
  go_to_lcd_position(0,1);
  send_a_num(myNum);

  while(1){

  }

  // Idealy
  //
  // initialize_encoder(PORT1, PIN1, PORT2, PIN2);
  //
  // while(1){
  //
  //  if(rotating_clockwise()){
  //
  //  } else if(rotating_counterclockwise) {
  //
  //
  //  }
  //
  // }

  

}




