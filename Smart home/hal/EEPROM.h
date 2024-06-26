/*
 * EEPROM.h
 *
 * Created: 9/15/2023 2:48:59 PM
 *  Author: Win-0
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_
/************** MACROS ****************/
/************ I MADE IT 0X50 NOT 0XC0 AS WE MAKE A SHIFT IN SLAVE ADDRESS AND FIXED ADDRESS 1010A2A1A0 ******/
#define EEPROM_FIXED_ADDRESS 0X50
/******************** A2 oprints zero or one made by hard ware  ****************/
#define EEPROM_A2 0

/*********************** 8K that has 1024 address **************/
char EEPROM_WRITE(short address,char data);
char EEPROM_READ(short address,char *data);




#endif /* EEPROM_H_ */