

#include "STD_TYPES.h"
# include "bit_math.h"
# include "GI_interface.h"


# define GI_SREG           *((volatile u8*)0x5f)


void GI_voidEnable(void)
{
    SET_BIT(GI_SREG, 7);
}

void GI_voidDisable(void)
{
    CLEAR_BIT(GI_SREG, 7);
}