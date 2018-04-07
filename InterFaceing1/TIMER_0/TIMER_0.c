
#include "avr/io.h"
#include "avr/interrupt.h"
#include "TIMER_0.h"


void Timer_0_Init()
{
	sei();
	TCCR0 = (1 << CS01) | (1 << CS00) ;
	TIMSK |= (1 << TOIE0);
	TIFR |= (1 << TOV0);
}



