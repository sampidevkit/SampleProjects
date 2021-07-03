#include "src/libcomp.h"

void main(void)
{
    tick_t Tick;

    SYSTEM_Initialize();
    Tick_Init();
    SoftPWM_Init();
    Tick_Reset(Tick);
    TextLCD_Init(LCD1602);
    TextLCD_Puts(0, 0, "LCD1602", LCD_PUT_STRING);
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();

    while(1)
    {
        if(Tick_Is_Over(&Tick, 100))
            SLED_Toggle();
    }
}