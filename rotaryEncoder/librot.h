#ifndef librot
#define librot

#include <avr/io.h>

#define LEFT 0
#define NO_ROT 1
#define RIGHT 2

int intialize_rot(int porta, int pina, int portb, int pinb);

int rotating();

void poll();

#endif

