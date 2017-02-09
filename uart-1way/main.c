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

  // U

  while(1){

    btn_poll(PINB, BTN, 0);   

    if (! pressed(0)){
      PORTB &= ~(1 << LED);
    } else {
      PORTB |= (1 << LED);
    }

  }

}

