#include <xc.h>
#include "tmr0.h"

void (*TMR0_InterruptHandler)(void);
volatile uint16_t timer0ReloadVal;

void TMR0_Initialize(void)
{
    //Enable 16bit timer mode before assigning value to TMR0H
    T0CONbits.T08BIT=0;
    // TMR0H 0; 
    TMR0H=0x00;
    // TMR0L 0; 
    TMR0L=0x00;
    // Load TMR0 value to the 16-bit reload variable
    timer0ReloadVal=(uint16_t) ((TMR0H<<8)|TMR0L);
    // Clear Interrupt flag before enabling the interrupt
    INTCONbits.TMR0IF=0;
    // Enabling TMR0 interrupt.
    INTCONbits.TMR0IE=1;
    // Set Default Interrupt Handler
    TMR0_SetInterruptHandler(TMR0_DefaultInterruptHandler);
    // T0PS 1:256; T08BIT 16-bit; T0SE Increment_lo_hi; T0CS FOSC/4; TMR0ON enabled; PSA assigned; 
    T0CON=0b10000111;
}

void TMR0_StartTimer(void)
{
    // Start the Timer by writing to TMR0ON bit
    T0CONbits.TMR0ON=1;
}

void TMR0_StopTimer(void)
{
    // Stop the Timer by writing to TMR0ON bit
    T0CONbits.TMR0ON=0;
}

uint16_t TMR0_ReadTimer(void)
{
    uint16_t readVal;
    uint8_t readValLow;
    uint8_t readValHigh;

    readValLow=TMR0L;
    readValHigh=TMR0H;
    readVal=((uint16_t) readValHigh<<8)+readValLow;

    return readVal;
}

void TMR0_WriteTimer(uint16_t timerVal)
{
    // Write to the Timer0 register
    TMR0H=timerVal>>8;
    TMR0L=(uint8_t) timerVal;
}

void TMR0_Reload(void)
{
    // Write to the Timer0 register
    TMR0H=timer0ReloadVal>>8;
    TMR0L=(uint8_t) timer0ReloadVal;
}

void TMR0_ISR(void)
{
    // clear the TMR0 interrupt flag
    INTCONbits.TMR0IF=0;
    // reload TMR0
    // Write to the Timer0 register
    TMR0H=timer0ReloadVal>>8;
    TMR0L=(uint8_t) timer0ReloadVal;
    // ticker function call;
    // ticker is 1 -> Callback function gets called every time this ISR executes
    TMR0_CallBack();
}

void TMR0_CallBack(void)
{
    if(TMR0_InterruptHandler)
        TMR0_InterruptHandler();
}

void TMR0_SetInterruptHandler(void (* InterruptHandler)(void))
{
    TMR0_InterruptHandler=InterruptHandler;
}

void TMR0_DefaultInterruptHandler(void)
{
}