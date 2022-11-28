#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#define LED_PIN     GPIO_NUM_17
#define BUTTON_PIN  GPIO_NUM_35

void soil_humidity(void *pvParameters);