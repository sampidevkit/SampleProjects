#include "mcc.h"

void SYSTEM_Initialize(void)
{
    PIN_MANAGER_Initialize();
    OSCILLATOR_Initialize();
    TMR1_Initialize();
    TMR2_Initialize();
    PWM1_Initialize();
    ADC_Initialize();
    EUSART_Initialize();
}

void OSCILLATOR_Initialize(void)
{

}