/*
 * TIM2_private.h
 *
 * Created: 12/19/2023 9:33:39 AM
 *  Author: hp
 */ 


#ifndef TIM2_PRIVATE_H_
#define TIM2_PRIVATE_H_



#define TIM2_TCCR2 (*(volatile u8*)0x45) 
#define TIM2_TIFR  (*(volatile u8*)0x58)
#define TIM2_TCNT2 (*(volatile u8*)0x44) 
#define TIM2_OCR2  (*(volatile u8*)0x43)
#define TIM2_TIMSK (*(volatile u8*)0x59)

#define TIM2_CS20             0
#define TIM2_CS21             1
#define TIM2_CS22             2
#define TIM2_WGM21            3
#define TIM2_COM20            4
#define TIM2_COM21            5
#define TIM2_WGM20            6
#define TIM2_FOC2             7
//
#define TIM2_OCIE2            7
#define TIM2_TOIE2            6

// 
#define TIM2_OCF2             7
#define TIM2_TOV2             6


#define TIM2_NORMAL_MODE            1
#define TIM2_CTC_MODE               2
#define TIM2_FAST_PWM_MODE          3



#endif 