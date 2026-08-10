/*
 * GccApplication1.c
 *
 * Created: 7/08/2026 9:57:22 AM
 * Author : ethan
 */ 
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#include "uart.h"

void usart_init(uint16_t ubrr);
void usart_transmit(uint8_t data);
uint16_t* generate_primes();
void print_num(uint16_t num);


int main(void)
{
	uint16_t NUM_PRIMES = 62;
	usart_init(12);
	
	uint16_t* primes = generate_primes(NUM_PRIMES);
	
	for (uint16_t i = 0; i < NUM_PRIMES; i++) {
		print_num(primes[i]);
		usart_transmit(44);
		usart_transmit(32);
	}
	
    /* Replace with your application code */
    while (1) 
    {
	}
	
}

