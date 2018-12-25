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
#pragma once

#include "config.h"

#ifdef CONTROL_SERIAL_PROTOCOL


/////////////////////////////////////////////////////////////////
// call this with received bytes; normally from main loop
void protocol_byte( unsigned char byte );
/////////////////////////////////////////////////////////////////


//// control structures used in firmware
typedef struct tag_POSN_DATA {
    // these get set
    long wanted_posn_mm[2];

    // configurations/constants
    int posn_max_speed; // max speed in this mode
    int posn_min_speed; // minimum speed (to get wheels moving)



    // just so it can be read back
    long posn_diff_mm[2];
    long posn_speed_demand[2];
} POSN_DATA;

extern POSN_DATA PosnData;

typedef struct tag_SPEED_DATA {
    // these get set
    long wanted_speed_mm_per_sec[2];

    // configurations/constants
    int speed_max_power; // max speed in this mode
    int speed_min_power; // minimum speed (to get wheels moving)
    int speed_minimum_speed; // below this, we don't ask it to do anything


    // just so it can be read back
    long speed_diff_mm_per_sec[2];
    long speed_power_demand[2];
} SPEED_DATA;

extern SPEED_DATA SpeedData;


typedef struct {
    uint8_t buzzerFreq;
    uint8_t buzzerPattern;
    uint16_t buzzerLen;
} BUZZER;

extern BUZZER Buzzer;


typedef struct {
    // both of these values are absolute values ranging from -1000 to 1000
    // base_pwm plus/minus steer is the raw PWM value
    // wether steer is added or substracted depends on the side R/L
    int16_t base_pwm;
    int16_t steer;
} PWM_STEER_CMD;

extern PWM_STEER_CMD PwmSteerCmd;


extern int control_type;
#define CONTROL_TYPE_NONE 0
#define CONTROL_TYPE_PWM 1
#define CONTROL_TYPE_MAX 2


/////////////////////////////////////////////////////////////////
// 'machine' protocol structures and definitions
//
// examples:
// ack - 02 02 41 BD
// nack - 02 02 4E B0
// test - 02 06 54 54 65 73 74 06
/////////////////////////////////////////////////////////////////

#pragma pack(push, 1)
typedef struct tag_PROTOCOL_MSG {
    unsigned char SOM; // 0x02
    unsigned char len; // len is len of ALL bytes to follow, including CS
    unsigned char bytes[254];  // variable number of data bytes, with a checksum on the end
    // checksum such that sum of bytes len to CS is zero
} PROTOCOL_MSG;

// content of 'bytes' above, for single byte commands
typedef struct tag_PROTOCOL_BYTES {
    unsigned char cmd; //
    unsigned char bytes[253];
} PROTOCOL_BYTES;


// content of 'bytes' above, for single byte commands
#define PROTOCOL_CMD_READVAL 'R'
typedef struct tag_PROTOCOL_BYTES_READVALS {
    unsigned char cmd; // 'R'
    unsigned char code; // code of value to read
} PROTOCOL_BYTES_READVALS;

#define PROTOCOL_CMD_WRITEVAL 'W'
typedef struct tag_PROTOCOL_BYTES_WRITEVALS {
    unsigned char cmd; // 'W'
    unsigned char code; // code of value to write
    unsigned char content[252]; // value to write
} PROTOCOL_BYTES_WRITEVALS;
#pragma pack(pop)

/////////////////////////////////////////////////////////
// command definitions
// ack - no payload
#define PROTOCOL_CMD_ACK 'A'
// nack - no payload
#define PROTOCOL_CMD_NACK 'N'

// a test command - normal payload - 'Test'
#define PROTOCOL_CMD_TEST 'T'
#define PROTOCOL_CMD_TESTRESPONSE 't'

// cause unit to restart - no payload
#define PROTOCOL_CMD_REBOOT 'B'

// response to an unkonwn command - maybe payload
#define PROTOCOL_CMD_UNKNOWN '?'

#define PROTOCOL_SOM 2
//
/////////////////////////////////////////////////////////////////


extern int enable_immediate;

#endif