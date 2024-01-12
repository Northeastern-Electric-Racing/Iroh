#include "seven_segment.h"
#include <stdint.h>

/* Global i2c config */
I2C_InitTypeDef i2c;

/* I2C timing register value *sepcifically* for the MAX6958AAEE+T */
i2c.Timing = 0x00813F50;
i2c.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
i2c.DualAddressMode = I2C_DUALADDRESS_DISABLE;
i2c.GeneralCallMode = I2C_GENERALCALL_DISABLE;
i2c.OwnAddress1 = 0x69;

HAL_StatusTypeDef i2c_init() {
	HAL_I2C_Init(*i2c);
}

HAL_StatusTypeDef write_digit(i2c_msg_t *msg) {
	return HAL_I2C_Mem_Write(*i2c, 0111000, msg->mem_address, 0x8, msg->data, msg->size, 1000);
}

HAL_StatusTypeDef write_current(uint16_t current) {
	/* Send first digit */
	i2c_msg_t msg;
	msg.mem_address = 0x20;
	msg.data = (current - (current % 10)) / 10;
	msg.size = sizeof(msg.data);
	write_digit(msg);

	/* Send second digit */
	msg.mem_address = 0x21;
	msg.data = current % 10;
	msg.size = sizeof(msg.data);
	write_digit(msg);
}

HAL_StatusTypeDef write_charge(uint16_t charge) {
	/* Send first digit */
	i2c_msg_t msg;
	msg.mem_address = 0x20;
	msg.data = (charge - (charge % 10)) / 10;
	msg.size = sizeof(msg.data);
	write_digit(msg);

	/* Send second digit */
	msg.mem_address = 0x24;
	msg.data = charge % 10;
	msg.size = sizeof(msg.data);
	write_digit(msg);
}