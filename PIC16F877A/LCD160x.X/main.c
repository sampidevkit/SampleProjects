#include "src/libcomp.h"

static const uint8_t Str[]="https://github.com/sampidevkit/";

void main(void)
{
    uint8_t lcdbuff[16];
    uint8_t i, j;
    tick_t Tick;

    SYSTEM_Initialize();
    Tick_Init();
    Tick_Reset(Tick);
    TextLCD_Init(LCD1602);
    TextLCD_Puts(0, 4, "LCD1602", LCD_PUT_STRING);
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();

    i=0;

    while(1)
    {
        if(Tick_Is_Over(&Tick, 250))
        {
            j=strlen(Str)-i;

            if(j>16)
                j=16;

            memset(lcdbuff, 0x00, 16);
            memcpy(lcdbuff, &Str[i], j);
            TextLCD_Puts(1, 0, lcdbuff, 16);

            if(++i>=strlen(Str))
                i=0;
        }
    }
}