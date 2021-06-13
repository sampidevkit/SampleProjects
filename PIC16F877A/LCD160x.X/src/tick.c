#include "libcomp.h"
#include "tick.h"

volatile uint16_t SoftTmr=0;

static void Tick_SoftTmr(void)
{
    SoftTmr++;
}

uint24_t Tick_Get(void)
{
    uint24_t CurTick;
    uint24_t CurCount;

    // prevent from overlapping of SoftTmr value
    do
    {
        CurCount=SoftTmr;
        CurTick=CurCount;
        CurTick<<=8;
        CurTick|=TMR0_ReadTimer();
    }
    while(SoftTmr!=CurCount);

    return CurTick;
}

bool Tick_Is_Over(tick_t *pTick, uint16_t ms)
{
    if(pTick->Over==1)
    {
        pTick->Begin=Tick_Get();
        pTick->End=ms*TICK_PER_MS;
        pTick->Over=0;
    }

    if((Tick_Get()-pTick->Begin)>=pTick->End)
        pTick->Over=1;

    return pTick->Over;
}

void Tick_Init(void)
{
    SoftTmr=0;
    TMR0_SetInterruptHandler(Tick_SoftTmr);
}