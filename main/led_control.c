#include "led_control.h" 

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

static const char * TAG = "led_control";

void config_pin(int pin) {
    gpio_config_t io_conf;
    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pin_bit_mask = (1ULL << pin);
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
    gpio_config(&io_conf);
}

void led_blink(void *pvParameters) {
    LedBlinkParams *params = (LedBlinkParams *) pvParameters;

    config_pin(params->led_pin);
    
    gpio_set_direction (params->led_pin,GPIO_MODE_OUTPUT);
    for( ;; ) 
    {
        gpio_set_level(params->led_pin, 1);
        vTaskDelay(params->delay / portTICK_PERIOD_MS);
        ESP_LOGI(TAG, "Led %d On", params->led_pin);

        gpio_set_level(params->led_pin, 0);
        vTaskDelay(params->delay / portTICK_PERIOD_MS);
        ESP_LOGI(TAG, "Led %d Off", params->led_pin);
    }
    vTaskDelete( NULL );
}

void blink(void)
{
    static LedBlinkParams params1 = { .led_pin = LED_PIN_1, .delay = 1500 };
    static LedBlinkParams params2 = { .led_pin = LED_PIN_2, .delay = 2000 };

    xTaskCreate ( &led_blink, "LED_BLINK_1", 1024*2, &params1, 3, NULL );
    xTaskCreate ( &led_blink, "LED_BLINK_2", 1024*2, &params2, 3, NULL );
}
