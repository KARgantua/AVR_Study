#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile int count = 0;
int arr[10] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};

ISR(INT0_vect)
{
	
	count++;
	if(count == 10)
		count = 0;
	PORTF = arr[count];
	_delay_ms(100);
	
}

ISR(INT1_vect)
{
	
	count--;
	if(count == -1)
		count = 9;
	PORTF = arr[count];
	_delay_ms(100);
	
}

int main(void)
{
    /* Replace with your application code */
	DDRF = 0xff;
	DDRD = 0xff;
	PORTD = 0xff;
	EICRA  = (1<<ISC00);
	EICRA  = (1<<ISC01);
	
	EIMSK |= 1<<INT0;
	EIMSK |= 1<<INT1;
	
	sei();
	
    while (1) 
    {
    }
	
	return 0;
}

