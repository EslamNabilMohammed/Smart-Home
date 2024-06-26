/*--------------------------include---------------------------*/

#include "LCD.h"

/*-------------------------helper fun fun--------------------------------*/
void lcd_4_bit_send_command_data(char command);
void lcd_enable_8bit();
/*-------------- 4bit lcd recieve 4bit higher then 4bit lower so we use this fun*/
void lcd_enable_4bit();
void lcd_enable_4bit()
{
	DIGITAL_WRITE_PIN_PORT(lcd_4_bit_enable_reg,lcd_4_bit_enable_pin,HIGH);
	_delay_ms(2);
	DIGITAL_WRITE_PIN_PORT(lcd_4_bit_enable_reg,lcd_4_bit_enable_pin,LOW);
}
/*-------------- 4bit lcd recieve 4bit higher then 4bit lower so we use this fun*/

/*--------------------------4_bit------------------------------------*/
void lcd_4_bit_init()
{
	DIGITAL_WRITE_DDR_pins(lcd_4_bit_DDR,lcd_4_bit_pin0,OUTPUT);
	DIGITAL_WRITE_DDR_pins(lcd_4_bit_DDR,lcd_4_bit_pin1,OUTPUT);
	DIGITAL_WRITE_DDR_pins(lcd_4_bit_DDR,lcd_4_bit_pin2,OUTPUT);
	DIGITAL_WRITE_DDR_pins(lcd_4_bit_DDR,lcd_4_bit_pin3,OUTPUT);
	DIGITAL_WRITE_DDR_pins(lcd_4_bit_enable_reg,lcd_4_bit_enable_pin,OUTPUT);
	DIGITAL_WRITE_DDR_pins(lcd_4_bit_RS_reg,lcd_4_bit_RS_pin,OUTPUT);
	_delay_ms(35);
	lcd_4_bit_send_command_data(0x02);
	lcd_4_bit_send_command(lcd_4_bit_two_line);
	_delay_us(45);
	lcd_4_bit_send_command( lcd_diplay_data);
	_delay_us(45);
	lcd_4_bit_send_command(lcd_clear);
	_delay_ms(2);
	lcd_4_bit_send_command(lcd_entry_mode_increment_shift_off);
}
void lcd_4_bit_send_command(char command)
{
	/*---------to init lcd we send s a set of command so rs=0,en should be at falling edge high followed by low after 1ms */
	/*-------------------output pins-------*/
	DIGITAL_WRITE_PIN_PORT(lcd_4_bit_RS_reg,lcd_4_bit_RS_pin,LOW); /*-----------RS=0-------*/
	lcd_4_bit_send_command_data(command>>4); /*-----------------------higher four bits-------------*/
	lcd_4_bit_send_command_data(command); /*----------------lower four bits--------------*/
}
void lcd_4_bit_send_command_data(char command)
{
	DIGITAL_WRITE_PIN_PORT(lcd_4_bit_port,lcd_4_bit_pin0,(command>>0) & 0x01);
	DIGITAL_WRITE_PIN_PORT(lcd_4_bit_port,lcd_4_bit_pin1,(command>>1) & 0x01);
	DIGITAL_WRITE_PIN_PORT(lcd_4_bit_port,lcd_4_bit_pin2,(command>>2) & 0x01);
	DIGITAL_WRITE_PIN_PORT(lcd_4_bit_port,lcd_4_bit_pin3,(command>>3) & 0x01);
	
	lcd_enable_4bit();
}
void lcd_4_bit_send_character(char character)
{
	DIGITAL_WRITE_PIN_PORT(lcd_4_bit_RS_reg,lcd_4_bit_RS_pin,HIGH);	/*-----------RS=1----------*/
	lcd_4_bit_send_command_data((character>>4));
	lcd_4_bit_send_command_data(character);
}
void lcd_4_bit_send_character_position(char row,char column,char character)
{
	column--;
	switch(row)
	{
		case row1:
		lcd_4_bit_send_command(0x80+column);
		break;
		case row2:
		lcd_4_bit_send_command(0xC0+column);
		break;
		case row3:
		lcd_4_bit_send_command(0x94+column);
		break;
		case row4:
		lcd_4_bit_send_command(0xD4+column);
		break;
		
	}
	lcd_4_bit_send_character(character);
	
	
}
void lcd_4_bit_send_string(char *str)
{
	int increment;
	for(increment=0;str[increment]!=0;increment++)
	lcd_4_bit_send_character(str[increment]);
}
void lcd_4_bit_send_string_position(char row,char column,char *str)
{       column--;
	int increment;
	switch(row)
	{
		case row1:
		lcd_4_bit_send_command(0x80+column);
		break;
		case row2:
		lcd_4_bit_send_command(0xC0+column);
		break;
		case row3:
		lcd_4_bit_send_command(0x94+column);
		break;
		case row4:
		lcd_4_bit_send_command(0xD4+column);
		break;
	}
	
	
	for(increment=0;str[increment]!=0;increment++)
	lcd_4_bit_send_character(str[increment]);
	
	
	
}
void lcd_4_bit_send_custom_charactr(char row,char column,char ch[],char mem_pos)
{
	char increment=0;
	lcd_4_bit_send_command(0x80+(8*mem_pos));
	for(increment=0;increment<=7;increment++)
	lcd_4_bit_send_character(ch[increment]);
	lcd_4_bit_send_character_position(row,column,mem_pos);
	
}

