/*
 * LDR.c
 *
 * Created: 7/11/2023 5:16:57 AM
 *  Author: Win-0
 */ 
#include "LDR.h"
short LDR_READING(void)
{
	/**************** here we should get only the analog value in milli volt ************/
	/************************* return digital value from (adc reading) is an short so we should take it in a short*************/
	short reading=(float)ADC_Read(channel_pin,adjustment);
	reading*=4.8828f;
	return reading;
}