#include <stdio.h>
#include <stdbool.h>
#include "system.h"
#include "tmr1.h"
#include "watchdog.h"
#include "pin_manager.h"

volatile bool En=0;

void TMR1_UsrCb(void)
{
    En=1;
}

int main(void)
{
    SYSTEM_Initialize();
    En=0;
    TMR1_SetInterruptHandler(TMR1_UsrCb);

    while(1)
    {
        if(BUTTON_GetValue()) // Hold the button for reseting and go to bootloader mode
            WATCHDOG_TimerClear();

        if(En)
        {
            En=0;
            STT_LED_Toggle();
            printf("\nHello world");
        }

    }

    return 1;
}