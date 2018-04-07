#include "avr/io.h"
#include "SEVENSEG.h"
#include "../DIO/DIO.h"

void SevenSeg_Init()
{
	Init_Port('C' , 0x3C);
	Init_Port('B' , 0x0F);
}

void SevenSeg_Enable(unsigned char value , unsigned char pin)
{
	Set_Port ( 'C' ,( 1 << pin ));
	Set_Port ( 'B' , value);
}
















void SevenSeg_Disable_1()
{
	Set_Port ( 'C' ,( 0 << 2 ));
}
void SevenSeg_Disable_2()
{
	Set_Port ( 'C' ,( 0 << 3 ));
}
