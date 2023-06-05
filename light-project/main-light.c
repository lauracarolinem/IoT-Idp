#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "sdkconfig.h"
#include "driver/adc.h"

#define LED_PIN 18
#define LIGHT_PIN 34
#define ANALOG_THRESHOLD 300

void light_sensor_task(void *pvParameters)
{
    adc1_config_width(ADC_WIDTH_BIT_12);
    adc1_config_channel_atten(ADC1_CHANNEL_6, ADC_ATTEN_DB_11);

    esp_rom_gpio_pad_select_gpio(LED_PIN);
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

    while (1)
    {
        int analogValue = adc1_get_raw(ADC1_CHANNEL_6);
        printf("Analog value: %d\n", analogValue);

        if (analogValue < ANALOG_THRESHOLD)
            gpio_set_level(LED_PIN, 1); // turn on LED
        else
            gpio_set_level(LED_PIN, 0); // turn off LED

        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

void app_main()
{
    adc1_config_width(ADC_WIDTH_BIT_12);
    adc1_config_channel_atten(LIGHT_PIN, ADC_ATTEN_DB_11);

    xTaskCreate(light_sensor_task, "light_sensor_task", 2048, NULL, 5, NULL);
}
