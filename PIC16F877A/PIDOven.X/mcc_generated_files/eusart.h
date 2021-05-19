#ifndef EUSART_H
#define EUSART_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

void EUSART_Initialize(void);
bool EUSART_is_tx_ready(void);
bool EUSART_is_rx_ready(void);
bool EUSART_is_tx_done(void);
uint8_t EUSART_Read(void);
void EUSART_Write(uint8_t txData);

#endif