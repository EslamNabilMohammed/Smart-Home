/*
 * interrupt.c
 *
 * Created: 7/13/2023 5:02:53 AM
 *  Author: Win-0
 */ 
#include "interrupt.h"
#include "Std_types.h"

/******************Global pointer to funcation(array of pointers to funcation ) *********************/
void (*ptr[2])(void)={0};
void interrupt_init(char interrupt_number,char edge)
{
	/************************* EXTERNAL INTERRUPTS ************************/
	switch(interrupt_number)
	{
		/********************* choosing edge&interrupt number ***************/
		case interrupt_0:
			DIGITAL_WRITE_DDR_pins(DIO_PORTD,PIN_2,INPUT);
		switch(edge)
		{
			case rising_edge:
			set_bit(EICRA,PIN_1);
			set_bit(EICRA,PIN_0);
			set_bit(EIMSK,PIN_0);
			Global_interrupt_enable();
			break;
			case falling_egde:
			set_bit(EICRA,PIN_1);
			clear_bit(EICRA,PIN_0);
			set_bit(EIMSK,PIN_0); /*peripheral interrupt flag*/
			Global_interrupt_enable();
			break;
			case low_Level:
			clear_bit(EICRA,PIN_1);
			clear_bit(EICRA,PIN_0);
			set_bit(EIMSK,PIN_0); /*peripheral interrupt flag*/
			Global_interrupt_enable();
			break;
		}
		case interrupt_1:
		DIGITAL_WRITE_DDR_pins(DIO_PORTD,PIN_3,INPUT);
		switch(edge)
		{
			case rising_edge:
			set_bit(EICRA,PIN_3);
			set_bit(EICRA,PIN_2);
			set_bit(EIMSK,PIN_1); /*peripheral interrupt flag*/
			Global_interrupt_enable();
			break;
			case falling_egde:
			set_bit(EICRA,PIN_3);
			clear_bit(EICRA,PIN_2);
			set_bit(EIMSK,PIN_1); /*peripheral interrupt flag*/
			Global_interrupt_enable();
			break;
			case low_Level:
			clear_bit(EICRA,PIN_3);
			clear_bit(EICRA,PIN_2);
			set_bit(EIMSK,PIN_1); /*peripheral interrupt flag*/
			Global_interrupt_enable();
			break;
		}
	}

}
char set_call_back(char interrupt_index,void (*l_ptr)(void))
{
	char read=1; /****************std_types_ok *************/
	if((ptr==0)||(interrupt_index>1))
	read=std_types_Nok; /************************error *********************/
	else
	ptr[interrupt_index]=l_ptr;
	return read;
}
void interrupt_Pcin(char pin)
{
	/*************** here i use only pin from 0 to 7 ***************/
	set_bit(PCICR,PIN_0);
	set_bit(PCMSK0,pin);
	Global_interrupt_enable();
}
/********************************** INTERRUPT DONE BY HARD WARE*********************/
/********************************* ISR of intterupt_0 ******************************/
void __vector_1(void)   __attribute__((signal));
void __vector_1(void)
{
	ptr[0]();
}
/********************************* ISR of intterupt_0 ******************************/
void __vector_2(void)   __attribute__((signal));
void __vector_2(void)
{
	ptr[1]();
}