
#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "libuart.h"

volatile unsigned char receivedByte;

char success = 0;

int main()
{
  DDRB |= 1 << PINB1;


  // 1. baud rate
  // 2. async dub speed
  // 3. data bit size 
  // 4. parity 
  // 5. stop bits
  // 6. Usart interupt 
  initialize_uart(9600, 0, 8, NONE, 1, TRUE);


  // Enable a prescaler (based on the internal/external clock)
  // Has to be between 16000000/50000 (320) and 16000000/200000 (80). 50000 and 200000 
  // come from the datasheet 
  ADCSRA |= (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2);
 
  ADMUX |= (1 << ADLAR);

  // Set the reference voltage source
  ADMUX |= (1 << REFS0);

  ADCSRA |= (1 << ADIE);
  ADCSRA |=  (1 << ADEN);

  sei();

  // Turn on the ADC filter
  ADCSRA |= (1 << ADSC);
   
  

  while(1)
  {
    //PORTB ^= 1 << PINB1;
    //uart_send('b');
  }
}


ISR(ADC_vect){

  // Lord, forgive me for this hacky mess. This is a proof of concept and it's not pretty
  // all spaces as filler
  char buffer[3] = {'0', '0', '0'};
  int myNum = ADCH;
  int i;

  if(myNum == 0) {
    buffer[3] = '0';
  }else{
    i = 0;
    while(myNum != 0){
      buffer[2 - i] = (myNum % 10) + '0';
      myNum = myNum / 10;
      i++;
    }
  }

  for(i = 0; i < 3; i++){
    uart_send(buffer[i]);
  }

  uart_send('\r'); 

  // Turn on the ADC filter
  ADCSRA |= (1 << ADSC);
    
}

