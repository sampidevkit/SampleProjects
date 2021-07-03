#ifndef PWM1_H
#define PWM1_H

#include <stdint.h>

#define PWM1_MAX_DUTY_VALUE     1023 // Res=log(FOSC/Fpwm)/log(2) (bit)
#define PWM1_INIT_DUTY_VALUE    0

void PWM1_Initialize(void);
void PWM1_LoadDutyValue(uint16_t dutyValue);

#endif