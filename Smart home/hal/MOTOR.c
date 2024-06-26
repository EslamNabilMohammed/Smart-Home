#include "MOTOR.h"
void motor_on_right()
{
	DIGITAL_WRITE_DDR_pins(motor_1_port,motor_1_pin0,OUTPUT);
	DIGITAL_WRITE_DDR_pins(motor_1_port,motor_1_pin1,OUTPUT);
	DIGITAL_WRITE_PIN_PORT(motor_1_port,motor_1_pin0,LOW);
	DIGITAL_WRITE_PIN_PORT(motor_1_port,motor_1_pin1,HIGH);
}


void motor_off()
{
	DIGITAL_WRITE_PIN_PORT(motor_1_port,motor_1_pin0,LOW);
	DIGITAL_WRITE_PIN_PORT(motor_1_port,motor_1_pin1,LOW);
}

void motor_on_left()
{
	DIGITAL_WRITE_DDR_pins(motor_1_port,motor_1_pin0,OUTPUT);
	DIGITAL_WRITE_DDR_pins(motor_1_port,motor_1_pin1,OUTPUT);
	DIGITAL_WRITE_PIN_PORT(motor_1_port,motor_1_pin0,HIGH);
	DIGITAL_WRITE_PIN_PORT(motor_1_port,motor_1_pin1,LOW);
	
}

