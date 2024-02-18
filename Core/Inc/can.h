#include <stdint.h>
#include "stm32g4xx_hal.h"
#include "fdcan.h"

HAL_StatusTypeDef receive_msg(can_t *hcan);