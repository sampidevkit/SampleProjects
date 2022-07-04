#include "libcomp.h"

static void ScanFound(uint8_t slvAddr)
{
    __db("\nFound %02X", slvAddr);
}

static void Plot(uint16_t Data)
{
    uint8_t i;

    EUSART_Write(0xFE);

    for(i=0; i<2; i++)
    {
        uint8_t c=((uint8_t *) (&Data))[i];

        switch(c)
        {
            case 0xFC:
            case 0xFD:
            case 0xFE:
                EUSART_Write(0xFD);
                EUSART_Write(c^0x20);
                break;

            default:
                EUSART_Write(c);
                break;
        }
    }

    EUSART_Write(0xFC);
}

void main(void)
{
    int8_t DeviceFound;

    SYSTEM_Initialize();
    __db("\nPIC16F18877 I2C\n");
    I2C_VBUS_SetHigh();
    __delay_ms(100);
    MSSP2_I2C_Master_Init(100000);
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();

    do
    {
        CLRWDT();
        __delay_ms(100);
        DeviceFound=MSSP2_I2C_Master_Scan(ScanFound);
        __db("\nFound %d I2C device(s)\n", DeviceFound);
    }
    while(DeviceFound==0);

    while(1)
    {
        uint8_t tmp[2];

        CLRWDT();

        tmp[0]=0x16;

        if(MSSP2_I2C_Master_WriteNByte(0x44, tmp, 1))
        {
            if(MSSP2_I2C_Master_ReadNByte(0x44, tmp, 2))
            {
                Plot(((uint16_t) tmp[1]<<8)|tmp[0]);
                System_Sleep();
            }
            else
                __db("\nRead error");
        }
        else
            __db("\nWrite error");

        System_Sleep();
    }
}