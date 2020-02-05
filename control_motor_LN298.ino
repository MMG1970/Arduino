const byte motorIzqA = 3;
const byte motorIzqB = 4;
const byte motorDerA = 5;
const byte motorDerB = 6;
const byte motorenableIzq = 10;
const byte motorenableDer = 11;

byte velocidad_inicial = 0;
byte velocidad_minima = 55;
bool sentido = true;


void setup() {
  Serial.begin(9600);
  pinMode(motorIzqA,OUTPUT);
  pinMode(motorIzqB,OUTPUT);
  pinMode(motorDerA,OUTPUT);
  pinMode(motorDerB,OUTPUT);

  analogWrite(motorenableIzq,velocidad_inicial);
  analogWrite(motorenableDer,velocidad_inicial);

}

void loop() {

  //prueba velocidad de arranque motor
  control_M_Izq(sentido, velocidad_minima);
  control_M_Der(sentido, velocidad_minima);
  velocidad_minima++;
  delay(300);
  Serial.println(String (velocidad_minima));

  //arranque 0-max veloc, con pausa
  //control_M_Izq(true,254);
  //delay(2000);
  //control_M_Izq(true,0);
  //delay(1000);
  //control_M_Izq(false,254);
  //delay(2000);
  //control_M_Izq(true,0);
  //delay(1000);

}

void control_M_Izq(bool sentido, byte vel){
  if (sentido == true){
    digitalWrite(motorIzqA,HIGH);
    digitalWrite(motorIzqB,LOW);
    }else{
     digitalWrite(motorIzqA,LOW);
     digitalWrite(motorIzqB,HIGH);
    }
    analogWrite(motorenableIzq,vel);
}

void control_M_Der(bool sentido, byte vel){
  if (sentido == true){
    digitalWrite(motorDerA,HIGH);
    digitalWrite(motorDerB,LOW);
    }else{
     digitalWrite(motorDerA,LOW);
     digitalWrite(motorDerB,HIGH);
    }
    analogWrite(motorenableDer,vel);
}
