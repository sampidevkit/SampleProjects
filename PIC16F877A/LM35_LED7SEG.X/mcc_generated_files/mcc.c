#include "mcc.h"

void SYSTEM_Initialize(void)
{
    PIN_MANAGER_Initialize();
    TMR1_Initialize();
    ADC_Initialize();
}