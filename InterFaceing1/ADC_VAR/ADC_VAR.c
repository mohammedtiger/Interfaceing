#include "avr/io.h"
#include "ADC_VAR.h"


void ADCVAR_Init()
{

	ADMUX = (1 << REFS0) | ( 1 << MUX2) | (1 <<MUX0);
}


unsigned int ADCVAR_Read()
{
	ADCSRA = (1 << ADEN) | (1 << ADPS1) | (1 << ADPS2) | (1 << ADSC);
	while(!(ADCSRA & (1 << ADIF)));
	ADCSRA |= (1 << ADIF);

	return ADC;
}

























int ADC_Read()
{
	ADCSRA = (1 << ADEN) | (1 << ADSC) | (1 << ADPS2) | (1 << ADPS1);
	while(!(ADCSRA & (1<<ADIF)));
	ADCSRA |= (1 << ADIF);
	return ADC;
}
