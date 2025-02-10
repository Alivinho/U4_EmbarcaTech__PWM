#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_PIN 22  

void setup_pwm(uint gpio) {
    gpio_set_function(gpio, GPIO_FUNC_PWM);  
    uint slice = pwm_gpio_to_slice_num(gpio);
    
    // Clock base da Raspberry Pi Pico = 125 MHz
    float clkdiv = 125.0e6 / (50.0 * 20000.0);  // Para obter um período de 20ms
    pwm_set_clkdiv(slice, clkdiv);  

    uint wrap = 20000;  
    pwm_set_wrap(slice, wrap);

    pwm_set_enabled(slice, true);  // Ativa o PWM
}

void set_servo_pwm(uint gpio, uint us) {
    uint slice = pwm_gpio_to_slice_num(gpio);
    uint wrap = 20000;  // Obtém o wrap atual

    // Calcula o duty cycle correto
    uint duty = (us * wrap) / 20000;
    pwm_set_gpio_level(gpio, duty);
}

int main() {
    stdio_init_all();
    setup_pwm(SERVO_PIN);

    while (1) {
        set_servo_pwm(SERVO_PIN, 2400);  // 2400us → 180º
        sleep_ms(2000);

        set_servo_pwm(SERVO_PIN, 1470);  // 1470us → ~90º
        sleep_ms(2000);

        set_servo_pwm(SERVO_PIN, 500);  // 500us → 0º
        sleep_ms(2000);
    }
}
