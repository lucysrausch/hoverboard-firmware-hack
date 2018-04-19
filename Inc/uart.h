/*
 * uart.h
 *
 *  Created on: Apr 12, 2018
 *      Author: tomvoc
 */

#pragma once

#include "stm32f1xx_hal.h"
#include "config.h"

#define UART2_BAUD 115200
#define UART2_RX_FIFO_SIZE 64
#define UART2_TX_FIFO_SIZE 64

#define UART3_BAUD 115200
#define UART3_RX_FIFO_SIZE 64
#define UART3_TX_FIFO_SIZE 64

typedef enum
{
  UARTCh2,
  UARTCh3
} UART_ch_t;


void UART_Init();
void UARTRxEnable(UART_ch_t uartCh, uint8_t enable);
uint32_t UARTAvailable(UART_ch_t uartCh);
int UARTSend(UART_ch_t uartCh, const uint8_t *buff, uint32_t len);
int UARTSendStr(UART_ch_t uartCh, const char *msg);
int UARTRead(UART_ch_t uartCh, uint8_t* buff, uint32_t len);
void UARTFlushRX(UART_ch_t uartCh);
void UARTFlushTX(UART_ch_t uartCh);
int UARTTXReady(UART_ch_t uartCh);
