#include <16F887.h>
#device ADC=10
#use delay(crystal=20mhz)
#include "tones.c"

#define SIZE 25

const struct note
{
    long tone;
    long length;
} happy_bday[SIZE]={
    C_note[0], 350, C_note[0], 100, D_note[0], 500, C_note[0], 500, F_note[0], 500, E_note[0], 900,
    C_note[0], 350, C_note[0], 100, D_note[0], 500, C_note[0], 500, G_note[0], 500, F_note[0], 900,
    C_note[0], 350, C_note[0], 100, C_note[1], 500, A_note[0], 500, F_note[0], 500, E_note[0], 500, D_note[0], 900,
    Bb_note[0], 350, Bb_note[0], 100, A_note[0], 500, F_note[0], 500, G_note[0], 500, F_note[0], 1200
};

void main(void)
{
    int i;

    while(TRUE)
    {
        for(i=0; i<SIZE; ++i)
        {
            generate_tone(happy_bday[i].tone, happy_bday[i].length);
            delay_ms(75);
        }
    }
}
