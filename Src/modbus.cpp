/*
 * Copyright © 2011-2012 Stéphane Raimbault <stephane.raimbault@gmail.com>
 *
 * License ISC, see LICENSE for more details.
 *
 * This library implements the Modbus protocol.
 * http://libmodbus.org/
 *
 */

#include "stdio.h"
#include "string.h"
#include "modbus.h"

#define _MODBUS_SLAVE       0
#define _MODBUS_FUNCTION    1
#define _MODBUS_REQ_LENGTH  6
#define _MODBUS_RSP_LENGTH  2

#define _MODBUS_CRC_LENGTH  2

#define _MODBUS_MAX_ADU_LENGTH  128

/* Supported function codes */
#define _FC_READ_HOLDING_REGISTERS    0x03
#define _FC_WRITE_MULTIPLE_REGISTERS  0x10

enum {
	_STEP_FUNCTION = 0x01, _STEP_META, _STEP_DATA
};

static uint16_t crc16(uint8_t *req, uint8_t req_length) {
	uint8_t j;
	uint16_t crc;

	crc = 0xFFFF;
	while (req_length--) {
		crc = crc ^ *req++;
		for (j = 0; j < 8; j++) {
			if (crc & 0x0001)
				crc = (crc >> 1) ^ 0xA001;
			else
				crc = crc >> 1;
		}
	}

	return (crc << 8 | crc >> 8);
}

static int check_integrity(uint8_t *msg, uint8_t msg_length) {
	uint16_t crc_calculated;
	uint16_t crc_received;

	if (msg_length < 2)
		return -1;

	crc_calculated = crc16(msg, msg_length - 2);
	crc_received = (msg[msg_length - 2] << 8) | msg[msg_length - 1];

	/* Check CRC of msg */
	if (crc_calculated == crc_received) {
		return msg_length;
	} else {
		return -1;
	}
}

static int build_response_basis(uint8_t slave, uint8_t function, uint8_t* rsp) {
	rsp[0] = slave;
	rsp[1] = function;

	return _MODBUS_RSP_LENGTH;
}

static uint8_t response_exception(uint8_t slave, uint8_t function,
		uint8_t exception_code, uint8_t *rsp) {
	uint8_t rsp_length;

	rsp_length = build_response_basis(slave, function + 0x80, rsp);

	/* Positive exception code */
	rsp[rsp_length++] = exception_code;

	return rsp_length;
}

Modbus::Modbus(UART_HandleTypeDef* uart, uint8_t slave_id) {
	_slave = slave_id <= 247 ? slave_id : 246;
	_uart = uart;
}

uint32_t Modbus::receive(uint8_t *req, uint8_t _slave) {
	uint8_t i;
	uint8_t length_to_read;
	uint8_t req_index;
	uint8_t step;
	uint8_t function;

	/* We need to analyse the message step by step.  At the first step, we want
	 * to reach the function code because all packets contain this
	 * information. */
	step = _STEP_FUNCTION;
	length_to_read = _MODBUS_FUNCTION + 1;

	req_index = 0;
	while (length_to_read != 0) {

		/* The timeout is defined to ~10 ms between each bytes.  Precision is
		 not that important so I rather to avoid millis() to apply the KISS
		 principle (millis overflows after 50 days, etc) */
		if (!available()) {
			i = 0;
			while (!available()) {
				HAL_Delay(1);
				if (++i == 10) {
					/* Too late, bye */
					return -1;
				}
			}
		}

		req[req_index] = this->read();

		/* Moves the pointer to receive other data */
		req_index++;

		/* Computes remaining bytes */
		length_to_read--;

		if (length_to_read == 0) {
			switch (step) {
			case _STEP_FUNCTION:
				/* Function code position */
				function = req[_MODBUS_FUNCTION];
				if (function == _FC_READ_HOLDING_REGISTERS) {
					length_to_read = 4;
				} else if (function == _FC_WRITE_MULTIPLE_REGISTERS) {
					length_to_read = 5;
				} else {
					/* Wait a moment to receive the remaining garbage */
					flush();
					if (req[_MODBUS_SLAVE] == _slave || req[_MODBUS_SLAVE] == MODBUS_BROADCAST_ADDRESS)
					{
						/* It's for me so send an exception (reuse req) */
						uint8_t rsp_length = response_exception(_slave,
																function,
																MODBUS_EXCEPTION_ILLEGAL_FUNCTION, req);
						send_msg(req, rsp_length);
						return -1 - MODBUS_EXCEPTION_ILLEGAL_FUNCTION;
					}

					return -1;
				}
				step = _STEP_META;
				break;

			case _STEP_META:
				length_to_read = _MODBUS_CRC_LENGTH;

				if (function == _FC_WRITE_MULTIPLE_REGISTERS)
					length_to_read += req[_MODBUS_FUNCTION + 5];

				if ((req_index + length_to_read) > _MODBUS_MAX_ADU_LENGTH) {
					flush();
					if (req[_MODBUS_SLAVE] == _slave||
					req[_MODBUS_SLAVE] == MODBUS_BROADCAST_ADDRESS) {
						/* It's for me so send an exception (reuse req) */
						uint8_t rsp_length = response_exception(_slave,
								function,
								MODBUS_EXCEPTION_ILLEGAL_DATA_VALUE, req);
						send_msg(req, rsp_length);
						return -1 - MODBUS_EXCEPTION_ILLEGAL_FUNCTION;
					}
					return -1;
				}
				step = _STEP_DATA;
				break;
			default:
				break;
			}
		}
	}

	return check_integrity(req, req_index);
}

