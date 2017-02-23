#include <avr/io.h>
#include "libbtn.h"
#include <util/delay.h>


#define LED PINB0

int main(void){

  /* Init LED and USART */

  // Initialize LED
  DDRB |= (1 << LED);


  // Init UART
  int ubrr_val = 25;
  UBRR0H = (unsigned char) (ubrr_val >> 8);
  UBRR0L = (unsigned char) ubrr_val;
  UCSR0B = (1 << RXEN0) | (1 << TXEN0);
  UCSR0C = (1 << USBS0) | (3 << UCSZ00);

  unsigned char receiveData;

  while(1){

    while(! (UCSR0A & (1 << RXC0)));

    receiveData = UDR0;
   
    // 43:35
    if(receiveData == 0b11110000){
      PORTB |= (1 << LED);
    }else{
      PORTB &= ~(1 << LED);
    }


    // Check to see if the receive buffer is empty
    
    // Receive buffer is full - (RXC flag)

    // Get the data 

    // Check the data
  
    // we're good, turn on the LED 


  }

}


