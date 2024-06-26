/*
 * LDR.h
 *
 * Created: 7/11/2023 5:17:12 AM
 *  Author: Win-0
 */ 


#ifndef LDR_H_
#define LDR_H_
/************************include ********************/
#include "..\mcal\ADC.h"
#include "..\mcal\DIO_MCAL.h"
/************************** MACROS ******************/
#define adjustment right_Adj
#define channel_pin channel_2

/**************************** return voltage *****************/
short LDR_READING(void);



#endif /* LDR_H_ */