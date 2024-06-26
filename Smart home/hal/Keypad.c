/*
 * Keypad.c
 *
 * Created: 4/20/2023 4:34:14 AM
 *  Author: Win-0
 */ 
/****************************** includes *****************/
#include "..\lib\atmega.h"
#include "..\mcal\DIO_MCAL.h"
#include "..\mcal\Std_types.h"
#include "Keypad.h"
#define F_CPU  16000000
#include <util/delay.h>
char Row_pins[Keybad_rows]={Keybad_row0,Keybad_row1,Keybad_row2,Keybad_row3};
char col_pins[Keybad_columns]={Keybad_col0,Keybad_col1,Keybad_col2,Keybad_col3};
char Keybad[Keybad_rows][Keybad_columns]=Keybad_keys;
 char Rows_counter=0;
 	char columns_counter=0;
	char Keybad_init(void)
	{
		for (Rows_counter=0;Rows_counter<Keybad_rows;Rows_counter++)
		{
			DIGITAL_WRITE_DDR_pins(Keybad_rows_port,Row_pins[Rows_counter],OUTPUT);
			DIGITAL_WRITE_DDR_pins(Keybad_columns_port,col_pins[Rows_counter],INPUT);
		}
		
	}
char Keybad_get_value(char *ptr)
{
	
	char Error_type=std_types_ok;
	if(ptr!=NULL)
	{
		*ptr=key_Not_pressed;
		for (Rows_counter=0;Rows_counter<Keybad_rows;Rows_counter++)
		{
			DIGITAL_WRITE_PIN_PORT(Keybad_rows_port,Row_pins[Rows_counter],HIGH);
			for (columns_counter=0;columns_counter<Keybad_columns;columns_counter++)
			{
				
				if (DIGITAL_READ(Keybad_columns_port,col_pins[columns_counter]))
				{	
					/**********************debouncing should be finished by delay to didnt get a random char *************/
					_delay_ms(20);
					while(DIGITAL_READ(Keybad_columns_port,col_pins[columns_counter]));
					/*********************** to get one char only one char *********/
					*ptr=Keybad[Rows_counter][columns_counter];
					break;
				
				}
			}
				DIGITAL_WRITE_PIN_PORT(Keybad_rows_port,Row_pins[Rows_counter],LOW);
			
		}
	}
	else
	Error_type=std_types_Nok;
	
	return Error_type;
	
	
	
}