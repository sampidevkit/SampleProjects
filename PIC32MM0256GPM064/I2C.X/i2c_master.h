#ifndef I2C_MASTER_H
#define I2C_MASTER_H

#include <stdint.h>
#include <stdbool.h>
#include "i2c_master_cfg.h"

typedef enum {
    I2C_Master_NOERR, // The message was sent.
    I2C_Master_BUSY, // Message was not sent, bus was busy.
    I2C_Master_FAIL // Message was not sent, bus failure
    // If you are interested in the failure reason,
    // Sit on the event call-backs.
} i2c_master_error_t;

typedef enum {
    I2C_Master_STOP = 1,
    I2C_Master_RESTART_READ,
    I2C_Master_RESTART_WRITE,
    I2C_Master_CONTINUE,
    I2C_Master_RESET_LINK
} i2c_master_operations_t;

typedef uint8_t i2c_master_address_t;
typedef i2c_master_operations_t(*i2c_master_callback_t)(void *funPtr);

// common callback responses
i2c_master_operations_t I2C_Master_CallbackReturnStop(void *funPtr);
i2c_master_operations_t I2C_Master_CallbackReturnReset(void *funPtr);
i2c_master_operations_t I2C_Master_CallbackRestartWrite(void *funPtr);
i2c_master_operations_t I2C_Master_CallbackRestartRead(void *funPtr);

/**
 * \brief Initialize I2C_Master interface
 *
 * \return Nothing
 */
void I2C_Master_Initialize(void);

/**
 * \brief Open the I2C_Master for communication
 *
 * \param[in] address The slave address to use in the transfer
 *
 * \return Initialization status.
 * \retval I2C_Master_NOERR The I2C_Master open was successful
 * \retval I2C_Master_BUSY  The I2C_Master open failed because the interface is busy
 * \retval I2C_Master_FAIL  The I2C_Master open failed with an error
 */
i2c_master_error_t I2C_Master_Open(i2c_master_address_t address);

/**
 * \brief Close the I2C_Master interface
 *
 * \return Status of close operation.
 * \retval I2C_Master_NOERR The I2C_Master open was successful
 * \retval I2C_Master_BUSY  The I2C_Master open failed because the interface is busy
 * \retval I2C_Master_FAIL  The I2C_Master open failed with an error
 */
i2c_master_error_t I2C_Master_Close(void);

/**
 * \brief Start an operation on an opened I2C_Master interface
 *
 * \param[in] read Set to true for read, false for write
 *
 * \return Status of operation
 * \retval I2C_Master_NOERR The I2C_Master open was successful
 * \retval I2C_Master_BUSY  The I2C_Master open failed because the interface is busy
 * \retval I2C_Master_FAIL  The I2C_Master open failed with an error
 */
i2c_master_error_t I2C_Master_MasterOperation(bool read);

/**
 * \brief Identical to I2C_Master_MasterOperation(false);
 */
i2c_master_error_t I2C_Master_MasterWrite(void); // to be depreciated

/**
 * \brief Identical to I2C_Master_MasterOperation(true);
 */
i2c_master_error_t I2C_Master_MasterRead(void); // to be depreciated

/**
 * \brief Set timeout to be used for I2C_Master operations. Uses the Timeout driver.
 *
 * \param[in] to Timeout in ticks
 *
 * \return Nothing
 */
void I2C_Master_SetTimeout(uint8_t timeOut);

/**
 * \brief Sets up the data buffer to use, and number of bytes to transfer
 *
 * \param[in] buffer Pointer to data buffer to use for read or write data
 * \param[in] bufferSize Number of bytes to read or write from slave
 *
 * \return Nothing
 */
void I2C_Master_SetBuffer(void *buffer, size_t bufferSize);

// Event Callback functions.

/**
 * \brief Set callback to be called when all specifed data has been transferred.
 *
 * \param[in] cb Pointer to callback function
 * \param[in] ptr  Pointer to the callback function's parameters
 *
 * \return Nothing
 */
void I2C_Master_SetDataCompleteCallback(i2c_master_callback_t cb, void *ptr);

/**
 * \brief Set callback to be called when there has been a bus collision and arbitration was lost.
 *
 * \param[in] cb Pointer to callback function
 * \param[in] ptr  Pointer to the callback function's parameters
 *
 * \return Nothing
 */
void I2C_Master_SetWriteCollisionCallback(i2c_master_callback_t cb, void *ptr);

/**
 * \brief Set callback to be called when the transmitted address was Nack'ed.
 *
 * \param[in] cb Pointer to callback function
 * \param[in] ptr  Pointer to the callback function's parameters
 *
 * \return Nothing
 */
void I2C_Master_SetAddressNackCallback(i2c_master_callback_t cb, void *ptr);

/**
 * \brief Set callback to be called when the transmitted data was Nack'ed.
 *
 * \param[in] cb Pointer to callback function
 * \param[in] ptr  Pointer to the callback function's parameters
 *
 * \return Nothing
 */
void I2C_Master_SetDataNackCallback(i2c_master_callback_t cb, void *ptr);

/**
 * \brief Set callback to be called when there was a bus timeout.
 *
 * \param[in] cb Pointer to callback function
 * \param[in] ptr  Pointer to the callback function's parameters
 *
 * \return Nothing
 */
void I2C_Master_SetTimeoutCallback(i2c_master_callback_t cb, void *ptr);


#endif