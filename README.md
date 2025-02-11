# Controle de Servo Motor com Raspberry Pi Pico

Este projeto demonstra como controlar um servo motor utilizando uma Raspberry Pi Pico. O código foi desenvolvido em C/C++ utilizando o SDK da Raspberry Pi Pico (`pico-sdk`). O servo motor é controlado por meio de sinais PWM (Pulse Width Modulation), permitindo movimentá-lo para diferentes ângulos.

## Objetivo

O objetivo deste projeto é fornecer um exemplo prático de como controlar um servo motor com a Raspberry Pi Pico, utilizando PWM para definir a posição do servo em diferentes ângulos (0°, 90° e 180°). Além disso, o projeto inclui uma movimentação periódica suave do servo, demonstrando como criar transições suaves entre posições.

## Estrutura do Projeto

O projeto consiste em um único arquivo de código-fonte (`main.c`), que contém toda a lógica necessária para controlar o servo motor. Abaixo está a estrutura do projeto:




## Instruções de Uso

### Conexões

Conecte o servo motor à Raspberry Pi Pico da seguinte forma:

- **Fio Vermelho (VCC)**: Conecte ao pino `VBUS` (5V) ou `VSYS` da Pico.
- **Fio Preto (GND)**: Conecte ao pino `GND` da Pico.
- **Fio Amarelo/Laranja (Sinal)**: Conecte ao pino `GPIO 22` da Pico.

### Compilação e Upload

1. Clone o repositório (se aplicável) ou crie um novo projeto com o código fornecido.
2. Configure o ambiente de desenvolvimento com o `pico-sdk`. Para mais detalhes, consulte a [documentação oficial](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf).
3. Compile o projeto usando `cmake` e `make`:

   ```bash
   mkdir build
   cd build
   cmake ..
   make

4. Conecte a Raspberry Pi Pico ao computador no modo de bootloader (segure o botão BOOTSEL enquanto conecta o USB).

5. Copie o arquivo .uf2 gerado para a Pico

## Explicação do Código

### Funções Principais

- setup_pwm(uint gpio):
  * Configura o pino GPIO especificado para funcionar como saída PWM.
  * Define o divisor de clock (clkdiv) para obter um período de 20 ms (frequência de 50 Hz, comum para servos).
  * Configura o valor de wrap para 20000, correspondente ao período de 20 ms.

- set_servo_pwm(uint gpio, uint us):
  * Define o duty cycle do PWM com base no tempo em microssegundos (us).
  * Converte o valor de us para o nível de duty cycle correspondente.

## Link do Vídeo

