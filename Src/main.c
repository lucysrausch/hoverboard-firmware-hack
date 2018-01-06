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

#include "main.h"
#include "stm32f1xx_hal.h"
#include "defines.h"
#include "gpio.h"

void SystemClock_Config(void);

extern TIM_HandleTypeDef htim_left;
extern TIM_HandleTypeDef htim_right;
extern ADC_HandleTypeDef hadc1;
extern ADC_HandleTypeDef hadc2;
extern volatile adc_buf_t adc_buffer[3];

volatile int posl = 0;
volatile int posr = 0;
volatile int pwml = 0;
volatile int pwmr = 0;

const int pwm_res = 64000000 / 2 / PWM_FREQ;

const uint8_t hall_to_pos[8] = {
  0,
  0,
  2,
  1,
  4,
  5,
  3,
  0,
};

inline void block(int pwm, int pos, int* u, int* v, int* w){
    switch(pos){
    case 0:
      *u = 0;
      *v = pwm;
      *w = -pwm;
      break;
    case 1:
      *u = -pwm;
      *v = pwm;
      *w = 0;
      break;
    case 2:
      *u = -pwm;
      *v = 0;
      *w = pwm;
      break;
    case 3:
      *u = 0;
      *v = -pwm;
      *w = pwm;
      break;
    case 4:
      *u = pwm;
      *v = -pwm;
      *w = 0;
      break;
    case 5:
      *u = pwm;
      *v = 0;
      *w = -pwm;
      break;
    default:
      *u = 0;
      *v = 0;
      *w = 0;
  }
}

int last_pos = 0;
int timer = 0;
int max_time = PWM_FREQ / 10;
volatile int vel = 0;

void DMA1_Channel1_IRQHandler(){
  DMA1->IFCR = DMA_IFCR_CTCIF1;
  HAL_GPIO_WritePin(LED_PORT, LED_PIN, 1);

  int ul = 0;
  int vl = 0;
  int wl = 0;

  int ur = 0;
  int vr = 0;
  int wr = 0;

  uint8_t hall_ul = HAL_GPIO_ReadPin(LEFT_HALL_U_PORT, LEFT_HALL_U_PIN);
  uint8_t hall_vl = HAL_GPIO_ReadPin(LEFT_HALL_V_PORT, LEFT_HALL_V_PIN);
  uint8_t hall_wl = HAL_GPIO_ReadPin(LEFT_HALL_W_PORT, LEFT_HALL_W_PIN);

  uint8_t hall_ur = HAL_GPIO_ReadPin(RIGHT_HALL_U_PORT, RIGHT_HALL_U_PIN);
  uint8_t hall_vr = HAL_GPIO_ReadPin(RIGHT_HALL_V_PORT, RIGHT_HALL_V_PIN);
  uint8_t hall_wr = HAL_GPIO_ReadPin(RIGHT_HALL_W_PORT, RIGHT_HALL_W_PIN);

  uint8_t halll = hall_ul * 1 + hall_vl * 2 + hall_wl * 4;
  posl = hall_to_pos[halll];
  posl += 2;
  posl %= 6;

  uint8_t hallr = hall_ur * 1 + hall_vr * 2 + hall_wr * 4;
  posr = hall_to_pos[hallr];
  posr += 2;
  posr %= 6;

  timer++;

  // if(timer > max_time){
  //   timer = max_time;
  //   vel = 0;
  // }

  // if(pos != last_pos){
  //   vel = 1000 * PWM_FREQ / timer / P / 6 * 2;

  //   if((pos - last_pos + 6) % 6 > 2){
  //     vel = -vel;
  //   }

  //   timer = 0;
  // }
  // last_pos = pos;
  
  block(pwml, posl, &ul, &vl, &wl);
  block(pwmr, posr, &ur, &vr, &wr);


  LEFT_TIM->LEFT_TIM_U = CLAMP(ul + pwm_res / 2, 0, pwm_res);
  LEFT_TIM->LEFT_TIM_V = CLAMP(vl + pwm_res / 2, 0, pwm_res);
  LEFT_TIM->LEFT_TIM_W = CLAMP(wl + pwm_res / 2, 0, pwm_res);

  RIGHT_TIM->RIGHT_TIM_U = CLAMP(ur + pwm_res / 2, 0, pwm_res);
  RIGHT_TIM->RIGHT_TIM_V = CLAMP(vr + pwm_res / 2, 0, pwm_res);
  RIGHT_TIM->RIGHT_TIM_W = CLAMP(wr + pwm_res / 2, 0, pwm_res);

HAL_GPIO_WritePin(LED_PORT, LED_PIN, 0);
}

int milli_vel_error_sum = 0;

int main(void)
{

  HAL_Init();

  SystemClock_Config();

 
  __HAL_RCC_DMA1_CLK_DISABLE();
  MX_GPIO_Init();
  MX_TIM_Init();
  MX_ADC1_Init();
  MX_ADC2_Init();

  
  HAL_GPIO_WritePin(OFF_PORT, OFF_PIN, 1);
  
  HAL_ADC_Start(&hadc1);
  HAL_ADC_Start(&hadc2);

  while (1)
  {
    HAL_Delay(0);
    // int milli_cur = 3000;
    // int milli_volt = milli_cur * MILLI_R / 1000;// + vel * MILLI_PSI * 141;
    // // pwm = milli_volt * pwm_res / MILLI_V;

    // int milli_vel_cmd = 200;
    // int milli_vel_error = milli_vel_cmd - vel;
    // milli_vel_error_sum += milli_vel_error;
    // milli_vel_error_sum = CLAMP(milli_vel_error_sum, -200000, 200000);
    // pwm = CLAMP(milli_vel_cmd / 5 + milli_vel_error_sum / 200, -500, 500);
    pwml = 100;
    pwmr = 100;

    // if(vel > milli_vel_cmd){
    //   HAL_GPIO_WritePin(LED_PORT, LED_PIN, 1);
    // }
    // else{
    //   HAL_GPIO_WritePin(LED_PORT, LED_PIN, 0);
    // }
  }
}

/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_PeriphCLKInitTypeDef PeriphClkInit;

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI_DIV2;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL16;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV8;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void _Error_Handler(char * file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1) 
  {
  }
  /* USER CODE END Error_Handler_Debug */ 
}

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif
