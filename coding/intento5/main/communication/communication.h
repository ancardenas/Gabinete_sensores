#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"
#include "freertos/timers.h"
#include "nvs_flash.h"
#include "esp_random.h"
#include "esp_event.h"
#include "esp_netif.h"
#include "esp_wifi.h"
#include "esp_log.h"
#include "esp_mac.h"
#include "esp_now.h"
#include "esp_crc.h"


#define CONFIG_ESPNOW_CHANNEL 1
#define ESPNOW_WIFI_IF  ESP_IF_WIFI_AP

// THE MAC Address of receiver 
//uint8_t broadcastAddress[] = {0x58, 0xbf, 0x25, 0x18, 0x8, 0x1}; //AQUI CAMBIAR DIRECCION MAC DE LA OTRA ESP
//uint8_t broadcastAddress[] = {0x94, 0xb9, 0x7e, 0xce, 0x1f, 0x2d};
//uint8_t broadcastAddress[] = {0x08, 0x3a, 0xf2, 0xbb, 0x1c, 0xd1};

// Structure example to send data
// Must match the receiver structure
typedef struct struct_message {
    float state;
    float inf;
} struct_message;

// structure for messages to be sent
//struct_message msg_send;
// structure to hold incoming readings
//struct_message msg_recv;


static void wifi_init(void);
static void espnow_send_cb(const uint8_t *mac_addr, esp_now_send_status_t status);
static void espnow_recv_cb(const uint8_t *mac_addr, const uint8_t *data, int len);
static void espnow_init(void);
void communication(void *pvParameters);