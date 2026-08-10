/*
 * primes.c
 *
 * Created: 10/08/2026 3:05:03 PM
 *  Author: ethan
 */ 
#include "primes.h"
#include "uart.h"

void print_num(uint16_t num) {
	uint8_t hundred = num/100 + 48;
	num = num % 100;
	uint8_t ten = num/10 + 48;
	num = num % 10;
	uint8_t one = num + 48;
	
	usart_transmit(hundred);
	usart_transmit(ten);
	usart_transmit(one);
}

uint16_t* generate_primes(uint16_t numPrimes) {
	uint16_t* primeList = (uint16_t*) malloc(numPrimes * sizeof(uint16_t));
	uint8_t index = 0;
	for (uint16_t i = 2; true; i++) {
		bool isPrime = true;
		for (uint16_t j = 2; j < i; j++) {
			if (i%j == 0) {
				isPrime = false;
			}
		}
		if (isPrime) {
			primeList[index] = i;
			index++;
		}
		if (index == numPrimes) {
			return primeList;
		}
	}
}