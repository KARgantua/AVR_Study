/*
 * AOCC.c
 *
 * Created: 2018-03-26 오후 3:05:56
 * Author : dsm2017
 */ 

#include <avr/io.h>


int main(void)
{
	unsigned char sw1, sw2, sw3, sw4;
	DDRB = 0xff;
	DDRE = 0x00;
	PORTE = 0xf0;
	
    /* Replace with your application code */
    while (1) 
    {
		sw1 = PINE & 0b00010000;
		sw2 = PINE & 0b00100000;
		sw3 = PINE & 0b01000000;
		sw4 = PINE & 0b10000000;
		if(sw1 == 0) PORTB = 0xff;
		else if(sw2 == 0) PORTB = 0x00;
		else if(sw3 == 0) PORTB = 0x55;
		else if(sw4 == 0) PORTB = 0xaa;
    }
	
	return 0;
}

