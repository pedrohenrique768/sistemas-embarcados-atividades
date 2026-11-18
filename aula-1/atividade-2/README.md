

# Atividade X — Nome da atividade

## Plataforma e link

- Plataforma: Tinkercad, Wokwi ou outra
- Link: COLE_O_LINK_AQUI
 https://www.tinkercad.com/things/asAX83DzAg8/editel?returnTo=%2Fclassrooms%2F7OjAnbHLZRm%2Factivities%2F4iyOzX8sN5v%3Fview%3Dwork%26type%3Dall

## Imagem do protótipo
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/9492392c-a84b-449e-8785-8b41e80bdcd9" />

![Estrutura do protótipo](prototipo.png)

## Componentes utilizados

- Arduino Uno
- Liste os demais componentes
  
-  (Uno, Nano ou Mega) + Cabo USB para alimentação e comunicação serial.   1x Protoboard (placa de ensaio) para realizar as conexões sem solda.   2x Botões (Push-buttons) — um para ativar/desativar o alarme e outro para simular o sensor de detecção. (Nota: o segundo botão pode ser substituído por um sensor de presença PIR ou sensor magnético de porta, se preferir).   1x LED (qualquer cor, como vermelho ou verde) para indicar visualmente o status do sistema.   1x Resistor de 220Ω (ou 330Ω) para proteger o LED contra excesso de corrente.   1x Buzzer (ativo ou passivo de 5V) para emitir o som de alerta.   Fios Jumpers (macho-macho) para interligar os componentes ao Arduino.   

## Como funciona

Explique os estados do sistema, o que provoca cada mudança de estado e o comportamento dos componentes.

O projeto consiste em um sistema de alarme controlado por máquina de estados no Arduino, operando em três modos distintos e registrando todas as mudanças no Monitor Serial:

DESATIVADO: Estado inicial em repouso, com o LED apagado e o buzzer mudo (ignora detecções). Ao apertar o botão principal, passa para ATIVADO.

ATIVADO: Sistema armado, indicado pelo LED aceso continuamente e buzzer mudo. Se o botão principal for apertado novamente, volta para DESATIVADO; se o botão/sensor de detecção for acionado, entra em ALERTA.

ALERTA: Alarme disparado, acionando o som contínuo do buzzer e fazendo o LED piscar rapidamente. Ao apertar o botão principal, o alarme é silenciado e retorna ao estado DESATIVADO.

## Testes realizados

1. Entrada ou condição testada:
2. Com o sistema inicialmente no estado DESATIVADO, pressionar o Botão do Sistema (pino 2) para armar o alarme; em seguida, pressionar o Botão/Sensor de Detecção (pino 3) para simular uma invasão e, por fim, pressionar novamente o Botão do Sistema (pino 2) para desligar o alarme.

3. Resultado esperado:

Ao pressionar o botão de ativação pela primeira vez, o sistema deve mudar para ATIVADO, acender o LED continuamente, manter o buzzer mudo e exibir "Transicao -> Novo estado: ATIVADO" no Monitor Serial.

Ao acionar o botão/sensor de detecção, o sistema deve mudar para ALERTA, fazer o LED piscar rapidamente, acionar o som do buzzer e exibir "Transicao -> Novo estado: ALERTA! (Intruso detectado)" no Monitor Serial.

Ao pressionar o botão do sistema novamente, o alarme deve retornar ao estado DESATIVADO, apagar o LED, silenciar o buzzer e registrar "Transicao -> Novo estado: DESATIVADO" no Monitor Serial.

3. Resultado observado:
O circuito respondeu conforme o esperado em todas as etapas: o LED permaneceu aceso fixo após a ativação, começou a piscar junto com o acionamento imediato do buzzer no momento em que o sensor foi pressionado e ambos foram desligados ao pressionar o botão principal novamente, com todas as mensagens de transição impressas corretamente no Monitor Serial.
