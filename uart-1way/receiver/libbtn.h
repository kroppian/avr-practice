#ifndef libbtn
#define libbtn

#define CONFIDENCE 100

#define BTN_COUNT 1

short btn_pressed[BTN_COUNT];
short conf_level[BTN_COUNT];
short curr_conf[BTN_COUNT];

short last_state[BTN_COUNT]; 
short current_state[BTN_COUNT]; 


void btn_poll(int port, int pin_no, int button_no);
int pressed(int button_no);

#endif

