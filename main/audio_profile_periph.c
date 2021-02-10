/* Play music from Bluetooth device

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_log.h"

#include "bluetooth_service.h"



void app_main(void)
{
    printf("Online \n");
    bluetooth_service_cfg_t ma_confi={
    .device_name="Ca Marche ?",
    .mode=BLUETOOTH_A2DP_SINK,
    };
    bluetooth_service_start(&ma_confi);
    //audio_element_handle_t bt_stream_reader = bluetooth_service_create_stream();
    //esp_periph_handle_t bt_periph = bluetooth_service_create_periph();
    int count=0;
    while(1){
        printf("en test depuis %i secondes \n",count);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        count+=1;
    }
    bluetooth_service_destroy();
}