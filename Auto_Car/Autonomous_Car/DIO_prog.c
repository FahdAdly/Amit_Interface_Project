


/* Include Library Layer*/
# include "BIT_MATH.h"
# include "STD_TYPES.h"

/*Include Mcal Layer*/
#include "DIO_private.h"
#include "DIO_interface.h"
#include "DIO_config.h"


void DIO_voidInit(void){
    DDRA = conc(DIO_U8_PA7_INITIAL_DIRECTION,DIO_U8_PA6_INITIAL_DIRECTION,DIO_U8_PA5_INITIAL_DIRECTION,DIO_U8_PA4_INITIAL_DIRECTION,DIO_U8_PA3_INITIAL_DIRECTION,DIO_U8_PA2_INITIAL_DIRECTION,DIO_U8_PA1_INITIAL_DIRECTION,DIO_U8_PA0_INITIAL_DIRECTION);
    DDRB = conc(DIO_U8_PB7_INITIAL_DIRECTION,DIO_U8_PB6_INITIAL_DIRECTION,DIO_U8_PB5_INITIAL_DIRECTION,DIO_U8_PB4_INITIAL_DIRECTION,DIO_U8_PB3_INITIAL_DIRECTION,DIO_U8_PB2_INITIAL_DIRECTION,DIO_U8_PB1_INITIAL_DIRECTION,DIO_U8_PB0_INITIAL_DIRECTION);
    DDRC = conc(DIO_U8_PC7_INITIAL_DIRECTION,DIO_U8_PC6_INITIAL_DIRECTION,DIO_U8_PC5_INITIAL_DIRECTION,DIO_U8_PC4_INITIAL_DIRECTION,DIO_U8_PC3_INITIAL_DIRECTION,DIO_U8_PC2_INITIAL_DIRECTION,DIO_U8_PC1_INITIAL_DIRECTION,DIO_U8_PC0_INITIAL_DIRECTION);
    DDRD = conc(DIO_U8_PD7_INITIAL_DIRECTION,DIO_U8_PD6_INITIAL_DIRECTION,DIO_U8_PD5_INITIAL_DIRECTION,DIO_U8_PD4_INITIAL_DIRECTION,DIO_U8_PD3_INITIAL_DIRECTION,DIO_U8_PD2_INITIAL_DIRECTION,DIO_U8_PD1_INITIAL_DIRECTION,DIO_U8_PD0_INITIAL_DIRECTION);

    PORTA = conc(DIO_U8_PA7_INITIAL_VALUE,DIO_U8_PA6_INITIAL_VALUE,DIO_U8_PA5_INITIAL_VALUE,DIO_U8_PA4_INITIAL_VALUE,DIO_U8_PA3_INITIAL_VALUE,DIO_U8_PA2_INITIAL_VALUE,DIO_U8_PA1_INITIAL_VALUE,DIO_U8_PA0_INITIAL_VALUE);
    PORTB = conc(DIO_U8_PB7_INITIAL_VALUE,DIO_U8_PB6_INITIAL_VALUE,DIO_U8_PB5_INITIAL_VALUE,DIO_U8_PB4_INITIAL_VALUE,DIO_U8_PB3_INITIAL_VALUE,DIO_U8_PB2_INITIAL_VALUE,DIO_U8_PB1_INITIAL_VALUE,DIO_U8_PB0_INITIAL_VALUE);
    PORTC = conc(DIO_U8_PC7_INITIAL_VALUE,DIO_U8_PC6_INITIAL_VALUE,DIO_U8_PC5_INITIAL_VALUE,DIO_U8_PC4_INITIAL_VALUE,DIO_U8_PC3_INITIAL_VALUE,DIO_U8_PC2_INITIAL_VALUE,DIO_U8_PC1_INITIAL_VALUE,DIO_U8_PC0_INITIAL_VALUE);
    PORTD = conc(DIO_U8_PD7_INITIAL_VALUE,DIO_U8_PD6_INITIAL_VALUE,DIO_U8_PD5_INITIAL_VALUE,DIO_U8_PD4_INITIAL_VALUE,DIO_U8_PD3_INITIAL_VALUE,DIO_U8_PD2_INITIAL_VALUE,DIO_U8_PD1_INITIAL_VALUE,DIO_U8_PD0_INITIAL_VALUE);
}

