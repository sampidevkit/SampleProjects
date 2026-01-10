#include "system/system.h"
#include "AT30TS74.h"

void I2CSlaver_Scan(void)
{
    uint8_t i, found;

    printf("\r\nScan I2C slaver: ");

    for(i=1, found=0; i<128; i++)
    {
        CLRWDT();
        I2C1_Host.Read(i, NULL, 0);
        while(I2C1_Host.IsBusy());

        if(I2C1_Host.ErrorGet()==I2C_ERROR_NONE)
        {
            found++;
            printf("%02X ", i);
        }
    }

    printf("\r\nFound total %d device(s)", found);
}

static void SW_InterruptCallback(void)
{
    RESET();
}

int main(void)
{
    bool error=0;
    
    SYSTEM_Initialize();

    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    __delay_ms(500);
    printf("\r\nAT30TS74 I2C THERMAL SENSOR\r\n");

    I2CSlaver_Scan();

    AT30TS74_SetSlave_Address(0x4B);

    if(AT30TS74_Init()==0)
    {
        error=1;
        printf("\r\n--> Sensor 0x4B is error");
    }

    AT30TS74_SetSlave_Address(0x4F);

    if(AT30TS74_Init()==0)
    {
        error=1;
        printf("\r\n--> Sensor 0x4F is error");
    }

    if(error)
    {
        printf("\r\n--> System reboot");
        __delay_ms(500);
        RESET();
    }
    
    SW_SetInterruptHandler(SW_InterruptCallback);

    while(1)
    {
        float t1, t2;
        uint8_t i, DvBuff[8];

        CLRWDT();
        LED_Toggle();
        AT30TS74_SetSlave_Address(0x4B);
        t1=AT30TS74_ReadTemp();

        AT30TS74_SetSlave_Address(0x4F);
        t2=AT30TS74_ReadTemp();

#if(0)
        // Header
        DvBuff[0]=0x03;
        // Temp1
        DvBuff[1]=t1;
        // Temp2
        DvBuff[2]=t2;
        // Footer
        DvBuff[3]=0xFC;

        for(i=0; i<4; i++)
        {
            EUSART1_Write(DvBuff[i]);
            while(!EUSART1_IsTxDone());
        }
#else
        printf("\r\nT1=%.3f, T2=%.3f", t1, t2);
#endif
        __delay_ms(100);
    }

    return 0;
}
