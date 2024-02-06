


#ifndef TIMER_REG_H_
#define TIMER_REG_H_

#define TMR0_NORMAL_MODE            1
#define TMR0_CTC_MODE               2
#define TMR0_FAST_PWM_MODE          3


#define    TIM_TCCR0     (*(volatile u8*)0x53)
#define    TIM_TCNT0     (*(volatile u8*)0x52)
#define    TIM_OCR0      (*(volatile u8*)0x5C)
#define    TIM_TIFR      (*(volatile u8*)0x58)
#define    TIM_TIMSK     (*(volatile u8*)0x59)

#define   TIM_CS00         0
#define   TIM_CS01         1
#define   TIM_CS02         2
#define   TIM_WGM01        3
#define   TIM_COM00        4
#define   TIM_COM01        5
#define   TIM_WGM00        6
#define   TIM_FOC0         7



#define    TIM_TOIE0        0
#define    TIM_OCIE0        1



#define    TIM_TOV0         0
#define    TIM_OCF0         1

#endif