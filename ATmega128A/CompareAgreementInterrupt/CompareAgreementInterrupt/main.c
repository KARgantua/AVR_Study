/*
 * CompareAgreementInterrupt.c
 *
 * Created: 2018-03-15 오후 10:37:53
 * Author : dsm2017
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

int state = 0;

ISR(TIMER1_COMPA_vect){
	state = !state;
	if(state) PORTB = 0xFF;
	else PORTB = 0x00;
	
	TCNT1 = 0;
}

int main(void)
{
    /* Replace with your application code */
	DDRB = 0xFF;
	PORTB = 0x00;
	
	OCR1A = 0x7FFF;
	
	TCCR1B |= (1 << CS12);
	
	TIMSK |= (1 << OCIE1A);
	
	sei();
    while (1) 
    {
    }
	
	return 0;
}

