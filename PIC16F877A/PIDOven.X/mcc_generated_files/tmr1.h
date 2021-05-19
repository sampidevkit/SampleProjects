#ifndef TMR1_H
#define TMR1_H

#include <stdbool.h>
#include <stdint.h>

#define TMR1_INTERRUPT_TICKER_FACTOR    1

void TMR1_Initialize(void);
void TMR1_StartTimer(void);
void TMR1_StopTimer(void);
uint16_t TMR1_ReadTimer(void);
void TMR1_WriteTimer(uint16_t timerVal);
void TMR1_Reload(void);
void TMR1_ISR(void);
void TMR1_CallBack(void);
void TMR1_SetInterruptHandler(void (* InterruptHandler)(void));
extern void (*TMR1_InterruptHandler)(void);
void TMR1_DefaultInterruptHandler(void);

#endif