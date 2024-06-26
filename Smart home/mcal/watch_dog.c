/*
 * watch_dog.c
 *
 * Created: 8/15/2023 9:06:23 AM
 *  Author: Win-0
 */ 
#include "..\lib\atmega.h"
#include "watch_dog.h"
#include "..\mcal\DIO_MCAL.h"
void WDT_INIT(char prescaler)
{
	/**************************system reset mode ******************/
	WDTCSR|=0x18; /*************set wdce to chang prescaler&wde  *****************/
	switch(prescaler)
	{
		case prescaler_2k:	
		WDTCSR|=prescaler_2k;
	    break;
		case prescaler_4k:
		WDTCSR|=prescaler_4k;
		break;
		case prescaler_8k:
		WDTCSR|=prescaler_8k;
		break;
		case prescaler_16k:
		WDTCSR|=prescaler_16k;
		break;
		case prescaler_32k:
		WDTCSR|=prescaler_32k;
		break;
		case prescaler_64k:
		WDTCSR|=prescaler_64k;
		break;
		case prescaler_128k:
		WDTCSR|=prescaler_128k;
		break;
		case prescaler_256k:
		WDTCSR|=prescaler_256k;
		break;
		case prescaler_512k:
		set_bit(WDTCSR,PIN_5);
		WDTCSR|=prescaler_2k;
		break;
		case prescaler_1024k:
		set_bit(WDTCSR,PIN_5);
		WDTCSR|=prescaler_4k;
		break;
	}
	
}
void WDT_DISABLE()
{
	clear_bit(WDTCSR,PIN_3);
	clear_bit(WDTCSR,PIN_6);
}