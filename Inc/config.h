#pragma once
#include "stm32f1xx_hal.h"

// ############################### DO-NOT-TOUCH SETTINGS ###############################

#define PWM_FREQ         16000      // PWM frequency in Hz
#define DEAD_TIME        32         // PWM deadtime

#define DELAY_IN_MAIN_LOOP 5        // in ms. default 5. it is independent of all the timing critical stuff. do not touch if you do not know what you are doing.

#define TIMEOUT          5          // number of wrong / missing input commands before emergency off
#define SERIAL_START_FRAME  0xABCD  // [-] Start frame definition for serial commands
#define SERIAL_TIMEOUT      160     // [-] Serial timeout duration for the received data. 160 ~= 0.8 sec. Calculation: 0.8 sec / 0.005 sec
#define SERIAL_BUFFER_SIZE  64      // [bytes] Size of Serial Rx buffer. Make sure it is always larger than the structure size

// ############################### GENERAL ###############################

// How to calibrate: connect GND and RX of a 3.3v uart-usb adapter to the right sensor board cable (be careful not to use the red wire of the cable. 15v will destroy everything.). if you are using nunchuck, disable it temporarily. enable DEBUG_SERIAL_USART3 and DEBUG_SERIAL_ASCII use asearial terminal.

// Battery voltage calibration: connect power source. see <How to calibrate>. write value nr 5 to BAT_CALIB_ADC. make and flash firmware. then you can verify voltage on value 6 (devide it by 100.0 to get calibrated voltage).
#define BAT_CALIB_REAL_VOLTAGE        43.0       // input voltage measured by multimeter  
#define BAT_CALIB_ADC                 1704       // adc-value measured by mainboard (value nr 5 on UART debug output)

#define BAT_NUMBER_OF_CELLS     10        // normal Hoverboard battery: 10s
#define BAT_LOW_LVL1_ENABLE     0         // to beep or not to beep, 1 or 0
#define BAT_LOW_LVL1            3.6       // gently beeps at this voltage level. [V/cell]
#define BAT_LOW_LVL2_ENABLE     1         // to beep or not to beep, 1 or 0
#define BAT_LOW_LVL2            3.5       // your battery is almost empty. Charge now! [V/cell]
#define BAT_LOW_DEAD            3.37      // undervoltage poweroff. (while not driving) [V/cell]

#define DC_CUR_LIMIT     15         // DC current limit in amps per motor. so 15 means it will draw 30A out of your battery. it does not disable motors, it is a soft current limit.

// Board overheat detection: the sensor is inside the STM/GD chip. it is very inaccurate without calibration (up to 45°C). so only enable this funcion after calibration! let your board cool down. see <How to calibrate>. get the real temp of the chip by thermo cam or another temp-sensor taped on top of the chip and write it to TEMP_CAL_LOW_DEG_C. write debug value 8 to TEMP_CAL_LOW_ADC. drive around to warm up the board. it should be at least 20°C warmer. repeat it for the HIGH-values. enable warning and/or poweroff and make and flash firmware.
#define TEMP_CAL_LOW_ADC        1655      // temperature 1: ADC value
#define TEMP_CAL_LOW_DEG_C      35.8      // temperature 1: measured temperature [°C]
#define TEMP_CAL_HIGH_ADC       1588      // temperature 2: ADC value
#define TEMP_CAL_HIGH_DEG_C     48.9      // temperature 2: measured temperature [°C]
#define TEMP_WARNING_ENABLE     0         // to beep or not to beep, 1 or 0, DO NOT ACTIVITE WITHOUT CALIBRATION!
#define TEMP_WARNING            60        // annoying fast beeps [°C]
#define TEMP_POWEROFF_ENABLE    0         // to poweroff or not to poweroff, 1 or 0, DO NOT ACTIVITE WITHOUT CALIBRATION!
#define TEMP_POWEROFF           65        // overheat poweroff. (while not driving) [°C]

#define INACTIVITY_TIMEOUT 8        // minutes of not driving until poweroff. it is not very precise.

// ############################### LCD DEBUG ###############################

//#define DEBUG_I2C_LCD             // standard 16x2 or larger text-lcd via i2c-converter on right sensor board cable

// ############################### SERIAL DEBUG ###############################

