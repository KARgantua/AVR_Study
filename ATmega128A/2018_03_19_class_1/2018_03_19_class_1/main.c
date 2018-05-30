/*
 * 2018_03_19_class_1.c
 *
 * Created: 2018-03-19 오후 1:47:59
 * Author : dsm2017
 */ 
#define F_CPU 16000000L
#define DELAY 500
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	int i;
	DDRB = 0xff;
	
	while(1)
	{
		/*for(i = 0; i < 8; i++)
		{
			PORTB = 1 << i;
			_delay_ms(DELAY);
		}
		for(i = 8; i > 0; i--)
		{
			PORTB = 1 << i;
			_delay_ms(DELAY);
		}
		for(i = 0; i < 8; i++)
		{
			PORTB = 1 << i;
			_delay_ms(DELAY);
		}
		for(i = 8; i > 0; i--)
		{
			PORTB = 1 << i;
			_delay_ms(DELAY);
		}
		for(i = 0; i < 4; i++)
		{
			PORTB = 0xaa;
			_delay_ms(DELAY);
			PORTB = 0x55;
			_delay_ms(DELAY);
		}
		*/
		for(i = 0; i < 4; i++)
		{
			PORTB = 0b00001111;
			_delay_ms(DELAY);
			PORTB = 0b11110000;
			_delay_ms(DELAY);
		}
	}
	
	return 0;
}

