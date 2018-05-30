/*
 * FND_2.c
 *
 * Created: 2018-04-04 오전 10:47:58
 * Author : dsm2017
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	int arr[10] = {0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90, 0xc0};
	int i;
	
	DDRA = 0xff;
	
    while (1) 
    {
		for(i = 0; i <= 9; i++)
		{
			PORTA = arr[i];
			_delay_ms(500);
		}
		for(i = 8; i >= 0; i--)
		{
			PORTA = arr[i];
			_delay_ms(500);
		}
    }
	
	return 0;
}

