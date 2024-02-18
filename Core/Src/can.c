#include "can.h"
#include "queues.h"

//Arbitrary CAN IDs
#define CAN_ID 0x69

bms_data_t bms_data;


void init_iroh_can(FDCAN_HandleTypeDef *hcan) {
    can_t fdcan;
    fdcan.callback = receive_msg;
    fdcan.id_list = 0;
    fdcan.id_list_len = 0;
    fdcan.hcan = hcan;

    can_init(&fdcan);
}    

HAL_StatusTypeDef receive_msg(can_t *can) 
{

    FDCAN_RxHeaderTypeDef rx_header;
    uint8_t rx_data[8]; //array of 8 bytes

    if (HAL_FDCAN_GetRxFifoFillLevel(can->hcan, FDCAN_RX_FIFO0) > 0) { //Check if messages are available
        if (HAL_FDCAN_GetRxMessage(can->hcan,FDCAN_RX_FIFO0,&rx_header,rx_data) == HAL_OK) {
            uint32_t message_id = rx_header.Identifier;
            if (message_id == CAN_ID) {
                bms_data.SoC = (uint8_t) rx_data[0];
                bms_data.current = (uint8_t) rx_data[1];
                if (osStatus_t osMessageQueuePut(bms_data_queue *bms_data, 0, 2000) == osOK) //timeout is 2000 ms
                    return HAL_OK;
                else
                    return HAL_ERROR
			}
        }
		return HAL_ERROR;
    } 
	return HAL_BUSY;
}


