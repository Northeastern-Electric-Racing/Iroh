#include "can.h"
#include "queues.h"

#define BMS_DATA_CAN_ID 0x69

bms_data_t bms_data;


can_t* init_iroh_can(FDCAN_HandleTypeDef *hcan) {

	assert(hcan);

	// iroh CAN struct
    can_t* ican = malloc(sizeof(can_t));
	assert(ican);

	ican->hcan         = hcan;
    ican->callback    = receive_msg;
    ican->id_list     = 0;
    ican->id_list_len = 0;

    assert(can_init(ican));

	return ican;
}



void receive_msg(FDCAN_HandleTypeDef *hfdcan) 
{

    FDCAN_RxHeaderTypeDef rx_header;
    uint8_t rx_data[8]; //array of 8 bytes

    if (HAL_FDCAN_GetRxFifoFillLevel(hfdcan, FDCAN_RX_FIFO0) > 0) { //Check if messages are available
        
		if (HAL_FDCAN_GetRxMessage(hfdcan,FDCAN_RX_FIFO0,&rx_header,rx_data) == HAL_OK) {

            uint32_t message_id = rx_header.Identifier;

            if (message_id == BMS_DATA_CAN_ID) {
                bms_data.SoC = (uint8_t) rx_data[0];
                bms_data.current = (uint8_t) rx_data[1];
                if (!osMessageQueuePut(bms_data_queue, &bms_data, 0, 2000) == osOK) {
					//throw error
				}
			}
        }
	}
}


