#include "TickTimer_CCS.h"
#use timer(timer=1, tick=1ms, bits=32, NOISR)

int1 Tick_Timer_Is_Over(tick_timer_t *pTick, tick_t ms) // <editor-fold defaultstate="collapsed" desc="Check timeout">
{
    if(pTick->Over==1)
    {
        pTick->Begin=get_ticks();
        pTick->End=ms*TICK_PER_MS;
        pTick->Over=0;
    }

    if((get_ticks()-pTick->Begin)>=pTick->End)
        pTick->Over=1;

    return pTick->Over;
} // </editor-fold>