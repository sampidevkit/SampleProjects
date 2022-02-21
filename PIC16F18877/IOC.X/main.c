#include "mcc_generated_files/mcc.h"

static volatile bool Update=0;
static volatile uint16_t Count=0;
static volatile uint8_t TmrInit=0;

static void TMR_IsrCb(void)
{
    TMR2=0;
    NOP();
    NOP();
    NOP();
    NOP();
    Count+=256;
    Count-=TmrInit;
    Update=1;
    TmrInit=TMR2;
}

static bool Button_is_pressed(void)
{
    static bool latch=1;

    if(latch!=UBT_N_GetValue())
    {
        latch=UBT_N_GetValue();
        return (!latch);
    }

    return 0;
}

void main(void)
{
    uint8_t DoNext=0;
    uint16_t Tick=0;
    uint32_t Pulse=0;

    SYSTEM_Initialize();
    Count=0;
    Update=0;
    TMR2=0;
    TMR2_SetInterruptHandler(TMR_IsrCb);
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    TmrInit=TMR2;

    while(1)
    {
        if(Update==1)
        {
            Update=0;
            printf("\n\nISR: ");
            printf("C=%d, ", Count);
            printf("I=%d", TmrInit);
            continue;
        }

        if(Button_is_pressed())
        {
            if(DoNext==0)
            {
                DoNext=1;
                Pulse=0;
                Count=0;
                printf("\nStart\n");
            }
            else
            {
                DoNext=0;
                printf("\nStop\n");
            }
        }

        switch(DoNext)
        {
            case 1:
                if(++Tick>=1000)
                {
                    PULSE_SetLow();
                    DoNext=2;
                    Pulse++;
                    printf("\n\nLOOP: P=%ld, ", Pulse);
                }
                break;

            case 2:
                PULSE_SetHigh();
                DoNext=1;
                Tick=0;
                Count+=TMR2;
                Count-=TmrInit;
                TMR2=0;
                NOP();
                NOP();
                NOP();
                NOP();
                TmrInit=TMR2;
                printf("C=%d, ", Count);
                printf("I=%d", TmrInit);
                break;

            default:
                break;
        }

        __delay_ms(1);
    }
}