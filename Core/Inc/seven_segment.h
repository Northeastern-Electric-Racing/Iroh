#ifndef SEVEN_SEGMENT_H
#define SEVEN_SEGMENT_H

#include <stdint.h>

#include "stm32g4xx_hal.h"
#include "stm32g4xx_hal_i2c.h"

typedef struct {
	uint16_t mem_address;	//internal memory address
	uint8_t data[8];
	uint16_t size;
} i2c_msg_t;

HAL_StatusTypeDef i2c_init(I2C_HandleTypeDef *hi2c);
HAL_StatusTypeDef write_current(I2C_HandleTypeDef *hi2c, uint16_t current);
HAL_StatusTypeDef write_charge(I2C_HandleTypeDef *hi2c, uint16_t charge);

#endif // SEVEN_SEGMENT_H