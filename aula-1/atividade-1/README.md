
# Atividade X — Nome da atividade

## Plataforma e link


- Plataforma: Tinkercad, Wokwi ou outra
- Link: COLE_O_LINK_AQUI
https://www.tinkercad.com/things/7MuT3povH90/editel?returnTo=%2Fclassrooms%2F7OjAnbHLZRm%2Factivities%2F4iyOzX8sN5v%3Fview%3Dwork%26type%3Dall

## Imagem do protótipo
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/5e86b151-39b6-40ea-9998-80374b31b197" />

![Estrutura do protótipo](prototipo.png)

## Componentes utilizados

- Arduino Uno
- Liste os demais componentes
  
1 LED vermelho
1 LED amarelo
1 LED verde
1 botão (push button)
3 resistores de 220 Ω
1 resistor de 10 kΩ (para o botão, caso não utilize INPUT_PULLUP)
Jumpers



1 protoboard
## Como funciona

Explique os estados do sistema, o que provoca cada mudança de estado e o comportamento dos componentes.

Como funciona o sistema
O semáforo começa com o LED vermelho aceso. Ao pressionar o botão, ele muda para verde, depois amarelo e, em seguida, volta para vermelho. Cada pressionamento permite apenas uma mudança de estado. O estado atual também é exibido no Monitor Serial.
Dados do sistema
- Entradas: botão conectado ao pino 2.
- Saídas: LEDs vermelho (pino 8), amarelo (pino 9) e verde (pino 10).
- Variável: estadoAtual, responsável por armazenar o estado do semáforo.
- Comunicação: Monitor Serial, configurado em 9600 baud.
- Linguagem: C++ (Arduino).
Objetivo: utilizar estados e transições para controlar o funcionamento de um semáforo eletrônico.

## Testes realizados

1. Entrada ou condição testada: Pressionar o botão conectado ao pino 2 do Arduino para mudar o estado do semáforo.

2. Resultado esperado: O semáforo deve mudar de vermelho para verde, depois amarelo e retornar ao vermelho, avançando apenas uma vez por clique.

3. Resultado observado: O sistema funcionou corretamente, os LEDs mudaram na sequência esperada e os estados foram exibidos no Monitor Serial.
