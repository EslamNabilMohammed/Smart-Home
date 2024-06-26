/*
 * IR.h
 *
 * Created: 9/17/2023 10:26:30 PM
 *  Author: Win-0
 */ 


#ifndef IR_H_
#define IR_H_
#define IR1_PORT DIO_PORTB
#define IR1_pin  PIN_0
#define IR2_PORT DIO_PORTB
#define IR2_pin  PIN_1
#define IR3_PORT DIO_PORTB
#define IR3_pin  PIN_2
#define IR4_PORT DIO_PORTB
#define IR4_pin  PIN_3
#define IR5_PORT DIO_PORTB
#define IR5_pin  PIN_4
#define IR6_PORT DIO_PORTB
#define IR6_pin  PIN_2
void IR_INIT(char port, char pin);
char IR_Read(char port, char pin);






#endif /* IR_H_ */