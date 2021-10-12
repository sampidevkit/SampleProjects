#include <main.h>

#define BUTTON          PIN_B0
#define EVENT1_INTERVAL (100*TICK_PER_MS) // 100ms
#define EVENT2_INTERVAL (1000*TICK_PER_MS) // 1000ms

uint8_t Button_Is_Pressed(void)
{
    static tick_t ButtonTick=0;
    uint8_t rslt=0;

    if(input(BUTTON)==0)
    {
        if(ButtonTick==0)
            ButtonTick=get_ticks();

        if((get_ticks()-ButtonTick)>EVENT2_INTERVAL) // event 2
        {
            rslt=2;
            ButtonTick=0;
        }
    }
    else if(ButtonTick>0)
    {
        if((get_ticks()-ButtonTick)>EVENT1_INTERVAL) // event 1
            rslt=1;

        ButtonTick=0;
    }

    return rslt;
}

void main(void)
{
    port_b_pullups(0xFF);

    while(TRUE)
    {
        switch(Button_Is_Pressed())
        {
            default: // Do nothing
                break;

            case 1:
                printf("Event 1\r\n");
                break;

            case 2:
                printf("Event 2\r\n");
                break;
        }
    }
}
