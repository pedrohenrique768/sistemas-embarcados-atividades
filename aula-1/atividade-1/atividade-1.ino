const int vermelho = 8;
const int amarelo = 9;
const int verde = 10;
const int botao = 2;

enum Estado {
  VERMELHO,
  VERDE,
  AMARELO
};

Estado estadoAtual = VERMELHO;

int leituraAnterior = HIGH;

void setup() {
  pinMode(vermelho, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(verde, OUTPUT);

  pinMode(botao, INPUT_PULLUP);

  Serial.begin(9600);

  atualizarSemaforo();
}

void loop() {
  int leitura = digitalRead(botao);

  if (leitura == LOW && leituraAnterior == HIGH) {
    if (estadoAtual == VERMELHO) {
      estadoAtual = VERDE;
    }
    else if (estadoAtual == VERDE) {
      estadoAtual = AMARELO;
    }
    else if (estadoAtual == AMARELO) {
      estadoAtual = VERMELHO;
    }

    atualizarSemaforo();

    delay(50);
  }

  leituraAnterior = leitura;
}

void atualizarSemaforo() {
  digitalWrite(vermelho, estadoAtual == VERMELHO);
  digitalWrite(verde, estadoAtual == VERDE);
  digitalWrite(amarelo, estadoAtual == AMARELO);

  if (estadoAtual == VERMELHO) {
    Serial.println("VERMELHO");
  }
  else if (estadoAtual == VERDE) {
    Serial.println("VERDE");
  }
  else if (estadoAtual == AMARELO) {
    Serial.println("AMARELO");
  }
}
