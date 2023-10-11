#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

int main(void) {
     stdio_init_all();

    adc_init();
    adc_gpio_init(26);
    adc_select_input(0);
    adc_set_temp_sensor_enabled(true);

    while(1){
        uint16_t raw = adc_read();
        const float conversion = 3.3f / (1<<12);
        float voltage =raw * conversion;
        float temperature = 27 - (voltage - 0.706)/0.001721;
        printf("Temperatura: %f °C\n", temperature);
        sleep_ms(500);
    }

    return 0;
}


