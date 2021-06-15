#include "libcomp.h"

tick_timer_t Tick;
uint8_t buffer[17];

uint16_t Temp2Speed(uint16_t t)
{
    // 10 C degree --> duty=0
    // 50 C degree --> duty=1023
    // duty=(t-10)*1023/40

    if(t<10)
        t=10;
    else if(t>50)
        t=50;

    t-=10;
    t*=1023;
    t/=40;

    return t;
}

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
            int16_t temp=LM35_GetTemper(0);
            uint16_t duty=Temp2Speed((uint16_t) temp);

            STT_LED_Toggle();
            TextLCD_Clear();
            sprintf(buffer, "T=%d", temp);
            TextLCD_Puts(0, 0, buffer, TEXTLCD_PUT_STRING);
            sprintf(buffer, "duty=%d", duty);
            TextLCD_Puts(1, 0, buffer, TEXTLCD_PUT_STRING);
            PWM1_LoadDutyValue(duty);
        }

        LM35_Tasks();
    }
}
