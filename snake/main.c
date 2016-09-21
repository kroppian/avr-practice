#include <avr/io.h>
#include <util/delay.h>

#define PLAYER1 0
#define PLAYER2 1

char path[] = {
  ~(1 << PINB0), // 11111110
  ~(1 << PINB1),
  ~(1 << PINB2),
  ~(1 << PINB3),
  ~(1 << PINB4),
  ~(1 << PINB5)
  };

short btn_pressed[2] = {0,0};
short conf_level[2] = {500,500};
short curr_conf[2] = {0,0};

int flash(short player){

  short delay = 200;

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

}


int main(void)
{

  // Turn on the first two buttons on port C as input
  DDRC &= ~(1 << PINC0);
  DDRC &= ~(1 << PINC1);
  // Turn on the first two buttons on port C to a hight threshold
  PORTC |= (1 << PINC0);
  PORTC |= (1 << PINC1);
 
  // set the start lights to output
  DDRC |= (1 << PINC2);
  DDRC |= (1 << PINC3);
  DDRC |= (1 << PINC4);

  // Clean out the output register reigsters
  PORTC |= (1 << PINC2);
  PORTC |= (1 << PINC3);
  PORTC |= (1 << PINC4);

  short position[2];
  position[PLAYER1] = 0;
  position[PLAYER2] = 0;
  short started;
  short goal = 6;

  // turn on pins 0 through 5 for port B as output
  DDRB |= 0xFF >> 2;
  // turn on pins 0 through 5 for port D as output
  DDRD |= 0xFF >> 2;
  
  // 0 & 0 -> 1
  // 1 & 0 -> 0
  short win;

  while(1){
    
    // set the initial states 
    PORTB |= 0xFF >> 2;  
    // set the initial states 
    PORTD |= 0xFF >> 2;  

    int i;

    started = 0;

    while ( ! started ) {

      for (i = 0; i < 200; i++){
        _delay_ms(1);
        if(clicked(PLAYER1) || clicked(PLAYER2)) {
          started = 1;
          break;
        }
      }

      // wipe player one's board
      PORTB |= 0xFF >> 2;
      // set the new position
      PORTB &= path[position[PLAYER1] % goal];

      // wipe player one's board
      PORTD |= 0xFF >> 2;
      // set the new position
      PORTD &= path[position[PLAYER2] % goal];

      if(clicked(PLAYER1) || clicked(PLAYER2)) 
        started = 1;

      position[PLAYER1]++;
      position[PLAYER2]++;

    }

    PORTC &= ~(1 << PINC2);
    _delay_ms(800);
    PORTC |= 1 << PINC2;
    PORTC &= ~(1 << PINC3);
    _delay_ms(800);
    PORTC |= 1 << PINC3;
    PORTC &= ~(1 << PINC4);
    _delay_ms(400);
    PORTC |= 1 << PINC4;

    
    // set the initial states 
    PORTB |= 0xFF >> 2;  
    // set the initial states 
    PORTD |= 0xFF >> 2;  

    // start the game over
    win = 0;
    position[PLAYER1] = 0;
    position[PLAYER2] = 0;

    while( ! win ) { 

      if(clicked(PLAYER1)){
        // wipe the board
        PORTB |= 0xFF >> 2;
        // set the new position
        PORTB &= path[position[PLAYER1]];
        position[PLAYER1]++;
        if (position[PLAYER1] == goal){
          for(i = 0; i < 8; i++) flash(PLAYER1);
          win = 1;
        }
      }

      if(clicked(PLAYER2)){
        // wipe the board
        PORTD |= 0xFF >> 2;
        // set the new position
        PORTD &= path[position[PLAYER2]];
        position[PLAYER2]++;
        if (position[PLAYER2] == goal){
          for(i = 1; i < 8; i++) flash(PLAYER2);
          win = 1;
        }
      }

    }
  }

}





