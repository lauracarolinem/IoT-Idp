#include <stdio.h>
#include <stdbool.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "ultrasonic.h"
#include <esp_err.h>

#define TRIG_PIN 26
#define ECHO_PIN 25
#define LED_PIN 18
#define DISTANCE_THRESHOLD 500 // centimetros

void ultrasonic_test(void *pvParameters)
{
    ultrasonic_sensor_t sensor = {
        .trigger_pin = TRIG_PIN,
        .echo_pin = ECHO_PIN};

    ultrasonic_init(&sensor);
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

    while (true)
    {
        float distance;
        esp_err_t res = ultrasonic_measure(&sensor, DISTANCE_THRESHOLD, &distance);
        if (res != ESP_OK)
        {
            printf("Error %d: ", res);
            switch (res)
            {
            case ESP_ERR_ULTRASONIC_PING:
                printf("Cannot ping (device is in invalid state)\n");
                break;
            case ESP_ERR_ULTRASONIC_PING_TIMEOUT:
                printf("Ping timeout (no device found)\n");
                break;
            case ESP_ERR_ULTRASONIC_ECHO_TIMEOUT:
                printf("Echo timeout (i.e. distance too big)\n");
                break;
            default:
                printf("%s\n", esp_err_to_name(res));
            }
        }
        else
        {
            printf("Distance: %0.04f cm\n", distance*100);
            if (distance*100 <= 10.0)
            {
                gpio_set_level(LED_PIN, 1);
            }else{
                gpio_set_level(LED_PIN, 0);
            }
        }

        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

void app_main()
{
    xTaskCreate(ultrasonic_test, "ultrasonic_test", configMINIMAL_STACK_SIZE * 3, NULL, 5, NULL);
}