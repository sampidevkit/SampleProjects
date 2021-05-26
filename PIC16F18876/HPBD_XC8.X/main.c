#include "mcc_generated_files/mcc.h"

// NOTE                 FREQUENCY
// Octave0  Octave1  Octave2  Octave3
#define C_NOTE0 262
#define C_NOTE1 523
#define C_NOTE2 1047
#define C_NOTE3 2093

#define Db_NOTE0 277
#define Db_NOTE1 554
#define Db_NOTE2 1109
#define Db_NOTE3 2217

#define D_NOTE0 294
#define D_NOTE1 587
#define D_NOTE2 1175
#define D_NOTE3 2349

#define Eb_NOTE0 311
#define Eb_NOTE1 622
#define Eb_NOTE2 1245
#define Eb_NOTE3 2489

#define E_NOTE0 330
#define E_NOTE1 659
#define E_NOTE2 1329
#define E_NOTE3 2637

#define F_NOTE0 349
#define F_NOTE1 698
#define F_NOTE2 1397
#define F_NOTE3 2794

#define Gb_NOTE0 370
#define Gb_NOTE1 740
#define Gb_NOTE2 1480
#define Gb_NOTE3 2960

#define G_NOTE0 392
#define G_NOTE1 784
#define G_NOTE2 1568
#define G_NOTE3 3136

#define Ab_NOTE0 415
#define Ab_NOTE1 831
#define Ab_NOTE2 1661
#define Ab_NOTE3 3322

#define A_NOTE0 440
#define A_NOTE1 880
#define A_NOTE2 1760
#define A_NOTE3 3520

#define Bb_NOTE0 466
#define Bb_NOTE1 923
#define Bb_NOTE2 1865
#define Bb_NOTE3 3729

#define B_NOTE0 494
#define B_NOTE1 988
#define B_NOTE2 1976
#define B_NOTE3 3951

void do_delay(int ms_delay, int num_ms, int us_delay, int num_us)
{
    int i;

    for(i=0; i<num_ms; i++)
    {
        CLRWDT();
        __delay_ms(250);
    }

    while(ms_delay>0)
    {
        CLRWDT();
        ms_delay--;
        __delay_ms(1);
    }

    for(i=0; i<num_us; i++)
        __delay_us(250);

    while(us_delay>0)
    {
        us_delay--;
        __delay_us(1);
    }
}

void generate_tone(long frequency, long duration)
{
    uint32_t total_delay_time; // in microseconds

    long total_ms_delay_time, total_us_delay_time;
    int num_us_delays, num_ms_delays, ms_delay_time, us_delay_time;
    long num_periods;

    total_delay_time=(uint32_t) ((1000000/frequency)/2-10); // calculate total delay time (10 for error)

    total_ms_delay_time=total_delay_time/1000; // total delay time of ms
    num_ms_delays=(int) (total_ms_delay_time/250); // number of 250ms delays needed
    ms_delay_time=total_ms_delay_time%250; // left over ms delay time needed
    ////////////////////////////////////
    total_us_delay_time=total_delay_time%1000; // total delay time of us (ms already acounted for)
    num_us_delays=(int) (total_us_delay_time/250); // number of 250us delays needed
    us_delay_time=total_us_delay_time%250; // left over us delay time needed

    num_periods=(duration*1000)/(1000000/frequency);

    while((num_periods--)!=0)
    {
        CLRWDT();
        do_delay(ms_delay_time, num_ms_delays, us_delay_time, num_us_delays);
        BUZZER_SetHigh();
        do_delay(ms_delay_time, num_ms_delays, us_delay_time, num_us_delays);
        BUZZER_SetLow();
    }

    return;
}

#define SIZE 25

const struct note
{
    long tone;
    long length;
} happy_bday[SIZE]={
    C_NOTE0, 350, C_NOTE0, 100, D_NOTE0, 500, C_NOTE0, 500, F_NOTE0, 500, E_NOTE0, 900,
    C_NOTE0, 350, C_NOTE0, 100, D_NOTE0, 500, C_NOTE0, 500, G_NOTE0, 500, F_NOTE0, 900,
    C_NOTE0, 350, C_NOTE0, 100, C_NOTE1, 500, A_NOTE0, 500, F_NOTE0, 500, E_NOTE0, 500, D_NOTE0, 900,
    Bb_NOTE0, 350, Bb_NOTE0, 100, A_NOTE0, 500, F_NOTE0, 500, G_NOTE0, 500, F_NOTE0, 1200
};

void main(void)
{
    SYSTEM_Initialize();
    //INTERRUPT_GlobalInterruptEnable();
    //INTERRUPT_PeripheralInterruptEnable();

    while(1)
    {
        int i;

        for(i=0; i<SIZE; ++i)
        {
            generate_tone(happy_bday[i].tone, happy_bday[i].length);
            __delay_ms(75);
        }
    }
}