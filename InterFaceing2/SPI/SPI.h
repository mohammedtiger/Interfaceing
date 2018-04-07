
#ifndef INTERFACEING2_SPI_SPI_H_
#define INTERFACEING2_SPI_SPI_H_

#define DDR_SPI DDRB
#define DD_MOSI 5
#define DD_MISO 6
#define DD_SCK  7

void SPI_MasterInit(void);
void SPI_MasterTransmit(char cData);
void SPI_SlaveInit(void);
char SPI_SlaveReceive(void);


#endif /* INTERFACEING2_SPI_SPI_H_ */
