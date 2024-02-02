#include "cmsis_os.h"
#include "seven_segment.h"
#include "fdcan.h"

void vSendBmsData(void* pv_params);
extern osThreadId_t send_bms_data_handle;
extern const osThreadAttr_t send_bms_data_attributes;