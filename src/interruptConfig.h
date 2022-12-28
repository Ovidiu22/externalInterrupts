/*
 * interruptConfig.h
 *
 * Created: 28.12.2022 14:39:46
 *  Author: lenovo
 */ 


#ifndef INTERRUPTCONFIG_H_
#define INTERRUPTCONFIG_H_

#define F_CPU 16000000ul
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>



 void interruptConfig(void);
 void enable_interrupts(void);
 




#endif /* INTERRUPTCONFIG_H_ */