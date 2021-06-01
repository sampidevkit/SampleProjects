#include "mcc_generated_files/mcc.h"

void Timer0_Isr_UserCb(void)
{
    LATAbits.LATA1^=1;
}

void main(void)
{
    SYSTEM_Initialize();
    TMR0_SetInterruptHandler(Timer0_Isr_UserCb);
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();

    while(1)
    {

    }
}