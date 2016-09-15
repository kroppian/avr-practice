#include <avr/io.h>
#include <util/delay.h>

char path[] = {
  ~(1 << PINB0),
  ~(1 << PINB1),
  ~(1 << PINB2),
  ~(1 << PINB3),
  ~(1 << PINB4),
  ~(1 << PINB5)
  };

short btn_pressed[2] = {0,0};
short conf_level[2] = {500,0};
short curr_conf[2] = {0,0};

int flash(int player){

  short delay = 500;

  _delay_ms(delay/2);
  if (player == 0)
    PORTB &= 0;
  else 
    PORTD &= 0;

  _delay_ms(delay/2);
  if (player == 0) 
    PORTB ^= 0xFF >> 2;
  else
    PORTD ^= 0xFF >> 2;

  return 0;

}

int clicked(int player){

  // If the button went from unpressed to pressed
  if(curr_conf[player] > conf_level[player] && ! btn_pressed[player] && bit_is_clear(PINC,player)){
    // Mark that the button is pressed
    btn_pressed[player] = 1; 
    // clear the streak
    curr_conf[player] = 0;
    return 1;
  } else if (curr_conf[player] > conf_level[player] && ! bit_is_clear(PINC,player)){
    btn_pressed[player] = 0; 
    curr_conf[player] = 0;
  } else {
    // We're either still holding the button down or still not holding the button down
    curr_conf[player]++; 
  }
  return 0;

  if (bit_is_clear(PINC,player))
    return 1;
  else 
    return 0; 

  /*if(! btn_pressed[player] && bit_is_clear(PINC,player)){
    // Mark that the button is pressed
    btn_pressed[player] = 1; 
    // clear the streak
    return 1;
  } else if (! bit_is_clear(PINC,player)){
    btn_pressed[player] = 0; 
    return 0;
  } */
}


int main(void)
{

  // Turn on the two buttons on port C as input
  DDRC &= ~(1 << PINC0);
  DDRC &= ~(1 << PINC1);
  // Turn on the two buttons on port C to a hight threshold
  PORTC |= (1 << PINC0);
  PORTC |= (1 << PINC1);
  
  // turn on pins 0 through 5 for port B as output
  DDRB |= 0b00111111;
  // turn on pins 0 through 5 for port D as output
  DDRD |= 0b00111111;

  // set the initial states 
  //PORTB &= 0xFF >> 2;
  PORTB |= 0b00111111;
  // set the initial states 
  PORTD |= 0b00111111;

  short goal = 6;
  short p0_pos = 0;
  short p1_pos = 0;

  int i;
  while(1) { 

    //if(clicked(PINC0)){
    if(clicked(PINC0)){
      //PORTB &= (0xFF << 1);
      PORTB = path[p0_pos % goal];
      p0_pos++;
      //for(i = 0; i < 4; i++) 
      //  flash(0);

    }

    if(clicked(PINC1)){
      //PORTD &= (0xFF << 1);
      PORTD = path[p1_pos % goal];
      p1_pos++;
      //for(i = 0; i < 4; i++) 
        //flash(1);
    }

  }

}







