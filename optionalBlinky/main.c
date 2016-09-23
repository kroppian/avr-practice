#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
  DDRB |= 1 << PINB0;     // turn pin one to an output
  DDRB &= ~(1 << PINB1);  // turn pin two to an input
  PORTB |= 1 << PINB1;    // turn pin two to a high threshold

  while(1)
  {
    PORTB ^= 1 << PINB0;

    if(bit_is_clear(PINB,1))
      _delay_ms(500);
    else
      _delay_ms(100);
    
  }
}


// 101010101
// 111111101


// 0 -> 0 
// 1 -> 0 



