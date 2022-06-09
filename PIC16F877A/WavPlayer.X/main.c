/*
    WAV Player using PIC16F877A microcontroller and SD card CCS C code.
    https://ccspicc.blogspot.com/2017/09/wav-player-pic16f877a-sd-card.html?fbclid=IwAR3gXRlWb5_IR_cweX2ycAfuKLuIqKUl-mtBDClhF7KHAyVhmuNCqQDzTkQ&m=1&fs=e&s=cl
 */

#include <16F877A.h>
#device ADC=10
#use delay(crystal=20MHz)
#use FIXED_IO(D_outputs=PIN_D3)

// SD Card module connections
#define SDCARD_SPI_HW
#define SDCARD_PIN_SELECT  PIN_D3
// End SD card module connections

#include "FAT_Lib.c"

static void play(void) // <editor-fold defaultstate="collapsed" desc="WAV play">
{
    int8 i, j, data[16], channel_count;

    sdcard_read_byte(address_pointer+22, &channel_count); // Read number of channels

    while(fat_read_data(16, data)==0)
    {
        for(i=0; i<16; i++)
        {
            set_timer1(0);
            j=data[i];
            set_pwm1_duty((int16) j); // Update PWM1 duty cycle

            if(channel_count==2)
            { // If 2-channel wave file (stereo)
                i++; // increment i
                j=data[i];
                set_pwm2_duty((int16) j); // Update PWM2 duty cycle
            }

            while(get_timer1()<500); // Wait some time (about 125us) to update the duty cycles
        }
    }
} // </editor-fold>

void main(void) // <editor-fold defaultstate="collapsed" desc="main function">
{
    const int8 *wav="mywav.wav";
    int1 ok=0;

    delay_ms(2000);
    setup_ccp1(CCP_PWM); // Configure CCP1 as a PWM
    setup_ccp2(CCP_PWM); // Configure CCP2 as a PWM
    set_pwm1_duty((int16) 0); // set PWM1 duty cycle to 0
    set_pwm2_duty((int16) 0); // set PWM2 duty cycle to 0
    setup_timer_2(T2_DIV_BY_1, 63, 1); // Set PWM frequency to maximum with 8-bit resolution
    setup_timer_1(T1_INTERNAL|T1_DIV_BY_1);
    ok|=sdcard_init(); // Initialize the SD card module
    ok|=fat_init(); // Initialize FAT library
    ok|=fat_open_file(wav); // Open the wave file

    if(ok==0)
        play();

    set_pwm1_duty((int16) 0); // set PWM1 duty cycle to 0
    set_pwm2_duty((int16) 0); // set PWM2 duty cycle to 0
    reset_cpu(); // system reset, play again
} // </editor-fold>
