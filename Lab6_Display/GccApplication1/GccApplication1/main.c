/*
 * GccApplication1.c
 *
 * Created: 27/09/2026 2:58:35 pm
 * Author : Ethan O'Meara
 */ 

#define F_CPU 2000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdint.h>

void transmitNumber(uint8_t num);

volatile uint8_t counter;

ISR(PCINT0_vect) {
	counter = 0;
}

int main(void)
{
	// Push button
	DDRB &= ~(1 << PORTB7);
	
	// Common cathodes
	DDRB |= (1 << PORTB0);
	DDRB |= (1 << PORTB1);
	
	// Anodes
	DDRC = 0b11111111;
	DDRB |= (1 << PORTB4);
	
	// Setup ds1/2
	PORTB |= (1 << PORTB0);
	PORTB &= ~(1 << PORTB1);
	
	// Interrupts
	PCICR |= (1 << PCIE0);
	PCMSK0 |= (1 << PCINT7);
	sei();
	
	counter = 0;
    /* Replace with your application code */
    while (1) 
    {
		transmitNumber(counter);
		counter++;
		if (counter == 10) {counter = 0;}
		_delay_ms(1000);
    }
}

void transmitNumber(uint8_t num) {
	switch (num) {
		case 0:
			PORTC = 0b00111111;
			PORTB &= ~(1 << PORTB4);
			break;
		case 1:
			PORTC = 0b00000110;
			PORTB &= ~(1 << PORTB4);
			break;
		case 2:
			PORTC = 0b01011011;
			PORTB |= (1 << PORTB4);
			break;
		case 3:
			PORTC = 0b01001111;
			PORTB |= (1 << PORTB4);
			break;
		case 4:
			PORTC = 0b01100110;
			PORTB |= (1 << PORTB4);
			break;
		case 5:
			PORTC = 0b01101101;
			PORTB |= (1 << PORTB4);
			break;
		case 6:
			PORTC = 0b01111101;
			PORTB |= (1 << PORTB4);
			break;
		case 7:
			PORTC = 0b00000111;
			PORTB &= ~(1 << PORTB4);
			break;
		case 8:
			PORTC = 0b01111111;
			PORTB |= (1 << PORTB4);
			break;
		case 9:
			PORTC = 0b01101111;
			PORTB |= (1 << PORTB4);
			break;
		default:
			PORTB |= (1 << PORTB4);
			break;
	}
}