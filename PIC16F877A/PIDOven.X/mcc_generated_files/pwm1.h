#ifndef PWM1_H
#define PWM1_H

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

#define PWM1_MAX_DUTY 1023

void PWM1_Initialize(void);
void PWM1_LoadDutyValue(uint16_t dutyValue);

#endif