#define DEBUG_SERIAL_USART3         // right sensor board cable, disable if I2C (nunchuck or lcd) is used!
#if defined(DEBUG_SERIAL_USART2)
  #define USART2_BAUD    115200     // UART baud rate
#elif defined(DEBUG_SERIAL_USART3)
  #define USART3_BAUD    115200     // UART baud rate
#endif
//#define DEBUG_SERIAL_SERVOTERM      // Software for plotting graphs: https://github.com/STMBL/Servoterm-app
#define DEBUG_SERIAL_ASCII          // "1:345 2:1337 3:0 4:0 5:0 6:0 7:0 8:0\r\n"

// ############################### INPUT ###############################

// ###### CONTROL VIA UART (serial) ######
//#define CONTROL_SERIAL_USART2       // left sensor board cable, disable if ADC or PPM is used!
#if defined(CONTROL_SERIAL_USART2)
  #define USART2_BAUD    19200      // UART baud rate
#elif defined(CONTROL_SERIAL_USART3)
  #define USART3_BAUD    19200      // UART baud rate
#endif
// for Arduino, use void loop(void){ Serial.write((uint8_t *) &steer, sizeof(steer)); Serial.write((uint8_t *) &speed, sizeof(speed));delay(20); }

// ###### CONTROL VIA RC REMOTE ######
// left sensor board cable. Channel 1: steering, Channel 2: speed. Use a very short cable!
//#define CONTROL_PPM                 // use PPM-Sum as input. disable CONTROL_SERIAL_USART2!
//#define PPM_NUM_CHANNELS 6          // total number of PPM channels to receive, even if they are not used.

// ###### CONTROL VIA TWO POTENTIOMETERS ######
// ADC-calibration to cover the full poti-range: connect potis to left sensor board cable (0 to 3.3V) (do NOT use the red 15V wire in the cable!). see <How to calibrate>. turn the potis to minimum position, write value 1 to ADC1_MIN and value 2 to ADC2_MIN. turn to maximum position and repeat it for ADC?_MAX. make, flash and test it.
//#define CONTROL_ADC                 // use ADC as input. disable CONTROL_SERIAL_USART2!
#define ADC1_MIN 0                // min ADC1-value while poti at minimum-position (0 - 4095)
#define ADC1_MAX 4095               // max ADC1-value while poti at maximum-position (0 - 4095)
#define ADC2_MIN 0                // min ADC2-value while poti at minimum-position (0 - 4095)
#define ADC2_MAX 4095               // max ADC2-value while poti at maximum-position (0 - 4095)

// ###### CONTROL VIA NINTENDO NUNCHUCK ######
// left sensor board cable. keep cable short, use shielded cable, use ferrits, stabalize voltage in nunchuck, use the right one of the 2 types of nunchucks, add i2c pullups. use original nunchuck. most clones does not work very well.
//#define CONTROL_NUNCHUCK            // use nunchuck as input. disable DEBUG_SERIAL_USART3!

// ###### MOTOR TEST MODE ######
// slowly move both wheels forward and backward, ignoring all inputs
#define CONTROL_MOTOR_TEST
#define CONTROL_MOTOR_TEST_MAX_SPEED 300         // sweep slowly from -MAX_SPEED to MAX_SPEED (0 - 1000)

// ############################### DRIVING BEHAVIOR ###############################

// inputs:
// - cmd1 and cmd2: analog normalized input values. -1000 to 1000
// - button1 and button2: digital input values. 0 or 1
// - adc_buffer.l_tx2 and adc_buffer.l_rx2: unfiltered ADC values (you do not need them). 0 to 4095
// outputs:
// - speedR and speedL: normal driving -1000 to 1000
// - weakr and weakl: field weakening for extra boost at high speed (speedR > 700 and speedL > 700). 0 to ~400

#define FILTER              0.1  // lower value == softer filter. do not use values <0.01, you will get float precision issues.
#define SPEED_COEFFICIENT   0.5  // higher value == stronger. 0.0 to ~2.0?
#define STEER_COEFFICIENT   0.5  // higher value == stronger. if you do not want any steering, set it to 0.0; 0.0 to 1.0
#define INVERT_R_DIRECTION
#define INVERT_L_DIRECTION
#define BEEPS_BACKWARD 1    // 0 or 1

