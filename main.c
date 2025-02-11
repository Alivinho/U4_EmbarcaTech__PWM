#include "pico/stdlib.h"
#include "hardware/pwm.h"

// Definição da GPIO do Servo Motor
#define SERVO_PIN 22  

// Protótipos das Funções Uitlizadas
void setup_pwm(uint gpio);
void set_servo_pwm(uint gpio, uint us);


int main() {
    stdio_init_all();
    setup_pwm(SERVO_PIN);

    // Movimentação do Servo Motor para os Ângulos correpondentes 
    set_servo_pwm(SERVO_PIN, 2400);  // 2400us → 180º
    sleep_ms(5000);

    set_servo_pwm(SERVO_PIN, 1470);  // 1470us → ~90º
    sleep_ms(5000);

    set_servo_pwm(SERVO_PIN, 500);  // 500us → 0º
    sleep_ms(5000);

    while (1) {

        // Movimentação periódica suave
        for (uint duty = 500; duty <= 2400; duty += 5) {
            set_servo_pwm(SERVO_PIN, duty);
            sleep_ms(10);
        }
        
        for (uint duty = 2400; duty >= 500; duty -= 5) {
            set_servo_pwm(SERVO_PIN, duty);
            sleep_ms(10);
        }
    }
}

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

    // Calculo do Duty Cicle 
    uint duty = (us * wrap) / 20000;
    pwm_set_gpio_level(gpio, duty);
}
