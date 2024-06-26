/*
 * Button.c
 *
 * Created: 7/19/2023 6:24:49 PM
 *  Author: Win-0
 */ 
#include "Button.h"
char get_button_read(char port,char pin)
{
	DIGITAL_WRITE_DDR_pins(port,pin,INPUT);
	DIGITAL_READ(port,pin);
}