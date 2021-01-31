#include <iostream>
#include <freertos/FreeRTOS.h>
#include "esp_spi_flash.h"
#include <freertos/task.h>
#include <esp_task_wdt.h>
#include <string.h>
#include "Cantask.h"
#include <ESP32CAN.h>
#include <CAN_config.h>

CAN_device_t CAN_cfg;
CAN_frame_t tx_frame, rx_frame;
char i = 33;

void sendMessage() {
  tx_frame.data.u8[7] = i;
  printf("sent %d, %.8s\n", i, tx_frame.data.u8);
  ESP32Can.CANWriteFrame(&tx_frame);
}

void checkMessage() {
  if(xQueueReceive(CAN_cfg.rx_queue,&rx_frame, 0)==pdTRUE){

    printf("New %s frame", (rx_frame.FIR.B.FF==CAN_frame_std ? "standard" : "extended"));
    if(rx_frame.FIR.B.RTR==CAN_RTR) printf(" RTR");
    printf(" from 0x%08x, DLC %d\r\n",rx_frame.MsgID,  rx_frame.FIR.B.DLC);
    
    for(int i = 0; i < 8; i++) printf("%c\t", (char)rx_frame.data.u8[i]);
  }
}

void cantask( void *pvParamters){
    tx_frame.FIR.B.FF = CAN_frame_std;
    tx_frame.MsgID = 0x101;
    tx_frame.FIR.B.DLC = 8;
    strcpy((char*)tx_frame.data.u8, "mymsg: ");
    CAN_cfg.speed=CAN_SPEED_1000KBPS;
    CAN_cfg.tx_pin_id = GPIO_NUM_25;
    CAN_cfg.rx_pin_id = GPIO_NUM_26;
    CAN_cfg.rx_queue = xQueueCreate(10,sizeof(CAN_frame_t));
    ESP32Can.CANInit();

    for(;;){
        if (i >= 127) i = 33;
        i++;
        sendMessage();
        checkMessage();
        esp_task_wdt_reset();
        vTaskDelay(500/portTICK_PERIOD_MS);
    }

}

