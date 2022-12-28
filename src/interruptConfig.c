/*
 * interruptConfig.c
 *
 * Created: 28.12.2022 14:40:04
 *  Author: lenovo
 */ 
#include <stdlib.h>
#include <stdio.h>
#include "interruptConfig.h"


 void enable_interrupts()
 {
	 EIMSK |= (1<<INT0);
	 EICRA |= (1<<ISC01);
	 sei();
 }
 
 void interruptConfig()
 {
	 DDRD &= ~(1<<PIND2);	// Input
	 //PORTD &= ~(1<<PIND2);	// Low
 }