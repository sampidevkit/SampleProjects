#include "libcomp.h"

tick_timer_t Tick;

void main(void)
{
    // System initialize
    SYSTEM_Initialize();
    Tick_Timer_Init();
    // Application initialize
    LM35_Init();
    Led7Seg_Init();
    Led7Seg_SetDigitValue(0, Led7SegCode[0]);
    Led7Seg_SetDigitValue(1, Led7SegCode[0]);
    Led7Seg_SetDigitValue(2, 0x9C); // degree
    Led7Seg_SetDigitValue(3, 0xC6); // C
    Tick_Timer_Reset(Tick);
    // Interrupt enable
    Enable_Peripheral_Interrupt();
    Enable_Global_Interrupt();

    while(1)
    {
        if(Tick_Timer_Is_Over_Ms(Tick, 500))
        {
            int16_t temp=LM35_GetTemper(0);

            if(temp>99)
                temp=99;

            Led7Seg_SetDigitValue(0, Led7SegCode[(uint8_t) (temp/10)]);
            Led7Seg_SetDigitValue(1, Led7SegCode[(uint8_t) (temp%10)]);
        }

        LM35_Tasks();
        Led7Seg_Tasks();
    }
}
