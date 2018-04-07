#include "I2CMaster.h"
#include<avr/io.h>

void init_master(void)
{
//TWSR = 0x00;
TWBR = 0x01;
}

void i2c_start(void)
{
TWCR= (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
while (!(TWCR & (1<<TWINT)));
while((TWSR & 0xF8)!= 0x08);
}





void i2c_repeated_start(void)
{
    // Clear TWI interrupt flag, Put start condition on SDA, Enable TWI
    TWCR= (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
    while(!(TWCR & (1<<TWINT))); // wait till restart condition is transmitted
    while((TWSR & 0xF8)!= 0x10); // Check for the acknowledgement
}

void i2c_write_address(unsigned char data)
{
TWDR = data;
TWCR = (1<<TWINT)|(1<<TWEN);
while (!(TWCR & (1<<TWINT)));
while((TWSR & 0xF8)!= 0x18);
}




void TWI_read_address(unsigned char data)
{
    TWDR=data;  // Address and read instruction
    TWCR=(1<<TWINT)|(1<<TWEN);    // Clear TWI interrupt flag,Enable TWI
    while (!(TWCR & (1<<TWINT))); // Wait till complete TWDR byte received
    while((TWSR & 0xF8)!= 0x40);  // Check for the acknowledgement
}





void i2c_writedata(unsigned char data)
{
TWDR = data;
TWCR = (1<<TWINT)|(1<<TWEN);
while (!(TWCR & (1<<TWINT)));
while((TWSR & 0xF8) != 0x28); // Check for the acknowledgement

}

uint8_t TWI_read_data(void)
{
    TWCR=(1<<TWINT)|(1<<TWEN);    // Clear TWI interrupt flag,Enable TWI
    while (!(TWCR & (1<<TWINT))); // Wait till complete TWDR byte transmitted
    while((TWSR & 0xF8) != 0x58); // Check for the acknowledgement
    return TWDR;

}

void i2c_stop(void)
{
TWCR=(1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}
