#ifndef TMR1_H
#define TMR1_H

#include <stdbool.h>
#include <stdint.h>

#define TMR1_INTERRUPT_TICKER_FACTOR    1
#define TMR1_SetInterruptHandler(pFnc)  TMR1_InterruptHandler=pFnc

extern void (*TMR1_InterruptHandler)(void);

void TMR1_Initialize(void);
uint16_t TMR1_ReadTimer(void);
void TMR1_WriteTimer(uint16_t timerVal);
// Interrupt finction, do not call in main function
void TMR1_ISR(void);

#endif