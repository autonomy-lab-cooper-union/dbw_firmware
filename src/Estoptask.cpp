#include <iostream>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/queue.h>
#include "Estoptask.h"
#include "queues.h"
#include <ESP32CAN.h>
#include <CAN_config.h>
#include <esp_task_wdt.h>
#include "MessageID.h"

CAN_frame_t es_rx;

void emergencyStop(){
  //Dummy function for now
  printf("EMERGENCY STOP\n");
}

void checkCAN() {
  if(xQueueReceive(canToEStop,&es_rx, 0)==pdTRUE){

    printf("New %s frame", (es_rx.FIR.B.FF==CAN_frame_std ? "standard" : "extended"));
    if(es_rx.FIR.B.RTR==CAN_RTR) printf(" RTR");
    printf(" from 0x%08x, DLC %d\r\n",es_rx.MsgID,  es_rx.FIR.B.DLC);
    printf("Estoptask received: ");
    for(int i = 0; i < 8; i++) printf("%c", (char)es_rx.data.u8[i]);
    printf("\n");
    //selects task based on message ID
    switch (es_rx.MsgID){
      case taskID::e_stop:
        emergencyStop();
        break;
      default:
        break;
    }
  }
}
void estoptask(void *pvParameters){
  for(;;){
    checkCAN();
    esp_task_wdt_reset();
    vTaskDelay(250/portTICK_PERIOD_MS);
  }
}
