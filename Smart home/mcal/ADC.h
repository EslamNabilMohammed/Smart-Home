/*
 * ADC.h
 *
 * Created: 7/6/2023 3:31:42 AM
 *  Author: Win-0
 */ 


#ifndef ADC_H_
#define ADC_H_
#include "..\lib\atmega.h"
#include "DIO_MCAL.h"
#define F_CPU 16000000
#include "util/delay.h"
/******************** ADC REGISTERS ************************/
#define  ADMUX *((volatile unsigned char *)0x7C)
#define  ADCSRA *((volatile unsigned char *)0x7A)
#define  ADCSRB *((volatile unsigned char *)0x7B)
#define  DIDR0  *((volatile unsigned char *)0x7E)
#define  ADCL *((volatile unsigned char *)0x78)
#define  ADCH *((volatile unsigned char *)0x79)
/*vref*/
enum volt
{
AREF,
AVCC,
Internal_11V=2	
};

/***************************prescaler********************************/
 enum prescale
{
	prescaler2,
	prescaler4=2,
	prescaler8,
    prescaler16,
	prescaler32,
	prescaler64,
	prescaler128,
};
 
/***********************Channels*******************************/
enum channel
{
channel_0=0,
channel_1,
channel_2,	
channel_3,	
channel_4,
channel_5,	
channel_6,
channel_7,		
};
/******************************macros***************************/
/***************************** conversion counter is the maximum conversion time as if flag=1 in the whole program it indicates a problem******/
#define left_Adj   1
#define right_Adj  0
#define conversion_counter 260000000 
#define ERROR_STATUS 1
/********************* funcations******************/
void ADC_Init(char prescaler, char vref);
short ADC_Read(char channel,char adj);
#endif /* ADC_H_ */