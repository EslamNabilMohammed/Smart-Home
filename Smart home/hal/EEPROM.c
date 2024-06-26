/*
 * EEPROM.c
 *
 * Created: 9/15/2023 2:49:13 PM
 *  Author: Win-0
 */ 
#include "EEPROM.h"
#include "..\mcal\Std_types.h"
#include "..\mcal\i2c.h"
#include "..\lib\atmega.h"
#include "..\mcal\DIO_MCAL.h"
#define F_CPU 16000000
#include "util\delay.h"
static char EEPROR_CHECK(TWI_ERROR ERROR);
static char EEPROR_CHECK(TWI_ERROR ERROR)
{
	char error_State=std_types_ok;
	if(ERROR!=I2C_OK)
	{
		error_State=std_types_Nok;
		
	}
	return error_State;
}
char EEPROM_WRITE(short address,char data)
{
	
	char error=std_types_ok;
	TWI_ERROR LOCAL_ERROR=I2C_OK;
	LOCAL_ERROR=I2C_START();
	error=EEPROR_CHECK(LOCAL_ERROR);
	/*********************address is a 10 bit address and we need to get A1&A0 SO we should make a shift *******/
	LOCAL_ERROR=I2C_SLAVE_Write((EEPROM_FIXED_ADDRESS)|(EEPROM_A2<<2)|(address>>8));
	error=EEPROR_CHECK(LOCAL_ERROR);
	/************************** send byte address and make a casting  *****************/
	LOCAL_ERROR=I2C_transmit((char)address);
	error=EEPROR_CHECK(LOCAL_ERROR);
	/***************************** send data ********************/
	LOCAL_ERROR=I2C_transmit(data);
	error=EEPROR_CHECK(LOCAL_ERROR);
	I2C_STOP();
	/****************** as we say after each stop conditon and new start conditon there should be a delay*******/
	_delay_ms(5);
	return error;
	
}
char EEPROM_READ(short address,char *data)
{
	char error=std_types_ok;
	TWI_ERROR LOCAL_ERROR=I2C_OK;
	LOCAL_ERROR=I2C_START();
	error=EEPROR_CHECK(LOCAL_ERROR);
	/*********************address is a 10 bit address and we need to get A1&A0 SO we should make a shift *******/
	LOCAL_ERROR=I2C_SLAVE_Write((EEPROM_FIXED_ADDRESS)|(EEPROM_A2<<2)|(address>>8));
	error=EEPROR_CHECK(LOCAL_ERROR);
	/************************** send byte address and make a casting  *****************/
	LOCAL_ERROR=I2C_transmit((char)address);
	error=EEPROR_CHECK(LOCAL_ERROR);
	/***************************** Repeated start to change mode to read ********************/
	LOCAL_ERROR=I2C_REPSTART();
	error=EEPROR_CHECK(LOCAL_ERROR);
	/********************* send address again but here send only 8 bits ************/
	LOCAL_ERROR=I2C_SLAVE_Read((EEPROM_FIXED_ADDRESS)|(EEPROM_A2<<2)|(address>>8));
	error=EEPROR_CHECK(LOCAL_ERROR);
	/*************** READ DATA  *************/
	LOCAL_ERROR=I2C_receive(data);
	error=EEPROR_CHECK(LOCAL_ERROR);
	I2C_STOP();
	
	/****************** as we say after each stop conditon and new start conditon there should be a delay*******/
	_delay_ms(5);
	return error;
}