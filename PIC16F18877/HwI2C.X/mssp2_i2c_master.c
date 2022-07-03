#include "libcomp.h"
#include "mssp2_i2c_master.h"

#ifdef __db
#undef __db
#endif

#define __db(...)

static uint8_t mssp2_i2c_timeout=255;

#define MSSP2_I2C_MasterOpen()               SSP2CON1bits.SSPEN=1
#define MSSP2_I2C_MasterClose()              SSP2CON1bits.SSPEN=0

#define MSSP2_I2C_MasterEnableIrq()          PIE3bits.SSP2IE=1
#define MSSP2_I2C_MasterDisableIrq()         PIE3bits.SSP2IE=0
#define MSSP2_I2C_MasterSetIrq()             PIR3bits.SSP2IF=1
#define MSSP2_I2C_MasterClearIrq()           PIR3bits.SSP2IF=0
#define MSSP2_I2C_MasterIsIrqEnabled()       PIE3bits.SSP2IE
#define MSSP2_I2C_MasterWaitForEvent()       if(mssp2_i2c_timeout>0){mssp2_i2c_timeout=255; while((PIR3bits.SSP2IF==0)&&(--mssp2_i2c_timeout>0)) __delay_us(5);}

#define MSSP2_I2C_MasterIsRxBufFull()        SSP2STATbits.BF
#define MSSP2_I2C_MasterClearBusCollision()  PIR3bits.BCL2IF=0
#define MSSP2_I2C_MasterSendNack()           do{SSP2CON2bits.ACKDT=1; SSP2CON2bits.ACKEN=1;}while(0)
#define MSSP2_I2C_MasterSendAck()            do{SSP2CON2bits.ACKDT=0; SSP2CON2bits.ACKEN=1;}while(0)
#define MSSP2_I2C_MasterIsNack()             SSP2CON2bits.ACKSTAT
#define MSSP2_I2C_MasterStop()               SSP2CON2bits.PEN=1
#define MSSP2_I2C_MasterStart()              SSP2CON2bits.SEN=1
#define MSSP2_I2C_MasterStartRx()            SSP2CON2bits.RCEN=1
#define MSSP2_I2C_MasterDisableRestart()     SSP2CON2bits.RSEN=0
#define MSSP2_I2C_MasterEnableRestart()      SSP2CON2bits.RSEN=1
#define MSSP2_I2C_MasterSendTxData(data)     SSP2BUF=data
#define MSSP2_I2C_MasterGetRxData()          SSP2BUF

void MSSP2_I2C_Master_Init(uint32_t clock)
{
    int32_t tmp;

    __db("\n%s: ", __FUNCTION__);

    PMD4bits.MSSP2MD=0; // enable MSSP module
    SSP2CON1=0x08; // disable I2C, Master mode, clock=FOSC / (4 * (SSPxADD+1))
    SSP2CON2=0x00;
    SSP2STAT=0x00;

    tmp=(_XTAL_FREQ>>2);
    tmp/=(int32_t) clock;
    tmp--;

    if(tmp>255)
        tmp=255;
    else if(tmp<0)
        tmp=0;

    SSP2ADD=(uint8_t) tmp;
    mssp2_i2c_timeout=255;

    __db("SSP2ADD=%02X\n", SSP2ADD);
}

void MSSP2_I2C_Master_Deinit(void)
{
    mssp2_i2c_timeout=0;
    SSP2CON1bits.SSPEN=0; // disable I2C
    PMD4bits.MSSP2MD=1; // disable MSSP module
}

bool MSSP2_I2C_Master_ReadNByte(uint8_t slvAddr, uint8_t *pD, uint8_t len)
{
    bool rslt=0;
    
    mssp2_i2c_timeout=255;
    // clear event
    MSSP2_I2C_MasterClearBusCollision();
    MSSP2_I2C_MasterClearIrq();
    // enable I2C
    MSSP2_I2C_MasterOpen();
    // send start bit
    MSSP2_I2C_MasterStart();
    // wait for event
    MSSP2_I2C_MasterWaitForEvent();
    // clear event
    MSSP2_I2C_MasterClearIrq();
    // send slave address
    MSSP2_I2C_MasterSendTxData((uint8_t) ((slvAddr<<1)|1));
    // wait for event
    MSSP2_I2C_MasterWaitForEvent();
    // clear event
    MSSP2_I2C_MasterClearIrq();
    // get ACK
    rslt|=MSSP2_I2C_MasterIsNack();
    // get N-1 byte data
    while(len>1)
    {
        // enable receive
        MSSP2_I2C_MasterStartRx();
        len--;
        // get data
        *pD=MSSP2_I2C_MasterGetRxData();
        pD++;
        // wait for event
        MSSP2_I2C_MasterWaitForEvent();
        // clear event
        MSSP2_I2C_MasterClearIrq();
        // send ACK
        MSSP2_I2C_MasterSendAck();
        // wait for event
        MSSP2_I2C_MasterWaitForEvent();
        // clear event
        MSSP2_I2C_MasterClearIrq();
    }
    // enable receive
    MSSP2_I2C_MasterStartRx();
    // get last data
    *pD=MSSP2_I2C_MasterGetRxData();
    // wait for event
    MSSP2_I2C_MasterWaitForEvent();
    // clear event
    MSSP2_I2C_MasterClearIrq();
    // send NACK
    MSSP2_I2C_MasterSendNack();
    // wait for event
    MSSP2_I2C_MasterWaitForEvent();
    // clear event
    MSSP2_I2C_MasterClearIrq();
    // send stop bit
    MSSP2_I2C_MasterStop();
    // wait for event
    MSSP2_I2C_MasterWaitForEvent();
    // clear event
    MSSP2_I2C_MasterClearIrq();
    // disable I2C
    MSSP2_I2C_MasterClose();

    if(mssp2_i2c_timeout>0)
        return !rslt;

    return 0;
}

bool MSSP2_I2C_Master_WriteNByte(uint8_t slvAddr, const uint8_t *pD, uint8_t len)
{
    bool rslt=0;
    
    mssp2_i2c_timeout=255;
    // clear event
    MSSP2_I2C_MasterClearBusCollision();
    MSSP2_I2C_MasterClearIrq();
    // enable I2C
    MSSP2_I2C_MasterOpen();
    // send start bit
    MSSP2_I2C_MasterStart();
    // wait for event
    MSSP2_I2C_MasterWaitForEvent();
    // clear event
    MSSP2_I2C_MasterClearIrq();
    // send slave address
    MSSP2_I2C_MasterSendTxData((uint8_t) (slvAddr<<1));
    // write N byte data
    while(len>0)
    {
        // wait for event
        MSSP2_I2C_MasterWaitForEvent();
        // clear event
        MSSP2_I2C_MasterClearIrq();
        // get ACK
        rslt|=MSSP2_I2C_MasterIsNack();
        len--;
        // send data
        MSSP2_I2C_MasterSendTxData(*pD++);
    }
    // wait for event
    MSSP2_I2C_MasterWaitForEvent();
    // clear event
    MSSP2_I2C_MasterClearIrq();
    // get ACK
    rslt|=MSSP2_I2C_MasterIsNack();
    // send stop bit
    MSSP2_I2C_MasterStop();
    // wait for event
    MSSP2_I2C_MasterWaitForEvent();
    // clear event
    MSSP2_I2C_MasterClearIrq();
    // disable I2C
    MSSP2_I2C_MasterClose();

    if(mssp2_i2c_timeout>0)
        return !rslt;

    return 0;
}