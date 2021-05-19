#include "libcomp.h"

tick_timer_t Tick;
uint8_t buffer[17];

void main(void)
{
    // System initialize
    SYSTEM_Initialize();
    Tick_Timer_Init();
    // Application initialize
    LM35_Init();
    TextLCD_Init(TEXTLCD1602);
    Tick_Timer_Reset(Tick);
    // Interrupt enable
    Enable_Peripheral_Interrupt();
    Enable_Global_Interrupt();

    while(1)
    {
        if(Tick_Timer_Is_Over_Ms(Tick, 500))
        {
            STT_LED_Toggle();
            TextLCD_Clear();
            sprintf(buffer, "T1=%d", LM35_GetTemper(0));
            TextLCD_Puts(0, 0, buffer, TEXTLCD_PUT_STRING);
            sprintf(buffer, "T2=%d", LM35_GetTemper(1));
            TextLCD_Puts(1, 0, buffer, TEXTLCD_PUT_STRING);
        }

        LM35_Tasks();
    }
}
