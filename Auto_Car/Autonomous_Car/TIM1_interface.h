/*
 * TIM1.h
 *
 * Created: 12/19/2023 9:26:50 AM
 *  Author: hp
 */ 


#ifndef TIM1_INTERFACE_H_
#define TIM1_INTERFACE_H_
void TMR1_Voidinit (void);
void TMR1_Voidstart(void);
void TMR1_Voidstop (void);

void TMR1_VoidsetCompareMatchValueA (u16 compareValue);
void TMR1_VoidsetFastPWM_usingMode14(f32 dytyCycle, u16 freq);





#endif /* TIM1_H_ */