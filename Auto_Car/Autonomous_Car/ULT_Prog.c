/*******************************************************************************/
/***************    Name : Mohamed Esam Saied  *********************************/
/***************    Date : 29/11/2023          *********************************/
/***************    SWC  : ULT_Driver          *********************************/
/***************    Version : 1.0              *********************************/
/*******************************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"
# define F_CPU 16000000UL
#include <util/delay.h>
#include "EXTI_interface.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include "GI_interface.h"
#include "Timer_interface.h"
#include "Timer_private.h"
#include "ULT_Private.h"
#include "ULT_Config.h"
#include "ULT_Interface.h"

static u16 volatile TIMER1_OVER_FLOW = 0;
volatile  u8  ex_count=1;
volatile  f32 distance=0;
volatile  u16 start_time=0,end_time=0,timeDiff=0;
volatile  u16 ovfCounter_start,ovfCounter_end;
extern volatile   u16 OvfCounter;


void ULT_VoidInit(void)
{
	DIO_u8SetPinDirection(ECHO_PORT,ECHO_PIN,DIO_INPUT);      
	DIO_u8SetPinDirection(TRIGGER_PORT,DIO_PIN0,DIO_OUTPUT);  
	EXTI_VoidSetCallBack(&EXTI_Voidaction);                             
}

void ULT_VoidsendTrigger(void)

{
	DIO_u8SetPinValue(TRIGGER_PORT,TRIGGER_PIN,DIO_HIGH);    
	_delay_us(10);                                             
	DIO_u8SetPinValue(TRIGGER_PORT,TRIGGER_PIN,DIO_LOW);     
}

void ULT_Voidget_Distance(f32* returned_distance)
{
	ULT_VoidsendTrigger();                                 
	EXTI_VoidEnable(EXTI_u8_INT0,EXTI_u8_RISING_EDGE);                  
	_delay_ms(50);                                             
	*returned_distance=distance;                              
}



void EXTI_Voidaction(void)                                       
{
	
	if (ex_count<=2)          
	{
		if (ex_count==1)      
		{
			// store the start time value
			start_time=TIM_TCNT0;
			
			// store number of OVFs at the start of the signal
			ovfCounter_start=OvfCounter;
			
			// at the first entry  we change the capture edge to falling edge to capture echo signal
			EXTI_VoidEnable(EXTI_u8_INT0,EXTI_u8_FALLING_EDGE);
			
		}
		
		else if(ex_count==2) // check if it's the second entry
		{
			//store end time value
			end_time=TIM_TCNT0;
			
			//store number of OVFs at the end of signal
			ovfCounter_end=OvfCounter;
			
			//calculate the time difference between start and end
			timeDiff=(end_time+(256*ovfCounter_end))-(start_time+(256*ovfCounter_start));
			
			//calculate the distance
			distance=timeDiff*0.068;// 	f32 ton=(h*(64/16000000))/2 >> 	*distance=ton*34000;
			
			//reset the counter to calculate new signal
			ex_count=0;
			
		}
		
		//increase the counter to sync with the entry state
		ex_count++;
	}
	
}