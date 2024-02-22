#ifndef CAN_H
#define CAN_H

#include <stdint.h>
#include "stm32g4xx_hal.h"
#include "fdcan.h"
#include <assert.h>
#include <stdlib.h>

can_t* init_iroh_can(FDCAN_HandleTypeDef *hcan);
void receive_msg(FDCAN_HandleTypeDef *hfdcan);

#endif