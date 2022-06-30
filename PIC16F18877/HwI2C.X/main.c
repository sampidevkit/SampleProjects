#include "libcomp.h"

void main(void)
{
    SYSTEM_Initialize();
    I2C_VBUS_SetHigh();
    MSSP2_I2C_Master_Init(100000);
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();

    while(1)
    {
        uint8_t tmp[2];
        
        CLRWDT();
        
        tmp[0]=0x16;
        
        if(MSSP2_I2C_Master_WriteNByte(0x44, tmp, 1))
        {
            if(MSSP2_I2C_Master_ReadNByte(0x44, tmp, 2))
            {
                __db("\nDegree: %d", ((uint16_t)tmp[1]<<8)|tmp[0]);
                System_Sleep();
            }
        }

        System_Sleep();
    }
}