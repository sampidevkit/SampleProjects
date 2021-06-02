#include <xc.h>
#include "uart.h"
#include "interrupt_manager.h"

void __interrupt() INTERRUPT_InterruptManager(void)
{
    if(PIR1bits.RCIF==1)
        UART_Receive_ISR();

    if(PIR1bits.TXIF==1)
        UART_Transmit_ISR();
}
