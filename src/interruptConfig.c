/*******************************/
/*** Created by Ovidiu Sabau ***/
/***  28th December 2022	 ***/
/*******************************/

#include <stdlib.h>
#include <stdio.h>
#include "interruptConfig.h"

 /* *****************************************************************
 Name:		enable_interrupts()
 Inputs:	none
 Outputs:	none
 Description:enables interrupt INT0 (pin D2 and sets falling condition for firing) 
 ******************************************************************** */
 void enable_interrupts()
 {
	 EIMSK |= (1<<INT0);
	 EICRA |= (1<<ISC01);
	 sei();
 }
 
 /* *****************************************************************
 Name:		interruptConfig()
 Inputs:	none
 Outputs:	none
 Description:sets PIND2 as input 
 ******************************************************************** */
 void interruptConfig()
 {
	 DDRD &= ~(1<<PIND2);	// Input
 }