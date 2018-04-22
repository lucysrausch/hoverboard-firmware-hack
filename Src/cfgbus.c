#include "cfgbus.h"
#include "uart.h"

volatile cfg_t cfg;

const cfg_entry_t cfg_entries[CFG_NUM_ENTRIES] = {
    {&cfg.magic     , sizeof(cfg.magic)     , t_u32 , false , "Magic Value"     },
    {&cfg.err_code  , sizeof(cfg.err_code)  , t_err , true  , "Error Code"      },
    {&cfg.dev_name  , sizeof(cfg.dev_name)  , t_str , true  , "Device Name"     },
    {&cfg.pwm_l     , sizeof(cfg.pwm_l)     , t_u32 , true  , "L-Mtr PWM"       },
    {&cfg.pwm_r     , sizeof(cfg.pwm_r)     , t_u32 , true  , "R-Mtr PWM"       },
    {&cfg.vbat      , sizeof(cfg.vbat)      , t_flt , false , "Battery Voltage" }
};

uint32_t CfgTick()
{
  return HAL_GetTick();
}

uint32_t CfgAvailable(void)
{
  return UARTAvailable(UARTCh2);
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
  //read all the bytes
  UARTFlushRX(UARTCh2);
}

void CfgFlushTx()
{
  //read all the bytes
  UARTFlushTX(UARTCh2);
}


