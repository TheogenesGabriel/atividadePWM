#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_PIN 22          // GPIO 22 para controle do servomotor
#define PWM_WRAP 12500        // Valor de "wrap" para o PWM 12500

// Função para configurar o PWM
void setup_pwm() {
    // Configura a GPIO 22 para funcionar como PWM
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);

    // Obtém o slice associado a gpio 22
    uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);

    // Define o valor de "wrap", isto é, o contador máximo do PWM
    pwm_set_wrap(slice_num, PWM_WRAP);

    // Configura o divisor de clock do PWM
    pwm_set_clkdiv(slice_num, 200); // 125 MHz

    // Habilita o PWM 
    pwm_set_enabled(slice_num, true);
}

// Função para definir o ângulo do servomotor, recebe como parametro o período ativo em microssegundos
void set_servo_angle(uint32_t pulso_ms) {
    // Obtém o número do "slice" de PWM associado à GPIO 22
    uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);

    // Converte o tempo de pulso em microssegundos para o valor de contagem do PWM
    uint32_t largura_pulso = (pulso_ms * PWM_WRAP) / 20000; // 20000 µs = 20 ms (período)

    // Define o nível do pulso (duty cycle), realiza o acionamento do servo na posição específica
    pwm_set_chan_level(slice_num, pwm_gpio_to_channel(SERVO_PIN), largura_pulso);
}

// Função para mover o servomotor para 180 graus
void move_180() {
    set_servo_angle(2400); // 2.400 µs = 180 graus
    sleep_ms(5000);        
}

// Função para mover o servomotor para 90 graus
void move_90() {
    set_servo_angle(1470); // 1.470 µs = 90 graus
    sleep_ms(5000);        
}

// Função para mover o servomotor para 0 graus
void move_0() {
    set_servo_angle(500); // 500 µs = 0 graus
    sleep_ms(5000);       
}

// Função para movimentação suave do servomotor entre 0 e 180 graus
void sweep() {
    uint32_t pulse = 500; // Começa em 0 graus (500 µs)
    while (true) {
        // Movimento de 0 a 180 graus
        while (pulse <= 2400) {
            set_servo_angle(pulse); 
            pulse += 5;             
            sleep_ms(10);                 
        }
        // Movimento de 180 a 0 graus
        while (pulse >= 500) {
            set_servo_angle(pulse); 
            pulse -= 5;             
            sleep_ms(10);                 
        }
    }
}

// Função principal
int main() {
    stdio_init_all(); 
    setup_pwm();      

    // Movimentos pré-definidos
    move_180(); // Move para 180 graus e aguarda 5 segundos
    move_90();  // Move para 90 graus e aguarda 5 segundos
    move_0();   // Move para 0 graus e aguarda 5 segundos

    // Inicia a movimentação suave do servomotor
    sweep();

    return 0;
}