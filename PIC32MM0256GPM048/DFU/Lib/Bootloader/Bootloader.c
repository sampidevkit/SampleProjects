#include "libcomp.h"
#include "Bootloader.h"

enum
{
    BLD_TRIGGER=0,
    BLD_COMM_INIT=1,
    BLD_INFO=2,
    BLD_COMM_READ=3,
    BLD_DATA_PROCESS=4,
    BLD_RSLT_SUCCESS=5,
    BLD_RSLT_ERROR=6,
    BLD_COMM_WRITE=7,
    BLD_DONE
};

private const uint8_t BldInfo[]={
    "\n" __PROJECT_NAME__ "\n"
    "HwID: " __HARDWARE_ID__ "\n"
    "MCU: " __BLD_NVM_TARGET_DEVICE_NAME__ "\n"
    "Rel: " __DATE__ "-" __TIME__
    "\n" __WEBSITE__ "\n"
};

private bool Wdt_Reset;
private uint8_t DoNext;
private uint8_t *pBuffer;
private uint8_t i, BufferLen;
private uint8_t Buffer[BLD_BUFFER_SIZE];

extern void appFunction(void);

#ifdef USE_BOOTLOADER_BUILTIN_EXCEPTION

void _general_exception_handler(void) // <editor-fold defaultstate="collapsed" desc="Exception handler">
{
    // Do nothing
    while(1);
} // </editor-fold>
#endif

private void Jump2App(void) // <editor-fold defaultstate="collapsed" desc="Jump to application">
{
    uint32_t *AppPtr;

    AppPtr=(uint32_t *) APP_RESET_ADDRESS;

    if(*AppPtr!=0xFFFFFFFF)
    {
#ifndef BLD_DISABLE_CODE_PROTECT
        if(FSECbits.CP==0) // Code protection bit must be enabled
#endif
            appFunction();
    }
} // </editor-fold>

public void BootLoader_Tasks(void) // <editor-fold defaultstate="collapsed" desc="Boot loader task">
{
    if(!Wdt_Reset)
        WATCHDOG_TimerClear();

    switch(DoNext)
    {
        case BLD_TRIGGER: // Check boot load trigger and Appzone
            if((BLD_Trigger_GetState()==0))
                DoNext=BLD_COMM_INIT;
            else
            {
                Jump2App(); // Jump out this function if no application
                DoNext=BLD_COMM_INIT;
            }
            break;

        case BLD_COMM_INIT: // Communication initialize
            BLD_Comm_Init();
            DoNext=BLD_INFO;
            pBuffer=(uint8_t *) BldInfo;

        case BLD_INFO:
            while(*pBuffer!=0x00)
            {
                if(BLD_IsTxReady())
                    BLD_Write(*pBuffer++);
                else
                    return;
            }

            BufferLen=0;
            DoNext=BLD_COMM_READ;

        case BLD_COMM_READ:
            while(BLD_IsRxReady())
            {
                Buffer[BufferLen]=BLD_Read();

                if(Buffer[BufferLen]=='\n')
                {
                    if(BufferLen<BLD_BUFFER_SIZE)
                        DoNext=BLD_DATA_PROCESS;
                    else
                        DoNext=BLD_RSLT_ERROR;
                }
                else if(BufferLen<BLD_BUFFER_SIZE)
                    BufferLen++;
            }
            break;

        case BLD_DATA_PROCESS: // Process data
            for(i=0; i<BufferLen; i++)
            {
                int8_t rslt;

                rslt=HEXPARSE_Tasks(Buffer[i]);

                if(rslt==PROC_DONE)
                {
                    DoNext=BLD_RSLT_SUCCESS;
                    break;
                }
                else if(rslt==PROC_ERR)
                {
                    DoNext=BLD_RSLT_ERROR;
                    break;
                }
            }

            DoNext=BLD_RSLT_SUCCESS;
            break;

        case BLD_RSLT_SUCCESS: // Success
            Buffer[0]='A';
            Buffer[1]=0;
            BufferLen=0;
            DoNext=BLD_COMM_WRITE;
            break;

        case BLD_RSLT_ERROR: // Error
            Buffer[0]='N';
            Buffer[1]=0;
            BufferLen=0;
            DoNext=BLD_COMM_WRITE;
            break;

        case BLD_COMM_WRITE:
        default: // Send response
            while(Buffer[BufferLen]!=0x00)
            {
                if(BLD_IsTxReady())
                    BLD_Write(Buffer[BufferLen++]);
                else
                    return;
            }

            DoNext=BLD_COMM_READ;
            BufferLen=0;
            break;
    }
} // </editor-fold>

public void BootLoader_Initialize(void) // <editor-fold defaultstate="collapsed" desc="Boot loader initialize">
{
    Wdt_Reset=0;
    DoNext=BLD_TRIGGER;
    BLD_Trigger_Init();
    Enable_Peripheral_Interrupt();
    Enable_Global_Interrupt();
} // </editor-fold>

public void BootLoader_Deinitialize(void) // <editor-fold defaultstate="collapsed" desc="Bootloader deinitialize">
{
    WATCHDOG_TimerClear();
    Wdt_Reset=1;
} // </editor-fold>