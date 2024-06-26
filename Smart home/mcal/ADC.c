/*
 * ADC.c
 *
 * Created: 7/6/2023 3:31:17 AM
 *  Author: Win-0
 */ 
#include "ADC.h"
void ADC_Init(char prescaler, char vref)
{
	DIGITAL_WRITE_DDR_pins(DIO_PORTC,channel_2,INPUT);
	
 /***********************choosing voltage ref**************************/
 switch(vref)
 {
	 case AREF:
	 ADMUX|=0x00;
	 break;
	 case AVCC:
	 ADMUX|=0x40;
	 break;
	 case Internal_11V:
	 ADMUX|=0xc0;
	 break;
 }
/**************************prescaler************************************/
/****************************we should choose the correct prescaler to get correct values for (adc) *******************************************/
switch(prescaler)
{
case prescaler128:
ADCSRA|=0x07;
break;
case prescaler64:
ADCSRA|=0x06;
break;
case prescaler32:
ADCSRA|=0x05;
break;
case prescaler16:
ADCSRA|=0x04;
break;
case prescaler8:
ADCSRA|=0x03;
break;
case prescaler4:
ADCSRA|=0x02;
break;
case prescaler2:
ADCSRA|=0x00;
break;
}
/*******************************(adc)enable**************************/
set_bit(ADCSRA,PIN_7);
/********************************(adc)auto triggering for free running mode*******************/
set_bit(ADCSRA,PIN_5);
ADCSRB|=0x00;
}

short ADC_Read(char channel,char adj)
{	
	int counter=0;
  short read=0; 
DIGITAL_WRITE_DDR_pins(DIO_PORTC,channel,INPUT);
 /******* we should clear the chanel bits first as when he choose for the seond or third time will case a chnnel choose error*************/
ADMUX&=0xE0;              /******clearing********/
ADMUX|=channel;             /*******channel number*****************/
switch(adj)
{
	case left_Adj:
	ADMUX|=0x20;
	ADCL&=0x02;
	read|=ADCL;
	read|=(short)(((short)ADCH)<<3);
	break;
	case right_Adj:
	ADMUX|=0x00;
	read|=ADCL;
	read|=(short)(((short)ADCH)<<8);
	break;
}
 /***************start conversion*******************/
 set_bit(ADCSRA,PIN_6);
 /*****************while loop here syncroniztion blocked we should make it unblocked as if there was a program and the flag =1 in the whole program there should be another status to get out of loop */ 
 while((get_bit(ADCSRA,PIN_6)&&(counter<conversion_counter)))
 {
	 counter++;
 }
 if(counter<conversion_counter)
      read=read;
 else
 read=ERROR_STATUS;
 return read;
 
}






/*
switch(adj)

{
	case left_Adj:
	ADMUX|=0x20;
	read|=ADCL<<7;
	read|=(short)(((short)ADCH)<<8);
	break;
	case right_Adj:
	ADMUX|=0x00;
	read|=ADCL;
	read|=(short)(((short)ADCH)<<8);
	break;
}
*/
