/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2017 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f1xx_hal.h"
#include "defines.h"
#include "gpio.h"


/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

extern TIM_HandleTypeDef htim_left;
extern TIM_HandleTypeDef htim_right;
extern ADC_HandleTypeDef hadc1;
extern ADC_HandleTypeDef hadc2;
extern volatile adc_buf_t adc_buffer[1];

volatile int pos = 0;
const int pwm_res = 64000000 / 2 / PWM_FREQ;

int cur = 0;
int milli_volt = 0;
volatile int pwm = 0;
uint8_t hall_to_pos[8] = {
  0,
  0,
  2,
  1,
  4,
  5,
  3,
  0,
};

int last_pos = 0;
int timer = 0;
int max_time = PWM_FREQ / 5;
volatile int vel = 0;

void DMA1_Channel1_IRQHandler(){
  DMA1->IFCR = DMA_IFCR_CTCIF1;
  int u = 0;
  int v = 0;
  int w = 0;

  uint8_t hall_u = HAL_GPIO_ReadPin(LEFT_HALL_U_PORT, LEFT_HALL_U_PIN);
  uint8_t hall_v = HAL_GPIO_ReadPin(LEFT_HALL_V_PORT, LEFT_HALL_V_PIN);
  uint8_t hall_w = HAL_GPIO_ReadPin(LEFT_HALL_W_PORT, LEFT_HALL_W_PIN);

  uint8_t hall = hall_u * 1 + hall_v * 2 + hall_w * 4;
  pos = hall_to_pos[hall];
  pos += 2;
  pos %= 6;

  timer++;

  if(timer > max_time){
    timer = max_time;
    vel = 0;
  }

  if(pos != last_pos){
    vel = 1000 * PWM_FREQ / timer / P / 6;

    if((pos - last_pos + 6) % 6 > 2){
      vel = -vel;
    }

    timer = 0;
  }
  last_pos = pos;

  switch(pos){
    case 0:
      u = 0;
      v = pwm;
      w = -pwm;
      break;
    case 1:
      u = -pwm;
      v = pwm;
      w = 0;
      break;
    case 2:
      u = -pwm;
      v = 0;
      w = pwm;
      break;
    case 3:
      u = 0;
      v = -pwm;
      w = pwm;
      break;
    case 4:
      u = pwm;
      v = -pwm;
      w = 0;
      break;
    case 5:
      u = pwm;
      v = 0;
      w = -pwm;
      break;
    default:
      u = 0;
      v = 0;
      w = 0;
  }

  LEFT_TIM->LEFT_TIM_U = CLAMP(u + pwm_res / 2, 0, pwm_res);
  LEFT_TIM->LEFT_TIM_V = CLAMP(v + pwm_res / 2, 0, pwm_res);
  LEFT_TIM->LEFT_TIM_W = CLAMP(w + pwm_res / 2, 0, pwm_res);
  // while(!(ADC1->SR & 2)){

  // }
  // while(!(DMA1->ISR & 2)){}
  // DMA1->IFCR = 1;
    
      // }
  if(adc_buffer[0].data1 > 1900){
    HAL_GPIO_WritePin(LED_PORT, LED_PIN, 1);
  }
  else{
    HAL_GPIO_WritePin(LED_PORT, LED_PIN, 0);
  }
}

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
  cur = 3;
  milli_volt = cur * MILLI_R;// + vel * MILLI_PSI * 141;
  pwm = milli_volt * pwm_res / MILLI_V;

  

  /* USER CODE BEGIN 3 */

  }
  /* USER CODE END 3 */

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

/**
  * @}
  */ 

/**
  * @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