//Turbo boost at high speeds while button1 is pressed:
//#define ADDITIONAL_CODE \
if (button1 && speedR > 700) { /* field weakening at high speeds */ \
  weakl = cmd1 - 700; /* weak should never exceed 400 or 450 MAX!! */ \
  weakr = cmd1 - 700; } \
else { \
  weakl = 0; \
  weakr = 0; }

// ###### SIMPLE BOBBYCAR ######
// for better bobbycar code see: https://github.com/larsmm/hoverboard-firmware-hack-bbcar
// #define FILTER              0.1
// #define SPEED_COEFFICIENT   -1
// #define STEER_COEFFICIENT   0

// #define ADDITIONAL_CODE \
if (button1 && speedR < 300) { /* drive backwards */ \
  speedR = speedR * -0.2f;   \
  speedL = speedL * -0.2f; } \
else { \
  direction = 1; } \
if (button1 && speedR > 700) { /* field weakening at high speeds */ \
  weakl = speedR - 600; /* weak should never exceed 400 or 450 MAX!! */ \
  weakr = speedR - 600; } \
else { \
  weakl = 0; \
  weakr = 0; }

// ###### ARMCHAIR ######
// #define FILTER              0.05
// #define SPEED_COEFFICIENT   0.5
// #define STEER_COEFFICIENT   -0.2

// #define ADDITIONAL_CODE if (button1 && scale > 0.8) { /* field weakening at high speeds */ \
  weakl = speedL - 600; /* weak should never exceed 400 or 450 MAX!! */ \
  weakr = speedR - 600; } \
else {\
  weakl = 0;\
  weakr = 0;

// ############################### VALIDATE SETTINGS ###############################

#if defined CONTROL_SERIAL_USART2 && defined CONTROL_ADC
  #error CONTROL_ADC and CONTROL_SERIAL_USART2 not allowed. it is on the same cable.
#endif

#if defined CONTROL_SERIAL_USART2 && defined CONTROL_PPM
  #error CONTROL_PPM and CONTROL_SERIAL_USART2 not allowed. it is on the same cable.
#endif

#if defined DEBUG_SERIAL_USART3 && defined CONTROL_NUNCHUCK
  #error CONTROL_NUNCHUCK and DEBUG_SERIAL_USART3 not allowed. it is on the same cable.
#endif

#if defined DEBUG_SERIAL_USART3 && defined DEBUG_I2C_LCD
  #error DEBUG_I2C_LCD and DEBUG_SERIAL_USART3 not allowed. it is on the same cable.
#endif

#if defined(CONTROL_SERIAL_USART2) && defined(CONTROL_SERIAL_USART3)
  #error CONTROL_SERIAL_USART2 and CONTROL_SERIAL_USART3 not allowed, choose one.
#endif

#if defined(DEBUG_SERIAL_USART2) && defined(DEBUG_SERIAL_USART3)
  #error DEBUG_SERIAL_USART2 and DEBUG_SERIAL_USART3 not allowed, choose one.
#endif

#ifdef CONTROL_SERIAL_USART2
  #if defined CONTROL_DEFINED
    #error select exactly 1 input method in config.h!
  #endif
  #define CONTROL_DEFINED
#endif

#ifdef CONTROL_SERIAL_USART3
  #if defined CONTROL_DEFINED
    #error select exactly 1 input method in config.h!
  #endif
  #define CONTROL_DEFINED
#endif

#ifdef CONTROL_PPM
  #if defined CONTROL_DEFINED
    #error select exactly 1 input method in config.h!
  #endif
  #define CONTROL_DEFINED
#endif

#ifdef CONTROL_ADC
  #if defined CONTROL_DEFINED
    #error select exactly 1 input method in config.h!
  #endif
  #define CONTROL_DEFINED
#endif

#ifdef CONTROL_NUNCHUCK
  #if defined CONTROL_DEFINED
    #error select exactly 1 input method in config.h!
  #endif
  #define CONTROL_DEFINED
#endif

#ifdef CONTROL_MOTOR_TEST
  #if defined CONTROL_DEFINED
    #error select exactly 1 input method in config.h!
  #endif
  #define CONTROL_DEFINED
#endif

#ifndef CONTROL_DEFINED
  #error select exactly 1 input method in config.h!
#endif
