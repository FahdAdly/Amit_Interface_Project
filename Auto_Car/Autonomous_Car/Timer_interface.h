

# ifndef TIMER_INTERFACE_H
# define TIMER_INTERFACE_H

#define TIMER0	0
#define TIMER1	1
#define TIMER2	2



void TIM_Voidinit(void);
void TIM_Voidstart(void);
void TIM_Voidstop(void);

void TIM_VoidsetCallBackOVF(void(*ptrToFun)(void));
void TIM_VoidsetCallBackCTC(void(*ptrToFun)(void));

void TIM_VoidsetCompareMatchValue(u8 compareValue);
void TIM_VoidsetDelay_ms_usingCTC(u16 delay_ms);
void TIM_VoidsetDytyCycle (u8 dytyCycle);
# endif