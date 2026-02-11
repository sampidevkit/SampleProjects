#include "mcc_generated_files/mcc.h"

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
    ADC_MUXPOS_t Ch=ADC_MUXPOS_GND_gc;

    SYSTEM_Initialize();
    DAC0_SetOutput(500);
    AC0.DACREF = 250;
    AC1.DACREF = 125;
    AC2.DACREF = 50;
    RTC_SetPITIsrCallback(PIT_UserCb);
    printf("\r\nAVR128DA48 ADC\r\n");

    while(1)
    {
        if(SW0_IsPressed())
        {
            uint32_t val;

            ADC0_Enable();
            val=(uint32_t) ADC0_GetConversion(Ch)/4;
            ADC0_Disable();

            switch(Ch)
            {
                case ADC_MUXPOS_GND_gc:
                    Ch=ADC_MUXPOS_TEMPSENSE_gc;
                    printf("\r\nADC MUXPOS GND=%ld", val);
                    break;

                case ADC_MUXPOS_TEMPSENSE_gc:
                    Ch=ADC_MUXPOS_DAC0_gc;
                    printf("\r\nADC MUXPOS TEMPSENSE=%ld", val);
                    break;

                case ADC_MUXPOS_DAC0_gc:
                    Ch=ADC_MUXPOS_DACREF0_gc;
                    printf("\r\nADC MUXPOS DAC0=%ld", val);
                    break;

                case ADC_MUXPOS_DACREF0_gc:
                    Ch=ADC_MUXPOS_DACREF1_gc;
                    printf("\r\nADC MUXPOS DACVREF0=%ld", val);
                    break;

                case ADC_MUXPOS_DACREF1_gc:
                    Ch=ADC_MUXPOS_DACREF2_gc;
                    printf("\r\nADC MUXPOS DACVREF1=%ld", val);
                    break;

                case ADC_MUXPOS_DACREF2_gc:
                    Ch=ADC_MUXPOS_GND_gc;
                    printf("\r\nADC MUXPOS ACVREF2=%ld", val);
                    break;

                default:
                    break;
            }

            //val*=2048;
            //val/=4096;
            printf(", U=%ld mV", val);
        }
    }

    return 0;
}