/*--------------------------8_bit------------------------------------*/
void lcd_enable_8bit()
{

	DIGITAL_WRITE_PIN_PORT(lcd_8_bit_enable_port,lcd_8_bit_enable_pin,HIGH);
	_delay_ms(1);
	DIGITAL_WRITE_PIN_PORT(lcd_8_bit_enable_port,lcd_8_bit_enable_pin,LOW);
}
void lcd_8_bit_init()
{
	DIGITAL_WRITE_DDR(lcd_8_bit_DDR,0b11111111); /*-------------------output pins-------*/
	DIGITAL_WRITE_DDR_pins(lcd_8_bit_enable_port,lcd_8_bit_enable_pin,OUTPUT);  /*-------------------output pins-------*/
	DIGITAL_WRITE_DDR_pins(lcd_8_bit_enable_port,lcd_8_bit_RS_pin ,OUTPUT);
	_delay_ms(35);
	lcd_8_bit_command(lcd_8_bit_two_line);
	_delay_us(45);
	lcd_8_bit_command( lcd_diplay_data);
	_delay_us(45);
	lcd_8_bit_command(lcd_clear);
	_delay_ms(2);
	lcd_8_bit_command(lcd_entry_mode_increment_shift_off);
}
void lcd_8_bit_command(char command)
{
	/*---------to init lcd we send s a set of command so rs=0,en should be at falling edge high followed by low after 1ms */
	DIGITAL_WRITE_PIN_PORT(lcd_8_bit_RS_port,lcd_8_bit_RS_pin,LOW); /*------------- RS=0------------------*/
	DIGITAL_WRITE_PORT(lcd_8_bit_port_data,command);
	lcd_enable_8bit();
}
void lcd_8_bit_send_character(char character)
{
	DIGITAL_WRITE_PIN_PORT(lcd_8_bit_RS_port,lcd_8_bit_RS_pin,HIGH); /*------------- RS=1------------------*/
	DIGITAL_WRITE_PORT(lcd_8_bit_port_data,character);
	lcd_enable_8bit();
}
void lcd_8_bit_send_character_position(char row,char column,char character)
{
	column--;
	switch(row)
	{
		case row1:
		lcd_8_bit_command(0x80+column);
		break;
		case row2:
		lcd_8_bit_command(0xC0+column);
		break;
		case row3:
		lcd_8_bit_command(0x94+column);
		break;
		case row4:
		lcd_8_bit_command(0xD4+column);
		break;
		
	}
	lcd_8_bit_send_character(character);
	
}
void lcd_8_bit_send_string(char *str)
{
	int increment;
	for(increment=0;str[increment]!=0;increment++)
	{
		
		lcd_8_bit_send_character(str[increment]);
	}
}
void lcd_8_bit_send_string_position(char row,char column,char *str)
{
	column--;
	switch(row)
	{
		case row1:
		lcd_8_bit_command(0x80+column);
		break;
		case row2:
		lcd_8_bit_command(0xC0+column);
		break;
		case row3:
		lcd_8_bit_command(0x94+column);
		break;
		case row4:
		lcd_8_bit_command(0xD4+column);
		break;
		
	}
	int increment=0;
	for(increment=0;str[increment]!=0;increment++)
	{
		lcd_8_bit_send_character(str[increment]);
	}
	
}
void lcd_8_bit_send_custom_charactr(char row,char column,char ch[],char mem_pos)
{
	char increment=0;
	lcd_8_bit_command((set_lcd_CGRAM_address+8*mem_pos));     /*------CGRAM can contain 8custom char only in each line and the custom char is an array of char-------*/
	for (increment=0;increment<=7;increment++)
	{
		lcd_8_bit_send_character(ch[increment]);
	}
	lcd_8_bit_send_character_position(row,column,mem_pos);
	
}

void lcd_4_bit_display_decimal_8_bit(unsigned char number) /*-----------------8_bit number---------------------*/
{
	char str[4]={0};
	sprintf(str,"%i",number);
	lcd_4_bit_send_string(str);
}
/*------------ if you want to convert number more than 8 bit you will increase the size of array by number of digits and increase one digit for null terminator----- */
void lcd_4_bit_display_decimal_16_bit(short number)
{
	char str[6]={0};
	sprintf(str,"%i",number);
	lcd_4_bit_send_string(str);
}
void lcd_4_bit_display_hexa(unsigned char number)
{
	char str[4]={0};
	sprintf(str,"0x%x",number);
	lcd_4_bit_send_string(str);
}
void lcd_4_bit_display_binary(unsigned char number)
{
	unsigned char str[8]={0};
	for(char i=7;i>=0;i--)
	{
		str[i]=number%2;
		number/=2;
		if(i==0)
		break;
	}
	for(char i=0;i<8;i++)
	{
		if(str[i]==0)
		lcd_4_bit_send_character('0');
		else
		lcd_4_bit_send_character('1');
		
	}
	
}