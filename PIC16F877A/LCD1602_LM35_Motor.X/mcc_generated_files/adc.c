#include "adc.h"
#include "mcc.h"

void ADC_Initialize(void)
{
    // FRC (clock derived from the internal A/D RC oscillator)
    ADCON0=0b11000000;
    // Right justified. Six (6) Most Significant bits of ADRESH are read as ?0?.
    // FRC (clock derived from the internal A/D RC oscillator)
    // A/D Port: AN0, VREF+=VDD, VREF-=VSS
    ADCON1=0b11001110;
    ADRESL=0x00;
    ADRESH=0x00;
    ADCON0bits.ADON=1;
}

uint16_t ADC_GetValOnChannel(adc_channel_t channel)
{
    static uint16_t prvVal=0;
    static adc_channel_t prvCh=0;

    if(prvCh!=channel)
    {
        // Turn off ADC
        ADCON0bits.ADON=0;
        // select the A/D channel
        ADCON0bits.CHS=channel;
        // Turn on the ADC module
        ADCON0bits.ADON=1;
        // Acquisition time delay
        __delay_us(20);
        // Start the conversion
        ADCON0bits.GO_nDONE=1;
        // update new channel
        prvCh=channel;
        // Wait for the conversion to finish
        while(ADCON0bits.GO_nDONE);
        __delay_us(50);
        // Conversion finished, return the result
        prvVal=((uint16_t) ((ADRESH<<8)+ADRESL));
        prvVal&=0b0000001111111111;
        // Start the conversion
        ADCON0bits.GO_nDONE=1;
    }
    else if(ADCON0bits.GO_nDONE==0)
    {
        __delay_us(50);
        prvVal=((uint16_t) ((ADRESH<<8)+ADRESL));
        prvVal&=0b0000001111111111;
        // Start new conversion
        ADCON0bits.GO_nDONE=1;
    }

    return prvVal; // if not ready, return previous value
}