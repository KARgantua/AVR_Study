﻿/*
 * UART1.c
 *
 * Created: 2018-03-21 오후 5:00:54
 *  Author: dsm2017
 */ 
#include <avr/io.h>

void UART1_init(void)
{
	UBRR1H = 0x00;
	UBRR1L = 207;
	
	UCSR1A |= (1 << U2X1);
	
	UCSR1C |= 0x06;
	
	UCSR1B |= (1 << RXEN1);
	UCSR1B |= (1 << TXEN1);
}

void UART1_transmit(char data)
{
	while( !(UCSR1A & (1 << UDRE1)) );
	UDR1 = data;
}

unsigned char UART1_receive(void)
{
	while( !(UCSR1A & (1 << RXC1)) );
	return UDR1;
}

void UART1_print_string(char *str)
{
	for(int i = 0; str[i]; i++)
		UART1_transmit(str[i]);
}

void UART1_print_1_byte_number(uint8_t n)
{
	char numString[4] = "0";
	int i, index = 0;
	
	if(n > 0){
		for(i = 0; n != 0 ; i++)
		{
			numString[i] = n % 10 + '0';
			n = n / 10;
		}
		numString[i] = '\0';
		index = i - 1;
	}
	
	for(i = index; i >= 0; i++)
		UART1_transmit(numString[i]);
}