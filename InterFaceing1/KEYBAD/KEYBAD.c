#include "../DIO/DIO.h"
#include "KEYBAD.h"

void Key_init()
{
	Init_Port('A',0xE0);
	Set_Port('A',0x1C);
}





unsigned char Key_Write_1()
{
	unsigned char KeyPressed = 0;
	Set_Pin('A' , 5);
	Set_Pin('A' , 6);
	Clear_Pin('A' , 7);

	if(0 == Read_Pin('A' , 2 )){
		KeyPressed = 1;
	}else if(0 == Read_Pin('A' , 3 )){
		KeyPressed = 4;
	}else if(0 == Read_Pin('A' , 4 )){
		KeyPressed = 7;
	}
	else
	{
		KeyPressed = 0;
	}
	return KeyPressed;
}









unsigned char Key_Write_2()
{
	unsigned char KeyPressed = 0;
	Set_Pin('A' , 5);
	Clear_Pin('A' , 6);
	Set_Pin('A' , 7);

	if(0 == Read_Pin('A' , 2 )){
		KeyPressed = 2;
	}else if(0 == Read_Pin('A' , 3 )){
		KeyPressed = 5;
	}else if(0 == Read_Pin('A' , 4 )){
		KeyPressed = 8;
	}
	else
	{
		KeyPressed = 0;
	}
	return KeyPressed;
}
unsigned char Key_Write_3()
{
	unsigned char KeyPressed = 0;
	Clear_Pin('A' , 5);
	Set_Pin('A' , 6);
	Set_Pin('A' , 7);

	if(0 == Read_Pin('A' , 2 )){
		KeyPressed = 3;
	}else if(0 == Read_Pin('A' , 3 )){
		KeyPressed = 6;
	}else if(0 == Read_Pin('A' , 4 )){
		KeyPressed = 9;
	}
	else
	{
		KeyPressed = 0;
	}
	return KeyPressed;
}

unsigned char Key_Write()
{
	return Key_Write_1()|Key_Write_2()|Key_Write_3();
}

