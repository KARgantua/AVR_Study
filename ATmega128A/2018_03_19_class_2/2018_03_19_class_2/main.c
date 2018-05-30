/*
 * 2018_03_19_class_2.c
 *
 * Created: 2018-03-19 오후 2:18:47
 * Author : dsm2017
 */ 

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	/*
	DDRB = 0xff;
	PORTB = 0xff;
	PORTB &= 0xa8;
     Replace with your application code */
    
		DDRB = 0xff;
		PORTB = 0x00;
		PORTB |= 0xc3;
	while (1) 
    {
    }
}

