#include "libcomp.h"
#include "pwm1.h"

void PWM1_Initialize(void)
{
    // PWM mode; PWM Least Significant bits=0; 
    CCP1CON=0b00001100;
    // CCPR1L 0; 
    CCPR1L=0x00;
    // CCPR1H 0; 
    CCPR1H=0x00;
    PWM1_LoadDutyValue(PWM1_INIT_DUTY_VALUE);
}

void PWM1_LoadDutyValue(uint16_t dutyValue)
{
    // Writing to 8 MSBs of pwm duty cycle in CCPRL register
    CCPR1L=((dutyValue&0x03FC)>>2);
    // Writing to 2 LSBs of pwm duty cycle in CCPCON register
    CCP1CON=((uint8_t) (CCP1CON&0xCF)|((dutyValue&0x0003)<<4));
}