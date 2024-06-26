/*
 * servo_motor.h
 *
 * Created: 8/15/2023 8:53:34 AM
 *  Author: Win-0
 */ 


#ifndef SERVO_MOTOR_H_
#define SERVO_MOTOR_H_
void servo_init();
void set_servo_angle(unsigned char angle);
void servo_ADC(char channel);
#endif /* SERVO_MOTOR_H_ */