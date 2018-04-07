#include "ADC_LDR.h"
#include "avr/io.h"

void ADCLDR_Init()
{
	ADMUX = (1 << REFS0) ;
}

unsigned int ADCLDR_Read()
{
	ADCLDR_Init();
	ADCSRA = (1 << ADEN) | (1 << ADPS1) | (1 << ADPS2) | (1 << ADSC);
	while(!(ADCSRA & (1 << ADIF)));
	ADCSRA |= (1 << ADIF);

	return ADC;
}
