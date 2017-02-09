#include <avr/io.h>
#include <util/delay.h>
#include "librot.h"

int main(void){

  DDRB |= (1 << PINB1);
  DDRB &= ~(1 << PINB2);
  DDRB &= ~(1 << PINB3);

  initialize_rot(PINSETB,PINB3,PINSETB,PINB2);

  TCCR1A |= (1 << WGM11) | (1 << COM1A1) | (1<<COM1A0);
  TCCR1B |= (1 << WGM12) | (1 << WGM13) | (1 << CS10 );
  ICR1 =  19999;

  int offset = 0;

  int is_rot = 0;

  while(1) {
 
    if(! is_rot && rotating() == RIGHT){
      offset += 500;
      is_rot = 1;
    }else if (! is_rot && rotating() == LEFT){
      offset -= 500;
      is_rot = 1;
    }else if(rotating() == NO_ROT){
      is_rot = 0; 
    }

    if(offset < 0){
      offset = 0; 
    }else if(offset > 19999){
      offset = 18000;
    }

    OCR1A = ICR1 - offset;


  }

}

