#ifndef __FLASH_STM32_H
#define __FLASH_STM32_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stdint.h"

typedef enum
	{
	FLASH_BUSY        = 1,
	FLASH_ERROR_PG    = 2,
	FLASH_ERROR_WRP   = 3,
	FLASH_ERROR_OPT   = 4,
	FLASH_COMPLETE    = 5,
	FLASH_TIMEOUT     = 6,
	FLASH_BAD_ADDRESS = 7
	} FLASH_Status;

#define IS_FLASH_ADDRESS(ADDRESS) (((ADDRESS) >= 0x08000000) && ((ADDRESS) < 0x0807FFFF))

FLASH_Status FLASH_WaitForLastOp(uint32_t Timeout);
FLASH_Status FLASH_ErasePage(uint32_t Page_Address);
FLASH_Status FLASH_ProgramHalfWord(uint32_t Address, uint16_t Data);

void FLASH_Unlock(void);
void FLASH_Lock(void);

#ifdef __cplusplus
}
#endif

#endif /* __FLASH_STM32_H */
