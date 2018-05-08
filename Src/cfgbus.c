#include "cfgbus.h"
#include "modbus.h"
#include "uart.h"
#include "eeprom.h"
#include <string.h>


//these function pointers should point to a user configurable function
//that stores/reads the 16bit value array in a non-volatile memory such as an eeprom
//@return: the number of registers succesfully written, should equal len on success
uint16_t (*CfgStore)(volatile uint16_t *data, uint16_t len) = &ee_store;
uint16_t (*CfgLoad)(volatile uint16_t *data, uint16_t len)  = &ee_load;

#ifdef MIN
#undef MIN
#endif

#define CFG_BUS_UART (UARTCh3)
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

//DO NOT TOUCH, used to generate cfg struct, entry list, and count number of entries
#define _VAR_ADDR(_var) (((uint16_t*)&cfg.vars._var)-&cfg.regs[0])
#define _VAR_SIZE(_var) ((sizeof(cfg.vars._var)+1)/2)

#define _XX_VAR(_var,_type)  _VAR_ADDR(_var), _VAR_SIZE(_var), _type
#define _U16(_var) _XX_VAR(_var,t_u16)
#define _U32(_var) _XX_VAR(_var,t_u32)
#define _U64(_var) _XX_VAR(_var,t_u64)
#define _I16(_var) _XX_VAR(_var,t_i16)
#define _I32(_var) _XX_VAR(_var,t_i32)
#define _I64(_var) _XX_VAR(_var,t_i64)
#define _FLT(_var) _XX_VAR(_var,t_flt)
#define _DBL(_var) _XX_VAR(_var,t_dbl)
#define _ERR(_var) _XX_VAR(_var,t_err)
#define _BOOL(_var) _XX_VAR(_var,t_bool)

#define _XX_STR(_var,_len) (_VAR_ADDR(_var)-_len/2), _len/2, t_str
#define _STR8(_var)  _XX_STR(_var,8)
#define _STR9(_var)  _XX_STR(_var,9)
#define _STR10(_var) _XX_STR(_var,10)
#define _STR11(_var) _XX_STR(_var,11)
#define _STR12(_var) _XX_STR(_var,12)
#define _STR13(_var) _XX_STR(_var,13)
#define _STR14(_var) _XX_STR(_var,14)
#define _STR15(_var) _XX_STR(_var,15)
#define _STR16(_var) _XX_STR(_var,16)
#define _STR17(_var) _XX_STR(_var,17)
#define _STR18(_var) _XX_STR(_var,18)
#define _STR19(_var) _XX_STR(_var,19)
#define _STR20(_var) _XX_STR(_var,20)
#define _STR21(_var) _XX_STR(_var,21)
#define _STR22(_var) _XX_STR(_var,22)
#define _STR23(_var) _XX_STR(_var,23)
#define _STR24(_var) _XX_STR(_var,24)

#define _LIST(_var,_2,_type,_rw,_name) { _type(_var), _rw, _name},
#define CFG_ENTRY_HEADER_REGS (12)

typedef enum
{
  cfg_magic_reg     = 0,
  cfg_dev_reg_first = 1,
  cfg_dev_reg_last  = 6,
  cfg_err_code      = 7,
  cfg_err_cnt       = 8,
  cfg_list_addr     = 9,
  cfg_list_size     = 10,
  cfg_nr_entries    = 11,
} cfg_fixed_reg_t;


typedef struct
{
  uint16_t address;
  uint8_t size;
  uint8_t type;      //types declared in "type_t" enum
  bool writeable;
  const char* name;  //only 16 chars sent over bus!!
} cfg_entry_t;


//counted in nr 16-bit registers
//5+name_len bytes, + /0 character +1 to ceil /2 devision
#define CFG_LIST_ENTRY_SIZE ((5+CFG_LIST_NAME_CHARS+2)/2)

volatile cfg_mem_t cfg;

const cfg_entry_t cfg_entries[CFG_NR_ENTRIES] = {
    CFG_ENTRIES(_LIST)
};

//helper functions
void _setWriteMask(uint16_t start, uint16_t nr_regs);
bool _isWriteAllowed(uint16_t start, uint16_t nr_regs);
void _endianRegCpy(volatile uint16_t* dst,volatile uint16_t* src, uint8_t nr_regs);
inline bool _isListEntry(uint16_t start, uint16_t nr_regs);


