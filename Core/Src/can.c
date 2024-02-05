#include "can.h";

//Arbitrary CAN IDs
#define VOLTAGE_CAN_ID 10
#define CURRENT_CAN_ID 20

HAL_StatusTypeDef receive_msg(can_t *can) 
{

    FDCAN_RxHeaderTypeDef rx_header;
    uint8_t rx_data[8]; //array of 8 bytes 

    if (HAL_FDCAN_GetRxFifoFillLevel(can->hcan, FDCAN_RX_FIFO0) > 0) { //Check if messages are available
        if (HAL_FDCAN_GetRxMessage(can->hcan,FDCAN_RX_FIFO0,&rx_header,rx_data) == HAL_OK) {
            uint32_t message_id = rx_header.Identifier;
            if (message_id == VOLTAGE_CAN_ID) {
				//process voltage ID
			}
			if (message_id == CURRENT_CAN_ID) {
				//process current ID
			}
			return HAL_OK;
        }
		return HAL_ERROR;
    } 
	return HAL_BUSY;
}

//initialize can
can_t fdcan;
fdcan.callback = receive_msg;

can_init(&fdcan);    

