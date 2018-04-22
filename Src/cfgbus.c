#include "cfgbus.h"
#include "uart.h"
#include "crc8.h"
#include "defines.h"
#include <string.h>


#define CFG_MAX_NAME_LEN (16)
#define CFG_BUFF_SIZE (CFG_MAX_NAME_LEN + 6)
#define CFG_RX_TIMEOUT_PBYTE (10) //timeout = nrbytes to receive * value in ms
#define CFG_TX_TIMEOUT_PBYTE (10) //timeout = nrbytes to send * value in ms

typedef enum
{
  cfg_st_init     = 0,
  cfg_st_idle     = 1,
  cfg_st_respond  = 2,
  cfg_st_process  = 3,
  cfg_st_err      = 4,
  cfg_st_nack     = 5
} cfg_state_t;


cfg_state_t _state      = cfg_st_idle;
cfg_ret_t   _err_state  = cfg_ok;
uint32_t    _recv_len   = 0;
cfg_cmd_t   _cmd        = cfg_cmd_nack;
uint8_t     _entry      = 0;
uint32_t    _tick       = 0;
uint8_t     _buff[CFG_BUFF_SIZE] = {0} ;


typedef struct
{
  volatile void *addr;
  uint8_t size;
  uint8_t type; //types declared in "type_t" enum
  uint8_t writeable; //0=no, !0= yes
  const char* name;
} cfg_entry_t;

volatile cfg_t cfg = {0};

//===========================================
//Update List to match cfg_t definition
//===========================================

//should have an entry for each cfg_t member!
const cfg_entry_t cfg_entries[CFG_NUM_ENTRIES] = {
    {&cfg.magic     , sizeof(cfg.magic)     , t_u32 , false , "Magic Value"     },
    {&cfg.err_code  , sizeof(cfg.err_code)  , t_err , true  , "Error Code"      },
    {&cfg.dev_name  , sizeof(cfg.dev_name)  , t_str , true  , "Device Name"     },
    {&cfg.pwm_l     , sizeof(cfg.pwm_l)     , t_u32 , true  , "L-Mtr PWM"       },
    {&cfg.pwm_r     , sizeof(cfg.pwm_r)     , t_u32 , true  , "R-Mtr PWM"       },
    {&cfg.vbat      , sizeof(cfg.vbat)      , t_flt , false , "Battery Voltage" }
};

//===========================================


void cfg_init()
{
  cfg.magic = 0xBAADC0DE;
}

static inline uint32_t getTick()
{
  return HAL_GetTick();
}

static inline uint32_t available(void)
{
  return UARTAvailable(UARTCh2);
}

static inline cfg_ret_t read(uint8_t *out, uint32_t cnt)
{
  return (UARTRead(UARTCh2,out,cnt) == cnt) ? cfg_ok : cfg_rx_error;
}

static inline cfg_ret_t send(const uint8_t *out, uint32_t cnt, bool wait)
{
  cfg_ret_t result = (UARTSend(UARTCh2,out,cnt)==0) ? cfg_ok : cfg_tx_error;

  if(wait && result == cfg_ok)
  {
    result = cfg_tx_timeout;
    uint32_t start = getTick();

    while(getTick()-start < CFG_TX_TIMEOUT_PBYTE*(cnt+1))
    {
      if(UARTTXReady(UARTCh2) == 0)
      {
        result = cfg_ok;
        break;
      }
      HAL_Delay(CFG_TX_TIMEOUT_PBYTE);
    }
  }

  return result;
}


static inline void flush_rx()
{
  //read all the bytes
  UARTFlushRX(UARTCh2);
}


static inline cfg_ret_t process(cfg_cmd_t cmd, uint8_t entryId, uint8_t *data, uint8_t len)
{
  cfg_entry_t entry = cfg_entries[entryId];

  //check if writeable
  if(entry.writeable == 0)
    return cfg_illegal_write;

  //check data length
  if(entry.size != len-1)
    return cfg_len_mismatch;

  //check crc
  uint8_t resp = cmd | entryId;
  uint8_t crc = crc8(0,&resp,1);
  crc = crc8(crc,data,len-1);

  if(crc != data[len-1])
    return cfg_crc_err;

  //could just memcpy the data into the entry address, but want to get atomic writes
  //as much as possible so cast and assign instead.
  switch(entry.type)
  {
    case t_u8:
      *((uint8_t *)entry.addr) = data[0];
      break;
    case t_u16:
      *((uint16_t *)entry.addr) = *((uint16_t *)data);
      break;
    case t_u32:
      *((uint32_t *)entry.addr) = *((uint32_t *)data);
      break;
    case t_u64:
      *((uint64_t *)entry.addr) = *((uint64_t *)data);
      break;
    case t_i8:
      *((int8_t *)entry.addr) = (int8_t )data[0];
      break;
    case t_i16:
      *((int16_t *)entry.addr) = *((int16_t *)data);
      break;
    case t_i32:
      *((int32_t *)entry.addr) = *((int32_t *)data);
      break;
    case t_i64:
      *((int64_t *)entry.addr) = *((int64_t *)data);
      break;
    case t_flt:
      *((float *)entry.addr) = *((float *)data);
      break;
    case t_dbl:
      *((double *)entry.addr) = *((double *)data);
      break;
    case t_bool:
      *((bool *)entry.addr) = (data[0] != 0) ? true : false;
      break;
    case t_err:
      *((cfg_ret_t *)entry.addr) = (cfg_ret_t)data[0];
      break;
    case t_str:
      memcpy((char *)entry.addr,data,entry.size);
      break;
  }

  return cfg_ok;
}

