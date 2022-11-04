#define rodaEsquerda1 6 //out1 e out2 e laranja
#define rodaEsquerda2 7

#define rodaDireita1 5 //out3 e out4 e verde
#define rodaDireita2 4

#define potenciometro A0

#define isolante 1
#define chao     0

#define obstaculo 0
#define livre     1

#define ledContador 13

#define sensorDireito  3
#define sensorEsquerdo 2
#define sensorParada   9

#define sensorContador 8

int contadorLinha          = 0;
int isBuraco               = 0;
int contadorSensorDireito  = 0;
int contadorSensorEsquerdo = 0;
int isBuracoDireito        = 0;
int isBuracoEsquerdo       = 0;
int valorSensorDireito;
int valorSensorEsquerdo;
int valorSensorParada;

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
}

void loop() {
  valorSensorDireito  = digitalRead(sensorDireito);
  valorSensorEsquerdo = digitalRead(sensorEsquerdo);
  valorSensorParada   = digitalRead(sensorParada);
  
  seguirCaminho();

  // Serial.print("Parar: ");
 //  Serial.println(valorSensorParada);
  
 // Serial.print("Contador: ");
 // Serial.println(contador);

//  Serial.print("Pino: ");
//  Serial.println(digitalRead(sensorContador));

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
    contadorLinha++;
  }else if(digitalRead(sensorContador) == chao && isBuraco == 1){
      isBuraco = 0;
  }
}
    
void seguirCaminho() {
  if(valorSensorParada == obstaculo){
    parar();
    return;
  }
  checkLinha();
  if((contadorLinha == 0) || (contadorLinha == 1) || (contadorLinha == 2)){
    andarLinhaReta(); 
  }else {
    //girarEsquerda();
   // parar();
    dobrarEsquerda();
  }
}

void dobrarEsquerda() {
  if(contadorSensorDireito == 0 && contadorSensorEsquerdo == 0){
    girarEsquerda();
    if(valorSensorDireito == isolante && isBuracoDireito == 0){
      isBuracoDireito = 1;
    }else if(valorSensorDireito == chao && isBuracoDireito == 1){
      contadorSensorDireito ++;
    }
  }else if(contadorSensorDireito == 1 && contadorSensorEsquerdo == 0){
    girarEsquerda();
    if(valorSensorEsquerdo == isolante && isBuracoEsquerdo == 0){
      isBuracoEsquerdo = 1;
    }else if(valorSensorEsquerdo == chao && isBuracoEsquerdo == 1){
      contadorSensorEsquerdo ++;
    }
  }else {
    contadorSensorDireito  = 0;
    contadorSensorEsquerdo = 0;
    contadorLinha          = 0;
  }
}



void teste() {
     
 // andarPraFrente();
 // delay(2000);
 // parar();
 // delay(500);
  
 // andarPraTras();
 // delay(2000);
 // parar();
 //delay(500);
  
// girarDireita();
 // delay(2000);
 // parar();
 // delay(500);

 // girarEsquerda();
//  delay(2000);
//  parar();
//  delay(500);
}
