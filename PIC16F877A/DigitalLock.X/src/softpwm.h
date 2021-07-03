#ifndef SOFTPWM_H
#define SOFTPWM_H

#include <stdint.h>

#define SOFTPWM_MAX_DUTY_VALUE  256
#define SOFTPWM_INIT_DUTY_VALUE 0

void SoftPWM_Init(void);
void SoftPWM_LoadDutyValue(uint8_t dutyValue);

#endif