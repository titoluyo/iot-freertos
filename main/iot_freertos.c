#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

#include "wifi_connect.h"
#include "time_sync.h"
#include "led_control.h" 

/*-----------------------------------------------------------*/

static const char * TAG = "iot_freertos";

/*-----------------------------------------------------------*/

void app_main(void)
{
    ESP_LOGI(TAG, "begin iot_freertos");
    initialize_wifi();
    initialize_sntp();
    blink();
}
