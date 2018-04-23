/*
 * Copyright © 2011 Stéphane Raimbault <stephane.raimbault@gmail.com>
 *
 * License ISC, see LICENSE for more details.

 * This library implements the Modbus protocol.
 * http://libmodbus.org/
 *
 */

#pragma once



#include <stdint.h>

#define MODBUS_BROADCAST_ADDRESS 0

/* Protocol exceptions */
typedef enum
{
  mb_illegal_func    = 1,
  mb_illegal_address = 2,
  mb_illega_value    = 3

} mb_exception_t;

void modbusUpdate();
