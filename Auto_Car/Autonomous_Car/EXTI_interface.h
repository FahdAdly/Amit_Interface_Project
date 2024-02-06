


# ifndef EXTI_INTERFACE_H
# define EXTI_INTERFACE_H


typedef enum
{
	EXTI_u8_INT0,
	EXTI_u8_INT1,
	EXTI_u8_INT2
}EX_sou;

typedef enum
{
	EXTI_u8_RISING_EDGE,
	EXTI_u8_FALLING_EDGE,
	EXTI_u8_LOW_LEVEL,
	EXTI_u8_ANY_LOGICAL_CHANGE
}EX_trig;

void EXTI_VoidEnable (EX_sou interSou,EX_trig interTrig);
void EXTI_VoidDisable(EX_sou interSou);
void EXTI_VoidSetCallBack(void(*ptrToFun)(void));
# endif