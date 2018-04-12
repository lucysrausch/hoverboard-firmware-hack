/*
 * uart.c
 *
 *  Created on: Apr 12, 2018
 *      Author: tomvoc
 */

#include "uart.h"
#include "string.h"

volatile uint8_t uart2_rx[UART2_RX_FIFO_SIZE]={0};
uint8_t uart2_tx[UART2_TX_FIFO_SIZE]={0};
volatile uint8_t uart3_rx[UART3_RX_FIFO_SIZE]={0};
uint8_t uart3_tx[UART3_TX_FIFO_SIZE]={0};

UART_HandleTypeDef huart2;
UART_HandleTypeDef huart3;

#define UART2_RX_DMA (DMA1_Channel6)
#define UART2_TX_DMA (DMA1_Channel7)

#define UART3_RX_DMA (DMA1_Channel3)
#define UART3_TX_DMA (DMA1_Channel2)

void UART_Init()
{

  __HAL_RCC_USART2_CLK_ENABLE();
  __HAL_RCC_USART3_CLK_ENABLE();
  __HAL_RCC_DMA1_CLK_ENABLE();

  huart2.Instance          = USART2;
  huart2.Init.BaudRate     = UART2_BAUD;
  huart2.Init.WordLength   = UART_WORDLENGTH_8B;
  huart2.Init.StopBits     = UART_STOPBITS_1;
  huart2.Init.Parity       = UART_PARITY_NONE;
  huart2.Init.Mode         = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl    = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  HAL_UART_Init(&huart2);

  huart3.Instance          = USART3;
  huart3.Init.BaudRate     = UART3_BAUD;
  huart3.Init.WordLength   = UART_WORDLENGTH_8B;
  huart3.Init.StopBits     = UART_STOPBITS_1;
  huart3.Init.Parity       = UART_PARITY_NONE;
  huart3.Init.Mode         = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl    = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  HAL_UART_Init(&huart3);

  //enable DMA tx/rx for both UART channels
  USART2->CR3 |= USART_CR3_DMAT | USART_CR3_DMAR;
  USART3->CR3 |= USART_CR3_DMAT | USART_CR3_DMAR;

  //USART2 GPIO Configuration PA2=TX, PA3=RX
  //USART3 GPIO Configuration PB10=TX, PB11=RX
  GPIO_InitTypeDef GPIO_InitStruct;

  //Init TX GPIO's
  GPIO_InitStruct.Mode  = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.Pin   = GPIO_PIN_2;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
  GPIO_InitStruct.Pin   = GPIO_PIN_10;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  //Init RX GPIO's
  GPIO_InitStruct.Mode  = GPIO_MODE_AF_INPUT;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.Pin   = GPIO_PIN_3;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
  GPIO_InitStruct.Pin   = GPIO_PIN_11;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  //Setup UART2/UART3 RX DMA as follows:
    //Mem size 8-bit, Peripheral size 8-bit, Increment memory address,
    //Circular operation, Peripheral-to-memory, Transfer complete interrupt
    //Priority level medium
  UART2_RX_DMA->CCR   = 0;
  UART2_RX_DMA->CNDTR = UART2_RX_FIFO_SIZE;
  UART2_RX_DMA->CPAR  = (uint32_t)&(USART2->DR);
  UART2_RX_DMA->CMAR  = (uint32_t)uart2_rx;
  UART2_RX_DMA->CCR   = DMA_CCR_MINC | DMA_CCR_CIRC | DMA_CCR_TCIE | DMA_CCR_PL_0;
  DMA1->IFCR           = DMA_IFCR_CTCIF2 | DMA_IFCR_CHTIF2 | DMA_IFCR_CGIF2;

  UART3_RX_DMA->CCR   = 0;
  UART3_RX_DMA->CNDTR = UART3_RX_FIFO_SIZE;
  UART3_RX_DMA->CPAR  = (uint32_t)&(USART3->DR);
  UART3_RX_DMA->CMAR  = (uint32_t)uart3_rx;
  UART3_RX_DMA->CCR   = DMA_CCR_MINC | DMA_CCR_CIRC | DMA_CCR_TCIE | DMA_CCR_PL_0;
  DMA1->IFCR           = DMA_IFCR_CTCIF3 | DMA_IFCR_CHTIF3 | DMA_IFCR_CGIF3;

  HAL_NVIC_SetPriority(DMA1_Channel6_IRQn, 5, 5);
  HAL_NVIC_EnableIRQ(DMA1_Channel6_IRQn);
  HAL_NVIC_SetPriority(DMA1_Channel3_IRQn, 5, 5);
  HAL_NVIC_EnableIRQ(DMA1_Channel3_IRQn);

  //Setup UART2/UART3 TX DMA as follows:
    //Mem size 8-bit, Peripheral size 8-bit, Increment memory address,
    //Non-circular operation, Memory-to-peripheral, No Transfer complete interrupt
    //Priority level low
  UART2_TX_DMA->CCR   = 0;
  UART2_TX_DMA->CNDTR = 0;
  UART2_TX_DMA->CPAR  = (uint32_t)&(USART2->DR);
  UART2_TX_DMA->CMAR  = (uint32_t)uart2_tx;
  UART2_TX_DMA->CCR   = DMA_CCR_MINC | DMA_CCR_DIR;
  DMA1->IFCR           = DMA_IFCR_CTCIF4 | DMA_IFCR_CHTIF4 | DMA_IFCR_CGIF4;

  UART3_TX_DMA->CCR   = 0;
  UART3_TX_DMA->CNDTR = 0;
  UART3_TX_DMA->CPAR  = (uint32_t)&(USART3->DR);
  UART3_TX_DMA->CMAR  = (uint32_t)uart3_tx;
  UART3_TX_DMA->CCR   = DMA_CCR_MINC | DMA_CCR_DIR;
  DMA1->IFCR           = DMA_IFCR_CTCIF5 | DMA_IFCR_CHTIF5 | DMA_IFCR_CGIF5;

}

