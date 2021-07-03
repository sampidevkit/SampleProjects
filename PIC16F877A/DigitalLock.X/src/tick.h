#ifndef TICK_H
#define TICK_H

#include <stdint.h>
#include <stdbool.h>

#define TICK_PER_MS     625 // FTMR1=FOSC/4/prescaler=20E6/4/8 (Hz)
#define Tick_Reset(cxt) cxt.Over=1

typedef struct {
    bool Over;
    uint32_t Begin;
    uint32_t End;
} tick_t;

void Tick_Init(void);
uint32_t Tick_Get(void);
bool Tick_Is_Over(tick_t *pTick, uint16_t ms);

#endif