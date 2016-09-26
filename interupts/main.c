#include <avr/io.h>
#include <avr/interrupt.h>


int main(void)
{

  sei();

  // set to output
  DDRB |= (1 << PINB0);

  // Turn the light to off at first
  PORTB &= ~(1 << PINB0);  

  TCCR1B |= 1 << CS10 | 1 << CS11 | 1<<WGM12;
  TIMSK1 |= 1<< OCIE1A;

  OCR1A = 15624;
  
  while(1){
  }
}


ISR(TIMER1_COMPA_vect){

  PORTB ^= 1<<PINB0;

}


