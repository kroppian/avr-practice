
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#include "liblcd.h"

int main(void)
{

  DDRC |= 1 << PINC2;
  
  int myNum = 0;

  initialize_lcd();

  initialize_rot(DDRC, PORTC, PINC1, DDRC, PORTC, PINC0);

  send_a_string("Hello again, Ian");

  while(1){


    if(rotating()){
      PORTC |= (1 << PINC2);  
    }else{
      PORTC &= ~(1 << PINC2);  
    }

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




