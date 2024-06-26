/*
 * DIO_MCAL.h
 *
 * Created: 3/22/2023 12:52:38 PM
 *  Author: Win-0
 */ 


#ifndef DIO_MCAL_H_
#define DIO_MCAL_H_
#include "..\lib\atmega.h"
#define DIO_PORTB  0
#define DIO_PORTC  1
#define DIO_PORTD  2
#define OUTPUT 1
#define INPUT 0
#define PIN_0 0
#define PIN_1 1
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5
#define PIN_6 6
#define PIN_7 7
#define HIGH 1
#define LOW  0
void  DIGITAL_WRITE_PIN_PORT(char port,char pin,char mode);
char  DIGITAL_READ(char port,char pin);
void DIGITAL_WRITE_DDR_pins(char port,char pin,char mode);
void  DIGITAL_WRITE_PORT(char port,char val);
void DIGITAL_WRITE_DDR(char port,char val);

#endif /* DIO_MCAL_H_ */