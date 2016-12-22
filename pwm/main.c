#include <avr/io.h>
#include <util/delay.h>

int main(void){

  DDRD |= 0xFF;
  DDRB |= 0xFF;
  TCCR1A |= (1 << WGM11) | (1 << COM1A1) | (1<<COM1A0);
  TCCR1B |= (1 << WGM12) | (1 << WGM13) | (1 << CS10 );
  ICR1 =  19999;


  while(1) {
  
    OCR1A = ICR1 - 0;
    _delay_ms(100);
    OCR1A = ICR1 - 400;
    _delay_ms(100);
    OCR1A = ICR1 - 800;
    _delay_ms(100);

    OCR1A = ICR1 - 1000;
    _delay_ms(100);

    OCR1A = ICR1 - 1200;
    _delay_ms(100);

    OCR1A = ICR1 - 1400;
    _delay_ms(100);

    OCR1A = ICR1 - 1600;
    _delay_ms(100);

    OCR1A = ICR1 - 1800;
    _delay_ms(100);

    OCR1A = ICR1 - 2000;
    _delay_ms(100);

    OCR1A = ICR1 - 2200;
    _delay_ms(100);


  }

}

