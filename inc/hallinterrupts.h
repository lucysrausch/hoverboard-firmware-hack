/*
* This file is part of the hoverboard-firmware-hack project.
*
* Copyright (C) 2018 Simon Hailes <btsimonh@googlemail.com>
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
#ifndef HALLINTERRUPTS_H
#define HALLINTERRUPTS_H

#include "config.h"

#ifdef HALL_INTERRUPTS

#include "defines.h"

#define HALL_PIN_MASK (LEFT_HALL_U_PIN | LEFT_HALL_V_PIN | LEFT_HALL_W_PIN | RIGHT_HALL_U_PIN | RIGHT_HALL_V_PIN | RIGHT_HALL_W_PIN)

//////////////////////////////////////////////////////////////
// change to change speed output value
#define HALL_SPEED_CALIBRATION 256000.0
// 10khz timer
#define HALL_INTERRUPT_TIMER_FREQ 100000

#define HALL_POSN_PER_REV 90
#define DEFAULT_WHEEL_SIZE_INCHES 6.5

//////////////////////////////////////////////////////////////
// this is the Hall data we gather, and can be read elsewhere
// one for each wheel
typedef struct tag_HALL_DATA_STRUCT{
    long HallPosn; // 90 per revolution
    long HallSpeed; // speed part calibrated to speed demand value

    float HallPosnMultiplier; // m per hall segment

    long HallPosn_mm; // posn in mm
    long HallPosn_mm_lastread; // posn offset set via protocol in mm
    long HallSpeed_mm_per_s; // speed in m/s

    unsigned long HallTimeDiff;
    unsigned long HallSkipped;
} HALL_DATA_STRUCT;
extern volatile HALL_DATA_STRUCT HallData[2];


////////////////////////////////////////////////////////////////////////////
// the one and only function we need to call to start it gathering Hall data
void HallInterruptinit(void);

// functions you can call
void HallInterruptSetWheelDiameterInches(float inches);
void HallInterruptSetWheelDiameterMM(float mm);
void HallInterruptReset();


// interrupt routine
void HallInterruptsInterrupt(void);


////////////////////////////////////////////////////////////////////////////
// it may be useful to read the current position and zero it at the same time
// this function provides this as an option, as well as getting a single
// snapshot with interrupts disabled
typedef struct tag_HALL_POSN {
    struct {
        int HallPosn; // 90 per revolution
        int HallSpeed; // speed part calibrated to speed demand value
        int HallPosn_mm; // posn in m
        int HallSpeed_mm_per_s; // speed in m/s
        unsigned long HallSkipped;
    } wheel[2];
} HALL_POSN;

void HallInterruptReadPosn( HALL_POSN *p, int Reset );


typedef struct tag_HALL_PARAMS{
    uint8_t hall_u;
    uint8_t hall_v;
    uint8_t hall_w;

    uint8_t hall;
    uint8_t last_hall;

    long long hall_time;
    long long last_hall_time;
    unsigned int timerwraps;
    unsigned int last_timerwraps;

    int incr;

    int zerospeedtimeout;

    // contant - modifies sign of calculated values
    int direction;


    int dmacount;
} HALL_PARAMS;

extern volatile HALL_DATA_STRUCT HallData[2];
extern TIM_HandleTypeDef h_timer_hall;
extern volatile HALL_PARAMS local_hall_params[2];
extern volatile long long timerwraps;


#endif

#endif