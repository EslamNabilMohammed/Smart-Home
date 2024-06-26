/*
 * UART.h
 *
 * Created: 7/16/2023 11:26:37 PM
 *  Author: Win-0
 */ 


#ifndef UART_H_
#define UART_H_
#include "..\lib\atmega.h"
#include "DIO_MCAL.h"
/****************************macros **********************/
#define baud_rate_value 103
/*************************speed type ******************/
#define single_speed 0
#define Double_speed 2
#define speed_type single_speed
/***********************mode ****************/
#define usart_asyncr   0x00
#define usart_syncr   0x40
#define usart_spi   0xc0
#define usart_mode  usart_asyncr
/********************parity check ************************/
#define	parity_disabled 0x00
#define even_parity    0x20
#define odd_parity     0x30
#define parity_mode    parity_disabled
/*************************stop mode *********************/
#define single_stop  0x00
#define double_stop  0x08
#define stop_mode   double_stop
/***************************** REGISTERS *****************/
#define UDR *((volatile char *)0XC6)
#define UCSRC *((volatile char *)0XC2)
#define UCSRB *((volatile char *)0XC1)
#define UCSRA *((volatile char *)0XC0)
#define UBRRL *((volatile char *)0XC4)
#define UBRRH *((volatile char *)0xC5)
#define UBRR  *((volatile short *)0XC4)
/*******************************funcations*********************/
void UART_Init();
void UART_Transmit(char data);
char UART_Receive(void);
void UART_ReceiveStr(char *str);
void UART_TransmitStr(char* str);
#endif /* UART_H_ */