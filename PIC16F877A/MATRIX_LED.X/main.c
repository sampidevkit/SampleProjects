#include "libcomp.h"

private bool APP_LedLine_Display1(uint8_t Pixel) // <editor-fold defaultstate="collapsed" desc="display 1">
{
    if(Pixel==0)
        LedMatrix_SetAll(0);

    LedMatrix_SetPixel(Pixel, 1);

    if(Pixel>=(NUMBER_OF_PIXELS-1))
        return 1;

    return 0;
} // </editor-fold>

private bool APP_LedLine_Display2(uint8_t Pixel) // <editor-fold defaultstate="collapsed" desc="display 4">
{
    if(Pixel==0)
        LedMatrix_SetAll(1);
    else
        LedMatrix_SetPixel(Pixel-1, 1);

    LedMatrix_SetPixel(Pixel, 0);

    if(Pixel>=(NUMBER_OF_PIXELS-1))
        return 1;

    return 0;
} // </editor-fold>

private bool APP_LedLine_Display3(uint8_t Pixel) // <editor-fold defaultstate="collapsed" desc="display 2">
{
    if(Pixel==0)
        LedMatrix_SetAll(1);

    LedMatrix_SetPixel(Pixel, 0);

    if(Pixel>=(NUMBER_OF_PIXELS-1))
        return 1;

    return 0;
} // </editor-fold>

private bool APP_LedLine_Display4(uint8_t Pixel) // <editor-fold defaultstate="collapsed" desc="display 3">
{
    if(Pixel==0)
        LedMatrix_SetAll(0);
    else
        LedMatrix_SetPixel(Pixel-1, 0);

    LedMatrix_SetPixel(Pixel, 1);

    if(Pixel>=(NUMBER_OF_PIXELS-1))
        return 1;

    return 0;
} // </editor-fold>

void main(void)
{
    uint8_t Count=0;
    uint8_t DoNext=0;
    tick_timer_t Tick={1, 0, 0};
    SYSTEM_Initialize();
    Tick_Timer_Init();
    LedMatrix_Init();
    Enable_Peripheral_Interrupt();
    Enable_Global_Interrupt();

    while(1)
    {
        if(Tick_Timer_Is_Over_Ms(Tick, 100))
            Count++;

        switch(DoNext)
        {
            case 0:
                if(APP_LedLine_Display1(Count))
                {
                    Count=0;
                    DoNext++;
                }
                break;

            case 1:
                if(APP_LedLine_Display2(Count))
                {
                    Count=0;
                    DoNext++;
                }
                break;

            case 2:
                if(APP_LedLine_Display3(Count))
                {
                    Count=0;
                    DoNext++;
                }
                break;

            default:
                if(APP_LedLine_Display4(Count))
                {
                    Count=0;
                    DoNext=0;
                }
                break;
        }

        LedMatrix_Tasks();
    }
}
