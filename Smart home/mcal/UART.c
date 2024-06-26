#include "UART.h"
#include "Std_types.h"
#include "..\lib\atmega.h"
#include "DIO_MCAL.h"
void UART_Init()
{
	/******************baud rate value **************/
	UBRR=baud_rate_value;
	/********************speed type***************/
	UCSRA&=speed_type;
     /**************frame format data,parity,stop*************/
	 /******************* 8bit data***************************/
	 set_bit(UCSRC,PIN_1);
	 set_bit(UCSRC,PIN_2);
	  /*********************check parity*********************/
	  UCSRC|=parity_mode;
	  /*****************number of stop bits *****************/
	  UCSRC|=stop_mode;
	  /**************************uart mode *****************/
	  UCSRC|=usart_mode;
	  /***********enable TX&RX ********************/
	  UCSRB|=0X18; 
}
void UART_Transmit(char data)
{
	/******************wait until the whole data has been shifted **************/
	while(get_bit(UCSRA,PIN_5)==0);
	UDR=data;
}
char UART_Receive()
{
	/******************wait until the receive register is empty **************/
		while(get_bit(UCSRA,PIN_7)==0);
		return UDR;
}
void UART_ReceiveStr(char* str)
{
	 char data;
	char iteration=0;
	while(data!='\r')
	{
		data=UART_Receive();
		str[iteration]=data;
		iteration++;
	}
	str[iteration]='\0';
}
void UART_TransmitStr(char* str)
{
	char iteration=0;
	while(str[iteration]!='\0')
	{
			while(get_bit(UCSRA,PIN_5)==0);
			UDR=str[iteration];
			iteration++;
	}
	UART_Transmit('\r');
}