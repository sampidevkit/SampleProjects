#include "system/system.h"

bool I2C_writeNByte(uint8_t slvAddr, uint8_t *pD, uint8_t len) // <editor-fold defaultstate="collapsed" desc="I2C write">
{
    I2C1_Host.Write(slvAddr, pD, len);
    while(I2C1_Host.IsBusy());

    if(I2C1_Host.ErrorGet()==I2C_ERROR_NONE)
    {
        return 1;
    }

    return 0;
} // </editor-fold>

bool I2C_readNByte(uint8_t slvAddr, uint8_t *pD, uint8_t len) // <editor-fold defaultstate="collapsed" desc="I2C read">
{
    I2C1_Host.Read(slvAddr, pD, len);
    while(I2C1_Host.IsBusy());

    if(I2C1_Host.ErrorGet()==I2C_ERROR_NONE)
    {
        return 1;
    }

    return 0;
} // </editor-fold>

void I2CSlaver_Scan(void) // <editor-fold defaultstate="collapsed" desc="I2C scan">
{
    uint8_t i, found;

    printf("\r\nScan I2C slaver: ");

    for(i=1, found=0; i<128; i++)
    {
        CLRWDT();

        if(I2C_readNByte(i, NULL, 0))
        {
            found++;
            printf("%02X ", i);
        }
    }

    printf("\r\nFound total %d device(s)", found);
} // </editor-fold>

static bool AT30TS74_Process(uint8_t SlvAddr, int16_t *pRslt) // <editor-fold defaultstate="collapsed" desc="AT30TS74 process">
{
#define AT30TS74_TEMPER_REG 0x00 // Temperature Register
#define AT30TS74_CONFIG_REG 0x01 // Configuration Register
#define AT30TS74_TLOW_REG   0x02 // TLOW Limit Register
#define AT30TS74_THIGH_REG  0x03 // THIGH Limit Register

    static uint8_t DoNext1=0, DoNext2=0;
    float tmp;
    uint8_t *DoNext, Buff[16];
    uint16_t rslt;

    if(SlvAddr==0x4B)
        DoNext=&DoNext1;
    else if(SlvAddr==0x4F)
        DoNext=&DoNext2;

    switch(*DoNext)
    {
        case 0: // Shutdown
            Buff[0]=AT30TS74_CONFIG_REG;
            Buff[1]=0x01;
            Buff[2]=0x00;

            if(I2C_writeNByte(SlvAddr, Buff, 3)==0)
            {
                printf("\nAT30TS74: %02X not found\n", SlvAddr);
                break;
            }

            *DoNext=*DoNext+1;
            break;

        case 1: // Configure
            Buff[0]=AT30TS74_CONFIG_REG;
            Buff[1]=0xFE;
            Buff[2]=0x00;

            if(I2C_writeNByte(SlvAddr, Buff, 3)==0)
            {
                *DoNext=0;
                break;
            }

            *DoNext=*DoNext+1;
            break;

        case 2:
            Buff[0]=AT30TS74_CONFIG_REG;
            Buff[1]=0x02;
            Buff[2]=0x00;

            if(I2C_writeNByte(SlvAddr, Buff, 3)==0)
            {
                *DoNext=0;
                break;
            }

            *DoNext=*DoNext+1;
            printf("\nAT30TS74: %02X initialized\n", SlvAddr);
            break;

        case 3:
            Buff[0]=AT30TS74_TEMPER_REG;

            if(I2C_writeNByte(SlvAddr, Buff, 1)==0)
            {
                *DoNext=0;
                break;
            }

            if(I2C_readNByte(SlvAddr, Buff, 2)==0)
            {
                *DoNext=0;
                break;
            }

            rslt=Buff[0];
            rslt<<=8;
            rslt|=Buff[1];

            if(rslt&0x8000)
            {
                rslt>>=7;
                tmp=rslt;
                tmp-=512;
            }
            else
            {
                rslt>>=7;
                tmp=rslt;
            }

            tmp*=0.5f;
            *pRslt=(int16_t)tmp;
            return 1;

        default:
            break;
    }

    return 0;
} // </editor-fold>

int main(void)
{
    SYSTEM_Initialize();

    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    __delay_ms(500);
    VSEN_EN_SetHigh();
    printf("\r\nAT30TS74 I2C THERMAL SENSOR\r\n");

    I2CSlaver_Scan();

    while(1)
    {
        int16_t t1, t2;
        uint8_t i, DvBuff[8];

        CLRWDT();
        LED_Toggle();
        AT30TS74_Process(0x4B, &t1);
        AT30TS74_Process(0x4F, &t2);

#if(1)
        // Header
        DvBuff[0]=0x03;
        // Temp1
        DvBuff[1]=(uint8_t)t1;
        // Temp2
        DvBuff[2]=(uint8_t)t2;
        // Footer
        DvBuff[3]=0xFC;

        for(i=0; i<4; i++)
        {
            EUSART1_Write(DvBuff[i]);
            while(!EUSART1_IsTxDone());
        }
#else
        printf("\r\nT1=%d, T2=%d", t1, t2);
#endif
        __delay_ms(100);
    }

    return 0;
}
