#define rodaEsquerda1 7 //out1 e out2 e laranja
#define rodaEsquerda2 6

#define rodaDireita1 4 //out3 e out4 e roxo
#define rodaDireita2 5

#define potenciometro A0

int sensorDireito  = 2;
int sensorEsquerdo = 3;

void setup() {
  Serial.begin(9600);
  pinMode(rodaEsquerda1, OUTPUT);
  pinMode(rodaEsquerda2, OUTPUT);

  pinMode(rodaDireita1, OUTPUT);
  pinMode(rodaDireita2, OUTPUT);

  pinMode(sensorDireito,  INPUT);
  pinMode(sensorEsquerdo, INPUT);
}

void loop() {
  int valorSensorDireito  = digitalRead(sensorDireito);
  int valorSensorEsquerdo = digitalRead(sensorEsquerdo);
  
  if((valorSensorDireito == 0) && (valorSensorEsquerdo == 0)) {
    andarPraFrente();
  }else if((valorSensorDireito == 1) && (valorSensorEsquerdo == 1)){
    parar();
  }
   
 // andarPraFrente();
 // delay(2000);
 // parar();
 // delay(500);
  
 // andarPraTras();
 // delay(2000);
 // parar();
 // delay(500);
  
 // girarDireita();
 // delay(2000);
 // parar();
 // delay(500);

 // girarEsquerda();
 // delay(2000);
 // parar();
 // delay(500);
}

void andarPraFrente() {
  digitalWrite(rodaEsquerda1, HIGH);
  digitalWrite(rodaEsquerda2, LOW);

  digitalWrite(rodaDireita1, HIGH);
  digitalWrite(rodaDireita2, LOW);
}

void andarPraTras() {
  digitalWrite(rodaEsquerda1, LOW);
  digitalWrite(rodaEsquerda2, HIGH);

  digitalWrite(rodaDireita1, LOW);
  digitalWrite(rodaDireita2, HIGH);
}

void parar() {
  digitalWrite(rodaEsquerda1, LOW);
  digitalWrite(rodaEsquerda2, LOW);

  digitalWrite(rodaDireita1, LOW);
  digitalWrite(rodaDireita2, LOW);
}

void girarEsquerda() {
  digitalWrite(rodaEsquerda1, LOW);
  digitalWrite(rodaEsquerda2, HIGH);

  digitalWrite(rodaDireita1, HIGH);
  digitalWrite(rodaDireita2, LOW);
}

void girarDireita() {
  digitalWrite(rodaDireita1, LOW);
  digitalWrite(rodaDireita2, HIGH);

  digitalWrite(rodaEsquerda1, HIGH);
  digitalWrite(rodaEsquerda2, LOW);
}
