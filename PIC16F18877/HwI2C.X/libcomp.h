#ifndef LIBCOMP_H
#define LIBCOMP_H

#include "mcc_generated_files/mcc.h"
#include "mssp2_i2c_master.h"

#ifndef INTERRUPT_GlobalInterruptEnable
#define INTERRUPT_GlobalInterruptEnable()
#endif

#ifndef INTERRUPT_PeripheralInterruptEnable
#define INTERRUPT_PeripheralInterruptEnable()
#endif

#define __db(...)   printf(__VA_ARGS__)

void System_Sleep(void);

#endif