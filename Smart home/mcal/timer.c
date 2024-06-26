/*
 * timerzero.c
 *
 * Created: 8/5/2023 6:59:06 PM
 *  Author: eslam nabil
 */ 
#include "timer.h"
#include "Std_types.h"
#include "DIO_MCAL.h"
#include "global_interrupth.h"
static void (*timer0_over)(void)=NULL;
static void (*timer0_ctcA)(void)=NULL;
static void (*timer0_ctcB)(void)=NULL;

void control_intensity(char pre)
{
	OCR0A=pre;
}
void timer0_init(char mode,char interrupt_type,char timer_prescaler)
{
	/**********mode ***********************/
	switch(mode)
	{
		/**********Preload value is the initial value of countinning***********/
		case normal:
		TCCR0A&=0x00;
		TCCR0B&=0x00;
		TCNT0=preload_value;
		switch(interrupt_type)
		{
			case overflow:
			TIMSK0|=overflow;
			Global_interrupt_enable();
			break;
			case no_interrupt:
			TIMSK0&=no_interrupt;
			break;
			default:
			break;
		}
		break;
		case compare:
		TCCR0A|=compare;
		clear_bit(TCCR0B,PIN_3);
		TCCR0A|=0x40;
		TCNT0=preload_value;
		switch(interrupt_type)
		{
			case compareA:		
			Global_interrupt_enable();
			OCR0A=compare_value;
		    TIMSK0|=compareA;
			break;
			case compareB:
			Global_interrupt_enable();
			OCR0B=compare_value;
			TIMSK0|=(compareB+1);
			break;	
		}
		break;
		case fast_pwm:
		TCCR0A|=fast_pwm;  /**************two pins are set**************/
		clear_bit(TCCR0B,PIN_3);
		TCNT0=preload_value;
		/*OCR0A=compare_value;*/
		/******************control pin action ************/
		switch(interrupt_type)
		{
			/******************************** compare A is avtivated *******************************/
			case normal:
			clear_bit(TCCR0A,PIN_6);
			clear_bit(TCCR0A,PIN_7);
			break;
			case toggle_pin:
			/*****************here the pin will toggle on comparematch  *********/
			TCCR0A|=toggle_pin;
			set_bit(TCCR0B,PIN_3);
			break;
			case inverting_mode:
			/*****************i will dell with inverting mode to set pin at compare and clear pin at overflow *********/
			TCCR0A|=inverting_mode;
			break;
		}
		break;
		case phase_correct:
		TCCR0A|=phase_correct;
		TCNT0=preload_value;
		switch(interrupt_type)
		{
			case normal:
			clear_bit(TCCR0A,PIN_7);
			clear_bit(TCCR0A,PIN_6);
			break;
			case toggle_pin:
			TCCR0A|=toggle_pin;
			clear_bit(TCCR0A,PIN_7);
			break;
			/******************to set pin in up counting and clear pin at down counting *************/
			case inverting_mode:
			TCCR0A|=inverting_mode;
			break;
		}
		break;
	}
	switch(timer_prescaler)
	{
		case normalprescale:
		TCCR0B|=normalprescale;
		break;
		case prescaler_8:
		TCCR0B|=prescaler_8;
		break;
		case prescaler_64:
		TCCR0B|=prescaler_64;
		break;
		case  prescaler_256:
		TCCR0B|=prescaler_256;
		break;
		case prescaler_1024:
		TCCR0B|=prescaler_1024;
		break;	
		case external_clock_rising:
		TCCR0B|=external_clock_rising;
		break;
		case external_clock_falling:
		TCCR0B|=external_clock_falling;
		break;
		
	}
}
char timer0_set_call_back_overflow(void (*ptr)(void))
{
	char read=std_types_ok;
	if(ptr!=NULL)
	{
	  timer0_over=ptr;	
	}
	else
	read=std_types_Nok;
	return read;
}
char timer0_set_call_back_ctcA(void (*ptr)(void))
{
	char read=std_types_ok;
	if(ptr!=NULL)
	{
		timer0_ctcA=ptr;
	}
	else
	read=std_types_Nok;
	return read;
}
char timer0_set_call_back_ctcB(void (*ptr)(void))
{
	char read=std_types_ok;
	if(ptr!=NULL)
	{
		timer0_ctcB=ptr;
	}
	else
	read=std_types_Nok;
	return read;
}
/********************timer0 overflow**************/
void __vector_16(void)  __attribute__((signal));
void __vector_16(void)
{
        TCNT0=preload_value;
		timer0_over();
        
}
/***********interrupt compare A ***************/
void __vector_14(void)  __attribute__((signal));
void __vector_14(void)
{
	static short counter=0;
	counter++;
	if(counter==overflow_number)
	{
		counter=0;
		timer0_ctcA();
		TCNT0=preload_value;
	}
}
void __vector_15(void)  __attribute__((signal));
void __vector_15(void)
{
	static short counter=0;
	counter++;
	if(counter==overflow_number)
	{
		counter=0;
		timer0_ctcB();
		TCNT0=preload_value;
	}
}