# AVR Practice

## Overview

This is a small project centered around learning the atmega328/P. I'm using an [ISP programmer](https://www.amazon.com/gp/product/B00TKVVWFC/ref=oh_aui_detailpage_o01_s00?ie=UTF8&psc=1) to program the chip.

## Requirements on Linux

* avrdude
* avr-gcc
* avr-libc

## Testing out your AVR connection

avrdude -c usbasp -p m328p

## Makeing a building your programs

Each of the sub directories has a make file. To build the program, simply run `make`. Then to program the atmega, run `make program` in Linux or Mac OSX . 

## Programming with the LCD 

I'm certain there's a more elegant way of doing this, but this is how I learned how to program with the LCD:

1. Remove the LCD from the circuit
2. Program the Atmega
3. Disconnect the ISP from the Atmega
4. Reconnect the LCD
5. Reconnect the ISP or another powersource


