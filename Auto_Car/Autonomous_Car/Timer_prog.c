


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Timer_config.h"
#include "Timer_interface.h"
#include "Timer_private.h"
#include "DIO_private.h"
#include "DIO_interface.h"

static void (*private_pCallBackCTC)(void)=NULL;

volatile static u16 private_ctcCounter;

void TIM_Voidinit (void)
{
	#if TMR0_MODE == TMR0_NORMAL_MODE
	//SET AS Normal Mode
	CLEAR_BIT(TIM_TCCR0,TIM_WGM00);
	CLEAR_BIT(TIM_TCCR0,TIM_WGM01);

	TIM_TCNT0=TMR0_PRELOAD_VALUE;
	// ENABLE INTERRUPT OF OVERFLOW
	SET_BIT(TIM_TIMSK,TIM_TOIE0);
	
	#elif TMR0_MODE == TMR0_CTC_MODE
	SET_BIT(TIM_TCCR0,TIM_WGM01);
	CLEAR_BIT(TIM_TCCR0,TIM_WGM00);
	// ENABLE INTERRUPT OF COMPARE MATCH
	SET_BIT(TIM_TIMSK,TIM_OCIE0);
	
	
	#elif TMR0_MODE == TMR0_FAST_PWM_MODE
	SET_BIT(TIM_TCCR0,TIM_WGM01);
	SET_BIT(TIM_TCCR0,TIM_WGM00);
	
	CLEAR_BIT(TIM_TCCR0,TIM_COM00);
	SET_BIT(TIM_TCCR0,TIM_COM01);
	
	#endif
}


void TIM_Voidstart  (void)
{
	// Select Prescaler Value = 64
	SET_BIT(TIM_TCCR0,TIM_CS00);
	SET_BIT(TIM_TCCR0,TIM_CS01);
	CLEAR_BIT(TIM_TCCR0,TIM_CS02);
}

void TIM_Voidstop                (void)
{
	// Select Prescaler Value = 0
	
	CLEAR_BIT(TIM_TCCR0,TIM_CS00);
	CLEAR_BIT(TIM_TCCR0,TIM_CS01);
	CLEAR_BIT(TIM_TCCR0,TIM_CS02);
	
}


void TIM_VoidsetCompareMatchValue(u8 compareValue)
{
	TIM_OCR0=compareValue;
}

void TMR_setDelay_ms_usingCTC(u16 delay_ms)
{
	// under condition tick time 4 MS
	TIM_OCR0 = 249;
	private_ctcCounter = delay_ms;
	
}

void TIM_VoidsetDytyCycle (u8 dytyCycle)
{
	// under condition non inverting fast pwm
	if(dytyCycle<=100)
	{
		TIM_OCR0 = ((dytyCycle*256)/100)-1;
	}
}





void TIM_VoidsetCallBackCTC(void(*ptrToFun)(void))
{
	if(ptrToFun!=NULL)
	{
		private_pCallBackCTC = ptrToFun;
	}
}




void __vector_10(void) __attribute__ ((signal));
void __vector_10(void)
{
	static u16 ctcCounter = 0;
	ctcCounter++;
	
	if(private_ctcCounter == ctcCounter)
	{
		// Clear Counter
		ctcCounter = 0;
		
		//call action
		if(private_pCallBackCTC != NULL)
		{
			private_pCallBackCTC();
		}
	}
}

volatile u16 OvfCounter = 0;

void __vector_11(void)__attribute__((signal));
void __vector_11(void)
{
	OvfCounter++;
}
