#ifndef LIBCOMP_H
#define	LIBCOMP_H

#include "mcc.h"
#include "LibDef.h"
#include "MAX7219.h"
#include "TickTimer.h"

// Global interrupt
#define Disable_Global_Interrupt()      INTERRUPT_GlobalInterruptDisable()
#define Enable_Global_Interrupt()       INTERRUPT_GlobalInterruptEnable()
// Peripheral interrupt
#define Disable_Peripheral_Interrupt()  INTERRUPT_PeripheralInterruptDisable()
#define Enable_Peripheral_Interrupt()   INTERRUPT_PeripheralInterruptEnable()
// Core timer interrupt
#define Disable_Coretimer_Interrupt()   (PIE1bits.TMR1IE=0)
#define Enable_Coretimer_Interrupt()    (PIE1bits.TMR1IE=1)
#define Clear_Coretimer_Interrupt()     (PIR1bits.TMR1IF=0)

void DbWriteStr(const char *pd);
void DbBcd2Hex(uint8_t i);
void DbLong2Hex(int32_t v);
void DbShort2Hex(int16_t v);
void DbByte2Hex(int8_t v);

//#define __debug(msg, val) do{DbWriteStr(msg), DbShort2Hex(val);}while(0)

#endif