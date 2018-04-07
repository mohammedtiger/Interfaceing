#include<avr/io.h>
// Function to initialize slave
void TWI_init_slave(uint8_t addrs)
{
    // Fill slave address to TWAR
    TWAR=0x20;
}




//Function to match the slave address and slave direction bit(read)
void TWI_match_read_slave(void)
{
    // Loop till correct acknoledgement have been received
    while((TWSR & 0xF8)!= 0x60)
    {
        // Get acknowlegement, Enable TWI, Clear TWI interrupt flag
        TWCR=(1<<TWEA)|(1<<TWEN)|(1<<TWINT);
        // Wait for TWINT flag
        while (!(TWCR & (1<<TWINT)));
    }
}
uint8_t TWI_read_slave(void)
{
    // Clear TWI interrupt flag,Get acknowledgement, Enable TWI
    TWCR= (1<<TWINT)|(1<<TWEA)|(1<<TWEN);
    // Wait for TWINT flag
    while (!(TWCR & (1<<TWINT)));
    // Wait for acknowledgement
    while((TWSR & 0xF8)!=0x80);
    // Get value from TWDR

    return TWDR;
}





















void TWI_match_write_slave()
{
    // Loop till correct acknowledgement have been received
    while((TWSR & 0xF8)!= 0xA8)
    {
        // Get acknowledgment, Enable TWI, Clear TWI interrupt flag
        TWCR=(1<<TWEA)|(1<<TWEN)|(1<<TWINT);
        while (!(TWCR & (1<<TWINT)));  // Wait for TWINT flag
    }
}

void TWI_write_slave(uint8_t write_data) // Function to write data
{
    // Fill TWDR register with the data to be sent
    TWDR= write_data;
    // Enable TWI, Clear TWI interrupt flag
    TWCR= (1<<TWEN)|(1<<TWINT);
    // Wait for the acknowledgement
    while((TWSR & 0xF8) != 0xC0);
}

