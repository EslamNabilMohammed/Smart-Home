/*
 * IR.c
 *
 * Created: 9/17/2023 10:26:39 PM
 *  Author: Win-0
 */ 
#include "IR.h"
#include "..\mcal\DIO_MCAL.h"
#include "..\lib\atmega.h"
void IR_INIT(char port, char pin)
{
	DIGITAL_WRITE_DDR_pins(port,pin,INPUT);
}
char IR_Read(char port, char pin)
{
	char reading=0;
	reading=DIGITAL_READ(port,pin);
	return reading;
}