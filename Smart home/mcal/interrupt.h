/*
 * interrupt.h
 *
 * Created: 7/13/2023 5:03:07 AM
 *  Author: Win-0
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_
/*********includes*****************/
#include "global_interrupth.h"
#include "DIO_MCAL.h"
#include "..\lib\atmega.h"
/***************** macros *********************************/
#define interrupt_0   0
#define interrupt_1   1
#define rising_edge   0
#define falling_egde  1
#define low_Level     2
/*************************** interrupt registers *********************/
#define MCUCR  *((volatile char *)0X55)
#define EICRA  *((volatile char*)0X69)
#define EIMSK  *((volatile char*)0X3D)
#define EIFR   *((volatile char*)0X3C)
#define PCICR  *((volatile char*)0X68)
#define PCIFR  *((volatile char*)0X3B)
#define PCMSK2 *((volatile char*)0X6D)
#define PCMSK1 *((volatile char*)0X6C)
#define PCMSK0 *((volatile char*)0X6B)

/************************** FUNCATIONS ********************/
void interrupt_init(char interrupt_number,char edge);
void interrupt_Pcin(char pin);
char set_call_back(char interrupt_index,void (*l_ptr)(void));
#endif /* INTERRUPT_H_ */