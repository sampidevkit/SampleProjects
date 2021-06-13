#ifndef KEYPAD_H
#define KEYPAD_H

#include "stdint.h"

typedef union
{
    uint16_t val;

    struct
    {
        unsigned Col0:4; // K1, K4, K7, Asterisk
        unsigned Col1:4; // K2, K5, K8, K0
        unsigned Col2:4; // K3, K6, K9, NumSign
        unsigned Col3:4; // RFU
    };
} key_t;

void Keypad_Init(void);
uint16_t Keypad_Task(void);

#endif