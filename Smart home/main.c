#include "hal/MOTOR.h"
#include "hal/LED.h"
#include "hal/LCD.h"

#include "lib\atmega.h"
#define F_CPU 16000000
#include "util\delay.h"
#include "mcal/ADC.h"
#include "hal/LDR.h"
#include "mcal/UART.h"
#include "hal/BUZZER.h"
#include "hal/Button.h"
#include "mcal/global_interrupth.h"
#include "mcal/interrupt.h"
#include "hal/Keypad.h"
#include "hal/temp_sensor.h"
#include "mcal/i2c.h"
#include "hal/EEPROM.h"
#include "hal/IR.h"
#include "hal/servo_motor.h"
#include "mcal/Internal_EEPROM.h"
int main(void)
{
	char admin=1;
	char guest=5;
	char row=1;
	char welcome_terminate=0;
	char keypad_reading=key_Not_pressed;
	char Admin[4]={0};
	char Guest[4]={0};
	int counter=0;
	/******************* master mode ***************/
	lcd_4_bit_init();
	Keybad_init();
	Internal_EEPROM_INIT();
	led_init(led_1_port,led1_pin);
	led_init(led_2_port,led2_pin);
	led_init(led_3_port,led2_pin);
	
	 if (Internal_EEPROM_Read(0x0000)==0xff)
	 {
		
		  lcd_4_bit_send_string_position(1,1,"welcome for the");
		  lcd_4_bit_send_string_position(2,1,"first time");
		  _delay_ms(10);
		  lcd_4_bit_send_command(lcd_clear);
	 }
	 
          while(1)
		  {
			 Keybad_get_value(&keypad_reading);
			  if (admin<5 &&Internal_EEPROM_Read(0x0001)==0xff)
			  {
				  lcd_4_bit_send_string_position(1,1,"set admin pass");
				  
			  }
			  
			  if (keypad_reading!=key_Not_pressed&&admin<5&&Internal_EEPROM_Read(admin)==0xff)
			  {
				  
				  Internal_EEPROM_Write(keypad_reading,admin);
				  lcd_4_bit_send_character_position(2,admin,keypad_reading);
				  _delay_ms(10);
				  lcd_4_bit_send_character_position(2,admin,'*');
				  admin++;
				  
			  if (admin==5)
			  {
				   Keybad_get_value(&keypad_reading);
				  lcd_4_bit_send_command(lcd_clear);
				  lcd_4_bit_send_string("admin pass saved");
				  _delay_ms(10);
				   lcd_4_bit_send_command(lcd_clear);
				  
			  }
			  }
			  if (admin==5&&guest<9&&Internal_EEPROM_Read(guest)==0xff)
			  {
				  
				   lcd_4_bit_send_string_position(1,1,"set guest pass");
			  }
			  
			   
			    if (keypad_reading!=key_Not_pressed&&guest<9&&admin==5)
			    {
		
			
				    Internal_EEPROM_Write(keypad_reading,guest);
				    lcd_4_bit_send_character_position(2,guest-4,keypad_reading);
				    _delay_ms(10);
				    lcd_4_bit_send_character_position(2,guest-4,'*');
				    guest++;
					  if (guest==9)
					  {
						  Keybad_get_value(&keypad_reading);
						  lcd_4_bit_send_command(lcd_clear);
						  lcd_4_bit_send_string("guest pass saved");
						  _delay_ms(10);
						  lcd_4_bit_send_command(lcd_clear);
			
						  
					  }
				}
				  Internal_EEPROM_Write(welcome_terminate+1,0x00);
			if (Internal_EEPROM_Read(guest)!=0xff)
			{
				lcd_4_bit_send_string_position(1,1,"please choose mode");
				lcd_4_bit_send_string_position(2,1,"1-admin");
				lcd_4_bit_send_string_position(2,10,"2-guest");
				
			
					if (keypad_reading=='1')
					{
						
						lcd_4_bit_send_command(lcd_clear);
						lcd_4_bit_send_string_position(1,5,"  please enter  ");
						lcd_4_bit_send_string_position(2,5,"  Admin password ");
						_delay_ms(10);
					   lcd_4_bit_send_command(lcd_clear);
						for (counter=0;counter<4;counter++)
						{
							
							Admin[counter]=keypad_reading;
							lcd_4_bit_send_character_position(3,1,keypad_reading);
						}
						
							
				
						
							
					  
					
				  }
			}
		  }
	
	
	return 0;
}