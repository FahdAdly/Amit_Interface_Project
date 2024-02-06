

/*Library*/
# include "BIT_MATH.h"
# include "STD_TYPES.h"
# define F_CPU 16000000UL
# include <util/delay.h>
/*MCAL*/
#include "DIO_private.h"
# include "DIO_interface.h"

/*HAL*/
# include "LCD_config.h"
# include "LCD_inteface.h"
# include "LCD_private.h"

void LCD_Voidinit(void)
{
	DIO_u8SetPinDirection(LCD_RS_PORT, LCD_RS_PIN, DIO_OUTPUT);
	DIO_u8SetPinDirection(LCD_RW_PORT, LCD_RW_PIN, DIO_OUTPUT);
	DIO_u8SetPinDirection(LCD_E_PORT, LCD_E_PIN, DIO_OUTPUT);
	DIO_u8SetPinDirection(LCD_D4_PORT, LCD_D4_PIN, DIO_OUTPUT);
	DIO_u8SetPinDirection(LCD_D5_PORT, LCD_D5_PIN, DIO_OUTPUT);
	DIO_u8SetPinDirection(LCD_D6_PORT, LCD_D6_PIN, DIO_OUTPUT);
	DIO_u8SetPinDirection(LCD_D7_PORT, LCD_D7_PIN, DIO_OUTPUT);
	
	_delay_ms(10);
	
	DIO_u8SetPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_LOW);   
	
	DIO_u8SetPinValue(LCD_RW_PORT,LCD_RW_PIN,DIO_LOW);   
	
	private_writeHalfPort(0b0010);
	DIO_u8SetPinValue(LCD_E_PORT,LCD_E_PIN,DIO_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_E_PORT,LCD_E_PIN,DIO_LOW);
	// Function Set
	LCD_VoidsendComand(0b00101000);
	_delay_ms(40);
	//Display ON/OFF
	LCD_VoidsendComand(0b00001111);
	_delay_us(40);
	//Display Clear
	LCD_VoidsendComand(0b00000001);
	_delay_ms(3);
	
	LCD_VoidsendComand(0b00000110);
}

void LCD_VoidsendComand (u8 comand)
{
	
	DIO_u8SetPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_LOW);   

	DIO_u8SetPinValue(LCD_RW_PORT,LCD_RW_PIN,DIO_LOW);   
	
	
	private_writeHalfPort(comand>>4);
	
	
	
	DIO_u8SetPinValue(LCD_E_PORT,LCD_E_PIN,DIO_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_E_PORT,LCD_E_PIN,DIO_LOW);

	private_writeHalfPort(comand);
	
	
	DIO_u8SetPinValue(LCD_E_PORT,LCD_E_PIN,DIO_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_E_PORT,LCD_E_PIN,DIO_LOW);

}


void LCD_VoidsendChar(u8 Char)
{
	DIO_u8SetPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_HIGH);   // RS=1
	
	DIO_u8SetPinValue(LCD_RW_PORT,LCD_RW_PIN,DIO_LOW);   //RW =0
	
	
	private_writeHalfPort(Char>>4);
	
	DIO_u8SetPinValue(LCD_E_PORT,LCD_E_PIN,DIO_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_E_PORT,LCD_E_PIN,DIO_LOW);
	private_writeHalfPort(Char);
	
	DIO_u8SetPinValue(LCD_E_PORT,LCD_E_PIN,DIO_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_E_PORT,LCD_E_PIN,DIO_LOW);
	
	
	
}

void LCD_VoidsendString(u8* Str)
{
	u8 counter=0;
	while(Str[counter]!='\0')
	{
		LCD_VoidsendChar(Str[counter]);
		++counter;
	}
}
void LCD_Voidclear(void)
{
	LCD_VoidsendComand(0b00000001);
	_delay_ms(2);
}



static void  private_writeHalfPort(u8 value)
{
	
	if (GET_BIT(value,0)==1)
	{
		DIO_u8SetPinValue(LCD_D4_PORT,LCD_D4_PIN,DIO_HIGH);
	}
	else
	{
		DIO_u8SetPinValue(LCD_D4_PORT,LCD_D4_PIN,DIO_LOW);
	}
	if (GET_BIT(value,1)==1)
	{
		DIO_u8SetPinValue(LCD_D5_PORT,LCD_D5_PIN,DIO_HIGH);
	}
	else
	{
		DIO_u8SetPinValue(LCD_D5_PORT,LCD_D5_PIN,DIO_LOW);
	}
	
	if (GET_BIT(value,2)==1)
	{
		DIO_u8SetPinValue(LCD_D6_PORT,LCD_D6_PIN,DIO_HIGH);
	}
	else
	{
		DIO_u8SetPinValue(LCD_D6_PORT,LCD_D6_PIN,DIO_LOW);
	}
	
	if (GET_BIT(value,3)==1)
	{
		DIO_u8SetPinValue(LCD_D7_PORT,LCD_D7_PIN,DIO_HIGH);
	}
	else
	{
		DIO_u8SetPinValue(LCD_D7_PORT,LCD_D7_PIN,DIO_LOW);
	}
	
	
}



void LCD_VoidsendNumber(s32 number)
{
	u8 count=0;
	u8 reminder,arr[16]={0,0,0,0,0};
	if (number < 0)
	{
		LCD_VoidsendChar('-');
		number=number * -1;
	}
	else if (number == 0)
	{
		LCD_VoidsendChar('0');
		
	}
	while (number != 0)
	{
		reminder = number % 10; 
		arr[count]=reminder; 
		number=number/10;    
		count++;
		
	}
	

	s8 num_count;
	for(num_count =(count-1);num_count>=0;num_count--)
	{
		LCD_VoidsendChar(arr[num_count]+'0');
		
	}
	
	
	
}