void cfg_update()
{

  if(_state == cfg_st_idle)
  {
    if(available())
    {
      uint8_t tmpRead = 0;
      _err_state = read(&tmpRead,1);
      _tick = getTick();

      if(_err_state == cfg_ok)
      {
        _cmd      = (cfg_cmd_t)(tmpRead & 0b11000000);
        _entry    = tmpRead & 0b00111111;

        if(_entry > CFG_NUM_ENTRIES-1)
          _err_state = cfg_invalid_entry;
        else if (_cmd == cfg_cmd_nack)
          _err_state = cfg_invalid_cmd;
        else
        {
          _recv_len = cfg_entries[_entry].size + 1;
          _state    = (_cmd == cfg_cmd_write) ? cfg_st_process : cfg_st_respond;
        }
      }
    }
  }


  if(_state == cfg_st_process)
  {
      if(available() >= _recv_len)
      {
        _err_state = read(_buff,_recv_len);
        if(_err_state == cfg_ok)
        {
          _err_state = process(_cmd, _entry, _buff, _recv_len);
          _state = (_err_state == cfg_ok) ? cfg_st_respond : _state;
          _tick = getTick();
        }
      }

      else if (getTick() - _tick > CFG_RX_TIMEOUT_PBYTE * _recv_len)
      {
        _err_state = cfg_rx_timeout;
      }
  }


  if(_state == cfg_st_respond)
  {
    if(_cmd == cfg_cmd_write)
    {
      uint8_t resp = _cmd | _entry;
      _err_state = send(&resp,1,false);
    }

    if(_cmd == cfg_cmd_read)
    {
      //build tx packet
      _buff[0]= _cmd | _entry;
      memcpy(&_buff[1],(uint8_t *)cfg_entries[_entry].addr,cfg_entries[_entry].size);
      _buff[cfg_entries[_entry].size + 1] = crc8(0,_buff,cfg_entries[_entry].size + 1);

      //packet
      _err_state = send(_buff,cfg_entries[_entry].size + 2, false);
    }

    //no point in error checking, since the other side can't check err status yet
    if(_cmd == cfg_cmd_list)
    {
      _buff[0] = _cmd;
      _buff[1] = CFG_NUM_ENTRIES;

      //send and wait
      _err_state = send(_buff,2,true);

      for(uint8_t i=0; i<CFG_NUM_ENTRIES; i++)
      {
        if(_err_state != cfg_ok)
          break;

        //get entry name length
        uint8_t str_len = MIN(strlen(cfg_entries[i].name),CFG_MAX_NAME_LEN);

        //build entry frame (id,type,size,name,crc)
        uint8_t index  = 0;
        _buff[index++] = i;
        _buff[index++] = cfg_entries[i].type;
        _buff[index++] = cfg_entries[i].size;
        _buff[index++] = cfg_entries[i].writeable;
        _buff[index++] = str_len;

        //copy name string
        memcpy(&_buff[index],cfg_entries[i].name,str_len);
        index += str_len;

        //calculate and store crc
        _buff[index] = crc8(0,_buff,index);

        //send frame, and wait until done
        _err_state = send(_buff,index+1,true);
      }
    }

    _state = cfg_st_idle;
  }


  if(_state == cfg_st_nack)
  {
      //after 100ms, clear receive buffer and send second nack. This indicates
      //device has recovered from error and is ready to receive again
      if (getTick() - _tick > 100)
      {
        flush_rx();

        //if we cannot send the nack here, we cannot recover, so keep retrying until we succeed
        uint8_t tmpSend = cfg_cmd_nack;
        _state = (send(&tmpSend,1,false) != cfg_ok) ? cfg_st_nack : cfg_st_idle;
      }

  }


  //if an active error state is present, store it in cfg so it can be retrieved,
  //and nack current command
  if(_err_state != cfg_ok && _state != cfg_st_err)
    _state = cfg_st_err;

  if(_state == cfg_st_err)
  {
    cfg.err_code = _err_state;
    _err_state = cfg_ok;
    _tick = getTick();

    //if we cannot send the nack here, we cannot recover, so keep retrying until we succeed
    uint8_t tmpSend = cfg_cmd_nack;
    _state = (send(&tmpSend,1,false) != cfg_ok) ? cfg_st_err : cfg_st_nack;
  }

}
