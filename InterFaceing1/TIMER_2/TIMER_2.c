
#include "avr/io.h"
#include "avr/interrupt.h"
#include "TIMER_2.h"

volatile int counter = 0;

void Timer_2_Init()
{
	sei();
	OCR2 = 125;
	TCNT2 = 0;
	TCCR2 = (1 << CS22) | (1 << WGM21);
	TIMSK |= (1 << OCIE2);
	TIFR |= (1 << OCF2);
}


ISR(TIMER2_COMP_vect)
{
	counter++;
}
