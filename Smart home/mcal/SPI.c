/*
 * SPI.c
 *
 * Created: 8/28/2023 5:47:03 PM
 *  Author: Eslam Nabil
 */ 
#include "..\lib\atmega.h"
#include "DIO_MCAL.h"
#include "Std_types.h"
#include "SPI.h"
void(*global_ptr)(void)=0;
void Spi_Init(void)
{
	#if (Spi_Mode==Spi_Master)
	{
		
		DIGITAL_WRITE_DDR_pins(DIO_PORTB,PIN_3,OUTPUT); /**************MOSI IS OUTPUT for master ********/
		DIGITAL_WRITE_DDR_pins(DIO_PORTB,PIN_4,INPUT);/***************MISO IS INPUT for master*********/
		DIGITAL_WRITE_DDR_pins(DIO_PORTB,PIN_5,OUTPUT);/****************CLOCK OUTPUT for master********/
		DIGITAL_WRITE_DDR_pins(DIO_PORTB,PIN_2,OUTPUT);/***************master ss***********************/
		set_bit(SPCR,PIN_5); /***********data order for LSB IT should be the same for two mcu *******************/
		set_bit(SPCR,PIN_4); /************to select master mode ***************/
	}
	
	#elif (Spi_Mode==Spi_Slave)
	DIGITAL_WRITE_DDR_pins(DIO_PORTB,PIN_3,INPUT); /**************MOSI IS INPUT for slave ********/
	DIGITAL_WRITE_DDR_pins(DIO_PORTB,PIN_4,OUTPUT);/***************MISO IS output or slave*********/
	DIGITAL_WRITE_DDR_pins(DIO_PORTB,PIN_5,INPUT);/****************CLOCK input or slave********/
	DIGITAL_WRITE_DDR_pins(DIO_PORTB,PIN_2,INPUT);/***************slave ss should be low so we use ground***********************/
	set_bit(SPCR,PIN_5); /***********data order for LSB IT should be the same for two mcu *******************/
    clear_bit(SPCR,PIN_4); /************to select slave mode ***************/
#endif
clear_bit(SPCR,PIN_3); /***********choosing clock form***********/
set_bit(SPCR,PIN_2);  /*************setup to write data first then sampling to read data ********/
/***********************************prescaler=16 *************************/
set_bit(SPCR,PIN_0);
clear_bit(SPCR,PIN_1);
/********************speed ****************/
clear_bit(SPSR,PIN_0);
/********************enable interrupt *************/
set_bit(SPCR,PIN_7);
/******************spi enable***************/
set_bit(SPCR,PIN_6);
}
void spi_set_Call_back(void(*ptr)(void))
{
	global_ptr=ptr;
}
void Spi_Transmit(char data)
{
	SPDR=data;
}
char Spi_Receive(void)
{
	/****************wait untill data transfer is completed **********/

	return SPDR;
}
void Spi_Transmitstr(char *data)
{
	 char iteration=0;
	for (iteration=0;data[iteration]!='\0';iteration++)
	{
		Spi_Transmit(data[iteration]);
	}
}
void Spi_Receivestr(char *data)
{
	 char iteration=0;
	 for (iteration=0;data[iteration]!='\0';iteration++)
	 {
		 data[iteration]=Spi_Receive();
	 }
	 data[iteration]='\0';
}
void __vector_17(void)   __attribute__((signal));
void __vector_17(void)
{
	global_ptr();
}