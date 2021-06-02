#ifndef UART_H
#define UART_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define UART_TX_BUFFER_SIZE 8
#define UART_RX_BUFFER_SIZE 16

void UART_Initialize(void);
uint8_t UART_is_tx_ready(void);
uint8_t UART_is_rx_ready(void);
bool UART_is_tx_done(void);
uint8_t UART_Read(void);
void UART_Write(uint8_t txData);
// Used in interrupt manager
void UART_Transmit_ISR(void);
void UART_Receive_ISR(void);

#endif