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

#if(1)
        status=USBDevice_Handle();
#endif
        // If USB error detected
        if(SUCCESS==status)
        {
            // Tests if DTE is set and USB ready for transfer
            if(true==USB_CDCDataTerminalReady())
            {
                // Checks that CDC TX buffer is not full or pipe is busy
                if(false==USB_CDCTxBusy())
                {
                    // Retrieves CDC data if available and writes it back over CDC
                    cdcStatus=USB_CDCRead(&cdcData);

                    if(CDC_SUCCESS==cdcStatus)
                    {
                        i=0;
                        LED_BUSY_SetLow();
                        cdcStatus=USB_CDCWrite(cdcData);
                    }
                }

                // Running CDC Virtual Serial Port handler
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