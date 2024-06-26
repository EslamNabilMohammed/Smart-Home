/*
 * Button.h
 *
 * Created: 7/19/2023 6:25:03 PM
 *  Author: Win-0
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
#include "..\lib\atmega.h"
#include "..\mcal\DIO_MCAL.h"
#define Button_port DIO_PORTD
#define Button_pin  PIN_2
char get_button_read(char port,char pin);




#endif /* BUTTON_H_ */