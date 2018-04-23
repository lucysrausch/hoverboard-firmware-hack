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


extern volatile cfg_t cfg;
const uint8_t _slaveID = 16;

#define MB_CHAR_TIMEOUT (1)  //max ms between chars
#define MB_PACKET_TIMEOUT (3)  //max ms between chars

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

#define _MB_BROADCAST_ADDR (0)

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

enum
{
  _st_idle,
  _st_header,
  _st_receive,
  _st_respond,
  _st_error
};

enum {
  _STEP_FUNCTION = 0x01, _STEP_META, _STEP_DATA
};

uint8_t _rcvBuff[_MODBUSINO_RTU_MAX_ADU_LENGTH] = {0};

uint8_t _state = _st_idle;
uint32_t _lastTick = 0;
uint32_t _lastAvailable = 0;

typedef struct
{
  uint8_t slave;
  uint8_t fcode;
  uint16_t first_reg;
  uint16_t nr_regs;
  uint8_t data_len;
} mb_hdr_t;

mb_hdr_t _hdr = {0};

static uint16_t _crc16(uint16_t crcIn, uint8_t data)
{
  uint16_t crc = crcIn ^ data;

  for (uint8_t j = 0; j < 8; j++) {
    if (crc & 0x0001)
      crc = (crc >> 1) ^ 0xA001;
    else
      crc = crc >> 1;
  }

  return crc;
}

static uint16_t crc16(uint16_t crcIn, uint8_t *data, uint8_t size) {

  uint16_t crc = crcIn;

  for(uint16_t i=0; i<size; i++)
  {
    crc = _crc16(crc,data[i]);
  }

  return crc;
}


static void send_msg(uint8_t *msg, uint8_t msg_length) {
  uint16_t crc = crc16(0xFFFF, msg, msg_length);

  msg[msg_length++] = crc >> 8;
  msg[msg_length++] = crc & 0x00FF;

  CfgWrite(msg, msg_length);
}

static void flush(void) {
  //wait until gap of pack-timeout occurs

  uint32_t loopStart = CfgTick();
  uint32_t start = 0;

  while (loopStart - CfgTick() < 30) //wait max 30ms
  {
    if(!CfgAvailable() && start == 0)
    {
      start = CfgTick();
    }
    else
    {
      CfgFlushRx();
      start = 0;
    }

    if(CfgTick() - start > MB_PACKET_TIMEOUT)
    {
      CfgFlushRx();
      break;
    }
  }

}

int valid_range(uint16_t first, uint16_t cnt)
{
  if(first+cnt > CFG_NUM_ENTRIES)
    return -1;
  else
    return 0;
}

void exception(uint8_t e, uint8_t nextState)
{
  cfg.err_cnt++;
  cfg.err_code = (cfg.err_code == cfg_ok) ? cfg_invalid_entry : cfg.err_code; //don't change until user clears

  uint8_t rsp[3];

  rsp[0] = _slaveID;
  rsp[1] = _hdr.fcode + 0x80;
  rsp[2] = e;

  send_msg(rsp,3);
  _state = nextState;
}


void inline timeout(uint8_t nextState)
{
  cfg.err_cnt++;
  cfg.err_code = (cfg.err_code == cfg_ok) ? cfg_rx_timeout : cfg.err_code; //don't change until user clears
  _state = nextState;
}

void rspHeader(uint8_t* rsp)
{
  rsp[0] = _hdr.slave;
  rsp[1] = _hdr.fcode;
  rsp[2] = (_hdr.first_reg >> 8) & 0xFF;
  rsp[3] = _hdr.first_reg & 0xFF;
  rsp[4] = (_hdr.nr_regs >> 8) & 0xFF;
  rsp[5] = _hdr.nr_regs & 0xFF;
}


int check_integrity(uint8_t *data)
{
  //build crc for header
  uint8_t hdr[6];
  rspHeader(hdr);
  uint16_t crc = crc16(0xFFFF,hdr,6);

  //continu for data if write regs
  if(_hdr.fcode == _fc_write_regs)
  {
    crc = crc16(crc,&_hdr.data_len,1);
    crc = crc16(crc,data,_hdr.data_len);
  }

  //get crc from received data (MSB first)
  uint16_t masterCrc = ((uint16_t)(data[_hdr.data_len] << 8)) + data[_hdr.data_len+1];

  return (crc == masterCrc) ? 0 : -1;
}


//const uint32_t nb_reg = 16;
//volatile uint16_t tab_reg[16];

