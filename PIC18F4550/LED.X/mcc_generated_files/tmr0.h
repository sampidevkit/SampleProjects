#ifndef TMR0_H
#define TMR0_H

#include <stdint.h>
#include <stdbool.h>

#define TMR0_INTERRUPT_TICKER_FACTOR    1

void TMR0_Initialize(void);
void TMR0_StartTimer(void);
void TMR0_StopTimer(void);
uint16_t TMR0_ReadTimer(void);
void TMR0_WriteTimer(uint16_t timerVal);
void TMR0_Reload(void);
void TMR0_ISR(void);
void TMR0_CallBack(void);
void TMR0_SetInterruptHandler(void (* InterruptHandler)(void));
extern void (*TMR0_InterruptHandler)(void);
void TMR0_DefaultInterruptHandler(void);

#endif