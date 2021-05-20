// PIC16F877A Configuration Bit Settings
// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>
#include <stdio.h>
#include <stdint.h>
#include "lcd.h"

// get/set HX711_DOUT aliases
#define HX711_DOUT_SetHigh()            (PORTBbits.RB4 = 1)
#define HX711_DOUT_SetLow()             (PORTBbits.RB4 = 0)
#define HX711_DOUT_Toggle()             (PORTBbits.RB4 ^= 1)
#define HX711_DOUT_GetValue()           PORTBbits.RB4
#define HX711_DOUT_SetDigitalInput()    (TRISBbits.TRISB4 = 1)
#define HX711_DOUT_SetDigitalOutput()   (TRISBbits.TRISB4 = 0)
// get/set HX711_SCLK aliases
#define HX711_SCLK_SetHigh()            (PORTBbits.RB5 = 1)
#define HX711_SCLK_SetLow()             (PORTBbits.RB5 = 0)
#define HX711_SCLK_Toggle()             (PORTBbits.RB5 ^= 1)
#define HX711_SCLK_GetValue()           PORTBbits.RB5
#define HX711_SCLK_SetDigitalInput()    (TRISBbits.TRISB5 = 1)
#define HX711_SCLK_SetDigitalOutput()   (TRISBbits.TRISB5 = 0)

char bulf[10];
#define HX711_SCALE 36

void HX711_Init(void)
{
    HX711_SCLK_SetHigh();
    HX711_DOUT_SetDigitalInput();
    HX711_SCLK_SetDigitalOutput();
}

uint32_t HX771_Read(void)
{
    uint8_t i;
    uint32_t value;

    while(HX711_DOUT_GetValue()==1);

    __delay_us(1);

    for(i=0, value=0; i<25; i++) // channel A, gain 128
    {
        HX711_SCLK_SetHigh();
        value<<=1;
        __delay_us(1);
        HX711_SCLK_SetLow();
        value|=HX711_DOUT_GetValue();
        __delay_us(1);
    }

    value>>=1; // remove bit 25
    value^=0x00800000;

    return value;
}

uint32_t Read_tb(void)
{
    int j;
    uint32_t sum=0;

    for(j=0; j<16; j++)
        sum+=HX771_Read();

    return (sum>>=4); // div 16
}

int main(void)
{
    float read1=0, offset=0, gram=0;

    LCD_Initialize();
    HX711_Init();
    LCD_clear();
    LCDGoto(1, 2);
    LCDPutStr("LOAD CELL 5KG");
    offset=Read_tb();
    __delay_ms(500);

    while(1)
    {
        read1=Read_tb();

        if(offset>=read1)
        {
            float val1=(offset-read1);
            gram=val1;
        }
        else
        {
            float val2=(read1-offset);
            gram=val2;
        }

        sprintf(bulf, "%.2f gram", gram/HX711_SCALE);
        LCDGoto(2, 8);
        LCDPutStr(bulf);
    }

    return 0;
}