void CfgInit()
{
  //=======================================
  //DO NOT CHANGE:: cfgbus required entries
  //=======================================

  if(ee_load(cfg.regs,CFG_NR_REGISTERS) != CFG_NR_REGISTERS)
  {
    for(int i=0; i<CFG_NR_REGISTERS; i++)
      cfg.regs[i] = 0; //if load was not succesfull, set all entries to 0 to be safe.
  }

  cfg.vars.magic = 0xC0DE;

  strncpy((char *)cfg.vars.dev_name,CFG_DEVICE_NAME,10);
  cfg.vars.dev_name[11] = 0x00;

  cfg.vars.err_cnt = 0;
  cfg.vars.err_code = cfg_ok;
  cfg.vars.nr_entries = CFG_NR_ENTRIES;

  //initialize writeMask here, so writeability can be determined fast after init
  for(int i=0; i<CFG_NR_ENTRIES; i++)
  {
    if(!cfg_entries[i].writeable)
    {
      //set corresponding writeMask entries to 1
      _setWriteMask(cfg_entries[i].address,(cfg_entries[i].size+1)/2);
    }
  }

  //=======================================
  //Initialize user entries here that should always have the
  //same value when starting the system. The rest will be
  //loaded from eeprom
  //=======================================

  if(cfg.vars.rate_limit == 0)
    cfg.vars.rate_limit = 1;

  if(cfg.vars.max_pwm_r == 0)
    cfg.vars.max_pwm_r = 200;

  if(cfg.vars.max_pwm_l == 0)
      cfg.vars.max_pwm_l = 200;

  cfg.vars.setpoint_l = 0;
  cfg.vars.setpoint_r = 0;
  cfg.vars.buzzer = 0;
  cfg.vars.speed_l = 0;
  cfg.vars.speed_r = 0;
  cfg.vars.tacho_l = 0;
  cfg.vars.tacho_r =0;
  cfg.vars.pwm_l = 0;
  cfg.vars.pwm_r = 0;
  cfg.vars.pos_l = 0;
  cfg.vars.pos_r = 0;
  cfg.vars.vbat = 0;
}


uint32_t CfgTick()
{
  return HAL_GetTick();
}


uint32_t CfgAvailable(void)
{
  return UARTRxAvailable(CFG_BUS_UART);
}


int CfgRead(uint8_t *out, uint32_t cnt)
{
  return UARTRead(CFG_BUS_UART,out,cnt);
}


int CfgWrite(uint8_t * data, uint32_t len)
{
  return UARTSend(CFG_BUS_UART,data,len);
}


void CfgFlushRx()
{
  UARTFlushRX(CFG_BUS_UART);
}


void CfgFlushTx()
{
  UARTFlushTX(CFG_BUS_UART);
}


void CfgSetError(int error)
{
  cfg_err_t err = cfg_unknown;
  switch(error)
  {
  case mb_illegal_func:
    err = cfg_invalid_cmd;
    break;
  case mb_illegal_address:
    err = cfg_illegal_write;
    break;
  case mb_illegal_value:
    err = cfg_invalid_data;
    break;
  case mb_timeout:
    err = cfg_rx_timeout;
    break;
  default:
    break;
  }

  cfg.vars.err_cnt++;
  cfg.vars.err_code = (cfg.vars.err_code == cfg_ok) ? err : cfg.vars.err_code; //don't change until user clears
}


_Bool CfgValidRange(uint16_t start, uint16_t nr_regs)
{
  if(start < CFG_ENTRY_HEADER_REGS)
  {
    return (start+nr_regs <= CFG_ENTRY_HEADER_REGS);
  }
  else if(start < CFG_LIST_REG_INDEX)
  {
    return (start+nr_regs <= sizeof(cfg.regs)/2); //if within register range
  }
  else
  {
    return _isListEntry(start,nr_regs);
  }
}


