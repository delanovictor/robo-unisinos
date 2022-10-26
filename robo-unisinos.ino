#define rodaEsquerda1 6 //out1 e out2 e laranja
#define rodaEsquerda2 7

#define rodaDireita1 5 //out3 e out4 e verde
#define rodaDireita2 4

#define potenciometro A0

#define isolante 1
#define chao     0
#define sensorContador 8

#define ledContador 13

int sensorDireito  = 2;
int sensorEsquerdo = 3;
int contador       = 0;

int valorSensorDireito;
int valorSensorEsquerdo;

void setup() {
  Serial.begin(9600);
  pinMode(rodaEsquerda1, OUTPUT);
  pinMode(rodaEsquerda2, OUTPUT);

  pinMode(rodaDireita1, OUTPUT);
  pinMode(rodaDireita2, OUTPUT);

  pinMode(sensorDireito,  INPUT);
  pinMode(sensorEsquerdo, INPUT);

  pinMode(ledContador, OUTPUT);

  pinMode(sensorContado, INPUT);
}

void loop() {
  valorSensorDireito  = digitalRead(sensorDireito);
  valorSensorEsquerdo = digitalRead(sensorEsquerdo);
  
  seguirCaminho();
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

void andarLinhaReta() {
  if(valorSensorDireito == valorSensorEsquerdo) {
    andarPraFrente();
   }else if((valorSensorDireito == isolante) && (valorSensorEsquerdo == chao)){
    corrigirParaDireita();
  }else if((valorSensorDireito == chao) && (valorSensorEsquerdo == isolante)){
    corrigirParaEsquerda();
  }
}

void corrigirParaDireita() {
  digitalWrite(rodaDireita1, LOW);
  digitalWrite(rodaDireita2, LOW);

  digitalWrite(rodaEsquerda1, HIGH);
  digitalWrite(rodaEsquerda2, LOW);
}

void corrigirParaEsquerda() {
  digitalWrite(rodaDireita1, HIGH);
  digitalWrite(rodaDireita2, LOW);

  digitalWrite(rodaEsquerda1, LOW);
  digitalWrite(rodaEsquerda2, LOW);
}

void checkLinha( ) {
  int passouLinha = digitalRead(sensorContador);
  
    contador++;
    digitalWrite(ledContador, HIGH);
    delay(1000);
    digitalWrite(ledContador, LOW);   
}
    
void seguirCaminho() {
  checkLinha();
  if((contador == 0) || (contador == 1) || (contador == 2)){
    andarLinhaReta(); 
  }else {
    parar();
  }
}

void teste() {
     
//  andarPraFrente();
//  delay(2000);
//  parar();
//  delay(500);
  
//  andarPraTras();
//  delay(2000);
//  parar();
//  delay(500);
  
 // girarDireita();
//  delay(2000);
//  parar();
//  delay(500);

//  girarEsquerda();
//  delay(2000);
//  parar();
//  delay(500);
}
