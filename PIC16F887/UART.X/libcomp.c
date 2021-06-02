#include "libcomp.h"

void SYSTEM_Initialize(void)
{
    PIN_MANAGER_Initialize();
    OSCILLATOR_Initialize();
    UART_Initialize();
    WDT_Initialize();
}

void OSCILLATOR_Initialize(void)
{
    // SCS HFINTOSC; SPLLEN disabled; IRCF 8MHz_HF; 
    OSCCON=0x70;
    // TUN 0; 
    OSCTUNE=0x00;
}

void WDT_Initialize(void)
{
    // Prescale rate 1:65536, WDT is turned on
    WDTCON=0b00010110;
    CLRWDT();
}