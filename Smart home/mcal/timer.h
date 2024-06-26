/*
 * timerzero.h
 *
 * Created: 8/5/2023 6:58:49 PM
 *  Author: eslam nabil
 */ 

#ifndef TIMERZERO_H_
#define TIMERZERO_H_
/*************************addreese*************/
#define  TCCR0A   *((volatile char *)0x44)
#define  TCCR0B   *((volatile char *)0x45)
#define  TCNT0  *((volatile char *)0x46)
#define  OCR0A   *((volatile char *)0x47)
#define  OCR0B  *((volatile char *)0x48)
#define  TIMSK0  *((volatile char *)0x6E)
#define  TIFR0  *((volatile char *)0x35)


/***********************macros*****************/

#define compare_value 99
#define preload_value 0
#define overflow_number 625
#define toggle_pin  0x40
#define inverting_mode 0xc0
/********************for interrupts *****************/
enum timer0_mode
{
	normal,
	phase_correct,
	compare,
	fast_pwm
	};
enum timer0_interrupt
{
	no_interrupt,
	overflow,
	compareA,
	compareB
};

enum timer_prescale
{
normalprescale=1,
prescaler_8,
prescaler_64,
prescaler_256,
prescaler_1024,
external_clock_falling,
external_clock_rising,
};
/**********************FUNCATIONS***************/
void timer0_init(char mode,char interrupt_type,char timer_prescaler);
char  timer0_set_call_back_overflow(void (*ptr)(void));
char timer0_set_call_back_ctcA(void (*ptr)(void));
void control_intensity(char pre);

#endif /* TIMERZERO_H_ */