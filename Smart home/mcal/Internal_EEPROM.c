/*
 * Internal_EEPROM.c
 *
 * Created: 9/18/2023 3:17:49 PM
 *  Author: Win-0
 */ 
#include "Internal_EEPROM.h"
#include "..\lib\atmega.h"
#include "DIO_MCAL.h"
#include "global_interrupth.h"
#define F_CPU 16000000
#include "util\delay.h"
void Internal_EEPROM_INIT(void)
{
	/************** address should be 10 bit address in EEPROM location from 0 to 1023 ********/
	
	/************** erase and write in one opertaion *************/
	clear_bit(EECR,PIN_5);
	clear_bit(EECR,PIN_4);
	/**********************diasble interrupt this bit is activated after each writing data **********/
	clear_bit(EECR,PIN_3);
	
}
void Internal_EEPROM_Write(char data,short address)
{
	/**************** writing sequence in eeprom ******/
	while(get_bit(EECR,PIN_1));
	/************ for writing on flash we should wait ***/
	while(get_bit(SPMCSR,PIN_0));
	EEAR=address;
	EEDR=data;
	set_bit(EECR,PIN_2);
	
	set_bit(EECR,PIN_1);
	
}
char Internal_EEPROM_Read(short address)
{
 /************** wait untill writing to eeprom is finished *************/
	while(get_bit(EECR,PIN_1));
		/************** address should be 10 bit address in EEPROM location from 0 to 1023 ********/
	EEAR=address;
	set_bit(EECR,PIN_0);
	return EEDR;
	
}