// Definição dos pinos
const int PINO_BOTAO_SISTEMA = 2;   // Botão para ativar/desativar o alarme
const int PINO_SENSOR_DETECCAO = 3; // Botão ou sensor que simula invasão
const int PINO_LED = 12;            // LED indicador de status
const int PINO_BUZZER = 8;          // Buzzer sonoro

// Definição dos estados do sistema (usando const int para evitar erro de compilação no Arduino)
const int DESATIVADO = 0;
const int ATIVADO = 1;
const int ALERTA = 2;

// Variável que guarda o estado atual
int estadoAtual = DESATIVADO;

// Variáveis auxiliares para leitura dos botões
bool ultimoEstadoBotaoSistema = HIGH;
bool ultimoEstadoSensor = HIGH;

// Variável para controlar o pisca-pisca do LED no estado ALERTA
unsigned long tempoAnteriorLed = 0;
bool estadoLedAlerta = LOW;

void setup() {
  Serial.begin(9600);

  pinMode(PINO_BOTAO_SISTEMA, INPUT_PULLUP);
  pinMode(PINO_SENSOR_DETECCAO, INPUT_PULLUP);
  pinMode(PINO_LED, OUTPUT);
  pinMode(PINO_BUZZER, OUTPUT);

  digitalWrite(PINO_LED, LOW);
  noTone(PINO_BUZZER);

  Serial.println("=== SISTEMA DE ALARME INICIADO ===");
  Serial.println("Estado atual: DESATIVADO");
}

void loop() {
  bool leituraBotaoSistema = digitalRead(PINO_BOTAO_SISTEMA);
  bool leituraSensor = digitalRead(PINO_SENSOR_DETECCAO);

  bool clicouBotaoSistema = (ultimoEstadoBotaoSistema == HIGH && leituraBotaoSistema == LOW);
  bool detectouMovimento = (ultimoEstadoSensor == HIGH && leituraSensor == LOW);

  switch (estadoAtual) {
    
    case DESATIVADO:
      digitalWrite(PINO_LED, LOW);
      noTone(PINO_BUZZER);

      if (clicouBotaoSistema) {
        mudarEstado(ATIVADO);
      }
      break;

    case ATIVADO:
      digitalWrite(PINO_LED, HIGH);
      noTone(PINO_BUZZER);

      if (clicouBotaoSistema) {
        mudarEstado(DESATIVADO);
      } 
      else if (detectouMovimento) {
        mudarEstado(ALERTA);
      }
      break;

    case ALERTA:
      tone(PINO_BUZZER, 1000);

      if (millis() - tempoAnteriorLed >= 150) {
        tempoAnteriorLed = millis();
        estadoLedAlerta = !estadoLedAlerta;
        digitalWrite(PINO_LED, estadoLedAlerta);
      }

      if (clicouBotaoSistema) {
        mudarEstado(DESATIVADO);
      }
      break;
  }

  ultimoEstadoBotaoSistema = leituraBotaoSistema;
  ultimoEstadoSensor = leituraSensor;
  delay(20); 
}

// Função atualizada recebendo 'int'
void mudarEstado(int novoEstado) {
  estadoAtual = novoEstado;

  Serial.print("Transicao -> Novo estado: ");
  switch (estadoAtual) {
    case DESATIVADO:
      Serial.println("DESATIVADO");
      break;
    case ATIVADO:
      Serial.println("ATIVADO");
      break;
    case ALERTA:
      Serial.println("ALERTA! (Intruso detectado)");
      break;
  }
}
