#include "libcomp.h"

void System_Sleep(void)
{
    while(!EUSART_is_tx_done());
    STT_LED_N_SetHigh();
    SLEEP();
    STT_LED_N_SetLow();
}