
#include "config.h"
#include "gpio.h"
#include "lcd.h"
#include "system.h"
void delay_ms(uint16_t time)
{
    while(time>0)
    {
        time--;
        __delay_ms(10);
    }
}