#ifndef LED7SEG_CFG_H
#define LED7SEG_CFG_H

#include <stdint.h>
#include <stdbool.h>

#define NUM_OF_7SEG_DIGIT           4
//#define USE_LED_7SEG_CC             1
#define USE_LED_7SEG_CA             1
#define LED_7SEG_ACT_TIME           4 // ms/digit
#define LED_7SEG_TOGGLE_COUNT       100

#define Led7Seg_Digit_Disable()     PORTD=0x00;
#define Led7Seg_Segment_Disable()   PORTB=0xFF;
#define Led7Seg_Segment_SetState(x) PORTB=x
#define Led7Seg_Digit_SetState(x)   PORTD=(~(1<<x))

#endif