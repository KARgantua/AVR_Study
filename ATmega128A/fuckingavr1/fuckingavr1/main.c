/*
 * fuckingavr1.c
 *
 * Created: 2018-03-21 오전 9:05:49
 * Author : dsm2017
 */ 

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	int i, led;
	DDRB = 0xff;
	while (1)
	{
		led = 0xff;
		for(i = 0; i < 9; i++){
			PORTB = led;
			_delay_ms(500);
			led = led << 1;
		}
		
		return 0;
	}


