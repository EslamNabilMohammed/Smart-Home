#include "LED.h"

void LED_ON(unsigned char port,unsigned char pin)
{
	
	DIGITAL_WRITE_PIN_PORT(port,pin,HIGH);
}
void LED_OFF(unsigned char port,unsigned char pin)
{
	
	
	DIGITAL_WRITE_PIN_PORT(port,pin,LOW);
	
	
}

void LED_toggle(char port,char pin)
{

 DIGITAL_WRITE_PIN_PORT(port,pin,HIGH);
 _delay_ms(100);
 DIGITAL_WRITE_PIN_PORT(port,pin,LOW);
}

void led_init(char port,char pin)
{
	DIGITAL_WRITE_DDR_pins(port,pin,OUTPUT);
}