

/*Library*/
#include "BIT_MATH.h"
#include "STD_TYPES.h"

/*Mcal*/
#include "EXTI_Private.h"
#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "GI_interface.h"

static void (*priv_CallBackEXTI)(void)=NULL;



void EXTI_VoidEnable (EX_sou interSou,EX_trig interTrig)
{
	switch(interSou)
	{
		case EXTI_u8_INT0:
		switch(interTrig)    //EDGE INT0
		{
			case EXTI_u8_RISING_EDGE:
			SET_BIT (EX_MCUCR,EX_ISC00);
			SET_BIT (EX_MCUCR,EX_ISC01);
			break;
			
			case EXTI_u8_FALLING_EDGE:
			CLEAR_BIT (EX_MCUCR,EX_ISC00);
			SET_BIT (EX_MCUCR,EX_ISC01);
			break;
			
			case EXTI_u8_LOW_LEVEL:
			CLEAR_BIT (EX_MCUCR,EX_ISC00);
			CLEAR_BIT (EX_MCUCR,EX_ISC01);
			break;
			
			case EXTI_u8_ANY_LOGICAL_CHANGE:
			SET_BIT (EX_MCUCR,EX_ISC00);
			CLEAR_BIT (EX_MCUCR,EX_ISC01);
			break;
		}
		SET_BIT(EX_GICR,EX_INT0);  //Enable INT0
		break;
		
		case EXTI_u8_INT1:
		switch(interTrig)    // EDGE INT1
		{
			case EXTI_u8_RISING_EDGE:
			SET_BIT (EX_MCUCR,EX_ISC10);
			SET_BIT (EX_MCUCR,EX_ISC11);
			break;
			
			case EXTI_u8_FALLING_EDGE:
			CLEAR_BIT (EX_MCUCR,EX_ISC10);
			SET_BIT (EX_MCUCR,EX_ISC11);
			break;
			
			case EXTI_u8_LOW_LEVEL:
			CLEAR_BIT (EX_MCUCR,EX_ISC10);
			CLEAR_BIT (EX_MCUCR,EX_ISC11);
			break;
			
			case EXTI_u8_ANY_LOGICAL_CHANGE:
			SET_BIT (EX_MCUCR,EX_ISC10);
			CLEAR_BIT (EX_MCUCR,EX_ISC11);
			break;
			
		}
		SET_BIT(EX_GICR,EX_INT1);  //Enable INT1
		break;
		
		case EXTI_u8_INT2:
		 switch(interTrig)
		{
			case EXTI_u8_RISING_EDGE:
			SET_BIT (EX_MCUCSR,EX_ISC2);
			break;
			
			case EXTI_u8_FALLING_EDGE:
			CLEAR_BIT (EX_MCUCSR,EX_ISC2);
			break;
		}
		SET_BIT(EX_GICR,EX_INT2);  //Enable INT2
		break;
		
		
	}
	
	
	
}
void EXTI_VoidDisable(EX_sou interSou)
{
	switch(interSou)
	{
		case EXTI_u8_INT0:
		CLEAR_BIT(EX_GICR,EX_INT0);
		break;
		case EXTI_u8_INT1:
		CLEAR_BIT(EX_GICR,EX_INT1);
		break;
		case EXTI_u8_INT2:
		CLEAR_BIT(EX_GICR,EX_INT2);
		break;
		
	}
	
}

/*CALLBACK FUN*/
void EXTI_VoidSetCallBack(void(*ptrToFun)(void))
{
	if(ptrToFun!=NULL)
	{
		priv_CallBackEXTI = ptrToFun;
	}
}



void __vector_1(void)__attribute__((signal));
void __vector_1(void)
{
	
	if(priv_CallBackEXTI != NULL)
	{
		priv_CallBackEXTI();
	}
	
	

}