#include "libcomp.h"

int main(void)
{
    int32_t tmp;
    tick_t tick;

    SYSTEM_Initialize();
    Tick_Reset(tick);
    LED1_SetLow();
    LED2_SetHigh();
    tmp=0;

    do
    {
        if(Tick_Is_Over(&tick, 100))
        {
            tmp++;
            LED1_Toggle();
            LED2_Toggle();
            WATCHDOG_TimerClear();
        }
    }
    while(tmp<30);

    LED1_SetLow();
    LED2_SetLow();
    USBDeviceAttach();

    while(1)
    {
        if(BUTTON_Is_Pressed())
        {
            LED1_SetHigh();
            LED2_SetHigh();
            while(1);
        }

        if(Tick_Is_Over(&tick, 1000))
        {

            float temper;
            uint8_t data[2]={0, 0};
            uint8_t reg=0x00;

            WATCHDOG_TimerClear();
            LED1_Toggle();
            LED2_SetHigh();
            //i2c_writeNBytes(0x48, &reg, 1);
            //i2c_readNBytes(0x48, &data[0], 2);

            tmp=data[0];
            tmp<<=8;
            tmp|=data[1];

            if(tmp&0x8000) // Temperature<0
            {
                tmp>>=7; // 9bit mode
                tmp-=512;
                temper=tmp;
                temper*=0.5f;
            }
            else // Temperature>0
            {
                tmp>>=7;
                temper=tmp;
                temper*=0.5f;
            }

            printf("\nT=%.1f%cC\n", temper, 0xB0);
            LED2_SetLow();
        }

        USB_CDC_Tasks();
    }

    return 1;
}
