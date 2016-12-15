
#include "librot.h"
#include <avr/interrupt.h>  

// 0 for left 
// 1 for no rotation
// 2 for right
unsigned short state;

int porta;
int pina;
int portb;
int pinb;

void initialize_rot(int data_dira, int new_porta, int new_pina, 
    int data_dirb, int new_portb, int new_pinb){

  state = 0;

  porta = new_porta;
  pina = new_pina;
  portb = new_portb;
  pinb = new_pinb;

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

}


int rotating(){

  return state;

}

// interup service routine
ISR(TIMER1_COMPA_vect){

  /*if(state)
    state = 0;
  else 
    state = 1;*/

  if(bit_is_clear(PINC,PINC1)) {
    state = 1;
  }else{
    state = 0;
  }

}

