#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
  DDRB |= 1 << PINB0;     // turn pin one to an output
  DDRB |= 1 << PINB1;     // turn pin two to an output
  DDRB &= ~(1 << PINB2);  // turn pin three to an input
  PORTB |= 1 << PINB2;    // turn pin three to a high threshold

  // set the initial states 
  PORTB |= 1 << PINB0;
  PORTB &= ~(1 << PINB1);

  short btn_pressed = 0;
  short min_streak = 500;
  short cur_streak = 0;


  while(1)
  {

    // If the button went from unpressed to pressed
    if(cur_streak > min_streak && ! btn_pressed && bit_is_clear(PINB,2)){
      PORTB ^= 1 << PINB0;
      PORTB ^= 1 << PINB1;
      // Mark that the button is pressed
      btn_pressed = 1; 
      // clear the streak
      cur_streak = 0;
    } else if (cur_streak > min_streak && ! bit_is_clear(PINB,2)){
      btn_pressed = 0; 
      cur_streak = 0;
    } else {
      // We're either still holding the button down or still not holding the button down
      cur_streak++; 
    }

  }
}


// 101010101
// 111111101


// 0 -> 0 
// 1 -> 0 



