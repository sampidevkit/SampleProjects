#include "mcc.h"

void SYSTEM_Initialize(void)
{
    INTERRUPT_Initialize();
    PIN_MANAGER_Initialize();
    OSCILLATOR_Initialize();
    TMR0_Initialize();
}

void OSCILLATOR_Initialize(void)
{
    OSCCON=0b0100000;
    OSCTUNE=0x00;
}