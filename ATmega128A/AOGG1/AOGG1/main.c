/*
 * AOGG1.c
 *
 * Created: 2018-03-26 오후 1:48:13
 * Author : dsm2017
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRB = 0xff;
	int i;
	char led;
    
	while (1) 
    {
		led = 0x00;
		
		for(i = 0; i < 5; i++)
		{
			PORTB = ~led;
			led = ( (0x01 << i) | (0x80 >> i) );
			_delay_ms(500);
		}
    }
	
	return 0;
}

