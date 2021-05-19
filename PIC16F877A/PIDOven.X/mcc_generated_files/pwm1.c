#include <xc.h>
#include "pwm1.h"

void PWM1_Initialize(void)
{
    CCP1CON=0b00001111; // PWM mode
    CCPR1H=0x00;
    CCPR1L=0x00;
}

void PWM1_LoadDutyValue(uint16_t dutyValue)
{
    dutyValue&=0x03FF;
    CCPR1H=(uint8_t) (dutyValue>>8);
    CCPR1L=(uint8_t) dutyValue;
}