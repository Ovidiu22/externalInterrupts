/*******************************/
/*** Created by Ovidiu Sabau ***/
/***  28th December 2022	 ***/
/*******************************/


#include "interruptConfig.h"

void blink_LED_PORTD(uint8_t, uint8_t);
volatile int toggle = 0;


int main(void)
{
	/* Initialization */
	interruptConfig();
	enable_interrupts();
	
	while(1)
	{
		if (toggle == 1)
		{
			blink_LED_PORTD(PIND7, 3);
			toggle = 0;
		}
	}
	
	return 0;
}

/* *****************************************************************
Name:		Interrupt service routine 0
Inputs:		none
Outputs:	none
Description:sets toggle = 1 when an external interrupt on pin PIND2 occurs
******************************************************************** */
ISR(INT0_vect)
{
	toggle = 1;
	_delay_ms(50);	// prevent pin toggling due to imperfect switching
}

/* *****************************************************************
Name:		blink_LED_PORTD()
Inputs:		pin number of the LED and how many times LED should blink
Outputs:	none
Description:blinks a LED a defined number of times
******************************************************************** */
void blink_LED_PORTD(uint8_t pinNumber, uint8_t times)
{
	DDRD |= (1 << pinNumber);
	for (uint8_t i = 0; i < times; i++)
	{
		PORTD |= ( 1 << pinNumber );
		_delay_ms(100);
		PORTD &= ~( 1 << pinNumber );
		_delay_ms(100);
	}
}