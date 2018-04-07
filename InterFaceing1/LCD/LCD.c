#include "LCD.h"
#include"util/delay.h"
#include <stdlib.h>

void LCDsendChar(unsigned char data)
{
	LCD_PORT_DATA = ( data & 0b11110000 );
	LCD_PORT_COMD |= LCD_RS;
	LCD_PORT_COMD |= LCD_E;
	_delay_ms(3);
	LCD_PORT_COMD &=~ (LCD_E);
	LCD_PORT_COMD &=~ (LCD_RS);
	_delay_ms(3);
	LCD_PORT_DATA = ( ( data & 0b00001111 ) << 4 );
	LCD_PORT_COMD |= LCD_RS;
	LCD_PORT_COMD |= LCD_E;
	_delay_ms(3);
	LCD_PORT_COMD&=~(LCD_E);
	LCD_PORT_COMD&=~(LCD_RS);
	_delay_ms(3);
}

void LCDsendCommand(unsigned char cmd)
{

	LCD_PORT_DATA = ( cmd & 0b11110000 );
	LCD_PORT_COMD |= LCD_E;
	_delay_ms(3);
	LCD_PORT_COMD &=~ (LCD_E);
	_delay_ms(3);
	LCD_PORT_DATA = ( ( cmd & 0b00001111 ) << 4 );
	LCD_PORT_COMD |= LCD_E;
	_delay_ms(3);
	LCD_PORT_COMD &=~ (LCD_E);
	_delay_ms(3);
}

void LCDinit(void)
{
	_delay_ms(50);

	LCD_DDR_DATA |= LCD_D7 | LCD_D6 | LCD_D5 | LCD_D4;
	LCD_DDR_COMD |= LCD_E  | LCD_RW | LCD_RS;

//	//---------------
	LCD_PORT_DATA = 0b00100000; //4 bit mode
	LCD_PORT_COMD |= LCD_E;
	_delay_ms(3);
	LCD_PORT_COMD &=~ (LCD_E);
	_delay_ms(3);

	LCDsendCommand(0b00101000);
	LCDsendCommand(0b00001110);
}
void LCDClear(void)
{
	LCDsendCommand(0b00000001);
}
void LCDReturnHome(void)
{
	LCDsendCommand(0b00000010);
}
void LCDshiftLeft(unsigned char n)
{
	for (uint8_t i=0;i<n;i++)
	{
		LCDsendCommand(0b00011000);
	}
}
void LCDshiftRight(unsigned char n)
{
	for (uint8_t i=0;i<n;i++)
	{
		LCDsendCommand(0b00011100);
	}
}
void LCDcursorOn(void)
{
	LCDsendCommand(0b00001110);
}
void LCDcursorOnBlink(void)
{
	LCDsendCommand(0b00001111);
}
void LCDcursorOFF(void)
{
	LCDsendCommand(0b00001100);
}

void LCDOFF(void)
{
	LCDsendCommand(0b00001000);
}

void LCDcursorLeft(unsigned char n)
{
	for (uint8_t i=0;i<n;i++)
	{
		LCDsendCommand(0b00010000);
	}
}
void LCDcursorRight(unsigned char n)
{
	for (uint8_t i=0;i<n;i++)
	{
		LCDsendCommand(0b00010100);
	}
}






void LCD_Write_Int(unsigned long n , unsigned char nBytes)
{
	unsigned char Arr[16] = {0};

	itoa(n , Arr , 10);

	LCDstring(Arr , nBytes);

}


void Write_Int(unsigned long n)
{	int i = 0;
	int Arr[16] = {0};
	while(n != 0)
	{
		i++;
		Arr[i]=(n%10);
		n=n/10;
	}
	for(int count = 0 ; count < i ; count ++ )
	{
	LCDsendChar(Arr[i-count] + '0');
	}
}





void LCDstring(unsigned char* data, unsigned char nBytes)
{
	uint8_t i;

	// check to make sure we have a good pointer
//	if (!data) return;

	// print data
	for(i = 0;  i < nBytes ; i++)
	{
		LCDsendChar(data[i]);
	}
}

void LCDGotoXY(unsigned char x, unsigned char y)
{
	uint8_t DDRAMAddr;
	switch(y)
	{
	case 1: DDRAMAddr = LCD_LINE0_DDRAMADDR + x; break;
	case 2: DDRAMAddr = LCD_LINE1_DDRAMADDR + x; break;
	default: DDRAMAddr = LCD_LINE0_DDRAMADDR+x;
	}
	// set data address
	LCDsendCommand((1 << 7) | DDRAMAddr);

}

