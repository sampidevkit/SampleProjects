
#include <xc.h>
#include "lcd.h"

void LCD_Initialize()
{
    LCD_PORT=0; // clear latches before enabling TRIS bits
    TRISD=0x00;
    LCD_PWR=1; // power up the LCD
    __delay_ms(LCD_Startup); // required by display controller to allow power to stabilize
    LCDPutCmd(0x32); // required by display initialization
    LCDPutCmd(FUNCTION_SET); // set 4-bit interface mode and 16x2 of lines and font
    LCDPutCmd(DISPLAY_SETUP); // turn on display and sets up cursor
    LCD_clear();
    LCDPutCmd(ENTRY_MODE); // set cursor movement direction

}

void LCD_clear(void)
{
    LCDPutCmd(0x01);
}

void LCDWriteNibble(uint8_t ch, uint8_t rs)
{

    ch=(uint8_t) (ch>>4); // always send the upper nibble
    ch=(uint8_t) (ch&0x0F); // mask off the nibble to be transmitted
    LCD_PORT=(uint8_t) (LCD_PORT&0xF0); // clear the lower half of LCD_PORT
    LCD_PORT=(uint8_t) (LCD_PORT|ch); // move the nibble onto LCD_PORT
    LCD_RS=rs; // set data/instr bit to 0 = insructions; 1 = data
    LCD_RW=0; // RW - set write mode
    LCD_EN=1; // set up enable before writing nibble
    LCD_EN=0; // turn off enable after write of nibble
}

void LCDPutChar(uint8_t ch)//vd:b: 01100010
{
    __delay_ms(5);

    //Send higher nibble first
    LCDWriteNibble(ch, data); //data	1

    //get the lower nibble
    ch=(uint8_t) (ch<<4);

    // Now send the low nibble
    LCDWriteNibble(ch, data); //data	1
}

void LCDPutCmd(uint8_t ch)
{
    __delay_ms(LCD_delay);
    LCDWriteNibble(ch, instr); //Send the higher nibble
    ch=(uint8_t) (ch<<4); //get the lower nibble
    __delay_ms(1);
    LCDWriteNibble(ch, instr); //Now send the lower nibble
}

void LCDPutStr(const uint8_t *str)
{
    uint8_t i=0;

    // While string has not been fully traveresed
    while(str[i])
    {
        // Go display current uint8_t
        LCDPutChar(str[i++]);
    }

}
/*  
void LCDGoto(uint8_t ln,uint8_t pos)
{
// if incorrect line or column
if ((ln > (NB_LINES-1)) || (pos > (NB_COL-1)))
{
// Just do nothing
return;
}

// LCD_Goto command
LCDPutCmd((ln == 1) ? (0xC0 | pos) : (0x80 | pos));

// Wait for the LCD to finish
__delay_ms(LCD_delay);
}
 */

/*
void LCDvt(unsigned uint8_t line, unsigned uint8_t column)//LcdGoto(1,2);
{
    uint8_t temp,z,y;
    if(line == 1)
    {
        temp = 0x80 + column - 1;//vd: column = 3, temp = 0x82 + 0x03 - 1 -> 10000010 + 00000011 - 00000001 = 10000100
        z = temp>>4;//z = 00001000
        y = temp & 0x0F; // y = 00000100
        LCDPutCmd(z);//Lcd_Cmd(0x08)
        LCDPutCmd(y);//Lcd_Cmd(0x04)
    }
    else if(line == 2)
    {
        temp = 0xC0 + column - 1;
        z = temp>>4;
        y = temp & 0x0F;
        LCDPutCmd(z);
        LCDPutCmd(y);
    }
}
 */
void LCDGoto(uint8_t line, uint8_t column)
{
    uint8_t temp2;
    switch(line)
    {
        case 1:
            temp2=(uint8_t)((column-1)+0x80);
            break;
        case 2:
            temp2=(uint8_t)((column-1)+0xc0);
            break;
    }
    LCDPutCmd(temp2);
    __delay_us(100);
}


/**
 End of File
 */


