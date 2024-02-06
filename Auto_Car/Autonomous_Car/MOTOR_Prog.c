/*
 * MOTOR_Prog.c
 *
 * Created: 12/17/2023 9:28:24 PM
 *  Author: hp
 */ 
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_private.h"
#include "DIO_interface.h"
# define F_CPU 16000000UL
#include <util/delay.h>
#include "TIM2_interface.h"
#include "MOTOR_interface.h"

void Motor_Init(u8 motor_num)
{
	DIO_u8SetPinDirection(M_E1_PORT,M_E1_PIN,DIO_OUTPUT);    
	DIO_u8SetPinDirection(M_E2_PORT,M_E2_PIN,DIO_OUTPUT);     
	
	DIO_u8SetPinDirection(M_IN1_PORT,M_IN1_PIN,DIO_OUTPUT);     
	DIO_u8SetPinDirection(M_IN2_PORT,M_IN2_PIN,DIO_OUTPUT);      
	
	DIO_u8SetPinDirection(M_IN3_PORT,M_IN3_PIN,DIO_OUTPUT);       
	DIO_u8SetPinDirection(M_IN4_PORT,M_IN4_PIN,DIO_OUTPUT);       
	
	TIM2_Voidinit();
	TIM2_Voidstart();
	
	switch(motor_num)
	{
		
		case M_1 :
		DIO_u8SetPinValue(M_E1_PORT,M_E1_PIN,DIO_HIGH);
		break;
		
		case M_2 :
		DIO_u8SetPinValue(M_E2_PORT,M_E2_PIN,DIO_HIGH);
		break;
	}
	
	
}
void Car_Motor_On(u8 motor_num ,u8 motor_dir)
{  switch(motor_num)
	{
		case M_1 :
		switch(motor_dir)
		{
			case  M_CK_WISE :
			DIO_u8SetPinValue (M_IN1_PORT,M_IN1_PIN,DIO_HIGH);
			DIO_u8SetPinValue(M_IN2_PORT,M_IN2_PIN,DIO_LOW);
			break;
			
			case M_COUN_CK_WISE:
			DIO_u8SetPinValue(M_IN2_PORT,M_IN2_PIN,DIO_HIGH);
			DIO_u8SetPinValue(M_IN1_PORT,M_IN1_PIN,DIO_LOW);
			break;
		}
		
		break;
		
		case M_2:
		switch(motor_dir)
		{
			case  M_CK_WISE :
			DIO_u8SetPinValue(M_IN3_PORT,M_IN3_PIN,DIO_HIGH);
			DIO_u8SetPinValue(M_IN4_PORT,M_IN4_PIN,DIO_LOW);
			break;
			
			case M_COUN_CK_WISE:
			DIO_u8SetPinValue(M_IN4_PORT,M_IN4_PIN,DIO_HIGH);
			DIO_u8SetPinValue(M_IN3_PORT,M_IN3_PIN,DIO_LOW);
			break;
		}
		break;
	}
	
}
void Car_Speed(u8 motor_num,u8 motor_dir, u8 motor_speed)
{
	DIO_u8SetPinDirection(DIO_u8_PORTD,DIO_PIN7,DIO_OUTPUT);       
	
	TIM2_VoidsetDutyCycle(motor_speed);
	switch(motor_num)
	{
		case M_1 :
		
		switch(motor_dir)
		{
			case  M_CK_WISE :
			DIO_u8SetPinValue (M_IN1_PORT,M_IN1_PIN,DIO_HIGH);
			DIO_u8SetPinValue (M_IN2_PORT,M_IN2_PIN,DIO_LOW);
			break;
			
			case M_COUN_CK_WISE:
			DIO_u8SetPinValue (M_IN2_PORT,M_IN2_PIN,DIO_HIGH);
			DIO_u8SetPinValue (M_IN1_PORT,M_IN1_PIN,DIO_LOW);
			break;
		}
		
		break;
		case M_2:
		switch(motor_dir)
		{
			case  M_CK_WISE :
			DIO_u8SetPinValue (M_IN3_PORT,M_IN3_PIN,DIO_HIGH);
			DIO_u8SetPinValue (M_IN4_PORT,M_IN4_PIN,DIO_LOW);
			break;
			
			case M_COUN_CK_WISE:
			DIO_u8SetPinValue (M_IN4_PORT,M_IN4_PIN,DIO_HIGH);
			DIO_u8SetPinValue (M_IN3_PORT,M_IN3_PIN,DIO_LOW);
			break;
		}
		break;
	}
	
	
	
	
}
void Car_Motor_Off(u8 motor_num)
{
	switch(motor_num)
	{
		case M_1 :
		DIO_u8SetPinValue (M_IN1_PORT,M_IN1_PIN,DIO_LOW);
		DIO_u8SetPinValue (M_IN2_PORT,M_IN2_PIN,DIO_LOW);
		break;
		
		case M_2:
		DIO_u8SetPinValue (M_IN3_PORT,M_IN3_PIN,DIO_LOW);
		DIO_u8SetPinValue (M_IN4_PORT,M_IN4_PIN,DIO_LOW);
		break;
	}
	
}
void Car_Stop(void)
{
	Car_Motor_Off(M_1);
	Car_Motor_Off(M_2);
}
void Car_Move(void)
{
	Car_Motor_On(M_1 ,M_CK_WISE);
	Car_Motor_On(M_2 ,M_CK_WISE);
}

void Car_Move_R(void)
{
	Car_Motor_On(M_1 ,M_CK_WISE);
	Car_Motor_Off(M_2);
	_delay_ms(1000);
	Car_Motor_Off(M_1);
	Car_Motor_Off(M_2);
}
void Car_Move_L(void)
{
	Car_Motor_On(M_2 ,M_CK_WISE);
	Car_Motor_Off(M_1);
	_delay_ms(1000);
	Car_Motor_Off(M_1);
	Car_Motor_Off(M_2);
}
void Car_Move_Back(void)
{
	Car_Motor_On(M_1 ,M_COUN_CK_WISE);
	Car_Motor_On(M_2 ,M_COUN_CK_WISE);
}