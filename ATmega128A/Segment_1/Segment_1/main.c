/*
 * Segment_1.c
 *
 * Created: 2018-04-04 오전 9:48:23
 * Author : dsm2017
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	DDRA = 0xff;
	
    while (1) 
    {
		/*
		PORTA = 0b11111001;			//1	 0xf9
		_delay_ms(1000);
		PORTA = 0b10100100;			//2  0xa4
		_delay_ms(1000);
		PORTA = 0b10110000;			//3  0xb0
		_delay_ms(1000);
		PORTA = 0b10011001;			//4  0x
		_delay_ms(1000);
		PORTA = 0b10010010;			//5
		_delay_ms(1000);
		PORTA = 0b10000010;			//6
		_delay_ms(1000);
		PORTA = 0b11111000;			//7
		_delay_ms(1000);
		PORTA = 0b10000000;			//8
		_delay_ms(1000);
		PORTA = 0b10010000;			//9
		_delay_ms(1000);
		*/
		
		PORTA = 0xc0;			//0	 0x
		_delay_ms(1000);
		PORTA = 0xf9;       	//1	 0x
		_delay_ms(1000);
		PORTA = 0xa4;			//2  0xa4
		_delay_ms(1000);
		PORTA = 0xb0;			//3  0xb0
		_delay_ms(1000);
		PORTA = 0x99;			//4  0x
		_delay_ms(1000);
		PORTA = 0x92;			//5
		_delay_ms(1000);
		PORTA = 0x82;			//6
		_delay_ms(1000);
		PORTA = 0xf8;			//7
		_delay_ms(1000);
		PORTA = 0x80;			//8
		_delay_ms(1000);
		PORTA = 0x90;			//9
		_delay_ms(1000);
    }
}