void Modbus::reply(	uint16_t *tab_reg, uint16_t nb_reg, uint8_t *req,
					uint8_t req_length, uint8_t _slave)
{
	uint8_t slave = req[_MODBUS_SLAVE];
	uint8_t function = req[_MODBUS_FUNCTION];
	uint16_t address = (req[_MODBUS_FUNCTION + 1] << 8) + req[_MODBUS_FUNCTION + 2];
	uint16_t nb = (req[_MODBUS_FUNCTION + 3] << 8) + req[_MODBUS_FUNCTION + 4];
	uint8_t rsp[_MODBUS_MAX_ADU_LENGTH];
	uint8_t rsp_length = 0;

	if (slave != _slave && slave != MODBUS_BROADCAST_ADDRESS) {
		return;
	}

	if (address + nb > nb_reg) {
		rsp_length = response_exception(slave, function,
		MODBUS_EXCEPTION_ILLEGAL_DATA_ADDRESS, rsp);
	} else {
		req_length -= _MODBUS_CRC_LENGTH;

		if (function == _FC_READ_HOLDING_REGISTERS) {
			uint16_t i;

			rsp_length = build_response_basis(slave, function, rsp);
			rsp[rsp_length++] = nb << 1;
			for (i = address; i < address + nb; i++) {
				rsp[rsp_length++] = tab_reg[i] >> 8;
				rsp[rsp_length++] = tab_reg[i] & 0xFF;
			}
		} else {
			uint16_t i, j;

			for (i = address, j = 6; i < address + nb; i++, j += 2) {
				/* 6 and 7 = first value */
				tab_reg[i] = (req[_MODBUS_FUNCTION + j] << 8)
						+ req[_MODBUS_FUNCTION + j + 1];
			}

			rsp_length = build_response_basis(slave, function, rsp);
			/* 4 to copy the address (2) and the no. of registers */
			memcpy(rsp + rsp_length, req + rsp_length, 4);
			rsp_length += 4;
		}
	}

	this->send_msg(rsp, rsp_length);
}

void Modbus::send_msg(uint8_t *msg, uint8_t msg_length) {
	uint16_t crc = crc16(msg, msg_length);

	msg[msg_length++] = crc >> 8;
	msg[msg_length++] = crc & 0x00FF;

	//todo: uart write
	//Serial.write(msg, msg_length);
}

void Modbus::flush(void) {
	uint8_t i = 0;

	//todo:flush incoming serial
	/* Wait a moment to receive the remaining garbage but avoid getting stuck
	 * because the line is saturated */
//    while (Serial.available() && i++ < 10) {
//	Serial.flush();
//	delay(3);
//    }
}

uint8_t Modbus::read() {
	return 0xAB;
}

uint32_t Modbus::available() {
	return 0;
}

int Modbus::update(uint16_t* tab_reg, uint16_t nb_reg) {
	int rc = 0;
	uint8_t req[_MODBUS_MAX_ADU_LENGTH];

	if (available()) {
		rc = receive(req, _slave);
		if (rc > 0) {
			reply(tab_reg, nb_reg, req, rc, _slave);
		}
	}

	/* Returns a positive value if successful,
	 0 if a slave filtering has occured,
	 -1 if an undefined error has occured,
	 -2 for MODBUS_EXCEPTION_ILLEGAL_FUNCTION
	 etc */
	return rc;
}
