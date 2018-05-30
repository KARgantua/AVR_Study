/*
 * FND_2.c
 *
 * Created: 2018-04-04 ¿ÀÀü 10:47:58
 * Author : dsm2017
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	int arr[10] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
	int i,j;
	
	DDRA = 0xff;
	DDRF = 0xff;
	
    while (1) 
    {
		for(i = 0; i < 10; i++)
		{
			PORTF = arr[i];
			for(j = 0; j < 10; j++)
			{
				PORTA = arr[j];
				_delay_ms(500);
			}
		}
    }
	
	return 0;
}

