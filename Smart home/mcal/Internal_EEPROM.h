/*
 * Internal_EEPROM.h
 *
 * Created: 9/18/2023 3:18:09 PM
 *  Author: Win-0
 */ 


#ifndef INTERNAL_EEPROM_H_
#define INTERNAL_EEPROM_H_
#define  EEARL  *((volatile char *)0x41)
#define  EEARH  *((volatile char *)0x42)
#define  EEAR  *((volatile char *)0x41)
#define  EEDR  *((volatile char *)0x40)
#define  EECR  *((volatile char *)0x3F)
#define  SPMCSR  *((volatile char *)0x57)
#define EEPE  PIN_1
#define EEMPE PIN_2
void Internal_EEPROM_INIT(void);
void Internal_EEPROM_Write(char data,short address);
char Internal_EEPROM_Read(short address);



#endif /* INTERNAL_EEPROM_H_ */