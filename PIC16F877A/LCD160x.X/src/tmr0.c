#include "libcomp.h"
#include "tmr0.h"

volatile uint8_t timer0ReloadVal;
void (*TMR0_InterruptHandler)(void);

void TMR0_Initialize(void)
{
    // No RBPU, INTEDG, Internal instruction cycle clock (CLKO), 
    // Increment on low-to-high transition on T0CKI pin, 
    // Prescaler is assigned to the Timer0 module,
    // Prescaler Rate Select bits 1:256
    timer0ReloadVal=OPTION_REG&0b11000000;
    timer0ReloadVal|=0b00000111;
    OPTION_REG=timer0ReloadVal;
    // TMR0 61; 
    TMR0=0x3D;
    // Load the TMR value to reload variable
    timer0ReloadVal=61;
    // Set Default Interrupt Handler
    TMR0_SetInterruptHandler(NULL);
    // Clear Interrupt flag before enabling the interrupt
    INTCONbits.TMR0IF=0;
    // Enabling TMR0 interrupt
    INTCONbits.TMR0IE=1;
}

void TMR0_WriteTimer(uint8_t count)
{
    timer0ReloadVal=(255-count)+1;
    TMR0=timer0ReloadVal;
}

void TMR0_ISR(void)
{
    // Clear the TMR0 interrupt flag
    INTCONbits.TMR0IF=0;
    TMR0=timer0ReloadVal;

    if(TMR0_InterruptHandler)
        TMR0_InterruptHandler();
}