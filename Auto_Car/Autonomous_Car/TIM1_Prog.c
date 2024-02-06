/*
 * TIM1.c
 *
 * Created: 12/19/2023 9:26:34 AM
 *  Author: hp
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIM1_private.h"
#include "TIM1_interface.h"


void TMR1_Voidinit (void)
{
	
	CLEAR_BIT(TIM1_TCCR1A,TIM1_WGM10);
	SET_BIT(TIM1_TCCR1A,TIM1_WGM11);
	SET_BIT(TIM1_TCCR1B,TIM1_WGM12);
	SET_BIT(TIM1_TCCR1B,TIM1_WGM13);
	
	CLEAR_BIT(TIM1_TCCR1A,TIM1_COM1A0);
	SET_BIT(TIM1_TCCR1A,TIM1_COM1A1);
	
	
}
void TMR1_Voidstart(void)
{
	
	SET_BIT(TIM1_TCCR1B,TIM1_CS10);
	SET_BIT(TIM1_TCCR1B,TIM1_CS11);
	CLEAR_BIT(TIM1_TCCR1B,TIM1_CS12);
	
}
void TMR1_Voidstop (void)
{
	CLEAR_BIT(TIM1_TCCR1B,TIM1_CS10);
	CLEAR_BIT(TIM1_TCCR1B,TIM1_CS11);
	CLEAR_BIT(TIM1_TCCR1B,TIM1_CS12);
	
}


void TMR1_VoidsetCompareMatchValueA (u16 compareValue)
{
	
	TIM1_OCR1A=compareValue;

}


void TMR1_VoidsetFastPWM_usingMode14(f32 dytyCycle, u16 freq)
{
	if(dytyCycle <= 100)
	{
		
		
		TIM1_ICR1  = ((1000000UL/freq)/4)-1;
		
		TIM1_OCR1A = ((dytyCycle*(TIM1_ICR1+1))/100.0)-1;
	}
}