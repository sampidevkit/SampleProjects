#include "mcc_generated_files/mcc.h"

void main(void)
{
    bool latch=0;
    uint16_t duty=0;
    SYSTEM_Initialize();

    while(1)
    {
        if(latch)
        {
            if(--duty==0)
                latch=0;
        }
        else
        {
            if(++duty>=1023)
                latch=1;
        }
        
        PWM6_LoadDutyValue(duty);
        __delay_ms(5);
    }
}