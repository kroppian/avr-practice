#ifndef librot
#define librot

#include <avr/io.h>

#define LEFT 0
#define NO_ROT 1
#define RIGHT 2

#define PINSETB 0
#define PINSETC 1
#define PINSETD 2

int intialize_rot(int porta, int pina, int portb, int pinb);

int rotating(void);

void poll(void);

int get_pins(int set);

#endif

