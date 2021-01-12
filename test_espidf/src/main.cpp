#include <iostream>
#include <freertos/FreeRTOS.h>
#include "esp_spi_flash.h"
#include <freertos/task.h>

extern "C" void app_main() {
    for (;;) {
        std::cout << "Howdy world from core " << xPortGetCoreID() << std::endl;
        vTaskDelay(500 / portTICK_PERIOD_MS);
        /* Print chip information */
        esp_chip_info_t chip_info;
        esp_chip_info(&chip_info);
        printf("This is ESP32 chip with %d CPU cores, WiFi%s%s, ",
                chip_info.cores,
                (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
                (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");

        printf("silicon revision %d, ", chip_info.revision);

        printf("%dMB %s flash\n", spi_flash_get_chip_size() / (1024 * 1024),
                (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");
        fflush(stdout);
    }
}