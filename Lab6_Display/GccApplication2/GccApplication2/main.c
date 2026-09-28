/*
 * GccApplication2.c
 *
 * Created: 28/09/2026 1:14:52 PM
 * Author : ethan
 */ 

#define F_CPU 2000000UL

#include <avr/io.h>
#include <util/delay.h>

#define SH_CP (1 << PORTC3)
#define SH_DS (1 << PORTC4)
#define SH_ST (1 << PORTC5)

void transmitDigit(uint8_t num, uint8_t place);

int digits[10] = {
	0b00111111,
	0b00000110,
	0b01011011,
	0b01001111,
	0b01100110,
	0b01101101,
	0b01111101,
	0b00000111,
	0b01111111,
	0b01101111
};

int main(void)
{
	// Initialise display
	DDRC |= (1 << DDC3);
	DDRC |= (1 << DDC4);
	DDRC |= (1 << DDC5);
	
	DDRD |= (1 << DDD4);
	DDRD |= (1 << DDD5);
	DDRD |= (1 << DDD6);
	DDRD |= (1 << DDD7);
	
	
	
	// Display 7
	
	transmitDigit(7, 3);
    /* Replace with your application code */
    while (1) 
    {
		//
		//_delay_ms(1000);
    }
}

void transmitDigit(uint8_t num, uint8_t place) {
	// Reset pins
	PORTD |= 0b11110000;
	// Set new pin
	PORTD &= ~(1 << (4 + place));
	
	PORTC &= ~SH_CP;
	PORTC &= ~SH_ST;
	
	for (int8_t i = 7; i >= 0; i--) {
		uint8_t transmitBit = digits[num] & (1 << i);
		if (transmitBit) {
			PORTC |= SH_DS;
		} else {
			PORTC &= ~SH_DS;
		}
		
		PORTC |= SH_CP;
		PORTC &= ~SH_CP;
	}
	PORTC |= SH_ST;
	PORTC &= ~SH_ST;
}