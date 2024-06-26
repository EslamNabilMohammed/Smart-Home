/*
 * Relay.c
 *
 * Created: 9/16/2023 7:34:23 PM
 *  Author: Win-0
 */ 
#include "Relay.h"
#include "..\mcal\DIO_MCAL.h"
#include "..\lib\atmega.h"
void Relay_init(void)
{
	
	DIGITAL_WRITE_DDR_pins(Relay_port,Relay_pin,OUTPUT);
}
void Relay_on(void)
{
	/*********************** normal mode connected to (normal closed) that acts as a switch off *********/
	/********************** we should connect it to (normal open) pin to act as a switch on ********/
	DIGITAL_WRITE_PIN_PORT(Relay_port,Relay_pin,HIGH);
}