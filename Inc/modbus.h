/*
 * Copyright © 2011 Stéphane Raimbault <stephane.raimbault@gmail.com>
 *
 * License ISC, see LICENSE for more details.

 * This library implements the Modbus protocol.
 * http://libmodbus.org/
 *
 */

#ifndef Modbusino_h
#define Modbusino_h

#include "stdio.h"
#include "stm32f1xx_hal.h"

#define MODBUS_BROADCAST_ADDRESS 0

/* Protocol exceptions */
#define MODBUS_EXCEPTION_ILLEGAL_FUNCTION     1
#define MODBUS_EXCEPTION_ILLEGAL_DATA_ADDRESS 2
#define MODBUS_EXCEPTION_ILLEGAL_DATA_VALUE   3

class Modbus {
public:
    Modbus(UART_HandleTypeDef* uart, uint8_t slave_id);
    int update(uint16_t *tab_reg, uint16_t nb_reg);
private:
    UART_HandleTypeDef* _uart;
    uint8_t _slave;

    uint32_t available();
    uint32_t receive(uint8_t *req, uint8_t _slave);
    uint8_t read();
    void flush(void);

    void reply( uint16_t *tab_reg, uint16_t nb_reg,
    			uint8_t *req, uint8_t req_length, uint8_t _slave );

    void send_msg(uint8_t *msg, uint8_t msg_length);
};

#endif
