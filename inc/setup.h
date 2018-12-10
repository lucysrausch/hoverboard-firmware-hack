/*
* This file is part of the hoverboard-firmware-hack project.
*
* Copyright (C) 2017-2018 Rene Hopf <renehopf@mac.com>
* Copyright (C) 2017-2018 Nico Stute <crinq@crinq.de>
* Copyright (C) 2017-2018 Niklas Fauth <niklas.fauth@kit.fail>
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

#pragma once

#include "config.h"
#include "stm32f1xx_hal.h"

void MX_GPIO_Init(void);
void MX_TIM_Init(void);
void MX_ADC1_Init(void);
void MX_ADC2_Init(void);
void USART2_IT_init();
void USART3_IT_init();
void UART2_Init();
void UART3_Init();

#if defined(CONTROL_NUNCHUCK)
  void Nunchuck_Read();     // defined in control.c
  void Nunchuck_Init();     // defined in control.c
  void I2C_Init();          // defined in setup.c
#endif

#ifdef SOFTWATCHDOG_TIMEOUT
  void MX_TIM3_Softwatchdog_Init(void);
  extern TIM_HandleTypeDef htim3;
#endif