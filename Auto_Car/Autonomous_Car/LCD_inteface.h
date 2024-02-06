

# ifndef LCD_INTERFACE_H
# define LCD_INTERFACE_H
/*Macros*/
void LCD_Voidinit(void);                    
void LCD_VoidsendChar(u8 Char);				
void LCD_VoidsendComand (u8 comand) ;       
void LCD_VoidsendString(u8* Str);
void LCD_Voidclear(void);
void LCD_VoidsendNumber (s32 num);
#endif