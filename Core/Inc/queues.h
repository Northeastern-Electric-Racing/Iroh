#ifndef QUEUES_H
#define QUEUES_H

#include "cmsis_os.h"

#define BMS_DATA_QUEUE_SIZE 8

typedef struct {
	uint8_t SoC;
	uint8_t current;
} bms_data_t;

extern osMessageQueueId_t bms_data_queue;

#define ERROR_QUEUE_SIZE 8

typedef struct {
	uint8_t code;
	char msg[20];
} iroh_error_t;

extern osMessageQueueId_t error_queue;

#endif