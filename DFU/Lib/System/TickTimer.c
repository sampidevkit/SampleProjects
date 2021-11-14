#include "libcomp.h"
#include "TickTimer.h"

public bool Tick_Timer_Is_Over(tick_timer_t *pTick, uint32_t Time) // <editor-fold defaultstate="collapsed" desc="Check tick over microsecond">
{
    if(pTick->Timeout)
    {
        pTick->Timeout=0;
        pTick->Duration=TICK_PER_MS*Time;
        pTick->Start=_CP0_GET_COUNT();
    }

    if((_CP0_GET_COUNT()-pTick->Start)>=pTick->Duration)
    {
        pTick->Timeout=1;
        return 1;
    }

    return 0;
} // </editor-fold>

public void Delay(uint32_t Time) // <editor-fold defaultstate="collapsed" desc="Delay">
{
    tick_t Duration;
    tick_t Start=_CP0_GET_COUNT();

    Duration=TICK_PER_MS*Time;

    while((_CP0_GET_COUNT()-Start)<Duration)
        ClrWdt();
} // </editor-fold>