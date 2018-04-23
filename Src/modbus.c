/*
 * Copyright © 2011-2012 Stéphane Raimbault <stephane.raimbault@gmail.com>
 *
 * License ISC, see LICENSE for more details.
 *
 * This library implements the Modbus protocol.
 * http://libmodbus.org/
 *
 */

#include <inttypes.h>
#include "modbus.h"
#include "cfgbus.h"
#include <string.h>

const uint8_t _slaveID = 16;

const uint32_t nb_reg = 16;
volatile uint16_t tab_reg[16];

//modbus frame header indices
enum
{
  _idx_slave    = 0,
  _idx_func     = 1,
  _idx_addr     = 2,
  _idx_reg_cnt  = 4,
  _idx_data_len = 6,
  _idx_data_start = 7
};



#define _MODBUS_RTU_PRESET_REQ_LENGTH  6
#define _MODBUS_RTU_PRESET_RSP_LENGTH  2

#define _MODBUS_RTU_CHECKSUM_LENGTH    2

#define _MODBUSINO_RTU_MAX_ADU_LENGTH  128

/* Supported function codes */
enum
{
  _fc_read_regs  = 0x03,
  _fc_write_regs = 0x10,
  _fc_invalid    = 0xFF
};

enum {
  _STEP_FUNCTION = 0x01, _STEP_META, _STEP_DATA
};

uint8_t _rcvBuff[_MODBUSINO_RTU_MAX_ADU_LENGTH] = {0};

static uint16_t crc16(uint8_t *req, uint8_t req_length) {
  uint8_t j;
  uint16_t crc;

  crc = 0xFFFF;
  while (req_length--) {
    crc = crc ^ *req++;
    for (j = 0; j < 8; j++) {
      if (crc & 0x0001)
        crc = (crc >> 1) ^ 0xA001;
      else
        crc = crc >> 1;
    }
  }

  return (crc << 8 | crc >> 8);
}

static int check_integrity(uint8_t *msg, uint8_t msg_length) {
  uint16_t crc_calculated;
  uint16_t crc_received;

  if (msg_length < 2)
    return -1;

  crc_calculated = crc16(msg, msg_length - 2);
  crc_received = (msg[msg_length - 2] << 8) | msg[msg_length - 1];

  /* Check CRC of msg */
  if (crc_calculated == crc_received) {
    return msg_length;
  } else {
    return -1;
  }
}

static int build_response_basis(uint8_t slave, uint8_t function, uint8_t* rsp) {
  rsp[0] = slave;
  rsp[1] = function;

  return _MODBUS_RTU_PRESET_RSP_LENGTH;
}

static void send_msg(uint8_t *msg, uint8_t msg_length) {
  uint16_t crc = crc16(msg, msg_length);

  msg[msg_length++] = crc >> 8;
  msg[msg_length++] = crc & 0x00FF;

  CfgWrite(msg, msg_length);
}

static uint8_t response_exception(uint8_t slave, uint8_t function,
    uint8_t exception_code, uint8_t *rsp) {
  uint8_t rsp_length;

  rsp_length = build_response_basis(slave, function + 0x80, rsp);

  /* Positive exception code */
  rsp[rsp_length++] = exception_code;

  return rsp_length;
}

static void flush(void) {
  /* Wait a moment to receive the remaining garbage but avoid getting stuck
   * because the line is saturated */
  uint32_t start = CfgTick();
  while (CfgAvailable() && CfgTick() - start < 20) {
    CfgFlushRx();
  }
}

