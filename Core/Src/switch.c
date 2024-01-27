#include "switch.h"

bool get_switch(GPIO_InitTypeDef init, uint8_t pin)
{
    switch (pin)
    {
    case 1:
        return HAL_GPIO_ReadPin(init, SWITCH_1_PIN);
    case 2:
        return HAL_GPIO_ReadPin(init, SWITCH_2_PIN);
    case 3:
        return HAL_GPIO_ReadPin(init, SWITCH_3_PIN);
    case 4:
        return HAL_GPIO_ReadPin(init, SWITCH_4_PIN);
    default:
        return false;
    }
}
