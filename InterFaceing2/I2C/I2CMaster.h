
#ifndef INTERFACEING2_I2C_I2CMASTER_H_
#define INTERFACEING2_I2C_I2CMASTER_H_

void init_master(void);
void i2c_start(void);
void i2c_write_address(unsigned char data);
void i2c_writedata(unsigned char data);
void i2c_stop(void);
void i2c_repeated_start(void);

#endif /* INTERFACEING2_I2C_I2CMASTER_H_ */
