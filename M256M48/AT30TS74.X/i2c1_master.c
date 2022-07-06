#include "libcomp.h"
#include "i2c1_master.h"

#ifdef __db
#undef __db
#endif

#define __db(...)

static uint8_t i2c1_timeout=255;

#define I2C1_MasterOpen()               I2C1CONbits.ON=1
#define I2C1_MasterClose()              I2C1CONbits.ON=0

#define I2C1_MasterEnableIrq()          IEC2SET=0x00; // IEC2bits.I2C1MIE=IEC2bits.I2C1SIE=IEC2bits.I2C1BCIE=0;
#define I2C1_MasterDisableIrq()         IEC2CLR=0x00; // IEC2bits.I2C1MIE=IEC2bits.I2C1SIE=IEC2bits.I2C1BCIE=0;
#define I2C1_MasterSetIrq()             PIR3bits.I2C1IF=1
#define I2C1_MasterClearIrq()           PIR3bits.I2C1IF=0
#define I2C1_MasterIsIrqEnabled()       PIE3bits.I2C1IE
#define I2C1_MasterWaitForEvent()       if(i2c1_timeout>0){i2c1_timeout=255; while((PIR3bits.I2C1IF==0)&&(--i2c1_timeout>0)) __delay_us(5);}

#define I2C1_MasterIsRxBufFull()        I2C1STATbits.BF
#define I2C1_MasterClearBusCollision()  PIR3bits.BCL2IF=0
#define I2C1_MasterSendNack()           do{I2C1CON2bits.ACKDT=1; I2C1CON2bits.ACKEN=1;}while(0)
#define I2C1_MasterSendAck()            do{I2C1CON2bits.ACKDT=0; I2C1CON2bits.ACKEN=1;}while(0)
#define I2C1_MasterIsNack()             I2C1CON2bits.ACKSTAT
#define I2C1_MasterStop()               I2C1CON2bits.PEN=1
#define I2C1_MasterStart()              I2C1CON2bits.SEN=1
#define I2C1_MasterStartRx()            I2C1CON2bits.RCEN=1
#define I2C1_MasterDisableRestart()     I2C1CON2bits.RSEN=0
#define I2C1_MasterEnableRestart()      I2C1CON2bits.RSEN=1
#define I2C1_MasterSendTxData(data)     I2C1BUF=data
#define I2C1_MasterGetRxData()          I2C1BUF

void I2C1_Master_Init(uint32_t clock)
{
    int32_t tmp;

    __db("\n%s: ", __FUNCTION__);

    I2C1CON1=0x08; // disable I2C, Master mode, clock=FOSC / (4 * (SSPxADD+1))
    I2C1CON2=0x00;
    I2C1STAT=0x00;

    tmp=(_XTAL_FREQ>>2);
    tmp/=(int32_t) clock;
    tmp--;

    if(tmp>255)
        tmp=255;
    else if(tmp<0)
        tmp=0;

    I2C1ADD=(uint8_t) tmp;
    i2c1_timeout=255;

    __db("I2C1ADD=%02X\n", I2C1ADD);
}

void I2C1_Master_Deinit(void)
{
    i2c1_timeout=0;
    I2C1CONbits.ON=0; // disable I2C
}

int8_t I2C1_Master_Scan(void (*pStreamFnc)(uint8_t))
{
    int8_t found;
    uint8_t slvAddr;

    if(pStreamFnc==NULL)
        return -1; // error

    for(slvAddr=0, found=0; slvAddr<127; slvAddr++)
    {
        bool rslt=0;

        i2c1_timeout=255;
        // clear event
        I2C1_MasterClearBusCollision();
        I2C1_MasterClearIrq();
        // enable I2C
        I2C1_MasterOpen();
        // send start bit
        I2C1_MasterStart();
        // wait for event
        I2C1_MasterWaitForEvent();
        // clear event
        I2C1_MasterClearIrq();
        // send slave address
        I2C1_MasterSendTxData((uint8_t) ((slvAddr<<1)|1));
        // wait for event
        I2C1_MasterWaitForEvent();
        // clear event
        I2C1_MasterClearIrq();
        // get ACK
        rslt|=I2C1_MasterIsNack();
        // enable receive
        I2C1_MasterStartRx();
        // get last data
        uint8_t dummy=I2C1_MasterGetRxData();
        // wait for event
        I2C1_MasterWaitForEvent();
        // clear event
        I2C1_MasterClearIrq();
        // send NACK
        I2C1_MasterSendNack();
        // wait for event
        I2C1_MasterWaitForEvent();
        // clear event
        I2C1_MasterClearIrq();
        // send stop bit
        I2C1_MasterStop();
        // wait for event
        I2C1_MasterWaitForEvent();
        // clear event
        I2C1_MasterClearIrq();
        // disable I2C
        I2C1_MasterClose();

        if((i2c1_timeout>0)&&(!rslt))
        {
            found++;
            pStreamFnc(slvAddr);
        }
    }

    return found;
}

