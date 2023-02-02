/*
 * Cooler_app.c
 *
 * Created: 15-Sep-22 1:51:21 AM
 *  Author: Aliaa
 */ 
#include "Cooler_app.h"

// uint16_t num_ADC;
//uint8_t duty;
/*****************************************************************************
* Function Name: Cooler_System_init
* Purpose      : Initialize the required components in the system
* Parameters   : void
* Return value : void
*****************************************************************************/

void Cooler_System_init(void)
{
	LED_BUZZ_PIN;
	LCD_init();
	TIMER1_PWM_oc1A_init();
	SEVEN_SEG_init();
	ADC_init();
}
/*****************************************************************************
* Function Name: write_temp
* Purpose      : write the temp on LCD and seven segment also write the duty in second line
* Parameters   : void
* Return value : void
*****************************************************************************/

void write_temp(void)
{
	num_ADC = (ADC_read()/2)+2;
	//SEVEN_SEG_write(num_ADC);
	LCD_write_command(0x80);
	//LCD_write_string("Temp =");
	LCD_write_num(num_ADC);
	LCD_write_command(0xc0);
	//LCD_write_string("duty=");

	
}
/*****************************************************************************
* Function Name: check_on_temp
* Purpose      : checks on the temp if it is higher than 35 then the dc motor, led and buzzer will be on 
                 also puts the duty cycle to control the speed of motor if it is 50C then the speed will be max
* Parameters   : void
* Return value : void
*****************************************************************************/

void check_on_temp(void)
{
	 num_ADC = (ADC_read()/2)+2;
	
	if (num_ADC >=35)
	{
		BUZZ(1);
		LED(1);
		DC_MOTOR(1);
		if((num_ADC>=35)&&(num_ADC<39))
		{
			duty=50;
			LCD_write_num(duty);
			TIMER1_PWM_oc1A_duty(duty);
		}
		else if((num_ADC>=39)&&(num_ADC<41))
		{
			duty=60;
			LCD_write_num(duty);
			TIMER1_PWM_oc1A_duty(duty);
		}
		else if((num_ADC>=41)&&(num_ADC<44))
		{
			duty=70;
			LCD_write_num(duty);
			TIMER1_PWM_oc1A_duty(duty);
		}
		else if((num_ADC>=44)&&(num_ADC<46))
		{
			duty=80;
			LCD_write_num(duty);
			TIMER1_PWM_oc1A_duty(duty);
		}
		else if((num_ADC>=46)&&(num_ADC<48))
		{
			duty=90;
			LCD_write_num(duty);
			TIMER1_PWM_oc1A_duty(duty);
		}
		else if((num_ADC>=48)&&(num_ADC<=50))
		{
			duty=100;
			LCD_write_num(duty);
			TIMER1_PWM_oc1A_duty(duty);
			
		}
		else
		{
			duty=0;
			LCD_write_num(duty);
			TIMER1_PWM_oc1A_duty(duty);
			_delay_ms(70);
		}
		
	}
	else
	{
		duty=0;
		BUZZ(0);
		LED(0);
		DC_MOTOR(0);
		LCD_write_num(duty);
		
	}
	
}