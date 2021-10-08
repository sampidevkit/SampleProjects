#include "libcomp.h"
#include "i2c_master.h"

// I2C_Master STATES

typedef enum
{
    I2C_Master_IDLE=0,
    I2C_Master_SEND_ADR_READ,
    I2C_Master_SEND_ADR_WRITE,
    I2C_Master_TX,
    I2C_Master_RX,
    I2C_Master_RCEN,
    I2C_Master_TX_EMPTY,
    I2C_Master_SEND_RESTART_READ,
    I2C_Master_SEND_RESTART_WRITE,
    I2C_Master_SEND_RESTART,
    I2C_Master_SEND_STOP,
    I2C_Master_RX_ACK,
    I2C_Master_RX_NACK_STOP,
    I2C_Master_RX_NACK_RESTART,
    I2C_Master_RESET,
    I2C_Master_ADDRESS_NACK,

} i2c_master_fsm_states_t;

// I2C_Master Event callBack List

typedef enum
{
    I2C_Master_DATA_COMPLETE=0,
    I2C_Master_WRITE_COLLISION,
    I2C_Master_ADDR_NACK,
    I2C_Master_DATA_NACK,
    I2C_Master_TIMEOUT,
    I2C_Master_NULL
} i2c_master_callbackIndex_t;

// I2C_Master Status Structure

typedef struct
{
    i2c_master_callback_t callbackTable[6];
    void *callbackPayload[6]; //  each callBack can have a payload
    uint16_t time_out; // I2C_Master Timeout Counter between I2C_Master Events.
    uint16_t time_out_value; // Reload value for the timeouts
    i2c_master_address_t address; // The I2C_Master Address
    uint8_t *data_ptr; // pointer to a data buffer
    size_t data_length; // Bytes in the data buffer
    i2c_master_fsm_states_t state; // Driver State
    i2c_master_error_t error;
    unsigned addressNackCheck:1;
    unsigned busy:1;
    unsigned inUse:1;
    unsigned bufferFree:1;

} i2c_master_status_t;

static void I2C_Master_SetCallback(i2c_master_callbackIndex_t idx, i2c_master_callback_t cb, void *ptr);
static void I2C_Master_Poller(void);
static inline void I2C_Master_MasterFsm(void);

/* I2C_Master interfaces */
static inline bool I2C_Master_MasterOpen(void);
static inline void I2C_Master_MasterClose(void);
static inline uint8_t I2C_Master_MasterGetRxData(void);
static inline void I2C_Master_MasterSendTxData(uint8_t data);
static inline void I2C_Master_MasterEnableRestart(void);
static inline void I2C_Master_MasterDisableRestart(void);
static inline void I2C_Master_MasterStartRx(void);
static inline void I2C_Master_MasterStart(void);
static inline void I2C_Master_MasterStop(void);
static inline bool I2C_Master_MasterIsNack(void);
static inline void I2C_Master_MasterSendAck(void);
static inline void I2C_Master_MasterSendNack(void);
static inline void I2C_Master_MasterClearBusCollision(void);

/* Interrupt interfaces */
static inline void I2C_Master_MasterEnableIrq(void);
static inline bool I2C_Master_MasterIsIrqEnabled(void);
static inline void I2C_Master_MasterDisableIrq(void);
static inline void I2C_Master_MasterClearIrq(void);
static inline void I2C_Master_MasterSetIrq(void);
static inline void I2C_Master_MasterWaitForEvent(void);

static i2c_master_fsm_states_t I2C_Master_DO_IDLE(void);
static i2c_master_fsm_states_t I2C_Master_DO_SEND_ADR_READ(void);
static i2c_master_fsm_states_t I2C_Master_DO_SEND_ADR_WRITE(void);
static i2c_master_fsm_states_t I2C_Master_DO_TX(void);
static i2c_master_fsm_states_t I2C_Master_DO_RX(void);
static i2c_master_fsm_states_t I2C_Master_DO_RCEN(void);
static i2c_master_fsm_states_t I2C_Master_DO_TX_EMPTY(void);
static i2c_master_fsm_states_t I2C_Master_DO_SEND_RESTART_READ(void);
static i2c_master_fsm_states_t I2C_Master_DO_SEND_RESTART_WRITE(void);
static i2c_master_fsm_states_t I2C_Master_DO_SEND_RESTART(void);
static i2c_master_fsm_states_t I2C_Master_DO_SEND_STOP(void);
static i2c_master_fsm_states_t I2C_Master_DO_RX_ACK(void);
static i2c_master_fsm_states_t I2C_Master_DO_RX_NACK_STOP(void);
static i2c_master_fsm_states_t I2C_Master_DO_RX_NACK_RESTART(void);
static i2c_master_fsm_states_t I2C_Master_DO_RESET(void);
static i2c_master_fsm_states_t I2C_Master_DO_ADDRESS_NACK(void);


