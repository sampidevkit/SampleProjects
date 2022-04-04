#include "mcc_generated_files/mcc.h"

void TMR0_UserISR(void)
{
    BLED_Toggle();
}

void main(void)
{
    SYSTEM_Initialize();
    TMR0_SetInterruptHandler(TMR0_UserISR);
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();

    while (1)
    {

    }
}