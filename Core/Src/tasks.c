/* All RTOS tasks are defined here */

#include "tasks.h"
#include "queues.h"
#include "seven_segment.h"

static I2C_HandleTypeDef* hi2c;

osThreadId_t send_bms_data_handle;
const osThreadAttr_t send_bms_data_handle_attributes = {
	.name = "SendBmsData",
	.stack_size = 128 * 8,
	.priority = (osPriority_t)osPriorityAboveNormal4
};

void vSendBmsData(void* pv_params) {

	hi2c = (I2C_HandleTypeDef*)pv_params;
	bms_data_t bms_data;

	for (;;) {
		if (osMessageQueueGet(bms_data_queue, &bms_data, NULL, 0U)) {
			write_current(hi2c, bms_data.current);
			write_charge(hi2c, bms_data.SoC);
		}
	}
}