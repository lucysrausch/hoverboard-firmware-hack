/*
* This file is part of the stmbl project.
*
* Copyright (C) 2013-2018 Rene Hopf <renehopf@mac.com>
* Copyright (C) 2013-2018 Nico Stute <crinq@crinq.de>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "stm32f1xx_hal.h"
#include "defines.h"
#include "setup.h"
#include "config.h"

void SystemClock_Config(void);

extern float adccmd1;
extern float adccmd2;

extern TIM_HandleTypeDef htim_left;
extern TIM_HandleTypeDef htim_right;
extern ADC_HandleTypeDef hadc1;
extern ADC_HandleTypeDef hadc2;
extern volatile adc_buf_t adc_buffer;
extern volatile uint16_t ppm_captured_value[PPM_NUM_CHANNELS+1];

extern volatile int pwml;
extern volatile int pwmr;
extern volatile int weakl;
extern volatile int weakr;

volatile int pwmrl = 0;

extern uint8_t buzzerFreq;
extern uint8_t buzzerPattern;

extern uint8_t enable;

extern volatile uint32_t timeout;

extern float batteryVoltage;
extern uint8_t nunchuck_data[6];


int milli_vel_error_sum = 0;

int main(void) {
  HAL_Init();
  __HAL_RCC_AFIO_CLK_ENABLE();
  HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
  /* System interrupt init*/
  /* MemoryManagement_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(MemoryManagement_IRQn, 0, 0);
  /* BusFault_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(BusFault_IRQn, 0, 0);
  /* UsageFault_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(UsageFault_IRQn, 0, 0);
  /* SVCall_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SVCall_IRQn, 0, 0);
  /* DebugMonitor_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DebugMonitor_IRQn, 0, 0);
  /* PendSV_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(PendSV_IRQn, 0, 0);
  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);

  SystemClock_Config();

  __HAL_RCC_DMA1_CLK_DISABLE();
  MX_GPIO_Init();
  MX_TIM_Init();
  MX_ADC1_Init();
  MX_ADC2_Init();
  UART_Init();

  HAL_GPIO_WritePin(OFF_PORT, OFF_PIN, 1);

  HAL_ADC_Start(&hadc1);
  HAL_ADC_Start(&hadc2);

  for (int i = 8; i >= 0; i--) {
    buzzerFreq = i;
    HAL_Delay(100);
  }
  buzzerFreq = 0;

  HAL_GPIO_WritePin(LED_PORT, LED_PIN, 1);

  int lastSpeedL = 0, lastSpeedR = 0;
  int speedL = 0, speedR = 0;
  float direction = 1;

  #ifdef CONTROL_PPM
    PPM_Init();
  #endif

  #ifdef CONTROL_NUNCHUCK
    I2C_Init();
    Nunchuck_Init();
  #endif



  enable = 1;

  while(1) {
    HAL_Delay(2);

    #ifdef CONTROL_NUNCHUCK
      Nunchuck_Read();
      setScopeChannel(0, (int)nunchuck_data[0]);
      setScopeChannel(1, (int)nunchuck_data[1]);
      setScopeChannel(2, (int)nunchuck_data[5] & 1);
      setScopeChannel(3, ((int)nunchuck_data[5] >> 1) & 1);
    #endif


    #ifdef CONTROL_PPM
      speedL = -(CLAMP((((ppm_captured_value[1]-500)+(ppm_captured_value[0]-500)/2.0)*(ppm_captured_value[2]/500.0)), -800, 800));
      speedR = (CLAMP((((ppm_captured_value[1]-500)-(ppm_captured_value[0]-500)/2.0)*(ppm_captured_value[2]/500.0)), -800, 800));
      if ((speedL < lastSpeedL + 50 && speedL > lastSpeedL - 50) && (speedR < lastSpeedR + 50 && speedR > lastSpeedR - 50) && timeout < 50) {
        //pwmr = speedR;
        //pwml = speedL;
      }

      lastSpeedL = speedL;
      lastSpeedR = speedR;
      //setScopeChannel(0, (int)pwmrl);
      //setScopeChannel(1, (int)speedL);
    #endif

    #ifdef CONTROL_ADC
      //adccmd1 = adccmd1 * 0.9 + (float)adc_buffer.l_rx2 * 0.1; // throttle
      adccmd2 = adccmd2 * 0.9 + (float)adc_buffer.l_tx2 * 0.1; // button

      pwmrl = pwmrl * 0.9 + (CLAMP(adc_buffer.l_rx2 - 700, 0, 2350) / 2.35) * 0.1 * direction;
      // pwmrl has to be 0-1000 (or negative when driving backwards)

      setScopeChannel(0, (int)adccmd1);
      setScopeChannel(1, (int)adccmd2);

      // adccmd2 = button, ranges 0 in idle and 4096 when pressed
      if (adccmd2 > 2000 && pwmrl < 300) { // driving backwards at low speeds
        direction = -0.2;
      } else {
        direction = 1;
      }

      if (adccmd2 > 2000 && pwmrl > 700) { // field weakening at high speeds
        weakl = pwmrl - 600; // weak should never exceed 400 or 450 MAX!!
        weakr = pwmrl - 600;
      } else {
        weakl = 0;
        weakr = 0;
      }

      if (pwml < 1000) {
        pwml +=1;
      }

      pwml = pwmrl;
      pwmr = -pwmrl;
    #endif

    consoleScope();

    timeout=0;

    if (HAL_GPIO_ReadPin(BUTTON_PORT, BUTTON_PIN)) {
      enable = 0;
      while (HAL_GPIO_ReadPin(BUTTON_PORT, BUTTON_PIN)) {}
      buzzerFreq = 0;
      buzzerPattern = 0;
      for (int i = 0; i < 8; i++) {
        buzzerFreq = i;
        HAL_Delay(100);
      }
      HAL_GPIO_WritePin(OFF_PORT, OFF_PIN, 0);
      while(1) {}
    }

    if (batteryVoltage < 36.0 && batteryVoltage > 33.0) {
      buzzerFreq = 5;
      buzzerPattern = 8;
    } else if  (batteryVoltage < 33.0 && batteryVoltage > 30.0) {
      buzzerFreq = 5;
      buzzerPattern = 1;
    } else if  (batteryVoltage < 30.0) {
      buzzerPattern = 0;
      enable = 0;
      for (int i = 0; i < 8; i++) {
        buzzerFreq = i;
        HAL_Delay(100);
      }
      HAL_GPIO_WritePin(OFF_PORT, OFF_PIN, 0);
      while(1) {}
    } else {
      buzzerFreq = 0;
      buzzerPattern = 0;
    }
  }
}

/** System Clock Configuration
*/
void SystemClock_Config(void) {
  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_PeriphCLKInitTypeDef PeriphClkInit;

  /**Initializes the CPU, AHB and APB busses clocks
    */
  RCC_OscInitStruct.OscillatorType      = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState            = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState        = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource       = RCC_PLLSOURCE_HSI_DIV2;
  RCC_OscInitStruct.PLL.PLLMUL          = RCC_PLL_MUL16;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  /**Initializes the CPU, AHB and APB busses clocks
    */
  RCC_ClkInitStruct.ClockType      = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource   = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider  = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2);

  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection    = RCC_ADCPCLK2_DIV8;
  HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit);

  /**Configure the Systick interrupt time
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq() / 1000);

  /**Configure the Systick
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}
