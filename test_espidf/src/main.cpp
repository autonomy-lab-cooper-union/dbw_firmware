#include <iostream>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

extern "C" void app_main() {
    for (;;) {
        std::cout << "Howdy world" << std::endl;
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}