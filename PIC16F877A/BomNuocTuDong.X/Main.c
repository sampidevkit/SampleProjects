#include <16F887.h>
#device ADC=10
#fuses HS, WDT
#use delay(crystal=16MHz, clock=16MHz)
#use FIXED_IO(C_outputs=PIN_C0, PIN_C1, PIN_C5, PIN_C6, PIN_C7)

//#define REBOOT_TIME 600 // 1min *60s *1000ms/100
#define REBOOT_TIME 3000 // 5min *60s *1000ms/100
//#define REBOOT_TIME 6000 // 10min *60s *1000ms/100
//#define REBOOT_TIME 18000 // 30min *60s *1000ms/100
//#define REBOOT_TIME 36000 // 60min *60s *1000ms/100

#define SYS_STT     PIN_C5

#define BUMP1       PIN_C0
#define EER_LED1    PIN_C6
#define SW11        PIN_D6
#define SW12        PIN_D7

#define BUMP2       PIN_C1
#define EER_LED2    PIN_C7
#define SW21        PIN_E0
#define SW22        PIN_E1

#include <stdbool.h>
#include <stdint.h>
#include "Tick_Timer.h"

typedef struct
{

    struct
    {
        bool Prev; // Previous state of Bump
        bool Pres; // Present state of Bump
    } State;
    tick_timer_t Tout;
    tick_timer_t Terr;
} control_t;

control_t Bump1Ctr, Bump2Ctr;
tick_timer_t TickSYS;

void main(void)
{
    uint16_t rebootCount=0;

    setup_wdt(WDT_ON);
    setup_wdt(WDT_2304MS|WDT_DIV_2); //~1.1 s reset
    Tick_Init();

    Tick_Reset(TickSYS);
    output_low(SYS_STT);

    Tick_Reset(Bump1Ctr.Terr);
    Tick_Reset(Bump1Ctr.Tout);
    Bump1Ctr.State.Prev=0;
    Bump1Ctr.State.Pres=0;
    output_bit(BUMP1, Bump1Ctr.State.Pres);
    output_low(EER_LED1);

    Tick_Reset(Bump2Ctr.Terr);
    Tick_Reset(Bump2Ctr.Tout);
    Bump2Ctr.State.Prev=0;
    Bump2Ctr.State.Pres=0;
    output_bit(BUMP2, Bump2Ctr.State.Pres);
    output_low(EER_LED2);

    uint8_t DoNext1=0;
    uint8_t DoNext2=0;

    while(true)
    {
        if(Tick_Is_Over(&TickSYS, 100))
        {
            if(rebootCount<REBOOT_TIME)
            {
                if((input(BUMP1)==0) && (input(BUMP2)==0)) // Disable auto reboot while bump is running
                    rebootCount++;

                restart_wdt();
                output_toggle(SYS_STT);
            }
            else
                reset_cpu();
        }

        switch(DoNext1)// <editor-fold defaultstate="collapsed" desc="Bump1Ctr">
        {
            case 1:// Bump1Ctr on
                if(Bump1Ctr.State.Prev==0)
                {
                    Bump1Ctr.State.Prev=1;
                    Tick_Reset(Bump1Ctr.Tout);
                    DoNext1=3;
                }
                else
                {
                    if((!input(SW12))&&Tick_Is_Over(&Bump1Ctr.Tout, 10000))// Waiting for 10s
                        DoNext1=4;
                    else DoNext1=0;
                }
                break;

            case 2:// Bump1Ctr off
                if(Bump1Ctr.State.Prev==1)
                {
                    Bump1Ctr.State.Prev=0;
                    DoNext1=3;
                }
                else DoNext1=0;
                break;

            case 3:// Bump1Ctr set output
                output_bit(BUMP1, Bump1Ctr.State.Pres);
                DoNext1=0;
                break;

            case 4:// Bump1Ctr stop
                output_bit(BUMP1, 0);
                DoNext1=5;
                break;

            case 5:// Bump1Ctr error
                if(Tick_Is_Over(&Bump1Ctr.Terr, 500)) output_toggle(EER_LED1);
                break;

            default:
                Bump1Ctr.State.Pres=(~input(SW12))|((~input(SW11))&Bump1Ctr.State.Prev);
                if(Bump1Ctr.State.Pres) DoNext1=1;
                else DoNext1=2;
                break;
        } // </editor-fold>

        switch(DoNext2)// <editor-fold defaultstate="collapsed" desc="Bump2Ctr">
        {

            case 1:// Bump2Ctr on
                if(Bump2Ctr.State.Prev==0)
                {
                    Bump2Ctr.State.Prev=1;
                    Tick_Reset(Bump2Ctr.Tout);
                    DoNext2=3;
                }
                else
                {
                    if((!input(SW22))&&Tick_Is_Over(&Bump2Ctr.Tout, 10000))// Waiting for 10s
                        DoNext2=4;
                    else DoNext2=0;
                }
                break;

            case 2:// Bump2Ctr off
                if(Bump2Ctr.State.Prev==1)
                {
                    Bump2Ctr.State.Prev=0;
                    DoNext2=3;
                }
                else DoNext2=0;
                break;

            case 3:// Bump2Ctr set output
                output_bit(BUMP2, Bump2Ctr.State.Pres);
                DoNext2=0;
                break;

            case 4:// Bump2Ctr stop
                output_bit(BUMP2, 0);
                DoNext2=5;
                break;

            case 5:// Bump2Ctr error
                if(Tick_Is_Over(&Bump2Ctr.Terr, 500)) output_toggle(EER_LED2);
                break;

            default:
                Bump2Ctr.State.Pres=(~input(SW22))|((~input(SW21))&Bump2Ctr.State.Prev);
                if(Bump2Ctr.State.Pres) DoNext2=1;
                else DoNext2=2;
                break;
        }// </editor-fold>
    }
}