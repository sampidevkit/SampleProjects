#include "main.h"
#include <stdint.h>
#include <stdbool.h>
#include <lcd.c>

typedef enum
{
    LM35_1=0,
    LM35_2,
    LM35_3
} cam_bien_t;

static bool Nut_Nhan(void)
{
    static bool prv=1;

    if(prv!=input(BUTTON))
    {
        prv=input(BUTTON);

        if(prv==0)
            return 1;
    }

    return 0;
}

uint8_t Doc_Cam_Bien(cam_bien_t idx)
{
    switch(idx)
    {
        case LM35_1:
            set_adc_channel(0);
            break;

        case LM35_2:
            set_adc_channel(1);
            break;

        case LM35_3:
            set_adc_channel(3);
            break;

        default:
            return 0;
    }

    delay_us(20);

    uint32_t t=(int16_t) read_adc();

    t*=500;
    t/=1024;

    return (uint8_t) t;
}

void Hien_Thi_Chung(void)
{
    uint8_t T1=Doc_Cam_Bien(LM35_1);
    uint8_t T2=Doc_Cam_Bien(LM35_2);
    uint8_t T3=Doc_Cam_Bien(LM35_3);

    lcd_gotoxy(1, 1);
    printf(lcd_putc, "U4=%03d, U3=%03d\nU2=%03d", T1, T2, T3);
}

void Hien_Thi_1(void)
{
    uint8_t T1=Doc_Cam_Bien(LM35_1);

    lcd_gotoxy(1, 1);
    printf(lcd_putc, "CAM BIEN U4\nT=%03d", T1);
}

void Hien_Thi_2(void)
{
    uint8_t T2=Doc_Cam_Bien(LM35_2);

    lcd_gotoxy(1, 1);
    printf(lcd_putc, "CAM BIEN U3\nT=%03d", T2);
}

void Hien_Thi_3(void)
{
    uint8_t T3=Doc_Cam_Bien(LM35_3);

    lcd_gotoxy(1, 1);
    printf(lcd_putc, "CAM BIEN U2\nT=%03d", T3);
}

void main(void)
{
    uint8_t Mode=0;
    uint16_t Count=0;

    setup_adc_ports(AN0_AN1_AN3);
    setup_adc(ADC_CLOCK_INTERNAL);
    lcd_init();

    while(true)
    {
        if(++Count>100) // C?p nh?t hi?n th? sau 100 chu k? code
            Count=0;

        if(Nut_Nhan())
        {
            lcd_putc('\f'); // clear LCD

            if(++Mode>3)
                Mode=0;

            Count=0;
        }

        if(Count==0)
        {
            switch(Mode)
            {
                default:
                case 0:
                    Hien_Thi_Chung();
                    break;

                case 1:
                    Hien_Thi_1();
                    break;

                case 2:
                    Hien_Thi_2();
                    break;

                case 3:
                    Hien_Thi_3();
                    break;
            }
        }
    }
}
