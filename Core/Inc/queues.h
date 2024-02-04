#ifndef QUEUES_H
#define QUEUES_H

#include "cmsis_os.h"

#define BMS_DATA_QUEUE_SIZE 8

typedef struct {
	uint16_t SoC;
	uint16_t current;
} bms_data_t;

extern osMessageQueueId_t bms_data_queue;

#endif