void CfgRegRead(uint16_t start, uint16_t nr_regs, uint8_t* data)
{
  if(_isListEntry(start,nr_regs)) //read from entry list
  {
    uint16_t idx = (start - CFG_LIST_REG_INDEX) / CFG_LIST_ENTRY_SIZE;
    cfg_entry_t entry = cfg_entries[idx];

    //format
    //0..1:index;
    //2   :size;
    //3   :type;        //types declared in "type_t" enum
    //4   :writeable;   //0=false, !0=true
    //5..n name chars;
    //n..m :/0 characters, where m == CFG_LIST_NAME_CHARS

    data[0] = (entry.address >> 8) & 0xFF;  //MSB
    data[1] = entry.address & 0xFF;         //LSB
    data[2] = entry.size;
    data[3] = entry.type;
    data[4] = entry.writeable;

    //copy string contents
    uint8_t cpy_len = MIN(CFG_LIST_NAME_CHARS,strlen(entry.name));
    uint8_t remaining = (CFG_LIST_NAME_CHARS+1)-cpy_len;
    strncpy((char *)&data[5],entry.name, cpy_len);
    memset(&data[5+cpy_len],'\0',remaining);   //fill remainder with 0 (always at least the last)
  }
  else
  {
    _endianRegCpy((uint16_t*)data,&cfg.regs[start],nr_regs);
  }
}


mb_exception_t CfgRegWrite(uint16_t start, uint16_t nr_regs, uint8_t* data)
{
  //before any check, if it is a write to magic value, and data equals magic value
  //store current settings in eeprom
  if(start == 0 && ((uint16_t*)data)[0] == cfg.vars.magic)
  {
    if(CfgStore(cfg.regs,CFG_NR_REGISTERS) != CFG_NR_REGISTERS)
      return mb_timeout;
    else
      return mb_ok;
  }

  if(_isListEntry(start,nr_regs))
    return mb_illegal_address;

  if(!_isWriteAllowed(start,nr_regs))
    return mb_illegal_address;

  _endianRegCpy(&cfg.regs[start],(uint16_t*)data,nr_regs);
  return mb_ok;
}


//==============================================================
//HELPER FUNCTIONS
//==============================================================

//this array stores a bit for every available 16-bit register
//the bit represents 0:read/write, 1:read only
uint8_t writeMask[(sizeof(cfg.regs)/16)+1] = {0};

const uint8_t loMasks[8] = {0xFF,0xFE,0xFC,0xF8,0xF0,0xE0,0xC0,0x80};
const uint8_t hiMasks[8] = {0x01,0x03,0x07,0x0F,0x1F,0x3F,0x7F,0xFF};


void _setWriteMask(uint16_t start, uint16_t nr_regs)
{
  if(start+nr_regs > sizeof(writeMask)*8)
    return;

  uint16_t loByte = start/8;
  uint16_t hiByte = (start+nr_regs-1)/8;

  uint8_t loBit = start%8;
  uint8_t hiBit = (start+nr_regs-1)%8;

  if(loByte == hiByte)
  {
    writeMask[loByte] |= (loMasks[loBit] & hiMasks[hiBit]);
  }
  else
  {
    writeMask[loByte] |= loMasks[loBit];
    writeMask[hiByte] |= hiMasks[hiBit];
  }

  for (int i=1; i<hiByte-loByte; i++)
    writeMask[loByte+i] = 0xFF;
}


//if any bits in writeMask in range start:start+nr_regs is 1, return false
bool _isWriteAllowed(uint16_t start, uint16_t nr_regs)
{
  if(start+nr_regs > sizeof(writeMask)*8)
    return false;

  uint16_t loByte = start/8;
  uint16_t hiByte = (start+nr_regs-1)/8;

  uint8_t loBit = start%8;
  uint8_t hiBit = (start+nr_regs-1)%8;

  volatile bool result;

  if(loByte == hiByte)
  {
    result = (writeMask[loByte] & (loMasks[loBit] & hiMasks[hiBit])) == 0;
  }
  else
  {
    result = (writeMask[loByte] & loMasks[loBit]) == 0;
    result = result && (writeMask[hiByte] & loMasks[hiBit])==0;
  }

  for (int i=1; i<hiByte-loByte; i++)
    result = result && writeMask[loByte+i] == 0x00;

  return result;
}


//handle endianess conversion on host side. If we do it here, and we have a little
//endian machine, a 32bit value like 0x01020304 will be read/written als 0x04030102
//and thus still needs to be corrected at the host side. No need to do that twice
void _endianRegCpy(volatile uint16_t* dst,volatile uint16_t* src, uint8_t nr_regs)
{
    for(uint32_t i = 0; i<nr_regs; i++)
      dst[i] = src[i];
}


inline bool _isListEntry(uint16_t start, uint16_t nr_regs)
{
  //if range is aligned with list entries, and nr_regs matches list entry size
  return ( (start - CFG_LIST_REG_INDEX) % CFG_LIST_ENTRY_SIZE == 0 && nr_regs == CFG_LIST_ENTRY_SIZE);
}


