#include "cfgbus.h"
#include "modbus.h"
#include "uart.h"
#include <string.h>

volatile cfg_mem_t cfg;

const cfg_entry_t cfg_entries[CFG_NR_ENTRIES] = {
    CFG_ENTRIES(_LIST)
};


void CfgInit()
{
  //do not change, cfgbus required entries
  cfg.vars.magic = 0xBAADC0DE;
  strcpy((char *)cfg.vars.dev_name,CFG_DEVICE_NAME);
  cfg.vars.err_cnt = 0;
  cfg.vars.err_code = cfg_ok;
  cfg.vars.list_addr = CFG_LIST_REG_INDEX;
  cfg.vars.list_size = CFG_NR_ENTRIES;

  //initialize user entries here

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

int CfgValidRange(uint16_t start, uint16_t nr_regs)
{
  if(start < CFG_LIST_REG_INDEX)
  {
    return (start+nr_regs < sizeof(cfg.regs)/2);
  }
  else
  {
    return !0;
  }
}

//copies in into out, assuming one of these is big endian (network)
void endianCpy(volatile void* in, uint8_t size, volatile void* out)
{
  const uint16_t _e = 1;
  uint8_t* pIn =  (uint8_t *)in;
  uint8_t* pOut = (uint8_t *)out;

  if( (*(char*)&_e) == 0 ) // if cpu=big_endian
    for(uint32_t i = 0; i<size; i++)
          pOut[i] = pIn[i];
  else
    for(uint32_t i = 0; i<size; i++)
      pOut[i] = pIn[size-i-1];
}

void CfgRegRead(uint16_t start, uint16_t nr_regs, uint8_t* data)
{
  endianCpy(&cfg.regs[start],nr_regs*2,data);
}

void CfgRegWrite(uint16_t start, uint16_t nr_regs, uint8_t* data)
{
  endianCpy(data,nr_regs*2,&cfg.regs[start]);
}