typedef i2c_master_fsm_states_t(*i2c_masterFsmHandler)(void);
const i2c_masterFsmHandler i2c_master_fsmStateTable[]={
    I2C_Master_DO_IDLE,
    I2C_Master_DO_SEND_ADR_READ,
    I2C_Master_DO_SEND_ADR_WRITE,
    I2C_Master_DO_TX,
    I2C_Master_DO_RX,
    I2C_Master_DO_RCEN,
    I2C_Master_DO_TX_EMPTY,
    I2C_Master_DO_SEND_RESTART_READ,
    I2C_Master_DO_SEND_RESTART_WRITE,
    I2C_Master_DO_SEND_RESTART,
    I2C_Master_DO_SEND_STOP,
    I2C_Master_DO_RX_ACK,
    I2C_Master_DO_RX_NACK_STOP,
    I2C_Master_DO_RX_NACK_RESTART,
    I2C_Master_DO_RESET,
    I2C_Master_DO_ADDRESS_NACK,
};

i2c_master_status_t I2C_Master_Status={0};

void I2C_Master_Initialize(void)
{

}

i2c_master_error_t I2C_Master_Open(i2c_master_address_t address)
{
    i2c_master_error_t returnValue=I2C_Master_BUSY;

    if(!I2C_Master_Status.inUse)
    {
        I2C_Master_Status.address=address;
        I2C_Master_Status.busy=0;
        I2C_Master_Status.inUse=1;
        I2C_Master_Status.addressNackCheck=0;
        I2C_Master_Status.state=I2C_Master_RESET;
        I2C_Master_Status.time_out_value=500; // MCC should determine a reasonable starting value here.
        I2C_Master_Status.bufferFree=1;

        // set all the call backs to a default of sending stop
        I2C_Master_Status.callbackTable[I2C_Master_DATA_COMPLETE]=I2C_Master_CallbackReturnStop;
        I2C_Master_Status.callbackPayload[I2C_Master_DATA_COMPLETE]=NULL;
        I2C_Master_Status.callbackTable[I2C_Master_WRITE_COLLISION]=I2C_Master_CallbackReturnStop;
        I2C_Master_Status.callbackPayload[I2C_Master_WRITE_COLLISION]=NULL;
        I2C_Master_Status.callbackTable[I2C_Master_ADDR_NACK]=I2C_Master_CallbackReturnStop;
        I2C_Master_Status.callbackPayload[I2C_Master_ADDR_NACK]=NULL;
        I2C_Master_Status.callbackTable[I2C_Master_DATA_NACK]=I2C_Master_CallbackReturnStop;
        I2C_Master_Status.callbackPayload[I2C_Master_DATA_NACK]=NULL;
        I2C_Master_Status.callbackTable[I2C_Master_TIMEOUT]=I2C_Master_CallbackReturnReset;
        I2C_Master_Status.callbackPayload[I2C_Master_TIMEOUT]=NULL;

        I2C_Master_MasterClearIrq();
        I2C_Master_MasterOpen();
        returnValue=I2C_Master_NOERR;
    }
    return returnValue;
}

i2c_master_error_t I2C_Master_Close(void)
{
    i2c_master_error_t returnValue=I2C_Master_BUSY;
    if(!I2C_Master_Status.busy)
    {
        I2C_Master_Status.inUse=0;
        I2C_Master_Status.address=0xff;
        I2C_Master_MasterClearIrq();
        I2C_Master_MasterDisableIrq();
        I2C_Master_MasterClose();
        returnValue=I2C_Master_Status.error;
    }
    return returnValue;
}

i2c_master_error_t I2C_Master_MasterOperation(bool read)
{
    i2c_master_error_t returnValue=I2C_Master_BUSY;
    if(!I2C_Master_Status.busy)
    {
        I2C_Master_Status.busy=true;
        returnValue=I2C_Master_NOERR;

        if(read)
        {
            I2C_Master_Status.state=I2C_Master_SEND_ADR_READ;
        }
        else
        {
            I2C_Master_Status.state=I2C_Master_SEND_ADR_WRITE;
        }
        I2C_Master_MasterStart();
        I2C_Master_Poller();
    }
    return returnValue;
}

