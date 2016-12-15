#ifndef librot
#define librot

#include <avr/io.h>

int intialize_rot(int porta, int pina, int portb, int pinb);

int rotating();

void poll();

#endif

