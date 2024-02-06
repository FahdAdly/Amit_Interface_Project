


# ifndef DIO_PRIVATE_H
# define DIO_PRIVATE_H

# define DIO_u8_INITIAL_OUTPUT    1 
# define DIO_u8_INITIAL_INPUT     0

# define DIO_u8_INITIAL_HIGH      1
# define DIO_u8_INITIAL_LOW       0
# define DIO_u8_INPUT_FLOATING    0
# define DIO_u8_INPUT_PULLUP      1 

/* Macros For Registers */

# define PORTA  (*(volatile u8 *)0x3B)
# define DDRA   (*(volatile u8 *)0x3A)
# define PINA   (*(volatile u8 *)0x39)

# define PORTB  (*(volatile u8 *)0x38)  
# define DDRB   (*(volatile u8 *)0x37)
# define PINB   (*(volatile u8 *)0x36)

# define PORTC  (*(volatile u8 *)0x35)
# define DDRC   (*(volatile u8 *)0x34)
# define PINC   (*(volatile u8 *)0x33)

# define PORTD  (*(volatile u8 *)0x32)
# define DDRD   (*(volatile u8 *)0x31)
# define PIND   (*(volatile u8 *)0x30)

/* Macros Like Function */
#define conc(a,b,c,d,e,f,g,h)    conc_help(a,b,c,d,e,f,g,h)
#define conc_help(a,b,c,d,e,f,g,h)   0b##a##b##c##d##e##f##g##h


/*#define NULL 			 0*/

#define OK  			 0
#define NOK				 1
#define NULL_POINTER	 2
#define TIMEOUT_ERR		 3

#define BUSY_ERR	     4

#endif