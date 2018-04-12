/*
 * uart.h
 *
 *  Created on: Apr 12, 2018
 *      Author: tomvoc
 */

#pragma once

#include "stm32f1xx_hal.h"
#include "config.h"

typedef enum
{
  UARTCh2,
  UARTCh3
} UART_ch_t;


void UART_Init();
void UARTRxEnable(UART_ch_t uartCh, uint8_t enable);
uint32_t UARTAvailable(UART_ch_t uartCh);
void UARTSend(UART_ch_t uartCh, uint8_t *buff, uint32_t len);
void UARTSendStr(UART_ch_t uartCh, const char *msg);
