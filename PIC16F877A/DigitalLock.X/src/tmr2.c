#include "libcomp.h"
#include "tmr2.h"

void TMR2_Initialize(void)
{
    // PR2 255; 
    PR2=0xFF;
    // TMR2 0; 
    TMR2=0x00;
    // Clearing IF flag.
    PIR1bits.TMR2IF=0;
    PIE1bits.TMR2IE=0;
    // 1:1 postscale, Timer2 is on, Prescaler is 16
    T2CON=0b00000111;
}