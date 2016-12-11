#ifndef lcdlib 
#define lcdlib

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#define MrLCDsCrib      PORTB
#define MrLCDsControl   PORTD
#define LightSwitch     5
#define ReadWrite       7
#define BiPolarMood     2
#define DataDirMrLCDControl DDRD
#define datadirMrLCDsCrib     DDRB

void initialize_lcd(void);
void check_if_mr_lcd_is_busy(void);
// allows the microcontroller to see the data that we're trying to send to it
void peek_a_boo(void);
void send_a_command(unsigned char command);
void send_a_character(unsigned char character);
void send_a_string(char * message);
void send_a_num(unsigned int num);
void go_to_lcd_position(unsigned int x, unsigned int y);

#endif