u8 DIO_u8SetPinDirection  (u8 copy_u8PortId, u8 copy_u8PinNumber, u8 copy_u8Direction){

    u8 Local_u8Error = STD_Sucesses ;

    if((copy_u8PortId<=DIO_u8_PORTD) && (copy_u8PinNumber <= DIO_PIN7) && ((copy_u8Direction == DIO_OUTPUT)||(copy_u8Direction == DIO_INPUT)))
    {
        switch(copy_u8PortId){

            case DIO_u8_PORTA :
                switch(copy_u8Direction){
                    case DIO_OUTPUT : SET_BIT(DDRA, copy_u8PinNumber);break;
                    case DIO_INPUT  : CLEAR_BIT(DDRA, copy_u8PinNumber);break;
                    default : Local_u8Error = STD_Error;
                }
            break;
            case DIO_u8_PORTB :
                switch(copy_u8Direction){
                    case DIO_OUTPUT : SET_BIT(DDRB, copy_u8PinNumber);break;
                    case DIO_INPUT  : CLEAR_BIT(DDRB, copy_u8PinNumber);break;
                    default : Local_u8Error = STD_Error;
                }
            break;
            case DIO_u8_PORTC :
                switch(copy_u8Direction){
                    case DIO_OUTPUT : SET_BIT(DDRC, copy_u8PinNumber);break;
                    case DIO_INPUT  : CLEAR_BIT(DDRC, copy_u8PinNumber);break;
                    default : Local_u8Error = STD_Error;
                }
            break;
            case DIO_u8_PORTD :
                switch(copy_u8Direction){
                    case DIO_OUTPUT : SET_BIT(DDRD, copy_u8PinNumber);break;
                    case DIO_INPUT  : CLEAR_BIT(DDRD, copy_u8PinNumber);break;
                    default : Local_u8Error = STD_Error;
                }
            break;
        }
    }
    else{
        Local_u8Error = STD_Error;
    }
    return Local_u8Error ; 

}

u8 DIO_u8SetPinValue      (u8 copy_u8PortId, u8 copy_u8PinNumber, u8 copy_u8Value){

    u8 Local_u8Error = STD_Sucesses ; 

    if((copy_u8PortId <= DIO_u8_PORTD) && (copy_u8PinNumber <= DIO_PIN7) && ((copy_u8Value == DIO_OUTPUT)||(copy_u8Value == DIO_INPUT)))
    {
        switch (copy_u8PortId)
        {
        case DIO_u8_PORTA:
            switch (copy_u8Value)
            {
            case DIO_HIGH : SET_BIT(PORTA, copy_u8PinNumber);break;
            case DIO_LOW  : CLEAR_BIT(PORTA, copy_u8PinNumber); break;
            default : Local_u8Error = STD_Error;
            }
            break;
        case DIO_u8_PORTB:
            switch (copy_u8Value)
            {
            case DIO_HIGH : SET_BIT(PORTB, copy_u8PinNumber);break;
            case DIO_LOW  : CLEAR_BIT(PORTB, copy_u8PinNumber); break;
            default : Local_u8Error = STD_Error;
            }
            break;
        case DIO_u8_PORTC:
            switch (copy_u8Value)
            {
            case DIO_HIGH : SET_BIT(PORTC, copy_u8PinNumber);break;
            case DIO_LOW  : CLEAR_BIT(PORTC, copy_u8PinNumber); break;
            default : Local_u8Error = STD_Error;
            }
            break;
        case DIO_u8_PORTD:
            switch (copy_u8Value)
            {
            case DIO_HIGH : SET_BIT(PORTD, copy_u8PinNumber);break;
            case DIO_LOW  : CLEAR_BIT(PORTD, copy_u8PinNumber); break;
            default : Local_u8Error = STD_Error;
            }
            break;
        
        default:
            break;
        }
    }
    else{
        Local_u8Error = STD_Error ;
    }
    return Local_u8Error = STD_Sucesses ;
}

