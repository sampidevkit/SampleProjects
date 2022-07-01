#include "mcc_generated_files/mcc.h"

#define __db(...)       printf(__VA_ARGS__)
#define MAX_PWM_DUTY    127
#define OUTPUT_SETVOL   5

static uint16_t VolInput, VolOutput;

static void GetVoltage(void)
{
    uint32_t tmp;

    // VIN_DIV=ADC*VRFE/1024=ADC*5000/1024;
    // VOUT=VIN_DIV*(Rtop+Rbot)/Rbot=VIN_DIV*30/10=VIN_DIV*3=ADC*5000*3/1024
    // VOUT=ADC*15000/1024=(ADC*15000)>>10
    tmp=ADC_GetConversion(VIN_DIV);
    tmp*=15000;
    VolInput=(uint16_t) (tmp>>10);
    // VOUT_DIV=ADC*VRFE/1024=ADC*5000/1024;
    // VOUT=VOUT_DIV*(Rtop+Rbot)/Rbot=VOUT_DIV*30/10=VOUT_DIV*3=ADC*5000*3/1024
    // VOUT=ADC*15000/1024=(ADC*15000)>>10
    tmp=ADC_GetConversion(VOUT_DIV);
    tmp*=15000;
    VolOutput=(uint16_t) (tmp>>10);

    __db("\nVin =%hu", VolInput);
    __db("\nVout=%hu", VolOutput);
}

void main(void)
{
    uint16_t PWMduty=0;

    SYSTEM_Initialize();
    PWM4_LoadDutyValue(0);
    //INTERRUPT_GlobalInterruptEnable();
    //INTERRUPT_PeripheralInterruptEnable();

    while(1)
    {
        STT_LED_SetHigh();
        GetVoltage();
        STT_LED_SetLow();
        SLEEP();
    }
}