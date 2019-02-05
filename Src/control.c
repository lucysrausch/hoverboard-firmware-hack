
#include "stm32f1xx_hal.h"
#include "defines.h"
#include "setup.h"
#include "config.h"
#include <stdbool.h>
#include <string.h>

TIM_HandleTypeDef TimHandle;
TIM_HandleTypeDef TimHandle2;
uint8_t ppm_count = 0;
uint8_t pwm_count = 0;
uint32_t timeout = 100;
uint8_t nunchuck_data[6] = {0};

uint8_t i2cBuffer[2];

extern I2C_HandleTypeDef hi2c2;
DMA_HandleTypeDef hdma_i2c2_rx;
DMA_HandleTypeDef hdma_i2c2_tx;

#ifdef CONTROL_PPM
uint16_t ppm_captured_value[PPM_NUM_CHANNELS + 1] = {500, 500};
uint16_t ppm_captured_value_buffer[PPM_NUM_CHANNELS+1] = {500, 500};
uint32_t ppm_timeout = 0;

bool ppm_valid = true;

#define IN_RANGE(x, low, up) (((x) >= (low)) && ((x) <= (up)))

void PPM_ISR_Callback() {
  // Dummy loop with 16 bit count wrap around
  uint16_t rc_delay = TIM2->CNT;
  TIM2->CNT = 0;

  if (rc_delay > 3000) {
    if (ppm_valid && ppm_count == PPM_NUM_CHANNELS) {
      ppm_timeout = 0;
      memcpy(ppm_captured_value, ppm_captured_value_buffer, sizeof(ppm_captured_value));
    }
    ppm_valid = true;
    ppm_count = 0;
  }
  else if (ppm_count < PPM_NUM_CHANNELS && IN_RANGE(rc_delay, 900, 2100)){
    timeout = 0;
    ppm_captured_value_buffer[ppm_count++] = CLAMP(rc_delay, 1000, 2000) - 1000;
  } else {
    ppm_valid = false;
  }
}

// SysTick executes once each ms
void PPM_SysTick_Callback() {
  ppm_timeout++;
  // Stop after 500 ms without PPM signal
  if(ppm_timeout > 500) {
    int i;
    for(i = 0; i < PPM_NUM_CHANNELS; i++) {
      ppm_captured_value[i] = 500;
    }
    ppm_timeout = 0;
  }
}

void PPM_Init() {
  GPIO_InitTypeDef GPIO_InitStruct;
  /*Configure GPIO pin : PA3 */
  GPIO_InitStruct.Pin = GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  __HAL_RCC_TIM2_CLK_ENABLE();
  TimHandle.Instance = TIM2;
  TimHandle.Init.Period = UINT16_MAX;
  TimHandle.Init.Prescaler = (SystemCoreClock/DELAY_TIM_FREQUENCY_US)-1;;
  TimHandle.Init.ClockDivision = 0;
  TimHandle.Init.CounterMode = TIM_COUNTERMODE_UP;
  HAL_TIM_Base_Init(&TimHandle);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI3_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI3_IRQn);
  HAL_TIM_Base_Start(&TimHandle);
}
#endif


#ifdef CONTROL_PWM
uint16_t pwm_captured_ch1_value = 500;
uint16_t pwm_captured_ch2_value = 500;
uint32_t pwm_timeout = 0;

#define IN_RANGE(x, low, up) (((x) >= (low)) && ((x) <= (up)))

int PWM_Signal_Correct(x, max, min) {
  int outVal = 0;
  if(x > -PWM_DEADBAND && x < PWM_DEADBAND) {
    outVal = 0;
  } else if(x > 0) {
    outVal = (float)CLAMP(x-PWM_DEADBAND, 0, 1000) / max * 1000;
  } else {
    outVal = 0 - ((float)CLAMP(x+PWM_DEADBAND, -1000, 0) / min * 1000);
  }
  return outVal;
}

void PWM_ISR_CH1_Callback() {
  // Dummy loop with 16 bit count wrap around
  uint16_t rc_signal = TIM3->CNT;
  TIM3->CNT = 0;

  if (IN_RANGE(rc_signal, 900, 2100)){
    timeout = 0;
    pwm_timeout = 0;
    pwm_captured_ch1_value = CLAMP(rc_signal, 1000, 2000) - 1000;
  }
}

