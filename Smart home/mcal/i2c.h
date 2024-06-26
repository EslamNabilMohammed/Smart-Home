	/*
 * i2c.h
 *
 * Created: 9/14/2023 1:38:58 PM
 *  Author: Win-0
 */ 


#ifndef I2C_H_
#define I2C_H_
#define TWBR  *((volatile char *)0xB8)
#define TWCR  *((volatile char *)0xBC)
#define TWSR  *((volatile char *)0xB9)
#define TWDR  *((volatile char *)0xBB)
#define TWAR  *((volatile char *)0xBA)
#define TWAMR  *((volatile char *)0xBD)
enum prescaler
{
 normal=1,
 prescaler_4=4,
 prescaler_16=16,
 prescaler_64=64,	
};
typedef enum
{
	I2C_OK=1,
	I2C_SC_ERROR,
	I2C_RS_ERROR,
	I2C_SLAVE_ERROR,
	I2C_TRA_ERROR,
	I2C_REC_ERROR,
	}TWI_ERROR;
#define prescaler_value normal
/*clock frequency to determine value in twi bit rate value */
#define clock_Freq 400000
/*************** funcation ******/
void I2C_MASTER_INIT(void);
void I2C_SLAVE_INIT(char address);
TWI_ERROR I2C_START(void);
TWI_ERROR I2C_REPSTART(void);
void I2C_STOP(void);
TWI_ERROR I2C_SLAVE_Write(char address);
TWI_ERROR I2C_SLAVE_Read(char address);
TWI_ERROR I2C_transmit(char data);
TWI_ERROR I2C_receive(char *read);


#endif /* I2C_H_ */