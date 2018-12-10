#include "stm32f1xx_hal.h"
#include "defines.h"
#include "setup.h"
#include "config.h"
#include "stdio.h"
#include "string.h"
#include "comms.h"

extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;

#ifdef DEBUG_SERIAL_USART3
#define UART_DMA_CHANNEL DMA1_Channel2
extern UART_HandleTypeDef huart3;
#endif

#ifdef DEBUG_SERIAL_USART2
#define UART_DMA_CHANNEL DMA1_Channel7
extern UART_HandleTypeDef huart2;
#endif


volatile uint8_t uart_buf[100];
volatile int16_t ch_buf[8];

int debug_out = 1;
int enablescope = 1;

//volatile char char_buf[300];

void setScopeChannel(uint8_t ch, int16_t val) {
  ch_buf[ch] = val;
}

void consoleScope() {
  if (!enablescope)
    return;

    #if defined DEBUG_SERIAL_SERVOTERM && (defined DEBUG_SERIAL_USART2 || defined DEBUG_SERIAL_USART3)
    uart_buf[0] = 0xff;
    uart_buf[1] = CLAMP(ch_buf[0]+127, 0, 255);
    uart_buf[2] = CLAMP(ch_buf[1]+127, 0, 255);
    uart_buf[3] = CLAMP(ch_buf[2]+127, 0, 255);
    uart_buf[4] = CLAMP(ch_buf[3]+127, 0, 255);
    uart_buf[5] = CLAMP(ch_buf[4]+127, 0, 255);
    uart_buf[6] = CLAMP(ch_buf[5]+127, 0, 255);
    uart_buf[7] = CLAMP(ch_buf[6]+127, 0, 255);
    uart_buf[8] = CLAMP(ch_buf[7]+127, 0, 255);
    uart_buf[9] = '\n';

    if(UART_DMA_CHANNEL->CNDTR == 0) {
      UART_DMA_CHANNEL->CCR &= ~DMA_CCR_EN;
      UART_DMA_CHANNEL->CNDTR = 10;
      UART_DMA_CHANNEL->CMAR  = (uint32_t)uart_buf;
      UART_DMA_CHANNEL->CCR |= DMA_CCR_EN;
    }
  #endif

  #if defined DEBUG_SERIAL_ASCII && (defined DEBUG_SERIAL_USART2 || defined DEBUG_SERIAL_USART3)
    memset(uart_buf, 0, sizeof(uart_buf));
    sprintf(uart_buf, "1:%i 2:%i 3:%i 4:%i 5:%i 6:%i 7:%i 8:%i\r\n", ch_buf[0], ch_buf[1], ch_buf[2], ch_buf[3], ch_buf[4], ch_buf[5], ch_buf[6], ch_buf[7]);

    if(UART_DMA_CHANNEL->CNDTR == 0) {
      UART_DMA_CHANNEL->CCR &= ~DMA_CCR_EN;
      UART_DMA_CHANNEL->CNDTR = strlen(uart_buf);
      UART_DMA_CHANNEL->CMAR  = (uint32_t)uart_buf;
      UART_DMA_CHANNEL->CCR |= DMA_CCR_EN;
    }
  #endif
}

void consoleLog(char *message)
{
#ifdef DEBUG_SERIAL_USART2
    HAL_UART_Transmit_DMA(&huart2, (uint8_t *)message, strlen(message));
#endif

#ifdef DEBUG_SERIAL_USART3
    HAL_UART_Transmit_DMA(&huart3, (uint8_t *)message, strlen(message));
#endif
  // TODO: Method to select which input is used for Protocol when both are active
#if defined(SERIAL_USART2_IT) && !defined(READ_SENSOR)
  USART2_IT_send((unsigned char *)message, strlen(message));
#elif defined(SERIAL_USART3_IT) && !defined(READ_SENSOR)
  USART3_IT_send((unsigned char *)message, strlen(message));
#else
  HAL_UART_Transmit_DMA(&huart2, (uint8_t *)message, strlen(message));
#endif
}

#ifdef SERIAL_USART2_IT

int USART2_IT_starttx() {
    __HAL_UART_ENABLE_IT(&huart2, UART_IT_TXE);
    return 1;
}

