#include "mcc_generated_files/mcc.h"
#include <util/delay.h>

bool SW0_IsPressed(void)
{
    static bool x=1;
    static uint8_t cnt=0;

    if(x!=(SW0_GetValue()!=0))
    {
        if(++cnt==0)
        {
            x^=1;

            if(x==0)
                return 1;
        }
    }
    else
        cnt=0;

    return 0;
}

void PIT_UserCb(void)
{
    LED0_Toggle();
}

int main(void)
{
    ADC_MUXPOS_t Ch=ADC_MUXPOS_DAC0_gc;

    SYSTEM_Initialize();
    DAC0_SetOutput(500);
    RTC_SetPITIsrCallback(PIT_UserCb);
    printf("\r\nAVR128DA48 ADC\r\n");

    while(1)
    {
        int32_t val;

        ADC0_Enable();
        val=(int32_t) ADC0_GetConversion(Ch)/4;
        ADC0_Disable();

        switch(Ch)
        {
            case ADC_MUXPOS_DAC0_gc:
            {
                Ch=ADC_MUXPOS_TEMPSENSE_gc;
                printf("\r\nADC MUXPOS DAC0=%ld", val);
                val*=2500;
                val/=4096;
                printf(", U=%ld mV", val);
                break;
            }

            case ADC_MUXPOS_TEMPSENSE_gc:
            {
                Ch=ADC_MUXPOS_DAC0_gc;
                printf("\r\nADC MUXPOS TEMPSENSE=%ld", val);

                int32_t temp;
                uint16_t sigrow_slope=SIGROW.TEMPSENSE0;
                uint16_t sigrow_offset=SIGROW.TEMPSENSE1;

                temp=(int16_t) sigrow_offset-val;
                temp*=(int16_t) sigrow_slope;
                temp+=0x0800;
                temp>>=12;
                temp-=273;
                printf(", T=%ld.%ld C\r\n", temp/10, temp%10);
                break;
            }

            default:
                break;
        }

        _delay_ms(1000);
    }

    return 0;
}
