#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <ultrasonic.h>
#include <esp_err.h>
#include "driver/gpio.h"
#include "main.h"
#include "modulos/ultrasonido.h"
#include "modulos/blink.h"
#include "modulos/soil_humidity.h"
#include "modulos/dht11.h"

#include"actuadores/vent.h"

#include "hmi/buttonRead.h"
#include "hmi/Display.h"
#include "hmi/font8x8_basic.h"
#include "hmi/ssd1306.h"

#include "communication/communication.h"


// estructura definida en Display.h, interfaz inicial
Screens screenSelected = S_WellcomeUi;

// Estructura parameters definida en main.h
Parameters MainLog;    // Instancia para llevar el log.
Parameters parameters; // Instancia para llevar los parametros que registra el usuario, la base para el control.

Parameters RangoMaxUiCustom; //
Parameters RangoMinUiCustom; // Aquí se guardará el rango máximo de cada variable, se usa solo en la interfaz Custom

Parameters BufferForParameters; // Donde se van a guardar los parametros mientras que el usuario los cambia, antes de modificarlos definitivamente.

Parameters defaultPlant1; // Parametros para las plantas
Parameters defaultPlant2;
Parameters defaultPlant3;

bool alarmFlag; // para la alarma, cada modulo
AlarmMessage alarmMessage; /*Estructura definida en dislplay.h, contiene las 8 lineas
de 16 caracteres que se pueden mostrar en el display */


void app_main()
{   
    //set_PWM();
    //set_timer();

    /*xTaskCreate(ultrasonic_test, "ultrasonic_test", configMINIMAL_STACK_SIZE * 3, NULL, 3, NULL);
    xTaskCreate(blink,"blink",configMINIMAL_STACK_SIZE * 3, NULL, 4, NULL);
    xTaskCreate(soil_humidity,"soil_humidity",configMINIMAL_STACK_SIZE*3,NULL,5,NULL);*/
    xTaskCreate(dht11,"dht11",configMINIMAL_STACK_SIZE*3,NULL, 5, NULL);
    xTaskCreate(logUpdate,"logUpdate",configMINIMAL_STACK_SIZE*3,NULL,5,NULL);
    xTaskCreate(communication,"communication",configMINIMAL_STACK_SIZE*3,NULL,5,NULL);
    /*while (1)
    {
        printf("Temperatura %fC \n",temp);
        vTaskDelay(100);
        if(temp>22){
            setDuty(900);
            vTaskDelay(200);
        }else{
            setDuty(0);
            
        }
    
    
    }
    
        printf("Temperatura %.1f%%",temp);*/
    SetComun();       // iniciando el I2c y los gpios del grupo de comunicaciones
   variablesInit(); // inizializando las variables

   while (1) // lo que esta en el main sería el main task (creo:v)
   {
    
      /*#Task1
      llamando la interfaz de usuario, pide como parametros la Screen a mostrar y todas
      las variables que usamos en el main
      Adentro de ella estaría la subtask "escucha a los botones"*/
      UserInterface(&screenSelected, &parameters, &BufferForParameters, &MainLog, &defaultPlant1, &defaultPlant2, &defaultPlant3, &RangoMaxUiCustom, &RangoMinUiCustom);

      /*#Task2
      Alarma personalizada, cada modulo debe encargarse de encender y apagar esta alarma
      dale valor al puntero de boolFlag.
      Cuando más de un modulo necesite encender la alarma se me ocurre hacer una QUEUE
       de alarmas, para ir mostrandolas todas */
      Alarm(alarmMessage,alarmFlag);
   
   }

}

void variablesInit()
{
   // inicializando el log (##Funcion del grupo de sensores)
   MainLog.temperatura = 0;
   MainLog.humedad = 0;
   MainLog.humedadSuelo = 0;
   MainLog.T_iluminacion = 0;
   // inicialización de parametros
   parameters.temperatura = 0;
   parameters.humedad = 0;
   parameters.humedadSuelo = 0;
   parameters.T_iluminacion = 0;
   // Rangos para la personalización
   RangoMaxUiCustom.temperatura = 70;
   RangoMaxUiCustom.humedad = 80;
   RangoMaxUiCustom.humedadSuelo = 80;
   RangoMaxUiCustom.T_iluminacion = 24;

   RangoMinUiCustom.temperatura = 12;
   RangoMinUiCustom.humedad = 40;
   RangoMinUiCustom.humedadSuelo = 30;
   RangoMinUiCustom.T_iluminacion = 1;

   // inicialización del Buffer
   BufferForParameters=RangoMinUiCustom;

   // Parametros de las plantas
   defaultPlant1.temperatura = 55;
   defaultPlant1.humedad = 18;
   defaultPlant1.humedadSuelo = 25;
   defaultPlant1.T_iluminacion = 11;

   defaultPlant2.temperatura = 25;
   defaultPlant2.humedad = 33;
   defaultPlant2.humedadSuelo = 32;
   defaultPlant2.T_iluminacion = 24;

   defaultPlant3.temperatura = 70;
   defaultPlant3.humedad = 80;
   defaultPlant3.humedadSuelo = 80;
   defaultPlant3.T_iluminacion = 24;

   // inicializando la alarma
   alarmFlag=false;
   strcpy(alarmMessage.line0, "     Esto      ");
   strcpy(alarmMessage.line1, "     Es        ");
   strcpy(alarmMessage.line2, "     Una       ");
   strcpy(alarmMessage.line3, "     Alarma    ");
   strcpy(alarmMessage.line4, "     De        ");
   strcpy(alarmMessage.line5, "     Prueba    ");
   strcpy(alarmMessage.line6, "     ---       ");
   strcpy(alarmMessage.line7, "     Saludos   ");
}
void logUpdate(void *pvParameters){
    while (1)
    {
    MainLog.temperatura=getTemp();
    vTaskDelay(pdMS_TO_TICKS(100));
    }
    
    
}