#ifndef INPUT_SWITCH_H
#define INPUT_SWITCH_H

#include <stdbool.h>
#include <stdint.h>
#include "stm32g4xx_hal.h"

#define SWITCH_1_PIN GPIO_PIN_4
#define SWITCH_2_PIN GPIO_PIN_5
#define SWITCH_3_PIN GPIO_PIN_6
#define SWITCH_4_PIN GPIO_PIN_7

bool get_switch(GPIO_InitTypeDef *init, uint8_t pin);

#endif
