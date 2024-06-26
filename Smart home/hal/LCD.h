/*
 * LCD.h
 *
 * Created: 4/7/2023 4:49:11 AM
 *  Author: Win-0
 */ 
#ifndef LCD_H_
#define LCD_H_
/*--------------------lcd_mcaros--------------------*/
#define lcd_4_bit_DDR          DIO_PORTC
#define lcd_4_bit_port         DIO_PORTC
#define lcd_4_bit_pin0         PIN_0
#define lcd_4_bit_pin1         PIN_1
#define lcd_4_bit_pin2         PIN_2
#define lcd_4_bit_pin3         PIN_3
#define lcd_4_bit_enable_pin   PIN_5
#define lcd_4_bit_RS_pin       PIN_4
#define lcd_4_bit_RS_reg       DIO_PORTC
#define lcd_4_bit_enable_reg   DIO_PORTC
/*-----------------8_BIT data & port------------*/
#define lcd_8_bit_DDR				DIO_PORTD
#define lcd_8_bit_enable_DDR		DIO_PORTB
#define lcd_8_bit_RS_DDR			DIO_PORTB
#define lcd_8_bit_port_data       DIO_PORTD
#define lcd_8_bit_enable_port  DIO_PORTB
#define lcd_8_bit_RS_port      DIO_PORTB
#define lcd_8_bit_pin0          PIN_0
#define lcd_8_bit_pin1          PIN_1
#define lcd_8_bit_pin2          PIN_2
#define lcd_8_bit_pin3          PIN_3
#define lcd_8_bit_pin4          PIN_4
#define lcd_8_bit_pin5          PIN_5
#define lcd_8_bit_pin6          PIN_6
#define lcd_8_bit_pin7          PIN_7
#define lcd_8_bit_enable_pin    PIN_1
#define lcd_8_bit_RS_pin        PIN_0
/*----------------- macro commands------------------*/
#define  lcd_clear  0x01
#define  lcd_return_home  0x02
#define  lcd_entry_mode_increment_shift_off  0x06
#define  lcd_entry_mode_increment_shift_on   0x07
#define  lcd_entry_mode_decrement_shift_off  0x04
#define  lcd_entry_mode_decrement_shift_on   0x05
#define  lcd_diplay_data                     0x0c
#define lcd_shift_right_cursor              0x14
#define lcd_shift_left_cursor               0x10
#define lcd_shift_left_display              0x18
#define lcd_shift_right_display             0x1d
/*  char font 5*7  send 4_bit  */
#define lcd_4_bit_one_line                  0x20 
#define lcd_4_bit_two_line                  0x28
/*  char font 5*7  send 8_bit  */
#define lcd_8_bit_one_line                  0x30
#define lcd_8_bit_two_line                  0x38
#define set_lcd_CGRAM_address               0x40
#define set_lcd_DDRAM_address               0x80
#define row1                                 1
#define row2                                 2
#define row3                                 3
#define row4                                 4
/*--------------------------include---------------------------*/
#define F_CPU 16000000 /* to define freq*/
#include "util\delay.h" /*for delay*/
#include "string.h"
#include "stdio.h"
#include "..\mcal\DIO_MCAL.h" /*to deal with microcontrler*/
/*--------------------------data_types-----------------------*/

/*--------------------------software intefaces-----------------------*/
/*--------------------------4_bit------------------------------------*/
void lcd_4_bit_init();
void lcd_4_bit_send_command(char command);
void lcd_4_bit_send_character(char character);
void lcd_4_bit_send_character_position(char row,char column,char character);
void lcd_4_bit_send_string(char *str);
void lcd_4_bit_send_string_position(char row,char column,char *str);
void lcd_4_bit_send_custom_charactr(char row,char column,char ch[],char mem_pos);
/*--------------------------8_bit------------------------------------*/
void lcd_8_bit_init();
void lcd_8_bit_command(char command);
void lcd_8_bit_send_character(char character);
void lcd_8_bit_send_character_position(char row,char column,char character);
void lcd_8_bit_send_string(char *str);
void lcd_8_bit_send_string_position(char row,char column,char *str);
void lcd_8_bit_send_custom_charactr(char row,char column,char ch[],char mem_pos);
void lcd_4_bit_display_decimal_8_bit(unsigned char number);
void lcd_4_bit_display_decimal_16_bit(short number);
void lcd_4_bit_display_hexa(unsigned char number);
void lcd_4_bit_display_binary(unsigned char number);
#endif /* LCD_H_ */