void reg_read(uint16_t reg, uint8_t* data)
{
  data[0] = (tab_reg[reg] >> 8) & 0xff;//MSB
  data[1] = tab_reg[reg] & 0xff;
}


void reg_write(uint16_t reg, uint8_t* data)
{
  tab_reg[reg] = ((uint16_t)(data[0] << 8)) + data[1];
}

void modbusUpdate() {

  //waiting for message to be addressed to this slave
  if(_state == _st_idle && CfgAvailable())
  {
    //reset state where necessary
    _hdr.data_len  = 0;
    _lastAvailable = 0;

    CfgRead(&_hdr.slave,1); //get slave address
    if(_hdr.slave != _slaveID && _hdr.slave != _MB_BROADCAST_ADDR )
    {
      flush(); //not for me, ignore
      return;
    }

    if(_hdr.fcode != _fc_write_regs && _hdr.fcode != _fc_read_regs)
    {
      exception(mb_illegal_func, _st_idle); //unsupported function
      return;
    }

    _lastTick = CfgTick();
    _state = _st_header;
  }

  //retrieve request header
  if(_state == _st_header)
  {
    //wait for entire header before we proceed
    //0:    function code
    //1..2: first reg address
    //3..4: nr regs involved
    //5: nr write bytes (only for writes)
    if(CfgAvailable() >= 6)
    {
      uint8_t rcv[5];
      CfgRead(rcv,5);
      _hdr.fcode     = rcv[0];
      _hdr.first_reg = ((uint16_t)(rcv[1] << 8)) + rcv[2];
      _hdr.nr_regs   = ((uint16_t)(rcv[3] << 8)) + rcv[4];

      if(valid_range(_hdr.first_reg,_hdr.nr_regs) != 0)
      {
        exception(mb_illegal_address,_st_idle);
        return;
      }

      if(_hdr.fcode == _fc_write_regs)
        CfgRead(&_hdr.data_len,1);

      _lastTick = CfgTick();
      _state = _st_receive;
    }
    else if (CfgAvailable() > _lastAvailable) //new data so proceed
    {
      _lastTick = CfgTick();
      _lastAvailable = CfgAvailable();
    }
    else if (CfgTick() - _lastTick > MB_CHAR_TIMEOUT) //timed out
    {
      timeout(_st_idle);
      return;
    }
  }


  if(_state == _st_receive)
  {
    //uint32_t timeout = (CfgTick() - _lastTick > MB_CHAR_TIMEOUT) ? 1 : 0;

    if(CfgAvailable() >= _hdr.data_len + 2)
    {
      CfgRead(_rcvBuff,_hdr.data_len + 2);

      //check integrity
      if(check_integrity(_rcvBuff))
      {
        _state = _st_respond;
      }
      else
      {
        exception(mb_illega_value,_st_idle);
        return;
      }
    }
    else if (CfgAvailable() > _lastAvailable) //new data so proceed
    {
      _lastTick = CfgTick();
      _lastAvailable = CfgAvailable();
    }
    else if (CfgTick() - _lastTick > MB_CHAR_TIMEOUT) //timed out
    {
      timeout(_st_idle);
      return;
    }
  }


  if(_state == _st_respond)
  {

    //0: The Slave Address
    //1: The Function Code 16 (Preset Multiple Registers, 10 hex - 16 )
    //2..3: The Data Address of the first register.
    //4..5: The number of registers written.
    //6..7: The CRC (cyclic redundancy check) for error checking.
    if(_hdr.fcode == _fc_write_regs)
    {
      for(int i=0; i<_hdr.nr_regs; i++)
      {
        reg_write(_hdr.first_reg + i, &_rcvBuff[i*2]);
      }

      //respond
      uint8_t rsp[6];
      rspHeader(rsp);
      send_msg(rsp,6);
    }

    //    0: The Slave Address
    //    1: The Function Code 3 (read Analog Output Holding Registers)
    //    2: The number of data bytes to follow (=nr_regs*2)
    //    3..n: The contents of the registers
    //    n+1..n+2: The CRC (cyclic redundancy check).
    if(_hdr.fcode == _fc_read_regs)
    {
      _rcvBuff[0] = _hdr.slave; //reuse to save memory
      _rcvBuff[1] = _hdr.fcode;
      _rcvBuff[2] = _hdr.nr_regs * 2;

      for(int i=0; i<_hdr.nr_regs; i++)
      {
        reg_read(_hdr.first_reg + i, &_rcvBuff[3 + i*2]);
      }

      send_msg(_rcvBuff, 3 + _hdr.nr_regs * 2);
    }

  }

}
