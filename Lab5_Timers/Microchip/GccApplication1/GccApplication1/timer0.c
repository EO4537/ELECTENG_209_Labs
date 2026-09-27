/*
 * timer0.c
 *
 * Created: 22/09/2026 10:15:25 AM
 *  Author: ethan
 */ 
#include "timer0.h"
#include "led.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

volatile uint8_t cycles = 0;

ISR(TIMER0_OVF_vect) { //This ISR function is called when timer0 reaches
	//compare value, compare flag is automatically cleared
	cycles++;
	
}

ISR(INT0_vect) {
	cycles = 0;
	
	EICRA |= (1 << ISC01);
	EICRA |= (1 << ISC00);
}

void timer0_init(){
	//TCCR0A |= (1 << COM0A0);
	//TCCR0A |= (1 << WGM01);
	//TCCR0B |= (1 << CS01);
	//TCCR0B |= (1 << CS02);
	//OCR0A = 77;
	//TIMSK0 |= (1 << OCIE0A);
	
	EIMSK |= (1 << INT0);
	EICRA |= (1 << ISC01);
	EICRA |= (1 << ISC00);
}

uint8_t timer0_check_clear_compare(){
	if(TIFR0 & (1 << OCF0A)){ //TODO: check compare flag
		//TODO: clear compare flag.
		//Note: in datasheet this is done by writing 1 to the compare flag
		TIFR0 |= (1 << OCF0A);
		return 1;
	}
	return 0;
}