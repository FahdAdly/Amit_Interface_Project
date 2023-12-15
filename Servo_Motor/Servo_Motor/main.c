
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "SE_M.h"

int main()
{
   	SE_Inti();
	Interrupt_Inti();
   while(1)
   {
	  
   }
}