#ifndef TMR0_H
#define TMR0_H

#include <stdint.h>
#include <stdbool.h>

#define TMR0_INTERRUPT_TICKER_FACTOR    1
#define TMR0_ReadTimer()                TMR0
#define TMR0_SetInterruptHandler(pFnc)  TMR0_InterruptHandler=pFnc

extern void (*TMR0_InterruptHandler)(void);

void TMR0_Initialize(void);
void TMR0_WriteTimer(uint8_t count);
// Interrupt finction, do not call in main function
void TMR0_ISR(void);

#endif