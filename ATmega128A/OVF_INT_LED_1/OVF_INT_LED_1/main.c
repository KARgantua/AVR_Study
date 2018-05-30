/*
 * OVF_INT_LED_1.c
 *
 * Created: 2018-03-14 오후 11:17:51
 * Author : dsm2017
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

volatile int state = 0;

ISR(TIMER1_OVF_vect)
{
	state = !state;
	if(state) PORTB = 0x01;
	else PORTB = 0x00;
}

int main(void)
{
    /* Replace with your application code */
	DDRB = 0x01;
	PORTB = 0x00;
	TCCR1B |= (1 << CS12);
	TIMSK |= (1 << TOIE1);
	sei();
    while (1) 
    {
    }
	return 0;
}

