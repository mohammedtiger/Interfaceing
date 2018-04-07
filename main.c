#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "InterFaceing2/UART/UART.h"
#include "InterFaceing2/I2C/I2CSlave.h"
#include "InterFaceing2/I2C/I2CMaster.h"

#define I2C_MASTER
//#define I2C_SLAVE





#ifdef I2C_MASTER

unsigned char address = 0x20, read = 1, write = 0;
unsigned char write_data ='A';

int main(void)
{

	uint8_t data[] = {"HelloWorld !! \r\n"};
	init_master();
	//sei();

	while(1)
	{


		for (int i = 0; i < sizeof(data) ; i++)
		{
			i2c_start();
			i2c_write_address(address+write);
			i2c_writedata(data[i]);
			i2c_stop();
			_delay_ms(10);

		}


	}
	return 0;

}
#endif


#ifdef I2C_SLAVE


int main(void)
{

	Uart_Init(9600);
	TWI_init_slave(0x20);
	sei();

	while(1)
	{
		TWI_match_read_slave();
		Uart_Transmit(TWI_read_slave());
	}
	return 0;

}
#endif
