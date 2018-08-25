#pragma once

#ifndef SENSORCOMS_H
#define SENSORCOMS_H


#include "stm32f1xx_hal.h"
#include "config.h"

/////////////////////////////////////////////////////////////////////////////////////
// this file encapsulates coms with the original sensor boards
// these use the 9 bit USART mode, sending 0x100 to signal the start of a comms frame
/////////////////////////////////////////////////////////////////////////////////////



#ifdef CONTROL_SENSOR

#pragma pack(push, 1)

// bytes send from sensor board
typedef struct tag_sensor_data{
  short Angle;
  short Angle_duplicate;
  unsigned char AA_55;
  unsigned char Accelleration;
  unsigned char Accelleration_duplicate;
  short Roll;
  unsigned char header_00; // this byte gets 0x100 (9 bit serial)
} SENSOR_DATA;

// bytes send to sensor.
// must be sent twice to take effect if other serial is on the same line
typedef struct tag_sensor_lights {
  unsigned char unknown;
  unsigned char flashcount; // non zero-> red flash number of times with pause
  unsigned char unknown1;
  unsigned char unknown2;
  unsigned char unknown3;
  unsigned char colour; // this byte gets bit 8 set (on 9 bit serial);
} SENSOR_LIGHTS;

#pragma pack(pop)


// bit masks for colour
#define SENSOR_COLOUR_OFF 0x0 // headlamp is on always?
#define SENSOR_COLOUR_HEADLAMP_FLASH 0x1 // IR foot detectors must be closed
#define SENSOR_COLOUR_ORANGE 0x2
#define SENSOR_COLOUR_GREEN 0x4
#define SENSOR_COLOUR_RED 0x8
#define SENSOR_COLOUR_NO_HEADLIGHTS 0x10 // suppress headlamp.
#define SENSOR_COLOUR_YELLOW (SENSOR_COLOUR_RED | SENSOR_COLOUR_GREEN)


/////////////////////////////////////////////////////////
// functions to use.
void USART_init_sensor_comms();
int  USART_sensorSend(int port, unsigned char *data, int len, int startframe);
short USART_sensor_getrx(int port);
int USART_sensor_rxcount(int port);
int USART_sensor_txcount(int port);
/////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////
// internal functions
void USART_init_sensor_port_USART2();
void USART_init_sensor_port_USART3();
int  USART_sensor_starttx(int port);
void USART_sensor_addRXshort(int port, unsigned short value);
short USART_sensor_getTXshort(int port);
void USART_sensor_addTXshort(int port, unsigned short value);

void myIRQ(int port, USART_TypeDef *us);
void USART2_IRQHandler(void);
void USART3_IRQHandler(void);
/////////////////////////////////////////////////////////

#else // end if CONTROL_SENSOR
#endif

#endif