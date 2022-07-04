#include "libcomp.h"
#include "mssp1_i2c_master.h"

#ifdef __db
#undef __db
#endif

#define __db(...)

static uint8_t mssp1_i2c_timeout=255;

#define MSSP1_I2C_MasterOpen()               SSP1CON1bits.SSPEN=1
#define MSSP1_I2C_MasterClose()              SSP1CON1bits.SSPEN=0

#define MSSP1_I2C_MasterEnableIrq()          PIE3bits.SSP1IE=1
#define MSSP1_I2C_MasterDisableIrq()         PIE3bits.SSP1IE=0
#define MSSP1_I2C_MasterSetIrq()             PIR3bits.SSP1IF=1
#define MSSP1_I2C_MasterClearIrq()           PIR3bits.SSP1IF=0
#define MSSP1_I2C_MasterIsIrqEnabled()       PIE3bits.SSP1IE
#define MSSP1_I2C_MasterWaitForEvent()       if(mssp1_i2c_timeout>0){mssp1_i2c_timeout=255; while((PIR3bits.SSP1IF==0)&&(--mssp1_i2c_timeout>0)) __delay_us(5);}

#define MSSP1_I2C_MasterIsRxBufFull()        SSP1STATbits.BF
#define MSSP1_I2C_MasterClearBusCollision()  PIR3bits.BCL2IF=0
#define MSSP1_I2C_MasterSendNack()           do{SSP1CON2bits.ACKDT=1; SSP1CON2bits.ACKEN=1;}while(0)
#define MSSP1_I2C_MasterSendAck()            do{SSP1CON2bits.ACKDT=0; SSP1CON2bits.ACKEN=1;}while(0)
#define MSSP1_I2C_MasterIsNack()             SSP1CON2bits.ACKSTAT
#define MSSP1_I2C_MasterStop()               SSP1CON2bits.PEN=1
#define MSSP1_I2C_MasterStart()              SSP1CON2bits.SEN=1
#define MSSP1_I2C_MasterStartRx()            SSP1CON2bits.RCEN=1
#define MSSP1_I2C_MasterDisableRestart()     SSP1CON2bits.RSEN=0
#define MSSP1_I2C_MasterEnableRestart()      SSP1CON2bits.RSEN=1
#define MSSP1_I2C_MasterSendTxData(data)     SSP1BUF=data
#define MSSP1_I2C_MasterGetRxData()          SSP1BUF

void MSSP1_I2C_Master_Init(uint32_t clock)
{
    int32_t tmp;

    __db("\n%s: ", __FUNCTION__);

    PMD4bits.MSSP1MD=0; // enable MSSP module
    SSP1CON1=0x08; // disable I2C, Master mode, clock=FOSC / (4 * (SSPxADD+1))
    SSP1CON2=0x00;
    SSP1STAT=0x00;

    tmp=(_XTAL_FREQ>>2);
    tmp/=(int32_t) clock;
    tmp--;

    if(tmp>255)
        tmp=255;
    else if(tmp<0)
        tmp=0;

    SSP1ADD=(uint8_t) tmp;
    mssp1_i2c_timeout=255;

    __db("SSP1ADD=%02X\n", SSP1ADD);
}

void MSSP1_I2C_Master_Deinit(void)
{
    mssp1_i2c_timeout=0;
    SSP1CON1bits.SSPEN=0; // disable I2C
    PMD4bits.MSSP1MD=1; // disable MSSP module
}

int8_t MSSP1_I2C_Master_Scan(void (*pStreamFnc)(uint8_t))
{
    int8_t found;
    uint8_t slvAddr;

    if(pStreamFnc==NULL)
        return -1; // error

    for(slvAddr=0, found=0; slvAddr<127; slvAddr++)
    {
        bool rslt=0;

        mssp1_i2c_timeout=255;
        // clear event
        MSSP1_I2C_MasterClearBusCollision();
        MSSP1_I2C_MasterClearIrq();
        // enable I2C
        MSSP1_I2C_MasterOpen();
        // send start bit
        MSSP1_I2C_MasterStart();
        // wait for event
        MSSP1_I2C_MasterWaitForEvent();
        // clear event
        MSSP1_I2C_MasterClearIrq();
        // send slave address
        MSSP1_I2C_MasterSendTxData((uint8_t) ((slvAddr<<1)|1));
        // wait for event
        MSSP1_I2C_MasterWaitForEvent();
        // clear event
        MSSP1_I2C_MasterClearIrq();
        // get ACK
        rslt|=MSSP1_I2C_MasterIsNack();
        // enable receive
        MSSP1_I2C_MasterStartRx();
        // get last data
        uint8_t dummy=MSSP1_I2C_MasterGetRxData();
        // wait for event
        MSSP1_I2C_MasterWaitForEvent();
        // clear event
        MSSP1_I2C_MasterClearIrq();
        // send NACK
        MSSP1_I2C_MasterSendNack();
        // wait for event
        MSSP1_I2C_MasterWaitForEvent();
        // clear event
        MSSP1_I2C_MasterClearIrq();
        // send stop bit
        MSSP1_I2C_MasterStop();
        // wait for event
        MSSP1_I2C_MasterWaitForEvent();
        // clear event
        MSSP1_I2C_MasterClearIrq();
        // disable I2C
        MSSP1_I2C_MasterClose();

        if((mssp1_i2c_timeout>0)&&(!rslt))
        {
            found++;
            pStreamFnc(slvAddr);
        }
    }

    return found;
}

