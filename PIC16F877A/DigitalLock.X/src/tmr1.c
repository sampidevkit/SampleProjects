#include "libcomp.h"
#include "tmr1.h"

volatile uint16_t timer1ReloadVal;
void (*TMR1_InterruptHandler)(void);

void TMR1_Initialize(void)
{
    T1CONbits.TMR1ON=0;
    TMR1H=0x00;
    TMR1L=0x00;
    // Load the TMR value to reload variable
    timer1ReloadVal=(uint16_t) ((TMR1H<<8)|TMR1L);
    TMR1_SetInterruptHandler(NULL);
    // Clear IF flag before enabling the interrupt.
    PIR1bits.TMR1IF=0;
    // Disable TMR1 interrupt.
    PIE1bits.TMR1IE=1;
    // Prescaler 1:8, Oscillator is shut-off, Internal clock (FOSC/4)
    // Enables Timer1
    T1CON=0b00110001;
}

uint16_t TMR1_ReadTimer(void)
{
    uint16_t readVal=TMR1H;

    readVal<<=8;
    readVal|=TMR1L;

    return readVal;
}

void TMR1_WriteTimer(uint16_t timerVal)
{
    if(T1CONbits.nT1SYNC==1)
    {
        // Stop the Timer by writing to TMRxON bit
        T1CONbits.TMR1ON=0;
        // Write to the Timer1 register
        TMR1H=(uint8_t) (timerVal>>8);
        TMR1L=(uint8_t) timerVal;
        // Start the Timer after writing to the register
        T1CONbits.TMR1ON=1;
    }
    else
    {
        // Write to the Timer1 register
        TMR1H=(uint8_t) (timerVal>>8);
        TMR1L=(uint8_t) timerVal;
    }
}

void TMR1_ISR(void)
{
    // Clear the TMR0 interrupt flag
    PIR1bits.TMR1IF=0;
    TMR1_WriteTimer(timer1ReloadVal);

    if(TMR1_InterruptHandler)
        TMR1_InterruptHandler();
}