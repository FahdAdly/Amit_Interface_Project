/*
 * SE_M.c
 * Created: 12/10/2023 1:32:14 AM
 * Author: FAHD9
 */

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "LCD_inteface.h"
#include "ULT_Interface.h"
#include "servo_interface.h"

 volatile f32 dis;
 volatile f32 dis_R, dis_L;

void SE_Inti()
{
    //Configure TIMER1
    TCCR1A |= (1 << COM1A1) | (1 << COM1B1) | (1 << WGM11); //NON Inverted PWM
    TCCR1B |= (1 << WGM13) | (1 << WGM12) | (1 << CS11) | (1 << CS10); //PRESCALER=64 MODE 14(FAST PWM)
    ICR1 = 4999;                                                     //FPWM=50Hz (Period = 20ms Standard).
    DDRD |= (1 << PIND5);
}

void Wait()
{
    _delay_ms(650);
}

void SE_R_Move()
{
	OCR1A=90;   //90 degree
	Wait();
}

void SE_L_Move()
{
	OCR1A=315;   //180 degree
	Wait();
}

void SE_Org_Position()
{
	OCR1A=186;   //0 degree
	Wait();
}

void Interrupt_Inti()
{
    DDRD &= ~(1 << PD3); // Change to PD3 for INT1
    PORTD |= (1 << PD3);
    MCUCR |= (1 << ISC11); // Change to ISC11 for falling edge trigger
    MCUCR &= ~(1 << ISC10);
    GICR |= (1 << INT1); // Change to INT1
    SET_BIT(SREG, 7);
}

void INT1_ISR(void) // Change from INT0_ISR to INT1_ISR
{
	ULT_Voidget_Distance(&dis);
	if(dis<40)
	{
    
	SE_R_Move();   //180 degree
	
    ULT_Voidget_Distance(&dis_R);
    /*DISTANCE RIGHT*/
    LCD_Voidclear();
    LCD_VoidsendString((u8 *)"R-dist.:");
    LCD_VoidsendNumber(dis_R);
    LCD_VoidsendString((u8 *)" cm");
    _delay_ms(50);
    LCD_Voidclear();
    
    SE_Org_Position();   //90 degree
    
    SE_L_Move();   //0 degree
    ULT_Voidget_Distance(&dis_L);
    /*DISTANCE LEFT*/
    LCD_VoidsendString((u8 *)"L-dist.:");
    LCD_VoidsendNumber(dis_L);
    LCD_VoidsendString((u8 *)" cm");
    _delay_ms(10);
	
	SE_Org_Position();   //90 degree
	
    GIFR |= (1 << INTF1); // Change to INTF1
	}
}

void __vector_2(void) __attribute__((signal)); // Change vector number
void __vector_2(void)
{
    INT1_ISR(); // Change from vector_1 to vector_2
}