i2c_master_error_t I2C_Master_MasterRead(void)
{
    return I2C_Master_MasterOperation(true);
}

i2c_master_error_t I2C_Master_MasterWrite(void)
{
    return I2C_Master_MasterOperation(false);
}

void I2C_Master_SetTimeOut(uint8_t timeOutValue)
{
    I2C_Master_MasterDisableIrq();
    I2C_Master_Status.time_out_value=timeOutValue;
    I2C_Master_MasterEnableIrq();
}

void I2C_Master_SetBuffer(void *buffer, size_t bufferSize)
{
    if(I2C_Master_Status.bufferFree)
    {
        I2C_Master_Status.data_ptr=buffer;
        I2C_Master_Status.data_length=bufferSize;
        I2C_Master_Status.bufferFree=false;
    }
}

void I2C_Master_SetDataCompleteCallback(i2c_master_callback_t cb, void *ptr)
{
    I2C_Master_SetCallback(I2C_Master_DATA_COMPLETE, cb, ptr);
}

void I2C_Master_SetWriteCollisionCallback(i2c_master_callback_t cb, void *ptr)
{
    I2C_Master_SetCallback(I2C_Master_WRITE_COLLISION, cb, ptr);
}

void I2C_Master_SetAddressNackCallback(i2c_master_callback_t cb, void *ptr)
{
    I2C_Master_SetCallback(I2C_Master_ADDR_NACK, cb, ptr);
}

void I2C_Master_SetDataNackCallback(i2c_master_callback_t cb, void *ptr)
{
    I2C_Master_SetCallback(I2C_Master_DATA_NACK, cb, ptr);
}

void I2C_Master_SetTimeoutCallback(i2c_master_callback_t cb, void *ptr)
{
    I2C_Master_SetCallback(I2C_Master_TIMEOUT, cb, ptr);
}

static void I2C_Master_SetCallback(i2c_master_callbackIndex_t idx, i2c_master_callback_t cb, void *ptr)
{
    if(cb)
    {
        I2C_Master_Status.callbackTable[idx]=cb;
        I2C_Master_Status.callbackPayload[idx]=ptr;
    }
    else
    {
        I2C_Master_Status.callbackTable[idx]=I2C_Master_CallbackReturnStop;
        I2C_Master_Status.callbackPayload[idx]=NULL;
    }
}

static void I2C_Master_Poller(void)
{
    while(I2C_Master_Status.busy)
    {
        I2C_Master_MasterWaitForEvent();
        I2C_Master_MasterFsm();
    }
}

static inline void I2C_Master_MasterFsm(void)
{
    I2C_Master_MasterClearIrq();

    if(I2C_Master_Status.addressNackCheck&&I2C_Master_MasterIsNack())
    {
        I2C_Master_Status.state=I2C_Master_ADDRESS_NACK;
    }
    I2C_Master_Status.state=i2c_master_fsmStateTable[I2C_Master_Status.state]();
}

static i2c_master_fsm_states_t I2C_Master_DO_IDLE(void)
{
    I2C_Master_Status.busy=false;
    I2C_Master_Status.error=I2C_Master_NOERR;
    return I2C_Master_RESET;
}

static i2c_master_fsm_states_t I2C_Master_DO_SEND_ADR_READ(void)
{
    I2C_Master_Status.addressNackCheck=1;
    I2C_Master_MasterSendTxData((uint8_t) (I2C_Master_Status.address<<1|1));
    return I2C_Master_RCEN;
}

static i2c_master_fsm_states_t I2C_Master_DO_SEND_ADR_WRITE(void)
{
    I2C_Master_Status.addressNackCheck=1;
    I2C_Master_MasterSendTxData((uint8_t) (I2C_Master_Status.address<<1));
    return I2C_Master_TX;
}

