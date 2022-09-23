#define rodaEsquerda1 8
#define rodaEsquerda2 7

#define rodaDireita1 6
#define rodaDireita2 5

#define motorEsquerdo 9
#define motorDireito 4

#define potenciometro A0

void setup() {

  pinMode(motorEsquerdo, OUTPUT);
  pinMode(rodaEsquerda1, OUTPUT);
  pinMode(rodaEsquerda2, OUTPUT);

  pinMode(motorDireito, OUTPUT);
  pinMode(rodaDireita1, OUTPUT);
  pinMode(rodaDireita2, OUTPUT);

  calcularVelocidade();
}

void loop() {
  andarPraFrente();
  delay(2000);
  parar();
  delay(500);
  
  andarPraTras();
  delay(2000);
  parar();
  delay(500);
  
  girarDireita();
  delay(2000);
  parar();
  delay(500);

  girarEsquerda();
  delay(2000);
  parar();
  delay(500);
}

void calcularVelocidade(){
//  int val = analogRead(potenciometro);  

  int val = 1024;
  
  analogWrite(motorEsquerdo, val / 4);
  analogWrite(motorDireito, val / 4);
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
