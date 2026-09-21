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

ISR(TIMER0_COMPA_vect) { //This ISR function is called when timer0 reaches
	//compare value, compare flag is automatically cleared
	led_toggle();
}

void timer0_init(){
	TCCR0A |= (1 << COM0A0);
	TCCR0A |= (1 << WGM01);
	TCCR0B |= (1 << CS02);
	OCR0A = 77;
	TIMSK0 |= (1 << OCIE0A);
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