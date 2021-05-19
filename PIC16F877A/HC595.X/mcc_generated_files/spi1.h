#ifndef SPI1_H
#define SPI1_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

void SPI1_Initialize(void);
uint8_t SPI1_ExchangeByte(uint8_t data);

#endif