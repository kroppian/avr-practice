#ifndef uart
#define uart

#include <math.h>
#include <avr/io.h>

#define EVEN 1
#define ODD 0 
#define NONE 2

#define TRUE 1
#define FALSE 0

unsigned char uart_receive(void){

  while(! (UCSR0A & (1 << RXC0)));
  return UDR0;

}

void uart_send(unsigned char data){

  while(! (UCSR0A & (1 << UDRE0)));
  UDR0 = data;

}

void initialize_uart(int baud, char async_dub_speed, char bit_data_size, char par, char stop_bits, char usart_interupt_enb){

  uint16_t ubbr_val = lrint( (F_CPU / (16L * baud)) - 1);

  if(async_dub_speed)
    UCSR0A = (1 << U2X0);

  if(usart_interupt_enb) UCSR0B |= (1 << RXCIE0);

  // U
  UBRR0H = (unsigned char) (ubbr_val >> 8);
  UBRR0L = (unsigned char) ubbr_val;
  UCSR0B = (1 << RXEN0) | (1 << TXEN0);

  if(stop_bits == 2)
    UCSR0C |= (1 << USBS0);


  if(par == EVEN){
    UCSR0C |= (1 << UPM01);
  }else if (par == ODD){
    UCSR0C |= (3 << UPM00);
  }


  if(bit_data_size == 6){
    UCSR0C |= (1 << UCSZ00); // 6 bit data length
  }else if(bit_data_size == 7){
    UCSR0C |= (2 << UCSZ00); // 7 bit data length
  }else if(bit_data_size == 8){
    UCSR0C |= (3 << UCSZ00); // 8 bit data length
  }else if(bit_data_size == 9){
    UCSR0C |= (7 << UCSZ00); // 9 bit data length
  }






}

#endif

