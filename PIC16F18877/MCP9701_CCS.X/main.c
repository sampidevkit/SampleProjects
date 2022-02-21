#include <main.h>

#define MCP9701_ADC_RES_BIT 10
#define MCP9701_ADC_VREF    2048 // FVR output 1

static float MCP9701_GetTemp(void) // <editor-fold defaultstate="collapsed" desc="Thermal sensor">
{
    int32_t tmp=(int16_t) adc_read(ADC_RESULT);
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
    output_low(VSSEN);
    setup_vref(VREF_ON|VREF_ADC_2v048);
    delay_ms(1000);
    init_graph();

    setup_timer_2(T2_CLK_INTERNAL|T2_DIV_BY_128, 255, 15); //~250ms period
    setup_adc(ADC_LEGACY_MODE|ADC_CLOCK_INTERNAL|ADC_TAD_MUL_255|ADC_ADRES_TO_ADPREV_AT_START|ADC_THRESHOLD_INT_END_OF_CALCULATION|ADC_CONTINUOUS_OPERATION_ENABLED);
    //setup_adc_ports(NO_ANALOGS);
    setup_adc_ports(NO_ANALOGS|sAN25);
    setup_adc_reference(VSS_FVR);
    set_adc_channel(sAN25);
    set_adc_trigger(ADC_TRIGGER_TIMER2);
    graph_clear();

    while(TRUE)
    {
        if(interrupt_active(INT_AD_THRESHOLD))
        {
            output_high(BLED);
            graph_point(adc_read(ADC_RESULT));
            clear_interrupt(INT_AD_THRESHOLD);
            output_low(BLED);
        }
    }
}
