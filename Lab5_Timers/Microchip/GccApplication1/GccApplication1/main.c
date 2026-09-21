/*
 * GccApplication2.c
 *
 * Created: 22/09/2026 8:45:22 AM
 * Author : ethan
 */ 
#define F_CPU 2000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB = 0b11111111;
	DDRC = 0b00000000;
	DDRD = 0b00000000;
    /* Replace with your application code */
    while (1) 
    {
		PORTB |= (1<<PORTB5);
		_delay_ms(375);
		PORTB &= !(1<<PORTB5);
		_delay_ms(125);
    }
}

