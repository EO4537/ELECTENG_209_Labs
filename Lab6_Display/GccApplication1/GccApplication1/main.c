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
#include <stdbool.h>

void transmitNumber(uint8_t num, bool digit1);

volatile uint8_t counter;
volatile bool digit1;
volatile uint8_t cycles;

ISR(PCINT0_vect) {
	counter = 0;
}

ISR (TIMER0_COMPA_vect) {
	transmitNumber(counter, digit1);
	digit1 = !digit1;
	cycles++;
	if (cycles == 100) {
		cycles = 0;
		counter++;
		if (counter == 100) {
			counter = 0;
		}
	}
}

int main(void)
{
	cycles = 0;
	counter = 0;
	digit1 = true;
	
	// Push button
	DDRB &= ~(1 << PORTB7);
	
	// Common cathodes
	DDRB |= (1 << PORTB0);
	DDRB |= (1 << PORTB1);
	
	// Anodes
	DDRC = 0b11111111;
	DDRB |= (1 << PORTB4);
	
	// Setup ds1/2
	DDRB |= (1 << PORTB0);
	DDRB |= (1 << PORTB1);
	
	// Timer setup
	TCCR0A |= (1 << COM0A0);
	TCCR0A |= (1 << WGM01);
	
	// Set to reset every ~10ms
	TCCR0B |= (1 << CS02);
	OCR0A |= 77;
	
	// Interrupts
	PCICR |= (1 << PCIE0);
	PCMSK0 |= (1 << PCINT7);
	
	TIMSK0 |= (1 << OCIE0A);
	sei();
	
    /* Replace with your application code */
    while (1) 
    {
    }
}

void transmitNumber(uint8_t num, bool digit1) {
	PORTB |= (1 << PORTB1);
	PORTB |= (1 << PORTB0);
	
	uint8_t digitToTransmit;
	if (digit1) {
		digitToTransmit = num / 10;
	} else {
		digitToTransmit = num % 10;
	}
	switch (digitToTransmit) {
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
	if (digit1) {
		PORTB &= ~(1 << PORTB0);
		} else {
		PORTB &= ~(1 << PORTB1);
	}
}