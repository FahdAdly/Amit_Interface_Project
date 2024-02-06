/*
 * Autonomous_Car.c
 *
 * Created: 11/29/2023 9:28:33 PM
 * Author : hp
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
# define F_CPU 16000000UL
#include <util/delay.h>
#include "DIO_Private.h"
#include "DIO_interface.h"
#include "Timer_private.h"
#include "Timer_interface.h"
#include "TIM1_private.h"
#include "TIM1_interface.h"
#include "GI_interface.h"
#include "EXTI_interface.h"
#include "LCD_inteface.h"
#include "servo_interface.h"
#include "MOTOR_interface.h"
#include "ULT_Interface.h"


int main(void)
{
	
	volatile f32 dis=0;                      
	volatile f32 dis_R=0,dis_L=0;  
	
	/*INIT ALL FUN */
	GI_voidEnable();
	ULT_VoidInit();
	LCD_Voidinit();
	TIM_Voidinit();
	TIM_Voidstart();
	Motor_Init(M_1);
	Motor_Init(M_2);
	SE_Inti();
	Interrupt_Inti();
	
	SE_Org_Position();
	
	
	while(1)
	{
	
		dis=0;
		dis_R=0,dis_L=0;
		
		/*READ DISTANCE*/
		ULT_Voidget_Distance(&dis);
		
		/*CLEAR LCD  */
		LCD_Voidclear(); 
		//SEND STRING
		LCD_VoidsendString((u8*)"distance:");
		//SEND NUM OF THE DISTANCE
		LCD_VoidsendNumber(dis);
		//SEND STRING
		LCD_VoidsendString((u8*)" cm");
		_delay_ms(90);
		/*CLEAR LCD  */
		LCD_Voidclear();
				
		if(dis > 40)
		{
			/*GO RTO FW*/
			Car_Move();	
		}		
		else if(dis <= 40)
		{
			/*STOP CAR*/
			Car_Stop();		
			if (dis < 40)
			{
				Car_Move_Back();
				_delay_ms(50);
				Car_Stop();
			}
			
			SE_L_Move();
			
			/*DISTANCE LEFT*/
			ULT_Voidget_Distance(&dis);
			dis_L=dis;
			LCD_VoidsendString((u8*)"L-dist.:");
			LCD_VoidsendNumber(dis_L);
			LCD_VoidsendString((u8*)" cm");
			_delay_ms(90);
			LCD_Voidclear();
			
			//oreginal postion
			SE_Org_Position();
			
			SE_R_Move();
			
			/*DISTANCE RIGHT*/
			ULT_Voidget_Distance(&dis);
			dis_R=dis;
			LCD_Voidclear();
			LCD_VoidsendString((u8*)"R-dist.:");
			LCD_VoidsendNumber(dis_R);
			LCD_VoidsendString((u8*)" cm");
			_delay_ms(90);
			LCD_Voidclear();
			
			//oreginal postion
			SE_Org_Position();
			
			if (dis_L > dis_R)
			{
				LCD_Voidclear();
				LCD_VoidsendString((u8*)"Moving Left");
				Car_Move_L();
				LCD_Voidclear();
				
			}
			
			if ( dis_R>dis_L)
			{
				
				LCD_Voidclear();
				LCD_VoidsendString((u8*)"Moving Right");
				Car_Move_R();
				LCD_Voidclear();
			}
			
		}
	}
}
