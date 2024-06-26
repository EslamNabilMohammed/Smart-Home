/*
 * BUZZER.c
 *
 * Created: 7/19/2023 5:46:24 PM
 *  Author: Win-0
 */ 
#include "BUZZER.h"
void buzzer_on(void)
{
	DIGITAL_WRITE_DDR_pins(buzzer_port,buzzer_pin,OUTPUT);
	DIGITAL_WRITE_PIN_PORT(buzzer_port,buzzer_pin,HIGH);
}
void buzzer_off(void)
{
	DIGITAL_WRITE_PIN_PORT(buzzer_port,buzzer_pin,LOW);
}
