

# ifndef DIO_INTERFACE_H
# define DIO_INTERFACE_H

/* Port Macros*/
# define DIO_u8_PORTA   0 
# define DIO_u8_PORTB   1
# define DIO_u8_PORTC   2
# define DIO_u8_PORTD   3

/* Pin Macros*/
# define DIO_PIN0 0
# define DIO_PIN1 1
# define DIO_PIN2 2
# define DIO_PIN3 3
# define DIO_PIN4 4
# define DIO_PIN5 5
# define DIO_PIN6 6
# define DIO_PIN7 7

/* Direction Macros */
# define DIO_OUTPUT 1
# define DIO_INPUT  0

/*Macros for High*/
# define DIO_HIGH   1
# define DIO_LOW    0


/* Function Prototype*/
void DIO_voidInit(void) ; 

u8   DIO_u8SetPinDirection  (u8 copy_u8PortId, u8 copy_u8PinNumber, u8 copy_u8Direction);

u8   DIO_u8SetPinValue      (u8 copy_u8PortId, u8 copy_u8PinNumber, u8 copy_u8Value);

u8   DIO_u8GetPinValue      (u8 copy_u8PortId, u8 copy_PinNumber, u8 * copy_u8PReturnedValue);

u8   DIO_u8SetPortDirection (u8 copy_u8PortId, u8 copy_u8Direction);

u8   DIO_u8SetPortValue     (u8 copy_u8portId, u8 copy_u8PortValue);

u8  DIO_u8GetPortValue     (u8 copy_u8portId, u8 * copy_u8PPortValue);



# endif