#include "freertos/FreeRTOS.h"


#include "freertos/task.h"
#include "driver/gpio.h"
#define LED_PIN     GPIO_NUM_17
#define BUTTON_PIN  GPIO_NUM_35

void soil_humidity(void *pvParameters){
    
       gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);   
    gpio_set_direction(BUTTON_PIN, GPIO_MODE_INPUT);
    while(1) {       
        if (gpio_get_level(BUTTON_PIN) == 0) {  // If button is pressed
            gpio_set_level(LED_PIN, 1);         // Turn the LED on
        } else {
            gpio_set_level(LED_PIN, 0);         // Turn the LED off
        }
        vTaskDelay(1); // Add 1 tick delay (10 ms) so that current task does not starve idle task and trigger watchdog timer
    }
}