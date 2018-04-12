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
#include "defines.h"
#include "config.h"

TIM_HandleTypeDef htim_right;
TIM_HandleTypeDef htim_left;
ADC_HandleTypeDef hadc1;
ADC_HandleTypeDef hadc2;
volatile adc_buf_t adc_buffer;

void MX_GPIO_Init(void) {
  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();

  //general GPIO struct init
  GPIO_InitStruct.Pull  = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

  //Digital Input pins
  GPIO_InitStruct.Mode  = GPIO_MODE_INPUT;

  GPIO_InitStruct.Pin = LEFT_HALL_U_PIN;
  HAL_GPIO_Init(LEFT_HALL_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = LEFT_HALL_V_PIN;
  HAL_GPIO_Init(LEFT_HALL_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = LEFT_HALL_W_PIN;
  HAL_GPIO_Init(LEFT_HALL_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = RIGHT_HALL_U_PIN;
  HAL_GPIO_Init(RIGHT_HALL_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = RIGHT_HALL_V_PIN;
  HAL_GPIO_Init(RIGHT_HALL_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = RIGHT_HALL_W_PIN;
  HAL_GPIO_Init(RIGHT_HALL_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = CHARGER_PIN;
  HAL_GPIO_Init(CHARGER_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = BUTTON_PIN;
  HAL_GPIO_Init(BUTTON_PORT, &GPIO_InitStruct);


  //output push-pull pins
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;

  GPIO_InitStruct.Pin = LED_PIN;
  HAL_GPIO_Init(LED_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = BUZZER_PIN;
  HAL_GPIO_Init(BUZZER_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = OFF_PIN;
  HAL_GPIO_Init(OFF_PORT, &GPIO_InitStruct);


  //analog IO pins
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;

  //Current / Phase sense and battery measurements
  GPIO_InitStruct.Pin = LEFT_DC_CUR_PIN;
  HAL_GPIO_Init(LEFT_DC_CUR_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = LEFT_U_CUR_PIN;
  HAL_GPIO_Init(LEFT_U_CUR_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = LEFT_V_CUR_PIN;
  HAL_GPIO_Init(LEFT_V_CUR_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = RIGHT_DC_CUR_PIN;
  HAL_GPIO_Init(RIGHT_DC_CUR_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = RIGHT_U_CUR_PIN;
  HAL_GPIO_Init(RIGHT_U_CUR_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = RIGHT_V_CUR_PIN;
  HAL_GPIO_Init(RIGHT_V_CUR_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = DCLINK_PIN;
  HAL_GPIO_Init(DCLINK_PORT, &GPIO_InitStruct);


  //alternate function push-pull
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;

  //left MTR timer HI pins
  GPIO_InitStruct.Pin = LEFT_TIM_UH_PIN;
  HAL_GPIO_Init(LEFT_TIM_UH_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = LEFT_TIM_VH_PIN;
  HAL_GPIO_Init(LEFT_TIM_VH_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = LEFT_TIM_WH_PIN;
  HAL_GPIO_Init(LEFT_TIM_WH_PORT, &GPIO_InitStruct);

  //left MTR timer LO pins
  GPIO_InitStruct.Pin = LEFT_TIM_UL_PIN;
  HAL_GPIO_Init(LEFT_TIM_UL_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = LEFT_TIM_VL_PIN;
  HAL_GPIO_Init(LEFT_TIM_VL_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = LEFT_TIM_WL_PIN;
  HAL_GPIO_Init(LEFT_TIM_WL_PORT, &GPIO_InitStruct);

  //right MTR timer HI pins
  GPIO_InitStruct.Pin = RIGHT_TIM_UH_PIN;
  HAL_GPIO_Init(RIGHT_TIM_UH_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = RIGHT_TIM_VH_PIN;
  HAL_GPIO_Init(RIGHT_TIM_VH_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = RIGHT_TIM_WH_PIN;
  HAL_GPIO_Init(RIGHT_TIM_WH_PORT, &GPIO_InitStruct);

  //right MTR timer LO pins
  GPIO_InitStruct.Pin = RIGHT_TIM_UL_PIN;
  HAL_GPIO_Init(RIGHT_TIM_UL_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = RIGHT_TIM_VL_PIN;
  HAL_GPIO_Init(RIGHT_TIM_VL_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = RIGHT_TIM_WL_PIN;
  HAL_GPIO_Init(RIGHT_TIM_WL_PORT, &GPIO_InitStruct);
}


void MX_TIM_Init(void) {
  __HAL_RCC_TIM1_CLK_ENABLE();
  __HAL_RCC_TIM8_CLK_ENABLE();

  TIM_MasterConfigTypeDef sMasterConfig;
  TIM_OC_InitTypeDef sConfigOC;
  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig;
  TIM_SlaveConfigTypeDef sTimConfig;

  htim_right.Instance               = RIGHT_TIM;
  htim_right.Init.Prescaler         = 0;
  htim_right.Init.CounterMode       = TIM_COUNTERMODE_CENTERALIGNED1;
  htim_right.Init.Period            = 64000000 / 2 / PWM_FREQ;
  htim_right.Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;
  htim_right.Init.RepetitionCounter = 0;
  htim_right.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  HAL_TIM_PWM_Init(&htim_right);

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_ENABLE;
  sMasterConfig.MasterSlaveMode     = TIM_MASTERSLAVEMODE_DISABLE;
  HAL_TIMEx_MasterConfigSynchronization(&htim_right, &sMasterConfig);

  sConfigOC.OCMode       = TIM_OCMODE_PWM1;
  sConfigOC.Pulse        = 0;
  sConfigOC.OCPolarity   = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCNPolarity  = TIM_OCNPOLARITY_LOW;
  sConfigOC.OCFastMode   = TIM_OCFAST_DISABLE;
  sConfigOC.OCIdleState  = TIM_OCIDLESTATE_RESET;
  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_SET;
  HAL_TIM_PWM_ConfigChannel(&htim_right, &sConfigOC, TIM_CHANNEL_1);
  HAL_TIM_PWM_ConfigChannel(&htim_right, &sConfigOC, TIM_CHANNEL_2);
  HAL_TIM_PWM_ConfigChannel(&htim_right, &sConfigOC, TIM_CHANNEL_3);

  sBreakDeadTimeConfig.OffStateRunMode  = TIM_OSSR_ENABLE;
  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_ENABLE;
  sBreakDeadTimeConfig.LockLevel        = TIM_LOCKLEVEL_OFF;
  sBreakDeadTimeConfig.DeadTime         = DEAD_TIME;
  sBreakDeadTimeConfig.BreakState       = TIM_BREAK_DISABLE;
  sBreakDeadTimeConfig.BreakPolarity    = TIM_BREAKPOLARITY_LOW;
  sBreakDeadTimeConfig.AutomaticOutput  = TIM_AUTOMATICOUTPUT_DISABLE;
  HAL_TIMEx_ConfigBreakDeadTime(&htim_right, &sBreakDeadTimeConfig);

  htim_left.Instance               = LEFT_TIM;
  htim_left.Init.Prescaler         = 0;
  htim_left.Init.CounterMode       = TIM_COUNTERMODE_CENTERALIGNED1;
  htim_left.Init.Period            = 64000000 / 2 / PWM_FREQ;
  htim_left.Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;
  htim_left.Init.RepetitionCounter = 0;
  htim_left.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  HAL_TIM_PWM_Init(&htim_left);

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_UPDATE;
  sMasterConfig.MasterSlaveMode     = TIM_MASTERSLAVEMODE_ENABLE;
  HAL_TIMEx_MasterConfigSynchronization(&htim_left, &sMasterConfig);

  sTimConfig.InputTrigger = TIM_TS_ITR0;
  sTimConfig.SlaveMode    = TIM_SLAVEMODE_GATED;
  HAL_TIM_SlaveConfigSynchronization(&htim_left, &sTimConfig);

  sConfigOC.OCMode       = TIM_OCMODE_PWM1;
  sConfigOC.Pulse        = 0;
  sConfigOC.OCPolarity   = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCNPolarity  = TIM_OCNPOLARITY_LOW;
  sConfigOC.OCFastMode   = TIM_OCFAST_DISABLE;
  sConfigOC.OCIdleState  = TIM_OCIDLESTATE_RESET;
  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_SET;
  HAL_TIM_PWM_ConfigChannel(&htim_left, &sConfigOC, TIM_CHANNEL_1);
  HAL_TIM_PWM_ConfigChannel(&htim_left, &sConfigOC, TIM_CHANNEL_2);
  HAL_TIM_PWM_ConfigChannel(&htim_left, &sConfigOC, TIM_CHANNEL_3);

  sBreakDeadTimeConfig.OffStateRunMode  = TIM_OSSR_ENABLE;
  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_ENABLE;
  sBreakDeadTimeConfig.LockLevel        = TIM_LOCKLEVEL_OFF;
  sBreakDeadTimeConfig.DeadTime         = DEAD_TIME;
  sBreakDeadTimeConfig.BreakState       = TIM_BREAK_DISABLE;
  sBreakDeadTimeConfig.BreakPolarity    = TIM_BREAKPOLARITY_LOW;
  sBreakDeadTimeConfig.AutomaticOutput  = TIM_AUTOMATICOUTPUT_DISABLE;
  HAL_TIMEx_ConfigBreakDeadTime(&htim_left, &sBreakDeadTimeConfig);

  LEFT_TIM->BDTR &= ~TIM_BDTR_MOE;
  RIGHT_TIM->BDTR &= ~TIM_BDTR_MOE;

  HAL_TIM_PWM_Start(&htim_left, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim_left, TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim_left, TIM_CHANNEL_3);
  HAL_TIMEx_PWMN_Start(&htim_left, TIM_CHANNEL_1);
  HAL_TIMEx_PWMN_Start(&htim_left, TIM_CHANNEL_2);
  HAL_TIMEx_PWMN_Start(&htim_left, TIM_CHANNEL_3);

  HAL_TIM_PWM_Start(&htim_right, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim_right, TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim_right, TIM_CHANNEL_3);
  HAL_TIMEx_PWMN_Start(&htim_right, TIM_CHANNEL_1);
  HAL_TIMEx_PWMN_Start(&htim_right, TIM_CHANNEL_2);
  HAL_TIMEx_PWMN_Start(&htim_right, TIM_CHANNEL_3);

  htim_left.Instance->RCR = 1;

  __HAL_TIM_ENABLE(&htim_right);
}


/* ADC1 init function */
void MX_ADC1_Init(void) {
  ADC_MultiModeTypeDef multimode;
  ADC_ChannelConfTypeDef sConfig;

  __HAL_RCC_ADC1_CLK_ENABLE();

  hadc1.Instance                   = ADC1;
  hadc1.Init.ScanConvMode          = ADC_SCAN_ENABLE;
  hadc1.Init.ContinuousConvMode    = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConv      = ADC_EXTERNALTRIGCONV_T8_TRGO;
  hadc1.Init.DataAlign             = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion       = 4;
  HAL_ADC_Init(&hadc1);

  /**Enable or disable the remapping of ADC1_ETRGREG:
    * ADC1 External Event regular conversion is connected to TIM8 TRG0
    */
  __HAL_AFIO_REMAP_ADC1_ETRGREG_ENABLE();

  //Configure the ADC multi-mode
  multimode.Mode = ADC_DUALMODE_REGSIMULT;
  HAL_ADCEx_MultiModeConfigChannel(&hadc1, &multimode);

  sConfig.SamplingTime = ADC_SAMPLETIME_7CYCLES_5;

  sConfig.Channel = ADC_CHANNEL_14; //right motor phase B sense
  sConfig.Rank    = 1;
  HAL_ADC_ConfigChannel(&hadc1, &sConfig);

  sConfig.Channel = ADC_CHANNEL_0; //left motor phase A sense
  sConfig.Rank    = 2;
  HAL_ADC_ConfigChannel(&hadc1, &sConfig);

  sConfig.SamplingTime = ADC_SAMPLETIME_13CYCLES_5;

  sConfig.Channel = ADC_CHANNEL_11; //right motor shunt current
  sConfig.Rank    = 3;
  HAL_ADC_ConfigChannel(&hadc1, &sConfig);

  sConfig.Channel = ADC_CHANNEL_12; //v-battery
  sConfig.Rank    = 4;
  HAL_ADC_ConfigChannel(&hadc1, &sConfig);

  hadc1.Instance->CR2 |= ADC_CR2_DMA;

  __HAL_ADC_ENABLE(&hadc1);

  __HAL_RCC_DMA1_CLK_ENABLE();

  DMA1_Channel1->CCR   = 0;
  DMA1_Channel1->CNDTR = 4;
  DMA1_Channel1->CPAR  = (uint32_t)&(ADC1->DR);
  DMA1_Channel1->CMAR  = (uint32_t)&adc_buffer;

  //ADC DMA settings:
  //Mem size 32-bit,
  //Peripheral size 32-bit, I
  //Increment memory address,
  //Circular operation,
  //Peripheral-to-memory
  //Transfer complete interrupt
  //Priority level high
  DMA1_Channel1->CCR   = DMA_CCR_MSIZE_1 | DMA_CCR_PSIZE_1 | DMA_CCR_MINC | DMA_CCR_CIRC | DMA_CCR_TCIE | DMA_CCR_PL_1;
  DMA1_Channel1->CCR |= DMA_CCR_EN;

  HAL_NVIC_SetPriority(DMA1_Channel1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel1_IRQn);
}


/* ADC2 init function */
void MX_ADC2_Init(void) {
  ADC_ChannelConfTypeDef sConfig;

  __HAL_RCC_ADC2_CLK_ENABLE();

  hadc2.Instance                   = ADC2;
  hadc2.Init.ScanConvMode          = ADC_SCAN_ENABLE;
  hadc2.Init.ContinuousConvMode    = DISABLE;
  hadc2.Init.DiscontinuousConvMode = DISABLE;
  hadc2.Init.ExternalTrigConv      = ADC_SOFTWARE_START;
  hadc2.Init.DataAlign             = ADC_DATAALIGN_RIGHT;
  hadc2.Init.NbrOfConversion       = 4;
  HAL_ADC_Init(&hadc2);

  sConfig.SamplingTime = ADC_SAMPLETIME_7CYCLES_5;

  sConfig.Channel = ADC_CHANNEL_15; //right motor phace C sense
  sConfig.Rank    = 1;
  HAL_ADC_ConfigChannel(&hadc2, &sConfig);

  sConfig.Channel = ADC_CHANNEL_13; //left motor phace B sense
  sConfig.Rank    = 2;
  HAL_ADC_ConfigChannel(&hadc2, &sConfig);

  sConfig.SamplingTime = ADC_SAMPLETIME_13CYCLES_5;

  sConfig.Channel = ADC_CHANNEL_10; //left motor shunt current
  sConfig.Rank    = 3;
  HAL_ADC_ConfigChannel(&hadc2, &sConfig);

  sConfig.Channel = ADC_CHANNEL_TEMPSENSOR; //internal temperature
  sConfig.Rank    = 4;
  HAL_ADC_ConfigChannel(&hadc2, &sConfig);

  hadc2.Instance->CR2 |= ADC_CR2_DMA;
  __HAL_ADC_ENABLE(&hadc2);
}
