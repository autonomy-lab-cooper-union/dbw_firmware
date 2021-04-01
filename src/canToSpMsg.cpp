#include <iostream>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/queue.h>
#include <string.h>
#include "Estoptask.h"
#include "queues.h"
#include <ESP32CAN.h>
#include <CAN_config.h>
#include <esp_task_wdt.h>
#include "MessageID.h"
#include "Nodes.h"

CAN_frame_t sp_rx_frame, sp_tx_frame;

void checkCAN() {
  if(xQueueReceive(canToSpMsg,&sp_rx_frame, 0)==pdTRUE){

    printf("New %s frame", (sp_rx_frame.FIR.B.FF==CAN_frame_std ? "standard" : "extended"));
    if(sp_rx_frame.FIR.B.RTR==CAN_RTR) printf(" RTR");
    printf(" from 0x%08x, DLC %d\r\n",sp_rx_frame.MsgID,  sp_rx_frame.FIR.B.DLC);
    printf("Command Received: ");
    for(int i = 0; i < 8; i++) printf("%c", (char)sp_rx_frame.data.u8[i]);
    printf("\n");
    //selects task based on message ID
    switch (sp_rx_frame.MsgID){
      case canmsg_ID::BRK_CMD: //tasks based on commands from ROS
        // emergencyStop();
        break;
      default:
        break;
    }
  }
}

void brakeRecieved(){
    
}

