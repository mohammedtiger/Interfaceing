
#include "avr/io.h"
#include "Toggle.h"
#include "../TIMER_0/TIMER_0.h"

void Toggle_init()
{
	DDRD = 0xf0;
}

