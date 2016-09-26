#ifndef button
#define button

#include <avr/io.h>

#define CONFIDENCE 500

short btn_pressed[btn_count];
short conf_level[btn_count];
short curr_conf[btn_count];

int clicked(int port, int pin_no, int button_no){

  conf_level[button_no] = CONFIDENCE;

  // If the button went from unpressed to pressed
  if(curr_conf[button_no] > conf_level[button_no] && ! btn_pressed[button_no] && bit_is_clear(port,pin_no)){
    // Mark that the button is pressed
    btn_pressed[button_no] = 1; 
    // clear the streak
    curr_conf[button_no] = 0;
    return 1;
  } else if (curr_conf[button_no] > conf_level[button_no] && ! bit_is_clear(port,pin_no)){
    btn_pressed[button_no] = 0; 
    curr_conf[button_no] = 0;
  } else {
    // We're either still holding the button down or still not holding the button down
    curr_conf[button_no]++; 
  }
  return 0;

}

#endif

