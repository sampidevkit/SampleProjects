#ifndef MCC_H
#define	MCC_H

#include <stdint.h>
#include <stdbool.h>

#include "tmr0.h"
#include "pin_manager.h"
#include "device_config.h"
#include "interrupt_manager.h"

void SYSTEM_Initialize(void);
void OSCILLATOR_Initialize(void);

#endif