int USART2_IT_send(unsigned char *data, int len) {

    int count = serial_usart_buffer_count(&usart2_it_TXbuffer);
    if (count + len + 1 > SERIAL_USART_BUFFER_SIZE-3){
        usart2_it_TXbuffer.overflow++;
        return -1;
    }

    for (int i = 0; i < len; i++){
        serial_usart_buffer_push(&usart2_it_TXbuffer, (SERIAL_USART_IT_BUFFERTYPE) data[i]);
    }

    return USART2_IT_starttx();
}

//////////////////////////////////////////////////////
// called from actual IRQ routines
void USART2_IT_IRQ(USART_TypeDef *us) {
  volatile uint32_t *SR     = &us->SR;  // USART Status register
  volatile uint32_t *DR     = &us->DR;  // USART Data register
  volatile uint32_t *CR1    = &us->CR1; // USART Control register 1

  // Transmit
  if ((*SR) & UART_FLAG_TXE) {
    if (serial_usart_buffer_count(&usart2_it_TXbuffer) == 0) {
      *CR1 = (*CR1 & ~(USART_CR1_TXEIE | USART_CR1_TCIE));
    } else {
      *DR = (serial_usart_buffer_pop(&usart2_it_TXbuffer) & 0x1ff);
    }
  }

  // Receive
  if (((*SR) & UART_FLAG_RXNE)) {
    SERIAL_USART_IT_BUFFERTYPE rword = (*DR) & 0x01FF;
    serial_usart_buffer_push(&usart2_it_RXbuffer, rword);
  }

  return;
}

#endif

#ifdef SERIAL_USART3_IT

int USART3_IT_starttx() {
    __HAL_UART_ENABLE_IT(&huart3, UART_IT_TXE);
    return 1;
}

int USART3_IT_send(unsigned char *data, int len) {

    int count = serial_usart_buffer_count(&usart3_it_TXbuffer);
    if (count + len + 1 > SERIAL_USART_BUFFER_SIZE-3){
        usart3_it_TXbuffer.overflow++;
        return -1;
    }

    for (int i = 0; i < len; i++){
        serial_usart_buffer_push(&usart3_it_TXbuffer, (SERIAL_USART_IT_BUFFERTYPE) data[i]);
    }

    return USART3_IT_starttx();
}

//////////////////////////////////////////////////////
// called from actual IRQ routines
void USART3_IT_IRQ(USART_TypeDef *us) {
  volatile uint32_t *SR     = &us->SR;  // USART Status register
  volatile uint32_t *DR     = &us->DR;  // USART Data register
  volatile uint32_t *CR1    = &us->CR1; // USART Control register 1

  // Transmit
  if ((*SR) & UART_FLAG_TXE) {
    if (serial_usart_buffer_count(&usart3_it_TXbuffer) == 0) {
      *CR1 = (*CR1 & ~(USART_CR1_TXEIE | USART_CR1_TCIE));
    } else {
      *DR = (serial_usart_buffer_pop(&usart3_it_TXbuffer) & 0x1ff);
    }
  }

  // Receive
  if (((*SR) & UART_FLAG_RXNE)) {
    SERIAL_USART_IT_BUFFERTYPE rword = (*DR) & 0x01FF;
    serial_usart_buffer_push(&usart3_it_RXbuffer, rword);
  }

  return;
}

#endif

int serial_usart_buffer_count(volatile SERIAL_USART_BUFFER *usart_buf) {
    int count = usart_buf->head - usart_buf->tail;
    if (count < 0) count += SERIAL_USART_BUFFER_SIZE;
    return count;
}

void serial_usart_buffer_push(volatile SERIAL_USART_BUFFER *usart_buf, SERIAL_USART_IT_BUFFERTYPE value) {
    int count = serial_usart_buffer_count(usart_buf);
    if (count >=  SERIAL_USART_BUFFER_SIZE-2){
        usart_buf->overflow++;
        return;
    }

    usart_buf->buff[usart_buf->head] = value;
    usart_buf->head = ((usart_buf->head + 1 ) % SERIAL_USART_BUFFER_SIZE);
}

SERIAL_USART_IT_BUFFERTYPE serial_usart_buffer_pop(volatile SERIAL_USART_BUFFER *usart_buf) {
  SERIAL_USART_IT_BUFFERTYPE t = 0;
  if (usart_buf->head != usart_buf->tail){
      t = usart_buf->buff[usart_buf->tail];
      usart_buf->tail = ((usart_buf->tail + 1 ) % SERIAL_USART_BUFFER_SIZE);
  }
  return t;
}