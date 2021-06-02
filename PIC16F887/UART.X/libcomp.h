#ifndef APPLAT_H
#define APPLAT_H

#include <xc.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "device_config.h"
#include "interrupt_manager.h"
#include "pin_manager.h"
#include "uart.h"

void SYSTEM_Initialize(void);
void OSCILLATOR_Initialize(void);
void WDT_Initialize(void);

#endif
