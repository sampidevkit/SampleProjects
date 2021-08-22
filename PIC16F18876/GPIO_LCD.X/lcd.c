


#include "lcd.h"
#include "gpio.h"
#include "system.h"
#include "config.h"

void LCD_Init(void)
{
    LCD_SetData(0x00);
    __delay_ms(5);
    LCD_RS=0;
    LCD_SetData(0x03);
    LCD_PulseEnable();
    LCD_PulseEnable();
    LCD_PulseEnable();
    LCD_SetData(0x02);
    LCD_PulseEnable();
    LCD_WriteCommand(0x2C);
    LCD_WriteCommand(0x0C);
    LCD_WriteCommand(0x06);
    LCD_Clear();
    LCD_Goto(LCD_LINE_1, 0);
}

void LCD_WriteCommand(unsigned char cmd)
{
    cmd=(cmd>>4)|(cmd<<4);
    LCD_SetData(cmd);
    LCD_PulseEnable();
    cmd=(cmd>>4)|(cmd<<4);
    LCD_SetData(cmd);
    LCD_PulseEnable();
}

void LCD_PulseEnable(void)
{
    LCD_EN=1;
    __delay_us(5);
    LCD_EN=0;
    __delay_us(50);
}

void LCD_SetData(unsigned char data)
{
    LCD_C4=(unsigned) ((data&0x01)>0);
    LCD_C5=(unsigned) ((data&0x02)>0);
    LCD_C6=(unsigned) ((data&0x04)>0);
    LCD_C7=(unsigned) ((data&0x08)>0);
}

void LCD_Goto(unsigned char line, unsigned char pos)
{
    LCD_WriteCommand(line+pos);
}

void LCD_Clear(void)
{
    LCD_WriteCommand(LCD_CLEAR);
    __delay_ms(2);
}

void LCD_WriteChar(char c)
{
    LCD_RS=1;
    LCD_WriteCommand(c);
    LCD_RS=0;
}

void LCD_WriteString(char *str)
{
    char *ptr=str;
    while(*ptr!=0)
    {
        LCD_WriteChar(*ptr);
        ptr++;
    }
}

void LCD_WriteSigned(int32_t number)
{
    char c[11];
    sprintf(c, "%ld", number);
    LCD_WriteString(c);
}

void LCD_WriteUnSigned(uint32_t number)
{
    char c[10];
    sprintf(c, "%lu", number);
    LCD_WriteString(c);
}

void LCD_WriteFloat(float f)
{
    char c[10];
    memset(c, 0, 10);
    int32_t i=(int32_t) (f*100);
    unsigned int len=0;
    while(i>0)
    {
        c[len]=i%10+'0';
        i/=10;
        len++;
    }
    while(len>0)
    {
        len--;
        if(len==1) LCD_WriteChar('.');
        LCD_WriteChar(c[len]);
    }
}

void LCD_WriteBinany(int8_t b)
{
    for(int idx=0; idx<8; idx++)
    {
        if((b&0x80)>0) LCD_WriteChar('1');
        else LCD_WriteChar('0');
        b<<=1;
    }
}
