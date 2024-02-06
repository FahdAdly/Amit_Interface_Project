/*
 * MOTOR_interface.h
 *
 * Created: 12/17/2023 9:28:48 PM
 *  Author: hp
 */ 
#define CRITICAL_u8_DISTANCE 		80
#define CAR_u16_OBSTCALE_SKIP_TIME 	1000
#define SERVO_u8_DELAY				200

#ifndef MOTOR_INTERFACE_H_
#define MOTOR_INTERFACE_H_
#define M_1                      1
#define M_2                      2

#define M_CK_WISE                1
#define M_COUN_CK_WISE           2

void Motor_Init(u8 motor_num);
void Car_Motor_On(u8 motor_num ,u8 motor_dir);
void Car_Speed(u8 motor_num,u8 motor_dir, u8 motor_speed);
void Car_Motor_Off(u8 motor_num);
void Car_Move(void);
void Car_Move_L(void);
void Car_Move_R(void);
void Car_Move_Back(void);
void Car_Stop(void);



/*IN1 C3*/
#define M_IN1_PORT   DIO_u8_PORTC
#define M_IN1_PIN    DIO_PIN3
/*IN2 C4*/
#define M_IN2_PORT   DIO_u8_PORTC
#define M_IN2_PIN    DIO_PIN4
/*IN3 C5*/
#define M_IN3_PORT   DIO_u8_PORTC
#define M_IN3_PIN    DIO_PIN5
/*IN4 C6*/
#define M_IN4_PORT   DIO_u8_PORTC
#define M_IN4_PIN    DIO_PIN6
/*E1 D4*/
#define M_E1_PORT   DIO_u8_PORTC
#define M_E1_PIN    DIO_PIN0
/*E2 D4*/
#define M_E2_PORT   DIO_u8_PORTC
#define M_E2_PIN    DIO_PIN0




#endif 