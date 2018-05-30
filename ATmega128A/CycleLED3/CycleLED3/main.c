/*
 * CycleLED3.c
 *
 * Created: 2018-03-21 오전 9:36:28
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
		led = 0xfe;
		for(i = 0; i < 8; i++){
			PORTB = led;
			led = led << 1 | 1;
			_delay_ms(500);
			 
		}
		for(i = 0; i < 8; i++){
			PORTB = led;
			led = led >> 1 | 1;
			_delay_ms(500);
			
		}
    }
	
	return 0;
}

