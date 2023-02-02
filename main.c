/*
 * Cooler_System(NEW).c
 *
 * Created: 14-Sep-22 2:51:25 PM
 * Author : Aliaa
 */ 
#include "LCD.h"
#include "ADC.h"
#include "PWM.h"
#include "SEVEN_SEG.h"
#include "Cooler_app.h"
#include "TIMER0.h"

static void (ctc_isr)(void);

int main(void)
{
	
	Cooler_System_init();
	timer0_ctc_isr = ctc_isr;
	 TIMER0_CTC_init(250);
	
	while (1)
	{
		write_temp();
		check_on_temp();
	
		
	}
	
}
void (ctc_isr)(void)
{
	static uint16_t num_ADC=0;
	 num_ADC = (ADC_read()/2)+2;
	SEVEN_SEG_write(num_ADC);
	
	
	
	
	
}
