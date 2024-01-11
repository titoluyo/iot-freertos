#ifndef LED_CONTROL_H
#define LED_CONTROL_H

#include "freertos/FreeRTOS.h"

#define LED_PIN_1 2
#define LED_PIN_2 4

typedef struct {
    int led_pin;
    TickType_t delay;
} LedBlinkParams;

void config_pin(int pin);
void led_blink(void *pvParameters);
void blink(void);

#endif // LED_CONTROL_H