static int receive() {

  /* We need to analyse the message step by step.
   * first get slave addres and function code (2 bytes)*/

  uint8_t length_to_read = 2;
  uint8_t rcv_index = 0;
  uint8_t step = _STEP_FUNCTION;
  uint8_t function = _fc_invalid;

  while (length_to_read != 0) {

    /* The timeout is defined to ~10 ms between each bytes */
    uint32_t start = CfgTick();
    while (!CfgAvailable() && CfgTick() - start < 10) {
      //do nothing
    }

    if (!CfgAvailable())
      return -1;

    CfgRead(&_rcvBuff[rcv_index], 1);

    /* update pointers to receive other data */
    rcv_index++;
    length_to_read--;

    if (length_to_read == 0)
    {
      switch (step)
      {
        case _STEP_FUNCTION:
          /* Function code position */
          function = _rcvBuff[_idx_func];
          if (function == _fc_read_regs)
          {
            length_to_read = 4;
          }
          else if (function == _fc_write_regs)
          {
            length_to_read = 5;
          }
          else
          {
            /* Wait a moment to receive the remaining garbage */
            flush();

            if (_rcvBuff[_idx_slave] == _slaveID ||
                _rcvBuff[_idx_slave] == MODBUS_BROADCAST_ADDRESS)
            {
              /* It's for me so send an exception (reuse req) */
              uint8_t rsp_length = response_exception(  _slaveID, function,
                                                        mb_illegal_func, _rcvBuff );
              send_msg(_rcvBuff, rsp_length);

              return -1 - mb_illegal_func;
            }

            return -1;
          }
          step = _STEP_META;
          break;

      case _STEP_META:
        length_to_read = _MODBUS_RTU_CHECKSUM_LENGTH;

        if (function == _fc_write_regs)
          length_to_read += _rcvBuff[_idx_data_len];

        if ((rcv_index + length_to_read) > _MODBUSINO_RTU_MAX_ADU_LENGTH) {
          flush();

          if (_rcvBuff[_idx_slave] == _slaveID || _rcvBuff[_idx_slave] == MODBUS_BROADCAST_ADDRESS) {
            /* It's for me so send an exception (reuse req) */
            uint8_t rsp_length = response_exception(_slaveID, function, mb_illega_value, _rcvBuff);
            send_msg(_rcvBuff, rsp_length);
            return -1 - mb_illega_value;
          }

          return -1;
        }
        step = _STEP_DATA;
        break;

      default:
        break;
      }
    }
  }

  return check_integrity(_rcvBuff, rcv_index);
}

static void reply(uint8_t req_length)
{

  //decode request header
  uint8_t  slave    = _rcvBuff[_idx_slave];
  uint8_t  function = _rcvBuff[_idx_func];
  uint16_t address  = ((uint16_t)(_rcvBuff[_idx_addr]) << 8) + _rcvBuff[_idx_addr+1];
  uint16_t nrRegs   = ((uint16_t)(_rcvBuff[_idx_reg_cnt]) << 8) + _rcvBuff[_idx_reg_cnt+1];

  uint8_t rsp[_MODBUSINO_RTU_MAX_ADU_LENGTH];
  uint8_t rsp_length = 0;

  if (slave != _slaveID && slave != MODBUS_BROADCAST_ADDRESS)
    return;

  if (address + nrRegs > nb_reg)
  {
    rsp_length = response_exception(slave, function,
    mb_illegal_address, rsp);
  }
  else
  {
    req_length -= _MODBUS_RTU_CHECKSUM_LENGTH;

    if (function == _fc_read_regs) {
      uint16_t i;

      rsp_length = build_response_basis(slave, function, rsp);
      rsp[rsp_length++] = nrRegs << 1;
      for (i = address; i < address + nrRegs; i++) {
        rsp[rsp_length++] = tab_reg[i] >> 8;
        rsp[rsp_length++] = tab_reg[i] & 0xFF;
      }
    } else {
      uint16_t i, j;

      for (i = address, j = _idx_data_start; i < address + nrRegs; i++, j += 2) {
        /* 6 and 7 = first value */
        tab_reg[i] = (uint16_t)(_rcvBuff[j] << 8) + _rcvBuff[j + 1];
      }

      rsp_length = build_response_basis(slave, function, rsp);
      /* 4 to copy the address (2) and the no. of registers */
      memcpy(rsp + rsp_length, _rcvBuff + rsp_length, 4);
      rsp_length += 4;
    }
  }

  send_msg(rsp, rsp_length);
}

int modbusUpdate() {
  int rc = 0;

  if (CfgAvailable()) {
    rc = receive();
    if (rc > 0) {
      reply(rc);
    }
  }

  /* Returns a positive value if successful,
   0 if a slave filtering has occured,
   -1 if an undefined error has occured,
   -2 for MODBUS_EXCEPTION_ILLEGAL_FUNCTION
   etc */
  return rc;
}
