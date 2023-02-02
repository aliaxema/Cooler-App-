/*
 * SEVEN_SEG.h
 *
 * Created: 8/13/2022 12:53:05 PM
 *  Author: Aliaa
 */ 


#ifndef SEVEN_SEG_H_
#define SEVEN_SEG_H_

#include "std_macros.h"

#define INIT_SEVEN_SEG_PINS DDRB |= 0b11111100;

void SEVEN_SEG_init(void);
void SEVEN_SEG_write(uint8_t data);

#define EN1(x) if(x == 1) SETBIT(PORTB,3); else CLRBIT(PORTB,3);
#define EN2(x) if(x == 1) SETBIT(PORTB,2); else CLRBIT(PORTB,2);
#define A(x)  if(x == 1) SETBIT(PORTB,4); else CLRBIT(PORTB,4);
#define B(x)  if(x == 1) SETBIT(PORTB,5); else CLRBIT(PORTB,5);
#define C(x)  if(x == 1) SETBIT(PORTB,6); else CLRBIT(PORTB,6);
#define D(x)  if(x == 1) SETBIT(PORTB,7); else CLRBIT(PORTB,7);



#endif /* SEVEN_SEG_H_ */