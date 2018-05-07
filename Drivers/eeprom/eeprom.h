#ifndef __EEPROM_H
#define __EEPROM_H

#include "flash_stm32.h"
#include "stdint.h"

uint16_t ee_init(void);

uint16_t ee_format(void);

uint16_t ee_erases(uint16_t *);
uint16_t ee_read (uint16_t address, uint16_t *data);
uint16_t ee_write(uint16_t address, uint16_t data);
uint16_t ee_update(uint16_t address, uint16_t data);
uint16_t ee_count(uint16_t *);
uint16_t ee_maxcount(void);

#endif	/* __EEPROM_H */
