/*
 * Copyright © 2011-2012 Stéphane Raimbault <stephane.raimbault@gmail.com>
 *
 * License ISC, see LICENSE for more details.
 *
 * This library implements the Modbus protocol.
 * http://libmodbus.org/
 *
 */

#include <stdint.h>
#include <stdbool.h>
#include "modbus.h"
#include "cfgbus.h"
#include <string.h>

//the following function pointers are used throughout the code. Point them to implementations to connect modbus
//to a UART port and register file

//should handle the logic of reading from and writing to holding registers (16bit).
//start  : the register index to start read/writing
//nr_regs: the number of registers to read/write
//data   : the data to write, or the buffer to read to
void (*reg_read)(uint16_t start, uint16_t nr_regs, uint8_t* data)            = &CfgRegRead;
mb_exception_t (*reg_write)(uint16_t start, uint16_t nr_regs, uint8_t* data) = &CfgRegWrite;
bool (*valid_range)(uint16_t start, uint16_t nr_regs)                        = &CfgValidRange;

//modbus physical communication (e.g. uart) read/write functions
//data: data to write/buffer to read to
//len : number of bytes to read/write
int (*mb_read)(uint8_t * data, uint32_t len)                           = &CfgRead;
int (*mb_write)(uint8_t * data, uint32_t len)                          = &CfgWrite;

//returns the number of avaialbe data-bytes to read
uint32_t (*available)()                                             = &CfgAvailable;

//flush rx/tx buffers of the serial communication
void (*flush_rx)(void)                                              = &CfgFlushRx;
void (*flush_tx)(void)                                              = &CfgFlushTx;

//get current timestamp in ms
uint32_t (*tick)(void)                                              = &CfgTick;

//gives the user information if something goes wrong. Use this to log or act
//allowed to do nothing
void (*error)(int code)                                             = &CfgSetError;


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


typedef struct
{
  uint8_t slave;
  uint8_t fcode;
  uint16_t first_reg;
  uint16_t nr_regs;
  uint8_t data_len;
} mb_hdr_t;


mb_hdr_t _hdr = {0};
uint8_t _rcvBuff[MB_RX_BUFFER_SIZE] = {0};
uint8_t _state = _st_idle;
uint32_t _lastTick = 0;
uint32_t _lastAvailable = 0;


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

  msg[msg_length++] = crc & 0xFF;
  msg[msg_length++] = (crc >> 8) & 0xFF;

  mb_write(msg, msg_length);
}


static void flush(void) {
  //wait until gap of pack-timeout occurs

  uint32_t loopStart = tick();
  uint32_t start = 0;

  while (loopStart - tick() < 30) //wait max 30ms
  {
    if(!available() && start == 0)
    {
      start = tick();
    }
    else
    {
      flush_rx();
      start = 0;
    }

    if(tick() - start > MB_PACKET_TIMEOUT)
    {
      flush_rx();
      break;
    }
  }

}


void exception(uint8_t e, uint8_t nextState)
{
  error(e);

  uint8_t rsp[3];

  rsp[0] = MB_SLAVE_ID;
  rsp[1] = _hdr.fcode + 0x80;
  rsp[2] = e;

  send_msg(rsp,3);
  _state = nextState;
}


void inline timeout(uint8_t nextState)
{
  error(mb_timeout);
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

  //get crc from received data (local crc is LSB first, so invert bytes)
  uint16_t masterCrc = ((uint16_t)(data[_hdr.data_len +1] << 8)) + data[_hdr.data_len];

  return (crc == masterCrc) ? 0 : -1;
}


void modbusUpdate() {

  //waiting for message to be addressed to this slave
  if(_state == _st_idle && available())
  {
    mb_read(&_hdr.slave,1); //get slave address
    if(_hdr.slave != MB_SLAVE_ID && _hdr.slave != MB_BROADCAST_ADDR )
    {
      flush(); //not for me, ignore
      return;
    }

    //reset state where necessary, and receive header
    _hdr.data_len  = 0;
    _lastAvailable = available();
    _lastTick = tick();
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
    if(available() >= 6)
    {
      uint8_t rcv[5];
      mb_read(rcv,5);
      _hdr.fcode     = rcv[0];
      _hdr.first_reg = ((uint16_t)(rcv[1] << 8)) + rcv[2];
      _hdr.nr_regs   = ((uint16_t)(rcv[3] << 8)) + rcv[4];

      if(_hdr.fcode != _fc_write_regs && _hdr.fcode != _fc_read_regs)
      {
        exception(mb_illegal_func, _st_idle); //unsupported function
        return;
      }

      if(!valid_range(_hdr.first_reg,_hdr.nr_regs))
      {
        exception(mb_illegal_address,_st_idle);
        return;
      }

      if(_hdr.fcode == _fc_write_regs)
        mb_read(&_hdr.data_len,1);

      _lastTick = tick();
      _state = _st_receive;
    }
    else if (available() > _lastAvailable) //new data so proceed
    {
      _lastTick = tick();
      _lastAvailable = available();
    }
    else if (tick() - _lastTick > MB_CHAR_TIMEOUT) //timed out
    {
      timeout(_st_idle);
      return;
    }
  }


  if(_state == _st_receive)
  {
    if(available() >= _hdr.data_len + 2)
    {
      mb_read(_rcvBuff,_hdr.data_len + 2);

      //check integrity
      if(check_integrity(_rcvBuff) == 0)
      {
        _state = _st_respond;
      }
      else
      {
        exception(mb_illegal_value,_st_idle);
        return;
      }
    }
    else if (available() > _lastAvailable) //new data so proceed
    {
      _lastTick = tick();
      _lastAvailable = available();
    }
    else if (tick() - _lastTick > MB_CHAR_TIMEOUT) //timed out
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
      mb_exception_t res = reg_write(_hdr.first_reg, _hdr.nr_regs, _rcvBuff);

      if(res != mb_ok)
      {
        exception(mb_illegal_address,_st_idle);
        return;
      }

      //respond
      uint8_t rsp[6];
      rspHeader(rsp);
      send_msg(rsp,6);

      _state = _st_idle;
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

      reg_read(_hdr.first_reg, _hdr.nr_regs, &_rcvBuff[3]);

      send_msg(_rcvBuff, 3 + _hdr.nr_regs * 2);

      _state = _st_idle;
    }

  }

}
