
#include "librot.h"
#include <avr/interrupt.h>  

// 0 for left 
// 1 for no rotation
// 2 for right
unsigned short state;

int initialize_rot(int data_dira, int porta, int pina, 
    int data_dirb, int portb, int pinb){

  sei();

  // Temporary 
  DDRC |= 1 << PINC2;
  PORTC &= ~(1 << PINC2);
  // End temporary 
 
  data_dira &= (1 << pina);
  data_dirb &= (1 << pinb);

  //     ---- 64 prescaler ------  waveform generation mode
  TCCR1B |= 1 << CS10 | 1 << CS11 | 1<<WGM12;
  // timer interupt mask
  TIMSK1 |= 1<< OCIE1A;

  OCR1A = 100;

  return 0;

}


int rotating(){

  return 0;

}

void poll(){

  PORTC ^= (1 << PINC2);

}

// interup service routine
ISR(TIMER1_COMPA_vect){

  poll();

}

