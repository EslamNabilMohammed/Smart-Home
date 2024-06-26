#include "DIO_MCAL.h"
void  DIGITAL_WRITE_PIN_PORT(char port,char pin,char mode)
/*   to write on the port           */
{
	switch	(mode)
	{
		case HIGH:
		switch(port)
		{
			case DIO_PORTB:
			set_bit(PORTB,pin);
			break;
			case DIO_PORTC:
			set_bit(PORTC,pin);
			break;
			case DIO_PORTD:
			set_bit(PORTD,pin);
			break;
		}
		break;
		case LOW:
		switch(port)
		{
			case DIO_PORTB:
			clear_bit(PORTB,pin);
			break;
			case DIO_PORTC:
			clear_bit(PORTC,pin);
			break;
			case DIO_PORTD:
			clear_bit(PORTD,pin);
			break;
		}
		break;
	}
}
void DIGITAL_WRITE_DDR_pins (char port,char pin,char mode)
/*      TO WRITE ON   DDR  */
{
	switch(mode)
	{
		case  INPUT:
		switch(port)
		{
			case DIO_PORTB:
			clear_bit(DDRB,pin);
			break;
			case DIO_PORTC:
			clear_bit(DDRC,pin);
			break;
			case DIO_PORTD:
			clear_bit(PORTD,pin);
			break;
		}
		break;
		case OUTPUT:
		switch(port)
		{
			case DIO_PORTB:
			set_bit(DDRB,pin);
			break;
			case DIO_PORTC:
			set_bit(DDRC,pin);
			break;
			case DIO_PORTD:
			set_bit(PORTD,pin);
			break;
		}
		break;		
	}
}
 char val;	
char  DIGITAL_READ(char port,char pin)
{
	switch(port)
	{
		case DIO_PORTB:
		val= get_bit(PINB,pin);
		break;
		case DIO_PORTC:
		val= get_bit(PINC,pin);
		break;
		case DIO_PORTD:
		val= get_bit(PIND,pin);
		break;
	}
	return val;
}
void  DIGITAL_WRITE_PORT(char port,char val)
{
	switch(port)
	{
		case DIO_PORTB:
		PORTB=val;
		break;
			case DIO_PORTC:
			PORTC=val;
			break;
			case DIO_PORTD:
			PORTD=val;
				break;
	}
}
void  DIGITAL_WRITE_DDR(char port,char val)
{
	
	switch(port)
	{
		case DIO_PORTB:
		DDRB=val;
		break;
		case DIO_PORTC:
		DDRC=val;
		break;
		case DIO_PORTD:
		DDRD=val;
		break;
	}
}