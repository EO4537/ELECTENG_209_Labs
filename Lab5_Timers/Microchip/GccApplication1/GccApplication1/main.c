/*
 * GccApplication2.c
 *
 * Created: 22/09/2026 8:45:22 AM
 * Author : ethan
 */ 
#define F_CPU 2000000UL

#include "timer0.h"
#include "led.h"

#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void)
{
	DDRB = 0b11111111;
	DDRC = 0b00000000;
	DDRD = 0b00000000;
	
	timer0_init();
	sei();
	
    while (1) 
    {}
}

