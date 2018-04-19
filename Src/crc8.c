/****************************************************************************
*
*   Copyright (c) 2006 Dave Hylands     <dhylands@gmail.com>
*
*   This program is free software; you can redistribute it and/or modify
*   it under the terms of the GNU General Public License version 2 as
*   published by the Free Software Foundation.
*
*   Alternatively, this software may be distributed under the terms of BSD
*   license.
*
*   See README and COPYING for more details.
*
****************************************************************************/
/**
*
*   @file   Crc8.c
*
*   @brief  This file contains the definition of the CRC-8 algorithim
*           used by SMBus
*
*
*****************************************************************************/

/* ---- Include Files ----------------------------------------------------- */
#include "crc8.h"

/* ---- Public Variables -------------------------------------------------- */
/* ---- Private Constants and Types --------------------------------------- */
/* ---- Private Variables ------------------------------------------------- */
/* ---- Private Function Prototypes --------------------------------------- */
/* ---- Functions --------------------------------------------------------- */

/****************************************************************************/
/**
*   Calculates the CRC-8 used as part of SMBus.
*
*   CRC-8 is defined to be x^8 + x^2 + x + 1
*
*   To use this function use the following template:
*
*       crc = crc8( crc, data, len );
*/

uint8_t _crc8( uint8_t inCrc, uint8_t inData )
{
  uint8_t   data;
  data = inCrc ^ inData;

  for (uint8_t i = 0; i < 8; i++ )
  {
    if (( data & 0x80 ) != 0 )
    {
        data <<= 1;
        data ^= 0x07;
    }
    else
    {
        data <<= 1;
    }
  }

  return data;

} // _crc8

/****************************************************************************/
/**
*   Calculates the CRC-8 used as part of SMBus over a block of memory.
*/

uint8_t crc8( uint8_t crc, const uint8_t *data, uint8_t len )
{
  for(int i=0; i<len; i++)
    crc = _crc8( crc, data[i] );

  return crc;

} // crc8

/** @} */