u8 DIO_u8GetPinValue      (u8 copy_u8PortId, u8 copy_PinNumber, u8 * copy_u8PReturnedValue){
    u8 Local_u8Error = STD_Sucesses ; 
    u8 Local_pinVal = 0 ; 
    if((copy_u8PortId <= DIO_u8_PORTD) && (copy_PinNumber <= DIO_PIN7) && (copy_u8PReturnedValue != NULL))
    {
        switch(copy_u8PortId){
            case DIO_u8_PORTA : 
                Local_pinVal = GET_BIT(PINA, copy_PinNumber);
                if (Local_pinVal == 0){
                    * copy_u8PReturnedValue = DIO_HIGH ;
                }
                else{
                    * copy_u8PReturnedValue = DIO_LOW ;
                }
            break;
            case DIO_u8_PORTB : 
                Local_pinVal = GET_BIT(PINB, copy_PinNumber);
                if (Local_pinVal == 0){
                    * copy_u8PReturnedValue = DIO_HIGH ;
                }
                else{
                    * copy_u8PReturnedValue = DIO_LOW ;
                }
            break;
            case DIO_u8_PORTC : 
                Local_pinVal = GET_BIT(PINC, copy_PinNumber);
                if (Local_pinVal == 0){
                    * copy_u8PReturnedValue = DIO_HIGH ;
                }
                else{
                    * copy_u8PReturnedValue = DIO_LOW ;
                }
            break;
            case DIO_u8_PORTD : 
                Local_pinVal = GET_BIT(PIND, copy_PinNumber);
                if (Local_pinVal == 0){
                    * copy_u8PReturnedValue = DIO_HIGH ;
                }
                else{
                    * copy_u8PReturnedValue = DIO_LOW ;
                }
            break;
            default : Local_u8Error = STD_Error ;

        }
    }
    else{
        Local_u8Error = STD_Error ; 
    }

return Local_u8Error ;
}

u8 DIO_u8SetPortDirection (u8 copy_u8PortId, u8 copy_u8Direction){

    u8 Local_u8Error = STD_Sucesses ; 
    if((copy_u8PortId <= DIO_u8_PORTD) && ((copy_u8Direction == DIO_INPUT)||(copy_u8Direction == DIO_OUTPUT))){

        switch(copy_u8PortId){

            case DIO_u8_PORTA:
                switch (copy_u8Direction)
                {
                case DIO_OUTPUT : DDRA = 0xff;break;
                case DIO_INPUT  : DDRA = 0x00;break;
                default:
                    Local_u8Error = STD_Error ;
                }
            break ; 
            case DIO_u8_PORTB : 
                switch (copy_u8Direction)
                {
                case DIO_OUTPUT : DDRB = 0xff;break;
                case DIO_INPUT  : DDRB = 0x00;break;
                default:
                    Local_u8Error = STD_Error ;
                }
            break;
            case DIO_u8_PORTC : 
                switch (copy_u8Direction)
                {
                case DIO_OUTPUT : DDRC = 0xff;break;
                case DIO_INPUT  : DDRC = 0x00;break;
                default:
                    Local_u8Error = STD_Error ;
                }
            break;
            case DIO_u8_PORTD : 
                switch (copy_u8Direction)
                {
                case DIO_OUTPUT : DDRD = 0xff;break;
                case DIO_INPUT  : DDRD = 0x00;break;
                default:
                    Local_u8Error = STD_Error ;
                }
            break;
            default: Local_u8Error = STD_Error ; 
        }
    }
    else{
        Local_u8Error = STD_Error ; 
    }
    return Local_u8Error ; 
}

u8 DIO_u8SetPortValue     (u8 copy_u8PortId, u8 copy_u8PortValue){
    u8 Local_u8Error = STD_Sucesses ; 
 
        switch (copy_u8PortId)
        {
        case DIO_u8_PORTA: PORTA = copy_u8PortValue ;break;
        case DIO_u8_PORTB: PORTB = copy_u8PortValue ;break; 
        case DIO_u8_PORTC: PORTC = copy_u8PortValue ;break; 
        case DIO_u8_PORTD: PORTD = copy_u8PortValue ;break; 
        default: Local_u8Error = STD_Error ; 
        }

        Local_u8Error = STD_Error ; 
    
    return Local_u8Error ; 
}

u8 DIO_u8GetPortValue(u8 copy_u8portId, u8 * copy_u8PPortValue){
    u8 Local_u8Error = STD_Sucesses ; 

    if((copy_u8PPortValue <= DIO_u8_PORTD) && (copy_u8PPortValue != (u8 *)NULL)){
        switch (copy_u8portId)
        {
        case DIO_u8_PORTA : *copy_u8PPortValue = PINA ; break;
        case DIO_u8_PORTB : *copy_u8PPortValue = PINB ; break;
        case DIO_u8_PORTC : *copy_u8PPortValue = PINC ; break;
        case DIO_u8_PORTD : *copy_u8PPortValue = PIND ; break;
        default  : Local_u8Error = STD_Error ; 
        }
    }
    else{
        Local_u8Error = STD_Error ; 
    }
    return Local_u8Error ; 
}


