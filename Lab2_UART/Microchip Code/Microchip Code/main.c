/*
 * GccApplication1.c
 *
 * Created: 7/08/2026 9:57:22 AM
 * Author : ethan
 */ 
#define F_CPU 2000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

void usart_init(uint16_t ubrr);
void usart_transmit(uint8_t data);
uint16_t* generate_primes();
void print_num(uint16_t num);


int main(void)
{
	usart_init(12);
	
	uint16_t* primes = generate_primes();
	
    /* Replace with your application code */
	uint16_t i = 0;
    while (1) 
    {
		if (primes[i] != 0) {
			print_num(primes[i]);
			usart_transmit(44);
			usart_transmit(32);
			i++;
		}
    }
	
}

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

uint16_t* generate_primes() {
	uint16_t* primeList = (uint16_t*)malloc(62 * sizeof(uint16_t));
	uint8_t index = 0;
	for (uint16_t i = 2; i < 300; i++) {
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
	}
	return primeList;
}

void usart_init(uint16_t ubrr) {
	UBRR0 = ubrr;
	UCSR0B |= (1<<TXEN0);
	UCSR0C |= (1<<UCSZ01);
	UCSR0C |= (1<<UCSZ00);
}

void usart_transmit(uint8_t data) {
	while (!(UCSR0A & (1<<UDRE0))) {
		_delay_ms(1);
	}
	UDR0 = data;
}