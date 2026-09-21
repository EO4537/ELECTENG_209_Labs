/*
 * timer0.c
 *
 * Created: 22/09/2026 10:15:25 AM
 *  Author: ethan
 */ 
#include "timer0.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
void timer0_init(){
	//TODO: initialise and configure timer0 to count to 10ms
}
uint8_t timer0_check_clear_compare(){
	if( 1 & (1 << 1 )){ //TODO: check compare flag
		//TODO: clear compare flag.
		//Note: in datasheet this is done by writing 1 to the compare flag
		return 1;
	}
	return 0;
}