#include <avr/io.h>
#include <util/delay.h>

#define btn_count 1

#include "button.h"


int main(void)
{

  // set to output
  DDRB |= (1 << PINB0);
  // set to input
  DDRB &= ~(1 << PINB1);

  // Turn the light to off at first
  PORTB &= ~(1 << PINB0);  

  // Turn the input to high voltage 
  PORTB |= (1 << PINB1);

  _delay_ms(500);

  while(1){
 
    if(clicked(PINB,PINB1,0))   
      PORTB ^= (1 << PINB0);
  
  }

  // 11111011
  // 10010111


}





