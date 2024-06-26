/*
 * servo_motor.c
 *
 * Created: 8/15/2023 8:53:57 AM
 *  Author: Win-0
 */ 
#include "servo_motor.h"
#include "..\mcal\DIO_MCAL.h"
#include "..\mcal\timer1.h"
#include "..\mcal\timer.h"
#include "..\mcal\ADC.h"
#include "temp_sensor.h"
void servo_init()
{
	timer1_init(fast_pwm,fast_inverting_mode,prescaler_64);
}
void set_servo_angle(unsigned char angle)
{
	/*************funcation here for prescaler=64*/
	short read=(short)(((float)(angle)*1.3888888)+250);
	OCR1A=read;
}
void servo_ADC(char channel)
{
	/***********************my funcations is based on prescaler64 *************/
	ADC_Init(prescaler128,AVCC);
	short read=(short)(((float)(ADC_Read(channel,right_Adj))*1.3888888)+250);
	set_timer1_compareA(read);
	timer1_init(fast_pwm,fast_inverting_mode,prescaler_64);
}