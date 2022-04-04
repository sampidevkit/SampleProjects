#include "mcc_generated_files/mcc.h"
#define MCP9701_ADC_RES_BIT 10  // ADC resolution
#define MCP9701_ADC_VREF    2048 // FVR output 1
//#define MCP9701_ADC_VREF    3300 // VDD

void main(void)
{
    SYSTEM_Initialize();
    ADCC_DisableContinuousConversion();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();

    while(1)
    {
        int32_t tmp=ADCC_GetSingleConversion(TEMP_SENSOR);
        // convert to mV
        tmp*=MCP9701_ADC_VREF;
        tmp>>=MCP9701_ADC_RES_BIT; // mV=(ADCvalue*Vref)>>ADC_resolution
        tmp-=400; // Offset 400mV at 0 C degree
        printf("\nVref=%dmV - ", MCP9701_ADC_VREF);
        printf("T=%.1f%cC", ((float) tmp)/19.5f, 0xB0); // Resolution MCP9701: 19.5mV/C degree
        __delay_ms(500);
    }
}