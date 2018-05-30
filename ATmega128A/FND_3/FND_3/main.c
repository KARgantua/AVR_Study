/*
 * FND_3.c
 *
 * Created: 2018-04-04 오전 11:00:28
 * Author : dsm2017
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	int arr[10] = {0b10001000, 0b10000011, 0b11000110, 0b10100001, 
		0b10000110,0b10001110, 0b10001001, 0b11000111, 0b11000000 ,0b10001100};
	int i;
	
	DDRA = 0xff;
	
    while (1) 
    {
		for(i = 0; i < 10; i++){
			PORTA = arr[i];
			_delay_ms(1000);
		}
    }
	
	return 0;
}

