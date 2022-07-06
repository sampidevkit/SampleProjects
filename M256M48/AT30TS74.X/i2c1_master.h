#ifndef I2C1_MASTER_H
#define I2C1_MASTER_H

#include <stdint.h>
#include <stdbool.h>

void I2C1_Master_Init(uint32_t clock);
void I2C1_Master_Deinit(void);
int8_t I2C1_Master_Scan(void (*pStreamFnc)(uint8_t));
bool I2C1_Master_ReadNByte(uint8_t slvAddr, uint8_t *pD, uint8_t len);
bool I2C1_Master_WriteNByte(uint8_t slvAddr, const uint8_t *pD, uint8_t len);

#endif