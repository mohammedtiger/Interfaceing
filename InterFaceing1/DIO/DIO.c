#include "avr/io.h"
#include "DIO.h"






void Init_Port(unsigned char Port , unsigned char value)
{
	switch(Port)
	{
	case 'A':
	case 'a':
		DDRA = value;
		break;
	case 'B':
	case 'b':
		DDRB = value;
		break;
	case 'C':
	case 'c':
		DDRC = value;
		break;
	case 'D':
	case 'd':
		DDRD = value;
		break;
	}
}












void Init_Pin(unsigned char Port ,unsigned char Pin, unsigned char value)
{
	switch(Port)
	{
	case 'A':
	case 'a':
		DDRA = (value << Pin);
		break;
	case 'B':
	case 'b':
		DDRB = (value << Pin);
		break;
	case 'C':
	case 'c':
		DDRC = (value << Pin);
		break;
	case 'D':
	case 'd':
		DDRD = (value << Pin);
		break;
	}
}




void Set_Port(unsigned char Port , unsigned char value)
{
	switch(Port)
	{
	case 'A':
	case 'a':
		PORTA = value;
		break;
	case 'B':
	case 'b':
		PORTB = value;
		break;
	case 'C':
	case 'c':
		PORTC = value;
		break;
	case 'D':
	case 'd':
		PORTD = value;
		break;
	}
}



void Set_Pin(unsigned char Port ,unsigned char Pin)
{
	switch(Port)
	{
	case 'A':
	case 'a':
		PORTA |= (1 << Pin);
		break;
	case 'B':
	case 'b':
		PORTB |= (1 << Pin);
		break;
	case 'C':
	case 'c':
		PORTC |= (1 << Pin);
		break;
	case 'D':
	case 'd':
		PORTD |= (1 << Pin);
		break;
	}
}



void Clear_Pin(unsigned char Port ,unsigned char Pin)
{
	switch(Port)
	{
	case 'A':
	case 'a':
		PORTA &= ~(1 << Pin);
		break;
	case 'B':
	case 'b':
		PORTB &= ~(1 << Pin);
		break;
	case 'C':
	case 'c':
		PORTC &= ~(1 << Pin);
		break;
	case 'D':
	case 'd':
		PORTD &= ~(1 << Pin);
		break;
	}
}





void Toggle_Pin(unsigned char Port ,unsigned char Pin)
{
	switch(Port)
	{
	case 'A':
	case 'a':
		PORTA ^= (1 << Pin);
		break;
	case 'B':
	case 'b':
		PORTB ^= (1 << Pin);
		break;
	case 'C':
	case 'c':
		PORTC ^= (1 << Pin);
		break;
	case 'D':
	case 'd':
		PORTD ^= (1 << Pin);
		break;
	}
}





volatile unsigned char Read_Pin(unsigned char Port ,unsigned char Pin   )
{
	volatile unsigned char value;
	switch(Port)
	{
	case 'A':
	case 'a':
		value = PINA & (1 << Pin);
		break;
	case 'B':
	case 'b':
		value = PINB & (1 << Pin);
		break;
	case 'C':
	case 'c':
		value = PINC & (1 << Pin);
		break;
	case 'D':
	case 'd':
		value = PIND & (1 << Pin);
		break;
	}
	return value;
}
