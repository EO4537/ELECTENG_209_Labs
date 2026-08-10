#ifndef UART_H
#define UART_H

#define F_CPU 2000000UL

#include <avr/io.h>
#include <util/delay.h>

void usart_init(uint16_t ubrr);
void usart_transmit(uint8_t data);

#endif