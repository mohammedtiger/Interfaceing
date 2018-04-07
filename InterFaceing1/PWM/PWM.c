#include "avr/io.h"
#include "PWM.h"

void PWM_Init()
{
	TCCR1A = (1 << WGM10) | ( 1 << COM1A1)| ( 1 << COM1B1);
	TCCR1B =  (1 << WGM12) | (1 << CS11) | (1 << CS10);
}

void PWM_1(unsigned char value)
{
	OCR1AL = value;
}

void PWM_2(unsigned char value)
{
	OCR1BL = value;
}
