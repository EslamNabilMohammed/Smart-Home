/*
 * i2c.c
 *
 * Created: 9/14/2023 1:38:45 PM
 *  Author: Win-0
 */ 
#include "i2c.h"
#include "DIO_MCAL.h"
#include "../lib/atmega.h"
#include "Std_types.h"
/******************** helper funcation *******/
static void bit_rate(void);
static void bit_rate(void)
{
	switch(prescaler_value)
	{
		case normal:
		clear_bit(TWSR,PIN_0);
		clear_bit(TWSR,PIN_1);
		break;
		case prescaler_4:
		set_bit(TWSR,PIN_0);
		clear_bit(TWSR,PIN_1);
		break;
		case prescaler_16:
		clear_bit(TWSR,PIN_0);
		set_bit(TWSR,PIN_1);
		break;
		case prescaler_64:
		set_bit(TWSR,PIN_0);
		set_bit(TWSR,PIN_1);
		break;
		
	}
	/*************equation ********/
	TWBR=(char)((double)((16000000-16*clock_Freq))/(int)(2*prescaler_value*clock_Freq));
}
void I2C_MASTER_INIT(void)
{
	/****************** clock frequency  *****/
	bit_rate();
	/**************enable ack *****************/
	set_bit(TWCR,PIN_6);
	
}
void I2C_SLAVE_INIT(char address)
{
	/**************** address shouldnt be a reserved one and it contains only 7bits so we should shift it left **********/
	TWAR=address<<1;
	/**************enable ack *****************/
	set_bit(TWCR,PIN_6);
}
TWI_ERROR I2C_START(void)
{
	TWI_ERROR start_error=I2C_OK;
	/*********************** interrupt flag must be cleared by software after each operation******************/
	set_bit(TWCR,PIN_7);
	/******************************** enable start condition **********/
	set_bit(TWCR,PIN_5);
	/**************** wait untill start condition is terminated means unitl interrupt flag is set************/
	while(get_bit(TWCR,PIN_7)==0);
	/********check status code for error ******/
	if ((TWSR&0xf8)!=0x08)
	{
		start_error=I2C_SC_ERROR;
	}
	/*********clear start condion bit ***********/
	clear_bit(TWCR,PIN_5);
	return start_error;
}
TWI_ERROR I2C_REPSTART(void)
{
	TWI_ERROR start_error=I2C_OK;
	/*********************** interrupt flag must be cleared by software after each operation******************/
	set_bit(TWCR,PIN_7);
	/******************************** enable start condition **********/
	set_bit(TWCR,PIN_5);
	/**************** wait untill start condition is terminated means unitl interrupt flag is set************/
	while(get_bit(TWCR,PIN_7)==0);
	/********check status code for error ******/
	if ((TWSR&0xf8)!=0x10)
	{
		start_error=I2C_RS_ERROR;
	}
	/*********clear start condion bit ***********/
	clear_bit(TWCR,PIN_5);
	return start_error;
}
void I2C_STOP(void)
{
	/*********************** interrupt flag must be cleared by software after each operation******************/
	set_bit(TWCR,PIN_7);
	/************enable stop bit ***********/	
	set_bit(TWCR,PIN_4);
}
TWI_ERROR I2C_SLAVE_Write(char address)
{
	TWI_ERROR slave_error=I2C_OK;
	/****************clear LSB bit to get mode of writing *********/
	clear_bit(TWDR,PIN_0);
	/*********************** interrupt flag must be cleared by software after each operation******************/
	set_bit(TWCR,PIN_7);
	while(get_bit(TWCR,PIN_7)==0);
	/***********check status code *******/
	if ((TWSR&0xf8)==0x18)
	{ 
		I2C_SLAVE_INIT(address);
	}
	else
	{
	 slave_error=I2C_SLAVE_ERROR;	
	}
	
	return  slave_error;
}
TWI_ERROR I2C_SLAVE_Read(char address)
{
TWI_ERROR slave_error=I2C_OK;
/****************set LSB bit to get mode of reading *********/
set_bit(TWDR,PIN_0);
/*********************** interrupt flag must be cleared by software after each operation******************/
set_bit(TWCR,PIN_7);
while(get_bit(TWCR,PIN_7)==0);
/***********check status code *******/
if ((TWSR&0xf8)==0x40)
{
	I2C_SLAVE_INIT(address);
}
else
{
	slave_error=I2C_SLAVE_ERROR;
}

return  slave_error;
}

TWI_ERROR I2C_transmit(char data)
{
	TWI_ERROR TRANMIT=I2C_OK;
	TWDR=data;
	/****************interrupt flag must be cleared by softaware at every step *****/
	set_bit(TWCR,PIN_7);
	/*****************wait until interrupt flag is set *********/
	while(get_bit(TWCR,PIN_7)==0);
	/***********check status code *******/
	if ((TWSR&0xf8)!=0x28)
	{
		TRANMIT=I2C_TRA_ERROR;
	}
	return TRANMIT;
} 
TWI_ERROR I2C_receive(char *read)
{
	TWI_ERROR receive=I2C_OK;
		/****************interrupt flag must be cleared by softaware at every step *****/
		set_bit(TWCR,PIN_7);
	while(get_bit(TWCR,PIN_7)==0);
	*read=TWDR;
	/***********check status code *******/
	if ((TWSR&0xf8)!=0x50)
	{
		receive=I2C_REC_ERROR;
	}
	return receive;
}