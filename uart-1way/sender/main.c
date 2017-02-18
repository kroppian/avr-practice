#include <avr/io.h>
#include "libbtn.h"
#include <util/delay.h>

#define BTN PINB0
#define LED PINB1

int main(void)
{

  // Initialize
  // LED
  DDRB |= (1 << LED);
  PORTB &= ~(1 << LED);

  // Button
  DDRB &= ~(1 << BTN);
  PORTB |= (1 << BTN);

  int ubrr_val = 25;
  // U
  UBRR0H = (unsigned char) (ubrr_val >> 8);
  UBRR0L = (unsigned char) ubrr_val;
  UCSR0B = (1 << RXEN0) | (1 << TXEN0);
  UCSR0C = (1 << USBS0) | (3 << UCSZ00);

  // 35:43
  while(1){

    btn_poll(PINB, BTN, 0);   

    if ( pressed(0)){
      PORTB |= (1 << LED);
      while(! (UCSR0A & (1 << UDRE0)));
      UDR0 = 0b11110000;
    } else {
      PORTB &= ~(1 << LED);
      UDR0 = 0b00000000;
    }

  }

}

