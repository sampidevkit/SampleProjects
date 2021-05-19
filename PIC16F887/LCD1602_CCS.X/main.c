#include <16F887.h>

#device ADC=10
#use delay(internal=8MHz)
#use FIXED_IO(C_outputs=PIN_C6, PIN_C5, PIN_C4, PIN_C3, PIN_C2, PIN_C1, PIN_C0)

#define LCD_RS_PIN   PIN_C0
#define LCD_RW_PIN   PIN_C1
#define LCD_ENABLE_PIN   PIN_C2
#define LCD_DATA4   PIN_C3
#define LCD_DATA5   PIN_C4
#define LCD_DATA6   PIN_C5
#define LCD_DATA7   PIN_C6

#include <LCD.C>

void main(void)
{
    /* LCD 1602 display map
      ----------------------------
     |[1, 1][1, 1][1, ...][16, 1]|
     |[1, 2][2, 2][2, ...][16, 2]|
      ----------------------------                                            */
    lcd_init();
    delay_ms(100);
    lcd_gotoxy(3, 1); // goto position x of line y
    printf(lcd_putc, "LCD1602 Demo\nHello World");
    delay_ms(1000);
    lcd_gotoxy(1, 2);
    printf(lcd_putc, "Count=");

    int i=0;

    while(TRUE)
    {
        lcd_gotoxy(7, 2);
        printf(lcd_putc, "%04u      ", i++);
        delay_ms(100);
    }
}
