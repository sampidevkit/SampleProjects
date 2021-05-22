#ifndef ADC_H
#define	ADC_H

#include <stdint.h>
#include <stdbool.h>

typedef enum {
    ADC_AN0 = 0x00,
    ADC_AN1,
    ADC_AN2,
    ADC_AN3,
    ADC_AN4,
    ADC_AN5,
    ADC_AN6,
    ADC_AN7
} adc_channel_t;

void ADC_Initialize(void);
uint16_t ADC_GetValOnChannel(adc_channel_t channel);

#endif