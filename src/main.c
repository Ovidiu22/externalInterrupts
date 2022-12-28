/*******************************/
/*** Created by Ovidiu Sabau ***/
/***  28th December 2022	 ***/
/*******************************/


#include "interruptConfig.h"

void blink_LED_PORTD(uint8_t, uint8_t);

volatile int toggle = 0;

int main(void)
{
	interruptConfig();
	enable_interrupts();
	
	while(1)
	{
		if (toggle == 1)
		{
			blink_LED_PORTD(PIND7, 2);
			toggle = 0;
		}
	}
}


ISR(INT0_vect)
{
	toggle = 1;
}


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