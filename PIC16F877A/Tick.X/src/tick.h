#ifndef TICK_H
#define TICK_H

#include <stdint.h>
#include <stdbool.h>

#define TICK_PER_MS     19 // FTMR0=FOSC/4/prescaler/1000=20E6/4/256/1000 (Hz)
#define Tick_Reset(cxt) cxt.Over=1

typedef struct {
    bool Over;
    uint24_t Begin;
    uint24_t End;
} tick_t;

void Tick_Init(void);
uint24_t Tick_Get(void);
bool Tick_Is_Over(tick_t *pTick, uint16_t ms);

#endif