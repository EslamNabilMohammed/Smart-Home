/*
 * watch_dog.h
 *
 * Created: 8/15/2023 9:04:08 AM
 *  Author: Win-0
 */ 


#ifndef WATCH_DOG_H_
#define WATCH_DOG_H_
#define WDTCSR   *((volatile char *)0x60)
#define MCUSR   *((volatile char *)0x54)
enum watch_prescaler
{
prescaler_2k,
prescaler_4k,
prescaler_8k,
prescaler_16k,
prescaler_32k,
prescaler_64k,
prescaler_128k,
prescaler_256k,
prescaler_512k,
prescaler_1024k	
};
void WDT_INIT(char prescaler);
void WDT_DISABLE();
#endif /* WATCH_DOG_H_ */