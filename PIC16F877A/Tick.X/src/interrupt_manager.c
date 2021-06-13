#include "libcomp.h"
#include "interrupt_manager.h"

void __interrupt() INTERRUPT_InterruptManager(void)
{
    if((INTCONbits.TMR0IE==1)&&(INTCONbits.TMR0IF==1))
        TMR0_ISR();
}