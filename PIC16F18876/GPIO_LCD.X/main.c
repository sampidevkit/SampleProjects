/*
 * File:   main.c
 * Author: SANG
 *
 * Created on July 14, 2021, 7:52 PM
 */


#include "config.h"
#include "system.h"
#include "lcd.h"

void main(void)
{
    //ADCON0bits.ADON = 0;
    OSCCON1=0;
    OSCCON2bits.COSC=0B110;
    OSCCON2bits.CDIV=0B000;
    TRISCbits.TRISC0=0;
    TRISCbits.TRISC1=0;
    TRISCbits.TRISC4=0;
    TRISCbits.TRISC5=0;
    TRISCbits.TRISC6=0;
    TRISCbits.TRISC7=0;

    TRISDbits.TRISD0=1;
    ANSELDbits.ANSD0=0;

    LATCbits.LATC0=0;
    LATCbits.LATC1=0;
    LATCbits.LATC4=0;
    LATCbits.LATC5=0;
    LATCbits.LATC6=0;
    LATCbits.LATC6=0;
    //cho nguon dien on dinh
    //delay_ms(100);
    //khoi dong lcd
    LCD_Init();
    //di chuyen con tro chuot
    //LCD_Goto(LCD_LINE_1,0);
    //viet doan test
    //  LCD_WriteString(" PIC16F18876 !");
    //1 ky tu dung day nhay don
    //LCD_WriteChar('S');
    //di chuyen xuong dong duoi
    //  LCD_Goto(LCD_LINE_2, 3);
    //viet so 100
    //  LCD_WriteUnSigned(100);
    // uint16_t Counter = 0;
    // int8_t vitri = 15;
    while(true)
    {
        LCD_Clear();
        LCD_Goto(LCD_LINE_1, 0);

        if(NUT_NHAN==1)
            LCD_WriteString("NUT DUOC NHAN");
        else
            LCD_WriteString("NUT KHONG NHAN");

        delay_ms(100);
    }
}