void UARTRxEnable(UART_ch_t uartCh, uint8_t enable)
{
  switch(uartCh)
  {
    case UARTCh2:
      if(enable)
        UART2_RX_DMA->CCR |= DMA_CCR_EN;
      else
        UART2_RX_DMA->CCR &= ~DMA_CCR_EN;
      break;

    case UARTCh3:
      if(enable)
        UART3_RX_DMA->CCR |= DMA_CCR_EN;
      else
        UART3_RX_DMA->CCR &= ~DMA_CCR_EN;
      break;
  }
}

uint32_t UARTAvailable(UART_ch_t uartCh)
{
  switch(uartCh)
  {
    case UARTCh2:
      return UART2_RX_FIFO_SIZE - UART2_RX_DMA->CNDTR;
      break;
    case UARTCh3:
      return UART3_RX_FIFO_SIZE - UART3_RX_DMA->CNDTR;
      break;
  }

  return 0;
}

void UARTSend(UART_ch_t uartCh, uint8_t *buff, uint32_t len)
{
  switch(uartCh)
  {
    case UARTCh2:
      //HAL_UART_Transmit(&huart2,buff,len,1000);

      if(UART2_TX_DMA->CNDTR == 0)
      {
        huart2.Instance->SR &= ~USART_SR_TC;
        UART2_TX_DMA->CCR &= ~DMA_CCR_EN;
        UART2_TX_DMA->CNDTR = len;
        UART2_TX_DMA->CMAR  = (uint32_t)buff;
        UART2_TX_DMA->CCR |= DMA_CCR_EN;
      }
      break;
    case UARTCh3:
      if(UART3_TX_DMA->CNDTR == 0)
      {
        UART3_TX_DMA->CCR &= ~DMA_CCR_EN;
        UART3_TX_DMA->CNDTR = len;
        UART3_TX_DMA->CMAR  = (uint32_t)buff;
        UART3_TX_DMA->CCR |= DMA_CCR_EN;
      }
      break;
  }
}

void UARTSendStr(UART_ch_t uartCh, const char *msg)
{
  UARTSend(uartCh, (uint8_t *)msg, strlen(msg));
}


//will be called every 64 received bytes, update FIFO info here
void DMA1_Channel6_IRQ(void)
{
  DMA1->IFCR = DMA_IFCR_CTCIF2;
}

//will be called every 64 reveived bytes, update FIFO info here
void DMA1_Channel3_IRQ(void)
{
  DMA1->IFCR = DMA_IFCR_CTCIF3;
}



