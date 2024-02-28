#include "can.h"
#include "queues.h"
#include "string.h"

#define BMS_DATA_CAN_ID 0x80

void receive_msg(FDCAN_HandleTypeDef *hfdcan) 
{

    bms_data_t bms_data;
    iroh_error_t e;

    FDCAN_RxHeaderTypeDef *rx_header;
    uint8_t *rx_data;

    if (!HAL_FDCAN_GetRxFifoFillLevel(hfdcan, FDCAN_RX_FIFO0)) {
        e.code = 1;
        strcpy(e.msg, "No msg Recieved");
        osMessageQueuePut(error_queue, &e, 0, 2000);
        return;
    } 

    if (!HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO0, rx_header, rx_data)) {
        e.code = 2;
        strcpy(e.msg, "Cannot get msg");
        osMessageQueuePut(error_queue, &e, 0, 2000);
        return;
    }

    uint32_t message_id = rx_header->Identifier;

    if (message_id == BMS_DATA_CAN_ID) {
        bms_data.SoC = rx_data[0];
        bms_data.current = rx_data[1];
        if (!osMessageQueuePut(bms_data_queue, &bms_data, 0, 2000)) {
            e.code = 3;
            strcpy(e.msg, "BMS data MQ err");
            osMessageQueuePut(error_queue, &e, 0, 2000);
            return;
        }
    }
}

void init_iroh_can(FDCAN_HandleTypeDef *hcan) {
    can_t *fdcan;
    fdcan->callback = receive_msg;
    fdcan->id_list = 0;
    fdcan->id_list_len = 0;
    fdcan->hcan = hcan;

    can_init(fdcan);
}   
