/*
 * Cooler_app.h
 *
 * Created: 15-Sep-22 1:51:04 AM
 *  Author: Aliaa
 */ 


#ifndef COOLER_APP_H_
#define COOLER_APP_H_

#include "std_macros.h"
#include "LCD.h"
#include "ADC.h"
#include "PWM.h"
#include "SEVEN_SEG.h"
#include "TIMER0.h"

#define LED_BUZZ_PIN DDRA|=0b00000110;
#define LED(x)      if(x==1) SETBIT(PORTA,1); else CLRBIT(PORTA,1);
#define BUZZ(x)     if(x==1) SETBIT(PORTA,2); else CLRBIT(PORTA,2);
#define DC_MOTOR(x) if(x==1) SETBIT(DDRD,3); else CLRBIT(DDRD,3);

uint16_t num_ADC;
uint8_t duty;

void Cooler_System_init(void);

void write_temp(void);

void check_on_temp(void);





#endif /* COOLER_APP_H_ */