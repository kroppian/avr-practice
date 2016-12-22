#include <avr/io.h>
#include <util/delay.h>
#include "librot.h"

int main(void){

  DDRB |= (1 << PINB1);
  DDRB &= ~(1 << PINB2);
  DDRB &= ~(1 << PINB3);
  //DDRB |= 0xFF;

  initialize_rot(PINSETB,PINB2,PINSETB,PINB3);

  /*TCCR1A |= (1 << WGM11) | (1 << COM1A1) | (1<<COM1A0);
  TCCR1B |= (1 << WGM12) | (1 << WGM13) | (1 << CS10 );
  ICR1 =  19999;*/

  int offset = 200;

  while(1) {
 
    if(rotating() == RIGHT ){
      PORTB |= 1 << PINB1;
    }else if (rotating() == LEFT){
      PORTB &= ~(1 << PINB1);

    }

    //OCR1A = ICR1 - offset;
    /*OCR1A = ICR1 - offset;
    _delay_ms(100);*/
    /*OCR1A = ICR1 - 400 + offset;
    _delay_ms(100);
    OCR1A = ICR1 - 800 + offset;
    _delay_ms(100);

    OCR1A = ICR1 - 1000 + offset;
    _delay_ms(100);

    OCR1A = ICR1 - 1200 + offset;
    _delay_ms(100);

    OCR1A = ICR1 - 1400 + offset;
    _delay_ms(100);

    OCR1A = ICR1 - 1600 + offset;
    _delay_ms(100);

    OCR1A = ICR1 - 1800 + offset;
    _delay_ms(100);

    OCR1A = ICR1 - 2000 + offset;
    _delay_ms(100);

    OCR1A = ICR1 - 2200 + offset;
    _delay_ms(100); */


  }

}

