/*
 * timer1.h
 *
 * Created: 8/11/2023 6:24:54 PM
 *  Author: Win-0
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_
#define  TCCR1A   *((volatile char *)0x80)
#define  TCCR1B   *((volatile char *)0x81)
#define  TCCR1C   *((volatile char *)0x82)
#define  TCNT1H  *((volatile char *)0x85)
#define  TCNT1L  *((volatile char *)0x84)
#define  TCNT1   *((volatile short *)0x84)
#define  OCR1AH   *((volatile char *)0x89)
#define  OCR1AL   *((volatile char *)0x88)
#define  OCR1A    *((volatile short *)0x88)
#define  OCR1BH  *((volatile char *)0x8B)
#define  OCR1BL  *((volatile char *)0x8A)
#define  OCR1B     *((volatile short *)0x8A)
#define  TIMSK1  *((volatile char *)0x6F)
#define  TIFR1  *((volatile char *)0x36)
#define  ICR1H  *((volatile char *)0x87)
#define  ICR1L  *((volatile char *)0x86)
#define  ICR1  *((volatile short *)0x86)
#define ICR1_value 5000
#define fast_inverting_mode 0x80
#define  rising_edge 1
#define  falling_edge 0
#define  edge   rising_edge
#define OCR1A_value 1000

void timer1_init(char mode,char interrupt_type,char timer_prescaler);
char  timer1_set_call_back_overflow(void (*ptr)(void));
char timer1_set_call_back_ctcA(void (*ptr)(void));
void set_timer1_compareA(short reading);
void ICU_INIT(void);




#endif /* TIMER1_H_ */