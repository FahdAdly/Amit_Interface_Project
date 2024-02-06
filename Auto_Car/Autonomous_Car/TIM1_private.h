/*
 * TIM1_private.h
 *
 * Created: 12/19/2023 9:27:58 AM
 *  Author: hp
 */ 


#ifndef TIM1_PRIVATE_H_
#define TIM1_PRIVATE_H_


#define TIM1_TCCR1A             (*(volatile u8*)0x4F)
#define TIM1_TCCR1B             (*(volatile u8*)0x4E)
#define TIM1_TCNT1              (*(volatile u16*)0x4C)
#define TIM1_OCR1A              (*(volatile u16*)0x4A)
#define TIM1_OCR1B              (*(volatile u16*)0x48)
#define TIM1_ICR1               (*(volatile u16*)0x46)
#define TIM1_TIMSK              (*(volatile u8*)0x59)
#define TIM1_TIFR               (*(volatile u8*)0x58)



#define TIM1_WGM10              0
#define TIM1_WGM11              1
#define TIM1_FOC1B              2
#define TIM1_FOC1A              3
#define TIM1_COM1B0             4
#define TIM1_COM1B1             5
#define TIM1_COM1A0             6
#define TIM1_COM1A1             7
//
#define TIM1_CS10               0
#define TIM1_CS11               1
#define TIM1_CS12               2
#define TIM1_WGM12              3
#define TIM1_WGM13              4
#define TIM1_ICES1              6
#define TIM1_ICNC1              7
//
#define TIM1_TOIE1              2
#define TIM1_OCIE1B             3
#define TIM1_OCIE1A             4
#define TIM1_TICIE1             5
//
#define TIM1_ICF1               5




#endif 