void PWM_ISR_CH2_Callback() {
  // Dummy loop with 16 bit count wrap around
  uint16_t rc_signal = TIM2->CNT;
  TIM2->CNT = 0;

  if (IN_RANGE(rc_signal, 900, 2100)){
    timeout = 0;
    pwm_timeout = 0;
    pwm_captured_ch2_value = CLAMP(rc_signal, 1000, 2000) - 1000;
  }
}

// SysTick executes once each ms
void PWM_SysTick_Callback() {
  pwm_timeout++;
  // Stop after 500 ms without PPM signal
  if(pwm_timeout > 500) {
    pwm_captured_ch1_value = 500;
    pwm_captured_ch2_value = 500;
    pwm_timeout = 0;
  }
}

void PWM_Init() {
  // Channel 1 (steering)

  GPIO_InitTypeDef GPIO_InitStruct2;
  /*Configure GPIO pin : PA2 */
  GPIO_InitStruct2.Pin = GPIO_PIN_2;
  GPIO_InitStruct2.Mode = GPIO_MODE_IT_RISING_FALLING;
  GPIO_InitStruct2.Speed = GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct2.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct2);

  __HAL_RCC_TIM3_CLK_ENABLE();
  TimHandle2.Instance = TIM3;
  TimHandle2.Init.Period = UINT16_MAX;
  TimHandle2.Init.Prescaler = (SystemCoreClock/DELAY_TIM_FREQUENCY_US)-1;;
  TimHandle2.Init.ClockDivision = 0;
  TimHandle2.Init.CounterMode = TIM_COUNTERMODE_UP;
  HAL_TIM_Base_Init(&TimHandle2);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI2_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI2_IRQn);
  HAL_TIM_Base_Start(&TimHandle2);

  // Channel 2 (speed)

  GPIO_InitTypeDef GPIO_InitStruct;
  /*Configure GPIO pin : PA3 */
  GPIO_InitStruct.Pin = GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  __HAL_RCC_TIM2_CLK_ENABLE();
  TimHandle.Instance = TIM2;
  TimHandle.Init.Period = UINT16_MAX;
  TimHandle.Init.Prescaler = (SystemCoreClock/DELAY_TIM_FREQUENCY_US)-1;;
  TimHandle.Init.ClockDivision = 0;
  TimHandle.Init.CounterMode = TIM_COUNTERMODE_UP;
  HAL_TIM_Base_Init(&TimHandle);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI3_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI3_IRQn);
  HAL_TIM_Base_Start(&TimHandle);
}
#endif

void Nunchuck_Init() {
    //-- START -- init WiiNunchuck
  i2cBuffer[0] = 0xF0;
  i2cBuffer[1] = 0x55;

  HAL_I2C_Master_Transmit(&hi2c2,0xA4,(uint8_t*)i2cBuffer, 2, 100);
  HAL_Delay(10);

  i2cBuffer[0] = 0xFB;
  i2cBuffer[1] = 0x00;

  HAL_I2C_Master_Transmit(&hi2c2,0xA4,(uint8_t*)i2cBuffer, 2, 100);
  HAL_Delay(10);
}

void Nunchuck_Read() {
  i2cBuffer[0] = 0x00;
  HAL_I2C_Master_Transmit(&hi2c2,0xA4,(uint8_t*)i2cBuffer, 1, 100);
  HAL_Delay(5);
  if (HAL_I2C_Master_Receive(&hi2c2,0xA4,(uint8_t*)nunchuck_data, 6, 100) == HAL_OK) {
    timeout = 0;
  } else {
    timeout++;
  }

  if (timeout > 3) {
    HAL_Delay(50);
    Nunchuck_Init();
  }

  //setScopeChannel(0, (int)nunchuck_data[0]);
  //setScopeChannel(1, (int)nunchuck_data[1]);
  //setScopeChannel(2, (int)nunchuck_data[5] & 1);
  //setScopeChannel(3, ((int)nunchuck_data[5] >> 1) & 1);
}
