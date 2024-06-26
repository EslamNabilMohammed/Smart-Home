/*
 * atmega.h
 *
 * Created: 4/30/2023 11:33:10 AM
 *  Author: Eslam Nabil   
 */ 
#ifndef ATMEGA_H_
#define ATMEGA_H_
/********************REGISTERS ************************/
#define  PORTB  *((volatile unsigned char *)0x25)
#define  DDRB   *((volatile unsigned char *)0x24)
#define PINB   *((volatile unsigned char *)0x23)
#define PORTC  *((volatile unsigned char *)0x28)
#define DDRC   *((volatile unsigned char *)0x27)
#define PINC   *((volatile unsigned char *)0x26)
#define PORTD  *((volatile unsigned char *)0x2B)
#define DDRD   *((volatile unsigned char *)0x2A)
#define PIND   *((volatile unsigned char *)0x29)
/******************** Macros ************************/
#define get_bit(reg,bit) ((reg>>bit)&1)
#define set_bit(reg,bit) (reg|=(1<<bit))
#define clear_bit(reg,bit) (reg&=~(1<<bit))
#define toggle_bit(reg,bit) (reg^=(1<<bit))
#endif /* ATMEGA_H_ */