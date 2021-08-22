#include "libcomp.h"

void Task1(void)
{
    static soft_event_t ThisEvent={NULL, NULL, NULL};
    static uint8_t DoNext=0;

    if(ThisEvent.Fnc!=NULL)
        return;

    switch(DoNext)
    {
        case 0:
            DoNext++;
            printf("\n1");
            ThisEvent.Fnc=(soft_event_fnc_t) Task1;
            ThisEvent.Args=NULL;
            SoftEvent_Add(&ThisEvent);
            break;

        case 2:
            DoNext++;
            printf("\n2");
            break;
    }

}

void main(void)
{
    SYSTEM_Initialize();
    SoftEvent_Init();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();

    while(1)
    {
        if(SoftEvent()==0)
        {
            printf("\nSleep");
            Sleep();
        }
    }
}