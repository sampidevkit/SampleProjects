#include "libcomp.h"
#include "softpwm.h"

volatile uint8_t DoNext=0;
volatile uint8_t Count=0;

static void SoftPWM_Task(void)
{
    // 1 pulse=51.2us
    
    switch(DoNext)
    {
        case 0:
            DoNext++;
            SERVO_SetHigh();
            TMR0_WriteTimer(Count);
            break;
            
        case 1:
            
            break;
    }
}

void SoftPWM_Init(void)
{
    DoNext=0;
    SERVO_SetLow();
    TMR0_WriteTimer(195);// interrupt 10ms
    TMR0_SetInterruptHandler(SoftPWM_Task);
}

void SoftPWM_LoadDutyValue(uint8_t dutyValue)
{

}