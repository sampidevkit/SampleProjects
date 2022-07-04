#ifndef MSSP1_I2C_MASTER_H
#define MSSP1_I2C_MASTER_H

#include <stdint.h>
#include <stdbool.h>

void MSSP1_I2C_Master_Init(uint32_t clock);
void MSSP1_I2C_Master_Deinit(void);
int8_t MSSP1_I2C_Master_Scan(void (*pStreamFnc)(uint8_t));
bool MSSP1_I2C_Master_ReadNByte(uint8_t slvAddr, uint8_t *pD, uint8_t len);
bool MSSP1_I2C_Master_WriteNByte(uint8_t slvAddr, const uint8_t *pD, uint8_t len);

#endif