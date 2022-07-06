#ifndef LIBCOMP_H
#define LIBCOMP_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "mcc_generated_files/usb/usb.h"
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/watchdog.h"
#include "mcc_generated_files/pin_manager.h"
#include "i2c1_master.h"

#define __db(...)       printf(__VA_ARGS__)

#define TICK_PER_MS     12000
#define Tick_Reset(cxt) cxt.Over=1

typedef struct {
    bool Over;
    uint32_t Begin;
    uint32_t End;
} tick_t;

bool Tick_Is_Over(tick_t *pTick, uint32_t ms);
bool BUTTON_Is_Pressed(void);
void USB_Rx_Tasks(void);
void USB_Tx_Tasks(void);
#define USB_CDC_Tasks() do{USB_Rx_Tasks(); USB_Tx_Tasks();}while(0)

#endif