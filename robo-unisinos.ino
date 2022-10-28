#define rodaEsquerda1 6 //out1 e out2 e laranja
#define rodaEsquerda2 7

#define rodaDireita1 5 //out3 e out4 e verde
#define rodaDireita2 4

#define potenciometro A0

#define isolante 1
#define chao     0

#define ledContador 13

#define sensorDireito  8
#define sensorEsquerdo 3

#define sensorContador 2


int contador = 0;
int isBuraco = 0;
int valorSensorDireito;
int valorSensorEsquerdo;

void setup() {
  Serial.begin(115200);
  pinMode(rodaEsquerda1, OUTPUT);
  pinMode(rodaEsquerda2, OUTPUT);

  pinMode(rodaDireita1, OUTPUT);
  pinMode(rodaDireita2, OUTPUT);

  pinMode(sensorDireito,  INPUT);
  pinMode(sensorEsquerdo, INPUT);

  pinMode(ledContador, OUTPUT);

  pinMode(sensorContador, INPUT);

  //attachInterrupt(digitalPinToInterrupt(sensorContador), checkLinha, RISING);
}

void loop() {
  valorSensorDireito  = digitalRead(sensorDireito);
  valorSensorEsquerdo = digitalRead(sensorEsquerdo);
  
  seguirCaminho();
  Serial.print("Contador: ");
  Serial.println(contador);

  Serial.print("Pino: ");
  Serial.println(digitalRead(sensorContador));

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

void checkLinha() {
  if(digitalRead(sensorContador) == isolante && isBuraco == 0){
    isBuraco = 1;
    contador++;
  }else if(digitalRead(sensorContador) == chao && isBuraco == 1){
      isBuraco = 0;
  }
}
    
void seguirCaminho() {
  checkLinha();
  if((contador == 0) || (contador == 1) || (contador == 2)){
    andarLinhaReta(); 
  }else {
    girarEsquerda();
  }
}



void teste() {
     
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
//  delay(2000);
//  parar();
//  delay(500);
}
