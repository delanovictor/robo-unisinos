#define output1 2
#define output2 3

#define output3 4
#define output4 5

#define enableA 9
#define enableB 10

//int analogPin = 3;\\1
int val = 1000;

void setup() {
  pinMode(enableA, OUTPUT);
  pinMode(output1, OUTPUT);
  pinMode(output2, OUTPUT);

  pinMode(enableB, OUTPUT);
  pinMode(output3, OUTPUT);
  pinMode(output4, OUTPUT);

}

void loop() {
  analogWrite(enableA, val / 4);
  analogWrite(enableB, val / 4);

  andarPraFrente();
  
  delay(2000);

  parar();

  delay(500);
  
  andarPraTras();
  
  delay(2000);

  parar();

  delay(500);
  
}

void andarPraFrente() {
  digitalWrite(output1, HIGH);
  digitalWrite(output2, LOW);

  digitalWrite(output3, HIGH);
  digitalWrite(output4, LOW);
}

void andarPraTras() {

  digitalWrite(output1, LOW);
  digitalWrite(output2, HIGH);

  digitalWrite(output3, LOW);
  digitalWrite(output4, HIGH);
}



void parar() {

  digitalWrite(output1, LOW);
  digitalWrite(output2, LOW);

  digitalWrite(output3, LOW);
  digitalWrite(output4, LOW);
}
