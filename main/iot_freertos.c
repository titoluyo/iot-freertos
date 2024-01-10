#include <stdio.h>

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "esp_expression_with_stack.h"

#include "sdkconfig.h"
#include "esp_event.h"
#include "esp_wifi.h"
#include "esp_wifi_default.h"
#include "esp_err.h"
#include "esp_netif.h"
#include "esp_sntp.h"
#include "esp_log.h"
#include "nvs_flash.h"

#include "wifi_connect.h"
#include "time_sync.h"

/*-----------------------------------------------------------*/

// static const char * TAG = "iot_freertos";

/*-----------------------------------------------------------*/

void app_main(void)
{
    initialize_wifi();

    initialize_sntp();
}
