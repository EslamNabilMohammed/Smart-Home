/*
 * global_interrupth.h
 *
 * Created: 7/13/2023 7:32:33 AM
 *  Author: Win-0
 */ 


#ifndef GLOBAL_INTERRUPTH_H_
#define GLOBAL_INTERRUPTH_H_
#include "DIO_MCAL.h"
#include "..\lib\atmega.h"
#define SREG   *((volatile char*)0X5F)
void Global_interrupt_enable(void);
void Global_interrupt_disable(void);




#endif /* GLOBAL_INTERRUPTH_H_ */