#include "stm32f1xx_hal.h"
#include "defines.h"
#include "setup.h"
#include "config.h"
#include "stdio.h"
#include "string.h"

UART_HandleTypeDef huart2;

volatile uint8_t uart_buf[300];
//volatile char char_buf[300];

void consoleScope(int16_t ch0, int16_t ch1, int16_t ch2, int16_t ch3, int16_t ch4, int16_t ch5, int16_t ch6, int16_t ch7) {
  #ifdef DEBUG_SERIAL_SERVOTERM
    uart_buf[0] = 0xff;
    uart_buf[1] = CLAMP(ch0+127, 0, 255);
    uart_buf[2] = CLAMP(ch1+127, 0, 255);
    uart_buf[3] = CLAMP(ch2+127, 0, 255);
    uart_buf[4] = CLAMP(ch3+127, 0, 255);
    uart_buf[5] = CLAMP(ch4+127, 0, 255);
    uart_buf[6] = CLAMP(ch5+127, 0, 255);
    uart_buf[7] = CLAMP(ch6+127, 0, 255);
    uart_buf[8] = CLAMP(ch7+127, 0, 255);
    uart_buf[9] = '\n';

    if(DMA1_Channel2->CNDTR == 0) {
      DMA1_Channel2->CCR &= ~DMA_CCR_EN;
      DMA1_Channel2->CNDTR = 10;
      DMA1_Channel2->CMAR  = (uint32_t)uart_buf;
      DMA1_Channel2->CCR |= DMA_CCR_EN;
    }
  #endif

  #ifdef DEBUG_SERIAL_ASCII
    memset(&uart_buf, 0, sizeof(uart_buf));
    sprintf(uart_buf, "%i;%i;%i;%i;%i;%i;%i;%i\n\r", ch0, ch1, ch2, ch3, ch4, ch5, ch6, ch7);

    if(DMA1_Channel2->CNDTR == 0) {
      DMA1_Channel2->CCR &= ~DMA_CCR_EN;
      DMA1_Channel2->CNDTR = strlen(uart_buf);
      DMA1_Channel2->CMAR  = (uint32_t)uart_buf;
      DMA1_Channel2->CCR |= DMA_CCR_EN;
    }
  #endif
}

void consoleLog(char *message)
{
    HAL_UART_Transmit_DMA(&huart2, (uint8_t *)message, strlen(message));
}
