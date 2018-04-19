/*
 * cfgbus.h
 *
 *  Created on: Apr 13, 2018
 *      Author: tomvoc
 */

#pragma once
#include <stdint.h>

/** CFGBUS PROTOCOL DESCRIPTION

CFGBUS (configbus) was designed as a simple protocol that allows setting and reading
configuration parameters on an embedded slave. The settable parameters can be retreived by the
host. This allows a generic GUI/Interface on the host side that can be used for different devices
with different settings.

It is easily ported, and performs simple error checking

Write entry

Side   | data         | nr bytes |
----------------------------------
host   | cmd | entry  | 1        |
host   | data[0...n]  | n        |
host   | crc          | 1        |
slave  | cmd | entry  | 1        |

Read entry value

Side   | data         | nr bytes |
----------------------------------
host   | cmd | entry  | 1        |
slave  | cmd | entry  | 1        |
slave  | data[0...n]  | n        |
slave  | crc          | 1        |


Read entry file
Side   | data         | nr bytes |
----------------------------------
host   | cmd          | 1        |
slave  | cmd          | 1        |
slave  | nr entries   | 1 (u8_t) |
----------------------------------
for each entry
----------------------------------
slave  | entry id     | 1 (u8_t) |
slave  | type         | 1 (u8_t) |
slave  | size         | 1 (u8_t) |
slave  | writable     | 1 (bool) |
slave  | descr len    | 1 (u8_t) |
slave  | descr        | len      |
slave  | crc          | 1 (u8_t) |


in case of any slave error, the slave will send a nack.
after the slave sent a nack it will wait 100ms, then clear the RX buffer and send another nack.
If the second nack is received, the slave is ready for comms again

**/



typedef enum
{
  cfg_ok              = 0,
  cfg_err             = 1,
  cfg_invalid_data    = 2,
  cfg_rx_timeout      = 3,
  cfg_rx_error        = 4,
  cfg_tx_timeout      = 5,
  cfg_tx_error        = 6,
  cfg_invalid_entry   = 7,
  cfg_invalid_cmd     = 8,
  cfg_err_write_len_mismatch = 9,
  cfg_crc_err         = 10,
  cfg_err_illegal_write = 11,
} cfg_ret_t;

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
  //add custom types here
} cfg_type_t;

typedef enum
{
  cfg_cmd_nack   = 0x00, //0b00000000,
  cfg_cmd_write  = 0x40, //0b01000000,
  cfg_cmd_read   = 0x80, //0b10000000,
  cfg_cmd_list   = 0xC0, //0b11000000
} cfg_cmd_t;


//should match the amound of entries in the cfg_t struct.
#define CFG_NUM_ENTRIES (5)

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

void cfg_init();
void cfg_update();
