#include<16f877a.h>
#device ADC=10
#use delay(clock=4MHz)
#use FIXED_IO(B_outputs=PIN_B3, PIN_B4, PIN_B5) // digit pins
#use FIXED_IO(D_outputs=PIN_D0, PIN_D1, PIN_D2, PIN_D3, PIN_D4, PIN_D5, PIN_D6, PIN_D7) // segment pins

#include <stdint.h>
#include <stdbool.h>

#define BT_VAO                  PIN_A0
#define BT_RA                   PIN_A1
#define BT_RESET                PIN_A2

#define DIGIT_TRAM              PIN_B3
#define DIGIT_CHUC              PIN_B4
#define DIGIT_DONVI             PIN_B5

#define CAP_NHAT_SEGMENT        0
#define TAT_HIEN_THI            1
#define HIEN_THI_DIGIT_DONVI    2
#define HIEN_THI_DIGIT_CHUC     4
#define HIEN_THI_DIGIT_TRAM     6

static const uint8_t CODE_7SEG[10]={0xc0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

static void HIEN_THI(int16_t value) // <editor-fold defaultstate="collapsed" desc="7-Seg LED display">
{
    static uint8_t DoNext=CAP_NHAT_SEGMENT;
    static int16_t segment=0x00;

    switch(DoNext)
    {
        case HIEN_THI_DIGIT_DONVI:
            output_low(DIGIT_DONVI);
            DoNext++;
            break;

        case HIEN_THI_DIGIT_CHUC:
            output_low(DIGIT_CHUC);
            DoNext++;
            break;

        case HIEN_THI_DIGIT_TRAM:
            output_low(DIGIT_TRAM);
            DoNext=CAP_NHAT_SEGMENT;
            break;

        case CAP_NHAT_SEGMENT: // Update new segment value
            segment=value;
            DoNext=TAT_HIEN_THI;
        case TAT_HIEN_THI: // Turn off all digit
        default:
            output_high(DIGIT_TRAM);
            output_high(DIGIT_CHUC);
            output_high(DIGIT_DONVI);
            output_d(CODE_7SEG[segment%10]);
            segment/=10;
            DoNext++;
            break;
    }
} // </editor-fold>

static bool BT_VAO_Is_Pressed(void) // <editor-fold defaultstate="collapsed" desc="Button VAO">
{
    static bool prv=1;
    static uint8_t t=0;

    if(prv!=input(BT_VAO))
    {
        if(prv==1)
        {
            if(++t>100) // check 100 cycles
            {
                prv=0;
                return 1;
            }
        }
        else
            prv=1;
    }
    else if(t>0)
        t=0;

    return 0;
} // </editor-fold>

static bool BT_RA_Is_Pressed(void) // <editor-fold defaultstate="collapsed" desc="Button RA">
{
    static bool prv=1;
    static uint8_t t=0;

    if(prv!=input(BT_RA))
    {
        if(prv==1)
        {
            if(++t>100) // check 100 cycles
            {
                prv=0;
                return 1;
            }
        }
        else
            prv=1;
    }
    else if(t>0)
        t=0;

    return 0;
} // </editor-fold>

static bool BT_RESET_Is_Pressed(void) // <editor-fold defaultstate="collapsed" desc="Button RESET">
{
    static bool prv=1;
    static uint8_t t=0;

    if(prv!=input(BT_RESET))
    {
        if(prv==1)
        {
            if(++t>100) // check 100 cycles
            {
                prv=0;
                return 1;
            }
        }
        else
            prv=1;
    }
    else if(t>0)
        t=0;

    return 0;
} // </editor-fold>

void main(void)
{
    int16_t giatri=0;
    set_tris_a(0b00111111);
    setup_adc(ADC_OFF);

    while(TRUE)
    {
        if(BT_VAO_Is_Pressed())
        {
            if(++giatri>999)
                giatri=0;
        }
        
        if(BT_RA_Is_Pressed())
        {
            if(--giatri<0)
                giatri=999;
        }
        
        if(BT_RESET_Is_Pressed())
            giatri=0;
        
        HIEN_THI(giatri);
        //delay_ms(100);
    }
}