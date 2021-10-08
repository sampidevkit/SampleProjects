#include <16F877A.h>
#device ADC=10
#use delay(crystal=20MHz)

#define LCD_RS_PIN      PIN_C0
#define LCD_RW_PIN      PIN_C1 // không c?n dùng chân này
#define LCD_ENABLE_PIN  PIN_C2
#define LCD_DATA4       PIN_C4
#define LCD_DATA5       PIN_C5
#define LCD_DATA6       PIN_C6
#define LCD_DATA7       PIN_C7
#define BUTTON          PIN_D6