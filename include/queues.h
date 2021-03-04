#ifndef QUEUES_H
#define QUEUES_H
#include <freertos/FreeRTOS.h>
#include <freertos/queue.h>

enum taskQueues{
    spMsgToCAN,
    estopToCAN,
    houseToCAN,
    watchToCAN,
    numQueues
};

extern QueueHandle_t canToEStop;
extern QueueHandle_t healthPing;
extern QueueHandle_t modeSet;
extern QueueHandle_t canToHouse;
extern QueueHandle_t canToWatch;
extern QueueHandle_t taskToCAN[taskQueues::numQueues];

#endif

