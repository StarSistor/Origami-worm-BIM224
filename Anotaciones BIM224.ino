

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


//******CLASE 4******


#include <Servo.h>
Servo dinosaurio;
Servo gato

void setup() {
  dinosaurio.attach(11);
  gato.attach(10);
  }
void loop() {

  dinosaurio.write(0);
  gato.write(0);
  delay(2000);

  dinosaurio.write(180);
  gato.write(180);
  delay(2000);
}



#include <IRremote.h>
#include <Servo.h>

Servo dino;

IRrecv irrecv(4);
decode_results results;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();

  dino.attach(3);

}

void loop(){
  if (irrecv.decode(&results)){
        Serial.println(results.value, HEX);
        irrecv.resume();
  }



if(results.value == FFA25D)
dino.write(90);

else
dino.write(0);
  
}


//******CLASE 5******

#include <IRremote.hpp>
#include <Servo.h>

Servo dino;


decode_results results;

void setup(){
  Serial.begin(9600);
  IrReceiver.begin(4, ENABLE_LED_FEEDBACK); // Inicializar receptor IR

  dino.attach(3);

}

void loop(){
  if (IrReceiver.decode()){
  uint32_t irValue = IrReceiver.decodedIRData.decodedRawData;
  Serial.println(irValue, HEX);
        

if(irValue == 0xFE01BF00)
dino.write(90);

else
dino.write(0);
  
  IrReceiver.resume();
   }
}





/*

       //Key	Code anterior y reciente
//POWER	0xFD00FF
//VOL+	0xFD807F
//FUNC/STOP	0xFD40BF
//│◄◄	0xFD20DF
//►││	0xFDA05F
//►►│	0xFD609F
//▼	0xFD10EF
//VOL-	0xFD906F
//▲	0xFD50AF
//0	0xFD30CF
//EQ	0xFDB04F
//ST/REPT	0xFD708F
//1	0xFD08F7
//2	0xFD8877
//3	0xFD48B7
//4	0xFD28D7
//5	0xFDA857
//6	0xFD6897
//7	0xFD18E7
//8	0xFD9867
//9	0xFD58A7 



FF00BF00
FE01BF00
FD02BF00
FB04BF00
FA05BF00
F906BF00
F708BF00
F609BF00
F50ABF00
F30CBF00
F20DBF00
F10EBF00
EF10BF00
EE11BF00
ED12BF00
EB14BF00
EB14BF00
EA15BF00
E916BF00
E718BF00
E619BF00
E51ABF00
*/
