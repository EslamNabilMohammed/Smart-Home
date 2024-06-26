/*
 * BUZZER.h
 *
 * Created: 7/19/2023 5:46:11 PM
 *  Author: Win-0
 */ 


#ifndef BUZZER_H_
#define BUZZER_H_
#include "..\mcal\DIO_MCAL.h"
#include "..\lib\atmega.h"
#define buzzer_port DIO_PORTC
#define buzzer_pin PIN_3
void buzzer_on(void);
void buzzer_off(void);




#endif /* BUZZER_H_ */