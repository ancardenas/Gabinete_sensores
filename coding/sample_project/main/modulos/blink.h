

#define led1 15


esp_err_t init_led(void);
esp_err_t blink_led(void);
void blink(void *pvParameters);