#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
//#include "led_strip.h"
#include "sdkconfig.h"


#define BUZZER_PIN  27
#define PUSH_BUTTON_PIN  33

void app_main(void)
{
    gpio_set_direction(BUZZER_PIN, GPIO_MODE_OUTPUT);   
    gpio_set_direction(PUSH_BUTTON_PIN, GPIO_MODE_INPUT);

    gpio_config_t button_conf = {
        .pin_bit_mask = (1ULL << PUSH_BUTTON_PIN),
        .mode = GPIO_MODE_INPUT,
        //.pull_up_en = GPIO_PULLUP_ENABLE,
        .pull_down_en = GPIO_PULLDOWN_ENABLE,
        .intr_type = GPIO_INTR_DISABLE
    };

    gpio_config(&button_conf);


    while(1) {       
        if (gpio_get_level(PUSH_BUTTON_PIN) == 1)
        {  
            gpio_set_level(BUZZER_PIN, 1);        
        } 
        else
        {
            gpio_set_level(BUZZER_PIN, 0);        
        }

        vTaskDelay(1);
    }
} 