static i2c_master_fsm_states_t I2C_Master_DO_TX(void)
{
    if(I2C_Master_MasterIsNack())
    {
        switch(I2C_Master_Status.callbackTable[I2C_Master_DATA_NACK](I2C_Master_Status.callbackPayload[I2C_Master_DATA_NACK]))
        {
            case I2C_Master_RESTART_READ:
                return I2C_Master_DO_SEND_RESTART_READ();
            case I2C_Master_RESTART_WRITE:
                return I2C_Master_DO_SEND_RESTART_WRITE();
            default:
            case I2C_Master_CONTINUE:
            case I2C_Master_STOP:
                return I2C_Master_DO_SEND_STOP();
        }
    }
    else
    {
        I2C_Master_Status.addressNackCheck=0;
        I2C_Master_MasterSendTxData(*I2C_Master_Status.data_ptr++);
        return (--I2C_Master_Status.data_length)?I2C_Master_TX:I2C_Master_TX_EMPTY;
    }
}

static i2c_master_fsm_states_t I2C_Master_DO_RX(void)
{
    *I2C_Master_Status.data_ptr++ =I2C_Master_MasterGetRxData();
    if(--I2C_Master_Status.data_length)
    {
        I2C_Master_MasterSendAck();
        return I2C_Master_RCEN;
    }
    else
    {
        I2C_Master_Status.bufferFree=true;
        switch(I2C_Master_Status.callbackTable[I2C_Master_DATA_COMPLETE](I2C_Master_Status.callbackPayload[I2C_Master_DATA_COMPLETE]))
        {
            case I2C_Master_RESTART_WRITE:
            case I2C_Master_RESTART_READ:
                return I2C_Master_DO_RX_NACK_RESTART();
            default:
            case I2C_Master_CONTINUE:
            case I2C_Master_STOP:
                return I2C_Master_DO_RX_NACK_STOP();
        }
    }
}

static i2c_master_fsm_states_t I2C_Master_DO_RCEN(void)
{
    I2C_Master_Status.addressNackCheck=0;
    I2C_Master_MasterStartRx();
    return I2C_Master_RX;
}

static i2c_master_fsm_states_t I2C_Master_DO_TX_EMPTY(void)
{
    I2C_Master_Status.bufferFree=true;
    switch(I2C_Master_Status.callbackTable[I2C_Master_DATA_COMPLETE](I2C_Master_Status.callbackPayload[I2C_Master_DATA_COMPLETE]))
    {
        case I2C_Master_RESTART_READ:
        case I2C_Master_RESTART_WRITE:
            return I2C_Master_DO_SEND_RESTART();
        case I2C_Master_CONTINUE:
            I2C_Master_MasterSetIrq();
            return I2C_Master_TX;
        default:
        case I2C_Master_STOP:
            return I2C_Master_DO_SEND_STOP();
    }
}

static i2c_master_fsm_states_t I2C_Master_DO_RX_EMPTY(void)
{
    I2C_Master_Status.bufferFree=true;
    switch(I2C_Master_Status.callbackTable[I2C_Master_DATA_COMPLETE](I2C_Master_Status.callbackPayload[I2C_Master_DATA_COMPLETE]))
    {
        case I2C_Master_RESTART_WRITE:
            I2C_Master_MasterEnableRestart();
            return I2C_Master_SEND_RESTART_WRITE;
        case I2C_Master_RESTART_READ:
            I2C_Master_MasterEnableRestart();
            return I2C_Master_SEND_RESTART_READ;
        case I2C_Master_CONTINUE:
            // Avoid the counter stop condition , Counter is incremented by 1
            return I2C_Master_RX;
        default:
        case I2C_Master_STOP:
            if(I2C_Master_Status.state!=I2C_Master_SEND_RESTART_READ)
            {
                I2C_Master_MasterDisableRestart();
            }
            return I2C_Master_RESET;
    }
}

static i2c_master_fsm_states_t I2C_Master_DO_SEND_RESTART_READ(void)
{
    I2C_Master_MasterEnableRestart();
    return I2C_Master_SEND_ADR_READ;
}

static i2c_master_fsm_states_t I2C_Master_DO_SEND_RESTART_WRITE(void)
{
    I2C_Master_MasterEnableRestart();
    return I2C_Master_SEND_ADR_WRITE;
}

static i2c_master_fsm_states_t I2C_Master_DO_SEND_RESTART(void)
{
    I2C_Master_MasterEnableRestart();
    return I2C_Master_SEND_ADR_READ;
}

static i2c_master_fsm_states_t I2C_Master_DO_SEND_STOP(void)
{
    I2C_Master_MasterStop();
    return I2C_Master_IDLE;
}

