#include <stdio.h>
#include <string.h>
#include <time.h>
#include "mcc_generated_files/mcc.h"

bool BUTTON_IsPressed(void)
{
    static bool prv=1;

    if(prv!=BUTTON_N_GetValue())
    {
        prv=BUTTON_N_GetValue();

        if(prv==0)
            return 1;
    }

    return 0;
}

int main(void)
{

    struct
    {
        uint8_t buf[UART1_CONFIG_RX_BYTEQ_LENGTH];
        int len;
    } CmdBuf;

    uint32_t Counter=0;

    SYSTEM_Initialize();
    CmdBuf.len=0;
    memset(CmdBuf.buf, 0x00, UART1_CONFIG_RX_BYTEQ_LENGTH); // clear buffer
    printf("\r\nPIC24 UART DEMO");
    printf("\r\nRel: %s, %s\r\n", __TIME__, __DATE__);

    while(1)
    {
        Counter++;

        while(UART1_IsRxReady())
        {
            if(CmdBuf.len==(UART1_CONFIG_RX_BYTEQ_LENGTH-1)) // overflow
            {
                CmdBuf.len=0;
                printf("\r\nRX buffer reset");
            }

            CmdBuf.buf[CmdBuf.len]=UART1_Read();

            if(CmdBuf.buf[CmdBuf.len]=='\r')
            {
                printf("\r\nRECEIVE: %s", (char *) CmdBuf.buf);
                CmdBuf.len=0;
                memset(CmdBuf.buf, 0x00, UART1_CONFIG_RX_BYTEQ_LENGTH); // clear buffer
            }
            else
                CmdBuf.len++;
        }

        if(BUTTON_IsPressed())
        {
            uint8_t i, len;
            char Cmd[32];

            sprintf(Cmd, "Counter=%ld\r", Counter);
            printf("\r\nSEND: %s", Cmd);

            for(i=0, len=strlen(Cmd); i<len; i++)
            {
                while(!UART1_IsTxReady());
                UART1_Write(Cmd[i]);
            }
        }
    }

    return 1;
}
