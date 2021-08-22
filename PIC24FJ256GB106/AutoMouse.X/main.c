#include <xc.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include "pin_manager.h"
#include "clock.h"
#include "system.h"
#include "usb.h"
#include "usb_config.h"
#include "usb_ch9.h"
#include "usb_hid.h"
#include "interrupt_manager.h"
#include "traps.h"
#include "tmr1.h"

#define TICK_PER_SEC    62500 // FOSC/2/256 
#define TICK_PER_MS     62 // FOSC/2/256/1000  
#define Tick_Reset(cxt) cxt.Over=1

typedef struct
{
    bool Over;
    uint16_t Begin;
    uint16_t End;
} tick_t;

#ifdef MULTI_CLASS_DEVICE
static uint8_t hid_interfaces[]={0};
#endif

bool Tick_Is_TimedOut(tick_t *pTick, uint16_t ms) // <editor-fold defaultstate="collapsed" desc="Check timeout">
{
    if(pTick->Over==1)
    {
        pTick->Begin=TMR1_Counter16BitGet();
        pTick->End=ms*TICK_PER_MS;
        pTick->Over=0;
    }

    if((TMR1_Counter16BitGet()-pTick->Begin)>=pTick->End)
        pTick->Over=1;

    return pTick->Over;
} // </editor-fold>

bool BT_UP_Is_Pressed(void) // <editor-fold defaultstate="collapsed" desc="Button UP">
{
    static bool prv=1;
    static uint8_t t=0;

    if(prv!=BUTTON_GetValue())
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

int main(void)
{
    SYSTEM_Initialize();

#ifdef MULTI_CLASS_DEVICE
    hid_set_interface_list(hid_interfaces, sizeof (hid_interfaces));
#endif
    usb_init();

    uint8_t x_count=100;
    uint8_t delay=7;
    int8_t x_direc=1;

    while(1)
    {
        if(usb_is_configured() && !usb_in_endpoint_halted(1) && !usb_in_endpoint_busy(1))
        {
            unsigned char *buf=usb_get_in_buffer(1);
            buf[0]=0x0;
            buf[1]=(--delay)?0:x_direc;
            buf[2]=0;
            usb_send_in_buffer(1, 3);

            if(delay==0)
            {
                if(--x_count==0)
                {
                    x_count=100;
                    x_direc*= -1;
                }
                delay=7;
            }
        }

#ifndef USB_USE_INTERRUPTS
        usb_service();
#endif
    }

    return 1;
}