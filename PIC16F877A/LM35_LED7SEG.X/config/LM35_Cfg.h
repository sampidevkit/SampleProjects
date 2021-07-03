#ifndef LM35_CFG_H
#define	LM35_CFG_H

#define NUM_OF_LM35             1
#define LM35_ADC_VREF           5000 // mV
#define LM35_ADC_RES            1024 // 10bit

#define LM35_1_ADC_POS_CHANNEL  ADC_AN0
//#define LM35_1_ADC_NEG_CHANNEL  ADC_AN1
#define LM35_1_ADC_NEG_CHANNEL  0xFF // not use

#define LM35_GetADC(ch)         ADC_GetValOnChannel(ch)

#endif