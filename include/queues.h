#ifndef QUEUES_H
#define QUEUES_H
#include <freertos/FreeRTOS.h>
#include <freertos/queue.h>

extern QueueHandle_t canToEStop;
extern QueueHandle_t healthPing;
extern QueueHandle_t modeSet;
extern QueueHandle_t canToHouse;
extern QueueHandle_t canToWatch;

#endif