#include "avr/io.h"
#include "avr/interrupt.h"
#include "UART.h"

void (*Uart_Func)(void);

volatile unsigned char DATAA = 0;


void Uart_RxInterrupt(unsigned char *data)
{
	*data = UDR;
}

void Uart_CallBackFunc(void (*Func)(void))
{
	Uart_Func = Func;
}
void Uart_Init(unsigned long baud)
{
	unsigned int data = 0;

	data = 8;

	UBRRH = (unsigned char)(data >> 8);
	UBRRL = (unsigned char)(data);

	UCSRB = (1 << RXEN) | (1 << TXEN);

#ifdef UART_INTERRUPT
	UCSRB |= (1 << RXCIE);
	//Uart_CallBackFunc((void(*)(void))Uart_RxInterrupt);
#endif

	UCSRC = (1 << UCSZ1) | (1 << UCSZ0) | (1 << URSEL);
}

void Uart_Transmit(unsigned char data)
{
	while(!(UCSRA & (1 << UDRE)));
	UDR = data;
}

unsigned char Uart_Receive()
{
	while(!(UCSRA &(1 << RXC)));
	return UDR;
}



#ifdef UART_INTERRUPT

ISR(USART_RXC_vect)
{
	//Uart_Func();
	DATAA = UDR;
}
#endif

