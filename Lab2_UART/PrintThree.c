/*
 * GccApplication1.c
 *
 * Created: 7/08/2026 9:57:22 AM
 * Author : ethan
 */ 
#define F_CPU 2000000UL

#include <avr/io.h>
#include <util/delay.h>

void usart_init(uint16_t ubrr);
void usart_transmit(uint8_t data);


int main(void)
{
	usart_init(12);
	
    /* Replace with your application code */
    while (1) 
    {
		usart_transmit(51);
		_delay_ms(500);
    }
}

void usart_init(uint16_t ubrr) {
	UBRR0 = ubrr;
	UCSR0B |= (1<<TXEN0);
	UCSR0C |= (1<<UCSZ01);
	UCSR0C |= (1<<UCSZ00);
}

void usart_transmit(uint8_t data) {
	while (UCSR0A & (0<<UDRE0)) {
		_delay_ms(1);
	}
	UDR0 = data;
}