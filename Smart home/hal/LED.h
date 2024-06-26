/*
 * LED.h
 *
 * Created: 3/22/2023 2:07:08 PM
 *  Author: Win-0
 */ 
#include "..\mcal\DIO_MCAL.h"
#ifndef LED_H_
#define LED_H_
#define F_CPU 16000000
#include "util\delay.h"
#define led_1_port DIO_PORTB
#define led_2_port DIO_PORTB
#define led_3_port DIO_PORTB
#define led_4_port DIO_PORTB
#define led1_pin PIN_0
#define led2_pin PIN_1
#define led3_pin PIN_6
#define led4_pin PIN_4

void LED_ON(unsigned char port,unsigned char pin);
void LED_OFF(unsigned char port,unsigned char pin);
void LED_toggle(char port,char pin);
void led_init(char port,char pin);
#endif /* LED_H_ */