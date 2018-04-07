/*
 * I2CSlave.h
 *
 *  Created on: Oct 16, 2017
 *      Author: root
 */

#ifndef INTERFACEING2_I2C_I2CSLAVE_H_
#define INTERFACEING2_I2C_I2CSLAVE_H_

void TWI_init_slave(uint8_t addrs);
void TWI_match_read_slave(void);
uint8_t TWI_read_slave(void);
void TWI_write_slave(uint8_t write_data);
void TWI_match_write_slave();


#endif /* INTERFACEING2_I2C_I2CSLAVE_H_ */
