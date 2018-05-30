/*
 * HaveDifferentCycleEachOther.c
 *
 * Created: 2018-03-15 오후 10:44:30
 * Author : dsm2017
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

int state0 = 0, state1 = 0, state2 =0;

ISR(TIMER1_COMPA_vect)
{
	state2 = !state2;
	if(state2) PORTB |= 0x04;
}

int main(void)
{
    /* Replace with your application code */

    while (1) 
    {
    }
}

