/*
 * FND_Button_3.c
 *
 * Created: 4/16/2018 3:09:10 PM
 * Author : dsm2017
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int arr[10] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
volatile char b = 0;

ISR(INT0_vect)
{
	b = 1;
	_delay_ms(100);
}

ISR(INT1_vect)
{
	b = 2;
	_delay_ms(100);
}

int main(void)
{
    /* Replace with your application code */
    int i = 0;
	
	DDRB = 0xff;
	DDRF = 0xff;
	DDRD = 0x00;
	PORTD = 0xff;
	
	//falling
	EICRA |= 1<<INT0;
	EICRA |= 0<<INT1;
	
	EIMSK |= 1<<INT0;
	EIMSK |= 1<<INT1;
	
	sei();
	
	while (1) 
    {
		if(b == 1)
		for(i = 0; i < 8; i++){
			PORTB |= 1 << i;
			_delay_ms(500);
		}
		else if(b == 2)
		for(i = 0; i <= 9; i++){
			PORTF = arr[i];
			_delay_ms(500);
		}
		b = 0;
		PORTB = 0;
    }
	
	return 0;
}

