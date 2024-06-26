/*
 * HAL.h
 *
 * Created: 3/22/2023 12:53:13 PM
 *  Author: Win-0
 */ 

#include "..\mcal\DIO_MCAL.h"
#ifndef	MOTOR_H_
#define MOTOR_H_
#define motor_1_port    DIO_PORTB
#define motor_1_pin0    PIN_1
#define motor_1_pin1    PIN_2
#define motor_1_enable  PIN_3
#define motor_2_port    DIO_PORTC
#define motor_2_pin0    PIN_3
#define motor_2_pin1    PIN_4
#define motor_2_enable  PIN_5
void motor_on_right( );

void motor_off();
void motor_on_left( );



#endif /* HAL_H_ */