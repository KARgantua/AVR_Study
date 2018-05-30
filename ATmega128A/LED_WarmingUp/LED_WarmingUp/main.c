/*
 * LED_WarmingUp.c
 *
 * Created: 2018-03-12 오후 2:19:16
 * Author : dsm2017
 */ 
#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
    DDRB = 0xff;
	int i;
	while (1) 
    {
         for(i = 0; i < 4; i++){
			 PORTB = 1 << i;
			 _delay_us(2200);
		 }
		 for(i = 0; i < 4; i++){
			 PORTB = 8 >> i;
			 _delay_us(2200);
		 }
    }
	
	return 0;
}

