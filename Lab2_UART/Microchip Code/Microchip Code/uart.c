#include "uart.h"
#include <avr/io.h>

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