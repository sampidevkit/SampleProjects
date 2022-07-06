#include "libcomp.h"

static uint8_t txBuf[CDC_DATA_OUT_EP_SIZE]={0x00};
static uint8_t txLen=0;
static uint8_t rxBuf[CDC_DATA_IN_EP_SIZE];
static uint8_t rxLen=0;

bool Tick_Is_Over(tick_t *pTick, uint32_t ms) // <editor-fold defaultstate="collapsed" desc="Check timeout">
{
    if(pTick->Over==1)
    {
        pTick->Begin=_CP0_GET_COUNT();
        pTick->End=ms*TICK_PER_MS;
        pTick->Over=0;
    }

    if((_CP0_GET_COUNT()-pTick->Begin)>=pTick->End)
        pTick->Over=1;

    return pTick->Over;
} // </editor-fold>

bool BUTTON_Is_Pressed(void) // <editor-fold defaultstate="collapsed" desc="Button UP">
{
    static bool prv=1;
    static tick_t tk={1, 0, 0};

    if(prv!=BUTTON_GetValue())
    {
        if(prv==1)
        {
            if(Tick_Is_Over(&tk, 100)) // check in 100ms
            {
                prv=0;
                return 1;
            }
        }
        else
            prv=1;
    }
    else if(tk.Over==0)
        tk.Over=1;

    return 0;
} // </editor-fold>

void USB_Rx_Tasks(void) // <editor-fold defaultstate="collapsed" desc="USB CDC Rx tasks">
{
    if(USBGetDeviceState()<CONFIGURED_STATE)
        return;

    if(USBIsDeviceSuspended()==true)
        return;

    if(USBUSARTIsTxTrfReady()==true)
    {
        rxLen=getsUSBUSART(rxBuf, CDC_DATA_IN_EP_SIZE);

        if(rxLen>0)
            putUSBUSART(rxBuf, rxLen);
    }
} // </editor-fold>

void USB_Tx_Tasks(void) // <editor-fold defaultstate="collapsed" desc="USB CDC Tx tasks">
{
    if(txLen>0)
    {
        putUSBUSART(txBuf, txLen);
        txLen=0;
    }

    CDCTxService();
} // </editor-fold>

void _mon_putc(char c) // <editor-fold defaultstate="collapsed" desc="SDTIO stream function">
{
    if(USBGetDeviceState()<CONFIGURED_STATE)
        return;

    if(USBIsDeviceSuspended()==true)
        return;

    txBuf[txLen++]=c;

    if(txLen>=CDC_DATA_IN_EP_SIZE)
    {
        txLen=0;
        putUSBUSART(txBuf, CDC_DATA_IN_EP_SIZE);
    }

    CDCTxService();
} // </editor-fold>
