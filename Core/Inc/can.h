#ifndef CAN_H
#define CAN_H

#include <stdint.h>
#include "stm32g4xx_hal.h"
#include "fdcan.h"

void init_iroh_can(FDCAN_HandleTypeDef *hcan);

#endif