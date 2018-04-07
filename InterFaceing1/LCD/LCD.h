
#ifndef LCD_H_
#define LCD_H_

#include"avr/io.h"

#define LCD_E   (1<<7)
#define LCD_RW  (1<<5)
#define LCD_RS  (1<<6)

#define LCD_D4  (1<<4)
#define LCD_D5  (1<<5)
#define LCD_D6  (1<<6)
#define LCD_D7  (1<<7)

#define LCD_DDR_DATA  DDRB
#define LCD_DDR_COMD  DDRC
#define LCD_PORT_DATA PORTB
#define LCD_PORT_COMD PORTC

#define LCD_LINE0_DDRAMADDR 0x00
#define LCD_LINE1_DDRAMADDR 0x40

extern void LCDsendChar(unsigned char ch);
extern void LCDsendCommand(unsigned char cmd);
extern void LCDinit(void);
extern void LCDClear(void);
void LCDReturnHome(void);
void LCDstring(unsigned char* data, unsigned char nBytes);
void LCDshiftLeft(unsigned char n);
void LCDshiftRight(unsigned char n);
void LCDcursorOnBlink(void);
void LCDcursorOn(void);
void LCDcursorOFF(void);
void LCDOFF(void);
void LCDON(void);
void LCDGotoXY(unsigned char x, unsigned char y);
void LCD_Write_Int(unsigned long n , unsigned char nBytes);
void Write_Int(unsigned long n);
#endif
