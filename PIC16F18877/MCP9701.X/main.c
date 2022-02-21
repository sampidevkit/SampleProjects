#include "mcc_generated_files/mcc.h"

#define MCP9701_ADC_RES_BIT 10
#define MCP9701_ADC_VREF    2048 // FVR output 1

static float MCP9701_GetTemp(void) // <editor-fold defaultstate="collapsed" desc="Thermal sensor">
{
    int32_t tmp=ADCC_GetSingleConversion(MCP970X);
    // convert to mV
    tmp*=MCP9701_ADC_VREF;
    tmp>>=MCP9701_ADC_RES_BIT; // mV=(ADCvalue*Vref)>>ADC_resolution
    // Offset 500mV at 0 C degree
    tmp-=400;
    // Resolution MCP9701: 19.5mV/C degree
    return (((float) tmp)/19.5f);
} // </editor-fold>

void main(void)
{
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();

    while (1)
    {

    }
}