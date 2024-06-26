/*
 * timer1.c
 *
 * Created: 8/11/2023 6:24:39 PM
 *  Author: Win-0
 */ 
#include "DIO_MCAL.h"
#include "..\lib\atmega.h"
#include "Std_types.h"
#include "timer1.h"
#include "global_interrupth.h"
#include "timer.h"
void (*Icu_ptr)(void);
void timer1_init(char mode,char interrupt_type,char timer_prescaler)
{
	switch (mode)
	{
		case normal:
		clear_bit(TCCR1A,PIN_0);
		clear_bit(TCCR1A,PIN_1);
		clear_bit(TCCR1B,PIN_3);
		clear_bit(TCCR1B,PIN_4);
		switch(interrupt_type)
		{
			case overflow:
			Global_interrupt_enable();
			TIMSK1|=overflow;
			break;
			
		}
		break;
		case fast_pwm:
		clear_bit(TCCR1A,PIN_0);
		set_bit(TCCR1A,PIN_1);
		set_bit(TCCR1B,PIN_3);
		set_bit(TCCR1B,PIN_4);
		ICR1=ICR1_value; /**************maximum value =(desired time/time of one tic)-1*************/
		
		switch(interrupt_type)
		{
			/********************* ocr1A*********************/
			case fast_inverting_mode:
			set_bit(TCCR1A,PIN_7);
			clear_bit(TCCR1A,PIN_6);
			DIGITAL_WRITE_DDR_pins(DIO_PORTB,PIN_1,OUTPUT);
			break;
		}
		break;
	}
	switch(timer_prescaler)
	{
		case normalprescale:
		TCCR1B|=normalprescale;
		break;
		case prescaler_8:
		TCCR1B|=prescaler_8;
		break;
		case prescaler_64:
		TCCR1B|=prescaler_64;
		break;
		case  prescaler_256:
		TCCR1B|=prescaler_256;
		break;
		case prescaler_1024:
		TCCR1B|=prescaler_1024;
		break;
		case external_clock_rising:
		TCCR1B|=external_clock_rising;
		break;
		case external_clock_falling:
		TCCR1B|=external_clock_falling;
		break;		
	}
}
set_timer1_compareA(short reading)
{
	OCR1A=reading; /******value=angle of servo motor *********/ 
}
void ICU_INIT(void)
{
	switch(edge)
	{
		case rising_edge:
		set_bit(TCCR1B,PIN_7); /************noise cancel*******/
		set_bit(TCCR1B,PIN_6);
	   /**********************global interrupt should be enabled and the input capture interrupt enable should be activated****/	
	    set_bit(TIMSK1,PIN_5);
		Global_interrupt_enable();
		break;
		case falling_edge:
		set_bit(TCCR1B,PIN_7);  /************noise cancel*******/
	   clear_bit(TCCR1B,PIN_6);
	   /**********************global interrupt should be enabled and the input capture interrupt enable should be activated****/
	   set_bit(TIMSK1,PIN_5);
	   Global_interrupt_enable();
	   break;
	}
}
char Icu_set_call_back(void (*l_ptr)(void))
{
	char read=1; /****************std_types_ok *************/
	if(l_ptr==0)
	read=std_types_Nok; /************************error *********************/
	else
	Icu_ptr=l_ptr;
	return read;
}

/********************ISR OF INPUT CAPTURE UNIT ********************/
void __vector_10(void)  __attribute__((signal));
void __vector_10(void)
{
	Icu_ptr();
}

