#ifndef QUEUES_H
#define QUEUES_H
#include <freertos/FreeRTOS.h>
#include <freertos/queue.h>

//exter
extern QueueHandle_t canToEStop;
extern QueueHandle_t healthPing;
extern QueueHandle_t modeSet;

#endif