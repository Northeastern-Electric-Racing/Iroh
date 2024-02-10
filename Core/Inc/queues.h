#include "cmsis_os.h"

#define BMS_DATA_QUEUE_SIZE 8

typedef struct {
	uint8_t SoC;
	uint8_t current;
} bms_data_t;

extern osMessageQueueId_t bms_data_queue;