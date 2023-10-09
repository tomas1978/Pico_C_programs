//LED connected to GP0
//Button on GP1 turns LED on
//Button on GP2 turns LED off
#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"

const uint LED_PIN = 0;
const uint ON_PIN = 1;
const uint OFF_PIN = 2;

int main() {
    stdio_init_all();
    
    gpio_init(LED_PIN);
    gpio_init(ON_PIN);
    gpio_init(OFF_PIN);
    
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_set_dir(ON_PIN, GPIO_IN);
    gpio_set_dir(OFF_PIN, GPIO_IN);
    
    int value;

    while (1) {

        if(gpio_get(ON_PIN)) {
            gpio_put(LED_PIN, 1);
            printf("On button pressed\n");
        }
        if(gpio_get(OFF_PIN)) {
            gpio_put(LED_PIN, 0);
            printf("Off button pressed\n");
        }
        
        sleep_ms(20);
    }

    return 0;
}
