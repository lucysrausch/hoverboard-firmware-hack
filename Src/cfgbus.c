#include "cfgbus.h"
#include "modbus.h"
#include "uart.h"
#include <string.h>

#ifdef MIN
#undef MIN
#endif

#define MIN(a, b) (((a) < (b)) ? (a) : (b))

typedef struct
{
  uint16_t index;
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
  //do not change, cfgbus required entries
  cfg.vars.magic = 0xBAADC0DE;
  strncpy((char *)cfg.vars.dev_name,CFG_DEVICE_NAME,sizeof(cfg.vars.dev_name)-1);
  cfg.vars.dev_name[sizeof(cfg.vars.dev_name)-1] = 0x00;
  cfg.vars.err_cnt = 0;
  cfg.vars.err_code = cfg_ok;
  cfg.vars.list_addr = CFG_LIST_REG_INDEX;
  cfg.vars.list_size = CFG_NR_ENTRIES;

  //initialize writeMask here, so writeability can be determined fast after init
  for(int i=0; i<CFG_NR_ENTRIES; i++)
  {
    if(!cfg_entries[i].writeable)
    {
      //set corresponding writeMask entries to 1
      _setWriteMask(cfg_entries[i].index,(cfg_entries[i].size+1)/2);
    }
  }

  //initialize user entries here
  //...

}


uint32_t CfgTick()
{
  return HAL_GetTick();
}


uint32_t CfgAvailable(void)
{
  return UARTRxAvailable(UARTCh2);
}


int CfgRead(uint8_t *out, uint32_t cnt)
{
  return UARTRead(UARTCh2,out,cnt);
}


int CfgWrite(uint8_t * data, uint32_t len)
{
  return UARTSend(UARTCh2,data,len);
}


void CfgFlushRx()
{
  UARTFlushRX(UARTCh2);
}


void CfgFlushTx()
{
  UARTFlushTX(UARTCh2);
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
  if(start < CFG_LIST_REG_INDEX)
  {
    return (start+nr_regs < sizeof(cfg.regs)/2); //if within register range
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

    data[0] = entry.index;
    data[1] = entry.index;
    data[2] = entry.size;
    data[3] = entry.type;
    data[4] = entry.writeable;

    //copy string contents
    uint8_t cpy_len = MIN(CFG_LIST_NAME_CHARS,strlen(entry.name));
    uint8_t remaining = (CFG_LIST_NAME_CHARS+1)-cpy_len;
    strncpy((char *)&data[5],entry.name, cpy_len);
    memset(&data[5+cpy_len],'\0',remaining);   //fill remainder with 0 (always at least the last)
  }
  else //read from registers
  {
    _endianRegCpy((uint16_t*)data,&cfg.regs[start],nr_regs);
  }
}


mb_exception_t CfgRegWrite(uint16_t start, uint16_t nr_regs, uint8_t* data)
{
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


//copies in into out, assuming one of these is big endian (network)
void _endianRegCpy(volatile uint16_t* dst,volatile uint16_t* src, uint8_t nr_regs)
{
//  const uint16_t _e = 1;
//  if( (*(char*)&_e) == 0 ) // if cpu=big_endian, don't flip data, just copy

  //solve endiannes on host with magic value, as otherwise little endian value
  //will have to be written as 03 04 01 02 (where 0n represent nth bit)

  for(uint32_t i = 0; i<nr_regs; i++)
    dst[i] = src[i];


}


inline bool _isListEntry(uint16_t start, uint16_t nr_regs)
{
  //if range is aligned with list entries, and nr_regs matches list entry size
  return ( (start - CFG_LIST_REG_INDEX) % CFG_LIST_ENTRY_SIZE == 0 && nr_regs == CFG_LIST_ENTRY_SIZE);
}


