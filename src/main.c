#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "driver/gpio.h"

#include "BLETask.h"
void app_main()
{

	gpio_set_direction(GPIO_NUM_2, GPIO_MODE_OUTPUT);

	ble_task_init();

	vTaskDelay(2000 / portTICK_PERIOD_MS);
	gpio_set_level(GPIO_NUM_2, 0);
	vTaskDelay(2000 / portTICK_PERIOD_MS);
	gpio_set_level(GPIO_NUM_2, 1);
	vTaskDelay(2000 / portTICK_PERIOD_MS);
	gpio_set_level(GPIO_NUM_2, 0);
	vTaskDelay(2000 / portTICK_PERIOD_MS);
	gpio_set_level(GPIO_NUM_2, 1);
	while (1)
	{
		vTaskDelay(10000 / portTICK_PERIOD_MS);
		ESP_LOGI("MAIN", "HELLO WORLD");
	}
}