#ifndef LIBCOMP_H
#define	LIBCOMP_H
/* *********************************************************** System Library */
#include <xc.h>
#include <time.h>
#include <stdint.h>
#include <stdbool.h>
/* ************************************************************** MCC Library */
#include "uart3.h"
#include "clock.h"
#include "system.h"
#include "watchdog.h"
#include "exceptions.h"
#include "pin_manager.h"
#include "memory/flash.h"
#include "interrupt_manager.h"
/* ************************************************************ SAMPI Library */
#include "Bootloader/Bootloader.h"
#include "Bootloader/BLD_Nvm_PIC32.h"
#include "Bootloader/HexParsing.h"
#include "Common/LibDef.h"
/* ************************************************************** Application */
// Clock sources
#define SYS_CLK                         24000000UL
#define PB_CLK                          12000000UL
#define CORETIMER_CLK                   12000000UL
// Global interrupt
#define Disable_Global_Interrupt()      __builtin_disable_interrupts()
#define Enable_Global_Interrupt()       __builtin_enable_interrupts()
// Peripheral interrupt
#define Disable_Peripheral_Interrupt()  // Not implemented in PIC32
#define Enable_Peripheral_Interrupt()   // Not implemented in PIC32
// Core timer interrupt
#define Disable_Coretimer_Interrupt()   (IEC0CLR=_IEC0_CTIE_MASK)
#define Enable_Coretimer_Interrupt()    (IEC0SET=_IEC0_CTIE_MASK)
#define Clear_Coretimer_Interrupt()     (IFS0CLR=_IFS0_CTIF_MASK)

#endif