bool MSSP1_I2C_Master_ReadNByte(uint8_t slvAddr, uint8_t *pD, uint8_t len)
{
    bool rslt=0;

    mssp1_i2c_timeout=255;
    // clear event
    MSSP1_I2C_MasterClearBusCollision();
    MSSP1_I2C_MasterClearIrq();
    // enable I2C
    MSSP1_I2C_MasterOpen();
    // send start bit
    MSSP1_I2C_MasterStart();
    // wait for event
    MSSP1_I2C_MasterWaitForEvent();
    // clear event
    MSSP1_I2C_MasterClearIrq();
    // send slave address
    MSSP1_I2C_MasterSendTxData((uint8_t) ((slvAddr<<1)|1));
    // wait for event
    MSSP1_I2C_MasterWaitForEvent();
    // clear event
    MSSP1_I2C_MasterClearIrq();
    // get ACK
    rslt|=MSSP1_I2C_MasterIsNack();
    // get N-1 byte data
    while(len>1)
    {
        // enable receive
        MSSP1_I2C_MasterStartRx();
        len--;
        // get data
        *pD=MSSP1_I2C_MasterGetRxData();
        pD++;
        // wait for event
        MSSP1_I2C_MasterWaitForEvent();
        // clear event
        MSSP1_I2C_MasterClearIrq();
        // send ACK
        MSSP1_I2C_MasterSendAck();
        // wait for event
        MSSP1_I2C_MasterWaitForEvent();
        // clear event
        MSSP1_I2C_MasterClearIrq();
    }
    // enable receive
    MSSP1_I2C_MasterStartRx();
    // get last data
    *pD=MSSP1_I2C_MasterGetRxData();
    // wait for event
    MSSP1_I2C_MasterWaitForEvent();
    // clear event
    MSSP1_I2C_MasterClearIrq();
    // send NACK
    MSSP1_I2C_MasterSendNack();
    // wait for event
    MSSP1_I2C_MasterWaitForEvent();
    // clear event
    MSSP1_I2C_MasterClearIrq();
    // send stop bit
    MSSP1_I2C_MasterStop();
    // wait for event
    MSSP1_I2C_MasterWaitForEvent();
    // clear event
    MSSP1_I2C_MasterClearIrq();
    // disable I2C
    MSSP1_I2C_MasterClose();

    if(mssp1_i2c_timeout>0)
        return !rslt;

    return 0;
}

bool MSSP1_I2C_Master_WriteNByte(uint8_t slvAddr, const uint8_t *pD, uint8_t len)
{
    bool rslt=0;

    mssp1_i2c_timeout=255;
    // clear event
    MSSP1_I2C_MasterClearBusCollision();
    MSSP1_I2C_MasterClearIrq();
    // enable I2C
    MSSP1_I2C_MasterOpen();
    // send start bit
    MSSP1_I2C_MasterStart();
    // wait for event
    MSSP1_I2C_MasterWaitForEvent();
    // clear event
    MSSP1_I2C_MasterClearIrq();
    // send slave address
    MSSP1_I2C_MasterSendTxData((uint8_t) (slvAddr<<1));
    // write N byte data
    while(len>0)
    {
        // wait for event
        MSSP1_I2C_MasterWaitForEvent();
        // clear event
        MSSP1_I2C_MasterClearIrq();
        // get ACK
        rslt|=MSSP1_I2C_MasterIsNack();
        len--;
        // send data
        MSSP1_I2C_MasterSendTxData(*pD++);
    }
    // wait for event
    MSSP1_I2C_MasterWaitForEvent();
    // clear event
    MSSP1_I2C_MasterClearIrq();
    // get ACK
    rslt|=MSSP1_I2C_MasterIsNack();
    // send stop bit
    MSSP1_I2C_MasterStop();
    // wait for event
    MSSP1_I2C_MasterWaitForEvent();
    // clear event
    MSSP1_I2C_MasterClearIrq();
    // disable I2C
    MSSP1_I2C_MasterClose();

    if(mssp1_i2c_timeout>0)
        return !rslt;

    return 0;
}