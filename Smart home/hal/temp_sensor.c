/*
 * temp_sensor.c
 *
 * Created: 7/9/2023 10:24:19 AM
 *  Author: Win-0
 */ 
#include "temp_sensor.h" 
#include "..\mcal\DIO_MCAL.h"
#include "..\mcal\ADC.h"
short temp_reading(char channel)
{
	DIGITAL_WRITE_DDR_pins(DIO_PORTC,channel,INPUT);
	/******************** here we get analog reading by getting digital reading*(5000/1024) then we get temp reading by dividing analog reading by 10*/
short read=(float)ADC_Read(channel,right_Adj);
 read=read*0.4882813f;
return read;
}
