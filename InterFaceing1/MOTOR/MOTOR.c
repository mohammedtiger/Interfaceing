
#include "../PWM/PWM.h"
#include "../DIO/DIO.h"
#include "MOTOR.h"

void Motor_Init()
{
	Init_Pin('D',7,1);
	Init_Pin('D',6,1);

}
void Motor_forword(unsigned char value)
{
	PWM_1(value);
	Set_Pin('D' , 7);
	Clear_Pin('D' , 6);

}


void Motor_backword(unsigned char value)
{
	PWM_1(value);
	Set_Pin('D' , 6);
	Clear_Pin('D' , 7);

}

void Motor_break()
{
	PWM_1(0);
	Set_Pin('D' , 6);
	Set_Pin('D' , 7);

}
