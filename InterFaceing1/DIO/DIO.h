/*
 * DIO.h
 *
 *  Created on: Sep 2, 2017
 *      Author: root
 */

#ifndef DIO_DIO_H_
#define DIO_DIO_H_

void Init_Port(unsigned char Port , unsigned char value);
void Init_Pin(unsigned char Port ,unsigned char Pin, unsigned char value);
void Set_Port(unsigned char Port , unsigned char value);
void Clear_Pin(unsigned char Port ,unsigned char Pin);
void Toggle_Pin(unsigned char Port ,unsigned char Pin);
void Set_Pin(unsigned char Port ,unsigned char Pin);
volatile unsigned char Read_Pin(unsigned char Port ,unsigned char Pin);



#endif /* DIO_DIO_H_ */
