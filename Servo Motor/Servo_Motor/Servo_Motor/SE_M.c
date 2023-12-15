/*
 * SE_M.c
 * Created: 12/10/2023 1:32:14 AM
 *  Author: FAHD9
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "SE_M.h"
#include "BIT_MATH.h"

void SE_Inti()
{
	//Configure TIMER1
	TCCR1A|=(1<<COM1A1)|(1<<COM1B1)|(1<<WGM11);        //NON Inverted PWM
	TCCR1B|=(1<<WGM13)|(1<<WGM12)|(1<<CS11)|(1<<CS10); //PRESCALER=64 MODE 14(FAST PWM)
	ICR1=5999;  //FPWM=50Hz (Period = 20ms Standard).
	DDRD|=(1<<PIND5);   
}
void Wait()
{
	_delay_ms(900);
}
void SE_Move()
{
		OCR1A=315;   //180 degree
		Wait();
		OCR1A=215;   //0 degree
		Wait();
		OCR1A=90;   //90 degree
		Wait();
}
void SE_Org_Position()
{
	OCR1A=215;   //0 degree
	Wait();
}
void SE_Control()
{
		SE_Move();	
		SE_Org_Position();
}
void Interrupt_Inti()
{
	DDRD &= ~(1 << PD2);
	PORTD |= (1 << PD2);
	MCUCR |= (1 << ISC01);
	MCUCR |= (1 << ISC00);
	GICR |= (1 << INT0);
	SET_BIT(SREG,7);
}
 void INT0_ISR(void) {
	SE_Control();
	GIFR |= (1 << INTF0);
}

void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	INT0_ISR();
}