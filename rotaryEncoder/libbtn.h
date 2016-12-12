#ifndef button
#define button

#include <avr/io.h>


short btn_pressed[BTN_COUNT];
short conf_level[BTN_COUNT];
short curr_conf[BTN_COUNT];

int pressed(int port, int pin_no, int button_no);


#endif

