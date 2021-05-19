#include "mcc.h"

void SYSTEM_Initialize(void)
{
    PIN_MANAGER_Initialize();
    OSCILLATOR_Initialize();
    TMR1_Initialize();
}

void OSCILLATOR_Initialize(void)
{

}