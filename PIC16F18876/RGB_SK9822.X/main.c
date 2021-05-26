#include "mcc_generated_files/mcc.h"

#ifndef INTERRUPT_GlobalInterruptEnable
#define INTERRUPT_GlobalInterruptEnable()
#endif

#ifndef INTERRUPT_PeripheralInterruptEnable
#define INTERRUPT_PeripheralInterruptEnable()
#endif

#define TICK_PER_MS     4 // LFINTOSC/4/TMR0_Prescaler/1000
#define Tick_Reset(cxt) cxt.Over=1

typedef struct
{
    bool Over;
    uint16_t Begin;
    uint16_t End;
} tick_t;

bool Tick_Is_TimedOut(tick_t *pTick, uint16_t ms) // <editor-fold defaultstate="collapsed" desc="Check timeout">
{
    if(pTick->Over==1)
    {
        pTick->Begin=TMR0_ReadTimer();
        pTick->End=ms*TICK_PER_MS;
        pTick->Over=0;
    }

    if((TMR0_ReadTimer()-pTick->Begin)>=pTick->End)
        pTick->Over=1;

    return pTick->Over;
} // </editor-fold>

void SK9822_Write(uint8_t Brightness, uint8_t Red, uint8_t Green, uint8_t Blue)
{
    SPI2_Open(SPI2_DEFAULT);
    CLKRCONbits.CLKREN=0; // disable CLKR_OUT
    Brightness|=0b11100000;
    // Start frame: 32 bits 0
    SPI2_ExchangeByte(0x00);
    SPI2_ExchangeByte(0x00);
    SPI2_ExchangeByte(0x00);
    SPI2_ExchangeByte(0x00);
    // Brightness
    SPI2_ExchangeByte(Brightness);
    // Blue
    SPI2_ExchangeByte(Blue);
    // Green
    SPI2_ExchangeByte(Green);
    // Red
    SPI2_ExchangeByte(Red);
    // End frame: 32 bits 1
    SPI2_ExchangeByte(0xFF);
    SPI2_ExchangeByte(0xFF);
    SPI2_ExchangeByte(0xFF);
    SPI2_ExchangeByte(0xFF);
    SPI2_Close();
    CLKRCONbits.CLKREN=1; // enable CLKR_OUT
}

void main(void)
{
    tick_t Tick;
    uint8_t i=1, j=3, k=5;
    uint8_t Brightness=0, Red=0, Green=0, Blue=0;

    SYSTEM_Initialize();
    Tick_Reset(Tick);
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();

    while(1)
    {
        if(Tick_Is_TimedOut(&Tick, 30))
        {
            Red+=i;
            Green+=j;
            Blue+=k;

            if((Red|Green|Blue)==0)
            {
                if(i==1)
                    i=3;
                else if(i==3)
                    i=5;
                else
                    i=1;

                if(j==1)
                    j=3;
                else if(j==3)
                    j=5;
                else
                    j=1;

                if(k==1)
                    k=3;
                else if(k==3)
                    k=5;
                else
                    k=1;

                Brightness++;
            }

            SLED_Toggle();
            SK9822_Write(Brightness, Red, Green, Blue);
        }
    }
}