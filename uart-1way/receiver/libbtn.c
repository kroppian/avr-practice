#include <avr/interrupt.h>  
#include "libbtn.h"

void btn_poll(int port, int pin_no, int button_no){

  conf_level[button_no] = CONFIDENCE;

  last_state[button_no] = current_state[button_no];
  current_state[button_no] = bit_is_clear(port,pin_no);

  // if we're confident enough that an event is actually happening
  if(curr_conf[button_no] > conf_level[button_no]){
  
    curr_conf[button_no]++; 

    // If the button went from unpressed to pressed
    if(current_state[button_no])
      btn_pressed[button_no] = 1; 
    else 
      btn_pressed[button_no] = 0; 
       
  }else if(last_state[button_no] == current_state[button_no]){
    curr_conf[button_no]++; 
  }else{
    curr_conf[button_no] = 0;
  }

}

int pressed(int button_no){

  return btn_pressed[button_no];

}


