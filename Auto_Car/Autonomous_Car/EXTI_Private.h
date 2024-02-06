


# ifndef EXTI_PRIVATE_H
# define EXTI_PRIVATE_H

#define  EX_MCUCR          (*(volatile u8*)0x55)
#define  EX_MCUCSR         (*(volatile u8*)0x54)
#define  EX_GICR           (*(volatile u8*)0x5B)
#define  EX_GIFR           (*(volatile u8*)0x5A)
#define  EX_ISC11           3
#define  EX_ISC10           2
#define  EX_ISC01           1
#define  EX_ISC00           0
#define  EX_ISC2            6

#define  EX_INT0            6
#define  EX_INT1            7
#define  EX_INT2            5

#define  INTF1           7
#define  INTF0           6
#define  INTF2           5

# endif