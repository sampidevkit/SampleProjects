#include <xc.h>
#include "tmr2.h"

void TMR2_Initialize(void)
{
    T2CONbits.TMR2ON=0;
    T2CON=0b00000011; // prescaler 16
    PR2=0xFF;
    TMR2=0x00;
    // Clearing IF flag before enabling the interrupt.
    PIR1bits.TMR2IF=0;
    // Enabling TMR2 interrupt.
    PIE1bits.TMR2IE=0;
    T2CONbits.TMR2ON=1;
}