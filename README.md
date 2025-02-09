# Controle de Servo Motor com Raspberry Pi Pico

Este projeto demonstra o controle de um servo motor usando PWM no Raspberry Pi Pico. O código configura um sinal PWM na GPIO 22 e permite o controle preciso da posição do servo motor por meio de diferentes funções.

## 📌 Funcionalidades
- Configuração do PWM para controle do servo motor.
- Movimentação para ângulos específicos (0°, 90°, 180°).
- Movimentação suave entre 0° e 180° de forma contínua.

## 🛠️ Hardware Necessário
- Raspberry Pi Pico
- Servo motor compatível com PWM (ex: SG90, MG995)
- Fonte de alimentação adequada para o servo motor
- Fios de conexão

## 🔧 Configuração do PWM
- O sinal PWM tem uma frequência de **50 Hz** (período de 20 ms).
- Os pulsos variam de **500 µs** (0°) a **2400 µs** (180°).

## 📜 Código Explicado
- `setup_pwm()`: Configura a GPIO 22 para gerar o sinal PWM adequado.
- `set_servo_angle(uint32_t pulso_ms)`: Define o tempo de pulso ativo para posicionar o servo.
- `move_180()`, `move_90()`, `move_0()`: Posicionam o servo em ângulos específicos.
- `sweep()`: Movimenta o servo continuamente entre 0° e 180° de forma suave.
- `main()`: Executa os movimentos predefinidos e inicia a movimentação contínua.

## 🚀 Como Usar
1. **Compilar e carregar o código** para o Raspberry Pi Pico.
2. **Conectar o servo motor** corretamente:
   - **VCC** (vermelho) → 5V ou 3.3V do Pico (dependendo do servo)
   - **GND** (preto/marrom) → GND do Pico
   - **Sinal** (amarelo/laranja) → GPIO 22
3. **Executar o código** no Pico.

## 🎥 Vídeo do Experimento
https://youtu.be/nLE-110qzLs.

## 💡 Efeito Visual com LED na GPIO 12
Se esse código fosse utilizado para controlar um LED na GPIO 12, o efeito visual seria uma transição de brilho suave e progressiva. Durante a movimentação do servo, o LED aumenta e diminui gradualmente a intensidade, criando um efeito de "respiração" semelhante ao visto em indicadores de stand-by de dispositivos eletrônicos. Existe também uma tremulação que pode ocorrer quando a frequência do PWM está muito baixa para os LEDs. No código, a frequência foi configurada para 50 Hz, que é ideal para servomotores, mas muito baixa para LEDs.
Os olhos humanos conseguem perceber variações em brilho em frequências abaixo de 100 Hz, especialmente abaixo de 70 Hz.

---
✏️ **Autor:** *Theógenes Gabriel araújo de Andrade*  

