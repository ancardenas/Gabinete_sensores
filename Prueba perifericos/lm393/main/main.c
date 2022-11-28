#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "modulos/soil_humidity.h"




void app_main(void)
{
   xTaskCreate(soil_humidity,"soil_humidity",configMINIMAL_STACK_SIZE*3,NULL,5,NULL);

}
