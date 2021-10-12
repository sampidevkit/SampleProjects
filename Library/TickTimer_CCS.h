#ifndef TICKTIMER_H
#define	TICKTIMER_H

#define TICK_PER_MS 1
#define tick_t      unsigned long long

typedef struct
{
    int1 Over;
    tick_t Begin;
    tick_t End;
} tick_timer_t;

#define Tick_Timer_Reset(cxt) cxt.Over=1

#endif