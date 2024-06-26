/*
 * SPI.h
 *
 * Created: 8/28/2023 5:46:50 PM
 *  Author: Win-0
 */ 


#ifndef SPI_H_
#define SPI_H_
#define  SPCR  *((volatile char *)0x4c)
#define  SPSR  *((volatile char *)0x4D)
#define  SPDR  *((volatile char *)0x4E)
#define  Spi_Master 1
#define  Spi_Slave  2
/**************Spi mode options  Spi_Master
                                 Spi_Slave*********/
#define Spi_Mode  Spi_Slave
void Spi_Init(void);
void Spi_Transmit(char data);
char Spi_Receive(void);
void Spi_Transmitstr(char *data);
void Spi_Receivestr(char *data);
void spi_set_Call_back(void(*ptr)(void));



#endif /* SPI_H_ */