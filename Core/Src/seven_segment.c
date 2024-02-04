/* Drivers for the seven segment display */

#include "seven_segment.h"
#include <stdint.h>

//I2C Drivers
HAL_StatusTypeDef i2c_init(I2C_HandleTypeDef *hi2c) {
	return HAL_I2C_Init(hi2c);
}

HAL_StatusTypeDef write_digit(I2C_HandleTypeDef *hi2c, i2c_msg_t *msg) {
	return HAL_I2C_Mem_Write(hi2c, 0111000, msg->mem_address, 0x8, msg->data, msg->size, 1000);
}

HAL_StatusTypeDef write_current(I2C_HandleTypeDef *hi2c, uint16_t current) {
	/* Send first digit */
	i2c_msg_t msg1 = {
		.mem_address = 0x20,
		.data = {(current - (current % 10)) / 10},
		.size = sizeof(int[8]),
	};
	write_digit(hi2c, &msg1);

	/* Send second digit */
	i2c_msg_t msg2 = {
		.mem_address = 0x21,
		.data = {current % 10},
		.size = sizeof(int[8]),
	};
	write_digit(hi2c, &msg2);
	
	return HAL_OK;
}

HAL_StatusTypeDef write_charge(I2C_HandleTypeDef *hi2c, uint16_t charge) {
	/* Send first digit */
	i2c_msg_t msg1 = {
		.mem_address = 0x22,
		.data = {(charge - (charge % 10)) / 10},
		.size = sizeof(int[8]),
	};
	write_digit(hi2c, &msg1);

	/* Send second digit */
	i2c_msg_t msg2 = {
		.mem_address = 0x23,
		.data = {charge % 10},
		.size = sizeof(int[8]),
	};
	write_digit(hi2c, &msg2);

	return HAL_OK;
}

//RTOS Task for sending BMS data to the 7-seg

const osThreadAttr_t send_bms_data_attributes = {
	.name = "SendBmsData",
	.stack_size = 128 * 8,
	.priority = (osPriority_t)osPriorityAboveNormal4
};

void vSendBmsData(void* pv_params) {
	for(;;) {

	}
}