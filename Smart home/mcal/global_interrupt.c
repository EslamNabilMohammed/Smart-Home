/*
 * global_interrupt.c
 *
 * Created: 7/13/2023 7:34:38 AM
 *  Author: Win-0
 */ 
#include "global_interrupth.h"
void Global_interrupt_enable(void)
{
		set_bit(SREG,PIN_7); 
}
void Global_interrupt_disable(void)
{
	clear_bit(SREG,PIN_7);
}