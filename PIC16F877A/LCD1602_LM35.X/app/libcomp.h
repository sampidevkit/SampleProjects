#ifndef LIBCOMP_H
#define	LIBCOMP_H

#include "mcc.h"
#include "LibDef.h"
#include "TickTimer.h"
#include "adc.h"
#include "LM35.h"
#include "TextLCD.h"

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

#endif