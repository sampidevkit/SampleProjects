#include "libcomp.h"

void System_Sleep(void)
{
    while(!EUSART_is_tx_done());
    STT_LED_SetLow();
    SLEEP();
    STT_LED_SetHigh();
}