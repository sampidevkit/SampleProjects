#include "mcc_generated_files/mcc.h"

void main(void)
{
    SYSTEM_Initialize();
    ANSELA=0;
    ANSELC=0;
    ANSELCbits.ANSC1=1;
    ADCON0bits.ADON=0;
    
#ifdef USE_FVR
    ADCON1=0b10100011; // ADFM right; ADPREF FVR; ADCS FOSC/32;  
#else
    ADCON1=0b10100000; // ADFM right; ADPREF VDD; ADCS FOSC/32; 
#endif

    while(1)
    {
        uint32_t vin=ADC_GetConversion(VIN_DIV);

#ifdef USE_FVR// VREF=FVR=2048mV
        vin*=12;
#else// VREF=VDD=3300mV
        vin*=2475;
        vin>>=7;
#endif

        printf("\nVin=%d mV\r", (uint16_t) vin);
        __delay_ms(500);
    }
}