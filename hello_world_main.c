/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
//#include "esp_spi_flash.h"
#include "driver/gpio.h"
#include "nvs_flash.h"

#define BLINK_GPIO_25 25
#define BLINK_GPIO_27 27

void hello_task(void *pvParameter)
{
    printf("Hello world!\n");

    vTaskDelay(1000 / portTICK_PERIOD_MS);

    /* Print chip information */
 /*  esp_chip_info_t chip_info;
    esp_chip_info(&chip_info);
    printf("This is %s chip with %d CPU core(s), WiFi%s%s, ",
            CONFIG_IDF_TARGET,
            chip_info.cores,
            (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
            (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");

    printf("silicon revision %d, ", chip_info.revision);

    printf("%dMB %s flash\n", spi_flash_get_chip_size() / (1024 * 1024),
            (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");

    printf("Minimum free heap size: %d bytes\n", esp_get_minimum_free_heap_size());*/
  /*  for (int i = 10; i >= 0; i--) {
    			        printf("Restarting in %d seconds...\n", i);
    			        vTaskDelay(1000 / portTICK_PERIOD_MS);
    			    }
    			    printf("Restarting now.\n");
    			    fflush(stdout);
    			    esp_restart();*/

}
void blink_task(void *pvParameter)
{
 	gpio_pad_select_gpio(BLINK_GPIO_25);
 	gpio_pad_select_gpio(BLINK_GPIO_27);

 	gpio_set_direction(BLINK_GPIO_25, GPIO_MODE_OUTPUT);
 	gpio_set_direction(BLINK_GPIO_27, GPIO_MODE_OUTPUT);


		gpio_set_level(BLINK_GPIO_25, 0);
		gpio_set_level(BLINK_GPIO_27, 1);
		 for (int i = 10; i >= 0; i--) {
		    			        printf("Restarting in %d seconds...\n", i);
		    			        vTaskDelay(1000 / portTICK_PERIOD_MS);
		    			    }
		 printf("Restarting now.\n");
		vTaskDelay(1000 / portTICK_PERIOD_MS);


		gpio_set_level(BLINK_GPIO_25, 1);
		gpio_set_level(BLINK_GPIO_27, 0);
		vTaskDelay(1000 / portTICK_PERIOD_MS);


}

void app_main()
{
	while(1)
	{



		nvs_flash_init();
	    xTaskCreate(&hello_task,"hello_task", 1024,NULL, 2,NULL);
		xTaskCreate(&blink_task,"blink_task", 1024,NULL, 2,NULL);
	}

}




