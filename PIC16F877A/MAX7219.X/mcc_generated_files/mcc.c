#include "mcc.h"

void SYSTEM_Initialize(void)
{
    PIN_MANAGER_Initialize();
    OSCILLATOR_Initialize();
    TMR1_Initialize();
    EUSART_Initialize();

#ifndef USE_SW_SPI
    SPI1_Initialize();
#endif
}

void OSCILLATOR_Initialize(void)
{

}