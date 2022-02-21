#include "mcc_generated_files/mcc.h"
#include "usr.h"

void main(void)
{
    SYSTEM_Initialize();
    TMR0_SetInterruptHandler(UsrFunc);
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();

    while (1)
    {
        UsrFunc();
        __delay_ms(100);
    }
}