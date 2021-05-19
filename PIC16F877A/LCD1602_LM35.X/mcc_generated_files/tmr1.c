#include <xc.h>
#include "tmr1.h"

volatile uint16_t timer1ReloadVal;
void (*TMR1_InterruptHandler)(void);

void TMR1_Initialize(void)
{
    T1CONbits.TMR1ON=0;
    TMR1H=0x00;
    TMR1L=0x00;
    T1CON=0b00110100;
    // Load the TMR value to reload variable
    timer1ReloadVal=(uint16_t) ((TMR1H<<8)|TMR1L);
    // Set Default Interrupt Handler
    TMR1_SetInterruptHandler(TMR1_DefaultInterruptHandler);
    // Clearing IF flag before enabling the interrupt.
    PIR1bits.TMR1IF=0;
    // Enabling TMR1 interrupt.
    PIE1bits.TMR1IE=1;
    T1CONbits.TMR1ON=1;
}

void TMR1_StartTimer(void)
{
    // Start the Timer by writing to TMRxON bit
    T1CONbits.TMR1ON=1;
}

void TMR1_StopTimer(void)
{
    // Stop the Timer by writing to TMRxON bit
    T1CONbits.TMR1ON=0;
}

uint16_t TMR1_ReadTimer(void) {
    uint16_t readVal = TMR1H;

    readVal <<= 8;
    readVal |= TMR1L;

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

void TMR1_Reload(void)
{
    TMR1_WriteTimer(timer1ReloadVal);
}

void TMR1_ISR(void)
{
    // Clear the TMR1 interrupt flag
    PIR1bits.TMR1IF=0;
    TMR1_WriteTimer(timer1ReloadVal);
    // ticker function call;
    // ticker is 1 -> Callback function gets called everytime this ISR executes
    TMR1_CallBack();
}

void TMR1_CallBack(void)
{
    // Add your custom callback code here
    if(TMR1_InterruptHandler)
    {
        TMR1_InterruptHandler();
    }
}

void TMR1_SetInterruptHandler(void (* InterruptHandler)(void))
{
    TMR1_InterruptHandler=InterruptHandler;
}

void TMR1_DefaultInterruptHandler(void)
{
    // add your TMR1 interrupt custom code
    // or set custom function using TMR1_SetInterruptHandler()
}