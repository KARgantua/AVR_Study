#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile int a = 0;
int arr[10] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};

ISR(INT0_vect)
{
	a = 1;
	_delay_ms(100);
}

ISR(INT1_vect)
{
	a = 2;
	_delay_ms(100);
}

int main(void)
{
	int i;
	/* Replace with your application code */
	DDRF = 0xff;
	DDRD = 0xff;
	PORTD = 0xff;
	EICRA = (1 << INT0);
	EICRA = (1 << INT1);
	
	EIMSK |= 1<<INT0;
	EIMSK |= 1<<INT1;
	
	sei();
	
	a = 0;
	PORTF = arr[0];
	while (1)
	{
		if(a == 1)
			for(i = 0; i <= 9; i++){
				PORTF = arr[i];
				_delay_ms(500);
				}
		else if(a == 2)
			for(i = 9; i >= 0; i--){
				PORTF = arr[i];
				_delay_ms(500);
			}
		a = 0;
		
	}
	
	return 0;
}