bool I2C1_Master_ReadNByte(uint8_t slvAddr, uint8_t *pD, uint8_t len)
{
    bool rslt=0;

    i2c1_timeout=255;
    // clear event
    I2C1_MasterClearBusCollision();
    I2C1_MasterClearIrq();
    // enable I2C
    I2C1_MasterOpen();
    // send start bit
    I2C1_MasterStart();
    // wait for event
    I2C1_MasterWaitForEvent();
    // clear event
    I2C1_MasterClearIrq();
    // send slave address
    I2C1_MasterSendTxData((uint8_t) ((slvAddr<<1)|1));
    // wait for event
    I2C1_MasterWaitForEvent();
    // clear event
    I2C1_MasterClearIrq();
    // get ACK
    rslt|=I2C1_MasterIsNack();
    // get N-1 byte data
    while(len>1)
    {
        // enable receive
        I2C1_MasterStartRx();
        len--;
        // get data
        *pD=I2C1_MasterGetRxData();
        pD++;
        // wait for event
        I2C1_MasterWaitForEvent();
        // clear event
        I2C1_MasterClearIrq();
        // send ACK
        I2C1_MasterSendAck();
        // wait for event
        I2C1_MasterWaitForEvent();
        // clear event
        I2C1_MasterClearIrq();
    }
    // enable receive
    I2C1_MasterStartRx();
    // get last data
    *pD=I2C1_MasterGetRxData();
    // wait for event
    I2C1_MasterWaitForEvent();
    // clear event
    I2C1_MasterClearIrq();
    // send NACK
    I2C1_MasterSendNack();
    // wait for event
    I2C1_MasterWaitForEvent();
    // clear event
    I2C1_MasterClearIrq();
    // send stop bit
    I2C1_MasterStop();
    // wait for event
    I2C1_MasterWaitForEvent();
    // clear event
    I2C1_MasterClearIrq();
    // disable I2C
    I2C1_MasterClose();

    if(i2c1_timeout>0)
        return !rslt;

    return 0;
}

bool I2C1_Master_WriteNByte(uint8_t slvAddr, const uint8_t *pD, uint8_t len)
{
    bool rslt=0;

    i2c1_timeout=255;
    // clear event
    I2C1_MasterClearBusCollision();
    I2C1_MasterClearIrq();
    // enable I2C
    I2C1_MasterOpen();
    // send start bit
    I2C1_MasterStart();
    // wait for event
    I2C1_MasterWaitForEvent();
    // clear event
    I2C1_MasterClearIrq();
    // send slave address
    I2C1_MasterSendTxData((uint8_t) (slvAddr<<1));
    // write N byte data
    while(len>0)
    {
        // wait for event
        I2C1_MasterWaitForEvent();
        // clear event
        I2C1_MasterClearIrq();
        // get ACK
        rslt|=I2C1_MasterIsNack();
        len--;
        // send data
        I2C1_MasterSendTxData(*pD++);
    }
    // wait for event
    I2C1_MasterWaitForEvent();
    // clear event
    I2C1_MasterClearIrq();
    // get ACK
    rslt|=I2C1_MasterIsNack();
    // send stop bit
    I2C1_MasterStop();
    // wait for event
    I2C1_MasterWaitForEvent();
    // clear event
    I2C1_MasterClearIrq();
    // disable I2C
    I2C1_MasterClose();

    if(i2c1_timeout>0)
        return !rslt;

    return 0;
}