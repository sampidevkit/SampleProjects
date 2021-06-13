#include "src/libcomp.h"

void main(void)
{
    tick_t Tick1, Tick2, Tick3;

    SYSTEM_Initialize();
    Tick_Init();
    Tick_Reset(Tick1);
    Tick_Reset(Tick2);
    Tick_Reset(Tick3);
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();

    while(1)
    {
        if(Tick_Is_Over(&Tick1, 100))
            LED1_Toggle();

        if(Tick_Is_Over(&Tick2, 200))
            LED2_Toggle();

        if(Tick_Is_Over(&Tick3, 500))
            LED3_Toggle();
    }
}