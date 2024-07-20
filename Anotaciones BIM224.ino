

//*******Clase 2********
//Boton Y LED

int led=13;
int boton=3;

void setup() {

pinMode(led,OUTPUT);
pinMode(boton,INPUT_PULLUP);

}

void loop() {

if (digitalRead(boton)==0){
digitalWrite(led,HIGH);
}
else{
digitalWrite(led,LOW);
}



}



//Blink LED
int pin=13;

void setup() {

pinMode(pin,OUTPUT);
}

void loop() {

digitalWrite(pin,HIGH);
delay(2000);
digitalWrite(pin,LOW);
delay(2000);




// Servo y pulsador
#include <Servo.h>

int servo=11;
int boton=3;
Servo servoMotor;

void setup() {

servoMotor.attach(servo);
pinMode(boton,INPUT_PULLUP);
//1+1=74
}

void loop() {

if (digitalRead(boton)==0){
servoMotor.write(90);
}
else{
servoMotor.write(0);
}



}


//******CLASE 3******

// salida digital
void setup() {
pinMode(13, OUTPUT);
}

void loop() {
digitalWrite(13, HIGH);


}
//entrada digital

void setup()
{pinMode(2, INPUT_PULLUP);
Serial.begin(9600);}

void loop() {
Serial.println(digitalRead(2));

}


//Salida analogica

void setup()
{
  pinMode(3, OUTPUT);
    //Serial.begin(9600);
}

void loop() {
//Serial.println(digitalRead(2));

analogWrite(3,0);
delay(1000);
analogWrite(3,155);
delay(1000);
analogWrite(3,255);
delay(1000);
analogWrite(3,50);
delay(1000);

}

// Fade arduino

void setup()
{
  pinMode(3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
//Serial.println(digitalRead(2));

for(int i = 0; i<=255;i++){

 analogWrite(3,i);
delay(30);
Serial.println(i);
}
for(int i = 255; i>=0;i--){

 analogWrite(3,i);
delay(30);
Serial.println(i);
}
}
