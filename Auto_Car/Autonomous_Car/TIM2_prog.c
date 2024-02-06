/*
 * TIM2_prog.c
 *
 * Created: 12/19/2023 9:34:36 AM
 *  Author: hp
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIM2_private.h"
#include "TIM2_config.h"
#include "TIM2_interface.h"

void TIM2_Voidinit  (void)
{
	#if TIM2_MODE == TIM2_NORMAL_MODE
	// Select Normal mode
	CLEAR_BIT(TIM2_TCCR2,TIM2_WGM20);
	CLEAR_BIT(TIM2_TCCR2,TIM2_WGM21);
	
	// PRELOAD VALUE
	TIM2_TCNT2 =TIM2_PRELOAD_VALUE;


	// enable TMR OVER FLOW INTURRUPT
	SET_BIT (TIM2_TIMSK,TIM2_TOIE2);
	
	#elif TIM2_MODE == TIM2_CTC_MODE
	// Select CTC mode
	CLEAR_BIT(TIM2_TCCR2,TIM2_WGM20);
	SET_BIT(TIM2_TCCR2,TIM2_WGM21);
	
	//ENABLE OC
	SET_BIT(TIM2_TIMSK,TIM2_OCIE2);
	
	
	#elif TMR2_MODE == TMR2_FAST_PWM_MODE
	// Select FAST PWM mode
	SET_BIT(TIM2_TCCR2,TIM2_WGM20);
	SET_BIT(TIM2_TCCR2,TIM2_WGM21);
	
	// SELECT NON INVERTING MODE
	CLEAR_BIT(TIM2_TCCR2,TIM2_COM20);
	SET_BIT(TIM2_TCCR2,TIM2_COM21);
	
	
	
	
	#endif
	
}


void TIM2_Voidstart (void)
{
	//SET PRESCALER 64
	CLEAR_BIT(TIM2_TCCR2,TIM2_CS20);
	CLEAR_BIT(TIM2_TCCR2,TIM2_CS21);
	SET_BIT(TIM2_TCCR2,TIM2_CS22);
}


void TIM2_Voidstop  (void)
{
	
	// STOP
	CLEAR_BIT(TIM2_TCCR2,TIM2_CS20);
	CLEAR_BIT(TIM2_TCCR2,TIM2_CS21);
	CLEAR_BIT(TIM2_TCCR2,TIM2_CS22);
	
}

static void(*private_pCallBackOVF)(void)=NULL;

static void(*private_pCallBackCTC)(void)=NULL;


void TIM2_VoidsetCallBackOVF(void(*ptrToFun)(void))
{
	
	if (ptrToFun!=NULL)
	{
		private_pCallBackOVF=ptrToFun;
	}
}



void __vector_5(void)__attribute__((signal));

void __vector_5(void)
{
	static u16 ovfCounter=0;
	
	ovfCounter++;
	
	if(TIM2_OVER_FLOW_COUNTER == ovfCounter)
	{
		TIM2_TCNT2=TIM2_PRELOAD_VALUE;
		
		ovfCounter=0;
		if(private_pCallBackOVF!=NULL)
		{
			private_pCallBackOVF();
		}
	}
}



void TIM2_VoidsetCallBackCTC(void(*ptrToFun)(void))
{
	if(ptrToFun!=NULL)
	{
		private_pCallBackCTC=ptrToFun;
	}
}


void TIM2_VoidsetCompareMatchValue(u8 compareValue)
{
	TIM2_OCR2=compareValue;
}

volatile static u16 private_ctcCounter;

void __vector_4(void)__attribute__((signal));

void __vector_4(void)
{
	static u16 ctcCounter=0;
	
	ctcCounter++;
	
	if(private_ctcCounter== ctcCounter)
	{
		
		ctcCounter=0;
		if(private_pCallBackCTC!=NULL)
		{
			private_pCallBackCTC();
		}
	}
}



void TIM2_VoidsetDelay_ms_usingCTC   (u16 delat_ms)
{
	// under condition ticktime 4 micro second
	TIM2_OCR2=249;
	private_ctcCounter=delat_ms;
}


void TIM2_VoidsetDutyCycle           (u8 dutycylce)
{
	if (dutycylce<=100)
	{
		TIM2_OCR2=((dutycylce*256)/100)-1;
	}
}