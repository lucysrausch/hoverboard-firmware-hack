#pragma once
#include "stm32f1xx_hal.h"

#define PWM_FREQ         16000     // PWM frequency in Hz
#define DEAD_TIME        32        // PWM deadtime
#define DC_CUR_LIMIT     1         // Motor DC current limit in amps
#define PPM_NUM_CHANNELS 6         // number of PPM channels to receive
#define VBAT_ADC_TO_UV (25532)  //25532 uV per ADC count
#define ADC_BATTERY_VOLT   0.026474

//do not change, deducted from other settings
#define DC_CUR_THRESHOLD  (DC_CUR_LIMIT*50) // x50 = /0.02 (old MOTOR_AMP_CONV_DC_AMP)


