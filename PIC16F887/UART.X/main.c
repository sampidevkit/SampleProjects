#include <string.h>
#include "libcomp.h"

const uint8_t Infor[]={
    "\n---------------------------------"
    "\nSAMPI DEVELOPMENT KIT"
    "\nUART DEMO CODE"
    "\nCompiler: MPLAB XC8"
    "\nReleased: "
    __DATE__
    "-"
    __TIME__
    "\n---------------------------------\n"
};

const uint8_t Help[]={
    "\n\n[HELP]: Help - All commands are ending by <CR>"
    "\n[GETx]: Get present state of LEDx"
    "\n[SETx]: LEDx set high"
    "\n[CLRx]: LEDx set low"
    "\n[INVx]: LEDx invert\n\n"
};

typedef struct
{
    uint8_t idx;
    const uint8_t *pStr;
} strcmp_t;

#define StrCmp_Init(cxt, src) do{cxt.idx=0; cxt.pStr=(uint8_t*)src;}while(0)

int8_t StrCmp(strcmp_t *pCxt, uint8_t c)
{
    if(c!=pCxt->pStr[pCxt->idx++])
    {
        pCxt->idx=0;
        return (-1); // error
    }

    if(pCxt->pStr[pCxt->idx]==0x00)
    {
        pCxt->idx=0;
        return 1; // matched
    }

    return 0; // to be continued
}

void main(void) // <editor-fold defaultstate="collapsed" desc="Main function">
{
    uint8_t x, DoNext=1, ToDo=255;
    strcmp_t HelpCxt, GetCxt, SetCxt, ClrCxt, InvCxt;

    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    __delay_ms(500);
    StrCmp_Init(HelpCxt, "HELP");
    StrCmp_Init(GetCxt, "GET");
    StrCmp_Init(SetCxt, "SET");
    StrCmp_Init(ClrCxt, "CLR");
    StrCmp_Init(InvCxt, "INV");
    printf(Infor);
    printf(Help);

    while(1)
    {
        uint8_t c;

        CLRWDT();

        if(UART_is_rx_ready())
        {
            c=UART_Read();
            UART_Write(c);

LOOP:
            switch(DoNext)
            {
                default:
                case 255:
                    printf("\nError\n\n");
                    DoNext=1;
                    break;

                case 0:
                    printf("\nOK\n\n");
                    DoNext=1;
                    break;

                case 1:
                    if(StrCmp(&HelpCxt, c)==1) // command HELP
                    {
                        ToDo=4;
                        DoNext=3;
                    }
                    else if(StrCmp(&GetCxt, c)==1) // command GETx
                    {
                        ToDo=5;
                        DoNext=2;
                    }
                    else if(StrCmp(&SetCxt, c)==1) // command SETx
                    {
                        ToDo=6;
                        DoNext=2;
                    }
                    else if(StrCmp(&ClrCxt, c)==1) // command CLRx
                    {
                        ToDo=7;
                        DoNext=2;
                    }
                    else if(StrCmp(&InvCxt, c)==1) // command INVx
                    {
                        ToDo=8;
                        DoNext=2;
                    }
                    else if(c=='\r')
                        DoNext=255;
                    break;

                case 2: // get x value
                    x=c-'0';
                    DoNext=3;
                    break;

                case 3: // get end command '\r'
                    if(c=='\r')
                    {
                        if(x<=7)
                        {
                            DoNext=ToDo;
                            goto LOOP;
                        }
                        else
                            DoNext=255;
                    }
                    else
                        DoNext=255;
                    break;

                case 4:
                    printf(Help);
                    DoNext=0;
                    break;

                case 5: // Command: GETx\r
                    printf("\nLED%d=%d", x, LED_GetValue(x));
                    DoNext=0;
                    break;

                case 6: // Command: SETx\r
                    LED_SetHigh(x);
                    printf("\nLED%d=1", x);
                    DoNext=0;
                    break;

                case 7: // Command: CLRx\r
                    LED_SetLow(x);
                    printf("\nLED%d=0", x);
                    DoNext=0;
                    break;

                case 8: // Command: INVx\r
                    LED_Toggle(x);
                    printf("\nLED%d=%d", x, LED_GetValue(x));
                    DoNext=0;
                    break;
            }

            if((DoNext==0)||(DoNext==255))
                goto LOOP;
        }
    }
} // </editor-fold>