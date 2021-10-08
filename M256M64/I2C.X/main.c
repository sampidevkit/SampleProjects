#include "libcomp.h"

#define TICK_PER_MS     12000
#define Tick_Reset(cxt) cxt.Over=1

typedef struct
{
    bool Over;
    uint32_t Begin;
    uint32_t End;
} tick_t;

bool Tick_Is_Over(tick_t *pTick, uint32_t ms) // <editor-fold defaultstate="collapsed" desc="Check timeout">
{
    if(pTick->Over==1)
    {
        pTick->Begin=_CP0_GET_COUNT();
        pTick->End=ms*TICK_PER_MS;
        pTick->Over=0;
    }

    if((_CP0_GET_COUNT()-pTick->Begin)>=pTick->End)
        pTick->Over=1;

    return pTick->Over;
} // </editor-fold>

int main(void)
{
    tick_t Tick={1,0,0};
    
    SYSTEM_Initialize();
    
    while(1)
    {
        if(Tick_Is_Over(&Tick, 500))
        {
            WATCHDOG_TimerClear();
            LED1_Toggle();
        }
    }
    
    return 1;
}