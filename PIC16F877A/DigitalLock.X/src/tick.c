#include "libcomp.h"
#include "tick.h"

volatile uint16_t SoftTmr=0;

static void Tick_SoftTmr(void)
{
    SoftTmr++;
}

uint32_t Tick_Get(void)
{
    uint32_t CurTick;
    uint32_t CurCount;

    // prevent from overlapping of SoftTmr value
    do
    {
        CurCount=SoftTmr;
        CurTick=CurCount;
        CurTick<<=16;
        CurTick|=TMR1_ReadTimer();
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
    TMR1_SetInterruptHandler(Tick_SoftTmr);
}