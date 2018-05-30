/*
 * CycleLED4.c
 *
 * Created: 2018-03-21 오전 9:51:34
 * Author : dsm2017
 */ 
#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    int i;
	char led;
	DDRB = 0xff;
	
	while (1) 
    {
		led = 0xff;
		for(i = 0; i < 5; i++)
		{
			PORTB = led;
			led = (led << 1) & (led >> 1);
			_delay_ms(500);
		}
		for(i = 0; i < 5; i++)
		{
			led = 0xff;
			led = (led << (4 - i)) & (led >> (4 - i));
			PORTB = led;
			_delay_ms(500);
		}
	}
	
	return 0;
}

