#include "avr/io.h"
#include "ADC_TEMP.h"

void ADCTEMP_Init()
{
	ADMUX = (1 << REFS0) | (1 << MUX0);
}




unsigned int ADCTEMP_Read()
{
	ADCTEMP_Init();
	ADCSRA = (1 << ADEN) | (1 << ADPS1) | (1 << ADPS2) | (1 << ADSC);

	while(!(ADCSRA & (1 << ADIF)));
	ADCSRA |= (1 << ADIF);

	return ADC;
}
