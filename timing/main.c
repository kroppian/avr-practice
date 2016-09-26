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

  TCCR1B |= (1 <<  CS10 | 1 <<  CS11);

  short short_goal = 2232;
  short long_goal = short_goal * 2;
  short goal = long_goal;
  short off = -1;

  while(1){

    if(clicked(PINB,PINB1,0)){
      if(goal != -1 && goal < long_goal)
        goal = off;
      else if (goal != -1 )
        goal = short_goal;
      else 
        goal = long_goal;
    }

    if(goal == -1)
       PORTB &= ~(1 << PINB0);
    else if(TCNT1 > goal){
   
       TCNT1 = 0;
       PORTB ^= (1 << PINB0);
    
    }

  }

  // 11111011
  // 10010111


}





