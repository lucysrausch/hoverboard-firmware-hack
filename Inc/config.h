#pragma once
#include "stm32f1xx_hal.h"

#define R 0.27
#define P 15
#define PSI 0.02
#define V 23

#define MILLI_R (R * 1000)
#define MILLI_PSI (PSI * 1000)
#define MILLI_V (V * 1000)

// ################################################################################

#define PWM_FREQ         16000     // PWM frequency in Hz
#define DEAD_TIME        32        // PWM deadtime

#define DC_CUR_LIMIT     35         // Motor DC current limit in amps

// ################################################################################

#define DEBUG_SERIAL_USART2
//#define DEBUG_SERIAL_USART3
#define DEBUG_BAUD       115200    // UART baud rate
//#define DEBUG_SERIAL_SERVOTERM
#define DEBUG_SERIAL_ASCII
//#define DEBUG_I2C_LCD

// ################################################################################

// ###### CONTROL VIA RC REMOTE ######
//#define CONTROL_PPM                // use PPM CONTROL_PPM
//#define PPM_NUM_CHANNELS 6         // number of PPM channels to receive

// ###### CONTROL VIA TWO POTENTIOMETERS ######
// #define CONTROL_ADC

// ###### CONTROL VIA NINTENDO NUNCHUCK ######
#define CONTROL_NUNCHUCK

// ################################################################################

// ###### DRIVING BEHAVIOR ######
#define FILTER              0.1
#define SPEED_COEFFICIENT   0.5
#define STEER_COEFFICIENT   0.5

// ###### BOBBYCAR ######
// #define FILTER              0.1
// #define SPEED_COEFFICIENT   1
// #define STEER_COEFFICIENT   0

// ###### ARMCHAIR ######
// #define FILTER              0.05
// #define SPEED_COEFFICIENT   0.5
// #define STEER_COEFFICIENT   0.2

// #define BEEPS_BACKWARD