static i2c_master_fsm_states_t I2C_Master_DO_RX_ACK(void)
{
    I2C_Master_MasterSendAck();
    return I2C_Master_RCEN;
}

static i2c_master_fsm_states_t I2C_Master_DO_RX_NACK_STOP(void)
{
    I2C_Master_MasterSendNack();
    return I2C_Master_SEND_STOP;
}

static i2c_master_fsm_states_t I2C_Master_DO_RX_NACK_RESTART(void)
{
    I2C_Master_MasterSendNack();
    return I2C_Master_SEND_RESTART;
}

static i2c_master_fsm_states_t I2C_Master_DO_RESET(void)
{
    I2C_Master_Status.busy=false;
    I2C_Master_Status.error=I2C_Master_NOERR;
    return I2C_Master_RESET;
}

static i2c_master_fsm_states_t I2C_Master_DO_ADDRESS_NACK(void)
{
    I2C_Master_Status.addressNackCheck=0;
    I2C_Master_Status.error=I2C_Master_FAIL;
    switch(I2C_Master_Status.callbackTable[I2C_Master_ADDR_NACK](I2C_Master_Status.callbackPayload[I2C_Master_ADDR_NACK]))
    {
        case I2C_Master_RESTART_READ:
        case I2C_Master_RESTART_WRITE:
            return I2C_Master_DO_SEND_RESTART();
        default:
            return I2C_Master_DO_SEND_STOP();
    }
}

void I2C_Master_BusCollisionIsr(void)
{
    I2C_Master_MasterClearBusCollision();
    I2C_Master_Status.state=I2C_Master_RESET;
}

i2c_master_operations_t I2C_Master_CallbackReturnStop(void *funPtr)
{
    return I2C_Master_STOP;
}

i2c_master_operations_t I2C_Master_CallbackReturnReset(void *funPtr)
{
    return I2C_Master_RESET_LINK;
}

i2c_master_operations_t I2C_Master_CallbackRestartWrite(void *funPtr)
{
    return I2C_Master_RESTART_WRITE;
}

i2c_master_operations_t I2C_Master_CallbackRestartRead(void *funPtr)
{
    return I2C_Master_RESTART_READ;
}

/* I2C_Master Register Level interfaces */
static inline bool I2C_Master_MasterOpen(void)
{
    return i2c1_driver_driver_open();
}

static inline void I2C_Master_MasterClose(void)
{
    //Disable I2C_Master
    i2c1_driver_close();
}

static inline uint8_t I2C_Master_MasterGetRxData(void)
{
    return i2c1_driver_getRXData();
}

static inline void I2C_Master_MasterSendTxData(uint8_t data)
{
    i2c1_driver_TXData(data);
}

static inline void I2C_Master_MasterEnableRestart(void)
{
    i2c1_driver_restart();
}

static inline void I2C_Master_MasterDisableRestart(void)
{
    //SSP1CON2bits.RSEN=0;
}

static inline void I2C_Master_MasterStartRx(void)
{
    i2c1_driver_startRX();
}

static inline void I2C_Master_MasterStart(void)
{
    i2c1_driver_start();
}

static inline void I2C_Master_MasterStop(void)
{
    i2c1_driver_stop();
}

static inline bool I2C_Master_MasterIsNack(void)
{
    return i2c1_driver_isNACK();
}

static inline void I2C_Master_MasterSendAck(void)
{
    i2c1_driver_sendACK();
}

static inline void I2C_Master_MasterSendNack(void)
{
    i2c1_driver_sendNACK();
}

static inline void I2C_Master_MasterClearBusCollision(void)
{
    i2c1_driver_clearBusCollision();
}

static inline bool I2C_Master_MasterIsRxBufFull(void)
{
    return i2c1_driver_isBuferFull();
}

static inline void I2C_Master_MasterEnableIrq(void)
{
    i2c1_enableIRQ();
}

static inline bool I2C_Master_MasterIsIrqEnabled(void)
{
    return i2c1_IRQisEnabled();
}

static inline void I2C_Master_MasterDisableIrq(void)
{
    i2c1_disableIRQ();
}

static inline void I2C_Master_MasterClearIrq(void)
{
    i2c1_clearIRQ();
}

static inline void I2C_Master_MasterSetIrq(void)
{
    i2c1_setIRQ();
}

static inline void I2C_Master_MasterWaitForEvent(void)
{
    i2c1_waitForEvent(0);
}
