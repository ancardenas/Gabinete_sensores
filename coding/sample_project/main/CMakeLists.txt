idf_component_register(SRCS "main.c" SRCS "modulos/blink.c" SRCS "modulos/ultrasonido.c" SRCS "modulos/soil_humidity.c" SRCS "modulos/dht11.c"
                       SRCS "actuadores/vent.c"
                       SRCS "hmi/buttonRead.c" SRCS "hmi/Display.c" SRCS "hmi/ssd1306.c" SRCS "hmi/ssd1306_i2c.c" SRCS "hmi/ssd1306_spi.c"
                       SRCS "communication/communication.c" 
                    INCLUDE_DIRS ".")
