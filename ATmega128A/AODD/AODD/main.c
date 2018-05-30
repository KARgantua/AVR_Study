/*
 * AODD.c
 *
 * Created: 2018-03-26 오후 2:49:58
 * Author : dsm2017
 */ 

#include <avr/io.h>


int main(void)
{
    /* Replace with your application code */
	unsigned char sw;
	DDRB = 0xff;
	DDRE = 0x00;
	PORTB = 0xff;
	
    while (1) 
    {
		sw = PINE & 0b00010000;
		if(sw != 0) PORTB = 0xff;
		else PORTB = 0x00;
    }
	
	return 0;
}

