
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

  sei();

  while(1)
  {
    PORTB ^= 1 << PINB1;
    //uart_send(0b01100001);
    //uart_send(0b10000110);
    uart_send('b');
    //uart_send(0b01010101);
    if(success)
      _delay_ms(10);
    else 
      _delay_ms(100);
  }
}


ISR(USART0_RX_VECT){

  receivedByte=  UDR0;

  success = 1;
  //PORTB ^= 1 << PINB1;


}

