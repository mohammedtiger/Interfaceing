/*
 * UART.h
 *
 *  Created on: Oct 6, 2017
 *      Author: root
 */

#ifndef INTERFACEING2_UART_UART_H_
#define INTERFACEING2_UART_UART_H_

#define FCLOCK 8000000UL
//#define UART_INTERRUPT

extern volatile unsigned char DATAA ;


void Uart_Init(unsigned long baud);
void Uart_Transmit(unsigned char data);
unsigned char Uart_Receive();

#endif /* INTERFACEING2_UART_UART_H_ */
