/*
 * Relay.h
 *
 * Created: 9/16/2023 7:34:08 PM
 *  Author: Win-0
 */ 


#ifndef RELAY_H_
#define RELAY_H_
#define Relay_port DIO_PORTB
#define Relay_pin PIN_2
void Relay_init(void);
void Relay_on(void);




#endif /* RELAY_H_ */