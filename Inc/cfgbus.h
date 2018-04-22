#pragma once

#ifndef CFGBUS_H
#define CFGBUS_H

#include <stdint.h>

uint32_t CfgAvailable();
int CfgRead(uint8_t * data, uint32_t len);
int CfgWrite(uint8_t * data, uint32_t len);
void CfgFlushRx();
void CfgFlushTx();
uint32_t CfgTick();

typedef enum
{
  cfg_ok              = 0,
  cfg_invalid_data    = 1,
  cfg_rx_timeout      = 2,
  cfg_rx_error        = 3,
  cfg_tx_timeout      = 4,
  cfg_tx_error        = 5,
  cfg_invalid_entry   = 6,
  cfg_invalid_cmd     = 7,
  cfg_len_mismatch    = 8,
  cfg_crc_err         = 9,
  cfg_illegal_write   = 10,
  cfg_unknown         = 11 //should be last
} cfg_err_t;

typedef enum
{
  t_u8    = 0,
  t_u16   = 1,
  t_u32   = 2,
  t_u64   = 3,
  t_i8    = 4,
  t_i16   = 5,
  t_i32   = 6,
  t_i64   = 7,
  t_flt   = 8,
  t_dbl   = 9,
  t_bool  = 10,
  t_str   = 11,
  t_err   = 12,
  t_unknown = 13//should be last
} cfg_type_t;

//should match the amound of entries in the cfg_t struct.
#define CFG_NUM_ENTRIES (6)

typedef enum
{
  false = 0,
  true  = !false
} bool_t;

typedef struct
{
  volatile void *addr;
  uint8_t size;
  uint8_t type; //types declared in "type_t" enum
  uint8_t writeable; //0=no, !0= yes
  const char* name;
} cfg_entry_t;

typedef struct
{
  uint32_t magic; //do not remove, it is used to determine endiannes on the other side
  uint8_t err_code; //do not remove, it is used to read back error states
  char dev_name[12];
  uint32_t pwm_l;
  uint32_t pwm_r;
  float vbat;
} cfg_t;

extern volatile cfg_t cfg;
extern const cfg_entry_t cfg_entries[CFG_NUM_ENTRIES];



#endif //CFGBUS_H

