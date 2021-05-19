#include "libcomp.h"

uint32_t count;
tick_timer_t Tick;

void main(void)
{
    SYSTEM_Initialize();
    Tick_Timer_Init();
    /* Application initialize */
    count=9999990;
    Tick_Timer_Reset(Tick);
    HC595_Init();
    Led7Seg_Init();
    Led7Seg_DigitToggleEnable(5); // toggle digit 5, to disable, call Led7Seg_DigitToggleDisable(5)

    Enable_Peripheral_Interrupt();
    Enable_Global_Interrupt();

    while(1)
    {
        if(Tick_Timer_Is_Over_Ms(Tick, 100))
        {
            STT_LED_Toggle();
            Led7Seg_DisplayInteger(count++);
        }

        Led7Seg_Tasks(); // call in loop function
    }
}
