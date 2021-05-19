#include "interrupt_manager.h"
#include "mcc.h"

void INTERRUPT_Initialize(void)
{
    RCONbits.IPEN=0;
}

void __interrupt() INTERRUPT_InterruptManager(void)
{
    if((INTCONbits.TMR0IE==1)&&(INTCONbits.TMR0IF==1))
        TMR0_ISR();
}