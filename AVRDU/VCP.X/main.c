#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/usb/usb_cdc/usb_cdc.h"
#include "mcc_generated_files/usb/usb_cdc/usb_cdc_virtual_serial_port.h"

#include <avr/wdt.h>
#include <avr/sleep.h>
#include <util/delay.h>
#include <avr/pgmspace.h>

#define ClrWdt() wdt_reset()
#define SoftReset() RSTCTRL_SoftwareReset()

int main(void)
{
    int i=0;
    // USB status variables
    uint8_t cdcData;
    volatile RETURN_CODE_t status=SUCCESS;
    volatile CDC_RETURN_CODE_t cdcStatus=CDC_SUCCESS;

    SYSTEM_Initialize();
    USB_Start();
    LED_BUSY_SetHigh();

    while(1)
    {
        ClrWdt();
        status=USBDevice_Handle();

        if(SUCCESS==status)
        {
            if(true==USB_CDCDataTerminalReady())
            {
                if(USB_CDCRxReady())
                {
                    USB_CDCRead(&cdcData);

                    if(false==USB_CDCTxBusy())
                    {
                        i=0;
                        LED_BUSY_SetLow();
                        USB_CDCWrite(cdcData);
                    }
                }

                status=USB_CDCVirtualSerialPortHandler();

                if(i<2000)
                    i++;
                else
                    LED_BUSY_SetHigh();
            }
            else
            {
                if(++i>=10000)
                {
                    i=0;
                    LED_BUSY_Toggle();
                }
            }
        }
    }
}