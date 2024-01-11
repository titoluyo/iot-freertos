#include <stdio.h>

// #include <stdlib.h>
// #include <stdarg.h>
// #include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
// #include "freertos/semphr.h"
// #include "esp_expression_with_stack.h"
#include "driver/gpio.h"
#include "rom/gpio.h"
// #include "esp_system.h"

// #include "sdkconfig.h"
// #include "esp_event.h"
// #include "esp_wifi.h"
// #include "esp_wifi_default.h"
// #include "esp_err.h"
// #include "esp_netif.h"
// #include "esp_sntp.h"
#include "esp_log.h"
// #include "nvs_flash.h"

#include "wifi_connect.h"
#include "time_sync.h"

/*-----------------------------------------------------------*/

#define LED_PIN_1 2
#define LED_PIN_2 4

static const char * TAG = "iot_freertos";

typedef struct {
    int led_pin;
    TickType_t delay;
} LedBlinkParams;


/*-----------------------------------------------------------*/

void led_blink(void *pvParameters) {
    // int led_pin = (int) pvParameters;
    LedBlinkParams *params = (LedBlinkParams *) pvParameters;

    gpio_config_t io_conf;
    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pin_bit_mask = (1ULL << params->led_pin);
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
    gpio_config(&io_conf);
    
    // gpio_pad_select_gpio(led_pin);
    
    // gpio_reset_pin(led_pin);
    gpio_set_direction (params->led_pin,GPIO_MODE_OUTPUT);
    for( ;; ) 
    {
        gpio_set_level(params->led_pin, 1);
        vTaskDelay(params->delay / portTICK_PERIOD_MS);
        ESP_LOGI(TAG, "Led 2 On");

        gpio_set_level(params->led_pin, 0);
        vTaskDelay(params->delay / portTICK_PERIOD_MS);
        ESP_LOGI(TAG, "Led 2 Off");
    }
    vTaskDelete( NULL );
}

void app_main(void)
{
    initialize_wifi();

    initialize_sntp();

    static LedBlinkParams params1 = { .led_pin = LED_PIN_1, .delay = 1500 };
    static LedBlinkParams params2 = { .led_pin = LED_PIN_2, .delay = 2000 };

    xTaskCreate ( &led_blink, "LED_BLINK_1", 1024*2, &params1, 3, NULL );
    xTaskCreate ( &led_blink, "LED_BLINK_2", 1024*2, &params2, 3, NULL );

}
