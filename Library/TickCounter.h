#ifndef TICKCOUNTER_H
#define	TICKCOUNTER_H

#include "LibDef.h"

typedef uint16_t tick_counter_t;

public bool Tick_Counter_Is_Over(tick_counter_t *pTick, uint16_t Count);

#define Tick_Counter_Reset(x) x=0

#endif