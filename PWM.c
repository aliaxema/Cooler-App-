/*
 * TIMER1.c
 *
 * Created: 21-Aug-22 9:50:47 PM
 *  Author: Aliaa
 */ 
#include "PWM.h"

/*****************************************************************************
* Function Name: TIMER1_PWM_oc1A_init
* Purpose      :init timer1 pin oc1a PWM (fast freq, 10bit, non inverting, no prescaler)
* Parameters   : void
* Return value : void
*****************************************************************************/
void TIMER1_PWM_oc1A_init(void){
	SETBIT(DDRD,5);
	SETBIT(TCCR1A,COM1A1); // set non inverting mode
	SETBIT(TCCR1A,WGM10);  // set FAST frq 10bit
	SETBIT(TCCR1A,WGM11);  // set FAST frq 10bit
	SETBIT(TCCR1B,WGM12);  // set FAST frq 10bit
	SETBIT(TCCR1B,CS10);   // No prescaler
	
}
/*
duty = (100 / 1023) * OCR1A


*/
void TIMER1_PWM_oc1A_duty(uint8_t duty){
	OCR1A = duty * 10.23;
}
/*
void TIMER1_ICM_init(void)
{
	//we will use it in the normal mode
	TCCR1A =0;
	TCNT1 = 0;
	SETBIT(PORTD,6); //input capture on this pin as an input
	//SETBIT(TCCR1A,COM1A0); //toggle
	SETBIT(TCCR1B,ICES1);//input capture edge select it is on rising edge
	SETBIT(TCCR1B,CS10);// no prescaler
	SETBIT(TIMSK,TICIE1); //input capture interrupt enable
	SETBIT(TIMSK,TOIE1); //timer overflow interrupt enable
	CLRBIT(TIFR,ICF1);
}
void TIMER1_ICM_rising(void)
{
	SETBIT(TCCR1B,ICES1);//input capture edge select it is on rising edge
}
void TIMER1_ICM_falling(void)
{
	CLRBIT(TCCR1B,ICES1);
}*/