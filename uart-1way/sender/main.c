#include <avr/io.h>
#include "libbtn.h"
#include <util/delay.h>

#include "uart.h"

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

  initialize_uart(16, 0, 6, 0, 2);

  // 35:43
  while(1){

    btn_poll(PINB, BTN, 0);   

    if ( pressed(0)){
      PORTB |= (1 << LED);
      uart_send(0b11110000);
    } else {
      PORTB &= ~(1 << LED);
      uart_send(0b00000000);
    }

  }

}

